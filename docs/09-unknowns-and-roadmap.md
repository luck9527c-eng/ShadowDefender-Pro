# Shadow Defender — Residual Unknowns and Decode Roadmap

> This file is the honest boundary of the reconstruction. Everything listed as
> **unknown** below is *not* established by the evidence in this repository; do
> not treat neighbouring inferences as substitutes.

## 1. What is established

| Area | Confidence | Basis |
| --- | --- | --- |
| Component inventory, identities, hashes, versions, install layout | observed | PE resources, filesystem, registry |
| Storage-stack placement (disk upper filter, volume lower filter, boot-start) | observed | class filter keys, service values |
| Driver device model, names, SDDL, pool tag | observed | `DriverEntry`, `.rdata` strings |
| Shadow storage model (bitmap, map file, chunk directory, NTFS `$Bitmap` fixup) | observed + inferred | `Stor*` trace strings, native pseudocode |
| Registry shadow hives | observed | driver strings, `ZwLoadKey`/`ZwUnloadKey` |
| Boot/hibernation handling | observed | BCD path, `dpstart.exe`, `BootExecute` |
| IRP dispatch table for the driver | observed | `sub_28005F5CC` |
| User-mode password, registration, trial, `hash2`, RC4, update check | observed | hexrays of the user-mode modules (non-VM regions) |
| All persistent formats (`user.dat`, `res.ini`, `diskpt.crt`, `diskpt.dat`, `diskptex.dat`) | observed (field meanings partly inferred) | files on disk + readers in code |
| CLI grammar, shell integration, uninstall order | observed | hexrays + registry + files |
| IPC topology (which device/object/mutex, who uses it) | observed | imports, call sites, object names |
| Obfuscation scheme (`.reloc` vault, relocator, VM, tables, programs) | observed | section table, disassembly, the unhide toolchain |

## 1a. Resolved since the first pass

The installation package (`docs/10-installer.md`) answered four questions that
the installed tree alone could not:

| Question | Resolution | Evidence |
| --- | --- | --- |
| Which driver image is actually installed? | The package's **`diskpt.win10.sys`**, renamed to `diskpt.sys`. The package also carries a 2017 `diskpt.sys` (v1.4.0.672) for older systems. | SHA-256 identical; `recon/verification.md` V7 |
| Where does the password salt `GUID` come from? | The **installer** generates it with `CoCreateGuid` and writes `HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID`. The driver contains no GUID logic. | installer strings + `CoCreateGuid` IAT; driver has no `GUID` string |
| Who is the vendor for the 1.5 line? | Installer and 2020 driver are EV-signed by **Beijing YiChengWeiLai Culture-Tech Co., Ltd.**; the 2017 driver by **StarSoftComm(China) Ltd.** | Authenticode on every artefact |
| Why `DefenderDaemon.exe` when the payload says `Daemon.exe`? | Renamed during install; the files are byte-identical. | SHA-256 identical |

Two related facts also emerged: the driver is deployed by **file copy plus
service-key creation**, not by an INF (the package contains no `.inf`), and the
same `.reloc`/VM obfuscation framework is present in the 1.4 driver as well,
with a slightly smaller vault (`0x45518` vs `0x48334`).

## 2. What is unknown

### 2.1 `\\.\DpControl` payload above the magic — RESOLVED

**Closed.** The payload is not parsed by the VM: the VM returns into an
undecoded native region that contains the real demultiplexer. See
`docs/12-ioctl-protocol.md`. Summary:

* 136-byte in/out buffer; both `InputBufferLength` and `OutputBufferLength` must
  equal `0x88`;
* `DWORD[0] = 0x74706B64 ('dkpt')`, `DWORD[1] = command`, `QWORD[2..3]` = args;
* fixed IOCTLs: `0x8000309C` (session/ID), `0x800030A0` (returns the 128-byte
  installation blob), `0x80000CD4` (register calling process),
  `0x80000D18` (teardown), `0x80002D48` (volume flag; returns `0x20000001`);
* command channel: `0, 101, 102, 200, 201, 202, 300, 500, 501` — progress
  events, session thread registration, file-handle registration, write-cache
  set/get.

Still open: command 0, the VM-derived IOCTL number for the command channel, and
the 128-byte installation-blob layout.

### 2.2 Driver-side operation set

The 27 VM programs in `diskpt.sys` (`0x67E9D` … `0x7503A`) are not yet attributed
to operations. Attributing them requires either decoding the VM or observing
runtime behaviour.

### 2.3 Bytecode instruction semantics

Recovered: instruction encoding shape, 71 opcode lengths with certainty, the
`IP`-slot convention, and the semantics of opcodes 1, 2, 3, 10, 12, 79 (~5 % of
the set). **The length table is now validated against real execution** — see
`docs/11-vm-emulation.md` §3.1. Unknown: the remaining ~130 opcodes' semantics,
the branch/predicate encoding for the variable-length control-flow opcodes, and
the calling convention used by the "call" opcodes (opcode 0 and the 20-byte
forms 14/45).

A working Unicorn harness exists (`tools/vm_emu.py`, `tools/vm_emu_ioctl.py`).
It executes the vendor handlers and records the true dispatch sequence, but a
cold, zeroed VM state is not sufficient: the DEVICE_CONTROL program runs a
50-opcode data-loading prologue and then unwinds (`docs/11` §3–§4). The next step
is to warm the state by running `DriverEntry` and the INIT programs first, or to
replay a live-captured state.

### 2.4 `diskpt.crt` field semantics

The 64-byte file contains four 16-byte records. The `state` field of record 0 is
`0` and of records 1–3 is `1`, `3`, `3`. On a three-volume host that *looks* like
"C: normal, D:/E: configured, 3 = persist across boot", but the identity and size
fields are not confirmed, and the driver validates three dwords per record
(`invalid config info(%x-%x-%x)`).

### 2.5 `diskpt0.sys` map-file header

Known: 512-byte header, created hidden + system + write-through + compressed,
size computed from disk geometry, validated by a three-dword match and by
`map file size == volume size`, and re-validated by `FsfTestVolume`. Unknown: the
bitmap/table geometry fields inside the header. The analysis host had no volume
in Shadow Mode, so no sample file existed to read.

### 2.6 Chunk naming

`X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\%08x%08x` is the chunk file pattern.
What the two 32-bit ordinals mean (sector index and generation? window and offset?)
is inferred but unconfirmed.

### 2.7 Write-cache encryption key schedule

RC4 KSA and PRGA are present in `Defender.exe` (`sub_1400615E0`, `sub_140060320`)
and in `CmdTool.exe` (`sub_140025350`, `sub_140024090`). The key derivation —
whether the `serviceGUID` alone, the password, or a per-volume secret is used —
is **unknown**.

### 2.8 Cache-size and threshold arithmetic

`CacheSize = 0` in the service key and `RAM` in `user.dat` configure the write
cache. The relationship between them, the `[space]` thresholds and the driver's
`MapWindowCapacity` / `MapTableSize` errors is not fully established.

### 2.9 Miscellaneous

* Whether `\Device\DpShadow<n>` is sector-addressed or file-addressed for the
  commit path (the GUI enumerates it as a file system, the driver creates it as a
  device object).
* The exact predicates of the eleven per-instance dispatch hooks installed by
  `sub_28005F5CC` (which IRP major functions each volume instance overrides).
* `Defender.exe`'s ~24 control-flow-flattened functions (same relocator pattern)
  were not decoded; the IOCTL wrappers' inner bodies are therefore unknown.
* Whether `res.ini` key 1010 and 30011 are unused or used by a build not present
  here (they are missing from the shipped file).
* Whether `Uninstall.exe`'s absent version resource is intentional.

## 3. Roadmap: how to close the VM

The toolchain in `tools/` was built for exactly this. Suggested order:

### Step 1 — finish the opcode table mechanically (hours)

The extraction in `tools/vm.py` parses the handler *pseudocode*; it recovered 71
of 125 constant advances. The handlers' tails follow a fixed shape:

```
mov  rx, [state+0xFB]        ; IP
add  rx, OFFSET              ; operand base for the tail read
movzx ry, word ptr [rx]      ; next opcode
shl  ry, 3
mov  rz, [state+0x54]        ; table
mov  rz, [rz+ry*8]           ; handler
add  qword ptr [state+0xFB], LEN
jmp  rz
```

Parse that epilogue from the **disassembly** (not the pseudocode) and read
`OFFSET` and `LEN` directly. That yields `(opcode → {len, next_opcode_read_offset})`
for all 136 handlers with no guessing. `tools/vm.py` already carries the
scaffolding (`load_opcode_lengths`, `slot_name`, `disasm_program`).

### Step 2 — emulate the VM instead of reading it (days, most reliable)

The decisive shortcut is to stop reasoning about the semantics and *run* them.
Unicorn is not installed on the host (`pip install unicorn`); everything else is
ready.

```python
# sketch
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
# 1. map the whole diskpt.sys image at its preferred base 0x280050000
#    using the section table, so that every absolute reference and the
#    dispatch table resolve exactly as at run time
# 2. allocate a 0x1000-byte state buffer; set
#       state+0xFB = base + program_rva      (IP)
#       state+0x54 = base + 0x679A9          (dispatch table)
#       state+0xE7 = 0                       (latch, let the init path run)
#       state+0x69 = 0                       (opcode cache)
#    and set rbp = state
# 3. hook UC_HOOK_CODE; whenever PC equals one of the 136 handler entry VAs,
#    record (handler_index, *(u64*)(state+0xFB)) and continue
# 4. start at handler 79 (the interpreter step)
```
The recorded sequence *is* the VM disassembly: opcode indices with live operand
addresses, in execution order, with no static reasoning at all. Extend it by
snapshotting the 0x1000-byte state before and after each handler to derive each
opcode's effect empirically, then pattern-match the diffs to real operations.

The same harness works unchanged for the user-mode modules once each module's
`(relocator, state RVA, table RVA)` triple from `docs/02-obfuscation.md` §7 is
supplied.

### Step 3 — correlate programs to operations (hours)

Each program is entered from exactly one `.text` stub, so the *caller* names it.
For `diskpt.sys`, walk `all_disasm.asm`, find every
`jmp loc_XXXXXXXX` whose target holds `push <rva>; push <idx>; jmp <relocator>`,
and map the enclosing `.text` function. The caller of program `0x6B8F3` is
`sub_2800630D8` (`IRP_MJ_DEVICE_CONTROL`) — that correlation is what makes the
IOCTL program identifiable. Do the same for the remaining 26.

### Step 4 — dynamic confirmation (optional but decisive)

The driver is **running** on the analysis host. A kernel debugger over a serial
or network transport would let you break on the relocator, dump the state
structure after `StorInitializeVolumeContext`, and capture a real
`diskpt0.sys` header by entering Shadow Mode on a scratch volume. That converts
§2.4, §2.5 and §2.6 from inferred to observed in one session. Do this on a
disposable machine or snapshot — entering Shadow Mode modifies the boot
configuration and the disk filter stack.

### Step 5 — fill the remaining sections

| Unknown | Cheapest route |
| --- | --- |
| §2.1 control payload | Step 2 + Step 3 on `diskpt.sys` |
| §2.2 program attribution | Step 3 |
| §2.3 opcode semantics | Step 2 |
| §2.4 `diskpt.crt` fields | Step 4, plus parse `StorFindMapFile` (`0x280059FE8`) now that its pseudocode is exported |
| §2.5 `diskpt0.sys` header | Step 4 |
| §2.6 chunk naming | Step 4 |
| §2.7 RC4 key schedule | hexrays of `sub_1400615E0` (KSA) — the key source is visible in the caller's argument setup, which is *outside* the VM |
| §2.8 cache arithmetic | cross-read `sub_140062690` (RAM-cache setter, `&MB << 20`) against the driver's `MapWindowCapacity` validation |

## 4. Known-answer tests for a reconstruction

Anyone rebuilding this product should be able to reproduce these, in this order:

1. `diskpt.sys` installs as a `Start = 0` driver in `System Bus Extender`, is
   inserted as a disk-class upper filter and a volume-class lower filter, and
   creates `\FileSystem\Filters\DpControl` + `\DosDevices\DpControl`.
2. Opening `\\.\DpControl` and sending a 136-byte buffer starting
   `64 6B 70 74` (`'dkpt'`) returns the installation GUID for the documented
   operation.
3. Entering Shadow Mode on a volume creates `X:\diskpt0.sys` with the documented
   attributes and geometry-derived size, creates `X:\{0D9DB60E-…}\`, records the
   volume in `C:\Windows\diskpt.crt`, and makes writes land in
   `X:\{0D9DB60E-…}\%08x%08x`.
4. Reads of untouched sectors still come from the original volume; the volume's
   reported free space matches the guest's expectation (`$Bitmap` fixup).
5. Exiting Shadow Mode without commit leaves the original volume byte-identical
   (except the `Sync` list); exiting with commit reproduces the writes.
6. A path listed in `%SystemRoot%\diskpt.dat` is committed while the volume is
   shadowed, silently.
7. `user.dat` and `%SystemRoot%\bootstat.dat` survive a shadow session.
8. `CMD: /pwd:<correct> /enter:CD` and `CmdTool.exe /list` behave as documented,
   with exit code 0 in both success and failure.
9. With `shellext=2`, the Explorer commit verb demands the password; with
   `shellext=1` it does not.
10. `Uninstall.exe` refuses while any volume is shadowed and removes the filter
    entries and `BootExecute` entry before touching files.

## 5. Method notes for whoever continues

* **Prefer the disassembly over the pseudocode** for anything about the VM.
  Hex-Rays' rendering of the obfuscated identity arithmetic is actively
  misleading (it produced `IP -= v5 & 0x7FFFFFFF` where the machine code is a
  plain relative add).
* **Do not trust section names, permissions, or sizes.** Check
  `.reloc` vs the `BASERELOC` directory every time.
* **Strings are the reliable index.** The driver's DbgPrint trace strings are
  ordinary `.rdata` and give trustworthy function names; `tools/ida_export.py`
  already emits them with their code xrefs.
* **Correlate before concluding.** Every claim in this repository that matters is
  backed by at least two independent signals (a string *and* a decompiled call
  site, or a registry value *and* a file on disk).
