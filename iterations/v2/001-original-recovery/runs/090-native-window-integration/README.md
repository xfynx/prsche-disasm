# Run090 - original window startup executes on Win32

Accepted on 2026-10-10: **213 full functions and 5 partial consumers**.
The common MSVC Win32 build includes 71 comparison/alias probes, four native
OS fixtures and three non-GUI link fixtures. Sixteen fresh original-x86
reports cover 5,091 bounded comparisons; unchanged accepted reports retain
their earlier evidence, and all 69 current source dependency closures pass.

Run086 now calls the actual recovered startup, worker, WndProc, registration
table, event handshake and position cleanup against real Win32. The observed
window was visible, had a 640x480 client area and the production WndProc, and
registered all 27 handlers. Two original resize notifications ran. Original
cleanup posted message 0x466; the worker destroyed the window and completed,
the duplicated OS thread handle joined, and the class reference was released.
The common-build process exited with code zero. Core/thread/narrow-window OS
fixtures also exited with zero. Evidence: `native-window-lifecycle-result.json`
and the three other `native-*-result.json` files, with source and EXE hashes.

The cleanup caller at 0053bcef previously passed 0x466 in the fourth argument
instead of the first. This would choose SendNotifyMessageA with a null message
instead of posting the worker's close message. The C++ call is corrected to
`0053a8e0(0x466,0,0,0)`, and the refreshed position oracle checks all four
arguments. The original wrapper preserves its asymmetric API return rules.

Runs083-085,087-089,091-092 add shutdown/null-renderer cleanup, window helper
calls, object cleanup/update, resize/key-table bindings, and event translation.
The existing mouse algorithm was independently checked and moved to one
consumer, with thin WndProc/renderer adapters. The original callback gate is
the fourth argument; an initial analysis hypothesis about the first argument
was rejected by the x86 stack oracle. No guessed input behavior was accepted.
Object elapsed-time comparisons include signed thresholds and DWORD wraps.

Callback 0053bae0 is now SHA-indexed as a complete 26-byte supplementary body:
32 manual entries, 36,619 catalog functions. Link inventory has no duplicate
project definitions: 1,002 defined symbols, 290 unresolved references, of
which 139 are addressed consumers outside the recovered registry. This is
an inventory of the libraries, not an attempted full game EXE link.

This is **not a playable game launch**. The native window fixture starts from
zero renderer/input BSS state. Unknown renderer virtual methods, dynamic
callbacks, the input-device snapshot and terminal shutdown service remain
explicit boundaries. Its host services are documented in Run086; no fake
game loop is supplied. Original WM_CLOSE/timer-driven process exit is not
the custom-message cleanup path exercised here. Visual gameplay, exact binary
matching, full FE/resource/engine startup, audio and both careers remain open.

All original behavior evidence is pinned to Porsche.exe SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The immutable original corpus is unchanged. Reproduce with:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
./local/builds/v2/001-original-recovery/bin/Release/native_window_lifecycle.exe
py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
py -3 scripts/research/structure-v2.py
```

Fresh verifier invocations are recorded in `refresh-plan.json` and each
report's verifier/source pins. Choose another report root after this run is
committed; historical reports are not mutable outputs.
