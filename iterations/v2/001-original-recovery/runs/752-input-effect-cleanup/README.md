# Run752 input effect cleanup (`00533050`)

Proof-only recovery of original `Porsche.exe` `00533050..0053309a` (75B,
`__cdecl` no arguments, void), SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The body SHA-256 is
`a8ab87266fcbe0ec203d3249cc2a6dc509859c9f7f4b97c8e17d7372809a686f`.

The binary-index query and raw assembly establish this order:

1. Return when `.bss` cell `0069dd10` is zero.
2. Scan 32 canonical Run688 `FeEffectEntry` records at `0069cb10`, stride
   `0x90`. For every record whose signed `input_slot_8c` is not `-1`, call
   `effect_object_88` through vtable `+0x08` (`__stdcall`, one object argument).
3. Scan indices `0..31`, call accepted-contract `00532b50(i)`, and call the
   controlled child `005331a0(i)` only for a nonzero result.

`input_effects_initialized_0069dd10` is the zero-initialized 4B cell immediately
after Run688's full record array. Original `00533020` is its sole writer: it
initializes every record `+0x8c` to `-1` and then writes the cell to `1`.
Run752 does not recover that initializer or the `005331a0` child.

## Native proof

Attempt `001` passes `/Od` and `/O2` with 720 cases per variant and all six
material mutations detected. Cases cover zero/nonzero initialization gates,
empty/full/alternating/edge record occupancy, records `0` and `31`, effect
vtable `+0x08`, callback mutations of later record state/object/vtable, all 32
`00532b50` calls, dynamic availability mutations, conditional `005331a0` calls,
full record/object/availability state, call order, and cdecl callee-saved/ESP
preservation. Production bytes for `0069cb10..0069dd13` are checked before
fixture seeding.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/752-input-effect-cleanup/native-config.json --attempt 001
```

Receipt:
`local/experiments/v2-input-effect-cleanup-752/001/receipt.json` (SHA-256
`28f5bcdb65e374f1eb7d4c26ac024d0c2051e2baa110f0d34127112d86603a6a`).

## Integration gate

This source is deliberately outside CMake and the recovery registry. Run494
defines `frame_control_slot_fields_494[32]` as a packed host array with 12 bytes
per entry. The original cells are instead Run688 record offsets
`+0x80/+0x88/+0x8c` with a `0x90` stride. Packed host entry 1 starts at byte
12; original record 1's cells start at byte `0x90`. The two compiled arrays are
therefore independent storages, even though both proofs label the same original
VAs.

Before binding `00533050`, replacement sources must make these accepted bodies
use Run688 `FeEffectEntry` storage and reprove them:

- Run494 `005338d0`;
- Run676 `00533480`;
- Run680 `005337e0`, `00533730`, `00533760`, and `00533120`.

The replacement proof must compare interleaved create/release/find/unload/
download/stop/reset/cleanup mutations. Until then Run752 proves only this body
and controlled endpoint transport; it does not establish shared-state fidelity,
live DirectInput behavior, game integration, startup, or gameplay.
