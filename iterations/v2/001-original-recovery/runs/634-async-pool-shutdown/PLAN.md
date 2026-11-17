# Run634 async pool shutdown (`00592590`, `00567cf0`, `00564750`, `00564700`, `00563d30`)

## Goal and criteria
- Recover the 5-function file/async-pool shutdown chain from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
  - `physical_file_clear_flag_00592590` (`00592590..005925ce`, 63B, `__cdecl`)
  - `file_operation_cancel_00567cf0` (`00567cf0..00567dbe`, 207B, `__cdecl`, jump table `00567dc0..00567de7`, 40B)
  - `async_slot_resolve_00564750` (`00564750..0056478c`, 61B, `__cdecl`)
  - `async_slot_cancel_00564700` (`00564700..00564745`, 70B, `__cdecl`)
  - `application_main_function_00563d30` (`00563d30..00563e0d`, 222B, `__cdecl`)
- Reuse all canonical headers without duplicating existing globals/types or including `frame_loop_clusters_400.hpp`.
- Record raw PE/Capstone CFG evidence in `original-index-supplement.json` and `scope-evidence.json`.
- Pass `verify-v2-native-batch.py` at `/Od` and `/O2` with 8 material mutation controls.

## Verified facts
- Direct PE disassembly confirms all 5 functions are absent from `functions.jsonl` and establishes exact spans, relocations, and the 40-byte `.text` jump table at `00567dc0`.
- `00592590` clears `PhysicalFile::padding[0]` at byte offset `+2` (`active` `+0`, `device` `+1`, `padding[0]` `+2`, `padding[1]` `+3`) when `physical_files_006af084 != nullptr`, `0 <= ~handle < physical_count_006af080`, and `active != 0`; otherwise calls `platform_disk_set_last_error(6)` (`005b21a4` `SetLastError`) and returns `0`.
- `00567cf0` switches on `FileOperation::type` at offset `+0x08` (`cases {2, 3}` clear physical flag if `dev->current == op` then fall through to `{0, 2, 3, 4, 6, 8, 9}` cancel/remove/prepend/callback with `op->flags |= 8`; `{1, 5, 7}` and `> 9` break cleanly).
- `00564750` uses signed `< 0x100` on `handle` and signed `< async_pool_capacity_006a5be0` on `handle & 0xff`, returning `rec` iff `*rec == handle`.
- `00564700` saves `op = slot[6]`, sets `slot[3] = 1`, calls `00567cf0(op)`, and calls `async_dispatch_00563cc0(slot)` iff `op == 0 && slot[5] == 0`.
- `00563d30` cancels slots `0..capacity-1`, pumps `file_pump_005366e0(0)` (when `file_current_thread_0055f780(0) != 0`) + `file_sleep_0055f740(0)` while any `slot[6] != 0`, closes `async_pool_active_006a5be4` with `0x64u`, removes and invokes `async_pool_callback_00563bd0`, destroys `async_pool_lock_006a5be8`, and frees/clears `async_pool_base_006a5bc0`.

## Next step / boundaries
- Attempt `003` (`local/experiments/v2-async-pool-shutdown-634/003/receipt.json`) passed 39 cases (88 events) at `/Od` and `/O2` with zero `/W4` warnings, zero `.data`/`.rdata` sections, and detected all 8 mutation controls.
- Pinned proof inputs are frozen. Production CMake/registry integration remains open.
- PARTIAL boundary: bounded native proof uses controlled stubs for external file/scheduler/heap/async callees and test storage for shared globals; live OS handles, threaded device workers, and production CMake/registry integration remain open.
