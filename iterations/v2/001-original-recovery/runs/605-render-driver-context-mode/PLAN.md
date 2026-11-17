# Run605 render driver context mode

## Goal and criteria
- Recover original `00549220..005492ed` (206 bytes) as `porsche::render_driver_context_mode_00549220`
  (`__fastcall`) and `005381d0..00538222` (83 bytes) as `porsche::render_driver_shift_bias_005381d0`
  (`__cdecl`), owning file-backed `.data` DWORDs `0x005dea60` and `0x005dea78` and reusing
  `porsche/render_loader.hpp`, `porsche/game_setup.hpp`, and
  `../479-audio-mixer-ramp-stop/audio_mixer_ramp_stop_479.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`) and PE bytes confirm `005381d0` returns
  `005dea60 >> 23`, clamps `shift` to `[0, 16]` (`shift << 23` in `005dea60`), sets `005dea78` to
  `0xffffffff`, and is called by `00549220` (`0054928f`), `00432ad5`, and `00432b2c`.
- PE bytes confirm `00549220` queries `[0x6bd97c](0x3f, buf)`, compares `mode`-indexed
  40-byte entries in `(*game_setup_movie_service_0069ed0c)->modes` scaled by `1.5f` (`0x005b246c`)
  against `buf[1]` and `buf[3]` via x87 `fcomp`, conditionally sets `0x10000` in `self+0x117e4`
  and `shift=1`, calls `005381d0(shift)`, stores `(float)(1 << shift)` at `self+0x117e8`, and
  sets `0x20000` in `self+0x117e4` when `[0x6bd934]()[0x4c..0x4e]` matches `"DX7"`.
- Attempt `001` (`local/experiments/v2-render-driver-context-mode-605/001/receipt.json`) passed 377
  cases (322 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `00549220`/`005381d0` and owned globals `0x005dea60`/`0x005dea78`.
- Out-of-range mode indices, null service/self pointers, arbitrary aliases, and production
  integration remain open.
