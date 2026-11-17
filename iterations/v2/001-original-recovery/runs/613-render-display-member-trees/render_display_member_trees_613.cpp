// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0044b1d0..0044b246, 119 bytes, sha256 1893c427a2ba7baf2e21914445e8d71a23d1941638d07989f77e2a0617ff31cd.
// Original 00466380..004664f3, 372 bytes, sha256 8e0f96c472cc39f82c45d00b7f652363e4ae972c45514e4bd7d370589a02b06a.
#include "render_display_member_trees_613.hpp"

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

} // namespace

namespace porsche {

void* __fastcall render_display_tree_ctor_0044b1d0(
    void* self, void* unused_edx, const std::uint8_t* flag_ptr, const void* unused_arg) {
    (void)unused_edx;
    (void)unused_arg;

    auto* const tree = static_cast<std::uint8_t*>(self);
    store32(tree, 0x00u, 0u);

    auto* const mgr = static_cast<std::uint8_t*>(application_context_heap_state_005e4fe8());
    auto* const pool = mgr + 0x28u;
    heap_enter_005322b0(load_ptr(pool, 0x00u));
    if (load_ptr(pool, 0x18u) == nullptr) {
        application_context_new_head_0059eeb0(3u, 0u);
    }
    auto* const node = static_cast<std::uint8_t*>(load_ptr(pool, 0x18u));
    store_ptr(pool, 0x18u, load_ptr(node, 0x04u));
    heap_leave_005322c0(load_ptr(pool, 0x00u));

    store_ptr(tree, 0x00u, node);
    store32(tree, 0x04u, 0u);
    tree[0x08u] = *flag_ptr;
    node[0x00u] = 0u;

    auto* const head = static_cast<std::uint8_t*>(load_ptr(tree, 0x00u));
    store32(head, 0x04u, 0u);
    store_ptr(head, 0x08u, head);
    store_ptr(head, 0x0cu, head);
    return self;
}

void* __fastcall render_display_member_raw_00466380(void* self, void* unused_edx) {
    (void)unused_edx;

    auto* const base = static_cast<std::uint8_t*>(self);
    std::uint32_t local_ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self));
    auto* const local_bytes = reinterpret_cast<std::uint8_t*>(&local_ecx);
    const std::uint8_t* const local_a = local_bytes + 2;
    std::uint8_t* const local_b = local_bytes + 3;

    void* t0 = render_allocate_0059ef90(0x0cu);
    if (t0 != nullptr) {
        t0 = render_display_tree_ctor_0044b1d0(t0, nullptr, local_b, local_a);
    }
    store_ptr(base, 0x00u, t0);

    static constexpr std::uint32_t kOffsets[7] = {
        0x14u, 0x0cu, 0x08u, 0x04u, 0x18u, 0x1cu, 0x10u
    };
    for (std::uint32_t i = 0u; i < 7u; ++i) {
        void* t = render_allocate_0059ef90(0x0cu);
        if (t != nullptr) {
            const void* const id = context_identity_00423610(local_b, nullptr);
            t = render_display_tree_ctor_0044b1d0(t, nullptr, local_a, id);
        }
        store_ptr(base, kOffsets[i], t);
    }
    return self;
}

void __cdecl render_display_member_00466380(void* member) {
    (void)render_display_member_raw_00466380(member, nullptr);
}

} // namespace porsche
