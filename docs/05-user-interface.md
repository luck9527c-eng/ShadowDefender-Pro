# Shadow Defender — GUI Structure and the `res.ini` Map

> Scope: the process/thread structure of `Defender.exe`, its window and page inventory,
> and the complete mapping from `res.ini` key ranges to features and to the code that
> loads them.
> Status: **observed** unless marked *inferred* / *unknown*. All addresses are VAs in
> `Defender.exe` (image base `0x140000000`) unless the module is named. Companion:
> [docs/06-cli-and-shell.md](06-cli-and-shell.md) for the tools whose strings come from the
> same file.

## 1. Entry point and process model

`Defender.exe` is a 64-bit statically linked MFC application (`vc7libs`/14x, `CDialog`-based,
`GdiplusStartup`, WININET, no COM server). The startup chain is entirely conventional:

| Address | Symbol | Role |
| --- | --- | --- |
| `0x14005eea4` | `start` | CRT entry (`__scrt_common_main_seh`) |
| `0x14007f8c0` | `WinMain_0` | MFC `AfxWinMain`: `AfxWinInit` → `pThread->InitInstance()` → `pThread->Run()` |
| `0x14000d12c` | `CDefenderApp::CDefenderApp` | installs `CDefenderApp::\`vftable'` (RTTI `.?AVCDefenderApp@@` @ `0x1400c37b8`); two `CString` members at `this+400` / `this+432` |
| `0x14000dfb8` | `CDefenderApp::InitInstance` | DPI awareness, driver probe, `/exit` scan, single-instance mutex, help path |
| `0x14000d720` | `CDefenderApp::ExitInstance` | `SetEvent`, `WaitForSingleObject`, `GdiplusShutdown`, `CoUninitialize` |
| `0x14001201c` | `CDefenderDlg::OnInitDialog` + message handling (0xd6d bytes) | main window: tabs, timer, status bar, tray/tip |

`InitInstance` (observed, `sub_14000DFB8`):

1. `LoadLibraryW(L"Shcore")` + `SetProcessDpiAwareness`.
2. `sub_14000D46C()` — opens `\\.\<winDriveLetter>:` to test for the driver
   (template `L"\\\\.\\ :"` @ `0x1400943a0`); failure ⇒ res.ini **1000** `"You have not
   enough privilege."`
3. `sub_1400622F0()` — obfuscated SD-API initialisation.
4. `gdiplus.dll` + `GdiplusStartup(app+416, …)`.
5. `sub_14000D538(app)` — `CommandLineToArgvW` scan for the single switch **`/exit`**
   (string @ `0x140087d78`), stores a flag at `app+384`.
6. `CreateMutexW(NULL, TRUE, L"Global\\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}")`; if
   `ERROR_ALREADY_EXISTS`, finds `#32770` / `"Shadow Defender"`, foregrounds it and, when
   `/exit` was given, posts `WM_APP+0x2C9` (`0x4C9`) to the running instance.
7. Builds `<exedir>\help.chm` into `app+208`.

Threads created by the process:

| Thread proc | Started from | Purpose |
| --- | --- | --- |
| `sub_14000F218` | `sub_140022BA0`, `sub_140023214`, `sub_1400236BC` | shadow-mode worker; `SetThreadPriority(15)`; parameter block of `0x18` bytes: `{event, mode, driveMask, dialogFlag, encrypt}`; mode `1` = enter, `2` = exit+commit, `3` = flags only |
| `sub_14000D36C` | app init | waits 5–15 s (randomised) then tests the system volume's `X:\diskpt0.sys` flag |
| `sub_14000EC2C` | menu / startup | `ShellExecuteW` → `DefenderDaemon.exe` |
| `StartAddress` `0x14000c294` | commit paths | normalises a `CStringArray` of paths (trim, wildcard handling) and calls the commit engine |
| `sub_140061540` | `sub_140063C20` | progress monitor: waits on {abort event, driver progress event} and invokes the progress callback |
| `sub_140010E30` | update menu / startup | HTTP update + registration check |

## 2. Main window and pages

* Window class `#32770`, caption from res.ini ID **0** (`"Shadow Defender"`), located by
  `FindWindowW(L"#32770", L"Shadow Defender")`.
* Custom bitmap tab control at `this+7528` (`CBitmapTab`): `sub_140007AC8(ctrl, 7)` on
  Vista and later, `sub_140007AC8(ctrl, 6)` otherwise; `IsVistaOrLater()` = `sub_14000EBAC`
  (`GetVersionExW().dwMajorVersion < 6`). Bitmaps from instance resources `0xAB`, `0xAC`,
  `0xAD`.
* `SetTimer(hwnd, 0, 1000, NULL)` — the 1 s UI tick.
* Status bar text from res.ini **21**; menu item from **20**.

The tab pages, in the order they are added (observed in `sub_14001201C`, with the tab
control's tab index, the res.ini caption ID and the page control ID):

| Tab # (Vista+) | Caption ID | Caption | Page control ID | Page class |
| --- | --- | --- | --- | --- |
| 0 | 10 | System Status | 180 (`0xB4`) | `CStatusPage` |
| 1 | 11 | Mode Setting | 181 (`0xB5`) | `CVolumePage` |
| 2 | 12 | File Exclusion List | 182 (`0xB6`) | `CFilePage` |
| 3 | 16 | Registry Exclusion List | 249 (`0xF9`) | `CRegistryPage` |
| 4 | 13 | Commit Now | 183 (`0xB7`) | `CCommitPage` |
| 5 | 14 | Administration | 184 (`0xB8`) | `CGeneralPage` |
| 6 | 15 | About | 185 (`0xB9`) | `CAboutPage` |

The non-Vista branch adds six tabs in the order 10, 11, 12, 13, 14, 15 (control IDs 180,
181, 182, 183, 184, 185) — i.e. it drops the **Registry Exclusion List** page. *Inferred:*
registry shadowing is a Vista+ feature; the branch decision is `IsVistaOrLater()`.

> **Discrepancy.** The task brief and `README.md` describe the main window as having
> "5 tabbed pages". The code adds **7** tabs on the analysis host's OS (Vista or later) and
> **6** on XP. The tables above are the observed truth; the "5 pages" figure matches no
> branch.

Dialog inventory (RTTI class names exist for every one of these; the loader for each
dialog's strings is in §4):

| Class | Loader | String group |
| --- | --- | --- |
| `CDefenderDlg` | `sub_14001201C` | 0, 10–16, 20–22 |
| `CStatusPage` | `sub_1400212FC`, refresh `sub_140020A84`, exclusion count `sub_140021A9C` | 10000–10012 |
| `CVolumePage` | `sub_140023FBC`; apply `sub_140022BA0`; tooltips `sub_1400260B8`, `sub_1400254D4` | 20000–20020 |
| `CFilePage` | `sub_140015DE8`; add/save/load `sub_140014CC8`, `sub_140014F7C`, `sub_140015BD8` | 30000–30013 |
| `CCommitPage` | `sub_14001E614`, list save/load `sub_14001EDF0` | 40000–40010 |
| `CGeneralPage` | `sub_140017854`; state push/pull `sub_140017D38` | 50000–50015 |
| `CRegistryPage` | `sub_14001F734` | 60000–60009 |
| `CRegistryDlg` | `sub_14001C5B4`, tree fill `sub_14001C1CC` | 180000–180003 |
| `CLoginDlg` | `sub_14001A958`; `OnOK` `sub_14001A2CC`; blank-password path `sub_140012F34` | 70000–70003 |
| `CSetPwdDlg` | `sub_140020314` (driven by `sub_140016888`) | 80000–80004 |
| `CRegisterDlg` | `sub_14001BC90`; `OnOK` `sub_14001BA88`; `sub_14001BFC4` | 100000–100004 |
| `CEnterDlg` | `sub_14001430C`; `OnOK` `sub_140014240` | 120000–120006 |
| `CExitDlg` | `sub_14001481C`, `sub_1400146DC` | 130000–130009 |
| `CShutdownDlg` | `sub_140020624` | 140000–140008 |
| `CCommitOptionDlg` | `sub_140009308` | 150000–150006 |
| commit progress dialog | `sub_140007E54` | 150007–150008 (Pause/Resume) |
| `CLowSpaceDlg` | `sub_14001AEF8`; list save `sub_14001ABE4` | 160000–160007 |
| trial nag dialog | `sub_140026570` | 90000–90004 |
| `CBusyDlg` | (templates compiled in; driven from `sub_140022BA0` etc.) | 1002, 1005, 1009 |
| `CAboutPage` | `sub_1400055E8` | 110000–110009 |

> **Correction.** `recon/analysis/defender_gui.md` §4.2 states that the 150000-group
> "dialog init [is] not in the exported set". It is: `sub_140009308 @ 0x140009308` loads
> 150000–150006 (`CCommitOptionDlg`) and `sub_140007E54 @ 0x140007e54` loads 150007/150008
> (Pause/Resume).

### 2.1 Control-ID crib (for implementers)

| Page | Controls |
| --- | --- |
| Administration (`sub_140017D38`) | 1118 `autostart`, 1075 `trayicon`, 1032 `tip`, 1028 `shellext` on/off, 1101 `shellext==2`, 1025 password-control, 1035 "Set New Password", 1099 `[space] disable`, 1107 "More Details", 1033 `encrypt`, 1034 `checkupdate`, 1036 `hibernation`, 1120 `RAM` |
| Mode Setting (`sub_140023FBC`) | volume list `1004`, mode buttons/combo `1114`, "Schedule" `sub_140023BE0` |
| System Status (`sub_140020A84`) | drive combo `1097`, fields `1081`, `1083`, `1085`, `1087`, `1089`, `1091`, `1094`, `1096`, `C2DPieGraph` at `this+71*8` |
| File Exclusion page (`sub_140016408`) | list `1005`, "Apply" `1049` (disabled while any volume is shadowed → res 30012) |
| Registry page (`sub_14001FC44`) | list `1005` |

## 3. How `res.ini` is found and parsed

Resolution is duplicated in every string-loading helper (`sub_14000D8DC`, `sub_14000DAF0`,
`sub_14000DDC8`, the daemon's `WinMain`, ShellExt's menu helpers):

```c
/* sub_14000D8DC @ 0x14000d8dc */
if (app->resIniPathCString /* app+432 */ is empty) {
    DWORD cb = 520;
    if (SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path",
                    &type, Filename, &cb) != ERROR_SUCCESS) {
        GetModuleFileNameW(NULL, Filename, 0x104);         /* exe directory fallback */
        *wcsrchr(Filename, L'\\') = 0;
    }
    wcscat_s(Filename, 0x104, L"\\res.ini");
    app->resIniPath = Filename;                             /* cached in a CString */
}
```

The file itself is a plain INI:

* one section that matters: **`[common]`**;
* keys are the **decimal string of the ID** (`Format(L"%d", id)`);
* values are UTF-16, single-line, with the two-character sequence `\n` used as the line
  break;
* an optional `[translate]` section carries `authorinfo` (credits).

`GetResString` (reconstruction of `sub_14000D8DC @ 0x14000d8dc`, size 0x1cd):

```c
/* reconstruction: res.ini loader — the original is an MFC/ATL implementation with
   CString temporaries; the behaviour is exactly this.                              */
CString GetResString(int id)
{
    WCHAR  path[260];
    WCHAR  buf[4096];                    /* ReturnedString[2048] WCHAR in the original   */
    WCHAR  key[32];
    DWORD  cb = 520;
    CString s;

    if (SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path",
                    NULL, path, &cb) != ERROR_SUCCESS) {
        GetModuleFileNameW(NULL, path, 260);
        *(wcsrchr(path, L'\\')) = 0;
    }
    wcscat_s(path, 260, L"\\res.ini");

    swprintf(key, L"%d", id);
    GetPrivateProfileStringW(L"common", key, L"", buf, 0x1000, path);  /* 4096 WCHARs */
    s = buf;
    s.Replace(L"\\n", L"\n");
    return s;
}

/* generic section/key form: sub_14000DAF0 (used for [translate] authorinfo) */
CString GetResStringEx(const wchar_t *section, const wchar_t *key);
```

Consequences an implementer must respect:

1. **Localisation is a file swap.** Replacing `res.ini` re-labels the whole UI, including
   the Explorer context menu, because `ShellExt.dll` reads the same file (IDs 1014/1015).
2. **The default is the empty string**, so a missing key yields a blank caption — no
   English fallback exists except in the daemon's tray menu (which carries built-in
   literal fallbacks `&Open Main Window`, `&Exit All Shadow Modes`, `Show Desktop &Tip`,
   `Hide Tray &Icon`, `&Help`).
3. Dialog templates are compiled in; captions are patched at run time with
   `CWnd::SetWindowText` after a `GetResString` call (`sub_140032D38`). There is no
   `LoadString` path for UI text.
4. The daemon has its own loader `sub_140002140 @ 0x140002140`
   (`GetPrivateProfileStringW(L"common", key, &Default, buf, len, path)`) used for the
   tray-menu (30–34), tooltips (1017/1018) and the low-space balloon (1016).

## 4. Complete `res.ini` key map

`keys` = keys present in the shipped file on the analysis host (208 keys total, file size
8935 bytes, CRLF line endings, no BOM). "Loader" cites the function that first calls
`GetResString(id)` for that group.

| Range | Keys | Feature | Loader (evidence) |
| --- | --- | --- | --- |
| `0` | 1 | application/window caption | `sub_14001201C` |
| `10–16` | 7 | tab captions in bitmap-tab order: 10 System Status, 11 Mode Setting, 12 File Exclusion List, 16 Registry Exclusion List, 13 Commit Now, 14 Administration, 15 About | `sub_14001201C` |
| `20–22` | 3 | 20 `"&Register"` menu item, 21 `"For help, press F1"` status bar, 22 `"A new version is avaible."` | `sub_14001201C`; update notice `sub_140018740` |
| `30–34` | 5 | tray popup menu: 30 Open, 31 Show Desktop Tip, 32 Hide Tray Icon, 33 Help, 34 Exit All Shadow Modes | daemon `sub_1400014F0` via `sub_140002140` |
| `100–101` | 2 | mode words `"Shadow Mode"` / `"Normal Mode"` | `sub_140025664` (used by `sub_140020A84`) |
| `200` | 1 | generic dialog title `"Hint"` for every `CFileDialog` | `sub_140015DE8` et al. |
| `1000–1023` | 23 of 24 | engine/progress messages; see the sub-table below | `sub_14000B85C`, `sub_14000FA78`, `sub_140022BA0`, `sub_140012F34`, `sub_14001A2CC`, daemon |
| `10000–10012` | 13 | System Status page: headings, Capacity / Used / Free / Actual Free / Space Used by SD / Path / Write-cache Total+Used, Exclusion list count | `sub_1400212FC` (init), `sub_140020A84` (refresh), `sub_140021A9C` (count) |
| `20000–20020` | 21 | Mode Setting page: table headers, Enter/Exit/Exit-All buttons and tooltips, schedule, RAM-cache label + warning | `sub_140023FBC`, `sub_140022BA0`, `sub_140023214`, `sub_1400236BC`, `sub_1400260B8`, `sub_1400254D4` |
| `30000–30013` | 13 of 14 | File Exclusion List page (list header, add/delete/apply, save/load, shadow-mode guards) | `sub_140015DE8`, `sub_140014CC8`, `sub_140014F7C`, `sub_140015BD8` |
| `40000–40010` | 11 | Commit Now page (list header, add/delete/apply, save/load) | `sub_14001E614`, `sub_14001EDF0` |
| `50000–50015` | 16 | Administration page (tray, tip, shell ext, password, low space, start with Windows, encrypt, update, hibernation) | `sub_140017854`, `sub_140017D38` |
| `60000–60009` | 10 | Registry Exclusion List page | `sub_14001F734` |
| `70000–70003` | 4 | password prompt (title, `"Please put in the &password:"`, OK, Cancel) | `sub_14001A958` |
| `80000–80004` | 5 | Set Password dialog | `sub_140020314` (driven by `sub_140016888`) |
| `90000–90004` | 5 | trial: 90000 expired, 90001 `"…expire in %d day(s)"`, 90002 Buy, 90003 Later, 90004 Register | `sub_140026570` |
| `100000–100004` | 5 | Register dialog (title, prompt, "Get Registration Code", OK, Cancel) | `sub_14001BC90`, `sub_14001BFC4` |
| `110000–110009` | 10 | About page (copyright, system information, user/organization/serial labels, online link, legal warning, OK) | `sub_1400055E8` |
| `120000–120006` | 7 | Enter Shadow Mode dialog (+ "Exit Shadow Mode on Shutdown", "Enter Shadow Mode on Boot") | `sub_14001430C`, `sub_140014240` |
| `130000–130009` | 10 | Exit Shadow Mode dialog (discard / commit all / force dismount) | `sub_14001481C`, `sub_1400146DC` |
| `140000–140008` | 9 | reboot/shutdown prompt | `sub_140020624` |
| `150000–150008` | 9 | commit confirmation/options + progress (deleted files, no recursion, pause/resume) | `sub_140009308` (150000–150006), `sub_140007E54` (150007/150008) |
| `160000–160007` | 8 | Threshold Space Setting dialog | `sub_14001AEF8`, `sub_14001ABE4` |
| `170000–170005` | 6 | verification-code prompt (title, prompt, tip, label, OK, Cancel) | **unknown** — no literal loader call found in `Defender.exe` (the immediate `0x29810` = 170000 does not occur); *inferred:* consumed through a computed ID |
| `180000–180003` | 4 | "Select a registry item" dialog | `sub_14001C5B4`, `sub_14001C1CC` |

`1000–1023` sub-table (the group has no key `1010`):

| ID | Text (shipped file) | Loader |
| --- | --- | --- |
| 1000 | You have not enough privilege. | `sub_14000DFB8` (driver-missing path; literal `0x3E8`) |
| 1001 | Operation aborted. | commit engine |
| 1002 | Operation finished. | `sub_140022BA0`, `sub_140023214` |
| 1003 | Invalid password. | `sub_14001A2CC` (literal `0x3EB`) |
| 1004 | The password field is invalid. Please type your password and try again. | `sub_1400201FC` |
| 1005 | Please wait ... | busy dialog |
| 1006–1008 | Committing %s / Commit file "%s" failed(%s) / Commit file "%s" failed, error code(%d) | `sub_14000B85C` |
| 1009 | Committing %s ..., %d percent completed. | `sub_14000FA78` (literal `0x3F1`) |
| 1011 | All documents\|*.*\|\| (file-dialog filter) | file dialogs |
| 1012 | You must select at least one volume. | `sub_140022BA0` |
| 1013 | Please save editing file … before enter Shadow Mode … | `sub_140022BA0` |
| 1014 | Commit by Shadow Defender | **`ShellExt.dll`** only (`GetPrivateProfileStringW(L"common", L"1014", …)`) |
| 1015 | Commit the selected files and folders … | **`ShellExt.dll`** only |
| 1016 | %s is in low free space, exit Shadow Mode now please. | daemon |
| 1017 / 1018 | %s is in Shadow Mode. / %s are in Shadow Mode. | daemon tray tooltip |
| 1019–1021 | replace-file prompt, "Shadow Defender List files", "Could not open file(%s)." | list save/load |
| 1022 / 1023 | Shadow Defender is committing changes, please wait a while... / Commit finished. | daemon balloons |

## 5. Where the host file differs from what the code expects

Nothing is *broken*: every ID that any literal loader call requests exists in the shipped
`res.ini`. The differences worth recording are:

1. **Unused numbering holes.** Keys `1010` and `30011` are absent from the file **and** are
   never requested by any module (0 occurrences of the immediates `0x3F2` and `0x753B` in
   `Defender.exe`; `CmdTool`/`Commit`/`ShellExt` do not request them either). They are
   retired IDs, not missing strings.
2. **`[translate] authorinfo` is commented out.** The shipped file contains
   `;authorinfo=Translated by: Tony`. `GetPrivateProfileStringW` skips `;`-comment lines, so
   `GetResStringEx(L"translate", L"authorinfo")` returns the default (empty) and the About
   page shows no translator credit even though the shipped file looks like it has one.
3. **Version drift in the copyright string.** The About text (ID 110001) says
   `Copyright (C) 2007-2020, SHADOWDEFENDER.COM`, while `Defender.exe` also contains the
   hard-coded literal `Copyright (C) 2007-2018, SHADOWDEFENDER.COM. All rights reserved.`
   The localisable string is newer than the executable's own copy — evidence that
   `res.ini` is updated independently of the binaries.
4. **No `[translate]` localisation is installed**: the section exists but is empty apart
   from the comment, i.e. the host runs the original English strings.
5. All keys that the **daemon** needs for its tray menu are present (30–34), so the daemon's
   literal fallbacks never appear on this host.

## 6. Open questions

1. **Who loads 170000–170005.** The group is present and clearly a dialog
   ("verification code"), but no literal loader exists in `Defender.exe`, and `CmdTool`,
   `Commit` and `ShellExt` do not request it. *Inferred:* the register/verification flow
   formats the ID at run time. The loader is **unknown**.
2. **The exact call chain that assigns page control IDs to tab indices** was read from the
   Vista+ branch of `sub_14001201C`; whether the XP branch maps any page differently
   (beyond dropping the registry page) was not independently verified.
3. **`CBusyDlg`, `CCommitOptionDlg`, `CWelcomeDlg` dialog templates** were not dumped; only
   their string IDs and (for the option dialog) the loader function are known.
4. Whether the About page's `[translate]` hook is the only consumer of
   `GetResStringEx` — one more call site may exist in code not covered by the export.
