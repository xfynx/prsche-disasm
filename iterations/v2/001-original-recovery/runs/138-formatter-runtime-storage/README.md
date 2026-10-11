# Run 138 — formatter CRT initial storage

Data-only packet for Porsche.exe SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. No recovered functions are added. The private verifier compares all eight native storage ranges (5057 bytes) against the original mapped PE image, normalizing only the first descriptor's two relocated buffer pointers after separately checking native identity. It checks actual pointer identities for both special descriptors, both null strings, the invalid record, and the three initial float callbacks. Ten original pointer cells are independently verified against PE HIGHLOW relocations. No callback is executed.

Index queries: `005e54e8`, `005e5768`, `006c01e0`, `006c02e0`, `005e5f50`, `005e5788`, `005e578c`, `005e5794`, `005e57a0`, `005e57a4` in `research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl`, followed through `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` and SHA-checked raw bytes.

Confirmed storage and consumers:

- `005a3683..005a369c` starts at `005e54e8`, increments 32, and stops at `005e5768`: exactly 20 descriptors. This loop is present in the indexed disassembly even though Ghidra did not assign it a function entry. The packet claims instruction evidence, not a new function boundary. `005a4259` compares descriptor identities with `005e5508` and `005e5528`; these alias entries 1 and 2, rather than separate descriptor owners.
- The first descriptor contains buffer pointers `006c0520`, flags `0x101`, and size word `0x1000` at +0x18. The 4096-byte referenced buffer is zero-filled in the PE mapped image. The next indexed cell is `006c1520`; the extent is supported by the descriptor size, not just this adjacency. Remaining first-three descriptor bytes and the 17 empty entries match raw bytes exactly.
- `005ab4e1..005ab582` scans pointer cells from `006c01e0` in steps of four, with exclusive end `006c02e0`: 64 cells. `005a953e` allocates `0x480` bytes for 32 records of 36 bytes, stores the first bank, and sets the runtime limit to 32. That initialization is not part of this packet. The initial PE table and limit are zero. The preceding cell `006c01dc` is separately owned solely to preserve cleanup's signed index -1; its higher-level semantics remain unknown.
- `005e5f50` is the 36-byte invalid record (`ffffffff 00000a00`, then zeros); the 36-byte stride is established by lowio consumers and initialization, not inferred from the neighboring object.
- Pointer cells `005e57a0/a4` relocate to `(null)` at `005c1a34` and UTF-16 `(null)` at `005c1a24`.
- Initial callback cells `005e5788/578c/5794` all point to `005abee8`. Its exact nine-byte body pushes 2 and calls fatal boundary `005a2e22`. Production holds unresolved typed function declarations, never null/no-op callbacks. Private probe symbols abort if called and provide link identities only. `005a0f5d` later replaces the callbacks with `005a41e3/005a3e8d/005a3e33`; these float bodies and the startup writer are not recovered here.

This is initial-image ownership, not initialized CRT or game readiness. The canonical storage must replace fixture definitions when composed with cleanup/parser; private fixture globals must not be linked alongside it. Next: recover `005abee8` through fatal consumer `005a2e22`, then `005a0f5d` and its callback consumers, and recover lowio initialization `005a953e` before claiming live file-handle behavior. No common registry/CMake or accepted packet was edited.

Reproduce:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/138-formatter-runtime-storage -B local/builds/v2/formatter-runtime-storage-138 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/formatter-runtime-storage-138 --config Release
py -3 scripts/research/verify-v2-formatter-runtime-storage.py --probe local/builds/v2/formatter-runtime-storage-138/Release/formatter_runtime_storage_probe.exe --report-dir iterations/v2/001-original-recovery/runs/138-formatter-runtime-storage
```
