# IDA batch export script for the Shadow Defender reconstruction.
# Usage: idat.exe -A -S"ida_export.py <outdir>" -L<log> <input>
# Dumps functions, pseudocode, strings+xrefs, imports, names to <outdir>.

import os
import sys
import traceback

import ida_auto
import ida_bytes
import ida_entry
import ida_funcs
import ida_hexrays
import ida_ida
import ida_nalt
import ida_name
import ida_segment
import idautils
import idc


def get_outdir():
    args = idc.ARGV[1:] if len(idc.ARGV) > 1 else []
    if args:
        return args[0]
    base = os.path.dirname(idc.get_idb_path())
    return os.path.join(base, "export")


def w(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", errors="replace") as fh:
        fh.write(text)


def main():
    out = get_outdir()
    os.makedirs(out, exist_ok=True)
    ida_auto.auto_wait()

    meta = []
    meta.append("input=%s" % ida_nalt.get_input_file_path())
    meta.append("idb=%s" % idc.get_idb_path())
    meta.append("imagebase=%#x" % ida_ida.inf_get_min_ea())
    meta.append("proc=%s" % ida_ida.inf_get_procname())
    meta.append("bits=%d" % ida_ida.inf_get_app_bitness())
    w(os.path.join(out, "meta.txt"), "\n".join(meta) + "\n")

    # ---- segments ----
    lines = []
    for seg_ea in idautils.Segments():
        s = ida_segment.getseg(seg_ea)
        lines.append(
            "%-10s %#010x-%#010x size=%#x perm=%s class=%s"
            % (
                ida_segment.get_segm_name(s),
                s.start_ea,
                s.end_ea,
                s.end_ea - s.start_ea,
                "%c%c%c"
                % (
                    "R" if s.perm & ida_segment.SEGPERM_READ else "-",
                    "W" if s.perm & ida_segment.SEGPERM_WRITE else "-",
                    "X" if s.perm & ida_segment.SEGPERM_EXEC else "-",
                ),
                ida_segment.get_segm_class(s),
            )
        )
    w(os.path.join(out, "segments.txt"), "\n".join(lines) + "\n")

    # ---- imports / exports ----
    imp, exp = [], []
    for i in range(ida_nalt.get_import_module_qty()):
        mod = ida_nalt.get_import_module_name(i) or "?"
        def cb(ea, name, ordinal):
            imp.append("%-24s %#010x %s" % (mod, ea, name or ("#%d" % ordinal)))
            return True
        ida_nalt.enum_import_names(i, cb)
    n_exp = ida_entry.get_entry_qty()
    for i in range(n_exp):
        ea = ida_entry.get_entry_ordinal(i)
        exp.append("%#010x %s" % (ida_entry.get_entry(ea), ida_entry.get_entry_name(ea)))
    w(os.path.join(out, "imports.txt"), "\n".join(sorted(set(imp))) + "\n")
    w(os.path.join(out, "exports.txt"), "\n".join(exp) + "\n")

    # ---- strings and their code xrefs (invaluable: trace strings name functions) ----
    slines = []
    for item in idautils.Strings():
        ea = item.ea
        stype = item.strtype
        try:
            sv = str(item)
        except Exception:
            sv = repr(item)
        refs = []
        for xref in idautils.XrefsTo(ea, 0):
            fn = ida_funcs.get_func(xref.frm)
            fname = ida_funcs.get_func_name(fn.start_ea) if fn else "?"
            refs.append("%#x(%s)" % (xref.frm, fname))
        slines.append(
            "%#010x type=%d len=%d refs=%s\n    %s"
            % (ea, stype, len(sv), ",".join(refs[:12]), sv)
        )
    w(os.path.join(out, "strings.txt"), "\n".join(slines) + "\n")

    # ---- functions + pseudocode ----
    flines, decl, bodies = [], [], []
    total = ida_funcs.get_func_qty()
    decompiled = 0
    for i in range(total):
        fn = ida_funcs.getn_func(i)
        if fn is None:
            continue
        ea = fn.start_ea
        name = ida_funcs.get_func_name(ea)
        size = fn.end_ea - fn.start_ea
        callers = []
        for x in idautils.XrefsTo(ea, 0):
            f2 = ida_funcs.get_func(x.frm)
            callers.append(ida_funcs.get_func_name(f2.start_ea) if f2 else "?")
        flines.append(
            "%#010x size=%#-6x %s callers=%s"
            % (ea, size, name, ",".join(sorted(set(callers))[:16]))
        )
        decl.append("%#010x %s" % (ea, name))

        try:
            cf = ida_hexrays.decompile(ea)
        except Exception:
            cf = None
        if cf is None:
            bodies.append("// ===== %s @ %#x (no pseudocode) =====\n" % (name, ea))
            continue
        decompiled += 1
        bodies.append("// ===== %s @ %#x size=%#x =====\n%s\n" % (name, ea, size, cf))

    w(os.path.join(out, "functions.txt"), "\n".join(flines) + "\n")
    w(os.path.join(out, "all_pseudocode.c"), "\n".join(bodies) + "\n")

    # ---- raw disassembly for every function ----
    dis = []
    for i in range(total):
        fn = ida_funcs.getn_func(i)
        if fn is None:
            continue
        name = ida_funcs.get_func_name(fn.start_ea)
        dis.append("// ===== %s @ %#x =====\n" % (name, fn.start_ea))
        for item_ea in idautils.FuncItems(fn.start_ea):
            dis.append(
                "%#010x  %s"
                % (item_ea, idc.generate_disasm_line(item_ea, idc.GENDSM_FORCE_CODE))
            )
        dis.append("")
    w(os.path.join(out, "all_disasm.asm"), "\n".join(dis) + "\n")

    # ---- global data / named locations ----
    nlines = []
    for ea, nm in idautils.Names():
        nlines.append("%#010x %s" % (ea, nm))
    w(os.path.join(out, "names.txt"), "\n".join(nlines) + "\n")

    print(
        "EXPORT DONE functions=%d decompiled=%d strings=%d -> %s"
        % (total, decompiled, len(slines), out)
    )


try:
    main()
except Exception:
    with open(os.path.join(os.path.dirname(idc.get_idb_path()), "EXPORT_ERROR.txt"), "w") as fh:
        fh.write(traceback.format_exc())
    traceback.print_exc()

idc.qexit(0)
