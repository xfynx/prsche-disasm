# Run051 — display result consumer and window effects

Original: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '00468030|0044e720|0044ebf0|0044ed10|00537600|0053bd40' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`. The index places `0x468030` at `0x468030..0x4680c5`, called from the display constructor and mode setter; its body and caller ABI are in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`0x468030` is a thiscall consumer (`ECX=display`, one stack result, `RET 4`). It first stores the result to display `+0x68`; if it equals the canonical applied mode index `0x619780`, it returns. Otherwise, fullscreen byte `display+0x60` calls shared `window_position_resize_0053bd40(0,0,0,0)` and uses video dimensions `640x480`. The windowed branch asks `0x44e720` for the selected ten-word mode record, takes words 0 and 1 as the video-base dimensions, and calls driver vtable slot `+0x1c` with the selected index; the virtual member consumes its stack word. Both branches then call `0x44ebf0(result)`, `0x44ed10()`, and `0x537600(0,0,0,width,height,0)`. Finally they call USER32 `ShowCursor(FALSE)` until its return value becomes negative.

The native implementation is complete through `RET 4`. It consumes `window_position_resize_0053bd40` from Run048; it does not copy that window helper. Run051's isolated fixture hooks that adapter to assert the exact four arguments. Other direct game helpers, the driver virtual call, `0x537600`, and USER32 `ShowCursor` remain typed call boundaries, with mode-record input and cursor return sequences injected by the fixture. Their internal implementations or side effects are outside this consumer proof.

The verifier compares seven original-x86/native cases covering the no-change return, both fullscreen/windowed branches, mode-record dimension flow, ordered helper calls, and repeated cursor calls. It also checks the original stack delta at `RET 4`. Run049 owns the canonical `0x619780` mode-index alias; `0x619784/88/8c` are already canonical in render-display source, and `0x628130` is owned by render startup.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/051-render-window -B local/builds/v2/render-window-051 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-window-051 --config Release --target render_window_probe
py -3 scripts/research/verify-v2-render-window.py
```
