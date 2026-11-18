# Run671 font state and vec3 distance (`0053eea0`, `0053e890`, `00532b20`, `005323a0`)

Bounded native x86-vs-C++ recovery proof for the 4-function font-attribute / vec3 packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 334 code bytes total):
- `porsche::font_state_set_pair_0053eea0` (`0053eea0..0053eeb2`, 19B, `__cdecl`, sha256 `a3d4b616b5258f5ebd03c00b4a88f9a39725dacca3a27036c7232f640306eafc`): stores `uint32_t` `first` at `obj + 0x3c` and `second` at `obj + 0x40`.
- `porsche::font_setstatef_0053e890` (`0053e890..0053e970`, 225B, `__cdecl`, sha256 `6ff0b47c2bac0a460d1925287e5b1a28651d97376e6028be72c1a07403fca8d1`, switch tables `0053e974..0053e99f` 44B and `0053e9a0..0053e9b6` 23B): sets float32 fields at `+0xb0` (state `1`), `+0xb4` (`2`), `+0xb8` (`3`), `+0xd0..+0xe4` (`18..23`), computes x87 `fdivr` (`value / *(float*)(font + 0xb8)`) rounded to float32 and `fistp` -> `int32_t` at `+0x14` (state `4`), and on invalid state (`< 1`, `5..17`, `> 23`) sets `005deb74 = "\\real\\cmn\\fontattr.c"` and `005deb78 = 0xf1` before calling two-arg `diagnostic_handler_005debf0` with `005bbb44` and `state`.
- `porsche::vec3_length_00532b20` (`00532b20..00532b44`, 37B, `__cdecl`, sha256 `41995978f9ba56c2ba1825360f8ed8a2c3df8d802a0c05775dabeba0a5dffb17`): computes x87 `sqrt((v[0]*v[0] + v[1]*v[1]) + v[2]*v[2])` in x87 precision and returns `float` in `ST(0)`.
- `porsche::vec3_distance_005323a0` (`005323a0..005323d4`, 53B, `__cdecl`, sha256 `24c4867be39ac156fd69cedb2a42fccc6d853ee113b8523d64d2262675e3737a`): computes float32 differences `diff[i] = b[i] - a[i]` (`i = 0..2`) and returns `vec3_length_00532b20(diff)`.

Owned `.data` / `.rdata` and reused canonical symbols:
- Owned `.rdata`: `porsche::font_setstatef_invalid_state_005bbb44[35]` (`005bbb44..005bbb66`, 35B `"FONT_setstatef - Invalid state %d\n"`, sha256 `16d0ed2fe17fb7db4ea06a49027420ec05649ecbb36e570fa1219bd5527ec247`, single ref at `0053e94d` inside `0053e890`).
- Reused `.rdata` string (not exclusively owned here): `"\\real\\cmn\\fontattr.c"` (`005bbb08..005bbb1c`, 21B, sha256 `a684a389a9349a379c1bd86709775fb58b666a0c709ded536120819cd7da1882`, shared across `0053e5c0`, `0053e890`, `0053e9c0`, `0053ebd0` in `references.jsonl`, zero prior owner in `source/`).
- Reused canonical symbols: `diagnostic_file_005deb74_set` and `diagnostic_line_005deb78` (`porsche/shared_runtime_globals.hpp`), and `diagnostic_handler_005debf0` (`porsche/files.hpp`).
- Owned `.data`: none.

## Verification

- Attempt `001` failed before execution on a fixture relocation offset typo (`0xd0u` vs `0xceu` for `005deb78` inside `0053e890`); preserved intact under `local/experiments/v2-font-state-vec3-671/001/`.
- Attempt `002` (`local/experiments/v2-font-state-vec3-671/002/receipt.json`, sha256 `ba79ac4bbc9274e26b025d2d5261c3c87226b6b58560a6b4a8559d3799ff39`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `font_state_vec3_671.cpp`, 66 cases covering `0053eea0` pairs, `0053e890` states `-2..25`, `INT32_MAX`/`INT32_MIN`, IEEE special bits, case 4 `fdivr`+`fistp` halfway ties/div-by-zero/overflow/CW rounding modes, `00532b20` lengths including `1e20f` / `1e-25f` / PC=53-bit, and `005323a0` distances; 20/20 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/671-font-state-and-vec3-dist/native-config.json --attempt 002`

## Boundaries

Bounded test domain (`PARTIAL`): covers controlled font/vec3 arenas, deterministic `diagnostic_handler_005debf0` stub, exact float32 bit comparisons, and clean x87 stack checks. Null/unmapped pointer faults, unrounded 80-bit `ST(0)` precision observed by callers beyond float32 return, non-default x87 rounding/NaN payload differences in `005323a0` subtraction / `0053e890` stores, non-returning diagnostic handlers, and production CMake/registry integration remain open.
