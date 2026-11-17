# Run634 async pool shutdown (`00592590`, `00567cf0`, `00564750`, `00564700`, `00563d30`)

Bounded native x86-vs-C++ recovery packet for the 5-function file/async-pool shutdown chain from `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):
- `physical_file_clear_flag_00592590` (`00592590..005925ce`, 63B, `__cdecl`, sha256 `30406284f379cf9102f60a0a38b2afe6e7cf2d974b69992ac918dcd998cb2322`)
- `file_operation_cancel_00567cf0` (`00567cf0..00567dbe`, 207B, `__cdecl`, sha256 `f805890daf0a698729cac0fbd03d9424f95ea9c30ee6f4ec0929b9a238f6b903`; switch table `00567dc0..00567de7`, 40B `.text`, sha256 `9f6977ba445a511b2cb59be9582856ca9b6a6e8acd52655ebe84cb6ad97aad77`)
- `async_slot_resolve_00564750` (`00564750..0056478c`, 61B, `__cdecl`, sha256 `46d3223f870f6f715239e362090199e1986c018613281110e53325865c521c2b`)
- `async_slot_cancel_00564700` (`00564700..00564745`, 70B, `__cdecl`, sha256 `f541725d0cb1a6a3d9adb9234310797f9181ff7141f9c0f358eaafce9efae0be`)
- `application_main_function_00563d30` (`00563d30..00563e0d`, 222B, `__cdecl`, sha256 `6cc7c7a6e7cfa89af46daddfc60efa1169c8ec4746711eba5164add41d2c3069`)

Zero new `.data` or `.rdata` globals are owned by this run.

Canonical include dirs:
- `iterations/v2/001-original-recovery/runs/634-async-pool-shutdown`
- `iterations/v2/001-original-recovery/runs/372-async-callbacks`
- `iterations/v2/001-original-recovery/runs/361-startup-device-pool`
- `iterations/v2/001-original-recovery/source/include`

## Verification

- Attempt `003` (`local/experiments/v2-async-pool-shutdown-634/003/receipt.json`): **PASS**
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/634-async-pool-shutdown/native-config.json --attempt 003`
  - `/Od` and `/O2` compiled with zero `/W4` warnings, zero `.data`/`.rdata` sections, and printed `async_pool_shutdown_original_x86_vs_cpp=PASS cases=39 events=88`.
  - All 8 mutation controls (`wrong-physical-padding-offset`, `wrong-physical-error-code`, `wrong-cancel-type-case2`, `wrong-cancel-callback-flag`, `wrong-resolve-signed-handle`, `wrong-slot-finalize-guard`, `wrong-shutdown-close-mode`, `wrong-shutdown-thread-pump`) exited `1` on `divergence`.

## Boundaries (PARTIAL)

Bounded native proof uses controlled stubs for `io_lock_00580ea0`, `io_unlock_00580ec0`, `operation_find_00567b80`, `io_locked_remove_005808f0`, `io_prepend_005806e0`, `async_dispatch_00563cc0`, `file_current_thread_0055f780`, `file_pump_005366e0`, `file_sleep_0055f740`, `close_00533da0`, `window_scheduler_remove_005366a0`, `async_pool_callback_00563bd0`, `heap_lock_destroy_005322d0`, `free_00531f90`, and `platform_disk_set_last_error`, with test storage for shared globals. Live OS handles, concurrent file worker threads, and production CMake/registry integration remain open.
