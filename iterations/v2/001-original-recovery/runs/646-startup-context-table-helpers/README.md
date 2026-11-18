# Run 646 startup/context table helpers (`0044b830`, `0044d320`, `0047f040`, `.data 00628bac..00628baf`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::startup_context_tree_find_0044b830` (`0044b830..0044b8b7`, 136B, `__thiscall` / C++ `__fastcall` with unused `EDX`, `ret 8`, returns `out_node`, sha256 `9df4778288dd4ce2bb76301d6f523560da38e0ebee0362a4bb771cc16ce352f8`).
- `porsche::startup_context_table_lookup_0044d320` (`0044d320..0044d374`, 85B, `__thiscall` / C++ `__fastcall` with unused `EDX`, `ret 8`, returns `node+0x18` or `nullptr`, sha256 `ad4cd535d6ca2d98670350ecaae23c4eaf47b44b20a7063bdda821f6480cca13`).
- `porsche::startup_context_table_init_0047f040` (`0047f040..0047f189`, 330B, `__cdecl(void)`, `ret 0`, sha256 `c1f7ab319e41aa32821399bfe54e78223014ee3cf73eba993b7776e6837c415b`).
- `porsche::startup_context_table_00628bac` (`.data 00628bac..00628baf`, 4B loader-zero pointer cell, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`).

## Index, Ownership & Canonical Headers

- `calls.jsonl`: `0044b830` has zero callees and is called by `0044d320`, `0044d380`, and `0044a770`; `0044d320` calls `0044b830` and has 19 callers including `00452590`; `0047f040` is tail-jumped from `004690d0` (`startup_sequence_call_004690d0`).
- `references.jsonl`: only `00468ae0`, `0047f040`, and `0047f190` access `00628bac` (no prior owner in `iterations/v2/001-original-recovery/`); `0047f040` reads `00628960` (`frame_service_root_00628960`) and `005e4fe8` (`application_context_heap_state_005e4fe8`).
- Reused canonical headers (`include_dirs`: `runs/646-startup-context-table-helpers`, `runs/290-frame-service-cluster`, `source/include`):
  - `iterations/v2/001-original-recovery/source/include/porsche/application_alloc.hpp` (`startup_network_allocate_0059ef90`)
  - `iterations/v2/001-original-recovery/source/include/porsche/context_effects.hpp` (`context_table_release_0059ecd0`, `application_context_member_storage_004211d0`, `application_context_heap_state_005e4fe8`, `heap_enter_005322b0`, `heap_leave_005322c0`)
  - `iterations/v2/001-original-recovery/runs/290-frame-service-cluster/frame_service_290.hpp` (`frame_service_root_00628960`)

- COFF section summary (`od-0.obj` / `o2-0.obj`): `4` bytes `.bss` (`?startup_context_table_00628bac@porsche@@3PAXA`), `0` bytes `.rdata`; defines `4` symbols and references only the `7` canonical externals above (including `?frame_service_root_00628960@porsche@@3IA`).

## Verification

- Attempt `001`: failed on non-material mutation `wrong-47f040-cap-threshold` (`cur_cap < target_cap` -> `cur_cap <= target_cap` at `target_cap == 0` produces identical zero-state vector); preserved immutable under `local/experiments/v2-startup-context-table-helpers-646/001`.
- Attempt `002`: **PASS** (`local/experiments/v2-startup-context-table-helpers-646/002/receipt.json`, sha256 `c2f564d7940bfc64e07796223f37a4b45f20e1f9d62570b31d1d6a0273a6e6ee`)
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/646-startup-context-table-helpers/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and passed `startup_context_table_helpers_original_x86_vs_cpp=PASS cases=56`.
  - All `7` material mutations (`wrong-44b830-upper-key-order`, `wrong-44b830-post-check`, `wrong-44d320-value-offset`, `wrong-47f040-already-initialized-guard`, `wrong-47f040-table-alloc-bytes`, `wrong-47f040-cap-offset`, `wrong-47f040-vec-storage-bytes`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `0044b830`, `0044d320`, `0047f040`, and `.data` `00628bac..00628baf` using controlled tree/arena buffers and deterministic callee stubs. In `0047f040`, the inlined vector reserve copy/deallocation branches (`0047f0dd..0047f14f`) are structurally unreachable after zero-initializing the newly allocated `0x0c`-byte vector at `0047f07d..0047f082` and are preserved verbatim; null `vec`/`frame_service_root_00628960` fault behavior, external storage ownership of `frame_service_root_00628960`, callers (`004690d0`, `00452590`), and production CMake/registry integration remain open.
