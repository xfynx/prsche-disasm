# Run080 — shared original diagnostic/runtime storage

Original: `Porsche.exe`, SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Run076 found duplicate native owners for original DWORD cells `0x005deb1c`, `0x005deb74`, and `0x005deb78`. The original x86 reference index and ASM show the same cells crossing recovered subsystem paths: `0x005deb1c` is written at `0044ed7b`, `0044f06e`, `00467849`, and in `00555bc0`; source/line writes pair at `0044919f/a9`, `00449748/52`, and `00449954/5e`. The two diagnostic cells have paired original readers at `005653be/c7` and `0059fbde/e3`.

`shared_runtime_globals.cpp` is the single production owner of three canonical `uint32_t` words. Existing heap, renderer, application-heap, file, and window names are typed reference views into those words. `diagnostic_file_005deb74()` and `_set()` encode/decode the pointer bits with `memcpy`; no pointer reference aliases a `uint32_t` object. The helper requires the original 32-bit pointer width. Original nullable/zero source-pointer behavior is preserved.

Affected standalone differential probes opt in to the header's fixture-storage branch, which defines the same alias graph in each isolated executable without changing shared build configuration. The dedicated Run080 executable links the actual production owner TU and checks storage identity plus bidirectional writes through every alias. This proves alias storage semantics, not whole-game runtime behavior.

The production source list needs one new TU: `source/recovered/Porsche.exe/shared_runtime_globals.cpp`. Rebuild affected probes/verifiers: `heap_probe` / `verify-v2-heap.py`, `application_heap_probe` / `verify-v2-application-heap.py`, `application_heap_init_probe` / `verify-v2-application-heap-init.py`, `application_bootstrap_probe` / `verify-v2-application-bootstrap.py`, `files_probe` / `verify-v2-files.py`, `device_probe` / `verify-v2-file-device.py`, `worker_probe` / `verify-v2-file-worker.py`, `joint_disk_probe` / `verify-v2-joint-disk.py`, `application_pool_probe` / `verify-v2-application-pool.py`, `startup_input_probe` / `verify-v2-startup-input.py`, `render_display_probe` / `verify-v2-render-display.py`, `render_objects_probe` / `verify-v2-render-objects.py`, `render_mode_probe` / `verify-v2-render-mode.py`, `render_state_init_probe` / `verify-v2-render-state-init.py`, `render_state_integration_probe` / `verify-v2-render-state-integration.py`, `render_loader_probe` / `verify-v2-render-loader.py`, `window_create_probe` / `verify-v2-window-create.py`, and `window_state_probe` / `verify-v2-window-state.py`.

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/080-shared-diagnostic-storage -B local/builds/v2/shared-diagnostic-storage-080 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/shared-diagnostic-storage-080 --config Release --target shared_diagnostic_storage_probe
py -3 iterations/v2/001-original-recovery/runs/080-shared-diagnostic-storage/verify.py --probe local/builds/v2/shared-diagnostic-storage-080/bin/Release/shared_diagnostic_storage_probe.exe
```
