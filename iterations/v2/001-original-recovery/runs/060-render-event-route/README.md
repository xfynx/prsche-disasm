# Run060 — cursor/event route shared by mouse and renderer calls

Original binary: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index query used `research/binary-index/README.md` and `rg '005728b0|0053a970|005367b0|005322b0|005322c0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d`. The direct body/call sequence is in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`; pseudocode cross-check is in `decompiled.c`.

`0x5728b0` is the four-word cdecl event route. When gate `0x5deaac` and shared class lock `0x69e59c` are nonzero, it signed-clamps the first two words against the canonical driver bounds at `0x6a643c/30` and `0x6a6438/34`, enters/leaves the shared lock through recovered `0x5322b0/0x5322c0`, stores the mode/button flags at `0x6a6440`, moves the cursor only when clamping changes a coordinate, and updates last cursor coordinates at `0x6a6448/44`. A nonzero down word invokes the callback pointer at `0x5debec` after unlocking. The original PE initializes that pointer to `0x5367b0`, whose recovered body returns zero; a different runtime target remains an explicit typed callback bridge.

Both existing entry paths now converge on the same implementation: `window_message_mouse_event_005728b0(x,y,flags,down)` is the thin adapter used by button handlers, and Run056's `render_driver_apply_005728b0` is the thin renderer adapter. The down callsite at `0x53b756` pushes `(x,y,flags,1)`; the up callsite at `0x53b7b6` pushes `(x,y,flags,0)`. Both extract x/y as unsigned 16-bit halves (`AND 0xffff`, logical `SHR 16`); the consumer then interprets the resulting 32-bit words with signed comparisons. Run056's `0x537600 -> 0x5726f0 -> 0x5728b0` call instead passes remembered coordinates, prior flags, and zero.

The small direct helper `0x53a970` is also recovered through typed USER32 edges. It calls ClientToScreen with the HWND at configuration `0x6b77a0 + 0x458`; success uses the translated point for SetCursorPos, failure uses the original point, and both paths call SetCursor(NULL). The default callback `0x5367b0` is reproduced as a no-side-effect zero return. Nine isolated Win32 fixtures differentially execute original x86 and native C++ across disabled gates, missing locks, in-bounds and clamped positions, both ClientToScreen outcomes, callback/no-callback, and the renderer bridge. Stack cleanup is checked for the cdecl entry. This proves the consumer and known helper through platform/callback boundaries; it does not verify a live game window or undocumented replacement callback targets.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/060-render-event-route -B local/builds/v2/render-event-route-060 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/render-event-route-060 --config Release --target render_event_route_probe
py -3 scripts/research/verify-v2-render-event-route.py
```
