# Run627 application audio init and diagnostic abort handler integration

Shared acceptance `attempt 002` passes for verified `625/002` and `626/002` on
`Run624` (`625/001`, `626/001`, and `627/001` logs are preserved immutable history
prior to renaming `application_audio_probe_init_625.cpp` ->
`application_audio_init_625.cpp` to satisfy `audit-v2-native-game-batch.py`
filename checks). Two PARTIAL originals (`004a66b0` 398B and `00565340` 381B,
779 code bytes total), 24B loader-zero `.data` (`006a5c24`, `005deb6c`,
`005deb84`, `005deb8c`, `005deb90`, `005deb94`), and 179B `.rdata` (`005b4ac0`
128B + `005bd4c4` 5B + `005bd4cc` 14B + `005bd4dc` 30B + `005d0b1c` 2B)
integrate. Build `002` compiles 355 TUs across 8 projects with unchanged inputs,
zero compiler or other linker errors, and 92 unresolved names / 95 references.
Four real dependencies (`application_audio_probe_initialize_004a66b0`,
`file_diagnostic_00565340`, `render_loader_report_00565340`, and
`window_scheduler_diagnostic_00565340`) close; no new unresolved name enters.
There is no recovered game EXE. Registry 956 preserves partial parent domains.

Native comparisons pass 552 measured cases (498 in `625/002` + 54 in `626/002`)
and 8 material controls (4 in `625` + 4 in `626`) at `/Od`/`/O2`. Canonical audio
init/device/state, mono/device diagnostic, lock, window shutdown, and process exit
owners are reused without duplication. Shared audit verifies 879 source pins.

Broader mode/descriptor bounds, actual MessageBox/process termination, startup
and gameplay remain open. Next independent packets are `628` (`00575820` +
`005757f0` + `00575810`) and `629` (`0056aff0`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/625-application-audio-probe-init/native-config.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/626-diagnostic-abort-handler/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/627-audio-init-diagnostic-abort-integration/build-config.json --phase configure --attempt 002
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/627-audio-init-diagnostic-abort-integration/build-config.json --phase build --attempt 002
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/627-audio-init-diagnostic-abort-integration/acceptance.json
```

Commands identify preserved/verified attempts; passed source/config/fixture inputs are frozen.
