# Run784 audio voice pitch and sim teardown integration

Shared integration PASS (`build-001` + `audit-v2-native-game-batch.py`) folding frozen Runs `777` and `783` onto the `Run780` baseline (`447` -> `449` TUs across 8 projects; no playable game EXE yet).

## Integrated batches

- **Run777 (`777-audio-voice-pitch/audio_voice_pitch_777.cpp`, `003/receipt.json` PASS):** `audio_voice_pitch_scale_00589e80` (`00589e80..00589f31`, 178B) and `audio_voice_recompute_pitch_00589f40` (`00589f40..00589fd5`, 150B). `56` `/Od`+`/O2` comparisons (`28`/variant), `12` mutations killed; REA `v2-audio-777-rea/001` PASS (2 dossiers). Owns the 256B `005e1d3c..005e1e3b` pitch lookup table (`const` `.rdata` in C++ COFF, original `.data`); reuses `006b4a00` (`Run434`).
- **Run783 (`783-sim-audio-teardown-leaves/sim_audio_teardown_leaves_783.cpp`, `001/receipt.json` PASS):** `application_sim_boundary_004a4760` (`004a4760..004a477e`, 31B), `application_sim_boundary_004ae470` (`004ae470..004ae4c8`, 89B), `application_sim_boundary_004b04d0` (`004b04d0..004b04dc`, 13B), `application_sim_boundary_004ad4d0` (`004ad4d0..004ad4ed`, 30B), and `audio_device_register_callback_005610e0` (`005610e0..00561107`, 40B). `28` `/Od`+`/O2` comparisons (`14`/variant), `12` mutations killed; REA `v2-sim-audio-783-rea/001` PASS (5 dossiers). Owns `1B .bss` (`00656ab0`); reuses `00655a04`, `00560180`, `00656ab4`, `006b48c0`.

## Shared build & frontier impact

- **Build & audit:** `449` TUs / 8 projects (`0` compiler errors, `0` non-unresolved linker errors), `84` native comparisons, `24` mutations, `1,109` source pins, `2` REA sessions (`v2-audio-777-rea/001`, `v2-sim-audio-783-rea/001`), `256B` read-only table (`005e1d3c..005e1e3b`), `1B` new `.bss` (`00656ab0`).
- **Closed frontier names (5):** `?audio_voice_recompute_pitch_00589f40@porsche@@YAXI@Z`, `?application_sim_boundary_004a4760@porsche@@YAXXZ`, `?application_sim_boundary_004ae470@porsche@@YAXHPAI@Z`, `?application_sim_boundary_004b04d0@porsche@@YAHHH@Z`, `?application_sim_boundary_004ad4d0@porsche@@YAXXZ`.
- **New unresolved frontier names (0):** none.
- **Total unresolved:** `86` names / `94` references (down from `91` / `99`).
- **Registry (`functions.json`):** `+7` entries (`1,262` total).

## Verification commands

```powershell
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/784-audio-voice-and-sim-teardown-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/784-audio-voice-and-sim-teardown-integration/acceptance.json
```

## Boundaries

`777` bounds valid `voice_slot` and modulation tables (`+0x58`/`+0x60`) and skips `005897c0` -> `00589fe0`. `783` forwards literal callback VAs (`0x004a45d0`, `0x004ac290`) into `00560180`/`005610e0`, bounds `+0xf0` callback table to 8 slots, and assumes valid `root+0xe8` buffer space. Live DirectSound/playback, sim teardown callers, startup, and gameplay remain open.
