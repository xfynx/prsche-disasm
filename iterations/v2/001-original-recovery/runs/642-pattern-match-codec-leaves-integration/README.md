# Run642 pattern match and audio stream codec leaves integration

Shared acceptance `attempt 001` passes for frozen `640/001` and `641/003`
(`641/001`–`002` preserved) on `Run639`. Six PARTIAL originals (`004a5f90` 464B,
`0056bce0` 41B, `0056bd10` 83B, `0056c380` 90B, `0056c3e0` 58B, and `0056c540`
221B; 957 code bytes total), `6B` file-backed `.data` (`005d13bc..005d13c1`),
and `36B` `.rdata` (`005bdd88..005bddab`) integrate. Build `001` compiles 365
TUs across 8 projects with unchanged inputs, zero compiler or other linker
errors, and 88 unresolved names / 91 references (unblocking `004ae4d0`/
`004ae8c0` and `0056c140`/`0056c420`/`0056b3b0`). There is no recovered game
EXE. Registry 985 preserves partial parent domains.

Native comparisons pass 332 measured cases (156 in `640/001` + 176 in
`641/003`) and 18 material controls (9 in `640` + 9 in `641`) at `/Od`/`/O2`.
Canonical formatter text/float helpers, heap locks, file operation group,
stream handle validation, shared diagnostic globals, and `005bd978` source-file
string owners are reused without duplication. Shared audit verifies 904 source
pins.

Parent callers (`004ae4d0`/`004ae8c0` and `0056c140`/`0056c420`/`0056b3b0`),
non-C locale CRT behavior, unmapped stream pointers, startup and gameplay
remain open. Verified `643` (`004ae4d0` + `004ae8c0`) and active `644`
(`0053c640`..`00555640`) integrate next in `645`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/640-pattern-match/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/641-audio-stream-codec-leaves/native-config.json --attempt 003
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/642-pattern-match-codec-leaves-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/642-pattern-match-codec-leaves-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/642-pattern-match-codec-leaves-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
