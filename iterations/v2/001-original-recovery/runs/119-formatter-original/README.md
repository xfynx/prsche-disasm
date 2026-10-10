# Run 119 — original formatter helper packet

This packet restores the six small x86 helpers called by the 1,825-byte parser
at `005a4371`: output-byte `005a4ab2`, repeat `005a4ae7`, counted-span
`005a4b18`, and raw argument readers `005a4b50/4b5d/4b6d`. The source image is
`Porsche.exe`, SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
`functions.jsonl`, `calls.jsonl`, and the address-pinned disassembly are hashed
in `verification.json`; each helper body is checked as raw-backed bytes before
the Unicorn oracle runs.

The descriptor is exactly 32 bytes for ABI purposes. Only cursor, remaining
capacity, base, and flags at offsets `+0/+4/+8/+0xc` are interpreted; the final
16 bytes are copied/compared as opaque state. The original output cleanup at
`005a4259` remains a typed boundary. A negative-capacity case verifies the
original call site, argument order, and `-1` return path against a recording
stub; cleanup's body effects and descriptor reads remain unresolved here.

The parser `005a4371` itself is **not recovered** by this run. Its indexed and
disassembled control flow selects conversion handlers from byte-class table
`005c19a8` and state-transition table `005c19c8`; float callbacks are runtime
initialized by `005a0f5d`, and the wide/multibyte path reaches `005abf5e`.
Run114's handwritten parser remains an isolated rejected experiment; none of
its algorithm is reused here. This run proves helpers only, not the formatter
parser, full CRT behavior, game link, or game launch.

The isolated MSVC x86 probe checks eight output-helper cases and three raw-fetch
cases against execution of the original helper bodies in Unicorn. It compares
descriptor prefix and opaque tail, emitted bytes/count, raw cursor advance,
caller ESP, and callee-saved registers. Counter wrap and the repeat helper's
`-1` abort check are included; float, wide-character, and parser conversion
behavior remain open.

Index call sites show four callers of `005a4ab2` (two in `005a4371`, one each
from the repeat/span helpers) and its capacity-failure call to `005a4259`. The
oracle checks EAX equals the physical `emitted_count` pointer on success and
the recorded cleanup-return branch. All five descriptor cases compare the
opaque 16-byte tail unchanged.

The 64-bit fetch advances the cursor by eight bytes before loading low/high
words, matching the original instruction order. For the 16-bit fetch, only AX
is meaningful: original `MOV AX` preserves the upper half of EAX from the
advanced cursor. Repeat/span callers ignore EAX, so their C++ declarations make
no return-register claim.

```powershell
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' -S `
  iterations/v2/001-original-recovery/runs/119-formatter-original `
  -B local/builds/v2/formatter-original-119 -A Win32
& 'local/tools/cmake-4.4.3-windows-x86_64/bin/cmake.exe' --build `
  local/builds/v2/formatter-original-119 --config Release
py -3 scripts/research/verify-v2-formatter-original.py `
  --probe local/builds/v2/formatter-original-119/Release/formatter_original_probe.exe `
  --report-dir iterations/v2/001-original-recovery/runs/119-formatter-original
```
