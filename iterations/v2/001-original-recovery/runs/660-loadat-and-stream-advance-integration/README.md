# Run660 resource loadat, probe reset, and audio stream codec advance integration

Shared acceptance `attempt 001` passes for frozen `658/003` (`658/001`..`002`
preserved) and `659/002` (`659/001` preserved) on `Run657`. Nine PARTIAL
originals (`00561e90` 138B, `00561e40` 71B, `00561f20` 71B, `0059db50` 218B,
`00566880` 62B, `004adf50` 188B, `0056ba20` 85B, `0056ba80` 97B, and `0056b860`
433B; 1363 code bytes total), `0B` `.data`, and `152B` `.rdata`
(`005bcd90..005bcdb5` 38B, `005bdbfc..005bdc23` 40B, `005bdc24..005bdc4a` 39B,
and `005bdc4c..005bdc6e` 35B) integrate. Build `001` compiles 377 TUs across 8
projects with unchanged inputs, zero compiler or other linker errors, and 77
unresolved names / 82 references. One frontier dependency
(`audio_stream_codec_advance_0056b860`) closes with zero new unresolved names.
There is no recovered game EXE. Registry 1032 preserves partial parent domains.

Native comparisons pass 220 measured cases (196 in `658/003` + 24 in `659/002`)
and 33 material controls (17 in `658` + 16 in `659`) at `/Od`/`/O2`. Canonical
file open/read/close/exists/roots/request helpers, resource atomic context,
formatter entry, heap locks, bigfile kind/descriptor reader, stream source
file/diagnostics, audio resource query root (`00656ab4`), and `0056baf0` refill
are reused without duplication. Shared audit verifies 934 source pins.

Audio probe configure `004ae100` / start `004a8b80` (and helpers
`00562100`/`00562300`/`0059df70`/`004a6c90`), startup/render leaves and gameplay
remain open. Integrate next in `661`/`662` -> `663`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/658-resource-loadat-and-reset/native-config.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/659-audio-stream-codec-advance/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/660-loadat-and-stream-advance-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/660-loadat-and-stream-advance-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/660-loadat-and-stream-advance-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
