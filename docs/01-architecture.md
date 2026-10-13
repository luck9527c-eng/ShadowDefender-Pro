# Shadow Defender — System Architecture

> Scope: Shadow Defender 1.5.0.726 as installed on the analysis host.
> Status: architecture and flows are **observed** where an address or artifact is
> cited and **inferred** where marked. Per-component detail lives in
> `docs/03` … `docs/08`.

## 1. Design summary

Shadow Defender is a **whole-volume redirector with a file-system and registry
filter on top**. It is not a sandbox in the security sense (it does not contain
malicious code); it is a *rollback* system: the guest operating system keeps
using its volumes normally, but every mutation is diverted into a per-volume
cache that can be dropped on reboot.

Three properties shape every design decision:

1. **It must load before the file systems.** The driver is `Start = 0`
   (`SERVICE_BOOT_START`) in the `System Bus Extender` load group, so it is
   present in the device stack before `Ntfs` mounts a volume.
2. **It must be invisible to the guest.** Volume free space, registry contents,
   paging and hibernation all have to keep working, so the driver maintains a
   consistent view rather than merely blocking writes.
3. **It must survive its own failure.** Because dropping the cache is equivalent
   to a reboot, the cache is a *separate file* per volume
   (`X:\diskpt0.sys`), not a memory structure, and the volume's configuration
   table (`diskpt.crt`) is a plain file in `%SystemRoot%`.

## 2. Component responsibilities

| Component | Process / mode | Responsibility |
| --- | --- | --- |
| `diskpt.sys` | kernel, boot-start | The redirector. Owns the volume set, the sector bitmap and cache, the file-system filter callbacks, the registry shadow hives, the boot/hibernation handling, and the device interface `\DpControl`. |
| `Service.exe` | LocalSystem service | Enumerates volumes and watches for volume arrival/removal, creates and removes the per-volume artifacts, bootstraps the driver's volume set, and is the privileged half used by the GUI and CLI. Registered under a GUID service name and additionally in the `SafeBoot\Minimal`/`Network` keys so it starts in safe mode. |
| `Defender.exe` | user, on demand | The GUI. Reads and writes configuration, issues mode changes, drives commit, and shows progress from the shared memory section. |
| `DefenderDaemon.exe` | user, per session | Tray icon, desktop tip, low-free-space balloons, global hotkey. Survives GUI exit so the tray state persists. |
| `CmdTool.exe` | user, on demand | Scriptable administration; a strict subset of the GUI's operations. |
| `Commit.exe` | user, on demand from Explorer | Commits an explicit path list that came from the shell extension. |
| `ShellExt.dll` | in-process, Explorer | Adds one context-menu verb when a selected drive is in Shadow Mode, and forwards the selection to `Commit.exe`. |
| `Uninstall.exe` | user, on demand | Removes the product in a fixed order that unwires the boot path first. |

## 3. State ownership

Shadow Defender splits state three ways, and the split explains most of its
observable behaviour.

| State | Lives in | Survives a shadow session? |
| --- | --- | --- |
| Which volumes are shadowed now | driver, and `diskpt.crt` | yes — that is the point |
| The redirect bitmap and cached sectors | `X:\diskpt0.sys` and `X:\{0D9DB60E-…}\` | no — discarded or committed on exit |
| User settings, password, serial | `user.dat` | **yes** — the driver write-throughs it (service value `Sync` includes `C:\Users\*\Shadow Defender\user.dat`) |
| File / registry exclusion lists | `%SystemRoot%\diskpt.dat`, `%SystemRoot%\diskptex.dat` | yes, for the same reason |
| Trial clock | `HKCR\CLSID\{78C3F4BC-…}` | yes — it must not be resettable by shadowing |
| Progress | `Global\ShadowDefenderSharedMemory` | n/a, transient |

The `Sync` service value is the mechanism behind the last two: it lists the files
the driver must commit to the original volume even while the volume is shadowed.
`bootstat.dat` is included so the boot-optimisation state stays truthful.

## 4. Operating flows

### 4.1 Enter Shadow Mode

```
Defender.exe  ── confirm ─┬─> CreateFileW("\\.\DpControl", 0x80 /* FILE_READ_ATTRIBUTES */,
                           │               FILE_SHARE_READ|WRITE, OPEN_EXISTING)
                           ├─> DeviceIoControl(0x800030A0)         read installation GUID
                           └─> DeviceIoControl(0x800025E4 + K, …)  push the requested volume set
                                          │
                                          ▼
                        diskpt.sys  IRP_MJ_DEVICE_CONTROL  (VM program 0x6B8F3)
                                          │
                     ┌────────────────────┴────────────────────┐
                     ▼                                         ▼
        per volume: create X:\diskpt0.sys            update C:\Windows\diskpt.crt
        (hidden+system+write-through+compressed,     (state slot for the volume)
         512-byte header, size from geometry)
                     │
                     ▼
        StorInitializeVolumeContext: geometry,
        map window, bitmap, \Device\DpShadow<n>,
        \DosDevices\DpShadow<n>, attach to the stack
                     │
                     ▼
        if "enter on boot" was chosen: install
        %SystemRoot%\dpstart.exe and add it to
        Session Manager\BootExecute; write BCD
        element 0x26000005 (HibernateEnabled)
```

Reconstructed from: `Defender.exe` worker `sub_14000F218` (mode 1) and
`sub_140022BA0`; the `mountvol X: /s|/d` trick used to mount the EFI system
partition for the BCD write; `Service.exe` `HandlerProc` device-event paths; and
the driver's own `Stor*` trace strings. See `docs/04-service-protocol.md` and
`docs/07-config-and-formats.md`.

**Consequence for the user:** entering Shadow Mode is not instantaneous and is
reported as a percentage through `Global\ShadowDefenderSharedMemory`, because the
driver has to lay down a map file whose size is a function of the volume size.

### 4.2 Write path while shadowed

```
application write
     │
     ▼
  Ntfs  ──>  volume stack  ──>  fvevol (BitLocker)  ──>  diskpt  ──>  iorate  ──>  rdyboost
                                                          │
                       bitmap says this sector was never  │
                       redirected?                        │
                            ├── yes ──> allocate a chunk in X:\{0D9DB60E-…}\ (%08x%08x),
                            │           set the bitmap bit, write the *original* sector
                            │           content there once, then write the new data
                            └── no  ──> write into the existing chunk
                                                          │
                                          read back: chunk if redirected,
                                                     original volume otherwise
```

The bitmap is per allocatable unit, so untouched sectors cost only one bit.
`StorInitNtfsBitmap` additionally walks NTFS metadata to find the *resident*
`$Bitmap` attribute and patches it, so that the volume's own free-space
accounting matches what the guest sees after redirecting a write.

`diskpt` is the *volume* class LowerFilter below `fvevol`, i.e. it sees
plaintext I/O and therefore works on BitLocker-encrypted volumes.

### 4.3 Commit

Commit has three distinct forms, all reaching the same driver engine:

| Form | Entry point | Selector |
| --- | --- | --- |
| "Commit Now" page | `Defender.exe` → worker mode `2` → `sub_140063C20` | a user-edited path list |
| Shell context menu | `ShellExt.dll` → `Commit.exe "<p1>|…|"` → `sub_140004670` | the Explorer selection |
| Command line | `CmdTool.exe /commit:PATH` | one path or directory |

Options observed in the UI and the driver: commit only *deleted* files
(`res.ini` 150006), and do not recurse into sub-folders (150003). The GUI's
commit engine is `sub_14000B85C`; it enumerates `\\.\DpShadow<id>\` to discover
ghost/deleted entries. Progress again flows through the shared memory section,
and the GUI retries a failing volume up to four times (`CB0`/`3C0` timeouts).

### 4.4 Exit Shadow Mode

Exit is the inverse of entry, with one extra requirement: the volume may be in
use.

1. The GUI asks the driver to drop the volume from the shadow set
   (`Defender.exe` worker mode `2`).
2. The driver detaches `\Device\DpShadow<n>`; if any handle is still open on the
   volume, the change cannot take effect immediately, which is exactly the case
   the UI warns about (`res.ini` 130001) and offers "Force dismount volume"
   (130008) for — implemented by the `FSCTL_LOCK_VOLUME` / `FSCTL_DISMOUNT_VOLUME`
   / `FSCTL_UNLOCK_VOLUME` trio.
3. If the volume could not be released, the pending state is written into
   `diskpt.crt` and the user is offered reboot or shutdown (140000–140008); the OS
   then exits Shadow Mode during shutdown.
4. `Service.exe` removes `X:\diskpt0.sys` and the chunk directory, and clears the
   volume's record in `diskpt.crt`.

Observed detail: after a successful exit the driver deletes
`X:\{0D9DB60E-…}\diskpt0.sys` as well (`Service.exe` `sub_1400018A0`), and it
tolerates `ERROR 0x20000001` from `IOCTL 0x80002D48` as a non-fatal condition.

### 4.5 Exclusion lists

Two lists, both pushed to the driver as files:

* **File/folder exclusions** — `%SystemRoot%\diskpt.dat`. While a volume is
  shadowed, writes under an excluded path are committed to the original volume
  immediately *and silently* (the UI warns about this in `res.ini` 1013 and
  30007).
* **Registry exclusions** — `%SystemRoot%\diskptex.dat`, same semantics for the
  shadowed hives.

Both are arrays of 1004-byte records (`u32 state; WCHAR path[500]`). The GUI can
also save/load a list to a user-chosen file (30009/30010, 40009/40010,
60008/60009). The UI refuses to add paths that are already inside a shadowed
volume when that would be meaningless (30012/30013).

### 4.6 Boot-time behaviour

While "Enter Shadow Mode on boot" is armed for a volume:

* `%SystemRoot%\dpstart.exe` is installed and referenced from
  `HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\BootExecute`.
* `diskpt.crt` carries the persistent state for the volume (`state = 3` in the
  observed records, see `docs/03-driver-diskpt.md` §4.2).
* BCD element `0x26000005` on the current boot entry exposes the
  "Enable hibernation in Shadow Mode" setting, because resuming from hibernation
  would restore a pre-shadow memory image.

### 4.7 Registry shadowing

Registry files are ordinary files, so the same bitmap engine protects them; what
the driver adds is *mounting*: it uses `ZwLoadKey`/`ZwUnloadKey` to expose the
shadow copies as parallel hives named
`\REGISTRY\MACHINE\REGISTRY.SD.SYSTEM`, `…\REGISTRY.SD.SOFTWARE`,
`…\REGISTRY.SD.SAM`, `…\REGISTRY.SD.SECURITY` and `…\REGISTRY.SD.USER.<sid>`,
sourced from `\Device\<shadow volume>\Windows\System32\Config\*` and each
profile's `NTUSER.DAT`. Shadowed users are found through
`…\ProfileList\<sid>\ProfileImagePath`.

## 5. Inter-process communication map

There is **no named pipe and no window-message protocol**. Every component talks
to the driver directly, and the only cross-process data exchange is shared
memory plus two mutexes and one event:

| Mechanism | Name | Used by |
| --- | --- | --- |
| Device | `\\.\DpControl` | GUI, Service, CmdTool, Commit |
| Device | `\\.\DpShadow<hex>` | GUI, Service (commit/status) |
| Device | `\\.\X:` + private FSCTLs | GUI, Service, CmdTool |
| Section | `Global\ShadowDefenderSharedMemory` | driver writes percent; GUI/CmdTool read |
| Mutex | `Global\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}` | single GUI instance |
| Mutex | `Local\Shadow Defender Daemon Mutex` | single daemon instance |
| Event | `Global\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}` | Service ↔ daemon latch |
| Process launch | `ShellExecuteW("Defender.exe", "/exit")` | daemon "Exit All Shadow Modes" |
| Process launch | `ShellExecuteW(…\Commit.exe, "<p1>|…|")` | shell extension → commit |

## 6. Security model (as designed, not as a claim)

* The control device grants `GENERIC_ALL` to `SYSTEM`, `LocalService` and
  `Builtin Users`. Any interactive user can therefore issue control IOCTLs; the
  *policy* gate is the password, enforced in user mode by the GUI and CLI, not by
  the driver.
* The password never reaches the driver. It is hashed in user mode as
  `MD5(UTF16LE(serviceGUID + password))` and only that hash lives in `user.dat`.
  The per-installation `serviceGUID` means a `user.dat` copied to another machine
  will not authenticate.
* The write cache can optionally be encrypted (`Encrypt write cache` in the
  Administration page); the driver carries RC4 KSA/PRGA routines for it.
* The product's own anti-tamper is *obfuscation*, not access control: the
  `.reloc`/VM scheme in `docs/02-obfuscation.md`. It hides behaviour from
  analysts; it does not stop a determined attacker with kernel privileges, and
  the driver runs at boot-start with full kernel authority.

## 7. Failure modes designed into the product

| Situation | Designed response |
| --- | --- |
| Low free space on a shadowed volume | balloon from the daemon using per-volume thresholds (`[space]` in `user.dat`, res.ini 160000–160007); res.ini 1016 and 50010–50011 document the warning. |
| Volume busy on exit | force-dismount option, else defer to reboot/shutdown (res.ini 130001, 130008, 140000–140008). |
| Hibernation while shadowed | BCD `HibernateEnabled` is forced off unless the user explicitly allows it (res.ini 50015). |
| A file must not be rolled back | exclusion lists, always committed immediately. |
| Cache file missing or invalid | driver validates the map file (size vs volume size, three header dwords) and refuses the volume (`StorFindMapFile: invalid config info`, `unrecognized volume`). |
| Service missing at boot | service is registered in `SafeBoot\Minimal` and `SafeBoot\Network`. |

## 8. Where the design is opaque

The control plane is bytecode (`docs/02-obfuscation.md`). Everything in this
document about *what* a control operation does derives from the user-mode side,
the driver's native `.text`, the shipped strings and observed artifacts.
The precise wire format of the `\\.\DpControl` payload above the `'dkpt'` magic,
and the exact IOCTL demultiplexing, live in VM program `0x6B8F3` and remain the
main open item — see `docs/09-unknowns-and-roadmap.md`.
