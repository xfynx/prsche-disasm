# Run 778: Scene Pass Compile & Default Factory (`0053f380`, `0053f980`, `0053fd60`, `00574ab0`)

## Scope

Additive recovery of the two `Run737` scene pass children (`scene_pass_children_737.hpp`) and their two leaf pass constructors in `Porsche.exe` (`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

- `0053f380..0053f425` (`166B`): `porsche::scene_pass_compile_0053f380` (`__fastcall`, `RET 0`) — queries slot pairs via `[vtable + 0x0c](&count)`, allocates `uint16_t` parent-index (`+0x24`) and `void*` pass-pointer (`+0x28`) arrays via `render_allocate_0059ef90`, matches passes on `self+0x04` (`+0x04` chain), and records parent pass indices from `[self+0x20]+0x04` (`+0x08` chain, `0xffff` when absent).
- `0053f980..0053fce1` (`866B`): `porsche::scene_pass_factory_default_0053f980` (`__cdecl`, `RET 0`) — 20-arm pass factory (`0x00..0x13`, `0x810B` for kind `0x09`, `nullptr` for `0x11` and `> 0x13`) using `0059ef90`, `0053f320`, `0053f600`, `0053fd60`, `00574ab0`, and exact `.rdata` vtable pointers.
- `0053fd60..0053fd80` (`33B`): `porsche::scene_pass_init_kind1_0053fd60` (`__thiscall`, `RET 4`) — kind-1 pass initializer (`vtable = 0x005b6a34`).
- `00574ab0..00574aca` (`27B`): `porsche::scene_pass_init_kind2_00574ab0` (`__thiscall`, `RET 4`) — kind-2 pass initializer delegating to `0053f320` (`vtable = 0x005c0898`).

Zero new data/bss or unresolved game symbols.

## Evidence & Commands

- REA session:
  `py -3 scripts/research/run-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/778-scene-pass-compile-factory/rea/queries.json --attempt 001`
  `py -3 scripts/research/audit-v2-rea-session.py --config iterations/v2/001-original-recovery/runs/778-scene-pass-compile-factory/rea/queries.json --attempt 001`
  Validation: `iterations/v2/001-original-recovery/runs/778-scene-pass-compile-factory/rea/validation.json` (`passed: true`, 4 dossiers).
- Native differential verification (`/Od` + `/O2`, `56` cases/variant, `12/12` mutations killed):
  `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/778-scene-pass-compile-factory/native-config.json --attempt 001`
  Receipt: `local/experiments/v2-scene-pass-compile-factory-778/001/receipt.json` (`status: PASS`).
