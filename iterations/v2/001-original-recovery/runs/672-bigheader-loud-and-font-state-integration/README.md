# Run672 loud bigheader, startup diag format, font state, and vec3 dist integration

Shared acceptance `attempt 001` passes for frozen `670/001` and `671/002` (`671/001`
preserved) on `Run669`. Seven PARTIAL originals (`005620c0` 63B, `0059dea0` 206B,
`0059fd90` 46B in `670`; `0053eea0` 19B, `0053e890` 225B, `00532b20` 37B,
`005323a0` 53B in `671`; 649 code bytes total), `35B` `.rdata`
(`005bbb44..005bbb66`), and zero new `.data`/`.bss` integrate. Build `001` compiles
384 TUs across 8 projects with unchanged inputs, zero compiler or other linker
errors, zero new unresolved names, and 72 unresolved names / 77 references (unlocker
providers for upcoming callers such as `004affd0`, `0053c6c0`, `00536870`,
`00471b70`). There is no recovered game EXE. Registry 1063 preserves partial parent
domains.

Native comparisons pass 186 measured cases (`54` in `670/001` + `132` in `671/002`)
and 32 material controls (`12 + 20`) at `/Od`/`/O2`. Canonical owners (`00562100`,
`005df770`, `00568d50`, `00568e90`, `006af168..006af370`, `00561b80`, `006afbe4`,
`005a0fbf`, `005a299e`, `0059fc20`, `005deb74`, `005deb78`, `005debf0`, and shared
read-only strings `005cc588` / `005bbb08`) are reused without duplication. Shared
audit verifies 952 source pins.

Next launch `673` (`render_loader_directx_00574eb0` + `00414bd0` + `00414c30`) and
`674` (audio probe / render startup leaves).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/670-bigheader-loud-and-startup-diag/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/671-font-state-and-vec3-dist/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/672-bigheader-loud-and-font-state-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/672-bigheader-loud-and-font-state-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/672-bigheader-loud-and-font-state-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
