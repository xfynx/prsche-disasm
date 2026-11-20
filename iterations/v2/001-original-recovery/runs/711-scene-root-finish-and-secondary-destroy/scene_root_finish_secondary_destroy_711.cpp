// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run711: two full original bodies newly exposed by the integrated Run706/Run707
// callers:
//   0044fc30..0044fca8 (121B) scene_root_finish (fastcall self + uint, RET 4)
//   0053f120..0053f15a (59B)  secondary_destroy_body (fastcall self, RET 0)
// Original body SHA-256 (raw PE bytes, pinned by verify-v2-native-batch.py):
//   0044fc30 5d77e2467a81dfd019efee8cfec6c6ef63294f4cc86d8313e37ac379148610e4
//   0053f120 66c16bbac4b3d4d376abf72dc1570aa8326b2cb9641c934a0906f8db0baac1ef
#include "scene_root_finish_secondary_destroy_711.hpp"

#include "porsche/application_state.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

U load32(const void* base, U offset) noexcept {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, 4u);
    return value;
}

void store32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, 4u);
}

void* ptr32(U value) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value));
}

// The original writes the raw vtable address 0x005b3c94 into [self]. It then
// dispatches through each *node's* [+0] vtable slot +4, with ECX=node and one
// stack dword 1; the callee pops that dword (__thiscall-like). No table is
// invented here: this is exactly the pointer the original stores.
constexpr U kSecondaryDestroyVtable_005b3c94 = 0x005b3c94u;
using DestroySlot = void (__thiscall *)(void* node, U one);

void invoke_destroy(void* node) noexcept {
    void* const vtable = ptr32(load32(node, 0u));
    const DestroySlot slot = reinterpret_cast<DestroySlot>(load32(vtable, 4u));
    slot(node, 1u);
}

} // namespace

// 0044fc30..0044fca8. The arena REVERSE word selects a forward (index from
// count-1 downward) or reverse (index from 0 upward) keyframe bound search.
// Every comparison in the original is a signed JGE/JLE/JG/JL on 32-bit bounds;
// [self+4] receives each probed index and the caller's stack dword is the value.
void __fastcall scene_root_finish_0044fc30(void* self, void*, U zero) {
    B* const table = static_cast<B*>(ptr32(load32(self, 0u)));

    if (application_state_006573e8.word(0x00657430u) != 0u) {
        I idx = static_cast<I>(load32(table, 4u)) - 1;
        store32(self, 4u, static_cast<U>(idx));
        if (idx > 1) {
            const I value = static_cast<I>(zero);
            for (;;) {
                idx = static_cast<I>(load32(self, 4u));
                const I lower = static_cast<I>(load32(table, static_cast<U>(idx) * 8u));
                bool step_down = (lower >= value);
                if (!step_down) {
                    const I upper = static_cast<I>(load32(table, static_cast<U>(idx) * 8u + 8u));
                    if (value <= upper) return;
                }
                --idx;
                store32(self, 4u, static_cast<U>(idx));
                if (idx <= 1) return;
            }
        }
        return;
    }

    store32(self, 4u, 0u);
    const I value = static_cast<I>(zero);
    const I limit = static_cast<I>(load32(table, 4u)) - 2;
    if (limit <= 0) return;
    I idx = 0;
    for (;;) {
        const I bound = static_cast<I>(load32(table, static_cast<U>(idx) * 8u + 8u));
        bool found = (bound > value);
        if (!found) {
            const I following = static_cast<I>(load32(table, static_cast<U>(idx) * 8u + 0x10u));
            if (value < following) return;
        }
        const I next = idx + 1;
        store32(self, 4u, static_cast<U>(next));
        idx = next;
        if (idx >= limit) return;
    }
}

// 0053f120..0053f15a. Preserves ESI, stores the raw vtable into [self], then
// walks [self+4] -> [node+8] siblings. For each reached sibling it calls the
// vtable+4 slot of a non-null [sibling+4] child, reloading [sibling+8] after
// that call, and finally calls the vtable+4 slot of the last sibling itself.
void __fastcall secondary_destroy_body_0053f120(void* self) {
    void* child = ptr32(load32(self, 4u));
    store32(self, 0u, kSecondaryDestroyVtable_005b3c94);
    if (child == nullptr) return;

    void* next = ptr32(load32(child, 8u));
    if (next == nullptr) {
        invoke_destroy(child);
        return;
    }

    for (;;) {
        child = next;
        void* grandchild = ptr32(load32(child, 4u));
        if (grandchild != nullptr) {
            invoke_destroy(grandchild);
        }
        next = ptr32(load32(child, 8u));
        if (next == nullptr) {
            invoke_destroy(child);
            return;
        }
    }
}

} // namespace porsche
