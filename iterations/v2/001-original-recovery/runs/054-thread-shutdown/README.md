# Run054 — thread shutdown and table cleanup

Source: immutable `local/game/Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Binary-index references and instruction evidence are in `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl` and `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`; the targeted consumers are `0055f1c0..0055f1f1` and `0055f200..0055f29d`.

`thread_shutdown_0055f1c0` returns immediately when `threads_initialized` is zero. Otherwise it clears that flag before any cleanup, calls table cleanup, closes the main-thread handle unconditionally, then destroys the start lock. It leaves the main handle, start-lock pointer, main thread ID, exit-registration flag, and thread serial unchanged.

`thread_table_cleanup_0055f200` returns when its table lock is null. Otherwise it enters the lock and uses the original signed `capacity > 0` and signed `slot < capacity` checks. A live entry handle invokes the existing `thread_unregister_0055f2b0(slot, serial)` while the table lock is held; that helper recursively enters/leaves the same lock, closes the handle if serial matches, then clears the entry's three fields. After the loop, a nonnull table is released through `file_object_free_0056e640`, and only that branch clears both table pointer and capacity. When the pointer is null and signed capacity is nonpositive, capacity stays unchanged; a positive capacity with a null table would dereference null and is outside these fixtures. The function leaves the table lock, clears its global pointer, and destroys it. Lock destruction uses the existing `heap_locks.cpp` implementation and links the lock cell into its free list.

The native probe links the production `file_threads.cpp`, `file_pages.cpp`, and `heap_locks.cpp` along with the new shutdown body. The original-x86 side executes the original shutdown, table cleanup, unregister, lock wrappers/destructor, and page-free wrapper; only Win32 `CloseHandle`, critical-section operations, and `VirtualFree` are hooked. Event traces compare nested lock order and handles, and state comparison covers all eight table entries, capacity, thread globals, lock cells, and free-list links. A live boundary assertion confirms the initialized flag is already clear at the first lock enter during shutdown.

Seventeen differential cases pass, including shutdown no-op, null locks/table, null main handle, capacities 0/1/2/4/8, capacities `0x80000000` and `0xffffffff` (signed-negative), occupied/empty entries, serial zero, and standalone table cleanup. They exercise the platform fixture only; no game shutdown launch is claimed.

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/054-thread-shutdown -B local/builds/v2/thread-shutdown-054 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/thread-shutdown-054 --config Release --target thread_shutdown_probe
py -3 scripts/research/verify-v2-thread-shutdown.py
```
