# Run624 render frame begin state and audio stream service consumed integration

Shared acceptance passes for frozen622001 and623001 on621. Four PARTIAL
originals (`00534540` 12B, `00535a90` 104B, `00566d80` 131B and `00566e40`
95B, 342 code bytes total) and 44B of file-backed `.data` (`005de680..005de6ab`)
integrate with zero new `.rdata`. Build001 compiles353 TUs across8 projects with
unchanged inputs, zero compiler or other linker errors and96 unresolved names/
100 references. Four real dependencies (`game_setup_draw_begin_00534540`,
`splash_progress_driver_frame_begin_00534540`,
`render_resource_texture_state_00535a90` and
`audio_stream_service_consumed_00566e40`) close; no new unresolved name enters.
There is no recovered game EXE. Registry954 preserves partial parent domains.

Native comparisons pass3820 measured cases (3600 in622001 + 220 in623001) and
9 material controls (5 in622 + 4 in623) atOd/O2. Canonical render descriptor
(`521`/`374`), window shutdown state (`window_shutdown`), render state flush
(`527`/`533`/`render_settings`) and audio stream storage (`561`) owners are
reused without duplication. Shared audit verifies873 source pins and966
canonical providers.

Broader aliases/faults/lifetimes, negative/out-of-range stage indices, null
audio stream slots, startup and gameplay remain open. Next independent packets
are625 (`004a66b0`) and626 (`00565340`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/622-render-frame-begin-state/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/623-audio-stream-service-consumed/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/624-frame-begin-audio-consumed-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/624-frame-begin-audio-consumed-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/624-frame-begin-audio-consumed-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
