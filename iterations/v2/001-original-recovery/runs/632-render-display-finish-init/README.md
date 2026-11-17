# Run632 render display finish init (`0053a780`, `0053bf20`, `004b0eb0`)

Bounded native x86-vs-C++ recovery packet for three Porsche.exe (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) functions:
- `window_handler_find_0053a780` (`0053a780..0053a7e4`, 101B, `__stdcall(uint32_t)`, sha256 `2a9c038efccffeb385082a7c622c4baeca4ec8c78ea50c40ba520c88c3cfc75f`)
- `window_keyboard_hook_disable_0053bf20` (`0053bf20..0053bf4d`, 46B, `__cdecl()`, sha256 `a99c7bf907b79c01cb46b9128ef44af038be5563b48bf14d66a7db004e0b903b`)
- `render_display_finish_init_004b0eb0` (`004b0eb0..004b0ed6`, 39B, `__cdecl()`, sha256 `883fc5a48d9638bc283a8f2f9aadf0a72ed6e64375ccc18efbc779498f86e5bb`)

Owned `.data`/`.rdata`: 0B new (all touched globals are canonical: `class_lock_0069e59c`, `window_fullscreen_006b7c01`, `window_handlers_0069e0e0`, `window_handler_count_0069e570`, `window_keyboard_hook_handle_0069e584`, `window_keyboard_hook_enabled_0069e588`, and `frame_pump_storage_bytes_006573b8() + 0x24` for `006573dc`).

Canonical header reuse and integration include_dirs:
- `iterations/v2/001-original-recovery/runs/632-render-display-finish-init`, `iterations/v2/001-original-recovery/runs/628-render-window-initialize`, `iterations/v2/001-original-recovery/source/include`.
- Headers reused: `porsche/frame_pump.hpp`, `porsche/heap.hpp`, `porsche/heap_locks.hpp`, `porsche/render_display.hpp`, `porsche/window_create.hpp`, `porsche/window_handlers.hpp`, `porsche/window_keys.hpp`, `porsche/window_procedure.hpp`, `../628-render-window-initialize/render_window_initialize_628.hpp`.
- `render_display_finish_init_632.hpp` avoids including `render_display_496.hpp` or `porsche/render_display.hpp` directly so consumers of either header do not hit a `DisplayModeRecord` redefinition.

## Verification

- Attempt `001` (`local/experiments/v2-render-display-finish-init-632/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/632-render-display-finish-init/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and printed `render_display_finish_init_original_x86_vs_cpp=PASS cases=16 events=41`.
  - All 6 material mutations (`omit-lock-create`, `wrong-find-return-zero`, `wrong-hook-fullscreen-guard`, `omit-hook-enabled-clear`, `wrong-finish-prev-guard`, `wrong-finish-message-id`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded test domain uses fixture stubs/storage for heap lock creation/entry/leave, `original_binary_search_005a2f23` / `window_message_compare_0053a7f0`, `window_keys_unhook_windows_hook` (`UnhookWindowsHookEx` IAT `[0x5b2304]`), `window_handler_register_0053a800`, and shared globals. Unrecovered `WM_ACTIVATEAPP` callback `render_display_activate_callback_004b0ee0` (address-transport declaration only), real Win32 hook teardown, lock contention, and production CMake/registry integration remain open.
