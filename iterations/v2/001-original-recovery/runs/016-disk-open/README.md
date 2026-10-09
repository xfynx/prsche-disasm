# Run 016 — physical disk open and slot allocation

Source: Porsche.exe SHA256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
Index query: 0x5919a0 (673 bytes), 0x591c50 (140 bytes), callers
0x568900/0x592400, and callees 0x591760/0x591820, 0x5321f0/0x5322b0/
0x5322c0/0x53c290 plus corrected Win32 IAT addresses in
`research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl`.
The full `disassembly.asm` establishes the original branch and ABI details.

Recovered behavior: slot allocator initializes on a null table pointer,
locks 0x6af07c, scans 32-byte entries for a zero active byte, clears a free
entry, marks it active, and returns the index or count when full. Physical
open calls this allocator before zeroing the output and SetLastError(0).
For a valid slot, it transforms flags into CreateFile access/share/disposition/
attributes, stores the mode and path-derived device, creates the per-device
lock if absent, and reads bytes per sector (0x800 fallback). CreateFile
failure clears active and leaves output null. Success sets block size and
file size. Mapping is attempted only for flag 0x800; a failed mapping or view
clears that mode bit but still succeeds. The output is the negative `~index`
handle used by the earlier physical backend. The original does not close the
file handle during mapping failure.

`0x591760` path-device calculation, `0x591820` initialization, heap locks,
and Win32 APIs are typed recording boundaries. Path fixture returns device 3
and stays within the 32 per-device mutex cells shown by 0x591820; other
device values and real OS I/O are not accepted. The probe controls OS
results and compares full two-slot state, mutex identity, API arguments/
order, output handle and return with original x86.

Verification:

    powershell -NoProfile -ExecutionPolicy Bypass -File scripts/build-v2.ps1
    py -3 scripts/research/verify-v2-disk-open.py

All 1,672 cases matched the unchanged original x86. The report compares both
32-byte file slots, per-device mutex identity, ordered boundary calls and
arguments, encoded output and return. `verification.json` records the binary,
probe and direct source/build dependency SHA; `source-functions.jsonl` pins
the two original body ranges and hashes. 0x5919a0 is 673 bytes with body
SHA256 `16600f2da8456f8d2aa04ad7619281fc401289ee2a3b1a3572e6152bdb5e8dc5`;
0x591c50 is 140 bytes with body SHA256
`0eaaeb0689b651606285b4426952f90c87a73db7920663e2b1fe0954c22a7751`.
This is original behavior proof for the bounded unit, not a byte match or
real disk-I/O/game-launch acceptance.
