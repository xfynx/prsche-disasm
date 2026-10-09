# Run065 — callback relocation, registration, and WndProc dispatch

This fixture connects the original 27-row registration sequence from `0053ac20` to the Run064 VA-to-native resolver, actual recovered `window_handler_register_0053a800` and `window_procedure_0053aba0`, and all production callback implementations in `window_handlers.cpp`, `window_messages.cpp`, and `window_keys.cpp`. The native probe links those production modules directly; callback bodies are not replaced by stubs. Registrations receive resolved native function pointers, while the original x86 oracle registers the original callback VAs and dispatches into the binary's real callback bodies.

The differential runs registration, sort, pump, and dispatch boundaries for all 27 table entries, then exercises WM_ACTIVATE, WM_SIZE, WM_KEYDOWN, WM_LBUTTONDOWN, WM_PAINT, and WM_CLOSE through both WndProc implementations. It compares sorted message/callback tables, ordered Win32/game-service events, WndProc returns, and relevant state including position, activation/hook fields, running state, and all 256 key-state bytes. All registration and six dispatch comparisons pass.

Win32 services and engine calls remain typed recorded boundaries: DefWindowProc, SetWindowsHookEx, PostQuitMessage, GetClientRect, ClientToScreen, BeginPaint/EndPaint, input queue insertion, mouse event dispatch, game pump/dispatch, and the resize-notification function pointer. The qsort boundary uses an explicitly bounded sort replacement for the original table's valid unique startup message IDs. The test is a deterministic x86 differential fixture, not a live window or game-launch claim.

The shared production initializer remains outside this run's ownership. Run064 supplies its explicit resolver; unknown callback VAs still fail before registration.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/065-window-callback-integration -B local/builds/v2/run065-window-callback-integration -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/run065-window-callback-integration --config Release --target window_callback_integration_probe
py -3 scripts/research/verify-v2-window-callback-integration.py
```
