# Run702 FE-entry / scene-route / scene-transfer typed leaves

Bounded original-x86 vs C++ recovery proof for seven typed children of the accepted
Run692 (`00413ea0`) and Run693 (`00468fb0`) callers. Original module `Porsche.exe`
SHA-256 `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`
(re-verified by the runner). All seven VAs are free in
`source/recovered/functions.json` (1133 entries: no entry_va and no `body_ranges`
overlap); raw .text body bytes and SHA-256 are pinned in `native-config.json`.

## Bodies (625B total, all full)

- `porsche::entry_fe_call_0046d960` (`0046d960..0046d970`, 17B, `__cdecl int`):
  element count `(end-begin)>>2` of vector header `0x00628178`.
- `porsche::entry_fe_call_0046d890` (`0046d890..0046d952`, 195B, `__cdecl uint`):
  two-pass RTTI/kind search over `0x00628168`; first pass returns index for kind 1
  with arena flag 0 or kind 2 with arena flag nonzero; second pass returns the
  first nonzero probe index.
- `porsche::entry_fe_call_004659e0` (`004659e0..00465a53`, 116B, `__cdecl void`):
  clears nine frame/entry words, tests slot byte `0x627f40 + 0x10c*arg0`, then
  conditionally calls `00465790(arg0,arg1)`.
- `porsche::scene_route_select_00475d70` (`00475d70..00475dab`, 60B, `__cdecl void`):
  local `{0,1,2,3}` selector, dispatch index `to + 2*from`.
- `porsche::scene_route_root_0044fae0` (`0044fae0..0044fb0d`, 46B, `__cdecl void`):
  allocate 0x13c, publish constructor return at `0x0061bc38`.
- `porsche::scene_transfer_enter_004521c0` (`004521c0..004521e8`, 41B, `__cdecl void`):
  allocate 0x328, publish constructor return at `0x0061bcc0`.
- `porsche::scene_transfer_slot_0044b960` (`0044b960..0044b9f5`, 150B, `__fastcall void*`):
  two 0xc slot headers, two sub-objects (0x58/0x1c), returns self. The original
  reads byte 3 of the saved ECX for header byte +8; the C++ form computes that
  byte from the argument.

Extern signatures in `entry_fe_scene_leaves_702.hpp` exactly match the accepted
caller declarations in runs 692/693. Excluded targets remain declared but undefined.

## Verification

```
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/702-entry-fe-scene-route-transfer-leaves/native-config.json --attempt 011
```

Receipt: `local/experiments/v2-entry-fe-scene-route-transfer-leaves-702/011/receipt.json`
— **PASS** at `/Od` and `/O2`; 58 measured cases per variant (inputs, call order,
used returns where defined, all owned cells, control-pool bytes and ABI canaries),
17/17 material `wrong-*` mutations detected. Marker:
`entry_fe_scene_leaves_original_x86_vs_cpp=PASS cases=58`. Attempts 001-010 are
preserved failed attempts (namespace/definition/link fixes, two reversed branch
polarities in `0046d890`, a byte-load precedence defect, an unobservable mutation
and an undefined-void-EAX comparison); none were renamed or reused.

## Ownership

Newly owned (unowned in registry and full run-source closure; loader-zero .data
virtual tail): `0x0061bc38`, `0x0061bcc0`, `0x006280e0`, `0x006280e4`,
`0x00606ad4`, `0x00628168`, `0x00628178` — 28B total.
Reused without redefinition: `view_slot_table_00627e80` (Run693),
`frame_reset_word_006280f0/ec/e8/100/fc/f8` (Run400/692), arena word
`0x00657430`, allocator `render_allocate_0059ef90`. `fe_loop_word_*`,
`fe_replay_scratch_005ed848`, `frame_reset_*` and
`route_object_registry_table_005e8c00` were not redefined.

## Exclusions (evidence only)

- `00413960` (536B): ~40 vtable method calls (`00469a80`..`00469b20`), six x87
  stores into `0x00627ea4`..`0x00627f4c`, nine-dword `MOVSD.REP` and two stack
  objects; destination-cell ownership and method contracts are unproven.
- `0045dbd0` (298B): ten heterogeneous callees (formatter, four constructors,
  two releases, two fastcall methods) plus three new `.bss` globals
  `0x00627e48/4c/50` with unproven lifetimes. Deferred to a dedicated packet.

## Boundaries

Bounded native domain: vector count <=6, slot indices 0/1, selector index 0..3,
allocation-failure position 0/1/2, constructor return modes self/pool/null,
arena flag 0/1. Null display, arbitrary pointers, real RTTI/vtable behavior,
multi-thread lifetime, faults, production CMake/registry/COFF integration and
full game startup remain open. Native stubs, body relocation and synthetic
callsites are harness code only.
