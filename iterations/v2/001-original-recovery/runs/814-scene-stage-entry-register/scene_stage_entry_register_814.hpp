// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run814: scene stage entry register, page protect, & resource clone cluster:
//   005af040..005af080 ( 65B) application_page_protect_005af040
//   0044d380..0044d515 (406B) scene_stage_entry_register_0044d380
//   0044d520..0044d543 ( 36B) scene_stage_entry_record_init_0044d520
//   0044d550..0044d5a1 ( 82B) scene_stage_entry_apply_state_0044d550
//   00536120..00536173 ( 84B) scene_resource_node_clone_00536120
//   005365a0..005365d4 ( 53B) scene_resource_node_set_name_005365a0
//   00423840..00423882 ( 67B) scene_tree_node_advance_00423840
#pragma once

#include <cstdint>

namespace porsche {

// Matches exact typed child declarations in runs/810-scene-stage-table-load/scene_stage_table_load_810.hpp.
void __cdecl application_page_protect_005af040(
    void* address, std::uint32_t bytes, std::uint32_t read_only);

void* __fastcall scene_stage_entry_register_0044d380(
    void* self, void* unused_edx, const void* entry_ptr,
    std::uint32_t zero_a, std::uint32_t entry_tag, std::uint32_t zero_b,
    std::uint32_t one_a, std::uint32_t one_b, std::uint32_t flags);

void* __fastcall scene_stage_entry_record_init_0044d520(
    void* self, void* unused_edx,
    std::uint32_t key0, std::uint32_t key1, void* obj, std::uint8_t owned);

void __fastcall scene_stage_entry_apply_state_0044d550(
    void* self, void* unused_edx, void* node, const void* state_28_bytes);

void* __fastcall scene_resource_node_clone_00536120(
    void* self, void* unused_edx, const void* src);

void __fastcall scene_resource_node_set_name_005365a0(
    void* self, void* unused_edx, const char* name);

void __fastcall scene_tree_node_advance_00423840(void* node_ptr, void* unused_edx);

// Single typed child frontier reached by 0044d380 (0044db70..0044dc4e, 223B, __thiscall, RET 0x8).
void* __fastcall scene_stage_entry_insert_0044db70(
    void* tree, void* unused_edx, void* out_pair, const void* entry_record);

} // namespace porsche
