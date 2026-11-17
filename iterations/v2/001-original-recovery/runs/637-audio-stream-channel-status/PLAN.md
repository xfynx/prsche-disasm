# Run637 audio stream channel status

## Goal and criteria
- Recover original `00567810..0056784f` (64 bytes) as `porsche::audio_stream_service_volume_00567810`,
  `00567850..00567893` (68 bytes) as `porsche::audio_stream_service_status_00567850`, and
  `00591320..00591372` (83 bytes) as `porsche::audio_channel_status_00591320` (`__cdecl`),
  reusing existing canonical declarations with zero newly owned `.data` or `.rdata` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 8 material mutation controls.

## Verified facts
- Direct disassembly from `local/game/Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) and `functions.jsonl`/`references.jsonl` confirm all 3 bodies, byte sizes/SHA-256s, relocations, and `__cdecl` calling conventions.
- Canonical `audio_canonical_434.hpp` owns the typed references for `audio_backend_channels_006b4a00`, `audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`, and `audio_backend_find_channel_00589d20` without conflicting with `audio_channel_voice_lookup_422.hpp`.
- `audio_stream_creation_561.hpp` provides `audio_stream_service_lookup_00566d60`, `porsche/application_audio_device.hpp` provides `application_audio_device_state_006b48c0` (`0x006b499c == [0xdcu]`), and `porsche/frame_services.hpp` provides `frame_services_boundary_00566340`.
- Attempt `001` (`local/experiments/v2-audio-stream-channel-status-637/001/receipt.json`) passed 513 cases (1620 events) at `/Od` and `/O2` and detected all 8 material mutation controls (`wrong-*`).
- COFF section audit of `audio_stream_channel_status_637.cpp` confirms zero `.data` and zero `.rdata` sections.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00567810`, `00567850`, and `00591320`.
- Bounded test domain uses test-only storage and controlled boundary stubs; production CMake/registry integration and unrecovered callers remain open.
