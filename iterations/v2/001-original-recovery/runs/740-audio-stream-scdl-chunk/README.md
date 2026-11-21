# Run 740: Audio Stream SCDl Chunk Closure (`005615c0`, `00566b40`, `00567060`)

## Scope
Closes the `?audio_stream_service_chunk_scdl_00567060@porsche@@YAHPAX0@Z` unresolved audio frontier from `Run733` / `Run735` along with its complete callee closure (3 functions, 910 code bytes total, zero new `.data`/`.bss` allocations, zero new unresolved game symbols):

1. `audio_stream_slot_push_chunk_005615c0` (`005615c0..0056167f`, 192 bytes, `sha256: 5b2dfeb4f0724b3b69f8804223e1433fc4ba95e5c5e71a2a8a0405a2f3e02ea5`)
2. `audio_stream_deinterleave_chunk_00566b40` (`00566b40..00566d3b`, 508 bytes, `sha256: a7ee17baaa248714c2279073290bfb72c59b9f29c75bff12fc751c4153d5636e`)
3. `audio_stream_service_chunk_scdl_00567060` (`00567060..00567131`, 210 bytes, `sha256: eef0cbe5d9cad364ddee312ee1dfbfa1e42c4df10ad51bac111b6ca5be862ad0`)

Reused canonical symbols:
- `application_audio_device_state_006b48c0` (`006b48c0`, offset `+0xdc` / `006b499c`)
- `audio_stream_slots_006b7cc0` (`006b7cc0`)
- `audio_backend_lock_005896d0` (`005896d0`) and `audio_backend_unlock_005896f0` (`005896f0`)
- `platform_virtual_alloc` (`005b2144`) and `platform_virtual_free` (`005b2148`)

## Files
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/audio_stream_scdl_chunk_740.hpp`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/audio_stream_scdl_chunk_740.cpp`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/scope-evidence.json`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/native-config.json`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/native-fixture.cpp.in`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/rea-queries.json`
- `iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/validation.json`

## Verification
- **REA Evidence**:
  - `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/rea-queries.json --attempt 001` -> `local/experiments/v2-audio-740-rea/001/receipt.json` (`status: completed`, 3 dossiers: `00567060`, `005615c0`, `00566b40`)
  - `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/rea-queries.json --attempt 001` -> `{"passed": true, "dossiers": 3, "repeated_equal": 0}` (`validation.json`)
- **Native Original x86 vs C++ Comparison**:
  - `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/740-audio-stream-scdl-chunk/native-config.json --attempt 002`
  - Receipt: `local/experiments/v2-audio-stream-scdl-chunk-740/002/receipt.json` (`"status": "PASS"`)
  - `/Od` and `/O2`: `audio_stream_scdl_chunk_original_x86_vs_cpp=PASS cases=24 events=36` (0 failed cases, ABI + FPU/MXCSR + arena + scratch snapshot + device/slot state bit-exact)
  - Material mutations: `16/16` detected (`exit_code: 1`)

## Explicit Bounds
- `audio_stream_service_chunk_scdl_00567060`: `1 <= channels <= 4` (original stack pointer array holds 4 slots); non-aliasing stream, entry table, chunk buffer, and slot record.
- `audio_stream_slot_push_chunk_005615c0`: `0 <= index < 16`, `sub_count <= 4`, slot record `capacity >= 1`.
- `audio_stream_deinterleave_chunk_00566b40`: bounded non-overflowing `chunk_len`; `platform_virtual_alloc` / `platform_virtual_free` verified with deterministic scratch arena and exact `(lpAddress, dwSize, flAllocationType, flProtect)` / `(lpAddress, dwSize, dwFreeType)` matching.
- Remaining `Run733` unresolved audio symbols (`00566ea0`, `005612a0`) remain separate boundaries due to larger unrecovered backend subtrees (`00590f70`, `00590ef0`, and `005612a0`'s 8 callees).
