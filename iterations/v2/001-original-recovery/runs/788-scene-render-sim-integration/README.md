# Run788 scene, render service, font, and sim integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding frozen Runs `781`, `782`, `785`, and `787` onto the `Run784` baseline (`449` -> `453` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run781 (`781-scene-stage-constructor/scene_stage_constructor_781.cpp`, `003/receipt.json` PASS):** `scene_stage_constructor_004522b0` (`004522b0..00452496`, 487B), `scene_flare_entry_ctor_004524a0` (`004524a0..00452507`, 104B), and `context_table_size_0059ece0` (`0059ece0..0059ecf1`, 18B). `32` `/Od`+`/O2` comparisons (`16`/variant), `10` mutations killed; REA `v2-scene-781-rea/001` PASS (3 dossiers). Zero new owned data; typed child `00452120`.
- **Run782 (`782-render-calibrate-service/render_calibrate_service_782.cpp`, `001/receipt.json` PASS):** `render_driver_calibrate_00536870` (`00536870..00536947`, 216B), `render_service_set_ops_0053c8d0` (`0053c8d0..0053c8d9`, 10B), `render_initialize_service_0053c8e0` (`0053c8e0..0053c90c`, 45B), and `render_service_init_indices_0053d840` (`0053d840..0053d895`, 86B). `126` `/Od`+`/O2` comparisons (`63`/variant), `12` mutations killed; REA `v2-render-input-782-rea/001` PASS (4 dossiers). Owns `25B` `.bss` (`0069de40`/`0069de48`/`0069de4c`/`0069eb90`/`0069eb94`/`0069eba0`/`0069eba4`).
- **Run785 (`785-sim-view-slot-cleanup/sim_view_slot_cleanup_785.cpp`, `001/receipt.json` PASS):** `application_sim_boundary_004642f0` (`004642f0..00464329`, 58B). `10` `/Od`+`/O2` comparisons (`5`/variant), `6` mutations killed; REA `v2-sim-view-slot-cleanup-785-rea/001` PASS (1 dossier). Zero new owned data; reuses `00657404` and `00627e80`.
- **Run787 (`787-render-font-destroy-and-prepare/render_font_destroy_787.cpp`, `001/receipt.json` PASS):** `render_font_prepare_00571a10` (`00571a10..00571a8c`, 125B), `render_calibration_dtor_00536840` (`00536840..0053686b`, 44B), `render_font_destroy_0053c8b0` (`0053c8b0..0053c8c8`, 25B), and `render_font_release_handle_00571a90` (`00571a90..00571ab8`, 41B). `60` `/Od`+`/O2` comparisons (`30`/variant), `10` mutations killed; REA `v2-render-input-787-rea/001` PASS (4 dossiers). Owns `4B` `.rdata` `005bb708` and `7,093B` `FNTF` font payload `005dfd8c..005e1940` (`const` in C++ COFF, original `.data`), closing `782`'s `00571a10`, `005bb708`, and `005dfd8c`.

## Shared build & frontier impact

- **Build & audit:** `453` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `228` native comparisons, `38` mutations, `1,118` source pins, `4` REA sessions (`v2-scene-781-rea/001`, `v2-render-input-782-rea/001`, `v2-sim-view-slot-cleanup-785-rea/001`, `v2-render-input-787-rea/001`), `25B` new `.bss`, `7,097B` read-only data (`4B` `.rdata` + `7,093B` `FNTF` payload).
- **Closed frontier names (4):** `?application_sim_boundary_004642f0@porsche@@YAXXZ`, `?render_driver_calibrate_00536870@porsche@@YAXXZ`, `?render_initialize_service_0053c8e0@porsche@@YAXXZ`, `?scene_stage_constructor_004522b0@porsche@@YIPAXPAX0@Z`.
- **New unresolved frontier names (5):** `?scene_flare_entries_resolve_00452120@porsche@@YIXPAX0@Z`, `?render_debug_font_create_0053c6c0@porsche@@YAPAXPBX@Z`, `?render_font_convert_glyphs_00594980@porsche@@YAXPAX@Z`, `?render_mouse_ops_table_005dfb60@porsche@@3PAIA`, `?render_service_ops_005dec08@porsche@@3PAXA`.
- **Total unresolved:** `87` names / `96` references (from `86` / `94`).
- **Registry (`functions.json`):** `+12` entries (`1,274` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/788-scene-render-sim-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/788-scene-render-sim-integration/acceptance.json
```

## Boundaries

`781` bounds `<= 200` flare holder slots and leaves `00452120` open (completed separately in `Run786`). `782`/`787` leave `005dfb60`, `005dec08`, `0053c6c0`, and `00594980` as explicit `PARTIAL` typed boundaries. `785` proves controlled deleting-destructor vtable dispatch on `view_slot_table_00627e80`. Live renderer/DirectInput hardware, startup, and gameplay remain open.
