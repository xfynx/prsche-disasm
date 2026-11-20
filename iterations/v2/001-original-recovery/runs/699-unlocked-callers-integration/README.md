# Run699: unlocked callers integration (695+696+697)

Fresh build001 compiles 403 C++ translation units / 8 projects; 113 unresolved
names / 118 references remain, no EXE. Two names close (`004a6c90`,
`00590250` — both opened by Run694) and three real children become visible
(`audio_bank_finalize_004a6bc0`, `audio_period_callback_005901b0`, data cell
`audio_system_active_006b499c`). Shared audit PASS: 2,796 measured native
cases / 49 detected mutations / 998 source pins. Registry 1133 adds four full
bodies / 1,353B.

Three completed worker batches enter the game graph unchanged:

- 695/012 `00411d20` (769B) `ff_effect_initialize` — the startup/FF-effect
  caller feeding accepted `startup_sequence_call_004121b0`; 28 comparisons /
  19 mutations; owns BSS block `005e9408` + config cells; reuses 688 leaves.
- 696/002 `005346d0` (352B) `render_getclutptr_from_resource` — the
  getclutptr dispatcher; 208 cases / 14 mutations; owns 41B message
  `005bb3fc`; reuses 689/685/686/536/380 providers; unlocks
  `00562810`/`00563440`.
- 697/004 `00590250` (56B) + `004a6c90` (176B) — audio period callback set +
  bank-file probe message; 2,560 cases (1,280 per variant) / 16 mutations;
  owns `005d1444`/`005d146c`; exact Run690 extern matches.

The `audio_period_callback_probe_697.cpp` basename is allowlisted in
`original_probe_sources` (audit naming hygiene).

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/699-unlocked-callers-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/699-unlocked-callers-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/699-unlocked-callers-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): `004a6bc0`/`005901b0`
bodies and the `006b499c` owner now exposed; `00562810`/`00563440` unlocked by
696; Run400/695 state-name single-storage reconciliation; fault/locale/vtable
domains, live devices and full startup/gameplay remain open.
