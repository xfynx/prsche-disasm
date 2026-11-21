# Run718: audio resource-map slot allocator

Recovers the full 60-byte `0058f7a0..0058f7db` body exposed by Run715's
`00599610` caller. The exact existing declaration is retained:
`void* __cdecl audio_group_slot_0058f7a0(std::uint32_t key)`.

The original masks the canonical count to unsigned low16, scans 8-byte rows,
writes the supplied key to the first zero-key row, preserves its payload DWORD,
and rereads the canonical map base for the returned row address. Zero/full count
returns null. Key zero is accepted; no null-map guard is invented.

Original `Porsche.exe` SHA-256 is
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`;
body SHA-256 is `a702a6ea7b7988efb2372269799f05c4aa32f33111085b286b34d161415360e9`.
Index query: `0058f7a0|0058f220|0058a970` in the Porsche Ghidra function index
and disassembly. Raw PE bytes, all three absolute references and both RET exits
are pinned. No calls or new cells. Run452's count/map owners are reused; the
fixture compiles actual Run452 and Run443 owner TUs. Their unused platform edges
fail closed. The accepted Run714 build's 414 compiler roots and recursive local
headers (771 files) contain one definition per map/count cell, both in Run452.
Registry/main-index body ranges have zero overlaps; original-index supplements
have no corresponding spans. Details: `scope-evidence.json`, `evidence.json`.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/718-audio-resource-slot/native-config.json --attempt 002
py -3 iterations/v2/001-original-recovery/runs/718-audio-resource-slot/audit-ownership.py
```

Native receipt PASS: `local/experiments/v2-audio-resource-slot-718/002/receipt.json`.
557 measured cases at each of `/Od` and `/O2`; 8/8 material controls; 178 input
pins and 149 output pins. Checks compare all 524,312 map bytes, payloads/canaries,
return, unchanged globals and ESP/EBP/EBX/ESI/EDI. Counts include 0, 1, 2, 3,
8, 31, 256, 32767, 32768 and 65535 with high-word poison; keys include zero and
high-bit values; empty-first/middle/last/full maps are covered. Production initial
count/map bytes are checked against immutable PE/loader-zero bytes before reset.
Attempt001 is retained: both variants passed, but mutation diagnostics lacked an
explicit stdout flush. Attempt002 changes only fixture flushing and passes.

Maps are stable, disjoint from canonical global cells, and readable/writable for
their full extent. Null map is exercised only with count zero. Global-cell aliasing,
asynchronous mutation, invalid-memory fault parity, actual Run715 composition,
live devices/audio and full startup remain open. No CMake/registry/shared-game
integration is claimed; coordinator owns that acceptance. Frozen proof inputs
must remain unchanged. `prepare.py` is initial evidence generation, not a command
to rerun over accepted inputs.
