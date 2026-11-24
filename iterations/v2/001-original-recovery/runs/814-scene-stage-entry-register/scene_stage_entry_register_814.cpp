// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run814: 005af040 (65B), 0044d380 (406B), 0044d520 (36B), 0044d550 (82B),
//         00536120 (84B), 005365a0 (53B), 00423840 (67B).
#include "scene_stage_entry_register_814.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "porsche/application_alloc.hpp"
#include "render_resource_node_536.hpp"
#include "scene_blur_state_774.hpp"
#include "scene_sky_texture_791.hpp"
#include "scene_stage_group_742.hpp"
#include "startup_context_table_helpers_646.hpp"
#include "startup_text_fallbacks_650.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_ptr(void* base, U offset, const void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

} // namespace

void __cdecl application_page_protect_005af040(
    void* address, std::uint32_t bytes, std::uint32_t read_only) {
    SYSTEM_INFO sys_info{};
    GetSystemInfo(&sys_info);
    DWORD old_protect = 0u;
    const DWORD size = (bytes / sys_info.dwPageSize) * sys_info.dwPageSize;
    const DWORD protect = (read_only != 0u) ? PAGE_READONLY : PAGE_READWRITE;
    (void)VirtualProtect(address, size, protect, &old_protect);
}

void* __fastcall scene_stage_entry_record_init_0044d520(
    void* self, void* /*unused_edx*/,
    std::uint32_t key0, std::uint32_t key1, void* obj, std::uint8_t owned) {
    B* const out = static_cast<B*>(self);
    store32(out, 0x00u, key0);
    store32(out, 0x04u, key1);
    store_ptr(out, 0x08u, obj);
    out[0x0cu] = 0u;
    out[0x0du] = owned;
    return self;
}

void __fastcall scene_stage_entry_apply_state_0044d550(
    void* self, void* /*unused_edx*/, void* node, const void* state_28_bytes) {
    if (state_28_bytes == nullptr) {
        return;
    }
    const B* const mask =
        reinterpret_cast<const B*>(startup_text_quality_mask_ptr_0044dfe0(load32(self, 0x04u)));
    B state_copy[28];
    std::memcpy(state_copy, state_28_bytes, sizeof(state_copy));
    scene_mode_set_c_00537a20(
        state_copy, nullptr, ((mask[2] & 0x04u) != 0u) ? 1u : 0u);
    scene_blur_state_commit_00536470(node, nullptr, state_copy);
}

void* __fastcall scene_resource_node_clone_00536120(
    void* self, void* /*unused_edx*/, const void* src) {
    B* const dst = static_cast<B*>(self);
    const B* const src_b = static_cast<const B*>(src);
    std::memcpy(dst + 0x04u, src_b + 0x04u, 0x20u);
    void* const shared_ref = load_ptr(src_b, 0x20u);
    std::memcpy(dst + 0x38u, src_b + 0x38u, 0x1cu);
    store32(dst, 0x00u, static_cast<U>(reinterpret_cast<std::uintptr_t>(
        render_resource_node_table_005bb6d4)));
    store32(shared_ref, 0x00u, load32(shared_ref, 0x00u) + 1u);
    return self;
}

void __fastcall scene_resource_node_set_name_005365a0(
    void* self, void* /*unused_edx*/, const char* name) {
    B* const dst = static_cast<B*>(self) + 0x24u;
    B ch = static_cast<B>(name[0]);
    dst[0] = ch;
    if (ch != 0u) {
        for (U idx = 1u; idx < 0x13u; ++idx) {
            ch = static_cast<B>(name[idx]);
            if (ch == 0u) {
                break;
            }
            dst[idx] = ch;
        }
    }
    static_cast<B*>(self)[0x37u] = 0u;
}

void __fastcall scene_tree_node_advance_00423840(void* node_ptr, void* /*unused_edx*/) {
    void* cur = load_ptr(node_ptr, 0x00u);
    void* next = load_ptr(cur, 0x0cu);
    if (next != nullptr) {
        store_ptr(node_ptr, 0x00u, next);
        while (load_ptr(next, 0x08u) != nullptr) {
            next = load_ptr(next, 0x08u);
            store_ptr(node_ptr, 0x00u, next);
        }
        return;
    }

    next = load_ptr(cur, 0x04u);
    while (cur == load_ptr(next, 0x0cu)) {
        store_ptr(node_ptr, 0x00u, next);
        next = load_ptr(next, 0x04u);
        cur = load_ptr(node_ptr, 0x00u);
    }
    if (load_ptr(cur, 0x0cu) != next) {
        store_ptr(node_ptr, 0x00u, next);
    }
}

void* __fastcall scene_stage_entry_register_0044d380(
    void* self, void* /*unused_edx*/, const void* entry_ptr,
    std::uint32_t zero_a, std::uint32_t entry_tag, std::uint32_t zero_b,
    std::uint32_t /*one_a*/, std::uint32_t one_b, std::uint32_t flags) {
    void* const tree = load_ptr(self, 0x08u);
    const U key_pair[2] = {zero_a, entry_tag};
    void* iter_node = nullptr;
    (void)startup_context_tree_find_0044b830(tree, nullptr, &iter_node, key_pair);

    void* const sentinel = load_ptr(tree, 0x00u);
    const void* const state_28 =
        reinterpret_cast<const void*>(static_cast<std::uintptr_t>(zero_b));

    if (iter_node == sentinel) {
        void* const driver = load_ptr(self, 0x00u);
        const U mode = load32(self, 0x04u);
        void* const created = scene_sky_texture_create_0044da10(
            entry_ptr, entry_tag, mode, driver, flags);
        scene_stage_entry_apply_state_0044d550(self, nullptr, created, state_28);
        if ((static_cast<B>(one_b) & 0xffu) == 0u) {
            render_resource_node_prepare_00536460(created, nullptr);
        }
        B record[16]{};
        void* const rec = scene_stage_entry_record_init_0044d520(
            record, nullptr, zero_a, entry_tag, created, 1u);
        B out_pair[8]{};
        (void)scene_stage_entry_insert_0044db70(tree, nullptr, out_pair, rec);
        return created;
    }

    void* clone_src = reinterpret_cast<void*>(static_cast<std::uintptr_t>(one_b));
    while (iter_node != load_ptr(tree, 0x00u) &&
           load32(iter_node, 0x10u) == zero_a &&
           load32(iter_node, 0x14u) == entry_tag) {
        clone_src = load_ptr(iter_node, 0x18u);
        if (std::memcmp(static_cast<const B*>(clone_src) + 0x38u, state_28, 0x1cu) == 0) {
            return clone_src;
        }
        scene_tree_node_advance_00423840(&iter_node, nullptr);
    }

    void* const mem = startup_network_allocate_0059ef90(0x54u);
    void* const cloned = (mem != nullptr)
        ? scene_resource_node_clone_00536120(mem, nullptr, clone_src)
        : nullptr;

    char clone_name[16]{};
    std::memcpy(clone_name, &entry_tag, sizeof(entry_tag));
    clone_name[4] = '\0';
    std::strcat(clone_name, ":CLONE");
    scene_resource_node_set_name_005365a0(cloned, nullptr, clone_name);
    scene_stage_entry_apply_state_0044d550(self, nullptr, cloned, state_28);

    B record[16]{};
    void* const rec = scene_stage_entry_record_init_0044d520(
        record, nullptr, zero_a, entry_tag, cloned, 0u);
    B out_pair[8]{};
    (void)scene_stage_entry_insert_0044db70(tree, nullptr, out_pair, rec);
    return cloned;
}

} // namespace porsche
