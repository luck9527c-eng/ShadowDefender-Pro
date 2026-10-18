# Shadow Defender — The Installer Package

> Artefact: `安装包\Setup.exe` (as supplied), 3 714 768 bytes,
> SHA-256 `9d2b7851eacc1a2eb43d8dc1e8a999c592c9855df3ed45c1fa26d09425b2d503`.
> Status: package structure and payload are **observed**; the install sequence is
> **observed** from the installer's own script strings and from the state the
> installer leaves behind; a few individual decisions are marked **inferred**.

This document was added after the installation package became available. It
supersedes nothing in `docs/01`–`docs/09`; it explains *how the analysed
installation came to exist* and it resolves two open questions:

* which driver image is actually installed (answer: `diskpt.win10.sys`, renamed);
* where the per-installation `GUID` — the password salt — comes from
  (answer: the installer generates it; the driver does not).

---

## 1. The package is four layers deep

```
安装包\Setup.exe                     3 714 768 B   7-Zip SFX (7zS2.sfx 9.20)
│                                                   Authenticode: Beijing YiChengWeiLai
│                                                   Culture-Tech Co., Ltd. (DigiCert EV)
├─ Setup.exe                           109 008 B   32-bit native launcher (IsWow64Process)
├─ Setup_x64.exe                     2 276 504 B   7-Zip SFX (LZMA:23 + BCJ2)
└─ Setup_x86.exe                     1 716 720 B   7-Zip SFX (LZMA:23 + BCJ2)
        │
        └─ payload (14 files) ──────────────────────────────────────────────┐
                                                                             │
        Setup.exe (x64)                888 792 B   Inno Setup installer     │
        (x86 variant:                  578 000 B)                          │
        ────────────────────────────────────────────────────────────────────┘
```

Layers observed:

| Layer | Format | Evidence |
| --- | --- | --- |
| Outer `Setup.exe` | PE32 i386, `7zS2.sfx` 9.20 stub; additional 7z stream at file offset `0xCA00` (3 647 232 B) | version resource `7z Setup SFX small`, `OriginalFilename 7zS2.sfx.exe`; 7-Zip lists `Setup.exe`, `Setup_x64.exe`, `Setup_x86.exe` |
| `Setup_x64.exe` / `Setup_x86.exe` | PE32+ / PE32 with the same 7z SFX stub; payload stream at `0xCA00` | 7-Zip lists 14 files |
| Launcher `Setup.exe` (109 008 B) | PE32 i386 native, imports `CreateProcessW`, `PathAppendW`, `IsWow64Process` | selects the x64 or x86 installer |
| Real `Setup.exe` (888 792 B x64 / 578 000 B x86) | PE32+, `Subsystem 2`, 5 sections, `.rsrc` = 436 742 B, 15 826-byte Authenticode overlay, manifest `requireAdministrator` with supportedOS Win7/8/8.1/10 | Inno Setup wizard strings (see §4) |

The Authenticode signature on **every** layer is valid and belongs to
`CN="Beijing YiChengWeiLai Culture-Tech Co., Ltd."`, issued by
`DigiCert EV Code Signing CA (SHA2)`. That is the same principal that signed the
installed `diskpt.win10.sys` (`docs/03-driver-diskpt.md` §1). The 2017 driver
variant carries a different signer — see §6.

`Setup.exe` on the outer two layers is *not* the Inno installer; it is
launcher/engine plumbing. The Inno installer is only reached after two
decompression steps.

## 2. Payload inventory

Extracted from `Setup_x64.exe` (x64) and `Setup_x86.exe` (x86); both archives
contain the same 14 names, with architecture-appropriate binaries.

| Payload name | x64 size | Installed as | Note |
| --- | --- | --- | --- |
| `Defender.exe` | 1 387 040 | `Defender.exe` | GUI |
| `Daemon.exe` | 592 768 | **`DefenderDaemon.exe`** | renamed at install |
| `Service.exe` | 134 096 | `Service.exe` | service host |
| `CmdTool.exe` | 760 640 | `CmdTool.exe` | CLI |
| `Commit.exe` | 905 336 | `Commit.exe` | shell helper |
| `ShellExt.dll` | 408 048 | `ShellExt.dll` | context menu |
| `Uninstall.exe` | 641 064 | `Uninstall.exe` | uninstaller |
| `Setup.exe` | 888 792 | (run, not installed) | Inno installer |
| **`diskpt.win10.sys`** | 478 544 | **`System32\drivers\diskpt.sys`** | **the installed driver** |
| **`diskpt.sys`** | 464 008 | `System32\drivers\diskpt.sys` on older OS | v1.4.0.672, 2017 |
| `diskpt2k.sys` | *not shipped* | — | referenced by the script; legacy Windows 2000 image, absent from this build |
| `res.ini` | 8 935 | `res.ini` | UI strings |
| `CmdTool.txt` | 1 552 | `CmdTool.txt` | CLI help |
| `Help.chm` | 335 391 | `Help.chm` | manual |
| `eula.rtf` | 10 131 | `eula.rtf` | licence |

### Byte-for-byte verification against the analysed installation

All installed files are **identical** to the payload:

```
diskpt.win10.sys == C:\Windows\System32\drivers\diskpt.sys
   6ffd78b5954064bba7370af51b2e4f1358424f542682218a1121a375f3903583
Daemon.exe       == C:\Program Files\Shadow Defender\DefenderDaemon.exe
   686e86b6a03ac32268de12d84145dfa6ffa568b6e2c92f7b432ebcd3d225dc63
CmdTool.exe, Commit.exe, Defender.exe, Service.exe, ShellExt.dll,
Uninstall.exe, res.ini                                  all identical
```

This closes the provenance question: the installation under analysis is exactly
the 1.5.0.726 package, and the driver on disk is `diskpt.win10.sys` with the
High Sierra name `diskpt.sys`. It also confirms that `DefenderDaemon.exe` is
`Daemon.exe` renamed — the version resource retains `Daemon` naming in some
places and the file is the same bytes.

## 3. Install sequence (reconstructed)

The installer is **Inno Setup**. Its Pascal script compiles to bytecode that the
Inno engine interprets, so the sequence below is reconstructed from the script's
own string constants plus the state the installer leaves on disk. Every quoted
string is an observed UTF-16 literal inside the real `Setup.exe`.

### 3.1 Pre-flight

| Check | Observed string | Behaviour |
| --- | --- | --- |
| OS version | reads `SOFTWARE\Microsoft\Windows NT\CurrentVersion` | chooses the driver image; refuses unsupported OS |
| unsupported OS | `Sorry, Shadow Defender doesn't support tihs operation system.` | abort (note the vendor's typo) |
| already shadowed | `Please install when your OS is not in Shadow Mode.` | abort |
| GUI running | `Please close Shadow Defender main interface.` | abort |
| hotfix, Win7/8 | `Shadow Defender maybe not working because KB2763674 hotfix is not found in this computer. Do you want to continue?` | warning, not fatal |
| hotfix, older Win10 builds | `Shadow Defender maybe not working because KB3185278 and KB3125574 are not found in this computer. Do you want to continue?` | warning, not fatal |
| build expiry | `Sorry, the setup program is expired.` | abort — the installer itself has a build/expiry gate |
| integrity | `Can't verify the installation,` / `Verifying the installtion ...` | pre-install verification step |

### 3.2 Driver selection

The script references three driver images:

```
\diskpt.win10.sys      shipped
\diskpt.sys            shipped (v1.4.0.672)
\diskpt2k.sys          referenced, NOT shipped
\drivers\diskpt.sys    destination
SYSTEM32\drivers\diskpt.sys
```

**Inferred selection rule** (from the file set and the destination name): Windows
10 receives `diskpt.win10.sys`; the pre-Windows-10 path receives the 2017
`diskpt.sys`; `diskpt2k.sys` remains in the script for a Windows 2000 path that
this package does not carry. The analysed host runs Windows 10
(10.0.19045), and its driver is byte-identical to `diskpt.win10.sys`, which is
consistent with the rule.

### 3.3 Files and renames

```
Defender.exe        -> <app>\Defender.exe
Daemon.exe          -> <app>\DefenderDaemon.exe
Service.exe         -> <app>\Service.exe
CmdTool.exe         -> <app>\CmdTool.exe
Commit.exe          -> <app>\Commit.exe
ShellExt.dll        -> <app>\ShellExt.dll
Uninstall.exe       -> <app>\Uninstall.exe
res.ini             -> <app>\res.ini
CmdTool.txt         -> <app>\CmdTool.txt
Help.chm            -> <app>\Help.chm
eula.rtf            -> <app>\eula.rtf
diskpt.win10.sys    -> System32\drivers\diskpt.sys
```

Observed rename mapping and the literal `.del` string indicate the standard
"replace on reboot" technique for files that are in use: the old file is renamed
with a `.del` suffix and `MoveFileExW(..., MOVEFILE_DELAY_UNTIL_REBOOT)`
completes the swap (`Setup.exe` imports `MoveFileExW` and `MoveFileW`).

### 3.4 Driver service key

The installer writes the driver's service key directly (it does not use an INF —
no `.inf` file is shipped):

```
HKLM\SYSTEM\CurrentControlSet\Services\diskpt
    ImagePath    REG_EXPAND_SZ  SYSTEM32\drivers\diskpt.sys
    Type         REG_DWORD      1            ; kernel driver
    Start        REG_DWORD      0            ; SERVICE_BOOT_START
    ErrorControl REG_DWORD      1
    Group        REG_SZ         System Bus Extender
    Control      REG_DWORD      0x10000001
    CacheSize    REG_DWORD      0
    Sync         REG_SZ         C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat
    GUID         REG_SZ         {fd1aecc8-b1e9-4b92-a188-daa06486e05b}
```

All value names are observed in the installer's string table
(`ImagePath`, `Type`, `Start`, `ErrorControl`, `Group`, `Control`, `CacheSize`,
`Sync`, `GUID`) together with the literal path
`SYSTEM\CurrentControlSet\Services\diskpt` and `System Bus Extender`.

### 3.5 The `GUID` value — password salt

This resolves the open question from `docs/08-licensing-and-crypto.md`.

Evidence:

* The installer's string table contains, in this order:
  `diskpt`, `SYSTEM\CurrentControlSet\Services\%s`, `GUID`,
  `%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x`
  — i.e. the value name and a sixteen-byte hex formatter.
* The installer imports `CoCreateGuid` (IAT RVA `0x140045ad0`) and contains **no**
  GUID literal other than its manifest's `supportedOS` identifiers.
* The driver contains **no** `GUID` string and no `UuidCreate`/`ExUuidCreate`
  import; its only randomness support is `RtlRandom`, used by an INIT routine
  (`sub_280079A08`) that seeds from `KeQueryPerformanceCounter` and then enters
  the VM.

Therefore the `GUID` under `Services\diskpt` is **created by the installer at
install time** (`CoCreateGuid`), written as a value of the driver key, and later
read by the user-mode password code as the salt. It is per installation by
design; that is why a `user.dat` copied to another machine does not authenticate.

Observed value on this host: `{fd1aecc8-b1e9-4b92-a188-daa06486e05b}`, and the
stored password hash reproduces exactly from it (see
`docs/08-licensing-and-crypto.md` §2 and `recon/verification.md` V2).

> The string `Enter a GUID.` in the installer is **not** a custom wizard page.
> It sits among the generic validation messages (`Enter an integer.`,
> `Enter a number.`, `Enter a date.`, …) and is the standard VCL edit-mask error.
> Do not infer a user-facing GUID prompt from it.

### 3.6 Filter registration

```
HKLM\SYSTEM\CurrentControlSet\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}
    UpperFilters: append "diskpt"          ; Disk drive class
HKLM\SYSTEM\CurrentControlSet\Control\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}
    LowerFilters: append "diskpt"          ; Volume class
```

Both class GUIDs and both value names (`UpperFilters`, `LowerFilters`) are
observed literals. The resulting order on the analysis host is
`{partmgr, diskpt}` and `{fvevol, diskpt, iorate, rdyboost}` respectively —
which is what the driver requires to sit on plaintext volume I/O
(`docs/03-driver-diskpt.md` §2).

### 3.7 Service, autostart and shell integration

```
"%s\Service.exe" /install              ; creates the GUID-named service
"%s\DefenderDaemon.exe" /Auto          ; Run entry
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Run
    Shadow Defender Daemon = "<app>\DefenderDaemon.exe" /Auto
```

`Service.exe /install` (`WinMain @ 0x140001010`, branch `wcsicmp(lpCmdLine,
L"/install")`) opens the SCM with `SC_MANAGER_ALL_ACCESS`,
`CreateServiceW(name = "{0CBD4F48-3751-475D-BE88-4F271385B672}",
display = "Shadow Defender Service", serviceType = 0x10, startType = 2,
binaryPath = <own path>)`, then registers the service under
`Control\SafeBoot\Minimal\{0CBD4F48-…}` and `…\Network\{0CBD4F48-…}`.

The installer's own string table also contains the shell-extension registration
and shortcut targets:

```
\Shadow Defender.lnk                   (Start Menu folder)
\Uninstall Shadow Defender.lnk
\Microsoft\Internet Explorer\Quick Launch\Shadow Defender.lnk
Create a Quick Launch icon
```

and the uninstall entry:

```
HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}
    DisplayName, DisplayVersion, Publisher, UninstallString, NoModify=1, NoRepair=1
HKLM\SOFTWARE\Shadow Defender
    Path    = C:\Program Files\Shadow Defender
    RegURL  = http://www.shadowdefender.com/purchase.php?sid=1
```

The trial marker key `CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` is also
referenced by the installer, consistent with it being created at install time
and later used by the GUI for the hidden trial timestamp.

### 3.8 Completion

Observed completion strings:

```
<PRODUCT> <VERSION> is being installed, please wait ...
<PRODUCT> <VERSION> has been installed on your computer.
Setup is not complete. If you exit now, the program will not be installed.
To complete the installation of <PRODUCT>, Setup must restart your computer.
```

A reboot is requested when a locked file had to be scheduled for replacement
(the `.del` path).

## 4. What the installer tells us that the installed tree could not

1. **Driver provenance.** The installed `diskpt.sys` is the shipped
   `diskpt.win10.sys`; the package also carries a 2017 `diskpt.sys`
   (v1.4.0.672) for older systems. The driver is deployed by **copy + service
   key creation**, not by an INF. There is no `.inf` in the package.
2. **The password salt is installer-generated.** `CoCreateGuid` + the `GUID`
   value writer + the absence of any GUID logic in the driver.
3. **The vendor identity.** The installer, the 2020 driver and (on this host)
   the whole distribution are signed by `Beijing YiChengWeiLai Culture-Tech Co.,
   Ltd.` under an EV certificate. That is the entity to attribute the product to
   for the 1.5 line.
4. **File renaming.** `Daemon.exe` → `DefenderDaemon.exe`; `diskpt.win10.sys` →
   `diskpt.sys`. Any file-name-based detection keyed on `Daemon.exe` or
   `diskpt.win10.sys` will miss an installed system.
5. **The installer has its own expiry and OS gates** and a hotfix warning set
   (`KB2763674`, `KB3185278`, `KB3125574`), which is useful for dating builds.

## 5. Driver variant comparison

| | `diskpt.sys` (2017) | `diskpt.win10.sys` (2020) |
| --- | --- | --- |
| FileVersion | **1.4.0.672** | **1.5.0.726** |
| Size | 464 008 | 478 544 |
| Signer | `StarSoftComm(China) Ltd.` | `Beijing YiChengWeiLai Culture-Tech Co., Ltd.` |
| Image base | `0x280050000` | `0x280050000` |
| `.text` | `0x1000`, `0x1FA04` | `0x1000`, `0x20544` |
| `.reloc` vault | `0x2C000`, **RWX**, `0x45518` | `0x2D000`, **RWX**, `0x48334` |
| `BASERELOC` directory | `0x2C000`, size **`0x18`** | `0x2D000`, size **`0x18`** |

Both variants use the same obfuscation framework: a section named `.reloc` whose
real relocation directory is 24 bytes, followed by a disguised code/data vault
(`docs/02-obfuscation.md`). The 1.4 driver's vault is `0x45518` bytes versus
`0x48334` in 1.5 — the framework predates the 1.5 line and grew slightly.

A reconstruction that must support both lines has to parameterise the vault
(`state` RVA, dispatch-table RVA, entry count) per build rather than hard-code
the 1.5 values.

## 6. Signing-identity timeline (observed)

| Year | Artefact | Signer |
| --- | --- | --- |
| 2017-10-15 | `diskpt.sys` v1.4.0.672 | `StarSoftComm(China) Ltd.` |
| 2020-08-01 | `diskpt.win10.sys` v1.5.0.726 | `Beijing YiChengWeiLai Culture-Tech Co., Ltd.` |
| 2020-08-06 | all user-mode binaries, `Setup.exe` | `Beijing YiChengWeiLai Culture-Tech Co., Ltd.` |

The 2020 certificate is EV (`DigiCert EV Code Signing CA (SHA2)`,
`SERIALNUMBER=91110108MA01PLRK7N`, private-organization extension present). This
is a factual observation about the artefacts; it does not by itself establish the
corporate relationship between the two named entities.

## 7. Reproduction

```bash
# 1. outer SFX -> three files
python - <<'PY'
import struct
d=open('安装包/Setup.exe','rb').read()
start=d.find(bytes.fromhex('377abcaf271c'))
# locate the valid archive header at the SFX payload offset
import re
for m in re.finditer(re.escape(bytes.fromhex('377abcaf271c')), d):
    i=m.start()
    try:
        nh_off, nh_size = struct.unpack_from('<QQ', d, i+12)
        end=i+32+nh_off+nh_size
        if d[i+6:i+8] in (b'\x00\x04', b'\x00\x03') and 0 < nh_size < 10**7 and end <= len(d):
            open('work/pack/payload.7z','wb').write(d[i:end]); print('carved at', hex(i), 'len', end-i)
    except Exception: pass
PY

# 2. list/extract with 7-Zip (any 7z binary; 20.02 x86 used here)
7z x -y -owork/pack/extracted work/pack/payload.7z          # Setup.exe, Setup_x64.exe, Setup_x86.exe
7z x -y -owork/pack/x64 work/pack/Setup_x64.exe.7z          # 14 payload files (carve first, see tools)
7z x -y -owork/pack/x86 work/pack/Setup_x86.exe.7z
```

The carve step is needed because the SFX executable is not a bare archive: the
7z stream starts at file offset `0xCA00` and the last 15 826 bytes of the file
are the Authenticode signature.

## 8. Open items specific to the installer

* The exact OS-to-driver predicate (which build number switches to
  `diskpt.win10.sys`) is **inferred**, not decoded: the Inno script is bytecode
  inside a compressed setup-data block.
* Whether `diskpt2k.sys` was ever shipped in another package cannot be
  determined from this build; it is referenced but absent.
* The installer's expiry date and integrity-verification mechanism were not
  decoded; only the user-facing strings were observed.
* The x86 installer (`Setup_x86.exe`, 578 000 B) was listed but not analysed in
  detail; it contains the same 14 names with 32-bit binaries
  (`CmdTool.exe` 568 784 B, `Defender.exe` 1 158 920 B,
  `diskpt.win10.sys` 350 536 B, `diskpt.sys` 342 152 B).
