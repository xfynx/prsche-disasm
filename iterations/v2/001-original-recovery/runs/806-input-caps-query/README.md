# Run 806 — DirectInput Device Capabilities Continuation

- Recovers `input_caps_success_unrecovered_0056fdf9` (`0056fdf9..0056ff8c`, 404B continuation inside `0056fdb0..0056ff8c` 477B) plus `.data` `input_axis_offsets_005dfa20` (`005dfa20..005dfa3f`, 32B).
- Closes the explicit unrecovered continuation boundary in `source/recovered/Porsche.exe/input_buffer.cpp` (`input_caps_0056fdb0`) with `0` new unresolved symbols.
- Native differential check: `local/experiments/v2-input-caps-query-806/002/receipt.json` PASS (`10` cases/variant `/Od` & `/O2`, `9/9` mutations killed); REA audit: `local/experiments/v2-render-input-806-rea/001/receipt.json` PASS (`1` dossier).
