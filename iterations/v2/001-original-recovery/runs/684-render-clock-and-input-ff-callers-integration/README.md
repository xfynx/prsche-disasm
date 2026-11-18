# Run684 render clock, CRT atol/atoi, and input FF-slot callers integration

Shared acceptance `attempt 001` passes for frozen `682/002` (`682/001` preserved)
and `683/001` on `Run681`. Ten PARTIAL originals (`005a1ebf` 139B, `005a1f4a` 11B,
`00555bc0` 979B in `682`; `005330a0` 118B, `00533320` 59B, `00533360` 59B,
`00572f30` 43B, `00572f5b` 53B, `00570420` 76B, `00570490` 34B in `683`; 1571 code
bytes total), `60B` `.data` (`005deae4..005deb0f`, `005deb20`,
`005deb28..005deb2f`, `005deb3c`), `4B` `.bss` (`0069cb08..0069cb0b`), and zero
owned `.rdata` integrate. Build `001` compiles 392 TUs across 8 projects with
unchanged inputs, zero compiler or other linker errors, zero new unresolved names,
and 69 unresolved names / 73 references. Both `render_clock_00555bc0` and
`render_mode_clock_00555bc0` close. There is no recovered game EXE. Registry 1103
preserves partial parent domains.

Native comparisons pass 2704 measured cases (`432` in `682/002` + `2272` in
`683/001`) and 54 material controls (`23 + 31`) at `/Od`/`/O2`. Canonical owners
(`005e54dc`, `005e52d0`, `005a2eae`, `00574e50/6b/89`, `00555a10/fa0/60b0`,
`005deb10..005deb38`, `005deb1c`, `005a3050`, `00532b50`, `00532e10`,
`00533120`, `00533160`, and `006be040`) are reused without duplication. Shared audit
verifies 972 source pins.

Next launch `685` and `686` on remaining render/palette leaves (`00570260`..`00570540`
and `005702a0`..`00571160`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/682-render-clock-and-crt-stricmp/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/683-input-ff-slot-callers-and-render-leaves/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/684-render-clock-and-input-ff-callers-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/684-render-clock-and-input-ff-callers-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/684-render-clock-and-input-ff-callers-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
