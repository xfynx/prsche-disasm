# Run597 startup transfer and quality tier integration

Shared acceptance passes for frozen595001 and596001 on594. Four PARTIAL originals
(`00468100` 8B, `004691c0` 11B, `0044e370` 150B and `0044dfb0` 35B, 204 code
bytes total) and one loader-zero `.data` DWORD (`00619770`, 4B) integrate.
Build001 compiles335 TUs across8 projects with unchanged inputs, zero compiler
or other linker errors and117 unresolved names/122 references. Two real
dependencies (`startup_sequence_transfer_004691c0` and
`startup_sequence_call_0044dfb0`) close; no new unresolved name enters. There
is no recovered game EXE. Registry916 preserves partial parent domains.

Native comparisons pass20032 measured cases (1024 in595001 + 19008 in596001) and
7 material controls (3 in595 + 4 in596) atOd/O2. All19 production instruction
bytes of `00468100`/`004691c0` match the original after relocation normalization.
Canonical display/mode/application/lifecycle owners are reused without
duplication. Shared audit verifies828 source pins and879 canonical providers.

Broader aliases/faults/lifetimes, live hardware/display producers, startup and
gameplay remain open. Next independent packets are598 (`004a4700` + `00560140`)
and599 (`00449b40` + `0053f0b0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/595-startup-transfer-end/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/596-startup-quality-tier/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/597-startup-transfer-quality-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/597-startup-transfer-quality-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/597-startup-transfer-quality-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
