# Run701 — view teardown / route family leaves

Status: **native proof PASS** (attempt 008). Originals and passed attempt inputs are immutable.

## Scope

Ten typed children of the integrated Run693 view lifecycle were examined. Eight
small leaves were recovered; two were excluded with evidence.

Recovered (raw PE bytes, SHA verified against `ddd748fd…ff39`):

| VA | bytes | body SHA-256 (first 12) | ABI |
|----|------:|-------------------------|-----|
| 00465cf0 | 133 | ffe435dd56f6 | cdecl void(int32) RET0, x87 |
| 00465e20 | 29 | d12fb9910a89 | cdecl void() RET0 |
| 0047f190 | 119 | da05e3ddfe84 | cdecl void() RET0 |
| 004b7140 | 16 | ad66ed1056e8 | cdecl void() RET0 |
| 00473100 | 67 | 9d667ff56107 | fastcall(this,unused,uint32) RET4 |
| 00473190 | 117 | 588cd1c9befe | fastcall(this,unused,const void*) RET4 |
| 00538d80 | 20 | de8e86aee4df | fastcall(this,unused) RET0 |
| 00540420 | 24 | b2c8ce219b82 | fastcall(this,unused) RET0, vtable slot0(arg1) |

Total: **525 code bytes** in `view_teardown_route_family_701.cpp/.hpp`.

Excluded:
- **00463c30** — large heterogeneous route-finish routine: entry branches to
  `0x00464049`, spans hundreds of instructions with many callees (disassembly
  `FUN_00463c30`, lines 121041..121370).
- **00466500** — 340B multi-field destructor, six distinct callees
  (`00466c30/00466ca0/00466d10/00466d60/004237d0/0059f050`) plus internal
  pointer rewiring (disassembly lines 124034..124171).

## Ownership

- All ten VAs unowned in `source/recovered/functions.json` (1133 entries; check
  covered `entry_va` and `body_ranges`, overlap result `[]`).
- Eight extern names/signatures match `application_view_lifecycle_693.hpp`
  exactly; only the previously-unowned definitions are added here. No Run693
  cell is redefined.
- One new loader-zero cell owned: `render_secondary_object_0062810c` (0x0062810c).
- Reused, never redefined: `view_slot_table_00627e80` (Run693),
  `startup_context_table_00628bac` (Run646), `render_teardown_state_0065b398`
  (Run601), `game_setup_movie_service_0069ed0c` (game_setup_globals.cpp),
  `application_release_0059f050`, `startup_service_noop_00516950`,
  `application_context_member_destroy_block_00441200`.
- Raw .rdata dword `0x005b245c` = `0xc0800000` (−4.0f) verified from the pinned
  PE before relocation; no invented constant.
- Opaque controlled endpoints: `0059f1c0`, `00514990`, `00539eb0`, and the
  00540420 vtable slot. Full algorithms remain outside this recovery.

## Proof

Command:

```
py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/701-view-teardown-route-family/native-config.json --attempt 008
```

Receipt: `local/experiments/v2-view-teardown-route-family-701/008/receipt.json` — status PASS.

Result: **36 cases**, both `/Od` and `/O2`, marker
`view_teardown_route_family_701_original_x86_vs_cpp=PASS`. Each case runs the
relocated original bytes and the C++ body through the same ABI-checking invoke
helper, comparing inputs, intermediate state (events, controlled buffers),
outputs, call order, ESP/EBP/EBX/ESI/EDI and full x87 state. **11 material
mutations** were each detected (all mutation natives exited 1). All eight
bodies are void, so post-return EAX (volatile last-endpoint result) is not a
compared output.

Failed/historical attempts 001–007 are preserved: 001 fixture-brace error,
002 declaration-order error, 003 missing global definition, 004 EAX comparison
on a void function, 005 missing vtable pointer in harness setup, 006 non-material
mutation fixture data, 007 stale mutation anchor. These are harness/fixture
repairs, not semantic hypothesis failures.

## Remaining boundaries

Opaque callee algorithms, null/unreachable producer states, fault/lifetime/
concurrency, live component acceptance, CPU-specific undefined flags and x87
precision. Production CMake/registry integration, the shared game build and the
game-link COFF audit are separate follow-up steps (not performed here).

## Files

`view_teardown_route_family_701.hpp/.cpp`, `native-fixture.cpp.in`,
`native-config.json`, `scope-evidence.json`, `evidence.json`, `README.md`.
