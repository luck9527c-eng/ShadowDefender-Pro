# Shadow Defender — The `\\.\DpControl` Protocol

> Status: **decoded from native code**. This closes the open item that
> `docs/09` §2.1 listed as the highest-value unknown.
>
> Evidence: `sub_280063121` (RVA `0x13121`), decompiled to
> `recon/ioctl/ioctl_demux.c`. See §1 for why IDA had never shown this code.

---

## 1. Where the protocol actually lives

The device-control entry `sub_2800630D8` (VA `0x2800630D8`) is 23 instructions:

```
0x2800630d8  mov [rsp+arg_0], rcx
0x2800630dd  push rbx .. r15
0x2800630e9  sub rsp, 88h
0x2800630f0  mov rbx, [rcx+40h]      ; DeviceExtension
0x2800630f4  mov r14, [rdx+0B8h]     ; Irp->CurrentStackLocation
0x2800630fb  mov rbp, rdx
0x2800630fe  mov rdi, rcx
0x280063101  jmp loc_2800BBB22       ; -> VM: push 6B8F3h; push 4Fh; jmp relocator
```

Because that `jmp` is unconditional, IDA treats everything after it as
unreachable and leaves **~2,900 bytes undecoded**. That region is the actual
IOCTL demultiplexer: it begins at `0x280063121` and runs to the function
epilogue at `0x280063c5c`.

It is reached when the VM returns. Forcing instruction creation at
`0x280063121` in a scratch database (delete the old function, `del_items`, then
`create_insn` + `add_func`) yields a normal Hex-Rays function. The recipe is in
`tools/ida_force_stub.py`.

The bytes just before the entry (`0x280063106..0x280063120`) are not code:
`b1 87 72 48 81 21 3a 97 3d e0 1c 3a e1 75 b4 3c …`.

## 2. Transport

```
Device      \\.\DpControl            (kernel: \FileSystem\Filters\DpControl)
Buffer      one 136-byte (0x88) block, METHOD_BUFFERED, used for both input and output
Validation  InputBufferLength == 0x88 AND OutputBufferLength == 0x88, else STATUS_INVALID_PARAMETER
```

The demux begins with a device identity check
(`cmp rdi, qword ptr [rip+0x118da]`), i.e. it only accepts requests that arrived
on the control device object.

### Payload

```c
struct dp_request {            /* 136 bytes */
    uint32_t magic;            /* 0x00  must be 0x74706B64 ("dkpt")            */
    uint32_t command;          /* 0x04  command selector, see §4              */
    uint64_t arg0;             /* 0x08  handle / size / pointer, per command  */
    uint64_t arg1;             /* 0x10  second handle / value, per command    */
    uint8_t  reserved[0x78];   /* 0x18                                         */
};
```

`0x74706B64` is also the driver's pool tag.

## 3. IOCTL set

| IOCTL | Signed | Behaviour (observed) |
| --- | --- | --- |
| `0x8000309C` | `-2147471204` | Session/ID query. Calls `sub_280051DB4(-1, &id)` and then `sub_280051F24(current_process, current_thread, id)`. Writes `29521` (`0x7351`) to `FileObject+0x18`. |
| `0x800030A0` | `-2147471200` | **Returns installation data.** Zeroes `buffer+8` for `0x80` bytes, then `memmove(buffer+8, &unk_280075680, 0x80)`; sets `IoStatus.Information = 136`. `unk_280075680` is the 128-byte installation blob — this is how `Defender.exe` obtains the GUID that salts the password hash (`docs/08`). |
| `0x80000CD4` | `-2147480364` | **Registers the calling process.** Writes `29522` (`0x7352`) to `FileObject+0x18`, then inserts `IoGetCurrentProcess()` into a 32-slot table at `qword_280074C20` (idempotent; a full table returns without inserting). |
| `0x80000D18` | `-2147480296` | **Exit / teardown.** If `byte_2800742E8 != 0`, clears it and calls `sub_28005E7CC(NULL)`. |
| `0x80002D48` | `-2147472056` | Volume-side flag. Sets `DeviceExtension+552 = 1`; returns `0x20000001` when already set. This is exactly the `ERROR 0x20000001` that `Service.exe` tolerates (`docs/04`). Reached through a separate branch that also enters the VM. |
| *derived* | — | The **command channel** (§4). Its IoControlCode is compared against a value the VM computes at run time, which is why the user-mode side uses installation-derived IOCTL numbers. |

All four fixed codes were also seen from the user-mode side except `0x8000309C`.

## 4. Command set

After the fixed IOCTLs, the demux checks:

```
if (code != <vm-derived>)  -> STATUS_INVALID_DEVICE_REQUEST
if (buffer[0] != 'dkpt')   -> STATUS_INVALID_DEVICE_REQUEST
switch (buffer[4]) { ... }
```

Observed command semantics:

| cmd | Behaviour |
| --- | --- |
| **0** | Falls through the selector chain; handler not yet separated from the shared tail. **Unknown.** |
| **101** | Register a **progress event**. `arg0` is an event handle; `ObReferenceObjectByHandle(arg0, 0x1F0003, ExEventObjectType)`; allocates a `0x28`-byte node (tag `'dkpt'`), stores the event at node+24, links it into `qword_280075700`, and publishes the node as the file's context (`FileObject+0x18`). |
| **102** | Signal every registered progress event (`KeSetEvent`) under `stru_280075620`. This is the completion broadcast the GUI listens for. |
| **200** | Register an **event pair**: `arg0` and `arg1` are both event handles; both are referenced and stored in a `0x28`-byte node (node+24 / node+32) linked into `qword_280075390`. |
| **201** | Register / increment the calling thread in the session table `qword_280075710` (per-process entry: process at +16, two threads at +32/+40, counters at +48/+52). Calls `sub_28005214C(process, thread, 0)` first as a filter. |
| **202** | Unregister / decrement the matching thread counter. |
| **300** | Open and register two file handles. Requires `arg0 != 0` and `arg1 != 0`; allocates a `0x28`-byte node, then performs two open-by-handle-style calls with access `0x1F0003` (`arg0` at `[rsp+0x48]`, `arg1` at `[rsp+0x60]`). |
| **500** | **Set write-cache size.** `dword_280074EE0 = *(uint64_t *)(buffer+8) / 1024` (bytes → KB). |
| **501** | **Get write-cache size.** `*(uint64_t *)(buffer+8) = dword_280074EE0 << 10` and `*(uint64_t *)(buffer+0x10) = dword_280074EE4 << 10` (KB → bytes; the two values are total and used). |

The selector is a chain of subtractions, so the accepted values are exactly
`0, 101, 102, 200, 201, 202, 300, 500, 501`; anything else ends in
`STATUS_INVALID_DEVICE_REQUEST`.

## 5. Per-file context tags

Two magic values are written to `FileObject+0x18` (the FsContext slot) to mark
what kind of session a file handle represents:

| Value | Written by | Meaning (inferred) |
| --- | --- | --- |
| `29521` (`0x7351`) | IOCTL `0x8000309C` | ID/session query handle |
| `29522` (`0x7352`) | IOCTL `0x80000CD4` | registered client process |

The `0x28`-byte pool nodes allocated by commands 101/200/300 all carry the pool
tag `'dkpt'`.

## 6. How the VM and the native demux fit together

The device-control path is a **two-stage filter**:

1. `sub_2800630D8` saves the device/IRP context and enters the VM with program
   `0x6B8F3` (entry index 79).
2. The VM runs a ~50-opcode prologue (see `docs/11`) that operates on data words.
3. Control returns into `0x280063121`, where the **native** demux validates the
   buffer sizes, switches on `IoControlCode`, checks the `'dkpt'` magic and
   dispatches the command.

That explains two things that were previously puzzling:

* why the emulated VM trace is identical for every IOCTL code — the code is
  consumed *after* the VM returns, not by the VM;
* why the user-mode callers use installation-derived IOCTL numbers for the
  command channel but fixed numbers for the four auxiliary codes.

## 7. Reconstructed header

`include/sd.h` has been updated with this structure, the IOCTL constants and the
command enumerator.

## 8. What is still open

* **cmd 0** — it shares the tail of the command chain and has not been isolated.
* Which value the VM computes for the command-channel IOCTL number, and how it
  derives it from the installation GUID.
* The 128-byte layout of `unk_280075680` returned by `0x800030A0` (it contains
  the GUID; the remaining bytes are not yet mapped).
* Commands 201/202's counters (+48/+52) are incremented/decremented but their
  effect on the data plane is not traced.
