# Run590 game setup object init (`00403520`)

Bounded native x86-vs-C++ recovery proof for `porsche::game_setup_object_init_raw_00403520`
(`__fastcall`, `ECX=object`, stack `bytes`, `RET 4`) and `porsche::game_setup_object_init_00403520`
(`__cdecl` bridge declared in `porsche/game_setup.hpp`), from `Porsche.exe` SHA
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, body `00403520..004035d7`
(184 bytes, sha256 `93e8d85755e402fbdae93e54d541b0bdd18359f3cb5c4efe32e015b9a814b4e4`).

## Native attempt

- `001` (`local/experiments/v2-game-setup-object-init-590/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/590-game-setup-object-init/native-config.json --attempt 001`
  - Variants: `/Od` and `/O2` both printed `game_setup_object_init_original_x86_vs_cpp=PASS cases=10`
    comparing relocated original `00403520` against both `game_setup_object_init_raw_00403520`
    and `game_setup_object_init_00403520` across `bytes=0xffffffff`, `bytes=0`, `bytes=1..0x100`
    (empty and non-empty pool heads, lock/head mutation on `heap_enter`), `bytes=0x101`, and
    `bytes=0xfffffffe` (32-bit wraparound).
  - Mutation controls: `omit-sentinel-guard`, `wrong-zero-end`, `wrong-large-threshold`, and
    `wrong-kind-shift` all detected (`exit_code=1`, `divergence`).

## Boundaries

Production source/CMake/registry integration, broader caller/consumer semantics, malformed
pointers/faults, and live heap/pool state ownership remain outside this run.
