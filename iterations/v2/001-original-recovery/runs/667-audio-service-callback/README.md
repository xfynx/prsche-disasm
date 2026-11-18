# Run667 audio service callback (`00590d80`, `00590df0`, `00590e20`, `005616b0`, `00566a40`, `00566910`, `004ad950`, `004ad9c0`)

Bounded native x86-vs-C++ recovery proof for the eight-function audio service callback closure (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 1902 code bytes total; recovers canonical `application_audio_service_callback_004ad9c0` declared by Run556):
- `porsche::audio_u32_mul64_00590d80` (`00590d80..00590de7`, 104B, sha256 `8d05ef0d7dc7fb01f6ff07f3f64ab901b4890eeaf97e23870cff21218485acbe`)
- `porsche::audio_u64_div32_00590df0` (`00590df0..00590e1f`, 48B, sha256 `3126b8aefba75d0ce69e086636d63e1f55194d18fe3b2e570152594c9944177f`)
- `porsche::audio_service_stream_lookup_00590e20` (`00590e20..00590e65`, 70B, sha256 `1c113e1fd292ae26b1de3d9b5633b5d7aacd12527f257ef82977f12ce8266195`)
- `porsche::audio_stream_slot_total_005616b0` (`005616b0..005616c3`, 20B, sha256 `8454f13e18341fff4b667c812cfede9856f5c3c323a8508fe17a3124450ae117`)
- `porsche::audio_service_slot_info_00566a40` (`00566a40..00566adb`, 156B, sha256 `7e0cb2106195ba17c37772484b72d5d7e46577a3b38b855ead3d0de57de6ccbc`)
- `porsche::audio_service_stream_info_00566910` (`00566910..00566a30`, 289B, sha256 `7105ede4827ddbec607c7f6ba7f4df3dac588fb58add9f65a2ec3f031fd5e94d`)
- `porsche::audio_service_split_004ad950` (`004ad950..004ad9b4`, 101B, sha256 `9799fa1351b18bda7d713eed1d273852f7b4617e28663eb702718625693582a7`)
- `porsche::application_audio_service_callback_004ad9c0` (`004ad9c0..004ade19`, 1114B; absent from `functions.jsonl`, supplemented in `original-index-supplement.json`; excludes 6 trailing `0x90` NOPs at `004ade1a..004ade1f`, sha256 `5f2705f6a9c0969a8dd25e851ec1dacc131263f2edad7a0122c795ca25d207e5`)

Indirect-call verification: `004adda7` raw PE bytes `ff 15 80 20 5b 00` execute `call dword ptr [0x005b2080]` (KERNEL32!GetTickCount IAT cell, bound to `porsche::platform_get_tick_count()`).

Reuses canonical symbols (`audio_resource_query_root_00656ab4`, `application_audio_device_state_006b48c0[0xdcu]` aliasing `006b499c`, `audio_stream_slots_006b7cc0`, `frame_services_words_005d1740`, `audio_stream_service_lookup_00566d60`, `audio_stream_service_reset_00567740`, `audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`, `splash_progress_resource_end_004ad6c0`, `audio_service_play_004ad8b0`, `audio_resource_locate_005666f0`, `audio_service_stream_start_00567720`, `render_seed_prng_next_00538040`, `window_worker_activation_00565560`, `audio_stream_service_ramp_00566ae0`, `audio_stream_service_volume_00567810`, `audio_stream_service_status_00567850`, `formatter_text_compare_n_005a2210`, `platform_get_tick_count`).

Owned `.data` tag strings (13 bytes total, uniquely referenced by `004ad9c0` in `references.jsonl`):
- `audio_service_tag_vic_005d1bd4[4]` (`005d1bd4..005d1bd7`, sha256 `c7a09fc120ab81ee344ce8fb6dbf068d17f9269b4840f1c4e96a842574fb8f61`, `"vic"`)
- `audio_service_tag_win_005d1bd8[4]` (`005d1bd8..005d1bdb`, sha256 `20ac7ff5c3b32ba590374983fc75ad4cbc87d528ddddf1ca110b2cdd1a1a2fc8`, `"win"`)
- `audio_service_tag_lose_005d1bdc[5]` (`005d1bdc..005d1be0`, sha256 `a6107ac6200f4d64e697049b9ef412cf8a35615edd9cf3335854dec666e959d8`, `"lose"`)

## Verification

- Attempt `005` (`local/experiments/v2-audio-service-callback-667/005/receipt.json`, sha256 `8869f1bff75fdfa9588df63e07765b65b2354295244174ca24d77e254a8310d2`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `audio_service_callback_667.cpp`, 61 cases each, 18/18 material `wrong-*` mutations detected). Earlier failed attempts `001`..`004` are preserved untouched.
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/667-audio-service-callback/native-config.json --attempt 005`

## Boundaries

Bounded test domain (`PARTIAL`): differential proof uses controlled root/channel/stream/slot arenas and deterministic callee stubs (including ASCII `_strnicmp` stub for `005a2210` and controlled `platform_get_tick_count()` for IAT `005b2080`). Incidental `EAX` on `void` `audio_service_split_004ad950`, null `audio_resource_query_root_00656ab4` dereference, `denom == 0` division in `00566a40`/`00566910`, arbitrary unmapped pointers, live audio backend execution, and production CMake/registry integration remain open.
