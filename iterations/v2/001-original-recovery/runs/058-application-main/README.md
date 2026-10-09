# Run 058: `app_main_004b6a50`

Recovered the 1,430-byte `Porsche.exe` function at `004b6a50..004b6fe5` as a
native C++ caller. The source follows the original setup, FE-record, render,
network, tick-loop, and shutdown control flow. The binary source is pinned by
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.

The binary-index lookup was `Porsche.exe` in
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl`,
followed by the exact range in
`research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`. The index
locates the function; the assembly provides the branch and state evidence.
`local/experiments/v2-app-main/004b6a50.c` was not used as semantic evidence.

The production source calls the recovered page, startup, FE, resource, and
render wrappers directly. Other callees remain typed interfaces. The isolated
probe controls their outputs and compares native C++ with original x86 across
14 cases: allocation success and failure; setup early exit and re-entry; both
startup network wait paths; FE modes; tick processing; configuration-name copy;
and the mode-3 network continuation and pending-action branches. It compares
return values, ordered boundary calls, selected startup/FE globals, and the
touched network fields and copied name.
The result is in `verification.json`; its dependency hashes include the probe,
production translation unit, transitive quoted headers, CMake file, verifier,
and dependency-hash helper.

The original call `0053c290(0x006573e8, 0, 0x3e24)` clears a span that includes
multiple FE globals. `application_main_fill_fe_arena_0053c290` remains an
explicit boundary until those addresses are represented by a shared arena and
aliases; the native probe does not clear a single host global for this call.
The `004b4da0` display consumer is also a boundary; the main-owned continuation
byte is initialized and changed by the recovered caller's network branches.
The startup exit, UI, game setup, and network consumers are fixture boundaries,
so this run does not claim their internal behavior or prove a real game launch.
The x86 tests force each wait boundary to make state ready; the original's
unbounded wait behavior is retained in source and was not timing-tested.

Rebuild and verify on the configured MSVC Win32 toolchain:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  'local/builds/v2/001-original-recovery/application-main-058' --config Release
py -3 scripts/research/verify-v2-application-main.py
```

Integration correction: original `004b6b68` tests a DWORD at `00657a60`; its host declaration is DWORD-sized. A nonzero-high-byte `0x100` case proves the branch is not a byte test. The refreshed integration report contains 15 cases.
