# Run607 frame audio stream ramp (`004ae3c0`, `00566ae0`, `00565dd0`)

Bounded native x86-vs-C++ recovery proof for `porsche::frame_services_boundary_004ae3c0`,
`porsche::audio_stream_service_ramp_00566ae0`, and `porsche::audio_channel_ramp_00565dd0`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `004ae3c0..004ae464` (165 bytes, sha256 `5a830abdc012cff5c0047770e3600566fdd7ff32434942aebd6952010ba49ab1`)
- `00566ae0..00566b37` (88 bytes, sha256 `8824374bc7b6abd7085028e9464bb1eea95a3f7d28e99117d09aa97553565f24`)
- `00565dd0..00565e6e` (159 bytes, sha256 `b3b76f0e2fbd62511e3209d964eea4fe11d2024a362242bdfa68a9116c246293`)
- Zero newly owned `.data` bytes; all referenced globals and boundary declarations are reused
  from `porsche/frame_services.hpp`, `porsche/application_audio_device.hpp`,
  `audio_resource_controls_478.hpp`, `audio_stream_creation_561.hpp`, and
  `audio_canonical_434.hpp`.

## Verification

- Attempt `001` (`local/experiments/v2-frame-audio-stream-ramp-607/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/607-frame-audio-stream-ramp/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `frame_audio_stream_ramp_original_x86_vs_cpp=PASS cases=770 events=3430`,
    comparing relocated original x86 against C++ across `audio_channel_ramp_00565dd0`,
    `audio_stream_service_ramp_00566ae0`, and `frame_services_boundary_004ae3c0` (active/inactive
    audio state `[0xdc]`, negative/valid channels, 0/1/multiple voices with live `006b4a00`
    reload, `steps <= 0` vs `> 0`, `root == 0` vs valid with live `00656ab4` reload,
    `[root+0x0c] <= -1` vs `>= 0`, `mode == 0` vs `!= 0`, `[root+0x14] == 0` vs `!= 0`, and
    `[root+0x70] < 0` vs `>= 0`), verifying `cdecl` ABI, `FXSAVE`/MXCSR preservation, return
    values, event traces, and full state.
  - Mutation controls (`wrong-channel-step-clamp`, `wrong-ramp-scale-shift`,
    `wrong-stream-ms-divisor`, `wrong-boundary-pending-flag`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and controlled boundary stubs for
`audio_stream_service_reset_00567740`, `audio_stream_service_lookup_00566d60`,
`audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`,
`audio_backend_find_channel_00589d20`, and `audio_backend_next_voice_00590340`. Production
CMake/registry integration and unrecovered callers remain open.
