# Run596 startup quality tier (`0044dfb0`, `0044e370`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_quality_tier_0044e370` and
`porsche::startup_sequence_call_0044dfb0` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `0044dfb0..0044dfd2` (35 bytes, sha256 `d522b7537756b3933f2ae53933abf93ee439e98952c830423ba32a15ffc82628`)
- `0044e370..0044e405` (150 bytes, sha256 `f4fee5f73afda6f1ff395d60f11e1e3bcd6a3ec1c127761bf639debafdf5ec50`)

## Verification

- Attempt `001` (`local/experiments/v2-startup-quality-tier-596/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/596-startup-quality-tier/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `startup_quality_tier_original_x86_vs_cpp=PASS cases=9504 events=9504`,
    comparing relocated original x86 against C++ for both `render_quality_tier_0044e370` (return
    `EAX`) and `startup_sequence_call_0044dfb0` (`0x00657d88` arena write, `0x00619770` clamp
    `3 -> 2` when `mode < 0x20u`, unrelated arena words untouched) across negative/zero/boundary
    `time_val`, `state0 >> 20`, `phys` (`0053c3d0`), `mode` (`0061978c`), ABI, and `FXSAVE`/MXCSR.
  - Mutation controls (`wrong-time-threshold`, `wrong-phys-threshold`, `wrong-mode-clamp`,
    `omit-arena-tier-write`) all exited `1` on `divergence`.

## Boundaries

Controlled test storage and callback boundary stand in for `render_resource_total_phys_0053c3d0`
and external globals (`005ce908`, `00619790`, `0061978c`); malformed pointers/faults, arbitrary
aliases, and production CMake/registry integration remain open.
