#!/usr/bin/env python3
"""Emulate diskpt.sys's IRP_MJ_DEVICE_CONTROL entry to map the IOCTL interface.

Why this works
--------------
`sub_2800630D8` is the driver's DEVICE_CONTROL stub. It seeds four registers and
then jumps into the bytecode VM:

    mov rbx, [rcx+0x40]     ; DeviceObject->DeviceExtension
    mov r14, [rdx+0xB8]     ; Irp->Tail.Overlay.CurrentStackLocation
    mov rbp, rdx
    mov rdi, rcx            ; DeviceObject
    ... push <program_rva>; push 79; jmp relocator

The VM reads the IOCTL code and the buffer lengths out of the IO_STACK_LOCATION,
so if we fabricate a plausible DEVICE_OBJECT + IRP + IO_STACK_LOCATION and let the
vendor code run, we can observe which opcodes and branches each IOCTL selects.

The emulation is a *model*, not observed runtime behaviour: unresolved imports
return 0 and unmapped pointers are backed with zero pages (both are reported).

Usage:
    python vm_emu_ioctl.py <driver> <ioctl_code> [--max-dispatch N] [--trace FILE]
"""
from __future__ import annotations

import argparse
import struct
import sys
from collections import Counter, OrderedDict

from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE
from unicorn.x86_const import (
    UC_X86_REG_RBP, UC_X86_REG_RSP, UC_X86_REG_RAX, UC_X86_REG_RIP,
    UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_RBX, UC_X86_REG_RSI,
    UC_X86_REG_RDI, UC_X86_REG_R8, UC_X86_REG_R9, UC_X86_REG_R10,
    UC_X86_REG_R11, UC_X86_REG_R12, UC_X86_REG_R13, UC_X86_REG_R14,
    UC_X86_REG_R15,
)

PAGE = 0x1000
ENTRY_DEVICE_CONTROL = 0x130D8      # VA 0x2800630D8 minus image base 0x280050000
TABLE_RVA = 0x679A9
STATE_RVA = 0x2D200
ENTRIES = 136


def a(v, al=PAGE):
    return (v + al - 1) & ~(al - 1)


class Image:
    def __init__(self, path):
        with open(path, "rb") as fh:
            self.data = fh.read()
        pe = struct.unpack_from("<I", self.data, 0x3C)[0]
        if self.data[pe:pe + 4] != b"PE\0\0":
            raise ValueError("not PE")
        nsec = struct.unpack_from("<H", self.data, pe + 6)[0]
        optsz = struct.unpack_from("<H", self.data, pe + 20)[0]
        opt = pe + 24
        self.imagebase = struct.unpack_from("<Q", self.data, opt + 24)[0]
        self.size_of_image = struct.unpack_from("<I", self.data, opt + 56)[0]
        self.sections = []
        sh = pe + 24 + optsz
        for i in range(nsec):
            o = sh + i * 40
            name = self.data[o:o + 8].rstrip(b"\0").decode("latin-1")
            vsz, va, rsz, ra = struct.unpack_from("<IIII", self.data, o + 8)
            self.sections.append((name, va, vsz, ra, rsz))

    def rva2off(self, rva):
        for _n, va, vsz, ra, rsz in self.sections:
            if va <= rva < va + max(vsz, rsz):
                return ra + (rva - va)
        return None

    def entries(self):
        off = self.rva2off(TABLE_RVA)
        return list(struct.unpack_from("<%dQ" % ENTRIES, self.data, off))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("ioctl", type=lambda s: int(s, 0))
    ap.add_argument("--max-dispatch", type=int, default=20000)
    ap.add_argument("--max-insn", type=int, default=80_000_000)
    ap.add_argument("--trace", default=None)
    ap.add_argument("--in-len", type=lambda s: int(s, 0), default=0x88)
    ap.add_argument("--out-len", type=lambda s: int(s, 0), default=0x88)
    ap.add_argument("--ioctl2", type=lambda s: int(s, 0), default=None,
                    help="second IOCTL code placed in the input buffer (for dispatchers that read it)")
    args = ap.parse_args()

    img = Image(args.image)
    base = img.imagebase
    table = img.entries()

    uc = Uc(UC_ARCH_X86, UC_MODE_64)

    image_size = a(max(img.size_of_image, max(va + max(vsz, rsz) for _n, va, vsz, ra, rsz in img.sections)))
    uc.mem_map(base, image_size, 7)
    uc.mem_write(base, img.data[:min(PAGE, len(img.data))])
    for _name, va, vsz, ra, rsz in img.sections:
        if rsz:
            uc.mem_write(base + va, img.data[ra:ra + rsz])

    # The state structure lives inside the vault. Zero it, like a freshly
    # initialised driver would before the first control request.
    uc.mem_write(base + STATE_RVA, b"\0" * 0x800)

    # ---- fabricated kernel objects -------------------------------------
    K = 0x40000000
    uc.mem_map(K, 0x10000, 7)
    DEVOBJ = K + 0x0000
    DEVEXT = K + 0x1000
    IRP = K + 0x2000
    STACKLOC = K + 0x3000
    SYSBUF = K + 0x4000
    INBUF = K + 0x5000
    OUTBUF = K + 0x6000
    uc.mem_write(DEVOBJ + 0x40, struct.pack("<Q", DEVEXT))   # DeviceExtension
    uc.mem_write(IRP + 0xB8, struct.pack("<Q", STACKLOC))    # CurrentStackLocation
    uc.mem_write(IRP + 0x18, struct.pack("<Q", SYSBUF))      # AssociatedIrp.SystemBuffer
    uc.mem_write(STACKLOC + 0x00, struct.pack("<B", 14))     # MajorFunction = IRP_MJ_DEVICE_CONTROL
    uc.mem_write(STACKLOC + 0x08, struct.pack("<I", args.out_len))   # OutputBufferLength
    uc.mem_write(STACKLOC + 0x10, struct.pack("<I", args.in_len))    # InputBufferLength
    uc.mem_write(STACKLOC + 0x18, struct.pack("<I", args.ioctl))     # IoControlCode
    uc.mem_write(STACKLOC + 0x20, struct.pack("<Q", INBUF))          # Type3InputBuffer
    uc.mem_write(STACKLOC + 0x28, struct.pack("<Q", DEVOBJ))         # DeviceObject
    # SYSTEM_BUFFER: magic 0x74706B64 then an optional second dword
    payload = struct.pack("<II", 0x74706B64, args.ioctl2 & 0xFFFFFFFF if args.ioctl2 is not None else 0)
    uc.mem_write(SYSBUF, payload)
    uc.mem_write(INBUF, payload)
    uc.mem_write(OUTBUF, b"\0" * 0x1000)

    # ---- stack ---------------------------------------------------------
    STACK = 0x41000000
    uc.mem_map(STACK, 0x20000, 7)
    rsp = STACK + 0x18000
    uc.mem_write(rsp, struct.pack("<Q", base))     # return to image header -> treat as end

    for reg, val in ((UC_X86_REG_RCX, DEVOBJ), (UC_X86_REG_RDX, IRP),
                     (UC_X86_REG_RSP, rsp), (UC_X86_REG_R8, 0),
                     (UC_X86_REG_R9, 0), (UC_X86_REG_RAX, 0),
                     (UC_X86_REG_RBX, 0), (UC_X86_REG_RSI, 0),
                     (UC_X86_REG_RDI, 0), (UC_X86_REG_R10, 0),
                     (UC_X86_REG_R11, 0), (UC_X86_REG_R12, 0),
                     (UC_X86_REG_R13, 0), (UC_X86_REG_R14, 0),
                     (UC_X86_REG_R15, 0), (UC_X86_REG_RBP, 0)):
        uc.reg_write(reg, val)

    handler_addr = {}
    for idx, rva in enumerate(table):
        if rva:
            handler_addr[base + rva] = idx

    trace = []
    recent = []
    ops = Counter()
    lazy = OrderedDict()
    faults = []
    imports = Counter()
    stop = {"flag": False}

    image_lo, image_hi = base, base + image_size
    k_lo, k_hi = K, K + 0x10000
    st_lo, st_hi = STACK, STACK + 0x20000

    def reg(uc, r):
        return uc.reg_read(r)

    def on_code(uc, address, size, _ud):
        if stop["flag"]:
            return
        if address in handler_addr:
            idx = handler_addr[address]
            ip = struct.unpack("<Q", uc.mem_read(base + STATE_RVA + 0xFB, 8))[0] if True else 0
            words = ()
            if image_lo <= ip < image_hi:
                try:
                    words = struct.unpack("<6H", uc.mem_read(ip, 12))
                except Exception:
                    pass
            trace.append((idx, ip - base if image_lo <= ip < image_hi else ip, words,
                          reg(uc, UC_X86_REG_R14), reg(uc, UC_X86_REG_RBX)))
            ops[idx] += 1
            if len(trace) >= args.max_dispatch:
                stop["flag"] = True
                uc.emu_stop()
            return
        recent.append(address)
        if len(recent) > 200:
            del recent[:100]
        if image_lo <= address < image_hi or k_lo <= address < k_hi or st_lo <= address < st_hi:
            # hitting the image header as a "return address" ends the run
            if address == base:
                stop["flag"] = True
                uc.emu_stop()
            return
        imports[address] += 1
        try:
            ret = struct.unpack("<Q", uc.mem_read(reg(uc, UC_X86_REG_RSP), 8))[0]
            uc.reg_write(UC_X86_REG_RSP, reg(uc, UC_X86_REG_RSP) + 8)
            uc.reg_write(UC_X86_REG_RAX, 0)
            uc.reg_write(UC_X86_REG_RIP, ret)
        except Exception:
            stop["flag"] = True
            uc.emu_stop()

    def on_unmapped(uc, access, address, size, value, _ud):
        page = address & ~0xFFF
        if page in lazy:
            return True
        if len(lazy) >= 512 or page == 0:
            faults.append((reg(uc, UC_X86_REG_RIP), address, "unrecoverable"))
            stop["flag"] = True
            uc.emu_stop()
            return False
        try:
            uc.mem_map(page, PAGE, 7)
        except Exception:
            faults.append((reg(uc, UC_X86_REG_RIP), address, "map-failed"))
            stop["flag"] = True
            uc.emu_stop()
            return False
        lazy[page] = True
        faults.append((reg(uc, UC_X86_REG_RIP), address, "zero-page"))
        return True

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_UNMAPPED, on_unmapped)

    print("# %s  IOCTL=%#x  in=%#x out=%#x" % (args.image, args.ioctl, args.in_len, args.out_len))
    print("# entry=%#x (sub_2800630D8)" % (base + ENTRY_DEVICE_CONTROL))
    try:
        uc.emu_start(base + ENTRY_DEVICE_CONTROL, 0, count=args.max_insn)
    except Exception as exc:  # noqa: BLE001
        print("# stopped: %r errno=%s" % (exc, getattr(exc, "errno", "?")), file=sys.stderr)

    print("# dispatches=%d distinct=%d" % (len(trace), len(ops)))
    if stop["flag"] and recent:
        print("# last code addresses before stop:")
        for pc in recent[-18:]:
            rel = pc - base if image_lo <= pc < image_hi else None
            print("#   %#x%s" % (pc, ("  (rva %#x)" % rel) if rel is not None else ""))
    if faults:
        print("# unmapped events=%d (zero pages=%d)" % (len(faults), len(lazy)))
        for pc, addr, kind in faults[:6]:
            print("#   pc=%#x addr=%#x %s" % (pc, addr, kind))
    if imports:
        print("# import/indirect targets=%s" % ", ".join("%#x x%d" % (x, n) for x, n in imports.most_common(6)))

    print("# opcode histogram: " + " ".join("op%d:%d" % (i, n) for i, n in ops.most_common()))

    lines = []
    for idx, rva, words, r14, rbx in trace:
        w = " ".join("%04x" % x for x in words)
        lines.append("op%-3d ip=%06x r14=%x rbx=%x  %s" % (idx, rva if isinstance(rva, int) else 0, r14, rbx, w))
    if args.trace:
        import os
        os.makedirs(os.path.dirname(args.trace), exist_ok=True)
        with open(args.trace, "w", encoding="utf-8") as fh:
            fh.write("\n".join(lines) + "\n")
        print("# trace -> %s (%d lines)" % (args.trace, len(lines)))
    else:
        print("\n".join(lines[:80]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
