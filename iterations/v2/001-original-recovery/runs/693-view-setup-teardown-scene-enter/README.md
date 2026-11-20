# Run693 application view lifecycle (`004640b0`, `00467740`, `00468fb0`)

Bounded native x86-vs-C++ recovery proof for the application view-slot setup (004640b0), display teardown (00467740) and scene-enter transfer (00468fb0) packet (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `porsche::application_main_function_004640b0` (`004640b0..004642e3`, 564B, `__cdecl`, sha256 `14afbbc2ec3ef1ab4aba97bb216f197bb2ad658f03569ee6f9bd57b4c2bdb4c4`): fills one or two 0x10c-byte view slots at `0x00627e80`/`0x00627f8c` from the route object selected by arena word `0x0065741c`, rebinds projection pair `0x005cf620..0x005cf62b` and slot tail `0x00627ecc..0x00627ed7`, sets route flag `0x005cf584` from the case-folded compare of arena name buffer `0x00657444` against "castle", then calls `00463c30` and no-op `00516950`.
- `porsche::application_main_function_00467740` (`00467740..004677cc`, 141B, `__cdecl`, sha256 `20ef52a859d751ea47f188295a3c4e7b5b737b1b7adda77dc5ab6554a711d9f9`): display teardown releasing fields 0x7c/0x6c objects via 00538d80/00540420 + allocator 0059f050, device via vtable slot 0 (arg 1), reset sub-objects +0x34/+0x14 via 00466500, release display, clear `0x00628130`, then release core via vtable slot 1 (arg 1).
- `porsche::startup_sequence_call_00468fb0` (`00468fb0..0046909b`, 236B, `__cdecl`, sha256 `3b7479d88e11277e59210d4b69afc8258fe2982bee5a325343696962509ec7fd`): allocates/constructs 0x38-byte scene buffer via 0059ef90/00537700, stores at `0x0062814c`, copies 14 dwords from the pointer stored at display-device field +0x70 offset +0x04, clears `0x00619800`, runs ordered scene stage reset chain, tail-jumps into 004521c0.

Owned data:
- `0x00627e80` 536B two 0x10c view slots; `0x005e8c00` 36B route-object registry (9 cells); `0x005cf620` 12B camera; `0x005cf584` 4B flag; `0x005cf5d8` 1B string byte; `0x005cf760` 7B "castle"; `0x0062814c`, `0x0061976c`, `0x00619800` scene cells.
- Reused canonical owners: `0x00657404`/`0x0065741c`/`0x00657444` arena, `0x00628130` display, `0x0065b39c` core, `0059ef90`/`0059f050` allocators, `00537700`, `0044ed10`, `00516950`, `00536080`, `00555390`, `004a4a70`, `005ae3c0`, `00463c30`.

## Verification

- Attempt `010` (`local/experiments/v2-view-setup-teardown-scene-enter-693/010/receipt.json`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings, 130 cases; 13 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/693-view-setup-teardown-scene-enter/native-config.json --attempt 010`
  - Receipt marker: `application_view_lifecycle_original_x86_vs_cpp=PASS cases=130`

## Boundaries

Bounded test domain (`PARTIAL`): covers view-slot setup across mode in {0,1,2,0x80000000,0x7fffffff}, route indices {0,3,8}, camera bytes {0,2,0xff}, prefill {0,1}, names {"castle","CAStle","harbor-town"} (90 cases); display teardown across display/state_7c/device/state_6c/core presence (32 cases); scene-enter across fail_alloc8 {0,1} x seed {0..3} (8 cases), including second-allocation failure. Null-display dereference, first-allocation failure, null device payload, real device/core vtable acceptance, locale/lock branch of 005ae3c0, and production CMake/registry integration remain open.