/*
 * sd.h — Shadow Defender 1.5.0.726 reconstructed interface definitions.
 *
 * RECONSTRUCTION, NOT ORIGINAL SOURCE.
 *
 * Every structure and constant here is derived from the analysis in
 * docs/03-driver-diskpt.md, docs/04-service-protocol.md,
 * docs/07-config-and-formats.md and docs/08-licensing-and-crypto.md.
 * Fields whose layout is not established are marked INFERRED or UNKNOWN.
 *
 * Verified artifact identities (SHA-256):
 *   diskpt.sys      6ffd78b5954064bba7370af51b2e4f1358424f542682218a1121a375f3903583
 *   Service.exe     dbb55e76877232405803ed752c3eb7a7eb795c00ce9f69ff3f86a57f5c5fdfb8
 *   Defender.exe    f01d686574c034b135321f650e6483144fb5d8c3c32d341e586af45220d0a6fc
 *   CmdTool.exe     5dcf3b773876662aa1a9f0c01722a815095c86ff2225ab035c94e1f2a4ab9ac7
 */
#ifndef SD_H
#define SD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* ==========================================================================
 * 1. Names, GUIDs and object names
 * ========================================================================== */

/* User-mode path of the driver's control device. OBSERVED. */
#define DP_CONTROL_DEVICE_PATH      L"\\\\.\\DpControl"

/* Kernel object names. OBSERVED (driver .rdata). */
#define DP_NT_CONTROL_DEVICE        L"\\FileSystem\\Filters\\DpControl"
#define DP_NT_CONTROL_DEVICE_ALT    L"\\FileSystem\\DpControl"      /* fallback, taken on STATUS_OBJECT_NAME_COLLISION */
#define DP_NT_CONTROL_SYMLINK       L"\\DosDevices\\DpControl"
#define DP_NT_SHADOW_DEVICE_FMT     L"\\Device\\DpShadow%d"          /* INFERRED: %d = volume ordinal */
#define DP_NT_SHADOW_SYMLINK_FMT    L"\\DosDevices\\%s%x"

/* Device security. OBSERVED as the literal SDDL string in the driver. */
#define DP_CONTROL_SDDL             L"D:P(A;;GA;;;SY)(A;;GA;;;LS)(A;;GA;;;BU)"

/* Progress section. OBSERVED: driver creates, user mode maps. */
#define DP_SHARED_MEMORY_NAME       L"Global\\ShadowDefenderSharedMemory"
#define DP_SHARED_MEMORY_BYTES      4096
#define DP_SHARED_MEMORY_PROGRESS   0   /* DWORD[0] = percent complete 0..100 */

/* Single-instance / latch objects. OBSERVED. */
#define DP_MUTEX_GUI                L"Global\\{44EE29B3-FD3D-4E65-BDFC-ABDA82EE76B0}"
#define DP_MUTEX_DAEMON             L"Local\\Shadow Defender Daemon Mutex"
#define DP_EVENT_SERVICE_DAEMON     L"Global\\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}"

/* Service registered by Service.exe. OBSERVED. */
#define DP_SERVICE_NAME             L"{0CBD4F48-3751-475D-BE88-4F271385B672}"
#define DP_SERVICE_DISPLAY          L"Shadow Defender Service"
#define DP_DRIVER_SERVICE_NAME      L"diskpt"

/* Shell extension COM identity. OBSERVED (ShellExt.dll RGS resources 101/102). */
#define DP_SHELLEXT_CLSID           L"{5EE8E9E6-2853-4D28-B2DE-6529EDA0A294}"
#define DP_SHELLEXT_PROGID          L"DefenderShellExt.ContextMenuExt.1"
#define DP_SHELLEXT_APPID           L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}"
#define DP_SHELLEXT_TYPELIB         L"{3A5C2EFF-619A-481D-8D5D-A6968DB02AF1}"

/* Hidden trial-timestamp key. OBSERVED. */
#define DP_TRIAL_CLSID_REGKEY       L"CLSID\\{78C3F4BC-C7BC-48E4-AD72-2DD16F6704A9}"

/* Volume shadow namespace. OBSERVED (driver .rdata). */
#define DP_SHADOW_DIR_GUID          L"{0D9DB60E-B0EA-4d53-A392-A5D274956846}"
#define DP_CHUNK_FILE_FMT           L"%s\\%s\\%08x%08x"       /* INFERRED: two 32-bit ordinals */
#define DP_SHADOW_MAP_FILE          L"diskpt0.sys"            /* per volume, at the volume root */
#define DP_ROOT_EXCLUSION_FILE      L"\\SystemRoot\\diskpt.dat"
#define DP_ROOT_COMMIT_FILE         L"\\SystemRoot\\diskpt0.dat"
#define DP_ROOT_REGISTRY_FILE       L"\\SystemRoot\\diskptex.dat"
#define DP_ROOT_CONFIG_FILE         L"\\SystemRoot\\diskpt.crt"
#define DP_ROOT_BOOT_AGENT          L"\\SystemRoot\\dpstart.exe"

/* Registry shadow hive names. OBSERVED. */
#define DP_SHADOW_HIVE_SYSTEM       L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SYSTEM"
#define DP_SHADOW_HIVE_SOFTWARE     L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SOFTWARE"
#define DP_SHADOW_HIVE_SAM          L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SAM"
#define DP_SHADOW_HIVE_SECURITY     L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SECURITY"
#define DP_SHADOW_HIVE_USER_PREFIX  L"\\REGISTRY\\MACHINE\\REGISTRY.SD.USER."

/* ==========================================================================
 * 2. Driver control protocol
 * ========================================================================== */

/* Request/response envelope, 136 bytes. OBSERVED magic and size; the meaning of
 * the payload bytes is UNKNOWN (parsed by VM program RVA 0x6B8F3). */
#define DP_MSG_MAGIC                0x74706B64u     /* 'dkpt' — also the pool tag */
#define DP_MSG_BYTES                0x88            /* 136 */

typedef struct dp_msg {
    uint32_t magic;                 /* DP_MSG_MAGIC */
    union {
        uint8_t  raw[DP_MSG_BYTES - 4];
        struct {
            /* UNKNOWN: operation selector, arguments, result.
             * Recoverable only by decoding VM program 0x6B8F3.
             * See docs/09-unknowns-and-roadmap.md §2.1. */
            uint32_t op;
            uint32_t arg[32];
        } u;
    } payload;
} dp_msg;

/* IOCTL codes. DeviceType 0x8000, METHOD_BUFFERED, FILE_ANY_ACCESS unless noted.
 * Values marked "fixed" are literal in the user-mode images; values marked
 * "derived" are computed at runtime from the installation GUID and therefore
 * differ per install. */
#define DP_CTL_GET_INSTALL_GUID     0x800030A0u     /* fixed; 0x88-byte in/out */
#define DP_CTL_SESSION_BASE         0x800025E4u     /* derived; real = BASE + K */
#define DP_CTL_DEVICE_OPEN_PROBE    0x80000D18u     /* fixed; CTL_CODE(0x8000,0x346,BUFFERED,ANY) */
#define DP_CTL_VOLUME_CLOSE         0x80002D48u     /* fixed; CTL_CODE(0x8000,0xB52,BUFFERED,ANY);
                                                       sent to \\.\X:, tolerates 0x20000001 */

/* FSCTLs used on \\.\X: directly. OBSERVED. */
#define DP_FSCTL_LOCK_VOLUME        0x00090018u
#define DP_FSCTL_DISMOUNT_VOLUME    0x0009001Cu
#define DP_FSCTL_UNLOCK_VOLUME      0x00090020u
#define DP_FSCTL_SET_COMPRESSION    0x0009C040u
#define DP_FSCTL_PRIVATE_0X98144    0x00098144u     /* CTL_CODE(9,0x51,BUFFERED,FILE_WRITE_ACCESS);
                                                       40/0x28-byte input, DWORD[0] = 0x4000 */
#define DP_FSCTL_PRIVATE_0X560000   0x00560000u     /* SD used-space query */

/* Query the installation GUID, which salts the password hash and offsets the
 * derived IOCTLs. Source: HKLM\SYSTEM\CurrentControlSet\Services\diskpt\GUID,
 * or IOCTL DP_CTL_GET_INSTALL_GUID. */
typedef struct dp_install_guid {
    uint8_t  guid[16];              /* INFERRED: 16-byte GUID; returned inside the 0x88 buffer */
    uint8_t  reserved[DP_MSG_BYTES - 4 - 16];
} dp_install_guid;

/* ==========================================================================
 * 3. Persistent formats
 * ========================================================================== */

/* ---- user.dat : INI, section [common], decimal-free keys, values are text ---- */

#define DP_USERDAT_SECTION          "common"
#define DP_USERDAT_SECTION_SPACE    "space"

/* Keys. OBSERVED.
 *   hash        lowercase hex MD5 of UTF-16LE(guid ++ password)
 *   hash2       serial, obfuscated with the 7-lane additive cipher (key
 *               {3,7,8,2,9,5,4}); see docs/08-licensing-and-crypto.md
 *   sn          display serial number (can be empty)
 *   time        Unix timestamp, seconds
 *   continue    trial continuation flag
 *   volume      drive letters that are configured (e.g. "CD")
 *   RAM         write cache in MB, 0 = disabled
 *   encrypt     encrypt write cache, 0/1
 *   hibernation allow hibernation in Shadow Mode, 0/1
 *   autostart   start with Windows, 0/1
 *   trayicon    tray icon enabled, 0/1
 *   tip         desktop tip enabled, 0/1
 *   tippos      desktop tip position (user-scope file only)
 *   shellext    shell context menu: 0 = off, 1 = on, 2 = on and require password
 *   checkupdate automatic update check, 0/1
 * Section [space]:
 *   disable     disable low-space notification, 0/1
 *   default     default threshold in MB
 *   <letter>    per-volume threshold in MB
 */

#define DP_UD_HASH          "hash"
#define DP_UD_HASH2         "hash2"
#define DP_UD_SN            "sn"
#define DP_UD_TIME          "time"
#define DP_UD_CONTINUE      "continue"
#define DP_UD_VOLUME        "volume"
#define DP_UD_RAM           "RAM"
#define DP_UD_ENCRYPT       "encrypt"
#define DP_UD_HIBERNATION   "hibernation"
#define DP_UD_AUTOSTART     "autostart"
#define DP_UD_TRAYICON      "trayicon"
#define DP_UD_TIP           "tip"
#define DP_UD_TIPPOS        "tippos"
#define DP_UD_SHELLEXT      "shellext"
#define DP_UD_CHECKUPDATE   "checkupdate"

#define DP_SHELLEXT_OFF     0
#define DP_SHELLEXT_ON      1
#define DP_SHELLEXT_PASSWORD 2

#define DP_HASH_HEX_BYTES   32      /* MD5 rendered as lowercase hex */
#define DP_BLANK_PASSWORD_SENTINEL "@BLANKPWD"

/* ---- diskpt.crt : the per-volume configuration table ---- */

/* 16-byte records. OBSERVED size (64 bytes) and record grouping; the identity
 * and size field meanings are INFERRED, the state field is INFERRED from the
 * observed values 0 / 1 / 3. See docs/09-unknowns-and-roadmap.md §2.4. */
typedef struct dp_volume_config {
    uint32_t id;                    /* 0x00  volume identity        INFERRED */
    uint32_t id_hi;                 /* 0x04  volume identity high   INFERRED */
    uint32_t size;                  /* 0x08  map/bitmap size        INFERRED */
    uint32_t state;                 /* 0x0C  0 normal, 1/3 shadow   INFERRED */
} dp_volume_config;

#define DP_VOLCFG_RECORD_BYTES      16
#define DP_VOLCFG_RECORDS           4       /* observed: 64 bytes total */

#define DP_VOLSTATE_NORMAL          0u
#define DP_VOLSTATE_SHADOW          1u
#define DP_VOLSTATE_PERSIST         3u      /* "enter Shadow Mode on boot"  INFERRED */

/* ---- exclusion / commit lists: 1004-byte records ---- */

typedef struct dp_exclusion {
    uint32_t state;                 /* 1 = active */
    uint16_t path[500];             /* UTF-16LE, NUL-terminated */
} dp_exclusion;

#define DP_EXCLUSION_BYTES          (sizeof(dp_exclusion))    /* 1004 */

/* ---- diskpt0.sys : per-volume map/cache file ---- */

/* Header is 512 bytes; only these facts are established:
 *   - created hidden + system + write-through, and compressed
 *   - size is computed from the volume's disk geometry
 *   - the driver validates three dwords ("invalid config info(%x-%x-%x)")
 *   - the file size must equal the volume size
 * The bitmap/table geometry fields are UNKNOWN. See roadmap §2.5. */
#define DP_MAP_HEADER_BYTES         512

typedef struct dp_map_header {
    uint32_t magic_or_version;      /* UNKNOWN */
    uint32_t field04;               /* INFERRED: cleared on creation */
    uint32_t field08;               /* UNKNOWN */
    uint32_t field0c;               /* INFERRED: cleared on creation */
    uint8_t  rest[DP_MAP_HEADER_BYTES - 16];   /* UNKNOWN */
} dp_map_header;

/* ==========================================================================
 * 4. Registration code (validation only)
 * ========================================================================== */

/* 25 characters over a 31-symbol alphabet: no I, no L, no O, no 0, no 1. */
#define DP_REGCODE_LEN              25
#define DP_REGCODE_ALPHABET         "ABCDEFGHJKMNPQRSTUVWXYZ23456789"
#define DP_REGCODE_BASE             31

/* Validates an existing registration code. This function only *checks* a code
 * the user already owns; code generation is deliberately not provided. */
int dp_regcode_verify(const char *code25);

/* ==========================================================================
 * 5. Password
 * ========================================================================== */

/* hash = lowercase_hex(MD5(UTF-16LE(install_guid ++ password)))
 * The installation GUID is the "GUID" value under
 * HKLM\SYSTEM\CurrentControlSet\Services\diskpt, so a user.dat copied to another
 * machine will not authenticate. */
int dp_password_hash(const char *install_guid_ascii,      /* e.g. "{fd1aecc8-...}" */
                     const uint16_t *password_utf16,      /* NUL-terminated */
                     char out_hex[DP_HASH_HEX_BYTES + 1]);

/* An empty password is stored as MD5(guid ++ "@BLANKPWD"), not as MD5(guid). */
int dp_password_is_blank(const char stored_hash_hex[DP_HASH_HEX_BYTES + 1],
                         const char *install_guid_ascii);

/* ==========================================================================
 * 6. Serial storage obfuscation (hash2)
 * ========================================================================== */

/* A 7-lane additive/rolling cipher over int16 lanes. This is storage
 * obfuscation, not encryption. Key as corrected in
 * docs/08-licensing-and-crypto.md: {3,7,8,2,9,5,4}. */
#define DP_HASH2_KEY_LANES          7
extern const int16_t dp_hash2_key[DP_HASH2_KEY_LANES];

/* Decode `in` into `out` (both NUL-terminated ASCII). Returns 0 on success. */
int dp_hash2_decode(const char *in, char *out, size_t out_bytes);
/* Encode `in` into `out`. Returns 0 on success. */
int dp_hash2_encode(const char *in, char *out, size_t out_bytes);

/* ==========================================================================
 * 7. res.ini UI string table
 * ========================================================================== */

/* Parses res.ini ([common], decimal keys, '\n' unescaped) and returns the text
 * for `id`. Location: HKLM\SOFTWARE\Shadow Defender\Path, else the executable's
 * directory. */
int dp_res_string(int id, wchar_t *out, size_t out_wchars);

/* ==========================================================================
 * 8. Update check
 * ========================================================================== */

#define DP_UPDATE_URL \
    L"http://www.shadowdefender.com/checkupdate-3011ca199c614b0c96a84f435046c4c5.php"
/* POST body: "version=<version>&extra=<extra>" */

#ifdef __cplusplus
}
#endif

#endif /* SD_H */
