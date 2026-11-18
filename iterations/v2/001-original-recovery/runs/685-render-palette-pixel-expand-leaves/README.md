# Run685 render palette pixel-expand leaves (`00570260`, `00570330`, `00570370`, `005704c0`, `00570510`, `00570540`)

Bounded native x86-vs-C++ recovery proof for the 6-function render palette/pixel-expand leaves packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 370 code bytes total):
- `porsche::render_palette_swap_rb555_00570260` (`00570260..0057029e`, 63B, `__cdecl`, leaf, sha256 `ddd0335dcb5338d4eee4c1193354c8af77c8427821a357839f732a01936610aa`): swaps the 5-bit red and blue fields of `count` 16-bit RGB555/BGR555 entries (`((v & 0x001fu) << 10) | (v & 0x03e0u) | ((v >> 10) & 0x001fu)`), clearing bit 15.
- `porsche::render_palette_8888_to_1555_alpha_00570330` (`00570330..00570367`, 56B, `__cdecl`, sha256 `db92c2570ded33b1ef24ee2dc22422ca7ccba9baf767dfc6a49633e2545284da`): for `count` 32-bit pixels, writes `0u` without calling `00572f5b` when unsigned `color < 0x40000000u`, otherwise calls `render_color_888_to_1555_00572f5b(color)`.
- `porsche::render_palette_888_to_1555_00570370` (`00570370..0057039d`, 46B, `__cdecl`, sha256 `362cc543be4b08e7c0ec91637cd6b8b7c5cbfa598fb1705ad17963770b62d712`): unconditionally converts `count` 32-bit pixels via `render_color_888_to_1555_00572f5b(src[i])`.
- `porsche::render_palette_8888_to_565_alpha_005704c0` (`005704c0..00570503`, 68B, `__cdecl`, sha256 `ec6508bf7ce51b547797459a32a2635dc46e4d48431de42e47f26defaf2a0957`): for `count` 32-bit pixels, writes `0u` without calling `00572f30` when unsigned `color < 0x40000000u`, otherwise calls `render_color_888_to_565_00572f30(color)` and promotes a zero 16-bit result (`test ax, ax`) to `1u`.
- `porsche::render_palette_888_to_565_00570510` (`00570510..0057053d`, 46B, `__cdecl`, sha256 `906d12b447b98b7af5b3c8c3d4f1d14252bc7594c39007253422cac0c3b4f550`): unconditionally converts `count` 32-bit pixels via `render_color_888_to_565_00572f30(src[i])`.
- `porsche::render_palette_8888_to_4444_00570540` (`00570540..0057059a`, 91B, `__cdecl`, leaf, sha256 `662da365981aff47cd30ce07576fc8ead540e36a85fbd8f0ae00ad2aa89df290`): packs the high 4 bits of each byte of `count` 32-bit ARGB8888 pixels into 16-bit ARGB4444 (`((color >> 16) & 0xf000u) | ((color >> 12) & 0x0f00u) | ((color >> 8) & 0x00f0u) | ((color >> 4) & 0x000fu)`).

Owned `.data` / `.rdata` / `.bss` and reused canonical symbols:
- Owned `.data` / `.rdata` / `.bss`: none (zero `.data`/`.rdata` references in `references.jsonl` or disassembly for all 6 functions; external `.data` references at `005de358..005de4f4` are table entries pointing to these functions).
- Reused canonical symbols: `render_color_888_to_565_00572f30` and `render_color_888_to_1555_00572f5b` (`../683-input-ff-slot-callers-and-render-leaves/input_ff_render_leaves_683.hpp`).

## Verification

- Attempt `001` (`local/experiments/v2-render-palette-expand-685/001/receipt.json`, sha256 `08f7f8719a675805c3df95c3ea72430b62db49fe17c2e5601b86682dab0ec5fc`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `render_palette_expand_685.cpp`, 324 cases per optimization / 648 total; 24/24 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/685-render-palette-pixel-expand-leaves/native-config.json --attempt 001`

## Boundaries

Bounded test domain (`PARTIAL`): covers `00570260`, `00570330`, `00570370`, `005704c0`, `00570510`, and `00570540` across non-positive and positive counts, full bit-walks, alpha threshold boundaries (`0x3fffffffu` / `0x40000000u` / `>= 0x80000000u`), `005704c0` 16-bit zero-to-`1u` promotion (including upper-16-bit ignore), guard canaries, overlapping/in-place buffers, and controlled `00572f30`/`00572f5b` call-order/argument transport. Null/unmapped `src`/`dst` pointers, arbitrary large counts, real `00572f30`/`00572f5b` body chaining in production link, concurrent mutation, and production CMake/registry integration remain open.
