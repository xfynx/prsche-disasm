# Run 647 startup sequence text (`0044df10`, `0044e010`)

Bounded native x86-vs-C++ recovery proof for two `Porsche.exe` functions (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 698 code bytes total):
- `porsche::startup_sequence_text_0044df10` (`0044df10..0044df62`, 83B, `__cdecl(uint32_t text_va) -> void`, sha256 `f5059db380db42931ac81fd47aad19a79e21ea0e7ced174212e3ecbcdd841456`).
- `porsche::startup_text_load_0044e010` (`0044e010..0044e276`, 615B, `__cdecl(uint32_t text_va) -> bool`, sha256 `6908ff62044e244d73104e8cca4803513fb1b3203729570d73c0513c8d135e5a`).

## Data Ownership & Canonical Reuse

- Owned `.data` in `startup_sequence_text_647.cpp`:
  - `startup_text_quality_masks_005ce59c[24]` (`005ce59c..005ce5fb`, 96B, sha256 `493ed4627abe3ebd9cdd3351d205ae4e0d36cfc856690296f57f716c0f19ed44`).
  - `startup_text_slots_005ce768[11]` (`005ce768..005ce8f3`, 396B, sha256 `eeda48d0e41e12044ece7788f5c71660ae53c4e1682510366e3d35c7556ac094`; includes sub-addresses `005ce770`, `005ce7b8`, `005ce8bc`, `005ce8c0`).
  - `startup_text_dtx_fmt_005ce8f4[9]` (`005ce8f4..005ce8fc`, 9B, `"%s%s.dtx\0"`, sha256 `4aa5d1a1e18d61e122c6fd88a460113283655619714b8556ad07fc15fd76dffe`).
- Reused canonical globals/callees:
  - `render_quality_selected_00619770` (`runs/596-startup-quality-tier/startup_quality_tier_596.hpp`)
  - `render_mode_state_00619790` (`00619800` = `[0x70]`, `source/include/porsche/render_mode.hpp`)
  - `install_paths_table_0065b2a0` (`0065b2b8` = `[6]`, `source/include/porsche/install_paths.hpp`)
  - `application_state_006573e8` (`00657444`, `source/include/porsche/application_state.hpp`)
  - `render_texture_format_16bit_mode_00554930`, `render_texture_slot_bind_00555640` (`runs/644-render-startup-text-leaves/render_startup_text_leaves_644.hpp`)
  - `formatter_entry_raw_005a0fbf` (`source/include/porsche/formatter_entry.hpp`)
  - `rooted_file_exists_0059dc30` (`runs/499-rooted-file-exists/rooted_file_exists_499.hpp`)
  - `resource_open_0059d8e0` (`runs/313-pr9-resource-open/resource_open_313.hpp`)
  - `free_00531f90` (`source/include/porsche/fe_stream.hpp`)
- Required `include_dirs`: `runs/647-startup-sequence-text`, `runs/313-pr9-resource-open`, `runs/494-render-resource-leaves`, `runs/499-rooted-file-exists`, `runs/596-startup-quality-tier`, `runs/644-render-startup-text-leaves`, `source/include`.

## Verification

- Attempt `002` (`local/experiments/v2-startup-sequence-text-647/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/647-startup-sequence-text/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled with zero `/W4` warnings and passed `startup_sequence_text_original_x86_vs_cpp=PASS cases=40 events=1360`.
  - All 10 material mutations (`wrong-44df10-16bit-mode-arg`, `wrong-44df10-fallback-polarity`, `wrong-44df10-fallback-table-order`, `wrong-44e010-alt-slot-5ce8bc`, `wrong-44e010-5ce8c0-values`, `wrong-44e010-dtx-sign-extend`, `wrong-44e010-skip-self-mask`, `wrong-44e010-take-next-offset`, `wrong-44e010-format-b-for-2`, `wrong-44e010-second-bind-flags`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof using real owned `.data` tables (`005ce59c`, `005ce768`, `005ce8f4`), real canonical `application_state.cpp` and `install_paths_storage.cpp`, controlled callee stubs (`00554930`, `00555640`, `005a0fbf`, `0059dc30`, `0059d8e0`, `00531f90`), and controlled fallback stubs (`0044df70`, `0044df80`, `0044df90`, `0044dfa0`). Unrecovered fallback targets (`0044df70..0044dfa0`, `0044de60`), out-of-range quality (`>= 4`), null `resource_open`/`install_paths_table[6]` fault behavior, real callee integration, callers (`004b67b0`, `004152e0`), and production CMake/registry integration remain open.
