# Run606 render initialize callbacks and driver context mode integration

Shared acceptance passes for frozen604001 and605001 on603. Three PARTIAL
originals (`005759f0` 43B, `005381d0` 83B and `00549220` 206B, 332 code bytes
total), 8B of file-backed `.data` (`005dea60`, `005dea78`) and 4B of loader-zero
`.data` (`006a64c0`) integrate. Build001 compiles341 TUs across8 projects with
unchanged inputs, zero compiler or other linker errors and111 unresolved names/
116 references. Two real dependencies (`render_initialize_callbacks_005759f0`
and `render_driver_context_mode_00549220`) close; no new unresolved name enters.
There is no recovered game EXE. Registry926 preserves partial parent domains.

Native comparisons pass822 measured cases (68 in604001 + 754 in605001) and8
material controls (4 in604 + 4 in605) atOd/O2. Canonical THRASH export table
(`006bd910`), movie service (`0069ed0c`) and `1.5f` scalar (`005b246c`) owners
are reused without duplication. Shared audit verifies843 source pins and919
canonical providers.

Broader aliases/faults/lifetimes, callback bodies (`00575a20`, `00575980`), live
THRASH DLL exports, startup and gameplay remain open. Next independent packets
are607 (`004ae3c0` + `00566ae0` + `00565dd0`) and608 (`004af900` + `00566340` +
`005662b0` + `00589df0` + `00590d10`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/604-render-initialize-callbacks/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/605-render-driver-context-mode/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/606-render-callbacks-mode-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/606-render-callbacks-mode-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/606-render-callbacks-mode-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
