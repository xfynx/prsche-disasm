// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run781: 004522b0..00452496 (487B), 004524a0..00452507 (104B), 0059ece0..0059ecf1 (18B).
#include "scene_stage_constructor_781.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/formatter_entry.hpp"
#include "startup_sequence_resource_table_649.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;
using ContextSizeFn = U(__cdecl*)(const void*);

constexpr U kNullTag = 0x6e756c6cu; // "null"
constexpr U kFlareEntryBytes = 0x8cu;
constexpr U kFlareFloat100 = 0x42c80000u; // 100.0f

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store_ptr(void* base, U offset, void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

void append_holder(void* self, void* holder) {
    const U idx = load32(self, 0x04u);
    store_ptr(self, 0x08u + idx * 4u, holder);
    store32(self, 0x04u, load32(self, 0x04u) + 1u);
}

} // namespace

std::uint32_t __cdecl context_table_size_0059ece0(const void* block) {
    const void* state = application_context_heap_state_005e4fe8();
    const auto query_size = reinterpret_cast<ContextSizeFn>(load_ptr(state, 0x18u));
    return query_size(block);
}

void* __fastcall scene_flare_entry_ctor_004524a0(
    void* self, void* /*unused_edx*/, std::uint32_t tag) {
    store32(self, 0x00u, tag);
    store32(self, 0x4cu, 4u);
    store32(self, 0x50u, 0u);
    store32(self, 0x54u, 0u);
    store32(self, 0x58u, 0u);
    for (U i = 0u; i < 2u; ++i) {
        store32(self, 0x04u + i * 4u, kNullTag);
        store32(self, 0x34u + i * 4u, kFlareFloat100);
        store32(self, 0x1cu + i * 4u, 0xffffffffu);
    }
    for (U i = 0u; i < 4u; ++i) {
        store32(self, 0x0cu + i * 4u, 0u);
        store32(self, 0x24u + i * 4u, 0u);
        store32(self, 0x3cu + i * 4u, 0u);
    }
    std::memset(static_cast<B*>(self) + 0x5cu, 0, 0x30u);
    return self;
}

void* __fastcall scene_stage_constructor_004522b0(void* self, void* /*unused_edx*/) {
    store32(self, 0x00u, 0u);
    std::memset(static_cast<B*>(self) + 0x08u, 0, 0x320u);
    store32(self, 0x04u, 0u);

    char path[0x190]{};
    formatter_entry_005a0fbf(path, "%sflare.dat", startup_resource_prefix_0065b30c);
    void* const data = resource_open_quiet_0059d9b0(path, 0u);

    if (data != nullptr) {
        const U total_bytes = context_table_size_0059ece0(data);
        const auto* cur = static_cast<const B*>(data);
        const auto* const end = cur + total_bytes;
        if (cur < end) {
            do {
                void* holder = startup_network_allocate_0059ef90(0x0cu);
                if (holder != nullptr) {
                    void* entry = startup_network_allocate_0059ef90(kFlareEntryBytes);
                    if (entry != nullptr) {
                        scene_flare_entry_ctor_004524a0(entry, nullptr, kNullTag);
                    }
                    store_ptr(holder, 0x00u, entry);
                    std::memcpy(entry, cur, kFlareEntryBytes);
                    scene_flare_entries_resolve_00452120(holder, nullptr);
                }
                append_holder(self, holder);
                cur += kFlareEntryBytes;
            } while (cur < end);
        }
        context_table_release_0059ecd0(data);
    } else {
        void* holder = startup_network_allocate_0059ef90(0x0cu);
        if (holder != nullptr) {
            void* entry = startup_network_allocate_0059ef90(kFlareEntryBytes);
            if (entry != nullptr) {
                entry = scene_flare_entry_ctor_004524a0(entry, nullptr, kNullTag);
            }
            store_ptr(holder, 0x00u, entry);
            scene_flare_entries_resolve_00452120(holder, nullptr);
        }
        append_holder(self, holder);
    }

    void* const old_table = load_ptr(self, 0x00u);
    if (old_table != nullptr) {
        (void)application_release_0059f050(old_table);
    }

    const U final_count = load32(self, 0x04u);
    void* const table = application_allocate_array_0059eff0(final_count * 4u);
    store_ptr(self, 0x00u, table);

    for (std::int32_t i = 0; i < static_cast<std::int32_t>(load32(self, 0x04u)); ++i) {
        void* const item = load_ptr(self, 0x08u + static_cast<U>(i) * 4u);
        store_ptr(load_ptr(self, 0x00u), static_cast<U>(i) * 4u, item);
    }
    return self;
}

} // namespace porsche
