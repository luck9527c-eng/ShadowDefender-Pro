# Reproducible verifications

Short, runnable checks that confirm the headline findings. Each entry states the
claim, the command, and the expected result. Run from the repository root.

---

## V1 — The real driver is `diskpt.sys`, not `SDFRd.sys`

**Claim.** Shadow Defender's kernel driver is `C:\Windows\System32\drivers\diskpt.sys`
and it is disguised: its version resource says `SHADOWDEFENDER.COM` while its
Authenticode signer does not.

```powershell
(Get-Item 'C:\Windows\System32\drivers\diskpt.sys').VersionInfo |
    Format-List CompanyName,ProductName,FileDescription,FileVersion
Get-AuthenticodeSignature 'C:\Windows\System32\drivers\diskpt.sys' |
    Select-Object Status,@{n='Signer';e={$_.SignerCertificate.Subject}}
```

Expected:

```
CompanyName     : SHADOWDEFENDER.COM
ProductName     : Shadow Defender
FileDescription : Shadow Defender Filter Driver
FileVersion     : 1.5.0.726

Status : Valid
Signer : CN=Beijing YiChengWeiLai Culture-Tech Co., ...
```

**Negative control.** `SDFRd.sys` in the same directory is a *Microsoft* inbox
driver ("SDF Reflector", WHQL-signed by `CN=Microsoft Windows`). Despite the
`SDF` prefix it is unrelated and must not be included in a reconstruction.

```powershell
Get-AuthenticodeSignature 'C:\Windows\System32\drivers\SDFRd.sys' |
    Select-Object Status,@{n='Signer';e={$_.SignerCertificate.Subject}}
```

---

## V2 — Password hashing scheme

**Claim.** `user.dat`'s `hash` is
`lowercase_hex(MD5(UTF-16LE(serviceGUID ++ password)))`, and an unset password is
stored as the sentinel `MD5(serviceGUID ++ "@BLANKPWD")`, where `serviceGUID` is
the brace-formatted `GUID` value of the driver service.

```python
import hashlib
guid = "{fd1aecc8-b1e9-4b92-a188-daa06486e05b}"   # HKLM\SYSTEM\CurrentControlSet\Services\diskpt -> GUID
print(hashlib.md5((guid + "@BLANKPWD").encode("utf-16-le")).hexdigest())
```

Expected:

```
eb1997a8cf8000a3d43ce85f0be18268
```

which is byte-identical to the `hash` value stored in the installed
`C:\Program Files\Shadow Defender\user.dat`. This simultaneously confirms:

* the salt is the driver service `GUID`, in lowercase brace form;
* the concatenation happens *before* UTF-16LE encoding of the whole string;
* the sentinel is `@BLANKPWD` (not the empty string) — note that
  `MD5(UTF16LE(guid))` is `3e5fc78fa5cb7fbb4c46d986dbfbbd85`, which does **not**
  match, so the sentinel is genuinely used;
* the analysis host's installation has **no password set**.

Independent control: the same construction with the *service name* GUID
`{0CBD4F48-3751-475D-BE88-4F271385B672}` yields `87e70e8f3c8ce519caa0af801b091eca`,
which does not match — so the salt is specifically the `diskpt` service `GUID`
value, not the service name.

---

## V3 — The obfuscated vault is code, not relocation data

**Claim.** In `samples/diskpt.sys` the section *named* `.reloc` spans `0x48334`
bytes while the `BASERELOC` data directory is only `0x18` bytes, and the region
past that 24-byte block is executable code reached through a 136-entry table of
RVAs at `0x679A9`.

```python
import struct
d = open('samples/diskpt.sys','rb').read()
pe = struct.unpack_from('<I', d, 0x3C)[0]
opt = pe + 24
rva, size = struct.unpack_from('<II', d, opt + 112 + 5*8)   # directory 5 = BASERELOC
print("BASERELOC rva=%#x size=%#x" % (rva, size))            # -> 0x2d000 size=0x18
# section named ".reloc"
nsec = struct.unpack_from('<H', d, pe + 6)[0]
optsz = struct.unpack_from('<H', d, pe + 20)[0]
sh = pe + 24 + optsz
for i in range(nsec):
    o = sh + i*40
    name = d[o:o+8].rstrip(b'\0').decode()
    vsz, va, rsz, ra = struct.unpack_from('<IIII', d, o+8)
    if name == '.reloc':
        print("%s VA=%#x VSize=%#x" % (name, va, vsz))       # -> .reloc VA=0x2d000 VSize=0x48334
# the dispatch table holds 136 plaintext RVAs
table = 0x28200 + (0x679A9 - 0x2d000)
vals = struct.unpack_from('<8Q', d, table)
print([hex(v) for v in vals])
```

Expected: `BASERELOC rva=0x2d000 size=0x18`, `.reloc VA=0x2d000 VSize=0x48334`,
and table entries in the range `0x2d353 …` (i.e. RVAs into the same section).

`tools/vm.py` performs the same check plus the full table walk:

```bash
python tools/vm.py samples/diskpt.sys --find-tables
# -> dispatch table rva=0x679a9 entries=136
```

---

## V4 — Filter and service registration

**Claim.** The driver is a boot-start disk-class upper filter and volume-class
lower filter, and its service key carries the write-through `Sync` list.

```powershell
Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Services\diskpt' |
    Format-List ImagePath,Type,Start,Group,ErrorControl,GUID,Sync,CacheSize,Control
Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}' |
    Select-Object UpperFilters,LowerFilters
Get-ItemProperty 'HKLM:\SYSTEM\CurrentControlSet\Control\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}' |
    Select-Object UpperFilters,LowerFilters
```

Expected on the analysis host:

```
Type=1  Start=0  Group=System Bus Extender  ErrorControl=1
GUID={fd1aecc8-b1e9-4b92-a188-daa06486e05b}
Sync=C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat
CacheSize=0  Control=0x10000001

disk class   UpperFilters = {partmgr, diskpt}
volume class LowerFilters = {fvevol, diskpt, iorate, rdyboost}
```

`Start = 0` + `System Bus Extender` is what lets the driver install before the
file systems mount; the `Sync` list is why `user.dat` survives a shadow session.

---

## V5 — Artifact set and hashes

**Claim.** The analysed binaries are the ones present on the host, unmodified.

```bash
sha256sum samples/*.exe samples/*.dll samples/diskpt.sys
```

Expected (must equal the hashes in `README.md` §8):

```
5dcf3b77…b9ac7  CmdTool.exe
e05d8725…17fbe  Commit.exe
f01d6865…0a6fc  Defender.exe
686e86b6…25dc63 DefenderDaemon.exe
dbb55e76…5fdfb8 Service.exe
14126b8a…27ca0  ShellExt.dll
78cf5509…7a850  Uninstall.exe
6ffd78b5…03583  diskpt.sys
```

---

## V6 — Shadow configuration table on disk

**Claim.** `C:\Windows\diskpt.crt` is 64 bytes = four 16-byte volume records, and
its per-record `state` dword reads 0 for one volume and 1/3/3 for the others.

```bash
xxd /c/Windows/diskpt.crt
ls -la /c/Windows/diskpt.dat /c/Windows/diskptex.dat     # both 0 bytes here
```

Expected: the dump reproduced in `docs/03-driver-diskpt.md` §4.2, with `state`
values `0x00000000`, `0x00000001`, `0x00000003`, `0x00000003`.

The same directory check confirms `X:\diskpt0.sys`,
`X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` and `C:\Windows\dpstart.exe` are
**absent** on the analysis host, i.e. no volume is currently in Shadow Mode —
which is why no map-file sample exists to read (see
`docs/09-unknowns-and-roadmap.md` §2.5).

---

## What these checks do **not** establish

They confirm identities, the password construction, the obfuscation structure and
the storage-stack registration. They do **not** decode the bytecode control
plane; the `\\.\DpControl` payload above the `'dkpt'` magic remains unknown. See
`docs/09-unknowns-and-roadmap.md`.

---

## V7 — Installer package and the origin of the password salt

**Claim.** The supplied package is a four-layer 7-Zip SFX chain; its payload is
byte-identical to the installed tree; the installed driver is the payload's
`diskpt.win10.sys`; and the `GUID` value used as the password salt is written by
the installer, not generated by the driver.

```bash
# 1. outer SFX: the 7z stream starts at 0xCA00, last 15826 bytes are the signature
python - <<'PY'
import struct, re
d=open('安装包/Setup.exe','rb').read()
sig=bytes.fromhex('377abcaf271c')
for m in re.finditer(re.escape(sig), d):
    i=m.start()
    nh_off, nh_size = struct.unpack_from('<QQ', d, i+12)
    end = i+32+nh_off+nh_size
    if d[i+6:i+8] in (b'\x00\x04', b'\x00\x03') and 0 < nh_size < 10**7 and end <= len(d):
        print('archive at', hex(i), 'length', end-i)
PY

# 2. list the payloads (any 7-Zip)
7z l work/pack/Setup_x64.exe.7z      # 14 files, incl. diskpt.sys + diskpt.win10.sys

# 3. identity: installed driver == diskpt.win10.sys, installed daemon == Daemon.exe
sha256sum samples/diskpt.sys work/pack/x64/diskpt.win10.sys
sha256sum samples/DefenderDaemon.exe work/pack/x64/Daemon.exe
```

Expected:

```
6ffd78b5…03583  *samples/diskpt.sys
6ffd78b5…03583  *work/pack/x64/diskpt.win10.sys      (identical)
686e86b6…5dc63  *samples/DefenderDaemon.exe
686e86b6…5dc63  *work/pack/x64/Daemon.exe            (identical)
```

Salt origin — the installer string table contains, in order, the service key
path, the value name and a 16-byte hex formatter:

```
diskpt
SYSTEM\CurrentControlSet\Services\%s
GUID
%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x
```

and the installer imports `CoCreateGuid`:

```python
import pefile
pe = pefile.PE('work/pack/x64/Setup.exe')
pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_IMPORT']])
for e in pe.DIRECTORY_ENTRY_IMPORT:
    for i in e.imports:
        if i.name and b'Guid' in i.name:
            print(e.dll.decode(), i.name.decode(), hex(i.address))
# -> ole32.dll CoCreateGuid 0x140045ad0
```

The driver, by contrast, has no `GUID` string and imports only `RtlRandom`
(used by `sub_280079A08`, which seeds from `KeQueryPerformanceCounter` and enters
the VM). The salt is therefore created by the installer.

**Signing.** All four layers are validly signed by the same principal as the
2020 driver:

```powershell
Get-AuthenticodeSignature '安装包\Setup.exe' | Select-Object Status,@{n='Signer';e={$_.SignerCertificate.Subject}}
```

```
Status : Valid
Signer : CN="Beijing YiChengWeiLai Culture-Tech Co., Ltd.", O="Beijing YiChengWeiLai Culture-Tech Co., Ltd.", ...
```

**Control.** The package's `diskpt.sys` (2017, v1.4.0.672) has a **different**
signer (`StarSoftComm(China) Ltd.`), so the signing identity changed between the
1.4 and 1.5 lines.
