# Run618 frame surface setup and file backend open integration

Shared acceptance passes for frozen616001 and617001 on615. Two PARTIAL
originals (`00568f30` 324B and `00568900` 170B, 494 code bytes total) and 28B
of loader-zero `.data` (`006a5c84..006a5c9f`) integrate with zero new
file-backed `.data` or `.rdata`. Build001 compiles349 TUs across8 projects with
unchanged inputs, zero compiler or other linker errors and102 unresolved names/
107 references. Two real dependencies (`frame_pump_boundary_00568f30` and
`file_backend_open_00568900`) close; no new unresolved name enters. There is no
recovered game EXE. Registry947 preserves partial parent domains.

Native comparisons pass318 measured cases (78 in616001 + 240 in617001) and8
material controls (4 in616 + 4 in617) atOd/O2. Canonical frame interface
release (`585`), render thrash exports (`528`), formatter character/copy
(`153`), physical disk open (`156`) and network callback enumeration (`488`)
owners are reused without duplication. Shared audit verifies863 source pins and
956 canonical providers.

Broader aliases/faults/lifetimes, unrecovered visitors (`00569080`, `005689b0`),
startup and gameplay remain open. Next independent packets are619 (`0048ff30`)
and620 (`0048cb50` + `00490420`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/616-frame-surface-setup/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/617-file-backend-open/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/618-frame-surface-file-open-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/618-frame-surface-file-open-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/618-frame-surface-file-open-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
