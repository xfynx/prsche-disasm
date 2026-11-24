# Run 802 — Render Driver Query & Pixel ARGB8888 Decoder

- Recovers `render_driver_probe_00556d20` (870B) and `render_pixel_to_argb8888_00557240` (267B; 1137B total) plus `.rdata` `005cf80c` (5B `"PBUF"`) and `005cf814` (8B `"UV Test"`).
- Closes `Run515` typed boundary `render_driver_probe_00556d20` over `porsche/render_display.hpp` (`0` new unresolved symbols).
- Native differential check: `local/experiments/v2-render-driver-query-802/002/receipt.json` PASS (`133` cases/variant `/Od` & `/O2`, `10/10` mutations killed); REA audit: `local/experiments/v2-render-input-802-rea/001/receipt.json` PASS (`1` dossier).
