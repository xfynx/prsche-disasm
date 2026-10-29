# Run447: OS/CPU startup feature integration

Three original bodies / 226 bytes from frozen [Run446](../446-cpu-features/README.md)
are integrated. Build002 compiles 237 C++ units across 8 projects. The CPU feature
provider closes one old name, with no new frontier: 179 names / 186 references remain.
There is still no recovered game executable or live startup acceptance.

Shared audit PASS: 28,570 native cases across `/Od` and `/O2`, 90,720 events,
12 detected mutations, 586 source pins and 347 unique canonical exports. Both ISA
helpers match their original body bytes at both optimizations. Opaque OS output
is preserved through the original stack layout; no new global storage is added.
The C++ core and platform adapters add zero original-function counts. Actual
GetVersionExA import identity is proved by Run446's nonexecuted SDK-linked DLL.

One REA session covers all three CPU bodies and five next-group navigation bodies,
with eight audited dossiers. Attempt001 retains sandbox `spawn EPERM`;002 finished
with a CRLF query config. Staging caught that config's normalization to LF, so003
records the final LF inputs. The exact002 config is archived with its local receipt;
no old receipt or native proof was changed. Game build001 failed
before a complete compile in the sandbox;002 passes outside it, with process-local
MSBuild node reuse disabled. Old failed receipts and accepted proofs are preserved.
Earlier audit snapshots remain in `rea/validation-attempt002.json` and
`validation-attempt001.json`; the current audits reference the final LF config.

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/446-cpu-features/native-config.json --attempt 002
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/447-cpu-features-integration/rea/queries.json --attempt 003
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/447-cpu-features-integration/build-config.json --phase configure --attempt 001
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/447-cpu-features-integration/build-config.json --phase build --attempt 002
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/447-cpu-features-integration/acceptance.json
```

These are accepted receipt identifiers; do not overwrite/re-execute numbered
attempts. Reuse unchanged proof and use a new attempt for changed inputs.
Artifacts: `local/experiments/v2-cpu-features-446/002`,
`local/experiments/v2-cpu-audio-groups-447-rea/003` and
`local/experiments/v2-cpu-features-game-447`. The source registry now links the
two Run442 parents to the separately accepted CPU provider; this is not a new
parent-plus-real-CPU composition comparison.

Next: group validator00590070 and release chain00565990/00590000/00590170/00590b50
(five indexed bodies /519B). The same REA session supplies navigation. Trace
00599100/005996d0 and callback consumers before selecting the next recovery packet.
Reuse canonical device state, preserve alternating initialized/opaque stack cells,
signed bounds, relative offsets and captured-versus-reloaded pointers. Details
are in `local/reports/audio-group-next-20261029.json`; no group code is accepted here.
Live Windows APIs, other physical CPUs, parent/probe composition, invalid memory,
concurrency and full startup/display/gameplay remain open;403/411 stay PARTIAL.
