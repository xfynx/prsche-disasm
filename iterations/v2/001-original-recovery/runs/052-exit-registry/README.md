# Run 052 — CRT callback registry

Source: `Porsche.exe`, SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Index query: `rg '005a2382|005a2400|005a2412|005a2535|005a253e|005a8161|005a8029' research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl`. Assembly and pseudocode were checked in the v2 Porsche binary corpus.

`005a2412` initializes an 0x80-byte callback array and sets both registry pointers to its base. `005a2382` locks with lock ID 0xD, checks whether the next 4-byte slot fits, obtains the current allocation size again before growing by 0x10 bytes, preserves the used-byte offset if the allocator moves the block, appends the callback (including null entries), unlocks, and returns the callback or null on growth failure. `005a2400` converts that result to 0 on success and -1 on null/failure. `005a2535/005a253e` are the exact lock-enter/leave wrappers. Existing `00557380` and its application-pool caller remain owned elsewhere; a void adapter supplies the recovered result-returning registry entry point.

Eight x86/native scenarios compare the complete 64 KiB arena, base and next pointers, per-call results, and allocator/lock call order. Coverage includes first allocation, exact capacity, one and multiple growth steps with relocation, reallocation failure, null callback insertion, and terminal initial-allocation failure.

`005a3be5`, `005a8161`, and `005a8029` are deterministic CRT allocation boundaries. The test fixture models their observed result contract and preserves bytes on successful relocation; their allocator internals are not claimed. Underlying lock operations `005a4ba4/005a4c05` and terminal `__amsg_exit(0x18)` are explicit boundaries. Shutdown callback traversal in `005a2490` is the next separate package.

Build and compare:

```powershell
. .\scripts\tool-env.ps1
cmake -S iterations/v2/001-original-recovery/runs/052-exit-registry -B local/builds/v2/001-original-recovery/exit-registry-052 -G "Visual Studio 17 2022" -A Win32
cmake --build local/builds/v2/001-original-recovery/exit-registry-052 --config Release --target exit_registry_probe
py -3 scripts/research/verify-v2-exit-registry.py
```
