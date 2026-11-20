# Run709: audio/scene child integration (705+706+707+708)

Fresh build001 compiles 411 C++ translation units / 8 projects; 108 unresolved
names / 115 references remain, no EXE. Ten names close and five typed real
children open (`005900b0` bank-open tail, `00598a70`/`00598cd0` reverb
finalize/query, `0044fc30` scene root finish, `0053f120` secondary-destroy
body). Shared audit PASS: 168 measured native cases / 29 detected mutations /
1,016 source pins. Registry 1161 adds nine full bodies / 907B.

Four completed worker batches enter the game graph unchanged:

- 705/006 audio bank open + period configure/reset: three bodies / 465B;
  64 cases / 13 mutations; owns loader-zero reverb storage
  `006b08c0..006b0a6c`; reuses 677/451/438/221 providers.
- 706/017 scene child ctor/slot binding: `00469b50` (7B) + `0044fb40` (230B);
  62 cases / 9 mutations; `004211d0` is a typed forwarder to already-owned
  storage (no duplicate body); RTTI `005cf908/005cf928` extern data only;
  `00458c90`/`004522b0`/`00475c80` excluded with evidence (the last overlaps
  Run649 cell `00628a28`).
- 707/001 teardown children: `00539eb0`/`00514990`/`0059f1c0` (20B); 34
  cases / 5 mutations; `00465790` (592B) excluded as heterogeneous.
- 708/001 texture callback leaf: `005556a0` (10B); 8 cases / 2 mutations;
  `005a177b` already owned (reused), `005a134b` is external CRT
  `__RTDynamicCast` (evidence only).

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/709-audio-scene-child-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/709-audio-scene-child-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/709-audio-scene-child-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): the five new children; the
evidence-excluded bodies (`0043ed00`/`00448b10`/`0044f240`/`00451490`/
`004552b0`/`00455f60`/`00463c30`/`00466500`/`00413960`/`0045dbd0`/
`00458c90`/`004522b0`/`00475c80`/`00465790`); storage-gated
`00562810`/`00563440` (run-273 proof); fault/lifetime/RTTI domains, live
devices and full-game acceptance.
