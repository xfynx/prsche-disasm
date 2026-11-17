# Run593 render display prevideo (`0044e2c0`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_display_prevideo_0044e2c0`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`,
body `0044e2c0..0044e364`, 165 bytes, sha256
`31b476817095733dd64d11fbd5ff1de498b1439cccac96ecc4652fc87aac047e`).

- Attempt `001` (`local/experiments/v2-render-display-prevideo-593/001/`): failed at compile
  (`C2011` `DisplayModeRecord` redefinition when mixing `render_display_496.hpp` with
  `porsche/render_display.hpp` pulled in by `porsche/render_mode.hpp`).
- Attempt `002` (`local/experiments/v2-render-display-prevideo-593/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/593-render-display-prevideo/native-config.json --attempt 002`
  - `/Od` and `/O2` both printed `render_display_prevideo_original_x86_vs_cpp=PASS cases=640 events=2080`
    comparing relocated original x86 against `porsche::render_display_prevideo_0044e2c0` across
    `display[0x60]` flag values (`0`, `1`, `0x80`, `0xff`), driver `vslot9` mode-table mutation,
    record `+0x28` selection, `0x0f -> 0x10` format normalization, `0x0061979a` (`[0x0a]`) write,
    live width/height reload after `0044e890`/`0044ed10`, alignment offsets `0..3`, ABI, and
    `FXSAVE`/MXCSR checks.
  - Mutation controls (`invert-software-flag-branch`, `wrong-mode-record-offset`,
    `omit-15bit-format-normalize`, `omit-mode-flag-byte-write`) all exited `1` on `divergence`.

## Boundaries

Controlled test storage and callback boundaries stand in for `vslot9`, `0044e890`, `0044ed10`,
and `00537600`; malformed pointers/faults, arbitrary aliases, production CMake/registry integration,
and unrecovered callees (`0044e890`, `00537600`) remain open.
