# Run623 audio stream service consumed

## Goal and criteria
- Recover original `00566d80` (`audio_stream_service_compact_00566d80`, 131B) and `00566e40` (`audio_stream_service_consumed_00566e40`, 95B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse `audio_stream_service_storage_006b7740` and `audio_stream_service_consumed_00566e40` via `audio_stream_creation_561.hpp` with zero new `.data` or `.rdata` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`) and PE bytes (`3e88637509337eaac214314428172a1c6ea781e4a9cd1757071abd8d6be0c5e7`, `f7d3672e95dbf6fe7ea4e521874e9fc8fa2607145be2be9a412041c947d06970`) confirm:
  - `00566d80` (`__cdecl`, 1 arg, 131B) has 1 `ABS32` relocation at `+0x14` (`00566d94`) to `006b7740`. It indexes `slots[handle_word & 0xff]`, compacts `0x2c`-byte records whose `[rec+4] != handle_word` while updating signed `entry[0x17]` to `write_idx` when `read_idx == static_cast<int8_t>(entry[0x17])`, decrements `entry[0x16]`, and decrements `entry[0x17]` if `static_cast<int8_t>(entry[0x17]) > static_cast<int8_t>(entry[0x16])`.
  - `00566e40` (`__cdecl`, 2 args, 95B; referenced as a callback pointer at `0056745c` in `005673d0`) has `ABS32` relocations at `+0x0b` (`00566e4b`) to `006b7780` and `+0x12` (`00566e52`) to `006b7740`, plus a `REL32` `E8` call at `+0x4b` (`00566e8b`) to `00566d80`. It looks up `state = *slots[index_map[service_id]]`, clamps per-record consumption to `state+0x1c` with carry-over, advances `state+0x14`, reduces `state+0x1c`, calls `00566d80(state+0x04)` when `*(state+0x14) >= *(state+0x18)`, and loops while `carry != 0`.
- Attempt `001` (`local/experiments/v2-audio-stream-service-consumed-623/001/receipt.json`) passed 110 cases at `/Od` and `/O2` with zero `.data`/`.rdata` bytes and detected all 4 mutation controls (`wrong-cursor-clamp`, `wrong-record-stride`, `wrong-compact-threshold`, `wrong-cursor-match-write`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00566d80` and `00566e40`.
- Domain bound: `consumed_bytes > *(state + 0x1c)` requires compaction to shift a subsequent record with positive `*(state + 0x1c)` into `state`; out-of-range `service_id`/`slot_index`, null pointers, and production integration remain open.
