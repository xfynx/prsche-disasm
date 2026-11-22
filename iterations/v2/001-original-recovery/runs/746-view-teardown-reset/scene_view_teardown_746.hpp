// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run746: view teardown tree reset cluster:
//   00466500..00466653 (340B) view_teardown_reset_00466500
//   00466c30..00466c9c (109B) scene_tree_clear_a_00466c30
//   00466ca0..00466d0c (109B) scene_tree_clear_b_00466ca0
//   00466d10..00466d5e ( 79B) scene_tree_nodes_release_a_00466d10
//   00466d60..00466dae ( 79B) scene_tree_nodes_release_b_00466d60
#pragma once

#include <cstdint>

namespace porsche {

// Original 00466d10..00466d5e (79B, __thiscall, 1 stack pointer arg, void return, RET 4).
void __fastcall scene_tree_nodes_release_a_00466d10(
    void* self, void* unused_edx, void* node);

// Original 00466d60..00466dae (79B, __thiscall, 1 stack pointer arg, void return, RET 4).
void __fastcall scene_tree_nodes_release_b_00466d60(
    void* self, void* unused_edx, void* node);

// Original 00466c30..00466c9c (109B, __thiscall, void return, RET 0).
void __fastcall scene_tree_clear_a_00466c30(void* self, void* unused_edx);

// Original 00466ca0..00466d0c (109B, __thiscall, void return, RET 0).
void __fastcall scene_tree_clear_b_00466ca0(void* self, void* unused_edx);

// Original 00466500..00466653 (340B, __thiscall, void return, RET 0).
// Matches caller declaration in runs/693-view-setup-teardown-scene-enter/application_view_lifecycle_693.hpp.
void __fastcall view_teardown_reset_00466500(void* self, void* unused_edx);

} // namespace porsche
