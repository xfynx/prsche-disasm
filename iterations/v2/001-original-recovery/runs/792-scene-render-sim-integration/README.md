# Run792 scene, font glyphs, sim queue, and sky texture integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding `786/004` (`00452120` + 6 leaves, `8B .bss`), `789/002` (`00594980` + 4 leaves, `0B`), `790/004` (`004a8570` + 4 leaves, `2140B .bss`), and `791/003` (`0044da10` + 3 leaves, `64B .data`) onto `Run788`: `457` TUs / 8 projects, **85 unresolved names / 94 references** (`3` closed, `1` new `0044d7e0`), `216` native comparisons, `41` mutations, `1,127` source pins, `4` REA sessions, `2,212B` new writable data (`2,148B .bss` + `64B .data`), registry `1,295` (`+21`), no EXE.

Commands: `$env:MSBUILDDISABLENODEREUSE='1'; py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/792-scene-render-sim-integration/build-config.json --phase build --attempt 001` and `py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/792-scene-render-sim-integration/acceptance.json`.

Bounds: `786` bounds 40 sky slots; `789` bounds `w0+w1 > 0`; `790` bounds 5 queue banks (`004af970`/`004afd30`/`004afe50`/`004b0a20` external); `791` leaves `0044d7e0` (`434B`) open; live renderer/DirectSound/startup/gameplay remain open.
