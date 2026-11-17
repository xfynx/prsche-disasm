# Run594 context destroy and display prevideo integration

Shared acceptance passes for frozen592001 and593002 (`593001` preserved) on591.
Two PARTIAL originals (`00525ec0` 124B and `0044e2c0` 165B, 289 code bytes total)
integrate with zero new original data. Build001 compiles333 TUs across8 projects
with unchanged inputs, zero compiler or other linker errors and119 unresolved
names/124 references. Two real dependencies
(`application_context_base_destroy_00525ec0` and
`render_display_prevideo_0044e2c0`) close; no new unresolved name enters. There
is no recovered game EXE. Registry912 preserves partial parent domains.

Native comparisons pass1304 measured cases (24 in592001 + 1280 in593002) and8
material controls (4 in592 + 4 in593) atOd/O2. All124 production instruction
bytes of `00525ec0` match the original after five `REL32` call normalizations.
Canonical context-base/allocator and display/mode owners are reused without
duplication. Shared audit verifies823 source pins and874 canonical providers.

Broader aliases/faults/lifetimes, unrecovered callees, startup and gameplay
remain open. Next independent packets are595 (`004691c0` + `00468100`) and596
(`0044dfb0` + `0044e370`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/592-context-base-destroy/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/593-render-display-prevideo/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/594-context-prevideo-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/594-context-prevideo-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/594-context-prevideo-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
