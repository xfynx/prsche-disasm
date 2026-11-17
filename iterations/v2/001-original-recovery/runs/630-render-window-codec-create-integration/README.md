# Run630 render window init and audio stream codec create integration

Shared acceptance `attempt 001` passes for frozen `628/001` and `629/001` on
`Run627`. Four PARTIAL originals (`005757f0` 26B, `00575810` 9B, `00575820`
270B, and `0056aff0` 564B; 869 code bytes total), 36B `.data` (`005e1960` 32B
callback table + `006a64bc` 4B loader-zero), and 248B `.rdata` (`005bd8b8`..`005bd9b4`)
integrate. Build `001` compiles 357 TUs across 8 projects with unchanged
inputs, zero compiler or other linker errors, and 96 unresolved names / 99
references. Two real dependencies (`render_initialize_window_00575820` and
`audio_stream_codec_create_0056aff0`) close; `005e1960` introduces its six real
callback frontier symbols (`0053a780`, `005756d0`, `005756e0`, `00575730`,
`00575770`, `005757d0`). There is no recovered game EXE. Registry 960 preserves
partial parent domains.

Native comparisons pass 148 measured cases (22 in `628/001` + 126 in `629/001`)
and 13 material controls (8 in `628` + 5 in `629`) at `/Od`/`/O2`. Canonical file
threads, heap locks, render display dimensions, render loader/library lifecycle,
window create/handlers/scheduler, diagnostic abort cleanup, audio stream codec
bytes, and shared diagnostic globals are reused without duplication. Shared
audit verifies 884 source pins.

Real THRASH DLL calls, unmapped stream buffer faults, the six newly exposed
`005e1960` callbacks, startup and gameplay remain open. Next active recovery
packets are `631` (five `005e1960` callbacks) and `632` (`0053a780` +
`0053bf20` + `004b0eb0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/628-render-window-initialize/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/629-audio-stream-codec-create/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/630-render-window-codec-create-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/630-render-window-codec-create-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/630-render-window-codec-create-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
