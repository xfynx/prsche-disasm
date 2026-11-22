# Run 746: View Teardown Reset (`00466500` Cluster)

## Scope

Additive recovery of `porsche::view_teardown_reset_00466500` (`?view_teardown_reset_00466500@porsche@@YIXPAX0@Z` from `runs/735-scene-audio-render-integration/build-003.json`) and its four RB-tree clear / node-release helpers in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00466500..00466653` (`340B`): `porsche::view_teardown_reset_00466500` (`__thiscall`, `RET 0`) — tears down the 8 tree slots of a 32-byte view structure in original slot order (`+0x00, +0x14, +0x0c, +0x08, +0x10, +0x04, +0x18, +0x1c`), returning each tree sentinel via `application_context_clear_004237d0(head, 0x20, 0)` and freeing each tree struct via `application_release_0059f050(tree)`.
- `00466c30..00466c9c` (`109B`): `porsche::scene_tree_clear_a_00466c30` (`__thiscall`, `RET 0`) — clears tree using `00466d10` and resets sentinel head (`+0x08=head, +0x04=0, +0x0c=head`) and count (`+0x04=0`).
- `00466ca0..00466d0c` (`109B`): `porsche::scene_tree_clear_b_00466ca0` (`__thiscall`, `RET 0`) — clears tree using `00466d60` and resets sentinel head and count.
- `00466d10..00466d5e` (`79B`): `porsche::scene_tree_nodes_release_a_00466d10` (`__thiscall`, `RET 4`) — post-order recursive (`+0x0c`) and left-tail (`+0x08`) node reclamation into context free list `[ctx + 0x40]` under `[ctx + 0x28]`.
- `00466d60..00466dae` (`79B`): `porsche::scene_tree_nodes_release_b_00466d60` (`__thiscall`, `RET 4`) — second instantiation of the same node reclamation helper.

All external callees and data globals (`005e4fe8`, `004237d0`, `0059f050`, `005322b0`, `005322c0`) are already recovered in canonical sources.

## Evidence & Commands

- REA session:
  `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/746-view-teardown-reset/rea/queries.json --attempt 001`
  `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/746-view-teardown-reset/rea/queries.json --attempt 001`
  Validation: `iterations/v2/001-original-recovery/runs/746-view-teardown-reset/rea/validation.json` (`passed: true`, 5 dossiers).
- Native differential verification (`/Od` + `/O2`, `35` cases/variant, `11/11` mutations killed):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/746-view-teardown-reset/native-config.json --attempt 002`
  Receipt: `local/experiments/v2-view-teardown-reset-746/002/receipt.json` (`status: PASS`).
