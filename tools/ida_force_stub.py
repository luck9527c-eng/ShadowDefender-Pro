# Force the native IOCTL demultiplexer inside sub_2800630D8 to be analysed.
# IDA stops at the unconditional jmp at 0x280063101 and never decodes the
# ~2,900 bytes that follow, which is where the IOCTL switch actually lives.
import os, ida_auto, ida_funcs, ida_hexrays, idc, idautils

OUT = idc.ARGV[1] if len(idc.ARGV) > 1 else "."
ida_auto.auto_wait()

STUB = 0x2800630D8
CODE = 0x280063121          # first real instruction after the obfuscated prologue

log = []
try:
    if ida_funcs.get_func(STUB):
        log.append("del_func -> %r" % ida_funcs.del_func(STUB))
    log.append("del_items -> %r" % idc.del_items(CODE, idc.DELIT_SIMPLE, 0x40))
    log.append("create_insn -> %r" % idc.create_insn(CODE))
    log.append("add_func -> %r" % ida_funcs.add_func(CODE))
except Exception as e:
    log.append("prep failed: %r" % e)

ida_auto.auto_wait(); ida_auto.auto_wait()

# seed the branch targets the linear sweep discovered
for t in (0x280063152,0x2800631a6,0x2800631ae,0x2800631df,0x2800631ed,0x280063228,
          0x280063239,0x280063243,0x280063256,0x28006325a,0x280063261,0x28006326c,
          0x280063293,0x280063324,0x280063343,0x2800633ac,0x2800633b7,0x2800633f6,
          0x28006345c,0x2800634b1,0x2800634ba,0x2800634c1,0x2800634cd,0x2800634d7,
          0x2800634e3,0x280063538,0x280063541,0x280063548,0x280063554,0x280063567,
          0x2800635b9,0x280063632,0x280063672,0x28006375f,0x280063797,0x2800639c1,
          0x280063c02,0x280063c13,0x280063c1d):
    try:
        idc.create_insn(t)
    except Exception:
        pass

ida_auto.auto_wait(); ida_auto.auto_wait()

lines = []
f = ida_funcs.get_func(CODE)
if f:
    lines.append("FUNCTION %#x .. %#x" % (f.start_ea, f.end_ea))
    try:
        lines.append(str(ida_hexrays.decompile(f.start_ea)))
    except Exception as e:
        lines.append("decompile failed: %r" % e)
    lines.append("")
    for ea in idautils.FuncItems(f.start_ea):
        lines.append("%#010x  %s" % (ea, idc.generate_disasm_line(ea, idc.GENDSM_FORCE_CODE)))
else:
    lines.append("no function at %#x" % CODE)

os.makedirs(OUT, exist_ok=True)
open(os.path.join(OUT, "ioctl_demux.c"), "w", encoding="utf-8").write("\n".join(lines))
open(os.path.join(OUT, "force_log.txt"), "w", encoding="utf-8").write("\n".join(log))
print("FORCE DONE")
idc.qexit(0)
