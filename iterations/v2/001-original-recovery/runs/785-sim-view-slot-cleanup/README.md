# Run 785: Sim View Slot Cleanup (`application_sim_boundary_004642f0`)

## Scope

Pure additive recovery of one frontier symbol referenced by [application_sim_teardown_691.hpp](../691-app-sim-teardown-audio-unload/application_sim_teardown_691.hpp#L87) (`FUN_004b68f0` call site `004b6a1e`, `UNCONDITIONAL_CALL`):

- `?application_sim_boundary_004642f0@porsche@@YAXXZ` (`004642f0..00464329`, 58 bytes, `sha256: c78a0d86e00b9e37b27f7c0184b661753b8dcd24398ae86b0cfdb3203efc4165`)

## Recovered Implementation

- [sim_view_slot_cleanup_785.hpp](sim_view_slot_cleanup_785.hpp)
- [sim_view_slot_cleanup_785.cpp](sim_view_slot_cleanup_785.cpp)

Behavior verified against `local/game/Porsche.exe` (`sha256: ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`):

1. Reads `application_state_006573e8.word(0x00657404u)` (`DAT_00657404`).
2. Computes view slot count `count = (mode == 1u) ? 2u : 1u`.
3. Walks `count` consecutive `0x10cu`-byte entries starting at `view_slot_table_00627e80 + 0x20u` (`00627ea0`, second slot at `00627fac`).
4. For each non-null slot pointer, calls deleting destructor `vtable[0](this, 1)` (`__thiscall`) and stores `nullptr` into the slot.
5. Allocates zero new `.bss`/`.data`/`.rdata` storage and opens zero new unresolved game symbols.

## Evidence and Verification

- Scope evidence: [scope-evidence.json](scope-evidence.json)
- REA config: [rea-queries.json](rea-queries.json)
- REA session receipt: `local/experiments/v2-sim-view-slot-cleanup-785-rea/001/receipt.json` (`exit_code: 0`)
- REA function dossier: `local/experiments/v2-sim-view-slot-cleanup-785-rea/001/function-004642f0.json`
- REA audit: [validation.json](validation.json) (`{"passed": true, "dossiers": 1, "repeated_equal": 0}`)
- Native harness config & template: [native-config.json](native-config.json), [native-fixture.cpp.in](native-fixture.cpp.in)
- Native receipt: `local/experiments/v2-sim-view-slot-cleanup-785/001/receipt.json`
  - Status: `PASS`
  - `/Od` & `/O2`: `sim_view_slot_cleanup_original_x86_vs_cpp=PASS cases=5 events=5` (`0` failed cases, matching `output_sha256: e6408a0d32b434f00786e3044823f92e700c860901e2a9c00c25c5349869726d`)
  - Material mutation controls: `6/6` detected (`wrong-mode-cmp`, `wrong-slot-count-alt`, `wrong-slot-base-offset`, `wrong-slot-stride`, `wrong-dtor-flag`, `wrong-slot-zero-skip`, all `exit_code: 1`)
