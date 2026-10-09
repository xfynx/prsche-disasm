# Run064 — native relocation for the window callback table

Source is immutable `local/game/Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. The original registration sequence is the 27 `(message, callback VA)` push pairs and calls to `0053a800` at `0053ad35..0053aecf`. The verifier extracts those pairs from the disassembly and checks them against the current `window_init.cpp` table. There are 16 distinct callback VAs.

`window_callback_resolve` maps each known original VA to the address of its declared native C++ callback. Those declarations share the recovered six-argument stdcall `WindowHandler` signature. The mapping covers `0053b040`, `0053b050`, `0053b230`, `0053b260`, `0053b290`, `0053b2a0`, `0053b2e0`, `0053b360`, `0053b3d0`, `0053b450`, `0053b6b0`, `0053b710`, `0053b770`, `0053b7d0`, `0053b870`, and `0053b8b0`. For each, the complete original disassembly ends at the next known callback/helper entry with `RET 18`; all entries compile into the shared typed function-pointer declaration without casts.

The table converter first resolves every VA and writes native `WindowHandlerEntry` values only when all entries are known and output capacity is sufficient. An unknown callback returns failure and its VA, never a no-op or executable guest address. The fixture proves all 27 records relocate to nonnull, distinct native pointers, verifies duplicate registrations share the corresponding pointer, checks original ordering/messages, and confirms an unknown VA leaves output unchanged. All 27 registrations resolve; no table callbacks remain unresolved.

This run adds only the relocation API, isolated probe, verifier, and report. It does not change `window_init.cpp` or the shared registration function. Integration needs the initializer to resolve each guest VA before registration, then pass the native callback through a typed registration entry point (or, on this enforced x86 target, an explicitly converted native pointer word). The existing raw-VA path must not execute until that wiring is done.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/064-window-callback-bindings -B local/builds/v2/run064-window-callback-bindings -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/run064-window-callback-bindings --config Release --target window_callback_bindings_probe
py -3 scripts/research/verify-v2-window-callback-bindings.py
```
