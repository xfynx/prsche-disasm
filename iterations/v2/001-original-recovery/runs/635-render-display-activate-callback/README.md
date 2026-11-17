# Run 635 render display activate callback (`005360d0`, `004b0ee0`)

Bounded native x86-vs-C++ recovery packet for two Porsche.exe (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) functions:
- `startup_service_active_get_005360d0` (`005360d0..005360d5`, 6B, `__fastcall`/`__thiscall(void* self)` returning `uint8_t`, sha256 `365a3085ba2da542e58e4a06bb523c0027d1ef57cbe9268513bef59b0b270d72`)
- `render_display_activate_callback_004b0ee0` (`004b0ee0..004b0f99`, 186B, `__stdcall(void*, void*, uint32_t, uint32_t, int32_t, int32_t*)` returning `uint32_t` with `RET 0x18`, sha256 `39f05a07399f92bf4a5647dfba824687a43da9516c7d561d0633021c8163caf5`)

Owned `.data`/`.rdata`: 0B new (verified by `dumpbin /SUMMARY` on `o2-0.obj`: no `.data`, `.rdata`, or `.bss` sections; all touched globals are canonical: `startup_service_active_0069dd1e`, `game_setup_movie_service_0069ed0c`, `frame_pump_byte_006573e0`, `frame_pump_byte_006573e1`, `frame_pump_byte_006573e2`, and `frame_pump_storage_bytes_006573b8()` offsets `+0x24` (`006573dc`) and `+0x2b` (`006573e3`)).

Canonical header reuse and integration `include_dirs`:
- `iterations/v2/001-original-recovery/runs/635-render-display-activate-callback`, `iterations/v2/001-original-recovery/runs/632-render-display-finish-init`, `iterations/v2/001-original-recovery/runs/570-startup-service-bindings`, `iterations/v2/001-original-recovery/source/include`.
- Headers reused: `../632-render-display-finish-init/render_display_finish_init_632.hpp`, `../570-startup-service-bindings/startup_service_570.hpp`, `porsche/frame_pump.hpp`, `porsche/game_setup.hpp`, `porsche/render_window.hpp`, `porsche/startup_input.hpp`, `porsche/window_procedure.hpp`.

## Verification

- Attempt `001` (`local/experiments/v2-render-display-activate-callback-635/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/635-render-display-activate-callback/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and printed `render_display_activate_callback_original_x86_vs_cpp=PASS cases=15 events=29`.
  - All 8 material mutations (`wrong-active-getter-value`, `omit-config-null-guard`, `wrong-hwnd-match-guard`, `wrong-show-cursor-loop-bound`, `wrong-inactive-guard-byte`, `omit-movie-service-deactivation`, `omit-result-zero-write`, `omit-previous-handler-forward`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded test domain uses fixture stubs/storage for `startup_window_handle_00557460`, `render_window_show_cursor` (`ShowCursor` IAT `[0x5b2278]`), `frame_pump_boundary_005360a0`, mock previous `WindowHandler`, and shared globals. Live Win32 `WM_ACTIVATEAPP` delivery, real `ShowCursor` cursor display count state, null `result` pointer fault behavior, and production CMake/registry integration remain open.
