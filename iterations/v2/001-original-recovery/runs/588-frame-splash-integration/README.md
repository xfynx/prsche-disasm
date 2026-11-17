# Run588 frame and splash integration

Shared acceptance passes for frozen585002 and587002 on584. Two PARTIAL originals
(`005693e0` 53B and `004edc00` 48B, 101 code bytes total) and three loader-zero
`.data` DWORDs `006a5ca0..006a5cab` (12B) integrate into the shared build.
Build001 compiles329 TUs across8 projects with unchanged inputs, zero compiler
or other linker errors and123 unresolved names/128 references. Two real
dependencies (`frame_pump_boundary_005693e0` and `splash_progress_dispatch_004edc00`)
close; no new unresolved name enters. There is no recovered game EXE. Registry908
preserves partial parent domains.

Native comparisons pass42 measured executions (32 in585002 + 10 in587002) and7
material controls (4 in585 + 3 in587) atOd/O2; attempts585001 and587001 are
preserved. All53 production instruction bytes of `005693e0` equal the original
after five DIR32 normalizations. Shared audit verifies813 source pins and868
canonical providers.

Broader aliases/faults/lifetimes, live frame/splash producers, startup and
gameplay remain open. Next independent packets are589 (`005363a0`) and590
(`00403520`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/585-frame-interface-release/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/587-splash-command-dispatch/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/588-frame-splash-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/588-frame-splash-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/588-frame-splash-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
