# Run604 render initialize callbacks (`005759f0`)

Bounded native x86-vs-C++ recovery proof for `porsche::render_initialize_callbacks_005759f0`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `005759f0..00575a1a` (43 bytes, sha256 `9d035527fbf1e5fd9be53dccc97879658db1d8f64fd206f18975d251f5b348f2`)
- Owned loader-zero `.data` DWORD (`0x006a64c0`, 4 bytes): `render_saved_display_hook_006a64c0`
- Reused `porsche::render_thrash_exports_006bd910[43]` (`porsche/render_loader.hpp`):
  - `render_thrash_exports_006bd910[27]` (`0x006bd97c`)
  - `render_thrash_exports_006bd910[40]` (`0x006bd9b0`)

## Verification

- Attempt `001` (`local/experiments/v2-render-initialize-callbacks-604/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/604-render-initialize-callbacks/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `render_initialize_callbacks_original_x86_vs_cpp=PASS cases=34 events=34`,
    comparing relocated original x86 against C++ across zero and nonzero
    `render_saved_display_hook_006a64c0`, varied `slot[40]` values, and callback-time mutations
    of `render_saved_display_hook_006a64c0` and `slot[40]`, checking ABI, callback args, state,
    and `FXSAVE`/MXCSR.
  - Mutation controls (`omit-set-state-call`, `wrong-set-state-key`, `wrong-hook-guard-polarity`,
    `wrong-display-hook-constant`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain covers zero and nonzero `render_saved_display_hook_006a64c0`, varied
`render_thrash_exports_006bd910[40]` values, and callback-time mutations during the
`__stdcall` `slot[27]` call using a controlled recording stub. Real THRASH DLL `set_state`
behavior, invocations of callback literals `0x00575a20` and `0x00575980`, external
readers/writers of `0x006a64c0` (such as `005759b2`), null/invalid `slot[27]` faults,
and production CMake/registry integration remain open.
