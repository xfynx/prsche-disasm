# Run587 splash command dispatch (`004edc00`)

Bounded native x86-vs-C++ recovery proof for `porsche::splash_progress_dispatch_004edc00`
(`Porsche.exe` SHA `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`,
body `004edc00..004edc2f`, 48 bytes, sha256 `7afecd805ef81d036e77b3e28f580d7c17f023abc55b82cfedc8d540dd9058fc`).

## Native attempts

- `001` (`local/experiments/v2-splash-command-writes-587/001/`): preserved failed attempt.
  `od-native` exited 1 (`divergence cursor reload after aliased first store case=3`) because
  line 96 of `native-fixture.cpp.in` computed `address(item.record)+12u` after line 88 had
  already converted `item.record = address(item.record)` (original-vs-C++ cursor and arena
  comparisons had already passed).
- `002` (`local/experiments/v2-splash-command-writes-587/002/receipt.json`): **PASS** after
  fixing line 96 to `item.record+12u`.
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/587-splash-command-dispatch/native-config.json --attempt 002`
  - Variants: `/Od` and `/O2` both printed `splash_command_dispatch_original_x86_vs_cpp=PASS cases=5`
    (normal, unaligned, high phase bit, cursor cell aliased as first destination, and source store
    overwriting cursor cell; cdecl ABI, final cursor, and full mapped arena checked).
  - Mutation controls: `omit-first-store`, `omit-source-store`, and `omit-phase-store` all
    detected (`exit_code=1`, `divergence`).

## Boundaries

Consumer semantics, malformed pointers/faults, arbitrary aliases, and production source/CMake/registry
integration remain outside this run.
