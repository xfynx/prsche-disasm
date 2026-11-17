# Run610 frame audio send level

## Goal and criteria
- Recover original `00565cd0` (137B), `00590290` (3B), `005902a0` (157B), `00589d70` (121B), and `00598eb0` (99B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse `porsche/frame_services.hpp`, `porsche/application_audio_device.hpp`, `audio_canonical_434.hpp`, and `audio_stop_435.hpp` with zero new `.data` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes, and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-00565cd0.json`) confirm all 5 bodies, relocations, and calling conventions (`__cdecl`).
- `00590290` returns `0`.
- `00589d70` multiplies signed `rec[bus + 0x45]` and `rec[bus + 0x44]`, scales by signed bus L/R masters at `006b4a0c + (bus << 4)` and `006b4a0d + (bus << 4)` via signed magic `0x82061029` >> 13 with sign-bit adjustment, and stores `rec[bus + 0x46]` and `rec[bus + 0x47]`.
- `00598eb0` selects signed `ch_rec[bus + 0x47]` when `(*hw_rec & 0x10) != 0` else `ch_rec[bus + 0x46]`, invokes `*(hw_rec + 0xd8)(*(hw_rec + 0xa4), val)`, and returns `0`.
- `005902a0` returns `-10` if `[006b499c] == 0`, else locks (`005896d0`), finds channel (`00589d20`), iterates voices (`00590340`), stores `rec[bus + 0x45] = (uint8_t)level`, calls `00589d70` and `00598eb0`, unlocks (`005896f0`), and returns `ch`.
- `00565cd0` extracts `bus = bus_flags & 0xffffff1f`, defaults `(flags & 0xe0) == 0` to `0xe0`, writes `006b4a0c + (bus << 4)` on `0x20` and `006b4a0d + (bus << 4)` on `0x80`, checks `00590290(flags, level) >= 0`, and if `[006b499c] != 0` and `(int16_t)006b49a4 > 0`, calls `005902a0(handle, bus, (int8_t)rec[bus + 0x45])` across active channel records.
- Attempt `001` (`local/experiments/v2-frame-audio-send-level-610/001/receipt.json`) passed 1129 cases (642 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-bus-flag-default`, `wrong-inactive-send-return`, `wrong-recompute-magic-shift`, `wrong-hw-channel-bit-mask`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for the 5 functions.
- Null record tables/callbacks, `bus >= 2`, out-of-range voice slots, arbitrary aliases, and production integration remain open.
