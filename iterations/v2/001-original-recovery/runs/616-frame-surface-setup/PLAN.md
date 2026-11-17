# Run616 frame surface setup

## Goal and criteria
- Recover original `00568f30` (`frame_pump_boundary_00568f30`, 324B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `porsche/frame_pump.hpp`, `porsche/render_loader.hpp`, and `../585-frame-interface-release/frame_interface_release_585.hpp`, owning 7 loader-zero `.data` DWORDs (`0x006a5c84..0x006a5c9f`).
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`5e6b1d75fd6acadf6f6d18a792fc14c961c3e15f768f610d53e1c32a8642c40e`), and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-00568f30.json`, `ev_69eaaca2c9220efc2d82b8d9eebd1ceef9101491d6dd502e1c18e144ec52a0ad`) confirm the 324B body, `__cdecl` 6-arg calling convention, 18 `ABS32` relocations, 3 `REL32` calls to `005693e0`, and literal callback VA `0x00569080`.
- `00568f30` calls `005693e0()`, records args/sentinel/state=2 in `0x006a5c84..0x006a5c9f`, returns early if `a5 != 0`, otherwise queries `render_thrash_exports_006bd910[9]` (`about[0x1f] == 7`) and `[27]` (`GetState(0x26, &frame_interface_final_flag_006a5ca0)`), enumerates modes via `vtbl[9]` with `0x11` and `0x00569080`, reloads `dd_ptr`, and if `frame_interface_second_006a5ca4 != 0` creates a 124-byte `YUY2` surface (`ddsd[0]=0x7c`, `ddsd[1]=0x1027`, `ddsd[2]=h`, `ddsd[3]=w`, `ddsd[5]=1`, `ddsd[18]=0x20`, `ddsd[19]=4`, `ddsd[20]=0x32595559`, `ddsd[26]=0x4098`) via `vtbl[6]`, setting state to `1` on success or calling `005693e0()` on failure.
- Attempt `001` (`local/experiments/v2-frame-surface-setup-616/001/receipt.json`) passed at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-surface-state-final`, `wrong-about-magic-seven`, `wrong-ddsd-fourcc`, `wrong-ddsd-caps`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00568f30`.
- Literal `0x00569080` enumeration callback behavior, null `dd_ptr` with nonzero `frame_interface_second_006a5ca4`, and production integration remain open.
