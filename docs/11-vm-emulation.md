# Shadow Defender — Dynamic VM Emulation

> Status: harness working; the driver's init programs and its DEVICE_CONTROL
> program both execute under emulation, and the state has been warmed
> successfully. The remaining task is locating where the IOCTL code is actually
> read — this document records what was established, what was ruled out, and the
> next step.
>
> Tools: `tools/vm_emu.py`, `tools/vm_emu_ioctl.py` (Unicorn 2.1.4).
> Traces: `recon/vm/`.

## 1. Why emulate rather than read

`docs/02-obfuscation.md` showed that the handlers are readable x86-64 but their
semantics are buried under per-handler opaque arithmetic: every handler mixes the
dispatch index with constants (`^ 0x86D6C1`, `+ 1469112754`, `&= 0xAD1C980`, …)
and pads instruction streams with `add reg, 0`. Hex-Rays output for handlers of
interest (`Dp_H090`, `Dp_H053`, `Dp_H075`) is a wall of identity arithmetic, not
logic.

Two independent checks make the "read the source" route unattractive:

* the dispatch index is *computed*, not a plain load — in the trace, handler 90
  at `0x6B8FD` dispatches opcode **53**, although none of its six operand words
  is `0x35`;
* handlers use `r14`/`rbx` freely as scratch, so the IOCTL stack location cannot
  be tracked by register naming.

Executing the vendor handlers and recording every dispatch avoids all of this:
the handler bodies are correct by construction.

## 2. The harness

`tools/vm_emu.py` — program-level harness:

1. maps the PE at its preferred base (sections at their RVAs, RWX),
2. pre-applies the runtime relocation the shared relocator would do (add the
   image base to the 136 qword table entries at RVA `0x679A9`),
3. allocates a scratch state block, sets `state+0xFB` = program pointer,
   `state+0x54` = table, `state+0xEF` = base, `state+0xE7` = 1,
4. starts at handler 79 (the interpreter step) with `RBP` = state,
5. logs `(handler index, instruction pointer, operand words)` on every dispatch,
6. backs unmapped reads with zero pages (capped, and reported) and returns 0 from
   unresolved imports (reported).

`tools/vm_emu_ioctl.py` — faithful-entry harness:

1. same image mapping, but **no** pre-relocation and a zeroed state, so the
   vendor relocator runs itself;
2. fabricates a `DEVICE_OBJECT` (with `DeviceExtension`), an `IRP` (with
   `AssociatedIrp.SystemBuffer` and `Tail.Overlay.CurrentStackLocation`) and an
   `IO_STACK_LOCATION` carrying a chosen `IoControlCode`, buffer lengths and
   `Type3InputBuffer`;
3. starts at `sub_2800630D8` (VA `0x2800630D8`, RVA `0x130D8`) with
   `RCX` = device, `RDX` = IRP;
4. logs the same dispatch records.

> Note on coordinates: IDA names (`sub_2800630D8`) are **virtual addresses**.
> The image base is `0x280050000`, so the RVA is `VA - 0x280050000` (`0x130D8`).
> Conflating the two is the easiest way to start the emulator at the wrong place.

## 3. What the emulator confirmed

### 3.1 The instruction-length table is correct

The observed `IP` progression matches the length table from
`docs/02-obfuscation.md` §4.2 exactly for all fifteen opcodes exercised:

```
op79  ip=06b8f3   -> +4  -> op12  ip=06b8f7
op12  ip=06b8f7   -> +2  -> op10  ip=06b8f9
op10  ip=06b8f9   -> +4  -> op90  ip=06b8fd
op90  ip=06b8fd   -> +10 -> op53  ip=06b907
op53  ip=06b907   -> +10 -> op90  ip=06b911
op90  ip=06b911   -> +10 -> op90  ip=06b91b
op90  ip=06b91b   -> +10 -> op75  ip=06b925
op75  ip=06b925   -> +10 -> op92  ip=06b92f
```

`op75` is a 10-byte form and `op14` the 20-byte form; both advance as predicted.
This independently validates the length extraction that was derived statically.

### 3.2 The VM program for `IRP_MJ_DEVICE_CONTROL` is a 50-opcode prologue

The program at RVA `0x6B8F3` (entered by the stub with `push 6B8F3h; push 4Fh`)
executes exactly 50 dispatches and then unwinds:

```
op79, op12, op10, op90, op53, op90, op90, op75, op92, op90, op53, op92, op90,
op53, op90, op90, op75, op53, op92, op6, op97, op14, op9, op63, op14, op14,
op57, op14, ...
```

Opcode histogram: `op90 ×14, op53 ×7, op92 ×6, op75 ×5, op14 ×4, op57 ×4,
op63 ×2`, then one each of `op79, op12, op10, op6, op97, op9, op72, op36`.

The operands in this region are high-entropy 4-byte words
(`dfcb2047`, `d89e8399 45bf1370`, `f221f0bd f9fa54ff`, …), i.e. the prologue is
loading *data*, not decoding control flow.

### 3.3 The three known IOCTL codes take an identical path

`0x80000D18`, `0x800030A0` and `0x80002D48` produce **byte-identical**
50-dispatch traces (`recon/vm/`). The dispatch on `IoControlCode` is therefore
not in this prologue: it happens later, in code reached only from an initialised
state.

### 3.4 The stub is 23 instructions; its middle 2,900 bytes are not code

REA (`read_function_instructions`, evidence `ev_720d6f6b…`) returns exactly 23
instructions for `sub_2800630D8`:

```
0x2800630d8  mov [rsp+arg_0], rcx      ... 0x280063101  jmp loc_2800BBB22
0x280063c58  pop rdi   ... 0x280063c5c  retn
0x2800bbb22  push 6B8F3h ; push 4Fh ; jmp sub_2800B7DE9
```

Everything between `0x280063106` and `0x280063c57` is undisassembled data inside
the function's nominal span. This matters: when the cold-state program unwinds
incorrectly it lands in that data, executes garbage and jumps to `0x2AEEA`
(an image RVA used as an absolute address). That failure is an artefact of the
harness, **not** driver behaviour.

## 3.5 Warm-up now works, and the state is only 0x153 bytes

Two corrections to the first pass:

**The state structure is 0x153 bytes, not 0x800.** The first opcode handler
(`Dp_H000`) starts at RVA `0x2D353`, so the state occupies exactly
`0x2D200 .. 0x2D352`. Clearing 0x800 bytes erased the first handlers and made
every warm program die after one dispatch. Note also that the Hex-Rays
pseudocode prints these offsets in **decimal**: `v0 + 335` is `0x14F`, and
`v0 + 251` is `0xFB`.

**The init sequence can be run program-by-program.** `DriverEntry` and its
helpers are themselves trampolines into the VM, and each program is reachable
directly:

```
DriverEntry        -> prog 0x6D1A2  (push 6D1A2h; push 4Fh; jmp relocator)
DriverEntry helper -> prog 0x6D7B1  (sub_280079604)
                   -> prog 0x6808A  (sub_280051078)
random seed        -> prog 0x7503A  (sub_280079A08, RtlRandom seeded from
                                     KeQueryPerformanceCounter)
```

Running `0x6808A, 0x6D7B1, 0x6D1A2, 0x7503A` in that order against one shared
state yields **63 / 2440 / 273 / 69 dispatches** respectively, i.e. the state is
genuinely initialised. The harness exposes this as `--warm`.

## 3.6 The 50-opcode prologue is IOCTL-independent — ruled out

With the state warmed, the DEVICE_CONTROL program still produces the *same* 50
dispatches for `0x80000D18`, `0x800030A0` and `0x80002D48`, and still ends by
jumping to `0x2AEEA` (an RVA used as an absolute address).

Conclusion, and it is a useful one: **program `0x6B8F3` is not the IOCTL
demultiplexer.** Its prologue loads data words and never consults the
`IoControlCode` field of the fabricated `IO_STACK_LOCATION`. The dispatch must
happen elsewhere — the candidates are:

* the stub's native continuation (the ~2,900 bytes that IDA does not decode),
* another VM program reached from the stub path,
* a handler that reads the stack location from a *saved* location rather than
  from `r14` (which the VM demonstrably reuses as scratch).

## 4. Complete VM program -> caller map

Every one of the 27 programs is a `push <prog>; push 4Fh; jmp relocator` stub in
the vault tail (`RVA 0x30076..0x35322`). Mapping each stub to the `.text`
function that jumps to it gives the operation table:

| program | caller (VA) | role |
| --- | --- | --- |
| `0x67E9D` | `sub_280051014` | unknown |
| `0x6808A` | `sub_280051078` | init (called from `DriverEntry`) |
| `0x6858C` | `sub_280051960` | `StorDispatchIo` |
| `0x68715` | `sub_280051DB4` | unknown |
| `0x689CA` | `sub_2800521C4` | unknown |
| `0x68D0C` | `sub_2800533FC` | unknown (storage path) |
| `0x68ED7` | `sub_280053EE8` | unknown |
| `0x690C4` | `sub_2800556EC` | `StorInitializeVolumeContext` |
| `0x6961C` | `sub_28005C474` | per-instance IRP hook |
| `0x69976` | `sub_28005C7C4` | per-instance IRP hook |
| `0x69CD0` | `sub_28005CA40` | per-instance IRP hook |
| `0x6A02A` | `sub_28005CCBC` | per-instance IRP hook |
| `0x6A384` | `sub_28005CF18` | per-instance IRP hook |
| `0x6A6DE` | `sub_28005D0A0` | per-instance IRP hook |
| `0x6AA10` | `sub_28005D718` | per-instance IRP hook |
| `0x6AD42` | `sub_28005DD58` | per-instance IRP hook |
| `0x6B074` | `sub_28005E0D8` | per-instance IRP hook |
| `0x6B3A6` | `sub_28005E294` | per-instance IRP hook |
| `0x6B6D8` | `sub_280062D4C` | `IRP_MJ_SHUTDOWN` |
| **`0x6B8F3`** | **`sub_2800630D8`** | **`IRP_MJ_DEVICE_CONTROL`** |
| `0x6C45E` | `sub_280065AD0` | unknown |
| `0x6C870` | `sub_280065DD4` | unknown |
| `0x6CBD9` | `sub_280066C40` | unknown |
| `0x6CD90` | `sub_28006E964` | unknown |
| **`0x6D1A2`** | **`DriverEntry`** | **driver initialisation** |
| `0x6D7B1` | `sub_280079604` | init helper (`DriverEntry`) |
| `0x7503A` | `sub_280079A08` | `RtlRandom` seeding |

This closes `docs/09` §2.2 (program attribution) for 19 of 27 programs; the eight
marked *unknown* have their caller identified but not the operation's meaning.

## 4.1 The original cold-state blocker (kept for the record)

`DriverEntry` (`0x280079008`, RVA `0x29008`) and the INIT routines enter the same
VM. Those init programs populate function pointers and state slots that the
device-control program later dereferences. Starting the control program against a
zeroed state means:

* state slots that should hold pointers are 0, so handlers consume NULL and the
  VM unwinds through the stack frame the relocator built;
* the branch that reads `IoControlCode` is never reached, which is exactly what
  §3.3 shows.

Emulating harder does not fix this; the harness has to run the *initialisation
sequence first*.

## 5. Next step

**Locate the code that reads `IoControlCode`.** The fastest discriminator is to
run the same warmed state with two different IOCTL codes and find the first
instruction whose control flow diverges. Since the VM handlers do not read
`r14`, the read is probably in native code: single-step from the stub at
`0x280063101` (where it jumps into the relocator) and, after the VM returns,
trace the native continuation. The stub's nominal body contains ~2,900 bytes
that IDA leaves as data; forcing instruction creation there in a scratch
database is the next cheap experiment.

Only if that path proves to be a dead end does the heavier route apply:

### Option A — warm the state (preferred, fully static host)

1. Fabricate a `DRIVER_OBJECT` and a `UNICODE_STRING` registry path.
2. Start at `DriverEntry` (RVA `0x29008`). Stub the imports it needs
   (`WdmlibIoCreateDeviceSecure`, `IoCreateSymbolicLink`, `ExAllocatePoolWithTag`,
   `PsGetVersion`) with plausible return values, recording each stub.
3. Let the INIT-section VM programs run; keep the emulated image state.
4. Then invoke `sub_2800630D8` with the fabricated IRP and sweep
   `IoControlCode` over the observed values.
5. Diff the traces; the first divergence per code is the demultiplexer.

The harness already supports steps 4–5; what is missing is a `--warm` mode that
runs a list of `(entry, register setup, stub table)` before the control request.

### Option B — live capture (decisive, needs a debugger)

Single-step the running driver at `sub_2800B7DE9` under a kernel debugger, dump
the 0x800-byte state after `StorInitializeVolumeContext`, and replay it as the
warm state in Option A. This converts the emulation from a model into a replay
of observed state. Do it on a disposable VM: loading the driver at boot and
entering Shadow Mode modifies the boot configuration and the filter stack.

### What would then be unlocked

* the `\\.\DpControl` payload layout above the `'dkpt'` magic (`docs/09` §2.1);
* attribution of the remaining 26 VM programs to operations (`§2.2`);
* the remaining ~130 opcode semantics (`§2.3`), by differencing state before and
  after each handler in a warm run.

## 6. Reproduction

```bash
pip install unicorn                       # 2.1.4 used here

# program-level trace (cold state, pre-relocated table)
python tools/vm_emu.py samples/diskpt.sys 0x6B8F3 --max-dispatch 2000

# faithful entry through the DEVICE_CONTROL stub, per IOCTL code
python tools/vm_emu_ioctl.py samples/diskpt.sys 0x80000D18 \
       --trace recon/vm/ioctl_0x80000D18.trace
python tools/vm_emu_ioctl.py samples/diskpt.sys 0x800030A0 \
       --trace recon/vm/ioctl_0x800030A0.trace
```

Both tools report, separately: dispatch count, opcode histogram, unresolved
imports, and unmapped-memory events. Anything produced by a zero page or a
zeroed import must be treated as a harness input, not as observed driver
behaviour.
