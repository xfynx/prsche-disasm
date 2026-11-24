// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run805: 00448b10..00448bb6 (167B), 0044d0b0..0044d153 (164B).
#include "scene_stage_reset_805.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/heap.hpp"
#include "porsche/render_startup.hpp"
#include "startup_sequence_resource_table_649.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

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

const char* scene_stage_reset_fsh_names_005cdeac[2] = {
    "common.fsh",
    "particle.fsh",
};

void* scene_stage_particle_table_owner_00613e08 = nullptr;

void* __fastcall scene_stage_table_ctor_0044d0b0(
    void* self, void* /*unused_edx*/, void* owner, std::uint32_t capacity) {
    store_ptr(self, 0x00u, owner);
    store32(self, 0x04u, capacity);
    store_ptr(self, 0x08u, nullptr);

    void* const holder = startup_network_allocate_0059ef90(0x0cu);
    if (holder == nullptr) {
        store_ptr(self, 0x08u, nullptr);
        return self;
    }

    store_ptr(holder, 0x00u, nullptr);
    B* const ctx = static_cast<B*>(application_context_heap_state_005e4fe8());
    B* const lock_slot = ctx + 0x28u;
    heap_enter_005322b0(load_ptr(lock_slot, 0u));
    if (load_ptr(ctx, 0x40u) == nullptr) {
        application_context_new_head_0059eeb0(3u, 0u);
    }
    B* const sentinel = static_cast<B*>(load_ptr(ctx, 0x40u));
    store_ptr(ctx, 0x40u, load_ptr(sentinel, 0x04u));
    heap_leave_005322c0(load_ptr(lock_slot, 0u));

    store_ptr(holder, 0x00u, sentinel);
    store32(holder, 0x04u, 0u);
    static_cast<B*>(holder)[0x08u] =
        static_cast<B>(reinterpret_cast<std::uintptr_t>(owner));
    sentinel[0x00u] = 0u;
    store_ptr(sentinel, 0x04u, nullptr);
    store_ptr(sentinel, 0x08u, sentinel);
    store_ptr(sentinel, 0x0cu, sentinel);

    store_ptr(self, 0x08u, holder);
    return self;
}

void __cdecl scene_stage_reset_00448b10() {
    for (U idx = 0u; idx < 2u; ++idx) {
        void* const mem = startup_network_allocate_0059ef90(0x0cu);
        void* obj = nullptr;
        if (mem != nullptr) {
            void* const driver = load_ptr(render_display_00628130, 0x74u);
            obj = scene_stage_table_ctor_0044d0b0(mem, nullptr, driver, 4u);
        }
        if (idx == 0u) {
            startup_context_table_owner_00613e04 = obj;
        } else {
            scene_stage_particle_table_owner_00613e08 = obj;
        }

        char path[256];
        (void)formatter_entry_005a0fbf(path, "%s", startup_resource_prefix_0065b30c);
        std::strcat(path, scene_stage_reset_fsh_names_005cdeac[idx]);
        scene_stage_table_load_0044d270(obj, nullptr, path, 0u);
    }
}

} // namespace porsche
