# Run717: DirectSound slot configure

Full original `0058f220..0058f286` (103B), SHA256
`2f099cf0e7722f5f2ca32ead45aca5867a0657c0eb1d17339a85aee5afdbcc45`.
The canonical Run715 declaration is retained: cdecl6, six DWORD argument slots,
low byte/word consumed for the first two. Cached Ghidra stdcall inference is
corrected by complete raw RET C3 and caller715 cleanup. Child0058f5b0 is cdecl0;
child0058e500 cdecl1 (0058f278 cleans4). Both remain unrecovered dependencies.

No owned data is added. Run443 owns device006ad760; Run452 owns all256x24B
slots006ad7b8..006aefb7. Both actual owner TUs are compiled into this proof.
Indexed interior aliases6ad7c0/c4/c8/cc/ce/cf map into the canonical table.
Registry1167 has no entry/body overlap;16 supplements/21 recorded ranges have
no overlap. Raw PE bytes, complete bodies and reused Ghidra checkpoint provenance
are in scope-evidence.json.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/717-audio-slot-configure/native-config.json --attempt 004
```

PASS:216 cases at each /Od and /O2;12/12 material /O2 controls detected.
Receipt: `local/experiments/v2-audio-slot-configure-717/004/receipt.json`.
Before seeding, the real production device/table initial bytes match raw PE
file-backed/loader-zero bytes. Both sides use actual canonical owners. The
fixture compares call order, signed guards, all6144 slot bytes before create and
after return, used returns and ESP/callee-saved registers. Cases include absent
device, nonpositive free-slot returns, positive slots1/2/127/255, signed create
returns, truncation, untouched row+4, callback changes to device and slot rows,
and original pointer-only clearing after a failed create. Controlled cdecl
callbacks transport the two child boundaries; their interiors/live DirectSound
remain open. Positive out-of-range slots, faults, concurrency and game startup
remain open. No graph integration is claimed.

Attempts001/002 preserve a fixture PE-path failure (001 output unflushed);
003 passed both native variants but was invalidated by input-pin drift when the
evidence file was edited during mutation execution.004 reruns frozen inputs.
