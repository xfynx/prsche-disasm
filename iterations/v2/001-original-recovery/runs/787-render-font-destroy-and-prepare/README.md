# Run 787 — Render Font Prepare, Destroy & Calibration Destructor (`00571a10`, `00536840`, `0053c8b0`, `00571a90`)

Closes three boundaries opened by `Run782` (`782-render-calibrate-service`): `00571a10`, `005bb708` (with its scalar deleting destructor `00536840`, font teardown `0053c8b0`, and handle release `00571a90`), and the `7093`-byte `.data` `FNTF` font blob `005dfd8c`.

## Recovered Symbols (`Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)

| Symbol | Address Range | Bytes | Code/Data SHA-256 | Role |
|---|---|---:|---|---|
| `?render_font_prepare_00571a10@porsche@@YAXPAX@Z` | `00571a10..00571a8c` | 125 | `594f43a48b17abc6269d9eceac8dca47d8e7d1ea414902f0c3f4950c5642188d` | Allocates handle via `ops[0]`, converts glyphs via `00594980`, uploads pixels via `ops[1]`, sets ready byte `+0xac` |
| `?render_calibration_dtor_00536840@porsche@@YIPAXPAX0I@Z` | `00536840..0053686b` | 44 | `50e3f3d9caaac79bd2112800bc69b207e5f736da0140e62116d2bed8329915b4` | Scalar deleting destructor (`ret 4`) at slot 0 of `005bb708`: resets vptr, calls `0053c8b0(font)`, releases `self` via `0059f050` if `flags & 1` |
| `?render_font_destroy_0053c8b0@porsche@@YAXPAX@Z` | `0053c8b0..0053c8c8` | 25 | `92a606942ede44b888c12e420351530697b96d24430b5e64783cef1cccb4a1af` | Releases handle via `00571a90` and frees font object via `ops[6]` (`+0x18`) |
| `?render_font_release_handle_00571a90@porsche@@YAXPAX@Z` | `00571a90..00571ab8` | 41 | `8d8d060224bf1d650657fd68f95c3808c7dc6c54e2079ec1bf403d464f215086` | Releases non-null texture handle via `ops[2]` (`+0x08`), clears `+0x44`, sets `+0xac = 1` |
| `render_calibration_vtable_005bb708` | `005bb708..005bb70b` | 4 | — | Owned `.rdata` 1-entry vtable `{ &render_calibration_dtor_00536840 }` |
| `render_debug_font_005dfd8c` | `005dfd8c..005e1940` | 7093 | `316e53fdf7bc89e4784c4f17dceaf08ab3e2506f5cde3d49b511ad1c3e4e0eea` | Owned `.data` embedded `FNTF` font payload (0 internal relocations) |

Totals: `235B` executable code (`125B + 44B + 25B + 41B`), `4B` `.rdata`, `7093B` `.data`.

## Files

- `render_font_destroy_787.hpp` / `render_font_destroy_787.cpp`
- `scope-evidence.json`
- `rea-queries.json` / `validation.json`
- `native-config.json` / `native-fixture.cpp.in`

## Evidence & Verification

1. **REA**:
   ```powershell
   py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/787-render-font-destroy-and-prepare/rea-queries.json --attempt 001
   py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/787-render-font-destroy-and-prepare/rea-queries.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-input-787-rea/001/receipt.json`
   - Dossiers: `function-00571a10.json`, `function-00536840.json`, `function-0053c8b0.json`, `function-00571a90.json`
   - Audit (`validation.json`): `passed: true`, `dossiers: 4`, `repeated_equal: 0`

2. **Native x86-vs-C++ Equivalence (`/Od` and `/O2`)**:
   ```powershell
   py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/787-render-font-destroy-and-prepare/native-config.json --attempt 001
   ```
   - Receipt: `local/experiments/v2-render-font-destroy-and-prepare-787/001/receipt.json` (`status: "PASS"`)
   - Variants: `/Od` and `/O2`, both `render_font_destroy_787_original_x86_vs_cpp=PASS cases=30` (`0` failed cases)
   - Mutation controls: `10/10` detected (`exit_code: 7`):
     `wrong-571a10-ops-alloc-zero`, `wrong-571a10-skip-convert`, `wrong-571a10-upload-pixels-off`, `wrong-571a10-ready-flag-invert`, `wrong-536840-vtable-write`, `wrong-536840-skip-release`, `wrong-53c8b0-ops-slot`, `wrong-571a90-clear-handle`, `wrong-571a90-ops-slot`, `wrong-571a90-null-gate`

## Scope Boundary (`PARTIAL`)

- Reused canonical symbols: `render_service_ops_005dec08` (`782`), `application_release_0059f050` (`application_alloc`).
- Explicit typed unrecovered boundary: `render_font_convert_glyphs_00594980` (`00594980`).
