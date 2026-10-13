# Shadow Defender — Password, Registration, Trial and Crypto

> Scope: the product's authentication and licensing mechanisms and the cryptography it
> uses for its own data, specified so that the behaviour can be reimplemented and
> interoperated with.
> Status: **observed** unless marked *inferred* / *unknown*. Addresses are VAs
> (`Defender.exe` base `0x140000000`, `CmdTool`/`Commit` base `0x140000000`).
>
> **Notice.** This document is a specification of the mechanisms found in the analysed
> binaries, produced for interoperability and security research. It deliberately contains
> **no licence-key generator**, no working serial, and no procedure for defeating the trial.
> The algorithms are described so that a reimplementation can be compatible with existing
> data (`user.dat`, `diskpt.crt`, the map files) and so that a reviewer can assess the
> design. Do not use it to produce licence keys or to circumvent the trial.

## 1. The four mechanisms

| Mechanism | Primitive | Stored where | Purpose |
| --- | --- | --- | --- |
| UI password | `MD5(UTF16LE(serviceGUID ++ password))`, lowercase hex | `user.dat [common] hash` | gate the Administration page, the shell-ext commit (`shellext == 2`) and `CmdTool /pwd:` |
| Registration code | 25 chars; base-31 encoding of `MD5(ANSI(code[16..25]) ++ key)[0..15]` compared to `code[0..15]` | `user.dat [common] hash2` (obfuscated), transient `sn` | prove a purchased serial |
| Trial | 30 days from a `SYSTEMTIME` hidden in an unrelated CLSID key | `HKCR\CLSID\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}` | limits unregistered use |
| Write-cache crypto | RC4 (KSA + PRGA) | map-file body and driver payloads | encrypt the shadow cache when enabled |

## 2. Password hashing

### 2.1 Algorithm

```
hash = lowercase_hex( MD5( UTF-16LE bytes of ( serviceGUID ++ password ) ) )

serviceGUID = HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID   (REG_SZ)
password    = the user's password, or the literal "@BLANKPWD" when the password is empty
```

Observed in all three user-facing implementations:

| Module | Function | Address | Notes |
| --- | --- | --- | --- |
| `Defender.exe` | `HashPassword(pwd, out32)` = `sub_140002864` | `0x140002864` | picks the GUID from the driver (when the system volume is shadowed) or from the registry, `wcscat_s` the password, `MD5Update(ctx, wide, 2*wcslen(wide))`, 16×`%02x` |
| `Defender.exe` | `sub_140012F34` | `0x140012f34` | the **blank password** path: `GUID + "@BLANKPWD"` → compared with `[common] hash` |
| `Defender.exe` | `CLoginDlg::OnOK` = `sub_14001A2CC` | `0x14001a2cc` | reads the edit control, hashes, compares, 3 tries (§2.4) |
| `CmdTool.exe` | `SdComputePasswordHash` = `sub_140002240` | `0x140002240` | fully plaintext; salt is the driver key (`sub_140025910`, 136-byte buffer) when the system volume is shadowed, else the registry GUID |
| `Commit.exe` | `sub_140003334` | `0x140003334` | computes the blank sentinel and compares against `[common] hash` (§2.3) |

MD5 implementations (all standard, constants `0x67452301`, `0xEFCDAB89`, `0x98BADCFE`,
`0x10325476`):

| Module | init | update | final | evidence |
| --- | --- | --- | --- | --- |
| `Defender.exe` | `sub_140001370` (`0x140001370`) | `sub_140001DF8` (`0x140001df8`) | `sub_1400014BC` (`0x1400014bc`) | RTTI class `MD5_CTX`; constants at `0x1400013xx` |
| `CmdTool.exe` | `sub_140001290` (`0x140001290`) | — | `sub_140001340` (`0x140001340`) | constants at `0x1400012A3/AA/B1/B8` and a second init site at `0x14000147B–90` |
| `Commit.exe` | `sub_140001304`/`0x14000131D` | — | `sub_14000142C` | constants at `0x140001304/30F/316/31D` and `0x1400014CD/D4/DB/E2` |

The UTF-16LE byte count is explicit in the code (`MD5Update(ctx, buf, 2 * wcslen(buf))`),
which is what makes the hash byte-order-sensitive and non-portable to UTF-8
implementations.

### 2.2 Why the salt is the installation GUID

`serviceGUID` is generated per installation (the host's is
`{fd1aecc8-b1e9-4b92-a188-daa06486e05b}`). Because it doubles as the input to the
obfuscated IOCTL-base derivation ([docs/04-service-protocol.md](04-service-protocol.md) §6),
the same secret is used for the password salt: `user.dat` copied to another installation
stops being a valid password store.

### 2.3 Worked illustration (verification, not a key)

For `serviceGUID = {fd1aecc8-b1e9-4b92-a188-daa06486e05b}` and the arbitrary example
password `Example-Password-123`:

```
string  : {fd1aecc8-b1e9-4b92-a188-daa06486e05b}Example-Password-123
bytes   : the same string encoded UTF-16LE (116 bytes)
MD5     : 6a0686ff67ec086f6b8ea00635112030
stored  : hash=6a0686ff67ec086f6b8ea00635112030
```

Cross-check on the analysed host: its `hash` is
`eb1997a8cf8000a3d43ce85f0be18268`, and
`MD5(UTF16LE("{fd1aecc8-b1e9-4b92-a188-daa06486e05b}" ++ "@BLANKPWD"))` reproduces that
value **exactly**. Two conclusions, both observed:

1. the hash construction and the GUID-as-salt reading are verified end-to-end on real
   data, and
2. **the analysed installation has no password set** — its stored value is the blank
   sentinel, not a hash of a user password.

The concrete blank-sentinel digest is installation-specific (it is a function of the local
GUID) and is deliberately not reproduced here except as this host-specific verification.

### 2.4 Where a password is required, and how it is checked

| Entry point | Check | Behaviour |
| --- | --- | --- |
| Administration page (res.ini 50004 "Enable password control") | `sub_140017D38` reads `hash` and compares it with the blank sentinel | equal ⇒ "Your password is empty, please set a new password." (res.ini **50006**), the checkbox is unchecked and "Set New Password" disabled. Changing the password (`sub_140016888` → `CSetPwdDlg`) writes the new hash and shows res.ini **50007**. When the password check is enabled, `sub_140016FE0` **forces `shellext = 2`** so the shell commit cannot bypass the password. |
| Password prompt `CLoginDlg` (`sub_14001A958` init, `sub_14001A2CC` OK) | reads the edit control, computes `hash(candidate)` and compares to `[common] hash` | mismatch ⇒ retry, counter at `this+0x150`, **max 3 attempts**, `Sleep(500)` between attempts, res.ini **1003** "Invalid password."; after the third failure `CDialog::OnCancel()`. Success sets a global flag (`g_app+376 = 1`) that the callers test. If the GUID cannot be read at all (driver absent **and** registry missing), res.ini 1003 is shown and the dialog is cancelled. |
| Shell context-menu commit | `Commit.exe sub_140003334` when `[common] shellext == 2` | computes the blank sentinel; if the stored hash equals it, the commit proceeds with no prompt; otherwise the password dialog (`sub_140005494`, validator `sub_140005654`) must return 1 **and** set `app+388`. Declining leaves the files uncommitted. |
| `CmdTool.exe` (all state-changing commands except `/list`) | VM region `0x140003565`–`0x140003CA0` | prints `Password is not specified or is not correct.` and stops. `/pwd:<OLD>` provides the candidate; `/xpwd:<NEW>` writes a new hash. |
| `CmdTool /xpwd:` | fully plaintext (`0x140003FCC`–`0x1400040B3`) | empty value ⇒ `"@BLANKPWD"`, i.e. clearing the password is the same operation as setting the blank sentinel. |

The comparison is always the same shape: `wcscmp(stored_hash, hex(MD5(GUID ++ candidate)))`
— a 32-character lowercase hex string comparison. No plaintext password is stored, and the
"no password" state is a *positive value*, not an empty field (though a missing `hash` key
is also treated as "unset" by `Commit.exe`, whose read default is
`00000000000000000000000000000000`).

## 3. Registration code

### 3.1 Format

* Exactly **25 characters** (after `-` separators are removed).
* Alphabet: `ABCDEFGHJKMNPQRSTUVWXYZ23456789` — A–Z **without I, L and O**, followed by
  digits 2–9 (`sub_14000328C` = `Base31(byte) = alphabet[byte % 31]`; index→char mapping
  observed literally, default `'3'`).
* The stored/entered form on this host is grouped: `hash2` is **29 characters**, i.e. the
  25 code characters plus 4 `-` separators, consistent with the `Remove('-')` call in
  `IsRegistered` (`sub_14000E8D4`) and the 25-character requirement in `VerifySerial`.

### 3.2 Verification

`VerifySerial` = `sub_140002FF4 @ 0x140002ff4`:

```c
/* code = 25 chars (uppercased), key = "V100" or "V110" */
wcsncpy_s(w, 32, code, 25); w[25] = 0; wcsupr_s(w, 32);
if (wcslen(w) != 25) return 0;

WideCharToMultiByte(CP_ACP, 0, w,  -1, mb,  32, NULL, NULL);   /* ANSI(code)  */
WideCharToMultiByte(CP_ACP, 0, key,-1, key2,32, NULL, NULL);   /* ANSI(key)   */
strcat_s(mb, 0x20, key2);                                      /* code + key  */

MD5Init(&ctx);
MD5Update(&ctx, mb + 16, strlen(mb) - 16);   /* NOTE: bytes of the code from offset 16 */
MD5Final(&ctx, digest);
for (i = 0; i < 16; ++i)
    if (base31(digest[i]) != w[i]) return 0; /* the FIRST 16 code chars are the check */
return 1;                                    /* else: compute days left, return 0 */
```

So the code is `[16 check characters][9 payload characters]`:

* the 9 payload characters (positions 16–24) take part in the hash **together with the
  version key**, so they are integrity-protected rather than "free" text;
* the 16 check characters are `base31(digest[0..15])` — one character per MD5 byte, giving
  31¹⁶ ≈ 2⁷⁹ nominally, of which only the 31-way residue of each byte is used (≈ 2⁷⁴
  distinct checks are actually expressible);
* the version key distinguishes codes: `"V100"` and `"V110"` (callers accept **either**).

> **Clarification of the source report.** `recon/analysis/defender_gui.md` §0/§3.5 renders
> this as "the first 16 are a base-31 encoding of `MD5(ANSI(code)+key)[16..]`". The
> correct reading is: the MD5 **input** starts at code offset **16**, and the digest
> **bytes 0–15** are base-31 encoded and compared to code characters **0–15**. The report's
> prose conflates the two offsets; the pseudocode above is the observed behaviour.

### 3.3 Storage: `sn` → `hash2`

`IsRegistered(key, &daysLeft)` = `sub_14000E8D4 @ 0x14000e8d4`:

```c
hash2 = user.dat[common\hash2];
if (hash2 != "")  code = Hash2ToSn(hash2);                 /* decode (§4) */
else {            code = MakeUpper(user.dat[common\sn]);   /* legacy plaintext */
                  WritePrivateProfileString("common","hash2", SnToHash2(code), path);
                  WritePrivateProfileString("common","sn", "", path);
                  CommitUserDatOutOfShadow(); }
code.Remove('-');
return VerifySerial(code, key, &daysLeft);
```

Callers consult both version keys:

```c
registered = IsRegistered(L"V100", &days) || IsRegistered(L"V110", &days);   /* main window */
```

`CRegisterDlg::OnOK` = `sub_14001BA88 @ 0x14001ba88` stores a newly entered code as
`hash2` and records `time = time64(NULL)`, then commits the file out of the shadow. The
"Get Registration Code" button (`sub_14001BFC4`) runs `VerifySerial(edit, L"V100"/L"V110", NULL)`
as a pure check.

## 4. `hash2` storage obfuscation

This is **storage obfuscation, not encryption**: it is a fixed additive substitution with a
published key, its only purpose being to keep the serial from appearing literally in
`user.dat`.

### 4.1 Algorithm (corrected)

`SnToHash2` = `sub_14000FD28 @ 0x14000fd28`:

```c
/* the seven key elements are the EVEN int16 lanes of a 16-byte constant (3,7,8,2)
   followed by three int16 values the compiler placed in the adjacent stack slots   */
static const short kHash2Key[7] = { 3, 7, 8, 2, 9, 5, 4 };
for (i = 0; i < len(sn); ++i) {
    v = sn[i] + kHash2Key[i % 7];
    if (v > 0x7A) v = (v % 0x7A) + 0x20;          /* wrap guard; unreachable for the
                                                     serial alphabet + these keys */
    out[i] = v;
}
```

`Hash2ToSn` = `sub_14000FBDC @ 0x14000fbdc`:

```c
for (i = 0; i < len(hash2); ++i) {
    v = hash2[i] - kHash2Key[i % 7];
    if (v < 0x20) v += 90;                        /* the inverse of the wrap guard */
    out[i] = v;
}
```

> **Correction to the source report.** `defender_gui.md` §3.5 states the key is
> `int16 {3,7,8,2,0,0,0}` taken from `xmmword_140089180`. The raw constant at
> `Defender.exe` file offset `0x87f80` is indeed `03 00 00 00 07 00 00 00 08 00 00 00 02 00 00 00`
> (int16 lanes `3,0,7,0,8,0,2,0`), **but** the code indexes the register file as
> `si128.m128i_i16[2 * (v6 % 7)]` — every *second* int16 lane — and the remaining three
> elements come from the adjacent locals `v15 = 9`, `v16 = 5`, `v17 = 4` that IDA shows in
> the function (`sub_14000FD28`, allocated at `[rsp+50h]/[rsp+54h]/[rsp+58h]`, immediately
> after `si128` at `[rsp+40h]`). The effective key is therefore
> **`{3, 7, 8, 2, 9, 5, 4}`**. Verification: with this key the host's `hash2`
> (<redacted: this installation's licence serial>) decodes to a 29-character string consisting only of the
> base-31 alphabet and exactly four `-` characters (groups `#####-#####-#####-#####-#####`),
> and re-encoding that string reproduces the observed `hash2` byte-for-byte. With the
> report's key the decode yields characters outside the alphabet, so the report's key
> cannot be right.

Synthetic illustration of the transform (the product's own storage encoding applied to a
made-up placeholder, not a licence key):

```
placeholder        : ABCDE-FGHJK-MNPQR-STUVW-XYZ23
encoded (hash2)    : DIKFN2JJORM6RRSXZ/\YYY^5Zb_66
decode(encode(x))  : ABCDE-FGHJK-MNPQR-STUVW-XYZ23     (round-trip holds exactly)
```

Note that the **encoded** form is not confined to the serial alphabet — it contains `\`,
`^`, `_`, `/` and lowercase characters. Only the *decoded* plaintext is expected to be a
base-31 code; `hash2` is never validated as itself containing only alphabet characters, it
is simply decoded first and the result is checked. The decode's `+90` guard exists for
ciphertext characters outside the range the encoder produces from a valid serial.

### 4.2 Properties

| Property | Value |
| --- | --- |
| Key | `{3,7,8,2,9,5,4}`, cycled with period 7 |
| Direction | encode = add, decode = subtract (each with a wrap guard) |
| Length | preserved exactly (host: 29 chars in, 29 out) |
| Strength | none — a single-character frequency analysis breaks it instantly; it is not a cipher. Note that the *encoded* string is not restricted to the serial alphabet: only the decoded plaintext is. |
| Where | `user.dat [common] hash2`; `sn` is cleared once `hash2` exists |

## 5. `sn`, `time`, `continue` and the 30-day trial

### 5.1 The values

| Key | Semantics | Evidence |
| --- | --- | --- |
| `sn` | the code as typed, before migration to `hash2`; cleared afterwards | `sub_14000E8D4` |
| `time` | `time64(NULL)` at registration, written as decimal; **never read back** by any analysed module | `sub_14001BA88`; observed `1809326992` |
| `continue` | "Enter Shadow Mode on Boot" (0/1) | `sub_140014240`, `sub_14001430C` |
| `volume` | drive letters scheduled/currently shadowed (observed `CD`) | `sub_140022BA0` |

`time` is *not* the trial clock — it is a record of when the code was entered. The trial
clock is hidden elsewhere (§5.2).

### 5.2 The trial clock

`VerifySerial` (`sub_140002FF4`), in the same function that validates the code, computes the
remaining days when a non-NULL `days` out-parameter is passed:

```c
pcbData = 16;
if (SHGetValueW(HKEY_CLASSES_ROOT,
                L"CLSID\\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}",
                L"" /*default value*/, &type, &SYSTEMTIME, &pcbData) == ERROR_SUCCESS) {
    GetSystemTime(&now);
    SystemTimeToFileTime(&start, &ftStart); SystemTimeToFileTime(&now, &ftNow);
    secs = (ftNow - ftStart) / 10000000;                 /* 100-ns units -> seconds */
    if (secs < 0x278D00 /*2 592 000 s = 30 days*/)
        *days = 30 - secs / 0x15180 /*86 400 s*/;
}
```

* The start timestamp is a 16-byte `SYSTEMTIME` stored as the **default value** of a CLSID
  key that belongs to no registered component — a deliberate hiding place.
* `Defender.exe` only *reads* it; no writer exists in any analysed module. *Inferred:* the
  installer or `Service.exe` creates it on first run.
* Expiry = "now − start ≥ 30 days". Days left is `30 - elapsed_days`, i.e. 30 on day 0.
* Uninstall removes the key (`Uninstall.exe`, docs/06 §5.2 step 5), which also resets the
  trial.

### 5.3 How the nag is driven

`TrialPrompt` = `sub_140026570 @ 0x140026570` (the dialog with string group 90000–90004):

```c
days = 0;
ok = IsRegistered(L"V100", &days) || IsRegistered(L"V110", &days);
EnableWindow(GetDlgItem(this, 1014 /*Later*/), (ok || days == 0) ? 0 : 1);

if (days != 0) {
    SetDlgItemText(1015, GetResString(90001));   /* "…will expire in %d day(s)." */
    Format(res90001, days);
    SetDlgItemText(1013, GetResString(90002));   /* &Buy    */
    SetDlgItemText(1014, GetResString(90003));   /* &Later  */
    SetDlgItemText(1000, GetResString(90004));   /* &Register */
} else {
    SetDlgItemText(1015, GetResString(90000));   /* "trial … is expired"   */
    /* *** force-exit Shadow Mode on every shadowed volume *** */
    for (drive = 'C'; drive <= 'Z'; ++drive)
        if (IsRealVolume(drive) && GetVolumeInfo(drive, &info) && info.inShadow == 1)
            SetVolumeFlag(drive, 0);             /* 0 = normal mode */
}
```

Observed consequences:

* The *expired* branch (90000) is not merely a message: it calls `sub_140062A80(drive, 0)`
  for every volume currently in shadow mode, i.e. **an expired trial takes the machine out
  of Shadow Mode** while leaving the "Later" button disabled. (The code path is entered
  only when `days == 0` and the code did not verify.)
* The 90001 branch formats the message with the remaining days; res.ini 90001 contains the
  literal `%d day(s)`.
* `&Buy` opens the purchase URL — `RegURL` from
  `HKLM\SOFTWARE\Shadow Defender` (observed
  `http://www.shadowdefender.com/purchase.php?sid=1`) through `sub_140026354`.
* `&Register` opens `CRegisterDlg` (100000–100004).

## 6. Cryptography for the write cache

### 6.1 RC4

`Defender.exe` and `CmdTool.exe` each contain a complete RC4 implementation with the
standard KSA/PRGA pair:

| Module | KSA | PRGA |
| --- | --- | --- |
| `Defender.exe` | `sub_1400615E0 @ 0x1400615e0` | `sub_140060320 @ 0x140060320` |
| `CmdTool.exe` | `sub_140025350 @ 0x140025350` | `sub_140024090 @ 0x140024090` |

```c
/* reconstruction — identical to the textbook algorithm; context is 258 bytes
   (the decompiler shows it as {int i; int j; unsigned char S[256];} = 264 bytes
   due to int alignment) */
typedef struct { unsigned char i, j, S[256]; } rc4_ctx;

void rc4_ksa(rc4_ctx *c, const unsigned char *key, int keylen) {
    for (int i = 0; i < 256; i++) c->S[i] = (unsigned char)i;
    c->i = c->j = 0;
    unsigned char j = 0;
    for (int i = 0; i < 256; i++) {
        j = (unsigned char)(j + c->S[i] + key[i % keylen]);
        unsigned char t = c->S[i]; c->S[i] = c->S[j]; c->S[j] = t;
    }
}
void rc4_apply(rc4_ctx *c, unsigned char *buf, int len) {
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

### 6.2 Where it is used, and where the key comes from

* The setting is `user.dat [common] encrypt` (0/1, default 0), exposed as res.ini 50013
  "&Encrypt write cache" (`sub_140016BD8`). It is passed to the enter-shadow worker as a
  thread parameter (`params[5] = (encrypt == 1)`), so the *driver* is told whether to
  encrypt.
* `CmdTool.exe sub_140026330` reads the first 512 bytes of `X:\diskpt0.sys` and then hands
  the buffer **together with an RC4 context** to a VM body, which strongly suggests the
  header/body are processed with RC4 on every mode change
  ([docs/07-config-and-formats.md](07-config-and-formats.md) §6.3).
* `PAGE_READWRITE` shared memory and the map file are the only structures passed through
  these functions in the recovered code; the commit data itself is copied with
  `CopyFileW`-style helpers, not encrypted.
* **The key material is not recovered.** It is supplied to the KSA by the caller inside the
  `.reloc` VM blocks in every case (`Defender.exe sub_1400615E0` has no visible caller that
  computes a key; `CmdTool` passes the context through the VM). *Inferred:* the key is
  derived from the installation GUID and/or the volume serial (both are available at every
  relevant call site), but this is **unknown** and must not be assumed.

### 6.3 Assessment

RC4 with a per-installation or per-volume key is adequate to keep a shadow cache from being
readable by ordinary file tools (the cache is hidden+system and compressed as well), and
the cipher's known weaknesses (biased keystream, no integrity) apply. Nothing in the
observed code authenticates the cache, so the design goal is confidentiality against
casual inspection, not tamper resistance.

## 7. Update / registration check

`CheckForUpdate` = `sub_140010E30 @ 0x140010e30` (run by the update thread; gated by
`user.dat [common] checkupdate`, default 1, res.ini 50014):

1. Version string from the executable's `VS_FIXEDFILEINFO` (`sub_14000DCB8`, format
   `%d.%d.%d.%d`).
2. Serial: `[common] hash2` decoded with `Hash2ToSn`, or `[common] sn` when `hash2` is
   empty (§3.3/§4).
3. The serial is converted to ANSI (`WideCharToMultiByte(CP_ACP)`), upper-cased
   (`strupr_s`), MD5-hashed (`sub_140001370`/`sub_140001DF8`/`sub_1400014BC`) and formatted
   as 32 lowercase hex characters.
4. Request body (observed string fragments `"version="` and `"&extra="`):

```
version=<a.b.c.d>&extra=<32-hex-md5-of-uppercased-ANSI-serial>
```

5. Transport: host `www.shadowdefender.com`, URL
   **`checkupdate-3011ca199c614b0c96a84f435046c4c5.php`** (both literals observed in
   `sub_140010E30`, `sub_140010e30`), sent by the MFC WININET helper
   `sub_1400131A4 @ 0x1400131a4`:

```c
CInternetSession::GetHttpConnection(host, INTERNET_DEFAULT_HTTP_PORT /*80*/, …);
/* headers:  Content-Type: application/x-www-form-urlencoded\r\nAccept-Language:en-us
             (+ optional \r\nReferer:)                                              */
CHttpFile::QueryInfoStatusCode(&status);
/* response read line-by-line in 1023-character lines */
```

6. The result is shown to the user as res.ini **22** `"A new version is avaible."`
   (`sub_140018740`); the same HTTP helper serves the "Get Registration Code" flow of the
   register dialog. The `extra` value also acts as a lightweight registration ping, which
   is why the check is only attempted when `checkupdate` is on.

Note that the URL is plain HTTP and carries a fixed opaque file name — no TLS, no
signature on the response. A MITM can therefore answer the check or observe the hashed
serial.

## 8. Design summary and open questions

| Design decision | Consequence |
| --- | --- |
| Password salted with the per-installation GUID | `user.dat` is not portable between installs |
| Blank password is a positive sentinel value | "no password" is distinguishable from "unknown", and it is a constant that any writer of `user.dat` can set |
| Password needed for shell commit only when `shellext == 2` (forced on when password control is enabled) | the three states are a real tri-state, not a boolean |
| Registration check is a 16-character MD5 residue over 9 payload characters + a version key | codes cannot be transferred between the `V100` and `V110` key families; the payload is integrity-protected but carries no other observable meaning |
| Serial kept in `user.dat` with an additive obfuscation, not encryption | reversible by anyone with the file; the point is to avoid a literal serial |
| Trial clock hidden in an unrelated CLSID key, and an expired trial exits Shadow Mode | expiry has a functional effect, not just a nag; deletion of the key (as by uninstall) resets the clock |
| RC4 with an unrecovered, per-install/volume key for the write cache | confidentiality only; the key must be recovered from the VM before a reimplementation can read an encrypted cache |

Open questions:

1. **RC4 key derivation.** The key is passed by the VM in both modules; it is not visible in
   the native code. Until it is recovered, encrypted map files cannot be decoded.
2. **`f(GUID) → K`** (shared with [docs/04-service-protocol.md](04-service-protocol.md) §6):
   the same obfuscated helper also derives the IOCTL base; recovering it would resolve both
   items at once.
3. **The 9 payload characters of a registration code.** They are hashed, so they are
   integrity-protected, but whether they encode a customer number, an entitlement or random
   data is unknown.
4. **`days` vs. the stored `time`.** `time` is never read; only the CLSID `SYSTEMTIME`
   drives expiry. Whether any module compares them (e.g. to detect clock rollback) was not
   observed.
5. **Who writes the trial `SYSTEMTIME`.** No writer exists in the analysed modules.
6. **`hash2` for an unregistered install.** `IsRegistered` migrates a legacy plaintext
   `sn` into `hash2`; a reimplementation must accept both to read an old `user.dat`.
