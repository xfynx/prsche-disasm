# Run 012 — FE action callbacks (bounded unit)

Source: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: FE `Analog`/`Button`/`Pov` action rows at 0x5cc5c8 and
callbacks 0x4119e0, 0x411a80, 0x411b40; `calls.jsonl` and
`references.jsonl` show 0x532e10 and writes to 0x5e8e60/0x5e9380.
The full `disassembly.asm` establishes the actual instructions. Ghidra omits
the 0x4119e0 function boundary, so its range is taken directly from
0x4119e0..0x411a40 in the listing; 0x411a80..0x411abd and
0x411b40..0x411b7d are indexed functions.

All three callbacks extract an unsigned device index (packed >> 16 for Button
and Pov, >> 20 for Analog), call 0x532e10(index, 6), and, only if nonzero,
scan 32 signed bytes from 0x5e8e60 until a negative or equal entry. They
overwrite that slot with the low byte of index; a full list is unchanged.
The Button callback first clears bit (packed & 31) in mask word
0x5e9380[index], only for index < 32, including when the callee returns null.
0x411680 initializes the 32 list bytes and 32 mask words to 0xff; PE initial
bytes are zero before initialization. The mask storage aliases the existing
FE state array at 0x5e9130 + 0x250, not a second global.

Original instructions set EAX=0 at every return. The owned C++ callbacks
return `uint32_t` zero and the native probe compares it with original EAX.
The shared FeAction declaration is updated by the coordinator during integration.
0x532e10 is still an external input service boundary with controlled null /
non-null results, and its other effects have not been recovered. The unit
does not claim full input-system or FE UI behavior.

Verification:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-fe-callbacks.py

`verification.json` records the SHA guard, full source/build dependency SHA,
whole list/mask snapshots, callee arguments, and native return. All 1,320
cases matched the unchanged original x86: 440 per callback, including null
and non-null getstate responses, signed list entries, full list, bit edges,
and broad packed inputs. This is a unit proof, not a byte match or game launch.

Next bounded step: recover `0x532e10` mode-6 path against original x86 with
mock DirectInput vtables. Its indexed 293-byte function has no decompiler
warnings, but is unrecovered; it checks device count and object at
`0x6be040 + index*0x10c`, selects state sizes 0x50/0x10/0x100 by type,
calls `0x56fce0` (which reaches `0x56fd00` and `0x56fd30` virtual calls),
and returns the per-device pointer on success. Compare inputs, intermediate
device/buffer state, vtable call order/results, and return for valid,
missing, invalid type, and loss/reacquire cases before replacing this probe
boundary. The three callees are indexed with no warnings and remain
unrecovered. This does not establish any higher-level input or GUI behavior.

Integration checkpoint: 92 verified C++ functions, 11 Win32/x86 probes built.
Run011 disk consumers passed 31 original-x86 cases. Shared callback ABI is u32;
all affected regressions passed: heap551, FE236, device474, worker69, wait87,
events249, threads94, joint89. Registry points to these fresh reports. Button
callback 4119e0 has SHA-guarded supplementary body index (97 bytes, both RETs).
Original OS concurrency and higher-level input/UI remain unverified.

Checkpoint audit:

    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts
    py -3 scripts/research/structure-v2.py
    py -3 scripts/research/trace-v2-startup.py
    py -3 scripts/research/inventory-v2.py --require-listing --require-decompile-attempts --write-verification
