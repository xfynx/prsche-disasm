# Run623 audio stream service consumed (`00566d80`, `00566e40`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::audio_stream_service_compact_00566d80` (`00566d80..00566e02`, 131B, sha256 `3e88637509337eaac214314428172a1c6ea781e4a9cd1757071abd8d6be0c5e7`)
- `porsche::audio_stream_service_consumed_00566e40` (`00566e40..00566e9e`, 95B, sha256 `f7d3672e95dbf6fe7ea4e521874e9fc8fa2607145be2be9a412041c947d06970`)

Reuses `audio_stream_service_storage_006b7740` and `audio_stream_service_consumed_00566e40` from `audio_stream_creation_561.hpp` with zero new `.data` or `.rdata` bytes.

## Verification

- Attempt `001` (`local/experiments/v2-audio-stream-service-consumed-623/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/623-audio-stream-service-consumed/native-config.json --attempt 001`
  - `/Od` and `/O2` compiled cleanly (`/W4`, zero `.data` or `.rdata` sections in `od-0.obj`/`o2-0.obj`) and printed `audio_stream_service_consumed_original_x86_vs_cpp=PASS cases=110`, comparing relocated original x86 against C++ across empty/negative counts, `0x2c`-byte record compaction, signed `entry[0x17]` cursor updates and clamping, all 16 `service_id` slots, threshold boundaries, and multi-record carry compaction.
  - Mutation controls (`wrong-cursor-clamp`, `wrong-record-stride`, `wrong-compact-threshold`, `wrong-cursor-match-write`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses a test-only definition of `audio_stream_service_storage_006b7740`. In `00566e40`, cases where `consumed_bytes > *(state + 0x1c)` require compaction at `*(state + 0x14) >= *(state + 0x18)` to shift a subsequent record with positive `*(state + 0x1c)` into `state` (otherwise the carry loop does not terminate on either original x86 or C++). Out-of-range `service_id`/`slot_index`, null slot/record pointers, and production CMake/registry integration remain open.
