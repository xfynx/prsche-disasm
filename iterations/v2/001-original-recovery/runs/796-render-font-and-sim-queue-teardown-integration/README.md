# Run796 render debug font and sim audio queue teardown integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding `793/004` (`0053c6c0` + 7 leaves, `226B` read-only data) and `794/002` (`004afd30`, `004afe50`, `004af970`, `004a8490`, `38B` read-only literals + `41B .bss`) onto `Run792`: `459` TUs / 8 projects, **82 unresolved names / 92 references** (`3` closed, `0` new), `272` native comparisons, `24` mutations, `1,132` source pins, `2` REA sessions, registry `1,307` (`+12`), no EXE.

Commands: `$env:MSBUILDDISABLENODEREUSE='1'; py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/796-render-font-and-sim-queue-teardown-integration/build-config.json --phase build --attempt 001` and `py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/796-render-font-and-sim-queue-teardown-integration/acceptance.json`.

Bounds: `793` reuses `005dec08` ops[5] and shared diagnostics (`00573a90`/`00573ab0`/`00573ae0` supplemented in `793/original-index-supplement.json`); `794` uses bounded mock file/bank/heap/callback stubs and CRT `std::puts`; live renderer, audio hardware, startup, and gameplay remain open.
