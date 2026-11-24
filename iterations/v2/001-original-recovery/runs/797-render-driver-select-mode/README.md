# Run 797 — Render Driver Mode Selection & State Setters

- Recovers `render_driver_select_mode_00538b30` (334B) + `00537830` (21B), `00537890` (39B), `005378c0` (21B), `005378e0` (21B), `00537900` (21B), `00537920` (23B), `00537940` (23B), `00537960` (23B), `00537980` (21B), `005379a0` (36B), and `005404a0` (51B; 634B total) plus `.data` `005ded4c` (4B) and `005dedf4` (4B).
- Closes `Run515` typed boundary `render_driver_select_mode_00538b30` using `515`/`518`/`521`/`523`/`581`/`render_display`/`render_loader`/`render_settings`/`window_shutdown`/`cursor_snapshot`/`render_descriptor` (`0` new unresolved symbols).
- Native differential check: `local/experiments/v2-render-driver-select-mode-797/002/receipt.json` PASS (`125` cases/variant `/Od` & `/O2`, `10/10` mutations killed); REA audit: `local/experiments/v2-render-input-797-rea/001/receipt.json` PASS (`11` dossiers).
