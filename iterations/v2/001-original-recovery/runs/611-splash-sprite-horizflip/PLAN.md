# Run611 splash sprite horizontal flip

## Goal and criteria
- Recover original `00563320` (286B), `0056e2a8` (24B), and `005712f0` (49B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Own 3 `.rdata` strings (`005bced8`, `005bcf08`, `005bcf48`, 126B total) and reuse `porsche/splash_progress.hpp`, `porsche/shared_runtime_globals.hpp`, `porsche/files.hpp`, `render_descriptor.hpp`, and `buffer_select.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes, and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-00563320.json`) confirm all 3 bodies, relocations, owned `.rdata` strings, and `__cdecl` calling conventions.
- `0056e2a8` reads 4 bytes at `src + bytes - 4` and right-shifts by `((-bytes) * 8 + 32) & 0x1f`.
- `005712f0` returns `width` directly when `bytes[0] == 0x7b`, else calls `00537f90(shape)`, maps `15` bpp to `16`, and returns `(bpp * width + 7) >> 3`.
- `00563320` emits diagnostics on packed (`head0 & 0x80`) or sub-8bpp (`bpp < 8`) shapes, swaps row pixels inward using `0056e2a8`/`0056e301` across `height` rows stepped by `stride`, and updates `*(int16_t*)(item + 8) = width - x16`.
- Attempt `002` (`local/experiments/v2-splash-sprite-horizflip-611/002/receipt.json`) passed 440 cases (1696 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-read-word-shift`, `wrong-stride-15bpp-check`, `wrong-packed-flag-mask`, `wrong-anchor-x-sign`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00563320`, `0056e2a8`, `005712f0`, and the 126B `.rdata` strings (`005bced8`, `005bcf08`, `005bcf48`).
- Null pointers, non-returning diagnostic handlers, out-of-bounds shape buffers, negative bpp, and production integration remain open.
