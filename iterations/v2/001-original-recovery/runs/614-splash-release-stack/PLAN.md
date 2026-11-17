# Run614 splash release stack

## Goal and criteria
- Recover original `0048d550` (`splash_progress_release_stack_0048d550`, 322B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `porsche/splash_progress.hpp`, `porsche/startup_services.hpp`, `porsche/fe_stream.hpp`, and `porsche/heap.hpp` with zero new `.data` or `.rdata` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`8f8080be41157bdfca4d2fc4acd538761b8e2178617eef084a3d16d4128ad02d`), and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-0048d550.json`, `ev_a9ef9e90cc8f529b60cc10eefae91c437a2681da5250f833f963bfb860557071`) confirm the 322B body, `__cdecl` 1-arg calling convention, 8 `ABS32` relocations to `00628c70`, and 3 `REL32` calls (`004b4cd0` x2, `005323e0` x1).
- `0048d550` guards on `startup_network_00628c70`, `[net+0x08]`, `net[0xbf] == 0`, and `*stack != 0`, then walks `fe_record_words_004b4cd0`-sized records, pre-flushing `net+0x160` via `vtbl[0]` if `used + byte_len > 0xf0 && used > 4`, copying via `heap_copy_dispatch_005323e0`, advancing `[net+0x250]`, and post-flushing if `used2 > 4`.
- Attempt `001` (`local/experiments/v2-splash-release-stack-614/001/receipt.json`) passed 100 cases (531 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-overflow-limit`, `wrong-pre-send-min`, `wrong-post-send-min`, `wrong-byte-len-shift`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `0048d550`.
- Null `stack` pointers, null `startup_network_00628c70` reloads inside `vtbl[0]` or `005323e0`, negative/out-of-bounds record lengths, and production integration remain open.
