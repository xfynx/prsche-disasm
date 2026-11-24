// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run810: scene stage table load & mapped shape table helpers:
//   0044d270..0044d314 (165B) scene_stage_table_load_0044d270
//   00537f30..00537f37 (  8B) scene_shape_table_count_00537f30
//   00537f60..00537f84 ( 37B) scene_shape_table_tag_00537f60
//   0059f880..0059f892 ( 19B) scene_mapped_file_init_0059f880
//   0059f8a0..0059f8e4 ( 69B) scene_mapped_file_close_0059f8a0
//   0059fb90..0059fbbd ( 46B) scene_mapped_file_data_0059fb90
#pragma once

#include <cstdint>

namespace porsche {

// Matches exact typed child declaration in runs/805-scene-stage-reset/scene_stage_reset_805.hpp.
void __fastcall scene_stage_table_load_0044d270(
    void* self, void* unused_edx, const char* path, std::uint32_t zero);

std::uint32_t __cdecl scene_shape_table_count_00537f30(const void* table);
void __cdecl scene_shape_table_tag_00537f60(
    const void* table, std::int32_t index, std::uint32_t* out_tag);

void __fastcall scene_mapped_file_init_0059f880(void* self, void* unused_edx);
void __fastcall scene_mapped_file_close_0059f8a0(void* self, void* unused_edx);
void* __fastcall scene_mapped_file_data_0059fb90(void* self, void* unused_edx);

// Typed child frontiers reached by 0044d270 and 0059fb90.
void __fastcall scene_mapped_file_open_0059f8f0(
    void* self, void* unused_edx, const char* path, std::uint32_t flags);
void* __fastcall scene_stage_entry_register_0044d380(
    void* self, void* unused_edx, const void* entry_ptr,
    std::uint32_t zero_a, std::uint32_t entry_tag, std::uint32_t zero_b,
    std::uint32_t one_a, std::uint32_t one_b, std::uint32_t flags);
void __cdecl application_page_protect_005af040(
    void* address, std::uint32_t bytes, std::uint32_t read_only);

} // namespace porsche
