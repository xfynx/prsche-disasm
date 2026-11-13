# Run576 texture scheduler integration

Shared acceptance passes for frozen Run575 native001 on Run574. Five PARTIAL
original bodies cover 1,111 code bytes. The two production TUs define seven
unique symbols, including the existing void scheduler facade and callback owner.
The 120 readonly diagnostic bytes match the original PE, and the four-byte
callback owner matches its loader-zero tail. Nine existing dependencies retain
unique canonical providers.

Build001 compiles 321 translation units across eight projects with unchanged
inputs and zero compiler or other linker errors. Both targeted names close,
`render_display_texture_update_005550e0` and `render_texture_process_005554b0`.
The measured frontier is 128 unresolved names and 135 references, with no EXE.
Registry893 records all five entries as partial. Earlier semantic parent
dependencies retain their classifications.

The shared audit verifies 808 native scenes, 1,032 core/facade comparisons,
2,898 events, ten mutation controls, 792 source pins and 836 listed canonical
providers. Actual scheduler/prepare/notify and canonical release/process chains
execute against the original x86 at Od/O2. Run575 owns detailed oracle, ABI,
REA, data ownership and mutation evidence.

Mapped counts0..32, signed score selection, callback/driver field and table
reloads, captured flags, descriptor words/nullness, used integer returns and
one seeded full FP state are covered. Out-of-range counts, arbitrary aliases,
faults, lifetimes, concurrency, stack descriptor identity, indirect return use,
live drivers, full startup and gameplay remain open.

```powershell
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/576-render-texture-scheduler-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/576-render-texture-scheduler-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/576-render-texture-scheduler-integration/acceptance.json
```

Passed attempts are immutable. Established elevated MSBuild execution was used.
Next trace the reachable texture allocation/copy providers from this frontier.
