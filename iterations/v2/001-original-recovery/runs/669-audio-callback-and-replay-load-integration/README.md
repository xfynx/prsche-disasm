# Run669 audio service callback and startup replay load integration

Shared acceptance `attempt 001` passes for frozen `667/005` (`667/001`..`004`
preserved) and `668/001` on `Run666`. Ten PARTIAL originals (`00590d80` 104B,
`00590df0` 48B, `00590e20` 70B, `005616b0` 20B, `00566a40` 156B, `00566910` 289B,
`004ad950` 101B, `004ad9c0` 1114B in `667`; `004146f0` 284B and `00413cf0` 420B
in `668`; 2606 code bytes total), `16065B` `.data`/`.bss` (`005d1bd4..005d1be0`
in `667`; `005e99fc`, `005e9a20..005ed843`, `005ed844`, `00606858`, `00606a80`,
`00699f34..00699fb3` in `668`), and `97B` `.data` read-only strings
(`005cc698..005cc6fa` in `668`) integrate. Build `001` compiles 382 TUs across
8 projects with unchanged inputs, zero compiler or other linker errors, and
72 unresolved names / 77 references. Two frontier
dependencies (`application_audio_service_callback_004ad9c0` and
`startup_sequence_call_00413cf0`) close with zero new unresolved names. There is no
recovered game EXE. Registry 1056 preserves partial parent domains.

Native comparisons pass 144 measured cases (`122` in `667/005` + `22` in
`668/001`) and 36 material controls (`18 + 18`) at `/Od`/`/O2`. Canonical
owners (`00656ab4`, `006b48c0`/`006b499c`, `006b7cc0`, `005d1740`, `006573e8`,
`005e99f4`, `0065b360`, audio/stream/PRNG/formatter/file helpers, and
`platform_get_tick_count`) are reused without duplication. Shared audit verifies
947 source pins.

Next launch `670` and `671` on remaining small startup/audio/render frontier leaves
(`005620c0`/`0059dea0`, `004a8b80`, `0053d360`/`0053d840`/`0053e890`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/667-audio-service-callback/native-config.json --attempt 005
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/668-startup-replay-load/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/669-audio-callback-and-replay-load-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/669-audio-callback-and-replay-load-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/669-audio-callback-and-replay-load-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
