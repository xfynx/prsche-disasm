# Run089 — original mouse input consumer

Original binary: immutable `local/game/Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The index entry point was `research/binary-index/README.md`; the query covered
`005728b0`, callers `0053b710/0053b770`, caller `0057272c`, their callees, and
the referenced globals. The body and callsites are in the SHA-pinned
`research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.

`005728b0` is a four-DWORD cdecl consumer with exact stack order
`(x, y, button_mask, transition)`. The mouse-button callers push x, y, the
derived three-button mask, and 1 for down or 0 for up. The body reads x/y and
the mask, then tests the fourth transition word as the callback gate. With gate `005deaac`
and class lock `0069e59c` both nonzero, it signed-clamps x/y using the bounds
at `006a643c/30` and `006a6438/34`, enters the class lock, stores the mask at
`006a6440`, invokes `0053a970(config=006b77a0,x,y)` only when clamping changed
a coordinate, updates cached coordinates `006a6448/44` only when changed, and
leaves the lock. After unlocking, it calls the current callback pointer at
`005debec` with the mask only when the fourth transition argument is nonzero.

The x86 caller stack confirms the fourth word is the callback gate, while the
third word is passed through as callback data. The cursor helper and
lock APIs remain explicit typed boundaries; `005367b0` is the original
zero-return no-op callback. Other dynamic callback targets are not guessed.
The native C++ probe compares event order, arguments, state, and cdecl stack
balance against the original x86 body. It tests guards, signed/equal/inverted
bounds, clamping, unchanged coordinates, callback targets, and both values
of the transition word. This is a consumer differential proof; it does
not claim that the common WndProc wiring has been migrated or that the game
has been launched.

`render_event_route.cpp` already has the same observed gate/pass-through
behavior; its symbol overlaps a renderer adapter, so this packet gives the
binary body a dedicated owner and an independent x86 differential. During
integration, remove the duplicate algorithm body `render_event_route_005728b0`
or make it a thin forwarder to `mouse_input_consumer_005728b0`. Preserve
`window_message_mouse_event_005728b0` as the adapter called by
`window_messages.cpp`, and preserve `render_driver_apply_005728b0` as the
renderer adapter; redirect both to this consumer. Keep the existing canonical
owners for bounds/cache globals in `render_driver_calls.cpp`, gate/callback
globals in `render_event_route.cpp`, class lock and window config in
`window_create.cpp`, and lock/helper/callback boundaries. This packet defines
no duplicate original-address globals.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/089-mouse-input -B local/builds/v2/mouse-input-089 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/mouse-input-089 --config Release --target mouse_input_probe
py -3 scripts/research/verify-v2-mouse-input.py
```
