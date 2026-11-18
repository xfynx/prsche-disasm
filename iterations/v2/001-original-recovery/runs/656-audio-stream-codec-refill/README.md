# Run656 audio stream codec refill & ring parse (`0056baf0`, `0056bd70`, `0056be40`, `0056c000`)

Bounded native x86-vs-C++ recovery proof for four audio stream codec refill and ring parsing functions (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 1,179 code bytes total):
- `porsche::audio_stream_codec_refill_0056baf0` (`0056baf0..0056bcda`, 491B, sha256 `c696b811c7c9d07c46753ae15753780f2e6b4995b992198bca69dab1b49a183a`)
- `porsche::audio_stream_codec_read_done_0056bd70` (`0056bd70..0056be30`, 193B, sha256 `2dbfea5b820f8dcadfa65485477dd0c98f74351a980d2024cf3b26c7be7f6df5`)
- `porsche::audio_stream_codec_process_ring_0056be40` (`0056be40..0056bff2`, 435B, sha256 `994f168245534cd55c3733e907b87689e86597090b68e8f443c55f4b02a7e5db`)
- `porsche::audio_stream_codec_match_tap_0056c000` (`0056c000..0056c03b`, 60B, sha256 `47cbab69c9f1a826e7aa58d48842456f844a51a4efec969ac6899712fa8e4354`)

Indirect-call verification: `0056bcbc`, `0056beab`, and `0056bfd7` raw PE bytes `ff 15 f0 eb 5d 00` execute `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`).

Reuses canonical symbols (`audio_stream_ring_contains_0056bce0`, `audio_stream_request_unlink_0056bd10`, `stream_source_file_005bd978`, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`, `heap_enter_005322b0`, `heap_leave_005322c0`, `operation_complete_00567df0`, `operation_callback_005680c0`, `request_read_00568b10`) and declares unrecovered child `audio_stream_codec_advance_0056b860(void*, std::uint32_t)`.

Owned read-only `.rdata` strings (143 bytes total, zero `.data` globals):
- `stream_err_unable_to_read_005bdc70[39]` (`0x005bdc70`, sha256 `b8e2c00934702510126720e8b8298dcc27d65c3c66d7a7548798706c93a5bfc3`)
- `stream_err_invalid_chunk_005bdc98[66]` (`0x005bdc98`, sha256 `f2e66a2ee5bf8c829acb67e65ca74716611f0e8318182559859df3202edc569a`)
- `stream_err_abort_tap_005bdcdc[38]` (`0x005bdcdc`, sha256 `259635bd48b26ca71cea5e10aa39cf4ee6fc799aeed5c0608d68d1a727f881ef`)

## Verification

- Attempt `001` (`local/experiments/v2-audio-stream-codec-refill-656/001/receipt.json`, sha256 `d85394801e2236fc2811d53fb6f5a4eb3c71cedc63a88f23b85f074e6217784e`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings, 27 cases / 80 events each, 14/14 material `wrong-*` mutations detected).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/656-audio-stream-codec-refill/native-config.json --attempt 001`

## Boundaries

Bounded test domain (`PARTIAL`): uses real Run641 codec leaf helpers, `stream_source_file_005bd978`, and `shared_runtime_globals` with controlled heap lock, file operation/read, `diagnostic_handler_005debf0`, and `audio_stream_codec_advance_0056b860` endpoints across a 32 KiB mapped arena. Unmapped/faulting pointers, live async file-I/O completion, unrecovered `audio_stream_codec_advance_0056b860` body, and production CMake/registry integration remain open.
