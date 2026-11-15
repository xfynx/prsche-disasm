# Run580 comparator integration

Shared acceptance passes for frozen579004 on Run578. Comparator00554310 and
state probe00554530 contribute 567 original code bytes and remain PARTIAL.
Actual selector54820 composes with the new comparator, and canonical359 driver
bindings preserve get10/set1/restore order and the first set's return value.

Build001 compiles 325 TUs across 8 projects with unchanged inputs and zero
compiler or other linker errors. The real comparator name closes. The measured
frontier is 127 unresolved names and 132 references, with no EXE. Registry900
retains earlier semantic dependency classifications.

The audit verifies 1,606 new native scenes, 3,912 events, seven material controls,
802 source pins and 854 listed canonical providers. The same process also
reruns 698 earlier transfer comparisons. These are reported separately from
the new scenes, and their mutation proof is reused.

Production COFF has ten unique definitions and three existing canonical
dependencies. New original writable data totals 884 bytes, comprising 876
initialized bytes and two 4-byte loader-zero cells. Independent PE checks cover
both preserved payloads, sparse field values and all 25 host pointer relocations.
The two null slots are retained. Sparse format flags use the first DWORD of
each original record, and canonical546 bit-depth fields retain their owner.
Raw payload gaps are preserved without assigning semantics to their contents.

Cases cover admitted format0..17/palette0..8 inputs, all indexed palette pairs,
duplicate/missing preference ranks, source bit8 and capability penalties, early
rejects, first-set return, restoration and dynamic callback/cache/table effects.
Nonvolatile/stack ABI and one seeded FP state are compared at Od/O2. Broader
enum/record, alias/fault/lifetime/concurrency, live driver, startup and gameplay
domains remain open. Function-pointer normalization is limited to the known
original/compiled comparator identities at the controlled transport boundary.

Fresh REA6.9 Ghidra dossiers cover both bodies. Their complete local Evidence
is hash-pinned alongside original PE/index and native artifacts. Attempts001–003
remain unaccepted setup/fixture failures. The shared build and audit each ran once.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/579-texture-format-comparator/native-config.json --attempt 004
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/580-texture-comparator-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/580-texture-comparator-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/580-texture-comparator-integration/acceptance.json
```

Commands identify preserved attempts. Next is Run581's reachable driver-state
packet. Actual depth conversion5350e0 remains a separate unresolved dependency.
