# Run645 audio transition finish and render startup text leaves integration

Shared acceptance `attempt 001` passes for frozen `643/002` (`643/001`
preserved) and `644/001` on `Run642`. Seven PARTIAL originals (`004ae4d0` 995B,
`004ae8c0` 198B, `0053c640` 63B, `00556370` 61B, `005563b0` 24B, `00554930` 19B,
and `00555640` 95B; 1455 code bytes total), `9B` `.data` (`005d1c1c..005d1c20`
5B + `0065b928..0065b92b` 4B loader-zero), and `0B` `.rdata` integrate. Build
`001` compiles 367 TUs across 8 projects with unchanged inputs, zero compiler or
other linker errors, and 86 unresolved names / 89 references. Three real
frontier dependencies (`application_audio_transition_finish_004ae4d0`,
`frame_services_boundary_004ae4d0`, and `frame_services_boundary_004ae8c0`)
close; linking `audio_callback_resource_564.obj` (`005666f0`/`00567720`) exposes
its single unrecovered child `audio_service_stream_start_00567550`. There is no
recovered game EXE. Registry 992 preserves partial parent domains.

Native comparisons pass 182 measured cases (92 in `643/002` + 90 in `644/001`)
and 20 material controls (10 in `643` + 10 in `644`) at `/Od`/`/O2`. Canonical
audio resource controls, application state, formatter entry, seed PRNG, pattern
matcher, stream ramp/volume/status, texture format preferences (`005dedcc[10]`),
texture slots (`006a33f8`), and heap copy owners are reused without duplication.
Shared audit verifies 909 source pins.

Real stream start `00567550`, parent callers (`0044df10`/`0044e010`,
`004690d0`/`00452590`), startup and gameplay remain open. Verified `646`
(`0044b830` + `0044d320` + `0047f040`) and active `647` (`0044e010` + `0044df10`)
integrate next in `648`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/643-audio-transition-finish/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/644-render-startup-text-leaves/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/645-audio-transition-text-leaves-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/645-audio-transition-text-leaves-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/645-audio-transition-text-leaves-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
