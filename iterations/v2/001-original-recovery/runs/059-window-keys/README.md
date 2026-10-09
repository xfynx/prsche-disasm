# Run059 — registered keyboard callbacks and accelerator

Source is the immutable `local/game/Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The binary-index caller chain places the window initialization consumer at `0053ac20`; its table registers WM_ACTIVATE (`0053b050`) and WM_KEYDOWN/WM_SYSKEYDOWN (`0053b450`). The thread worker also calls `0053b530` before translating queued messages. `0053b050` installs the `WH_KEYBOARD` callback at `0053b150`, which reads running/filter/hook state and an optional cdecl game callback from the original globals.

The recovered entry ranges and x86 ABI are `0053b050..0053b14c` (six stdcall arguments, `RET 18`), `0053b150..0053b226` (three stdcall arguments, `RET C`), `0053b450..0053b52c` (six stdcall arguments, `RET 18`), and `0053b530..0053b5f1` (two cdecl arguments, plain `RET`). The accelerator's 91 class bytes at `0053b654` and 24-entry jump table at `0053b5f4` are transcribed from the binary; all keys in the byte table's `0x21..0x7b` range are compared, including default-class entries.

Win32 calls (`DefWindowProcA`, `SetWindowsHookExA`, `UnhookWindowsHookEx`, `ShowCursor`, `GetAsyncKeyState`, `CallNextHookEx`), optional hotkey dispatch at `0069e590`, keyboard scan-code translation through the existing `0069e5a0` owner, and queue insertion at `0053a9e0` remain explicit typed boundaries. The implementation reuses existing window state and key-state storage, with no duplicate production globals.

The isolated MSVC Win32 probe was compared against execution of the original x86 functions. All 563 cases passed: exhaustive in-range accelerator entries for both registered key messages plus range/message gates; key repeat clamping, map/no-map, worker-accelerator and shortcut enqueue paths; activation validation, active/minimized transitions, hook install/remove outcomes and output `LRESULT`; and keyboard-hook gates, Ctrl/context branches, recognized keys, optional dispatch, and next-hook behavior. The fixture covers bounded valid startup capacities, not corrupted negative capacities that would cause original counter-wrap loops.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/059-window-keys -B local/builds/v2/run059-window-keys -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/run059-window-keys --config Release --target window_keys_probe
py -3 scripts/research/verify-v2-window-keys.py
```
