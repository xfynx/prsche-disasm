# Run737 scene pass children (`0053f160`, `0053f230`, `0053f2a0`)

Native `005` PASS: recovers `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`) `scene_pass_append_0053f160` (`0053f160..0053f1ab`, 76B, raw SHA-256 `2ea3c7e041d8794cc2017b15b2074d33abb78d762d15bf88856000ccf4521f77`, `__thiscall` RET `4`), `scene_pass_create_0053f230` (`0053f230..0053f29c`, 109B, raw SHA-256 `060443d42213095b9afdd7b97296eafc229b38775fd0185ca5d0fc2710f2f089`, `__cdecl` RET `0`), and `scene_pass_finalize_0053f2a0` (`0053f2a0..0053f318`, 121B, raw SHA-256 `255ec16ad5d4e59451bf33b30a12c5316f409c64cd89e7f4a8d47c927370e0fd`, `__thiscall` RET `0`) in `scene_pass_children_737.cpp` (306 code bytes total). Matches the caller declarations in `Run736` (`scene_blur_program_736.hpp`) and `Run738` (`scene_blur_stage_child_738.hpp`).

## Behavior & ownership

- `scene_pass_append_0053f160`: appends `pass` to the `[self+4]` doubly-linked list via `[node+8]` (`next`) / `[node+4]` (`prev`), clears `[pass+8]`, and records `[pass+0x20] = self`.
- `scene_pass_create_0053f230`: lazily initializes canonical `render_cleanup_head_0069ebb0` (`Run599`) with an 8-byte sentinel (`next = nullptr`, `callback_va = 0x0053f980`) via `render_allocate_0059ef90(8)`, walks the factory list invoking `scene_pass_factory_default_0053f980` when `callback_va == 0x0053f980` (or the stored 32-bit callback pointer otherwise), and calls vtable slot `+0x08(pass, flags)` on the first non-null pass before returning it.
- `scene_pass_finalize_0053f2a0`: walks `[self+4]` -> `[pass+8]`, invokes vtable `+0x10`, clears `[pass+0x18]`/`[pass+0x1c]`, assigns sequential indices via vtable `+0x14` and `+0x18` predicates (copying `+0x18` to `+0x1c` when `+0x14` is true and `+0x18` is false), then walks `[self+4]` calling `scene_pass_compile_0053f380(pass)`.
- Zero new owned `.data`/`.rdata`/`.bss`. Reuses canonical `render_cleanup_head_0069ebb0` (`Run599`) and `render_allocate_0059ef90`. Downstream unrecovered typed children: `scene_pass_factory_default_0053f980` and `scene_pass_compile_0053f380`.

## Verification

```powershell
py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/737-scene-pass-children/rea/queries.json --attempt 002
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/737-scene-pass-children/native-config.json --attempt 005
```

- REA receipt: `local/experiments/v2-scene-pass-children-737-rea/002/receipt.json` (`rea/validation.json`: `passed: true`, `function-0053f160.json`, `function-0053f230.json`, `function-0053f2a0.json`).
- Native receipt: `local/experiments/v2-scene-pass-children-737/005/receipt.json` (`status: PASS`).
- 43 cases / 275 events per `/Od` and `/O2` (86 measured comparisons): 4 append list lengths (`0..3`), 7 factory-create modes (allocator failure, null factory result, single/multi-node chains, sentinel `0x0053f980` dispatch), and 32 finalize cases (`length 0..3` x `8` predicate patterns including `compile` next-pointer mutation). Checks ESP/EBP/EBX/ESI/EDI, return EAX, `0069ebb0`, ordered events, and full owner/node/pass/allocated-node buffers.
- 11/11 material mutations detected (`wrong-append-next-offset`, `wrong-append-prev`, `wrong-append-owner-offset`, `wrong-create-alloc-size`, `wrong-create-callback-args`, `wrong-create-skip-next`, `wrong-create-flags`, `wrong-finalize-reset-offset`, `wrong-finalize-index-step`, `wrong-finalize-copy-condition`, `wrong-finalize-skip-compile`), all exiting with code `1` on `"divergence"`.
- Preserved failed attempts: `001` (single-line MSVC `__asm` comment `;`), `002` (raw default-factory offset check `0x1f` vs `0x20`), `003` (host-relocated `0x0053f980` in `allocated_node` vs `Run599` sentinel `0x0053f980u`), `004` (non-unique mutation anchor for `wrong-append-owner-offset`).

## Boundaries

Controlled endpoints prove transport and call order for `render_allocate_0059ef90`, `scene_pass_factory_default_0053f980`, `scene_pass_compile_0053f380`, and pass vtable slots `+0x08/+0x10/+0x14/+0x18`. Downstream pass factory, compile, virtual implementations, invalid-pointer faults, and shared CMake/registry integration remain open.
