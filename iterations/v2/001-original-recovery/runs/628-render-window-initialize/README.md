# Run628 render window initialize (`005757f0`, `00575810`, `00575820`)

Bounded native x86-vs-C++ recovery packet for three Porsche.exe (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) functions:
- `render_window_abort_cleanup_005757f0` (`005757f0..00575809`, 26B, sha256 `b203a001842b1c1815979614230876eda37e674213928f3d20fa0f84aa3a2f86`)
- `render_window_exit_cleanup_00575810` (`00575810..00575818`, 9B, sha256 `6b8ae2b332a7ff0893cd61b88ee0b620d42a233d732ede333d07027ff0a867ad`)
- `render_initialize_window_00575820` (`00575820..0057592d`, 270B, sha256 `a1c198173ba759040c35a248016f8b370c26dc62cbc27a82b1b09e14842c943a`)

Owned `.data` globals:
- `render_window_callbacks_005e1960[8]` (`005e1960`, 32B `.data`, sha256 `8d2949ce5fe961541d7d1287c3c38a5eb75c6214bca2c735a14274a100be28e8`):
  - `[0]` `0x005756d0` -> `render_window_callback_005756d0` (unrecovered, declared for address transport only)
  - `[1]` `0x00557460` -> `startup_window_handle_00557460` (reused from `porsche/startup_input.hpp`)
  - `[2]` `0x0053a800` -> `window_handler_register_0053a800` (reused from `porsche/window_create.hpp`)
  - `[3]` `0x0053a780` -> `window_handler_find_0053a780` (unrecovered, declared for address transport only)
  - `[4]` `0x005756e0` -> `render_window_callback_005756e0` (unrecovered, declared for address transport only)
  - `[5]` `0x00575730` -> `render_window_callback_00575730` (unrecovered, declared for address transport only)
  - `[6]` `0x00575770` -> `render_window_callback_00575770` (unrecovered, declared for address transport only)
  - `[7]` `0x005757d0` -> `render_window_callback_005757d0` (unrecovered, declared for address transport only)
- `render_window_exit_registered_006a64bc` (`006a64bc`, 4B loader-zero `.data`).

Canonical header reuse:
- `porsche/file_threads.hpp`, `porsche/heap.hpp`, `porsche/render_display.hpp` (canonical `extern` for `render_display_texture_width_005deac8` / `height_005deacc` owned by `496-render-present-caller-repair/render_display_496.cpp`, avoiding `DisplayModeRecord` collision with `render_display_496.hpp`), `porsche/render_loader.hpp`, `porsche/startup_input.hpp`, `porsche/window_create.hpp`, `porsche/window_scheduler.hpp`, `../528-render-library-lifecycle/render_library_lifecycle_528.hpp`, `../626-diagnostic-abort-handler/diagnostic_abort_handler_626.hpp`.

## Verification

- Attempt `001` (`local/experiments/v2-render-window-initialize-628/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/628-render-window-initialize/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and printed `render_window_initialize_original_x86_vs_cpp=PASS cases=11 events=66`.
  - All 8 mutation controls (`wrong-default-width`, `wrong-default-height`, `wrong-prepare-guard`, `wrong-fullscreen-flag`, `wrong-scheduler-guard`, `wrong-exit-flag`, `omit-abort-cleanup-clear`, `wrong-exit-cleanup-arg`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded test domain uses controlled THRASH export slots `[19]`/`[27]` and test-only stubs/storage for external callees and shared globals. Real THRASH DLL `init`/`setstate` behavior, the 6 unrecovered callback bodies in `render_window_callbacks_005e1960`, concurrent thread initialization, and production CMake/registry integration remain open.
