# Run605 render driver context mode (`00549220`, `005381d0`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_driver_context_mode_00549220`
and `porsche::render_driver_shift_bias_005381d0` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00549220..005492ed` (206 bytes, sha256 `7b7b61e0e3be7e2f30dddf2272d1aa8e804b5ab1bbd31f16d305a8655b01154a`)
- `005381d0..00538222` (83 bytes, sha256 `f4af57344683d0fa91792730db76c6f0f56a82700a5b535ec9ccd9ebfe85ae96`)
- Owned file-backed `.data` DWORDs (`0x005dea60`, `0x005dea78`, 8 bytes total):
  - `render_driver_exp_bias_005dea60 = 0x00800000`
  - `render_driver_exp_dirty_005dea78 = 0xffffffffu`

## Verification

- Attempt `001` (`local/experiments/v2-render-driver-context-mode-605/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/605-render-driver-context-mode/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `render_driver_context_mode_original_x86_vs_cpp=PASS cases=377 events=322`,
    comparing relocated original x86 against C++ for both `render_driver_shift_bias_005381d0` (216
    cases across negative, `0..16`, and `> 16` shifts and varied initial `005dea60`/`005dea78`) and
    `render_driver_context_mode_00549220` (161 cases across `[0x6bd97c]` failure vs success,
    `mode` indices `0..3`, `<`/`==`/`>`/NaN float comparisons against `1.5f`-scaled mode dimensions,
    and `[0x6bd934]` about strings `"DX7"` vs non-matching), verifying ABI, `self` prefix/suffix
    preservation, `self+0x117e4`/`self+0x117e8`, owned `.data` globals, and `FXSAVE`/MXCSR.
  - Mutation controls (`wrong-negative-shift-limit`, `wrong-flag-10000`, `wrong-dx7-char`,
    `wrong-shift-float-power`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `render_thrash_exports_006bd910`,
`game_setup_movie_service_0069ed0c` (modes `0..3`), and `audio_mixer_gain_scale_005b246c`
(`1.5f`). Out-of-range mode indices, null service/self pointers, arbitrary aliases, and
production CMake/registry integration remain open.
