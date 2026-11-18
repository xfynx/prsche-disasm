# Run 650 startup text fallbacks & quality-mask helper (`0044de50`, `0044de60`, `0044df70..0044dfa0`, `0044dfe0`)

Bounded native x86-vs-C++ recovery proof for seven `Porsche.exe` functions (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 265 code bytes total):
- `porsche::startup_text_fallback_4_0044de50` (`0044de50..0044de5f`, 16B, `__cdecl() -> void`, sha256 `e2517159161164853ac19577fd6386ab24edc851d4f64f3f7f9c206687950074`).
- `porsche::startup_text_fallback_apply_0044de60` (`0044de60..0044df02`, 163B, `__cdecl(const StartupTextFallbackEntry650*, int32_t) -> void`, sha256 `9eab89ed1d6e0b33a94aefa5c1297cbf80060d059f6594b40305e21c66702790`).
- `porsche::startup_text_fallback_0_0044df70` (`0044df70..0044df7f`, 16B, `__cdecl() -> void`, sha256 `feef284f2ef3819e0552a9409754b5d9cd0bee82dab7cfaa66947991db3ab23a`; supplemented in `original-index-supplement.json`).
- `porsche::startup_text_fallback_1_0044df80` (`0044df80..0044df8f`, 16B, `__cdecl() -> void`, sha256 `361fdb277107a1942d7699806a0b8ebb974fb7be07e3b3dec42c9a0105d7f4a1`; supplemented in `original-index-supplement.json`).
- `porsche::startup_text_fallback_2_0044df90` (`0044df90..0044df9f`, 16B, `__cdecl() -> void`, sha256 `2850b72d41a2a5eb694ac4cbf1cee08f5871198a3ff510507431c0d2348b9935`; supplemented in `original-index-supplement.json`).
- `porsche::startup_text_fallback_3_0044dfa0` (`0044dfa0..0044dfa0`, 1B, `__cdecl() -> void`, sha256 `ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e`; supplemented in `original-index-supplement.json`).
- `porsche::startup_text_quality_mask_ptr_0044dfe0` (`0044dfe0..0044e004`, 37B, `__cdecl(uint32_t) -> uint32_t*`, sha256 `b5c2700c0fbb0c804b9ed5826fdaa7ea7374f25810ade35ca65f9d512ac43575`).

## Data Ownership & Canonical Reuse

- Owned `.data` in `startup_text_fallbacks_650.cpp`:
  - `startup_text_fallback_table_0_005ce658[11]` (`005ce658..005ce699`, 66B, sha256 `db2d2826464c69d117454bb948b3d4d83d8ee5e78245deccb08e3afdb98198bb`).
  - `startup_text_fallback_table_1_005ce69c[10]` (`005ce69c..005ce6d7`, 60B, sha256 `8902bbe0b888323cfad06dd5d9a8ba39ebb6d09513fc74f969d14bcbd70b8d59`).
  - `startup_text_fallback_table_2_005ce6d8[11]` (`005ce6d8..005ce719`, 66B, sha256 `1c155024cf9bcda39b954b5097444d0788e53ac4449333cbbfab56679ad37d6b`).
  - `startup_text_fallback_table_4_005ce71c[12]` (`005ce71c..005ce763`, 72B, sha256 `d489fafb492214fc9028381f975ac7a54d4fb9d7ea745095e1b9072ea616189e`).
- Reused canonical globals/callees:
  - `render_mode_state_00619790` (`006197ae` = `[0x1e]`, `00619800` = `[0x70]`, `source/include/porsche/render_mode.hpp`)
  - `render_quality_selected_00619770` (`runs/596-startup-quality-tier/startup_quality_tier_596.hpp`)
  - `startup_text_quality_masks_005ce59c` (`runs/647-startup-sequence-text/startup_sequence_text_647.hpp`)
  - `render_texture_slot_bind_00555640` (`runs/644-render-startup-text-leaves/render_startup_text_leaves_644.hpp`)

## Verification

- Attempt `001` (`local/experiments/v2-startup-text-fallbacks-650/001/receipt.json`, sha256 `a257e6891ffd50857fe1035c156294033a9574c53b18b5f87781808fafd0da39`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/650-startup-text-fallbacks/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero `/W4` warnings and passed `startup_text_fallbacks_original_x86_vs_cpp=PASS cases=94 events=350`.
  - All 12 material mutations (`wrong-44de50-count`, `wrong-44df70-table`, `wrong-44df80-count`, `wrong-44df90-table`, `wrong-44dfa0-non-empty`, `wrong-44de60-mip-global`, `wrong-44de60-mip-shift`, `wrong-44de60-format-b`, `wrong-44de60-slot1-stage`, `wrong-44de60-slot0-sign`, `wrong-44dfe0-alt-index`, `wrong-44dfe0-row-stride`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native x86-vs-C++ proof using real owned `.data` tables (`005ce658`, `005ce69c`, `005ce6d8`, `005ce71c`), fixture-defined canonical globals (`render_mode_state_00619790`, `render_quality_selected_00619770`, `startup_text_quality_masks_005ce59c`), and controlled `render_texture_slot_bind_00555640` stub. Out-of-range quality (`>= 4`) or mask index (`>= 6`) on `0044dfe0`, invalid non-null `entries` with `count > 0` on `0044de60`, real callee integration (`00555640`), callers, and production CMake/registry integration remain open.
