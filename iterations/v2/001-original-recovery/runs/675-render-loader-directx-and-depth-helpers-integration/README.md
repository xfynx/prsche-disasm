# Run675 render loader DirectX and depth helpers integration

Shared acceptance `attempt 001` passes for frozen `673/001` and `674/003` (`674/001`..`002`
preserved) on `Run672`. Nine PARTIAL originals (`00574eb0` 202B, `00414bd0` 75B,
`00414c30` 124B in `673`; `005345e0` 74B, `00535340` 21B, `00535360` 24B,
`00571490` 70B, `00571520` 14B, `00573070` 3B in `674`; 607 code bytes total),
`84B` `.data` (`005de574..005de5ab`, `005de5ac..005de5c7`), and zero owned `.rdata`
integrate. Build `001` compiles 386 TUs across 8 projects with unchanged inputs,
zero compiler or other linker errors, zero new unresolved names, and 71 unresolved
names / 76 references. One frontier dependency (`render_loader_directx_00574eb0`)
closes, and unlocker helpers prepare upcoming callers such as `005350e0` and
`004121b0`. There is no recovered game EXE. Registry 1072 preserves partial parent
domains.

Native comparisons pass 1764 measured cases (`38` in `673/001` + `1726` in `674/003`)
and 42 material controls (`21 + 21`) at `/Od`/`/O2`. Canonical owners (`005a3be5`,
`005a3b9d`, `00531ca0`, `005323e0`, `0056e290`, `porsche/render_loader.hpp`
declaration of `00574eb0`, Win32 `version.lib`/`GetVersionExA`, and shared
literal `005d11e8`) are reused without duplication. Shared audit verifies 957
source pins.

Next launch `676` and `677` on remaining math/input/audio leaves (`00532b50`..`00411710`,
`00565b30`/`00565ad0`/`00590140`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/673-render-loader-directx-and-startup-alloc/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/674-render-depth-helper-leaves/native-config.json --attempt 003
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/675-render-loader-directx-and-depth-helpers-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/675-render-loader-directx-and-depth-helpers-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/675-render-loader-directx-and-depth-helpers-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
