# Shadow Defender 1.5.0.726 — Reverse Engineering & Reconstruction Dossier

Complete reverse-engineering record and reconstruction blueprint for the
commercial Windows "shadow mode" product **Shadow Defender** by
SHADOWDEFENDER.COM, as installed on the analysis host.

This repository is the result of static analysis (IDA Pro 9.4), PE/resource
parsing, registry and filesystem forensics, and runtime inspection of the
installed product. It contains: the recovered architecture, every interface and
on-disk format, the obfuscation scheme the product uses, a reconstruction
blueprint with headers and reimplemented logic, and an explicit list of what
remains unknown.

---

## 1. What Shadow Defender is

Shadow Defender puts selected volumes into **Shadow Mode**: all writes to the
volume are redirected into a per-volume cache, reads come from the cache when
present and from the original volume otherwise, and on exit the changes are
either discarded or optionally committed. It also isolates the registry the same
way, and it can *exclude* chosen files, folders and registry keys so that their
changes are committed to the original volume even while shadowing.

Documented feature set (from the shipped `res.ini` string table and `Help.chm`):

* System Status view: per-volume capacity / used / free / actual free /
  space-consumed-by-SD, write-cache totals, exclusion lists.
  The `res.ini` groups 10000–180000 map to those pages and their dialogs;
  see [docs/05-user-interface.md](docs/05-user-interface.md).
* Mode Setting view: enter / exit / exit-all Shadow Mode, per-volume scheduling
  ("Enter Shadow Mode on boot"), RAM used as write cache.
* File Exclusion List and Registry Exclusion List, with save/load to file.
* Commit Now: push selected files/folders to the original volume immediately,
  including commit of *deleted* files only, and non-recursive commit.
* Administration: tray icon, desktop tip, shell context-menu extension,
  password control, low-free-space notification with per-volume thresholds,
  start with Windows, encrypt write cache, automatic update check, enable
  hibernation in Shadow Mode.
* Registration: trial with expiry, 25-character registration code, About box
  with user / organization / serial number.

## 2. Component inventory

Installed under `C:\Program Files\Shadow Defender` unless noted.

| File | Size | Identity | Role |
| --- | --- | --- | --- |
| `diskpt.sys` | 478 544 | `SHADOWDEFENDER.COM` / `Shadow Defender Filter Driver` 1.5.0.726 | **Kernel driver.** Boot-start disk/volume filter. In `C:\Windows\System32\drivers\`. |
| `Service.exe` | 134 096 | `SHADOWDEFENDER.COM` 1.5.0.726 | Windows service, registered under the GUID name `{0CBD4F48-3751-475D-BE88-4F271385B672}`. Enumerates volumes, drives the driver, deletes/creates per-volume artifacts. |
| `Defender.exe` | 1 387 040 | same | Main GUI (7 tabbed pages on Vista+, 6 on XP — the Registry Exclusion List page is not built on XP — plus dialogs). |
| `DefenderDaemon.exe` | 592 768 | same | Per-session tray agent, launched as `"…\DefenderDaemon.exe" /Auto` from `HKLM\…\Run`. |
| `CmdTool.exe` | 760 640 | same | Command-line administration tool. |
| `Commit.exe` | 905 336 | same | GUI helper invoked by the shell extension to commit selected paths. |
| `ShellExt.dll` | 408 048 | same | In-process Explorer context-menu handler. |
| `Uninstall.exe` | 641 064 | (no version resource) | MFC uninstaller. |
| `res.ini` | 8 935 | — | All UI strings, keyed by decimal IDs, section `[common]`. |
| `user.dat` | 138 | — | Settings + password hash + serial. |
| `Help.chm`, `eula.rtf`, `CmdTool.txt` | — | — | Shipped documentation. |

Non-program artifacts:

| Path | Meaning |
| --- | --- |
| `%APPDATA%\Shadow Defender\user.dat` | per-user settings (`tippos`) |
| `C:\Windows\diskpt.crt` | per-volume shadow configuration table (64 bytes = 4 × 16) |
| `C:\Windows\diskpt.dat` | file exclusion list (0 bytes here) |
| `C:\Windows\diskptex.dat` | registry exclusion list (0 bytes here) |
| `C:\Windows\dpstart.exe` | boot agent, present only while boot-time shadowing is armed |
| `X:\diskpt0.sys` | per-volume map/cache file, present only while that volume is shadowed |
| `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` | per-volume chunk cache directory |
| `Global\ShadowDefenderSharedMemory` | progress section shared with the GUI |

> **The driver is disguised.** It ships as `diskpt.sys`, is signed by
> `CN=Beijing YiChengWeiLai Culture-Tech Co.` while its version resource says
> `SHADOWDEFENDER.COM`, and registers the neutral service name `diskpt`. A
> signature- or name-based inventory will not find it. See
> [docs/03-driver-diskpt.md](docs/03-driver-diskpt.md).

## 3. Architecture

```
                     ┌──────────────────────────────────────────┐
                     │ Explorer / user                          │
                     └───────┬──────────────────────┬───────────┘
             context menu    │                      │  CmdTool.exe /reboot etc.
                     ┌───────▼────────┐             │
                     │ ShellExt.dll   │             │
                     │ CLSID {5EE8E9E6-│            │
                     │ 2853-4D28-B2DE-│             │
                     │ 6529EDA0A294}  │             │
                     └───────┬────────┘             │
              ShellExecuteW  │                      │
                     ┌───────▼────────┐             │
                     │ Commit.exe     │             │
                     └───────┬────────┘             │
                             │                      │
   ┌───────────────┐  CreateFileW("\\.\DpControl")  │
   │ Defender.exe  ├────────────────────────────────┤
   │ (GUI, 5 pages)│  DeviceIoControl(0x88-byte     │
   └───┬───────────┘  request, magic 'dkpt')        │
       │  CreateFileMappingW("Global\\ShadowDefenderSharedMemory")  progress 0..100
       │  ShellExecuteW("DefenderDaemon.exe" / Defender.exe /exit)
   ┌───▼───────────────┐
   │ DefenderDaemon.exe│  tray + desktop tip, 30 s poll, hotkey Ctrl+Alt+Shift+U
   └───────────────────┘
                             │
   ┌─────────────────────────▼──────────────────────────────────┐
   │ Service.exe  (service name {0CBD4F48-3751-475D-BE88-       │
   │              4F271385B672}, LocalSystem, auto, SafeBoot)   │
   │  • volume enumeration (FindFirstVolumeW / GetDriveTypeW)    │
   │  • device notifications (volume arrival/removal)             │
   │  • driver bootstrap and per-volume artifact cleanup          │
   └─────────────────────────┬──────────────────────────────────┘
                             │  IRP_MJ_DEVICE_CONTROL
   ┌─────────────────────────▼──────────────────────────────────┐
   │ diskpt.sys  — SHA-256 6ffd78b5…3583                         │
   │  Disk-class UpperFilter = {partmgr, diskpt}                 │
   │  Volume-class LowerFilter = {fvevol, diskpt, iorate, …}     │
   │                                                             │
   │  native layer (.text, 275 functions, unobfuscated)          │
   │    DriverEntry, common IRP dispatch, Stor* storage layer,    │
   │    Fsf* file-system layer, registry shadow hives             │
   │                                                             │
   │  obfuscated control plane (section named ".reloc", RWX)      │
   │    136 opcode handlers + 27 bytecode programs + dispatch     │
   │                                                             │
   │  devices: \FileSystem\Filters\DpControl, \DosDevices\DpControl
   │           \Device\DpShadow%d                                 │
   │  SDDL   : D:P(A;;GA;;;SY)(A;;GA;;;LS)(A;;GA;;;BU)            │
   └─────────────────────────────────────────────────────────────┘
```

**Two-layer design.** The *data plane* (sector redirection, file-system
filtering, registry hives, boot handling) is ordinary native x86-64 and
decompiles cleanly. The *control plane* (IOCTL parsing, configuration, session
and licensing logic) is compiled into a custom bytecode VM in every module. That
split is the single most important architectural fact about this product.

## 4. The obfuscation scheme (key finding)

Every module contains a section **named `.reloc`** whose real `BASERELOC`
directory is only 24 bytes but whose section body is up to 295 KB. The body is
`RWX` and holds:

1. **136 (driver) / 126 (user-mode) opcode handlers** — plain x86-64, but never
   analysed because the section is data-class;
2. a **dispatch table** of qword RVAs that a shared relocator converts to
   absolute pointers at run time, guarded by an atomic one-time latch;
3. **27 bytecode programs** (driver) implementing the control plane.

Call sites are 15-byte stubs: `push <program_rva>; push <entry_index>;
jmp <relocator>`.

The VM is a register machine whose register file *is* a scratch structure; the
instruction pointer is one of its own slots (`state+0xFB`), so branches are
writes to a register. Handlers are padded with identity arithmetic
(`add reg, 0`, `or reg, 0`) and a bogus "opcode cache" combined with
per-handler constants before every dispatch.

Full detail, including the relocator reconstruction, the state layout, the
instruction encoding and the recovered opcode table:
**[docs/02-obfuscation.md](docs/02-obfuscation.md)**.

## 5. Interfaces and formats recovered

| Interface / format | Where documented |
| --- | --- |
| `\\.\DpControl` device protocol, 136-byte (`0x88`) request envelope with magic `'dkpt'`, `IOCTL 0x80000D18` / `0x80002D48`, installation-derived IOCTL arithmetic | [docs/04-service-protocol.md](docs/04-service-protocol.md) |
| `\\.\DpShadow<hex>` shadow devices, `FSCTL_LOCK_VOLUME` / `DISMOUNT` / `UNLOCK`, private FSCTL `0x98144` / `0x560000` | [docs/04-service-protocol.md](docs/04-service-protocol.md) |
| `user.dat` (settings, `hash`, `hash2`, `sn`, `time`, `continue`, `volume`, `RAM`, `encrypt`, `hibernation`, `autostart`, `trayicon`, `tip`, `shellext`, `checkupdate`, `[space]`) | [docs/07-config-and-formats.md](docs/07-config-and-formats.md) |
| `res.ini` string table (all UI text, keyed by decimal ID) | [docs/05-user-interface.md](docs/05-user-interface.md) |
| `diskpt.crt` volume-config table, `diskpt.dat` / `diskptex.dat` exclusion records (1004 bytes: `u32 state; WCHAR path[500]`), `diskpt0.sys` map file, `X:\{0D9DB60E-…}\%08x%08x` chunks | [docs/03-driver-diskpt.md](docs/03-driver-diskpt.md), [docs/07-config-and-formats.md](docs/07-config-and-formats.md) |
| Password hash `MD5(UTF16LE(serviceGUID + password))`, blank sentinel `@BLANKPWD`, 25-char registration code over base-31 alphabet, `hash2` additive cipher, trial timestamp in `HKCR\CLSID\{78C3F4BC-…}`, RC4 for the write cache | [docs/08-licensing-and-crypto.md](docs/08-licensing-and-crypto.md) |
| CLI grammar (`/pwd`, `/xpwd`, `/list`, `/enter`, `/exit`, `/commit`, `/now`, `/reboot`, `/shutdown`, undocumented `/data`) | [docs/06-cli-and-shell.md](docs/06-cli-and-shell.md) |
| Shell context-menu CLSID / AppID / TypeLib / verbs and the exact `Commit.exe` command line | [docs/06-cli-and-shell.md](docs/06-cli-and-shell.md) |
| Uninstall order (services, filters, BootExecute, files, registry) | [docs/06-cli-and-shell.md](docs/06-cli-and-shell.md) |

## 6. Repository layout

```
docs/                 analysis and reconstruction documents (this is the deliverable)
  01-architecture.md        system architecture and component interaction
  02-obfuscation.md         the .reloc / bytecode-VM obfuscation scheme
  03-driver-diskpt.md        kernel driver internals
  04-service-protocol.md     user <-> driver protocol
  05-user-interface.md       GUI structure and res.ini map
  06-cli-and-shell.md        CmdTool, Commit, ShellExt, Uninstall
  07-config-and-formats.md   every persistent format
  08-licensing-and-crypto.md password, registration, trial, RC4
  09-unknowns-and-roadmap.md what is still unknown and how to close it
  10-installer.md          the installation package: four-layer SFX chain, payload,
                           install sequence, and the origin of the password salt
recon/
  analysis/           detailed sub-investigations
    defender_gui.md         1224 lines, GUI + daemon
    cli_and_shell.md        1341 lines, CLI tools + shell + uninstaller
  ida/<module>/       IDA exports: pseudocode, disassembly, functions, strings+xrefs,
                      imports, names, segments
  unhide/             recovered hidden-VM artifacts (functions, pseudocode, opcode table)
  *.strings.*.txt     raw string dumps
include/              reconstructed headers
src/                  reconstructed / reimplemented source
tools/                the analysis toolchain (see below)
samples/              local copies of the analysed binaries (for hash verification);
                      the vendor executables and driver are NOT committed — see .gitignore
work/                 scratch copy of the driver used by the unhide script (not committed)
.gitignore            keeps the vendor binaries and IDA databases out of the repository
```

## 7. Toolchain

| Tool | Purpose |
| --- | --- |
| `tools/ida_export.py` | Batch-export a module: all functions, hexrays pseudocode, disassembly, strings **with code xrefs**, imports, exports, names, segments. |
| `tools/ida_unhide.py` | Re-class a `.reloc` vault as code, seed functions at every dispatch-table target, dump everything recovered. |
| `tools/unhide_scan.py` | Locate relocator / table / thunks in a module without IDA. |
| `tools/vm.py` | VM profiler and disassembler (opcode lengths, per-opcode advance and opcode-read offset, program listing, dispatch-table discovery). |
| `tools/discalc.py` | VA → file offset → capstone disassembly. |
| `tools/refs.py` | file-offset ↔ RVA ↔ string ↔ xref lookups. |
| `tools/strings.py` | ASCII + UTF-16LE string extraction with regex filtering. |
| `tools/fn.py` | Extract named function blocks from a hexrays export. |

Reproduce the driver export and the vault recovery:

```bash
/d/Apps/IDApro/idat.exe -A \
  -S"$PWD/tools/ida_export.py $PWD/recon/ida/diskpt" \
  -L"$PWD/recon/ida/diskpt.log" samples/diskpt.sys

/d/Apps/IDApro/idat.exe -A \
  -S"$PWD/tools/ida_unhide.py $PWD/recon/unhide" \
  -L"$PWD/recon/unhide/unhide.log" work/diskpt_work.sys
```

## 8. Evidence discipline

Every document distinguishes:

* **observed** — present in a decompilation, a string, a registry value or a file
  on disk, cited by address or path;
* **inferred** — an interpretation of observations (structure layouts, field
  meanings, ordering), stated as such;
* **unknown** — not established. See
  [docs/09-unknowns-and-roadmap.md](docs/09-unknowns-and-roadmap.md).

Verified artifact hashes are in `samples/` (`sha256sum samples/*`); notable ones:

Runnable reproductions of the headline findings — the driver identity, the
password construction, the obfuscated-vault geometry, the filter/service
registration and the artifact hashes — are collected in
[recon/verification.md](recon/verification.md).

```
diskpt.sys      6ffd78b5954064bba7370af51b2e4f1358424f542682218a1121a375f3903583
Service.exe     dbb55e76877232405803ed752c3eb7a7eb795c00ce9f69ff3f86a57f5c5fdfb8
Defender.exe    f01d686574c034b135321f650e6483144fb5d8c3c32d341e586af45220d0a6fc
DefenderDaemon  686e86b6a03ac32268de12d84145dfa6ffa568b6e2c92f7b432ebcd3d225dc63
CmdTool.exe     5dcf3b773876662aa1a9f0c01722a815095c86ff2225ab035c94e1f2a4ab9ac7
Commit.exe      e05d8725d1fd01f7dd5378d45c771fd90c0f49ef584701d71da7924411717fbe
ShellExt.dll    14126b8ac600b26882cca045942295899dcbdf5a31222d73173081681b027ca0
Uninstall.exe   78cf5509a1558758fdbb99a78cc5ba4794e12ee03401196baa497f1ed5a7a850
```

Installation package (supplied separately; see `docs/10-installer.md`):

```
安装包\Setup.exe          9d2b7851eacc1a2eb43d8dc1e8a999c592c9855df3ed45c1fa26d09425b2d503
  embedded Setup.exe     1ed6170d2a71baf93d8bbd13907668c35ba51fc26f8b32e14d97b22baa4c3e09
  embedded Setup_x64.exe eef48e01728cbaccff97339f39da3e5c0854d7b2f20a29744995bdd833069b25
  embedded Setup_x86.exe 946c4e370bfc87cf896edd8f0bcdc2c981cb7ee94d7569b5d6fdf3a55fe5d267
```

The x64/x86 payloads are byte-identical to the installed tree; in particular the
installed driver is the package's **`diskpt.win10.sys`** (renamed to `diskpt.sys`)
and the installed daemon is **`Daemon.exe`** (renamed to `DefenderDaemon.exe`).

> A likely **false lead** also present on the host: `C:\Windows\System32\drivers\SDFRd.sys`
> is a **Microsoft** inbox driver ("SDF Reflector", WHQL-signed). Despite the
> `SDF` prefix it is unrelated to Shadow Defender and must not be included in a
> reconstruction.

## 9. Legal and scope note

This dossier documents an already-installed commercial product for
interoperability, security review and reimplementation research. No licence keys
were generated, no copy protection was circumvented, and the analysed binaries
are the ones already present on the analysis host. The registration and trial
algorithms are documented as facts about the binary; `docs/08-licensing-and-crypto.md`
is written as a specification, not as a key generator.
