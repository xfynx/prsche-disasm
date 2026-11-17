# Run590 game setup object init

Recover original `00403520..004035d7` (184 bytes, sha256
`93e8d85755e402fbdae93e54d541b0bdd18359f3cb5c4efe32e015b9a814b4e4`) as
`porsche::game_setup_object_init_raw_00403520` and `porsche::game_setup_object_init_00403520`,
reusing canonical `porsche/game_setup.hpp` and `porsche/context_effects.hpp` declarations.
Evidence is cached in `local/experiments/v2-frontier-469-rea/001/function-00403520.json` and
summarized in `scope-evidence.json`.

## Status

- Implemented `game_setup_object_init_590.hpp`/`.cpp`, `native-fixture.cpp.in`, and
  `native-config.json`.
- Passed attempt `001` (`local/experiments/v2-game-setup-object-init-590/001/receipt.json`):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/590-game-setup-object-init/native-config.json --attempt 001`
  (`/Od` and `/O2` passed 10 cases; all 4 mutation controls detected with exit 1).

Next step: integrate `game_setup_object_init_590.cpp` into production build/registry in a
follow-up integration run.
