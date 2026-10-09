# Run025 — application heap startup and page allocation

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query `rg '0059e9d0|0059ed40|0059ed90|0059edb0' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`; the four indexed bodies are 324, 75, 19, and 116 bytes. Exact instructions and ordered calls were checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` at `0059e9d0..0059eb13`, `0059ed40..0059ed8a`, `0059ed90..0059eda2`, and `0059edb0..0059ee23`. Direct startup chain: `004b6a50 -> 0059ed40` at `004b6a65`; `004b6a50 -> 004a5410 -> 0059e9d0/0059edb0`. The initializer also calls `0059ed40` at `0059ea3c`.

Confirmed behavior: `0059ed40` caches `SYSTEM_INFO.dwPageSize` if zero, unsigned-rounds the requested bytes, writes the rounded value, then invokes `VirtualAlloc(NULL, rounded, 0x3000, 4)`. `0059ed90` invokes `VirtualFree(address, 0, 0x8000)` and returns its result. `0059e9d0` sets the page/initialized globals, clears 0x8c0 bytes of records, creates 16 locks at 0x8c intervals, allocates the primary arena, optionally creates the object heap, records the failure source/line before diagnostics, and invokes the remaining allocator/FE startup callees in the original order. `0059edb0` takes the record lock, prepends `count` nodes allocated through the indirect heap table, then releases the lock. The startup call uses slot zero and count 400.

`application_heap.hpp/cpp` encode these four consumers. Win32, lock, allocator, diagnostic and FE callees are named typed boundaries with controlled fixture behavior. The 16-record region and indirect queue index table are isolated from the existing FE heap globals. `application_heap_probe.cpp` and `verify-v2-application-heap.py` compare 48 cases against original x86, including startup primary success/failure, object heap present/absent/failure, page rounding and allocator failure, release BOOL, and queue counts 0/1/2/400. Compared state includes page/arena/object globals, initialized flag, failure metadata, all 16 lock slots, queue links, returns, and ordered boundary arguments. `verification.json` pins source and executable hashes. This is a bounded consumer proof; callees and real OS allocations are not recovered here.

Reproduce on x86 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/025-application-heap -B local/builds/v2/001-original-recovery/application-heap -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-heap --config Release --target application_heap_probe
py -3 scripts/research/verify-v2-application-heap.py
```

Integration dependencies: the platform must implement `application_system_page_size`, `application_virtual_alloc/free`, `application_os_start`, `application_fill`, lock creation/enter/leave, primary commit, optional object heap, diagnostics, secondary startup, queue/printf/heap registrations, final heap setup, and queue node allocation. The source retains their call order and original argument values; a running window still requires those callees and the later main-loop consumers. `0059ef90` is the next startup allocator caller to recover against the same arena state.
