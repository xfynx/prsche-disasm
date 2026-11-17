# Run631 render window callbacks (`005756d0`, `005756e0`, `00575730`, `00575770`, `005757d0`)

Bounded native x86-vs-C++ recovery packet for the 5 unindexed `render_window_callbacks_005e1960` callbacks from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `render_window_callback_005756d0` (`005756d0..005756da`, 11B, `__cdecl`, sha256 `3f08780f124dbb553fa004fc946d0368c7d1d11152b7aac7ea272f70ffeca0c2`)
- `render_window_callback_005756e0` (`005756e0..00575726`, 71B, `__stdcall`, sha256 `f06045d33aaf8c6f3c671b657bf6cc6c0106e60ae2dc65a593e23b9f3663c5c1`)
- `render_window_callback_00575730` (`00575730..0057576c`, 61B, `__stdcall`, sha256 `35938a0660a9ce0fe452465f22076ba794138c54f2960d61b1a96023f9e7261a`)
- `render_window_callback_00575770` (`00575770..005757c3`, 84B, `__stdcall`, sha256 `1044c197f77692670e35b440eb5f6d07783e00c1566d145f38621a2b7494eb41`)
- `render_window_callback_005757d0` (`005757d0..005757e6`, 23B, `__stdcall`, sha256 `02a16a5f5019d09026e72e6893a1cdd520ec39503e3b71f8695edf29ffa5376e`)

Owned `.rdata` constant:
- `render_window_ddraw2_iid_005bef50[16]` (`005bef50..005bef5f`, 16B `.rdata`, sha256 `eed8d6675a93dbd48b7f456da84b927303c118613a957f9ccd38aa2e2c4c5c1b`, `{b3a6f3e0-2b43-11cf-a2de-00aa00b93356}`).

Canonical include dirs:
- `iterations/v2/001-original-recovery/runs/631-render-window-callbacks`
- `iterations/v2/001-original-recovery/runs/628-render-window-initialize`
- `iterations/v2/001-original-recovery/runs/549-render-diagnostic`
- `iterations/v2/001-original-recovery/runs/345-diagnostic-devices`
- `iterations/v2/001-original-recovery/source/include`

## Verification

- Attempt `001` (`local/experiments/v2-render-window-callbacks-631/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/631-render-window-callbacks/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero `/W4` warnings and printed `render_window_callbacks_original_x86_vs_cpp=PASS cases=18 events=15`.
  - All 8 mutation controls (`wrong-timed-callback-arg`, `wrong-ddraw2-iid-byte`, `wrong-qi-counter-skip`, `wrong-release-clear-omit`, `wrong-lock-opaque-value`, `wrong-diag-channel-case2`, `wrong-diag-channel-default`, `wrong-resize-arg0-guard`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native proof uses a controlled COM vtable mock (`QueryInterface`/`Release`), controlled stubs for `timed_callbacks_005366e0`, `heap_enter_005322b0`, `heap_leave_005322c0`, `render_texture_diagnostic_0055ec50`, `diagnostic_handler_005debf0`, and `window_resize_notification_pointer_005df9b8`, and test storage for shared globals. Live DirectDraw2/THRASH objects, concurrent lock/thread behavior, `005e1960` slot `[3]` (`window_handler_find_0053a780`), and production CMake/registry integration remain open.
