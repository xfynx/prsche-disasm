# Run593 render display prevideo

## Goal and criteria
- Recover original `0044e2c0..0044e364` (165 bytes, sha256
  `31b476817095733dd64d11fbd5ff1de498b1439cccac96ecc4652fc87aac047e`) as
  `porsche::render_display_prevideo_0044e2c0` (`__cdecl`), reusing canonical headers
  `porsche/render_mode.hpp` and `porsche/render_activate.hpp` without redefining external symbols
  in production `.cpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 neutral mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-0044e2c0.json`,
  evidence `ev_a96a49c5f378b880560b6442c526f034a81ca707103e85a52ff66ecab2b86cb0`) and PE bytes
  confirm branch on `display[0x60] == 0`, `vslot9` call (`driver+0x24`), 40-byte copy from
  `modes+0x28`, `0x0f -> 0x10` format normalization, `0x0061979a` (`state[0x0a] = 1`),
  `0044e890`/`0044ed10` calls, live width/height reload, and `00537600(0,0,0,w,h,0)` call.
- `render_display_496.hpp` collides with `porsche/render_display.hpp` (included by
  `porsche/render_mode.hpp`) on `struct DisplayModeRecord` (`C2011`, preserved in attempt `001`);
  reusing `porsche/render_mode.hpp` + `porsche/render_activate.hpp` provides the identical
  `void __cdecl render_display_prevideo_0044e2c0()` ABI declaration for Run496 linker closure.
- Attempt `002` (`local/experiments/v2-render-display-prevideo-593/002/receipt.json`) passed
  640 cases (2,080 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration with
  Run496; unrecovered callees (`0044e890`, `00537600`) remain open.
