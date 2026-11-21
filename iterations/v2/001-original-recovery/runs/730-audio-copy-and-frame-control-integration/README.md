# Run730 shared audio copy, frame control and scene tree integration

On the Run727 baseline, the Win32 build compiles **425 translation units** across
eight projects, replacing `400-frame-loop-clusters/00412030.cpp` with
`729-frame-control-state-consumer/frame_control_state_729.cpp` and adding
`728-audio-resource-copy/audio_resource_copy_728.cpp` and
`731-scene-tree-constructors/scene_tree_constructors_731.cpp`. Six unresolved
symbols close with zero new unresolved names, leaving **97 unresolved names /
104 references** and no game executable.

- Run728/005 adds `audio_resource_copy_0058e310` (399B) and 4B readonly
  `005c1694` (`audio_copy_min_005c1694`), reusing canonical `00597c10`,
  `00597dc0`, `00597f20`, `005a0f98`, `005c1698` and `006b48c0+0xe3`.
- Run729/002 replaces the unregistered Run400 `00412030` TU (91B, 0B new data)
  to consume canonical Run695 `frame_control_ff_state_005e9408`, closing the
  three stale Run400 `frame_control_*` globals (`005e940c`, `005e9410`,
  `005e9420`). Attempt `001` is preserved (callsite offset `0x53` vs `0x52`
  fixture typo).
- Run731/002 adds `scene_stage_tree_ctor_00455830` and
  `scene_stage_tree_ctor_004558b0` (119B each, 0B new data), reusing
  canonical `005e4fe8`, `005322b0`, `005322c0` and `0059eeb0`.

The shared audit passes **14,610 original-x86 comparisons** across `/Od` and
`/O2` (`728/005`: 5,760 cases / 10 mutations; `729/002`: 4,608 cases / 7
mutations; `731/002`: 4,242 cases / 7 mutations; 24 material controls total),
verifies **1,053 source pins** and audits 13 REA sessions (including
`v2-audio-scene-724-rea/001` for `0058e310` and `v2-audio-scene-730-rea/001`
for `00412030`, `00455830` and `004558b0`). Registry total: **1,186 entries**.
Bounded component domains, controlled endpoints, live devices, faults,
concurrency and full startup remain open.

```powershell
$run = 'iterations/v2/001-original-recovery/runs/730-audio-copy-and-frame-control-integration'
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase configure --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config "$run/build-config.json" --phase build --attempt 002
py -3 scripts/research/audit-v2-native-game-batch.py --config "$run/acceptance.json"
```
