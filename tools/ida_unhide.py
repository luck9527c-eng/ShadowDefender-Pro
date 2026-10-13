# Expose the driver's hidden control-plane code (revision 2).
#
# diskpt.sys declares a genuine BASERELOC directory of only 0x18 bytes, while the
# section *named* ".reloc" spans 0x48334 bytes. Everything past the real
# relocation block is disguised code, entered through a 136-entry dispatch table
# at RVA 0x679A9 whose entries are RVAs resolved by a runtime thunk.
#
# This script renames and re-classes the region as code, seeds a function at
# every dispatch-table target, and dumps what the decompiler recovers.
#
# Usage: idat.exe -A -S"ida_unhide.py <outdir>" <diskpt.sys>

import os
import traceback

import ida_auto
import ida_bytes
import ida_funcs
import ida_hexrays
import ida_name
import ida_nalt
import ida_segment
import idautils
import idc

TABLE_RVA = 0x679A9
TABLE_COUNT = 136
SEC_NAME = ".reloc"
SEGATTR_PERM = 5
SEGPERM_RX = 1 | 4


def w(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", errors="replace") as fh:
        fh.write(text)


def main():
    out = idc.ARGV[1] if len(idc.ARGV) > 1 else "."
    os.makedirs(out, exist_ok=True)
    ida_auto.auto_wait()

    try:
        imagebase = ida_nalt.get_imagebase()
    except Exception:
        imagebase = 0x280050000
    log = ["imagebase=%#x" % imagebase]

    seg = None
    for ea in idautils.Segments():
        s = ida_segment.getseg(ea)
        if ida_segment.get_segm_name(s) == SEC_NAME:
            seg = s
            break
    if seg is None:
        w(os.path.join(out, "UNHIDE_ERROR.txt"), "section %s not found" % SEC_NAME)
        return
    log.append("section %s %#x-%#x" % (SEC_NAME, seg.start_ea, seg.end_ea))
    start = seg.start_ea

    # 1) permissions: read + exec
    try:
        log.append("set_segm_attr(PERM) -> %r" % idc.set_segm_attr(start, SEGATTR_PERM, SEGPERM_RX))
    except Exception as exc:  # noqa: BLE001
        log.append("set_segm_attr failed: %r" % exc)

    # 2) class -> CODE, then rename away from ".reloc" so the decompiler stops
    #    treating the region as read-only data.
    try:
        log.append("set_segm_class -> %r" % idc.set_segm_class(start, "CODE"))
    except Exception as exc:  # noqa: BLE001
        log.append("set_segm_class failed: %r" % exc)
    try:
        log.append("set_segm_name -> %r" % idc.set_segm_name(start, ".dpcode"))
    except Exception as exc:  # noqa: BLE001
        log.append("set_segm_name failed: %r" % exc)

    # 3) the 24 real relocation bytes are data, not code
    try:
        idc.del_items(imagebase + 0x2D000, idc.DELIT_SIMPLE, 0x18)
    except Exception as exc:  # noqa: BLE001
        log.append("del_items reloc header failed: %r" % exc)

    # 4) seed functions at each dispatch-table target
    table_ea = imagebase + TABLE_RVA
    made, failed = 0, []
    for i in range(TABLE_COUNT):
        v = ida_bytes.get_qword(table_ea + i * 8)
        if v == 0:
            continue
        target = imagebase + v
        try:
            idc.del_items(target, idc.DELIT_SIMPLE, 0x10)
            ci = idc.create_insn(target)
            fn = ida_funcs.add_func(target)
            if ci and fn:
                made += 1
                ida_name.set_name(target, "Dp_H%03d_%x" % (i, v), ida_name.SN_NOCHECK)
            else:
                failed.append("idx%d rva=%#x create_insn=%r add_func=%r" % (i, v, ci, fn))
        except Exception as exc:  # noqa: BLE001
            failed.append("idx%d rva=%#x exc=%r" % (i, v, exc))
    log.append("table targets seeded=%d failed=%d" % (made, len(failed)))
    log.extend(failed[:50])

    # 5) let auto-analysis chase calls out of the seeded entries
    ida_auto.auto_wait()
    ida_auto.auto_wait()

    # 6) dump everything inside the hidden range
    flines, bodies, dis, dec = [], [], [], 0
    for i in range(ida_funcs.get_func_qty()):
        fn = ida_funcs.getn_func(i)
        if fn is None or fn.start_ea < start:
            continue
        ea = fn.start_ea
        name = ida_funcs.get_func_name(ea)
        size = fn.end_ea - fn.start_ea
        flines.append("%#010x size=%#-6x %s" % (ea, size, name))
        try:
            cf = ida_hexrays.decompile(ea)
        except Exception:
            cf = None
        if cf is not None:
            dec += 1
            bodies.append("// ===== %s @ %#x size=%#x =====\n%s\n" % (name, ea, size, cf))
        else:
            bodies.append("// ===== %s @ %#x (no pseudocode) =====\n" % (name, ea))
        dis.append("// ===== %s @ %#x =====\n" % (name, ea))
        for item in idautils.FuncItems(ea):
            dis.append("%#010x  %s" % (item, idc.generate_disasm_line(item, idc.GENDSM_FORCE_CODE)))
        dis.append("")

    w(os.path.join(out, "hidden_functions.txt"), "\n".join(flines) + "\n")
    w(os.path.join(out, "hidden_pseudocode.c"), "\n".join(bodies) + "\n")
    w(os.path.join(out, "hidden_disasm.asm"), "\n".join(dis) + "\n")
    w(os.path.join(out, "unhide_log.txt"), "\n".join(log) + "\n")
    print("UNHIDE DONE hidden_funcs=%d decompiled=%d" % (len(flines), dec))


try:
    main()
except Exception:
    traceback.print_exc()
    w(os.path.join(".", "UNHIDE_TRACEBACK.txt"), traceback.format_exc())

idc.qexit(0)
