# Run743 audio, render, and scene integration

Shared integration PASS (`build-002` + `audit-v2-native-game-batch.py`) folding frozen Runs `740`, `741`, and `742` onto the `Run739` baseline (`432` -> `435` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run740 (`740-audio-stream-scdl-chunk/audio_stream_scdl_chunk_740.cpp`, `002/receipt.json` PASS):** `audio_stream_slot_push_chunk_005615c0` (`005615c0..0056167f`, 192B), `audio_stream_deinterleave_chunk_00566b40` (`00566b40..00566d3b`, 508B), and `audio_stream_service_chunk_scdl_00567060` (`00567060..00567131`, 210B). 48 `/Od`+`/O2` comparisons, 16 mutations killed; REA `v2-audio-740-rea/001` PASS. Zero new owned data; reuses `006b48c0`, `006b7cc0`, `005896d0`/`005896f0`, `VirtualAlloc`/`VirtualFree`.
- **Run741 (`741-render-shape-transfer/render_shape_transfer_741.cpp`, `002/receipt.json` PASS):** `render_shape_transfer_00571630` (`00571630..00571984`, 853B + 24B jump table `00571988` + 25B LUT `005719a0`) and `render_shape_two_stage_span_005719c0` (`005719c0..00571a04`, 69B). 66 `/Od`+`/O2` comparisons, 11 mutations killed; REA `v2-render-input-741-rea/001` + `v2-render-input-734-rea/001` PASS. Owns `55B .rdata` (`005c073c..005c0760`, `005c0764..005c0775`) and `8B .bss` (`006a6424..006a6427`, `006a6428..006a642b`).
- **Run742 (`742-scene-stage-group-ctor/scene_stage_group_742.cpp`, `001/receipt.json` PASS):** `scene_stage_group_ctor_0059f070` (`0059f070..0059f1b8`, 329B), `scene_pass_init_0053f320` (`0053f320..0053f340`, 33B), `scene_pass_init_alt_0053f600` (`0053f600..0053f61c`, 29B), `scene_mode_set_c_00537a20` (`00537a20..00537a29`, 10B), and `scene_mode_set_10_00537a60` (`00537a60..00537a69`, 10B). 296 `/Od`+`/O2` comparisons, 10 mutations killed; REA `v2-scene-stage-group-742-rea/001` + `v2-audio-scene-730-rea/001` PASS. Zero new owned data; reuses `0059ef90`, `005379f0`, `0053f160`, `0053f2a0`.

## Shared build & frontier impact

- **Build & audit:** `435` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `410` native comparisons, `37` mutations, `1,074` source pins, `3` REA sessions (`v2-audio-740-rea/001`, `v2-render-input-741-rea/001`, `v2-scene-stage-group-742-rea/001`), `55B` new `.rdata`, `8B` new `.bss`. (`configure-001` failed before switching relative paths to `CMAKE_CURRENT_LIST_DIR`; `build-002` passed.)
- **Closed frontier names (3):** `audio_stream_service_chunk_scdl_00567060`, `render_shape_transfer_00571630`, `scene_stage_group_ctor_0059f070`.
- **New unresolved frontier names (2):** `render_shape_row_converter_00534b90`, `render_shape_convert_type_00534d40`.
- **Total unresolved:** `100` names / `107` references (down from `101` / `108`).
- **Registry (`functions.json`):** `+10` entries (`1,227` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/743-audio-render-scene-integration/build-config.json --phase build --attempt 002
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/743-audio-render-scene-integration/acceptance.json
```

## Boundaries

`740` bounds SCDl channels (`1..4`), slot index (`0..15`), non-aliasing buffers, and deterministic `VirtualAlloc`/`VirtualFree` endpoints (`00566ea0`, `005612a0` remain open). `741` keeps `00534b90`, `00534d40`, and uninitialized stack scratch bytes beyond stage-1 writes in `005719c0` as explicit `PARTIAL` bounds. `742` proves controlled transport for `005379f0`/`0059ef90`/`0053f160`/`0053f2a0` while null-receiver faults, live virtual pass dispatch, live devices, startup, and gameplay remain open.
