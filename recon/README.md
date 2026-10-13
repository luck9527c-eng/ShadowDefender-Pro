# `recon/` — raw evidence and how to regenerate it

This directory holds the machine-generated evidence behind every claim in
`docs/`. Nothing here is hand-written analysis; the hand-written analysis is in
`docs/` and `recon/analysis/`.

## What is here

| Path | Content |
| --- | --- |
| `verification.md` | Short runnable checks confirming the headline findings. Start here. |
| `analysis/defender_gui.md` | Sub-investigation: `Defender.exe` + `DefenderDaemon.exe`. |
| `analysis/cli_and_shell.md` | Sub-investigation: `CmdTool.exe`, `Commit.exe`, `ShellExt.dll`, `Uninstall.exe`. |
| `ida/<module>/` | IDA 9.4 exports of each module (see below). |
| `unhide/` | The recovered hidden-VM artifacts for `diskpt.sys`: the re-classified functions, their pseudocode and disassembly, plus the opcode table derived from them. |
| `diskpt.strings.ascii.txt`, `diskpt.strings.wide.txt` | Raw ASCII and UTF-16LE string dumps of the driver. |

### Per-module IDA export contents

Each `ida/<module>/` directory is produced by `tools/ida_export.py` and contains:

| File | Content |
| --- | --- |
| `all_pseudocode.c` | Hex-Rays pseudocode for every function, delimited by `// ===== <name> @ <addr> size=<n> =====`. Cited throughout `docs/`. |
| `all_disasm.asm` | Raw disassembly for every function, same delimiters. Use this rather than the pseudocode for anything about the obfuscated VM — Hex-Rays' rendering of the identity arithmetic is misleading. |
| `functions.txt` | One line per function: address, size, name, callers. |
| `strings.txt` | Every string with its address, length and **code cross-references**. This is the fastest index into a module; the driver's `diskpt!Stor…` trace strings name whole subsystems. |
| `imports.txt`, `exports.txt` | Imports with IAT addresses and the export table. |
| `names.txt` | All named locations, including globals. |
| `segments.txt`, `meta.txt` | Section map with permissions, and image base / architecture. |

Modules present: `diskpt` (driver), `Service`, `Defender`, `DefenderDaemon`,
`CmdTool`, `Commit`, `ShellExt`, `Uninstall`.

## What is deliberately absent

The vendor's executables and driver are **commercial software and are not
redistributed here**; `.gitignore` excludes `samples/*.exe`, `samples/*.dll`,
`samples/*.sys` and `work/`. The analysis is fully reproducible from an installed
copy: restore the binaries into `samples/`, confirm them against the SHA-256
values in `README.md` §8, and re-run the exports.

## Regenerating this directory

Prerequisites: IDA Pro 9.4 at `/d/Apps/IDApro` (adjust the paths below), Python 3,
and the binaries in `samples/`.

```bash
# 1. Pseudocode / disassembly / strings-with-xrefs for one module
/d/Apps/IDApro/idat.exe -A \
  -S"$PWD/tools/ida_export.py $PWD/recon/ida/diskpt" \
  -L"$PWD/recon/ida/diskpt.log" samples/diskpt.sys

#    ... repeat for Service.exe, Defender.exe, DefenderDaemon.exe, CmdTool.exe,
#    Commit.exe, ShellExt.dll, Uninstall.exe

# 2. Recover the hidden ".reloc" vault of the driver and decompile it.
#    Runs on a copy so the original IDB is untouched.
cp samples/diskpt.sys work/diskpt_work.sys
/d/Apps/IDApro/idat.exe -A \
  -S"$PWD/tools/ida_unhide.py $PWD/recon/unhide" \
  -L"$PWD/recon/unhide/unhide.log" work/diskpt_work.sys

# 3. Raw strings of the driver
python tools/strings.py samples/diskpt.sys --min 6 --mode a > recon/diskpt.strings.ascii.txt
python tools/strings.py samples/diskpt.sys --min 6 --mode w > recon/diskpt.strings.wide.txt

# 4. Sanity checks
python tools/vm.py samples/diskpt.sys --find-tables      # -> rva=0x679a9 entries=136
python tools/vm.py samples/diskpt.sys --exports recon/unhide --list-programs
```

`tools/ida_export.py` and `tools/ida_unhide.py` are tolerant of re-runs: the
unhide script creates a fresh database each time, and both write their output
into the directory passed as the script argument.

## Provenance

All exports were produced with **IDA Pro 9.4** (Hex-Rays decompiler,
`hexx64.dll`) on Windows 10 x64. Each module's `meta.txt` records the input path,
image base, processor and bitness. The unhide run's own log
(`unhide/unhide_log.txt`) records how many dispatch-table targets were seeded and
which ones were already covered by auto-analysis.
