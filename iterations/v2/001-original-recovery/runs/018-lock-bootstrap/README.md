# Run018 — thread and lock bootstrap call graph

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. Search `0055f320`, `0055f3b0`, `005321f0`, `00532250`, `0056e5f0` in the Ghidra function/call index, then inspect the same addresses in `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`. [evidence.json](evidence.json) records exact call sites, globals, original order, and the next fixture.

The apparent cycle terminates in the original: `0055f320` writes `006a57dc = 1` at `0055f32d` before calling `0055f3b0`. That function creates the table lock through `005321f0`; the nested create sees the flag already set and skips its own call to `0055f320`. After the table allocation, `0055f320` creates a second lock. An empty lock pool first grows through `00532250` and `0056e5f0`.

No joint native/x86 claim is made here. The next executable fixture starts at original `0055f320(0)` with zeroed thread globals and empty lock pool, records only OS, fill, and exit-registration boundaries, and compares each intermediate global and arena state with the linked C++ functions. A 4096-byte page success case should request 1200 bytes for 100 thread entries, round to 4096, produce capacity 341, and initialize two critical sections. These are expected values derived from the cited instructions; the executable comparison remains to be run.
