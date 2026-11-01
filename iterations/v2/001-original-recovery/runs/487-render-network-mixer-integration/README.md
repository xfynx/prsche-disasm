# Run487: renderer replacement, network and mixer configuration

Frozen484/485/486 add16 original bodies/1,192B, repair the1,761B constructor
and add2,048B uniquely owned original data. Registry692 entries. Shared audit PASS:
29,346 cases/1,116,912 events/38 mutations/650 source pins/505 canonical exports.
One build compiles264 C++ units in8 projects. Seven old names close and16 real
callback/constructor providers appear:166 names/172 references versus483's157/163.
There is still no linked or executed recovered game EXE.

484 replaces the old render_display.cpp in the game target; historical source/
probe/proof files stay unchanged. Corrected x87 dimensions/projection, surface
constant, transforms, vertices, pixel dispatch, texture copy, finish receiver and
PBUF string are compared against full raw caller execution. The shared auditor
allows only an explicit one-for-one replacement covered by a fresh native packet;
3positive/9negative guards and unchanged483 regression pass. Compiler/template
inline accessors are excluded from canonical original-provider checks.

Important remaining constructor defect:494 independently traced44e870 as a
2-argument byte setter; frozen484 still forwards/records one word. The prior
improvements stand, but the constructor remains PARTIAL pending494/496. The raw
caller reuses queued readOK across vslot and later present calls; RET cleanup
alone did not establish the endpoint's arity. present-followup.json pins this
finding. No convenient one-argument implementation is accepted.

485 composes real IO-list/exit-registry/audio-lock providers and exposes560380.
486 composes real438 allocation/475 processing; nine constructors and six PCM
providers remain genuine typed dependencies. Opaque config+7 producer validity,
full473+475+476 scene, liveplatform/fault/concurrency/gameplay boundaries remain.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/487-render-network-mixer-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/487-render-network-mixer-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/487-render-network-mixer-integration/acceptance.json
```

Next ready intake:488 callback drain,489 actual pixel conversion+parent and492
C++ PCM kernels.490 is an unintegrated assembly reference, not the production
C++ packet; two unsupported3DNow branches retain an explicit missing oracle.
Source consolidation remains deferred until original-code recovery is complete.
