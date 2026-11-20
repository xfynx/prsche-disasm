// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run707: three recovered unowned typed-child bodies.
//
// Original body SHA-256 (raw PE bytes, verified by verify-v2-native-batch.py):
//   00539eb0 0cac20a41b626fdad61736c75f8c473d21d0f25e99fd96d130e8eeb45cf3e161
//   00514990 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e
//   0059f1c0 c001fa5623328321ab94cacd5f145bc27eab23ff4e07f47991edcb160e9c5ea9
#include "view_teardown_child_leaves_707.hpp"

#include <cstring>

namespace porsche {

// 00539eb0..00539ebd (14B). this-in-ECX (unused_edx is the harness fastcall
// placeholder). Reads the receiver's first dword and, when non-null, releases
// that cell through the canonical allocator 0059f050. ECX is restored by the
// original POP ECX; fastcall ECX is volatile so no explicit restore is needed.
void __fastcall buffer_cell_release_00539eb0(void* self, void* unused_edx) {
    (void)unused_edx;
    void* cell = nullptr;
    std::memcpy(&cell, self, sizeof cell);
    if (cell != nullptr) {
        (void)application_release_0059f050(cell);
    }
}

// 00514990 (1B). Single RET: no side effects, no state, no used return.
void __cdecl registry_item_noop_00514990(void* item) {
    (void)item;
}

// 0059f1c0..0059f1c4 (5B). Pure tail JMP to 0053f120 with ECX (this) preserved;
// the thunk itself has no other semantics. The 59-byte target body is a separate
// unowned child whose virtual-delete algorithm is outside this packet.
void __fastcall teardown_secondary_destroy_0059f1c0(void* self, void* unused_edx) {
    (void)unused_edx;
    secondary_destroy_body_0053f120(self);
}

} // namespace porsche
