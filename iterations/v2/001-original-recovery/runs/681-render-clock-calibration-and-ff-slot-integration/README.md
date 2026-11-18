# Run681 render clock calibration and input FF-slot integration

Shared acceptance `attempt 001` passes for frozen `679/004` (`679/001`..`003`
preserved) and `680/001` on `Run678`. Nine PARTIAL originals (`00555a10` 431B,
`00555fa0` 270B, `005560b0` 278B in `679`; `005337a0` 54B, `005337e0` 41B,
`00533730` 40B, `00533760` 64B, `00533120` 60B, `00574080` 29B in `680`; 1267
code bytes total), `16B` `.data` (`005deb14`, `005deb24`, `005deb34`, `005deb38`),
and zero owned `.rdata` integrate. Build `001` compiles 390 TUs across 8 projects
with unchanged inputs, zero compiler or other linker errors, zero new unresolved
names, and 71 unresolved names / 76 references (unlocking upcoming callers
`render_clock_00555bc0`/`render_mode_clock_00555bc0`, `005330a0`, `00533320`,
`00533360`, and `00562810`/`00563440`). There is no recovered game EXE. Registry
1093 preserves partial parent domains.

Native comparisons pass 12856 measured cases (`1470` in `679/004` + `11386` in
`680/001`) and 47 material controls (`22 + 25`) at `/Od`/`/O2`. Canonical owners
(`0053c380`, `0053c2e0`, `005deb10`, `005deb48`, `006b7c7c`,
`frame_control_slot_fields_494`, `006be040`, `00533160`, and `005de620`) are
reused without duplication. Shared audit verifies 967 source pins.

Next launch `682` (`00555bc0` + `005a1f4a`/`005a1ebf` closing `render_clock_00555bc0`
and `render_mode_clock_00555bc0`) and `683` (`005330a0`, `00533320`, `00533360`, and
render/palette leaves `00572f30`/`00572f5b`/`00570420`/`00570490`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/679-render-clock-calibration-leaves/native-config.json --attempt 004
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/680-input-ff-slot-and-render-leaves/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/681-render-clock-calibration-and-ff-slot-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/681-render-clock-calibration-and-ff-slot-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/681-render-clock-calibration-and-ff-slot-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
