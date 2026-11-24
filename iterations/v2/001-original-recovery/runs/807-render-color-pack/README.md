# Run807: Render color packing & palette nearest-match

Recovers `render_palette_nearest_00537e30` (`156B`), `render_color_pack_00537ed0` (`95B`), `render_color_888_to_pal8_00572f90` (`77B`), and `render_color_8888_to_4444_00573000` (`47B`; `375B` total, `256B` `.data` `005de790`, `4B` `.bss` `0069e0ac`, `0` unrecovered callees) in `render_color_pack_807.{cpp,hpp}`, preparing `0053cbc0` (`005dec08` / `005dec18`) and `00563160`.
Native diff `local/experiments/v2-render-color-pack-807/004/receipt.json` **PASS** (`131` cases/variant `/Od` & `/O2`, `10/10` mutations killed); REA `local/experiments/v2-render-input-807-rea/001/receipt.json` + `validation.json` **PASS** (`4` dossiers).
