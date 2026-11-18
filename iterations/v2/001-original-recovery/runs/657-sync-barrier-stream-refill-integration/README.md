# Run657 network sync barrier and audio stream codec refill integration

Shared acceptance `attempt 001` passes for frozen `655/002` (`655/001`
preserved) and `656/001` on `Run654`. Seven PARTIAL originals (`0055ff60` 15B,
`0048d350` 30B, `0048cdf0` 1364B, `0056baf0` 491B, `0056bd70` 193B, `0056be40`
435B, and `0056c000` 60B; 2588 code bytes total), `77B` `.data`
(`005d0738..005d078d`), and `143B` `.rdata` (`005bdc70..005bdc96` 39B,
`005bdc98..005bdcd9` 66B, and `005bdcdc..005bdd01` 38B) integrate. Build `001`
compiles 375 TUs across 8 projects with unchanged inputs, zero compiler or other
linker errors, and 78 unresolved names / 83 references. Three frontier
dependencies (`application_main_function_0048cdf0`,
`startup_sequence_call_0048cdf0`, and `audio_stream_codec_refill_0056baf0`) close
while `0056bd70` exposes `audio_stream_codec_advance_0056b860` (`+1`). There is
no recovered game EXE. Registry 1023 preserves partial parent domains.

Native comparisons pass 100 measured cases (46 in `655/002` + 54 in `656/001`)
and 27 material controls (13 in `655` + 14 in `656`) at `/Od`/`/O2`. Canonical
application main/startup sequence wrappers, network service/action helpers,
key-callback cell, heap locks, render diagnostic, sleep/timer callbacks, file
operation/read helpers, stream source file/shared diagnostic globals, and Run641
codec leaves are reused without duplication. Shared audit verifies 929 source
pins.

Stream codec advance `0056b860`, file/resource loadat helpers and probe leaves,
audio bank loaders, startup and gameplay remain open. Active workers `658`
(resource loadat/reset) and `659` (`0056b860` advance) integrate next in `660`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/655-network-sync-barrier/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/656-audio-stream-codec-refill/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/657-sync-barrier-stream-refill-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/657-sync-barrier-stream-refill-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/657-sync-barrier-stream-refill-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
