# Run731 scene tree constructor pair

Native002 PASS: `00455830..004558a6` and `004558b0..00455926`,119B each,
thiscall RET8. Production `scene_tree_constructors_731.cpp` reuses canonical
context005e4fe8, heap-enter/leave5322b0/5322c0 and new-head59eeb0. No new state
or unresolved child. Shared integration remains pending.

Both constructors zero holder[0], enter the current context+28 lock, pop a node
from a typed free list (refilling when empty), leave the reloaded lock, then set
holder.node/count/tag and node.tag/parent/self-links. First830 uses context+78,
refill(kind17,0); second8b0 uses context+3c,refill(kind2,0). They read the first
byte pointer only, preserve holder9..11 and unwritten node bytes, and returnself.
`original-listing.asm` records the exact indexed assembly; native-config pins
raw module/bodySHA before relocation. No guessed pool/type initialization.

Verification:

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/731-scene-tree-constructors/native-config.json --attempt 002
py -3 iterations/v2/001-original-recovery/runs/731-scene-tree-constructors/audit.py
```

2121 cases per `/Od` and `/O2`:2048 isolated ctor comparisons (all256 byte values,
both pools, empty/refilled versus nonempty, external versus holder+9 alias),
then73 actual731+721+726+716 composed comparisons. Isolated calls pass NULL as
the unused second pointer and check RET8, returnself and preserved nonvolatile
registers. Composition compares roots, both matrices, all touched/untouched node,
holder and allocation bytes, free lists, ordered heap calls and outgoingECX.
Raw original constructors replace controlled tree-ctor endpoints on the oracle
side. C++ production definitions execute on the candidate side. Seven material
controls detect wrong pool/kind/tag/next/self-link/count/node-tag.
Attempt001 preserves a faulting wrong-refill-kind2 mutation;002 uses invalid
kind18 to fail at the controlled endpoint's explicit argument assertion.

Input closure/receipt/COFF pins are in `evidence.json`. Audit checks registry
body_ranges and main-index ranges for overlap, and confirms no .data/.bss in
either production object. Packet takes no registry/shared/earlier-packet edits.

Production intake adds only this `.cpp`, its include directory and the existing
Run721 include directory. Registry entries are830/8b0,238B total, with recovered
children005322b0/005322c0/0059eeb0 and canonical context accessor. Reuse pinned
721/726/716 sources; fixtures remain test-only. New-head must return a valid node;
other aliases, invalid-pointer faults, broad concurrency/lifetime and live heap
remain outside the tested domain.
