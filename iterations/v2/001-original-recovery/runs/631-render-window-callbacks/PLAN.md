# Run631 render window callbacks (`005756d0`, `005756e0`, `00575730`, `00575770`, `005757d0`)

## Goal and criteria
- Recover the 5 unindexed `render_window_callbacks_005e1960` callbacks from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
  - `render_window_callback_005756d0` (`005756d0..005756da`, 11B, `__cdecl`)
  - `render_window_callback_005756e0` (`005756e0..00575726`, 71B, `__stdcall`)
  - `render_window_callback_00575730` (`00575730..0057576c`, 61B, `__stdcall`)
  - `render_window_callback_00575770` (`00575770..005757c3`, 84B, `__stdcall`)
  - `render_window_callback_005757d0` (`005757d0..005757e6`, 23B, `__stdcall`)
- Own 16B `.rdata` IID `render_window_ddraw2_iid_005bef50` (`005bef50..005bef5f`), matching `IID_IDirectDraw2` (`{b3a6f3e0-2b43-11cf-a2de-00aa00b93356}`).
- Record raw PE/Capstone CFG evidence in `original-index-supplement.json` and `scope-evidence.json`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 8 material mutation controls.

## Verified facts
- Direct PE disassembly confirms all 5 functions are `LAB_*` entries absent from `functions.jsonl`, and confirms exact body spans before alignment `0x90` bytes plus all 19 relocations.
- `005bef50` has no prior owner in `iterations/v2/001-original-recovery/`.
- `005756e0` accesses `&window_configuration_storage_006b77a0` at offset `+0x000` (`006b77a0`) and offset `+0x470` (`006b7c10`) via pointer/byte arithmetic without modifying `porsche/window_state.hpp`.
- `00575730` calls `heap_enter_005322b0` / `heap_leave_005322c0` (`porsche/heap.hpp`) with `thread_start_lock_006a57d8` (`porsche/file_threads.hpp`).
- `00575770` passes `reinterpret_cast<const char*>(arg1)` directly to `diagnostic_handler_005debf0` (`case 0`), `render_texture_diagnostic_0055ec50(2u, ...)` (`case 2`), or `render_texture_diagnostic_0055ec50(6u, ...)` (`case 1` / `default`).
- Attempt `001` (`local/experiments/v2-render-window-callbacks-631/001/receipt.json`) passed 18 cases (15 events) at `/Od` and `/O2` with zero `/W4` warnings and detected all 8 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Production CMake/registry integration and recovery of remaining `005e1960` slot `[3]` (`window_handler_find_0053a780`) remain open.
- PARTIAL boundary: bounded native proof uses a controlled COM vtable mock and test stubs/storage for external callees and shared globals; live DirectDraw2/THRASH objects and thread contention remain unverified.
