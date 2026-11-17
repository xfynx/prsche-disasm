# Run604 render initialize callbacks

## Goal and criteria
- Recover original `005759f0..00575a1a` (43 bytes) as `porsche::render_initialize_callbacks_005759f0`
  (`__cdecl`), owning loader-zero `.data` DWORD `render_saved_display_hook_006a64c0` (`0x006a64c0`)
  and reusing `render_thrash_exports_006bd910[43]` (`porsche/render_loader.hpp`).
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 neutral material mutation controls.

## Verified facts
- Binary index (`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl` and
  `references.jsonl`) and PE bytes confirm `005759f0..00575a1a` (43 bytes, sha256
  `9d035527fbf1e5fd9be53dccc97879658db1d8f64fd206f18975d251f5b348f2`), called by `00556bb0`
  (`00556c54`), calls `(__stdcall *)(0x27, 0x00575a20)` through `0x006bd97c` (`slot[27]`), then
  reads `0x006a64c0` and if zero swaps `0x006bd9b0` (`slot[40]`) with `0x00575980` while saving
  the previous `slot[40]` value in `0x006a64c0`.
- `0x006a64c0` lies in the `.data` virtual tail (`0x005e7000..0x006c1537`, loader-zero in `Porsche.exe`).
- Attempt `001` (`local/experiments/v2-render-initialize-callbacks-604/001/receipt.json`) passed 34 cases
  (34 callback events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `005759f0` and `render_saved_display_hook_006a64c0`.
- Real THRASH DLL `set_state` behavior, callback literals `0x00575a20` and `0x00575980`, external
  `0x006a64c0` consumers, null/invalid `slot[27]` faults, and production CMake/registry integration
  remain open.
