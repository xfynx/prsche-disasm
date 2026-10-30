# Run449: resource-path Windows IAT bindings

The original0059d650 consumer calls GetModuleFileNameA through005b2064 and
GetDriveTypeA through005b2060. Indexed imports and raw callsite bytes establish
the bindings. Linker aliases retain the actual SDK IAT cells; there is no copied
pointer, dynamic initialization, new original body or original storage. The
modern anchor retains the archive member and its linker directives in Run450.

Native002 passes48 cases and3 mutation controls across `/Od` and `/O2`: the
recovered cell addresses equal the SDK cells, loaded targets equal GetProcAddress,
and original call/load instructions agree with typed and direct API calls on
returns, LastError, buffers and canaries. The14 indexed instruction bytes are
callsite evidence only, not a new recovered function. Harness carriers are marked.
A separate unexecuted NOENTRY DLL links the same object and imports exactly
GetModuleFileNameA/GetDriveTypeA; evidence and command are pinned locally.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/449-resource-path-iat/native-config.json --attempt 002
```

Receipt: `local/experiments/v2-resource-path-iat-449/002/receipt.json`.
001 main variants passed, but its mutation failure marker was unflushed;
002 changes fixture flushing only and retains001 logs. Windows APIs are tested
on this host. Historical OS/filesystem fidelity, the full resource algorithm and
real game startup remain unverified. Run450 owns game integration/acceptance.
