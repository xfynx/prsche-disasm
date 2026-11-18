# Run687 render palette pixel-expand and conversion leaves integration

Shared acceptance `attempt 001` passes for frozen `685/001` and `686/002` (`686/001`
preserved) on `Run684`. Eleven PARTIAL originals (`00570260` 63B, `00570330` 56B,
`00570370` 46B, `005704c0` 68B, `00570510` 46B, `00570540` 91B in `685`;
`005702a0` 68B, `00570920` 102B, `00570990` 101B, `00570ff0` 184B, `00571160` 78B
in `686`; 903 code bytes total) and zero new `.data`/`.rdata`/`.bss` integrate.
Build `001` compiles 394 TUs across 8 projects with unchanged inputs, zero compiler
or other linker errors, zero new unresolved names, and 69 unresolved names / 73
references (unlocking upcoming callers `005346d0`, `00534830`, `00534b90`,
`00562810`, `00563440`, and `00534d40`). Inherited MSVC `/O2` XMM constant
`__xmm@000f000f000f000f000f000f000f000f` is excluded from `canonical_providers`
(compiler COMDAT shared across `texture_children_577.obj` and
`render_palette_expand_685.obj`). There is no recovered game EXE. Registry 1114
preserves partial parent domains.

Native comparisons pass 1060 measured cases (`648` in `685/001` + `412` in
`686/002`) and 47 material controls (`24 + 23`) at `/Od`/`/O2`. Canonical owners
(`00572f30`, `00572f5b` from `683`) are reused without duplication. Shared audit
verifies 977 source pins.

Next launch `688` (`005333a0` + `005334e0`, unlocking `00411d20` ->
`startup_sequence_call_004121b0`) and `689` (`00570780` + `00570820` +
`00534830`, unlocking `005346d0` -> `00562810`/`00563440`).

```powershell
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/685-render-palette-pixel-expand-leaves/native-config.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/686-render-palette-convert-leaf-table/native-config.json --attempt 002
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/687-render-palette-leaves-integration/build-config.json --phase configure --attempt 001
$env:MSBUILDDISABLENODEREUSE='1'
py -3 scripts/research/build-v2-game-batch.py --config iterations/v2/001-original-recovery/runs/687-render-palette-leaves-integration/build-config.json --phase build --attempt 001
py -3 scripts/research/audit-v2-native-game-batch.py --config iterations/v2/001-original-recovery/runs/687-render-palette-leaves-integration/acceptance.json
```

Commands identify preserved attempts; passed source/config/fixture inputs are frozen.
