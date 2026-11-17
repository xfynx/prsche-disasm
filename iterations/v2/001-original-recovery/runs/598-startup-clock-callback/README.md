# Run598 startup clock callback (`004a4700`, `00560140`)

Bounded native x86-vs-C++ recovery proof for `porsche::startup_sequence_call_004a4700` and
`porsche::clock_worker_register_callback_00560140` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `004a4700..004a4759` (90 bytes, sha256 `85a22a84d0758c82e74af76b08e70eac46414be4b8e9aff443c64955812c2a3f`)
- `00560140..00560176` (55 bytes, sha256 `b45f2346092ef605f5a05368779fdea8df5a7e1efe25c74682033e7a5b446cc4`)

## Verification

- Attempt `001` (`local/experiments/v2-startup-clock-callback-598/001`): failed on `omit-reset-source-zero` non-unique mutation anchor (preserved).
- Attempt `002` (`local/experiments/v2-startup-clock-callback-598/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/598-startup-clock-callback/native-config.json --attempt 002`
  - `/Od` and `/O2` both printed `startup_clock_callback_original_x86_vs_cpp=PASS cases=178 events=0`,
    comparing relocated original x86 against C++ for `clock_worker_register_callback_00560140`
    (empty/partial/full/scattered-null tables, duplicates at slots `0..7`, `nullptr` callback)
    and `startup_sequence_call_004a4700` (`0x00655a04` in `{0, 1, 2, 0xffffffff}`, `0x00655a08`
    and `0x006559e0` unconditional zeroes, `0x004a45d0u` registration and 7 guarded zeroes),
    ABI, and `FXSAVE`/MXCSR.
  - Mutation controls (`omit-duplicate-scan`, `wrong-slot-limit`, `invert-init-guard`,
    `omit-reset-source-zero`) all exited `1` on `divergence`.

## Boundaries

Controlled test storage stands in for `frame_pump_word_00655a08` and
`clock_worker_callbacks_006b7c20[8]`; callback literal `0x004a45d0u` is passed without executing
the callback body; malformed pointers/faults, arbitrary aliases, and production CMake/registry
integration remain open.
