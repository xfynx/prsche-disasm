# Run 777: Audio Voice Pitch Scale Closure (`00589e80`, `00589f40`)

## Scope
Recovers both `audio_voice_pitch_scale_00589e80` and `audio_voice_recompute_pitch_00589f40` alongside the canonical 256-byte pitch lookup table `audio_pitch_scale_table_005e1d3c`, closing `?audio_voice_recompute_pitch_00589f40@porsche@@YAXI@Z` on the `Run751`/`Run761` unresolved linker frontier without modifying `Run434`'s `006b4a00` storage or ABI (2 functions, 328 code bytes total, 256B `.data` table, zero new unresolved game symbols):

1. `audio_voice_pitch_scale_00589e80` (`00589e80..00589f31`, 178 bytes, `sha256: 7313cfa93428141920de670f8bcb67e3592467fdc9be164bbe5bace00af31578`)
2. `audio_voice_recompute_pitch_00589f40` (`00589f40..00589fd5`, 150 bytes, `sha256: 5e19d342e400ba717d25caf9282beda2c015719a7a057eceaa6a3cecb23143c5`)

Owned `.data` table (256 bytes, read-only lookup):
- `audio_pitch_scale_table_005e1d3c` (`005e1d3c..005e1e3b`, 256 bytes, `sha256: 24e944a9313649312e7251afb205894bcf816f2e8005ae004e5a30a5806baa15`; negative indices `-255..-1` index via `005e1e3c + idx = 005e1d3c + 256 + idx`)

Reused canonical symbols:
- `audio_backend_channels_006b4a00` (`006b4a00`, `Run434`)

## Files
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/audio_voice_pitch_777.hpp`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/audio_voice_pitch_777.cpp`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/scope-evidence.json`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/native-config.json`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/native-fixture.cpp.in`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/rea-queries.json`
- `iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/validation.json`

## Verification
- **REA Evidence**:
  - `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/rea-queries.json --attempt 001` -> `local/experiments/v2-audio-777-rea/001/receipt.json` (`status: completed`, 2 dossiers: `00589f40`, `00589e80`)
  - `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/rea-queries.json --attempt 001` -> `{"passed": true, "dossiers": 2, "repeated_equal": 0}` (`validation.json`)
- **Native Original x86 vs C++ Comparison**:
  - `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/777-audio-voice-pitch/native-config.json --attempt 003`
  - Receipt: `local/experiments/v2-audio-voice-pitch-777/003/receipt.json` (`"status": "PASS"`)
  - `/Od` and `/O2`: `audio_voice_pitch_original_x86_vs_cpp=PASS cases=28` (0 failed cases, ABI + FPU/MXCSR + 256B lookup table vs `Porsche.exe` + voice row arena bit-exact)
  - Material mutations: `12/12` detected (`exit_code: 1`)

## Explicit Bounds
- `audio_voice_recompute_pitch_00589f40`: valid `voice_slot` within `0x70`-stride `006b4a00` table and valid modulation tables at `+0x58`/`+0x60` when non-null (`+0x3f` signed `int8_t`, `+0x4b` unsigned `uint8_t`).
- `00589f40` closes `?audio_voice_recompute_pitch_00589f40@porsche@@YAXI@Z` directly in `Run777`; `005897c0` -> `00589fe0` was intentionally skipped per `Run756` (6 unresolved indirect calls in `00589fe0`).
