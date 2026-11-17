# Run602 render input route

## Goal and criteria
- Recover original `00586cd0..00586d0e` (63 bytes) as `porsche::render_input_dispatch_00586cd0`
  (`__cdecl`), owning loader-zero `.data` arrays `render_input_handlers_006ad440[65]`,
  `render_input_low_map_006ad544[256]`, and `render_input_high_map_006ad644[256]`
  (`0x006ad440..0x006ad743`).
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 neutral material mutation controls.

## Verified facts
- Binary index (`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl` and
  `references.jsonl`) and PE bytes confirm `00586cd0..00586d0e` (63 bytes, sha256
  `4652d9a2bcf3728612a4d51f475b8136e751fc40648f5102352dfdbc9517db52`), called by `00560060`
  (`0056006b`), routes signed `event < 0x100` via `0x006ad544[event]` and `0x100 <= event < 0x10000`
  via `0x006ad644[event >> 8]`, returns `event` when `>= 0x10000` or slot `== 0`, and otherwise
  invokes non-null `0x006ad440[slot]` and returns `0`.
- `0x006ad440..0x006ad743` lie in `.data` virtual tail (loader-zero in `Porsche.exe`).
- Attempt `001` (`local/experiments/v2-render-input-route-602/001/receipt.json`) passed 335 cases
  (158 handler events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `00586cd0` and the 3 owned `.data` arrays.
- Negative signed events (`< 0`) out-of-bounds table indices, slot values `>= 65`, external
  writers, malformed pointers/faults, arbitrary aliases, and production integration remain open.
