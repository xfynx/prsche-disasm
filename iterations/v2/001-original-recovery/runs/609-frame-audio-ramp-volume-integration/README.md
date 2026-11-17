# Run609 frame audio stream ramp and channel volume integration

Shared acceptance passes for frozen607001 and608001 on606. Eight PARTIAL
originals (`00565dd0` 159B, `00566ae0` 88B, `004ae3c0` 165B, `00589df0` 140B,
`00590d10` 62B, `005662b0` 141B, `00566340` 50B and `004af900` 112B, 917 code
bytes total) and 21B of loader-zero `.data` (`00656ae8..00656aef`, `00657388`,
`006573a4`, `006573a8..006573af`) integrate. Build001 compiles343 TUs across8
projects with unchanged inputs, zero compiler or other linker errors and108
unresolved names/113 references. Three real dependencies
(`frame_services_boundary_004ae3c0`, `frame_services_boundary_004af900` and
`frame_services_boundary_00566340`) close; no new unresolved name enters. There
is no recovered game EXE. Registry934 preserves partial parent domains.

Native comparisons pass2540 measured cases (1540 in607001 + 1000 in608001) and8
material controls (4 in607 + 4 in608) atOd/O2. Canonical audio device/backend
(`434`, `435`, `478`, `561`) owners are reused without duplication. Shared
audit verifies848 source pins and932 canonical providers.

Broader aliases/faults/lifetimes, live hardware voice callbacks, startup and
gameplay remain open. Next independent packets are610 (`00565cd0` + `00590290` +
`005902a0` + `00589d70` + `00598eb0`) and611 (`00563320` + `0056e2a8` +
`005712f0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/607-frame-audio-stream-ramp/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/608-frame-audio-channel-volume/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/609-frame-audio-ramp-volume-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/609-frame-audio-ramp-volume-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/609-frame-audio-ramp-volume-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
