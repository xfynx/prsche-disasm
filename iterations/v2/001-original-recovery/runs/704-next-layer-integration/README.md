# Run704: next-layer integration (700+701+702+703)

Fresh build001 compiles 407 C++ translation units / 8 projects; 113 unresolved
names / 119 references remain, no EXE. Eighteen names close and eighteen typed
real children open (audio bank open/configure/reset, buffer release, entry FE
service, formatter compare, registry noop, RTTI camera/scene elements, scene
elem/ctor/dispatch/slot chain, texture alloc report/callback, secondary
destroy). Shared audit PASS: 3,656 measured native cases / 49 detected
mutations / 1,007 source pins. Registry 1152 adds nineteen full bodies /
1,611B.

Four completed worker batches enter the game graph unchanged:

- 700/003 scene reset leaf chain: `00458b80` (38B) + `00467f40` (77B); 12
  cases / 8 mutations; six heterogeneous family bodies excluded with evidence.
- 701/008 view teardown/route family: eight bodies / 525B; 72 cases / 11
  mutations; new loader-zero cell `0062810c`; `00463c30`/`00466500` excluded.
- 702/011 entry FE + scene route/transfer leaves: seven bodies / 625B; 116
  cases / 17 mutations; `00413960`/`0045dbd0` excluded.
- 703/005 audio finalize + period callback: `004a6bc0` (193B) + `005901b0`
  (153B); 3,456 cases / 13 mutations; `00562810`/`00563440` excluded pending
  run-273 storage proof (`006bda20`/`006b3020`).

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/704-next-layer-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/704-next-layer-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/704-next-layer-integration/acceptance.json
```

Remaining boundaries (backlog owns the full list): the 18 new children plus
the 8 evidence-excluded bodies (0043ed00/00448b10/0044f240/00451490/
004552b0/00455f60/00463c30/00466500/00413960/0045dbd0) and the storage-gated
`00562810`/`00563440`; fault/lifetime/RTTI domains, live devices and
full-game acceptance remain open.
