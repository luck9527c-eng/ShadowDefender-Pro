# Shadow Defender 1.5.0.726 — `Defender.exe` / `DefenderDaemon.exe`
## Reconstructed technical report (from IDA Pro Hex-Rays exports)

**Targets analysed**

| Binary | Size | Image base | PDB path (leaked) |
|---|---|---|---|
| `Defender.exe` (main GUI) | 1 387 040 B | `0x140000000` | `D:\Work\Defender\app\Defender\x64\Release\Defender.pdb` (string @ `0x1400adddc`) |
| `DefenderDaemon.exe` (tray daemon) | 592 768 B | `0x140001000` | (not exported) |

**Evidence sources** (all in `recon/ida/`):
`Defender/all_pseudocode.c`, `Defender/all_disasm.asm`, `Defender/strings.txt`, `Defender/names.txt`,
`Defender/imports.txt`, `Defender/segments.txt`, `Defender/functions.txt`,
`DefenderDaemon/all_pseudocode.c`, `DefenderDaemon/all_disasm.asm`, `DefenderDaemon/strings.txt`,
plus `samples/res.ini`, `samples/user.dat`, `samples/Defender.exe`, `samples/DefenderDaemon.exe`
(raw PE used to resolve data templates by VA→file-offset) and `samples/CmdTool.txt`.

**Conventions used below**
* `0x1400xxxxx` = VA in `Defender.exe`; `0x1400xxxxx` (daemon) is marked as such.
* **OBSERVED** = literally present in the decompilation / disassembly / raw data.
* **INFERRED** = my interpretation of observed facts.
* **UNKNOWN** = not recoverable from these exports (reason given).
* Function names like `sub_140012F34` are IDA names; I add my inferred name in *italics*.
* `¶` marks a citation: file + address.

---

## 0. Executive summary

`Defender.exe` is a 64-bit MFC (statically linked, VS2017-era `vc7libs`/`14x` ATL) dialog application.
Its main window is a `#32770` dialog class (`FindWindowW(L"#32770", L"Shadow Defender")`
¶`0x14000e160`, `sub_14000DFB8`/`all_pseudocode.c`), registered under a *global* single-instance mutex
`Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` (¶`0x14000dfb8`).

All privileged work (enter/exit shadow mode, commit, exclusions, write-cache configuration) is done by
calling into the **kernel driver `diskpt.sys` directly** from user mode:

* control device `\\.\DpControl` (symbolic link to `\FileSystem\Filters\DpControl`),
  used with **IOCTL `0x800030A0`** (query GUID/state) and with
  **IOCTL `0x800025E4 + K`** where `K` is a per-installation DWORD derived from
  `HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID` and computed by an obfuscated helper
  (`sub_140061A90`, global `dword_1400C9DB0` set from a CRT initialiser ¶`0x140001339`);
* per-volume shadow devices `\\.\DpShadow<hex>` (created by the driver: ¶`diskpt.sys` `0x28008...`, same
  naming as `swprintf(L"\\DosDevices\\%s%x", "DpShadow", ...)` ¶`diskpt/all_pseudocode.c:2203`);
* raw volume handles `\\.\X:` with `FSCTL_LOCK_VOLUME`=`0x90018`, `FSCTL_DISMOUNT_VOLUME`=`0x9001C`,
  `FSCTL_UNLOCK_VOLUME`=`0x90020` and one private FSCTL `0x98144`;
* a progress channel `Global\ShadowDefenderSharedMemory` (create-file-mapping, 0x1000 bytes, first DWORD = %).

There is **no named pipe**, and **no window-message IPC between `Defender.exe` and `DefenderDaemon.exe`**
(OBSERVED: `Defender.exe` contains none of the daemon's strings/window class and imports no
`RegisterWindowMessage`, see §2.6). The daemon is a *passive* tray/tip agent that reads the same
`user.dat`/`res.ini`, receives volume notifications from the driver, and launches
`Defender.exe /exit` when the user picks "Exit All Shadow Mode".

Passwords are `MD5(UTF-16LE(serviceGUID + password))` hex-lowercase; the empty password is the sentinel
`MD5(GUID + "@BLANKPWD")`. Registration codes are 25 characters: the first 16 are a base-31 encoding of
`MD5(ANSI(code)+key)[16..]` (the hash covers **everything except the first 16 characters**), the key being
`"V100"`/`"V110"`; the serial is stored obfuscated as `hash2` using a 7-element additive substitution cipher.
A 30-day trial timestamp is hidden in `HKCR\CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (a `SYSTEMTIME`).

A significant part of the driver-facing API layer of `Defender.exe` is **control-flow obfuscated**: ~24
functions end in `jmp loc_14014xxxx` stubs that push an RVA + a cookie (`0x35`) and jump to a dispatcher
`sub_140147C33` located in a section deliberately named `.reloc` (`RWX`, class=CODE,
`0x140119000-0x140157000`, ¶`segments.txt`). Those blocks were never disassembled in the export, so the
*inner bodies* of the IOCTL wrappers are lost; everything around them (strings, buffer sizes, constants,
call sites, callers) is recovered and cited below.

---

## 1. Program structure

### 1.1 Segments / build

```
HEADER  0x140000000-0x140001000  ---
.text   0x140001000-0x140084000  R-X  (523 KB code)
.idata  0x140084000-0x140084f58  R--
.rdata  0x140084f58-0x1400c2000  R--
.data   0x1400c2000-0x1400c57d0  RW-
.data   0x1400c5860-0x1400cb000  RW-
.pdata  0x1400cb000-0x1400d3000  R--
.reloc  0x140119000-0x140157000  RWX class=CODE   <-- obfuscated code, NOT exported
```
¶`segments.txt`. Imports show a statically linked MFC 14.x (CWinApp/CWnd/CDialog/CFile/CFileFind/
CInternetSession/CHttpFile/CListCtrl, `CDataRecoveryHandler`, D2D, GDI+), `GdiplusStartup`, WININET,
`SHGetValueW/SHSetValueW`, `DeviceIoControl`, `CreateFileMappingW/MapViewOfFile`, no `WinHttp`, no COM server.
¶`imports.txt`.

### 1.2 Entry point chain (OBSERVED)

| Address | Symbol | Role |
|---|---|---|
| `0x14005eea4` | `start` | CRT entry (from `__scrt_common_main_seh`) |
| `0x14005ed30` | `?__scrt_common_main_seh@@YAHXZ` | CRT startup, calls `WinMain` |
| `0x14007f8c0` | `WinMain_0` | **MFC `AfxWinMain`**: `AfxWinInit` → `pThread->InitInstance()` → `pThread->Run()` ¶`0x14007f8c0` |
| `0x14000d12c` | `sub_14000D12C` | **`CDefenderApp::CDefenderApp()`** — installs `CDefenderApp::\`vftable'` (RTTI `.?AVCDefenderApp@@` @ `0x1400c37b8`, vftable lea @ `0x14000d14f`) and two `CString` members at `this+400`/`this+432` ¶`0x14000d12c` |
| `0x14000dfb8` | `sub_14000DFB8` | **`CDefenderApp::InitInstance()`** ¶`0x14000dfb8` |
| `0x14000d720` | `sub_14000D720` | **`CDefenderApp::ExitInstance()`** — `SetEvent`, `WaitForSingleObject`, `GdiplusShutdown`, `CoUninitialize` ¶`0x14000d720` |
| `0x14001201c` | `sub_14001201C` | **main window `OnInitDialog` + message handling** (size 0xd6d) ¶`0x14001201c` |

`InitInstance` sequence (OBSERVED ¶`0x14000dfb8`):

1. `LoadLibraryW(L"Shcore")` + `GetProcAddress(...,"SetProcessDpiAwareness")`.
2. `sub_14000D46C()` — opens `\\.\ <winDriveLetter>:` to test driver presence (template `L"\\\\.\\ :"` @ `0x1400943a0`).
3. `sub_1400622F0()` (obfuscated SD-API init, returns non-zero on success).
4. `LoadLibraryW(L"gdiplus.dll")`, `GdiplusStartup(app+416, …)`.
5. `sub_14000D538(app)` — command-line scan for **`/exit`** (`CommandLineToArgvW`, `wcsicmp(*v, L"/exit")`,
   sets `app+384=1`) ¶`0x14000d538`; string `/exit` @ `0x140087d78`.
6. `CreateMutexW(NULL, TRUE, L"Global\\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}")`;
   if `GetLastError()==183` (already running) → `FindWindowW(L"#32770", L"Shadow Defender")`,
   `ShowWindow`, `SetForegroundWindow`, and if `/exit` was given `SendMessageW(hwnd, 0x4C9, 0, 0)`
   (custom "exit now" message) ¶`0x14000dfb8`.
7. Build help path `<exedir>\help.chm` into `app+208`; `CreateSolidBrush(0xF0F0F0)` for the page background.
8. Failure of step 2 (driver missing) → message **res.ini ID `0x3E8` = 1000 `"You have not enough privilege."`**
   ¶`0x14000dfb8`.

### 1.3 Main window (OBSERVED)

* `SetWindowText` = res.ini ID **0** (`"Shadow Defender"`) ¶`0x14001201c` line ~146.
* Custom bitmap-tab control at `this+7528`: `sub_140007AC8(ctrl, 7)` / `(ctrl, 6)` — **7 tabs on
  Vista+, 6 on XP** (`IsVistaOrLater()` = `sub_14000EBAC`, `GetVersionExW().dwMajorVersion < 6`) ¶`0x14000ebac`.
* Bitmaps loaded from instance resources `0xAB, 0xAC, 0xAD` (`LoadBitmapW(inst, (LPCWSTR)0xAB)`).
* `SetTimer(hwnd, 0, 1000 /*1 s*/, NULL)` ¶`0x140012b..`.
* Status bar text ID **21** (`"For help, press F1"`), menu item **20** (`"&Register"`).
* Tray icon / desktop tip in the GUI itself: `sub_140013708` (icon), `sub_140013868(this,1,1,0)` (tip) ¶`0x140012...`.

### 1.4 Dialog / page inventory (OBSERVED via `res.ini` ID usage per function)

`sub_14000D8DC(app, out, id)` is the res.ini string loader (§4.1); every dialog initialiser uses it:

| Function | res.ini IDs used | Inferred class |
|---|---|---|
| `sub_14001201C` | 0,10,11,12,13,14,15,16,20,21,22 | **`CDefenderDlg`** (main, tab captions + menu) |
| `sub_1400212FC` | 10000–10012 | **`CStatusPage`** init ("System Status") |
| `sub_140020A84` | 100,101 | `CStatusPage` refresh + pie chart |
| `sub_140021A9C` | 10001 (+ reads `%SystemRoot%\diskpt.dat`) | status: "Exclusion list:" count |
| `sub_140023FBC` | 20000–20020 | **`CVolumePage`** init ("Mode Setting") |
| `sub_140022BA0` | 1002,1005,1012,20016 | **`CVolumePage::OnApply`** (enter/exit) |
| `sub_140023214` | 1002,1005 | exit / apply worker launcher |
| `sub_1400236BC` | 1002,1005,1012 | "Exit All Shadow Modes" worker launcher |
| `sub_1400260B8` | 20012–20015,20018 | volume-page tooltips |
| `sub_1400254D4` | 20020 | RAM-cache warning tooltip |
| `sub_140015DE8` | 200,30000–30010 | **`CFilePage`** init ("File Exclusion List") |
| `sub_140014CC8`,`sub_140014F7C`,`sub_140015BD8` | 1011,1020,1021,30008,30012,30013 | file-page add/save/load/validate |
| `sub_14001E614`,`sub_14001EDF0` | 1002,1019,1020,1021 | **`CCommitPage`** ("Commit Now") save/load `.sdrl` |
| `sub_14000A09C`,`sub_14000A964`,`sub_140015284` | 1011,1020,1021 (+`.sdl`) | commit/exclusion list file dialogs |
| `sub_140017854` | 200,50000–50015 | **`CGeneralPage`** init ("Administration") |
| `sub_140017D38` | 50006 | `CGeneralPage` state push/pull |
| `sub_14001F734` | 200,60000–60009 | **`CRegistryPage`** ("Registry Exclusion List") |
| `sub_14001C5B4`,`sub_14001C1CC` | 180000–180003 (+`@DUMMY`) | **`CRegistryDlg`** ("Select a registry item") |
| `sub_1400055E8` | 110000–110008 | **`CAboutPage`** |
| `sub_140012F34` | (no res id) | **`CLoginDlg` "blank password" path** |
| `sub_14001A2CC` | 1003 | **`CLoginDlg::OnOK`** (password entry, 3 tries) |
| `sub_14001A958` | 70000–70003 | **`CLoginDlg`** init |
| `sub_140020314` | 80000–80004 | **`CSetPwdDlg`** |
| `sub_140016888` | 50007 | `ChangePassword()` (drives `CSetPwdDlg`) |
| `sub_14001BC90` | 100000–100004 | **`CRegisterDlg`** |
| `sub_14001BFC4` | (none) | "Get Registration Code" button |
| `sub_14001430C` | 120000–120006 | **`CEnterDlg`** |
| `sub_14001481C` | 130000–130009 | **`CExitDlg`** |
| `sub_14001AEF8` | 160000–160007 | **`CLowSpaceDlg`** ("Threshold Space Setting") |
| `sub_140020624` | 140001–140008 | **`CShutdownDlg`** (reboot/shutdown prompt) |
| `sub_140026570` | 90000–90004 | **trial nag dialog** ("expired"/"expire in %d day(s)") |
| `sub_1400055E8` + `sub_140010E30` | 1100xx / update | About / update check |
| `sub_1400201FC` | 1003,1004 | small password retry prompt |
| `sub_14000FA78` | 1009 | **commit progress callback** |
| `sub_14000B85C` | 1002,1006,1007,1008,1022 | **commit engine** (§5.3) |

Class names are confirmed independently by RTTI strings in `.data`: `CDefenderApp`, `CDefenderDlg`,
`CStatusPage`, `CVolumePage`, `CFilePage`, `CCommitPage`, `CGeneralPage`, `CRegistryPage`, `CRegistryDlg`,
`CAboutPage`, `CLoginDlg`, `CSetPwdDlg`, `CRegisterDlg`, `CEnterDlg`, `CExitDlg`, `CLowSpaceDlg`,
`CShutdownDlg`, `CBusyDlg`, `CCommitOptionDlg`, `CWelcomeDlg`, `CBitmapTab`, `CPageHolder`, `CChildPage`,
`CTipCtrl`, `CTitleCtrl`, `CInPlaceEdit`, `CInPlaceCombo`, `CHyperLink`, `C2DPieGraph`, `MD5_CTX`
¶`all_pseudocode.c` lines 1810–2219 (RTTI block `0x1400c33e0` …).

### 1.5 Threads (OBSERVED)

| Thread proc | Started from | Purpose |
|---|---|---|
| `sub_14000F218` | `sub_140022BA0`, `sub_140023214`, `sub_1400236BC` | **shadow-mode worker** (mode 1 enter / 2 exit-commit / 3 flag-only), `SetThreadPriority(15)` |
| `sub_14000D36C` | app init | waits 5–15 s (randomised) for the "exit event" then checks the system volume's `X:\diskpt0.sys` flag |
| `sub_14000EC2C` | (menu / startup) | launches `DefenderDaemon.exe` via `ShellExecuteW` |
| `StartAddress` `0x14000c294` | `CreateThread` from commit paths | **commit worker**: normalises paths (wildcards, trim), calls `sub_14000B85C` |
| `sub_140061540` | `sub_140063C20` | **progress monitor**: waits on {abort event, driver progress event}, calls progress callback with the value in shared memory |
| update thread | `sub_140010E30` as `CreateThread` start routine | HTTP update/registration check |

---

## 2. IPC — how `Defender.exe` talks to the driver / service

### 2.1 Overview (OBSERVED names)

```
Defender.exe ──CreateFile("\\\\.\\DpControl")──► \FileSystem\Filters\DpControl      (diskpt.sys)
     │            IOCTL 0x800030A0                       (GUID / volume state query, 0x88 buf)
     │            IOCTL 0x800025E4 + K  (K = f(GUID))    (session / config push, 0x88 buf)
     ├──CreateFile("\\\\.\\DpShadow<hex>")──────────────► shadow volume device object
     ├──CreateFile("\\\\.\\X:") + FSCTL 0x90018/0x9001C/0x90020/0x98144
     ├──CreateFileMapping("Global\\ShadowDefenderSharedMemory")  (progress %)
     └──user.dat / res.ini / %SystemRoot%\diskpt*.dat  (file-based config + lists)

Service.exe ──CreateEvent/OpenEvent──► "Global\\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}"
DefenderDaemon.exe ──OpenEvent/WaitForSingleObject──► same event
DefenderDaemon.exe ──ShellExecute("Defender.exe","/exit")──► Defender.exe
```

### 2.2 `\\.\DpControl` — control device (OBSERVED)

Opened with `CreateFileW(L"\\\\.\\DpControl", GENERIC_READ(0x80), FILE_SHARE_READ|WRITE(3), NULL,
OPEN_EXISTING(3), FILE_ATTRIBUTE_NORMAL(0x80), NULL)` in every wrapper
(string `aDpcontrol` @ `0x14006173e`, `0x14006184e`, `0x140061bd5`, `0x140062578`, `0x1400626c3`,
`0x140062803`, `0x14006370e`, `0x140063f20`). The name literal is `L"\\\\.\\DpControl"` (raw bytes
`5C 00 5C 00 2E 00 5C 00 44 00 70 00 ...`).

**IOCTL A — GUID/state query: `0x800030A0`** (fixed, no base added)

`sub_140061BA0(arg0_out512)` ¶`0x140061ba0` @ `0x140061c6b`:
```
CreateFileW(L"\\\\.\\DpControl", 0x80, 3, 0, 3, 0x80, 0);   // GENERIC_READ
ZeroMemory(local, 0x88);                                   // 136-byte in/out buffer
DeviceIoControl(h, 0x800030A0 /* edx=800030A0h */,
                local, 0x88, local, 0x88, &bytes, NULL);   // r8=local, r9d=0x88
CloseHandle(h);  return 1 on success;
```
Callers use it to obtain the diskpt **service GUID string** into a 512-byte buffer
(`sub_140012F34`, `sub_140017D38`, `sub_14001A2CC`, `sub_140001...`): pattern
```
if (sub_140061BA0(Buffer) == 0) {           // IOCTL failed → registry fallback
    sprintf_s(key, "SYSTEM\\CurrentControlSet\\Services\\%s", L"diskpt");
    SHGetValueW(HKEY_LOCAL_MACHINE, key, L"GUID", …, Buffer, &size512);
}
```
So the decoded meaning is INFERRED: **"give me the installation GUID"** (used by both sides to derive the
common IOCTL base). The exact 136-byte layout of the query block is UNKNOWN (the body is in the `.reloc` VM).

**IOCTL B — session/config push: `0x800025E4 + K`**

`sub_140061710` ¶`0x140061710` @ `0x1400617a1` and `sub_140063EF0` ¶`0x140063ef0` @ `0x140063f96`:
```
h = CreateFileW(L"\\\\.\\DpControl", 0x80, 3, 0, 3, 0x80, 0);
ZeroMemory/init local 0x88-byte block;                       // sub_140063EF0 zeroes 136 bytes
GetModuleHandleW(L"kernel32.dll"); DeviceIoControl = GetProcAddress(...,"DeviceIoControl");
code = dword_1400C9DB0 + 0x800025E4;                         // add eax, 800025E4h
DeviceIoControl(h, code, &local, 0x88, &local, 0x88, &bytes, NULL);
CloseHandle(h);
```
`dword_1400C9DB0` is a module-global initialised by a CRT constructor:
`sub_140001330` → `result = sub_140061A90(); dword_1400C9DB0 = result;` ¶`0x140001339`.
`sub_140061A90` ¶`0x140061a90` reads `HKLM\SYSTEM\CurrentControlSet\Services\diskpt` value `GUID`
(512-byte `REG_SZ`, e.g. `{XXXXXXXX-....}`) and returns a DWORD **derived from it by the obfuscated tail**
(UNKNOWN exactly which bytes; the visible code path ends in the `.reloc` dispatcher at `0x140061b2e`).
INFERRED: the driver uses the installation GUID as a per-install secret so that a third party cannot
compute the IOCTL numbers statically; both `Defender.exe` and `diskpt.sys` derive the same 32-bit `K`.

Wrappers seen:
* `sub_140061710()` — "release/end session" (called after config file I/O, see §3).
* `sub_140061820(arg)` — "acquire/begin session" (called before config file I/O). Both contain the
  identical IOCTL-B block ¶`0x140061710`, ¶`0x140061820`.
* `sub_1400636E0()` ¶`0x1400636e0` — same but *without* an explicit 0x88 init (used to push
  low-space thresholds / tray / tip settings to the driver).
* `sub_140063EF0()` ¶`0x140063ef0` — called at the start of entering shadow mode (`sub_14000F218` case 1).

**IOCTL C — private volume FSCTL `0x98144`** (OBSERVED ¶`0x14006396c`, `sub_1400637F0`)

```
h = CreateFileW(L"X:\\", GENERIC_WRITE, 3, 0, 3, FILE_FLAG_NO_BUFFERING(0x2000000), 0);
DWORD in[10] = {0x4000, 0, ...};                    // 0x28 = 40 bytes, first dword 0x4000
DeviceIoControl(h, 0x98144, in, 0x28, NULL, 0, &bytes, NULL);
```
`0x98144` decodes as `CTL_CODE(0x9 /*FILE_DEVICE_FILE_SYSTEM*/, 0x51, METHOD_BUFFERED, FILE_ANY_ACCESS)`
with the vendor bit `0x8000` OR-ed into the device type (a common trick to smuggle a "write" variant of an
FSCTL past the `FILE_ANY_ACCESS` check). INFERRED: "prepare volume for shadowing / mark dirty".
After it, for the **Windows volume** the app enables `SeBackupPrivilege`, deletes
`HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability\LastAliveStamp`, and calls
`RegFlushKey` on HKLM/HKCU/HKCC/HKCR/HKU, then opens `\\.\X:` again (obfuscated `sub_140063AF0`).

**IOCTL D — private volume query `0x560000`** (OBSERVED ¶`0x14000259d`, `sub_14000251C`)
```
h = CreateFileW(path, GENERIC_READ, 3, 0, 3, 0, 0);
DeviceIoControl(h, 0x560000, NULL, 0, OutBuffer /*0x1000*/, 0x1000, &bytes, NULL);
*out = *(DWORD*)(OutBuffer + 8);        // dword at offset 8 of the reply (size in MB is printed as MB/GB)
```
Called with `\\?\Volume{GUID}` names in `sub_14000F218`, `sub_14002482C`, `sub_140024E0C`
(exit-shadow path). INFERRED: "how many bytes does SD occupy on this volume" (matches res.ini 10008
"Space Used by SD").

### 2.3 Volume handles and FSCTLs (OBSERVED, un-obfuscated)

`sub_1400603C0` ¶`0x1400603c0` (lock + dismount loop used by commit):
```
h = CreateFileW(L"\\\\.\\X:", GENERIC_READ|GENERIC_WRITE(0xC0000000), 3, 0, 3, 0x80, 0);
DeviceIoControl(h, 0x90018 /*FSCTL_LOCK_VOLUME*/);       // ¶0x140060510
DeviceIoControl(h, 0x9001C /*FSCTL_DISMOUNT_VOLUME*/);    // ¶0x1400605/0x1400607a0
DeviceIoControl(h, 0x90020 /*FSCTL_UNLOCK_VOLUME*/);      // ¶0x14006055e, 0x140060834
// then open the SHADOW device:
sprintf(buf, L"\\\\.\\%s%x", L"DpShadow", volInfo[0]);    // ¶0x1400606f1-0x1400606f8
h2 = CreateFileW(buf, GENERIC_RW, 3, 0, 3, 0x80, 0);
DeviceIoControl(h2, 0x90018/0x9001C/0x90020 …)            // lock/dismount the shadow volume too
```
`sub_140060CB0` ¶`0x140060cb0` is the same routine with a different retry order; `sub_140063C20` tries
`CB0`→`3C0`→`CB0`→`3C0` (4 attempts) before committing the volume.
`sub_140022BA0` uses the same FSCTLs purely as a **busy test** before entering shadow mode
(¶`0x140022d59`, `0x140022d91`) and shows res 20016 ("Some files on this volume(s) are in use…") on failure.

`sub_140061930(drive)` = open `\\.\X:` with `GENERIC_RW` ¶`0x140061930`.
`sub_140062910(drive)` = open `\\.\X:` `GENERIC_READ` ¶`0x140062910`.
`sub_140002470(drive)` = open `\\.\X:\` (`L"\\\\.\\C:\\"` template @ `0x1400852c0`) and `FlushFileBuffers`
¶`0x140002470`.

### 2.4 Shared memory / progress channel (OBSERVED)

`sub_140063C20` = *CommitVolume/SwitchVolume with progress* ¶`0x140063c20`:
```
CreateEventW(NULL,FALSE,FALSE,NULL)        -> "Parameter"  (auto-reset, driver -> monitor)
CreateEventW(NULL,TRUE ,FALSE,NULL)        -> hEvent       (manual-reset, abort)
CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE(4), 0, 0x1000,
                   L"Global\\ShadowDefenderSharedMemory");            // ¶0x140063cb3
base = MapViewOfFile(hMap, FILE_MAP_WRITE|FILE_MAP_READ(6), 0,0,0);
*(DWORD*)base = 0;                                    // progress counter DWORD[0]
hThread = CreateThread(NULL,0,sub_140061540,&tlsParams,0,NULL);
sub_140061820();                                      // driver "begin"
v6 = sub_140060CB0(drive, flags, ctx);
if (!v6) v6 = sub_1400603C0(drive, flags, ctx);
if (!v6) v6 = sub_140060CB0(drive, flags, ctx);
if (!v6) v6 = sub_1400603C0(drive, flags, ctx);
err = GetLastError();
sub_140061710();                                      // driver "end"
…
SetEvent(hEvent); WaitForSingleObject(hThread,INFINITE);
```
`sub_140061540` = monitor thread ¶`0x140061540`: `WaitForMultipleObjects(2, {hEvent, Parameter})`;
while `Parameter` fires it calls `callback(*progressDWORD, ctx)`.
The callback is `sub_14000FA78` ¶`0x14000fa78`: formats res.ini ID **0x3F1 = 1009**
`"Committing %s ..., %d percent completed."` with the drive letter and the shared-memory value, then
`SendMessageW(hwnd, 0x465, heapBlock, 0)` to update the busy dialog.

⇒ **The driver publishes commit progress as a DWORD in
`\BaseNamedObjects\ShadowDefenderSharedMemory` and signals a user-supplied event handle.**
Object name in code is `Global\ShadowDefenderSharedMemory` (session-global, matches the earlier finding).

### 2.5 Other synchronisation objects (OBSERVED)

| Object | Type | Created in | Notes |
|---|---|---|---|
| `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | mutex | `Defender.exe` `sub_14000DFB8` @`0x14000dfb8` | single instance of the GUI |
| `Local\Shadow Defender Daemon Mutex` | mutex | daemon `WinMain` @`0x140003680` | single instance per session |
| `Global\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}` | event | **`Service.exe`** (string @ Service.exe `0x18140`); daemon `OpenEventW(EVENT_MODIFY_STATE(0x1F0003))` then waits | "SD busy / commit in progress" latch; daemon waits on it before doing work |
| `Global\ShadowDefenderSharedMemory` | file mapping (0x1000) | `Defender.exe` `sub_140063C20` | progress |
| `hEvent` / `Parameter` | unnamed events | `sub_140063C20` | progress handshake |
| unnamed events + `sub_1400057A0` / `sub_140005670` | device-change notifications | daemon | volume arrival/removal |

### 2.6 What is **not** used (OBSERVED negatives)

* **No named pipes**: the string `pipe` does not occur in `all_disasm.asm` of either binary.
* **No `WM_COPYDATA`, no `RegisterWindowMessage` in `Defender.exe`** (imports.txt has it only in the daemon,
  which registers `TaskbarCreated` ¶daemon `sub_140001000` @`0x140001000`).
* `Defender.exe` contains none of `WM_DAEMONMSG`, `Shadow Defender Daemon Window`,
  `Shadow Defender Daemon Mutex`, or the daemon's `Global\{C6F6A26F…}` GUID (raw-PE search of
  `samples/Defender.exe` → NOT FOUND); the daemon contains none of the GUI's custom messages.
* The only cross-process channel Defender.exe↔daemon is **launch + `/exit`** (see §7): `Defender.exe`
  spawns the daemon (`sub_14000EC2C`, `ShellExecuteW(...,"open", "...\DefenderDaemon.exe", ...)`), and the
  daemon spawns `Defender.exe /exit` (`sub_1400025D0(1)`, daemon).
* The daemon's self-messages are `WM_USER+0x65` (0x465 refresh), `+0x66` (0x466), `+0x67` (0x467 volume
  change) and `0x47B` — INFERRED to be the message the daemon logs as **`WM_DAEMONMSG`**, wParam
  `DM_SHOWTIP=1` / `DM_HIDETIP=2`
  (debug strings at daemon `0x140003582-0x1400035ad`, sender `sub_1400034C0` @`0x1400034c0`) — these are
  **internal**, not used by `Defender.exe`.

### 2.7 Reconstructed wrapper (reconstruction, not original source)

```c
/* --- reconstruction: SD-API device session IOCTL (sub_140061710 / sub_140061820 / sub_1400636E0) --- */
static DWORD g_IoctlBase;                 /* dword_1400C9DB0 */

static BOOL DpOpenControl(void)           /* returns 1 on success; handle closed inside VM blocks */
{
    HANDLE h = CreateFileW(L"\\\\.\\DpControl", GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE,
                           NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) return FALSE;
    BYTE ctx[0x88] = {0};                 /* 136-byte session block; content UNKNOWN */
    DWORD bytes;
    BOOL ok = DeviceIoControl(h, g_IoctlBase + 0x800025E4, ctx, sizeof ctx,
                              ctx, sizeof ctx, &bytes, NULL);
    CloseHandle(h);
    return ok;
}

static BOOL DpQueryGuid(WCHAR *out512)    /* sub_140061BA0, IOCTL 0x800030A0 */
{
    HANDLE h = CreateFileW(L"\\\\.\\DpControl", GENERIC_READ, 3, NULL, OPEN_EXISTING, 0x80, NULL);
    if (h == INVALID_HANDLE_VALUE) return FALSE;
    BYTE q[0x88] = {0}, bytes;
    BOOL ok = DeviceIoControl(h, 0x800030A0, q, sizeof q, q, sizeof q, &bytes, NULL);
    CloseHandle(h);
    if (ok) { /* VM block copies the GUID string into out512 */ }
    return ok;
}

/* --- reconstruction: volume lock/dismount/commit with progress (sub_140063C20) --- */
int CommitVolume(WCHAR drive, int flags, int mode, PVOID callback, PVOID ctx)
{
    OpenRawVolume(drive);                                   /* sub_140061930 */
    if (!flags || !callback) return LockAndDismountVol(drive, flags, mode); /* sub_140060CB0 */
    HANDLE evAbort = CreateEventW(NULL, TRUE,  FALSE, NULL);
    HANDLE evProgress = CreateEventW(NULL, FALSE, FALSE, NULL);
    struct { HANDLE evProgress; HANDLE evAbort; LPVOID shm; PVOID cb; PVOID ctx; } t =
        { evProgress, evAbort, NULL, callback, ctx };
    HANDLE hmap = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 0x1000,
                                     L"Global\\ShadowDefenderSharedMemory");
    if (hmap) { t.shm = MapViewOfFile(hmap, FILE_MAP_WRITE|FILE_MAP_READ, 0,0,0);
                if (t.shm) *(DWORD*)t.shm = 0; }
    HANDLE th = CreateThread(NULL, 0, ProgressThread, &t, 0, NULL);
    DpOpenControl();                                        /* begin */
    int rc = 0;
    rc = LockAndDismountVol(drive, flags, mode);
    if (!rc) rc = LockAndDismountVol2(drive, flags, mode);
    if (!rc) rc = LockAndDismountVol(drive, flags, mode);
    if (!rc) rc = LockAndDismountVol2(drive, flags, mode);
    DWORD err = GetLastError();  DpSessionEnd();
    if (rc) { WCHAR p[132]; wsprintf(p, L"%c:\\diskpt0.sys", drive);
              SetFileAttributesW(p, 0x80); DeleteFileW(p); }
    SetEvent(evAbort); WaitForSingleObject(th, INFINITE); CloseHandle(th);
    if (t.shm) UnmapViewOfFile(t.shm);
    if (hmap) CloseHandle(hmap);
    SetLastError(err);
    return rc;
}
```

---

## 3. Config / state

### 3.1 `res.ini` — all UI strings (OBSERVED)

Path resolution (duplicated in `sub_14000D8DC` ¶`0x14000d8dc`, `sub_14000DAF0` ¶`0x14000daf0`,
`sub_14000DDC8`, daemon `WinMain`):
```
SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path", REG_SZ, buf, &520);
if (that fails) { GetModuleFileNameW(NULL, buf, 260); *wcsrchr(buf,'\\') = 0; }
wcscat_s(buf, 260, L"\\res.ini");
```
The path is cached in the app object at `this+432` (a `CString`; emptiness tested as `*(DWORD*)(p-16)==0`).

Reader: **`GetResString(id)`** = `GetPrivateProfileStringW(L"common", "%d" % id, L"", buf, 0x1000, path)`
followed by `CString::Replace(L"\\n", L"\n")` — i.e. **every string lives in section `[common]` keyed by the
decimal ID** ¶`0x14000d8dc`. The generic form `sub_14000DAF0(app,out,section,key)` is used only for
`[translate] / authorinfo` (About page, ¶`0x1400055e8`).

Consequence: the string table can be localised by replacing `res.ini`; `[translate] authorinfo=` credits
the translator (see `samples/res.ini` line 2).

### 3.2 `user.dat` — the settings store (OBSERVED)

Path: same `HKLM\SOFTWARE\Shadow Defender\Path` fallback logic + `L"\\user.dat"`, **then remapped into the
shadow area if the containing volume is currently in shadow mode**:
```c
sub_1400620E0(path[0] /*drive letter*/, &volInfo);
if (volInfo.inShadow == 1) sub_140061CE0(path, path, &len);   /* append shadow directory */
```
¶`0x14000ddc8` (`GetUserDatPath`) and ¶`0x14000feb8` (`CommitUserDatOutOfShadow`).

Writers always follow this pattern (e.g. `sub_1400169F8` ¶`0x1400169f8`):
```
GetUserDatPath(p);
sub_140061820();                       /* driver session begin */
WritePrivateProfileStringW(section, key, value, p);
sub_140002418(p);                      /* CreateFileW(GENERIC_WRITE)+FlushFileBuffers ¶0x140002418 */
CommitUserDatOutOfShadow();            /* sub_14000FEB8: if volume in shadow, copy shadow→real
                                          (SetFileAttributesW(p,0x80); CopyFileW(shadow,real,FALSE);
                                          up to 3 retries with 100 ms sleep) */
sub_140061710();                       /* driver session end */
```

**Complete key list (OBSERVED; every `WritePrivateProfileStringW` literal in `all_pseudocode.c`):**

| Section | Key | Values / default | Written by | Meaning (INFERRED from res.ini IDs) |
|---|---|---|---|---|
| `common` | `hash` | 32 hex chars, default `0000…0` | `sub_140016888` (set pwd), `sub_140016FE0` | password hash (MD5 hex) |
| `common` | `hash2` | 32 chars cipher text | `sub_14000E8D4`, `sub_14001BA88` | obfuscated registration code |
| `common` | `sn` | 25-char code | `sub_14000E8D4` (clears after deriving hash2) | registration code (cleared once hash2 written) |
| `common` | `time` | decimal Unix `time_t` | `sub_14001BA88` | registration timestamp (write-only; never read back) |
| `common` | `continue` | 0/1 (default 0) | `sub_140014240` | "Enter Shadow Mode on Boot" schedule flag |
| `common` | `volume` | drive letters e.g. `CD` | `sub_140022BA0` | volumes scheduled/currently in shadow mode |
| `common` | `RAM` | MB integer (default 0) | `sub_140023DD4` | write-cache size in MB (converted `<<20` before sending to driver, ¶`0x140022ba0`) |
| `common` | `encrypt` | 0/1 (default 0) | `sub_140016BD8` | encrypt write cache |
| `common` | `hibernation` | 0/1 (default 1) | `sub_140016CC8` | allow hibernation in shadow mode |
| `common` | `autostart` | 0/1 (default 1) | `sub_1400169F8` | start with Windows |
| `common` | `trayicon` | 0/1 (default 1) | `sub_14001766C` | tray icon |
| `common` | `tip` | 0/1 (default 1) | `sub_140017574` | desktop tip |
| `common` | `shellext` | 0/1/**2** (default 1) | `sub_140016FE0`, `sub_140017404`, `sub_140016AE4` | shell context menu; **2 = ask password when committing** (res 50008) |
| `common` | `checkupdate` | 0/1 (default 1) | `sub_140017764` | automatic update check |
| `space` | `disable` | 0/1 (default 0) | `sub_140016E48` | disable low-space notification |
| `space` | `default` | MB integer | `sub_14001ABE4` | default low-space threshold |
| `space` | `<letter>` | MB integer | `sub_14001ABE4` (from list ctrl) | per-volume threshold |

Defaults are read with `GetPrivateProfileIntW(section,key,default,path)` — e.g. `sub_140017D38` ¶`0x140017d38`:
`autostart=1, trayicon=1, tip=1, shellext=1, encrypt=0, checkupdate=1, hibernation=1, [space] disable=0`.

`user.dat` is a plain INI (`samples/user.dat` confirms `[common] hash=… hash2=… sn= time=… RAM=0
continue=0 volume=CD`).

**Second `user.dat`**: the daemon uses `%APPDATA%\Shadow Defender\user.dat` with key `tippos`
(strings `\\Shadow Defender\\user.dat` @daemon `0x138d8`, `tippos` @`0x13910`) — the desktop-tip position.

### 3.3 Registry keys touched (OBSERVED)

| Key / value | Access | Where |
|---|---|---|
| `HKLM\SOFTWARE\Shadow Defender` `Path` (REG_SZ) | read | program-directory override (all binaries) |
| `HKLM\SOFTWARE\Shadow Defender` `RegURL` | read | registration URL for the purchase page (`sub_140026354` ¶`0x140026354`) |
| `HKLM\SYSTEM\CurrentControlSet\Services\diskpt` `GUID` (REG_SZ ≤512) | read (via IOCTL first) | `sub_140061A90`, `sub_140012F34`, `sub_140017D38`, `sub_14001A2CC`, `sub_140002864`, daemon |
| `HKLM\SYSTEM\CurrentControlSet\Services\diskpt` `Control` (REG_DWORD, 4 B, default `0x10000101`) | read+write | `sub_140016CC8` — **bit 0x80 = "hibernation disabled"** |
| `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}` `RegisteredOwner`/`RegisteredOrganization` | read | About page ¶`0x1400055e8` |
| `HKCR\CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (default value, 16 bytes SYSTEMTIME) | read only | **trial start timestamp** ¶`0x140002ff4` |
| `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Reliability` `LastAliveStamp` | delete | before shadowing the system volume ¶`0x1400637f0` |

### 3.4 Password handling (OBSERVED — fully recovered)

**Hash algorithm** (`sub_140002864` *HashPassword(pwd, out32)* ¶`0x140002864`):

```
GUID = (system volume in shadow) ? IOCTL-0x800030A0 result
                                 : HKLM\…\Services\diskpt\GUID
wide = GUID + password                       /* wide string concatenation, wcscat_s */
MD5Init(&ctx); MD5Update(&ctx, wide, 2*wcslen(wide));   /* 2*len == UTF-16LE BYTE count */
MD5Final(&ctx, d);
out32 = sprintf("%02x%02x…%02x", d[0..15]);              /* lowercase hex, 32 chars */
```

Notes / evidence:
* UTF-16LE byte count is explicit: `sub_140001DF8(ctx, buf, 2 * v3)` with `v3 = wcslen(...)`
  ¶`0x140002864`, `0x140017d38`, `0x140012f34`, `0x14001a2cc`, `0x140080651`.
* MD5 is the standard `MD5_CTX` implementation (RTTI `.?AVMD5_CTX@@`, ctor `sub_140001370` sets
  `A=0x67452301,B=0xEFCDAB89,C=0x98BADCFE,D=0x10325476`, `sub_140001DF8` = update,
  `sub_1400014BC` = final ¶`0x140001370`, `0x140001df8`, `0x1400014bc`).
* The hex format string is the 16×`%02x` literal (e.g. ¶`0x140012f34`).

**Empty-password sentinel `@BLANKPWD`** — `sub_140012F34` ¶`0x140012f34` (the "password is blank" path):
```
String2 = ReadPasswordHash();                 /* user.dat [common] hash */
Buffer  = GUID();
wcscat_s(Buffer, 0x100, L"@BLANKPWD");
d = MD5(Buffer, 2*len);  hex(d) -> Buffer;
if (wcscmp(Buffer, String2) != 0) { if (g_app->field_376 == 0) PostQuitMessage(0); }
```
So "password not set" is represented as `hash == MD5(GUID + "@BLANKPWD")`, and the Administration page
detects it (`sub_140017D38` compares and, when equal, shows res **0xC356 = 50006** "Your password is empty,
please set a new password." and unchecks "Enable password control" / disables "Set New Password").

**Password check (login dialog)** — `sub_14001A2CC` ¶`0x14001a2cc`:
```
String2 = ReadPasswordHash();  Buffer = GUID();
wcscat_s(Buffer, 0x100, pwdEditText /* this+0x148 */);
hex(MD5(Buffer, 2*len)) -> Buffer;
if (wcscmp(Buffer, String2) != 0) → retry (counter this+0x150, max 3, Sleep(500),
                                      AfxMessageBox(res 0x3EB = 1003 "Invalid password.")),
                                      after 3 tries CDialog::OnCancel();
else { g_app->field_376 = 1;   /* authenticated */  call vtable[768] (OnOK) }
```
If the GUID cannot be read at all (driver absent), res **0x3EB = 1003** is shown and the dialog is cancelled.

**Password change** — `sub_140016888` ¶`0x140016888`: `DoModal(CSetPwdDlg)` → on OK
`HashPassword(newPwd, String)` → `WritePrivateProfileStringW(L"common", L"hash", String, user.dat)` →
flush → `CommitUserDatOutOfShadow()` → success message res **0xC357 = 50007**
(and it hides `this+320`, the "password is empty" hint window, when the new password is non-empty).

### 3.5 Registration / serial / trial (OBSERVED, fully recovered)

**Verification primitive** `sub_140002FF4` = *VerifySerial(code25, key, &daysLeft)* ¶`0x140002ff4`:

```c
wcsncpy_s(w, 32, code, 25); w[25] = 0; wcsupr_s(w, 32);      /* exactly 25 chars, uppercased */
if (wcslen(w) != 25) return 0;
WideCharToMultiByte(0, 0x200, w,  -1, mb,   32, NULL, NULL);   /* ANSI(code)  */
WideCharToMultiByte(0, 0x200, key,-1, key2, 32, NULL, NULL);   /* ANSI(key)   */
strcat_s(mb, 0x20, key2);                                      /* code + key  */
MD5Init(&ctx);
len = strlen(mb);
MD5Update(&ctx, mb + 16, len - 16);        /* *** hash starts at offset 16 *** */
MD5Final(&ctx, digest);
valid = 1;
for (i = 0; i < 16; ++i)
    if (base31(digest[i]) != w[i]) { valid = 0; break; }       /* compare first 16 chars */
if (valid) return 1;
/* else compute days left (below) and return 0 */
```

`base31(byte)` = `sub_14000328C` ¶`0x14000328c`: `byte % 31` mapped to the alphabet
**`ABCDEFGHJKLMNPQRSTUVWXYZ23456789`** (A–Z minus I, L, O, then digits 2–9; index→char observed literally:
0→'A' … 22→'Z', 23→'2' … 30→'9', default '3').

**Trial counter** (same function, when `arg3 != NULL`) ¶`0x140002ff4`:
```c
SHGetValueW(HKEY_CLASSES_ROOT, L"CLSID\\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}",
            L"" /*default*/, &type, &SYSTEMTIME, &size16);
GetSystemTime(&now);
SystemTimeToFileTime(start,&ftStart); SystemTimeToFileTime(now,&ftNow);
secs = (ftNow - ftStart) / 10 000 000;
if (secs < 0x278D00 /*2 592 000 s = 30 days*/)
    *daysLeft = 30 - (secs / 0x15180 /*86 400*/);
```
⇒ **30-day trial**, start time hidden in an unrelated CLSID key. This key is only *read* by `Defender.exe`
(no writer in this binary — INFERRED: written by the installer / `Service.exe`).

**Serial storage: substitution cipher** `hash2 ⇄ sn`

*Encrypt* `sub_14000FD28` ¶`0x14000fd28` (serial → hash2):
```c
key = *(int16[7]*)(&xmmword_140089180);      /* {3,7,8,2,0,0,0} little-endian int16 */
for (i = 0; i < len(sn); ++i) {
    v = sn[i] + key[i % 7];
    if (v > 0x7A) v = v % 0x7A + 0x20;
    out += v;
}
```
*Decrypt* `sub_14000FBDC` ¶`0x14000fbdc` (hash2 → serial):
```c
for (i = 0; i < len(hash2); ++i) {
    v = hash2[i] - key[i % 7];
    if (v < 0x20) v += 90;
    out += v;
}
```
`xmmword_140089180` raw = `03 00 00 00 07 00 00 00 08 00 00 00 02 00 00 00` (int16 key {3,7,8,2,0,0,0}).
`-` (0x2D) characters are stripped after decryption (`CString::Remove(&str, 45)` ¶`0x14000e8d4`).
The `sn` string is uppercase before encryption (`MakeUpper`).

**Registration check `IsRegistered()`** — `sub_14000E8D4` ¶`0x14000e8d4`:
```
hash2 = user.dat[common\hash2];
if (hash2 != "") code = Hash2ToSn(hash2);
else            { code = MakeUpper(user.dat[common\sn]);
                  WritePrivateProfileString("common","hash2", SnToHash2(code), path);
                  WritePrivateProfileString("common","sn", "", path);
                  CommitUserDatOutOfShadow();  }
code.Remove('-');
return VerifySerial(code, key, &daysLeft);
```
Callers pass the **version keys** `"V100"` / `"V110"`:
```
registered = IsRegistered("V100",&days) || IsRegistered("V110",&days);
```
¶`all_pseudocode.c:13275` (main window), `:29336` (`sub_140026570`, trial nag), and
`sub_14001BFC4` (`CRegisterDlg` "Get Registration Code" → `VerifySerial(src, L"V100"/L"V110", NULL)`
¶`all_pseudocode.c:21197`).

**Register dialog OK** `sub_14001BA88` ¶`0x14001ba88`:
```
code = edit control text;  t = time64(NULL);
WritePrivateProfileString(L"common", L"hash2", SnToHash2(code), path);
WritePrivateProfileString(L"common", L"time",  "%d" % t,    path);
CommitUserDatOutOfShadow();
```
Trial-nag UI = res IDs 90000 ("expired"), 90001 ("will expire in %d day(s)"), 90002 Buy, 90003 Later,
90004 Register (¶`0x140026570`). Purchase URL `http://www.shadowdefender.com/purchase.php?sid=1`
(¶`0x140026354`).

### 3.6 Driver data files used by the GUI (OBSERVED)

| File | Record | Purpose |
|---|---|---|
| `%SystemRoot%\diskpt.dat` | 1004 B: `DWORD state(=1)` + `WCHAR path[500]` | **File Exclusion List** (read `sub_140016408` ¶`0x140016408`, written `sub_14000C684` ¶`0x14000c684`, counted in the status page `sub_140021A9C`) |
| `%SystemRoot%\diskpt0.dat` | same 1004 B layout | **"Commit Now" pending list** (written `sub_14000C684`, read back `sub_14000CE40` ¶`0x14000ce40`) |
| `%SystemRoot%\diskptex.dat` | same 1004 B layout | **Registry Exclusion List** (read `sub_14001FC44` ¶`0x14001fc44`) |
| `X:\diskpt0.sys` | binary | per-volume shadow-area container: created/verified when entering shadow mode, deleted on failure/exit (`sub_14000F218`, `sub_140063C20`, `sub_140061F10`); backed up as `%s.bak` / `%s.bak.%03d` (`sub_140062B00`) |
| `%SystemRoot%\diskpt.dat.bak` etc. | – | generated by the SdSetVolumeFlag path (`%s.bak`, `%s.bak.%03d` strings in `sub_140062B00`) |
| `C:\sdtrace.log` | text | debug log written by `sub_140064030` (*SdTrace*) — every SDK error message goes here (and to `OutputDebugStringW`) |
| `\\.\DpShadow%x\` | device namespace | enumerated with `CFileFind` to find files that exist **only in the shadow** (deleted/ghost files) during commit ¶`0x14000b85c` |

The exclusion lists are held by the **driver** (the GUI reads/writes the driver's own list file and, when
the volume is in shadow mode, the same file is re-mapped into the shadow area through `sub_140061CE0`).

---

## 4. UI feature map and `res.ini`

### 4.1 Loading

* `GetResString(id)` = `sub_14000D8DC` — `[common]`, key = decimal ID, `\n` → newline, 4096-char buffer.
* `GetResStringEx(section,key)` = `sub_14000DAF0` (used for `[translate]authorinfo`).
* No `LoadString` usage for UI text: the dialog templates are compiled in, all captions are patched at
  runtime with `CWnd::SetWindowText` (`sub_140032D38`) after `GetResString`.

### 4.2 res.ini ID groups (from `samples/res.ini`, cross-checked against code)

| Group | Purpose | Evidence |
|---|---|---|
| `0` | window caption | ¶`0x14001201c` |
| `10–16` | tab captions, in the order used by the bitmap tab: 10 System Status, 11 Mode Setting, 12 File Exclusion List, 16 Registry Exclusion List, 13 Commit Now, 14 Administration, 15 About | ¶`0x14001201c` (IDs 10,11,12,16,13,14,15) |
| `20–22` | menu "&Register", status bar "For help, press F1", "A new version is avaible." | ¶`0x14001201c`, `sub_140018740` |
| `30–34` | tray popup menu: 30 "&Open Shadow Defender", 31 "&Show Desktop Tip", 32 "Hide Tray &Icon", 33 "&Help", 34 "&Exit All Shadow Modes" | daemon `sub_1400014F0` (`sub_140002140(30..34,…)`) |
| `100–101` | "Shadow Mode"/"Normal Mode" status words | ¶`0x140020a84`, `0x140025664` |
| `200` | generic "Hint" dialog title | every `CFileDialog` (`CFileDialog(…,"sdl",…)`) |
| `1000–1023` | **commit engine + shared progress strings**: 1000 privilege error, 1002 finished, 1003 invalid password, 1005 wait, 1006/1007/1008 commit errors, 1009 "%d percent completed", 1011 file filter, 1012 select a volume, 1014/1015 shell-menu caption/description, 1016 low-space balloon, 1017/1018 "…is/are in Shadow Mode.", 1020/1021 list-file dialogs, 1022/1023 commit started/finished | ¶`0x14000b85c`, `0x14000fa78`, `sub_140022ba0`, daemon |
| `10000–10012` | System Status page: volume/write-cache capacity, used, free, actual free, used by SD, cache total/used, "Path"/exclusion count | ¶`0x1400212fc`, `0x140020a84`, `0x140021a9c` |
| `20000–20020` | Mode Setting page: table headers, Enter/Exit/Exit-All buttons + tooltips, Schedule, RAM-cache label + warning | ¶`0x140023fbc`, `0x1400260b8`, `0x1400254d4` |
| `30000–30013` | File Exclusion List page (35 strings incl. Save/Load `.sdl`) | ¶`0x140015de8` |
| `40000–40010` | Commit Now page (documentation only here: the code uses the same 1002/1011/1019/1020/1021 + `.sdrl` filter) | ¶`0x14001e614` |
| `50000–50015` | Administration page (tray/tip/shell/password/low-space/autostart/encrypt/update/hibernation) | ¶`0x140017854`, `0x140017d38` |
| `60000–60009` | Registry Exclusion List page | ¶`0x14001f734` |
| `70000–70003` | Login dialog (password prompt) | ¶`0x14001a958` |
| `80000–80004` | Set Password dialog | ¶`0x140020314` |
| `90000–90004` | trial expired / expires in %d days / Buy / Later / Register | ¶`0x140026570` |
| `100000–100004` | Register dialog (code entry + "Get Registration Code") | ¶`0x14001bc90` |
| `110000–110009` | About page (copyright, system information, online link, warning) | ¶`0x1400055e8` |
| `120000–120006` | Enter Shadow Mode dialog (+ "Exit Shadow Mode on Shutdown", "Enter Shadow Mode on Boot") | ¶`0x14001430c` |
| `130000–130009` | Exit Shadow Mode dialog (discard/commit all, force dismount) | ¶`0x14001481c`, `0x1400146dc` |
| `140000–140008` | reboot/shutdown prompt | ¶`0x140020624` |
| `150000–150008` | "Commit now" confirmation / option dialog (`CCommitOptionDlg`: commit deleted files, do not recurse, pause/resume) | strings present; handler `sub_14000b85c` (flags) — dialog init not in the exported set |
| `160000–160007` | Threshold Space Setting dialog | ¶`0x14001aef8` |
| `170000–170005` | verification-code prompt | strings only (used by the register flow) |
| `180000–180003` | Select a registry item dialog | ¶`0x14001c5b4` |

### 4.3 Administration page control map (OBSERVED ¶`0x140017d38`, `0x140017404`, `0x140016cc8`, …)

| Control ID | Setting key | Handler |
|---|---|---|
| 1118 | `autostart` | `sub_1400169F8` |
| 1075 | `trayicon` | `sub_14001766C` |
| 1032 | `tip` | `sub_140017574` |
| 1028 | `shellext` (on/off) | `sub_140017404` |
| 1101 | `shellext==2` (need password) | `sub_140017404` (enabled only when 1028 and 1025 are checked) |
| 1025 | `hash != blank` (password control) | `sub_140017D38`, `sub_140016FE0` |
| 1035 | "Set New Password" button | `sub_140016888` |
| 1099 | `[space] disable` | `sub_140016E48` |
| 1107 | "More Details" (threshold dialog) | `sub_14001AEF8` |
| 1033 | `encrypt` | `sub_140016BD8` |
| 1034 | `checkupdate` | `sub_140017764` |
| 1036 | `hibernation` | `sub_140016CC8` (also writes the driver `Control` bit) |
| 1120 | `RAM` (MB) | `sub_140023DD4` |

Volume page: list `1004`, mode combo/buttons `1114`, etc. (¶`0x140023fbc`, `0x140022ba0`).
Status page: drive combo `1097`, fields `1081,1083,1085,1087,1089,1091,1094,1096`, pie chart `C2DPieGraph`
at `this+71*8` (¶`0x140020a84`).

---

## 5. Core operations

### 5.1 Enter shadow mode (OBSERVED at `sub_140022BA0` → `sub_14000F218`)

1. `CVolumePage::OnApply` (`sub_140022BA0` ¶`0x140022ba0`):
   * count checked rows in list `1004`; if 0 → res 1012 "You must select at least one volume."
   * `DoModal(CEnterDlg)` (`sub_140014150`); the dialog persists
     "Enter Shadow Mode on Boot" in `common\continue`.
   * busy-test each selected volume: `CreateFileW(L"\\\\.\\X:", GENERIC_RW)` +
     `DeviceIoControl(FSCTL_LOCK_VOLUME 0x90018)` + `DeviceIoControl(FSCTL_DISMOUNT_VOLUME 0x9001C)`
     (¶`0x140022d59`, `0x140022d91`); on failure → res 20016 + `MB_RETRYCANCEL`.
   * build the drive mask string, `WritePrivateProfileStringW(L"common", L"volume", mask, user.dat)`,
     `CommitUserDatOutOfShadow()`.
   * `ramBytes = GetPrivateProfileIntW(L"common", L"RAM", 0, path) << 20; sub_140062690(&ramBytes);`
     → **RAM write-cache size passed to the driver** (obfuscated wrapper).
   * `enc = GetPrivateProfileIntW(L"common", L"encrypt", 0, path)` → stored in the thread params.
   * `params = new 0x18 { pBusyDlg=&v51, mode=1, driveMask, flagFromDialog, enc==1 }`
     (¶`0x140022ba0`: `v25[2]=1; v25[4]=v54; v25[5]=PrivateProfileIntW==1; v25[3]|=1<<(letter-'C')`).
   * `h = CreateThread(..., sub_14000F218, params, CREATE_SUSPENDED(4), ...)`;
     `sub_1400627D0(h)` — **hands the thread handle to the driver** (driver can post to it);
     `ResumeThread`; `DoModal(CBusyDlg)` with res 1005 "Please wait ..."; after completion
     message res 1002 "Operation finished."
2. Worker `sub_14000F218` mode **1** ¶`0x14000f218`:
   * `SetThreadPriority(GetCurrentThread(), 15)`; `DpSessionBegin()` (`sub_140061820`).
   * `sub_140063EF0()` — driver-side prepare IOCTL.
   * if `sub_14000E714()` (user.dat `hibernation` == 1) → `sub_1400065FC()` = *EnsureHibernateEnabled()*
     (¶`0x1400065fc`): WMI/BCD call chain `CoInitialize` →
     `sub_140006244` (`IWbemLocator::ConnectServer(L"\\.\root\wmi")`) → `sub_140005DCC`
     (`GetObject("BcdStore")`) → `sub_140005FFC` (`ExecMethod("OpenObject", "{9dea862c-5cdd-4e70-acc1-f32b344d4795}")`)
     → `sub_1400063A0` (`ExecMethod(…, 0x26000005, 1)`) — i.e. it sets the BCD element
     **`0x26000005` (`HibernateEnabled`) to 1**. (Strings `BcdStore`, `BcdObject`, `OpenStore`,
     `OpenObject`, `\\.\root\wmi`, `{9dea862c-5cdd-4e70-acc1-f32b344d4795}` ¶`0x140005dcc`,
     `0x140005ffc`, `0x1400063a0`, `0x1400065fc`.) So the option means: when hibernation is allowed,
     make sure Windows hibernation is switched **on** before shadowing starts; the *blocking* of
     hibernation while in shadow mode is done by the driver through the `Control` bit (see §5.8).
   * per selected drive (mask in `params[3]`):
     `sub_140062A80(drive, flags)` — set volume shadow flag in the driver, where
     `flags = (exitOnShutdown ? 0x102 : 0x2) [| 1]` (`lpThreadParameter[5] != 0 ? 258 : 2`, `| 1` when
     `params[4]==1`) ¶`0x14000f218`;
     `sub_140002470(drive)` flush; `sub_1400637F0(drive)` = the `0x98144` prepare FSCTL + registry flush;
     on failure delete `<drive>:\diskpt0.sys`.
   * **system volume special case** (if the Windows volume was selected): find a free drive letter
     (scan down from `Z`), `SetVolumeMountPointW(L"X:\\", VolumeName)`, then
     `CreateProcessW(NULL, L"mountvol X: /s", …, CREATE_NEW_CONSOLE|hide)` and, at the end,
     `mountvol X: /d` + `DeleteVolumeMountPointW` ¶`0x14000f218`.
   * on completion `SetThreadPriority(...,0)`, `SetEvent(params[0])`, `DpSessionEnd()`.

### 5.2 Exit shadow mode (discard / commit)

* `CExitDlg` (`sub_14001481C`, res 130000-130009) offers *"Discard all changes except Exclusion List
  (recommended)"* / *"Commit all changes"* / *"Force dismount volume"*.
* Worker `sub_14000F218` mode **2** (¶`0x14000f218`):
  * if the "discard" flag (`params[4]`) is 0 → `sub_140063C20(drive, 0, params[5], NULL, NULL)`
    (drive released with **no** commit callback);
  * else `sub_140063C20(drive, 4, params[5], sub_14000FA78 /*progress*/, &ctx)` → commit with progress;
  * on success delete `X:\diskpt0.sys`, `SHChangeNotify(SHCNE_ASSOCCHANGED)` once if any volume succeeded.
* Worker mode **3** = "only update flags" (used for the deferred/"exit on shutdown" cases and for
  `sub_140023214/sub_1400236BC` when the volume is busy): per drive `sub_140062A80(drive, params[4])`.
* Handlers: `sub_140023214` (single/all) and `sub_1400236BC` (all) construct the same 0x18-byte parameter
  block with mode 2 or 3 and `CBusyDlg` (res 1005/1002). `sub_14002482C`/`sub_140024E0C` are the
  single-drive exit helpers (they call `sub_14000251C` = the `0x560000` size query, `sub_140062A80`,
  `mountvol`).
* If a volume cannot be exited, `CShutdownDlg` (`sub_140020624`, res 140001-140008) offers
  "Exit Shadow Mode and reboot now / shutdown now / later" (reboot/shutdown is delegated to
  `ExitWindowsEx`/`InitiateSystemShutdown` via the SDK — not visible in the exported bodies).

### 5.3 Commit

* **Commit Now page**: the user builds a list; "Apply" writes it to `%SystemRoot%\diskpt0.dat`
  (`sub_14000C684`) which the driver consumes; progress/reporting uses the shared-memory channel
  (§2.4) and res 1006/1009/1022/1023.
* **Commit engine** `sub_14000B85C` (recursive, ¶`0x14000b85c`):
  * for a file: compute its shadow path `sub_140061CE0(path, out, &len)`, copy shadow→real
    (with `SetFileAttributesW(p,FILE_ATTRIBUTE_NORMAL)`), on error report res 1007/1008;
  * for a folder: `CFileFind` recursion; option "recurse into sub-folders" from `CCommitOptionDlg`
    (`a1[6] != 0`);
  * **deleted files**: enumerate `\\.\DpShadow<id>\` (`sprintf(L"\\\\.\\%s%x\\", "DpShadow", id)`,
    ¶`0x14000b85c`) to find files that exist only in the shadow overlay and delete them from the shadow
    (i.e. "commit the deletion"); the option is res 150002 "Commit deleted files" /
    150006 "Commit deleted files ONLY";
  * helper `sub_140002218` performs the real copy and back-up naming `%s.bak` / `%s.bak.%03d`
    (¶`0x140002218`, strings).
* Entry points for commit-by-path (used by CmdTool/Commit.exe style callers): the thread proc
  `StartAddress` @`0x14000c294` (¶`0x14000c294`) normalises a `CStringArray` of paths
  (`TrimLeft/TrimRight`, wildcard `*` handling, `sub_140009AE4` to strip the file name) and calls
  `sub_14000B85C`. It also uses `sub_140002600`/`sub_140002668` to sum directory sizes
  (¶`0x140002600`, `0x140002668`) and `sub_140002E80`/`sub_140002218` for the copy.

### 5.4 Exclusion lists

* **File**: list control `1005` on `CFilePage`. Load: read `%SystemRoot%\diskpt.dat`, keep records whose
  `DWORD state == 1`, skip `":*"`/`"*"` wildcard entries, `InsertItem` (¶`0x140016408`). Save/Apply:
  allocate `1004*count`, set `state=1`, `wcscpy_s(&rec[1], 500, path)`, `CFile::Open(path,
  typeBinary|modeCreate|modeWrite)`, `Write`, `SetLength(1004*count)`; empty list → `DeleteFileW`
  (¶`0x14000c684`). While any volume is in shadow mode the Apply button (`1049`) is disabled
  (res 30012, ¶`0x140016408`).
* **Registry**: list `1005` on `CRegistryPage`, `%SystemRoot%\diskptex.dat`, same 1004-byte records
  (¶`0x14001fc44`). Items are picked with `CRegistryDlg` which browses the raw hive paths
  `\REGISTRY\MACHINE\SAM|SECURITY|SOFTWARE|SYSTEM`, `\REGISTRY\USER\%SID%` and uses the literal
  **`@DUMMY`** as a placeholder for the per-user hive (¶`0x14001c1cc`, `sub_14000D798` builds the SID string
  via `ConvertSidToStringSidW` ¶`0x14000d798`).
* "Apply" for exclusions ends with `sub_1400636E0()` — **push settings into the driver** — plus
  `CommitUserDatOutOfShadow` (¶`0x14001abe4` pattern for the low-space list; ¶`0x140016408` for files).

### 5.5 Schedule on boot (OBSERVED)

* `common\continue` (0/1) = "Enter Shadow Mode on Boot" (¶`0x140014240` writes it; `sub_14001430C`
  restores the checkbox state; handler `sub_140023BE0` for the volume page "Schedule" button).
* `common\volume` = drive letters to be put into shadow mode (¶`0x140022ba0`,
  read back at ¶`0x140024...` line 28942).
* At boot the **driver** (loaded with the `diskpt` service) instantiate the shadow volumes from the flag
  stored on each volume (`X:\diskpt0.sys` present ⇒ shadow), which is why `sub_14000F218` writes/deletes
  that file. `Service.exe`/daemon re-apply `volume`/`continue` — the daemon reads `autostart` for `/Auto`
  (¶daemon WinMain).

### 5.6 RAM write cache (OBSERVED)

* Setting: `common\RAM` = **megabytes** (`sub_140023DD4` ¶`0x140023dd4` parses the edit box text at
  control 1120, strips non-digits).
* Applied: `ramBytes = value << 20` and passed to the obfuscated API (`sub_140062690(&ramBytes)`) right
  before entering shadow mode (¶`0x140022ba0`).
* Reported: status page shows "Write cache information: Total/Used"
  (`sub_140062540(&used,&total)` ¶`0x140020a84`) — values come from the driver.
* Resource strings: 20019 "RAM used as Write Cache:" and 20020 the warning.

### 5.7 Write-cache encryption (OBSERVED)

* Setting `common\encrypt` 0/1 (¶`0x140016bd8`), passed to the driver as thread-param flag
  `encrypt==1` (¶`0x140022ba0`) and used by `sub_140022BA0`/`sub_140062B00`.
* `Defender.exe` also contains a **full RC4 implementation**:
  `sub_1400615E0` = KSA over a 256-entry state ¶`0x1400615e0`
  (array initialised 0..255 with SSE, then the classic `j = (j + S[i] + key[i % keylen]) & 0xFF` swap loop),
  and `sub_140060320` = PRGA ¶`0x140060320`:
  ```c
  i = ++i & 0xFF; j = (j + S[i]) & 0xFF; swap(S[i],S[j]); data[k] ^= S[(S[i]+S[j]) & 0xFF];
  ```
  INFERRED: same-algorithm key stream used to encrypt the shadow-overlay cache (or the key exchange with
  the driver). The key material itself is supplied by the caller in the `.reloc` VM blocks → UNKNOWN.
* UI: res 50013 "&Encrypt write cache".

### 5.8 Hibernation control (OBSERVED)

* Checkbox 1036 → `sub_140016CC8` ¶`0x140016cc8`:
  ```c
  DWORD ctl; SHGetValueW(HKLM, L"SYSTEM\\CurrentControlSet\\Services\\diskpt", L"Control",
                         &type, &ctl /*default 0x10000101*/, &4);
  if (checkbox == 1) ctl &= ~0x80;   else ctl |= 0x80;
  SHSetValueW(HKLM, …, L"Control", REG_DWORD, &ctl, 4);
  WritePrivateProfileStringW(L"common", L"hibernation", "1"/"0", user.dat);  flush; commit;
  ```
  ⇒ **bit 0x80 of the diskpt service `Control` value = "hibernation forbidden"** (driver-side enforcement).
* When `hibernation == 1` the enter-shadow worker additionally ensures Windows hibernation is switched
  **on** through WMI/BCD (`sub_1400065FC` sets BCD element `0x26000005` `HibernateEnabled`=1 inside the
  `\\.\root\wmi` `BcdStore`/`BcdObject` code ¶`0x1400065fc`, `0x140005dcc`…); i.e. the option is
  "hibernation is allowed in Shadow Mode", and the *forbidding* of hibernation is enforced by the driver
  through the `Control` bit 0x80 (see above).
* The checkbox is greyed out when the Windows volume is already in shadow mode (¶`0x140017d38`).

### 5.9 Low-space notifications (OBSERVED)

* Thresholds live in `user.dat` `[space]` — `default` (MB) and per-volume `<letter>` (MB)
  (`CLowSpaceDlg` = `sub_14001AEF8` ¶`0x14001aef8`, list control on the dialog, `sub_14001ABE4`
  ¶`0x14001abe4` writes them and pushes them to the driver with `sub_1400636E0`).
* The **daemon** reads them (`sub_140002240(drive)`), pushes each volume's threshold to the driver
  (`sub_1400058F0(drive, MB<<20)`) and polls every 30 s; when free space < threshold it shows a balloon
  with res 1016 `"%s is in low free space, exit Shadow Mode now please."` (daemon `sub_1400014F0` timer,
  ¶daemon `0x1400014f0`; `sub_140002140(1016,…)` + `sub_1400026C0` = Shell_NotifyIcon balloon).
* UI: res 50009 "Notify me with low free space…", 50010 "More Details", 50011 warning,
  160000-160007 threshold dialog.

### 5.10 Auto-update (OBSERVED)

* `sub_140010E30` ¶`0x140010e30` (*CheckForUpdate*):
  * version from the exe's `VS_FIXEDFILEINFO` (`sub_14000DCB8` ¶`0x14000dcb8`, `"%d.%d.%d.%d"`);
  * read `common\hash2` (decrypt to the serial) or `common\sn`;
  * compute an MD5 hex (of serial/extra data — the same 16-`%02x` formatter);
  * build query `version=<ver>&extra=<hex>`;
  * `sub_1400131A4(host="www.shadowdefender.com",
                   url="checkupdate-3011ca199c614b0c96a84f435046c4c5.php", …)`.
* `sub_1400131A4` ¶`0x1400131a4` = MFC WININET POST helper: `CInternetSession::GetHttpConnection`,
  headers `"Content-Type: application/x-www-form-urlencoded\r\nAccept-Language:en-us"` (+ optional
  `"\r\nReferer:"`), `CHttpFile::QueryInfoStatusCode`, then reads the response body line by line
  (1023-char lines).
* Result handling: res 22 `"A new version is avaible."` is shown by the main window
  (¶`sub_140018740`, `sub_14001201c`); the same HTTP helper is used for "Get Registration Code".
* Setting `common\checkupdate` (default 1).

---

## 6. Shell integration (context menu → commit)

**OBSERVED:**
* `Defender.exe`'s own involvement is limited to:
  * `sub_14000D2A8` ¶`0x14000d2a8`: `LoadLibraryW(L"ShellExt.dll")` + `GetProcAddress(..., "SetWorkMode")`
    + call with **`1`**. The string `SetWorkMode` @ `0x140088fd0`, `ShellExt.dll` @ `0x14000d2ac`.
  * the persisted tri-state `user.dat [common] shellext` = 0 (disabled) / 1 (enabled) /
    **2 = enabled + "Need password when committing files via shell context menu"** (res 50008);
    handlers `sub_140016FE0` ¶`0x140016fe0` (when the password-control checkbox changes, shellext is
    forced to `2` and written) and `sub_140017404` ¶`0x140017404` (the tri-state checkbox).
  * The same `SetWorkMode(1)` call appears in `DefenderDaemon.exe`'s `WinMain`
    (`0x140003a0a`, argument `1`).
* There is **no** `RegSetValueEx`/`SHSetValue` of a shell-ext CLSID anywhere in `Defender.exe`
  (only `diskpt\Control` is written with `SHSetValueW`, `sub_140016CC8`) ⇒ registration of the
  context-menu handler is done by `ShellExt.dll` / the installer.
* `Defender.exe` does **not** reference `Commit.exe` (raw-PE search: NOT FOUND) and contains no
  `/commit`, `/pwd:`, `/enter`, `/list` switches (only **`/exit`**, `0x140087d78`).
* Menu strings for the shell items live in res.ini IDs **1014** ("Commit by Shadow Defender") and
  **1015** ("Commit the selected files and folders to the orginal volume if the volume is in shadow
  mode.") — loaded by whichever module owns the menu (ShellExt.dll reads the same res.ini; the string is
  not referenced in `Defender.exe`).

**INFERRED:** `ShellExt.dll` exports `SetWorkMode(BOOL)` where 1 = install/refresh the Explorer context
menu (it reads `res.ini` IDs 1014/1015 and `user.dat [common] shellext`), and the menu action runs
`Commit.exe` (or `Defender.exe`-equivalent SDK code) with the selected paths — matching
`samples/CmdTool.txt`'s `/commit:FILE_OR_DIRECTORY` interface.
**UNKNOWN:** the exact command line `ShellExt.dll` builds for `Commit.exe` — ShellExt.dll/Commit.exe were
not in this task's evidence set.

---

## 7. `DefenderDaemon.exe`

**Purpose (OBSERVED):** session-level tray-icon + "desktop tip" agent and low-space watchdog; it starts
with Windows (`/Auto`), shows which volumes are in shadow mode, offers the popup menu, and can trigger
"Exit All Shadow Mode" by launching the GUI.

### 7.1 WinMain (OBSERVED ¶daemon `0x140003680`)

1. `hObject = CreateMutexW(NULL, FALSE, L"Local\\Shadow Defender Daemon Mutex")`; if
   `GetLastError()==ERROR_ALREADY_EXISTS(183)` → exit (single instance per session).
2. `OpenEventW(EVENT_MODIFY_STATE(0x1F0003), FALSE, L"Global\\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}")`;
   if it exists → `WaitForSingleObject(..., INFINITE)` (waits for the Service/commit to finish before
   doing its own work; the event is created by `Service.exe`, whose string table contains the same GUID).
3. If `wcsicmp(lpCmdLine, L"/Auto") == 0`: read `HKLM\SOFTWARE\Shadow Defender\Path` →
   `\user.dat`; **if `GetPrivateProfileIntW(L"common", L"autostart", 1, user.dat) != 1` → exit**.
   (So `/Auto` = the logon/autostart entry point.)
4. Enumerate volumes `'C'..'Z'`: `sub_140001110(drive)` (open) + `sub_140005210(drive,&info)`;
   if `info.inShadow == 1` set bit `drive-'C'` in `dword_140020C5C` (the **shadow-volume mask**).
5. `byte_140020C58 = (sub_1400023E0() == 0)` and `v10 = sub_1400024F0()` →
   flags `byte_140020C5A/59/5B` (tray-icon/tip enable states read from user.dat
   `common\trayicon` / `common\tip`; `sub_1400023E0`/`sub_1400024F0` are the getters).
6. Create the **hidden main window**: `CreateDialogParamW(hInstance, 101, NULL, sub_1400014F0, 0)`,
   caption `L"Shadow Defender Daemon Window"`, `GWL_EXSTYLE |= WS_EX_TOOLWINDOW(0x80)`,
   `MoveWindow(0,0,0,0)`, `ShowWindow(5)` then `ShowWindow(0)`.
7. If `shadowMask != 0 && !flag` → `hWnd = sub_140001330(hInstance)` (create the visible **desktop tip**
   window, class `tooltips_class32`, bitmap from `<dir>\shadow.bmp`).
8. Threads: `StartAddress` (`sub_140002C40`) = volume/state monitor, `sub_1400027A0` = notification waiter.
9. `RegisterHotKey(hiddenWnd, 0, MOD_ALT|MOD_CONTROL|MOD_SHIFT(7), VK_U(0x75))` — **Ctrl+Alt+Shift+U**
   (emergency hotkey; `UnregisterHotKey` in the window proc).
10. `LoadLibraryW(L"ShellExt.dll")` + `SetWorkMode(1)`.

### 7.2 Window proc `sub_1400014F0` (OBSERVED ¶daemon `0x1400014f0`)

* Handles `TaskbarCreated` (re-adds the tray icon — `RegisterWindowMessageW(L"TaskbarCreated")`
  registered in daemon `sub_140001000`), `WM_TIMER` id 1 every **30 000 ms** (`SetTimer(hwnd,1,0x7530)`).
* `WM_COMMAND` with menu IDs **12772–12775** (0x31E4–0x31E7):
  * 12772 "&Open Main Window" → `sub_1400025D0(0)` = `ShellExecuteW(...,"<dir>\Defender.exe", NULL, …, 5)`;
  * 12773 "&Help" → `sub_140003C1C(hwnd, "<dir>\Help.chm", 1)` (HTML-Help helper that also verifies
    `hhctrl.ocx` via `CLSID\{ADB880A6-D8FF-11CF-9377-00AA003B7A11}\InprocServer32`, daemon `sub_140003AEC`);
  * 12774 "Hide Tray &Icon" → `sub_140001DB0(hwnd, 0, NIM_DELETE(2))`;
  * 12775 "&Exit All Shadow Mode" → **`sub_1400025D0(1)` = `Defender.exe /exit`**;
  * "Show Desktop &Tip" toggles the tip (`sub_140001DB0(...,2)` / `sub_1400034C0(1)`).
* Timer body: re-enumerate volumes; if a volume is in shadow and its free space
  `< sub_140002240(drive) << 20` → balloon with res 1016; on shadow-state change
  `sub_140001DB0(hwnd, mask, NIM_ADD/MODIFY/DELETE)` and `sub_1400034C0` (`UpdateStatus`) which posts
  `0x47B` (logged as **WM_DAEMONMSG**) with `1=DM_SHOWTIP` / `2=DM_HIDETIP` to the tip window
  (debug strings `"UpdateStatus: WM_DAEMONMSG, DM_SHOWTIP"…`).
* Balloons for commit activity: `sub_140002140(1022/1023, …)` = res "Shadow Defender is committing
  changes, please wait a while…" / "Commit finished." — driven by the events from `sub_140005670` /
  `sub_1400057A0` (device + global-event notifications).
* Tray tooltip text: res **1017/1018** `"%s is in Shadow Mode."` / `"%s are in Shadow Mode."` filled with
  the shadow-volume mask (¶daemon `sub_140001db0`).
* Popup menu labels: res 30–34 as listed in §4.2; the built-in fallbacks
  `&Open Main Window`, `&Exit All Shadow Mode`, `Show Desktop &Tip`, `Hide Tray &Icon`, `&Help` also
  exist as literals (daemon `0x20cf2`–`0x20d9c`).
* ITip state: `%APPDATA%\Shadow Defender\user.dat` key `tippos` (tip coordinates),
  tip strings from res 1017/1018, tip bitmap `<dir>\shadow.bmp`.

### 7.3 Interaction summary

```
[logon] ──► DefenderDaemon.exe /Auto ──► reads user.dat(autostart, trayicon, tip, [space])
                                    ├─► waits Global\{C6F6A26F-…} (Service.exe latch)
                                    ├─► monitors volumes (sub_1400058F0 pushes thresholds to driver)
                                    ├─► tray icon + desktop tip + low-space balloon (res 1016)
                                    └─► menu "Exit All Shadow Mode" ──► Defender.exe /exit
Defender.exe ◄──launch── DefenderDaemon.exe   (sub_14000EC2C ── ShellExecuteW "open")
```
No shared memory, no messages: the two programs only share **files** (`res.ini`, `user.dat`,
`%APPDATA%\Shadow Defender\user.dat`) and the **driver**.

---

## 8. Obfuscation, anti-analysis and limitations

1. **Section mislabelling / control-flow flattening.** A 0x3e000-byte `RWX class=CODE` section named
   `.reloc` (`0x140119000-0x140157000`, ¶`segments.txt`) holds a dispatcher and ~35 encrypted basic-block
   stubs. In `.text`, 24 sites replace a normal branch with
   `jmp loc_14014E392` → stub `push <rva>; push 0x35; jmp sub_140147C33`
   (e.g. ¶`0x14006175f`, stub @`0x14014e392`; a full list is at `.text` offsets
   `0x14000e245, 0x14000e7a7, 0x1400113d2, 0x140060a45, 0x140061345, 0x14006175f, 0x14006186f,
   0x1400619b3, 0x140061b2e, 0x140061c07, 0x140061ca0, 0x140061dc1, 0x140061ee9, 0x14006207b,
   0x14006219a, 0x1400622f7, 0x140062599, 0x1400626e4, 0x140062824, 0x140062998, 0x140063331,
   0x14006372f, 0x140063b45, 0x140063f4f`). After each jump the linear byte stream resumes with junk
   (anti-disassembly filler) and then the real continuation, which is only reachable through the VM.
2. **Practical impact.** The *bodies* of the SD-API wrappers whose tail is VM'd are only partially
   recovered: `sub_1400603C0`, `sub_140060CB0`, `sub_140061540`, `sub_140061710`, `sub_140061820`,
   `sub_140061930`, `sub_140061A90`, `sub_140061BA0`, `sub_140061CE0`, `sub_140062140`,
   `sub_1400622F0`, `sub_140062540`, `sub_140062690`, `sub_1400627D0`, `sub_140062910`, `sub_140062B00`,
   `sub_1400636E0`, `sub_1400637F0`, `sub_140063AF0`, `sub_140063EF0`, `sub_14000E788`, plus tails of
   `sub_14000E1xx`, `sub_14000E7xx`, `sub_1400113D2`. What *is* recovered: device names, IOCTL codes,
   buffer sizes, call order, callers, and every string they use.
3. **Deliberately runtime-computed IOCTL numbers.** `0x800025E4 + f(serviceGUID)` defeats static IOCTL
   enumeration; see §2.2. **UNKNOWN:** `f()` (bytes of the GUID used, mixing, endianness).
4. **`sdtrace.log`** — `sub_140064030` writes formatted strings to `C:\sdtrace.log` and
   `OutputDebugStringW` (used by all SDK error paths: "Open Volume failed %d", "Lock Volume11 failed %d",
   "Dismount Volume1 failed %d", "Get Volume Information failed %d", …).
5. Exports: `exports.txt` = `?SetWorkMode` only? — for `Defender.exe` `exports.txt` is 19 bytes
   (`samples/EXPORT_ERROR.txt` shows the export script failed on the *strings* step, not exports);
   the DLL `ShellExt.dll` export `SetWorkMode` is confirmed by name strings in both binaries.
6. The `.reloc` blocks are un-analysable from these exports; `recon/unhide/` contains an *unrelated*
   recovery effort for `diskpt.sys` (image base `0x280050000`), not for `Defender.exe`.

---

## 9. Evidence index — key functions

| Address | Inferred name | Evidence highlights |
|---|---|---|
| `0x14000d12c` | `CDefenderApp::ctor` | installs vftable, CStrings @+400/+432 |
| `0x14000d2a8` | `EnableShellExt()` | `LoadLibraryW("ShellExt.dll")`, `SetWorkMode(1)` |
| `0x14000d36c` | boot flag checker | waits 5–15 s, `X:\diskpt0.sys` check, `sub_140062A80` |
| `0x14000d46c` | `DriverPresent()` | opens `\\.\C:` |
| `0x14000d538` | `/exit` parser | `CommandLineToArgvW`, sets app+384 |
| `0x14000d5b8` | `SdMessageBox()` | `MessageBoxW(..., L"Shadow Defender", ...)` |
| `0x14000d624` | `MessageFilter()` | `ChangeWindowMessageFilter(563, 1)` — 563 = `WM_COPYGLOBALDATA` |
| `0x14000d688` | `EnablePrivilege(name)` | `AdjustTokenPrivileges` |
| `0x14000d798` | `GetUserSidString()` | `GetTokenInformation(TokenUser)` + `ConvertSidToStringSidW` |
| `0x14000d8dc` | `GetResString(id)` | res.ini `[common]` `%d` |
| `0x14000daf0` | `GetResStringEx(sec,key)` | `[translate]authorinfo` |
| `0x14000dcb8` | `GetFileVersionString()` | `GetFileVersionInfoW`/`VerQueryValueW`, `%d.%d.%d.%d` |
| `0x14000ddc8` | `GetUserDatPath()` | `Path`→`\user.dat`, shadow remap via `sub_140061CE0` |
| `0x14000df2c` | `ReadPasswordHash()` | `[common]hash`, default `000…0` |
| `0x14000dfb8` | `CDefenderApp::InitInstance` | DPI, single-instance mutex, `/exit`, `help.chm` |
| `0x14000e714` | `GetHibernationSetting()` | `[common]hibernation` default 1 |
| `0x14000e8d4` | `IsRegistered(key)` | hash2/sn → `sub_140002FF4`, `Remove('-')` |
| `0x14000ebac` | `IsVistaOrLater()` | `GetVersionExW`, cached @app+440 |
| `0x14000ec2c` | `LaunchDaemon()` | `ShellExecuteW("<dir>\DefenderDaemon.exe")` |
| `0x1400065fc` | `EnsureHibernateEnabled()` | WMI `BcdStore`/`BcdObject`, element `0x26000005`=1 |
| `0x14000f218` | `ShadowModeWorker` | mountvol, FSCTL lock, `sub_140062A80/637F0/63C20` |
| `0x14000fa78` | `CommitProgressCallback` | res 1009, `SendMessage(hwnd,0x465,…)` |
| `0x14000fbdC` | `Hash2ToSn()` | −key[i%7], `+90` fixup |
| `0x14000fd28` | `SnToHash2()` | +key[i%7], `%0x7A` wrap |
| `0x14000feb8` | `CommitUserDatOutOfShadow()` | `CopyFileW(shadow,real)`, 3 retries |
| `0x140002418` | `FlushIniFile(path)` | `CreateFileW(GENERIC_WRITE)`+`FlushFileBuffers` |
| `0x140002470` | `FlushVolume(letter)` | open `\\.\X:\`, `FlushFileBuffers` |
| `0x14000251C` | `QuerySdUsage(path,&mb)` | IOCTL `0x560000`, reads dword @out+8 |
| `0x140002864` | `HashPassword(pwd,out32)` | MD5(GUID+pwd) over `2*wcslen` bytes |
| `0x140002FF4` | `VerifySerial(code,key,&days)` | base31 over MD5[16..], 30-day trial |
| `0x14000328C` | `Base31(byte)` | `%31` → `ABCDEFGHJKLMNPQRSTUVWXYZ23456789` |
| `0x14000b85c` | `CommitPath(recursive)` | `\\.\DpShadow%x\`, `\*.sdl`/`\*.sdrl` |
| `0x14000c294` | `CommitThreadProc` | trims/normalises path list |
| `0x14000c684` | `SaveCommitList()` | `%SystemRoot%\diskpt0.dat`, 1004-byte records |
| `0x14000ce40` | `LoadCommitList()` | same file |
| `0x140010e30` | `CheckForUpdate()` | version, `version=&extra=`, `checkupdate-…php` |
| `0x14001201c` | `MainWndInit` | tabs 10…16, `SetTimer(…,1000)` |
| `0x140012f34` | `CheckBlankPassword()` | `@BLANKPWD` comparison |
| `0x1400131a4` | `HttpPost(host,url,…)` | `Content-Type…`, `QueryInfoStatusCode` |
| `0x140014240` | `EnterDlg::OnOK` | writes `common\continue` |
| `0x14001430c` | `CEnterDlg::OnInitDialog` | 120000-120006, reads `continue` |
| `0x14001481c` | `CExitDlg::OnInitDialog` | 130000-130009 |
| `0x140016408` | `LoadFileExclusionList()` | `%SystemRoot%\diskpt.dat` |
| `0x140016888` | `ChangePassword()` | `HashPassword`→`[common]hash`, 50007 |
| `0x1400169f8` | `SetAutostart()` | `[common]autostart` |
| `0x140016ae4` | `SetShellExt()` | `[common]shellext` (0/1/2) |
| `0x140016bd8` | `SetEncryptCache()` | `[common]encrypt` |
| `0x140016cc8` | `SetHibernation()` | diskpt `Control` bit 0x80 + `[common]hibernation` |
| `0x140016e48` | `SetLowSpaceNotify()` | `[space]disable`, 50011 |
| `0x140016fe0` | `SetPasswordControlOn()` | 50006/50007, forces shellext=2 |
| `0x140017404` | `SetShellExtTriState()` | shellext 0/1/2 (50008) |
| `0x140017574` | `SetTip()` | `[common]tip` |
| `0x14001766c` | `SetTrayIcon()` | `[common]trayicon` |
| `0x140017764` | `SetCheckUpdate()` | `[common]checkupdate` |
| `0x140017d38` | `CGeneralPage::OnInitDialog` | all settings + blank-password test |
| `0x140018974` | `ShellOpenOrRun(path)` | `ShellExecuteW` then `HKCR\.htm\shell\open\command` |
| `0x1400188cc` | `QueryRegDefaultString(hkey,subkey,out)` | `RegOpenKeyExW`+`RegQueryValueW` (used for `HKCR\.htm`) |
| `0x140018b04` | `RegTree reader` | companion helper |
| `0x14001a2cc` | `CLoginDlg::OnOK` | MD5(GUID+pwd) compare, 3 tries, 1003 |
| `0x14001abE4` | `SaveLowSpaceList()` | `[space]` keys + `sub_1400636E0` |
| `0x14001aef8` | `CLowSpaceDlg` | 160000-160007 |
| `0x14001ba88` | `CRegisterDlg::OnOK` | `hash2`+`time`, `time64` |
| `0x14001bc90` | `CRegisterDlg::OnInitDialog` | 100000-100004 |
| `0x14001bfc4` | `GetRegistrationCode()` | `VerifySerial(src,"V100"/"V110",NULL)` |
| `0x14001c1cc` | `RegistryTreeAddItem()` | `@DUMMY`, SID, `\REGISTRY\USER\` |
| `0x14001f734` | `CRegistryPage::OnInitDialog` | 60000-60009 |
| `0x14001fc44` | `LoadRegistryExclusionList()` | `%SystemRoot%\diskptex.dat` |
| `0x140020624` | `CShutdownDlg::OnInitDialog` | 140001-140008 |
| `0x140020a84` | `CStatusPage::Refresh()` | disk free, `sub_1400620E0`, `sub_140062540`, pie |
| `0x1400212fc` | `CStatusPage::OnInitDialog` | 10000-10012 |
| `0x140021a9c` | `StatusExclusionCount()` | reads `diskpt.dat` |
| `0x140022ba0` | `CVolumePage::OnApply` | FSCTL busy test, `[common]volume`, worker mode 1 |
| `0x140023214` | `DoExitShadow()` | worker mode 2/3 |
| `0x1400236bc` | `DoExitAll()` | worker mode 2/3 |
| `0x140023be0` | `VolumePageSchedule()` | list `1004`/button `1114` |
| `0x140023dd4` | `SetRamCache()` | `[common]RAM` |
| `0x140023fbc` | `CVolumePage::OnInitDialog` | 20000-20020 |
| `0x14002482c`,`0x140024e0c` | `ExitOneVolume(immediate)` | `mountvol`, `diskpt0.sys` delete |
| `0x1400254d4` | RAM-cache tooltip | res 20020 |
| `0x140025664` | `VolumeModeText()` | res 100/101 |
| `0x1400260b8` | volume page tooltips | 20012-20018 |
| `0x140026354` | `OpenPurchasePage()` | res `RegURL` / `purchase.php?sid=1` |
| `0x140026570` | `TrialPrompt()` | 90000-90004, `IsRegistered` |
| `0x1400602c0` | `SdFormatMessage(fmt,…)` | SDK printf wrapper |
| `0x140060320` | `RC4_Apply(state,buf,len)` | PRGA |
| `0x1400615e0` | `RC4_Init(state,key,len)` | KSA |
| `0x1400603c0`/`0x140060cb0` | `LockDismountVolume()` | FSCTL 0x90018/0x9001C/0x90020, `\\.\DpShadow%x` |
| `0x140061540` | `ProgressMonitorThread` | 2 events + shared memory + callback |
| `0x140061710`/`0x140061820` | `DpSessionEnd`/`DpSessionBegin` | IOCTL `0x800025E4+K`, 0x88-byte block |
| `0x140061a90` | `ComputeIoctlBase()` | reads diskpt `GUID` → `dword_1400C9DB0` |
| `0x140061ba0` | `QueryDriverGuid(buf512)` | IOCTL `0x800030A0`, 0x88-byte block |
| `0x140061ce0` | `GetShadowPath(path,out,len)` | allocates `len+32` WCHARs, shadow directory |
| `0x140061f10` | `ReadVolumeFlag(letter,&flags)` | reads `X:\diskpt0.sys` header |
| `0x1400620e0`/`0x140062140` | `GetVolumeInfo(letter,&info)` | `info[0]`=shadow id, `info[1]`=inShadow, `info[2]`=used bytes |
| `0x1400622f0` | `SdInit()` | SDK init |
| `0x140062540` | `GetWriteCacheUsage(&used,&total)` | status page numbers |
| `0x140062690` | `SetRamCacheBytes(&bytes)` | called with `RAM<<20` |
| `0x1400627d0` | `SetWorkerThread(hThread)` | after `CreateThread(CREATE_SUSPENDED)` |
| `0x140062910` | `OpenVolumeRead(letter)` | `\\.\X:` |
| `0x140062a80` | `SetVolumeFlag(letter,flags)` | flags 2/3/0x102/0x103 |
| `0x140062b00` | `SdSetVolumeFlag()` | `%s.bak`, `X:\diskpt0.sys`, geometry checks |
| `0x1400636e0` | `PushSettingsToDriver()` | IOCTL (no explicit block init) |
| `0x1400637f0` | `PrepareVolume(letter)` | FSCTL `0x98144` + registry flush |
| `0x140063c20` | `CommitVolumeWithProgress()` | shared memory + attempts CB0/3C0 |
| `0x140063ef0` | `DriverPrepareShadow()` | IOCTL, 0x88 zeroed |
| `0x140064030` | `SdTrace(fmt,…)` | `OutputDebugStringW` + `C:\sdtrace.log` |
| daemon `0x140003680` | `WinMain` | `/Auto`, mutex, global event, hotkey, tray |
| daemon `0x1400014f0` | `DaemonWndProc` | tray, timer 30000 ms, menu 12772-12775 |
| daemon `0x140002e30` | `TipDialogProc` | res 1017/1018, tip window |
| daemon `0x140002c40` | `VolumeMonitorThread` | thresholds `[space]` → `sub_1400058F0` |
| daemon `0x140001db0` | `TrayNotify(action)` | `Shell_NotifyIconW` add/modify/delete |
| daemon `0x1400025d0` | `LaunchDefender(exitFlag)` | `ShellExecuteW("<dir>\Defender.exe", "/exit"?)` |
| daemon `0x1400034c0` | `UpdateStatus(refresh)` | posts `0x47B` (WM_DAEMONMSG) / DM_SHOWTIP/HIDETIP |
| daemon `0x140001000` | `RegisterTaskbarCreated()` | `RegisterWindowMessageW(L"TaskbarCreated")` |

---

## 10. Answers to the specific questions posed

1. **Program structure** — MFC `AfxWinMain` (`WinMain_0 @0x14007f8c0`) → `CDefenderApp::InitInstance`
   (`sub_14000DFB8`) → `CDefenderDlg` as a `#32770` dialog with a custom `CBitmapTab` + 7 `CChildPage`
   pages; ~25 `CDialog` subclasses (table in §1.4); no `wWinMain`, no exported symbol other than through
   ShellExt.dll's `SetWorkMode`.
2. **IPC** — direct `DeviceIoControl` on `\\.\DpControl` (IOCTLs `0x800030A0` and `0x800025E4+K`),
   `\\.\DpShadow<hex>`, raw volume FSCTLs `0x90018/0x9001C/0x90020/0x98144`, the private volume IOCTL
   `0x560000`, a named shared-memory channel `Global\ShadowDefenderSharedMemory` (progress %) and a
   user-supplied event, plus file-based config. **No pipes, no `WM_COPYDATA`.** Daemon↔GUI = process
   launch with `/exit`; Daemon/Service latch = `Global\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}`.
3. **Config** — `res.ini` (all UI text, `[common]` + decimal IDs, `[translate]`) and `user.dat`
   (`[common] hash/hash2/sn/time/continue/volume/RAM/encrypt/hibernation/autostart/trayicon/tip/shellext/
   checkupdate`, `[space] disable/default/<letter>`), both relocated next to the exe or per
   `HKLM\SOFTWARE\Shadow Defender\Path`, and *transparently redirected into the shadow overlay* while the
   volume is in shadow mode. Registry: `diskpt\GUID` (IOCTL key), `diskpt\Control` bit 0x80 (hibernation),
   `Uninstall\{93A07A0D-…}` owner/org, `HKCR\CLSID\{78C3F4BC-…}` trial timestamp, `Reliability\LastAliveStamp`
   (deleted). Password = `MD5(UTF-16LE(serviceGUID + password))`; blank = `MD5(GUID+"@BLANKPWD")`.
   Registration = 25-char code, `base31(MD5(ANSI(code)+"V100"/"V110")[16..])[0..15] == code[0..15]`,
   stored obfuscated in `hash2` with a 7-element additive cipher; 30-day trial.
4. **UI map** — §4.2/§4.3 (res.ini groups by dialog).
5. **Core operations** — §5 (enter/exit/commit/exclusions/schedule/RAM/encryption/hibernation/
   low-space/update), each with the observed call sequence.
6. **Shell integration** — Defender.exe only calls `ShellExt.dll!SetWorkMode(1)` and stores the tri-state
   `shellext` (0/1/2) in user.dat; registration of the menu and the `Commit.exe` invocation are outside
   this binary (UNKNOWN details; §6).
7. **Daemon** — §7: `/Auto` logon agent, single instance (`Local\Shadow Defender Daemon Mutex`), waits on
   the Service's global event, creates a hidden `#32770` window + tray icon + `tooltips_class32` desktop
   tip (`shadow.bmp`, position in `%APPDATA%\Shadow Defender\user.dat:tippos`), 30 s polling of volumes and
   low-space thresholds (res 1016 balloon), menu (res 30-34) with "Exit All Shadow Mode" →
   `Defender.exe /exit`, hotkey Ctrl+Alt+Shift+U, `SetWorkMode(1)`.

### Highest-value reconstruction targets still open
* the exact 0x88-byte control-block layout for IOCTLs `0x800030A0` / `0x800025E4+K` (in `.reloc` VM);
* `f(GUID) → K` (IOCTL base obfuscation);
* the RC4 key material for write-cache encryption and whether the driver or the GUI performs the
  encryption;
* the shadow-directory name appended by `GetShadowPath` (`+32 WCHAR` → 32-char name; not present as a
  literal in `Defender.exe` — likely `{0D9DB60E-B0EA-4d53-A392-A5D274956846}` truncated/derived at runtime);
* ShellExt.dll → Commit.exe command line and `diskpt.sys`-side verification of the same items.
