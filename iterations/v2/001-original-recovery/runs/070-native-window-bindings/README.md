# Run070 — native Win32 window bindings

This package adds direct x86 platform implementations for the already declared window APIs in `window_runtime.hpp`, `window_create.hpp`, `window_worker.hpp`, `window_handlers.hpp`, `window_messages.hpp`, `window_keys.hpp`, `window_position.hpp`, `window_procedure.hpp`, and `render_event_route.hpp`. Repeated adapters share a small set of internal USER32 calls for client rectangles, client-to-screen conversion, cursor visibility, cursor selection, foreground activation, rectangle adjustment, and system parameters. The adapter bodies contain no game logic and no placeholder returns.

Bindings call USER32 for window creation/class registration, message dispatch, keyboard hooks, cursor, paint, positioning, and class cleanup; GDI for `GetStockObject`; and KERNEL32 for module handle and last-error lookup. `GetMessageA` preserves its signed `-1/0/positive` result. The compile fixture checks x86 layouts and representative function-pointer ABIs, references all exported wrappers, and links the static library against `user32`, `gdi32`, and `kernel32`. It does not create a window or invoke GUI APIs; the native GUI run belongs to the integration owner.

Adapter ABI differences retained from existing declarations:

- `window_set_foreground` and `window_worker_set_foreground_window` declare `void*`, while USER32 `SetForegroundWindow` returns `BOOL`. The wrapper places the returned 32-bit 0/1 value in EAX through the declared pointer-sized return; consumers treat it as the original integer result.
- `window_message_begin_paint` declares `uint32_t`, while `BeginPaint` returns an HDC. The wrapper returns the x86 handle bits as `uint32_t`.
- `window_register_class` returns `uint16_t`, matching `RegisterClassA`'s ATOM result. `window_worker_dispatch_message`, `window_keys_def_window_proc`, `window_keys_call_next_hook`, and `window_default_procedure` use signed 32-bit results to preserve x86 `LRESULT` bits.
- `WindowWorkerMessage`, the RECT-shaped structures, POINT, and `OriginalWndClassA` are compile-time checked against their Win32 counterparts on x86.

The following typed declarations remain game or engine boundaries and are intentionally not implemented here: registration/diagnostic and channel helpers; recovered worker waits, pump/dispatch and callbacks; the accelerator and activation/focus helpers; queue insertion/translation and resize notification; mouse routing; handler sorting; position remove/idle/timed calls; and dynamic renderer callbacks. They are not Win32 API aliases, so this package does not replace them with no-ops.

Build the x86 static library and compile fixture:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/070-native-window-bindings -B local/builds/v2/native-window-bindings-070 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/native-window-bindings-070 --config Release --target win32_window_bindings_compile_fixture
```
