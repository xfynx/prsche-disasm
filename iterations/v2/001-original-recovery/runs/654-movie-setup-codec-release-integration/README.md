# Run654 game setup movie and audio stream codec release integration

Shared acceptance `attempt 001` passes for frozen `652/003` (`652/001`,
`652/002` preserved) and `653/008` (`653/001`..`653/007` preserved) on
`Run651`. Eight PARTIAL originals (`00472860` 321B, `0059e440` 526B, `004dd4a0`
341B, `00566e10` 36B, `0056b3b0` 175B, `0056c140` 568B, `0056c420` 280B, and
`0056c620` 287B; 2534 code bytes total), `28B` `.data` (`005d998c..005d9999`
14B and `005d999c..005d99a9` 14B), and `273B` `.rdata` (`005bdaa0..005bdac7`
40B, `005bdd30..005bdd5d` 46B, `005bdd60..005bdd84` 37B, `005bddac..005bdde7`
60B, `005bdde8..005bde19` 50B, and `005bde1c..005bde43` 40B) integrate. Build
`001` compiles 373 TUs across 8 projects with unchanged inputs, zero compiler or
other linker errors, and 80 unresolved names / 85 references. Five frontier
dependencies (`audio_stream_codec_destroy_0056b3b0`,
`audio_stream_codec_reset_0056c420`, `audio_stream_service_release_00566e10`,
`game_setup_movie_004dd4a0`, and `game_setup_resource_open_0059e440`) close
while `0056c620` exposes `audio_stream_codec_refill_0056baf0` (`+1`). There is
no recovered game EXE. Registry 1016 preserves partial parent domains.

Native comparisons pass 122 measured cases (52 in `652/003` + 70 in `653/008`)
and 24 material controls (11 in `652` + 13 in `653`) at `/Od`/`/O2`. Canonical
game setup globals/movie callers, application context storage/effects/move,
heap locks, file roots/exists/close/wait, formatter entry, audio stream channel
storage (`006b7740`), stream validation/source file, and Run641 codec leaves
are reused without duplication. Shared audit verifies 924 source pins.

Stream codec refill `0056baf0` (and its read path `0056bd70`/`0056be40`),
network sync barrier `0048cdf0`, audio bank loaders, startup and gameplay
remain open. Active `655` (`0055ff60` + `0048d350` + `0048cdf0`) and `656`
integrate next in `657`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/652-game-setup-movie/native-config.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/653-audio-stream-codec-release/native-config.json --attempt 008
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/654-movie-setup-codec-release-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/654-movie-setup-codec-release-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/654-movie-setup-codec-release-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
