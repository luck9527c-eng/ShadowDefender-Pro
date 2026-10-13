#!/usr/bin/env python3
"""Extract ASCII and UTF-16LE strings from a binary (no external deps).

Usage:
    python strings.py FILE [--min N] [--mode {a,w,b}] [--grep PATTERN] [--offset]
"""
import argparse
import re

_ASCII_RE = re.compile(rb"[\x20-\x7e]{%d,}")
_WIDE_RE = re.compile(rb"(?:[\x20-\x7e]\x00){%d,}")


def extract(data: bytes, minlen: int, mode: str):
    out = []
    if mode in ("a", "b"):
        for m in _ASCII_RE.pattern and re.compile(rb"[\x20-\x7e]{%d,}" % minlen).finditer(data):
            out.append((m.start(), "A", m.group().decode("latin-1")))
    if mode in ("w", "b"):
        for m in re.compile(rb"(?:[\x20-\x7e]\x00){%d,}" % minlen).finditer(data):
            out.append((m.start(), "W", m.group().decode("utf-16le")))
    out.sort(key=lambda t: t[0])
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("file")
    ap.add_argument("--min", type=int, default=5)
    ap.add_argument("--mode", choices=list("awb"), default="b")
    ap.add_argument("--grep", default=None, help="case-insensitive regex filter")
    ap.add_argument("--offset", action="store_true", help="prefix file offset")
    ap.add_argument("--no-dedup", action="store_true")
    args = ap.parse_args()

    with open(args.file, "rb") as fh:
        data = fh.read()

    pat = re.compile(args.grep, re.I) if args.grep else None
    seen = set()
    for off, kind, s in extract(data, args.min, args.mode):
        if pat and not pat.search(s):
            continue
        if not args.no_dedup:
            key = (kind, s)
            if key in seen:
                continue
            seen.add(key)
        print("%08x %s %s" % (off, kind, s) if args.offset else s)


if __name__ == "__main__":
    main()
