#!/usr/bin/env python3
"""Ad-hoc VA-based disassembler for the Shadow Defender samples.

Usage:
    python.discalc.py FILE --start 0x1400B5B6D --len 0x400
    python.discalc.py FILE --rva 0xB5B6D --len 0x200
    python.discalc.py FILE --foff 0x6be00 --len 0x200
"""
import argparse
import struct
import sys

import capstone

SECT = []


def load(path):
    data = open(path, "rb").read()
    pe = struct.unpack_from("<I", data, 0x3C)[0]
    nsec = struct.unpack_from("<H", data, pe + 6)[0]
    optsz = struct.unpack_from("<H", data, pe + 20)[0]
    magic = struct.unpack_from("<H", data, pe + 24)[0]
    if magic == 0x20B:
        imgbase = struct.unpack_from("<Q", data, pe + 24 + 24)[0]
    else:
        imgbase = struct.unpack_from("<I", data, pe + 24 + 28)[0]
    so = pe + 24 + optsz
    secs = []
    for i in range(nsec):
        e = so + i * 40
        nm = data[e:e + 8].rstrip(b"\0").decode("latin-1")
        vsz, va, rsz, ptr = struct.unpack_from("<IIII", data, e + 8)
        chars = struct.unpack_from("<I", data, e + 36)[0]
        secs.append((nm, va, vsz, ptr, rsz, chars))
    return data, imgbase, secs


def rva_to_off(secs, rva):
    for nm, va, vsz, ptr, rsz, ch in secs:
        if va <= rva < va + max(vsz, rsz):
            return ptr + (rva - va)
    return None


def off_to_rva(secs, off):
    for nm, va, vsz, ptr, rsz, ch in secs:
        if ptr <= off < ptr + rsz:
            return va + (off - ptr)
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("--start")
    ap.add_argument("--rva")
    ap.add_argument("--foff")
    ap.add_argument("--len", type=lambda s: int(s, 0), default=0x200)
    ap.add_argument("--sections", action="store_true")
    ap.add_argument("--mode", default="64")
    args = ap.parse_args()

    data, imgbase, secs = load(args.file)
    if args.sections:
        for nm, va, vsz, ptr, rsz, ch in secs:
            print("%-10s VA=%08x VSZ=%08x PTR=%08x RAW=%08x CH=%08x" % (nm, imgbase + va, vsz, ptr, rsz, ch))
        return
    if args.start:
        va = int(args.start, 16)
    elif args.rva:
        va = imgbase + int(args.rva, 16)
    elif args.foff:
        off = int(args.foff, 16)
        rva = off_to_rva(secs, off)
        va = imgbase + rva
    else:
        ap.error("need --start/--rva/--foff")

    off = rva_to_off(secs, va - imgbase)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64 if args.mode == "64" else capstone.CS_MODE_32)
    md.detail = False
    code = data[off:off + args.len]
    n = 0
    for ins in md.disasm(code, va):
        print("%08x  %-8s %s" % (ins.address, ins.mnemonic, ins.op_str))
        n += 1
    print(";; %d instructions from %#x (file off %#x)" % (n, va, off))


main()
