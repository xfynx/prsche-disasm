# Run698: application startup cluster integration (691+692+693)

Fresh build001 compiles 400 C++ translation units / 8 projects; 112 unresolved
names / 116 references remain, no EXE. Seven old names close
(`004a88a0`, `004a8cd0`, `004b68f0`, `00413ea0`, `004640b0`, `00467740`,
`00468fb0`) and fifty typed real children become visible — the workers' honest
extern seams for the next recovery layer (scene stage/route/teardown, FE-entry
calls, sim boundaries, player tables). Shared audit PASS: 374 measured native
cases / 75 detected mutations / 991 source pins and exact canonical COFF
ownership. Registry 1129 adds eight full bodies / 2,479B.

Three completed worker batches enter the game graph unchanged:

- 691/007 sim teardown / startup playlist / Sim De-init: `004a88a0` (471B) +
  `004a8cd0` (235B) + `004b68f0` (337B), 68 case runs / 44 mutations; owns
  playlist table `00656528` and log literals; reuses 690 cells without
  duplicates; 21 unowned typed boundaries.
- 692/015 FE-entry reset + frame/session reset: `00413ea0` (296B) +
  `00414eb0` (196B), 46 comparisons / 18 mutations; owns `fe_loop_word_*`
  cells and `fe_replay_scratch_005ed848[0x6400]`. The 2,674B FE main-loop
  `004152e0` is evidence-only (≈70 unrecovered callees) and is NOT integrated.
- 693/010 view-slot setup / display teardown / scene-enter:
  `004640b0` (564B) + `00467740` (141B) + `00468fb0` (236B), 260 cases /
  13 mutations; null-display/fault domains excluded; two partial-work defects
  corrected against raw PE.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/698-app-startup-cluster-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/698-app-startup-cluster-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/698-app-startup-cluster-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): the 50 new typed children
are the next frontier (scene/route/teardown cluster, FE-entry calls, sim
boundaries); `004152e0` needs its ~70 callees first; fault/locale/vtable
domains and full startup/display acceptance remain open.
