# Run707: unowned typed children exposed by Run704

Bounded native x86-vs-C++ recovery proof for three previously-unowned typed
children newly exposed by the integrated Run704 callers (`Porsche.exe` SHA-256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`, 20 code
bytes total):

- `porsche::buffer_cell_release_00539eb0` (`00539eb0..00539ebd`, 14B, `__fastcall(this, unused_edx)`, sha256 `0cac20a41b626fdad61736c75f8c473d21d0f25e99fd96d130e8eeb45cf3e161`): reads `[ECX]`, and on non-null releases that cell through the canonical `0059f050`.
- `porsche::registry_item_noop_00514990` (`00514990`, 1B, `__cdecl(void*)`, sha256 `ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e`): single `RET`; no side effects.
- `porsche::teardown_secondary_destroy_0059f1c0` (`0059f1c0..0059f1c4`, 5B, `__fastcall(this, unused_edx)`, sha256 `c001fa5623328321ab94cacd5f145bc27eab23ff4e07f47991edcb160e9c5ea9`): tail `JMP` to the unowned `0053f120`, preserving ECX.

Excluded with evidence: `00465790` (592B, `entry_fe_service`) is a large
heterogeneous entry/initializer service with eight loader-zero globals, three
unproved tables, ~20 float constants and three distinct callees. No provider is
defined for it; it remains an explicit unresolved boundary (see
`scope-evidence.json` / `evidence.json`).

Ownership: the three VAs are unowned in `source/recovered/functions.json` and
the catalog; no `body_ranges` overlap (owned neighbour `00539e50` ends at
`00539ea8`). No owned cells are redefined; the exported names/signatures match
the accepted Run701/702/692 callers exactly. `application_release_0059f050` is
reused as the canonical provider; `0053f120` is a newly declared unowned typed
child. Zero new `.data`/`.rdata`/`.bss`.

## Verification

- Attempt `001` (`local/experiments/v2-view-teardown-child-leaves-707/001/receipt.json`, status PASS): 17 cases per variant at `/Od` and `/O2` (34 measured comparisons), 5/5 material `wrong-*` mutations detected, ABI event/argument/nonvolatile-register checks. Original bytes are injected into RWX slots with the `0059f050` CALL and `0053f120` JMP relocated to controlled mocks; both sides are invoked through the same ABI-checking helpers.
  - Command: `py -3 scripts/research/verify-v2-native-batch.py --config iterations/v2/001-original-recovery/runs/707-view-teardown-child-leaves/native-config.json --attempt 001`

## Boundaries

PARTIAL: bounded domain covers null/non-null/interior cell pointers, two receiver objects, no-op call absence, thunk self transport, ESP/EBP/EBX/ESI/EDI preservation and material mutations. The full `0053f120` virtual-delete/vtable algorithm, the `00465790` service, real allocator/vtable state, null-receiver fault behavior, fault/lifetime/concurrency and production CMake/registry integration remain open. No live game/startup/display/gameplay acceptance is claimed.
