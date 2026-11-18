# Run648 startup context table helpers and startup sequence text integration

Shared acceptance `attempt 001` passes for frozen `646/002` (`646/001`
preserved) and `647/002` (`647/001` preserved) on `Run645`. Five PARTIAL
originals (`0044b830` 136B, `0044d320` 85B, `0047f040` 330B, `0044df10` 83B, and
`0044e010` 615B; 1249 code bytes total), `505B` `.data` (`005ce59c..005ce5fb`
96B, `005ce768..005ce8f3` 396B, `005ce8f4..005ce8fc` 9B, and
`00628bac..00628baf` 4B loader-zero), and `0B` `.rdata` integrate. Build `001`
compiles 369 TUs across 8 projects with unchanged inputs, zero compiler or
other linker errors, and 89 unresolved names / 92 references. Real frontier
dependency `startup_sequence_text_0044df10` closes (`-1`) while its local
fallback table exposes `startup_text_fallback_0_0044df70`..`0044dfa0` (`+4`).
There is no recovered game EXE. Registry 997 preserves partial parent domains.

Native comparisons pass 192 measured cases (112 in `646/002` + 80 in `647/002`)
and 17 material controls (7 in `646` + 10 in `647`) at `/Od`/`/O2`. Canonical
application allocator, context base/effects, heap locks, install paths,
application state, render mode, quality tier, rooted file exists, resource
open, fe_stream free, and texture slot bind owners are reused without
duplication. Shared audit verifies 914 source pins.

Fallback leaves `0044df70..0044dfa0` (plus `0044de50`/`0044de60`/`0044dfe0`),
parent `004690d0`/`00452590`, startup and gameplay remain open. Verified `649`
(`00561e00` + `0059d9b0` + `00452590` + `004690d0`) and active `650`
(`0044de50`..`0044dfe0`) integrate next in `651`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/646-startup-context-table-helpers/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/647-startup-sequence-text/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/648-context-helpers-startup-text-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/648-context-helpers-startup-text-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/648-context-helpers-startup-text-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
