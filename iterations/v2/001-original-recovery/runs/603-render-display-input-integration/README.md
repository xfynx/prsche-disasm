# Run603 render display apply and input route integration

Shared acceptance passes for frozen601001 and602001 on600. Three PARTIAL
originals (`0056a680` 38B, `004b70d0` 112B and `00586cd0` 63B, 213 code bytes
total), 12B of file-backed `.data` (`005e517c..005e5187`) and 808B of loader-zero
`.data` (`0065b398`, `006a5dd4..006a5deb`, `006ad440..006ad743`,
`006afc7c..006afc83`) integrate. Build001 compiles339 TUs across8 projects with
unchanged inputs, zero compiler or other linker errors and113 unresolved names/
118 references. Two real dependencies (`render_display_apply_004b70d0` and
`render_input_dispatch_00586cd0`) close; no new unresolved name enters. There
is no recovered game EXE. Registry923 preserves partial parent domains.

Native comparisons pass1240 measured cases (570 in601001 + 670 in602001) and8
material controls (4 in601 + 4 in602) atOd/O2. Canonical startup noop
(`00516950`), x87 `_ftol` (`005a0f98`), display texture height (`005deacc`) and
window tick (`006b7c40`) owners are reused without duplication. Shared audit
verifies838 source pins and913 canonical providers.

Broader aliases/faults/lifetimes, negative signed input events, external table
writers, startup and gameplay remain open. Next independent packets are604
(`005759f0`) and605 (`00549220` + `005381d0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/601-render-display-apply/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/602-render-input-route/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/603-render-display-input-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/603-render-display-input-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/603-render-display-input-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
