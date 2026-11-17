# Run599 render misc cleanup (`00449b40`, `0053f0b0`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_misc_00449b40` and
`porsche::render_cleanup_register_0053f0b0` (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00449b40..00449b67` (40 bytes, sha256 `b9b191b8ab6aa45883a6b8f202868d8ec2ff806078ff7bce86b97e5285bf491b`)
- `0053f0b0..0053f112` (99 bytes, sha256 `dbc5031bd948c1a13a0b7f3390bea9e048436da2d36e12ed38eb5a1a860d33de`)

## Verification

- Attempt `001` (`local/experiments/v2-render-misc-cleanup-599/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/599-render-misc-cleanup/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `render_misc_cleanup_original_x86_vs_cpp=PASS cases=36 events=48`,
    comparing relocated original x86 against C++ for both `render_cleanup_register_0053f0b0`
    and `render_misc_00449b40` across `head == nullptr`, 1-node and 2-node existing lists,
    second-allocation success/failure, `g_alloc_call`, `g_last_alloc_size`, `g_arena[8]`,
    `render_cleanup_head_0069ebb0`, `render_identity_lut_ptr_00619758`, all 256 bytes of
    `render_identity_lut_00618e74`, ABI, and `FXSAVE`/MXCSR.
  - Mutation controls (`wrong-sentinel-callback`, `wrong-first-alloc-size`,
    `wrong-lut-byte-mask`, `wrong-cleanup-callback-va`) all exited `1` on `divergence`.

## Boundaries

Deterministic 8-node test arena stands in for `render_allocate_0059ef90`; first-allocation
null pointer dereference fault (`0053f0b0+0x26`), cleanup callback execution (`00449b70`,
`0053f980`), arbitrary aliases, and production CMake/registry integration remain open.
