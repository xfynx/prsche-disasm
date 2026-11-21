# Run 741 — Render Shape Transfer (`00571630`, `005719c0`)

Promoted from the `Run734` (`734-render-fill`) / `Run735` child frontier.

## Recovered Symbols (`Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`)

| Symbol | Address Range | Bytes | Code/Data SHA-256 | Role |
|---|---|---:|---|---|
| `?render_shape_transfer_00571630@porsche@@YAXPBXHHPBQBX@Z` | `00571630..00571984` | 853 | `8b6e6039bd809999b4b1d8f890df5cfc970362487e322b27db20aed37458c516` | Shape type validation, conversion selection (`00534b90` / `00534d40` / two-stage `005719c0`), 4-side clipping, fast-path / per-row span dispatch |
| `jump_table_00571988` | `00571988..0057199f` | 24 | `87e75231cb9a1f3edacb2e8fb367887433e3c84a4ec7bf8720440a3a139c4715` | 6-entry switch jump table for `00571630` |
| `lookup_table_005719a0` | `005719a0..005719b8` | 25 | `24fe4016ec7c252dc23df2de5ac73180c686d6c13d74554f92e26152b04c75dd` | 25-byte `0x6d..0x85` shape-type index LUT for `00571630` |
| `?render_shape_two_stage_span_005719c0@porsche@@YAXPAXPBXI@Z` | `005719c0..00571a04` | 69 | `8e2a46081883260e48e9be52e3e8203fc389f464fd6a81e0968045fc845df5f8` | Two-stage span adapter (`0x1900` stack buffer via `006a6424` then `006a6428`) |
| `render_shape_invalid_fmt_005c073c` | `005c073c..005c0760` | 37 | `6ef88932a3cff648161158adc8317c9c166d186a2f1364193b15f38f0adef9a3` | `.rdata` `"movdfl - INVALID SHAPE TYPE ($%02x)\n"` |
| `render_shape_source_file_005c0764` | `005c0764..005c0775` | 18 | `b4e3903034cb4a21628689df555f8809b76db1c191158726525a6bf15116d71a` | `.rdata` `"\\real\\pc\\movdfl.c"` |
| `render_shape_stage1_fn_006a6424` | `006a6424..006a6427` | 4 | — | `.bss` stage-1 span callback pointer |
| `render_shape_stage2_fn_006a6428` | `006a6428..006a642b` | 4 | — | `.bss` stage-2 span callback pointer |

Totals: `922B` executable code (`853B + 69B`), `55B` owned `.rdata` strings (`37B + 18B`), `8B` owned `.bss`.

## Files

- `render_shape_transfer_741.hpp` / `render_shape_transfer_741.cpp`
- `scope-evidence.json`
- `rea-queries.json` / `validation.json`
- `native-config.json` / `native-fixture.cpp.in`

## Evidence & Verification

1. **REA**:
   - `00571630`: `local/experiments/v2-render-input-734-rea/001/function-00571630.json` (audited in `runs/734-render-fill/validation.json`)
   - `005719c0`, `00534b90`, `00534d40`:
     ```powershell
     py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/741-render-shape-transfer/rea-queries.json --attempt 001
     ```
     Receipt: `local/experiments/v2-render-input-741-rea/001/receipt.json`; audit: `iterations/v2/001-original-recovery/runs/741-render-shape-transfer/validation.json` (`passed: true`, `dossiers: 3`, `repeated_equal: 0`).

2. **Native x86-vs-C++ Equivalence (`/Od` and `/O2`)**:
   ```powershell
   py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/741-render-shape-transfer/native-config.json --attempt 002
   ```
   - Receipt: `local/experiments/v2-render-shape-transfer-741/002/receipt.json` (`status: "PASS"`)
   - Variants: `/Od` and `/O2`, both `render_shape_transfer_original_x86_vs_cpp=PASS cases=33` (`0` failed cases)
   - Mutation controls: `11/11` detected (`exit_code: 1`):
     `wrong-571630-diag-line`, `wrong-571630-override-type`, `wrong-571630-direct-mode-cmp`, `wrong-571630-dither-cmp`, `wrong-571630-clip-left-skip`, `wrong-571630-clip-right-gap`, `wrong-571630-bpp15-slot`, `wrong-571630-bpp24-slot`, `wrong-571630-fast-path-disable`, `wrong-571630-free-alloc`, `wrong-5719c0-stage2-call`

## Scope Boundary (`PARTIAL`)

- Downstream shape conversion helpers `?render_shape_row_converter_00534b90@porsche@@YAPAXPBXIH@Z` (`00534b90`) and `?render_shape_convert_type_00534d40@porsche@@YAPAXPBXIHH@Z` (`00534d40`) remain explicit typed boundaries declared in `render_shape_transfer_741.hpp` and mocked with recording stubs in the native harness.
- In `005719c0`, only the bytes written by `render_shape_stage1_fn_006a6424` into the `0x1900`-byte stack buffer are verified; uninitialized stack bytes beyond `stage1` writes are bounded by `count` in the fixture.
