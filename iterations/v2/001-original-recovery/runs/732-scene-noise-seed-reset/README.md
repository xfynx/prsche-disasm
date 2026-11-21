# Run732 scene noise seed reset and companion PRNG seed writer

Native `003` PASS: recovers `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) `scene_stage_reset_0044f240` (`0044f240..0044f2ed`, 174B, `__cdecl void()`, RET 0) and its sole unrecovered callee `render_seed_prng_seed_00538110` (`00538110..00538150`, 65B, `__cdecl void(uint32_t)`, RET 0) in `scene_noise_seed_732.cpp`. Closes the `727/build-001.json` frontier symbol `?scene_stage_reset_0044f240@porsche@@YAXXZ` (called by `startup_sequence_call_00468fb0` in `application_view_lifecycle_693.cpp`) and the open companion seed-writer boundary from Run638 (`00538040`) with zero new unresolved frontier symbols and no existing TU replacements.

## Original evidence & ownership

- Ghidra REA session `local/experiments/v2-scene-noise-seed-reset-732/rea/001` (`receipt.json`, audited in `rea/validation.json`) extracts `function-0044f240.json`, `function-00538110.json`, and downstream reader `function-0044f2f0.json`.
- `00538110` writes the six contiguous 32-bit state words of canonical `render_seed_prng_state_005de910[6]` (`0x005de910..0x005de927`, owned by Run638) using the exact cumulative additive/subtractive constants (`+0xf22d0e56`, `-0x69fbe76d`, `+0x3df3b646`, `+0x40dde76d`, `-0x68cd851f`, `+0xd1a9fbe7`). At `seed == 0` these produce the exact initial `.data` words of `005de910..005de927`.
- `0044f240` clears `scene_noise_flag_005ce938` (`0x005ce938`, 4B `.data`, initial value `1`), snapshots the next word from canonical `render_seed_prng_next_00538040()` (`00538040`, Run638), seeds the PRNG with `0x3039` (`12345`) via `00538110`, populates the 267-float gradient table `scene_noise_gradient_00619804[267]` (`0x00619804..0x00619c2f`, 1,068B loader-zero `.bss`) via unsigned-64 `FILD QWORD`, `FMUL [0x005b3ca4]` (`2^-32f`), `FSUB [0x005b23f0]` (canonical `render_surface_half_005b23f0 = 0.5f`, Run511), `FADD ST(0), ST(0)`, and `FSTP DWORD`, initializes `scene_noise_perm_00619c30[4096]` (`0x00619c30..0x0061bc2f`, 8,192B loader-zero `.bss`) to `0..4095`, shuffles all 4,096 entries from index `4095` down to `0` inclusive (`JGE` after `SUB ESI, 2; CMP ESI, 0x619c30`) using `render_seed_prng_next_00538040() & 0xfff`, and restores the PRNG via `00538110(saved_seed)`.
- Newly owned symbols (zero `functions.json` / `body_ranges` overlap, zero external storage collisions):
  - `.rdata` `0x005b3ca4` (4B, raw `0x2f800000`): `porsche::scene_noise_inv_2pow32_005b3ca4`
  - `.data` `0x005ce938` (4B, raw `0x00000001`): `porsche::scene_noise_flag_005ce938`
  - `.bss` `0x00619804..0x00619c2f` (1,068B, loader-zero): `porsche::scene_noise_gradient_00619804[267]`
  - `.bss` `0x00619c30..0x0061bc2f` (8,192B, loader-zero): `porsche::scene_noise_perm_00619c30[4096]`

## Verification

```powershell
py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/732-scene-noise-seed-reset/rea/queries.json --attempt 001
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/732-scene-noise-seed-reset/rea/queries.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/732-scene-noise-seed-reset/native-config.json --attempt 003
py -3 iterations/v2/001-original-recovery/runs/732-scene-noise-seed-reset/audit.py
```

- Receipt: `local/experiments/v2-scene-noise-seed-reset-732/003/receipt.json` (`status: PASS`).
- 68 cases per `/Od` and `/O2` (136 measured original-x86 vs C++ comparisons): 32 direct and `00538110 -> 00538040` composed seed-stream comparisons plus 36 full `0044f240` reset comparisons across 6 initial PRNG states and 6 x87 control-word precision/rounding configurations (`PC=24/53/64`, `RC=nearest/down/up/chop`) and pre-seeded FPU stack depths.
- 10/10 material mutations killed (`wrong-seed-s0-const`, `wrong-seed-s3-add`, `wrong-seed-s5-const`, `wrong-noise-flag-clear`, `wrong-fixed-seed-const`, `wrong-gradient-count`, `wrong-gradient-double`, `wrong-perm-mask`, `wrong-perm-lower-bound`, `wrong-seed-restore`), all exiting with code `7` on `"divergence "`.
- Preserved failed attempts: `001` had a duplicate token mention in a comment in `native-fixture.cpp.in`; `002` passed all 267 floats and 4,096 permutation words but exposed an x87 `C1` status-bit difference under `/Od` when a helper returned `float` in `ST(0)` (`FLD`+`FSTP` cleared `C1`), resolved in `003` by storing directly via `FSTP DWORD PTR [eax]`.

## Boundaries

Lattice noise evaluator `0044f2f0` and the remaining unrecovered callers of `00538110` (`00428940`, `004e3160`, `004f7db0`) remain separate unrecovered functions. Shared CMake/registry integration is deferred to the integration run.
