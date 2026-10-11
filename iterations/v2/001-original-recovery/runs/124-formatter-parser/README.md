# Run 124 - original table-driven formatter parser

This isolated packet restores the 1,825-byte body at `Porsche.exe:005a4371` from SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`. It is
being checked against the original x86 body, not against Run114's rejected
handwritten parser. All 128 bytes of state/classification data at `005c19c8`
match the mapped PE bytes; the eight dispatch targets at `005a4a92`, indexed
call graph, disassembly hash, and source dependency hashes are saved in
`verification.json`.

Run119's six exact output/raw-va helpers and 32-byte descriptor are reused.
The trailing 16 descriptor bytes stay opaque. The 108 wrapper still prepares
only 16 initialized bytes; this parser target does not establish safe linkage
to cleanup `005a4259`, whose remaining descriptor reads are unrecovered.

The parser recovers the indexed state machine and integer, string, character,
counted-string, `%n`, and float dispatch, as a complete body relative to explicit external boundaries. It remains isolated
and is not wired into the game. Finite cases do not establish every input combination. The original unsigned division/remainder callees (`005a67b0` and
`005a6820`) and `_strlen` (`005a6730`) execute in Unicorn; typed native
boundaries record their arguments and results. Float callbacks, wide encoder
`005abf5e`, and cleanup `005a4259` remain explicit typed boundaries whose
fixture effects are not claimed. The canonical native pointer cell
`formatter_ctype_table_005e52d0` is initialized from all 512 raw-backed original
bytes and checked byte-for-byte. State 0 follows `005a4510..005a454f`: it tests
`table[current_unsigned_byte*2+1] & 0x80`, emits the current signed byte, and,
when set, consumes and emits one following byte. The initial PE table has no
such flags. Differential cases cover the original pointer, a changed pointer
with the flag clear/set, `%` consumption versus conversion, a terminal
following NUL, and zero/one-byte descriptor capacity. Other locale-table
writers and parser boundaries remain integration work.

The verifier compares 62 cases across all eight parser states and conversion
letters `c/C`, `d/i`, `e/E/f/g/G`, `n`, `o`, `p`, `s/S`, `u`, `x/X`, and `Z`,
including malformed-length and unknown conversions. It compares output,
return/count, descriptor and opaque tail, callback and cleanup calls, and
per-digit arithmetic/string-length traces. This is bounded differential proof
of the recovered body and listed inputs; external callee effects and untested
input combinations remain open.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/124-formatter-parser `
  -B local/builds/v2/formatter-parser-124 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/formatter-parser-124 --config Release
py -3 scripts/research/verify-v2-formatter-parser.py `
  --probe local/builds/v2/formatter-parser-124/Release/formatter_parser_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/124-formatter-parser
```

Root review corrected zero-value alternate hexadecimal prefixes
(`005a48f5..005a48fb`) and the shared narrow/wide padding path
(`005a4985..005a4a79`). Four zero hex/pointer vectors and zero/left wide padding
were added;62 original-x86/native cases pass. Full-body classification counts
restored control flow with typed external edges; it does not claim complete CRT effects.
