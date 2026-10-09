# Run031 — active application allocator dispatch

Original: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '00531f70|0059ef90|0059efc0|0059eff0|0059f020|0059f050' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. The active table at PE `005e4700` has `005e4704 = 00531f70` and `005e4708 = 00531f90`; its pointer is installed by `0059e9d0` at `005e4fe8`. PE bytes at `005e5070/005e5074` are `new\0new[]\0`. Assembly checked at `00531f70..00531f87`, `0059ef90..0059efb5`, `0059efc0..0059efe4`, `0059eff0..0059f010`, `0059f020..0059f044`, and `0059f050..0059f062`.

The four allocation wrappers coerce zero bytes to one, choose `new` or `new[]` and the object, explicit, or zero heap index, then call the active table +4. `00531f70` delegates source, size, and heap index to the already recovered `00531ca0` allocator. `0059f050` skips null and otherwise uses active table +8, the already recovered `00531f90` free. The startup network allocation at `004a5410` uses `0059ef90(0x268)`; renderer startup also calls this allocator through its previously verified consumer.

`application_alloc.hpp/cpp` implement the active startup dispatch without redefining any Run025 global. The isolated probe supplies Run025's object heap index and recording implementations of the existing core allocator/free. `verify-v2-application-alloc.py` executes the original wrappers and table entry in Unicorn, stopping at `00531ca0`/`00531f90`. Across 124 cases, native x86 and original x86 return values, source strings, byte counts, heap indexes, and core call order match. `verification.json` pins source and probe hashes. This proves routing into the already recovered core; it does not itself prove a combined live Win32 heap execution or a first game window.

Reproduce:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/031-application-alloc -B local/builds/v2/001-original-recovery/application-alloc -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-alloc --config Release --target application_alloc_probe
py -3 scripts/research/verify-v2-application-alloc.py
```

Integration: link `application_alloc.cpp` with `application_heap.cpp`, the existing `heap.cpp`/FE heap definitions, and the startup service consumer. The Run025 object heap index is the only shared global used here. Before calling the allocator from startup, implement the Run025 OS/page/lock/heap initialization boundaries and ensure the active 005e4700 table state. The next acceptance step is a joint allocator/initialization fixture using real recovered `00531ca0`/`00531f90`, followed by the bounded `004b6a50` startup caller.
