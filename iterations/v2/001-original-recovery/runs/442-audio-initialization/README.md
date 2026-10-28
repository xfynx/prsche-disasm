# Run442: original audio descriptor initialization

Recovers `0058a4f0..0058a68a` (411B) and `0058a690..0058a8a4` (533B).
The existing int32 initialization and void apply COFF contracts match. Canonical
device storage is reused; only the three separately proved loader-zero summary
bytes `006b4883..85` are new. Full440 manifest plus delta checked411 source/header
files; the root-owned caller repair is the only admitted source difference.

Native004 PASS: 84,597 cases at each of `/Od` and `/O2`, 169,194 total, with18
detected mutations. SHA-checked raw/index bodies include944 new bytes and140 bytes
of accepted query/apply callers. Checked relocations cover109 absolute operands
and5 calls. Tests compare exact full Scenes at child entry/exit and final state,
plus cdecl stack and EBX/ESI/EDI/EBP. Initial canonical and new storage zeros are
observed before fixture reset; incidental EAX from void apply is ignored.

Covered behavior: all capacity bytes and signed flag bytes; probe negative/zero/
positive returns; capacity0 preserving `cc/cd`; 24-DWORD active rollback;
unsigned clamp boundaries; exact sums255/256/257/510; exhaustive short flag lists,
255-flag compaction with canonical aliases, restart and updated count bounds;
summary priorities, period clamps and feature callback ordering/bit preservation.
Raw callers exercise external descriptors and canonical offsets0/4/14/7c.

The composed `+4` descriptor case exposed an old `005656d0` alias-order defect:
original loads `descriptor+0x74` before storing state `+0x78`. The coordinator
repaired the shared owner; this proof verifies that repair without adding another
original count. The ownership artifact pins the exact admitted difference.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/442-audio-initialization/native-config.json --attempt 004
```

Evidence: `original-index.json`, `ownership.json`, `coff.json`, `evidence.json`.
Full logs/receipt: `local/experiments/v2-audio-initialization-442/004/`.
Passed inputs are frozen; Root444 owns integration. Failed attempts are preserved:
001 omitted5 indexed relocation operands,002 found the old caller defect,003
passed both variants but exposed the missing exact257 mutation case.

`0058e650` is controlled here and independently supplied by443. `00597070`
remains an unresolved uint32 CPU/OS endpoint; no failure locals or CPU algorithm
are guessed. Valid local buffers, descriptor aliases and single-threaded state
bound acceptance. Live devices/startup, asynchronous mutation, invalid/faulting
memory and full gameplay remain open.
