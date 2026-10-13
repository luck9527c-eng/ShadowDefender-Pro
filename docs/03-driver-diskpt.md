# Shadow Defender — The Kernel Driver (`diskpt.sys`)

> Artifact: `C:\Windows\System32\drivers\diskpt.sys`
> SHA-256 `6ffd78b5954064bba7370af51b2e4f1358424f542682218a1121a375f3903583`
> PE32+ x86-64 · 478 544 bytes · CompanyName `SHADOWDEFENDER.COM` ·
> ProductName `Shadow Defender` · FileDescription `Shadow Defender Filter Driver` ·
> FileVersion `1.5.0.726` · PDB path `d:\work\defender\sys\diskpt\objfre_win7_amd64\amd64\diskpt.pdb`

## 1. Identity and disguise

The driver does not ship under a Shadow Defender name.

* It is copied to `System32\drivers\diskpt.sys` — a filename chosen to read as a
  disk-partition driver.
* Its Authenticode signature is **not** Shadow Defender's: `Get-AuthenticodeSignature`
  reports `CN=Beijing YiChengWeiLai Culture-Tech Co., …`. The embedded version
  resource, however, is `SHADOWDEFENDER.COM`. Signature and metadata therefore
  disagree, which is why this file does not show up in a filter for
  "Shadow Defender" drivers.
* The service is registered as `diskpt`, again a neutral name:

```
HKLM\SYSTEM\CurrentControlSet\Services\diskpt
    ImagePath    REG_EXPAND_SZ  SYSTEM32\drivers\diskpt.sys
    Type         REG_DWORD      1        (kernel driver)
    Start        REG_DWORD      0        (SERVICE_BOOT_START)
    ErrorControl REG_DWORD      1
    Group        REG_SZ         System Bus Extender
    Control      REG_DWORD      0x10000001
    GUID         REG_SZ         {fd1aecc8-b1e9-4b92-a188-daa06486e05b}
    Sync         REG_SZ         C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat
    CacheSize    REG_DWORD      0
```

Two of these values matter:

* **`GUID`** is generated per installation. It is the salt for the user-interface
  password hash and for the device-session key (see `docs/08-licensing-and-crypto.md`).
* **`Sync`** is the write-through list: files the driver must commit back to the
  original volume even while the volume is shadowed. It contains `bootstat.dat`
  and every profile's `Shadow Defender\user.dat`, which is how settings survive a
  shadow session.
* `Start = 0` with `Group = System Bus Extender` means the driver loads at boot
  from the `System Bus Extender` load group, i.e. **after disk enumeration but
  before the file systems mount** — the earliest point at which a full-disk
  redirector can install itself.

## 2. Registration in the storage stack

The driver is a **disk upper filter and a volume lower filter**:

```
HKLM\SYSTEM\CurrentControlSet\Control\Class\{4D36E967-E325-11CE-BFC1-08002BE10318}
    UpperFilters = {partmgr, diskpt}          ; Disk drive class
    LowerFilters = {EhStorClass}

HKLM\SYSTEM\CurrentControlSet\Control\Class\{71A27CDD-812A-11D0-BEC7-08002BE2092F}
    UpperFilters = {ambakdrv, volsnap}        ; Volume class
    LowerFilters = {fvevol, diskpt, iorate, rdyboost}
```

Observed on the analysis host. `diskpt` sits above `partmgr` on the disk class and
below BitLocker's `fvevol` on the volume class, which is exactly the placement a
sector-level redirector needs: it sees plaintext volume I/O after decryption and
can intercept every read and write.

In the driver's own registration it also creates the object
`\FileSystem\Filters\DpControl` (falling back to `\FileSystem\DpControl`), which
is the legacy "filter driver announcement" object other file-system components
enumerate.

## 3. Devices and namespaces

| Name | Kind | Purpose |
| --- | --- | --- |
| `\FileSystem\Filters\DpControl` (fallback `\FileSystem\DpControl`) | control device, `DeviceType = FILE_DEVICE_FILE_SYSTEM (8)`, `FILE_DEVICE_SECURE_OPEN` | IOCTL entry point |
| `\DosDevices\DpControl` | symbolic link | user-mode path `\\.\DpControl` |
| `\Device\DpShadow%d` | device per shadowed volume | shadow volume; user-mode path `\\.\DpShadow<hex>` |
| `\DosDevices\<volume>"%x"` | per-instance aliases | internal lookups |
| `\BaseNamedObjects\ShadowDefenderSharedMemory` | section | progress reporting (`Global\ShadowDefenderSharedMemory` from user mode) |

Device security descriptor, from the literal SDDL string in `.rdata`
(`D:P(A;;GA;;;SY)(A;;GA;;;LS)(A;;GA;;;BU)`):

```
OWNER: none (P = protected)
DACL : ACE 0  GENERIC_ALL  LocalSystem
       ACE 1  GENERIC_ALL  LocalService        (LS)
       ACE 2  GENERIC_ALL  Builtin Users       (BU)
```

All three principals get `GENERIC_ALL`; the DACL is protected (no inheritance).
This is broad by design because `Commit.exe` and `CmdTool.exe` must reach the
device from ordinary user sessions.

## 4. Shadow storage layout

Strings recovered from the driver define the on-disk model:

```
\??\C:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\        shadow area on volume C:
X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\%08x%08x    per-chunk cache file
\SystemRoot\diskpt.dat        file exclusion list
\SystemRoot\diskpt.crt        volume configuration table
\SystemRoot\diskptex.dat      registry exclusion list
X:\diskpt0.sys                per-volume map/cache file
\SystemRoot\dpstart.exe       boot-time agent (installed while shadowing)
```

### 4.1 Sector map

`StorInitializeVolumeContext` (`0x2800556EC`) and `StorFindMapFile`
(`0x280059FE8`) implement the sector redirector. Their trace strings name the
whole pipeline:

```
StorInitializeVolumeContext: FltDeviceIoControl(IOCTL_DISK_GET_DRIVE_GEOMETRY)
StorInitializeVolumeContext: BytesPerSector = %d
StorInitializeVolumeContext: FltDeviceIoControl(IOCTL_DISK_GET_PARTITION_INFO)
StorInitializeVolumeContext: MmAllocateContiguousMemory(%d)
StorInitializeVolumeContext: ERROR MapWindowCapacity = %d
StorInitializeVolumeContext: ERROR (MapTableSize = %d)
StorInitializeVolumeContext: AllocateBitmapSize doesn't match!
StorInitializeVolumeContext: IoCreateDevice / IoCreateSymbolicLink
StorFindMapFile: ZwCreateFile(%ws) / ZwReadFile(%ws) / ZwQueryInformationFile(%ws)
StorFindMapFile: ZwFsControlFile(%ws)
StorFindMapFile: invalid config info(%x-%x-%x)
StorFindMapFile: AllocateBitmapSize = %d
StorFindMapFile: map file size(%d) doesn't match volume size(%I64d)
StorFindMapFile: unrecognized volume
StorInitializeBitmap: ExAllocatePoolWithTag / FltReadWriteSectors
StorInitNtfsBitmap: Can't find NtfsAttributeData / find Resident attribute
```

Reconstructed shape (**inferred** from the above and the call graph):

* The driver queries geometry and partition info through
  `FltDeviceIoControl` on the volume it is attached to.
* It loads or creates a **bitmap** whose size is derived from the volume length
  (`AllocateBitmapSize`). One bit per allocatable unit marks whether that unit
  has been redirected.
* The map/cache file is `X:\diskpt0.sys`, validated by a header where three
  dwords must match (`invalid config info(%x-%x-%x)`) and by
  `map file size == volume size`. The 512-byte header is created with hidden +
  system + write-through attributes and, per `CmdTool.exe`, compression.
* Writing a previously untouched sector allocates a chunk in
  `X:\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\` named `%08x%08x` (two 32-bit
  ordinals), marks the bitmap and redirects subsequent reads.
* `StorInitNtfsBitmap` additionally parses NTFS metadata to locate the
  *resident* `$Bitmap` attribute so that the volume's free-space accounting stays
  consistent from the guest's point of view.
* `\??\C:\diskpt0.sys` and `\??\C:\{0D9DB60E-…}` are the hard-coded names; the
  `{\??\%s%x}` templates build them for arbitrary volumes.

### 4.2 Volume configuration table — `diskpt.crt`

Observed on the analysis host: 64 bytes in `C:\Windows\diskpt.crt`, i.e. four
16-byte records.

```
00000000  1a ef f2 c3  fc 7c 07 00   80 0b 09 00  00 00 00 00
00000010  2f dc 2c b3  e1 57 42 d6   78 d0 0d 00  01 00 00 00
00000020  6a cf 10 52  01 70 58 85   20 2a 15 00  03 00 00 00
00000030  c9 5d 23 eb  36 32 07 dc   40 9b 0b 00  03 00 00 00
```

Structure (**inferred**, consistent with `invalid config info(%x-%x-%x)` which
validates three dwords per record):

```c
struct dp_volume_config {     /* 16 bytes */
    u32 id;                   /* 0x00  volume identity (signature/offset) */
    u32 id_hi;                /* 0x04                                 */
    u32 size;                 /* 0x08  map/bitmap size (MB-ish)       */
    u32 state;                /* 0x0C  0 = normal, 1 / 3 = shadow     */
};
```

Record 0 has `state = 0` while records 1–3 have `state = 1, 3, 3`. On a host with
volumes C:, D:, E: this matches "C: normal, D: and E: configured", and the `3`
values are the persistent ("enter Shadow Mode on boot") flag. **This mapping is
inferred from the observed values and is the single most useful thing to confirm
next.**

### 4.3 Exclusion lists

`%SystemRoot%\diskpt.dat` (file exclusions) and `%SystemRoot%\diskptex.dat`
(registry exclusions) are, per `Defender.exe`, arrays of 1004-byte records:

```c
struct dp_exclusion {          /* 1004 bytes */
    u32  state;                /* 1 = active */
    WCHAR path[500];           /* NUL-terminated, UTF-16LE */
};
```

Both files exist on the analysis host and are **0 bytes** (no exclusions
configured). The commit list ("Commit Now") is stored as `diskpt0.dat` in the
driver's own naming and pushed by the GUI.

## 5. Registry shadowing

The driver redirects the registry as well as the file system. Its strings name
the shadow keys it creates and reads:

```
\REGISTRY\MACHINE\REGISTRY.SD.SYSTEM     <- \Device\<vol>\Windows\System32\Config\SYSTEM
\REGISTRY\MACHINE\REGISTRY.SD.SOFTWARE   <-  … \Config\SOFTWARE
\REGISTRY\MACHINE\REGISTRY.SD.SAM        <-  … \Config\SAM
\REGISTRY\MACHINE\REGISTRY.SD.SECURITY   <-  … \Config\SECURITY
\REGISTRY\MACHINE\REGISTRY.SD.USER.      <- \Device\<vol>\Users\<user>\NTUSER.DAT
\REGISTRY\USER\
*\REGISTRY.SD.*                          (filter pattern)
\REGISTRY\MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\ProfileList\
ProfileImagePath
```

It uses `ZwLoadKey` / `ZwUnloadKey` to mount the shadow hives under parallel
names, which is why the shadow copy of the registry is visible and rollback is
all-or-nothing.

## 6. Boot, hibernation and page/swap files

Strings and behaviour that place the driver in the boot path:

```
\REGISTRY\MACHINE\BCD00000000\Objects\{9dea862c-5cdd-4e70-acc1-f32b344d4795}\Elements\26000005
\SystemRoot\dpstart.exe
\hiberfil.sys   \pagefile.sys
\Device\%s%x\hiberfil.sys     \Device\%s%x\pagefile.sys
\Driver\VolSnap   \Driver\volsnap   \Driver\Disk
\FileSystem\Ntfs  \FileSystem\Fastfat  \FileSystem\exFat
```

* BCD element `0x26000005` on the `{9dea862c-…}` (current) object is
  **`HibernateEnabled`**. Shadow Defender writes it so that hibernation cannot
  restore a pre-shadow memory image over a shadowed volume. The GUI exposes the
  same setting as "Enable hibernation in Shadow Mode".
* `dpstart.exe` is installed into `%SystemRoot%` and referenced by
  `Session Manager\BootExecute` while a volume is scheduled to enter Shadow Mode
  at boot (`Uninstall.exe` removes it from `BootExecute`).
* `hiberfil.sys` and `pagefile.sys` are special-cased and served from the shadow
  volume, so a shadowed system volume still pages and hibernates correctly.
* The driver attaches to `\Driver\Disk`, `\Driver\VolSnap`, `Ntfs`, `Fastfat` and
  `exFat`, i.e. it interoperates with VSS and with the three file systems it must
  not corrupt.

## 7. In-memory layout and IRP dispatch

`.text` decompiles cleanly (275 functions). The dispatch is a single common
routine reached from the driver object.

| IRP major function | Value | Handler | Notes |
| --- | --- | --- | --- |
| `IRP_MJ_CREATE` | 0 | `0x28005F944` | |
| `IRP_MJ_CLOSE` | 2 | `0x280060344` | |
| `IRP_MJ_READ` | 3 | (inherited block) | pass-through for attached devices |
| `IRP_MJ_WRITE` | 4 | `0x280062260` | redirect path |
| `IRP_MJ_SET_INFORMATION` | 6 | `0x2800606F0` | |
| `IRP_MJ_FLUSH_BUFFERS` | 9 | `0x280062B18` | |
| `IRP_MJ_CLEANUP` | 18 | `0x2800600B0` | |
| `IRP_MJ_DEVICE_CONTROL` | 14 | `0x2800630D8` | **VM trampoline**, program `0x6B8F3` |
| `IRP_MJ_SHUTDOWN` | 16 | `0x280062D4C` | |
| `IRP_MJ_PNP` | 27 | `0x280063024` | |
| `IRP_MJ_FILE_SYSTEM_CONTROL` | 13 | minor 0/1/3 handlers `0x280063C88`, `0x280064148`, `0x280064860` | |

Common entry: `0x28005F5CC`. It also *installs* per-instance hooks into eleven
dispatch slots at run time — `0x28005C474`, `0x28005CCBC`, `0x28005D0A0`,
`0x28005DC1C`, `0x28005C7C4`, `0x28005CF18`, `0x28005DD58`, `0x28005CA40`,
`0x28005D718`, `0x28005E0D8`, `0x28005E294` — which is how each shadow volume
gets its own read/write path.

### 7.1 Named layers

Trace strings plus cross-references give these names:

| Address | Name | Role |
| --- | --- | --- |
| `0x280079008` | `DriverEntry` | pool tag `'dkpt'` (0x74706B64), copies `RegistryPath`, calls `PsGetVersion`, creates the secure control device, creates the `DpControl` symlink, then enters the vault |
| `0x280051960` | `StorDispatchIo` | storage dispatch, drives bitmap initialisation |
| `0x2800556EC` | `StorInitializeVolumeContext` | geometry, contiguous map window, bitmap, device + symlink creation |
| `0x280058DF4` | `StorInitializeBitmap` | bitmap load/format |
| `0x280059420` | `StorInitNtfsBitmap` | NTFS `$Bitmap` discovery |
| `0x280059FE8` | `StorFindMapFile` | locate/validate `diskpt0.sys` |
| `0x28005B1E8` | `StorPreInitBitmap` | pre-init (`ZwCreateFile`) |
| `0x28006BD6C` | `FsfTestVolume` | file-system-layer volume probe; reads the same config header |
| `0x2800B7DE9` | vault relocator | see `docs/02-obfuscation.md` |

### 7.2 Pool tags

`'dkpt'` (`0x74706B64`) is the module's allocation tag and is also the magic
first dword of the 136-byte (`0x88`) user↔driver request buffer used by
`Service.exe` and `CmdTool.exe`.

## 8. The control plane is bytecode

`IRP_MJ_DEVICE_CONTROL` does not contain an `IoControlCode` switch in native
code. It is a 15-byte stub:

```
0x2800630D8:  mov [rsp+8], rcx        ; save DeviceObject
              push rbx..r15 ; sub rsp, 88h
              mov rbx, [rcx+40h]      ; DeviceExtension
              mov r14, [rdx+0B8h]     ; IRP
              mov rbp, rdx
              mov rdi, rcx
              jmp loc_2800BBB22
0x2800BBB22:  push 6B8F3h             ; VM program RVA
              push 4Fh                ; entry handler index (79 = interpreter)
              jmp sub_2800B7DE9       ; relocator
```

So the entire device-control implementation — IOCTL demultiplexing, argument
validation, configuration, session and licensing — lives in the bytecode program
at RVA `0x6B8F3`. This is the reason a native-only reverse engineering of
Shadow Defender stops at the boundary of its most interesting functionality.

## 9. What the driver handles natively vs in the VM

| Subsystem | Location | Evidence |
| --- | --- | --- |
| Storage bitmap, map file, chunk redirection | native `.text` (`Stor*`) | trace strings + full pseudocode |
| File-system filter callbacks | native `.text` (`Fsf*`, per-IRP handlers) | clean decompilation |
| Registry shadow hives | native `.text` (registry strings, `ZwLoadKey`) | strings + xrefs |
| Boot/hibernation/BCD | native `.text` + VM | BCD path string, `dpstart.exe` |
| **IOCTL parsing and control protocol** | **VM program `0x6B8F3`** | trampoline above |
| **Configuration and session management** | **VM** | trampolines from `Service.exe` paths |

## 10. Open items

See `docs/09-unknowns-and-roadmap.md`. The three highest-value unknowns are the
IOCTL demultiplexer in program `0x6B8F3`, the exact `dp_volume_config` field
semantics, and the `diskpt0.sys` map-file header.
