# Run678 input-slot/FE-attachment and audio-bank/CPU-probe leaves integration

Shared acceptance `attempt 001` passes for frozen `676/001` and `677/003` (`677/001`..`002`
preserved) on `Run675`. Twelve PARTIAL originals (`00532b50` 46B, `00533160` 58B,
`00533480` 82B, `00532ff0` 21B, `004116d0` 62B, `00411710` 67B in `676`;
`00565b30` 35B, `00565ad0` 81B, `00590140` 41B, `00574e50` 27B, `00574e6b` 30B,
`00574e89` 34B in `677`; 584 code bytes total), `4B` `.bss` (`005e8e5c..005e8e5f`),
and zero new `.data`/`.rdata` integrate. Build `001` compiles 388 TUs across 8
projects with unchanged inputs, zero compiler or other linker errors, zero new
unresolved names, and 71 unresolved names / 76 references (unlocking upcoming
callers `00555bc0`, `00411d20`, and `004a6bc0`). There is no recovered game EXE.
Registry 1084 preserves partial parent domains.

Native comparisons pass 540 measured cases (`388` in `676/001` + `152` in `677/003`)
and 38 material controls (`21 + 17`) at `/Od`/`/O2`. Canonical owners (`0069cb0c`,
`006be040`, `frame_control_slot_fields_494`, `0053c290`, `005e8e60`, `00532e10`, and
`006b48c0`) are reused without duplication. Shared audit verifies 962 source pins.

Next launch `679` and `680` (`render_clock_00555bc0` callees `00555a10`/`00555fa0`/`005560b0`,
plus input/render leaves `00533120`/`00533730`/`005337e0`/`00574080`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/676-startup-input-slot-and-math-leaves/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/677-audio-bank-state-and-cpu-feature-leaves/native-config.json --attempt 003
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/678-input-slot-math-and-audio-cpu-leaves-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/678-input-slot-math-and-audio-cpu-leaves-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/678-input-slot-math-and-audio-cpu-leaves-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
