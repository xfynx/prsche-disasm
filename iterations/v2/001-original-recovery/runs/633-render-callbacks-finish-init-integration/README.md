# Run633 render callbacks and finish init integration

Shared acceptance `attempt 001` passes for frozen `631/001` and `632/001` on
`Run630`. Eight PARTIAL originals (five `005e1960` callbacks in `631`:
`005756d0` 11B, `005756e0` 71B, `00575730` 61B, `00575770` 84B, `005757d0` 23B
with `original-index-supplement.json`; plus `632`: `0053a780` 101B, `0053bf20`
46B, `004b0eb0` 39B; 436 code bytes total), `0B` new `.data`, and `16B`
`.rdata` (`005bef50` `IID_IDirectDraw2`) integrate. Build `001` compiles 359 TUs
across 8 projects with unchanged inputs, zero compiler or other linker errors,
and 90 unresolved names / 93 references. All seven targeted dependencies
(`004b0eb0`, `0053a780`, `005756d0`, `005756e0`, `00575730`, `00575770`,
`005757d0`) close; `004b0eb0` exposes its single `004b0ee0` callback frontier
name. There is no recovered game EXE. Registry 968 preserves partial parent
domains.

Native comparisons pass 68 measured cases (36 in `631/001` + 32 in `632/001`)
and 14 material controls (8 in `631` + 6 in `632`) at `/Od`/`/O2`. Canonical
heap lock, frame pump storage, thread lock, diagnostic, window state/keys/
handlers/procedure/runtime, and `render_window_callbacks_005e1960` owners are
reused without duplication. Shared audit verifies 889 source pins.

Live COM/Win32 hook teardown, multi-threaded lock contention, `004b0ee0`
activation callback, startup and gameplay remain open. Active recovery packets
are `634` (`00563d30`..`00592590`) and `635` (`005360d0` + `004b0ee0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/631-render-window-callbacks/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/632-render-display-finish-init/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/633-render-callbacks-finish-init-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/633-render-callbacks-finish-init-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/633-render-callbacks-finish-init-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
