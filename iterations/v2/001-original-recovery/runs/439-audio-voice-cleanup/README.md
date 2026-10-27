# Run439: original voice-node and group cleanup

Recovers `00597010..00597062` (83B) and `00589c00..00589d14` (277B).
Both exact Run435 COFF contracts remain void cdecl1; incidental EAX is unclaimed.
No new storage: voice-table ownership stays in435, channel views in434 and
timestamp `006b49a8` is read from canonical device offset `0xe8`.

Native002 PASS: 54,267 cases per `/Od` and `/O2`, 108,534 total, with16 detected
mutations. Full indexed360B equal SHA-checked raw PE bytes. Proof compares exact
final memory and callback-time state hashes, with explicit stack and
EBX/ESI/EDI/EBP checks and canonical initial-state assertions before reset.

The node walker captures next before free, skips embedded `+0x2c/+0x64` nodes,
retains the captured signed-index voice entry and publishes next after release.
The finalizer preserves signed count, unsigned group, handle sign, nonzero active,
last flagged slot, preceding-record sentinel and the exact1/2 transition rules.
Timestamp loads follow each channel's clears, including tested physical aliases.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/439-audio-voice-cleanup/native-config.json --attempt 002
```

Evidence is in `original-index.json`, `ownership.json`, `coff.json` and
`evidence.json`; full logs/receipt are under
`local/experiments/v2-audio-voice-cleanup-439/002/`. Inputs are frozen for440 intake.
Attempt001 matched both native variants, then a deliberately wrong table-reload
mutation looped into fixture cap91. Only that mutation was narrowed; production
and fixture stayed unchanged, and001 is preserved.

`0058ac30` is a controlled native endpoint here; independent438 supplies the
production contract. Actual composed allocator execution belongs to440.
Valid local pointers, mapped aliases, a readable preceding sentinel and acyclic
lists bound this proof. Invalid pointers, cycles, faults, opaque raw returns,
concurrency, live device behavior and full gameplay remain open.
