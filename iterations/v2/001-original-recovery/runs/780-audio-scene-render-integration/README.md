# Run780 audio, scene pass, and render/startup integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding frozen Runs `773`, `778`, and `779` onto the `Run776` baseline (`444` -> `447` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run773 (`773-audio-voice-allocator/audio_allocator_773.cpp`, `004/receipt.json` PASS):** `audio_voice_selection_contains_005898b0` (`005898b0..005898e0`, 49B) and `audio_backend_allocate_voice_005898f0` (`005898f0..00589bf2`, 771B). `30` `/Od`+`/O2` comparisons (`15`/variant), `14` mutations killed; REA `v2-audio-allocator-dependency-research-759/002` PASS (4 dossiers). Owns `12B .bss` (`006b48a8..006b48af` 8B, `006ad74c..006ad74f` 4B); reuses `006b48c0`, `006b4a00`, `00565d60`.
- **Run778 (`778-scene-pass-compile-factory/scene_pass_compile_factory_778.cpp`, `001/receipt.json` PASS):** `scene_pass_compile_0053f380` (`0053f380..0053f425`, 166B), `scene_pass_factory_default_0053f980` (`0053f980..0053fce1`, 866B), `scene_pass_init_kind1_0053fd60` (`0053fd60..0053fd80`, 33B), and `scene_pass_init_kind2_00574ab0` (`00574ab0..00574aca`, 27B). `112` `/Od`+`/O2` comparisons (`56`/variant), `12` mutations killed; REA `v2-scene-778-rea/001` PASS (4 dossiers). Zero new owned data; reuses `0059ef90`, `0053f320`, `0053f600`.
- **Run779 (`779-render-env-and-startup-ff/render_env_startup_ff_779.cpp`, `001/receipt.json` PASS):** `render_environment_00573030` (`00573030..00573061`, 50B) and `startup_sequence_call_004121b0` (`004121b0..0041222b`, 124B). `126` `/Od`+`/O2` comparisons (`63`/variant), `10` mutations killed; REA `v2-render-input-779-rea/001` PASS (2 dossiers). Owns `6B .rdata` (`005c0838..005c083d`) and `4B .bss` (`00606ad0..00606ad3`); reuses `005a0fbf`, `00411d20`, `005e9408`, `00414c30`, `00533480`, `00657424`, `005e8b34`.

## Shared build & frontier impact

- **Build & audit:** `447` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `268` native comparisons, `36` mutations, `1,104` source pins, `3` REA sessions (`v2-audio-allocator-dependency-research-759/002`, `v2-scene-778-rea/001`, `v2-render-input-779-rea/001`), `16B` new `.bss`, `6B` new `.rdata`.
- **Closed frontier names (5):** `?audio_backend_allocate_voice_005898f0@porsche@@YAHHIPAIII@Z`, `?render_environment_00573030@porsche@@YAIPBD0I@Z`, `?scene_pass_compile_0053f380@porsche@@YIXPAX@Z`, `?scene_pass_factory_default_0053f980@porsche@@YAPAXII@Z`, `?startup_sequence_call_004121b0@porsche@@YAXXZ`.
- **New unresolved frontier names (2):** `?crt_putenv_005a38c7@porsche@@YAHPBD@Z`, `?ff_effect_frame_tick_004123e0@porsche@@YAXXZ`.
- **Total unresolved:** `91` names / `99` references (down from `94` / `101`).
- **Registry (`functions.json`):** `+8` entries (`1,255` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/780-audio-scene-render-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/780-audio-scene-render-integration/acceptance.json
```

## Boundaries

`773` bounds `channel_count <= 4`, slots `0..127`, controlled `00565d60`, and leaves caller `00590420` open. `778` proves controlled vtable slot `+0x0c` and acyclic pass lists while preserving raw `.rdata` vtables without live virtual implementations. `779` leaves `crt_putenv_005a38c7` and `ff_effect_frame_tick_004123e0` as explicit `PARTIAL` typed boundaries. Live audio/renderer/FF hardware, startup, and gameplay remain open.
