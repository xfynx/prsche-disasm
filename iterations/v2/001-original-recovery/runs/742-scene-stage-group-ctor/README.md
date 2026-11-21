# Run742 scene stage group constructor (`0059f070` + 4 leaves)

Native `001` PASS: recovers `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) `scene_stage_group_ctor_0059f070` (`0059f070..0059f1b8`, 329B) and its four leaf callees (`0053f320` 33B, `0053f600` 29B, `00537a20` 10B, `00537a60` 10B; 411 code bytes total) in `scene_stage_group_742.cpp`. Closes `?scene_stage_group_ctor_0059f070@porsche@@YIPAXPAX0@Z` (`Run721` caller `004552b0`) with zero new unresolved frontier symbols, zero new `.data`/`.rdata`/`.bss`, and pure additive linking once `Run737` (`0053f160`, `0053f2a0`) is integrated.

## Behavior & ownership

- `scene_stage_group_ctor_0059f070`: zeros `[self+4]` and `[self+8]`, stores raw group vtable `0x005b3c94` at `[self]`, constructs embedded mode at `self+0x0c` via `scene_mode_ctor_005379f0` (`Run726`), allocates and appends six `0x30`-byte pass objects via `render_allocate_0059ef90(0x30)` and `scene_pass_append_0053f160` (`Run737`) — five initialized with `scene_pass_init_0053f320` and overwritten with vtables `0x005b6a34` `(1,7)`, `0x005b3bf0` `(5,0)`, `0x005b69e4` `(2,0)`, `0x005b6a0c` `(3,0)`, `0x005b69bc` `(7,0)`, plus the sixth initialized with `scene_pass_init_alt_0053f600(0)` (preserving null on allocation failure) — then calls `scene_pass_finalize_0053f2a0` (`Run737`), `scene_mode_set_c_00537a20(self+0x0c, 0)`, `scene_mode_set_10_00537a60(self+0x0c, 0)`, stores `self+0x0c` at `[self+0x48]`, and returns `self`.
- `scene_pass_init_0053f320` (`0053f320..0053f340`, 33B, `__thiscall` RET `8`): sets `[self+0x0c] = kind`, `[self] = 0x005bbc3c`, `[self+0x10] = subkind`, `[self+0x24] = 0`, `[self+0x28] = 0`, returns `self`.
- `scene_pass_init_alt_0053f600` (`0053f600..0053f61c`, 29B, `__thiscall` RET `4`): sets `[self+0x0c] = 0`, `[self+0x10] = subkind`, `[self+0x24] = 0`, `[self+0x28] = 0`, `[self] = 0x005bbc60`, returns `self`.
- `scene_mode_set_c_00537a20` (`00537a20..00537a29`, 10B, `__thiscall` RET `4`): sets `[self+0x0c] = value`.
- `scene_mode_set_10_00537a60` (`00537a60..00537a69`, 10B, `__thiscall` RET `4`): sets `[self+0x10] = value`.
- Zero `functions.json` / `body_ranges` overlaps; zero new owned `.data`/`.rdata`/`.bss`; zero new unresolved children.

## Verification

```powershell
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/742-scene-stage-group-ctor/rea/queries.json --attempt 001
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/742-scene-stage-group-ctor/native-config.json --attempt 001
```

- REA dossiers: `local/experiments/v2-audio-scene-730-rea/001/function-0059f070.json` and `local/experiments/v2-scene-stage-group-742-rea/001/receipt.json` (`rea/validation.json`: `passed: true`, `function-0053f320.json`, `function-0053f600.json`, `function-00537a20.json`, `function-00537a60.json`).
- Native receipt: `local/experiments/v2-scene-stage-group-ctor-742/001/receipt.json` (`status: PASS`).
- 148 cases per `/Od` and `/O2` (296 measured comparisons): 8 isolated setter leaf cases (`00537a20`/`00537a60`), 12 isolated pass-init cases (`0053f320`/`0053f600`), and 128 composed `0059f070` cases covering all 64 allocation-failure bitmasks (`0..63`) x 2 poison patterns. Checks return `EAX`, ESP/EBP/EBX/ESI/EDI, ordered child call events, full `0x4c`-byte group buffer, and all six `0x30`-byte pass buffers (including untouched bytes).
- 10/10 material mutations killed (`wrong-pass-init-vtable`, `wrong-pass-alt-vtable`, `wrong-mode-set-c-off`, `wrong-mode-set-10-off`, `wrong-group-vtable`, `wrong-pass1-subkind`, `wrong-pass2-vtable`, `wrong-pass4-kind`, `wrong-group-mode-backptr`, `wrong-skip-finalize`), all exiting with code `7` on `"divergence "`.

## Boundaries

Controlled endpoints prove transport and order for `005379f0`, `0059ef90`, `0053f160`, and `0053f2a0`. Null-receiver faults, live virtual pass methods/vtables, and shared CMake/registry integration (requires `Run737` for `0053f160`/`0053f2a0`) remain open.
