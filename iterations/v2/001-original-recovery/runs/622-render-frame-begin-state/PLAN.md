# Run622 render frame begin state

## Goal and criteria
- Recover original `00534540` (12B, owning 44B `.data` `005de680..005de6ab`, exporting both `game_setup_draw_begin_00534540` and `splash_progress_driver_frame_begin_00534540`) and `00535a90` (`render_resource_texture_state_00535a90`, 104B, 0B new data) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `porsche/game_setup.hpp`, `porsche/splash_progress.hpp`, `porsche/window_shutdown.hpp`, `porsche/render_settings.hpp`, `render_descriptor.hpp`, `render_state_flush_527.hpp`, and `render_resource_533.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with material mutation controls.

## Verified facts
- `Porsche.exe` PE bytes and binary index (`functions.jsonl`, `references.jsonl`) confirm `00534540` (`00534540..0053454b`, 12B, `push 0x005de680; call 0x00534480; pop ecx; ret`), `005de680` (`005de680..005de6ab`, 44B, 11 DWORDs `{0,0,0,0,2,0,0,0x280,0x1e0,0,0}` followed at `+0x2c` by `window_shutdown_state_005de6ac`), and `00535a90` (`00535a90..00535af7`, 104B, previously archived in Run527 `original-evidence.json`).
- `00534540` stages `render_frame_begin_descriptor_005de680[0..10]` and `window_shutdown_state_005de6ac` into a 12-DWORD local buffer, calls `render_descriptor_bind_00534480(staging)`, writes `[0..10]` back, and propagates `[11]` back to `window_shutdown_state_005de6ac` only when modified.
- `00535a90` forwards `(key, value)` directly to `render_settings_set_state_006bd97c` when `render_resource_texture_fallback_0069dd1c == 0`; otherwise computes `stage = sar(key, 16)` and `remapped_key = (key & 0xf0000u) | 0x0du`, clamping `value` to `1u` when `render_state_flush_records_005de6bc[stage * 14 + 11] == 1` or `render_state_flush_records_005de6bc[stage * 14 + 13] == 1`.

- Attempt `001` (`local/experiments/v2-render-frame-begin-state-622/001/receipt.json`) passed 1800 cases (1800 events) at `/Od` and `/O2` and detected all 5 mutation controls (`wrong-tail-sync`, `wrong-fallback-bypass`, `wrong-key-mask`, `wrong-stage-stride`, `wrong-record-offset`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00534540` and `00535a90`.
- `00535a90` stays `PARTIAL` outside `stage` in `0..1`; negative/out-of-bounds stage values and production CMake/registry integration remain open.
