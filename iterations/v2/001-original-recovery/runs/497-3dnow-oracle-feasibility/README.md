# Run497: bounded 3DNow oracle feasibility

Feasibility PASS, frozen001. Installed Unicorn2.1.3 executes unchanged original
PFMUL/PFADD/PI2FD/FEMMS bytes on its Athlon11 and Phenom1 CPU models. All8 AMD
known-input probes match exact expected output bits/reset state. Default model19
rejects all4 with `Invalid instruction (UC_ERR_INSN_INVALID)`, errno10, at the
target instruction. Host PF7 remains false; no native acceptance is claimed.

The pinned Porsche.exe SHA256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index queries0059bc40/0059bb90 locate the registered original functions and
00598460 selector references. Raw PE bytes, not inferred pseudocode, provide:

- 0059bc6a `0f0fc8b4`: PFMUL mm1,mm0; `(1.5,-2)*(2,3)` gives
  raw `000040400000c0c0` / `(3,-6)`.
- 0059bc73 `0f0fca9e`: PFADD mm1,mm2; `(1.5,-2)+(2,3)` gives
  raw `000060400000803f` / `(3.5,1)`.
- 0059bbb4 `0f0fc90d`: PI2FD mm1,mm1; `(-32768,32767)` gives
  raw `000000c700feff46` / `(-32768.0,32767.0)`.
- 0059bcdb `0f0e`: FEMMS; observed FPTAG5559 becomesffff, FPSW0000
  stays0000 after a harness MMX load. PF operation tags remain555a/5569/5559
  respectively. These are observed Unicorn getter values, not hardware tag proof.

API: `Uc(UC_ARCH_X86, UC_MODE_32)`, then `ctl_set_cpu_model(11)` before memory or
register initialization. `ctl_get_cpu_model()` confirms11. Core API version is
`(2,1,33620991)`. The installed package exposes38 models; [feasibility.json](feasibility.json)
records the complete inventory, module path, Python/Capstone versions, original
body bytes/hashes/disassembly and every state/error/output. No install/network,
emulator patch or production source/registry/build change was needed.

The probe maps only harness memory, executes exact target opcodes copied from the
SHA-checked PE and uses synthetic MOVQ setup/output transport. It tests finite
known inputs only; full bodies, exceptional FP values, producer/caller contracts,
hardware conformance, live audio and gameplay remain unproved. No approximate
replacement or accepted function count follows.

```powershell
py -3 iterations/v2/001-original-recovery/runs/497-3dnow-oracle-feasibility/probe.py
```

The command created immutable
`local/experiments/v2-3dnow-oracle-feasibility-497/001/result.json`; it rejects an
existing output directory. The local attempt contains the exact probe input;
the tracked report is its byte-for-byte copy. Do not overwrite001 or modify the
frozen probe; later scope belongs in a separate batch.

[Next batch proposal](next-batch-proposal.md) describes original-vs-C++ comparison
under the same emulated CPU. Run490/492/495 and their accepted inputs are untouched.
