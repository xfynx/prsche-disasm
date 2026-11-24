# Run800 scene route spec and texture descriptor integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding `795/002` (`00475c80`, `00475a60`, `276B .bss`) and `799/002` (`0044d7e0`, `0044d710`, `160B .data`) onto `Run796`: `461` TUs / 8 projects, **81 unresolved names / 91 references** (`2` closed, `1` new `005557d0`), `150` native comparisons, `20` mutations, `1,137` source pins, `2` REA sessions, `436B` new writable data (`276B .bss` + `160B .data`), registry `1,311` (`+4`), no EXE.

Commands: `$env:MSBUILDDISABLENODEREUSE='1'; py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/800-scene-route-and-texture-integration/build-config.json --phase build --attempt 001` and `py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/800-scene-route-and-texture-integration/acceptance.json`.

Bounds: `795` bounds `spec_index < 4` in file fixtures (`00628a20+0x08` mirrors `00628a28`); `799` leaves `005557d0` (`415B`) open; live renderer, startup, and gameplay remain open.
