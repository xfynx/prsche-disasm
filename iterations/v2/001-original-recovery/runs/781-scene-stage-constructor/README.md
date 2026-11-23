# Run 781: Scene Stage Flare Constructor (`004522b0`, `004524a0`, `0059ece0`)

## Scope

Additive recovery of `porsche::scene_stage_constructor_004522b0` (`?scene_stage_constructor_004522b0@porsche@@YIPAXPAX0@Z` from `Run776/build-001.json`), `scene_flare_entry_ctor_004524a0`, and `context_table_size_0059ece0` in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `004522b0..00452496` (`487B`): `porsche::scene_stage_constructor_004522b0` (`__thiscall`, `RET 0`) — zeroes `0x328` bytes, formats `%sflare.dat` via `005a0fbf`, opens via `0059d9b0`, parses `0x8c`-byte flare records (or constructs one default `"null"` fallback record when absent), resolves each holder through typed child `00452120`, and packs the pointer array at `[self + 0x00]` via `0059eff0`.
- `004524a0..00452507` (`104B`): `porsche::scene_flare_entry_ctor_004524a0` (`__thiscall`, `RET 4`) — initializes a `0x8c`-byte flare descriptor with `tag`, `100.0f` (`0x42c80000`), `-1` slots, and zeroed trailing fields.
- `0059ece0..0059ecf1` (`18B`): `porsche::context_table_size_0059ece0` (`__cdecl`, `RET 0`) — invokes the context state's `+0x18` size callback.

Zero new data/bss globals; single typed child frontier `scene_flare_entries_resolve_00452120` (`154B`).

## Evidence & Commands

- REA session:
  `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/781-scene-stage-constructor/rea/queries.json --attempt 001`
  `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/781-scene-stage-constructor/rea/queries.json --attempt 001`
  Validation: `iterations/v2/001-original-recovery/runs/781-scene-stage-constructor/rea/validation.json` (`passed: true`, 3 dossiers).
- Native differential verification (`/Od` + `/O2`, `16` cases/variant, `10/10` mutations killed):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/781-scene-stage-constructor/native-config.json --attempt 003`
  Receipt: `local/experiments/v2-scene-stage-constructor-781/003/receipt.json` (`status: PASS`).
