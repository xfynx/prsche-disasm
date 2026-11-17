# Run636 async pool shutdown and render activate callback integration

Shared acceptance `attempt 001` passes for frozen `634/003` (`634/001` and
`634/002` preserved) and `635/001` on `Run633`. Seven PARTIAL originals
(`00592590` 63B, `00567cf0` 207B, `00564750` 61B, `00564700` 70B, `00563d30`
222B with `original-index-supplement.json`; plus `005360d0` 6B, `004b0ee0`
186B; 815 code bytes total), `0B` new `.data`, and `0B` new `.rdata` integrate.
Build `001` compiles 361 TUs across 8 projects with unchanged inputs, zero
compiler or other linker errors, and 88 unresolved names / 91 references. Both
targeted frontier dependencies (`application_main_function_00563d30` and
`render_display_activate_callback_004b0ee0`) close with zero new unresolved
names. There is no recovered game EXE. Registry 975 preserves partial parent
domains.

Native comparisons pass 108 measured cases (78 in `634/003` + 30 in `635/001`)
and 16 material controls (8 in `634` + 8 in `635`) at `/Od`/`/O2`. Canonical
startup pool, async callbacks, files/worker/wait/disk, frame pump, movie
service, startup service, window, heap lock, and scheduler owners are reused
without duplication. Shared audit verifies 894 source pins.

Live OS file/async worker threads, live `WM_ACTIVATEAPP` / `ShowCursor` state,
startup and gameplay remain open. Active Wave 6 packets are `637` (`00567810` +
`00567850` + `00591320`) and `638` (`00538040`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/634-async-pool-shutdown/native-config.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/635-render-display-activate-callback/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/636-async-pool-shutdown-activate-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/636-async-pool-shutdown-activate-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/636-async-pool-shutdown-activate-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
