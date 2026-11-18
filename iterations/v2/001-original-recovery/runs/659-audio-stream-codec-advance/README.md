# Run659 audio stream codec advance & open/close callbacks (`0056b860`, `0056ba20`, `0056ba80`)

Bounded native x86-vs-C++ recovery proof for three audio stream codec advance and async open/close completion functions (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 615 code bytes total):
- `porsche::audio_stream_codec_advance_0056b860` (`0056b860..0056ba10`, 433B, sha256 `7934318957f3fd74c440f7f8f20b10299a959d2361223fd6d1e167561b2f27a5`)
- `porsche::audio_stream_codec_open_done_0056ba20` (`0056ba20..0056ba74`, 85B, sha256 `0c7048ca80924f5deb797afa63eee427b9363c92c115e0099a1f48dfe63b8b99`)
- `porsche::audio_stream_codec_close_done_0056ba80` (`0056ba80..0056bae0`, 97B, sha256 `09c69111b2176f2560a92a51ae1f75ff6a6d32875a6357dd8580559ee99bc3d6`)

Indirect-call verification: `0056b98b`, `0056b9dd`, `0056ba5b`, and `0056bac8` raw PE bytes `ff 15 f0 eb 5d 00` execute `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`). In `0056ba20` (`0056ba5b`, line `0x1e7`), two arguments (`stream_err_unable_to_open_file_005bdc4c`, `codec + 0x5c`) are pushed via inline `__asm` with `add esp, 8` cleanup through the canonical 1-arg cell.

Reuses canonical symbols (`audio_stream_codec_advance_0056b860` declaration and `audio_stream_codec_refill_0056baf0` from Run656, `stream_source_file_005bd978` from Run629, `diagnostic_handler_005debf0`, `operation_complete_00567df0`, `operation_callback_005680c0`, `request_open_00568aa0`, `request_close_00568ae0`, `heap_enter_005322b0`, `heap_leave_005322c0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`).

Owned read-only `.rdata` strings (114 bytes total, zero `.data` globals):
- `stream_err_unable_to_close_005bdbfc[40]` (`0x005bdbfc`, sha256 `f9febd79be8378d7d942cf0154a04d722f02572a70097b4da9daca38a9327745`)
- `stream_err_unable_to_open_005bdc24[39]` (`0x005bdc24`, sha256 `da27c69ec5efca7426511392488414b2aaef64eb70bc4c454c192a89311188d3`)
- `stream_err_unable_to_open_file_005bdc4c[35]` (`0x005bdc4c`, sha256 `0c6ec80e892e46599a47b433580bb4e63cc912c96ee14b3fb96c04cce50d7bd3`)

## Verification

- Attempt `002` (`local/experiments/v2-audio-stream-codec-advance-659/002/receipt.json`, sha256 `b397ae96060212e202d0fa6b758999d5fa5c1eec9a7a868ebd9b94457818e0c5`): PASS at `/Od` and `/O2` (`/W4`, 0 warnings on `audio_stream_codec_advance_659.cpp`, 12 cases / 45 events each, 16/16 material `wrong-*` mutations detected; Attempt `001` also passed with `C4996` on `strcpy`, fixed to `memcpy` in Attempt `002`).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/659-audio-stream-codec-advance/native-config.json --attempt 002`

## Boundaries

Bounded test domain (`PARTIAL`): uses real `stream_source_file_005bd978` and `shared_runtime_globals` with controlled `heap_enter_005322b0`, `heap_leave_005322c0`, `operation_complete_00567df0`, `operation_callback_005680c0`, `request_open_00568aa0`, `request_close_00568ae0`, `diagnostic_handler_005debf0`, and `audio_stream_codec_refill_0056baf0` endpoints across an 8 KiB mapped arena (with `0056ba20`/`0056ba80` callback relocations tested both directly and chained end-to-end). Unmapped/faulting pointers, live async file-I/O completion, and production CMake/registry integration remain open.
