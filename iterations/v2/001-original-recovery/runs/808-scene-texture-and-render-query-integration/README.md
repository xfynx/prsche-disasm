# Run808 scene texture shrink and render driver query integration

Shared integration PASS (`build-002` + `audit-v2-native-game-batch.py`) folding `801/004` (`005557d0`, `00574c70`, `0B` data) and `802/002` (`00556d20`, `00557240`, `13B .rdata` `005cf80c`/`005cf814`) onto `Run804`: `465` TUs / 8 projects, **77 unresolved names / 87 references** (`2` closed, `0` new), `418` native comparisons, `20` mutations, `1,147` source pins, `2` REA sessions, registry `1,329` (`+4`), no EXE.

Commands: `$env:MSBUILDDISABLENODEREUSE='1'; py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/808-scene-texture-and-render-query-integration/build-config.json --phase build --attempt 002` and `py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/808-scene-texture-and-render-query-integration/acceptance.json`.

Bounds: `801` adds `375-texture-constructor` include path for `texture_constructor.hpp` and bounds valid format codes; `802` supplements `00556d20` in `802/original-index-supplement.json`; live renderer, startup, and gameplay remain open.
