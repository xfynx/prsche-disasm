# Run607 frame audio stream ramp

## Goal and criteria
- Recover original `00565dd0..00565e6e` (159 bytes) as `porsche::audio_channel_ramp_00565dd0`,
  `00566ae0..00566b37` (88 bytes) as `porsche::audio_stream_service_ramp_00566ae0`, and
  `004ae3c0..004ae464` (165 bytes) as `porsche::frame_services_boundary_004ae3c0` (`__cdecl`),
  reusing existing canonical declarations with zero newly owned `.data` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes, and cached REA
  (`local/experiments/v2-frontier-469-rea/001/function-004ae3c0.json`, evidence
  `ev_67d614a14fba6e5937439dc42fb6b73af721c8094c2f99ee2ebdf5d4b2cf6c7f`) confirm the
  exact control flow, field offsets, reloads of `audio_resource_query_root_00656ab4` and
  `audio_backend_channels_006b4a00`, and relocations for `004ae3c0`, `00566ae0`, and
  `00565dd0`.
- Attempt `001` (`local/experiments/v2-frame-audio-stream-ramp-607/001/receipt.json`) passed 770
  cases (3430 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `004ae3c0`, `00566ae0`, and `00565dd0`.
- Production CMake/registry integration and unrecovered callers remain open.
