# Run 789 — Render Font Glyph Palette Conversion (`00594980..00594ca0`)

Closes `Run787`'s remaining function boundary `render_font_convert_glyphs_00594980` (`00594980`, `91B`) plus its 4 internal palette helpers (`005949e0` `70B`, `00594a30` `285B`, `00594b50` `220B`, `00594c30` `113B`; `779B` code total, `0B` data/bss, `0` unresolved symbols).
- REA: `local/experiments/v2-render-input-789-rea/001/receipt.json` + `validation.json` (`passed: true`, 5 dossiers).
- Native: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/789-render-font-convert-glyphs/native-config.json --attempt 002` -> `local/experiments/v2-render-font-convert-glyphs-789/002/receipt.json` `PASS` (`40` cases/variant `/Od` and `/O2`, `11/11` mutations killed).
- Bounds: exact over nonzero divisor (`w0 + w1 > 0`, matching all callers).
