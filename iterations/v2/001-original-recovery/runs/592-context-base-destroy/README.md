# Run592 context base destroy (`00525ec0`)

Bounded native x86-vs-C++ recovery proof for `porsche::application_context_base_destroy_00525ec0`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`,
body `00525ec0..00525f3b`, 124 bytes, sha256
`8c3fc02650c45d6a5a6290e2d0c2780d0a5f0eacdcf6df97db96cf5df900fb54`).

- Attempt `001` (`local/experiments/v2-context-base-destroy-592/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/592-context-base-destroy/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `context_base_destroy_original_x86_vs_cpp=PASS cases=12 events=52`
    comparing relocated original x86 against naked `__fastcall application_context_base_destroy_00525ec0`
    across 4 null-allocation `EAX` seeds (proving incoming `EAX` preservation), `count == 0`,
    empty list with non-zero count, 1/2/3-node lists, sibling `next` and sentinel-pointer mutations
    during `unlink`, `__fastcall` ABI, and `FXSAVE`/MXCSR preservation.
  - Mutation controls (`omit-vtable-store`, `fallthrough-zero-count`, `wrong-member-offset`,
    `wrong-notify-flag`) all exited `1` on `divergence`.

## Boundaries

Controlled test endpoints stand in for canonical `005262e0`, `004e4560`, `004d7da0`, `004237d0`,
and `0059f050`; malformed pointers/faults, arbitrary aliases, production CMake/registry integration,
and unrecovered callee/caller semantics remain open.
