# Run653 audio stream codec & service release (`00566e10`, `0056b3b0`, `0056c140`, `0056c420`, `0056c620`)

Bounded native x86-vs-C++ recovery proof for five audio stream codec and service release/reset/destroy functions (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 1,346 code bytes total):
- `porsche::audio_stream_service_release_00566e10` (`00566e10..00566e33`, 36B, sha256 `53207ea2ce397bb1df94431d284b7a9c02643717470cd2ce5205d36abebf6a1f`, supplemented in `original-index-supplement.json`)
- `porsche::audio_stream_codec_destroy_0056b3b0` (`0056b3b0..0056b45e`, 175B, sha256 `eb1d1d1000e23fc0eb0f3a91b8d917351c17e1f2f73fb87ea18581285e82c72b`)
- `porsche::audio_stream_codec_abort_node_0056c140` (`0056c140..0056c377`, 568B, sha256 `a85ed49b2b67c6dcb24fceafebfb13795bf185987bc7d0c26aaf0a2a283a4d3b`)
- `porsche::audio_stream_codec_reset_0056c420` (`0056c420..0056c537`, 280B, sha256 `0103e90f596744505d318693746b3b4e322e0be24f4d0f45c67b91507d9bf9b8`)
- `porsche::audio_stream_codec_release_chunk_0056c620` (`0056c620..0056c73e`, 287B, sha256 `0e45f351da30eaf61d0d166cb12bbfbeac45f467e94e15226d07ff5332938776`)

Indirect-call verification: `0056b3e6`, `0056c17a`, `0056c456`, `0056c655`, `0056c69d`, and `0056c734` raw PE bytes `ff 15 f0 eb 5d 00` execute `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`).

Reuses canonical symbols (`audio_stream_service_storage_006b7740`, `audio_stream_handle_validate_0056b380`, Run641 codec leaf helpers, `stream_source_file_005bd978`, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`, `heap_enter_005322b0`, `heap_leave_005322c0`, `heap_lock_destroy_005322d0`, `close_00533da0`, `file_current_thread_0055f780`, `file_pump_005366e0`, `file_sleep_0055f740`) and declares unrecovered child `audio_stream_codec_refill_0056baf0(void*, std::uint32_t)`.

Owned read-only `.rdata` strings (273 bytes total, zero `.data` globals):
- `stream_err_destroy_invalid_handle_005bdaa0[40]` (`0x005bdaa0`, sha256 `4ef1ce5f3539753b7c44349cce9893b8c05375fbb031a00e8311002e5378a087`)
- `stream_err_cancelrequest_invalid_handle_005bdd30[46]` (`0x005bdd30`, sha256 `d7d52e0bc0f5040e5282c5dd870177b9146b768f03968cafd6f39bc9e6f85b6d`)
- `stream_err_kill_invalid_handle_005bdd60[37]` (`0x005bdd60`, sha256 `667f008b5c08c6df51b4cace2488ef47f4f37ae4408b187459ebe154b9c3e0f8`)
- `stream_err_release_wrong_stream_005bddac[60]` (`0x005bddac`, sha256 `47b71ef9da75b779b1654c52e6f758c3fb2ad5c7ce727e6cdae3f2a93843b6a0`)
- `stream_err_release_already_released_005bdde8[50]` (`0x005bdde8`, sha256 `65e158cb26120b1c052a9799912d8ab216fc393db5323e55712a4248e895a639`)
- `stream_err_release_invalid_handle_005bde1c[40]` (`0x005bde1c`, sha256 `225a1c3231b760dbc964530e92a0186f5572fea4e8c25facfccc65c7a13ccae2`)

## Verification

- Attempt `008` (`local/experiments/v2-audio-stream-codec-release-653/008/receipt.json`): PASS at `/Od` and `/O2` (`/W4`, 13/13 material `wrong-*` mutations detected; attempts `001`–`007` preserved).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/653-audio-stream-codec-release/native-config.json --attempt 001`

## Boundaries

Bounded test domain (`PARTIAL`): uses real canonical `audio_stream_handle_validate_0056b380`, Run641 codec leaves, `stream_source_file_005bd978`, and `shared_runtime_globals` with controlled heap lock, file close/wait/pump, `file_operation_set_group_005681b0`, `diagnostic_handler_005debf0`, and `audio_stream_codec_refill_0056baf0` endpoints across an 8 KiB mapped arena. Unmapped/faulting pointers, unrecovered `audio_stream_codec_refill_0056baf0` body, concurrent `state28` updates outside the controlled wait loop, and production CMake/registry integration remain open.
