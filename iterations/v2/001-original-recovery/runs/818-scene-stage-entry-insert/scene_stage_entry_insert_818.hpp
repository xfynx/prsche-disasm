// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run818: scene stage entry RB-tree insert & rebalance cluster:
//   0044db70..0044dc4e (223B) scene_stage_entry_insert_0044db70
//   0044b800..0044b828 ( 43B) scene_stage_key_less_0044b800
//   0044de20..0044de42 ( 35B) scene_stage_entry_copy_0044de20
//   004314c0..0043166d (430B) scene_rb_tree_rebalance_004314c0
#pragma once

#include <cstdint>

namespace porsche {

// Matches exact typed child declaration in runs/814-scene-stage-entry-register/scene_stage_entry_register_814.hpp.
void* __fastcall scene_stage_entry_insert_0044db70(
    void* tree, void* unused_edx, void* out_pair, const void* entry_record);

bool __fastcall scene_stage_key_less_0044b800(
    const void* lhs, void* unused_edx, const void* rhs);

void __cdecl scene_stage_entry_copy_0044de20(void* dst, const void* src);

void __cdecl scene_rb_tree_rebalance_004314c0(void* node, void** root_ptr);

} // namespace porsche
