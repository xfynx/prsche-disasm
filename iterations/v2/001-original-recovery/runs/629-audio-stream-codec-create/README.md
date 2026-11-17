# Run629 audio stream codec create (`0056aff0`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::audio_stream_codec_create_0056aff0` (`0056aff0..0056b223`, 564B, sha256 `3c48bdf3f3510051a89235a9fc15545580bdfe77c1e893f47ffa594572f765be`)

Reuses canonical symbols (`audio_stream_codec_bytes_0056afc0`, `heap_lock_create_005321f0`, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`) via `audio_stream_creation_561.hpp`, `audio_stream_service_559.hpp`, `porsche/files.hpp`, `porsche/heap.hpp`, and `porsche/shared_runtime_globals.hpp`.

Owned read-only `.rdata` strings (248B total, no new `.data` globals):
- `stream_err_invalid_filters_005bd8b8[48]` (`0x005bd8b8`, sha256 `cac66de7a7eb6bcb1741b9d2b18f3f75d3ef2637236b7536ecfe200f07533414`)
- `stream_err_invalid_taps_005bd8e8[45]` (`0x005bd8e8`, sha256 `7e574dd99f741bd1b0e491e4f0558ea1ded036f5bbd0adf4fa17803af16435f2`)
- `stream_err_too_many_requests_005bd918[40]` (`0x005bd918`, sha256 `1acdcce0662b465219b0c040a24b6380e7c933c53f4d830bf4ab50c03060ab7b`)
- `stream_err_min_requests_005bd940[55]` (`0x005bd940`, sha256 `dd1148e34482ea40df1ba75c0f67abc071894ade268c30b32d4300a40cdc9dff`)
- `stream_source_file_005bd978[19]` (`0x005bd978`, sha256 `4a87a432224df5a492d35a98ba89e025b801e4b1689c7d6555884b6d00829034`)
- `stream_err_buf_small_005bd98c[41]` (`0x005bd98c`, sha256 `d5cc887bc35a50891f575f1045e3d882a69d48440af09817eb13559d9c2c9121`)

## Verification

- Attempt `001` (`local/experiments/v2-audio-stream-codec-create-629/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/629-audio-stream-codec-create/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and printed `audio_stream_codec_create_original_x86_vs_cpp=PASS cases=63 events=63`, verifying all 6 `.rdata` arrays against raw PE bytes and comparing relocated original x86 against C++ across buffer-size/request/filter/tap validation paths, signed wrapping arithmetic, buffer alignment offsets (`0..31`), lock handle ordering (`'STRM'` written prior to `heap_lock_create_005321f0`), full 80 KiB arena memory, and x87/ABI state.
  - Mutation controls (`wrong-buffer-threshold`, `wrong-requests-min`, `wrong-taps-upper-bound`, `wrong-ring-align`, `wrong-last-request-null`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses real canonical `audio_stream_codec_bytes_0056afc0` and `shared_runtime_globals` with controlled `heap_lock_create_005321f0` and `diagnostic_handler_005debf0` endpoints across an 80 KiB mapped buffer arena. Unmapped/faulting `stream_buf` pointers, concurrency, downstream stream codec consumers, and production CMake/registry integration remain open (PARTIAL).
