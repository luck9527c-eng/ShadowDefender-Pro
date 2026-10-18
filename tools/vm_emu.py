#!/usr/bin/env python3
"""Emulate Shadow Defender's bytecode VM to recover its control flow.

The driver's control plane is a register machine: opcode handlers are ordinary
x86-64 code inside the disguised ``.reloc`` section, and the register file is a
scratch structure at RVA 0x2D200. Each handler ends by dispatching the next
opcode itself, so *executing* the handlers with the vendor code and logging every
dispatch recovers the program without needing to understand each opcode.

Approach
--------
* map the PE image at its preferred base exactly as the loader would,
* allocate a scratch state block and point RBP at it,
* pre-relocate the qword dispatch table (what the runtime relocator does),
* set state+0xFB (the instruction pointer) to the program to run,
* start at handler 79 (the interpreter step) and log every dispatch.

Unresolved imports are emulated as "return 0" so analysis can continue past
them; every such event is reported so it is never mistaken for real behaviour.

Usage:
    python vm_emu.py <driver> <program_rva> [--max-dispatch N] [--trace-out FILE]
                     [--state-rva 0x2D200] [--table-rva 0x679A9] [--entries 136]
"""
from __future__ import annotations

import argparse
import struct
import sys
from collections import Counter, OrderedDict

from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_UNMAPPED
from unicorn.x86_const import (
    UC_X86_REG_RBP, UC_X86_REG_RSP, UC_X86_REG_RAX, UC_X86_REG_RIP,
    UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_RBX, UC_X86_REG_RSI,
    UC_X86_REG_RDI, UC_X86_REG_R8, UC_X86_REG_R9, UC_X86_REG_R10,
    UC_X86_REG_R11, UC_X86_REG_R12, UC_X86_REG_R13, UC_X86_REG_R14,
    UC_X86_REG_R15, UC_X86_REG_EFLAGS,
)

PAGE = 0x1000


def align_up(v, a=PAGE):
    return (v + a - 1) & ~(a - 1)


class Image:
    def __init__(self, path):
        with open(path, "rb") as fh:
            self.data = fh.read()
        pe = struct.unpack_from("<I", self.data, 0x3C)[0]
        if self.data[pe:pe + 4] != b"PE\0\0":
            raise ValueError("not PE")
        self.pe = pe
        self.nsec = struct.unpack_from("<H", self.data, pe + 6)[0]
        self.optsz = struct.unpack_from("<H", self.data, pe + 20)[0]
        opt = pe + 24
        self.imagebase = struct.unpack_from("<Q", self.data, opt + 24)[0]
        self.size_of_image = struct.unpack_from("<I", self.data, opt + 56)[0]
        self.sections = []
        sh = pe + 24 + self.optsz
        for i in range(self.nsec):
            o = sh + i * 40
            name = self.data[o:o + 8].rstrip(b"\0").decode("latin-1")
            vsz, va, rsz, ra = struct.unpack_from("<IIII", self.data, o + 8)
            ch = struct.unpack_from("<I", self.data, o + 36)[0]
            self.sections.append((name, va, vsz, ra, rsz, ch))

    def rva2off(self, rva):
        for _n, va, vsz, ra, rsz, _c in self.sections:
            if va <= rva < va + max(vsz, rsz):
                return ra + (rva - va)
        return None

    def read(self, rva, n):
        off = self.rva2off(rva)
        if off is None:
            return None
        return self.data[off:off + n]


def map_image(uc, img):
    base = img.imagebase
    total = align_up(max(img.size_of_image, max(s[1] + max(s[2], s[4]) for s in img.sections)))
    uc.mem_map(base, total, 7)  # RWX: the vault is RWX and the loader patches it
    hdr = min(0x1000, len(img.data))
    uc.mem_write(base, img.data[:hdr])
    for name, va, vsz, ra, rsz, _ch in img.sections:
        if rsz:
            chunk = img.data[ra:ra + rsz]
            uc.mem_write(base + va, chunk)
    return base, total


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("program", type=lambda s: int(s, 0))
    ap.add_argument("--max-dispatch", type=int, default=200000)
    ap.add_argument("--max-insn", type=int, default=20_000_000)
    ap.add_argument("--state-rva", type=lambda s: int(s, 0), default=0x2D200)
    ap.add_argument("--table-rva", type=lambda s: int(s, 0), default=0x679A9)
    ap.add_argument("--entries", type=int, default=136)
    ap.add_argument("--trace-out", default=None)
    ap.add_argument("--stop-at-dispatch", type=int, default=None,
                    help="stop when this opcode index is dispatched (default: never)")
    args = ap.parse_args()

    img = Image(args.image)
    base = img.imagebase

    # --- pre-relocate the dispatch table ---
    table_off = img.rva2off(args.table_rva)
    entries = list(struct.unpack_from("<%dQ" % args.entries, img.data, table_off))
    handlers = {}
    for idx, rva in enumerate(entries):
        if rva == 0:
            continue
        handlers[base + rva] = idx
    if not handlers:
        print("no dispatch-table entries", file=sys.stderr)
        return 2

    uc = Uc(UC_ARCH_X86, UC_MODE_64)
    map_image(uc, img)

    # The loader does not relocate these: the runtime relocator adds the image
    # base to every table entry. Do the same in emulated memory.
    relocated = [ (rva + base) if rva else 0 for rva in entries ]
    uc.mem_write(base + args.table_rva, struct.pack("<%dQ" % args.entries, *relocated))

    # --- scratch state block ---
    STATE = 0x30000000
    STATE_SIZE = 0x40000
    uc.mem_map(STATE, STATE_SIZE, 7)
    state = STATE
    ip = base + args.program

    # what the runtime relocator (0x2800B7DE9) installs before entering the VM
    uc.mem_write(state + 0x0EF, struct.pack("<Q", base))
    uc.mem_write(state + 0x0FB, struct.pack("<Q", ip))
    uc.mem_write(state + 0x054, struct.pack("<Q", base + args.table_rva))
    uc.mem_write(state + 0x0E7, struct.pack("<I", 1))
    uc.mem_write(state + 0x069, struct.pack("<I", 0))
    uc.mem_write(state + 0x01C, struct.pack("<I", 0))

    # --- stack ---
    STACK = 0x31000000
    uc.mem_map(STACK, 0x20000, 7)
    rsp = STACK + 0x18000
    uc.mem_write(rsp, struct.pack("<Q", base + 0x000) )  # dummy return address

    regs = {UC_X86_REG_RBP: state, UC_X86_REG_RSP: rsp,
            UC_X86_REG_RCX: 0, UC_X86_REG_RDX: 0,
            UC_X86_REG_R8: 0, UC_X86_REG_R9: 0, UC_X86_REG_R10: 0,
            UC_X86_REG_R11: 0, UC_X86_REG_R12: 0, UC_X86_REG_R13: 0,
            UC_X86_REG_R14: 0, UC_X86_REG_R15: 0, UC_X86_REG_RAX: 0,
            UC_X86_REG_RBX: 0, UC_X86_REG_RSI: 0, UC_X86_REG_RDI: 0}
    for r, v in regs.items():
        uc.reg_write(r, v)

    trace = []
    op_counts = Counter()
    import_hits = Counter()
    unmapped_hits = []
    stop = {"flag": False}

    image_lo, image_hi = base, base + align_up(img.size_of_image)
    state_lo, state_hi = STATE, STATE + STATE_SIZE
    stack_lo, stack_hi = STACK, STACK + 0x20000

    def in_image(a):
        return image_lo <= a < image_hi

    lazy_pages = OrderedDict()
    mem_faults = []

    def on_unmapped(uc, access, address, size, value, user_data):
        # A handler dereferenced a pointer we have no value for (usually a
        # zero-initialised field). Map a zero page so the trace can continue,
        # and record the event: these are synthetic inputs, not observed data.
        page = address & ~0xFFF
        if page in lazy_pages:
            return True
        if len(lazy_pages) >= 256 or page < 0x1000 or page > 0x00007FFFFFFFFFFF:
            mem_faults.append((uc.reg_read(UC_X86_REG_RIP), address, "unrecoverable"))
            stop["flag"] = True
            uc.emu_stop()
            return False
        try:
            uc.mem_map(page, PAGE, 7)
        except Exception:
            mem_faults.append((uc.reg_read(UC_X86_REG_RIP), address, "map-failed"))
            stop["flag"] = True
            uc.emu_stop()
            return False
        lazy_pages[page] = True
        mem_faults.append((uc.reg_read(UC_X86_REG_RIP), address, "mapped-zero"))
        return True

    def on_code(uc, address, size, user_data):
        if stop["flag"]:
            return
        if address in handlers:
            idx = handlers[address]
            ip_now = struct.unpack("<Q", uc.mem_read(state + 0x0FB, 8))[0]
            try:
                words = struct.unpack("<8H", uc.mem_read(ip_now, 16))
            except Exception:
                words = ()
            trace.append((idx, ip_now - base, words))
            op_counts[idx] += 1
            if len(trace) >= args.max_dispatch:
                stop["flag"] = True
                uc.emu_stop()
            if args.stop_at_dispatch is not None and idx == args.stop_at_dispatch:
                stop["flag"] = True
                uc.emu_stop()
            return
        if in_image(address) or (state_lo <= address < state_hi) or (stack_lo <= address < stack_hi):
            return
        # jumped into an unresolved import / null pointer: emulate "return 0"
        import_hits[address] += 1
        try:
            ret = struct.unpack("<Q", uc.mem_read(uc.reg_read(UC_X86_REG_RSP), 8))[0]
            uc.reg_write(UC_X86_REG_RSP, uc.reg_read(UC_X86_REG_RSP) + 8)
            uc.reg_write(UC_X86_REG_RAX, 0)
            uc.reg_write(UC_X86_REG_RIP, ret)
        except Exception:
            unmapped_hits.append(address)
            stop["flag"] = True
            uc.emu_stop()

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_UNMAPPED, on_unmapped)

    start_pc = base + entries[79] if entries[79] else base + 0x5177c
    print("# image   : %s" % args.image)
    print("# base    : %#x   state=%#x   program=%#x" % (base, state, args.program))
    print("# handler : %#x (index 79)" % start_pc)
    print("# entries : %d (non-null %d)" % (len(entries), len(handlers)))

    try:
        uc.emu_start(start_pc, 0, count=args.max_insn)
    except Exception as exc:  # noqa: BLE001
        print("# emulation stopped: %r errno=%s" % (exc, getattr(exc, "errno", "?")), file=sys.stderr)

    print("# dispatched instructions: %d" % len(trace))
    print("# distinct opcodes: %d" % len(op_counts))
    if import_hits:
        print("# unresolved import/indirect targets hit: %s" %
              ", ".join("%#x x%d" % (a, n) for a, n in import_hits.most_common(8)))
    if unmapped_hits:
        print("# unrecoverable unmapped targets: %s" % ", ".join("%#x" % a for a in unmapped_hits[:8]))
    if mem_faults:
        print("# unmapped memory events: %d (lazy zero pages: %d)" % (len(mem_faults), len(lazy_pages)))
        for pc, addr, kind in mem_faults[:10]:
            print("#   pc=%#x addr=%#x %s" % (pc, addr, kind))

    # opcode histogram
    print("\n# opcode histogram (index: count):")
    for idx, n in op_counts.most_common():
        print("  op%-3d %6d" % (idx, n))

    # dispatch listing
    out = []
    for idx, rva, words in trace:
        w = " ".join("%04x" % x for x in words[:6])
        out.append("op%-3d ip=%06x  %s" % (idx, rva, w))
    if args.trace_out:
        with open(args.trace_out, "w", encoding="utf-8") as fh:
            fh.write("\n".join(out) + "\n")
        print("\n# trace written to %s (%d lines)" % (args.trace_out, len(out)))
    else:
        print("\n# dispatch trace (first 120):")
        print("\n".join(out[:120]))

    return 0


if __name__ == "__main__":
    sys.exit(main())
