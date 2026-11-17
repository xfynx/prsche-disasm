# Run629 audio stream codec create (`0056aff0`)

## Goal and criteria
- Recover original `0056aff0` (`0056aff0..0056b223`, 564B, sha256 `3c48bdf3f3510051a89235a9fc15545580bdfe77c1e893f47ffa594572f765be`) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) implementing `porsche::audio_stream_codec_create_0056aff0`.
- Reuse canonical symbols without duplicate definitions (`audio_stream_codec_bytes_0056afc0`, `heap_lock_create_005321f0`, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74` / `005deb78`) and own the 6 `.rdata` strings (`005bd8b8`, `005bd8e8`, `005bd918`, `005bd940`, `005bd978`, `005bd98c`, 248B total).
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 5 material mutation controls.

## Verified facts
- Disassembly of `0056aff0..0056b223` and `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/` confirm 27 relocations (25 absolute, 2 relative `E8`), 6 `.rdata` strings (248B total, no prior owner in `iterations/v2/001-original-recovery/`), and 0 new `.data` globals.
- Signed range checks (`buf_bytes - min_bytes < 0x6000`, `num_requests` in `[2, 0x100]`, `num_filters` in `[1, 0x10]`, `num_taps` in `[1, num_filters]`) write `stream_source_file_005bd978` and line (`0x3a8`, `0x3ae`, `0x3b4`, `0x3ba`, `0x3c0`) into `005deb74`/`005deb78` and call through `diagnostic_handler_005debf0`.
- Success path writes `'STRM'` (`0x4d525453`) before calling `heap_lock_create_005321f0()`, initializes header offsets `[0x00..0x160]` (leaving `[0x164..0x16f]` untouched), links request nodes (`+0x128` stride, nulling final `+0x0c`), initializes filter entries (`+0x0c` stride) and tap entries (`+0x10` stride, leaving `+0x0c` untouched), computes 32-byte aligned `ring_start`, and returns `taps_base`.
- Attempt `001` (`local/experiments/v2-audio-stream-codec-create-629/001/receipt.json`) passed 63 cases (63 events) at `/Od` and `/O2` with zero `/W4` warnings and detected all 5 mutation controls (`wrong-buffer-threshold`, `wrong-requests-min`, `wrong-taps-upper-bound`, `wrong-ring-align`, `wrong-last-request-null`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `0056aff0` and its 248B `.rdata` strings.
- Unmapped/faulting `stream_buf` pointers, concurrency, downstream stream codec consumers, and production CMake/registry integration remain open (PARTIAL).
