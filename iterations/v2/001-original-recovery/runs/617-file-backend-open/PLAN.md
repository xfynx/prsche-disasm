# Run617 file backend open

## Goal and criteria
- Recover original `00568900` (`file_backend_open_00568900`, 170B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations (`porsche/file_worker.hpp`, `porsche/formatter_search.hpp`, `porsche/formatter_strings.hpp`, `porsche/disk_open.hpp`, `porsche/files.hpp`, `../488-network-callback-drain/network_callback_drain_488.hpp`) with zero new `.data` or `.rdata` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`22c0e608b84a8d6c56614a4dbd829fd386348103e2a099a8a2072dfd2b9b205c`), and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-00568900.json`, `ev_6f1e3068d5a9c4682eb21db069eb02a79b47797303d2f1ab8c5dc8c9b743e7f1`) confirm the 170B body, `__cdecl` 3-arg calling convention, 1 `ABS32` relocation (`0x90` -> `006a5c38`), 4 `REL32` calls (`0x14` -> `005a2780`, `0x44` -> `005a28a0`, `0x67` -> `005919a0`, `0x95` -> `00580e60`), and literal `0x005689b0` push at `0x8b`.
- Assembly trace (`0x568937..0x568954`) confirms that with `ESI` pushed on the stack, `0x568950: MOV dword ptr [ESP + 0x14], EBP` writes `pipe + 1` into `ctx.full_path` (`[ESP_base + 0x10]`, Ghidra `local_110`), leaving `ctx.handle_or_tail` (`[ESP_base + 0x14]`, Ghidra `local_10c`) as `nullptr` unless updated by `00580e60`.
- Attempt `001` (`local/experiments/v2-file-backend-open-617/001/receipt.json`) passed 120 cases (312 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-pipe-delimiter`, `wrong-zero-block-arg`, `wrong-tail-slot`, `wrong-status-guard`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `00568900`.
- Recovery of visitor `005689b0`, null `path` pointers, prefix lengths >= 260 bytes, and production CMake/registry integration remain open.
