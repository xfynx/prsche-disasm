# Run035 — window worker and message pump

Source: immutable `local/game/Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index queries identified USER32 imports `GetMessageA`, `TranslateMessage`, `DispatchMessageA`, `IsIconic`, `GetClientRect`, `SetForegroundWindow`, `SetActiveWindow`, `DestroyWindow`, `ClientToScreen`, `SetCursor`, and `ShowCursor`. The reference `0x53aeea` passes `0x53b8d0` to thread start `0x55f420`; instructions `0x53b8d0..0x53bad8` manually bound the worker body absent from Ghidra's function catalog. The worker calls recovered `0x53bb00` at `0x53b8da`.

`window_worker_0053b8d0` recovers the worker's call ordering, position selection, message processing, idle callback path, HWND teardown, and fullscreen focus branch. Calls to Win32, `0x55fb20/0x55fb90/0x55fc10`, `0x5322b0/0x5322c0`, `0x53b530`, `0x565560`, `0x573980`, and `0x558350` remain typed fixture boundaries. The thread argument is unused in the original; its configuration comes from the shared `window_configuration_address_006b77a0` identity. The worker reads shared fullscreen state `0x6b7c01` after the create and wait calls, and uses the existing window, class-lock, thread-handle, running, and override globals rather than local production copies.

`GetMessageA` is modeled with its original signed `BOOL` result. The worker tests the value for zero, so `-1` is nonzero and enters the message dispatch path; it does not use a `> 0` test. A fixture now exercises `0xffffffff` (signed `-1`) and confirms the same ordered dispatch boundaries as the original x86. `py -3 scripts/research/verify-v2-window-worker.py` ran six native C++ versus original x86 comparisons, including windowed/fullscreen modes with and without position override, dispatch, idle callback, and a wait boundary that changes fullscreen after creation. Return value, HWND and position globals, plus ordered boundary calls matched. `verification.json` records hashes and the comparison result. A failed `CreateWindowExA` case is outside the bounded fixture: with both the local and global HWND equal to zero, the original loop does not reach its exit comparison. A real HWND/message procedure and game launch remain unverified.

Rebuild the isolated probe with:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/035-window-worker -B local/builds/v2/001-original-recovery/run035-window-worker -A Win32
cmake --build local/builds/v2/001-original-recovery/run035-window-worker --config Release --target window_worker_probe
py -3 scripts/research/verify-v2-window-worker.py
```
