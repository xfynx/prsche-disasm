# Run621 shutdown network destroy and engine service consume resource integration

Shared acceptance passes for frozen619001 and620001 on618. Three PARTIAL
originals (`0048ff30` 522B, `00490420` 170B and `0048cb50` 361B, 1053 code bytes
total) and 12B of `.rdata` (`005d072c`, `"CDataPacket\0"`) integrate with zero
new writable `.data`. Build001 (configured in `configure-002`, `configure-001`
preserved) compiles351 TUs across8 projects with unchanged inputs, zero compiler
or other linker errors and100 unresolved names/104 references. Two real
dependencies (`ShutdownNetwork311::destroy_0048ff30` and
`engine_service_consume_resource_0048cb50`) close; no new unresolved name
enters. There is no recovered game EXE. Registry950 preserves partial parent
domains.

Native comparisons pass138 measured cases (88 in619001 + 50 in620001) and8
material controls (4 in619 + 4 in620) atOd/O2. Canonical startup network
(`311`), network lifecycle/callback drain (`289`/`488`), heap/context allocation
(`289`/`331`), splash network queries (`510`) and network member list (`289`)
owners are reused without duplication. Shared audit verifies868 source pins and
960 canonical providers.

Broader aliases/faults/lifetimes, null receiver/network edge cases, startup and
gameplay remain open. Next independent packets are622 (`00534540` + `00535a90`)
and623 (`00566e10` + `00566e40`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/619-shutdown-network-destroy/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/620-engine-service-consume-resource/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/621-network-destroy-consume-integration/build-config.json --phase configure --attempt 002
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/621-network-destroy-consume-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/621-network-destroy-consume-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
