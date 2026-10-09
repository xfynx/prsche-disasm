# Run036 - first native Win32 window from recovered consumers

Compiled and executed native_window_smoke.exe (PE machine014c/x86) on Windows.
It executes original class-registration prefix53ac20, complete window create
53bb00, WndProc53aba0, comparator53a7f0 and CRT binary search5a2f23, bound to
real Win32 APIs. No machine-code trampoline or original EXE is executed here.
Actual result: class registered with recovered WndProc, visible HWND,
640x480 client area,39 real messages through the default-procedure boundary,
clean window destruction, process exit0. See native-window-result.json.

This is a source/native platform smoke fixture, not a runnable game. Its
positioned/channels-ready/empty-handler state is explicit synthetic test input.
The 640x480 default and Porsche name have caller evidence575820/4a5c30->5655f0.
The harness message pump is platform test infrastructure, not a reconstructed
game loop. Full window_init, worker, renderer and app_main are not executed.
Original visuals/behavior are not accepted from an HWND or IsWindowVisible.

Build: configure this run with MSVC Win32 CMake, build native_window_smoke,
or use scripts/build-v2.ps1 (common target builds the same source fixture).
Executed: local/builds/v2/native-window-036/bin/Release/native_window_smoke.exe.
The window stays for300ms then closes automatically. This run records an
actual bounded native execution, separate from original-x86 unit comparisons.

Next: join original memory/allocator, THRASH driver loading, full window
initialization, shared configuration state and worker, then original main
startup. Unknown game calls remain unresolved, not replaced with no-op logic.
