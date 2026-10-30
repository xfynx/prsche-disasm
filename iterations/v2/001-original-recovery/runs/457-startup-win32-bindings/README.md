# Run457: startup Win32 adapters

Nine missing application-instance/display/cursor boundaries now transport to
the original indexed SDK imports. Raw Porsche.exe import descriptors and 56
parent-context instructions confirm DLL/name/IAT identity, argument order and
used returns. Eight adapters use cdecl at the existing C++ boundary; cursor uses
stdcall. ReleaseDC/MessageBoxA returns remain ignored. The desktop and cursor
adapters reuse accepted `audio_platform_desktop_window` and `window_show_cursor`.
The full Run453 manifest plus delta (595 files) has no competing providers.
There are **zero new original algorithms or original storage**.

Native001 passes 432 cases across `/Od` and `/O2`, with nine detected mutations.
The fixture verifies its actual import-directory cells and loaded SDK addresses
before installing controlled endpoints in its own IAT. It compares original
CALL/cached MOV+CALL instructions with adapters on arguments, endpoint/count,
LastError, stack balance and all used return bits. The 58 original instruction
bytes are callsite evidence; synthetic register saves/PUSH/RET and relocated
operands are marked. Cells are restored and checked. No live dialog, window
activation or cursor API is invoked.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/457-startup-win32-bindings/native-config.json --attempt 001
```

Receipt: `local/experiments/v2-startup-win32-bindings-457/001/receipt.json`.
`original-evidence.json`, `ownership.json`, `coff.json` and `evidence.json` pin
the mappings, closure search and nine actual COFF definitions. A separate,
unexecuted NOENTRY DLL links those same objects plus accepted providers and
imports exactly the nine SDK exports; `platform-imports-link.json` pins it.
Its first link omitted libraries needed while resolving discarded canonical
functions; the retained local log records that failure. Link002 supplies the
existing libraries and passes without source changes.

Production source: `startup_win32_bindings_457.cpp`. Run456 owns shared game
integration and registry/docs. Full parent composition, live display/window
behavior, historical OS fidelity and game startup remain unverified here.
