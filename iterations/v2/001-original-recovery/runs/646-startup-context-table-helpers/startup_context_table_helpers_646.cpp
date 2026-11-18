// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044b830..0044b8b7 (136B), 0044d320..0044d374 (85B),
// 0047f040..0047f189 (330B), and .data 00628bac..00628baf (4B).
#include "startup_context_table_helpers_646.hpp"

#include <cstring>

namespace {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::uint32_t load32(const void* base, std::uint32_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof value);
    return value;
}

void store32(void* base, std::uint32_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof value);
}

void* load_ptr(const void* base, std::uint32_t offset) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(load32(base, offset)));
}

void store_ptr(void* base, std::uint32_t offset, const void* value) {
    store32(base, offset, static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value)));
}

std::uintptr_t addr_of(const void* p) {
    return reinterpret_cast<std::uintptr_t>(p);
}

} // namespace

namespace porsche {

void* startup_context_table_00628bac = nullptr;

void** __fastcall startup_context_tree_find_0044b830(
    void* tree, void* unused_edx, void** out_node, const std::uint32_t* key_pair) {
    (void)unused_edx;

    void* const sentinel = load_ptr(tree, 0x00u);
    void* cur = load_ptr(sentinel, 0x04u);
    void* cand = sentinel;

    if (cur != nullptr) {
        const std::uint32_t key0 = key_pair[0];
        const std::uint32_t key1 = key_pair[1];
        do {
            const std::uint32_t node_key0 = load32(cur, 0x10u);
            if (node_key0 < key0 || (node_key0 == key0 && load32(cur, 0x14u) < key1)) {
                cur = load_ptr(cur, 0x0cu);
            } else {
                cand = cur;
                cur = load_ptr(cur, 0x08u);
            }
        } while (cur != nullptr);
    }

    if (cand == sentinel) {
        *out_node = sentinel;
        return out_node;
    }

    const std::uint32_t key0 = key_pair[0];
    const std::uint32_t cand_key0 = load32(cand, 0x10u);
    if (key0 < cand_key0 || (key0 == cand_key0 && key_pair[1] < load32(cand, 0x14u))) {
        *out_node = sentinel;
        return out_node;
    }

    *out_node = cand;
    return out_node;
}

void* __fastcall startup_context_table_lookup_0044d320(
    void* self, void* unused_edx, std::uint32_t key0, std::uint32_t key1) {
    (void)unused_edx;

    std::uint32_t key_pair[2] = {key0, key1};
    void* tree = load_ptr(self, 0x08u);
    void* found = nullptr;
    void** const result = startup_context_tree_find_0044b830(tree, nullptr, &found, key_pair);

    tree = load_ptr(self, 0x08u);
    void* const node = *result;
    if (node == load_ptr(tree, 0x00u)) {
        return nullptr;
    }
    return load_ptr(node, 0x18u);
}

void __cdecl startup_context_table_init_0047f040() {
    if (startup_context_table_00628bac != nullptr) {
        return;
    }

    void* const table = startup_network_allocate_0059ef90(0xccu);
    if (table == nullptr) {
        startup_context_table_00628bac = nullptr;
        return;
    }

    void* const raw_vec = startup_network_allocate_0059ef90(0x0cu);
    std::uint8_t* vec = nullptr;
    if (raw_vec != nullptr) {
        store32(raw_vec, 0x00u, 0u);
        store32(raw_vec, 0x04u, 0u);
        store32(raw_vec, 0x08u, 0u);
        vec = static_cast<std::uint8_t*>(raw_vec);
    }
    store_ptr(table, 0xa4u, vec);

    const void* const root = reinterpret_cast<const void*>(
        static_cast<std::uintptr_t>(frame_service_root_00628960));
    const void* const service_sub = load_ptr(root, 0x10u);
    const std::uint32_t target_cap = load32(service_sub, 0x88u);

    const std::uintptr_t old_begin_addr = addr_of(load_ptr(vec, 0x00u));
    const std::uintptr_t old_cap_end_addr = addr_of(load_ptr(vec, 0x08u));
    const std::int32_t cur_cap =
        static_cast<std::int32_t>(old_cap_end_addr - old_begin_addr) >> 2;

    if (static_cast<std::uint32_t>(cur_cap) < target_cap) {
        const std::uintptr_t old_end_addr = addr_of(load_ptr(vec, 0x04u));
        const std::int32_t cur_count =
            static_cast<std::int32_t>(old_end_addr - old_begin_addr) >> 2;

        void* new_buf = nullptr;
        if (target_cap != 0u) {
            new_buf = application_context_member_storage_004211d0(target_cap << 2, 0u);
        }

        std::uintptr_t src_addr = old_begin_addr;
        std::uintptr_t dst_addr = addr_of(new_buf);
        while (src_addr != old_end_addr) {
            if (dst_addr != 0u) {
                store32(reinterpret_cast<void*>(dst_addr), 0x00u,
                        load32(reinterpret_cast<const void*>(src_addr), 0x00u));
            }
            src_addr += 4u;
            dst_addr += 4u;
        }

        void* const cur_begin = load_ptr(vec, 0x00u);
        const std::uintptr_t cur_cap_end_addr = addr_of(load_ptr(vec, 0x08u));
        const std::int32_t old_cap =
            static_cast<std::int32_t>(cur_cap_end_addr - addr_of(cur_begin)) >> 2;

        if (old_cap != 0) {
            const std::uint32_t old_bytes = static_cast<std::uint32_t>(old_cap) * 4u;
            if (old_bytes > 0x100u) {
                context_table_release_0059ecd0(cur_begin);
            } else {
                auto* const mgr = static_cast<std::uint8_t*>(
                    application_context_heap_state_005e4fe8());
                auto* const pool = mgr + 0x28u;
                heap_enter_005322b0(load_ptr(pool, 0x00u));
                const std::uint32_t head_off = (((old_bytes - 1u) >> 3u) * 4u) + 0x0cu;
                store_ptr(cur_begin, 0x04u, load_ptr(pool, head_off));
                store_ptr(pool, head_off, cur_begin);
                heap_leave_005322c0(load_ptr(pool, 0x00u));
            }
        }

        const std::uintptr_t new_addr = addr_of(new_buf);
        store_ptr(vec, 0x00u, new_buf);
        store_ptr(vec, 0x04u,
                  reinterpret_cast<const void*>(new_addr + static_cast<std::uint32_t>(cur_count) * 4u));
        store_ptr(vec, 0x08u,
                  reinterpret_cast<const void*>(new_addr + target_cap * 4u));
    }

    startup_context_table_00628bac = table;
}

} // namespace porsche
