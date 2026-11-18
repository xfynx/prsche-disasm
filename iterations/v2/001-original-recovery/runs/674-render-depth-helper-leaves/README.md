# Run674 render depth helper leaves (`005345e0`, `00535340`, `00535360`, `00571490`, `00571520`, `00573070`)

Bounded native x86-vs-C++ recovery proof for the 6-function render depth/chunk/MMX leaf packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 206 code bytes total):
- `porsche::render_shape_type_to_depth_index_005345e0` (`005345e0..00534629`, 74B, `__cdecl`, sha256 `41b4236df6343dc538c6bd6ee1157137b154d79446ee6eea828957da8c5a8422`, jump table `0053462c..0053464f` 36B, lookup table `00534650..005346ce` 127B): maps `shape_type` (`0x01`/`0x40`/`0x7a` -> `0`, `0x02`/`0x41`/`0x7b` -> `1`, `0x03`/`0x7e` -> `2`, `0x04`/`0x78` -> `3`, `0x05`/`0x43`/`0x7f` -> `4`, `0x7d` -> `5`, `0x6d` -> `6`, `0x42` -> `7`, else `-1`).
- `porsche::render_depth_format_index_00535340` (`00535340..00535354`, 21B, `__cdecl`, sha256 `554535f758a38842731221929c2ba39a7cadcb56277bf561b4d9e75e6ddef98b`): unsigned bounds check `< 14u` indexing owned `.data` table `005de574..005de5ab` (56B), returning `-1` when `>= 14u`.
- `porsche::render_depth_level_00535360` (`00535360..00535377`, 24B, `__cdecl`, sha256 `79fc0e7a9db29412118823acb25b5db74e46180c675cdf48da6676c046bfbb98`): signed bounds check `0 <= depth_index < 7` indexing owned `.data` table `005de5ac..005de5c7` (28B), returning `0` when out of range.
- `porsche::render_chunk_size_00571490` (`00571490..005714d5`, 70B, `__cdecl`, sha256 `2b1ba69164682713c228e2561d3e9d05944907e6d1d114dfe8634b5e949f2ccb`, jump table `005714d8..005714df` 8B, lookup table `005714e0..00571516` 55B): checks `header[1]` in `{0xfb, 0x32}` and `(header[0] & 0xfe)` in `{0x10, 0x18, 0x30, 0x32, 0x34, 0x46}`, calling canonical `render_descriptor_read_be_0056e290(header + 2, 3u)` (`../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp`, provider in `540-render-texture-cleanup-reader/render_texture_cleanup_540.cpp`) or returning `0`.
- `porsche::render_chunk_size_wrapper_00571520` (`00571520..0057152d`, 14B, `__cdecl`, sha256 `9c39780d860c34f21f163986074eb501b2639530af158307b6a8d9049bbfed59`): forwards `header` to `00571490` and returns its `uint32_t` result in `EAX`.
- `porsche::render_mmx_empty_00573070` (`00573070..00573072`, 3B, `__cdecl`, sha256 `e9be6a1bee9469387a05d3c4e3932f68ede109bb4bd40ef195bb07003db89bf7`): executes `emms` and returns.

Owned `.data` / `.rdata` and reused canonical symbols:
- Owned `.data`: `porsche::render_depth_format_table_005de574[14]` (`005de574..005de5ab`, 56B, sha256 `ddddfbc86cf721c2f168ee3fbd94a11aba89466d71ba2cb4f27946f7374a9aeb`, single ref at `00535349`), and `porsche::render_depth_level_table_005de5ac[7]` (`005de5ac..005de5c7`, 28B, sha256 `4c816952ba53cc361d8e45bd833338dc6427e4a5d5f06ebad5351fd46439a15a`, single ref at `0053536d`).
- Owned `.rdata`: none.
- Reused canonical symbol: `porsche::render_descriptor_read_be_0056e290` (`0056e290`, declared in `../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp`, defined in `../540-render-texture-cleanup-reader/render_texture_cleanup_540.cpp`).

## Verification

- Attempt `001` failed fixture compilation on braced-init-list range-for without `<initializer_list>`; preserved intact under `local/experiments/v2-render-depth-helpers-674/001/`.
- Attempt `002` passed `/Od` and `/O2` (863 cases) and failed on `wrong-535340-bound-14` (`format_index >= 13u` is equivalent to `>= 14u` because `005de574[13] == -1`); preserved intact under `local/experiments/v2-render-depth-helpers-674/002/`.
- Attempt `003` (`local/experiments/v2-render-depth-helpers-674/003/receipt.json`, sha256 `068c258c5707ee7e13f769c7d4bd2b465de6166db97ecb9888f63050d482da3e`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `render_depth_helpers_674.cpp`, 863 cases covering `005345e0` all 256 byte values + 8 32-bit boundary values, `00535340` `0..16` + 5 boundary values, `00535360` 15 signed boundary values, `00571490` all 512 `(b0, 0xfb/0x32)` pairs + 24 invalid-marker pairs + 32-bit sentinel forwarding, `00571520` 19 wrapper/sentinel cases, and `00573070` 6 x87/MMX `emms` seed states; 21/21 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/674-render-depth-helper-leaves/native-config.json --attempt 003`

## Boundaries

Bounded test domain (`PARTIAL`): covers exhaustive byte-range and 32-bit boundary inputs for `005345e0`, `00535340`, `00535360`, and `00571490`/`00571520`, big-endian 3-byte reads via instrumented/real `0056e290`, sentinel 32-bit return forwarding, and `emms` x87/MMX tag reset via `fxsave`. Null/unmapped header pointer faults, unaligned/page-straddling 4-byte reads inside `0056e290`, concurrent table mutation, and production CMake/registry integration remain open.
