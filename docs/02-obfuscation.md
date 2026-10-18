# Shadow Defender — Code Obfuscation Scheme

> Scope: Shadow Defender 1.5.0.726, all seven modules.
> Status: **observed** unless marked otherwise. Method: IDA Pro 9.4 static analysis
> plus the export/unhide toolchain in `tools/`.

## 1. Summary

Every Shadow Defender module hides its device-I/O and control plane behind one
shared home-grown obfuscation framework:

| Element | Description |
| --- | --- |
| Camouflaged section | A section **named `.reloc`** with `RWX` permissions whose real `BASERELOC` data directory is tiny. The section is the module's private code+data vault. |
| Trampoline stubs | Each protected operation is a 15-byte stub `push <descriptor_rva>; push <entry_index>; jmp <relocator>`. |
| Runtime relocator | A shared routine that caches the module base, lazily converts a table of qword **RVAs** into absolute pointers, and tail-jumps into the vault. |
| Dispatch table | An array of qword RVAs immediately following the relocator, one per operation/index. |
| Register machine | The vault contains a bytecode interpreter. Its "registers" are byte offsets inside a per-module scratch structure; the instruction pointer is itself one of those slots. |
| Noise | Every handler performs opaque XOR/ADD/OR arithmetic on a fake "opcode cache" before dispatch, and reads several constants through `add reg, 0` / `or reg, 0` identity chains. |

The point of the design is that a disassembler sees a data-class section filled
with apparently meaningless words, while the real logic only appears once the
relocator has run.

## 2. Section layout (worked example: `diskpt.sys`)

SHA-256 `6ffd78b5954064bba7370af51b2e4f1358424f542682218a1121a375f3903583`.

| Section | RVA | VSize | RawPtr | Flags | Note |
| --- | --- | --- | --- | --- | --- |
| `.text` | `0x1000` | `0x20544` | `0x400` | `R-X` | ordinary code: KMDF glue, IRP dispatch, `Stor*`/`Fsf*` layers |
| `.rdata` | `0x22000` | `0x16F8` | `0x20A00` | `R--` | strings, import thunks |
| `.data` | `0x24000` | `0x17E0` | `0x22200` | `RW-` | globals |
| `.pdata` | `0x26000` | `0xBDC` | `0x22A00` | `R--` | exception data |
| `PAGE` | `0x27000` | `0x1A47` | `0x23600` | `R-X` | pagable code |
| `INIT` | `0x29000` | `0x2A42` | `0x25200` | `RWX` | init code |
| `.rsrc` | `0x2C000` | `0x3B8` | `0x27E00` | `R--` | resources |
| **`.reloc`** | **`0x2D000`** | **`0x48334`** | **`0x28200`** | **`RWX`** | **vault: handlers + tables + bytecode** |

The optional-header `BASERELOC` directory points at `0x2D000` with size
**`0x18`** — a single 24-byte relocation block (8 HIGHLOW entries in page
`0x24000`). Everything from `0x2D018` to `0x75334` is therefore *not*
relocation data, despite the section name.

Entropy profile of the vault (16 KB blocks) shows two distinct regions:

```
0x02D000 .. 0x065000   entropy ~4.8-5.0   ~32 % zero bytes   handler code
0x069000 .. 0x075000   entropy ~6.8-6.9   ~19 % zero bytes   tables + programs
```

## 3. The runtime relocator (`diskpt.sys` @ `0x2800B7DE9`)

Reconstructed from the disassembly:

```c
/* entered with two pushed values: (deeper) descriptor_rva, (shallower) index */
void __noreturn Dp_VmEnter(u32 descriptor_rva, u32 index)
{
    u64 base = self_address_rounded_down_to_image_base();   /* call $+5 / pop / sub */
    u8 *state = (u8 *)(base + 0x2D200);                     /* per-module scratch */

    /* one-time init, guarded by an atomic flag at state + 0xE7 */
    if (lock_cmpxchg_acquire((u32 *)(state + 0xE7), 0, 1) == 0) {
        *(u64 *)(state + 0xEF) = base;                       /* IMAGE_BASE   */
        *(u64 *)(state + 0xFB) = base + descriptor_rva;      /* IP           */
        u64 *tbl = (u64 *)(base + 0x679A9);                  /* 136 entries  */
        if (*(u64 *)(state + 0x54) != (u64)tbl) {
            for (int i = 0; i < 136; i++) tbl[i] += base;    /* RVA -> pointer */
            *(u64 *)(state + 0x54) = (u64)tbl;
        }
    }
    jump_to(*(u64 *)(*(u64 *)(state + 0x54) + index * 8));
}
```

So the table at `0x679A9` is pre-populated with **plaintext RVAs** and is turned
into a real function-pointer table only at run time. A static reader sees a list
of plausible-looking integers; a debugger sees a jump table.

In the sample the table holds 136 entries, all pointing into
`0x2D353 .. 0x66C51` — the handler region.

### The obfuscation is not a packer

The vault is **not encrypted and not compressed** (entropy 4.8–6.9, not ~7.99).
The bytes are the final code; only the *entry* and the *semantics* are hidden.
This is why the handlers are readable once the section is re-classified as code.

## 4. The register machine

### 4.1 Dispatch

`Dp_H079` (handler index `0x4F` = 79) is the interpreter step:

```asm
; rbp = state
mov     rax, rbp
add     rax, 1Ch
mov     dword ptr [rax], 0        ; FLAGS = 0
mov     r14, rbp
add     r14, 0FBh
mov     r14, [r14]                ; r14 = IP
mov     si, [r14]                 ; opcode = *(u16 *)IP      <-- opcode from IP+0
shl     rsi, 3
mov     rcx, rbp
add     rcx, 54h
mov     rbx, [rcx]                ; dispatch table base
add     rbx, rsi
mov     r11, [rbx]                ; handler
add     qword ptr [rbp+0FBh], 4   ; IP += 4
jmp     r11
```

Every handler ends with the same epilogue: it performs its work, re-derives the
**next** opcode, advances `IP` by its own instruction length, and tail-jumps.

### 4.2 Instruction encoding

```c
struct dp_insn {           /* variable length, fixed per opcode */
    u16 operand0;          /*  0x00 : state offset ("register selector") */
    u16 operand1;          /*  0x02 :               "                    */
    u16 operand2;          /*  0x04 :               "                    */
    u16 operand3;          /*  0x06 :               "                    */
    u16 reserved;          /*  0x08 :                               */
    u8  flags;             /*  0x0A : predicate / direction byte     */
    /*  0x0B .. 0x13 for the 20-byte forms                          */
};
```

Observed total lengths and their opcode sets (diskpt handler set, 125 of 136
handlers carry a visible constant advance):

| Length | Opcode count | Notable opcodes |
| --- | --- | --- |
| 2 | 1 | 12 — register-file reset (writes eight state slots to 0) |
| 4 | 4 | 1 — `V[ip[0]] = V[0xA6]` (move); 10 — push return address; 79 — interpreter step |
| 5 | 1 | 97 |
| 6 | 5 | 9, 64, 72, 107, 134 |
| 8 | 24 | 8, 22, 27, 28, 35, 41, 51, 55, 70, 74, 77, 78, 80, 82, 86, 99, 101, 102, 113, 119, 123, 124, 126, 129 |
| 10 | 4 | 53, 75, 90, 92 |
| 11 | 26 | 2, 3, 7, 11, 13, 15, 17, 23, 25, 26, 29, 34, 37, 43, 49, 67, 68, 69, 73, 84, 96, 98, 111, 115, 117, 131 |
| 12 | 1 | 114 |
| 13 | 3 | 47, 61, 128 |
| 20 | 2 | 14, 45 |
| variable | 11 | branches / calls that compute the advance (`v11`, `v13`, `v14` forms) |

Handlers whose advance is *computed* are the control-flow opcodes: their
`IP` update depends on a predicate byte and on the `FLAGS` slot.

### 4.3 The state structure ("register file")

All handlers receive it in `rbp`; `diskpt.sys` places it at RVA `0x2D200`.
Fields recovered so far:

| Offset | Size | Meaning (`observed`) |
| --- | --- | --- |
| `+0x1C` | u32 | `FLAGS`. Bit `0x400` is the direction flag consulted by the string-ops. Cleared by the interpreter step. |
| `+0x54` | u64 | Dispatch-table base (set to `base + 0x679A9`). |
| `+0x69` | u32 | Rolling "opcode cache" — pure dispatch noise; always ORed/XORed back to the true opcode. |
| `+0x9E` | u64 | Noise accumulator, written with `reg ^ (state + 0x69)`. |
| `+0xA6` | u64 | Scratch source register used by the move opcode. |
| `+0xE7` | u32 | Atomic "vault initialised" latch. |
| `+0xEF` | u64 | Image base. |
| `+0xFB` | u64 | **Instruction pointer.** Branches work by writing into the register that aliases this slot. |
| `+0xF7`, `+0x11B`, `+0x11D`, `+0x133`, `+0x14F`, `+0x9D`, `+0xAE`, `+0x163`… | — | Additional scratch registers cleared by opcode 12. |

Confirmed semantics for a first set of opcodes:

| Opcode | Length | Behaviour |
| --- | --- | --- |
| 1 | 4 | `V[ip[0]] = V[0xA6]` — move |
| 2 | 11 | modifies two virtual strings by ±8 depending on `FLAGS & 0x400`, optionally stores `EFLAGS` into `V[ip[0]]` — a REP-class string operation |
| 3 | 11 | `*(u64 *)V[ip[8]] -= V[ip[4]]`, direction-adjust, store `EFLAGS` if `ip[10] != 0` |
| 10 | 4 | `V[ip[2]] = &retaddr` — push (saves the native return address into a virtual register) |
| 12 | 2 | zeroes eight scratch slots — program prologue |
| 79 | 4 | interpreter step (above) |

## 5. VM programs

Each protected operation has its own program. `tools/vm.py --list-programs`
extracts them by scanning for the `push <rva>; push <idx>` stubs. For
`diskpt.sys` all 27 programs enter through index `0x4F` and live in
`0x67E9D .. 0x7503A`:

```
0x67E9D 0x6808A 0x6858C 0x68715 0x689CA 0x68D0C 0x68ED7 0x690C4 0x6961C
0x69976 0x69CD0 0x6A02A 0x6A384 0x6A6DE 0x6AA10 0x6AD42 0x6B074 0x6B3A6
0x6B6D8 0x6B8F3 0x6C45E 0x6C870 0x6CBD9 0x6CD90 0x6D1A2 0x6D7B1 0x7503A
```

`0x6B8F3` is reached from the `IRP_MJ_DEVICE_CONTROL` stub, so it is the driver's
**IOCTL program**. Programs are separated by short native stubs
(`E9 <rel32>` jumps) and by inline descriptor data.

A program begins with a fixed prologue seen at every entry:

```
0x67E9D:  op12                      ; reset scratch registers
0x67E9F:  op0                       ; (control/handoff form)
0x67EA3:  op10, operand 0x004B      ; push
0x67EA7:  op48, operand 0x0C6D      ; load / literal group
          ... 6- or 10-byte inline payloads separated by op48 ...
```

The `op48` group is followed by high-entropy inline payloads (6 or 10 bytes each)
which are the **per-program data** (identifiers, keys, encrypted constants).

## 6. Why the opcode fields are not trivially readable

Three mechanisms defeat naive reading:

1. **Dispatch comes from a different offset than the operand.** Handler 1 reads
   its operand from `IP+0` but takes the *next* opcode from `IP+2`; handler 2
   reads operands from `IP+2, IP+4, IP+6, IP+8, IP+10` and takes the next opcode
   from `IP+0`. The apparent offsets are consistent within a handler, but the
   "opcode word" and "operand word" swap roles between opcodes.
2. **Identity arithmetic.** Handlers contain `add reg, 0`, `or reg, 0`,
   `add reg, 0FBh` + `mov reg, [reg]` chains that exist only to lengthen the
   instruction stream and break pattern matching.
3. **Fake opcode cache.** The value at `state+0x69` is combined with the real
   opcode through XOR/OR/ADD with per-handler constants (e.g. `^ 0x86D6C1`,
   `+ 0x627C1932`, `+ 1036032465`) and then masked to 16 bits. The result is
   always the true opcode, but a reader cannot tell without evaluating the chain.

## 7. The same framework in the user-mode modules

| Module | Relocator | Vault state | Table | Entries | Vault section |
| --- | --- | --- | --- | --- | --- |
| `diskpt.sys` | `0x2800B7DE9` | `0x2D200` | `0x679A9` | 136 | `.reloc`, size `0x48334` |
| `CmdTool.exe` | `0x1400AE263` | `0x75400` | `0xADE73` | 126 | `.reloc` |
| `Commit.exe` | `0x1400D86E8` | `0xA4E00` | — | 126 | `.reloc` |
| `ShellExt.dll` | `0x180062591` | `0x30800` | — | 126 | `.reloc` |
| `Uninstall.exe` | `0x14009F351` | `0x6F200` | — | 126 | `.reloc` |
| `Defender.exe` | `0x140147C33` | — | — | — | `.reloc` |

The scheme is therefore a **product-wide obfuscation framework**, not a one-off:
the same stub shape, the same relocator logic and the same VM appear in the
kernel driver and in every user-mode tool. `tools/unhide_scan.py` recovers the
tables and thunks for user-mode modules; `tools/ida_unhide.py` re-classifies a
vault and seeds functions at every table target (125/136 recovered for
`diskpt.sys`).

## 8. Consequences for analysis

* **Do not trust section names or permissions.** `.reloc` here is `RWX` code.
  Always cross-check `BASERELOC`/`EXCEPTION` directory sizes against section
  sizes.
* **Cross-reference by strings, not by opcode.** The DbgPrint trace strings
  (`diskpt!StorInitializeVolumeContext: …`) are ordinary `.rdata` strings and
  give reliable names for the `.text` layer.
* **The `.text` layer is largely unobfuscated.** Storage (`Stor*`), the file
  system filter (`Fsf*`), the per-IRP handlers and `DriverEntry` decompile
  cleanly. Only the *control plane* (IOCTL parsing, configuration, licensing,
  device session management) is inside the VM.
* **Sizes are deliberately uniform.** 126/136-entry tables and fixed-size
  programs make the vault look like a table even on a hex dump.

## 9. Toolchain

| Tool | Purpose |
| --- | --- |
| `tools/ida_export.py` | Batch-export functions, pseudocode, disassembly, strings-with-xrefs, imports, names for a module. |
| `tools/ida_unhide.py` | Re-class a `.reloc` vault as code, seed functions at every dispatch-table target, dump the recovered functions. |
| `tools/unhide_scan.py` | Locate the relocator/table/thunks without IDA. |
| `tools/vm.py` | VM profiler/disassembler: opcode length table, per-opcode advance and opcode-read offset, program listing. |
| `tools/vm_emu.py` | Unicorn harness that executes the handlers and logs every VM dispatch (program-level). |
| `tools/vm_emu_ioctl.py` | Same, entered through the real `IRP_MJ_DEVICE_CONTROL` stub with a fabricated IRP/IO_STACK_LOCATION. See `docs/11-vm-emulation.md`. |
| `tools/discalc.py` | VA → file offset → capstone disassembly helper. |
| `tools/refs.py` | file-offset ↔ RVA ↔ string ↔ xref helper. |
| `tools/strings.py`, `tools/fn.py` | ASCII/UTF-16 string extraction; function-block extraction from a hexrays export. |
