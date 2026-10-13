# Shadow Defender — The User ↔ Driver Protocol

> Scope: every channel over which the user-mode Shadow Defender modules talk to the
> kernel driver `diskpt.sys`, plus the progress section and the cross-process
> synchronisation objects that surround them.
> Status: **observed** unless a claim is marked *inferred* or *unknown*; sources are cited
> as `module @ address` (IDA VA) or as a registry / file path. Companion documents:
> [docs/03-driver-diskpt.md](03-driver-diskpt.md) (driver internals) and
> [docs/02-obfuscation.md](02-obfuscation.md) (why part of this protocol is only
> statically known as *shape*, not as *semantics*).

## 1. Participants

Seven modules touch the driver. They split into two groups by *how* they talk to it:

| Module | Role towards the driver | Driver calls |
| --- | --- | --- |
| `Defender.exe` | full control: enter/exit shadow mode, commit, exclusions, RAM cache, volume flags | plaintext call sites (**codes and buffers known**), VM bodies |
| `DefenderDaemon.exe` | volume state polling, per-volume thresholds, notifications | plaintext call sites, VM bodies |
| `CmdTool.exe` | command-line enter/exit/commit/password | plaintext call sites, VM bodies |
| `Commit.exe` | commit of paths selected in Explorer | **no `DeviceIoControl` import at all** — all device I/O is resolved inside the VM |
| `ShellExt.dll` | context-menu entry point, volume-state test | plaintext call sites, VM bodies |
| `Uninstall.exe` | removal of driver artifacts | plaintext call sites, VM bodies |
| `Service.exe` | SESSIONCHANGE / DEVICEARRIVAL housekeeping, shadow-area creation, state-file cleanup | **fully plaintext**, fixed IOCTL codes |

The asymmetry matters: `Service.exe` is the only module whose driver conversation is
entirely visible in native code (§5), and it is also the only module that does **not** use
the installation-specific IOCTL base (§6).

## 2. Device namespace

| Name | Kind | Created by | User-mode path |
| --- | --- | --- | --- |
| `\FileSystem\Filters\DpControl` (fallback `\FileSystem\DpControl`) | control device, `DeviceType = FILE_DEVICE_FILE_SYSTEM (8)`, `FILE_DEVICE_SECURE_OPEN` | `diskpt.sys` `DriverEntry` (`0x280079008`) | `\\.\DpControl` |
| `\DosDevices\DpControl` | symbolic link | `diskpt.sys` | `\\.\DpControl` |
| `\Device\DpShadow%d` | per-volume shadow device (index at device-extension `+236`, **decimal**) | `diskpt.sys` (`0x2800...`; `swprintf(L"\\Device\\DpShadow%d", …)`, `diskpt/all_pseudocode.c:2184`, `:2322`) | — |
| `\Device\DpShadow%x` + `\DosDevices\DpShadow%x` | second per-volume device + symlink (index at `+232`, **hex**) | `diskpt.sys` (`diskpt/all_pseudocode.c:2203 ff.`) | `\\.\DpShadow<hex>` |
| `\BaseNamedObjects\ShadowDefenderSharedMemory` | section (4 KiB) | `diskpt.sys` opens/creates it (`diskpt/all_pseudocode.c:5856`) and `Defender.exe` creates it (`0x140063cb3`/`0x140063cd9`) | `Global\ShadowDefenderSharedMemory` |
| `\\.\X:` | raw volume device | OS | `\\.\X:` |

Two traps:

* The driver names the **device** `DpShadow%d` (decimal) but the **symlink** `DpShadow%x`
  (hex), using two different per-volume indices (`+236` vs `+232`). Every user-mode caller
  opens the *symlink* form `\\.\DpShadow%x` (`Defender.exe @ 0x1400606f1`,
  `CmdTool.exe @ 0x140024461`), so a reimplementation must keep the hex form for the
  DOS-visible name. `docs/03-driver-diskpt.md` lists `\Device\DpShadow%d`; both are
  observed and are not the same string.
* The control device's object type is 8 (file system), while every IOCTL code uses device
  type `0x8000` (§5). The I/O manager does not compare the two, so this is legal but easy
  to mis-read when grepping for `FILE_DEVICE_FILE_SYSTEM`.

Device security descriptor (literal SDDL in the driver's `.rdata`):
`D:P(A;;GA;;;SY)(A;;GA;;;LS)(A;;GA;;;BU)` — owner `LocalSystem`, protected DACL (no
inheritance), `GENERIC_ALL` for `SYSTEM`, `LOCAL SERVICE` and `BUILTIN\Users`. The broad
grant is deliberate: `Commit.exe` and `CmdTool.exe` must reach the device from ordinary
interactive sessions.

## 3. How the control device is opened

Every caller uses one identical pattern (observed at nine sites in `Defender.exe` alone:
strings `aDpcontrol` at `0x14006173e`, `0x14006184e`, `0x140061bd5`, `0x140062578`,
`0x1400626c3`, `0x140062803`, `0x14006370e`, `0x140063f20`):

```c
CreateFileW(L"\\\\.\\DpControl",
            FILE_READ_ATTRIBUTES /*0x80*/,                /* dwDesiredAccess  */
            FILE_SHARE_READ | FILE_SHARE_WRITE /*3*/,     /* dwShareMode      */
            NULL, OPEN_EXISTING /*3*/, FILE_ATTRIBUTE_NORMAL /*0x80*/, NULL);
```

| Caller | `lea rcx, "\\\\.\\DpControl"` sites | Source |
| --- | --- | --- |
| `Defender.exe` | `0x14006173e`, `0x14006184e`, `0x140061bd5`, `0x140062578`, `0x1400626c3`, `0x140062803`, `0x14006370e`, `0x140063f20` (8 sites) | `Defender/all_disasm.asm` |
| `DefenderDaemon.exe` | `0x140004dce`, `0x140004ede`, `0x140005105`, `0x1400056a3`, `0x1400057d9` (5 sites) | `DefenderDaemon/all_disasm.asm` |
| `CmdTool.exe` | `0x1400254ae`, `0x1400255be`, `0x140025945` | `CmdTool/all_disasm.asm` |
| `Commit.exe` | `0x1400389de`, `0x140038aee`, `0x140038d15`, `0x1400394e3` | `Commit/all_disasm.asm` |
| `ShellExt.dll` | `0x1800088be`, `0x1800089ce`, `0x180008bf5` | `ShellExt/all_disasm.asm` |
| `Uninstall.exe` | `0x140023b6e`, `0x140023c7e`, `0x140023ea5` | `Uninstall/all_disasm.asm` |
| `Service.exe` | `0x1400014d2` (`HandlerProc @ 0x140001470`) | `Service/all_disasm.asm` |

(These are the `lea rcx, …` instructions that supply the file name to `CreateFileW`; IDA
labels the string `aDpcontrol` in `Defender.exe`/`CmdTool.exe` and `FileName` in the other
modules.)

> **Correction to `recon/analysis/defender_gui.md`.** That report renders the access mask
> as `GENERIC_READ(0x80)`. `0x80` is `FILE_READ_ATTRIBUTES`; `GENERIC_READ` is
> `0x80000000`. The distinction is not cosmetic: it explains why the driver's control
> codes are declared `FILE_ANY_ACCESS` (§5) — a handle that carries no read/write data
> access is still allowed to issue them. (`Service.exe` really does open the *volume* with
> `GENERIC_READ` = `0x80000000` at `0x1400018a0`, which is where the confusion comes from.)

Opening the volume device uses `GENERIC_READ|GENERIC_WRITE` (`0xC0000000`,
`Defender.exe sub_1400603C0`) or `GENERIC_READ` (`0x80000000`, `sub_140062910`,
`Service.exe 0x1400018a0`), and the shadow device uses `FILE_READ_ATTRIBUTES` (`0x80`).

## 4. The request/response envelope

All control traffic uses **one 136-byte (`0x88`) block, passed as both input and output**
of a `METHOD_BUFFERED` `DeviceIoControl`, with a 4-byte magic in the first DWORD:

```c
#define DP_MSG_MAGIC  0x74706B64u   /* 'd','k','p','t' little-endian */
#define DP_MSG_SIZE   0x88          /* 136 */

typedef struct _DP_MSG {
    DWORD Magic;                    /* 0x00  set by the caller            */
    BYTE  Payload[132];             /* 0x04  request + response body      */
} DP_MSG;
```

Observed facts:

* The magic is written explicitly by `Service.exe` before the `\\.\DpControl` call:
  `OutBuffer = 1953524580` (= `0x74706B64`) at `0x1400014fe`, followed by
  `DeviceIoControl(h, 0x80000D18, &OutBuffer, 0x88, &OutBuffer, 0x88, …)` at `0x14000152d`
  (`Service/all_pseudocode.c:183–185`).
* `0x74706B64` is simultaneously the driver's pool tag (`ExAllocatePoolWithTag`), i.e. the
  message signature and the allocation tag are intentionally the same four bytes
  (`diskpt.sys` `0x2800517BC`, `0x280051867`, 20+ sites).
* Every other module zeroes the 136-byte block and lets the VM body fill it in — e.g.
  `Defender.exe sub_140061BA0` (`ZeroMemory(local, 0x88)` at `0x140061c60`),
  `sub_140063EF0` (zeroes 136 bytes), `CmdTool.exe sub_140025910` (`_BYTE v1[136]`,
  `memset` then VM), `Commit.exe` (VM only).
* `Service.exe`'s **per-volume** message (`0x80002D48`) is the exception that proves the
  rule: `sub_1400018A0` passes an *uninitialised* 136-byte stack buffer
  (`_BYTE OutBuffer[144]` at `0x1400018a0`) — no magic is written. Either the driver does
  not validate the magic for that code, or the field is silently ignored. Marked
  *inferred*: the magic is a signature of the `\\.\DpControl` session messages only.

*inferred* payload shape. The same 136-byte block backs visibly different operations —
session begin/end (`sub_140061710`, `sub_140061820`), RAM-cache size
(`sub_140062690(&ramBytes)`, called with `RAM<<20`), worker-thread handle
(`sub_1400627D0(hThread)` after `CreateThread(…, CREATE_SUSPENDED)`), settings push
(`sub_1400636E0`), per-volume flag (`sub_140062A80(drive, flags)` with flags
`2`/`3`/`0x102`/`0x103`), volume prepare (`sub_140063EF0`). The natural reading is a tagged
union inside `Payload[132]` whose discriminator is written by the VM dispatcher; the
discriminator value, field offsets and all constants are **unknown** because the bodies
live in the `.reloc` bytecode (see `docs/02-obfuscation.md`). What *is* known: every call
site, the buffer size, the argument values computed in native code, and the call order.

The two volume-level private codes carry different, *non*-`DP_MSG` payloads: `0x98144`
takes a 40-byte input with `DWORD[0] = 0x4000` (§7) and `0x560000` returns a `0x1000`-byte
reply read at `+8` (§7).

## 5. IOCTL inventory

`CTL_CODE(DeviceType, Function, Method, Access)` = `(DeviceType<<16)|(Access<<14)|(Function<<2)|Method`.

| Code | Decomposition | Route | Sender (call site) | Observed effect |
| --- | --- | --- | --- | --- |
| `0x80000D18` | `CTL_CODE(0x8000, 0x346, METHOD_BUFFERED, FILE_ANY_ACCESS)` | `\\.\DpControl` | `Service.exe` @ `0x14000152d` (`HandlerProc`, on `SERVICE_CONTROL_SESSIONCHANGE`, once per service lifetime — guard `dword_14001DBBC`) | 136-byte `'dkpt'` message; failure is latched |
| `0x80002D48` | `CTL_CODE(0x8000, 0xB52, METHOD_BUFFERED, FILE_ANY_ACCESS)` | `\\.\X:` | `Service.exe` @ `0x1400019ae` (`sub_1400018A0`, called for drives `A`–`Z` from the `SERVICE_CONTROL_DEVICEEVENT` / `dwEventType == 0x8000` (volume arrival) branch, `Service/all_pseudocode.c:203–206`) | per-volume state message; on failure (except `0x20000001`) `X:\diskpt0.sys` is deleted |
| `0x800030A0` | `CTL_CODE(0x8000, 0xC28, METHOD_BUFFERED, FILE_ANY_ACCESS)` | `\\.\DpControl` | `Defender.exe` @ `0x140061c6b` (`sub_140061BA0`); `DefenderDaemon.exe` @ `0x14000519b`; `Commit.exe` @ `0x140038dab`; `ShellExt.dll` @ `0x180008c8b`; `Uninstall.exe` @ `0x140023f3b` | returns the installation GUID string (512-byte buffer); callers fall back to the registry when it fails |
| `0x800025E4 + K` | base `CTL_CODE(0x8000, 0x979, METHOD_BUFFERED, FILE_ANY_ACCESS)`; `K` is installation-specific and not a multiple-of-4 field addition (see §6) | `\\.\DpControl` | `Defender.exe` @ `0x1400617a1` (`sub_140061710`, session end) and `0x140063f96` (`sub_140063EF0`, prepare); `DefenderDaemon.exe` @ `0x140004f41`; `CmdTool.exe` @ `0x140025511`, `0x140025621`; `Commit.exe` @ `0x140038b51`; `ShellExt.dll` @ `0x180008921`; `Uninstall.exe` @ `0x140023ce1` | the whole SD-API control plane: session begin/end, settings push, RAM cache, thread handle, volume flags |
| `0x00098144` | `CTL_CODE(9, 0x51, METHOD_BUFFERED, FILE_WRITE_ACCESS)` | `\\.\X:` | `Defender.exe` @ `0x14006396c` (`sub_1400637F0`), `CmdTool.exe` @ `0x14002708c` (`sub_140026F10`) | private volume prepare for shadowing / mark dirty; 40-byte input, `DWORD[0] = 0x4000` |
| `0x00560000` | `CTL_CODE(0x56, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)` | `\\.\X:` / `\\?\Volume{…}` | `Defender.exe` @ `0x14000259d` (`sub_14000251C`) | query "space used by SD"; reply DWORD at `+8` of a `0x1000` buffer |
| `0x0009C040` | `FSCTL_SET_COMPRESSION` | `X:\diskpt0.sys` file handle | `Defender.exe` @ `0x140063116`; `CmdTool.exe` @ `0x140026946` | compress the map/cache file (2-byte input `= 0`) |
| `0x00070000` / `0x00074004` / `0x00070048` | `IOCTL_DISK_GET_DRIVE_GEOMETRY` / `_GET_LENGTH_INFO` / `_GET_PARTITION_INFO` | volume or shadow device | `CmdTool.exe` @ `0x1400264b6`/`0x14002652e`/`0x140026574`; `Defender.exe` @ `0x1400630d8`-region and `81439`/`81447`/`81449` in the export | geometry for the `diskpt0.sys` size formula (§7 of `docs/07-config-and-formats.md`) |
| `0x00090018` / `0x0009001C` / `0x00090020` | `FSCTL_LOCK_VOLUME` / `_DISMOUNT_VOLUME` / `_UNLOCK_VOLUME` | `\\.\X:` and `\\.\DpShadow%x` | many sites, §7 | volume quiescing |

Note that the private FSCTL/IOCTL *device types* (`9`, `0x56`) are chosen from the
file-system and "unknown" ranges but **not** exercised through the driver's control device;
they are sent to the volume itself. The driver's `IRP_MJ_DEVICE_CONTROL` handler does not
need them — the file-system filter sees them as ordinary `IRP_MJ_FILE_SYSTEM_CONTROL`
traffic.

## 6. Installation-specific IOCTL numbers

`0x800025E4 + K` is the only code that changes between installations. `K` is derived from
the per-install `GUID` value under
`HKLM\SYSTEM\CurrentControlSet\Services\diskpt` (REG_SZ, e.g.
`{fd1aecc8-b1e9-4b92-a188-daa06486e05b}` on the analysis host) so that the control-plane
codes cannot be enumerated statically.

Observed bootstrapping (`Defender.exe`, `sub_140061A90 @ 0x140061a90`):

```c
/* returns K; result is stored in dword_1400C9DB0 by a CRT initialiser            */
if (sub_140061BA0(pvData) != 0)          /* IOCTL 0x800030A0 -> GUID string      */
    return sub_140147C33();              /* VM: derive K from the driver-provided GUID */
SHGetValueW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\diskpt",
            L"GUID", &type, pvData, &cb = 512);
if (status == ERROR_SUCCESS) return sub_140147C33();   /* VM: derive K from the registry */
```

The initialiser is `sub_140001330` → `dword_1400C9DB0 = sub_140061A90()` at `0x140001339`.
Every module embeds its own copy of this helper plus its own global:

| Module | Global holding `K` | Stored at | IOCTL issued as |
| --- | --- | --- | --- |
| `Defender.exe` | `dword_1400C9DB0` | `0x140001339` | `add eax, 800025E4h` @ `0x1400617a1`, `0x140063f96` |
| `DefenderDaemon.exe` | `dword_140021390` | `0x140001029` | `@ 0x140004f41` |
| `CmdTool.exe` | `dword_14006C4B4` | (CRT init) | `@ 0x140025511`, `0x140025621` |
| `Commit.exe` | `dword_14007C194` | (CRT init) | `@ 0x140038b51` |
| `ShellExt.dll` | `dword_18002A8B0` | (CRT init) | `@ 0x180008921` |
| `Uninstall.exe` | `dword_14005C2C4` | (CRT init) | `@ 0x140023ce1` |
| `Service.exe` | — | — | does not use `K` |

Consequences for tooling, stated plainly:

1. Static IOCTL enumeration is impossible for every code except the fixed ones in §5. The
   number must be computed at run time from the GUID.
2. The only *fixed* code that is safe to call before `K` is known is `0x800030A0`, which
   itself is how `K` is obtained — that is the protocol's bootstrap.
3. The transform `f(GUID) → K` is inside the `.reloc` VM (`sub_140147C33` in
   `Defender.exe`, `sub_1400AE263` in `CmdTool.exe`, etc.); the visible code before the
   dispatcher reveals only that the **whole GUID string** (not just its first bytes) is
   available to it. **Unknown:** which bytes are mixed, the mixing function, endianness
   and whether the result is masked.
4. `K` is not necessarily aligned, so `Function`/`Access` bits of `0x800025E4 + K` are not
   individually meaningful. Do not decompose the sum — decompose the base and treat the
   sum as opaque.
5. `Service.exe` deliberately avoids all of this (fixed codes on both devices), which
   suggests the service predates or intentionally opts out of the per-install scheme.

## 7. The volume-level channel

### 7.1 Shadow devices and volume handles

`Defender.exe sub_1400603C0 @ 0x1400603c0` (used by the commit path) is the canonical
sequence; `sub_140060CB0 @ 0x140060cb0` is the same routine with a different retry order,
and `sub_140063C20` alternates them up to four times:

```c
h = CreateFileW(L"\\\\.\\X:", GENERIC_READ|GENERIC_WRITE, 3, NULL, OPEN_EXISTING, 0x80, NULL);
DeviceIoControl(h, 0x90018 /*LOCK_VOLUME*/,    NULL,0,NULL,0,&n,NULL);   /* @0x140060510 */
DeviceIoControl(h, 0x9001C /*DISMOUNT_VOLUME*/,NULL,0,NULL,0,&n,NULL);   /* @0x1400607a0 */
DeviceIoControl(h, 0x90020 /*UNLOCK_VOLUME*/,  NULL,0,NULL,0,&n,NULL);   /* @0x14006055e */
swprintf(buf, L"\\\\.\\%s%x", L"DpShadow", volInfo[0]);                  /* @0x1400606f1 */
h2 = CreateFileW(buf, GENERIC_RW, 3, NULL, OPEN_EXISTING, 0x80, NULL);
/* the same lock/dismount/unlock trio is then issued on h2 */
```

The CmdTool twin is `sub_140024130` / `sub_140024A20` (lock sites at `0x140024280`,
`0x1400243b8`, `0x140024510`, … 18 lock/dismount sites, 8 unlock sites).

Two distinct uses are observed for this trio:

* **real quiescing** before a commit or a mode change (`sub_1400603C0`,
  `CmdTool sub_140024A20`);
* **busy detection only** before entering shadow mode — `CVolumePage::OnApply`
  (`Defender.exe sub_140022BA0 @ 0x140022d59`, `0x140022d91`) locks and dismounts each
  selected volume and, on failure, shows res.ini ID 20016 ("Some files on this volume(s)
  are in use…") with `MB_RETRYCANCEL`. The same test is used by the exit path
  (`sub_140023214 @ 0x140023341`, `0x140023379`).

The commit path's retry order is *observed* as `CB0 → 3C0 → CB0 → 3C0` inside
`sub_140063C20`; the exit path deletes `X:\diskpt0.sys` on success and calls
`SHChangeNotify(SHCNE_ASSOCCHANGED)`.

### 7.2 Private volume prepare — FSCTL `0x98144`

`Defender.exe sub_1400637F0 @ 0x14006396c` and `CmdTool.exe sub_140026F10 @ 0x14002708c`:

```c
h = CreateFileW(L"X:\\", GENERIC_WRITE, 3, NULL, OPEN_EXISTING,
                FILE_FLAG_NO_BUFFERING /*0x20000000*/ | FILE_FLAG_BACKUP_SEMANTICS, NULL);
DWORD in[10] = {0x4000};                 /* 0x28 = 40 bytes, first DWORD 0x4000 */
DeviceIoControl(h, 0x98144, in, 0x28, NULL, 0, &n, NULL);
```

Immediately afterwards, if the volume is the system volume, the caller enables
`SeBackupPrivilege`, deletes
`HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability\LastAliveStamp` and calls
`RegFlushKey` on HKLM/HKCU/HKCC/HKCR/HKU (so that the shadowed boot does not prompt for an
unclean shutdown). *Inferred:* `0x98144` = "prepare volume for shadowing / mark dirty".

> **Contradiction in the source reports.** `recon/analysis/defender_gui.md` describes
> `0x98144` as `CTL_CODE(0x9, 0x51, METHOD_BUFFERED, FILE_ANY_ACCESS)` with "the vendor bit
> `0x8000` OR-ed into the device type". `cli_and_shell.md` describes it correctly. The
> arithmetic settles it: `CTL_CODE(9, 0x51, METHOD_BUFFERED, FILE_WRITE_ACCESS)` =
> `0x90000 | (2<<14) | (0x51<<2) | 0 = 0x98144`. The `0x8000` bit is the **Access** field
> (`FILE_WRITE_ACCESS`), not a device-type bit. This is not cosmetic: a handle must have
> been opened with write access for the I/O manager to admit the request.

### 7.3 Private volume query — IOCTL `0x560000`

`Defender.exe sub_14000251C @ 0x14000259d`:

```c
h = CreateFileW(path, GENERIC_READ, 3, NULL, OPEN_EXISTING, 0, NULL);   /* \\.\X: or \\?\Volume{…} */
DeviceIoControl(h, 0x560000, NULL, 0, OutBuffer, 0x1000, &n, NULL);
*out = *(DWORD*)(OutBuffer + 8);        /* rendered as MB/GB; feeds res.ini 10008 */
```

Called from the enter/exit workers (`sub_14000F218`, `sub_14002482C`, `sub_140024E0C`) with
`\\?\Volume{GUID}` names. *Inferred:* "bytes occupied by SD on this volume" (res.ini ID
10008 "Space Used by SD").

### 7.4 Map/cache file actions

`X:\diskpt0.sys` is created, compressed and truncated by the *user-mode* side before the
driver ever sees it: `CmdTool.exe sub_140026330` (fully plaintext, `0x140026330`) computes
the size from disk geometry, opens it with
`GENERIC_RW, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM|FILE_FLAG_WRITE_THROUGH`
(`0xC0000000`, disposition `4`, flags `0x80000006`), issues `0x9C040` (`FSCTL_SET_COMPRESSION`)
and `SetEndOfFile`s it. The size formula and header handling are specified in
[docs/07-config-and-formats.md](07-config-and-formats.md) §"diskpt0.sys".

## 8. Progress reporting — `Global\ShadowDefenderSharedMemory`

The commit path publishes a percentage through a named section, not through the IOCTL
envelope:

```c
/* Defender.exe sub_140063C20 @ 0x140063c20 */
evAbort    = CreateEventW(NULL, TRUE,  FALSE, NULL);        /* manual reset, abort      */
evProgress = CreateEventW(NULL, FALSE, FALSE, NULL);        /* auto reset, driver->app  */
hMap       = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 0x1000,
                                L"Global\\ShadowDefenderSharedMemory");   /* @0x140063cd9 */
base       = MapViewOfFile(hMap, FILE_MAP_WRITE|FILE_MAP_READ, 0,0,0);
*(DWORD*)base = 0;                                          /* progress slot DWORD[0]   */
hThread    = CreateThread(NULL,0,sub_140061540,&tlsParams,0,NULL);  /* monitor thread   */
sub_140061820();                       /* driver session begin  */
/* commit with up to 4 attempts */
sub_140061710();                       /* driver session end    */
SetEvent(evAbort); WaitForSingleObject(hThread, INFINITE);
```

| Aspect | Observation |
| --- | --- |
| Section size | `0x1000` bytes (`dwMaximumSizeLow = 1000h`) |
| Progress field | `DWORD[0]` = percent; the app writes 0 before starting |
| Creator | `Defender.exe sub_140063C20` (`0x140063cd9`); `CmdTool.exe sub_140027340` (`0x1400273f9`) — same name, size and protection |
| Reader | monitor thread `Defender.exe sub_140061540` (waits on `{abort, progress}`), which invokes the callback `sub_14000FA78`; CmdTool's `StartAddress` worker does the equivalent |
| Callback | `sub_14000FA78` formats res.ini ID 1009 `"Committing %s ..., %d percent completed."` and posts `WM_USER+0x65` (0x465) to the busy dialog |
| Driver side | `diskpt.sys` also opens `\BaseNamedObjects\ShadowDefenderSharedMemory` (`diskpt/all_pseudocode.c:5856`), i.e. the **driver** is the writer of the progress value; the app only reads it |
| Lifetime | section is unlinked/closed when the mapping handle closes (`UnmapViewOfFile` + `CloseHandle` in `sub_140063C20`) |

## 9. Cross-process synchronisation

| Object | Type | Creator (site) | Consumer | Purpose |
| --- | --- | --- | --- | --- |
| `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | mutex | `Defender.exe sub_14000DFB8 @ 0x14000dfb8` (`CreateMutexW(NULL,TRUE,…)`; `ERROR_ALREADY_EXISTS` → find `#32770`/`"Shadow Defender"`, foreground it) | `Uninstall.exe sub_140002B18` | single GUI instance; uninstaller refuses to run while the GUI is up ("Please close Shadow Defender main interface.") |
| `Local\Shadow Defender Daemon Mutex` | mutex | `DefenderDaemon.exe WinMain @ 0x140003680` | daemon itself | one daemon per session |
| `Global\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}` | event | **`Service.exe`** `CreateEventW` @ `0x14000128b`/`0x1400012a6` (with a security descriptor; the service then starts its worker thread) | `DefenderDaemon.exe` `OpenEventW(EVENT_MODIFY_STATE)` @ `0x1400036ea`, then `WaitForSingleObject(…, INFINITE)` | "service/commit busy" latch: the daemon waits before doing tray/low-space work |
| `Global\ShadowDefenderSharedMemory` | section | see §8 | see §8 | progress |
| unnamed `evAbort` / `evProgress` | events | `Defender.exe sub_140063C20` | monitor thread `sub_140061540`; driver signals the progress event | progress handshake |
| unnamed device-notification events | events | `DefenderDaemon.exe` (`sub_140005670`, `sub_1400057A0`) | daemon volume monitor | volume arrival/removal |

There is **no named pipe and no window-message IPC**: `Defender.exe` and the daemon share
only files (`res.ini`, `user.dat`), the driver, and plain process launches
(`DefenderDaemon.exe /Auto`; `Defender.exe /exit`).

## 10. Error handling and fallbacks

* **`ERROR 0x20000001` is tolerated.** `Service.exe sub_1400018A0` deletes
  `X:\diskpt0.sys` on a failed `0x80002D48` **unless** `GetLastError() == 536870913`
  (`0x20000001`) — i.e. the driver reports "already in that state / nothing to do" with a
  code that is not a real failure (`Service/all_pseudocode.c:313–319`). A reimplementation
  must use the same sentinel or trigger spurious state-file deletion on every boot.
* **State-file deletion fallback.** Whenever a volume operation fails, the user-mode side
  removes the map file so the next boot starts clean:
  `SetFileAttributesW(L"X:\\diskpt0.sys", FILE_ATTRIBUTE_NORMAL); DeleteFileW(...)` in
  `Defender.exe sub_14000F218`, `sub_140063C20`, and `Service.exe sub_1400018A0`.
* **GUID bootstrap fallback.** `0x800030A0` → registry `…\Services\diskpt\GUID` →
  `SetLastError` + return 0 (see §6).
* **Retry ladders.** Commit tries `sub_140060CB0`/`sub_1400603C0` alternately four times
  before giving up; the mode-change worker retries lock/dismount by rebuilding the
  volume handle.
* **Diagnostics.** All of these paths log to `C:\sdtrace.log` through
  `Defender.exe sub_140064030` (`SdFormatMessage` at `sub_1400602C0`), `CmdTool.exe
  sub_140027610` (file, 1 MB cap, prefix `"[ % 16s ] | "`) and the shared
  `OutputDebugStringW` wrapper. Strings observed: `"Lock Volume11 failed %d"`,
  `"Dismount Volume1 failed %d"`, `"Get Volume Information failed %d"`,
  `"SdSetVolumeFlag: CreateFile(%s) failed(%d)"`.
* **Last-error preservation.** The wrappers save `GetLastError()`, close the handle, then
  `SetLastError(saved)` before returning — e.g. `Service.exe` `0x1400014fe`-region and
  `sub_1400018A0`, `Defender.exe sub_140063C20`.

## 11. Reconstructed header (reconstruction, not original source)

```c
/* dp_protocol.h — reconstructed from the observations in §2–§9.                */
/* Everything marked UNKNOWN was not recovered; do not treat it as a contract.  */
#ifndef DP_PROTOCOL_H
#define DP_PROTOCOL_H

#include <windows.h>

#define DP_MSG_MAGIC   0x74706B64u      /* 'd','k','p','t' ; also the pool tag */
#define DP_MSG_SIZE    0x88             /* 136                                 */

typedef struct _DP_MSG {
    DWORD Magic;                        /* must be DP_MSG_MAGIC for DpControl  */
    BYTE  Payload[132];                 /* UNKNOWN tagged union                */
} DP_MSG, *PDP_MSG;

/* Fixed codes (safe to hard-code) ------------------------------------------- */
#define IOCTL_DP_SERVICE_MSG   0x80000D18u  /* CTL_CODE(0x8000,0x346,BUFFERED,ANY) ; Service.exe  */
#define IOCTL_DP_VOLUME_MSG    0x80002D48u  /* CTL_CODE(0x8000,0xB52,BUFFERED,ANY) ; Service.exe  */
#define IOCTL_DP_QUERY_GUID    0x800030A0u  /* CTL_CODE(0x8000,0xC28,BUFFERED,ANY) ; -> WCHAR[256] */
#define IOCTL_DP_VOLUME_PREP   0x00098144u  /* CTL_CODE(9,0x51,BUFFERED,WRITE)     ; DWORD in[10]={0x4000} */
#define IOCTL_DP_VOLUME_USAGE  0x00560000u  /* CTL_CODE(0x56,0,BUFFERED,ANY)       ; out DWORD at +8 */

/* Installation-specific code family (base only; K comes from the GUID) ------- */
#define IOCTL_DP_SESSION_BASE  0x800025E4u

typedef enum _DP_OP {                  /* INFERRED opcode names; values UNKNOWN  */
    DP_OP_SESSION_BEGIN = 0,
    DP_OP_SESSION_END,
    DP_OP_PUSH_SETTINGS,               /* sub_1400636E0                          */
    DP_OP_SET_RAM_CACHE,               /* sub_140062690, argument = RAM << 20    */
    DP_OP_SET_WORKER_THREAD,           /* sub_1400627D0, argument = HANDLE       */
    DP_OP_SET_VOLUME_FLAG,             /* sub_140062A80, flags 2/3/0x102/0x103   */
    DP_OP_PREPARE_SHADOW,              /* sub_140063EF0                          */
    DP_OP_GET_VOLUME_INFO,             /* info[0]=shadow id, [1]=inShadow, [2]=used */
    DP_OP_GET_VOLUME_FLAGS,            /* sub_140061F10, reads X:\diskpt0.sys header */
    DP_OP_GET_CACHE_USAGE,             /* sub_140062540, used/total              */
    DP_OP_GET_VOLUME_USAGE             /* sub_14000251C is the 0x560000 variant  */
} DP_OP;

DWORD DpComputeIoctlBase(void);        /* = f(serviceGUID); VM-obfuscated, UNKNOWN body */
#define DP_IOCTL(op) ((DWORD)(IOCTL_DP_SESSION_BASE + dpGlobalIoctlBase + (op)*0))
/* NOTE: the per-op offset is NOT known to be (op)*0; the family may use a single
   code with a discriminator inside Payload[]. Both readings fit the evidence.      */

BOOL DpSessionIoControl(const DP_MSG *in, DP_MSG *out);   /* sub_140061710/820/636E0 shape */
BOOL DpQueryGuid(WCHAR out[256]);                          /* sub_140061BA0                */
BOOL DpSetVolumeFlag(WCHAR drive, DWORD flags);            /* sub_140062A80                */

#endif /* DP_PROTOCOL_H */
```

## 12. Open questions

1. **The 132-byte payload.** Discriminator, field offsets and constants — all inside the
   `.reloc` VM. This is the single highest-value unknown of the whole product.
2. **`f(GUID) → K`.** Which bytes, which mixing, what masking. Needed for any
   reimplementation that must coexist with the original driver, and for static tooling.
3. **Whether the base is per-op.** The evidence (one `add eax, 800025E4h` per wrapper,
   different wrappers for different features) fits either a single multi-purpose code with
   an internal opcode or a family with per-op additions. Unresolved.
4. **`0x560000` reply semantics beyond `+8`.** Only the DWORD at `+8` is read.
5. **`0x98144` semantics.** The 40-byte input is `{0x4000, 0, …}` at every observed call
   site; the remaining 36 bytes are zero at the sites where they are initialised, but the
   meaning of `0x4000` is unknown.
6. **The magic on volume messages.** `Service.exe` does not set it for `0x80002D48`;
   whether the driver checks it there is unknown.
7. **Who else writes the shared-memory percentage.** The driver opens the section, but the
   exact write site was not located in the native `.text` layer.
