# Run739 scene program integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding frozen Runs `736`, `737`, and `738` onto the `Run735` baseline (`428` -> `432` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run736 (`736-scene-blur-program-lifecycle/scene_blur_program_736.cpp`, `006/receipt.json` PASS):** `scene_blur_program_ctor_00468240` (`00468240..00468307`, 200B) and `scene_blur_program_setup_004685e0` (`004685e0..00468628`, 73B). 152 `/Od`+`/O2` comparisons, 10 mutations killed. Zero new owned data; reuses `0059ef90`, `0059eff0`.
- **Run737 (`737-scene-pass-children/scene_pass_children_737.cpp`, `005/receipt.json` PASS):** `scene_pass_append_0053f160` (`0053f160..0053f1ab`, 76B), `scene_pass_create_0053f230` (`0053f230..0053f29c`, 109B), and `scene_pass_finalize_0053f2a0` (`0053f2a0..0053f318`, 121B). 86 `/Od`+`/O2` comparisons, 11 mutations killed; REA `v2-scene-pass-children-737-rea/002` PASS. Zero new owned data; reuses `render_cleanup_head_0069ebb0` (`Run599`) and `0059ef90`.
- **Run738 (`738-scene-blur-stage-child/scene_blur_stage_child_738.cpp`, `001/receipt.json` PASS):** `scene_blur_program_stage_00468440` (`00468440..004685d0`, 401B). 240 `/Od`+`/O2` comparisons, 12 mutations killed; REA `v2-scene-blur-stage-child-738-rea/002` PASS. Zero new owned data; reuses `startup_text_quality_mask_ptr_0044dfe0` (`Run650`).
- **Run739 ABI bridge (`scene_blur_stage_abi_bridge_739.cpp`):** forwards Run736's parameter-4 `std::uint32_t` overload (`?scene_blur_program_stage_00468440@porsche@@YIXPAX0IIIIII@Z`) to Run738's canonical `void*` definition (`?scene_blur_program_stage_00468440@porsche@@YIXPAX0IPAXIIII@Z`).

## Shared build & frontier impact

- **Build & audit:** `432` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `478` native comparisons, `33` mutations, `1,068` source pins, `3` REA sessions (`v2-audio-scene-730-rea/001`, `v2-scene-pass-children-737-rea/002`, `v2-scene-blur-stage-child-738-rea/002`), `0` new `.data`/`.rdata`/`.bss` bytes.
- **Closed frontier names (2):** `scene_blur_program_ctor_00468240`, `scene_blur_program_setup_004685e0` (while `00468440`, `0053f160`, `0053f230`, `0053f2a0` also resolve internally).
- **New unresolved frontier names (6):** `scene_pass_compile_0053f380`, `scene_pass_factory_default_0053f980`, `scene_blur_state_flag_00537a70`, `scene_blur_state_one_00537a40`, `scene_blur_state_quality_00537a30`, `scene_blur_state_commit_00536470`.
- **Total unresolved:** `101` names / `108` references (up from `97` / `104`).
- **Registry (`functions.json`):** `+6` entries (`1,217` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/739-scene-program-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/739-scene-program-integration/acceptance.json
```

## Boundaries

Controlled endpoints in the underlying native proofs remain bounded for `0053f980`, `0053f380`, pass vtable slots `+0x08/+0x10/+0x14/+0x18`, `00537a70`, `00537a40`, `00537a30`, `00536470`, valid non-null blur program/pass/table pointers, null `0059ef90` node allocation only (array allocation failure in `00468240` and null/invalid receiver faults remain open), and unrecovered live renderer/startup/gameplay execution.
