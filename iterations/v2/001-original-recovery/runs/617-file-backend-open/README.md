# Run617 file backend open (`00568900`)

Bounded native x86-vs-C++ recovery proof for:
- `porsche::file_backend_open_00568900` (`00568900..005689a9`, 170B, sha256 `22c0e608b84a8d6c56614a4dbd829fd386348103e2a099a8a2072dfd2b9b205c`)

Reuses canonical declarations (`porsche/file_worker.hpp`, `porsche/formatter_search.hpp`, `porsche/formatter_strings.hpp`, `porsche/disk_open.hpp`, `porsche/files.hpp`, `../488-network-callback-drain/network_callback_drain_488.hpp`) with zero new `.data` or `.rdata` bytes.

## Verification

- Attempt `001` (`local/experiments/v2-file-backend-open-617/001/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/617-file-backend-open/native-config.json --attempt 001`
  - `/Od` and `/O2` both compiled cleanly (`/W4`) and printed `file_backend_open_original_x86_vs_cpp=PASS cases=120 events=312`, comparing relocated original x86 against C++ across direct disk opens, `'|'`-delimited prefix/tail splits, `flags == 0`/`flags != 0`, `ctx.status == 0`/`!= 0`, and `ctx.handle_or_tail` mutations inside `00580e60`.
  - Mutation controls (`wrong-pipe-delimiter`, `wrong-zero-block-arg`, `wrong-tail-slot`, `wrong-status-guard`) all exited `1` on `divergence`.

## Boundaries

Bounded test domain uses test-only storage and providers for `free_auxiliary_006a5c38`, `formatter_search_character_005a2780`, `formatter_error_copy_n_005a28a0`, `disk_physical_open_005919a0`, and `network_callback_enumerate_locked_00580e60`, passing literal visitor `0x005689b0u`. Recovery of visitor `005689b0`, null `path` pointers, prefix lengths >= 260 bytes, and production CMake/registry integration remain open.
