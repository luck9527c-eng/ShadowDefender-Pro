#!/usr/bin/env python3
"""Map file offsets <-> RVAs for a PE, and find immediate references to an RVA in a binary.

Usage:
    python refs.py FILE --foff 0x48870
    python refs.py FILE --rva 0x4cc10
    python refs.py FILE --grep "Password is not"        # find strings and their RVAs
    python refs.py FILE --scan-rva 0x4cc10             # find lea/mov references to that RVA
"""
import argparse
import re
import struct
import sys


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
        secs.append((nm, va, vsz, ptr, rsz))
    return f, ib, secs


def o2r(secs, off):
    for nm, va, vsz, ptr, rsz in secs:
        if ptr <= off < ptr + rsz:
            return va + off - ptr
    return None


def r2o(secs, rva):
    for nm, va, vsz, ptr, rsz in secs:
        if va <= rva < va + max(vsz, rsz):
            return ptr + rva - va
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("--foff")
    ap.add_argument("--rva")
    ap.add_argument("--grep")
    ap.add_argument("--scan-rva")
    ap.add_argument("--scan-str")
    args = ap.parse_args()
    f, ib, secs = pe(args.file)
    if args.foff:
        o = int(args.foff, 16)
        r = o2r(secs, o)
        print("foff %#x -> rva %#x -> va %#x" % (o, r, ib + r))
    if args.rva:
        r = int(args.rva, 16)
        o = r2o(secs, r)
        print("rva %#x -> va %#x file %#x" % (r, ib + r, o))
        print(repr(f[o:o + 120]))
    if args.grep:
        pat = re.compile(args.grep.encode("utf-16le"))
        for m in pat.finditer(f):
            r = o2r(secs, m.start())
            if r is None:
                continue
            end = f.find(b"\0\0", m.start())
            s = f[m.start():end + 1].decode("utf-16le", "replace")
            print("foff %#08x rva %#06x va %#012x  %s" % (m.start(), r, ib + r, s))
    if args.scan_str:
        # scan for any 4-byte little-endian value pointing into .rdata whose target starts with the string
        pass
    if args.scan_rva:
        tgt = int(args.scan_rva, 16)
        b = struct.pack("<I", tgt)
        print("references to rva %#x:" % tgt)
        for m in re.finditer(re.escape(b), f):
            r = o2r(secs, m.start())
            if r is None:
                continue
            print("  ref at foff %#x rva %#x va %#x" % (m.start(), r, ib + r))


main()
