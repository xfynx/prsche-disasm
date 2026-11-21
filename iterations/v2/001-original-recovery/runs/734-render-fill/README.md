# Run734 render display and splash solid-fill subsystem (`00537e00`, `00562680`, `00562500..00562650`)

Bounded native x86-vs-C++ recovery proof for the 12-function render/splash solid-fill subsystem (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 719 code bytes total):
- `porsche::render_display_fill_00537e00` (`00537e00..00537e2c`, 45B, `__cdecl`, sha256 `a95c3f5fcbc701738b965f7f385944dfcc7b73cc7e0cbffcf7cf4e846c2dbcee`): reads clip rectangle `window_shutdown_config_005de620[5..8]` (`005de634..005de640`) and forwards `(clip_left, clip_top, clip_right - clip_left, clip_bottom - clip_top, color)` to `00562680`. Closes frontier symbol `?render_display_fill_00537e00@porsche@@YAXI@Z`.
- `porsche::splash_progress_draw_text_00562680` (`00562680..005627ef`, 368B, `__cdecl`, sha256 `7d41dc10d7b12f8d7fd3d7baeeffca13f4a68f46836c1d7d605841235e7cd683`, jump table `005627f0..005627ff` 16B, lookup table `00562800..0056280c` 13B): when `window_shutdown_mode_005de630` (`005de630`) is not `0` or `0xff` and `window_shutdown_state_005de64c` (`005de64c`) is `0`, saves THRASH states `10` and `1` via `006bd984`, disables state `10` (`006bd97c`) and texture (`006bd954`), converts `color` via `00574b70`, converts signed 32-bit `(x, y, value, font)` via `fild`/`fstp`, draws the rectangle via `0056daf0`, and restores states `10` and texture. Otherwise replicates `color` by bit depth (`4`, `8`, `15`/`16`, else passthrough) into `render_fill_color_006a5bb8` (`006a5bb8`), initializes `render_fill_backend_005decd8` (`005decd8`) from `copy_flag_005deb1c` (`4`) / `copy_flag_005deb18` (`3`) / `0` when `< 0`, builds the local shape header `{cfg_2c & 0xff, width_u16, height_u16}`, invokes `render_shape_transfer_00571630(&desc, x, y, render_fill_mode_tables_005df8e0[backend])`, and calls `render_mmx_empty_00573070()` (`emms`) when reloaded `render_fill_backend_005decd8 == 3`. Closes frontier symbol `?splash_progress_draw_text_00562680@porsche@@YAXHHIII@Z`.
- Ten span-fill leaf callbacks referenced by `005df880..005df8f3` (`306B` total; `00562540` indexed in `functions.jsonl`, nine unindexed entries documented with full raw CFG and relocation evidence in `original-index-supplement.json`):
  - `render_fill_span_scalar_8_00562500` (`00562500..00562519`, 26B)
  - `render_fill_span_scalar_16_00562520` (`00562520..0056253c`, 29B)
  - `render_fill_span_24_00562540` (`00562540..00562569`, 42B)
  - `render_fill_span_scalar_32_00562570` (`00562570..00562590`, 33B)
  - `render_fill_span_mmx_8_005625a0` (`005625a0..005625b9`, 26B)
  - `render_fill_span_mmx_16_005625c0` (`005625c0..005625dc`, 29B)
  - `render_fill_span_mmx_32_005625e0` (`005625e0..00562600`, 33B)
  - `render_fill_span_sse_8_00562610` (`00562610..00562629`, 26B)
  - `render_fill_span_sse_16_00562630` (`00562630..0056264c`, 29B)
  - `render_fill_span_sse_32_00562650` (`00562650..00562670`, 33B)

Owned `.data` / `.bss`:
- `render_fill_backend_005decd8` (`005decd8..005decdf`, 4B `.data`, initial `-1`).
- `render_fill_table_scalar_005df880[8]`, `render_fill_table_mmx_005df8a0[8]`, `render_fill_table_sse_005df8c0[8]`, `render_fill_mode_tables_005df8e0[5]` (`005df880..005df8f3`, 116B `.data`).
- `render_fill_color_006a5bb8` (`006a5bb8..006a5bbb`, 4B `.bss`, loader-zeroed).

## Verification

- REA session (`local/experiments/v2-render-input-734-rea/001/receipt.json`, `validation.json`): PASS for `00537e00`, `00562680`, `00562540`, `00571630`.
- Attempt `001` failed pre-compile header pin scan on transitive `537 -> 536 -> 533` include directories; preserved under `local/experiments/v2-render-fill-734/001/`.
- Attempt `002` caught an out-of-bounds 8bpp palette index in the fixture's hardware 3D test loop (`0x12345678` passed to `00574b70` 256-entry palette lookup); preserved under `local/experiments/v2-render-fill-734/002/`.
- Attempt `003` (`local/experiments/v2-render-fill-734/003/receipt.json`): **PASS** at `/Od` and `/O2` (`1015` cases per variant = `2030` native comparisons, `0` failed cases, `14/14` material mutations killed).
  ```powershell
  py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/734-render-fill/native-config.json --attempt 003
  ```

## Boundaries

Bounded test domain (`PARTIAL`): verifies PE initial state before relocation, hardware 3D and software paths of `00537e00` and `00562680`, all `bpp` switch branches, lazy and preset backend selection, post-transfer backend reload and `emms` tag cleanup, and all 10 span callbacks across alignments and counts. Downstream software shape transfer `render_shape_transfer_00571630` (`00571630`, 853B) remains an explicit typed frontier boundary.
