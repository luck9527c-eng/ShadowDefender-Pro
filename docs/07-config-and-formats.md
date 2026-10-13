# Shadow Defender — Persistent Formats

> Scope: every file, on-disk structure and registry value the product reads or writes,
> with byte-level layout, producer/consumer and the values observed on the analysis host.
> Status: **observed** unless marked *inferred* / *unknown*; observed host values are
> reproduced verbatim. Companion: [docs/03-driver-diskpt.md](03-driver-diskpt.md) for the
> driver's use of these formats and [docs/08-licensing-and-crypto.md](08-licensing-and-crypto.md)
> for the meaning of `hash`/`hash2`.

## 1. Inventory

| Artifact | Size on host | Producer | Consumer |
| --- | --- | --- | --- |
| `<install>\user.dat` | 138 B | GUI, daemon, service, CmdTool | GUI, daemon, CmdTool, Commit, ShellExt |
| `%APPDATA%\Shadow Defender\user.dat` | 20 B | daemon | daemon |
| `<install>\res.ini` | 8 935 B | installer / translator | every UI module (see docs/05) |
| `%SystemRoot%\diskpt.crt` | 64 B | driver | driver |
| `%SystemRoot%\diskpt.dat` | 0 B | GUI / driver | driver, GUI |
| `%SystemRoot%\diskptex.dat` | 0 B | GUI / driver | driver, GUI |
| `%SystemRoot%\diskpt0.dat` | (absent) | GUI ("Commit Now") | driver |
| `X:\diskpt0.sys` | (absent — no volume shadowed) | GUI, `CmdTool.exe` | driver |
| `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\%08x%08x` | (absent) | driver | driver |
| `%SystemRoot%\dpstart.exe` | (absent) | installer / driver | `BootExecute` |
| `C:\sdtrace.log` | (diagnostics) | all modules | analyst |
| `Global\ShadowDefenderSharedMemory` | 4 096 B | GUI, CmdTool | GUI, CmdTool, driver |

## 2. `user.dat` — INI settings store

### 2.1 Location and redirection

All modules resolve the path identically:

```c
DWORD cb = 520;
if (SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path", …) != ERROR_SUCCESS) {
    GetModuleFileNameW(NULL, buf, 260);
    *wcsrchr(buf, L'\\') = 0;                       /* executable directory */
}
wcscat_s(buf, 260, L"\\user.dat");
```

An exact copy lives in the driver's `Sync` value
(`HKLM\SYSTEM\CurrentControlSet\Services\diskpt\Sync` =
`C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat`), so the driver writes user
profiles' settings back to the real volume even while the volume is shadowed.

While the containing volume is in shadow mode the path is **remapped into the shadow
area** before any write (`sub_1400620E0` → if `volInfo.inShadow == 1`,
`sub_140061CE0(path, path, &len)`), and after writing, `sub_14000FEB8` copies the file back
out of the shadow (`SetFileAttributesW(p, 0x80); CopyFileW(shadow, real, FALSE)`, up to 3
retries with a 100 ms sleep). The canonical write sequence is:

```c
GetUserDatPath(p);
sub_140061820();                       /* driver session begin          */
WritePrivateProfileStringW(section, key, value, p);
sub_140002418(p);                      /* CreateFileW(GENERIC_WRITE) + FlushFileBuffers */
CommitUserDatOutOfShadow();            /* sub_14000FEB8                 */
sub_140061710();                       /* driver session end            */
```

The **daemon** uses a second file, `%APPDATA%\Shadow Defender\user.dat`, for the desktop
tip position only (strings `\Shadow Defender\user.dat` @ daemon `0x138d8`, `tippos` @
`0x13910`).

### 2.2 `[common]` keys

| Key | Type / default | Written by | Meaning (*inferred* from the UI that owns it) |
| --- | --- | --- | --- |
| `hash` | 32 lowercase hex chars; default `00000000000000000000000000000000` | `sub_140016888` (password change), `sub_140016FE0`, `CmdTool /xpwd:` | password hash, `MD5(UTF16LE(GUID ++ password))`; blank sentinel `MD5(GUID+"@BLANKPWD")` |
| `hash2` | string, 29 chars on this host | `sub_14000E8D4` (migration), `sub_14001BA88` (registration) | registration code, obfuscated (see docs/08) |
| `sn` | 25-char code, normally empty | `sub_14000E8D4` clears it after writing `hash2` | plaintext registration code as typed |
| `time` | decimal Unix time; observed `1809326992` | `sub_14001BA88` (`time64(NULL)`) | registration timestamp; write-only — never read back by any module |
| `continue` | 0/1, default 0 | `sub_140014240` | "Enter Shadow Mode on Boot" |
| `volume` | drive letters, e.g. `CD` | `sub_140022BA0` | volumes scheduled for/currently in shadow mode |
| `RAM` | megabytes, default 0 | `sub_140023DD4` | RAM write-cache size; sent to the driver as `value << 20` |
| `encrypt` | 0/1, default 0 | `sub_140016BD8` | encrypt the write cache (res.ini 50013) |
| `hibernation` | 0/1, default 1 | `sub_140016CC8` | "Enable hibernation in Shadow Mode" (also flips driver `Control` bit 0x80) |
| `autostart` | 0/1, default 1 | `sub_1400169F8` | start with Windows (daemon's `/Auto` gate) |
| `trayicon` | 0/1, default 1 | `sub_14001766C` | tray icon |
| `tip` | 0/1, default 1 | `sub_140017574` | desktop tip |
| `shellext` | 0/1/**2**, default 1 | `sub_140016FE0`, `sub_140017404`, `sub_140016AE4` | shell context menu; `2` = ask for the password when committing (res.ini 50008) |
| `checkupdate` | 0/1, default 1 | `sub_140017764` | automatic update check |
| `tippos` | string; observed `6686956` | daemon | desktop-tip position (only in the `%APPDATA%` copy) |

### 2.3 `[space]` section

| Key | Type / default | Written by | Meaning |
| --- | --- | --- | --- |
| `disable` | 0/1, default 0 | `sub_140016E48` | disable low-free-space notification (checkbox 1099) |
| `default` | MB integer | `sub_14001ABE4` | threshold applied to volumes without an override |
| `<letter>` (e.g. `C`, `D`) | MB integer | `sub_14001ABE4` (from the threshold list control) | per-volume threshold |

The daemon reads `[space]` per volume (`sub_140002240(drive)`), pushes each threshold to
the driver as `MB << 20` (`sub_1400058F0(drive, bytes)`) and polls every 30 s; below the
threshold it raises the tray balloon with res.ini 1016.

### 2.4 Observed host contents

`C:\Program Files\Shadow Defender\user.dat` (138 bytes, CRLF):

```
[common]
hash=eb1997a8cf8000a3d43ce85f0be18268
hash2=<redacted: this installation's licence serial>
sn=
time=1809326992
RAM=0
continue=0
volume=CD
```

`%APPDATA%\Shadow Defender\user.dat`:

```
[common]
tippos=6686956
```

Worked reading of the first file: **no password is set** — `hash =
eb1997a8cf8000a3d43ce85f0be18268` is exactly
`MD5(UTF16LE("{fd1aecc8-b1e9-4b92-a188-daa06486e05b}" ++ "@BLANKPWD"))`, the blank-password
sentinel for this host's `diskpt` GUID (verified; see
[docs/08-licensing-and-crypto.md](08-licensing-and-crypto.md) §2.3). The installation is
registered (`hash2` non-empty, `sn` cleared), volumes `C:` and `D:` are nominated in
`volume=CD`, no RAM cache is configured, the boot-time schedule is off, and `time` (a Unix
timestamp) is a write-only registration record.

## 3. `res.ini`

Format and full key map: [docs/05-user-interface.md](05-user-interface.md) §3–§5.
Format facts needed if you must parse it: UTF-16/ANSI INI, `[common]` section, decimal
string keys, `\n` used as an embedded newline, optional `[translate]` section, `;` starts a
comment. It is read through `GetPrivateProfileStringW` with a 4096-wchar buffer and located
via `HKLM\SOFTWARE\Shadow Defender\Path` (fallback: the module's own directory).

## 4. `diskpt.crt` — volume configuration table

`%SystemRoot%\diskpt.crt`, 64 bytes on the analysis host = four 16-byte records.
**Observed bytes** (identical to the dump in `docs/03-driver-diskpt.md` §4.2):

```
offset  bytes
0x00    1a ef f2 c3  fc 7c 07 00   80 0b 09 00  00 00 00 00
0x10    2f dc 2c b3  e1 57 42 d6   78 d0 0d 00  01 00 00 00
0x20    6a cf 10 52  01 70 58 85   20 2a 15 00  03 00 00 00
0x30    c9 5d 23 eb  36 32 07 dc   40 9b 0b 00  03 00 00 00
```

Reconstructed record (**field meanings inferred**; the record size and the three-dword
validation are observed — the driver logs `StorFindMapFile: invalid config info(%x-%x-%x)`):

```c
/* reconstruction — INFERRED layout */
struct dp_volume_config {      /* 16 bytes, packed */
    u32 id;                    /* 0x00  volume identity (signature / offset)      */
    u32 id_hi;                 /* 0x04                                            */
    u32 size;                  /* 0x08  map/bitmap size (MB-ish; 0x0b0980 = 723 328 KB ≈ 706 MB) */
    u32 state;                 /* 0x0C  0 = normal, 1 / 3 = shadow/armed           */
};
```

Record 0 has `state = 0`; records 1–3 have `state = 1, 3, 3`. On a host with C:, D:, E:
this reads as "C: normal, D: and E: configured", with `3` as the persistent
("enter on boot") flag. `docs/03-driver-diskpt.md` states this mapping is inferred and
calls it "the single most useful thing to confirm next"; nothing in the user-mode modules
dissects the file, so that remains true. **Unknown:** whether `id` is a volume serial, a
partition offset or a signature hash, and whether the record order is the volume ordinal.

> Note: the 64-byte size is *coincidentally* twice the 32-byte size of a GUID; the file is
> not a GUID list. The observed per-record strides are exactly 16 bytes.

## 5. Exclusion lists — `diskpt.dat`, `diskptex.dat`, `diskpt0.dat`

### 5.1 Record format

All three files are arrays of fixed 1004-byte records:

```c
struct dp_exclusion {          /* 1004 bytes */
    u32   state;               /* 0x000  1 = active                          */
    WCHAR path[500];           /* 0x004  NUL-terminated, UTF-16LE            */
};                             /* 4 + 1000 = 1004                            */
```

| File | Content | Read by | Written by |
| --- | --- | --- | --- |
| `%SystemRoot%\diskpt.dat` | **File Exclusion List** | driver; GUI `sub_140016408`; count shown by `sub_140021A9C` | GUI `sub_14000C684` |
| `%SystemRoot%\diskptex.dat` | **Registry Exclusion List** | driver; GUI `sub_14001FC44` | GUI `sub_14000C684` |
| `%SystemRoot%\diskpt0.dat` | **"Commit Now" pending list** | driver; GUI `sub_14000CE40` | GUI `sub_14000C684` |

### 5.2 Save / load semantics (observed)

* **Load** (`sub_140016408` for files, `sub_14001FC44` for registry): read the file, keep
  only records with `state == 1`, skip the wildcard placeholders `":*"` / `"*"`, and insert
  the path into list control 1005. While any volume is in shadow mode the "Apply" button
  (control 1049) is disabled and res.ini 30012 is shown (`"At least one file you selected is
  in Shadow Mode. Please add them before you place the volume into Shadow Mode."`).
* **Save** (`sub_14000C684`): allocate `1004 * count` bytes, set `state = 1`, copy the path
  with `wcscpy_s(&rec[1], 500, path)`, then
  `CFile::Open(path, typeBinary|modeCreate|modeWrite)`, `Write`, `SetLength(1004 * count)`.
  An **empty list deletes the file** rather than writing a zero-length one.
* The lists live in `%SystemRoot%`, so they are inside the shadow overlay when the system
  volume is shadowed; the GUI re-maps the path through `GetShadowPath` (`sub_140061CE0`)
  exactly like `user.dat`.
* **User-facing list files.** Apart from the driver's own copies, the GUI can save/load a
  list to an arbitrary file through `CFileDialog`:
  * exclusion lists use the filter `%s(*.sdl)|*.sdl||` (res.ini 30009/30010, 60008/60009),
  * commit lists use `%s(*.sdrl)|*.sdrl||` (res.ini 40009/40010),
  * the generic file filter string is res.ini 1011 `All documents|*.*||`.
  Both extensions are written in the **same 1004-byte record format** (the code reuses
  `sub_14000C684` with a caller-supplied path).
* The registry list uses absolute hive paths as text: `\REGISTRY\MACHINE\SAM|SECURITY|SOFTWARE|SYSTEM`
  and `\REGISTRY\USER\%SID%`, with the literal placeholder **`@DUMMY`** standing for the
  per-user hive (`sub_14001C1CC`; the SID string is built by `sub_14000D798` with
  `ConvertSidToStringSidW`).

## 6. `X:\diskpt0.sys` — per-volume map/cache file

### 6.1 Attributes and creation

Created by the user-mode side, not the driver. Fully plaintext implementation:
`CmdTool.exe sub_140026330 @ 0x140026330` (`SdSetVolumeFlag`; `Defender.exe`'s twin is
`sub_140062B00`).

```c
SetFileAttributesW(L"X:\\diskpt0.sys", FILE_ATTRIBUTE_NORMAL);
h = CreateFileW(L"X:\\diskpt0.sys", GENERIC_READ|GENERIC_WRITE /*0xC0000000*/,
                FILE_SHARE_READ|FILE_SHARE_WRITE /*3*/, NULL,
                CREATE_ALWAYS /*4*/,
                FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM|FILE_FLAG_WRITE_THROUGH /*0x80000006*/,
                NULL);
if (h == INVALID_HANDLE_VALUE) {                    /* rotate the old file away */
    for (i = 0; i < 1000; i++) {
        MoveFileW(L"X:\\diskpt0.sys", i == 0 ? L"X:\\diskpt0.sys.bak"
                                             : L"X:\\diskpt0.sys.bak.%03d");
        if (ok) break;
    }
    /* after 1000 failures: PathRemoveFileSpecW + GetTempFileNameW + DeleteFileW + MoveFileW */
}
DeviceIoControl(h, 0x9C040 /*FSCTL_SET_COMPRESSION*/, &zero16 /*2 bytes*/, 2, NULL, 0, &n, NULL);
```

*Rotation*: the previous file becomes `<name>.bak`, then `.bak.000`, `.bak.001`, … up to
999 attempts.

### 6.2 Size formula (verbatim logic)

The file is pre-allocated with `SetEndOfFile` at a size derived from the volume geometry:

```c
/* v30 = volume size in bytes, v28 = bytes per sector                        */
if (v28 > 0x1000) { SetLastError(0x57 /*ERROR_INVALID_PARAMETER*/); return 0; }

cluster = 4096;
if (v30 > 0x100000000)  cluster = 0x2000;
if (v30 > 0x200000000)  cluster *= 2;
if (v30 > 0x4000000000) cluster *= 2;
if (v30 > 0x8000000000) cluster *= 2;

meta  = ((((v30 / cluster) + 8) / 8 + 4096) / 0x1000) << 12;   /* metadata, page aligned */
perSec = 2048;
if (v28 > 0x2000) perSec = v28 / 4;

offset = (4 * (v30 / cluster) / 0x2000) << 13) + 0x8000;       /* data area */
if ((flags & 3) != 0) offset *= 2;                             /* armed state doubles it */
SetFilePointer(h, offset + 5 * meta + 4096, NULL, FILE_BEGIN);
SetEndOfFile(h);
```

*Observed*: the constants and the branch conditions above. *Inferred*: `cluster` = the
product's allocation unit; `meta` = the three map/bitmap regions plus a header repeated
`5 * meta`; the `+4096` is a final page. The exact role of each term is **unknown**; the
formula is reproduced so a reimplementation can at least produce the same file size.

### 6.3 512-byte header

After allocation the first 512 bytes are read, two DWORDs are cleared and the block is
written back:

```c
SetFilePointer(h, 0, NULL, FILE_BEGIN);
ReadFile(h, header, 0x200, &n, NULL);
*(DWORD*)(header + 4)  = 0;          /* observed: stack slots v34 / v35 */
*(DWORD*)(header + 12) = 0;
SetFilePointer(h, 0, NULL, FILE_BEGIN);
WriteFile(h, header, 0x200, &n, NULL);
```

*Observed*: the file is read/written in 512-byte header units, offsets `+4` and `+12` are
cleared on a mode change, and the reader (`sub_140025C80`, `Defender sub_140061F10`) opens
the file with `GENERIC_READ` + `FILE_FLAG_NO_BUFFERING|FILE_ATTRIBUTE_NORMAL`
(`0x20000080`), seeks to 0 and reads exactly 512 bytes before handing the buffer **and an
RC4 context** to the VM. *Inferred:* the header holds a validity/version field plus a key
or state word at `+4`/`+12`; the RC4-encrypted body follows. The header's full field map is
**unknown** (values are only ever produced by the VM bodies).

### 6.4 Driver-side validation

`StorFindMapFile` (`0x280059FE8`) locates and validates the file with
`ZwCreateFile` / `ZwReadFile` / `ZwQueryInformationFile` / `ZwFsControlFile` (trace strings,
`docs/03-driver-diskpt.md` §4.1):

```
StorFindMapFile: ZwCreateFile(%ws) / ZwReadFile(%ws) / ZwQueryInformationFile(%ws)
StorFindMapFile: ZwFsControlFile(%ws)
StorFindMapFile: invalid config info(%x-%x-%x)
StorFindMapFile: AllocateBitmapSize = %d
StorFindMapFile: map file size(%d) doesn't match volume size(%I64d)
StorFindMapFile: unrecognized volume
StorInitializeVolumeContext: BytesPerSector = %d
StorInitializeVolumeContext: ERROR MapWindowCapacity = %d
StorInitializeVolumeContext: ERROR (MapTableSize = %d)
StorInitializeVolumeContext: AllocateBitmapSize doesn't match!
```

So the driver:

1. re-queries geometry (`FltDeviceIoControl(IOCTL_DISK_GET_DRIVE_GEOMETRY)`,
   `IOCTL_DISK_GET_PARTITION_INFO`),
2. reads the header and checks **three dwords** (`invalid config info(%x-%x-%x)`),
3. checks `map file size == volume size` — that is, the pre-allocated file size computed by
   `SdSetVolumeFlag` in §6.2 is the *validation*, not an accident,
4. rejects unknown volumes,
5. allocates the bitmap and a contiguous map window.

The driver also *writes* through the same helpers
(`StorInitializeBitmap: ExAllocatePoolWithTag / FltReadWriteSectors`,
`StorInitNtfsBitmap: Can't find NtfsAttributeData / find Resident attribute`,
`StorPreInitBitmap` using `ZwCreateFile`).

## 7. `{0D9DB60E-B0EA-4d53-A392-A5D274956846}` — chunk cache

| Item | Value |
| --- | --- |
| Directory | `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` (`\??\C:\{0D9DB60E-…}\` in driver kernel paths) |
| Chunk file | `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\%08x%08x` — two 32-bit ordinals, lowercase hex, no separator |
| Created by | driver (`Stor*`); the directory is also created/removed by `Service.exe sub_1400016A0`, called from `sub_1400018A0` on volume arrival |
| Naming (inferred) | the two ordinals are almost certainly the chunk index and a sub-index/version within the containing map region; the pair format matches the `%08x%08x` literal in the driver's `.rdata` |

The file names are produced by the driver, not the user-mode modules; no user-mode tool
opens them. `Service.exe sub_1400018A0 @ 0x1400018a0` builds
`L"\\\\.\\%C:"` + `L"\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}"` and calls the create/remove
helper before sending the per-volume `0x80002D48` message (docs/04 §7).

## 8. `dpstart.exe` and `BootExecute`

| Item | Value |
| --- | --- |
| File | `%SystemRoot%\dpstart.exe` |
| Referenced by | `HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\BootExecute` (multi-string entry `dpstart`) |
| Purpose | boot-time agent installed while a volume is scheduled to enter Shadow Mode at boot |
| Evidence | driver strings `\SystemRoot\dpstart.exe`; `Uninstall.exe` removes the `BootExecute` element first and only then deletes the file (`sub_140001A34`, ordered list §5.2 of docs/06) |
| Observed state | absent on the analysis host (no boot-time schedule armed) |

The driver's own BCD interaction is the *other* half of the boot story: element
`0x26000005` (`HibernateEnabled`) on object `{9dea862c-5cdd-4e70-acc1-f32b344d4795}` is
written by the GUI/CmdTool through WMI (`\\.\root\wmi` → `BcdStore` → `OpenObject` →
`ExecMethod`) before shadowing the system volume, and the backing store path is also
visible in the driver strings
(`\REGISTRY\MACHINE\BCD00000000\Objects\{9dea862c-…}\Elements\26000005`).

## 9. Registry layout

### 9.1 Product configuration

| Key / value | Type | Observed value | Access |
| --- | --- | --- | --- |
| `HKLM\SOFTWARE\Shadow Defender\Path` | REG_SZ | `C:\Program Files\Shadow Defender` | read by every module (also the `res.ini`/`user.dat` locator) |
| `HKLM\SOFTWARE\Shadow Defender\RegURL` | REG_SZ | `http://www.shadowdefender.com/purchase.php?sid=1` | read for the purchase page (`sub_140026354`) |

### 9.2 The driver service

`HKLM\SYSTEM\CurrentControlSet\Services\diskpt` (observed on the host):

| Value | Type | Data |
| --- | --- | --- |
| `ImagePath` | REG_EXPAND_SZ | `SYSTEM32\drivers\diskpt.sys` |
| `Type` | REG_DWORD | `1` (kernel driver) |
| `Start` | REG_DWORD | `0` (`SERVICE_BOOT_START`) |
| `ErrorControl` | REG_DWORD | `1` |
| `Group` | REG_SZ | `System Bus Extender` |
| `Control` | REG_DWORD | `0x10000001` |
| `GUID` | REG_SZ | `{fd1aecc8-b1e9-4b92-a188-daa06486e05b}` — **per installation** |
| `Sync` | REG_SZ | `C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat` |
| `CacheSize` | REG_DWORD | `0` |

`GUID` is the salt of the password hash and the input of the IOCTL-base derivation
(docs/04 §6, docs/08 §2). `Sync` lists the files the driver must commit out of the shadow
even while the volume is shadowed (`bootstat.dat` and each profile's
`Shadow Defender\user.dat`). `Control` bit `0x80` is the "hibernation forbidden" flag
written by `Defender.exe sub_140016CC8`; that function reads the value with default
`0x10000101` when it is missing, which differs from the host's stored `0x10000001` only in
bit 8 — the default is not a second observed value, it is the fallback used when the value
is absent.

### 9.3 Load points and filters

| Key | Value | Effect |
| --- | --- | --- |
| `…\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}\UpperFilters` | `{partmgr, diskpt}` | disk-class upper filter |
| `…\Control\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}\LowerFilters` | `{fvevol, diskpt, iorate, rdyboost}` | volume-class lower filter (below BitLocker's `fvevol`) |
| `…\Control\Session Manager\BootExecute` | contains `dpstart` while a boot-time schedule is armed | see §8 |
| `…\Services\{0CBD4F48-3751-475D-BE88-4F271385B672}` | service, `LocalSystem`, auto-start | Shadow Defender service (`Service.exe`) |
| `…\Control\SafeBoot\Minimal\{0CBD4F48-3751-475D-BE88-4F271385B672}` | present | service must start in safe mode (minimal) |
| `…\Control\SafeBoot\Network\{0CBD4F48-3751-475D-BE88-4F271385B672}` | present | …and in safe mode with networking |
| `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run` | `Shadow Defender Daemon = "C:\Program Files\Shadow Defender\DefenderDaemon.exe" /Auto` | per-user/session tray agent |

The `Run` entry is the daemon's logon path; `/Auto` makes it read
`[common] autostart` and exit if `!= 1`. Neither `Uninstall.exe` nor any other analysed
module removes this value (`observed negative`, docs/06 §5.2).

### 9.4 Registration, COM and trial

| Key | Content | Written by |
| --- | --- | --- |
| `HKLM\…\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}` | `RegisteredOwner`, `RegisteredOrganization` (read by the About page), `StartMenuFolder` (default `Shadow Defender`), `UninstallString` | installer |
| `HKCR\CLSID\{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` | `DefenderContextMenuExt Class` + `InprocServer32` (Apartment), `ProgID`, `VersionIndependentProgID`, `AppID`, `TypeLib` | `ShellExt!DllRegisterServer` (RGS 102) |
| `HKCR\AppID\{FF2EA936-C1E1-428D-9572-F4285AFC4F48}` | `DefenderShellExt` | `ShellExt!DllRegisterServer` (RGS 101) |
| `HKCR\TypeLib\{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}` | typelib registration | `ShellExt!DllRegisterServer` |
| `HKCR\*\shellex\ContextMenuHandlers\DefenderContextMenuExt`, same under `Directory` and `Drive` | the CLSID | `ShellExt!DllRegisterServer` |
| `HKCR\CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (default value) | 16 bytes = `SYSTEMTIME` — **hidden trial start timestamp** | installer / `Service.exe`; only *read* by `Defender.exe sub_140002FF4` |
| `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability\LastAliveStamp` | **deleted** before shadowing the system volume (with `SeBackupPrivilege`) | `Defender.exe sub_1400637F0`, `CmdTool sub_140026F10` |

> The trial timestamp is deliberately stored under a CLSID key that has nothing to do with
> the product; `Uninstall.exe` removes it (docs/06 §5.2, step 5).

### 9.5 Registry shadow hives

The driver mounts shadow copies of the registry under parallel key names (driver strings,
`docs/03-driver-diskpt.md` §5):

```
\REGISTRY\MACHINE\REGISTRY.SD.SYSTEM     <- \Device\<vol>\Windows\System32\Config\SYSTEM
\REGISTRY\MACHINE\REGISTRY.SD.SOFTWARE   <-  … \Config\SOFTWARE
\REGISTRY\MACHINE\REGISTRY.SD.SAM        <-  … \Config\SAM
\REGISTRY\MACHINE\REGISTRY.SD.SECURITY   <-  … \Config\SECURITY
\REGISTRY\MACHINE\REGISTRY.SD.USER.      <- \Device\<vol>\Users\<user>\NTUSER.DAT
\REGISTRY\USER\
*\REGISTRY.SD.*                          (filter pattern)
\REGISTRY\MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\ProfileList\ProfileImagePath
```

`ZwLoadKey` / `ZwUnloadKey` mount these, which is why the shadowed registry is visible and
rollback is all-or-nothing. The GUI's registry-exclusion picker addresses the same hives by
their raw paths (`\REGISTRY\MACHINE\…`, `\REGISTRY\USER\%SID%`, `@DUMMY` placeholder —
§5.2).

## 10. Reconstructed structs (reconstruction)

```c
/* dp_formats.h — reconstruction from the observations above.                     */
#pragma pack(push, 1)

typedef struct dp_exclusion {           /* 1004 B : diskpt.dat / diskptex.dat / diskpt0.dat */
    unsigned long  state;               /* 1 = active                                       */
    wchar_t        path[500];
} dp_exclusion;

typedef struct dp_volume_config {       /* 16 B : diskpt.crt, 4 records                     */
    unsigned long  id;                  /* INFERRED: volume identity                        */
    unsigned long  id_hi;
    unsigned long  size;                /* INFERRED: map size                               */
    unsigned long  state;               /* 0 normal, 1/3 shadow/armed                       */
} dp_volume_config;

#pragma pack(pop)

/* diskpt0.sys: 512-byte header, then an RC4-protected body.  The file is created with
   FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM|FILE_FLAG_WRITE_THROUGH and NTFS
   compression, and its length must equal the driver's computed map size.            */
#define DP0SYS_HEADER_SIZE  0x200
#define DP0SYS_ATTRS        0x80000006ul     /* HIDDEN|SYSTEM|WRITE_THROUGH */
```

## 11. Open questions

1. **`diskpt.crt` field semantics** — `id`, `id_hi` and the exact meaning of `state` values
   `1` vs `3` are inferred from four records on one host. Confirm by toggling volumes.
2. **`diskpt0.sys` 512-byte header layout** — only the size, the unit of I/O and the two
   zeroed dwords (`+4`, `+12`) are observed. The driver validates three dwords; which ones
   is unknown.
3. **`diskpt0.sys` body format / RC4 key** — see docs/08 §6.
4. **The `%08x%08x` chunk-name ordinals** — index/sub-index assignment unknown.
5. **`diskpt0.dat` on this host is absent** while the GUI is supposed to write it on
   "Commit Now → Apply"; either no commit list was ever applied or the file is transient.
6. **`dpstart.exe`** — never present on the host, so its behaviour was not observed; only
   its install location, its `BootExecute` reference and its removal path are known.
7. **`RegisteredOwner`/`RegisteredOrganization`** are read for the About page but their
   writer (installer vs. first run) was not observed.
