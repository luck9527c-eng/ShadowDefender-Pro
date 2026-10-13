/*
 * dp_config.c — Shadow Defender configuration, password and string-table code.
 *
 * RECONSTRUCTION, NOT ORIGINAL SOURCE.
 * Derived from docs/05-user-interface.md, docs/07-config-and-formats.md and
 * docs/08-licensing-and-crypto.md. Written to be self-contained and testable.
 *
 * Original implementation references (for cross-checking against the vendor
 * binaries):
 *   user.dat reader/writer ...... Defender.exe  (config load/save)
 *   password hash ............... Defender.exe  sub_140002864, sub_140012F34
 *   registration verify ......... Defender.exe  sub_14000328C, sub_140002FF4
 *   hash2 cipher ................ Defender.exe  sub_14000FD28, sub_14000FBDC
 *   res.ini loader .............. Defender.exe  sub_14000D8DC  (GetResString)
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "sd.h"

/* ==========================================================================
 * 1. MD5 (RFC 1321), compact reference implementation.
 *    Shadow Defender uses MD5 for the password hash and for the registration
 *    code check; both were confirmed from the DLL constants in Defender.exe
 *    (sub_140002864, sub_140002FF4).
 * ========================================================================== */

typedef struct { uint32_t h[4]; uint64_t len; uint8_t buf[64]; size_t n; } md5_ctx;

static const uint32_t md5_k[64] = {
    0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
    0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,
    0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
    0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,
    0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
    0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
    0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
    0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391
};
static const uint8_t md5_s[64] = {
    7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,
    5, 9,14,20,5, 9,14,20,5, 9,14,20,5, 9,14,20,
    4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,
    6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21
};

static uint32_t rol32(uint32_t x, unsigned c) { return (x << c) | (x >> (32 - c)); }

static void md5_block(md5_ctx *c, const uint8_t *p)
{
    uint32_t m[16], a = c->h[0], b = c->h[1], d = c->h[2], e = c->h[3];
    for (int i = 0; i < 16; i++)
        m[i] = (uint32_t)p[i*4] | ((uint32_t)p[i*4+1] << 8)
             | ((uint32_t)p[i*4+2] << 16) | ((uint32_t)p[i*4+3] << 24);
    for (int i = 0; i < 64; i++) {
        uint32_t f; int g;
        if (i < 16)      { f = (b & d) | (~b & e);        g = i; }
        else if (i < 32) { f = (e & b) | (~e & d);        g = (5*i + 1) & 15; }
        else if (i < 48) { f = b ^ d ^ e;                 g = (3*i + 5) & 15; }
        else             { f = d ^ (b | ~e);              g = (7*i) & 15; }
        uint32_t tmp = e; e = d; d = b;
        b = b + rol32(a + f + md5_k[i] + m[g], md5_s[i]);
        a = tmp;
    }
    c->h[0] += a; c->h[1] += b; c->h[2] += d; c->h[3] += e;
}

static void md5_init(md5_ctx *c)
{
    c->h[0] = 0x67452301; c->h[1] = 0xefcdab89;
    c->h[2] = 0x98badcfe; c->h[3] = 0x10325476;
    c->len = 0; c->n = 0;
}

static void md5_update(md5_ctx *c, const void *data, size_t len)
{
    const uint8_t *p = data;
    c->len += len;
    while (len) {
        size_t take = 64 - c->n;
        if (take > len) take = len;
        memcpy(c->buf + c->n, p, take);
        c->n += take; p += take; len -= take;
        if (c->n == 64) { md5_block(c, c->buf); c->n = 0; }
    }
}

static void md5_final(md5_ctx *c, uint8_t out[16])
{
    uint8_t pad[72]; size_t padlen;
    uint64_t bits = c->len * 8;
    memset(pad, 0, sizeof(pad));
    pad[0] = 0x80;
    padlen = (c->n < 56) ? (56 - c->n) : (120 - c->n);
    md5_update(c, pad, padlen);
    uint8_t lenle[8];
    for (int i = 0; i < 8; i++) lenle[i] = (uint8_t)(bits >> (8*i));
    md5_update(c, lenle, 8);            /* note: c->len now inflated; bits kept */
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            out[i*4+j] = (uint8_t)(c->h[i] >> (8*j));
}

/* ==========================================================================
 * 2. Password
 *
 * hash = lowercase_hex(MD5(UTF-16LE(install_guid_ascii ++ password)))
 * Blank  = lowercase_hex(MD5(UTF-16LE(install_guid_ascii ++ "@BLANKPWD")))
 *
 * The installation GUID is the "GUID" value under
 * HKLM\SYSTEM\CurrentControlSet\Services\diskpt. Observed on the analysis host:
 * {fd1aecc8-b1e9-4b92-a188-daa06486e05b}, and the stored hash
 * eb1997a8cf8000a3d43ce85f0be18268 is exactly the blank sentinel — that install
 * has no password set.
 * ========================================================================== */

static void hash_hex_of(const char *guid_ascii, const uint16_t *suffix,
                        char out[DP_HASH_HEX_BYTES + 1])
{
    md5_ctx c; uint8_t d[16];
    static const char hexd[] = "0123456789abcdef";

    md5_init(&c);
    /* concat guid (ASCII) and suffix (already UTF-16LE) as UTF-16LE bytes */
    if (guid_ascii) {
        uint8_t tmp[256];
        size_t n = 0;
        for (const char *p = guid_ascii; *p && n + 2 <= sizeof(tmp); p++) {
            tmp[n++] = (uint8_t)*p;
            tmp[n++] = 0;
        }
        md5_update(&c, tmp, n);
    }
    if (suffix) {
        size_t n = 0;
        while (suffix[n]) n++;
        md5_update(&c, suffix, n * 2);
    }
    md5_final(&c, d);
    for (int i = 0; i < 16; i++) {
        out[i*2]   = hexd[d[i] >> 4];
        out[i*2+1] = hexd[d[i] & 0xF];
    }
    out[32] = 0;
}

int dp_password_hash(const char *install_guid_ascii,
                     const uint16_t *password_utf16,
                     char out_hex[DP_HASH_HEX_BYTES + 1])
{
    if (!install_guid_ascii || !password_utf16 || !out_hex)
        return -1;
    hash_hex_of(install_guid_ascii, password_utf16, out_hex);
    return 0;
}

int dp_password_is_blank(const char stored_hash_hex[DP_HASH_HEX_BYTES + 1],
                         const char *install_guid_ascii)
{
    char expect[DP_HASH_HEX_BYTES + 1];
    static const uint16_t sentinel[] = {
        '@','B','L','A','N','K','P','W','D', 0 };
    hash_hex_of(install_guid_ascii, sentinel, expect);
    return strcmp(expect, stored_hash_hex) == 0;
}

/* ==========================================================================
 * 3. hash2 — serial storage obfuscation
 *
 * Seven int16 lanes, additive/rolling. Storage obfuscation only: the transform
 * is invertible without a secret, so it must not be treated as encryption.
 *
 * The lane key as corrected in docs/08-licensing-and-crypto.md is
 * { 3, 7, 8, 2, 9, 5, 4 }; the correction matters because the vendor code
 * indexes every second int16 lane and takes three values from adjacent locals.
 * The analysis host's hash2 value round-trips byte-exactly with this key.
 * ========================================================================== */

const int16_t dp_hash2_key[DP_HASH2_KEY_LANES] = { 3, 7, 8, 2, 9, 5, 4 };

int dp_hash2_decode(const char *in, char *out, size_t out_bytes)
{
    if (!in || !out) return -1;
    size_t n = strlen(in);
    if (n >= out_bytes) return -1;
    for (size_t i = 0; i < n; i++) {
        int lane = (int)(i % DP_HASH2_KEY_LANES);
        /* rolling accumulation across earlier lanes */
        int acc = 0;
        for (int l = 0; l < lane; l++)
            acc += dp_hash2_key[l] * (int)(i / DP_HASH2_KEY_LANES + 1);
        out[i] = (char)((unsigned char)in[i] - (unsigned char)(acc + dp_hash2_key[lane]));
    }
    out[n] = 0;
    return 0;
}

int dp_hash2_encode(const char *in, char *out, size_t out_bytes)
{
    if (!in || !out) return -1;
    size_t n = strlen(in);
    if (n + 1 > out_bytes) return -1;
    for (size_t i = 0; i < n; i++) {
        int lane = (int)(i % DP_HASH2_KEY_LANES);
        int acc = 0;
        for (int l = 0; l < lane; l++)
            acc += dp_hash2_key[l] * (int)(i / DP_HASH2_KEY_LANES + 1);
        out[i] = (char)((unsigned char)in[i] + (unsigned char)(acc + dp_hash2_key[lane]));
    }
    out[n] = 0;
    return 0;
}

/* ==========================================================================
 * 4. Registration code — validation only
 *
 * 25 characters over a 31-symbol alphabet. The check is
 *   base31(MD5(ANSI(code[16..24]) ++ "V100" | "V110"))[0..15] == code[0..15]
 * i.e. the first sixteen characters are a function of the last nine.
 *
 * This function only *verifies* a code the user already owns; code generation is
 * deliberately not implemented. See the notice in
 * docs/08-licensing-and-crypto.md.
 * ========================================================================== */

static int base31_value(char c)
{
    const char *p = strchr(DP_REGCODE_ALPHABET, c);
    return p ? (int)(p - DP_REGCODE_ALPHABET) : -1;
}

static int md5_to_base31(const uint8_t digest[16], char out[17])
{
    /* Treat the first 16 digest bytes as a big-endian integer and render the
     * low-order 16 symbols in base 31. INFERRED arithmetic: the observed codes
     * verify under this rule, but the vendor's shift order was not fully
     * recovered. See docs/09-unknowns-and-roadmap.md. */
    uint8_t buf[17];
    memcpy(buf, digest, 16);
    buf[16] = 0;
    for (int i = 15; i >= 0; i--) {
        unsigned rem = 0;
        for (int j = 0; j <= i; j++) {
            unsigned cur = (rem << 8) | buf[j];
            buf[j] = (uint8_t)(cur / DP_REGCODE_BASE);
            rem = cur % DP_REGCODE_BASE;
        }
        out[15 - i] = DP_REGCODE_ALPHABET[rem];
    }
    out[16] = 0;
    return 0;
}

int dp_regcode_verify(const char *code25)
{
    if (!code25 || strlen(code25) != DP_REGCODE_LEN)
        return 0;
    for (int i = 0; i < DP_REGCODE_LEN; i++)
        if (base31_value(code25[i]) < 0)
            return 0;

    static const char *suffixes[] = { "V100", "V110" };
    for (size_t s = 0; s < 2; s++) {
        char tail[10 + 4 + 1];
        memcpy(tail, code25 + 16, 9);
        tail[9] = 0;
        strcat(tail, suffixes[s]);

        md5_ctx c; uint8_t d[16]; char expect[17];
        md5_init(&c);
        md5_update(&c, tail, strlen(tail));
        md5_final(&c, d);
        md5_to_base31(d, expect);

        if (memcmp(expect, code25, 16) == 0)
            return 1;
    }
    return 0;
}

/* ==========================================================================
 * 5. user.dat — INI reader/writer
 *
 * Format: UTF-8/ANSI INI, section [common], CRLF line endings, `key=value`.
 * The shipped file on the analysis host:
 *
 *   [common]
 *   hash=eb1997a8cf8000a3d43ce85f0be18268
 *   hash2=<redacted: this installation's licence serial>
 *   sn=
 *   time=1809326992
 *   RAM=0
 *   continue=0
 *   volume=CD
 *
 * The per-user copy in %APPDATA%\Shadow Defender\user.dat holds the desktop-tip
 * position, e.g. `[common]\r\ntippos=6686956`.
 *
 * The settings file is on the driver's write-through list (service value
 * `Sync` = "C:\Windows\bootstat.dat;C:\Users\*\Shadow Defender\user.dat"), so
 * changes survive a shadow session; that is why the product can remember
 * settings across Shadow Mode.
 * ========================================================================== */

typedef struct {
    char section[64];
    char key[128];
    char value[512];
} dp_ini_line;

static char *dp_trim(char *s)
{
    while (*s == ' ' || *s == '\t' || *s == '\r' || *s == '\n') s++;
    size_t n = strlen(s);
    while (n && (s[n-1] == ' ' || s[n-1] == '\t' || s[n-1] == '\r' || s[n-1] == '\n'))
        s[--n] = 0;
    return s;
}

/* Returns a malloc'd copy of the value, or NULL. Caller frees. */
char *dp_ini_get(const char *path, const char *section, const char *key)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;

    char line[1024], cur[64] = "";
    char *result = NULL;

    while (fgets(line, sizeof(line), f)) {
        char *s = dp_trim(line);
        if (*s == 0 || *s == ';' || *s == '#') continue;
        if (*s == '[') {
            char *close = strchr(s, ']');
            if (close) {
                *close = 0;
                snprintf(cur, sizeof(cur), "%s", s + 1);
            }
            continue;
        }
        char *eq = strchr(s, '=');
        if (!eq) continue;
        *eq = 0;
        char *k = dp_trim(s);
        char *v = dp_trim(eq + 1);
        if (strcmp(cur, section) == 0 && strcmp(k, key) == 0) {
            result = strdup(v);
            break;
        }
    }
    fclose(f);
    return result;
}

int dp_ini_set(const char *path, const char *section, const char *key, const char *value)
{
    /* Rewrite the file preserving unrelated lines. The vendor implementation
     * writes through SHSetValueW/SHGetValueW when the file is not present, but
     * the on-disk format is the INI file either way. */
    FILE *in = fopen(path, "rb");
    FILE *out = fopen(".dp_userdat.tmp", "wb");
    if (!out) { if (in) fclose(in); return -1; }

    int wrote = 0, in_section = 0, saw_section = 0;
    char line[1024], cur[64] = "";

    if (in) {
        while (fgets(line, sizeof(line), in)) {
            char copy[1024];
            snprintf(copy, sizeof(copy), "%s", line);
            char *s = dp_trim(copy);
            if (*s == '[') {
                char *close = strchr(s, ']');
                if (close) { *close = 0; snprintf(cur, sizeof(cur), "%s", s + 1); }
                if (strcmp(cur, section) == 0 && in_section && !wrote) {
                    fprintf(out, "%s=%s\r\n", key, value ? value : "");
                    wrote = 1;
                }
                in_section = (strcmp(cur, section) == 0);
                if (in_section) saw_section = 1;
                fputs(line, out);
                continue;
            }
            if (in_section) {
                char k[1024];
                snprintf(k, sizeof(k), "%s", copy);
                char *eq = strchr(k, '=');
                if (eq) {
                    *eq = 0;
                    if (strcmp(dp_trim(k), key) == 0) {
                        if (!wrote) {
                            fprintf(out, "%s=%s\r\n", key, value ? value : "");
                            wrote = 1;
                        }
                        continue;               /* drop the old line */
                    }
                }
            }
            fputs(line, out);
        }
        fclose(in);
    }
    if (!saw_section) fprintf(out, "[%s]\r\n", section);
    if (!wrote) {
        if (saw_section) { /* section exists but key missing: append at end is
                              acceptable because the parser is order-independent */
        }
        fprintf(out, "%s=%s\r\n", key, value ? value : "");
    }
    fclose(out);

    remove(path);
    if (rename(".dp_userdat.tmp", path) != 0) return -1;
    return 0;
}

/* ==========================================================================
 * 6. res.ini — UI string table
 *
 * [common] section, decimal keys, values are the display strings with `\n`
 * escapes that must be unescaped. Location: HKLM\SOFTWARE\Shadow Defender\Path,
 * else the directory containing the running executable.
 *
 * This is the loader for the table documented in docs/05-user-interface.md.
 * Observed quirks on the analysis host: keys 1010 and 30011 are absent, and the
 * `authorinfo` line is commented out, so no translator credit is shown.
 * ========================================================================== */

int dp_res_string_from(const char *res_ini_path, int id, wchar_t *out, size_t out_wchars)
{
    char key[32];
    char *v;
    size_t i = 0;

    snprintf(key, sizeof(key), "%d", id);
    v = dp_ini_get(res_ini_path, "common", key);
    if (!v) return -1;

    /* unescape `\n` into a real newline */
    for (char *p = v, *d = v; *p; p++) {
        if (p[0] == '\\' && p[1] == 'n') { *d++ = '\n'; p++; }
        else if (p[0] == '\\' && p[1] == '\\') { *d++ = '\\'; p++; }
        else *d++ = *p;
    }

    for (; v[i] && i + 1 < out_wchars; i++)
        out[i] = (wchar_t)(unsigned char)v[i];
    out[i] = 0;
    free(v);
    return 0;
}
