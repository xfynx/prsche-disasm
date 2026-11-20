# Run712: reverb/scene children integration (710+711)

Fresh build001 compiles 413 C++ translation units / 8 projects; 104 unresolved
names / 111 references remain, no EXE. Five names close (reverb bank tail,
reverb finalize/query, scene root finish, secondary destroy) and one new child
opens (`00590a80` audio group decode). Shared audit PASS: 658 measured native
cases / 26 detected mutations / 1,021 source pins. Registry 1166 adds five
full bodies / 392B.

Two completed worker batches enter the game graph unchanged:

- 710/007 audio reverb typed children: `005900b0` (133B) + `00598a70` (29B) +
  `00598cd0` (50B); 238 cases / 13 mutations; owns loader-zero
  `006b0a80[1024]` + `006b1680[4]`; Run705 reverb storage untouched;
  `00590a80` left as an unowned typed child.
- 711/004 scene root finish + secondary destroy: `0044fc30` (121B) +
  `0053f120` (59B); 420 cases / 13 mutations; reused canonical
  `application_state_006573e8`; no new owned data.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/712-reverb-scene-children-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/712-reverb-scene-children-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/712-reverb-scene-children-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): `00590a80` group decode;
the evidence-excluded heterogeneous bodies; storage-gated
`00562810`/`00563440` (run-273 proof); fault/lifetime/RTTI domains, live
devices and full-game acceptance.
