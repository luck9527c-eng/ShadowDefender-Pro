# Shadow Defender — Command-Line Tools and Shell Integration

> Scope: `CmdTool.exe`, `Commit.exe`, `ShellExt.dll` and `Uninstall.exe` — grammar,
> behaviour, registration data, exact output text and exit codes, and the shared
> infrastructure they all embed.
> Status: **observed** unless marked *inferred* / *unknown*. Addresses are VAs in the
> named module (`CmdTool`/`Commit`/`Uninstall` base `0x140000000`, `ShellExt` base
> `0x180000000`). Consolidated from `recon/analysis/cli_and_shell.md`.
> Companion: [docs/04-service-protocol.md](04-service-protocol.md) for the device
> protocol, [docs/02-obfuscation.md](02-obfuscation.md) for the `.reloc` VM.

## 1. The shared substrate

### 1.1 Family and identity

| Target | PE | Image base | Version resource |
| --- | --- | --- | --- |
| `CmdTool.exe` | PE32+ x64 | `0x140000000` | "Shadow Defender Command Line Tool", 1.5.0.726 |
| `Commit.exe` | PE32+ x64 | `0x140000000` | 1.5.0.726 |
| `ShellExt.dll` | PE32+ x64 | `0x180000000` | "Shadow Defender Shell Extension", 1.5.0.726 |
| `Uninstall.exe` | PE32+ x64 | `0x140000000` | (no version resource) |
| `Service.exe` | PE32+ x64 | `0x140000000` | service `{0CBD4F48-3751-475D-BE88-4F271385B672}` |

All are Authenticode-signed (DigiCert; the embedded `SECURITY` directory is present).
`CmdTool`/`Commit`/`Uninstall` are MFC 14 applications, `ShellExt` is ATL. All four ship
with relocation blocks **pre-applied** in the file (absolute VAs are stored in `.rdata`
tables, e.g. `ShellExt.dll` `0x18001b798`), so a re-derivation of RVAs from the raw file
must account for the image-like layout.

### 1.2 Device I/O lives inside the VM

Every tool in this document contains an oversized section *named* `.reloc` (`RWX`,
class=CODE) whose real `BASERELOC` directory covers only a small prefix. Past that prefix
the section holds: a relocator, a 126-entry table of qword **RVAs**, and the handlers the
table points at. Call sites are 15-byte stubs:

```asm
push <program_rva>        ; e.g. 0x000AE317
push <entry_index>        ; e.g. 0x5B
jmp  <relocator>
```

The relocator caches the module base, flips the table's RVAs into absolute pointers under
an atomic latch, and tail-jumps through `table[index]`. Everything the tools do to the
driver — the `CreateFileW` + `DeviceIoControl` sequences, including their IOCTL codes and
buffer contents — is inside those handlers. **The device-I/O bodies of all four tools are
therefore opaque to static analysis**; what is recovered is the surrounding plaintext
(filenames, buffer sizes, call order, strings, and — in `CmdTool` — a handful of
re-implemented wrappers). The scheme is documented in full in
[docs/02-obfuscation.md](02-obfuscation.md), §7.

Recovered per-module constants (observed; the driver included for context):

| Module | Relocator | VM workspace RVA | Table RVA | Entries |
| --- | --- | --- | --- | --- |
| `CmdTool.exe` | `0x1400AE263` | `0x75400` | `0xADE73` | 126 |
| `Commit.exe` | `0x1400D86E8` | `0xA4E00` | (in `0xA4F00…`) | 126 |
| `ShellExt.dll` | `0x180062591` | `0x30800` | — | 126 |
| `Uninstall.exe` | `0x14009F351` | `0x6F200` | — | 126 |
| `diskpt.sys` | `0x2800B7DE9` | `0x2D200` | `0x679A9` | 136 |

For `CmdTool.exe` the table entries themselves are plaintext RVAs
(`0x75553, 0x757EF, 0x7665E, … 0xADE0B`); the bodies they point at are not ordinary
compiled code but VM-style bytecode that mutates a scratch register file with opaque
XOR/OR/ADD constants (`xor dword ptr [r10], 0x24323E20` at `0x140075582`).

### 1.3 Shared support library ("SdApi")

All four binaries statically link the same helper library, recognisable by its string set:
`diskpt`, `SYSTEM\CurrentControlSet\Services\%s`, `GUID`, the 16×`%02x` formatter,
`FAT32/FAT16/EXFAT/NTFS`, `\\.\C:`, `%s\*`, `%s\%s`,
`CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}`, `Path`, `SOFTWARE\Shadow Defender`,
`diskpt0.sys`, `%c:\%s`, `DpShadow`, `C:\sdtrace.log`.

`CmdTool.exe` instance (observed):

| Function | Address | Role |
| --- | --- | --- |
| `sub_140025480` / `sub_140025590` | `0x140025480` / `0x140025590` | driver session unlock/lock; visible part is `CreateFileW(L"\\\\.\\DpControl", 0x80, 3, NULL, 3, 0x80, NULL)` (`0x1400254ae`, `0x1400255be`), body in VM |
| `sub_1400256A0` | `0x1400256A0` | `\\.\<drive>:` open probe |
| `sub_140025800` | `0x140025800` | read the installation GUID (driver first, then `HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID`) |
| `sub_140025910` | `0x140025910` | open `\\.\DpControl`, then VM with a **136-byte (`0x88`)** zeroed buffer |
| `sub_140025A50` | `0x140025A50` | shadow-path resolution |
| `sub_140025C80` | `0x140025C80` | read `<drive>:\diskpt0.sys` state (512-byte header + VM) |
| `sub_140025E50` / `sub_140025EB0` | `0x140025E50` | open `\\.\X:` and query volume info (`info.dwState == 1` ⇒ shadowed) |
| `sub_1400262B0` | `0x1400262B0` | `\\.\X:` + set-mode entry point |
| `sub_140026330` | `0x140026330` | `SdSetVolumeFlag` — fully plaintext; writes/validates `diskpt0.sys` |
| `sub_140026F10` | `0x140026F10` | `/now` + `/enter` immediate apply |
| `sub_140027340` | `0x140027340` | `/now` + `/exit` immediate apply + shared memory |
| `sub_140027610` | `0x140027610` | trace logger → `C:\sdtrace.log`, format `"[ % 16s ] \| " + msg`, 1 MB cap |

`C:\sdtrace.log` is a *diagnostic* log, not a console: `sub_140027610` opens it with
`wfopen_s(…, L"a+")` and truncates at 0x100000 bytes. All `SdSetVolumeFlag: …`,
`Open Volume…`, `Dismount Volume…`, `Volume is not protected`,
`Get Volume Information failed %d` strings land there.

### 1.4 Shared configuration surface

| Artifact | Content |
| --- | --- |
| `HKLM\SOFTWARE\Shadow Defender` | `Path` (install directory), read by all four tools |
| `<install>\res.ini` | localised strings; numeric keys in `[common]` (ShellExt reads 1014/1015) |
| `<install>\user.dat` | `[common] hash/hash2/sn/time/RAM/continue/volume/shellext/hibernation/…` |
| `X:\diskpt0.sys` | per-volume shadow state file (hidden+system, write-through, NTFS-compressed) |
| `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` | per-volume chunk cache directory |

`[common] shellext` is a **tri-state mode**, not a boolean (observed in ShellExt's
`QueryContextMenu` and Commit's `sub_140003334`):

| Value | Context-menu item | Password required |
| --- | --- | --- |
| `0` | suppressed (returns 0 without inserting) | — |
| `1` | shown | no |
| `2` | shown | **yes** |
| anything else | shown | no (treated as "not 1/2") |

### 1.5 Cross-process values used as IPC

| Value | Where | Meaning |
| --- | --- | --- |
| `Global\ShadowDefenderSharedMemory` | CmdTool `sub_140027340` (`0x1400273f9`) | 4096-byte section, `DWORD[0]` = progress |
| `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | Uninstall `sub_140002B18` | GUI single-instance mutex; if held ⇒ "Please close Shadow Defender main interface." |
| `"Shadow Defender Daemon Window"` | Uninstall `sub_140002B18` | `FindWindowW(NULL, …)` then `SendMessageW(hwnd, 0x47B, 0, 0)` |
| `0x402` (`WM_USER+2`), wParam `0x14/0x28/0x50/0x64` | Uninstall `sub_140001A34` | self-posted progress ticks |

## 2. `CmdTool.exe`

### 2.1 Entry and dispatch

`start @ 0x1400235C0` → CRT → `main @ 0x140005510`. `main` initialises, calls
`sub_140003330 @ 0x140003330` (size 0x1116, **the entire dispatcher**) and returns **0
unconditionally** on the normal path:

```c
int main(void)
{
    if (sub_14000833C(GetModuleHandleW(NULL), 0, GetCommandLineW(), 0) != 0) {
        wsetlocale(0, L".OCP");
        sub_140026060();          /* hidden-code/VM runtime init   */
        sub_140003330();          /* command dispatcher (exit code discarded) */
        sub_140025460();
        return 0;
    }
    printf(L"Fatal error: Initialization failed\n");
    return 1;
}
```

Three byte ranges inside `sub_140003330` are VM payloads — notably
`0x140003565`–`0x1400039AD` (1096 bytes, exits via `jmp 0x1400B5B6D`), which contains the
**`/pwd:` verification**, and `0x140003B25`–`0x140003CA0` (379 bytes). The HEX-RAYS
output for the function is truncated at those points; the plaintext logic around them is
in `all_disasm.asm` `0x140003330`–`0x14000443B`.

### 2.2 Grammar

Two passes over `CommandLineToArgvW`. Pass 1 (`0x140003400`–`0x14000355D`) validates and
extracts; comparisons are case-insensitive (`_wcsnicmp`/`_wcsicmp`):

| Argument | Match | Value handling |
| --- | --- | --- |
| `/pwd:<OLD>` | first 5 wchars | value after `:` copied into a 64-wchar buffer (`wcsncpy_s`, ≤ 0x20) |
| `/data:<V>` | first 6 wchars | **undocumented**; value after `:` copied into a 128-wchar buffer |
| `/list` | exact | flag |
| `/enter:<D…>` | first 7 wchars | accepted; letters parsed in pass 2 |
| `/exit:<D…>` | first 6 wchars | accepted |
| `/xpwd:<NEW>` | first 6 wchars | accepted |
| `/commit:<P>` | first 8 wchars | accepted |
| `/reboot` | exact | flag |
| `/shutdown` | exact | flag |
| `/now` | exact | sets `now_flag` |
| anything else | — | **silently ignored** |

If no switch was recognised the tool prints the shipped `CmdTool.txt` (resolved via
`GetModuleFileNameW` → `PathRemoveFileSpecW` → `PathAppendW(L"CmdTool.txt")`) and returns;
`main` discards the return value, so the exit code is 0.

Pass 2 (`0x140003CA0`–`0x140004315`) runs the actions in a fixed order: `/enter:` →
`/exit:` → `/xpwd:` → `/commit:` → `/list`, then a separate loop for `/reboot` /
`/shutdown`.

Differences from the shipped `samples/CmdTool.txt`:

1. `/data:<V>` is **not documented**. It is parsed and stored but the plaintext action
   loop never consumes it; its handler is in the VM. *Inferred:* it overrides the data key
   used for the password salt.
2. The doc implies `/now` belongs to `/enter`. The code also honours `/now` with `/exit`,
   through a **different** path (`sub_140027340` instead of `sub_140026F10`).
3. Drive letters are a **set of characters**, not a range: the loop after the colon accepts
   only `C`–`Z`/`c`–`z` (`lea ecx,[rdx-43h]; cmp cx,17h; jbe ok` at `0x140003CF0`), so
   `/enter:CDE` means three drives; `A:` and `B:` are rejected.
4. Values may contain `:` (`wcschr(arg, ':')` finds the *first* colon) but the copies are
   bounded (32 wchars for `/pwd:`, 128 for `/data:`/`/xpwd:`).
5. All switches are case-insensitive.
6. `/commit:"C:\Test"` works — `CommandLineToArgvW` strips the quotes, and the handler
   additionally strips one leading/trailing `"` if present (`cmp cx,22h` at `0x1400040E6`).

### 2.3 Per-command behaviour

Common preamble for `/enter` and `/exit`: `sub_140025590()` (driver session lock) before
any state change, `sub_140025480()` after.

**`/list`** (`0x140004137`–`0x140004193`) — for `letter = 'C'..'Z'`:
`sub_140002460(letter)` then `sub_140025E50(letter, &info)`; when `info.dwState == 1`:

```
%c: is in shadow mode.
```

**`/enter:<set>`** (`0x140003CA0`–`0x140003E94`), per letter:

```c
sub_1400262B0(letter, 3);          /* set the pending flag to "shadow"      */
sub_140025C80(letter, &status);    /* read the pending flag back            */
if (status != 3)  printf(L"Failed to change the status of %c:, error code = %d.\n", …);
else if (!now)    printf(L"Change the status of %c: successfully,\nPlease restart the computer for this to take effect.\n", …);
else if (sub_140026F10(letter)) printf(L"Change the status of %c: successfully.\n", …);
else { OutputDebugStringW(L"CmdTool: error code %d\n");
       printf(L"Change the status of %c: successfully,\nbut a reboot is required for changes to take effect.\n", …); }
```

Special case at `0x140003D06`: when the requested drive equals the current system drive the
code reads `HKLM\SOFTWARE\Shadow Defender\Path\user.dat`, tests
`[common] hibernation` (default 0) and, if set, calls `sub_140002F20()` — a WMI/BCD helper
that opens the BCD store object `{9dea862c-5cdd-4e70-acc1-f32b344d4795}` and sets element
`0x26000005` (`HibernateEnabled`) to 1 before shadowing the system volume. (The same
element is set by the GUI; see [docs/05-user-interface.md](05-user-interface.md).)

**`/exit:<set>`** (`0x140003E94`–`0x140003FCC`) — same shape with mode `0`; with `/now` it
calls `sub_140027340(letter, 0, 1, 0, 0)`.

**`/xpwd:<NEW>`** (`0x140003FCC`–`0x1400040B3`) — fully plaintext:

```c
p = wcschr(arg, ':');
newpwd = (p[1] == 0) ? L"@BLANKPWD" : p + 1;      /* empty ⇒ the blank sentinel */
sub_140002240(newpwd, hashed);                     /* MD5(salt + newpwd) → 32 hex */
userdat = GetUserDatPath();                        /* sub_1400045F0              */
sub_140025590();
if (!WritePrivateProfileStringW(L"common", L"hash", hashed, userdat))
     printf(L"Failed to change the password, error code = %d.\n", GetLastError());
else printf(L"Password has been changed successfully.\n");
```

**`/commit:<path>`** (`0x1400040B3`–`0x140004137`):

```c
p = wcschr(arg, ':') + 1;
if (p[0] == L'"') p[wcslen(p)-1] = 0;               /* strip quotes */
if (sub_140025E50(p[0], &info) && info.dwState == 1) {  /* source volume shadowed */
    sub_140025590();
    sub_1400049A0(p, info.dwVolumeSerial_or_size);  /* the commit worker */
    sub_140025480();
}
```

`sub_1400049A0` (plaintext, 0x7d3 bytes) walks the path with `FindFirstFileW`, `%s\*.*`,
`"\*.*"`, `pathFindFileNameW`, copies each file out of the shadow area through
`\\.\%s%x\`-style volume handles (`PathAppendW` / `GetVolumeNameForVolumeMountPointW`) and
prints:

```
Failed to commit "%s", error code = %d.
Commit "%s" successfully.
Failed to delete "%s", error code = %d.
Delete "%s" successfully.
```

**`/reboot`** (`0x1400041C0`–`0x140004260`) and **`/shutdown`**
(`0x140004260`–`0x140004306`) — identical shape: print `System is rebooting...` /
`System is shutting down...`, enable `SeShutdownPrivilege`
(`OpenProcessToken(…, TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY)`,
`LookupPrivilegeValueW(NULL, L"SeShutdownPrivilege", …)`,
`AdjustTokenPrivileges(SE_PRIVILEGE_ENABLED)`), then `ExitWindowsEx(flags, 0x30000)` with
`6` (`EWX_POWEROFF|EWX_FORCE`) for reboot and `0x0D`
(`EWX_SHUTDOWN|EWX_POWEROFF|EWX_FORCE`) for shutdown.

**`/now` + `/enter`** — `sub_140026F10` (plaintext, 0x2F1 bytes):

```c
GetWindowsDirectoryW(sysdir, 260); upper(sysdir[0]); upper(letter);
h = CreateFileW(L"X:\\", GENERIC_WRITE, 3, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
if (h != INVALID_HANDLE_VALUE) {
    DWORD in[10] = {0}; in[0] = 0x4000;
    DeviceIoControl(h, 0x98144, in, 0x28, NULL, 0, &ret, NULL);   /* @0x14002708c */
    CloseHandle(h);
}
if (letter == sysdir[0]) {                       /* system volume */
    OpenProcessToken(…); LookupPrivilegeValue(NULL, L"SeBackupPrivilege", …);
    AdjustTokenPrivileges(…);
    SHDeleteValueW(HKLM, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Reliability",
                   L"LastAliveStamp");
    RegFlushKey(HKLM/HKCU/HKCC/HKCR/HKU);
}
return sub_140027210(L"\\\\.\\X:");              /* CreateFileW GENERIC_RW + VM body */
```

**`/now` + `/exit`** — `sub_140027340` (plaintext, 0x2CB): opens the volume, creates an
auto-reset event (parameter) and a manual-reset event (done), creates/maps
`Global\ShadowDefenderSharedMemory` (4096 bytes, `DWORD[0] = 0`), starts the UI/progress
thread, then retries the dismount twice through each of the two paths
(`sub_140024A20` ×2, then `sub_140024130` ×2). On success:

```c
swprintf(fn, L"%c:\\%s", letter, L"diskpt0.sys");
SetFileAttributesW(fn, FILE_ATTRIBUTE_NORMAL);
DeleteFileW(fn);
```

### 2.4 Non-driver device codes used by CmdTool

| Code | Name | Use |
| --- | --- | --- |
| `0x00090018` | `FSCTL_LOCK_VOLUME` | lock/dismount dance (18 sites) |
| `0x0009001C` | `FSCTL_DISMOUNT_VOLUME` | same |
| `0x00090020` | `FSCTL_UNLOCK_VOLUME` | same (8 sites) |
| `0x0009C040` | `FSCTL_SET_COMPRESSION` | compress the state file (`0x140026946`) |
| `0x00098144` | private (`CTL_CODE(9, 0x51, BUFFERED, FILE_WRITE_ACCESS)`) | `/now`+`/enter`, 40-byte input, `DWORD[0] = 0x4000` |
| `0x00070000` | `IOCTL_DISK_GET_DRIVE_GEOMETRY` | geometry for the state-file size |
| `0x00074004` | `IOCTL_DISK_GET_LENGTH_INFO` | disk size |
| `0x00070048` | `IOCTL_DISK_GET_PARTITION_INFO` | fallback (0x90 bytes) |

### 2.5 Output and exit codes

| Situation | stdout | exit |
| --- | --- | --- |
| init failure (practically unreachable) | `Fatal error: Initialization failed` | **1** |
| no recognised switch | contents of `CmdTool.txt` | **0** (dispatcher's value discarded) |
| wrong/missing password | `Password is not specified or is not correct.` | **0** |
| `/list` hit | `%c: is in shadow mode.` | 0 |
| `/enter`,`/exit` ok without `/now` | `Change the status of %c: successfully,` + restart notice | 0 |
| ok and applied | `Change the status of %c: successfully.` | 0 |
| ok but deferred | `…but a reboot is required for changes to take effect.` + `OutputDebugStringW("CmdTool: error code %d")` | 0 |
| state change failed | `Failed to change the status of %c:, error code = %d.` | 0 |
| `/xpwd:` | `Password has been changed successfully.` / failure text | 0 |
| `/commit:` | `Commit "%s" successfully.` / `Failed to commit "%s", error code = %d.` | 0 |
| `/reboot`,`/shutdown` | `System is rebooting...` / `System is shutting down...` | 0 / process dies |

> **Important:** `CmdTool.exe` **does not signal failure through its exit code.** Scripts
> must parse stdout (or watch `C:\sdtrace.log`).

## 3. `Commit.exe`

### 3.1 Grammar

`start @ 0x1400378C8` → CRT → MFC `AfxWinMain` → `InitInstance` override
**`sub_140003334 @ 0x140003334`** (size 0x50D, always returns 0). There is no switch
grammar; `CommandLineToArgvW` is not imported. The argument is located by hand:

```c
LPWSTR cl  = GetCommandLineW();
WCHAR  sep = (*cl == L'"') ? L'"' : L' ';
LPWSTR end = wcschr(cl + 1, sep);            /* end of argv[0]           */
LPWSTR list = end + 2;                       /* skip separator + space   */
WCHAR  bar  = wcschr(list, L'|');            /* token separator          */
BOOL   hasWildcard = (wcschr(list, L'*') != NULL);
```

⇒ de-facto grammar **`Commit.exe "<path1>|<path2>|…|<pathN>"`** — a single quoted argument,
`|`-separated, exactly as `ShellExt.dll` builds it (§4.5). A lone path without `|` is also
tolerated (the `bar == NULL` branch jumps to the epilogue). Tokenisation:

```c
do { *bar = 0; CStringArray::SetAtGrow(&arr, n, list); *bar = L'|'; list = bar + 1; }
while ((bar = wcschr(bar + 1, L'|')) != NULL);
```

(Observed at `0x140004178`–`0x1400041A3`.)

### 3.2 Behaviour

1. `sub_1400031D0(&userdat)` builds `%Path%\user.dat`, applying the shadow redirection
   fix-up (`sub_140039050`) when the volume is shadowed.
2. Reads `[common] shellext` (default 1).
3. If `shellext == 2` → password gate (§3.4).
4. Confirmation dialog `sub_140005B9C(&dlg, 0)` + `DoModal()`; the constructor receives
   `hasWildcard`, so the wording depends on whether directory wildcards are present.
5. On OK: tokenise, then
   `CreateThread(NULL, 0, StartAddress /*0x140004670*/, &params, STACK_SIZE_PARAM_IS_A_RESERVATION, NULL)`
   followed by the progress dialog `sub_140004F14(&dlg2, 0)` (thread handle stored in the
   dialog object), `CloseHandle(thread)` after `DoModal`.

Worker `StartAddress @ 0x140004670` (plaintext, 0x3D8 bytes), per path:

```c
TrimRight/TrimLeft(path);
if (wcschr(path, L'*'))                       /* "C:\dir\*.*" → the directory */
    path = Left(path, wcsrchr(path, L'\\') - path);
if (PathIsDirectory(path)) sub_1400023F0(path, vol, &size);
else                       sub_140002388(path, &size);
sub_140039050(path[0], &volinfo);             /* must be shadowed, else skip    */
if (wcschr(path, L'*') && PathFileExistsW(dir_of_path)) {
    sub_140038E20(dir, buf, &cb); sub_1400020D0(buf);
}
sub_140003E0C(&params, path, volinfo);        /* recursive commit worker (0x864 B) */
```

### 3.3 IPC facts

* `\\.\DpControl` is opened by the shared helpers `sub_1400389B0` / `sub_140038AC0`
  (lock/unlock, `0x1400389de`/`0x140038aee`), `sub_140038BD0` (GUID query, `0x140038dab`),
  `sub_140038CE0`, `sub_1400394B0`.
* **`Commit.exe` does not import `DeviceIoControl` at all** — every device call is reached
  through the VM (which resolves the API or uses a fixed-up table entry).
* Volume probing/state-file/shadow-area helpers match CmdTool's (`sub_140039620`,
  `sub_140038E20`, `diskpt0.sys`, `{0D9DB60E-…}`).
* `ShellExecuteW` is imported (MFC shell helpers).

### 3.4 Password gate (the fully recovered reference)

```c
if (shellext_mode == 2) {
    WCHAR stored[128];
    GetPrivateProfileStringW(L"common", L"hash",
                             L"00000000000000000000000000000000",   /* default = "unset" */
                             stored, 128, userdat);
    WCHAR key[512] = {0};
    if (sub_140038CE0(key) != 0                                    /* VM body */
        || SHGetValueW(HKEY_LOCAL_MACHINE,
                       L"SYSTEM\\CurrentControlSet\\Services\\diskpt", L"GUID",
                       &type, key, &cb = 512) == ERROR_SUCCESS) {
        wcscat_s(key, 0x100, L"@BLANKPWD");
        CString s(key, 2*wcslen(key)); sub_14000142C(&s, digest16);  /* MD5 */
        swprintf(hex, L"%02x%02x…%02x", digest16[0..15]);
        if (wcscmp(hex, stored) == 0) goto proceed;                  /* blank password OK */
    }
    if (sub_140005494(&pwdDlg, 0) && CDialog::DoModal(&pwdDlg) == 1
        && *((BYTE*)app + 388) != 0)
        goto proceed;
    /* else nothing is committed */
}
```

The dialog's validator is `sub_140005654 @ 0x140005654`: it re-reads `[common] hash` (same
default) and calls the **VM** relocator for the final `hash(typed) == stored` comparison —
the compare site is opaque, the algorithm is not (§5).

### 3.5 Exit codes

`Commit.exe` is a GUI application: **no stdout/stderr**, all feedback through dialogs.
`InitInstance` always returns 0, so `AfxWinMain` takes the "InitInstance failed" path and
the process exits with `ExitInstance()`'s value (normally **0**). No documented status
codes. Diagnostics go to `C:\sdtrace.log` (shared logger) and `OutputDebugStringW`.

## 4. `ShellExt.dll`

### 4.1 Exports

| Export | Address | Note |
| --- | --- | --- |
| `DllCanUnloadNow` | `0x180006FD0` | `GetLockCount() != 0` |
| `DllGetClassObject` | `0x180007000` | ATL factory lookup over the class table at `0x18002A210` |
| `DllRegisterServer` | `0x180007240` | AppID + classes (RGS 102) + typelib |
| `DllUnregisterServer` | `0x180007350` | reverse of the above |
| **`SetWorkMode`** | `0x1800073F0` | `void SetWorkMode(int)` → `dword_18002A190 = a1` (non-standard export) |
| `DllEntryPoint` | `0x1800082C0` | |

`DllMain @ 0x180007160`: on `DLL_PROCESS_DETACH` it does

```c
if (dword_18002A190 != 0 && LoadLibraryW(L"ntdll.dll")) return sub_180062591();
```

i.e. **`SetWorkMode(1)` arms a VM-assisted cleanup hook that runs when Explorer unloads
the DLL**; `SetWorkMode(0)` disarms it. Both `Defender.exe` (`sub_14000D2A8` @
`0x14000d2a8`, string `SetWorkMode` @ `0x140088fd0`) and `DefenderDaemon.exe`
(`0x140003a0a`) call it with `1`.

### 4.2 COM registration data (RGS resources)

`DllRegisterServer` calls `sub_1800052F0(module, 101, …, {L"APPID", L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}"})`
(observed at `0x180007270`) and `sub_180001420(mode)` → RGS **102**. The scripts:

* **RGS 101** (73 bytes): `HKCR { NoRemove AppID { '%APPID%' = s 'DefenderShellExt' } }`
* **RGS 102** (1302 bytes):

```
HKCR
{
    DefenderShellExt.ContextMenuExt.1 = s 'DefenderContextMenuExt Class'
    { CLSID = s '{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}' }
    DefenderShellExt.ContextMenuExt   = s 'DefenderContextMenuExt Class'
    { CLSID = s '{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}'
      CurVer = s 'DefenderShellExt.ContextMenuExt.1' }
    NoRemove CLSID
    {
        ForceRemove {5EE8E9E6-2853-4D28-B2DE-6529EDA0A294} = s 'DefenderContextMenuExt Class'
        {
            ProgID = s 'DefenderShellExt.ContextMenuExt.1'
            VersionIndependentProgID = s 'DefenderShellExt.ContextMenuExt'
            InprocServer32 = s '%MODULE%'
            { val ThreadingModel = s 'Apartment' }
            val AppID = s '%APPID%'
            'TypeLib' = s '{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}'
        }
    }
    NoRemove *
    { NoRemove shellex { NoRemove ContextMenuHandlers
        { ForceRemove DefenderContextMenuExt = s '{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}' } } }
    NoRemove Directory
    { NoRemove shellex { NoRemove ContextMenuHandlers
        { ForceRemove DefenderContextMenuExt = s '{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}' } } }
    NoRemove Drive
    { NoRemove shellex { NoRemove ContextMenuHandlers
        { ForceRemove DefenderContextMenuExt = s '{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}' } } }
}
```

The embedded application manifest requests **`asInvoker`** (resources ID 24/2).

| GUID | Value |
| --- | --- |
| CLSID | `{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` |
| AppID | `{FF2EA936-C1E1-428D-9572-F4285AFC4F48}` |
| TypeLib | `{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}` |
| ProgID | `DefenderShellExt.ContextMenuExt.1` (+ version-independent `…ContextMenuExt`) |
| private interface of the handler | `{A36985CB-46CB-43FD-805E-DC8871233CE9}` |
| `IID_IShellExtInit` / `IID_IContextMenu` / `IID_IClassFactory` / `IID_IUnknown` | standard (`{000214E8-…}`, `{000214E4-…}`, `{00000001-…‑C000-000000000046}`, `{00000000-…}`) |

### 4.3 Object layout

Class record at `.data` `0x18001AB40` (CLSID pointer `0x18001AB80`, `pfnUpdateRegistry`
`0x180001420`, `pfnGetClassObject` `0x180001CF0`, `pfnCreateInstance` `0x180001E60`,
cached factory `0x18002A160`). The COM interface map is `.rdata @ 0x18001AAE0`:

| # | IID | offset | |
| --- | --- | --- | --- |
| 0 | `{A36985CB-46CB-43FD-805E-DC8871233CE9}` | `0x00` | private |
| 1 | `IID_IShellExtInit` | `0x08` | |
| 2 | `IID_IContextMenu` | `0x10` | |
| 3 | terminator | — | |

Primary vtable `0x18001AB98` (`QueryInterface` `0x180001F10`, `AddRef` `0x180001E90`
increments `[this+0x18]`, `Release` `0x180001EC0`), a real-map `QueryInterface` at
`0x180002020`, and sub-vtables for `IShellExtInit` (`Initialize` = `0x180001440`) and
`IContextMenu` (`QueryContextMenu` = `0x180001AA0`, `InvokeCommand` = `0x1800018E0`,
`GetCommandString` = `0x1800016E0`). The object also holds a
`std::list<std::wstring>` of selected paths (`+0x10`/`+0x18`/`+0x20`) and an `HBITMAP` for
the menu glyph at `+1104`.

### 4.4 Methods

**`IShellExtInit::Initialize` — `0x180001440` (0x29B)**

```c
if (pdtobj->GetData(&fmt_CF_HDROP_TYMED_HGLOBAL, &stg) < 0) return E_INVALIDARG;
HDROP hdrop = GlobalLock(stg.hGlobal);
UINT n = DragQueryFileW(hdrop, 0xFFFFFFFF, NULL, 0);
if (n - 1 > 0x63) { …return E_INVALIDARG; }        /* 1..100 files (≤100) */
paths.clear();
for (UINT i = 0; i < n; i++) {
    UINT len = DragQueryFileW(hdrop, i, NULL, 0);
    wchar_t *p = new wchar_t[len + 8];
    if (DragQueryFileW(hdrop, i, p, len + 1)) {
        if (GetFileAttributesW(p) & FILE_ATTRIBUTE_DIRECTORY)
            wcscat_s(p, len + 8, L"\\*.*");        /* directory → wildcard */
        paths.push_back(std::wstring(p));
    }
}
```

⇒ **directories are stored with a trailing `\*.*`**; that is where the `*` seen by
Commit's `hasWildcard` flag and wildcard trimming comes from. More than 100 selected items
are rejected outright.

**`IContextMenu::QueryContextMenu` — `0x180001AA0` (0x247)**

* Returns 0 immediately for `CMF_DEFAULTONLY`.
* Resolves the install dir (`HKLM\SOFTWARE\Shadow Defender\Path`, else the DLL dir) and
  reads `[common] shellext` from `user.dat`; `0` ⇒ returns 0 (no item).
* Builds the drive bitmask of the selection, then shows **one** item only when at least one
  selected drive is a real volume currently in shadow mode (`sub_180008D00(drive, st)` and
  `*(DWORD*)(st+4) == 1`).
* Menu text = `res.ini [common] 1014`; command ID = Explorer's `idCmdFirst`; bitmap via
  `SetMenuItemBitmaps`.

**`IContextMenu::GetCommandString` — `0x1800016E0` (0x1F3)** — help/verb text from
`res.ini [common] 1015`, converted to ANSI unless `GCS_UNICODE` is set.

**`IContextMenu::InvokeCommand` — `0x1800018E0` (0x1B2)** — the exact invocation:

```c
if (*(WORD*)((char*)pici + 16) != 0 || *(WORD*)((char*)pici + 18) != 0)
    return E_INVALIDARG;                                    /* lpVerb must be NULL/0 only */
GetModuleFileNameW(hModule, exe, 260);                      /* *.dll path                 */
*(wcsrchr(exe, L'\\') + 1) = 0;                                       /* keep "<dir>\"     */
wcscat_s(exe, 260, L"Commit.exe");
wchar_t *args = new wchar_t[total + 10];                              /* Σ(len+1)+10       */
args[0] = 0;
for (auto &s : paths) { wcscat_s(args, …, s.c_str()); wcscat_s(args, …, L"|"); }
ShellExecuteW(NULL, L"open", exe, args, NULL, SW_SHOW);
```

⇒ **`"<dir of ShellExt.dll>\Commit.exe" "<path1>|<path2>|…|<pathN>|"`** — one quoted
argument with a **trailing `|`**, working directory unset (`lpDirectory = NULL`).

### 4.5 Other facts

* Imports include `LoadLibraryA/W`, `LoadLibraryExW`, `GetProcAddress`, `VirtualProtect`,
  `VirtualQuery`, `GetSystemInfo` (VM loader), `DragQueryFileW`, `ShellExecuteW`,
  `InsertMenuW`, `SetMenuItemBitmaps`, `LoadImageW`, `GetIconInfo`, `DrawIconEx`,
  `CreateDIBSection`, `BeginBufferedPaint` (menu glyph; UxTheme).
* Diagnostics: `C:\sdtrace.log`.
* The CLSID `{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (which holds the trial timestamp, see
  [docs/08-licensing-and-crypto.md](08-licensing-and-crypto.md)) appears in `Defender.exe`
  and `Uninstall.exe` but **not** here.

## 5. `Uninstall.exe`

### 5.1 Grammar and guards

`start @ 0x140022A8C` → CRT → MFC wizard. The only `GetCommandLineW` call belongs to MFC;
there is no switch table ⇒ **no command-line grammar**; the tool is invoked from the
`UninstallString` of
`HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}`.

Pre-flight guard `sub_140002B18`:

```c
for (WCHAR d = 'C'; d <= 'Z'; d++)
    if (IsRealVolume(d) && QueryVolumeShadowState(d, &st) && st == 1) {
        MessageBoxW(NULL, L"Please uninstall when your OS is not in Shadow Mode.",
                    L"Setup - Shadow Defender", MB_ICONINFORMATION);
        return 0;
    }
HANDLE m = CreateMutexW(NULL, FALSE, L"Global\\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}");
if (m && GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(m);
    MessageBoxW(NULL, L"Please close Shadow Defender main interface.", L"Setup - Shadow Defender", MB_ICONINFORMATION);
    return 0;
}
CloseHandle(m);
HWND w = FindWindowW(NULL, L"Shadow Defender Daemon Window");
SendMessageW(w, 0x47B, 0, 0);        /* tell the daemon an uninstall is running */
return 1;
```

Files that cannot be deleted immediately are pre-marked with
`MoveFileExW(…, NULL, MOVEFILE_DELAY_UNTIL_REBOOT /*4*/)`.

### 5.2 Ordered removal list

Worker `StartAddress @ 0x1400027DC` → **`sub_140001A34 @ 0x140001A34`** (0xDA8 bytes,
plaintext). Progress is reported with `SendMessageW(hwnd, 0x402, percent, 0)` and
`SetWindowTextW(hwndStatus, stage)`.

| # | Stage | Action |
| --- | --- | --- |
| 1 | `Remove registry information...` | for every real volume `C..Z`: `MoveFileExW(L"<d>:\\diskpt0.sys", NULL, MOVEFILE_DELAY_UNTIL_REBOOT)` |
| 2 | — | `<install>\shellext.dll` → `LoadLibraryW` + `DllUnregisterServer` + `FreeLibrary` (removes CLSID, `*`/`Directory`/`Drive` shell handlers, AppID, TypeLib) |
| 3 | — | remove `diskpt` from `HKLM\SYSTEM\CurrentControlSet\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}\UpperFilters`, from `…\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}\LowerFilters`, and `dpstart` from `…\Session Manager\BootExecute` (helper `sub_140001820` removes one element of a multi-string) |
| 4 | — | **only if** both filter lists no longer contain `diskpt` (`sub_1400016CC`): `SetFileAttributesW(%SystemRoot%\drivers\diskpt.sys, NORMAL)`, `DeleteFileW`, `SHDeleteKeyW(HKLM, "SYSTEM\\CurrentControlSet\\Services\\diskpt")` |
| 5 | — | `SHDeleteKeyW(HKLM, "Software\\Shadow Defender")`; `SHDeleteKeyW(HKCR, "CLSID\\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}")` |
| 6 | — | if `BootExecute` no longer contains `dpstart`: delete `%SystemRoot%\dpstart.exe` |
| 7 | — | `CreateProcessW(NULL, L"\"<install>\\Service.exe\" /Uninstall", …, SW_HIDE)` + `WaitForSingleObject(INFINITE)` — service stop and service unregistration (`{0CBD4F48-3751-475D-BE88-4F271385B672}`, incl. its `SafeBoot\Minimal\|Network` subkeys) |
| 8 | `Deleting shortcuts...` | 3 common-start-menu shortcuts (`Shadow Defender.lnk`, `Help.lnk`, `Uninstall Shadow Defender.lnk`; folder name from the Uninstall key's `StartMenuFolder`, default `Shadow Defender`), then empty directories upward; common desktop `Shadow Defender.lnk`; per-user Quick Launch `Shadow Defender.lnk` |
| 9 | `Deleting files...` | from `%SystemRoot%`: `diskpt.dat`, `diskpt.crt`, `diskpt0.dat`; from the install dir: `Defender.exe`, `DefenderDaemon.exe`, `Commit.exe`, `CmdTool.exe`, `CmdTool.txt`, `eula.rtf`, `Help.chm`, `res.ini`, `user.dat`, `Uninstall.exe`; `ShellExt.dll` and `Service.exe` are renamed `*.del`, the copy deleted, then `MoveFileExW(*.del, NULL, 4)`; finally `MoveFileExW(<install dir>, NULL, 4)` |
| 10 | `Deregistering production information...` | `SHDeleteKeyW(HKLM, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}")` |

Summary of what is removed: driver + service + filter registrations + `BootExecute` entry +
`dpstart.exe`; `HKLM\Software\Shadow Defender`; the trial CLSID; the Uninstall key; five
`.lnk` files; 15 named files; per-volume `diskpt0.sys` (delete-on-reboot). The shadow-area
directory `{0D9DB60E-…}` is **not** referenced here — *inferred:* removed by
`Service.exe /Uninstall`, which owns the remover (`sub_1400016A0`). No
`…\CurrentVersion\Run` value is removed by this binary even though the host has the
`Shadow Defender Daemon` Run entry — *observed negative*; the Run value is presumably
removed by the installer/`Service.exe`.

### 5.3 Output

MFC wizard UI text only; no console output. On completion the worker sets a flag and posts
its own private message to the wizard. **Exit codes: none documented/observable** (typical
`ExitInstance()` → 0).

## 6. Reader's checklist

| Item | Value |
| --- | --- |
| Control device open | `CreateFileW(L"\\\\.\\DpControl", 0x80, 3, NULL, 3, 0x80, NULL)` |
| Shadow device | `\\.\DpShadow<hex>` (`%x`, from the volume's shadow id) |
| Session IOCTL | `0x800025E4 + K`, `K = f(diskpt GUID)` — per module, see docs/04 §6 |
| GUID query IOCTL | `0x800030A0` (fixed) |
| Progress section | `Global\ShadowDefenderSharedMemory`, 4096 bytes, `DWORD[0]` = % |
| Password hash | `lowercase_hex(MD5(UTF16LE(diskpt GUID ++ password)))`; blank = `MD5(GUID+"@BLANKPWD")` |
| `shellext` | 0 = hidden, 1 = shown, 2 = shown + password |
| Menu text | `res.ini [common] 1014`, help text `1015` (ShellExt only) |
| Commit invocation | `"<dir>\Commit.exe" "<p1>\|…\|<pN>\|"` via `ShellExecuteW` |
| Max selection | 100 items; directories become `<dir>\*.*` |
| Diagnostics | `C:\sdtrace.log` (not stdout) |
| CmdTool exit codes | always 0 on the normal path — parse stdout |

## 7. Open questions

1. **`/pwd:` verification and `/data:` semantics.** Both inside `CmdTool`'s VM region
   (`0x140003565`–`0x140003CA0`); only the failure string and the observed behaviour are
   known.
2. **`Commit.exe`'s device conversation.** No `DeviceIoControl` import; the codes used by
   its recursive worker (`sub_140003E0C`) are VM-only.
3. **`Uninstall.exe`'s shadow-area cleanup.** Whether `Service.exe /Uninstall` removes
   `X:\{0D9DB60E-…}` directories is asserted only by the remover's presence in
   `Service.exe`, not by tracing its parameterisation.
4. **Who removes the `Run` entry** for `DefenderDaemon.exe`.
5. **`ShellExt.dll`'s `SetWorkMode` cleanup hook** (`sub_180062591`): behaviour unknown
   beyond "runs at Explorer unload with `ntdll` loaded".
6. **`CmdTool`'s `%c: is in shadow mode.`** is printed only for `C..Z`; volumes without
   drive letters cannot be listed.
