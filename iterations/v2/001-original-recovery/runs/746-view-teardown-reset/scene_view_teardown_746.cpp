// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run746: 00466500..00466653 (340B), 00466c30..00466c9c (109B),
//         00466ca0..00466d0c (109B), 00466d10..00466d5e (79B), 00466d60..00466dae (79B).
#include "scene_view_teardown_746.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/heap.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;
using ClearFn = void(__fastcall*)(void*, void*);
using ReleaseNodesFn = void(__fastcall*)(void*, void*, void*);

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

// Returns one tree node to the shared context free list at [ctx + 0x40]
// under the lock stored at [ctx + 0x28].
void push_free_tree_node(void* node) {
    auto* ctx = static_cast<B*>(application_context_heap_state_005e4fe8());
    auto* pool = ctx + 0x28u;
    heap_enter_005322b0(load_ptr(pool, 0u));
    store_ptr(node, 0x04u, load_ptr(pool, 0x18u));
    store_ptr(pool, 0x18u, node);
    heap_leave_005322c0(load_ptr(pool, 0u));
}

// Post-order subtree reclamation: recurses on right child (+0x0c), frees node,
// and tail-iterates along left child (+0x08).
void release_subtree_impl(void* self, void* node, ReleaseNodesFn recurse) {
    while (node != nullptr) {
        recurse(self, nullptr, load_ptr(node, 0x0cu));
        void* left_next = load_ptr(node, 0x08u);
        push_free_tree_node(node);
        node = left_next;
    }
}

void reset_tree_sentinel(void* tree) {
    void* head = load_ptr(tree, 0x00u);
    store_ptr(head, 0x08u, head);
    head = load_ptr(tree, 0x00u);
    store_ptr(head, 0x04u, nullptr);
    head = load_ptr(tree, 0x00u);
    store_ptr(head, 0x0cu, head);
    store32(tree, 0x04u, 0u);
}

// Matches 00466c30 and 00466ca0: walks left chain from head+4, recursing right subtrees.
void clear_tree_loop_impl(void* self, ReleaseNodesFn release_subtree) {
    if (load32(self, 0x04u) == 0u) {
        return;
    }
    void* head = load_ptr(self, 0x00u);
    void* node = load_ptr(head, 0x04u);
    while (node != nullptr) {
        release_subtree(self, nullptr, load_ptr(node, 0x0cu));
        void* left_next = load_ptr(node, 0x08u);
        push_free_tree_node(node);
        node = left_next;
    }
    reset_tree_sentinel(self);
}

// Matches the inlined clear at +0x04 and +0x1c inside 00466500: calls the
// recursive node-release helper directly on the root pointer at head+4.
void __fastcall clear_tree_inlined_a(void* self, void*) {
    if (load32(self, 0x04u) != 0u) {
        void* head = load_ptr(self, 0x00u);
        scene_tree_nodes_release_a_00466d10(self, nullptr, load_ptr(head, 0x04u));
        reset_tree_sentinel(self);
    }
}

void __fastcall clear_tree_inlined_b(void* self, void*) {
    if (load32(self, 0x04u) != 0u) {
        void* head = load_ptr(self, 0x00u);
        scene_tree_nodes_release_b_00466d60(self, nullptr, load_ptr(head, 0x04u));
        reset_tree_sentinel(self);
    }
}

} // namespace

void __fastcall scene_tree_nodes_release_a_00466d10(
    void* self, void* /*unused_edx*/, void* node) {
    release_subtree_impl(self, node, &scene_tree_nodes_release_a_00466d10);
}

void __fastcall scene_tree_nodes_release_b_00466d60(
    void* self, void* /*unused_edx*/, void* node) {
    release_subtree_impl(self, node, &scene_tree_nodes_release_b_00466d60);
}

void __fastcall scene_tree_clear_a_00466c30(void* self, void* /*unused_edx*/) {
    clear_tree_loop_impl(self, &scene_tree_nodes_release_a_00466d10);
}

void __fastcall scene_tree_clear_b_00466ca0(void* self, void* /*unused_edx*/) {
    clear_tree_loop_impl(self, &scene_tree_nodes_release_b_00466d60);
}

void __fastcall view_teardown_reset_00466500(void* self, void* /*unused_edx*/) {
    struct SlotSpec {
        U offset;
        ClearFn clear;
    };
    static constexpr SlotSpec kSlots[] = {
        {0x00u, &scene_tree_clear_a_00466c30},
        {0x14u, &scene_tree_clear_a_00466c30},
        {0x0cu, &scene_tree_clear_b_00466ca0},
        {0x08u, &scene_tree_clear_b_00466ca0},
        {0x10u, &scene_tree_clear_b_00466ca0},
        {0x04u, &clear_tree_inlined_a},
        {0x18u, &scene_tree_clear_b_00466ca0},
        {0x1cu, &clear_tree_inlined_b},
    };
    for (const SlotSpec& spec : kSlots) {
        void* tree = load_ptr(self, spec.offset);
        if (tree != nullptr) {
            spec.clear(tree, nullptr);
            application_context_clear_004237d0(load_ptr(tree, 0x00u), 0x20u, 0u);
            (void)application_release_0059f050(tree);
        }
    }
}

} // namespace porsche
