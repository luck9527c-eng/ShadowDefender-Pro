#!/usr/bin/env python3
"""Disassembler for Shadow Defender's custom bytecode VM.

Background
----------
Every Shadow Defender module (diskpt.sys, Service.exe, Defender.exe, CmdTool.exe,
Commit.exe, ShellExt.dll, Uninstall.exe) hides its device-I/O layer inside a
section *named* ``.reloc`` that is really RWX code + a bytecode interpreter.
A 15-byte stub per call site pushes an (program RVA, entry index) pair and jumps
to a shared relocator, which:

  * caches the module base at state+0xEF,
  * lazily adds the base to a table of qword RVAs (the opcode dispatch table),
  * stores the program entry pointer at state+0xFB,
  * jumps to dispatch_table[entry index].

state is a per-module scratch structure (diskpt: RVA 0x2D200). Handler Dp_H079 is
the interpreter loop::

    opcode = *(u16*)ip;
    dispatch_table[opcode]();
    ip += <per-opcode length>;

So dispatch_table[] is a 136-entry opcode handler table and the "hidden code" is
bytecode for a register machine whose register file *is* the state structure
(operands are byte offsets into it; the instruction pointer itself lives at
state+0xFB).

Instruction encoding
--------------------
  u16 opcode ; N x u16 operand ; [trailing u8 flags]
Total length is fixed per opcode and is recovered from the handler's
``state[0xFB] += N``.

Usage
-----
  python vm.py <binary> --table-table <ida_export_dir> <program_rva> [more...]
  python vm.py <binary> --list-programs
"""
from __future__ import annotations

import argparse
import os
import re
import struct
import sys

# ---------------------------------------------------------------- PE helpers


class Image:
    def __init__(self, path: str):
        with open(path, "rb") as fh:
            self.data = fh.read()
        self.path = path
        pe = struct.unpack_from("<I", self.data, 0x3C)[0]
        if self.data[pe:pe + 4] != b"PE\0\0":
            raise ValueError("not a PE file: %s" % path)
        self.nsec = struct.unpack_from("<H", self.data, pe + 6)[0]
        self.optsz = struct.unpack_from("<H", self.data, pe + 20)[0]
        opt = pe + 24
        self.imagebase = struct.unpack_from("<Q", self.data, opt + 24)[0]
        self.sections = []
        sh = pe + 24 + self.optsz
        for i in range(self.nsec):
            o = sh + i * 40
            name = self.data[o:o + 8].rstrip(b"\0").decode("latin-1")
            vsz, va, rsz, ra = struct.unpack_from("<IIII", self.data, o + 8)
            ch = struct.unpack_from("<I", self.data, o + 36)[0]
            self.sections.append((name, va, vsz, ra, rsz, ch))

    def rva2off(self, rva: int) -> int | None:
        for _n, va, vsz, ra, rsz, _c in self.sections:
            if va <= rva < va + max(vsz, rsz):
                return ra + (rva - va)
        return None

    def read(self, rva: int, n: int) -> bytes:
        off = self.rva2off(rva)
        if off is None:
            raise ValueError("rva %#x not mapped" % rva)
        return self.data[off:off + n]

    def section_named(self, name: str):
        for s in self.sections:
            if s[0] == name:
                return s
        return None


# ------------------------------------------------- per-module VM descriptors

VM_PROFILES = {
    "diskpt.sys": dict(state=0x2D200, table=0x679A9, count=136),
    "Service.exe": dict(state=None, table=None, count=136),
    "Defender.exe": dict(state=None, table=None, count=136),
    "CmdTool.exe": dict(state=0x75400, table=0xADE73, count=126),
    "Commit.exe": dict(state=0xA4E00, table=None, count=126),
    "ShellExt.dll": dict(state=0x30800, table=None, count=126),
    "Uninstall.exe": dict(state=0x6F200, table=None, count=126),
}


def find_dispatch_table(img: Image, hint: int | None) -> tuple[int, int]:
    """Locate the (rva, count) of the qword RVA dispatch table inside the
    disguised section. Entries are plaintext RVAs that fall inside the same
    section; the table is the longest such run."""
    sec = img.section_named(".reloc")
    if sec is None:
        raise ValueError("no .reloc section")
    _n, va, vsz, ra, rsz, _c = sec
    end = va + max(vsz, rsz)
    if hint:
        # count how many consecutive qword RVAs follow the hint
        n = 0
        while True:
            v = struct.unpack_from("<Q", img.data, ra + (hint - va) + n * 8)[0]
            if not (va <= v < end):
                break
            n += 1
        return hint, n
    best, bestn = None, 0
    i = 0
    span = rsz
    while i + 8 <= span:
        n = 0
        while True:
            j = ra + i + n * 8
            if j + 8 > ra + span:
                break
            v = struct.unpack_from("<Q", img.data, j)[0]
            if not (va + 0x100 <= v < end):
                break
            n += 1
        if n > bestn:
            best, bestn = va + i, n
        i += 8 if n == 0 else n * 8
    return best, bestn


# ------------------------------------------- opcode lengths from IDA exports

LEN_RE = re.compile(
    r"// ===== Dp_H(\d+)_\w+ @ (0x[0-9a-f]+) size=(0x[0-9a-f]+) =====\n(.*?)(?=\n// ===== |\Z)",
    re.S,
)
ADV_RE = re.compile(r"\(v0 \+ 251\) \+= (\d+)LL;")


def load_opcode_lengths(export_dir: str) -> dict[int, int]:
    """Map opcode -> instruction length, parsed from the handler pseudocode."""
    lengths: dict[int, int] = {}
    for fn in ("hidden_pseudocode.c", "all_pseudocode.c"):
        path = os.path.join(export_dir, fn)
        if not os.path.exists(path):
            continue
        txt = open(path, encoding="utf-8", errors="replace").read()
        for idx, _ea, _size, body in LEN_RE.findall(txt):
            i = int(idx)
            if i in lengths:
                continue
            m = ADV_RE.search(body)
            if m:
                lengths[i] = int(m.group(1))
    return lengths


# ------------------------------------------------------------- disassembly

# state-structure slots recognised so far (diskpt family)
SLOTS = {
    0x1C: "FLAGS",
    0x54: "DISPATCH_BASE",
    0x69: "OPCODE_CACHE",
    0x9E: "SCRATCH_Q",
    0xA6: "SCRATCH_SRC",
    0xE7: "INIT_ONCE",
    0xEF: "IMAGE_BASE",
    0xFB: "IP",
}


def slot_name(off: int) -> str:
    return SLOTS.get(off, "V[%#x]" % off)


def disasm_program(img: Image, table_rva: int, start_rva: int, lengths: dict[int, int],
                   limit: int = 400, stop_rvas: set[int] | None = None):
    out = []
    ip = start_rva
    seen = set()
    for _ in range(limit):
        if ip in seen:
            out.append("  %#08x: (already visited - loop)" % ip)
            break
        seen.add(ip)
        if stop_rvas and ip in stop_rvas and ip != start_rva:
            out.append("  %#08x: <-> program boundary" % ip)
            break
        try:
            raw = img.read(ip, 32)
        except ValueError:
            out.append("  %#08x: <unmapped>" % ip)
            break
        op = struct.unpack_from("<H", raw, 0)[0]
        ln = lengths.get(op)
        if ln is None:
            out.append("  %#08x: op%03d (unknown length) bytes=%s" %
                       (ip, op, raw[:12].hex(" ")))
            break
        fields = []
        # operand area: everything after the u16 opcode
        n = ln - 2
        nwords = n // 2
        for k in range(nwords):
            fields.append(struct.unpack_from("<H", raw, 2 + k * 2)[0])
        tail = raw[2 + nwords * 2:ln]
        fdesc = " ".join(slot_name(f) if f > 0x80 else str(f) for f in fields)
        tdesc = (" tail=" + tail.hex()) if tail else ""
        out.append("  %#08x: op%03d  %s%s" % (ip, op, fdesc, tdesc))
        ip += ln
    return out, ip


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("programs", nargs="*", type=lambda s: int(s, 0))
    ap.add_argument("--exports", help="IDA export dir holding the handler pseudocode")
    ap.add_argument("--table", type=lambda s: int(s, 0), help="dispatch table RVA")
    ap.add_argument("--count", type=int, default=None)
    ap.add_argument("--limit", type=int, default=400)
    ap.add_argument("--list-programs", action="store_true")
    ap.add_argument("--find-tables", action="store_true")
    args = ap.parse_args()

    img = Image(args.image)
    print("# image=%s base=%#x" % (os.path.basename(args.image), img.imagebase))

    if args.find_tables:
        rva, n = find_dispatch_table(img, args.table)
        print("# dispatch table rva=%#x entries=%d" % (rva, n))
        return

    lengths = load_opcode_lengths(args.exports) if args.exports else {}
    print("# opcode lengths known: %d" % len(lengths))
    tdesc = sorted(lengths.items(), key=lambda kv: kv[1])
    bylen: dict[int, list[int]] = {}
    for idx, ln in tdesc:
        bylen.setdefault(ln, []).append(idx)
    for ln in sorted(bylen):
        print("#   len %2d : %s" % (ln, ",".join(str(i) for i in bylen[ln])))

    if args.list_programs:
        import re as _re
        asm = "all_disasm.asm"
        if args.exports and os.path.exists(os.path.join(args.exports, asm)):
            txt = open(os.path.join(args.exports, asm), encoding="utf-8", errors="replace").read()
            lines = txt.split("\n")
            found = []
            for i in range(len(lines) - 2):
                m1 = _re.match(r"^(0x[0-9a-f]+)\s+push\s+([0-9A-Fa-f]+)h", lines[i].strip())
                m2 = _re.match(r"^(0x[0-9a-f]+)\s+push\s+([0-9A-Fa-f]+)h", lines[i + 1].strip())
                if m1 and m2 and "jmp" in lines[i + 2] and "sub_2800B7DE9" in lines[i + 2]:
                    found.append((int(m1.group(2), 16), int(m2.group(2), 16)))
            print("# VM programs (program_rva, entry_index):")
            for rva, idx in found:
                print("#   %#08x  idx=%d" % (rva, idx))
        return

    for p in args.programs:
        print("\n===== program @ %#x =====" % p)
        out, end = disasm_program(img, args.table or 0, p, lengths, args.limit)
        print("\n".join(out))
        print("# ended at %#x" % end)


if __name__ == "__main__":
    main()
