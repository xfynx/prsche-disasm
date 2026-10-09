# Run049 — display-mode request consumer

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index query: `rg '00467fc0|00468030|004b6cb9|005376c0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d. The index records `0x467fc0` as `0x467fc0..0x46802f`, with direct calls to `0x5376c0` and `0x468030`; caller references identify main `0x4b6cb9`. The instruction evidence is in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

At `0x4b6cb9`, main passes canonical globals `0x657a48` (width), `0x657a4c` (height), `0x657a50` (mode), then transition value `2`; `ECX` is `0x628130` (the display instance). In `0x467fc0`, requested width/height/mode are compared in order against actual globals `0x619784/0x619788/0x61978c`. An equal triple returns without side effects. Otherwise width zero replaces both width and height with actual values. Display byte `+0x60` selects the fullscreen path: that path supplies result zero to `0x468030`; the other pushes transition then literal `1` and calls `0x5376c0`, so its argument tuple is `(width,height,mode,transition,1)`. The result is forwarded to `0x468030`.

`render_display_reconfigure_00467fc0` reproduces this complete control flow through the original `RET 0x10`. The differential fixture runs the original x86 entry with typed hooks for `0x5376c0` and `0x468030`; for the latter, the hook applies only the directly observed first instruction effect, storing the result at `display+0x68`. The remainder of `0x468030` (window positioning, helper calls, and cursor handling) is outside coverage. The existing startup and display packages are dependencies/evidence only and are not modified here.

The verifier compares nine cases across unchanged mode, width/height/mode changes, zero-width fallback, fullscreen/windowed branches, return values, and the x86 stack delta. It does not claim renderer/device success or full main initialization.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/049-render-activate -B local/builds/v2/render-activate-049 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-activate-049 --config Release --target render_activate_probe
py -3 scripts/research/verify-v2-render-activate.py
```
