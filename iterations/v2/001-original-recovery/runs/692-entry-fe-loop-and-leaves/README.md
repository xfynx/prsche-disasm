# Run692 FE entry-region leaves (`00413ea0`, `00414eb0`; `004152e0` deferred)

Bounded original-x86 vs C++ recovery proof for two unresolved app_main-path leaves; evidence pack for the third. Module `Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39` (re-verified against `local/game/Porsche.exe`). All three VAs are unowned in `source/recovered/functions.json` (only listed in `unrecovered_dependencies` of entry `004b6a50`); binary-index body ranges and all body SHA-256 values were re-checked against raw PE bytes.

## Bodies

- `porsche::application_main_function_00413ea0` (`00413ea0..00413fc7`, 296B, `__cdecl` void/ret 0, sha256 `99fe96b4…f64c`): FE entry reset. Mode 0/1 clears 0x6400-dword replay scratch `005ed848..00606847` plus `005e99f8`/`005e99fc` and copies state word `0065741c` to `00606858`; mode >=2 resets the `00606860..00606870` words, probes `0046d960`, then either walks `application_audio_source_storage_005e8bfc` cells 1..count writing `0046d890()` returns to object `+0x10e4` and calling `00413960` (state word `006573e8 == 9` skips straight to the 0x14 epilogue), or stores 0xa and calls `004659e0(0,0xa)` on a zero probe. Caller `004b6dbe`.
- `porsche::application_main_function_00414eb0` (`00414eb0..00414f73`, 196B, `__cdecl` void/ret 0, sha256 `873b8b28…51d0`): reuses the unchanged canonical TU `runs/400-frame-loop-clusters/00414eb0.cpp` (first compiled here); resets frame/session cells and issues ten zero-arg/one-arg service calls. Caller `004b6db4`. The fifteen `frame_reset_*` cells get their only definitions in `fe_entry_leaves_692.cpp` (no prior owner in the closure).
- `004152e0` (`004152e0..00415d51`, 2674B, sha256 `f6138852…0d749`): **DEFERRED**. Verified 133 calls / 85 unique callees, ~70 of them unrecovered, two constructed stack objects, a 27-case switch with unowned read-only tables `00415d54`/`00415d9c`. Full evidence in `body-evidence.json` / `scope-evidence.json` / `evidence.json`. Caller `004b6ec8`. `004121b0` appears only as a documented callee; it and `00411d20` are Run695 territory and were not touched.

Caller extern declarations in `source/include/porsche/application_main.hpp` (lines 52/54/59) are exact zero-argument `void __cdecl` matches; no caller was modified.

## Verification

- Attempt `015` (`local/experiments/v2-entry-fe-loop-and-leaves-692/015/receipt.json`): PASS at `/Od` and `/O2`. 23 cases per variant (46 measured input/state/call-trace comparisons) and 18/18 material `wrong-*` mutations detected.
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/692-entry-fe-loop-and-leaves/native-config.json --attempt 015`
  - Attempts 001-014 are preserved failed attempts: all crashed because `patch_rel` patched E8 rel32 against the original VA instead of the runtime copy address. The current template uses `address(slot) + off + 5`; attempts are immutable and were not reused or renamed.

## Ownership

Owned here: ten `fe_loop_word_*` 4B cells, `fe_replay_scratch_005ed848[0x6400]` (0x19000B STOSD span), and the fifteen `frame_reset_*` definitions. Reused canonical owners (unchanged declarations): `global_005e99f4`, `replay_state_005e99fc`, `replay_mode_flag_00606858`, `application_state_006573e8` words, `application_audio_source_storage_005e8bfc` (extent still deferred), `frame_reset_source_005e99b8`, `startup_sequence_word_00606ac0/00606ac4`. No invented arrays, callbacks or table extents.

## Boundaries

`004152e0` is evidence-only, not a recovery claim. New frontier callees `0046d960/0046d890/00413960/004659e0` are typed declarations, not proven providers. The 5-cell audio storage view is a bounded harness transport. Native fixtures, callorder stubs and the ABI canary are harness code only. Production build/registry/COFF-ownership audit, real frontier providers, concurrency/fault/live-device behavior and full-game startup/visual acceptance remain open; no guessed implementation was integrated.
