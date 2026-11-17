# Run639 audio stream status and render seed PRNG integration

Shared acceptance `attempt 001` passes for frozen `637/001` and `638/001` on
`Run636`. Four PARTIAL originals (`00567810` 64B, `00567850` 68B, `00591320`
83B, and `00538040` 193B; 408 code bytes total), `24B` file-backed `.data`
(`005de910..005de927`), and `0B` `.rdata` integrate. Build `001` compiles 363
TUs across 8 projects with unchanged inputs, zero compiler or other linker
errors, and unchanged 88 unresolved names / 91 references (unblocking
reachable parents `004ae4d0`/`004ae8c0`). There is no recovered game EXE.
Registry 979 preserves partial parent domains.

Native comparisons pass 1160 measured cases (1026 in `637/001` + 134 in
`638/001`) and 15 material controls (8 in `637` + 7 in `638`) at `/Od`/`/O2`.
Canonical audio device state (`006b48c0[0xdc]`), audio canonical bindings
(`006b4a00`, `005896d0`, `005896f0`, `00589d20`), audio stream lookup
(`00566d60`), and frame services (`00566340`) owners are reused without
duplication. Shared audit verifies 899 source pins.

Companion seed writer `00538110`, reachable parent chain `004ae4d0`/`004ae8c0`,
live audio backend threads, startup and gameplay remain open. Active recovery
workers are `640` (`004a5f90`) and `641` (`0056bce0`..`0056c540`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/637-audio-stream-channel-status/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/638-render-seed-prng/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/639-audio-status-prng-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/639-audio-status-prng-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/639-audio-status-prng-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
