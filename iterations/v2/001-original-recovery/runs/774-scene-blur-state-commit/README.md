# Run 774: Scene Blur State Setters & Commit (`00537a30`, `00537a40`, `00537a70`, `00536470`)

## Scope

Additive recovery of the four direct `Run738` scene blur state children (`scene_blur_stage_child_738.hpp`) in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00537a30..00537a38` (`9B`): `porsche::scene_blur_state_quality_00537a30` (`__thiscall`, `RET 4`) — stores `value` at `[self + 0x00]`.
- `00537a40..00537a49` (`10B`): `porsche::scene_blur_state_one_00537a40` (`__thiscall`, `RET 4`) — stores `value` at `[self + 0x04]`.
- `00537a70..00537a7c` (`13B`): `porsche::scene_blur_state_flag_00537a70` (`__thiscall`, `RET 4`) — stores `value` at `[self + 0x14]` and `[self + 0x18]`.
- `00536470..00536505` (`150B`): `porsche::scene_blur_state_commit_00536470` (`__thiscall`, `RET 4`) — copies 28 bytes from `state_28_bytes` to `[self + 0x38..0x53]`, inspects `[0069ed0c]+0x04`, and if `+0x08 == self` (bank 0, pairs `0..6`) or else `+0x0c == self` (bank 1, pairs `7..13`), updates changed cached values in `render_state_flush_records_005de6bc[28]` and invokes the corresponding `__cdecl(key, value)` callback in `render_state_flush_callbacks_005de72c[7]`.

Zero new globals or unresolved child symbols (`0069ed0c`, `005de6bc`, `005de72c` are canonically owned).

## Evidence & Commands

- REA session:
  `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/774-scene-blur-state-commit/rea/queries.json --attempt 001`
  `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/774-scene-blur-state-commit/rea/queries.json --attempt 001`
  Validation: `iterations/v2/001-original-recovery/runs/774-scene-blur-state-commit/rea/validation.json` (`passed: true`, 4 dossiers).
- Native differential verification (`/Od` + `/O2`, `25` cases/variant, `11/11` mutations killed):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/774-scene-blur-state-commit/native-config.json --attempt 002`
  Receipt: `local/experiments/v2-scene-blur-state-commit-774/002/receipt.json` (`status: PASS`).
