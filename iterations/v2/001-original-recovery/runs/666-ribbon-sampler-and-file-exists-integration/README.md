# Run666 road ribbon sampler integration

Shared acceptance `attempt 003` (`build-001.json` and `build-002.json` preserved)
passes for frozen `664/005` (`664/001`..`004` preserved) on `Run663`. Three PARTIAL
originals (`00532860` 17B, `00434aa0` 750B, `00434a90` 5B; 772 code bytes total),
`3204B` `.bss` (`0060fde0..00610a5f` and `00628bc0`), and `8B` `.rdata`
(`005bb2c8..005bb2cf`) integrate. Build `003` compiles 380 TUs across 8 projects
with unchanged inputs, zero compiler or other linker errors, and 74
unresolved names / 79 references. `startup_sequence_call_00434a90`
closes with zero new unresolved names. Standalone `Run665` (`005` PASS, 258x2=516
cases, 14 mutations) confirmed its six path-device/file-exists functions are already
canonically owned in `porsche_game_entry_bridges` by `326`/`327`/`329`/`331` and
`formatter_search.cpp`, so `665` is retained as verified standalone proof without
duplicate production linkage. There is no recovered game EXE. Registry 1046 preserves
partial parent domains.

Native comparisons pass 74 measured cases and 13 material controls at
`/Od`/`/O2`. Canonical owners are reused without duplication. Shared audit verifies
942 source pins.

Active flash worker `667` (`00590d80`..`004ad9c0`) and completed `668/001`
(`004146f0`/`00413cf0`, 704B) prepare `Run669` integration and `004a8b80`/`004a8cd0`/
`00537e00`/`0053c8e0`/`00565c70` frontier closures.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/664-road-ribbon-sampler/native-config.json --attempt 005
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/666-ribbon-sampler-and-file-exists-integration/build-config.json --phase configure --attempt 003
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/666-ribbon-sampler-and-file-exists-integration/build-config.json --phase build --attempt 003
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/666-ribbon-sampler-and-file-exists-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
