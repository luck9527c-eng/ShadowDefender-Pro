import idc, ida_segment, ida_ida, ida_bytes, ida_funcs, idautils
out=[]
out.append("SEGATTR_* : " + ",".join(n for n in dir(ida_segment) if n.startswith("SEGATTR")))
out.append("seg funcs : " + ",".join(n for n in dir(ida_segment) if "segm" in n or "segment" in n))
out.append("idc seg   : " + ",".join(n for n in dir(idc) if "segm" in n or "segment" in n))
out.append("SEGPERM   : " + ",".join(n for n in dir(ida_segment) if n.startswith("SEGPERM")))
out.append("set_segment_type: %s" % hasattr(ida_segment,"set_segment_type"))
out.append("set_segm_class: %s" % hasattr(ida_segment,"set_segm_class"))
open(r"D:\workSpace\ShadowDefender-Pro\recon\unhide\probe.txt","w").write("\n".join(out))
idc.qexit(0)
