# Run611 splash sprite horizontal flip (`00563320`, `0056e2a8`, `005712f0`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::splash_progress_update_sprite_00563320` (`00563320..0056343d`, 286B, sha256 `48483524cca2ef9a8bbd29364a1054ab3fd3594f4d7e43bf4e1b285504e3dace`)
- `porsche::render_buffer_read_word_0056e2a8` (`0056e2a8..0056e2bf`, 24B, sha256 `a9c10bb3ae44528ab961d3026ab3f81c24f5a1b670d66e610ffe5202323c337f`)
- `porsche::splash_shape_row_stride_005712f0` (`005712f0..00571320`, 49B, sha256 `4f8f9547765a6535b98a0d3292121df2a8b5113e237b22ea120ce78653d39fa2`)

Owned read-only `.rdata` strings (126 bytes total):
- `splash_hflip_bits_fmt_005bced8[47]` (`0x005bced8..0x005bcf06`)
- `splash_hflip_packed_fmt_005bcf08[61]` (`0x005bcf08..0x005bcf44`)
- `splash_hflip_file_005bcf48[18]` (`0x005bcf48..0x005bcf59`)

## Verification

- Attempt `002` (`local/experiments/v2-splash-sprite-horizflip-611/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/611-splash-sprite-horizflip/native-config.json --attempt 002`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `splash_sprite_horizflip_original_x86_vs_cpp=PASS cases=440 events=1696`, comparing relocated original x86 against C++ across all 3 functions (ABI checks, full buffer/diagnostic state snapshots, and event traces).
  - Mutation controls (`wrong-read-word-shift`, `wrong-stride-15bpp-check`, `wrong-packed-flag-mask`, `wrong-anchor-x-sign`) all exited `1` on `divergence`.
  - Note: Attempt `001` (`local/experiments/v2-splash-sprite-horizflip-611/001`) passed `/Od`, `/O2`, and 3 mutations before encountering Windows UAC `WinError 740` on the unmanifested 4th mutation executable containing `update` in its filename; renamed to `wrong-anchor-x-sign` for attempt `002`.

## Boundaries

Bounded test domain uses test-only storage and providers for `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`, `diagnostic_handler_005debf0`, `render_descriptor_bits_00537f90`, and `render_buffer_word_0056e301`. Null pointers, non-returning diagnostic handlers, out-of-bounds shape buffers, negative bpp, and production CMake/registry integration remain open.
