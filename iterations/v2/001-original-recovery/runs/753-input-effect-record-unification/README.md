# Run753 input effect record unification

Run753 provides three drop-in translation-unit replacements that remove the
independent packed `frame_control_slot_fields_494[32]` storage and make all six
compiled consumers use canonical Run688 `frame_control_effects_0069cb10[32]`:

- `render_resource_494_record_unified_753.cpp` replaces Run494
  `render_resource_494.cpp` (`005338d0` changed);
- `startup_input_slot_math_676_record_unified_753.cpp` replaces Run676
  `startup_input_slot_math_676.cpp` (`00533480` changed);
- `input_ff_slot_render_680_record_unified_753.cpp` replaces Run680
  `input_ff_slot_render_680.cpp` (`005337e0`, `00533730`, `00533760`, and
  `00533120` changed).

Accepted Run494/676/680 files are untouched. Unchanged functions are retained
in the replacement copies with their accepted algorithms. The six changed
bodies now address `FeEffectEntry::field_80`, `effect_object_88`, and
`input_slot_8c` at original offsets `+0x80/+0x88/+0x8c`, with `0x90` between
records. No Run753 source defines `frame_control_slot_fields_494`.

## Original evidence and ABI

The binary index and REA attempt `002` pin all six complete original bodies in
`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
REA attempt `001` preserves a sandbox `spawn EPERM`; read-only audit of attempt
`002` passes for all six dossiers.

- `005338d0`, 53B, `cdecl1 void`;
- `00533480`, 82B, `cdecl1 void`;
- `005337e0`, 41B, `cdecl1 void`;
- `00533730`, 40B, `cdecl0 int32`;
- `00533760`, 64B, `cdecl1 void`;
- `00533120`, 60B, `cdecl1 uint32`.

## Native proof

Attempt `003` passes `/Od` and `/O2`: 139 cases per variant, cdecl ABI, original
production zero bytes, all 10 material mutations, full-record preservation,
callback ordering/mutation, slot `0/1/31` and signed bounds, first-free scans,
download state-to-device routing, and reset return propagation. The lifecycle
cases compose accepted Run688 create with migrated release/unload/download/
stop/reset and Run752 cleanup in three different orders.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/753-input-effect-record-unification/native-config.json --attempt 003
```

Receipt:
`local/experiments/v2-input-effect-record-unification-753/003/receipt.json`,
SHA-256 `1efde2d09a8934a32acc790def264839a280cb3bfc73186bee0cebf8e9541b02`.

Attempts are preserved: `001` found a fixture namespace qualification error;
`002` passed 130 individual cases before a lifecycle callback created an
invalid occupied/null-effect fixture record; `003` repairs that controlled
fixture state. Neither earlier attempt exposed a target-body mismatch.

`dumpbin /symbols` over attempt `003` objects finds zero references or
definitions of `frame_control_slot_fields_494`. The three replacement objects
and Run752 reference `frame_control_effects_0069cb10`; Run688 `od-3.obj` is its
single definition.

## Boundary

This packet does not edit shared CMake, registry, plans, status, or accepted
sources. The coordinator must replace the three old source paths together;
linking old and replacement translation units simultaneously would duplicate
function symbols. Controlled COM transport is not live DirectInput/hardware,
startup, or gameplay acceptance.
