# Run608 frame audio channel volume (`004af900`, `00566340`, `005662b0`, `00589df0`, `00590d10`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::frame_services_boundary_004af900` (`004af900..004af96f`, 112B, sha256 `952dcbe96c15902c7e429038640ecbec7c2c2cac5820bc4444abba0b064261fd`)
- `porsche::frame_services_boundary_00566340` (`00566340..00566371`, 50B, sha256 `5c68e6e28b7b603a2ab29ff76062a7e6886ebfb9018d1e19a2b0f4f67d58ca99`)
- `porsche::audio_channel_volume_005662b0` (`005662b0..0056633c`, 141B, sha256 `5f3ca5b7f89d16fc1fe668eda3d67508504711d16ee60e474c0bb8ac80b7bcea`)
- `porsche::audio_voice_recompute_gain_00589df0` (`00589df0..00589e7b`, 140B, sha256 `0d231a017eb74cdeb3fa399a75d1e4261c974bed5c6ea0d80eb6a5c1909f3a8b`)
- `porsche::audio_voice_apply_gain_00590d10` (`00590d10..00590d4d`, 62B, sha256 `c1f7496256814cbfc7e853b578fdf63897783d1891b7fb94e687a0efd47b6bdf`)

Owned loader-zero `.data` objects (21 bytes total):
- `frame_audio_mode_006573a4` (`0x006573a4`, 1B)
- `frame_audio_tag_00657388` (`0x00657388`, 4B)
- `frame_audio_primary_handle_006573a8` (`0x006573a8`, 4B)
- `frame_audio_secondary_handle_006573ac` (`0x006573ac`, 4B)
- `frame_audio_extra_handles_00656ae8[2]` (`0x00656ae8..0x00656aef`, 8B)

## Verification

- Attempt `001` (`local/experiments/v2-frame-audio-channel-volume-608/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/608-frame-audio-channel-volume/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `frame_audio_channel_volume_original_x86_vs_cpp=PASS cases=500 events=414`, comparing relocated original x86 against C++ across all 5 functions (ABI checks, full state snapshots, and event traces).
  - Mutation controls (`wrong-inactive-device-return`, `wrong-unchanged-volume-early-return`, `wrong-envelope-divisor-shift`, `wrong-mode-tag-guard`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `application_audio_device_state_006b48c0`, `audio_backend_channels_006b4a00`, `audio_backend_voice_table_006b489c`, `audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`, `audio_backend_find_channel_00589d20`, `audio_backend_next_voice_00590340`, `audio_channel_stop_00565d60`, and `hw_rec+0xd4` callbacks. Null record tables/callbacks, out-of-range voice slots, arbitrary aliases, and production CMake/registry integration remain open.
