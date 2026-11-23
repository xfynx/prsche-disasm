# Run776 scene blur state and input/render misc integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding frozen Runs `774` and `775` onto the `Run761` baseline (`442` -> `444` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run774 (`774-scene-blur-state-commit/scene_blur_state_774.cpp`, `002/receipt.json` PASS):** `scene_blur_state_quality_00537a30` (`00537a30..00537a38`, 9B), `scene_blur_state_one_00537a40` (`00537a40..00537a49`, 10B), `scene_blur_state_flag_00537a70` (`00537a70..00537a7c`, 13B), and `scene_blur_state_commit_00536470` (`00536470..00536505`, 150B). `50` `/Od`+`/O2` comparisons (`25`/variant), `11` mutations killed; REA `v2-scene-774-rea/001` PASS (4 dossiers). Zero new owned data; reuses canonical `0069ed0c`, `005de6bc`, `005de72c`.
- **Run775 (`775-input-effect-slot-and-render-misc/input_effect_slot_render_misc_775.cpp`, `001/receipt.json` PASS):** `input_slot_effect_cleanup_005331a0` (`005331a0..005331eb`, 76B) and `render_misc_00465df0` (`00465df0..00465e15`, 38B). `192` `/Od`+`/O2` comparisons (`96`/variant), `9` mutations killed; REA `v2-render-input-775-rea/001` PASS (2 dossiers). Zero new owned data; reuses canonical `0069cb08`, `006be040`, `00532b50`, `00533120`, `0059ef90`, `0059f070`, `0062810c`.

## Shared build & frontier impact

- **Build & audit:** `444` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `242` native comparisons, `20` mutations, `1,097` source pins, `2` REA sessions (`v2-scene-774-rea/001`, `v2-render-input-775-rea/001`), `0` new `.data`/`.rdata`/`.bss` bytes.
- **Closed frontier names (6):** `?scene_blur_state_quality_00537a30@porsche@@YIXPAX0I@Z`, `?scene_blur_state_one_00537a40@porsche@@YIXPAX0I@Z`, `?scene_blur_state_flag_00537a70@porsche@@YIXPAX0I@Z`, `?scene_blur_state_commit_00536470@porsche@@YIXPAX0PBX@Z`, `?input_slot_effect_cleanup_005331a0@porsche@@YAXH@Z`, `?render_misc_00465df0@porsche@@YAXXZ`.
- **New unresolved frontier names (0):** none.
- **Total unresolved:** `94` names / `101` references (down from `100` / `107`).
- **Registry (`functions.json`):** `+6` entries (`1,247` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/776-scene-blur-and-input-render-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/776-scene-blur-and-input-render-integration/acceptance.json
```

## Boundaries

`774` bounds non-null receiver (`>= 0x54` bytes for commit), valid 28B input state, non-null `0069ed0c` + `+0x04` subobject during commit, and valid `__cdecl (uint32_t, uint32_t)` flush callbacks in `005de72c[0..6]`. `775` proves bounded mapped input-slot cleanup and `00465df0` `0x4c`-byte `0059f070` allocation/store into `0062810c`. Null-service/live D3D state flush, live DirectInput hardware, startup, and gameplay remain open.
