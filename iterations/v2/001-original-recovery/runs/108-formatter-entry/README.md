# Run 108 — variadic formatter entry

Run 108 restores original `005a0fbf..005a1010` (82 bytes) from `Porsche.exe`,
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The versioned Ghidra index (`functions.jsonl`, `calls.jsonl`) records 584 direct
incoming calls, plus calls from the entry to `005a4371` and `005a4259`; the
disassembly is `research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm`.
Its assembly establishes a 16-byte
descriptor at `EBP-20h`, passes the untouched x86 variadic stack at `EBP+10h`
to `005a4371`, decrements descriptor DWORD `+4`, then either calls
`005a4259(0, descriptor)` when the signed result is negative or stores zero
through descriptor cursor `+0`. It returns the exact EAX from `005a4371`.

The public signature is `int32 __cdecl(char* output, const char* format, ...)`.
The explicit raw adapter takes the original x86 vararg-word pointer for
standalone probes. Descriptor offsets are cursor `+0`, signed remaining `+4`,
base `+8`, and flags `+0xC`; initialization is output, `0x7fffffff`, output,
`0x42`. The recovered wrapper does not implement formatting or cleanup.
Those callees remain typed boundaries, and fixture mutations are test scripts,
not claims about their algorithms.

Seven differential cases exercise EAX preservation, raw argument words, the
signed DEC boundary and wraparound, both branch outcomes, and clear-at-mutated-
cursor behavior. The Unicorn oracle executes the original entry and hooks only
the two callees. `verification.json` records the exact source dependency hashes.
The proof covers the wrapper and its x86 cdecl ABI; it does not prove formatter
core output, cleanup effects, locale behavior, or a working game.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/108-formatter-entry `
  -B local/builds/v2/formatter-entry-108 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/formatter-entry-108 --config Release
py -3 scripts/research/verify-v2-formatter-entry.py `
  --probe local/builds/v2/formatter-entry-108/Release/formatter_entry_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/108-formatter-entry
```
