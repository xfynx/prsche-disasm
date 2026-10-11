# Run 137 — formatter runtime leaves

This isolated packet recovers three indexed Porsche.exe leaves called directly by formatter parser `005a4371`: `_strlen` at `005a6730` (123 bytes), `__aulldiv` at `005a67b0` (104 bytes), and `__aullrem` at `005a6820` (117 bytes). Source evidence is pinned to SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`; the verifier checks function ranges, raw body hashes, parser call edges, and the complete disassembly hash.

The integer helpers follow the two original control paths. A zero divisor high dword triggers sequential 32-bit `DIV` operations. A nonzero high dword triggers paired `SHR`/`RCR` normalization, a 32-bit quotient estimate, and the original product-limb comparison/correction. The byte-string length helper preserves the original initial alignment scan, `0x7efefeff` word probe, `0x81010100` predicate, and ordered byte checks.

The verifier executes each original body in Unicorn x86 and compares direct native calls for 16 nonzero-divisor pairs, including maximum values, high divisor dwords, and normalization boundaries. Two selected inputs explicitly take both quotient/remainder correction branches. It also checks 56 NUL-terminated strings across all four initial alignments and lengths through 255. The verifier checks original return values, stack cleanup, and preserved registers. Divide-by-zero is excluded because the original `DIV` faults; invalid/nonterminated pointers are also outside scope. No external CRT export or runtime binding is claimed.

Reproduce the private Win32 x86 MSVC probe and differential report:

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S iterations/v2/001-original-recovery/runs/137-formatter-runtime -B local/builds/v2/formatter-runtime-137 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build local/builds/v2/formatter-runtime-137 --config Release
py -3 scripts/research/verify-v2-formatter-runtime.py --probe local/builds/v2/formatter-runtime-137/Release/formatter_runtime_probe.exe --report-dir iterations/v2/001-original-recovery/runs/137-formatter-runtime
```
