# Run614 splash release stack (`0048d550`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::splash_progress_release_stack_0048d550` (`0048d550..0048d691`, 322B, sha256 `8f8080be41157bdfca4d2fc4acd538761b8e2178617eef084a3d16d4128ad02d`)

Reuses canonical declarations (`porsche/splash_progress.hpp`, `porsche/startup_services.hpp`, `porsche/fe_stream.hpp`, `porsche/heap.hpp`) with zero new `.data` or `.rdata` bytes.

## Verification

- Attempt `001` (`local/experiments/v2-splash-release-stack-614/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/614-splash-release-stack/native-config.json --attempt 001`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `splash_release_stack_original_x86_vs_cpp=PASS cases=100 events=531`, comparing relocated original x86 against C++ across entry guards, single/multi-record stacks, `0xf0`/`4` flush boundaries, and mid-loop `vtbl[0]`/`005323e0` state mutations.
  - Mutation controls (`wrong-overflow-limit`, `wrong-pre-send-min`, `wrong-post-send-min`, `wrong-byte-len-shift`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `startup_network_00628c70`, `fe_record_words_004b4cd0`, `heap_copy_dispatch_005323e0`, and transport vtable slot 0. Null `stack` pointers, null `startup_network_00628c70` reloads inside `vtbl[0]` or `005323e0`, negative/out-of-bounds record word counts, and production CMake/registry integration remain open.
