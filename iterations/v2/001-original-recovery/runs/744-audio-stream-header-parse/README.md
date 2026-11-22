# Run 744: Audio Stream Header Parse Closure (`00561900`, `00590ef0`, `00590f70`, `00599720`)

## Scope
Recovers the audio stream header parser and byte-rate/format subtree called by `audio_stream_service_chunk_schl_00566ea0` (4 functions, 1,123 code bytes total, zero new `.data`/`.bss` allocations, zero new unresolved game symbols):

1. `audio_stream_info_init_00561900` (`00561900..00561950`, 81 bytes, `sha256: a0dd4bc847d8f676477cad8a482f7dbd4d1486c8d73a15c2e2294f64405fa775`)
2. `audio_stream_header_byte_rate_00590ef0` (`00590ef0..00590f63`, 116 bytes, `sha256: 55f41f84cd6acbf0d8566b3907a7bd6598c3d31284b04c899848ebf44cb13adc`)
3. `audio_stream_header_parse_00590f70` (`00590f70..005912d6`, 871 bytes, `sha256: 218d61a3188611e419dc12bc56b359fd23b3decd345949ee87b13bf867f5c5cb`)
4. `audio_stream_codec_from_format_00599720` (`00599720..00599756`, 55 bytes, `sha256: 696f4431bf114c2ad5bbe778e5b96ad4082718fb40dbc902e7e970042d72c4bd`)

Reused canonical symbols:
- `application_audio_device_state_006b48c0` (`006b48c0`, reads `+0x1c` / `006b48dc` and `+0x154..0x17b` / `006b4a14`)
- `application_audio_backend_allocate_0058aae0` (`0058aae0`)
- `audio_stream_copy_forward_00598a50` (`00598a50`)
- `audio_token_read_00599760` (`00599760`)

## Files
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/audio_stream_header_parse_744.hpp`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/audio_stream_header_parse_744.cpp`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/scope-evidence.json`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/native-config.json`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/native-fixture.cpp.in`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/rea-queries.json`
- `iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/validation.json`

## Verification
- **REA Evidence**:
  - `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/rea-queries.json --attempt 002` -> `local/experiments/v2-audio-744-rea/002/receipt.json` (`status: completed`, 4 dossiers: `00590f70`, `00590ef0`, `00561900`, `00599720`)
  - `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/rea-queries.json --attempt 002` -> `{"passed": true, "dossiers": 4, "repeated_equal": 0}` (`validation.json`)
- **Native Original x86 vs C++ Comparison**:
  - `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/744-audio-stream-header-parse/native-config.json --attempt 002`
  - Receipt: `local/experiments/v2-audio-stream-header-parse-744/002/receipt.json` (`"status": "PASS"`)
  - `/Od` and `/O2`: `audio_stream_header_parse_original_x86_vs_cpp=PASS cases=24 events=54` (0 failed cases, ABI + FPU/MXCSR + device state + full arena bit-exact)
  - Material mutations: `16/16` detected (`exit_code: 1`)

## Explicit Bounds
- `audio_stream_header_parse_00590f70`: `0 <= channels <= 4`; when `channels >= 2`, token `0x9d` initializes channel-1 base volume; at most 4 tag `0x14` entries (`info+0x34..0x53`).
- `audio_stream_header_byte_rate_00590ef0`: full `uint16` sample rate x `uint8` channels arithmetic with bit-exact `SAR 8` shift (`sar_8`).
- `audio_stream_service_chunk_schl_00566ea0` remains blocked on `audio_stream_voice_start_005612a0` (791B, 8 unrecovered backend callees) and `[006b49e0]`.
