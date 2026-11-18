# Run686 render palette conversion leaves (`005702a0`, `00570920`, `00570990`, `00570ff0`, `00571160`)

Bounded native x86-vs-C++ recovery proof for the 5-function render/palette conversion leaf packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 533 code bytes total):
- `porsche::render_palette_565_to_1555_005702a0` (`005702a0..005702e3`, 68B, `__cdecl`, leaf, sha256 `a85aaaaadbc9a0ed417f4b56f2553f102979942eabd780dfcdccd0601a3adb97`): converts `count` 16-bit RGB565 entries to ARGB1555 (`0u` -> `0u`, else `0x8000u | ((v >> 1) & 0xffe0u) | (v & 0x1fu)`).
- `porsche::render_palette_a555_to_8888_00570920` (`00570920..00570985`, 102B, `__cdecl`, leaf, sha256 `1f11fee70c3f52dc5865807f277b3fc6d324870d73a3b63d9d2550dfce931c1c`): expands `count` 32-bit entries preserving bits `[31:24]` and expanding RGB555 bits `[14:0]` to 8-8-8 via `(c5 << 3) | (c5 >> 2)` (ignoring bits `[23:15]`).
- `porsche::render_palette_a565_to_8888_00570990` (`00570990..005709f4`, 101B, `__cdecl`, leaf, sha256 `3f94c5932e0e43f6111f90afe34e17559743d9dc26e772fa2c2830dd7677ea19`): expands `count` 32-bit entries preserving bits `[31:24]` and expanding RGB565 bits `[15:0]` to 8-8-8 via `(c5 << 3) | (c5 >> 2)` and `(c6 << 2) | (c6 >> 4)` (ignoring bits `[23:16]`).
- `porsche::render_palette_vga6_to_8888_00570ff0` (`00570ff0..005710a7`, 184B, `__cdecl`, leaf, sha256 `d9e8948b93fe6a1330e2b2754cf3cc4613b0095abd2a0ffe8be207fdc80a1bcf`): scales `count` 3-byte VGA RGB triplets via `(c * 255 + 32) / 63` (truncated to `uint8_t`) into 4-byte BGRA entries with alpha `0xffu` (`0x00u` at index `255`), preserving original per-channel read/write order.
- `porsche::render_palette_rgb24_to_8888_00571160` (`00571160..005711ad`, 78B, `__cdecl`, leaf, sha256 `0db3819527e2e6e4db943bbbbdb8c6a4232c94bfdc43e216da40a8db9987644d`): packs `count` 3-byte RGB triplets into 4-byte BGRA entries with alpha `0xffu` (`0x00u` at index `255`), preserving original per-channel read/write order.

Owned `.data` / `.rdata` / `.bss`:
- None: all 5 functions are pure arithmetic/copy leaves with zero callees and zero `.data`/`.rdata`/`.bss` accesses (`.data` references at `005de364` and `005de378` are external table entries pointing to `005702a0`).

## Verification

- Attempt `001` (`local/experiments/v2-render-palette-convert-686/001`, preserved): failed on `case=114` (`00570ff0` `kDstAhead1` overlap), exposing `dst[4*i+2]`/`dst[4*i+1]` writes occurring before `src[3*i+1]`/`src[3*i+2]` reads in C++ vs the original instruction schedule.
- Attempt `002` (`local/experiments/v2-render-palette-convert-686/002/receipt.json`, sha256 `5dbd2a66bde05b5cf469c5d24dd072251ec530fa6db4c168ecf7403e96378665`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `render_palette_convert_686.cpp`, 206 cases per optimization / 412 total; 23/23 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/686-render-palette-convert-leaf-table/native-config.json --attempt 002`

## Boundaries

Bounded test domain (`PARTIAL`): covers positive counts up to `260` (crossing the index `255` alpha threshold in `00570ff0` and `00571160`), non-positive counts (`INT32_MIN`, `-1`, `0`), single-bit/inverted-bit/ignored-middle-bit/byte-`0..255` walks, guard canaries before and after destination buffers, and in-place/overlapping buffer aliasing. Null/unmapped `src` or `dst` pointers, huge counts overflowing 32-bit pointer offsets, concurrent mutation, and production CMake/registry integration remain open.
