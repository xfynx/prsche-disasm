# Run 779 — Render Environment & Startup Force-Feedback Init (`00573030`, `004121b0`)

Closes two direct unresolved frontier symbols from `Run761` (`761/build-001.json`) / `Run776` (`5354eba`).

## Recovered Symbols (`Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)

| Symbol | Address Range | Bytes | Code/Data SHA-256 | Role |
|---|---|---:|---|---|
| `?render_environment_00573030@porsche@@YAIPBD0I@Z` | `00573030..00573061` | 50 | `ece7a18deb1439806cd476ba049e57d6f3d401ce539486c7170ac5b19136e0f0` | Formats `"%s=%s"` into a `0x200`-byte stack buffer via `005a0fbf`, calls `005a38c7`, returns `0` |
| `render_environment_fmt_005c0838` | `005c0838..005c083d` | 6 | `e314e7a77a705c9b8f0bd2964f8a80c58552243502340071968cde61ee950694` | Owned `.rdata` `"%s=%s"` format string |
| `?startup_sequence_call_004121b0@porsche@@YAXXZ` | `004121b0..0041222b` | 124 | `c0d36c963c64210155854701d8c80dc91e16758f195b1f7f226242ce211fb110` | Initializes FF via `00411d20`, registers `004123e0` into `00606ad0` via `00414c30` when enabled and `global_00657424 < 2`, and tears down via `00533480` if disabled after insert |
| `startup_frame_tick_table_00606ad0` | `00606ad0..00606ad3` | 4 | — | Owned loader-zero `.bss` pointer cell |

Totals: `174B` executable code (`50B + 124B`), `6B` `.rdata`, `4B` `.bss`.

## Files

- `render_env_startup_ff_779.hpp` / `render_env_startup_ff_779.cpp`
- `scope-evidence.json`
- `rea-queries.json` / `validation.json`
- `native-config.json` / `native-fixture.cpp.in`

## Evidence & Verification

1. **REA**:
   ```powershell
   py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/779-render-env-and-startup-ff/rea-queries.json --attempt 001
   py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/779-render-env-and-startup-ff/rea-queries.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-input-779-rea/001/receipt.json`
   - Dossiers: `function-00573030.json`, `function-004121b0.json`
   - Audit (`validation.json`): `passed: true`, `dossiers: 2`, `repeated_equal: 0`

2. **Native x86-vs-C++ Equivalence (`/Od` and `/O2`)**:
   ```powershell
   py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/779-render-env-and-startup-ff/native-config.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-env-and-startup-ff-779/001/receipt.json` (`status: "PASS"`)
   - Variants: `/Od` and `/O2`, both `render_env_startup_ff_779_original_x86_vs_cpp=PASS cases=63` (`0` failed cases)
   - Mutation controls: `10/10` detected (`exit_code: 7`):
     `wrong-573030-fmt-order`, `wrong-573030-skip-putenv`, `wrong-573030-return-nonzero`, `wrong-4121b0-enabled-gate`, `wrong-4121b0-signed-mode-cmp`, `wrong-4121b0-mode-limit`, `wrong-4121b0-preinsert-state`, `wrong-4121b0-insert-key`, `wrong-4121b0-postinsert-stop`, `wrong-4121b0-clear-fields`

## Scope Boundary (`PARTIAL`)

- Reused canonical symbols: `formatter_entry_005a0fbf`, `ff_effect_initialize_00411d20`, `frame_control_ff_state_005e9408`, `startup_sorted_table_insert_00414c30`, `input_slot_stop_ff_00533480`, `global_00657424`, `application_player_object_table_005e8b34`.
- Explicit typed unrecovered boundaries: `crt_putenv_005a38c7` (`005a38c7`) and `ff_effect_frame_tick_004123e0` (`004123e0`).
