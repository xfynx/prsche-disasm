# Run738 scene blur stage child (`00468440`)

Native `001` PASS: recovers `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) `scene_blur_program_stage_00468440` (`00468440..004685d0`, 401B, raw SHA-256 `7f6d301f75f9b2b83b9f1d659d3bbdcbf04f3ac5c5c1ed827faab40e1391dd66`, `__thiscall` via `__fastcall` bridge, RET `0x18`) in `scene_blur_stage_child_738.cpp`, exposed by Run736 (`004685e0`).

## Behavior & ownership

- Appends four render passes via `scene_pass_create_0053f230(kind, 0, 0x20)` and `scene_pass_append_0053f160([self+0], pass)` for `kind` in `{3, 4, 8, 6}` and writes the corresponding `(stride * index + slot) << 3` row entries in `[self+4]`:
  - slot `[self+0x1d]`: `([self+0x10] << 3, slot_1d_value)`
  - slot `[self+0x1e]`: `(0x54, source)`
  - slot `[self+0x1f]`: `(0x18, slot_1f_value)`
  - slot `[self+0x20]`: `([self+0x10] << 2, slot_20_value)`
- Reloads `[self+0]` and `[self+4]` per call/write to preserve child-mutation aliasing, and computes `(stride * index + slot) << 3` using unsigned 32-bit modular arithmetic matching x86 `IMUL`/`ADD`/`SHL`.
- When `source != nullptr`, copies 28 bytes from `source + 0x38` to a local state buffer, calls `scene_blur_state_flag_00537a70(state, (enabled & 0xff) == 0 ? 1 : 0)`, `scene_blur_state_one_00537a40(state, 1)`, queries `startup_text_quality_mask_ptr_0044dfe0(1)` (`Run650`), calls `scene_blur_state_quality_00537a30(state, quality[0] == 0x10 ? 1 : 0)`, and commits via `scene_blur_state_commit_00536470(source, state)`.
- Zero new owned `.data`/`.rdata`/`.bss`. Reuses canonical `startup_text_quality_mask_ptr_0044dfe0` (`Run650`). Unrecovered downstream children: `00537a70`, `00537a40`, `00537a30`, `00536470` (plus `0053f230`/`0053f160`, recovered separately in `Run737`).
- **Integration note:** Frozen `736/scene_blur_program_736.hpp` declares parameter 4 as `std::uint32_t b` (`?scene_blur_program_stage_00468440@porsche@@YIXPAX0IIIIII@Z`), whereas `738/scene_blur_stage_child_738.hpp` declares parameter 4 as `void* source` (`?scene_blur_program_stage_00468440@porsche@@YIXPAX0IPAXIIII@Z`). Shared integration (`Run739`) must align or bridge this C++ mangled parameter type.

## Verification

```powershell
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/738-scene-blur-stage-child/rea/queries.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/738-scene-blur-stage-child/native-config.json --attempt 001
```

- REA receipt: `local/experiments/v2-scene-blur-stage-child-738-rea/002/receipt.json` (`rea/validation.json`: `passed: true`, `function-00468440.json`).
- Native receipt: `local/experiments/v2-scene-blur-stage-child-738/001/receipt.json` (`status: PASS`).
- 120 cases per `/Od` and `/O2` (240 measured comparisons): 3 stride/index layouts (including signed negative `stride = 0xff`), null vs non-null `source`, 5 `enabled` bitmasks (`0`, `1`, `0x100`, `0x101`, `0xffffffff`), `quality[0]` in `{0x10, 0x0f}`, and mutating vs non-mutating `0053f160` aliasing. Checks ESP/EBP/EBX/ESI/EDI, ordered child events, and full 40B receiver, 512B table, and 128B source buffers.
- 12/12 material mutations (`m01`..`m12`) detected, all exiting with code `7` on `"divergence "`.

## Boundaries

Controlled endpoints prove call transport and order only for `0053f230`, `0053f160`, `00537a70`, `00537a40`, `0044dfe0`, `00537a30`, and `00536470`. Downstream child semantics, null receiver/table faults, broad aliasing, concurrency, and shared CMake/registry integration remain open.
