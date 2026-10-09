# Run040 — combined application heap bootstrap and allocation

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '0059ed40|005aef80|005697f0|0059ef90|00531f70|00531ca0|0059f050|00531f90' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. Original x86 bodies checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`: page allocation `0059ed40..0059ed8a`, primary commit `005aef80..005aefca`, heap initialization `005697f0..005699eb`, active allocator entry `00531f70..00531f87`, allocate `00531ca0..00531f63`, network wrapper `0059ef90..0059efb5`, free `00531f90..005320a5`, and release wrapper `0059f050..0059f062`.

The probe composes the already recovered implementations directly: Run025's `application_page_alloc_0059ed40`, Run033's `application_heap_commit` and the real `heap_init_005697f0`, then Run031's `startup_network_allocate_0059ef90` and `application_release_0059f050`, which reach the real `allocate_00531ca0`/`free_00531f90`. The x86 verifier runs those original bodies in order. It seeds page size 4096 and the active table pointer (`005e4fe8 -> 005e4700`), state installed by the wider `0059e9d0` startup; that wider FE setup body is outside this run. `0059e9d0` also stores the primary arena global before calling `005aef80`, which the comparison models as startup state.

Six deterministic cases exercise zero and small requests, multiple live blocks, and adjacent/non-LIFO frees. For every case the verifier compares the entire 64 KiB arena after heap initialization and after each allocation/free, all 16 heap-table entries, primary/default/page/object-heap globals, return values, and ordered page/format/fill/lock calls. Native and original callback addresses differ because the recovered C++ function is relocated; only the four-byte `OriginalHeap::callback` field at arena offset `0x4c` is canonicalized to original VA `005aef70`. Every other arena byte is compared verbatim. Locks are single-thread fixture tokens; Win32 page allocation/free and CRT format/fill are the declared boundaries. Link-only no-op symbols for other `application_heap.cpp` entrypoints are never called in these cases.

Reproduce on x86 MSVC:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/040-application-bootstrap -B local/builds/v2/001-original-recovery/application-bootstrap -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-bootstrap --config Release --target application_bootstrap_probe
py -3 scripts/research/verify-v2-application-bootstrap.py
```

`verification.json` pins the source/probe hashes and original module SHA. This verifies the joined allocation chain, not the entire `0059e9d0` startup, queue/pool initialization, multithreaded locking, or a game launch.
