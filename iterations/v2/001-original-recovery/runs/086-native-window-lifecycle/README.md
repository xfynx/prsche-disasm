# Run086 - native original window lifecycle

This fixture calls the recovered original `window_init_0053ac20(640,480,0)`:
class registration, all 27 callback registrations, real original thread
bootstrap, event handshake, CreateWindowExA, recovered WndProc and message
callbacks. It then calls `window_position_cleanup_0053bcb0`, which posts the
original custom message 0x466 through recovered `0053a8e0`; the worker destroys
the HWND, exits, and is joined using a duplicated OS handle. The original
thread shutdown runs through the fixture's explicit host exit registry.

The driver checks the HWND, visibility, client dimensions, production WndProc,
resize notifications, handler count, worker completion, window destruction and
class reference release. A 15-second watchdog fails explicitly on a hang.
It saves/restores the host lock-key toggle states around the original create
routine, whose verified behavior clears them. Restoration is fixture cleanup.

The renderer/input dispatch gate and all window configuration object words
start at their original BSS zero values. Renderer virtual cleanup and dynamic
input callbacks are consequently outside this test. Unknown boundaries abort
if reached; no fake successful renderer or game loop is supplied. CRT qsort,
zero-only DWORD fill and process exit registration are explicit host services.
The executable is an OS integration fixture, not a rebuilt playable game.

Source Porsche.exe SHA256:
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Original call/ABI evidence and differential checks are in Runs041,060,062,
069,077,079,082-085,087-089. The 0053bcef caller is corrected to pass
`0053a8e0(0x466,0,0,0)`; Run048's refreshed proof checks all four arguments.
