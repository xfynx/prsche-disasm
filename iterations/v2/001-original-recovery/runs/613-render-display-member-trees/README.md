# Run613 render display member trees (`00466380`, `0044b1d0`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::render_display_member_raw_00466380` / `porsche::render_display_member_00466380` (`00466380..004664f3`, 372B, sha256 `8e0f96c472cc39f82c45d00b7f652363e4ae972c45514e4bd7d370589a02b06a`)
- `porsche::render_display_tree_ctor_0044b1d0` (`0044b1d0..0044b246`, 119B, sha256 `1893c427a2ba7baf2e21914445e8d71a23d1941638d07989f77e2a0617ff31cd`)

Zero owned `.data` or `.rdata` bytes; reuses canonical declarations from `porsche/render_objects.hpp`, `porsche/render_startup.hpp`, `porsche/context_services.hpp`, `porsche/application_context_base.hpp`, `porsche/context_effects.hpp`, and `porsche/heap.hpp`.

## Verification

- Attempt `002` (`local/experiments/v2-render-display-member-trees-613/002/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/613-render-display-member-trees/native-config.json --attempt 002`
  - `/Od` and `/O2` compiled cleanly (`/W4`) and printed `render_display_member_trees_original_x86_vs_cpp=PASS cases=570 events=20962`, matching relocated original x86 against C++ (`__fastcall` and `__cdecl`) across direct `0044b1d0` tests (empty/partial/non-empty pool, lock/head mutation modes, flag bytes) and all 256 8-bit allocation masks (`0x00..0xff`) for `00466380`.
  - Mutation controls (`wrong-pool-slot-arg`, `wrong-tree-flag-copy`, `wrong-node-sentinel-link`, `wrong-member-offset-order`) all exited `1` on `divergence`.
  - Note: Attempt `001` failed fixture compilation due to a missing `#include <initializer_list>`; fixed and verified in attempt `002`.

## Boundaries

Bounded test domain uses deterministic test arenas and providers for `render_allocate_0059ef90`, `context_identity_00423610`, `application_context_heap_state_005e4fe8`, `heap_enter_005322b0`, `heap_leave_005322c0`, and `application_context_new_head_0059eeb0`. Null `self`/`flag_ptr`/heap-state pointers, pool refill failure, and production CMake/registry integration remain open.
