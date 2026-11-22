# Run747 view teardown integration

On the Run743 baseline, the fresh Win32 build compiles **436 translation units**
across eight projects with no compiler or other linker diagnostics. It closes
`view_teardown_reset_00466500` with zero new unresolved names, leaving **99
unresolved names / 106 references** and no game EXE.

The shared audit passes for frozen Run746/002: **70 original-x86/C++
comparisons**, **11 material mutations**, **1,077 source pins**, the Run746 REA
session, and unique canonical COFF providers. Registry entries rise from
1,227 to **1,232**, adding the five Run746 bodies (`00466500`, `00466c30`,
`00466ca0`, `00466d10`, `00466d60`). Their inclusive original body ranges have
no overlap with the existing registry, including supplemental `body_ranges`.
There is no newly owned `.data`, `.rdata`, or `.bss` storage.

Run746 verifies valid non-null view/tree structures, acyclic node links,
original slot order, canonical lock/free-list endpoints, and exact ABI. Null or
cyclic trees, invalid-pointer faults, live renderer behavior, startup and
gameplay remain open. The native-proved Run744 header parser stays out of the
game graph until its unresolved parent `00566ea0` needs it. Run745 is tracing
the reachable render conversion parent before its depth child is considered.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/747-view-teardown-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/747-view-teardown-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/747-view-teardown-integration/acceptance.json
```
