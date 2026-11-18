# Run651 startup sequence resource table and startup text fallbacks integration

Shared acceptance `attempt 001` passes for frozen `649/002` (`649/001`
preserved) and `650/001` on `Run648`. Eleven PARTIAL originals (`00561e00` 63B,
`0059d9b0` 206B, `00452590` 198B, `004690d0` 17B, `0044de50` 16B, `0044de60`
163B, `0044df70` 16B, `0044df80` 16B, `0044df90` 16B, `0044dfa0` 1B, and
`0044dfe0` 37B; 749 code bytes total), `295B` `.data` (`005ce658..005ce699` 66B,
`005ce69c..005ce6d7` 60B, `005ce6d8..005ce719` 66B, `005ce71c..005ce763` 72B,
and 31B loader-zero across `00613e04`, `00619760`, `0061bcc8`, `0061c164`,
`0061e180`, `0061e1cc`, `0061e1d4`, `00628a28`, `0065b30c`), and `0B` `.rdata`
integrate. Build `001` compiles 371 TUs across 8 projects with unchanged
inputs, zero compiler or other linker errors, and 84 unresolved names / 88
references. Five frontier dependencies (`startup_sequence_call_004690d0` and
`startup_text_fallback_0_0044df70`..`0044dfa0`) close with zero new unresolved
symbols. There is no recovered game EXE. Registry 1008 preserves partial parent
domains.

Native comparisons pass 338 measured cases (150 in `649/002` + 188 in `650/001`)
and 22 material controls (10 in `649` + 12 in `650`) at `/Od`/`/O2`. Canonical
file roots, resource dispatch/predicate, fe_stream, formatter entry, shape/copy
leaves, context table helpers, render mode, quality tier, quality masks, and
texture slot bind owners are reused without duplication. Shared audit verifies
919 source pins.

Game setup movie `004dd4a0`/`0059e440`/`00472860`, audio codec/service
frontiers, startup and gameplay remain open. Active `652` (`00472860` +
`0059e440` + `004dd4a0`) and next frontier packet `653` integrate in `654`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/649-startup-sequence-resource-table/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/650-startup-text-fallbacks/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/651-resource-table-text-fallbacks-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/651-resource-table-text-fallbacks-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/651-resource-table-text-fallbacks-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
