# Run804 render mode selection and sim audio VIV startup integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding `797/002` (`00538b30` + 11 setters, `8B .data`) and `798/007` (`004affd0`, `005665b0`, `175B` literals across `005d1d60..005d1e29` / `202B` PE span + `14B .bss`) onto `Run800`: `463` TUs / 8 projects, **79 unresolved names / 89 references** (`2` closed, `0` new), `264` native comparisons, `21` mutations, `1,142` source pins, `2` REA sessions, registry `1,325` (`+14`), no EXE.

Commands: `$env:MSBUILDDISABLENODEREUSE='1'; py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/804-render-mode-and-sim-startup-integration/build-config.json --phase build --attempt 001` and `py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/804-render-mode-and-sim-startup-integration/acceptance.json`.

Bounds: `797` supplements `00538b30` in `797/original-index-supplement.json`; `798` bounds synthetic BIG/BIGH v1/v2 payloads and controlled loader/alloc/free stubs (`005a177b` -> `std::printf`); live renderer, audio hardware, startup, and gameplay remain open.
