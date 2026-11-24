# Run 793 — Debug Font Creation & State Setup

- Recovers `render_debug_font_create_0053c6c0` (490B), `font_find_glyph_0053d920` (74B), `font_bsearch_glyph_0053d970` (74B), `font_setstate_0053e5c0` (643B), `font_read_u16_cursor_00573a90` (17B), `font_read_u8_cursor_00573ab0` (14B), `font_ascii_to_sjis_fullwidth_00573ac0` (30B), and `font_read_sjis_cursor_00573ae0` (59B; 1401B total) plus `.rdata` `005bbb20` (34B) and `.data` `005dfcc8` (192B).
- Closes `Run782` typed boundary `render_debug_font_create_0053c6c0` using `render_service_ops_005dec08`, `render_buffer_read_word_0056e2a8`, `font_state_set_pair_0053eea0`, `font_setstatef_0053e890`, and shared diagnostics (`0` new unresolved symbols).
- Native differential check: `local/experiments/v2-render-debug-font-create-793/004/receipt.json` PASS (`125` cases per `/Od` and `/O2`, `12/12` mutations killed); REA audit: `local/experiments/v2-render-input-793-rea/001/receipt.json` PASS (`5` dossiers).
