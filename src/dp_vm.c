/*
 * dp_vm.c — Shadow Defender's code-obfuscation framework, reconstructed.
 *
 * RECONSTRUCTION, NOT ORIGINAL SOURCE. This file describes the mechanism
 * recovered in docs/02-obfuscation.md; it is written to be compiled and run
 * against a mapped image so that the bytecode can be exercised, not to be a
 * byte-exact copy of the vendor's code.
 *
 * The framework appears in all seven modules with only the three constants
 * (state RVA, dispatch-table RVA, entry count) changing:
 *
 *   module          relocator VA        state RVA   table RVA   entries
 *   diskpt.sys      0x2800B7DE9         0x2D200     0x679A9     136
 *   CmdTool.exe     0x1400AE263         0x75400     0xADE73     126
 *   Commit.exe      0x1400D86E8         0xA4E00     unknown     126
 *   ShellExt.dll    0x180062591         0x30800     unknown     126
 *   Uninstall.exe   0x14009F351         0x6F200     unknown     126
 *   Defender.exe    0x140147C33         unknown     unknown     unknown
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/* --------------------------------------------------------------------------
 * 1. Module descriptor
 * ------------------------------------------------------------------------ */

typedef struct dp_vm_module {
    const char *name;
    uint8_t    *image;          /* whole image mapped at its preferred base */
    uint8_t    *image_base;     /* == image, i.e. preferred base             */
    uint32_t    relocator_rva;  /* VA - base of the shared relocator         */
    uint32_t    state_rva;      /* per-module scratch / register file        */
    uint32_t    table_rva;      /* qword RVA dispatch table                  */
    uint32_t    entry_count;    /* 136 for the driver, 126 for user mode     */
    size_t      image_size;
} dp_vm_module;

/* --------------------------------------------------------------------------
 * 2. State (register file) layout — diskpt.sys offsets
 *
 * The same field order is used by the other modules; only the base RVA moves.
 * Offsets marked INFERRED are named from usage, not from a symbol.
 * ------------------------------------------------------------------------ */

#define DP_STATE_FLAGS        0x01C   /* u32; bit 0x400 = direction flag       */
#define DP_STATE_DISPATCH     0x054   /* u64; set to base + table_rva          */
#define DP_STATE_OPCODE_CACHE 0x069   /* u32; dispatch noise                   */
#define DP_STATE_NOISE_ACC    0x09E   /* u64; dispatch noise                   */
#define DP_STATE_SCRATCH_SRC  0x0A6   /* u64; source of the move opcode        */
#define DP_STATE_INIT_LATCH   0x0E7   /* u32; atomic one-time latch            */
#define DP_STATE_IMAGE_BASE   0x0EF   /* u64; module base                      */
#define DP_STATE_IP           0x0FB   /* u64; instruction pointer (a register!) */
#define DP_STATE_BYTES        0x200   /* INFERRED: room for the scratch slots  */

#define DP_FLAG_DIRECTION     0x400u

/* --------------------------------------------------------------------------
 * 3. The relocator
 *
 * Reconstructed from diskpt.sys @ 0x2800B7DE9. The vendor code computes its own
 * base with `call $+5 / pop / sub`, then falls through here.
 *
 * `descriptor_rva` is the program to run; `entry_index` selects the opcode
 * handler to enter with. Every user-mode-visible operation uses entry index 79
 * (the interpreter step), so `entry_index` is effectively always 79 in the
 * observed call sites.
 * ------------------------------------------------------------------------ */

typedef void (*dp_handler_fn)(uint8_t *state);

static void dp_vm_enter(dp_vm_module *mod, uint32_t descriptor_rva, uint32_t entry_index)
{
    uint8_t *state = mod->image + mod->state_rva;
    uint64_t *table = (uint64_t *)(mod->image + mod->table_rva);

    /* One-time initialisation, guarded by an atomic latch. The vendor code uses
     * a lock cmpxchg spin; here a plain test is enough for a single-threaded
     * replay harness. */
    if (*(uint32_t *)(state + DP_STATE_INIT_LATCH) == 0) {
        *(uint64_t *)(state + DP_STATE_IMAGE_BASE) = (uint64_t)mod->image_base;
        *(uint64_t *)(state + DP_STATE_IP)         = (uint64_t)(mod->image + descriptor_rva);

        /* The table holds RVAs; convert once. The vendor code re-checks against
         * state+0x54 so a second entry does not double-relocate. */
        if (*(uint64_t *)(state + DP_STATE_DISPATCH) != (uint64_t)table) {
            for (uint32_t i = 0; i < mod->entry_count; i++)
                table[i] += (uint64_t)mod->image_base;
            *(uint64_t *)(state + DP_STATE_DISPATCH) = (uint64_t)table;
        }
        *(uint32_t *)(state + DP_STATE_INIT_LATCH) = 1;
    }

    ((dp_handler_fn)table[entry_index])(state);
}

/* --------------------------------------------------------------------------
 * 4. Instruction encoding
 *
 * Fixed length per opcode; the length is a property of the handler. Within a
 * handler the operand words sit at IP+0, +2, +4, ... but *which* word is the
 * "next opcode" differs between opcodes, which is what defeats naive reading:
 * the interpreter step reads the opcode from IP+0, while handler 1 reads its
 * operand from IP+0 and takes the next opcode from IP+2.
 * ------------------------------------------------------------------------ */

typedef struct dp_insn_desc {
    uint16_t opcode;
    uint8_t  length;                /* total instruction length in bytes    */
    uint8_t  next_opcode_offset;    /* where the handler reads the next op  */
    const char *mnemonic;           /* INFERRED where non-NULL              */
} dp_insn_desc;

/* Lengths recovered with certainty from the handler epilogues. Opcodes absent
 * from this table are the control-flow forms whose advance is computed from a
 * predicate and the FLAGS slot. See docs/02-obfuscation.md §4.2. */
static const dp_insn_desc dp_insn_table[] = {
    {  0,  8, 0, NULL        },  /* relative jump; 4-byte displacement at IP+4 */
    {  1,  4, 2, "mov"       },  /* V[IP+0] = V[0xA6]                          */
    {  2, 11, 0, NULL        },  /* REP-class string op, direction-aware       */
    {  3, 11, 0, NULL        },  /* V[IP+8] -= V[IP+4], direction-aware        */
    {  8,  8, 0, NULL        },
    {  9,  6, 0, NULL        },
    { 10,  4, 0, "push"      },  /* V[IP+2] = &retaddr                         */
    { 11, 11, 0, NULL        },
    { 12,  2, 0, "reset"     },  /* zeroes eight scratch slots                 */
    { 13, 11, 0, NULL        },
    { 14, 20, 0, NULL        },  /* large form                                 */
    { 15, 11, 0, NULL        },
    { 17, 11, 0, NULL        },
    { 22,  8, 0, NULL        },
    { 23, 11, 0, NULL        },
    { 25, 11, 0, NULL        },
    { 26, 11, 0, NULL        },
    { 27,  8, 0, NULL        },
    { 28,  8, 0, NULL        },
    { 29, 11, 0, NULL        },
    { 30, 11, 0, NULL        },
    { 34, 11, 0, NULL        },
    { 35,  8, 0, NULL        },
    { 37, 11, 0, NULL        },
    { 41,  8, 0, NULL        },
    { 43, 11, 0, NULL        },
    { 45, 20, 0, NULL        },  /* large form                                 */
    { 47, 13, 0, NULL        },  /* variable predicate form                    */
    { 49, 11, 0, NULL        },
    { 50,  4, 0, NULL        },
    { 51,  8, 0, NULL        },
    { 53, 10, 0, NULL        },
    { 55,  8, 0, NULL        },
    { 58, 11, 0, NULL        },
    { 61, 13, 0, NULL        },
    { 64,  6, 0, NULL        },
    { 66, 13, 0, NULL        },
    { 67, 11, 0, NULL        },
    { 68, 11, 0, NULL        },
    { 69, 11, 0, NULL        },
    { 70,  8, 0, NULL        },
    { 72,  6, 0, NULL        },
    { 73, 11, 0, NULL        },
    { 74,  8, 0, NULL        },
    { 75, 10, 0, NULL        },
    { 77,  8, 0, NULL        },
    { 78,  8, 0, NULL        },
    { 79,  4, 0, "step"      },  /* interpreter step                           */
    { 80,  8, 0, NULL        },
    { 81, 13, 0, NULL        },
    { 82,  8, 0, NULL        },
    { 83, 13, 0, NULL        },
    { 84, 11, 0, NULL        },
    { 86,  8, 0, NULL        },
    { 90, 10, 0, NULL        },
    { 92, 10, 0, NULL        },
    { 96, 11, 0, NULL        },
    { 97,  5, 0, NULL        },
    { 98, 11, 0, NULL        },
    { 99,  8, 0, NULL        },
    {101,  8, 0, NULL        },
    {102,  8, 0, NULL        },
    {107,  6, 0, NULL        },
    {111, 11, 0, NULL        },
    {113,  8, 0, NULL        },
    {114, 12, 0, NULL        },
    {115, 11, 0, NULL        },
    {117, 11, 0, NULL        },
    {119,  8, 0, NULL        },
    {123,  8, 0, NULL        },
    {124,  8, 0, NULL        },
    {126,  8, 0, NULL        },
    {128, 13, 0, NULL        },
    {129,  8, 0, NULL        },
    {131, 11, 0, NULL        },
    {134,  6, 0, NULL        },
};

static const dp_insn_desc *dp_insn_lookup(uint16_t opcode)
{
    for (size_t i = 0; i < sizeof(dp_insn_table) / sizeof(dp_insn_table[0]); i++)
        if (dp_insn_table[i].opcode == opcode)
            return &dp_insn_table[i];
    return NULL;
}

/* --------------------------------------------------------------------------
 * 5. The interpreter step (opcode 79), reconstructed from diskpt.sys @ 0x2800A177C
 *
 *   state->flags = 0;
 *   handler = state->dispatch[ *(u16 *)state->ip ];
 *   state->ip += 4;
 *   handler(state);
 *
 * Note the +4: the interpreter step advances past the two-word minimum, so the
 * following handler's own epilogue performs the rest of its advance.
 * ------------------------------------------------------------------------ */

void dp_op_step(uint8_t *state)
{
    uint64_t *table;

    *(uint32_t *)(state + DP_STATE_FLAGS) = 0;

    uint8_t *ip = *(uint8_t **)(state + DP_STATE_IP);
    uint16_t opcode = *(uint16_t *)ip;

    table = (uint64_t *)(*(uint64_t *)(state + DP_STATE_DISPATCH));
    dp_handler_fn handler = (dp_handler_fn)table[opcode];

    *(uint64_t *)(state + DP_STATE_IP) += 4;
    handler(state);
}

/* --------------------------------------------------------------------------
 * 6. Static walker
 *
 * Produces a listing of a program without executing it. Branches are not
 * followed; for control-flow recovery use the emulation harness described in
 * docs/09-unknowns-and-roadmap.md §3 step 2, which is reliable because it runs
 * the vendor handlers directly.
 * ------------------------------------------------------------------------ */

typedef struct dp_listing_sink {
    void (*emit)(void *ctx, uint32_t rva, uint16_t opcode, uint8_t length,
                 const uint16_t *operands, int n_operands);
    void *ctx;
} dp_listing_sink;

int dp_vm_walk(const dp_vm_module *mod, uint32_t program_rva,
               dp_listing_sink *sink, uint32_t max_steps)
{
    uint32_t ip = program_rva;
    uint64_t *table = (uint64_t *)(mod->image + mod->table_rva);

    for (uint32_t step = 0; step < max_steps; step++) {
        uint16_t opcode = *(uint16_t *)(mod->image + ip);
        if (opcode >= mod->entry_count)
            return -1;                          /* left the opcode space */

        const dp_insn_desc *d = dp_insn_lookup(opcode);
        if (d == NULL)
            return -2;                          /* control-flow / unknown length */

        uint16_t operands[8];
        int n = (int)(d->length - 2) / 2;
        if (n > 8)
            n = 8;
        for (int i = 0; i < n; i++)
            operands[i] = *(uint16_t *)(mod->image + ip + 2 + i * 2);

        if (sink && sink->emit)
            sink->emit(sink->ctx, ip, opcode, d->length, operands, n);

        (void)table;
        ip += d->length;
    }
    return 0;
}

/* --------------------------------------------------------------------------
 * 7. Known opcode semantics (grows as the decode proceeds)
 * ------------------------------------------------------------------------ */

/* opcode 1 (length 4, operand at IP+0):  V[IP[0]] = V[0xA6] */
void dp_op_1_mov(uint8_t *state)
{
    uint8_t *ip  = *(uint8_t **)(state + DP_STATE_IP);
    uint16_t dst = *(uint16_t *)(ip + 0);
    *(uint64_t *)(state + dst) = *(uint64_t *)(state + DP_STATE_SCRATCH_SRC);
    /* advance + tail-dispatch to table[*(u16*)(ip+2)] performed by the caller */
}

/* opcode 10 (length 4, operand at IP+2): push the native return address */
void dp_op_10_push_retaddr(uint8_t *state, uint64_t return_address)
{
    uint8_t *ip  = *(uint8_t **)(state + DP_STATE_IP);
    uint16_t dst = *(uint16_t *)(ip + 2);
    *(uint64_t *)(state + dst) = return_address;
}

/* opcode 12 (length 2): clear the scratch register file */
void dp_op_12_reset(uint8_t *state)
{
    static const uint16_t slots[] = { 0x069, 0x14F, 0x11D, 0x133, 0x0F7,
                                      0x11B, 0x09D, 0x0AE };
    for (size_t i = 0; i < sizeof(slots) / sizeof(slots[0]); i++) {
        /* the vendor code clears a dword, a word and a byte at specific slots;
         * all eight writes are zeroing writes */
        *(uint32_t *)(state + slots[i]) = 0;
    }
}

/* opcode 3 (length 11): V[IP+8] -= V[IP+4], direction-aware, conditional
 * EFLAGS store into V[IP+0] when IP+10 != 0. */
void dp_op_3_sub(uint8_t *state, uint32_t eflags)
{
    uint8_t *ip = *(uint8_t **)(state + DP_STATE_IP);
    uint64_t *dst = (uint64_t *)(state + *(uint16_t *)(ip + 8));
    uint64_t  src = *(uint64_t *)(state + *(uint16_t *)(ip + 4));

    *dst -= src;

    if (*(uint32_t *)(state + DP_STATE_FLAGS) & DP_FLAG_DIRECTION)
        *(uint64_t *)(state + *(uint16_t *)(ip + 8)) -= 8;
    else
        *(uint64_t *)(state + *(uint16_t *)(ip + 8)) += 8;

    if (*(uint8_t *)(ip + 10) != 0)
        *(uint64_t *)(state + *(uint16_t *)(ip + 0)) = eflags;
}
