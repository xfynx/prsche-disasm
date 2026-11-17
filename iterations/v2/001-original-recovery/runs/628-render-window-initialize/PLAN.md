# Run628 render window initialize

## Goal and criteria
- Recover `005757f0` (26B), `00575810` (9B), and `00575820` (270B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) with canonical signature `render_initialize_window_00575820(std::uint32_t first)`.
- Own 32B `.data` table `render_window_callbacks_005e1960` (`005e1960`) and 4B loader-zero `.data` `render_window_exit_registered_006a64bc` (`006a64bc`), reusing canonical headers without duplicating definitions or fabricating unrecovered callback bodies.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 8 material mutation controls.

## Verified facts
- Direct PE disassembly confirms all instructions and relocations (2 for `005757f0`, 1 for `00575810`, 32 for `00575820`) plus raw 32-byte table `005e1960` (`[0x5756d0, 0x557460, 0x53a800, 0x53a780, 0x5756e0, 0x575730, 0x575770, 0x5757d0]`) and 4-byte loader-zero `006a64bc`.
- Of the 8 `005e1960` entries, `00557460` (`startup_window_handle_00557460`) and `0053a800` (`window_handler_register_0053a800`) are already recovered; the remaining 6 (`005756d0`, `0053a780`, `005756e0`, `00575730`, `00575770`, `005757d0`) are declared with exact original x86 ABIs for address transport only.
- Including `porsche/render_display.hpp` (pulled in by `diagnostic_abort_handler_626.hpp`) provides the canonical `extern` for `render_display_texture_width_005deac8` / `height_005deacc` without colliding with `DisplayModeRecord` in `render_display_496.hpp`.
- Attempt `001` (`local/experiments/v2-render-window-initialize-628/001/receipt.json`) passed 11 cases (66 events) at `/Od` and `/O2` with zero `/W4` warnings and detected all 8 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `005757f0`, `00575810`, `00575820`, `005e1960`, and `006a64bc` (noting the 6 unrecovered callback declarations in `005e1960` will surface as explicit unresolved linker symbols until recovered).
- PARTIAL boundary: real THRASH DLL behavior, the 6 unrecovered callbacks in `005e1960`, concurrency, and production CMake/registry integration remain open.
