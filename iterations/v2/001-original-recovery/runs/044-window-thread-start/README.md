# Run044 — application window thread start

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index navigation: `rg '0055f420|0053af06' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl`. The direct window caller `0053ac20` calls `0055f420` at `0053af06`; its pushes identify callback `0053b8d0`, stack size, priority, ignored fourth argument, and caller-owned `ThreadRecord` output. The exact body `0055f420..0055f4ee` was checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` and `decompiled.c`.

The recovered cdecl signature is `(callback, stack_size, priority, unused4, ThreadRecord*)`. The function reuses `file_threads.cpp` globals and the original `thread_init_0055f320`, trampoline `thread_bootstrap_0055f4f0`, registration `thread_register_0055f560`, and priority translation `thread_priority_0055f8b0`. On CreateThread success it writes record stack/priority/flags, registers, applies priority, resumes, and polls the trampoline handshake with `SleepEx(1,1)`. The x86/native proof compares a full 128 KiB arena, thread globals, return value, and ordered OS/heap calls across success, failure, occupied-table, initialized, and initialization paths.

The probe supplies deterministic OS/lock/allocation endpoints. Thread scheduling and execution of the worker body are not asserted; the callback identity is compared as original VA `0053b8d0`. This run verifies the native window-thread start boundary, not the complete `0053ac20` window lifecycle or a game launch.

Reproduce with x86 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/044-window-thread-start -B local/builds/v2/001-original-recovery/window-thread-start-044 -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/window-thread-start-044 --config Release --target window_thread_start_probe
py -3 scripts/research/verify-v2-window-thread-start.py
```

`verification.json` pins the original SHA, native probe hash, and compiled source/header hashes. Native C++ matched original x86 in all recorded cases.
