#!/usr/bin/env python3
"""Recover Shadow Defender's hidden dispatch scheme from a PE.

Scheme (observed in CmdTool/Commit/ShellExt, same family as diskpt.sys):
  * a section named ".reloc" that is RWX and much larger than the declared
    BASERELOC data directory;
  * 12-byte thunks of the form  68 <table_rva> 68 <index> e9 <rel32->thunk_core>;
  * a shared core thunk that lazily adds the image base to a 126-qword table
    and jumps through it.

This tool finds the stubs, resolves each one to its table entry, and can
disassemble the resolved targets with capstone.
"""
import argparse
import struct
import sys

import capstone

FB = 0x400  # typical .text raw pointer for these binaries


def pe(path):
    f = open(path, "rb").read()
    p = struct.unpack_from("<I", f, 0x3C)[0]
    nsec = struct.unpack_from("<H", f, p + 6)[0]
    optsz = struct.unpack_from("<H", f, p + 20)[0]
    m = struct.unpack_from("<H", f, p + 24)[0]
    ib = struct.unpack_from("<Q", f, p + 24 + 24)[0] if m == 0x20B else struct.unpack_from("<I", f, p + 24 + 28)[0]
    so = p + 24 + optsz
    secs = []
    for i in range(nsec):
        e = so + i * 40
        nm = f[e:e + 8].rstrip(b"\0").decode("latin-1")
        vsz, va, rsz, ptr = struct.unpack_from("<IIII", f, e + 8)
        ch = struct.unpack_from("<I", f, e + 36)[0]
        secs.append([nm, va, vsz, ptr, rsz, ch])
    dd = p + 24 + (112 if m == 0x20B else 96)
    brva, bsz = struct.unpack_from("<II", f, dd + 5 * 8)
    return f, ib, secs, brva, bsz


def r2o(secs, rva):
    for nm, va, vsz, ptr, rsz, ch in secs:
        if va <= rva < va + max(vsz, rsz):
            return ptr + rva - va
    return None


def read_rva(f, secs, rva, n):
    o = r2o(secs, rva)
    if o is None:
        return None
    return f[o:o + n]


def find_stubs(f, ib, secs):
    out = []
    for nm, va, vsz, ptr, rsz, ch in secs:
        blob = f[ptr:ptr + rsz]
        for i in range(len(blob) - 12):
            if blob[i] != 0x68 or blob[i + 5] != 0x68 or blob[i + 10] != 0xE9:
                continue
            t = struct.unpack_from("<I", blob, i + 1)[0]
            idx = struct.unpack_from("<I", blob, i + 6)[0]
            rel = struct.unpack_from("<i", blob, i + 11)[0]
            tgt = ib + va + i + 15 + rel
            out.append((ib + va + i, t, idx, tgt))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("--list-stubs", action="store_true")
    ap.add_argument("--limit", type=int, default=40)
    ap.add_argument("--disasm", help="rva to disassemble")
    ap.add_argument("--len", type=lambda s: int(s, 0), default=0x200)
    ap.add_argument("--qwords", help="rva:count to dump qwords")
    args = ap.parse_args()

    f, ib, secs, brva, bsz = pe(args.file)
    print("imagebase=%#x  BASERELOC rva=%#x size=%#x" % (ib, brva, bsz))
    for nm, va, vsz, ptr, rsz, ch in secs:
        print("  %-9s VA=%012x VSZ=%07x RAW=%07x CH=%08x" % (nm, ib + va, vsz, rsz, ch))

    if args.disasm:
        rva = int(args.disasm, 16)
        o = r2o(secs, rva)
        md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
        for ins in md.disasm(f[o:o + args.len], ib + rva):
            print("%012x  %-7s %s" % (ins.address, ins.mnemonic, ins.op_str))
        return

    if args.qwords:
        rva, cnt = args.qwords.split(":")
        rva = int(rva, 16)
        cnt = int(cnt, 0)
        for k in range(cnt):
            v = struct.unpack("<Q", read_rva(f, secs, rva + k * 8, 8))[0]
            mark = ""
            if 0x1000 <= v < 0x100000:
                mark = "  <- rva"
            print("[%3d] rva %#x = %#018x%s" % (k, rva + k * 8, v, mark))
        return

    stubs = find_stubs(f, ib, secs)
    print("stubs found: %d" % len(stubs))
    for va, t, idx, tgt in stubs[:args.limit]:
        ent_rva = t + idx * 8
        raw = read_rva(f, secs, ent_rva, 8)
        ent = struct.unpack("<Q", raw)[0] if raw else None
        print("stub@%012x table=%#x idx=%#x -> thunk %012x ; entry rva=%#x val=%s" %
              (va, t, idx, tgt, ent_rva, ("%#x" % ent) if ent is not None else "OOB"))


main()
