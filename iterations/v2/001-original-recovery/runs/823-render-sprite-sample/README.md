# Run823: Subpixel bilinear sprite sampler (`0058ccbf`)

Recovers `render_sprite_sample_0058ccbf` (`0058ccbf..0058ccef` `49B` + `0058c1f0..0058ccbe` `2,767B` 58-routine shift-and-add lerp block via `256B` `005e1e60[0..63]` table; `2,816B` total, `0` new unresolved symbols) in `sprite_sample_823.{cpp,hpp}`, closing the final `Run817` boundary.
Native diff `local/experiments/v2-render-sprite-sample-823/001/receipt.json` **PASS** (`258` cases/variant `/Od` & `/O2` covering all 64 `(v_sub, u_sub)` slots, `6/6` mutations killed); REA `local/experiments/v2-render-input-823-rea/001/receipt.json` + `validation.json` **PASS** (`1` dossier) + `original-index-supplement.json`.
