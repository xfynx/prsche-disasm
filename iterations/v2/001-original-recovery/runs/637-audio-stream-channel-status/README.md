# Run637 audio stream channel status (`00567810`, `00567850`, `00591320`)

Bounded native x86-vs-C++ recovery proof for `porsche::audio_stream_service_volume_00567810`,
`porsche::audio_stream_service_status_00567850`, and `porsche::audio_channel_status_00591320`
(`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `00567810..0056784f` (64 bytes, sha256 `3de16d2b4c489ecfe4d745626df141a55b789b4119960fcd8912a781fb3ba9a1`)
- `00567850..00567893` (68 bytes, sha256 `cd1370530c5f9be45cce0af175ed88cd1cd22968c918b6605dbccf780d5b94a1`)
- `00591320..00591372` (83 bytes, sha256 `78e8298a6550549ec14a007e8300da151c9eff76f4808396bd6d3a36c26f78ec`)
- Zero `.data` and zero `.rdata` bytes; all referenced globals and boundary declarations are
  reused from `porsche/frame_services.hpp`, `porsche/application_audio_device.hpp`,
  `audio_stream_creation_561.hpp`, and `audio_canonical_434.hpp` (avoiding `audio_channel_voice_lookup_422.hpp`).

## Verification

- Attempt `001` (`local/experiments/v2-audio-stream-channel-status-637/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/637-audio-stream-channel-status/native-config.json --attempt 001`
  - `/Od` and `/O2` both printed `audio_stream_channel_status_original_x86_vs_cpp=PASS cases=513 events=1620`,
    comparing relocated original x86 against C++ across `audio_channel_status_00591320`,
    `audio_stream_service_status_00567850`, and `audio_stream_service_volume_00567810`
    (inactive/active `[0xdc]`, missing/present `00566d60` slot, negative/valid channel index,
    live `006b4a00` reload during `005896f0`, `int8_t` sign extension of `rec[0x3d]` and `obj[0xe4]`,
    `status >= 0` vs `< 0` fallback, `uint8_t` store to `obj[0xe4]` before `00566340`, full 32-bit
    `volume` forwarding, and discarded `00566340` return), verifying `cdecl` ABI, `FXSAVE`/MXCSR
    preservation, return values, event traces, and full state.
  - All 8 mutation controls (`wrong-volume-inactive-device-return`, `wrong-volume-target-byte-store`,
    `wrong-volume-discard-return`, `wrong-status-negative-fallback-guard`,
    `wrong-status-fallback-sign-extension`, `wrong-channel-status-missing-return`,
    `wrong-channel-status-stride`, `wrong-channel-status-sign-extension`) exited `1` on `divergence`.

## Boundaries

Bounded test domain (`PARTIAL`): uses test-only storage and controlled boundary stubs for
`audio_stream_service_lookup_00566d60`, `frame_services_boundary_00566340`,
`audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`, and
`audio_backend_find_channel_00589d20`. Production CMake/registry integration and unrecovered
callers remain open.
