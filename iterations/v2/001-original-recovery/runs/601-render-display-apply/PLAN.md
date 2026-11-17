# Run601 render display apply

## Goal and criteria
- Recover original `004b70d0..004b713f` (112 bytes) as `porsche::render_display_apply_004b70d0` and
  `0056a680..0056a6a5` (38 bytes) as `porsche::render_frame_timer_reset_0056a680` (`__cdecl`),
  owning file-backed `.data` DWORDs `0x005e517c..0x005e5187` and loader-zero `.data` DWORDs
  `0x006afc7c`, `0x006afc80`, `0x0065b398`, and `0x006a5dd4..0x006a5deb`, reusing
  `porsche/render_startup.hpp`, `porsche/window_runtime.hpp`, `porsche/startup_service_516950.hpp`,
  `../496-render-present-caller-repair/render_display_496.hpp`, and
  `../522-audio-stream-transform/audio_stream_transform_522.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-004b70d0.json`,
  evidence `ev_0d645a436d4fa613e70a8c57a739e53a83dc809b2940a341826a247a67ce791f`) and PE bytes
  confirm `004b70d0` forwards `(field7c, field74, 0x80)` to `00516950`, sets `0x005e517c = 0x3f000000`,
  `0x005e5180 = 0x3f800000`, calls `0056a680`, zeroes `0x006afc7c`, converts
  `uint64_t(0x005e5184) * float(0x005e5180)` via `005a0f98` (`__ftol`), sets `0x0065b398 = 1`,
  and stores `0x005deacc - step` into `0x006afc80`.
- PE bytes and catalog entry (`functions.jsonl`) confirm `0056a680` zeroes `0x006a5dd4`, `0x006a5dd8`,
  `0x006a5de0`, `0x006a5de4`, and `0x006a5de8`, and copies `current_tick_006b7c40` (`0x006b7c40`)
  to `0x006a5ddc`.
- Attempt `001` (`local/experiments/v2-render-display-apply-601/001/receipt.json`) passed 285 cases
  (280 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `004b70d0`/`0056a680` and their 12 owned globals (`0x005e517c..0x005e5187`, `0x006afc7c`,
  `0x006afc80`, `0x0065b398`, `0x006a5dd4..0x006a5deb`).
- Broader caller integration and arbitrary aliases remain open.
