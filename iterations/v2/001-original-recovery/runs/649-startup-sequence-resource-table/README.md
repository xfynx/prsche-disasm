# Run 649 quiet resource open & startup sequence resource table (`00561e00`, `0059d9b0`, `00452590`, `004690d0`)

Bounded native x86-vs-C++ recovery packet for `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::file_open_quiet_00561e00` (`00561e00..00561e3e`, 63B, `__cdecl`, `ret 0`, sha256 `f78f5bcefcb9c8d4d0aebf8a6941e95a2b939848cb11c5fe06bac54b82b1856b`): quiet sibling of `file_open_00561ca0`, sets `context.callback_diagnostic_flag = 0`.
- `porsche::resource_open_quiet_0059d9b0` (`0059d9b0..0059da7d`, 206B, `__cdecl`, `ret 0`, sha256 `67fefe2f5bf3db4a7a147cfbc16a6b1f740b2e80e7a7d2674873eccabc735dfd`): quiet sibling of `resource_open_0059d8e0`; opens via `00561e00` and invokes `missing_file_006afbe4(name, -2)` when rooted lookup fails.
- `porsche::startup_sequence_resource_table_setup_00452590` (`00452590..00452655`, 198B, `__cdecl`, `ret 0`, sha256 `ffb8506fd5bffd55a85e4e51cccae68b67e402986ee2daf4d9cf3269a60b9c7f`): loads `%snight.psh` (`"nght"` entry `+ 0x10`) when `00628a28 != 0`, resets `0061bcc8`/`0061e180`, and queries `(0, 0x44414548)` from `00613e04` via `0044d320`.
- `porsche::startup_sequence_call_004690d0` (`004690d0..004690e0`, 17B, `__cdecl`, `ret 0`, sha256 `4f4307295da4d469e18b602ab3fc7fd4f8f9e33542012ec72bcedd4b97950eb0`): declared in `porsche/startup_sequence.hpp`; calls `00452590`, sets `00619760 = 1`, and tail-jumps to `0047f040`.

## Index, Ownership & Canonical Headers

- Owned loader-zero `.data` BSS globals (zero prior owners in `iterations/v2/001-original-recovery/`):
  - `startup_night_shape_enabled_00628a28` (`00628a28..00628a29`, 2B, sha256 `96a296d224f285c67bee93c30f8a309157f0daa35dc5b87e410b78630a09cfc7`)
  - `startup_resource_prefix_0065b30c` (`0065b30c..0065b30f`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_night_shape_buffer_0061c164` (`0061c164..0061c167`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_night_shape_data_0061e1cc` (`0061e1cc..0061e1cf`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_context_table_owner_00613e04` (`00613e04..00613e07`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_head_state_a_0061bcc8` (`0061bcc8..0061bccb`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_head_state_b_0061e180` (`0061e180..0061e183`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_head_table_entry_0061e1d4` (`0061e1d4..0061e1d7`, 4B, sha256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`)
  - `startup_sequence_flag_00619760` (`00619760..00619760`, 1B, sha256 `6e340b9cffb37a989ca544e6bb780a2c78901d3fb33738768511a30617afa01d`)
- Reused canonical headers (`include_dirs`: `runs/649-startup-sequence-resource-table`, `runs/646-startup-context-table-helpers`, `runs/290-frame-service-cluster`, `runs/644-render-startup-text-leaves`, `runs/334-resource-open`, `source/include`):
  - `porsche/startup_sequence.hpp`, `porsche/files.hpp`, `porsche/resource_dispatch.hpp`, `porsche/resource_predicate.hpp`, `porsche/formatter_entry.hpp`, `porsche/fe_stream.hpp`, `resource_open_334.hpp`, `render_startup_text_leaves_644.hpp`, `startup_context_table_helpers_646.hpp`.

## Verification

- Attempt `001`: fixture compilation failed (`<initializer_list>` and `<utility>` missing in `native-fixture.cpp.in`); preserved immutable under `local/experiments/v2-startup-sequence-resource-table-649/001`.
- Attempt `002`: **PASS** (`local/experiments/v2-startup-sequence-resource-table-649/002/receipt.json`, sha256 `e3f9e26c3029b45ffc909c6c4e5ce68f6ec4b22498e81304f60be3867a5c4bfd`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/649-startup-sequence-resource-table/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and passed `startup_sequence_resource_table_original_x86_vs_cpp=PASS cases=75`.
  - All `10` material mutations exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof for `00561e00`, `0059d9b0`, `00452590`, `004690d0`, and the 9 loader-zero `.data` BSS globals using `<260B` paths, controlled arenas, and deterministic callee stubs; external producers/consumers of those 9 `.data` cells, unrecovered callers of `0059d9b0`/`00561e00`, null shape/entry fault behavior, and production CMake/registry integration remain open.
