# Run589 frame state release (`005363a0`)

Bounded native x86-vs-C++ recovery proof for `porsche::frame_pump_boundary_005363a0` /
`porsche::startup_lifecycle_apply_raw_005363a0` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, body `005363a0..00536451`,
178 bytes, sha256 `4317a6d2d78522e8b3b4a2b34d39961d5a73ce36fb94972a7510fdae7c7a03bf`).

- Attempt `001` (`local/experiments/v2-frame-state-release-589/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/589-frame-state-release/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `frame_state_release_original_x86_vs_cpp=PASS cases=3024 events=45792`
    comparing relocated original x86 against both `startup_lifecycle_apply_raw_005363a0` (`__fastcall`)
    and `frame_pump_boundary_005363a0` (`__cdecl`) across all receiver-slot, gate, alignment,
    callback-mutation, reload-after-release, ABI, and `FXSAVE`/MXCSR cases.
  - Mutation controls (`omit-second-loop-pass`, `wrong-record-stride`, `skip-active-gate`,
    `omit-second-slot-reload`) all exited `1` on `divergence`.

## Boundaries

Controlled test storage/callbacks stand in for the canonical `527`/`570`/`572` externals;
malformed pointers/faults, arbitrary aliases, production CMake/registry integration, and caller
semantics (`004b0d70`, `00536a60`) remain open.
