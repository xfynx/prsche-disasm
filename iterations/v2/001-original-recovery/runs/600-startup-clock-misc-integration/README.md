# Run600 startup clock callback and render misc cleanup integration

Shared acceptance passes for frozen598002 (`598001` preserved) and599001 on597.
Four PARTIAL originals (`00560140` 55B, `004a4700` 90B, `0053f0b0` 99B and
`00449b40` 40B, 284 code bytes total) and 300B of loader-zero `.data`
(`005e99b8`, `00618e74..00618f73`, `00619758`, `006559e0`, `006559e8..006559f7`,
`006559fc..00655a07`, `0069ebb0`) integrate. Build001 compiles337 TUs across8
projects with unchanged inputs, zero compiler or other linker errors and115
unresolved names/120 references. Two real dependencies
(`startup_sequence_call_004a4700` and `render_misc_00449b40`) close; no new
unresolved name enters. There is no recovered game EXE. Registry920 preserves
partial parent domains.

Native comparisons pass428 measured cases (356 in598002 + 72 in599001) and8
material controls (4 in598 + 4 in599) atOd/O2. Canonical clock-worker callback
table (`006b7c20`), frame-pump word (`00655a08`) and render allocator (`0059ef90`)
owners are reused without duplication. Shared audit verifies833 source pins and
895 canonical providers.

Broader aliases/faults/lifetimes, callback bodies (`004a45d0`, `00449b70`,
`0053f980`), startup and gameplay remain open. Next independent packets are601
(`004b70d0` + `0056a680`) and602 (`00586cd0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/598-startup-clock-callback/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/599-render-misc-cleanup/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/600-startup-clock-misc-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/600-startup-clock-misc-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/600-startup-clock-misc-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
