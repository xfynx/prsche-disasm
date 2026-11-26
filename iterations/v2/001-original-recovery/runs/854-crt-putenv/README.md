# Run854: CRT putenv wrapper and narrow/wide dispatch

Recovers complete original `crt_putenv_005a38c7` (`005a38c7..005a38e7`) and its private `crt_putenv_inner_005a38e8` (`005a38e8..005a397b`) from Porsche.exe SHA-256 `ddd748fd...ff39`.

The wrapper takes CRT lock 12, calls the inner routine, unlocks 12, and preserves the inner return. The inner routine requires initialized CRT environment state, allocates and installs the narrow `NAME=VALUE` copy through the verified Run838 provider, then mirrors it to the wide environment only when that table exists. The original uses OEM code page `1`, a `-1` source count, and a `wide_count * 2` allocation.

Native proof: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/854-crt-putenv/native-config.json --attempt 003`. Attempt 003 passes 72 original-x86/C++ comparisons in both `/Od` and `/O2` (424 observed direct-callee events per variant); all five material mutations are detected.

The production closure reuses canonical lock/unlock, string, allocation, copy, conversion, and Run838 environment providers. `crt_wsetenv_005aa039` is the sole new typed unresolved boundary. The proof controls that endpoint and does not claim live OS environment acceptance.
