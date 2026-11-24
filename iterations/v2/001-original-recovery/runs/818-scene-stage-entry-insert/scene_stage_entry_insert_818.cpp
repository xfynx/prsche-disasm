// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run818: 0044db70 (223B), 0044b800 (43B), 0044de20 (35B), 004314c0 (430B).
#include "scene_stage_entry_insert_818.hpp"

#include "porsche/application_context_base.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

enum : U {
    kOffColor = 0x00u,
    kOffParent = 0x04u,
    kOffLeft = 0x08u,
    kOffRight = 0x0cu,
    kRed = 0u,
    kBlack = 1u,
};

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

B node_color(const void* node) {
    return static_cast<const B*>(node)[kOffColor];
}

void set_node_color(void* node, B color) {
    static_cast<B*>(node)[kOffColor] = color;
}

void rotate_tree_step(void* x, void** root_ptr, U dir_off, U opp_off) {
    void* const y = load_ptr(x, opp_off);
    void* const beta = load_ptr(y, dir_off);
    store_ptr(x, opp_off, beta);
    if (beta != nullptr) {
        store_ptr(beta, kOffParent, x);
    }
    void* const xp = load_ptr(x, kOffParent);
    store_ptr(y, kOffParent, xp);
    if (x == *root_ptr) {
        *root_ptr = y;
    } else if (x == load_ptr(xp, dir_off)) {
        store_ptr(xp, dir_off, y);
    } else {
        store_ptr(xp, opp_off, y);
    }
    store_ptr(y, dir_off, x);
    store_ptr(x, kOffParent, y);
}

} // namespace

bool __fastcall scene_stage_key_less_0044b800(
    const void* lhs, void* /*unused_edx*/, const void* rhs) {
    const U l0 = load32(lhs, 0x00u);
    const U r0 = load32(rhs, 0x00u);
    if (l0 < r0) {
        return true;
    }
    if (l0 != r0) {
        return false;
    }
    return load32(lhs, 0x04u) < load32(rhs, 0x04u);
}

void __cdecl scene_stage_entry_copy_0044de20(void* dst, const void* src) {
    if (dst != nullptr) {
        std::memcpy(dst, src, 0x10u);
    }
}

void __cdecl scene_rb_tree_rebalance_004314c0(void* node, void** root_ptr) {
    set_node_color(node, static_cast<B>(kRed));
    while (node != *root_ptr) {
        void* parent = load_ptr(node, kOffParent);
        if (node_color(parent) != kRed) {
            break;
        }
        void* const grand = load_ptr(parent, kOffParent);
        const bool parent_is_left = (parent == load_ptr(grand, kOffLeft));
        const U near_off = parent_is_left ? kOffLeft : kOffRight;
        const U far_off = parent_is_left ? kOffRight : kOffLeft;

        void* const uncle = load_ptr(grand, far_off);
        if (uncle != nullptr && node_color(uncle) == kRed) {
            set_node_color(parent, static_cast<B>(kBlack));
            set_node_color(uncle, static_cast<B>(kBlack));
            set_node_color(grand, static_cast<B>(kRed));
            node = grand;
            continue;
        }

        if (node == load_ptr(parent, far_off)) {
            node = parent;
            rotate_tree_step(node, root_ptr, near_off, far_off);
            parent = load_ptr(node, kOffParent);
        }
        set_node_color(parent, static_cast<B>(kBlack));
        void* const gp = load_ptr(parent, kOffParent);
        set_node_color(gp, static_cast<B>(kRed));
        rotate_tree_step(gp, root_ptr, far_off, near_off);
    }
    set_node_color(*root_ptr, static_cast<B>(kBlack));
}

void* __fastcall scene_stage_entry_insert_0044db70(
    void* tree, void* /*unused_edx*/, void* out_pair, const void* entry_record) {
    B* const sentinel = static_cast<B*>(load_ptr(tree, 0x00u));
    B* y = sentinel;
    B* x = static_cast<B*>(load_ptr(sentinel, kOffParent));
    while (x != nullptr) {
        y = x;
        const bool go_left = scene_stage_key_less_0044b800(
            entry_record, nullptr, x + 0x10u);
        x = static_cast<B*>(load_ptr(x, go_left ? kOffLeft : kOffRight));
    }

    const bool insert_left = (y == sentinel) ||
        scene_stage_key_less_0044b800(entry_record, nullptr, y + 0x10u);

    B* const new_node = static_cast<B*>(
        application_context_member_storage_004211d0(0x20u, 0u));
    scene_stage_entry_copy_0044de20(new_node + 0x10u, entry_record);

    if (insert_left) {
        store_ptr(y, kOffLeft, new_node);
        if (y == sentinel) {
            store_ptr(sentinel, kOffParent, new_node);
            store_ptr(sentinel, kOffRight, new_node);
        } else if (y == load_ptr(sentinel, kOffLeft)) {
            store_ptr(sentinel, kOffLeft, new_node);
        }
    } else {
        store_ptr(y, kOffRight, new_node);
        if (y == load_ptr(sentinel, kOffRight)) {
            store_ptr(sentinel, kOffRight, new_node);
        }
    }

    store_ptr(new_node, kOffParent, y);
    store_ptr(new_node, kOffLeft, nullptr);
    store_ptr(new_node, kOffRight, nullptr);

    scene_rb_tree_rebalance_004314c0(
        new_node, reinterpret_cast<void**>(sentinel + kOffParent));
    store32(tree, 0x04u, load32(tree, 0x04u) + 1u);
    store_ptr(out_pair, 0x00u, new_node);
    return out_pair;
}

} // namespace porsche
