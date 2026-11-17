# Run612 frame audio send level and splash sprite horizflip integration

Shared acceptance passes for frozen610001 and611002 (`611001` preserved) on609.
Eight PARTIAL originals (`00590290` 3B, `00589d70` 121B, `00598eb0` 99B,
`005902a0` 157B, `00565cd0` 137B, `0056e2a8` 24B, `005712f0` 49B and `00563320`
286B, 876 code bytes total) and 126B of `.rdata` strings (`005bced8`,
`005bcf08`, `005bcf48`) integrate with zero new writable `.data`. Build001
compiles345 TUs across8 projects with unchanged inputs, zero compiler or other
linker errors and106 unresolved names/111 references. Two real dependencies
(`frame_services_boundary_00565cd0` and `splash_progress_update_sprite_00563320`)
close; no new unresolved name enters. There is no recovered game EXE.
Registry942 preserves partial parent domains.

Native comparisons pass3138 measured cases (2258 in610001 + 880 in611002) and8
material controls (4 in610 + 4 in611) atOd/O2. Canonical audio device/backend
(`434`, `435`), render descriptor (`374`), pixel buffer (`378`/`381`) and
diagnostic (`files`/`shared_runtime_globals`) owners are reused without
duplication. Shared audit verifies853 source pins and943 canonical providers.

Broader aliases/faults/lifetimes, `bus >= 2`, non-returning diagnostics, startup
and gameplay remain open. Next independent packets are613 (`00466380` +
`0044b1d0`) and614 (`0048d550`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/610-frame-audio-send-level/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/611-splash-sprite-horizflip/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/612-frame-send-sprite-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/612-frame-send-sprite-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/612-frame-send-sprite-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
