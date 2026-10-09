# Run 017 — input mode branches, source trace only

Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: Porsche.exe Ghidra `calls.jsonl` / `references.jsonl`, then
`research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm` at 0x532e10
and `defined-data.jsonl` at 0x532f38–0x532f64. These are source navigation
and instruction evidence; this run has no native implementation or x86 replay.

Confirmed dispatch after the signed count comparison and non-null device check:
the mode table at 0x532f38 maps modes 1, 2, 6, 8 to 0x532ed6, 0x532ede,
0x532e5b, 0x532efb respectively. Modes 3–5 and 7, plus values outside 1–8,
go to the diagnostic block at 0x532f0a. Mode 1 returns the signed count loaded
from 0x69cb0c at 0x532ed6. Mode 2 passes the device pointer and 0x6bde20 to
0x56fdb0 at 0x532ede; it returns 0x6bde20 only when that call returns zero.
Mode 8 passes the device pointer to 0x56fff0 at 0x532efb and returns its result.
The mode-6 type table at 0x532f58 maps low-byte types 1/4 to size 0x50, type 2
to 0x10 and type 3 to 0x100; Run 013 compared this path with original x86.

Still unknown: semantics and side effects of 0x56fdb0 and 0x56fff0; global
diagnostic state for rejected modes/types; behavior of a negative index before
the slot array and indices above the known 32-slot arena. No behavior from
those paths has been connected to the C++ unit.

Next step: trace 0x56fdb0 and 0x56fff0 instructions, callers and callees;
replay modes 1/2/8 with the same initialized globals and mock DirectInput
vtable, comparing return, 0x6bde20, diagnostics, slot arena and COM calls.
Resolve negative/unmapped index memory only after identifying the adjacent
original globals and actual count bounds.
