# Run598 startup clock callback

## Goal and criteria
- Recover original `004a4700..004a4759` (90 bytes) as `porsche::startup_sequence_call_004a4700`
  and `00560140..00560176` (55 bytes) as `porsche::clock_worker_register_callback_00560140`
  (`__cdecl`), owning 9 loader-zero `.data` DWORDs (`0x006559e0`, `0x00655a04`, `0x006559e8`,
  `0x006559ec`, `0x006559f0`, `0x00655a00`, `0x006559f4`, `0x006559fc`, `0x005e99b8`) and reusing
  `porsche/clock_worker.hpp`, `porsche/frame_pump.hpp`, and `porsche/startup_sequence.hpp`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 neutral mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-004a4700.json`,
  evidence `ev_63a8672c95d5ea67d19bb1149026ae98bf5aa89c2cf56e5180a6bb6d5ac1c97e`) and PE bytes
  confirm `004a4700` unconditionally zeroes `0x00655a08` and `0x006559e0`, and when
  `0x00655a04 == 0` sets `0x00655a04 = 1`, calls `0x00560140(0x004a45d0)`, and zeroes the 7
  remaining DWORDs (`0x006559e8`, `0x006559ec`, `0x006559f0`, `0x00655a00`, `0x006559f4`,
  `0x006559fc`, `0x005e99b8`).
- PE bytes confirm `00560140` scans `0x006b7c20[0..7]` for an existing match first, then scans
  `0x006b7c20[0..7]` for a `nullptr` slot and writes the callback if found.
- Attempt `002` (`local/experiments/v2-startup-clock-callback-598/002/receipt.json`) passed 178
  cases (0 external events) at `/Od` and `/O2` and detected all 4 mutation controls (attempt `001`
  preserved after `omit-reset-source-zero` anchor collision).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `004a4700`/`00560140` and the 9 owned `.data` DWORDs.
