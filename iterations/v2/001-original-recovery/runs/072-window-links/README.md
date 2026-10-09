# Run072 — recovered window caller links

`source/platform/window_links.cpp` binds the window-facing extern names to already recovered callees. It contains only ABI adapters; algorithm bodies remain in their accepted source owners. Callsite addresses below were checked in the immutable Porsche.exe disassembly and against the C++ call sites.

| Window-facing name | Callee owner / original VA | ABI bridge and result use | Original callsite evidence |
|---|---|---|---|
| `window_lock_create_005321f0` | `heap_lock_create_005321f0`, `heap_locks.cpp`, `005321f0` | Exact `cdecl () -> void*`; returned lock is stored and later passed to lock APIs. | `window_create.cpp`/`window_init.cpp`, e.g. `0053ac31` and `0053ad35` call the original VA. |
| `window_message_pump_005322b0`, `window_worker_game_pump_005322b0` | `heap_enter_005322b0`, `heap_locks.cpp`, `005322b0` | Caller takes a 32-bit lock identity; adapter reinterprets those same x86 bits as `void*`. Original callee is `cdecl(void*) -> void`; callers ignore EAX. The adapter's required `uint32_t` result is a non-semantic zero. | WndProc paint path `0053b80a`; worker message loop `0053b9e3`. Both push the shared lock value. |
| `window_message_dispatch_005322c0`, `window_worker_game_dispatch_005322c0` | `heap_leave_005322c0`, `heap_locks.cpp`, `005322c0` | Same lock-pointer bridge; original return is void and both callers ignore EAX. Adapter zero is non-semantic. | WndProc `0053b836`; worker message loop `0053ba26`. |
| `window_timed_callback_005366e0`, `window_position_timed_005366e0` | `timed_callbacks_005366e0`, `window_runtime.cpp`, `005366e0` | Exact `cdecl(uint32_t) -> uint32_t`; current callsites ignore the result. | `window_init.cpp` calls at `0053af57/0053af99`; position cleanup loop at `0053bd0a`. |
| `window_idle_0055f740`, `window_position_idle_0055f740` | `file_sleep_0055f740`, `file_events.cpp`, `0055f740` | Both preserve the single 32-bit milliseconds argument. Callee forwards to `SleepEx(milliseconds, TRUE)`. The void-facing alias discards the DWORD; the uint32 alias returns it. Window callers ignore the result. | `window_init.cpp` calls at `0053af5d/0053af93`; position loop at `0053bd03`. |
| `window_prepare_0053bcb0` | `window_position_cleanup_0053bcb0`, `window_position.cpp`, `0053bcb0` | Exact `cdecl() -> void`. | `window_init.cpp` calls at `0053af76`, guarded by a non-null HWND. |
| `window_resize_0053bec0` | `window_position_center_0053bec0`, `window_position.cpp`, `0053bec0` | Both are `cdecl` with two 32-bit words and void result; adapter preserves bit patterns while presenting the target's signed parameters. | `window_init.cpp` calls at `0053af3a` and `0053b020`; returned value is unused. |
| `window_thread_wait_0055fb30` | `file_event_signal_0055fb30`, `file_events.cpp`, `0055fb30` | Exact event-handle word; source alias returns void while `SetEvent` returns BOOL. Original caller ignores EAX. | `window_init.cpp` calls at `0053af81`. |
| `window_worker_wait_0055fb20` | `file_auto_event_0055fb20`, `file_events.cpp`, `0055fb20` | No arguments; event HANDLE is converted to the declared 32-bit return. The caller stores and uses the handle. | Worker startup call at `0053b8e1`. |
| `window_worker_wait_0055fb90` | `file_worker_wait_0055fb90`, `file_events.cpp`, `0055fb90` | One 32-bit handle word reinterpreted as `void*`; HANDLE/null result is converted to uint32. Worker ignores the wait result. | Worker startup call at `0053b8ec`. Original body waits indefinitely on the one event and returns the event handle on success. |
| `window_worker_wait_0055fc10` | `file_close_event_0055fc10`, `file_events.cpp`, `0055fc10` | One 32-bit handle word; `uint32_t` BOOL result matches. Worker ignores it. | Worker startup call at `0053b8f7`. |

The lock names `005322b0/c0` are not separate window routines: disassembly shows they forward their one pointer argument to `EnterCriticalSection`/`LeaveCriticalSection`. The sleep, timed-callback, event, cleanup, and centering targets likewise use their existing accepted implementations rather than copied behavior.

The x86 probe links the real `heap_locks.cpp`, `file_events.cpp`, `window_runtime.cpp`, `window_position.cpp`, Run070's `win32_window.cpp`, and `win32_core.cpp`. It executes a seeded critical-section lifecycle through the window lock aliases, creates/signals/waits/closes a real Win32 event through the worker aliases, checks both timed-callback aliases against recovered callback state, and takes the no-window cleanup branch. No GUI window is created. CRT/game edges required only for linking are explicit aborting boundaries: thread initialization, file-object allocation, channel notification, and position removal. The fixture seeds the lock pool and avoids those paths.

Build and run the non-GUI joint link fixture:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/072-window-links -B local/builds/v2/window-links-072 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/window-links-072 --config Release --target window_links_probe
./local/builds/v2/window-links-072/bin/Release/window_links_probe.exe
```
