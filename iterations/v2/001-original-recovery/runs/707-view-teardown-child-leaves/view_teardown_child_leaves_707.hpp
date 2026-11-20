// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run707 packet: unowned typed children newly exposed by the integrated Run704.
// Recovered bodies:
//   00539eb0 (14B, buffer_cell_release)
//   00514990 (1B,  registry_item_noop)
//   0059f1c0 (5B,  teardown_secondary_destroy tail thunk)
// Excluded with evidence: 00465790 (592B, large/heterogeneous entry service).
//
// The exported function symbols are the exact names/signatures the accepted
// Run701 / Run702 / Run692 callers resolve. Those callers are NOT redefined
// here; only the three previously-unowned definitions live in this TU.
#pragma once

#include <cstdint>

namespace porsche {

// ---------------------------------------------------------------------------
// Canonical / unowned callees (extern references, never defined here).
// ---------------------------------------------------------------------------
std::uint32_t __cdecl application_release_0059f050(void* object); // canonical, Run078
// New typed child: 59B tail-jump target of the 0059f1c0 thunk. Its virtual
// delete / vtable semantics remain unrecovered (declared here only).
void __fastcall secondary_destroy_body_0053f120(void* self);

// ---------------------------------------------------------------------------
// Recovered original bodies (exact accepted extern names/signatures).
// ---------------------------------------------------------------------------
void __fastcall buffer_cell_release_00539eb0(void* self, void* unused_edx);
void __cdecl registry_item_noop_00514990(void* item);
void __fastcall teardown_secondary_destroy_0059f1c0(void* self, void* unused_edx);

} // namespace porsche
