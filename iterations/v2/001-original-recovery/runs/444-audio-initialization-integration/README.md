# Run444: audio initialization and DirectSound capability integration

Build002 compiles235 C++ TUs across8 projects. Two old names close and the real
CPU-feature child00597070 appears:180 names/187 references remain, no game EXE.
Seven original bodies/1,580B are added; an existing descriptor alias defect is
repaired without increasing the original-function count.

- [442](../442-audio-initialization/README.md):two parents944B;169,194 native cases,
  18 detected mutations. Raw accepted query/apply callers also exercise aliasing.
  Three summary bytes have original zero/ownership proof; device state is reused.
- [443](../443-audio-device-capabilities/README.md):five bodies636B and32B GUIDs;
  4,272 cases,9 mutations. Actual production platform-object import binding matches
  DSOUND ordinal1 and both USER32 window imports; game linkage includes dsound.lib.
- [445](../445-audio-owner-alias-regression/README.md):the immutable441 fixture
  rechecks the changed owner TU;1,392 cases,9 mutations,zero new bodies.

Shared audit PASS:174,858 cases across `/Od` and `/O2`,36 mutations,582 pins and
342 unique canonical COFF exports. No fixture providers enter the game graph.
Existing005656d0 now reads descriptor+74 after the forward copy and before the
state+78 store, matching005656e8/005656eb; the earlier+78 capture remains intact.
The descriptor=canonical+4 counterexample passes both optimizations.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/444-audio-initialization-integration/build-config.json --phase configure --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/444-audio-initialization-integration/build-config.json --phase build --attempt 002
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/444-audio-initialization-integration/acceptance.json
```

Full receipts/logs: `local/experiments/v2-audio-initialization-game-444`.
Build001 compiled all sources but could not open an existing deeply nested
DirectInput library (LNK1181). Its config/receipts remain unchanged. The short
root `local/builds/v2/a444` fixes that link-input problem;002 is the accepted build.
The path change required no native revalidation.442/443 failed fixture/control
attempts remain documented in their own packets.

CPU/OS00597070 remains controlled/unrecovered. Parent/probe composition and live
DirectSound, group00590070/00565990, full startup/display/gameplay, invalid memory
and concurrency remain open;403/411 stay PARTIAL. Next handle PR26, including its
description/comments, before starting another recovery batch.
