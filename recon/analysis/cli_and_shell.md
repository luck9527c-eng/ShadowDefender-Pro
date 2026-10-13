# Shadow Defender 1.5.0.726 — CLI tools and shell integration

Targets: `CmdTool.exe`, `Commit.exe`, `ShellExt.dll`, `Uninstall.exe`
(cross-reference: `Service.exe`, `diskpt.sys`)

Evidence base: IDA exports in `recon/ida/<Target>/` (`all_pseudocode.c`, `all_disasm.asm`,
`functions.txt`, `names.txt`, `segments.txt`, `imports.txt`, `strings.txt`) plus raw
string/scans of `samples/*`. `recon/ida/*/strings.txt` is **incomplete** (the export
crashed — see `samples/EXPORT_ERROR.txt`), so string evidence below is taken from the
binaries directly (`tools/strings.py`), with the file offset given as `foff` and the
virtual address as `va` where useful.

Confidence markers used throughout:
* **OBSERVED** — read directly from code/data bytes or decompiler output.
* **INFERRED** — reasoned from observed facts; reasoning is stated.
* **UNKNOWN** — not resolvable from the available static evidence.

---

## 0. Cross-cutting findings (read this first)

### 0.1 Family identity

| Target | PE | Image base | App version resource |
|---|---|---|---|
| CmdTool.exe | PE32+ x64 | `0x140000000` | `CmdTool.exe`, "Shadow Defender Command Line Tool", 1.5.0.726 |
| Commit.exe | PE32+ x64 | `0x140000000` | `Commit.exe`, 1.5.0.726 |
| ShellExt.dll | PE32+ x64 | `0x180000000` | `ShellExt.dll`, "Shadow Defender Shell Extension", 1.5.0.726 |
| Uninstall.exe | PE32+ x64 | `0x140000000` | `Uninstall.exe`, 1.5.0.726 |
| Service.exe | PE32+ x64 | `0x140000000` | "Shadow Defender Service Application" (service name `{0CBD4F48-3751-475D-BE88-4F271385B672}`) |

All four are Authenticode-signed (`SECURITY` data directory, DigiCert text) and all MFC/
ATL-based (CmdTool/Commit/Uninstall: MFC 14; ShellExt: ATL). The four samples have their
relocations **pre-applied** in the file (e.g. `ShellExt.dll` stores absolute VAs such as
`0x18001b798` in `.rdata` tables), i.e. they are memory-image-like dumps rather than
untouched link output. This matters for anyone re-deriving RVAs from the raw files.

### 0.2 Self-protection: code hidden in a section named `.reloc` (VM-obfuscated)

**OBSERVED.** Every target in the family carries an oversized RWX section *named* `.reloc`
whose declared `BASERELOC` data directory covers only a small prefix:

| Target | `.reloc` VA range | section size | real `BASERELOC` size |
|---|---|---|---|
| CmdTool.exe | `0x140074000`–`0x1400BDF6F` | `0x49F6F` | `0x1280` |
| Commit.exe | `0x1400A3000`–`0x1400E0000`-ish | `0x3CEA1` | `0x1C40` |
| ShellExt.dll | `0x180030000`–`0x180064000`-ish | `0x33E1E` | `0x74C` |
| Uninstall.exe | `0x14009F351`-ish region | (no BASERELOC dir; `RESOURCE` shadows) | 0 |
| diskpt.sys | `.reloc` `0x48334` bytes | — | `0x18` |

Everything past the genuine relocation blocks is **code in a second, obfuscated form**.

**Call mechanism (OBSERVED, reconstructed from `CmdTool.exe` 0x1400AE263, identical in
`diskpt.sys` 0x2800B7DE9, `ShellExt.dll` 0x180062591, `Uninstall.exe` 0x14009F351,
`Commit.exe` 0x1400D86E8).** Call sites are 15-byte stubs in the hidden region:

```asm
; CmdTool.exe @ 0x1400B5B6D
68 17 E3 0A 00        push   <context_rva>      ; e.g. 0x000AE317
68 5B 00 00 00        push   <index>            ; e.g. 0x5B
E9 .. .. .. ..        jmp    <shared_dispatcher>
```

The dispatcher:

```asm
; CmdTool.exe @ 0x1400AE263  (name varies per module)
        pushfq
        push rax rcx rdx rbx rbx rbp rsi rdi r15 r14 r13 r12 r11 r10 r9 r8
        call   $+5
        pop    rcx
        sub    rcx, 1Eh                 ; rcx = dispatcher VA
        sub    rcx, 0AE263h             ; rcx = module base
        mov    ebp, 75400h              ; per-module VM workspace RVA
        add    rbp, rcx                 ; rbp -> VM context block
        push   rcx
        mov    ecx, 1
        mov    ebx, 2Eh                 ; VM spinlock slot
        lock cmpxchg [rbx+rbp], ecx     ; acquire
        pop    rcx
        mov    ebx, 0D2h ; mov [rbx+rbp], rcx     ; ctx.base = module base
        mov    ebx, 0F3h
        mov    rax, [rsp+90h]           ; = first pushed arg (context_rva)
        add    rax, rcx
        mov    [rbx+rbp], rax           ; ctx.current_block = base+context_rva
        mov    eax, 0ADE73h             ; fixed 126-entry pointer table RVA
        add    rax, rcx
        mov    ebx, 10h
        cmp    [rbx+rbp], rax           ; already relocated?
        je     done
        mov    ebx, 3F0h ; shr ebx,3    ; 126 entries
fixup:  add    qword [rax], rcx         ; add module base to 126 qwords
        add    rax, 8 ; dec ebx ; jnz fixup
        mov    [rbx+rbp], rax           ; mark table relocated
done:   mov    rbx, [rsp+88h]           ; = second pushed arg (index)
        shl    rbx, 3
        add    rax, rbx
        jmp    qword [rax]              ; dispatch to table[index]
```

Reconstructed per-module constants (OBSERVED):

| Module | dispatcher | VM workspace RVA | dispatcher table RVA | entries |
|---|---|---|---|---|
| CmdTool.exe | `0x1400AE263` | `0x75400` | `0xADE73` | 126 |
| Commit.exe | `0x1400D86E8` | `0x4E00`+`0xA0000` = `0xA4E00` | (in `0xA4F00..`) | 126 |
| ShellExt.dll | `0x180062591` | `0x30800` | — | — |
| Uninstall.exe | `0x14009F351` | `0x6F200` | — | — |
| diskpt.sys | `0x2800B7DE9` | `0x2D200` | `0x679A9`/`0xB79A9` | 136 |

**OBSERVED:** for `CmdTool.exe` the table at RVA `0xADE73` holds **126/126 valid RVAs**
(`0x75553, 0x757EF, 0x7665E, … 0xADE0B`) — i.e. the *entry pointers* are plaintext.
**OBSERVED:** the bodies they point at are **not** ordinary compiled code but
*VM/bytecode-style obfuscated code* operating on the context block at
`module_base + 0x75400`, e.g. at table entry 0 (`0x140075553`):

```asm
140075553  mov  rbx, rbp
140075556  mov  rdx, rbp
140075559  add  rdx, 0F3h
140075567  mov  rax, 24323E20h        ; opaque constant
140075574  add  r10, 4Ch              ; VM register slot
140075582  xor  dword ptr [r10], eax  ; keyed mutation
...
14009033E  sub  dword ptr [rax], 7B96B09Dh
1400A4706  or   dword ptr [r8], 50CD1FEAh
```

So: the *entry points* are recoverable, the *semantics* are not (each instruction mutates a
slot of a virtual register file with XOR/OR/ADD of opaque constants, and calls/jumps go
through the fixed 126-entry pointer table). **This is the single most important obstacle to
a full static reconstruction of the user-mode tools.** Compare `recon/ida/diskpt` +
`tools/ida_unhide.py`, which document exactly the same scheme for the driver; the driver
dumps in `recon/unhide/hidden_pseudocode.c` show the same opcode-style arithmetic
(e.g. `*(_DWORD *)(v0 + 105) ^= 0x346F8BB4u;`).

Consequence per question: **the device-I/O primitive bodies (`CreateFileW`+`DeviceIoControl`
sequences) are inside this region in all four tools, so their exact IOCTL codes/buffers are
UNKNOWN statically** except where a tool also contains a plaintext path (CmdTool does, see
§1.3), and except `Service.exe`, whose driver calls are plaintext (§5).

### 0.3 Shared "SdApi" support library

All four binaries statically link the same helper library (same code, different addresses),
identified by its string set: `diskpt`, `SYSTEM\CurrentControlSet\Services\%s`, `GUID`,
`%02x%02x…` (16 bytes → 32 hex chars), `FAT32/FAT16/EXFAT/NTFS`, `\\.\C:`, `%s\*`, `%s\%s`,
`CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}`, `Path`, `SOFTWARE\Shadow Defender`,
`diskpt0.sys`, `%c:\%s`, `DpShadow`, `C:\sdtrace.log`.

Representative instance (CmdTool.exe):

| Function | Address | Role (OBSERVED) |
|---|---|---|
| `sub_140025480` / `sub_140025590` | `0x140025480` / `0x140025590` | lock/unlock pair; visible part = `CreateFileW(L"\\\\.\\DpControl", 0x80, 3, NULL, 3, 0x80, NULL)`; body → VM |
| `sub_1400256A0` | `0x1400256A0` | `\\.\<drive>:` volume open probe |
| `sub_140025800` | `0x140025800` | read driver GUID; fallback `HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID` |
| `sub_140025910` | `0x140025910` | open `\\.\DpControl`, then VM ⇒ fills a **136-byte (0x88)** key buffer |
| `sub_140025A50` | `0x140025A50` | path resolution (redirected path) |
| `sub_140025C80` | `0x140025C80` | read `<drive>:\diskpt0.sys` (state file); see §1.3 |
| `sub_140025E50`/`sub_140025EB0` | `0x140025E50` | open `\\.\X:` and query volume info (struct `v[1]` = shadow-mode flag) |
| `sub_1400262B0` | `0x1400262B0` | `\\.\X:` + set-mode entry point |
| `sub_140026330` | `0x140026330` | `SdSetVolumeFlag` — full plaintext implementation, §1.3 |
| `sub_140026F10` | `0x140026F10` | `/now`+`/enter` immediate apply, §1.3 |
| `sub_140027340` | `0x140027340` | `/now`+`/exit` immediate apply + shared memory, §1.3 |
| `sub_140027610` | `0x140027610` | **trace logger → `C:\sdtrace.log`**, format `"[ % 16s ] \| " + msg`, 1 MB cap |

`sub_140027610` is a `printf`-style variadic but writes to `C:\sdtrace.log`, **not stdout**
(OBSERVED: it `wfopen_s(..., L"C:\\sdtrace.log", L"a+")`, prefixes
`swprintf(Buffer, L"[ % 16s ] | ", L"Defender")` and truncates the file when ≥ 0x100000).
All `SdSetVolumeFlag: …`, `Open Volume…`, `Dismount Volume…`, `Volume is not protected`,
`Get Volume Information failed %d` strings are diagnostics for that file.

### 0.4 Shared configuration surface

| Artifact | Content (OBSERVED) |
|---|---|
| `HKLM\SOFTWARE\Shadow Defender` | `Path` (REG_SZ, install dir); read by CmdTool, Commit, ShellExt, Uninstall |
| `<install>\res.ini` | localised UI strings; keys are numeric IDs, read with `GetPrivateProfileStringW(L"common", L"1014"/L"1015", …)` |
| `<install>\user.dat` | INI; `[common] hash=`, `hash2=`, `sn=`, `time=`, `RAM=`, `continue=`, `volume=`, and (OBSERVED in code) `[common] shellext=` and `[common] hibernation=` |
| `X:\diskpt0.sys` | per-volume shadow **state file** in the volume root (hidden+system, NTFS-compressed) |
| `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` | shadow area directory (OBSERVED: `Service.exe` `sub_1400018A0` builds `L"\\\\.\\%C:"` + `L"\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}"`) |

`[common] shellext` is a **mode** value (OBSERVED semantics in ShellExt `QueryContextMenu`
and Commit `sub_140003334`):

* `0` — context-menu item suppressed (ShellExt returns 0 without inserting anything).
* `1` — item shown, no password challenge.
* `2` — item shown, **password protected** (Commit verifies/asks).
* anything else — treated as “not 1/2”, item shown but no challenge (Commit skips to the work).

### 0.5 Dialog/UI guard values used as IPC

| Value | Where | Meaning (OBSERVED/INFERRED) |
|---|---|---|
| `Global\ShadowDefenderSharedMemory` | CmdTool `sub_140027340` | 4096-byte `CreateFileMappingW(INVALID, PAGE_READWRITE=4, 0, 0x1000, name)` + `MapViewOfFile(FILE_MAP_READ|WRITE=6)`; first DWORD set to 0 (progress/status hand-shake with the UI thread) |
| `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | Uninstall `sub_140002B18` | installer/main-UI single-instance mutex; `ERROR_ALREADY_EXISTS` ⇒ "Please close Shadow Defender main interface." |
| `"Shadow Defender Daemon Window"` | Uninstall `sub_140002B18` | `FindWindowW(NULL, …)` then `SendMessageW(hwnd, 0x47B, 0, 0)` (WM_USER+0x7B) |
| `0x402` (WM_USER+2), wParam = `0x14/0x28/0x50/0x64` | Uninstall `sub_140001A34` | progress bar ticks sent to its own dialog |

---

## 1. CmdTool.exe — Shadow Defender Command Line Tool

### 1.1 Entry point and dispatch

* `start` @ `0x1400235C0` → CRT → `main` @ **`0x140005510`** (OBSERVED).
* `main`:
  ```c
  int main(void)
  {
      LPWSTR cl = GetCommandLineW();
      HMODULE h  = GetModuleHandleW(NULL);
      if ( sub_14000833C(h, 0, cl, 0) != 0 ) {   /* CRT/app init, always 1 */
          wsetlocale(0, L".OCP");
          sub_140026060();      /* hidden-code/VM: initialise runtime */
          sub_140003330();      /* the whole command dispatcher */
          sub_140025460();      /* CloseHandle(g_initHandle) */
          return 0;             /* <-- exit code 0 even on command failure */
      }
      printf(L"Fatal error: Initialization failed\n");
      return 1;
  }
  ```
* The real work is one function: **`sub_140003330` @ `0x140003330`** (size 0x1116). Note that
  IDA’s hexrays output for this function is **truncated** (`// ===== sub_140003330` body ends
  early at `return sub_1400AE263();`) because three byte ranges inside it are VM payloads;
  the full logic must be read from `all_disasm.asm` (0x140003330–0x14000443B).

Three byte ranges inside the dispatcher are **not** normal code (OBSERVED high entropy,
no single-byte XOR key reduces it; each starts with a real `jmp rel32` into the hidden
region):

| Range | Size | Exit jump | Note |
|---|---|---|---|
| `0x140003565`–`0x1400039AD` | 1096 B | `jmp 0x1400B5B6D` | entropy 7.70 |
| `0x1400039C9`–`0x140003AFE` | 309 B | — | entropy ~6.9 |
| `0x140003B25`–`0x140003CA0` | 379 B | — | entropy ~6.6 |

⇒ The `/pwd:` **verification** and the VM payload for the *first* pass live there
(**UNKNOWN** statically). Everything else is plaintext.

### 1.2 Command-line grammar

**Parsing (two passes over `CommandLineToArgvW`):**

Pass 1 @ `0x140003400`–`0x14000355D` — *validation and value extraction*. For every
`argv[i]` (`i≥1`), case-insensitive comparison (`_wcsnicmp`/`_wcsicmp`):

| Argument | Comparison | Action |
|---|---|---|
| `/pwd:<OLD>` | first 5 wchars | `wcschr(arg,':')`, copy ≤ 0x20 wchars after `:` into `Destination[64]` |
| `/data:<V>` | first 6 wchars | copy ≤ 0x80 wchars after `:` into `v20[128]` |
| `/list` | exact | accept |
| `/enter:<D..>` | first 7 wchars | accept |
| `/exit:<D..>` | first 6 wchars | accept |
| `/xpwd:<NEW>` | first 6 wchars | accept |
| `/commit:<P>` | first 8 wchars | accept |
| `/reboot` | exact | accept |
| `/shutdown` | exact | accept |
| `/now` | exact | accept, set `now_flag = 1` |
| anything else | — | ignored |

If **no** recognised switch was seen, the tool prints the contents of the `CmdTool.txt`
next to the executable (OBSERVED: `GetModuleFileNameW` → `PathRemoveFileSpecW` →
`PathAppendW(L"CmdTool.txt")` → line-by-line `printf`), i.e. self-documenting help.
It also returns 1 to `main`, which discards it.

Pass 2 @ `0x140003CA0`–`0x140004315` — *action loop*: for every argument, in the fixed order
`/enter:` → `/exit:` → `/xpwd:` → `/commit:` → `/list` (each test short-circuits), and then a
second loop for `/reboot` / `/shutdown`.

**Differences vs. the documented grammar in `samples/CmdTool.txt`:**

1. **Undocumented `/data:<V>` switch** (OBSERVED, exact-match on 6 wchars, value copied into
   a 128-wchar buffer). It is accepted by the parser but the plaintext action loop never
   consumes it ⇒ its handler is in the VM region (**UNKNOWN** semantics; INFERRED: an
   override of the "GUID/data key" used for the password salt, cf. §1.4/§3.3).
2. The doc says `/now` “task effects immediately” only with `/enter`. **OBSERVED** the code
   also honours `/now` with `/exit`, via a *different* code path
   (`sub_140027340` instead of `sub_140026F10`).
3. Drive letters and multiple letters: `/enter:CDE` is not a range — the code iterates the
   **characters after the colon** in the string, accepting only `C`–`Z` / `c`–`z`
   (`lea ecx,[rdx-43h]; cmp cx,17h; jbe ok` / `-63h` for lowercase, `0x140003CF0`), so
   `CDE` = three drives, exactly as the doc implies. `A`/`B` are rejected.
4. `wcschr(arg, ':')` is used for every value switch, so a value may contain `:`; but the
   copy is bounded (`wcsncpy_s`, 0x20 wchars for `/pwd:`, 0x80 for `/data:`/`/xpwd:`).
5. Case-insensitivity: all switches are matched case-insensitively (`_wcsnicmp`/`_wcsicmp`).
6. `/commit:"C:\Test"` (quoted) works because `CommandLineToArgvW` strips quotes; the handler
   additionally strips one leading/trailing `"` if present (`cmp cx,22h`, `0x1400040E6`).

### 1.3 Per-command semantics (OBSERVED, from `all_disasm.asm`)

Common preamble for `/enter` and `/exit` (`0x140003CA0`/`0x140003E94`): `sub_140025590()`
(driver-lock entry) is taken **before** any state change and `sub_140025480()` (exit) after.

**`/list`** (`0x140004137`–`0x140004193`): loops `letter = 'C'..'Z'`; for each,
`sub_140002460(letter)` (volume candidate?) then `sub_140025E50(letter, &info)`; if
`info.dwState == 1` prints:
```
%c: is in shadow mode.\n        /* va 0x140049808 */
```

**`/enter:<letter>`** (`0x140003CA0`–`0x140003E94`):
```c
sub_1400262B0(letter, 3);              /* request mode 3 into the "pending" field */
sub_140025C80(letter, &status);        /* read back pending status            */
if (status != 3) printf(L"Failed to change the status of %c:, error code = %d.\n",
                        letter, GetLastError());
else if (!now_flag)
    printf(L"Change the status of %c: successfully,\nPlease restart the computer for this to take effect.\n", letter);
else if (sub_140026F10(letter))
    printf(L"Change the status of %c: successfully.\n", letter);
else {
    OutputDebugStringW(sprintf(L"CmdTool: error code %d\n", GetLastError()));
    printf(L"Change the status of %c: successfully,\nbut a reboot is required for changes to take effect.\n", letter);
}
```
Note the special case at `0x140003D06`: if the requested drive equals the current drive
(`[rbp+var_240]`), the code first resolves `SOFTWARE\Shadow Defender\Path` → `\user.dat`
and tests `GetPrivateProfileIntW(L"common", L"hibernation", 0, user.dat)`; if non-zero it
calls `sub_140002F20()` (WMI: `CoInitialize` → connect `\\.\root\wmi` → object
`{9dea862c-5cdd-4e70-acc1-f32b344d4795}` (BCD store) → `SetBooleanElement(0x26000005, 1)` —
INFERRED: disable hibernate before entering shadow mode on the system volume).

**`/exit:<letter>`** (`0x140003E94`–`0x140003FCC`): same shape with mode `0`;
`now_flag` ⇒ `sub_140027340(letter, info, 1, 0, 0)`.

**`/xpwd:<NEW>`** (`0x140003FCC`–`0x1400040B3`) — password change, **entirely plaintext**:
```c
p = wcschr(arg, ':');
newpwd = (p[1] == 0) ? L"@BLANKPWD" : p+1;      /* va 0x140049458 */
sub_140002240(newpwd, hashed);                    /* MD5(salt+newpwd) -> 32 hex chars, §1.4 */
userdat = GetUserDatPath();                       /* sub_1400045F0 */
sub_140025590();
if (!WritePrivateProfileStringW(L"common", L"hash", hashed, userdat))
    printf(L"Failed to change the password, error code = %d.\n", GetLastError());
else
    printf(L"Password has been changed successfully.\n");
```
⇒ the new value goes to **`user.dat` → `[common] hash=`**. Note: `@BLANKPWD` is the
sentinel for “empty password” (the hash of the empty password is NOT the hash of an empty
string).

**`/commit:<path>`** (`0x1400040B3`–`0x140004137`):
```c
p = wcschr(arg, ':') + 1;
if (p[0] == L'"') p[wcslen(p)-1] = 0;             /* strip quotes */
if (sub_140025E50(p[0], &info) && info.dwState == 1) {   /* drive is in shadow mode */
    sub_140025590();
    sub_1400049A0(p, info.dwVolumeSerial_or_size);       /* the commit worker */
    sub_140025480();
}
```
`sub_1400049A0` (0x7d3 bytes, plaintext) walks the path (`FindFirstFileW`, `%s\*.*`,
`"\*.*"`, `pathFindFileNameW`), copies each file out of the shadow area via
`\\.\%s%x\` style volume handles (`PathAppendW`/`GetVolumeNameForVolumeMountPointW`), and
prints
```
Failed to commit "%s", error code = %d.\n   /* foff 0x48620 */
Commit "%s" successfully.\n                 /* foff 0x48678 */
Failed to delete "%s", error code = %d.\n   /* foff 0x486e0 */
Delete "%s" successfully.\n                 /* foff 0x48738 */
```

**`/reboot`** (`0x1400041C0`–`0x140004260`) and **`/shutdown`** (`0x140004260`–`0x140004306`):
identical shape — print `System is rebooting...\n` / `System is shutting down...\n`, then
`OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY=0x28)`,
`LookupPrivilegeValueW(NULL, L"SeShutdownPrivilege", &luid)`,
`AdjustTokenPrivileges(SE_PRIVILEGE_ENABLED=2)`, then
`ExitWindowsEx(uFlags, 0x30000)` with `uFlags = 6` (`EWX_POWEROFF|EWX_FORCE`) for `/reboot`
and `uFlags = 0x0D` (`EWX_POWEROFF|EWX_FORCEIFHUNG|EWX_FORCE`… actually
`EWX_SHUTDOWN|EWX_POWEROFF|EWX_FORCE`) for `/shutdown`. Window/exit code: `main` still
returns 0 — but the process usually dies with the system.

**`/now` with `/enter`** — `sub_140026F10(letter)` (plaintext, 0x2F1 bytes):
```c
GetWindowsDirectoryW(sysdir, 260);  upper(sysdir[0]);  upper(letter);
h = CreateFileW(L"X:\\", GENERIC_WRITE, 3, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
if (h != INVALID_HANDLE_VALUE) {
    DWORD in[10] = {0}; in[0] = 0x4000;
    DeviceIoControl(h, 0x98144, in, 0x28, NULL, 0, &ret, NULL);   /* custom volume FSCTL */
    CloseHandle(h);
}
if (letter == sysdir[0]) {                      /* system volume */
    OpenProcessToken(...); LookupPrivilegeValue(NULL, L"SeBackupPrivilege", ...);
    AdjustTokenPrivileges(...);
    SHDeleteValueW(HKLM, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Reliability", L"LastAliveStamp");
    RegFlushKey(HKLM/HKCU/HKCC/HKCR/HKU);       /* avoid "unclean shutdown" prompts */
}
return sub_140027210(L"\\\\.\\X:");             /* CreateFileW GENERIC_RW + VM body */
```

**`/now` with `/exit`** — `sub_140027340(letter, info, flag, 0, 0)` (plaintext, 0x2CB):
```c
sub_1400256A0(letter);                                  /* volume open probe */
hParam = CreateEventW(NULL, FALSE, FALSE, NULL);
hDone  = CreateEventW(NULL, TRUE,  FALSE, NULL);
hMap   = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                            0, 0x1000, L"Global\\ShadowDefenderSharedMemory");
if (hMap) { p = MapViewOfFile(hMap, FILE_MAP_READ|FILE_MAP_WRITE, 0,0,0);
            if (p) *(DWORD*)p = 0; }                     /* progress slot = 0 */
hThread = CreateThread(NULL, 0, StartAddress, &hParam, 0, NULL);   /* UI/progress thread */
sub_140025590();
/* up to 4 attempts, alternating the two dismount paths */
for (i = 0; i < 2 && !rc; i++) rc = sub_140024A20(letter, info, flag);
for (i = 0; i < 2 && !rc; i++) rc = sub_140024130(letter, info, flag);
sub_140025480();
if (rc) {                                /* success: remove the state file */
    swprintf(fn, L"%c:\\%s", letter, L"diskpt0.sys");
    SetFileAttributesW(fn, FILE_ATTRIBUTE_NORMAL);
    DeleteFileW(fn);
}
SetEvent(hDone); WaitForSingleObject(hThread, INFINITE); ...cleanup...
```

### 1.4 IPC of CmdTool.exe

**(a) Control device `\\.\DpControl`** — the visible access pattern is always:
```c
CreateFileW(L"\\\\.\\DpControl",            /* foff 0x51650, va 0x140052250 */
            0x80 /*FILE_READ_ATTRIBUTES*/, 3 /*share R|W*/, NULL,
            3 /*OPEN_EXISTING*/, 0x80 /*FILE_ATTRIBUTE_NORMAL*/, NULL);
```
appearing in `sub_140025480`, `sub_140025590`, `sub_140025800`, `sub_140025910`,
`sub_140025EB0` (OBSERVED at `all_disasm` 0x1400254AE, 0x1400255BE, 0x140025945,
0x140025C99 region). The **`DeviceIoControl` calls that follow are inside the VM region**
⇒ the *codes and buffers used by CmdTool itself* are **UNKNOWN** statically.
(For the codes the driver exposes, see §5.)

**(b) Per-volume state file `<drive>:\diskpt0.sys`** — opened/parsed by `sub_140025C80`
(0x140025C80) and created by `sub_140026330`; see below. Probe form:
```c
h = CreateFileW(fn, GENERIC_READ, 3, NULL, OPEN_EXISTING,
                FILE_FLAG_NO_BUFFERING|FILE_ATTRIBUTE_NORMAL /*0x20000080*/, NULL);
SetFilePointer(h, 0, NULL, FILE_BEGIN);
ReadFile(h, Buffer, 0x200, &n, NULL);            /* 512-byte header */
/* then VM body consumes Buffer + RC4 context */
```

**(c) `sub_140026330` — `SdSetVolumeFlag` (plaintext, 0xBDE bytes) ⇒ full state-file layout.**
Called by `sub_1400262B0(letter, mode)` with a volume device name buffer.

```c
sub_140025EB0(vol);                                  /* open the volume, read info      */
swprintf(state, L"%s\\%s", vol, L"diskpt0.sys");     /* state file path                 */
wcscpy(dev, vol);
if (info.protected == 1)                              /* volume already protected         */
    swprintf(dev, L"\\\\.\\%s%x", L"DpShadow", *(_QWORD*)&info.something);
                                                      /* shadow device name \\.\DpShadow<hex> */
hDev = CreateFileW(dev, GENERIC_READ, 3, NULL, OPEN_EXISTING, 0x80, NULL);
if (hDev == INVALID) { log(L"SdSetVolumeFlag: CreateFile(%s) failed(%d)"); return 0; }

/* geometry probing */
DeviceIoControl(hDev, 0x70000 /*IOCTL_DISK_GET_DRIVE_GEOMETRY*/,   NULL,0, &geo, 0x18, &ret, NULL);
DeviceIoControl(hDev, 0x74004 /*IOCTL_DISK_GET_LENGTH_INFO*/,      NULL,0, &len, 0x20, &ret, NULL);
   /* fallback: 0x70048 = IOCTL_DISK_GET_PARTITION_INFO (0x90 bytes) */
CloseHandle(hDev);

/* layout maths (OBSERVED constants) */
cluster = 4096;  if (disk > 0x100000000) cluster = 0x2000;   /* doubling steps */
                 if (disk > 0x200000000) cluster *= 2; … up to 0x8000000000
meta    = ((disk/cluster + 8)/8 + 4096) & ~0xFFF;           /* metadata area, page aligned */
perSec  = (bytesPerSector > 0x2000) ? bytesPerSector/4 : 2048;

if (info.protected == 1)  return VM(perSec, metaMod);        /* VM body writes the record   */

SetFileAttributesW(state, FILE_ATTRIBUTE_NORMAL);
h = CreateFileW(state, GENERIC_RW, 3, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM|FILE_FLAG_WRITE_THROUGH /*0x80000006*/, NULL);
if (h == INVALID) {                                  /* rotate the old state file away  */
    for (i = 0; i < 1000; i++) {
        name = (i==0) ? L"%s.bak" : L"%s.bak.%03d";
        if (MoveFileW(state, name)) break;
    }
    /* after 1000 failures: GetTempFileNameW + DeleteFileW + MoveFileW */
    h = CreateFileW(state, GENERIC_RW, 3, NULL, CREATE_ALWAYS, 0x80000006, NULL);
}
DWORD in = 0;
DeviceIoControl(h, 0x9C040 /*FSCTL_SET_COMPRESSION*/, &in, 2, NULL, 0, &ret, NULL);
SetFilePointer(h, ((4*(disk/cluster)/0x2000) << 13) + 0x8000
                    + 5*meta
                    + ((mode & 3) ? ((4*(disk/cluster)/0x2000) << 13) + 0x8000 : 0)
                    + 4096, NULL, FILE_BEGIN);
SetEndOfFile(h);                                     /* pre-allocate                     */
SetFilePointer(h, 0, NULL, FILE_BEGIN);
ReadFile(h, header, 0x200, &n, NULL);
*(DWORD*)(header+4) = 0; *(DWORD*)(header+12) = 0;    /* clear state flags (stack slots) */
SetFilePointer(h, 0, NULL, FILE_BEGIN);
WriteFile(h, header, 0x200, &n, NULL);
return VM(perSec, metaMod);                           /* VM body writes the driver record  */
```
So the state file is a **sparse/compressed, hidden+system 512-byte-header file** whose body is
pre-allocated from the disk size and whose header carries two state DWORDs cleared on mode
change. Geometry/FSCTL constants are quoted above.

**(d) Non-driver volume FSCTLs** (OBSERVED, `CmdTool.exe`):

| Code | Name | Use |
|---|---|---|
| `0x00090018` | `FSCTL_LOCK_VOLUME` | `sub_140024A20`/`sub_140024130` lock/dismount dance (18 sites) |
| `0x0009001C` | `FSCTL_DISMOUNT_VOLUME` | same (18 sites) |
| `0x00090020` | `FSCTL_UNLOCK_VOLUME` | same (8 sites) |
| `0x0009C040` | `FSCTL_SET_COMPRESSION` | state file compression |
| `0x00098144` | **custom** (DeviceType 9, function 81, METHOD_BUFFERED, FILE_WRITE_ACCESS) | `/now`+`/enter`, input = 0x28 bytes with `DWORD[0] = 0x4000` ⇒ INFERRED: Shadow Defender filter-driver control on `\\.\X:` |
| `0x00070000` | `IOCTL_DISK_GET_DRIVE_GEOMETRY` | geometry |
| `0x00074004` | `IOCTL_DISK_GET_LENGTH_INFO` | disk size |
| `0x00070048` | `IOCTL_DISK_GET_PARTITION_INFO` | fallback (0x90 bytes) |

**(e) RC4** — `sub_140024090` @ `0x140024090` is the **RC4 PRGA** and `sub_140025350` @
`0x140025350` is the **RC4 KSA** (OBSERVED: 256-byte state initialised to 0..255, standard
`j = j + S[i] + key[i % len]` swap loop; PRGA `i++; j += S[i]; swap; out ^= S[S[i]+S[j]]`).
⇒ **the state file / driver payloads are RC4-encrypted** (INFERRED: keyed with a per-volume
key derived from the disk size / volume serial; the exact key derivation is inside the VM).

```c
/* reconstructed RC4 (x86-64, CmdTool.exe) */
typedef struct { unsigned char i, j; unsigned char S[256]; } RC4_CTX;  /* 258 B, see note */

void rc4_ksa(RC4_CTX *c, const unsigned char *key, int keylen)
{
    for (int i = 0; i < 256; i++) c->S[i] = (unsigned char)i;
    c->i = c->j = 0;
    unsigned char j = 0;
    for (int i = 0; i < 256; i++) {
        j = (unsigned char)(j + c->S[i] + key[i % keylen]);
        unsigned char t = c->S[i]; c->S[i] = c->S[j]; c->S[j] = t;
    }
}
void rc4_apply(RC4_CTX *c, unsigned char *buf, int len)
{
    unsigned char i = c->i, j = c->j;
    for (int k = 0; k < len; k++) {
        i = (unsigned char)(i + 1);
        j = (unsigned char)(j + c->S[i]);
        unsigned char t = c->S[i]; c->S[i] = c->S[j]; c->S[j] = t;
        buf[k] ^= c->S[(unsigned char)(c->S[i] + c->S[j])];
    }
    c->i = i; c->j = j;
}
```
The decompiler shows the state as `int v12; int v13; _DWORD v14[260];` — i.e. the real
buffer is a **264-byte** structure (`{int x; int y; unsigned char S[256];}`) whose `S` is
accessed as bytes; use that layout when re-implementing.

### 1.5 Password handling (CmdTool)

`/xpwd:` calls `sub_140002240(password, out64)` @ `0x140002240` (**plaintext, fully
recovered**):

```c
BOOL SdComputePasswordHash(const wchar_t *password, wchar_t *out64 /*>=64 wchars*/)
{
    MD5_CTX ctx;
    wchar_t salt[256];      /* 512 bytes */
    wchar_t sysdir[260];
    BYTE    info[160];      /* volume info from sub_140025E50 */
    BYTE    digest[16];

    MD5Init(&ctx);                                       /* sub_140001290 @ 0x140001290 */
    GetWindowsDirectoryW(sysdir, 260);
    sub_140025E50(sysdir[0], info);                      /* \\.\C: + query */
    if (info.dwShadowFlag == 1) {
        sub_140025910(salt);                             /* per-install key via \\.\DpControl */
    } else {
        DWORD cb = 512;
        if (SHGetValueW(HKEY_LOCAL_MACHINE,
                        L"SYSTEM\\CurrentControlSet\\Services\\diskpt", L"GUID",
                        &type, salt, &cb) != ERROR_SUCCESS)
            return FALSE;
    }
    wcscat_s(salt, 0x100, password);                     /* salt = <GUID> ++ password */
    MD5Update(&ctx, salt, 2 * wcslen(salt));             /* UTF-16LE bytes           */
    MD5Final(&ctx, digest);                              /* sub_140001340            */
    swprintf(out64, 64, L"%02x%02x%02x%02x%02x%02x%02x%02x"
                        L"%02x%02x%02x%02x%02x%02x%02x%02x",
             digest[0], ... digest[15]);
    return TRUE;
}
```

* **Algorithm: MD5** (OBSERVED — the four MD5 init constants appear literally:
  `0x67452301` @ `0x1400012A3`, `0xEFCDAB89` @ `0x1400012AA`, `0x98BADCFE` @ `0x1400012B1`,
  `0x10325476` @ `0x1400012B8`, with a second identical init site at `0x14000147B..0x140001490`;
  the class name string in the vftable is `MD5_CTX`).
* **Salt/key = the installation GUID string**, not a random salt:
  * preferred: fetched from the driver (`sub_140025910` — opens `\\.\DpControl`, then VM;
    buffer is **0x88 = 136 bytes**, see §5.1);
  * fallback: `HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID` (REG_SZ, the driver’s
    install GUID; the driver formats/uses it as 16 bytes → 32 hex chars, see the
    `%02x…` format string shared by the whole family).
* **Combination scheme: `MD5( UTF16LE( GUID ++ password ) )`** — the password bytes are
  concatenated *after* the GUID, encoded little-endian UTF-16, then hashed.
* **Storage: `user.dat` → `[common] hash=` = 32 lowercase hex digits.**
* **Empty password sentinel: the literal `"@BLANKPWD"`** — `/xpwd:` with an empty value
  hashes `GUID + "@BLANKPWD"`, so “no password” is a fixed, checkable value rather than a
  special marker.
* `hash2=` in `user.dat` is **not** produced by CmdTool (no reference in this binary) —
  produced by the GUI/service (**UNKNOWN** here, presumably a second-generation/legacy
  digest).
* The **verification** of `/pwd:<OLD>` itself is in the VM region (`0x140003B25`–`0x140003CA0`)
  and prints `Password is not specified or is not correct.` (va `0x140049470`) on failure;
  the exact compare site is **UNKNOWN**, but it must be
  `0 == wcscmp(userdat[common].hash, MD5hex(GUID + old_password))` given the shared helpers
  and Commit’s fully-recovered analogue (§2.4).

### 1.6 Reconstructed C — CmdTool main dispatch

```c
int wmain(void)                       /* @ 0x140003330, args via GetCommandLineW */
{
    int argc; LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    WCHAR pwd[64]  = {0};             /* /pwd:  value, 64 wchars */
    WCHAR data[128]= {0};             /* /data: value, 128 wchars */
    int   now = 0, seen = 0;

    if (!argv) return 1;
    for (int i = 1; i < argc; i++) {
        LPWSTR a = argv[i];
        if (!_wcsnicmp(a, L"/pwd:",  5)) { LPWSTR c=wcschr(a,':'); if(c) wcsncpy_s(pwd ,64,c+1,32); seen=1; }
        else if (!_wcsnicmp(a, L"/data:",6)) { LPWSTR c=wcschr(a,':'); if(c) wcsncpy_s(data,128,c+1,128); seen=1; }
        else if (!_wcsicmp(a, L"/list")     || !_wcsnicmp(a,L"/enter:", 7)
              || !_wcsnicmp(a, L"/exit:",  6) || !_wcsnicmp(a,L"/xpwd:",  6)
              || !_wcsnicmp(a, L"/commit:",8) || !_wcsicmp(a, L"/reboot")
              || !_wcsicmp(a, L"/shutdown")) { seen = 1; }
        else if (!_wcsicmp(a, L"/now"))    { now = 1; seen = 1; }
        /* unknown switches are silently ignored */
    }
    if (!seen) { PrintCmdToolTxt(); return 1; }        /* self-help */

    /* ---- password gate: NOT RECOVERABLE (VM region 0x140003565..0x140003CA0) ----
       observed behaviour: prints "Password is not specified or is not correct."
       and stops; otherwise falls through. */

    for (int i = 1; i < argc; i++) {
        LPWSTR a = argv[i], p;
        /* /enter:  -- letters after ':' are parsed as a set (C..Z / c..z) */
        if (!_wcsnicmp(a, L"/enter:", 7) && (p = wcschr(a, ':'))) {
            while ((WCHAR ch = p[1]) != 0) {
                ++p;
                if (!((ch>='C'&&ch<='Z')||(ch>='c'&&ch<='z'))) continue;
                WCHAR drive = TOUPPER(ch);
                if (drive == g_currentDrive) {
                    WCHAR ini[260];
                    GetShadowDefenderPath(ini);                 /* HKLM\...\Shadow Defender\Path */
                    wcscat_s(ini, 260, L"\\user.dat");
                    if (GetPrivateProfileIntW(L"common", L"hibernation", 0, ini))
                        WmiSetBcdBoolean(1);                    /* sub_140002F20 */
                }
                sub_1400262B0(drive, 3);                        /* request shadow mode */
                DWORD st = 0; sub_140025C80(drive, &st);         /* read back           */
                if (st != 3) { printf(L"Failed to change the status of %c:, error code = %d.\n", drive, GetLastError()); continue; }
                if (!now) { printf(L"Change the status of %c: successfully,\nPlease restart the computer for this to take effect.\n", drive); continue; }
                if (sub_140026F10(drive)) printf(L"Change the status of %c: successfully.\n", drive);
                else { OutputDebugStringW(Sprintf64(L"CmdTool: error code %d\n", GetLastError()));
                       printf(L"Change the status of %c: successfully,\nbut a reboot is required for changes to take effect.\n", drive); }
            }
        }
        else if (!_wcsnicmp(a, L"/exit:", 6) && (p = wcschr(a, ':'))) {
            while ((WCHAR ch = p[1]) != 0) {
                ++p;
                if (!((ch>='C'&&ch<='Z')||(ch>='c'&&ch<='z'))) continue;
                WCHAR drive = TOUPPER(ch);
                sub_1400262B0(drive, 0);
                DWORD st = 1; sub_140025C80(drive, &st);
                if (st != 0) { printf(L"Failed to change the status of %c:, error code = %d.\n", drive, GetLastError()); continue; }
                if (!now) { printf(L"Change the status of %c: successfully,\nPlease restart the computer for this to take effect.\n", drive); continue; }
                if (sub_140027340(drive, 0, 1, 0, 0)) printf(L"Change the status of %c: successfully.\n", drive);
                else { OutputDebugStringW(Sprintf64(L"CmdTool: error code %d\n", GetLastError()));
                       printf(L"Change the status of %c: successfully,\nbut a reboot is required for changes to take effect.\n", drive); }
            }
        }
        else if (!_wcsnicmp(a, L"/xpwd:", 6) && (p = wcschr(a, ':'))) { /* §1.3, fully recovered */ }
        else if (!_wcsnicmp(a, L"/commit:", 8) && (p = wcschr(a, ':'))) { /* §1.3 */ }
        else if (!_wcsicmp(a, L"/list")) { /* C..Z loop, "%c: is in shadow mode.\n" */ }
        else if (!_wcsicmp(a, L"/reboot"))   { ExitWindowsEx(6,    0x30000); }
        else if (!_wcsicmp(a, L"/shutdown")) { ExitWindowsEx(0x0D, 0x30000); }
    }
    return 0;
}
```

### 1.7 Exit codes and output summary (CmdTool)

| Situation | stdout | exit code |
|---|---|---|
| init fails (`sub_14000833C` == 0; effectively unreachable) | `Fatal error: Initialization failed\n` | **1** |
| unknown/absent switch | contents of `CmdTool.txt` | **0** (return value of `sub_140003330` is discarded by `main`) |
| wrong/missing password | `Password is not specified or is not correct.\n` | **0** |
| `/list` hit | `%c: is in shadow mode.\n` | 0 |
| `/enter`,`/exit` ok, no `/now` | `Change the status of %c: successfully,\nPlease restart the computer for this to take effect.\n` | 0 |
| `/enter`,`/exit` ok + `/now` applied | `Change the status of %c: successfully.\n` | 0 |
| ok but not applied | `Change the status of %c: successfully,\nbut a reboot is required for changes to take effect.\n` + `OutputDebugStringW("CmdTool: error code %d\n")` | 0 |
| state change failed | `Failed to change the status of %c:, error code = %d.\n` | 0 |
| `/xpwd:` ok / fail | `Password has been changed successfully.\n` / `Failed to change the password, error code = %d.\n` | 0 |
| `/commit:` | `Commit "%s" successfully.\n` / `Failed to commit "%s", error code = %d.\n` | 0 |
| `/reboot`,`/shutdown` | `System is rebooting...\n` / `System is shutting down...\n` | 0 (system goes down) |

**OBSERVED/IMPORTANT:** CmdTool **does not communicate failures through its exit code** —
`main` returns 0 unconditionally on the normal path. Scripts must parse stdout.
Diagnostics (not stdout): `C:\sdtrace.log` via `sub_140027610`.

---

## 2. Commit.exe — context-menu commit helper

### 2.1 Entry point and CLI

* `start` @ `0x1400378C8` → CRT → MFC `AfxWinMain` → the app object’s `InitInstance`
  override, which is **`sub_140003334` @ `0x140003334`** (size 0x50D; OBSERVED:
  `InitCommonControls(); CWinApp::InitInstance(); AfxEnableControlContainer();` then the
  work, and it **always returns 0**).
* **There is no switch grammar.** Commit does not use `CommandLineToArgvW` (not imported);
  it reads `GetCommandLineW()` and locates the argument by hand (OBSERVED @ `0x140003450`):

```c
LPWSTR cl = GetCommandLineW();
WCHAR  sep = (*cl == L'"') ? L'"' : L' ';
LPWSTR end = wcschr(cl + 1, sep);          /* end of argv[0] */
...
LPWSTR list = end + 2;                     /* skip separator + space */
LPWSTR bar  = wcschr(list, L'|');          /* token separator */
BOOL   hasWildcard = (wcschr(list, L'*') != NULL);
```

⇒ **De-facto grammar: `Commit.exe "<path1>|<path2>|…|<pathN>"`** — one single quoted
argument, `|`-separated, as produced by ShellExt.dll (§3.5). A lone path with no `|` at all
is also accepted (`wcschr` is only used to *find* the end of the list for the tokenizer;
if it is NULL the whole block is skipped) — **INFERRED** from the presence of the
`bar == NULL` branch that jumps straight to the epilogue.

Tokenisation (OBSERVED @ `0x140004178`–`0x1400041A3`):
```c
do { *bar = 0; CStringArray::SetAtGrow(&arr, n, list); *bar = L'|'; list = bar + 1; }
while ((bar = wcschr(bar + 1, L'|')) != NULL);
```

### 2.2 Behaviour

1. `sub_1400031D0(&userdat)` builds `%Path%\user.dat` (`Path` from
   `HKLM\SOFTWARE\Shadow Defender`, else the module directory), with the
   `sub_140039050`-based redirection fix-up if the volume is shadowed.
2. `[common] shellext` (default 1) is read from `user.dat` — see §0.4.
3. If `shellext == 2` → password gate (§2.4).
4. Dialog 1: `sub_140005B9C(&dlg, 0)` then `DoModal()` — a confirmation dialog; on OK:
   tokenise the list into a `CStringArray`, then
   `CreateThread(NULL, 0, StartAddress /*0x140004670*/, &params, 4 /*STACK_SIZE_PARAM_IS_A_RESERVATION*/, NULL)`,
   then dialog 2 `sub_140004F14(&dlg2, 0)` (progress) is shown with the thread handle in the
   dialog object (`*(dlg2+8) = thread`), `CloseHandle(thread)` after `DoModal`.
5. Dialog 1 receives `hasWildcard` (any `*` in the list) in its ctor, so the pre-flight dialog
   wording depends on whether directory wildcards are present.

**Worker thread `StartAddress` @ `0x140004670` (plaintext, 0x3D8 bytes)** — per path:
```c
TrimRight/TrimLeft(path);
if (wcschr(path, L'*'))                        /* "C:\dir\*.*"  -> use the directory */
    path = Left(path, wcsrchr(path, L'\\') - path);
if (PathIsDirectory(path)) sub_1400023F0(path, vol, &size); else sub_140002388(path, &size);
...
/* second pass */
sub_140039050(path[0], &volinfo);               /* must be in shadow mode, else skip  */
if (wcschr(path, L'*') && PathFileExistsW(dir_of_path))
    { sub_140038E20(dir, buf, &cb); sub_1400020D0(buf); }
sub_140003E0C(&params, path, volinfo);          /* the recursive commit worker         */
```
`sub_140003E0C` (0x864 bytes, recursive) does the actual copy of shadow-area data back to the
real volume, using the shared helpers (`FindFirstFileExW`-style enumeration, `%s\*`,
`%s\%s`, `\\.\%s%x\`, `%c:\%s`, `diskpt0.sys`). Its per-file device I/O is in the VM region
(**UNKNOWN** codes).

### 2.3 IPC of Commit.exe

* `\\.\DpControl` — same access pattern as CmdTool (`CreateFileW(L"\\\\.\\DpControl", 0x80, 3,
  NULL, 3, 0x80, NULL)`) inside the **shared** helpers `sub_1400389B0` / `sub_140038AC0`
  (lock/unlock, `0x1400389DE` / `0x140038AEE`), `sub_140038BD0` (GUID, `0x140038D15`),
  `sub_140038CE0` (volume key, `0x140038CE0`), `sub_1400394B0` (`0x1400394E3`).
  **The `DeviceIoControl` calls are VM bodies** ⇒ codes **UNKNOWN**.
* `\\.\X:` volumes (`sub_1400256A0`-equivalent `sub_140039620`/`sub_140038E20`), the per-volume
  state file `X:\diskpt0.sys` and the shadow-area GUID are shared with CmdTool (§0.4).
* **No `DeviceIoControl` import at all** in the import table (OBSERVED — `Commit.exe`
  `imports.txt` has `CreateFileW` but not `DeviceIoControl`) ⇒ Commit never calls
  `DeviceIoControl` from plaintext code; all device I/O is resolved dynamically inside the VM
  body (the VM can `GetProcAddress` or use a fixed-up pointer table entry).
* `ShellExecuteW` is imported (used by the MFC shell helpers and by `ShellExt.dll`).

### 2.4 Password handling (Commit) — the fully recovered check

`sub_140003334` (plaintext, OBSERVED @ `0x140003431`–`0x1400034F5`):

```c
if (shellext_mode == 2) {
    WCHAR stored[128];
    GetPrivateProfileStringW(L"common", L"hash",
                             L"00000000000000000000000000000000",   /* foff 0x50290 */
                             stored, 128, userdat);
    WCHAR key[512] = {0};
    CString s;
    if (sub_140038CE0(key) != 0                                    /* driver key (VM body) */
        || SHGetValueW(HKEY_LOCAL_MACHINE,
                       L"SYSTEM\\CurrentControlSet\\Services\\diskpt", L"GUID",
                       &type, key, &cb = 512) == ERROR_SUCCESS) {
        wcscat_s(key, 0x100, L"@BLANKPWD");                       /* foff 0x502e8 */
        s.SetString(key, 2*wcslen(key));
        sub_14000142C(&s, digest16);                              /* MD5                  */
        swprintf(hex, L"%02x%02x%02x%02x%02x%02x%02x%02x"
                       L"%02x%02x%02x%02x%02x%02x%02x%02x", digest16[0..15]);
        if (wcscmp(hex, stored) == 0) goto proceed;               /* blank password  OK    */
    }
    /* password set or key unavailable */
    if (sub_140005494(&pwdDlg, 0) /* ctor */ && CDialog::DoModal(&pwdDlg) == 1
        && *((BYTE*)app + 388) != 0)
        goto proceed;
    /* else fall through: nothing is committed */
}
proceed:
```
Key facts:

* **Same algorithm and same salt as CmdTool**: `MD5( UTF16LE( GUID ++ password ) )`
  hex-encoded — the constant `"00000000000000000000000000000000"` is the *default* value read
  when `[common] hash` is missing, i.e. “unset”.
* `Commit.exe` proves that the **blank-password digest is `MD5(GUID + "@BLANKPWD")`**: it
  computes exactly that and compares it to the stored `hash`. If equal, no password is set and
  Commit proceeds silently. If not equal, it must *ask*.
* The ask-dialog’s validator is `sub_140005654` @ `0x140005654`: it re-reads `[common] hash`
  (same default) and then calls the **VM body** `sub_1400D86E8` — so the final
  `hash(typed_password) == stored` comparison is virtualised (**UNKNOWN** site; the algorithm
  is known).
* MD5 evidence: identical constants at `0x140001304/0x14000130F/0x140001316/0x14000131D`
  and `0x1400014CD/0x1400014D4/0x1400014DB/0x1400014E2` (OBSERVED).
* `res.ini [common] 1014/1015` are read by the GUI helpers, not here.

### 2.5 Exit codes and output (Commit)

* Commit is a GUI app: no stdout/stderr output at all (no `printf` family usage for user
  messages); all feedback is through MFC dialogs.
* `InitInstance` (`sub_140003334`) always returns 0 ⇒ `AfxWinMain` takes the
  “InitInstance failed” path and exits with `ExitInstance()`’s value (normally **0**).
  ⇒ **exit code 0 / UNKNOWN non-zero codes.** No documented status codes.
* Diagnostics: `C:\sdtrace.log` through the shared `sub_140027610`-equivalent
  (`sub_140003170`+`OutputDebugStringW` also present).

---

## 3. ShellExt.dll — Explorer context-menu extension

### 3.1 Exports (OBSERVED, `ShellExt/exports.txt`)

| Export | Address | Note |
|---|---|---|
| `DllCanUnloadNow` | `0x180006FD0` | `(*((CAtlModule*)&qword_18002A1A0))->GetLockCount() != 0` |
| `DllGetClassObject` | `0x180007000` | ATL class-factory lookup over the class table `qword_18002A210..qword_18002A218` |
| `DllRegisterServer` | `0x180007240` | registers AppID + all classes (RGS resource **102**) + typelib |
| `DllUnregisterServer` | `0x180007350` | unregisters classes + AppID |
| **`SetWorkMode`** | `0x1800073F0` | `void SetWorkMode(int)` → `dword_18002A190 = a1` (**extra, non-standard export**) |
| `DllEntryPoint` | `0x1800082C0` | |

`DllMain` @ `0x180007160` (OBSERVED): on `DLL_PROCESS_DETACH` (`fdwReason == 2`) it does
`if (dword_18002A190 != 0 && LoadLibraryW(L"ntdll.dll")) return sub_180062591();` — i.e.
**`SetWorkMode(1)` arms a hidden (VM) unload hook that runs `ntdll`-assisted cleanup** when
Explorer unloads the DLL. **INFERRED:** used by the installer/main UI to enable a
teardown/unhook path; `SetWorkMode(0)` disarms it.

### 3.2 COM registration data extracted from the binary

The ATL RGS scripts live in `.rsrc` as custom resource type **`REGISTRY`**:

* **ID 101** (73 bytes):
  ```
  HKCR { NoRemove AppID { '%APPID%' = s 'DefenderShellExt' } }
  ```
* **ID 102** (1302 bytes) — full reconstruction:
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
* **ID 101 vs. the AppID passed by code:** `DllRegisterServer` calls
  `sub_1800052F0(module, 0x65 /*=101*/, 1, {L"APPID", L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}"})`
  — `%APPID%` = **`{FF2EA936-C1E1-428D-9572-F4285AFC4F48}`** (OBSERVED at `0x180007270`).
  `sub_180001420(mode)` (referenced from the class table at `0x18001ab48`) calls
  `sub_1800052F0(module, 102, mode)` — the class RGS.
  `DllUnregisterServer` repeats both with the “unregister” flag.

**Resulting registry surface (exact):**

| Key | Value |
|---|---|
| `HKCR\AppID\{FF2EA936-C1E1-428D-9572-F4285AFC4F48}` | default = `DefenderShellExt` |
| `HKCR\DefenderShellExt.ContextMenuExt.1` | default = `DefenderContextMenuExt Class`; `CLSID = {5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` |
| `HKCR\DefenderShellExt.ContextMenuExt` | same + `CurVer = DefenderShellExt.ContextMenuExt.1` |
| `HKCR\CLSID\{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` | `DefenderContextMenuExt Class`, `ProgID`, `VersionIndependentProgID`, `InprocServer32 = <dll path>`, `ThreadingModel = Apartment`, `AppID = {FF2EA936-…}`, `TypeLib = {3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}` |
| `HKCR\*\shellex\ContextMenuHandlers\DefenderContextMenuExt` | `{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` |
| `HKCR\Directory\shellex\ContextMenuHandlers\DefenderContextMenuExt` | same |
| `HKCR\Drive\shellex\ContextMenuHandlers\DefenderContextMenuExt` | same |
| TypeLib `{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}` | registered from `TYPELIB/1` resource via `RegisterTypeLib`/`RegisterTypeLibForUser` (`sub_180006D70`) |

The embedded application manifest requests **`asInvoker`** (OBSERVED, `ID=24/ID=2` resource).

### 3.3 COM class, interfaces and vtable (OBSERVED)

Class table entry (`.data` @ `0x18001AB40`) → class record:

```
0x18001AB40: +0x00 → 0x18001AB80  (CLSID  = {5EE8E9E6-2853-4D28-B2DE-6529EDA0A294})
             +0x08 → 0x180001420  (pfnUpdateRegistry → RGS 102)
             +0x10 → 0x180001CF0  (pfnGetClassObject / CreateInstance)
             +0x18 → 0x180001E60  (pfnCreateInstance)
             +0x20 → 0x18002A160  (cached class-factory pointer)
```
`DllGetClassObject` (0x180007000) compares `rclsid` against that CLSID, lazily creates the
factory under `CriticalSection` with creator IID `unk_18001B5C0 = IID_IUnknown
{00000000-0000-0000-C000-000000000046}`, stores it with `EncodePointer`, and returns
`E_NOINTERFACE` (`0x80040111` / -2147221231) when nothing matched.

**COM interface map — the *real* one, `.rdata` @ `0x18001AAE0`** (`_ATL_INTMAP_ENTRY`
`{piid, dw, pFunc}`, used by `sub_180002020` @ `0x180002020 = "sub rcx,…; jmp
CComObjectRootEx::InternalQueryInterface"`):

| # | IID | object offset | kind |
|---|---|---|---|
| 0 | **`{A36985CB-46CB-43FD-805E-DC8871233CE9}`** (private interface) | `0x00` | offset |
| 1 | **`{000214E8-0000-0000-C000-000000000046}`** = `IID_IShellExtInit` | `0x08` | offset |
| 2 | **`{000214E4-0000-0000-C000-000000000046}`** = `IID_IContextMenu` | `0x10` | offset |
| 3 | terminator `{NULL,0,0}` | — | — |

The class-factory object has its own map (`.rdata` @ `0x18001A548`, single entry
`{00000001-0000-0000-C000-000000000046}` = **`IID_IClassFactory`**, offset 0) used by
`sub_180001F10`; the factory’s `IClassFactory::CreateInstance`
(`sub_180001250` @ `0x180001250`, guard returns `CLASS_E_NOAGGREGATION` `0x80040110`)
forwards to `*(this+0x40)`.

**Object layout and vtable @ `0x18001AB98`** (OBSERVED, pointers found by scanning `.rdata`):

| Slot | Target | Meaning |
|---|---|---|
| `+0x00` `0x18001AB98` | `0x180001F10` | `QueryInterface` (class-factory map) |
| `+0x08` | `0x180001E90` | `AddRef` (`[this+0x18]++`) |
| `+0x10` | `0x180001EC0` | `Release` |
| `+0x18` `0x…ABB0` | `0x180001250` | ATL helper |
| `+0x20` | `0x1800012B0` | `_pAtlModule->Lock/Unlock(bool)` |
| `+0x28` | `0x180001F30` | `CComObjectCached` dtor/helper |
| `+0x38` `0x…ABD0` | **`0x180002020`** | `QueryInterface` (real map `0x18001AAE0`) |
| `+0x60` `0x18001ABF8` | `0x180001200/120C/1218/**0x180001440**` | **`IShellExtInit`** sub-vtable: QI/AddRef/Release adjust `rcx` by −8 then jump to the primary helpers; `Initialize` |
| `+0x80` `0x18001AC18` | …`0x180001224/1230/123C/**0x180001AA0**/**0x1800018E0**/**0x1800016E0**` | **`IContextMenu`** sub-vtable (adjusts `rcx` by −0x10): `QueryContextMenu`, `InvokeCommand`, `GetCommandString` |

`m_dwRef`/`m_dwRef`-equivalent lives at **object + 0x18** (OBSERVED in the AddRef/Release
thunks `sub_180001FB0`/`sub_180001FC0`). The class also has a `std::list<std::wstring>`
member (`+0x10`/`+0x18`/`+0x20`) holding the selected paths, and an `HBITMAP` at `+1104`
(`a1+1104`, used for the menu bitmap).

### 3.4 The COM methods (OBSERVED, fully plaintext)

**`IShellExtInit::Initialize` — `sub_180001440` @ `0x180001440` (0x29B)**
```c
HRESULT Initialize(LPCITEMIDLIST pidlFolder, IDataObject *pdtobj, HKEY hkeyProgID)
{
    STGMEDIUM stg = { .tymed = TYMED_HGLOBAL };
    FORMATETC fmt = { .cfFormat = CF_HDROP /*15*/, .ptd = NULL, .dwAspect = 1,
                      .lindex = -1, .tymed = TYMED_HGLOBAL };
    if (pdtobj->GetData(&fmt, &stg) < 0) return E_INVALIDARG;      /* 0x80070057 */
    HDROP hdrop = GlobalLock(stg.hGlobal);
    if (!hdrop) return E_INVALIDARG;
    UINT n = DragQueryFileW(hdrop, 0xFFFFFFFF, NULL, 0);           /* file count */
    if (n - 1 > 0x63)                                             /* 1..100 files */
        { GlobalUnlock; ReleaseStgMedium; return E_INVALIDARG; }
    paths.clear();                                                /* sub_1800058D0 */
    for (UINT i = 0; i < n; i++) {
        UINT len = DragQueryFileW(hdrop, i, NULL, 0);
        wchar_t *p = new wchar_t[len + 8];
        if (DragQueryFileW(hdrop, i, p, len + 1)) {
            if (GetFileAttributesW(p) & FILE_ATTRIBUTE_DIRECTORY)  /* 0x10 */
                wcscat_s(p, len + 8, L"\\*.*");                    /* directory wildcard */
            paths.push_back(std::wstring(p));                  /* list node alloc */
        }
    }
    GlobalUnlock(stg.hGlobal); ReleaseStgMedium(&stg);
    return S_OK;
}
```
⇒ **directories are stored with a trailing `\*.*`** — this is what produces the `*` that
Commit’s `hasWildcard` flag and `StartAddress` wildcard handling observe.

**`IContextMenu::QueryContextMenu` — `sub_180001AA0` @ `0x180001AA0` (0x247)**
```c
HRESULT QueryContextMenu(HMENU hmenu, UINT indexMenu, UINT idCmdFirst,
                         UINT idCmdLast, UINT uFlags)
{
    if (uFlags & CMF_DEFAULTONLY /*1*/) return 0;
    /* install dir */
    if (SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path",
                    &type, dir, &cb = 520) != 0) {
        GetModuleFileNameW(hInst, dir, 260);
        *wcsrchr(dir, L'\\') = 0;
    }
    swprintf(userdat, L"%s\\user.dat", dir);
    if (GetPrivateProfileIntW(L"common", L"shellext", 1, userdat) == 0)
        return 0;                                        /* menu item suppressed */

    /* drive bitmask of the selection */
    DWORD mask = 0;
    for (auto &s : paths) { WCHAR c = Lower(s[0]); mask |= 1 << (c - L'c'); }

    /* only show the item if at least one selected drive is a real volume
       AND is currently in shadow mode */
    for (WCHAR d = L'C'; d <= L'Z'; d++) {
        BYTE st[8];
        if (!(mask & (1 << (d - L'C')))) continue;
        if (sub_180008D00(d, st) == 0) continue;              /* volume candidate */
        if (*(DWORD*)(st + 4) != 1) continue;                 /* not shadowed */
        swprintf(ini, L"%s\\res.ini", dir);
        GetPrivateProfileStringW(L"common", L"1014", &def, text, 0x1000, ini);
        InsertMenuW(hmenu, indexMenu, MF_BYPOSITION /*0x400*/, idCmdFirst, text);
        if (hBitmap) SetMenuItemBitmaps(hmenu, indexMenu, MF_BYPOSITION /*0x404*/, hBitmap, NULL);
        return 1;                                             /* one item added */
    }
    return 0;
}
```
* **Verb/menu text is localised via `res.ini [common] 1014`** (numeric key). The menu command
  **ID = `idCmdFirst`** (Explorer’s first free ID) — i.e. the handler does not use a private
  verb ID.
* The item is only offered when the target is on a **shadowed volume**.

**`IContextMenu::GetCommandString` — `sub_1800016E0` @ `0x1800016E0` (0x1F3)**
```c
if ((uFlags & (GCS_HELPTEXTW|GCS_VERBW|GCS_VALIDATEW)) == 0) return E_INVALIDARG;  /* a3&5 */
... read HKLM\SOFTWARE\Shadow Defender\Path (or module dir) -> dir
wcscat_s(dir, 260, L"\\res.ini");
GetPrivateProfileStringW(L"common", L"1015", &def, buf, 0x1000, dir);
if (uFlags & GCS_UNICODE /*4*/) lstrcpynW(psz, buf, cchMax);
else { WideCharToMultiByte(CP_ACP /*3*/, ...); lstrcpynA(psz, ansi, cchMax); }
return S_OK;
```
* **Help/verb text comes from `res.ini [common] 1015`.**
* `res.ini` is resolved relative to `HKLM\SOFTWARE\Shadow Defender\Path` (fallback: the DLL’s
  own directory) — same rule as everywhere else.

**`IContextMenu::InvokeCommand` — `sub_1800018E0` @ `0x1800018E0` (0x1B2)`** — this is the
**exact Commit.exe command line**:

```c
HRESULT InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
    if (*(WORD*)(pici+16) != 0 || *(WORD*)(pici+18) != 0)   /* lpVerb must be NULL/default */
        return E_INVALIDARG;

    size_t total = 0;
    for (auto &s : paths) total += s.length() + 1;          /* sum of lengths */

    WCHAR exe[260];
    GetModuleFileNameW(hModule, exe, 260);
    wchar_t *bs = wcsrchr(exe, L'\\');
    if (!bs) return 0;
    bs[1] = 0;                                              /* keep "<dir>\" */
    wcscat_s(exe, 260, L"Commit.exe");                      /* aCommitExe, foff 0x… */

    wchar_t *args = new wchar_t[total + 10];
    args[0] = 0;
    for (auto &s : paths) { wcscat_s(args, total+10, s.c_str());
                            wcscat_s(args, total+10, L"|"); }

    ShellExecuteW(NULL, L"open", exe, args, NULL, SW_SHOW /*5*/);
    delete[] args;
    return S_OK;
}
```

⇒ **Exact invocation:**
```
"<dir of ShellExt.dll>\Commit.exe"  "<path1>|<path2>|…|<pathN>|"
```
(one quoted argument, `|`-joined, with a **trailing `|`**; the working directory is not set
(`lpDirectory = NULL`); the verb shown to Explorer is the localised `res.ini` text; the class
is registered for `*`, `Directory` and `Drive`.)

### 3.5 Other ShellExt facts

* Imports include `LoadLibraryA/W`, `LoadLibraryExW`, `GetProcAddress`, `VirtualProtect`,
  `VirtualQuery`, `GetSystemInfo` — used by the hidden/VM loader and by the ATL module; and
  `DragQueryFileW`, `ShellExecuteW`, `InsertMenuW`, `SetMenuItemBitmaps`, `LoadImageW`,
  `GetIconInfo`, `DrawIconEx`, `CreateDIBSection`, `BeginBufferedPaint`, `UxTheme` for the
  menu icon (the `HBITMAP` at object `+1104`) and the ATL `CComClassFactory`/typelib helpers.
* `SetWorkMode` is the only exported function besides the four COM/self-registration entry
  points and `DllEntryPoint` (**OBSERVED**). Its only consumer is `DllMain` (§3.1).
* Diagnostics: `C:\sdtrace.log` (shared `sub_180…` logger).
* `ShellExt.dll` carries **no** other GUID registrations. The extra CLSID
  `{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (with a `CLSID\` prefix) appears in
  **Defender.exe** and in **Uninstall.exe** (OBSERVED text at `Defender.exe` foff `0x8411E`
  and `Uninstall.exe` foff `0x4651E`, next to the shared SdApi strings) — **INFERRED:**
  a second COM class registered by the main GUI; it is *not* served by ShellExt.dll. Exact
  role **UNKNOWN**.

---

## 4. Uninstall.exe

### 4.1 Entry point, command line, guards

* `start` @ `0x140022A8C` → CRT → MFC dialog application. **There is no application-specific
  command line**: the only `GetCommandLineW` call in the whole binary is MFC’s
  (`all_disasm` `0x140029C0D`), and there is no switch string table. ⇒ **grammar: none
  (GUI wizard only)**, invoked by the `UninstallString` under
  `HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}`.
* Pre-flight guard `sub_140002B18` @ `0x140002B18` (OBSERVED):
```c
for (WCHAR d = L'C'; d <= L'Z'; d++)
    if (IsRealVolume(d) && QueryVolumeShadowState(d, &st) && st == 1) {
        MessageBoxW(NULL, L"Please uninstall when your OS is not in Shadow Mode.",
                    L"Setup - Shadow Defender", MB_ICONINFORMATION /*0x40*/);
        return 0;
    }
HANDLE m = CreateMutexW(NULL, FALSE, L"Global\\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}");
if (m && GetLastError() == ERROR_ALREADY_EXISTS /*183*/) { CloseHandle(m);
    MessageBoxW(NULL, L"Please close Shadow Defender main interface.",
                L"Setup - Shadow Defender", 0x40); return 0; }
CloseHandle(m);
HWND w = FindWindowW(NULL, L"Shadow Defender Daemon Window");
SendMessageW(w, 0x47B /*WM_USER+0x7B*/, 0, 0);       /* tell the daemon we are uninstalling */
return 1;
```
* Files replaced during uninstall are pre-marked for delete-on-reboot
  (`MoveFileExW(..., NULL, MOVEFILE_DELAY_UNTIL_REBOOT = 4)`); `IsRealVolume` is the same
  FAT/FAT16/FAT32/EXFAT/NTFS + `GetVolumeNameForVolumeMountPointW` check used everywhere
  (`sub_1400014B4` @ `0x1400014B4`).

### 4.2 Exact order of operations

Worker: `StartAddress` @ `0x1400027DC` (thread) → **`sub_140001A34` @ `0x140001A34`**
(0xDA8 bytes, plaintext). Progress is reported with `SendMessageW(hwnd, 0x402, <percent>, 0)`
and `SetWindowTextW(hwndStatus, <stage text>)`.

| # | Stage text | Action (OBSERVED) |
|---|---|---|
| 0 | — | `SendMessageW(progress, 0x402, 0, 0)` |
| 1 | `Remove registry information...` | For every real volume `C..Z`: `MoveFileExW(L"<d>:\\diskpt0.sys", NULL, MOVEFILE_DELAY_UNTIL_REBOOT)` (delete per-volume shadow **state files** at reboot) |
| 2 | — | Resolve install dir (`HKLM\SOFTWARE\Shadow Defender\Path`, else module dir) → `\shellext.dll`; `LoadLibraryW` + `GetProcAddress("DllUnregisterServer")` + call it + `FreeLibrary` (removes `HKCR\CLSID\{5EE8E9E6-…}`, `HKCR\*\shellex…`, AppID, TypeLib) |
| 3 | — | Remove filter-driver load points (helper `sub_140001820` = remove a multi-string element): `HKLM\SYSTEM\CurrentControlSet\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}\UpperFilters` − `diskpt`; `HKLM\SYSTEM\CurrentControlSet\Control\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}\LowerFilters` − `diskpt`; `HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\BootExecute` − `dpstart` |
| 4 | — | **If** both `UpperFilters` and `LowerFilters` no longer contain `diskpt` (`sub_1400016CC`): `SetFileAttributesW(%SystemRoot%\drivers\diskpt.sys, NORMAL)`; `DeleteFileW(%SystemRoot%\drivers\diskpt.sys)`; `SHDeleteKeyW(HKLM, "SYSTEM\\CurrentControlSet\\Services\\diskpt")` |
| 5 | — | `SHDeleteKeyW(HKLM, "Software\\Shadow Defender")`; `SHDeleteKeyW(HKCR, "CLSID\\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}")` |
| 6 | — | **If** `BootExecute` no longer contains `dpstart`: delete `%SystemRoot%\dpstart.exe` |
| 7 | — | `CreateProcessW(NULL, L"\"<install dir>\\Service.exe\" /Uninstall", …, STARTUPINFO{cb=104, dwFlags=STARTF_USESHOWWINDOW, wShowWindow=SW_HIDE}, …)` and `WaitForSingleObject(INFINITE)` — service stop + service unregistration |
| 8 | `Deleting shortcuts...` | progress 0x14; delete `<common start menu>\<StartMenuFolder>\Shadow Defender.lnk`, `…\Help.lnk`, `…\Uninstall Shadow Defender.lnk` (StartMenuFolder from `HKLM\…\Uninstall\{93A07A0D-…}\StartMenuFolder`, default `Shadow Defender`), then remove now-empty directories upward; delete `<common desktop>\Shadow Defender.lnk`; delete `%APPDATA%\Microsoft\Internet Explorer\Quick Launch\Shadow Defender.lnk` |
| 9 | `Deleting files...` | progress 0x28; from the Windows directory: `\diskpt.dat`, `\diskpt.crt`, `\diskpt0.dat`; from the install directory: `\Defender.exe`, `\DefenderDaemon.exe`, `\Commit.exe`, `\CmdTool.exe`, `\CmdTool.txt`, `\eula.rtf`, `\Help.chm`, `\res.ini`, `\user.dat`, `\Uninstall.exe`; **`\ShellExt.dll`** and **`\Service.exe`** are renamed to `*.del`, the copy is deleted, then `MoveFileExW(*.del, NULL, MOVEFILE_DELAY_UNTIL_REBOOT)`; finally `MoveFileExW(<install dir>, NULL, 4)` (delete the directory at reboot) |
| 10 | `Deregistering production information...` | progress 0x50; `SHDeleteKeyW(HKLM, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}")`; progress 0x64 |

**Summary of what Uninstall removes**

* **Services**: none directly — it delegates to `"<dir>\Service.exe" /Uninstall` (which owns
  service `{0CBD4F48-3751-475D-BE88-4F271385B672}`, including its
  `SafeBoot\Minimal|Network\{0CBD4F48-…}` subkeys — see `Service.exe` strings).
* **Driver**: `%SystemRoot%\drivers\diskpt.sys` + `HKLM\SYSTEM\CurrentControlSet\Services\diskpt`,
  but only after the filter hooks are gone; plus the boot driver `%SystemRoot%\dpstart.exe`
  and its `BootExecute` entry.
* **Filter registrations**: DiskDrive-class `UpperFilters`, Volume-class `LowerFilters`,
  `Session Manager\BootExecute`.
* **Registry keys**: `HKLM\Software\Shadow Defender`; `HKCR\CLSID\{78C3F4BC-…}`;
  `HKLM\…\Uninstall\{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}`; plus everything ShellExt’s
  `DllUnregisterServer` removes.
* **Per-volume state**: `<d>:\diskpt0.sys` on every real volume (delete-on-reboot). The
  shadow **area directory** `{0D9DB60E-…}` is **not** referenced here (INFERRED: removed by
  `Service.exe /Uninstall`, which has the `sub_1400016A0` remover for it).
* **Shortcuts**: 5 `.lnk` files (common start menu ×3, common desktop ×1, user Quick Launch ×1).
* **Files**: 15 named files (3 in `%SystemRoot%`: `diskpt.dat`, `diskpt.crt`, `diskpt0.dat`;
  12 in the install dir) + `dpstart.exe` + `%SystemRoot%\drivers\diskpt.sys` + `.del`
  staging + directory removal at reboot.
* **Run entries**: none observed (no `…\CurrentVersion\Run` reference in this binary;
  the autostart is the service + `BootExecute`). ⇒ **UNKNOWN/negative**: no Run entry is
  deleted, so no Run entry is likely used.

### 4.3 Exit codes / output (Uninstall)

* MFC wizard; UI text comes from the string table / dialogs:
  `Uninstall - <PRODUCT>`, `Uninstalling`,
  `Please wait while <PRODUCT> <VERSION> is being uninstalled.`,
  `<PRODUCT> <VERSION> Uninstall`, `was successfully removed from your computer.`,
  `To complete the uninstallation of <PRODUCT> <VERSION>, your computer must be restarted.`,
  `Setup - Shadow Defender` (message boxes). No `printf`/console output.
* On completion the worker sets `dword_14005D080 = 1` and posts
  `PostMessageW(ownerWnd, *(DWORD*)(threadParam+24), 1, 0)` to the wizard.
* **Exit codes: none documented/observable** (typical MFC `ExitInstance()` → 0). The reboot
  prompt is UI-level, and the actual files are removed at next boot via
  `MOVEFILE_DELAY_UNTIL_REBOOT`.

---

## 5. Driver IPC cross-reference (Service.exe / diskpt.sys)

### 5.1 The 136-byte "dkpt" message (OBSERVED in Service.exe)

`Service.exe` is the only tool whose driver calls are plaintext:

```c
/* Service.exe HandlerProc @ 0x140001470, SERVICE_CONTROL_* / device-notification path */
BYTE msg[136] = {0};
*(DWORD*)msg = 0x74706B64;                       /* "dkpt" little-endian: 'd','k','p','t' */
h = CreateFileW(L"\\\\.\\DpControl", 0x80, 3, NULL, 3, 0x80, NULL);
DeviceIoControl(h, 0x80000D18, msg, 0x88, msg, 0x88, &ret, NULL);   /* in == out buffer */

/* per-volume, Service.exe sub_1400018A0 @ 0x1400018A0 */
swprintf(dev, L"\\\\.\\%C:", drive);
swprintf(dir, L"%s\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}", dev);   /* shadow area */
sub_1400016A0(dir);                                                  /* create/remove dir */
h = CreateFileW(dev, GENERIC_READ, 3, NULL, 3, 0, NULL);
DeviceIoControl(h, 0x80002D48, msg, 0x88, msg, 0x88, &ret, NULL);
if (failed && GetLastError() != 0x20000001)
    DeleteFileW(L"<dev>\\diskpt0.sys");
```

Reconstructed request/response block (**OBSERVED layout**; the *field semantics* beyond the
magic are **UNKNOWN** because the driver's handler is VM-obfuscated):

```c
#define DP_MSG_MAGIC  0x74706B64u          /* 'd','k','p','t' — also the driver's pool tag */
#define DP_MSG_SIZE   0x88                 /* 136 */

typedef struct _DP_MSG {                   /* in == out, METHOD_BUFFERED, 136 bytes */
    DWORD  Magic;                          /* 0x00  must be DP_MSG_MAGIC */
    BYTE   Payload[132];                   /* 0x04  request/response body (UNKNOWN shape) */
} DP_MSG;

#define IOCTL_DP_CONTROL   0x80000D18u     /* \\.\DpControl  — CTL_CODE(0x8000, 0x346, BUFFERED, 0) */
#define IOCTL_DP_VOLUME    0x80002D48u     /* \\.\X:         — CTL_CODE(0x8000, 0xB52, BUFFERED, 0) */
```

* Both codes use DeviceType **`0x8000`** (FILE_DEVICE_UNKNOWN-range, vendor), METHOD_BUFFERED,
  access 0, input length == output length == `0x88`.
* `0x74706B64` is *also* the driver's `ExAllocatePoolWithTag` tag (OBSERVED at 0x2800517BC,
  0x280051867, … more than 20 sites in `diskpt.sys`), i.e. the message signature and the pool
  tag are deliberately the same 4 bytes.
* `0x20000001` (`STATUS_WAIT_1`/“already in that state” style) is specifically tolerated by
  `Service.exe` and does not trigger the fallback state-file removal.

**`CmdTool.exe` uses the same 136-byte size:** `sub_140025910` (the “get installation key”
helper used for the password salt) opens `\\.\DpControl` and then calls the VM body with a
`0x88`-byte zeroed buffer (`_BYTE v1[136]`) — **strong evidence the same `DP_MSG` block is
the request format for all tools** (OBSERVED buffer size, INFERRED interpretation).

### 5.2 Driver internals (context)

* `diskpt.sys` pool tag `Dkpt`/`0x74706B64`; device types/objects: `\\.\DpControl` (control
  device) and `\\.\DpShadow<n>` (per-volume filter instances, from CmdTool’s
  `L"\\\\.\\%s%x"` + `L"DpShadow"`).
* Driver dispatch is `IRP_MJ_DEVICE_CONTROL` (MajorFunction `0x0E`) →
  `sub_2800533FC` @ `0x2800533FC`, which is a **pure trampoline into the VM region**
  (`return sub_2800B7DE9();`), i.e. the whole IOCTL dispatch table is virtualised.
* `diskpt.sys` also exposes `FltDeviceIoControl` calls for `IOCTL_DISK_GET_DRIVE_GEOMETRY` /
  `IOCTL_DISK_GET_PARTITION_INFO` (`all_pseudocode` lines ~1971/1997) and a
  `ZwDeviceIoControlFile` pair (lines ~8663/8726) — i.e. the driver performs the *same*
  device probes CmdTool does in `sub_140026330`.
* Driver strings/log lines use the `diskpt!StorInitializeVolumeContext: …` prefix.

⇒ **The complete IOCTL/structure protocol between the tools and the driver is NOT statically
recoverable** beyond `DP_MSG` above: it exists only as VM bytecode (opaque constants
XOR/OR/ADDed into the VM context). Recovering it requires either (a) emulating/decrypting the
VM bytecode, or (b) dynamic tracing of `DeviceIoControl` with the driver loaded.

---

## 6. Quick reference

### 6.1 CLSIDs / IIDs / GUIDs

| GUID | Value | Where |
|---|---|---|
| ShellExt CLSID | `{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}` | ShellExt RGS 102, class table `0x18001AB80` |
| ShellExt AppID | `{FF2EA936-C1E1-428D-9572-F4285AFC4F48}` | ShellExt `DllRegisterServer` 0x180007270, RGS 101 |
| ShellExt TypeLib | `{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}` | ShellExt `.rdata` `0x18001B758`, `TYPELIB` resource |
| Private interface of `DefenderContextMenuExt` | `{A36985CB-46CB-43FD-805E-DC8871233CE9}` | ShellExt COM map `0x18001AAE0[0]` |
| `IID_IShellExtInit` | `{000214E8-0000-0000-C000-000000000046}` | ShellExt COM map `[1]` |
| `IID_IContextMenu` | `{000214E4-0000-0000-C000-000000000046}` | ShellExt COM map `[2]` |
| `IID_IClassFactory` | `{00000001-0000-0000-C000-000000000046}` | ShellExt factory map `0x18001A548[0]` |
| `IID_IUnknown` | `{00000000-0000-0000-C000-000000000046}` | ShellExt creator IID `0x18001B5C0` |
| Extra CLSID deleted by uninstall | `{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` | Uninstall `SHDeleteKeyW(HKCR, "CLSID\\…")`; text also in Defender.exe |
| Service | `{0CBD4F48-3751-475D-BE88-4F271385B672}` | Service.exe (out of scope here) |
| Installer uninstall key | `{93A07A0D-454E-43d1-86A9-5DE9C5F4411A}` | Uninstall.exe |
| Installer mutex | `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | Uninstall.exe |
| Shadow area (volume) | `{0D9DB60E-B0EA-4d53-A392-A5D274956846}` | Service.exe `sub_1400018A0`; established context |
| Shared memory | `Global\ShadowDefenderSharedMemory` (4096 B) | CmdTool `sub_140027340` |

### 6.2 Devices / files / messages

| Item | Value |
|---|---|
| Control device | `\\.\DpControl` (open: `0x80` access, share 3, OPEN_EXISTING, flags `0x80`) |
| Per-volume filter device | `\\.\DpShadow<hex>` |
| Volume device | `\\.\X:` (`\\.\ :` template + `wcschr`), `<d>:\` for FSCTL paths |
| Accessible volume | `X:\diskpt0.sys` (hidden+system+write-through, NTFS-compressed; `%s.bak`, `%s.bak.%03d` rotation) |
| Volume state query | `\\.\X:` + DriverMessage; returns `state == 1` ⇒ “in shadow mode” |
| Diagnostics log | `C:\sdtrace.log`, line prefix `"[ % 16s ] \| "` (arg = `Defender`), 1 MB cap |
| Uninstall → daemon | `SendMessageW(FindWindowW(NULL, L"Shadow Defender Daemon Window"), 0x47B, 0, 0)` |
| Uninstall → own UI | `WM_USER+2` (`0x402`), wParam = progress `0/0x14/0x28/0x50/0x64` |
| Commit ↔ progress UI | unnamed auto-reset + manual-reset events + worker thread `0x140004670` |

### 6.3 Password scheme (final, shared)

```
user.dat -> [common] hash = lowercase-hex( MD5( UTF16LE( K ++ password ) ) )        (32 chars)
K = HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID     (REG_SZ string)
    (CmdTool prefers a driver-provided key via \\.\DpControl, 136-byte buffer,
     when the system volume is already protected)
password = "@BLANKPWD"  when the user clears the password
```
Observed at: CmdTool `sub_140002240` (`0x140002240`, write path `/xpwd:`), Commit
`sub_140003334` (`0x140003334`, blank-password test) — MD5 constants confirmed in both
binaries.

### 6.4 Residual unknowns (all VM-bound)

1. Exact IOCTL codes/structures the four tools send to `\\.\DpControl` and `\\.\X:`
   (only `0x80000D18` / `0x80002D48` + the 136-byte `dkpt` block are known, from Service.exe).
2. The `/pwd:` comparison site and the `/data:` handler in CmdTool.
3. The per-volume RC4 key derivation and the state-file body layout beyond the 512-byte header.
4. `user.dat hash2=` (not referenced by any of the four tools).
5. The role of CLSID `{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` (Defender.exe).
6. Whether `Service.exe /Uninstall` removes the `{0D9DB60E-…}` shadow-area directories
   (plausible; the remover exists in Service.exe but the parameterisation is in `Service.exe`).
