# Run 019 — input property and bounded capabilities exit

Original: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: input mode dispatch 0x532e10 in the Porsche.exe Ghidra
`calls.jsonl` leads to 0x56fdb0 and 0x56fff0; the v2
`disassembly.asm` at 0x56fdb0–0x56ff8c and 0x56fff0–0x570045 is the
instruction evidence. 0x53c290 is the output clearing wrapper.

0x56fff0 creates a 0x14-byte property with header words 0x14, 0x10, 0, 0,
calls device vtable +0x14 with selector 2, and maps a successful output word
at property +0x10: 0 to return 2, 1 to return 3, any other value to return 0.
A failed COM call returns 0. This whole function is recovered.

0x56fdb0 clears 0x21c output bytes, initializes a 0x244-byte capabilities
record with size 0x244, and calls vtable +0x3c. A nonzero COM result is
returned unchanged. This early failure exit is recovered. A zero result enters
the still unknown 0x56fdf9–0x56ff7e path, including 0x5a28a0 `_strncpy` calls and
vtable +0x0c/+0x38 calls. It crosses an explicit external boundary in C++.
The unit must not be counted as a complete 0x56fdb0 implementation.

Verification:

    py -3 scripts/research/verify-v2-input-buffer.py

All 37 native cases match original x86 for return, full output buffer and
COM call arguments/order. `verification.json` records original, probe and
source/build SHA guards, and separates full 0x56fff0 from partial 0x56fdb0.
This does
not test live DirectInput devices, whole mode-2 behavior, game launch or byte
identity.

Next trace: follow 0x56fdb0 success from 0x56fdf9, including the exact
0x244-byte capabilities layout, 0x5a28a0 string bounds, vtable +0x0c/+0x38
outputs and the three bounded loops. Then replay mode 2 through 0x532e10
with real original initialization and compare intermediate output words.
