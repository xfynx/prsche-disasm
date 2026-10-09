# Run 013 — original input getstate mode 6 and DirectInput helpers

Source: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: 0x532e10, 0x56fce0, 0x56fd00, 0x56fd30 in the Porsche.exe
`research/binary-index/ghidra` call/reference index and the v2 full `disassembly.asm`. All four are indexed
without decompiler warnings. 0x532b80 initializes a 0x2180-byte input array,
which contains 32 slots of 0x10c bytes at 0x6be040. The count is 0x69cb0c.

Recovered from instructions: signed count comparison and null-device exits;
mode 6 uses low byte of slot +8 as type, with state sizes 0x50 for 1/4,
0x10 for 2, and 0x100 for 3. It passes slot +0xc to 0x56fce0, then returns
slot +8, even if the DirectInput read fails. Invalid type calls the diagnostic
boundary and returns null. 0x56fce0 calls 0x56fd00 then 0x56fd30. The helpers
call Poll (vtable +0x64) and GetDeviceState (+0x24); HRESULT 0x8007000c or
0x8007001e triggers Acquire (+0x1c), then one retry only if Acquire succeeds.
The 0x56fd00/0x56fd30 helpers leave the final Poll/GetDeviceState/Acquire
result in EAX; 0x56fce0 leaves 0x56fd30's EAX. Their callers in this unit
ignore it, but the native probe compares it. DirectInput methods are typed stdcall
boundaries and the probe records their order, arguments and controlled writes.

The native unit covers mode 6 and early count/device exits. Modes 1/2/8,
invalid mode diagnostics, and negative index access to memory preceding the
slot array remain explicit external boundaries. The invalid-type diagnostic
is recorded without claiming global diagnostic state recovery. This unit
does not restore real DirectInput devices or gameplay input acceptance.

Verification:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-input-state.py

All 1,026 native cases matched original x86 for the return, normalized whole
32-slot arena, and COM call order. `verification.json` records the source SHA,
source/build dependency SHA and probe SHA. The report distinguishes the partial
0x532e10 branch coverage from the three fully covered helpers. This is a unit
comparison, not a byte match or game launch.

Next trace: see `../017-input-modes/README.md` for the original mode dispatch,
callee addresses and still open boundaries. No other mode is implemented here.
