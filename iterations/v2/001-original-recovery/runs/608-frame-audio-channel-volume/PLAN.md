# Run608 frame audio channel volume

## Goal and criteria
- Recover original `004af900` (112B), `00566340` (50B), `005662b0` (141B), `00589df0` (140B), and `00590d10` (62B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Own the 21 bytes of loader-zero `.data` globals (`006573a4`, `00657388`, `006573a8`, `006573ac`, `00656ae8[2]`) and reuse `porsche/frame_services.hpp`, `porsche/application_audio_device.hpp`, `audio_canonical_434.hpp`, and `audio_stop_435.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes, and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-004af900.json`, `function-00566340.json`) confirm all 5 bodies, relocations, and calling conventions (`__cdecl`).
- `00589df0` computes scaled channel/voice/master gain via signed magic multiplication (`0x4186143d` >> 19), optional envelope scaling via `rec+0x5c` (`0x81020409` >> 6), and optional LUT remapping via `rec+0x54`, storing the byte at `rec+0x3d`.
- `00590d10` invokes `*(hw_rec + 0xd4)(*(hw_rec + 0xa0), (int8_t)ch_rec[0x3d])` and returns `0`.
- `005662b0` looks up `ch = 00589d20(handle)` and iterates voices via `00590340(ch, &voice_slot)`, early-returning `0` if `rec+0x2c == volume << 16`, otherwise updating `rec+0x2c`, zeroing `rec+0x24`, and calling `00589df0` + `00590d10`.
- `00566340` returns `0xfffffff6` if `[006b499c] == 0`, else wraps `005662b0(handle, volume)` in `005896d0`/`005896f0`.
- `004af900` guards non-zero `tag` against `(int8_t)006573a4 == mode` and `00657388 == tag`, mutes `006573a8` and `006573ac` via `00566340(h, 0)`, and stops + clears (`-1`) `00656ae8[0..1]` via `00565d60`.
- Attempt `001` (`local/experiments/v2-frame-audio-channel-volume-608/001/receipt.json`) passed 500 cases (414 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for the 5 functions and 21 bytes of `.data` globals (`006573a4`, `00657388`, `006573a8`, `006573ac`, `00656ae8[2]`).
- Null record tables/callbacks, out-of-range voice slots, arbitrary aliases, and production integration remain open.
