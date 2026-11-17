# Run595 startup transfer end (`004691c0` / `00468100`)

Bounded native x86-vs-C++ recovery proof for `porsche::startup_sequence_transfer_004691c0`
(`004691c0..004691ca`, 11 bytes, sha256
`611feffed93f6a3f80fa1c77d856e92f5bade0bf69e5531b2a4189e907913d90`) and
`porsche::render_display_transfer_end_00468100` (`00468100..00468107`, 8 bytes, sha256
`c7eb9fa091e6c7322d0fb94ea902913506561139a707ee74638bd57af08357e4`) in `Porsche.exe`
(`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).

- Attempt `001` (`local/experiments/v2-startup-transfer-end-595/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/595-startup-transfer-end/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `startup_transfer_end_original_x86_vs_cpp=PASS cases=512 events=512`,
    verifying relocated `00468100` (`__fastcall`, `ECX=display`) and `004691c0` (`__cdecl`,
    loading `render_display_00628130` and tail-jumping to `00468100`) across display alignments
    `0..3`, varied/unaligned `[display+0x74]` values (storage offsets `0..3`, null, sentinel),
    `EDX` passthrough, controlled endpoint state mutation, ABI, and `FXSAVE`/MXCSR checks.
  - Mutation controls (`wrong-display-field-offset`, `bypass-transfer-end`,
    `clear-display-global`) all exited `1` on `divergence`.

## Boundaries

Controlled test storage and endpoint stand in for `startup_lifecycle_end_raw_00536050`;
malformed pointers/faults, arbitrary aliases, and production CMake/registry integration remain open.
