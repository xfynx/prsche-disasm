# Run048 — window cleanup, resize and centering

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index navigation ties `0053bcb0` and `0053bec0` to startup (`0053ac20`), `0053bd40` to both `0053bec0` and the fullscreen configuration caller `00468030`. Exact instruction evidence is in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`window_position_cleanup_0053bcb0` reproduces `0053bcb0..0053bd3f`: restore saved SPI settings `0x11`/`0x56`, request game-window removal, pump the two game helpers until the shared HWND clears, then decrement class refcount and unregister only at zero.

`window_position_resize_0053bd40` reproduces `0053bd40..0053bebd` with cdecl `(x,y,width,height)` arguments and no callee stack cleanup. The stack-local RECT provenance is verified against the original x86 execution: for entry ESP `S`, `SUB ESP,0x20` and three saved-register pushes establish `F=S-0x2c`; `PUSH -0x14` and `PUSH hwnd` place ESP at `F-8`; stores at `0053bd81..bd95` initialize RECT words at `F+0x0c..0x18`. The first `GetWindowLongA` returns with ESP at `F`; the second returns with ESP at `F-8`; therefore `LEA [ESP+0x14]` at `0053bda8` points to `F+0x0c`, the initialized RECT. The verifier hooks API callee entries with RET cleanup including the hardware return-address pop, then asserts the live `0053bda8` ESP and `AdjustWindowRectEx` pointer and leading RECT values.

The recovered body obtains missing client dimensions with `GetClientRect`, builds and adjusts the window RECT from `GetWindowLongA` styles, selects override coordinates, explicit coordinates, or the SPI work area, then calls `SetWindowPos`. It converts the resulting client rectangle with two `ClientToScreen` calls and updates the shared position, width and height fields. `window_position_center_0053bec0` reproduces the original `CDQ; SUB; SAR` signed centering arithmetic and calls the resize helper. Win32 APIs and game helpers `0053a8e0`, `0055f740`, and `005366e0` remain typed boundaries.

The verifier passes 66 original-x86 differential cases spanning cleanup, centering, explicit and override positioning, absent dimensions, negative coordinates, and stack provenance. These are bounded API-fixture checks, not a real window launch claim.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/048-window-position -B local/builds/v2/window-position-048 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-position-048 --config Release --target window_position_probe
py -3 scripts/research/verify-v2-window-position.py
```
