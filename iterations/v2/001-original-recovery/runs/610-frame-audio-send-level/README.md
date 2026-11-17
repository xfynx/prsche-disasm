# Run610 frame audio send level (`00565cd0`, `00590290`, `005902a0`, `00589d70`, `00598eb0`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::frame_services_boundary_00565cd0` (`00565cd0..00565d58`, 137B, sha256 `37db905daea42465abe5c02e1237f35e96dbf83374682a9d086f610a85fb488f`)
- `porsche::audio_send_validate_00590290` (`00590290..00590292`, 3B, sha256 `4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e`)
- `porsche::audio_channel_send_level_005902a0` (`005902a0..0059033c`, 157B, sha256 `d9c5cf7a14b041080a02afa2d9a157e1c7995f449693217867c8a97caada2b53`)
- `porsche::audio_voice_recompute_send_00589d70` (`00589d70..00589de8`, 121B, sha256 `ad5c9f92237398e9a6c81fe662d10fe76b36470105f4feea9919df13f31a75fb`)
- `porsche::audio_voice_apply_send_00598eb0` (`00598eb0..00598f12`, 99B, sha256 `c2d6d7a1fa958a0c418754fcc07c32149f26638de4b5b3fef49d8d850cc242c9`)

Zero new `.data` bytes; all referenced state (`application_audio_device_state_006b48c0`, `audio_backend_channel_count_006b49a4`, `audio_backend_channels_006b4a00`, `audio_backend_voice_table_006b489c`) and lock/lookup/voice-iteration helpers are reused from canonical headers.

## Verification

- Attempt `001` (`local/experiments/v2-frame-audio-send-level-610/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/610-frame-audio-send-level/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `frame_audio_send_level_original_x86_vs_cpp=PASS cases=1129 events=642`, comparing relocated original x86 against C++ across all 5 functions (ABI checks, full state snapshots, and event traces).
  - Mutation controls (`wrong-bus-flag-default`, `wrong-inactive-send-return`, `wrong-recompute-magic-shift`, `wrong-hw-channel-bit-mask`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain covers `bus` in `{0, 1}` with flag masks `{0x00, 0x20, 0x80, 0xa0, 0xe0}`, active/inactive audio system (`[0xdc] == 0` vs `1`), `channel_count` in `{-1, 0, 1, 2}`, `hw_rec[0] & 0x10` `0` vs `0x10`, and positive/negative signed byte values in `0x44`, `0x45`, `0x14c`, `0x14d`, using test-only storage and providers. Null record tables/callbacks, `bus >= 2`, out-of-range voice slots, arbitrary aliases, and production CMake/registry integration remain open.
