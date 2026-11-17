# Run619 shutdown network destroy

## Goal and criteria
- Recover original `0048ff30` (`porsche::ShutdownNetwork311::destroy_0048ff30`, 522B) from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`).
- Reuse canonical declarations in `shutdown_helpers_311.hpp`, `porsche/startup_services.hpp`, `porsche/application_alloc.hpp`, `porsche/files.hpp`, `porsche/network_lifecycle.hpp`, `porsche/heap_locks.hpp`, `network_callback_drain_488.hpp`, and `porsche/application_context_base.hpp` with zero new `.data` or `.rdata` bytes.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 4 material mutation controls.

## Verified facts
- Binary index (`functions.jsonl`, `references.jsonl`), PE bytes (`83cecaa49d7aba951ea94886c3d3f5148acfa5324ca00cefcb268aa8dc6f6c85`), and cached REA (`local/experiments/v2-frontier-469-rea/001/receipt.json`: `function-0048ff30.json`, `ev_618f5087c01e5a6d4af6353505f13969febaa01f1a743071c9058cbb4e8ce392`) confirm the 522B body, `__thiscall` (`ECX=this`, `RET 0`) calling convention, 2 `ABS32` relocations (`00628c70`, `006afbe4`), and 17 `REL32` calls (`0048e9c0`, `005322d0`, `0059f050` x2, `005603b0`, `004237d0` x12).
- When `startup_network_00628c70 != nullptr`, `0048ff30` clears `missing_file_006afbe4 = nullptr`, calls `network_lifecycle_reset_0048e9c0(this, nullptr)`, if `*(this+0x10)` is non-null destroys `*lock_box` via `heap_lock_destroy_005322d0` and frees `lock_box` via `application_release_0059f050`, unconditionally frees `*(this+0x18)` via `application_release_0059f050`, and calls `network_callbacks_drain_005603b0()`.
- Regardless of `startup_network_00628c70`, `0048ff30` clears the 6 circular doubly-linked list head slots on `this` in order (`+0x264`, `+0x260`, `+0x25c`, `+0x258`, `+0x254`, `+0x150`), advancing `edi = edi[0]` before calling `application_context_clear_004237d0(node, 0xc, 0)`, reloading `*head_slot` on each step, resetting `s0[0] = s0` and `s1[1] = s1`, and calling `application_context_clear_004237d0(s2, 0xc, 0)`.
- Attempt `001` (`local/experiments/v2-shutdown-network-destroy-619/001/receipt.json`) passed 44 cases (534 events) at `/Od` and `/O2` and detected all 4 mutation controls (`wrong-missing-file-reset`, `wrong-lock-box-offset`, `wrong-clear-node-size`, `wrong-list-order`).

## Next step / boundaries
- Pinned proof inputs are frozen. Coordinator owns production CMake/registry integration for `0048ff30`.
- Null `this` or null list head slot pointers, cross-list aliasing, and production integration remain open.
