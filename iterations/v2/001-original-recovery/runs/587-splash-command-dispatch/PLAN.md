# Run587 splash command dispatch

Recover only original 004edc00, its four ordered 32-bit stores and its live
cursor/output alias effects. Evidence: Porsche.exe SHA
ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39;
binary-index body 004edc00..004edc2f, 48 bytes
(sha256 `7afecd805ef81d036e77b3e28f580d7c17f023abc55b82cfedc8d540dd9058fc`).
The complete instruction and caller dossier is recorded in scope-evidence.json.

## Status

- Bound `splash_command_dispatch_587.hpp`/`.cpp` and `native-fixture.cpp.in`
  to canonical `porsche::splash_progress_dispatch_004edc00` via
  `porsche/splash_progress.hpp` and configured `native-config.json`.
- Preserved immutable attempt `001` (`local/experiments/v2-splash-command-writes-587/001/`),
  which failed `od-native` at `case=3` due to double `address(item.record)` on line 96 of
  `native-fixture.cpp.in` (fixed to `item.record+12u`).
- Passed attempt `002` (`local/experiments/v2-splash-command-writes-587/002/receipt.json`):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/587-splash-command-dispatch/native-config.json --attempt 002`
  (`/Od` and `/O2` passed 5 cases; `omit-first-store`, `omit-source-store`, and
  `omit-phase-store` mutations all detected with exit 1).

Broader callers, malformed pointers/faults and semantic consumers remain open.
No production source, registry, CMake or global documentation changes belong
to this run.
