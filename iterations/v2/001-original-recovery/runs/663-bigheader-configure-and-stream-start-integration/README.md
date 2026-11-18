# Run663 bigheader configure and audio service stream start integration

Shared acceptance `attempt 001` passes for frozen `661/003` (`661/001`..`002`
preserved) and `662/001` on `Run660`. Eleven PARTIAL originals (`00568b50` 64B,
`00533d70` 39B, `00562100` 499B, `00562300` 63B, `0059df70` 206B, `004ae100`
423B, `0056b790` 105B, `0056b800` 91B, `0056b690` 250B, `0056c040` 242B, and
`00567550` 267B; 2249 code bytes total), `47B` `.data`/`.bss` (`005d1bf0..005d1c19`
and `0065b314` in `661`; `006a5df0` in `662`), and `244B` `.rdata`
(`005bcde4..005bce88` in `661`; `005bdbd0..005bdbf9` and `005bdd04..005bdd2c` in
`662`) integrate. Build `001` compiles 379 TUs across 8 projects with unchanged
inputs, zero compiler or other linker errors, and 75 unresolved names / 80
references. Two frontier dependencies (`application_audio_probe_configure_004ae100`
and `audio_service_stream_start_00567550`) close with zero new unresolved names.
There is no recovered game EXE. Registry 1043 preserves partial parent domains.

Native comparisons pass 128 measured cases (70 in `661/003` + 58 in `662/001`)
and 36 material controls (20 in `661` + 16 in `662`) at `/Od`/`/O2`. Canonical
owners (file open/read/chunks/close, request read/wait/sync, heap alloc/locks,
resource atomic context/roots, audio resource kind/descriptor/banks/channels,
stream codec lock/advance, and diagnostics) are reused without duplication.
Shared audit verifies 939 source pins.

Active flash workers `664` (`00532860`/`00434aa0`/`00434a90`) and `665`
(`005a2780`..`00561b80`) prepare integration in `Run666`. Audio probe start
`004a8b80` and startup leaves (`00413cf0`, `004ad9c0`) follow.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/661-bigheader-and-audio-probe-configure/native-config.json --attempt 003
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/662-audio-service-stream-start/native-config.json --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/663-bigheader-configure-and-stream-start-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/663-bigheader-configure-and-stream-start-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/663-bigheader-configure-and-stream-start-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
