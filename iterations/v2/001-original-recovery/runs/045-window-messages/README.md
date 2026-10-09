# Run045 — original window message callbacks

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The binary index was queried for `GetClientRect`, `ClientToScreen`, `BeginPaint`, and `EndPaint`; the corresponding import references lead into the callback bodies below. The native bodies were checked against the original image in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

Recovered full stdcall callbacks, each with six arguments and `RET 0x18`:

| VA | Behavior established from instructions |
|---|---|
| `0x53b360` | On non-null configuration, matching shared HWND, and windowed mode, obtains the configured HWND client RECT, maps it to screen coordinates, writes left/top to configuration `+0x468/+0x46c`, and conditionally calls function pointer `0x5df9b8`. The pointer target `0x5654d0` increments `0x6a5c2c`. |
| `0x53b3d0` | On non-null configuration and matching HWND, clamps the low 16 bits of `lParam` to queue capacity `0x69e560`; for each item calls `0x53a9e0(wParam, (lParam>>16)&0x7f, (lParam>>24)&1)`. Queue internals remain a typed boundary. Returns 1. |
| `0x53b6b0` | On non-null configuration and matching HWND, translates scan code `(lParam>>16)&0x7f` through table pointer `0x69e5a0`; clears one key-state byte at `0x5de028+key`, or clears bytes `+0x5e/+0x52` for translated `0x2a/0x36`. Returns 0. |
| `0x53b710`, `0x53b770` | Translate the three observed mouse-button bits from `wParam` to flags 1/2/4, extract signed 16-bit x/y from `lParam`, and call `0x5728b0(x,y,flags,down)` with down=1/0. Other button bits are ignored. Returns 0. |
| `0x53b7d0` | For matching non-null HWND/configuration, optionally calls SetForegroundWindow in fullscreen, executes game-pump / BeginPaint / EndPaint / dispatch sequence using lock value `0x6a57d8`, conditionally calls `0x5df9b8` in windowed mode, writes 1 to the result pointer, and returns 1. Other paths return 1 without side effects. |

The x86 verifier runs 773 cases against the original executable bytes. USER32 calls are controlled boundaries; `0x53a9e0`, `0x5728b0`, and `0x5322b0/0x5322c0` are typed queue, mouse-routing, and game-pump boundaries. The key translation table bytes are taken from the original `.data` at `0x5df934`; its dereference at `0x69e5a0` is represented by a typed translation boundary in C++. This run does not claim recovery of activation `0x53b050`, key-down `0x53b450`, the WndProc callback relocation table, resize helpers `0x53bcb0/0x53bd40/0x53bec0`, or real Win32 event behavior.

Build and compare:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/045-window-messages -B local/builds/v2/window-messages-045 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-messages-045 --config Release --target window_messages_probe
py -3 scripts/research/verify-v2-window-messages.py
```
