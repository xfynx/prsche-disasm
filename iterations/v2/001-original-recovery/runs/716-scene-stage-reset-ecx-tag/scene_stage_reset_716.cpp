#include "scene_stage_reset_716.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_startup.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

void* scene_stage_root_006115c0 = nullptr;
void* scene_stage_root_00627dfc = nullptr;

namespace {

inline void store_dword(void* base, std::size_t off, void* value) {
    std::memcpy(static_cast<unsigned char*>(base) + off, &value, sizeof value);
}
inline void store_dword(void* base, std::size_t off, std::uint32_t value) {
    std::memcpy(static_cast<unsigned char*>(base) + off, &value, sizeof value);
}
inline void store_byte(void* base, std::size_t off, std::uint8_t value) {
    std::memcpy(static_cast<unsigned char*>(base) + off, &value, sizeof value);
}
inline void* load_dword(const void* base, std::size_t off) {
    void* value = nullptr;
    std::memcpy(&value, static_cast<const unsigned char*>(base) + off, sizeof value);
    return value;
}

} // namespace

void __cdecl scene_stage_reset_0043ed00() {
    std::uint32_t entry_ecx = 0u;
    __asm { mov entry_ecx, ecx }
    const std::uint8_t tag = static_cast<std::uint8_t>(entry_ecx >> 24);

    void* holder = render_allocate_0059ef90(0x0cu);
    if (holder == nullptr) {
        scene_stage_root_006115c0 = nullptr;
        __asm { mov ecx, entry_ecx }
        return;
    }
    store_dword(holder, 0u, static_cast<void*>(nullptr));

    unsigned char* const ctx = static_cast<unsigned char*>(
        application_context_heap_state_005e4fe8());
    unsigned char* const list_slot = ctx + 0x28u;
    unsigned char* const free_slot = ctx + 0x3cu;

    heap_enter_005322b0(load_dword(list_slot, 0u));

    if (load_dword(free_slot, 0u) == nullptr) {
        application_context_new_head_0059eeb0(2u, 0u);
    }

    void* const node = load_dword(free_slot, 0u);
    void* const next = load_dword(node, 4u);
    store_dword(free_slot, 0u, next);
    heap_leave_005322c0(load_dword(list_slot, 0u));

    store_dword(holder, 0u, node);
    store_dword(holder, 4u, std::uint32_t{0u});
    store_byte(holder, 8u, tag);

    store_byte(node, 0u, std::uint8_t{0u});
    store_dword(node, 4u, std::uint32_t{0u});
    store_dword(node, 8u, node);
    store_dword(node, 0x0cu, node);

    scene_stage_root_006115c0 = holder;
    __asm { mov ecx, entry_ecx }
}

void __cdecl scene_stage_reset_00455f60() {
    std::uint32_t entry_ecx = 0u;
    __asm { mov entry_ecx, ecx }
    const std::uint8_t tag = static_cast<std::uint8_t>(entry_ecx >> 24);

    void* root = render_allocate_0059ef90(4u);
    if (root == nullptr) {
        scene_stage_root_00627dfc = nullptr;
        __asm { mov ecx, entry_ecx }
        return;
    }

    void* holder = render_allocate_0059ef90(0x0cu);
    if (holder == nullptr) {
        store_dword(root, 0u, static_cast<void*>(nullptr));
        scene_stage_root_00627dfc = root;
        __asm { mov ecx, entry_ecx }
        return;
    }
    store_dword(holder, 0u, static_cast<void*>(nullptr));

    void* const member = application_context_member_storage_004211d0(0x18u, 0u);

    store_dword(holder, 0u, member);
    store_dword(holder, 4u, std::uint32_t{0u});
    store_byte(holder, 8u, tag);

    store_byte(member, 0u, std::uint8_t{0u});
    store_dword(member, 4u, std::uint32_t{0u});
    store_dword(member, 8u, member);
    store_dword(member, 0x0cu, member);

    store_dword(root, 0u, holder);
    scene_stage_root_00627dfc = root;
    __asm { mov ecx, entry_ecx }
}

} // namespace porsche
