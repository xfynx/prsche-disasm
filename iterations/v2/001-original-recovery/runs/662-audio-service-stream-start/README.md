# Run662 audio service stream start & queue (`0056b790`, `0056b800`, `0056b690`, `0056c040`, `00567550`)

Bounded native x86-vs-C++ recovery proof for five audio stream request-queueing and service-start functions (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 955 code bytes total; closes `audio_service_stream_start_00567550` frontier dependency called by `audio_callback_resource_564.cpp`):
- `porsche::audio_stream_codec_alloc_request_0056b790` (`0056b790..0056b7f8`, 105B, sha256 `34f012e052cf9303930d6d75fa23fa7a7ece0b13b24dcf3f9f729288f7d7bfa0`)
- `porsche::audio_stream_codec_enqueue_request_0056b800` (`0056b800..0056b85a`, 91B; excludes 5 trailing `0x90` NOPs at `0056b85b..0056b85f`, sha256 `4aadac1dcbfd0f90cbaea291eda7441848f0a09dc29a99da5bcfeb6889981b5e`)
- `porsche::audio_stream_codec_queue_file_0056b690` (`0056b690..0056b789`, 250B, sha256 `3bf0f6a00ddb6c9fd46f1910c7ef9f5de003e3dc2c5e1bbc503a399c3f22e9eb`)
- `porsche::audio_stream_codec_queue_memory_0056c040` (`0056c040..0056c131`, 242B, sha256 `3be6197e4425e92db0b9bf9c6f13c12d7f15baff5d3281c556a3aca77054daef`)
- `porsche::audio_service_stream_start_00567550` (`00567550..0056765a`, 267B, sha256 `b9eeaa6a11b9823aee36d503f54fdf85d06b29c71c5f18d423f6f98b4a64e76c`)

Indirect-call verification: `0056b6c6` and `0056c076` raw PE bytes `ff 15 f0 eb 5d 00` execute `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`, 1 arg at lines `0x617` and `0x677`).

Reuses canonical symbols (`heap_enter_005322b0`, `heap_leave_005322c0`, `audio_stream_handle_validate_0056b380` from Run565, `audio_stream_codec_advance_0056b860` from Run656, `audio_stream_service_lookup_00566d60` from Run561, `audio_backend_lock_005896d0` and `audio_backend_unlock_005896f0` from Run434, `application_audio_device_state_006b48c0[0xdc]` aliasing `006b499c`, `stream_source_file_005bd978` from Run629, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`).

Owned read-only `.rdata` strings (83 bytes total) and loader-zero `.data` BSS (4 bytes):
- `stream_err_queuefile_invalid_005bdbd0[42]` (`0x005bdbd0..0x005bdbf9`, sha256 `f16642d8073b00a3dd33119252b5800e743e347af8475723b1d6093c952a1301`)
- `stream_err_queuemem_invalid_005bdd04[41]` (`0x005bdd04..0x005bdd2c`, sha256 `084a9d1dd6854d67d9fadeb9107ee274e94b6005e833dfb0e1fea220db513089`)
- `audio_stream_request_serial_006a5df0` (`0x006a5df0..0x006a5df3`, 4B loader-zero `.data` BSS, referenced only by `0056b790`)

## Verification

- Attempt `001` (`local/experiments/v2-audio-service-stream-start-662/001/receipt.json`, sha256 `bbbdb67f43766e276dacb4e2ebf01dcccb9da18d0d3f823acc06a1fde5f09b7d`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `audio_service_stream_start_662.cpp`, 29 cases / 101 events each, 16/16 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/662-audio-service-stream-start/native-config.json --attempt 001`

## Boundaries

Bounded test domain (`PARTIAL`): uses real Run565 `audio_stream_handle_validate_0056b380`, Run629 `stream_source_file_005bd978`, `shared_runtime_globals`, `application_audio_device_state_006b48c0[0xdc]`, and PE `005a28a0` (`_strncpy` on the original side) with controlled `heap_enter_005322b0`, `heap_leave_005322c0`, `audio_stream_codec_advance_0056b860`, `audio_stream_service_lookup_00566d60`, `audio_backend_lock_005896d0`, `audio_backend_unlock_005896f0`, and `diagnostic_handler_005debf0` endpoints across an 8 KiB mapped arena. Unmapped/faulting pointers, live backend/codec execution, and production CMake/registry integration remain open.
