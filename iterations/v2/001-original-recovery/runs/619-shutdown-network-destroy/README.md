# Run619 shutdown network destroy (`0048ff30`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::ShutdownNetwork311::destroy_0048ff30` (`0048ff30..00490139`, 522B, sha256 `83cecaa49d7aba951ea94886c3d3f5148acfa5324ca00cefcb268aa8dc6f6c85`)

Reuses canonical declarations (`shutdown_helpers_311.hpp`, `porsche/startup_services.hpp`, `porsche/application_alloc.hpp`, `porsche/files.hpp`, `porsche/network_lifecycle.hpp`, `porsche/heap_locks.hpp`, `network_callback_drain_488.hpp`, `porsche/application_context_base.hpp`) with zero new `.data` or `.rdata` bytes.

## Verification

- Attempt `001` (`local/experiments/v2-shutdown-network-destroy-619/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/619-shutdown-network-destroy/native-config.json --attempt 001`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `shutdown_network_destroy_original_x86_vs_cpp=PASS cases=44 events=534`, comparing relocated original x86 against C++ across `startup_network_00628c70` null/non-null branches, `[this+0x10]`/`[this+0x18]` null/non-null combinations, all 6 circular doubly-linked list slots (`+0x264`, `+0x260`, `+0x25c`, `+0x258`, `+0x254`, `+0x150`) with 0..3 nodes, mid-call field mutations by `0048e9c0`/`005322d0`, and mid-loop `*head_slot` reload mutations inside `004237d0`.
  - Mutation controls (`wrong-missing-file-reset`, `wrong-lock-box-offset`, `wrong-clear-node-size`, `wrong-list-order`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `startup_network_00628c70`, `missing_file_006afbe4`, `network_lifecycle_reset_0048e9c0`, `heap_lock_destroy_005322d0`, `application_release_0059f050`, `network_callbacks_drain_005603b0`, and `application_context_clear_004237d0`. Null `this` or null list head slot pointers, cross-list aliasing, and production CMake/registry integration remain open.
