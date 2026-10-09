# Run033 — primary and object heap initialization

Original: `Porsche.exe` SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '005aef80|0059ebc0|00569a70|005697f0|0059ed40' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d -g '*.jsonl'`. Instruction bodies were checked in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` at `005aef80..005aefca`, `0059ebc0..0059ec39`, `00569a70..00569a8b`, and `0059ed40..0059ed8a`.

`005aef80` calls `005697f0` for heap index 0 with name `005c250c` (`RAM`), arena and byte count from its arguments, quantum 8, alignment `0x40`, locked 1, and callback `005aef70`; it then aliases heap 1 to heap 0 and stores the arena in `005deb98` only if that global is null. `005aef70` returns zero. `0059ebc0` chooses the first empty heap index 3–15 through `00569a70`; for a nonzero queue slot it writes the selected index at `*(DWORD*)(*(DWORD*)005e4fec - slot*4)`. The initialized pointer at `005e4fec` is `006af374`, the 16-entry queue index table. It rounds/allocates through Run025's `0059ed40`, stores the arena at `006af3b4 + index*4` before checking allocation failure, returns -1 on null, and otherwise calls `005697f0` with the fixed name at `005e8e50`, the rounded bytes, caller quantum, alignment `0x20`, locked normalized to 0/1, and no callback.

The C++ wrappers use the already recovered heap initializer and Run025 page allocator. The native x86 probe records these boundary calls and resulting globals. `verify-v2-application-heap-init.py` executes original x86 for 364 cases and compares primary alias/default behavior, object slot selection, queue indexing, page rounding/allocation, heap-init arguments, return values, and arena writes. `verification.json` pins the original binary, source, and probe hashes. Reproduction:

```powershell
. ./scripts/tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/033-application-heap-init -B local/builds/v2/001-original-recovery/application-heap-init -G 'Visual Studio 17 2022' -A Win32
cmake --build local/builds/v2/001-original-recovery/application-heap-init --config Release --target application_heap_init_probe
py -3 scripts/research/verify-v2-application-heap-init.py
```

Scope boundary: no case fills every heap slot 3–15. The original selector then returns 16, and the following stores target one past the 16-entry arena and heap tables; that overflow path is not modeled as valid initialization. The final `005679f0` call in the larger `0059e9d0` startup is a separate pool initializer. Its body allocates a 0xe00 pool and a caller-sized table through `00591820`, `00580630`, and `0056e5f0`, then creates lock-backed records; those dependencies are not part of this package and remain a separate recovery step. The complete game startup is not claimed.
