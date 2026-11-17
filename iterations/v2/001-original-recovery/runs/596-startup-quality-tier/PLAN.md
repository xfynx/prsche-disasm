# Run596 startup quality tier

## Goal and criteria
- Recover original `0044e370..0044e405` (150 bytes) as `porsche::render_quality_tier_0044e370`
  and `0044dfb0..0044dfd2` (35 bytes) as `porsche::startup_sequence_call_0044dfb0` (`__cdecl`),
  owning loader-zero `render_quality_selected_00619770` (`0x00619770`) and reusing canonical
  headers (`porsche/startup_sequence.hpp`, `porsche/render_mode.hpp`,
  `porsche/application_state.hpp`, `../494-render-resource-leaves/render_resource_494.hpp`).
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 neutral mutation controls.

## Verified facts
- Cached REA dossier (`local/experiments/v2-frontier-469-rea/001/function-0044dfb0.json`,
  evidence `ev_4f4084a66d5f6f054ae092565b73aad6bfc3e74c67fe18591eb1d619a6e3bb60`) and PE bytes
  confirm `0044dfb0` calls `0044e370`, stores the raw tier at `0x00657d88`
  (`application_state_006573e8.word(0x00657d88u)`), clamps `3 -> 2` when `0x0061978c < 0x20u`,
  and writes `render_quality_selected_00619770` (`0x00619770`).
- PE bytes and catalog entry (`functions.jsonl`) confirm `0044e370` divides `0x005ce908` by
  `1000000` (signed), reads `state0 >> 20` from `0x00619790`, calls `0x0053c3d0` and divides
  twice by `1024` (signed), and evaluates tier thresholds `0..3` with unsigned `0x0061978c > 0x10u`.
- Attempt `001` (`local/experiments/v2-startup-quality-tier-596/001/receipt.json`) passed 9,504
  cases (9,504 events) at `/Od` and `/O2` and detected all 4 mutation controls.

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for
  `0044dfb0`/`0044e370` and `0x00619770`.
