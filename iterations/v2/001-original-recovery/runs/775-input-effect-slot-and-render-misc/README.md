# Run 775 — Input Slot Effect Cleanup & Render Secondary Alloc (`005331a0`, `00465df0`)

Closes two direct unresolved frontier symbols from `Run761` (`761/build-001.json`) with zero new `.data`/`.rdata`/`.bss` globals and zero new unresolved game symbols.

## Recovered Symbols (`Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)

| Symbol | Address Range | Bytes | Code SHA-256 | Role |
|---|---|---:|---|---|
| `?input_slot_effect_cleanup_005331a0@porsche@@YAXH@Z` | `005331a0..005331eb` | 76 | `8620ae7652c994d1c3b86c17b408c40f5970fd056972c36c8d6b0d6fe1be5cf9` | Child of `00533050` (`Run752`): gates on `0069cb08` and `00532b50(slot)`, calls `00533120(slot)` and clears bit 0 of `input_slots_006be040[slot].flags_04` when bit 0 is set |
| `?render_misc_00465df0@porsche@@YAXXZ` | `00465df0..00465e15` | 38 | `de15fe8feb9be8912f2b5fa4bacee322c1534a220b952fcc0699451b70cd49a6` | Child of `00467470`: allocates `0x4c` bytes via `0059ef90`, constructs `0059f070` (`Run742`), and stores the result (or `nullptr` on failure) into `0062810c` (`Run701`) |

Totals: `114B` executable code (`76B + 38B`), `0B` new `.data`/`.rdata`/`.bss`, `0` new unresolved symbols.

## Files

- `input_effect_slot_render_misc_775.hpp` / `input_effect_slot_render_misc_775.cpp`
- `scope-evidence.json`
- `rea-queries.json` / `validation.json`
- `native-config.json` / `native-fixture.cpp.in`

## Evidence & Verification

1. **REA**:
   ```powershell
   py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/775-input-effect-slot-and-render-misc/rea-queries.json --attempt 001
   py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/775-input-effect-slot-and-render-misc/rea-queries.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-input-775-rea/001/receipt.json`
   - Dossiers: `function-005331a0.json`, `function-00465df0.json`
   - Audit (`validation.json`): `passed: true`, `dossiers: 2`, `repeated_equal: 0`

2. **Native x86-vs-C++ Equivalence (`/Od` and `/O2`)**:
   ```powershell
   py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/775-input-effect-slot-and-render-misc/native-config.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-input-effect-slot-and-render-misc-775/001/receipt.json` (`status: "PASS"`)
   - Variants: `/Od` and `/O2`, both `input_effect_slot_render_misc_775_original_x86_vs_cpp=PASS cases=96` (`0` failed cases)
   - Mutation controls: `9/9` detected (`exit_code: 7`):
     `wrong-5331a0-root-gate`, `wrong-5331a0-has-device-gate`, `wrong-5331a0-flag-bit`, `wrong-5331a0-skip-reset`, `wrong-5331a0-clear-bit`, `wrong-5331a0-slot-index`, `wrong-465df0-alloc-size`, `wrong-465df0-null-store`, `wrong-465df0-ctor-result`

## Reused Canonical Dependencies

- `input_directinput_0069cb08` (`683-input-ff-slot-callers-and-render-leaves`)
- `input_slots_006be040` (`porsche/input_state.hpp`)
- `input_slot_has_device_00532b50` (`676-startup-input-slot-and-math-leaves`)
- `input_slot_reset_ff_00533120` (`753-input-effect-record-unification` / `680-input-ff-slot-and-render-leaves`)
- `startup_network_allocate_0059ef90` (`application_alloc.cpp`)
- `scene_stage_group_ctor_0059f070` (`742-scene-stage-group-ctor`)
- `render_secondary_object_0062810c` (`701-view-teardown-route-family`)
