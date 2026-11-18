# Run641 audio stream codec leaves (`0056bce0`, `0056bd10`, `0056c380`, `0056c3e0`, `0056c540`)

Bounded native x86-vs-C++ recovery proof for five zero-unrecovered-callee audio stream codec leaf helpers (`Porsche.exe` SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 493 code bytes total):
- `porsche::audio_stream_ring_contains_0056bce0` (`0056bce0..0056bd08`, 41B, sha256 `c3a26795b666ad068eda385f9d795553845f366f46eaa79f930cf957ba1283eb`)
- `porsche::audio_stream_request_unlink_0056bd10` (`0056bd10..0056bd62`, 83B, sha256 `867cc6c575eb1bb7ae917cbe740c6a96548a9ee058d30781613ff61560384c24`)
- `porsche::audio_stream_consume_bytes_0056c380` (`0056c380..0056c3d9`, 90B, sha256 `a7b103ac2d05ff7acb0d14f4cf06f8f6a5f5c094d705214f59651c68c91fa607`)
- `porsche::audio_stream_request_lookup_0056c3e0` (`0056c3e0..0056c419`, 58B, sha256 `864a69b605fcddba20caafb61bce75060d67a1213e7f6a321a2107e0408287d9`)
- `porsche::audio_stream_get_0056c540` (`0056c540..0056c61c`, 221B, sha256 `289e2fe4a2e4cad9c6fd74fcfdb28d2aceb733e22a89ebbb6dee17e778cce541`)

Indirect-call verification: `0056c575` raw PE bytes `ff 15 f0 eb 5d 00` execute `call dword ptr [0x005debf0]` (`diagnostic_handler_005debf0`), identical to `0056aff0`.

Reuses canonical symbols (`heap_enter_005322b0`, `heap_leave_005322c0`, `file_operation_set_group_005681b0`, `audio_stream_handle_validate_0056b380`, `stream_source_file_005bd978`, `diagnostic_handler_005debf0`, `shared_runtime_word_005deb74`, `shared_runtime_word_005deb78`) via `porsche/files.hpp`, `porsche/heap.hpp`, `porsche/shared_runtime_globals.hpp`, `audio_codec_access_565.hpp`, `audio_greedy_transition_568.hpp`, and `audio_stream_codec_create_629.hpp`.

Owned read-only `.rdata` string (36 bytes, zero `.data` globals):
- `stream_err_get_invalid_handle_005bdd88[36]` (`0x005bdd88`, `"STREAM_get - invalid stream handle\n"`, sha256 `b9051bbf37f4e477effc3d6a97182d32925e1445257dfe4608abf8388db2bf3d`)

## Verification

- Attempt `003` (`local/experiments/v2-audio-stream-codec-leaves-641/003/receipt.json`): **PASS** (attempts `001`/`002` preserved as immutable historical runs where `wrong-get-remaining-inclusive` / `wrong-get-wrap-sentinel` hit uninitialized arena bytes before those two fixture cases were populated).
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/641-audio-stream-codec-leaves/native-config.json --attempt 003`
  - `/Od` and `/O2` compiled with zero warnings (`/W4`) and both printed `audio_stream_codec_leaves_original_x86_vs_cpp=PASS cases=88 events=41`, verifying `005bdd88` and `005bd978` raw PE bytes and comparing relocated original x86 against C++ across unsigned wrapped ring membership, all doubly-linked active/cursor/free-stack unlink topologies, signed wrapping byte-consumption thresholds and greedy callbacks, `0x128`-stride request lookup, and `STREAM_get` handle validation, chunk-tag clearing, lock caching/re-read ordering, ring-wrap `-1` sentinel traversal, ABI, x87/MXCSR state, and full 8 KiB arena memory.
  - All 9 mutation controls (`wrong-ring-contains-end-inclusive`, `wrong-unlink-active-fallback`, `wrong-consume-threshold-strict`, `wrong-consume-greedy-flag-order`, `wrong-lookup-stride`, `wrong-lookup-index-mask`, `wrong-get-clear-tag-bits`, `wrong-get-remaining-inclusive`, `wrong-get-wrap-sentinel`) exited `1` on `divergence`.

## Boundaries

Bounded test domain (`PARTIAL`): uses real canonical `audio_stream_handle_validate_0056b380`, `stream_source_file_005bd978`, and `shared_runtime_globals` with controlled `heap_enter_005322b0`, `heap_leave_005322c0`, `file_operation_set_group_005681b0`, and `diagnostic_handler_005debf0` endpoints across an 8 KiB mapped arena. Unmapped/faulting pointers, unlinked chunk rings, concurrency, parent callers (`0056c140`/`0056c420`/`0056b3b0`), and production CMake/registry integration remain open.
