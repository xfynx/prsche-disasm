# Run 773: Audio Voice Allocator Closure (`005898b0`, `005898f0`)

## Scope
Recovers both the allocator membership scan (`005898b0`) and the full audio voice allocator (`005898f0`), closing `?audio_backend_allocate_voice_005898f0@porsche@@YAHHIPAIII@Z` on the `Run751`/`Run761` unresolved linker frontier with zero new unresolved game symbols (2 functions, 820 code bytes total, 12B allocator-private `.bss`):

1. `audio_voice_selection_contains_005898b0` (`005898b0..005898e0`, 49 bytes, `sha256: 66173fda19494edcca424054de25ca4a4f66de80a29bc8c024b97be685da3556`)
2. `audio_backend_allocate_voice_005898f0` (`005898f0..00589bf2`, 771 bytes, `sha256: 339fbcaa839f7fa4cf676eb1305faea97b9bb646ded691960f0d9cbe790670fc`)

Owned `.bss` cells (12 bytes total):
- `audio_voice_selection_006b48a8` (`006b48a8..006b48af`, 8 bytes: `std::int16_t[4]`)
- `audio_voice_generation_006ad74c` (`006ad74c..006ad74f`, 4 bytes: `std::uint32_t`)

Reused canonical symbols:
- `application_audio_device_state_006b48c0` (`006b48c0`, reads `+0xe8` / `006b49a8`)
- `audio_backend_channels_006b4a00` (`006b4a00`, `Run434`)
- `audio_channel_stop_00565d60` (`00565d60`, `Run435`)

## Files
- `iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/audio_allocator_773.hpp`
- `iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/audio_allocator_773.cpp`
- `iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/scope-evidence.json`
- `iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/native-config.json`
- `iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/native-fixture.cpp.in`

## Verification
- **REA Evidence (reused from Run759)**:
  - `local/experiments/v2-audio-allocator-dependency-research-759/002/receipt.json` (`function-005898b0.json`, `function-005898f0.json`, `function-00565d60.json`, `function-00565720.json`)
  - `iterations/v2/001-original-recovery/runs/759-audio-allocator-dependency-research/validation.json` (`{"passed": true, "dossiers": 4, "repeated_equal": 0}`)
- **Native Original x86 vs C++ Comparison**:
  - `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/773-audio-voice-allocator/native-config.json --attempt 004`
  - Receipt: `local/experiments/v2-audio-voice-allocator-773/004/receipt.json` (`"status": "PASS"`)
  - `/Od` and `/O2`: `audio_voice_allocator_original_x86_vs_cpp=PASS cases=15 events=3` (0 failed cases, ABI + FPU/MXCSR + `.bss` + full `0x70`-record arena bit-exact)
  - Material mutations: `14/14` detected (`exit_code: 1`)

## Explicit Bounds
- `audio_backend_allocate_voice_005898f0`: `channel_count <= 4` (matches 8-byte selection list `006b48a8..006b48af` preceding `006b48b0` and 4-word slot array in voice record `+0x04..+0x0b`), slots `0..127` (matches `movsx cx, al` / `movsx dx, bl` at `005899aa`/`00589a7e`), and controlled `audio_channel_stop_00565d60` endpoint (live stop semantics accepted in `Run435`).
- `005898f0` closes `?audio_backend_allocate_voice_005898f0@porsche@@YAHHIPAIII@Z` directly in `Run773` (no separate `Run777` needed for `005898f0`); second caller `00590420` remains unrecovered.
