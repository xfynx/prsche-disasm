# Run 782 — Render Driver Calibration & Service Init (`00536870`, `0053c8d0`, `0053c8e0`, `0053d840`)

Closes two direct unresolved frontier symbols from `Run761` / `Run776` (`5354eba`) plus two internal render service children.

## Recovered Symbols (`Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)

| Symbol | Address Range | Bytes | Code SHA-256 | Role |
|---|---|---:|---|---|
| `?render_driver_calibrate_00536870@porsche@@YAXXZ` | `00536870..00536947` | 216 | `8d81e38d572f1bd834fe6e2de4236bbbd3a2c6dd6bacd3f4ed3c2f9037822a5e` | One-shot mouse/calibration setup: binds `005dfb60` via `0053c8d0`, initializes `0053c8e0`, probes movie service flag `0069de4c`, allocates `0x2c` calibration object `0069de44`, sets states `0x14`/`0x15` to `-0.5f`, calls `00571a10` |
| `?render_service_set_ops_0053c8d0@porsche@@YAXPAX@Z` | `0053c8d0..0053c8d9` | 10 | `860add851908ca56106874dff425e9501f93e553b40fb0b9774bebda15430cb1` | Stores active render service ops table into `005dec08` |
| `?render_initialize_service_0053c8e0@porsche@@YAXXZ` | `0053c8e0..0053c90c` | 45 | `5da4f6813b8b91e6eb3abfd7648a7b494776d00777cf12152936f4de77451913` | One-shot render service init: initializes index array `0053d840(0)`, creates debug font `0069eb90` from `005dfd8c` via `0053c6c0` |
| `?render_service_init_indices_0053d840@porsche@@YAXH@Z` | `0053d840..0053d895` | 86 | `cbb6dbd0813480c61c74b36ff5c1c33287f4c1979b1f5ece45ec16ad34d42aa1` | Allocates `count` (default `0x190`) dwords via `ops[5]` (`+0x14`) and populates identity indices `0..count-1` |

Owned loader-zero `.bss` (`25B` total): `render_calibration_initialized_0069de40` (`4B`), `render_calibration_cookie_0069de48` (`4B`), `render_calibration_flag_0069de4c` (`1B`), `render_service_font_0069eb90` (`4B`), `render_service_initialized_0069eb94` (`4B`), `render_service_capacity_0069eba0` (`4B`), `render_service_indices_0069eba4` (`4B`).

Totals: `357B` executable code (`216B + 10B + 45B + 86B`), `25B` `.bss`, `0B` `.rdata`.

## Files

- `render_calibrate_service_782.hpp` / `render_calibrate_service_782.cpp`
- `scope-evidence.json`
- `rea-queries.json` / `validation.json`
- `native-config.json` / `native-fixture.cpp.in`

## Evidence & Verification

1. **REA**:
   ```powershell
   py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/782-render-calibrate-service/rea-queries.json --attempt 001
   py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/782-render-calibrate-service/rea-queries.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-input-782-rea/001/receipt.json`
   - Dossiers: `function-00536870.json`, `function-0053c8d0.json`, `function-0053c8e0.json`, `function-0053d840.json`
   - Audit (`validation.json`): `passed: true`, `dossiers: 4`, `repeated_equal: 0`

2. **Native x86-vs-C++ Equivalence (`/Od` and `/O2`)**:
   ```powershell
   py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/782-render-calibrate-service/native-config.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-calibrate-service-782/001/receipt.json` (`status: "PASS"`)
   - Variants: `/Od` and `/O2`, both `render_calibrate_service_782_original_x86_vs_cpp=PASS cases=63` (`0` failed cases)
   - Mutation controls: `12/12` detected (`exit_code: 7`):
     `wrong-536870-init-gate`, `wrong-536870-flag-set`, `wrong-536870-alloc-size`, `wrong-536870-state-ctor-offset`, `wrong-536870-setstatef-val`, `wrong-536870-setstatef-ids`, `wrong-536870-null-store`, `wrong-53c8d0-store`, `wrong-53c8e0-init-gate`, `wrong-53d840-default-count`, `wrong-53d840-ops-slot`, `wrong-53d840-fill-loop`

## Scope Boundary (`PARTIAL`)

- Reused canonical symbols: `render_calibration_object_0069de44` (`525`), `game_setup_movie_service_0069ed0c` (`game_setup`), `startup_network_allocate_0059ef90` (`application_alloc`), `render_resource_node_state_ctor_005379d0` (`536`), `font_setstatef_0053e890` (`671`).
- Explicit typed unrecovered boundaries: `render_mouse_ops_table_005dfb60`, `render_debug_font_005dfd8c`, `render_calibration_vtable_005bb708`, `render_service_ops_005dec08`, `render_debug_font_create_0053c6c0` (`0053c6c0`), `render_font_prepare_00571a10` (`00571a10`).
