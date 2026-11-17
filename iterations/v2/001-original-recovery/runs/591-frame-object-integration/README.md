# Run591 frame state and object init integration

Shared acceptance passes for frozen589001 and590001 on588. Two PARTIAL originals
(`005363a0` 178B and `00403520` 184B, 362 code bytes total) integrate with zero
new original data. Build001 compiles331 TUs across8 projects with unchanged
inputs, zero compiler or other linker errors and121 unresolved names/126
references. Two real dependencies (`frame_pump_boundary_005363a0` and
`game_setup_object_init_00403520`) close; no new unresolved name enters. There
is no recovered game EXE. Registry910 preserves partial parent domains.

Native comparisons pass6068 measured cases (6048 in589001 + 20 in590001) and8
material controls (4 in589 + 4 in590) atOd/O2. Canonical state/callback/release
owners (`527`, `570`, `572`) and context/heap owners (`context_effects`,
`application_heap_state`) are reused without duplication. Shared audit verifies
818 source pins and872 canonical providers.

Broader aliases/faults/lifetimes, live frame/allocator producers, startup and
gameplay remain open. Next independent packets are592 (`00525ec0`) and593
(`0044e2c0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/589-frame-state-release/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/590-game-setup-object-init/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/591-frame-object-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/591-frame-object-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/591-frame-object-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
