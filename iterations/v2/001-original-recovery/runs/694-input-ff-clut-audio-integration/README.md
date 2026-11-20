# Run694: input FF / CLUT / audio probe integration

Fresh build001 compiles 397 C++ translation units / 8 projects; 69 unresolved
names / 72 references remain, no EXE. Two old names close
(`application_audio_period_control_00565c70`, `application_audio_probe_start_004a8b80`)
and two real children become visible (`application_audio_probe_message_004a6c90`,
`audio_period_callback_set_00590250`). Shared audit PASS: 24,380 native cases /
72 detected mutations / 984 source pins and exact canonical COFF ownership.
Registry 1121 adds seven full bodies / 1,868B.

Three completed worker batches enter the game graph unchanged:

- 688/001 input FF frame control: `005333a0` (219B) + `005334e0` (532B), 102
  cases / 28 mutations (resumed batch; two raw-PE-verified corrections over the
  dead session's partial sources). Unlocks `00411d20` ->
  `startup_sequence_call_004121b0`.
- 689/005 render CLUT: `00570780` (148B) + `00570820` (128B) +
  `00534830` (419B getclut16ptr dispatcher), 944 cases / 30 mutations.
  Unlocks `005346d0` -> `00562810`/`00563440`.
- 690/004 audio probe/period: `00565c70` (90B) + `004a8b80` (332B), 23,334
  cases / 14 mutations. Closed both live frontier names of its batch.

The `application_audio_probe_690.cpp` basename is allowlisted in
`original_probe_sources` (audit naming hygiene; not an FE probe TU).

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/694-input-ff-clut-audio-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/694-input-ff-clut-audio-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/694-input-ff-clut-audio-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): unowned `00590250` /
`004a6c90` bodies now exposed as real children; `006a6420` runtime writer and
`0065b318` writers unindexed; 688's `0069cb10` record-array readers
(`00533910`/`00533b40`/`005365xx`) must reuse the 688 extern; 494 semantic
cells `+0x80/+0x88/+0x8c` and 688's host arrays remain separate pending
single-storage reconciliation. COM vtable transport, live devices and
full-game acceptance stay unproved.
