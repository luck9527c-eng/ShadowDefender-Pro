#!/usr/bin/env python3
"""Print function blocks from an IDA hexrays export.

Usage:
    python fn.py <all_pseudocode.c> <name-or-regex> [--head N] [--max N]
    python fn.py <all_pseudocode.c> --list
"""
import argparse
import re
import sys

BLOCK = re.compile(r"// ===== (.+?) @ (0x[0-9a-f]+)(?: size=(0x[0-9a-f]+))? =====\n(.*?)(?=\n// ===== |\Z)",
                   re.S)


def load(path):
    txt = open(path, encoding="utf-8", errors="replace").read()
    return BLOCK.findall(txt)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("pattern", nargs="?")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--head", type=int, default=None, help="print only the first N lines of each body")
    ap.add_argument("--max", type=int, default=4, help="max blocks to print")
    args = ap.parse_args()

    blocks = load(args.file)
    if args.list:
        for name, ea, size, _b in blocks:
            print("%s @ %s size=%s" % (name, ea, size))
        return

    pat = re.compile(args.pattern)
    n = 0
    for name, ea, size, body in blocks:
        if not pat.search(name) and not pat.search(ea):
            continue
        print("// ===== %s @ %s size=%s =====" % (name, ea, size))
        lines = body.split("\n")
        if args.head:
            lines = lines[: args.head]
        print("\n".join(lines))
        print()
        n += 1
        if n >= args.max:
            break
    if n == 0:
        sys.stderr.write("no match for %r\n" % args.pattern)


if __name__ == "__main__":
    main()
