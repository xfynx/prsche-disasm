// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run702 typed children of the accepted Run692 FE-entry and Run693 scene-enter callers.
#pragma once

#include <cstdint>

namespace porsche {

// ---- Exact externs used by accepted callers (do not change signature) --------
// From runs/692-entry-fe-loop-and-leaves/fe_entry_leaves_692.hpp
std::int32_t __cdecl entry_fe_call_0046d960();
std::uint32_t __cdecl entry_fe_call_0046d890();
void __cdecl entry_fe_call_00413960(std::uint32_t value); // excluded, evidence only
void __cdecl entry_fe_call_004659e0(std::uint32_t first, std::uint32_t second);

// From runs/693-view-setup-teardown-scene-enter/application_view_lifecycle_693.hpp
void __cdecl scene_route_select_00475d70(std::uint32_t from, std::uint32_t to);
void __cdecl scene_route_root_0044fae0(void* root);
void __cdecl scene_transfer_enter_004521c0();
void* __fastcall scene_transfer_slot_0044b960(void* self, void* unused_edx);
void __cdecl scene_route_bind_0045dbd0(void* root, std::uint32_t mode); // excluded, evidence only

// ---- Cells newly owned by this packet (all loader-zero .data virtual tail) ----
extern void* scene_route_root_object_0061bc38;
extern void* scene_transfer_object_0061bcc0;
extern std::uint32_t entry_fe_flag_word_006280e0;
extern std::uint32_t entry_fe_flag_word_006280e4;
extern std::uint32_t entry_fe_frame_word_00606ad4;
// Pointers to the original two-dword {begin,end} vector headers.
extern std::uint32_t* scene_elem_vector_00628168;
extern std::uint32_t* scene_elem_count_vector_00628178;

// ---- Reused canonical owners (declared only, never redefined here) -----------
extern std::uint8_t view_slot_table_00627e80[0x218u]; // Run693
extern std::uint32_t frame_reset_word_006280f0;       // Run400/692
extern std::uint32_t frame_reset_word_006280ec;
extern std::uint32_t frame_reset_word_006280e8;
extern std::uint32_t frame_reset_word_00628100;
extern std::uint32_t frame_reset_word_006280fc;
extern std::uint32_t frame_reset_word_006280f8;

// ---- Opaque callees: observed call-site ABI only, no algorithm claimed --------
void __cdecl entry_fe_service_00465790(std::uint32_t first, std::uint32_t second);
void __cdecl scene_route_dispatch_00475c80(std::uint32_t value);
void* __cdecl scene_slot_object_004211d0(std::uint32_t size, std::uint32_t zero);
void* __fastcall scene_root_constructor_0044fb40(void* self, void* unused_edx,
                                                  void* root);
void* __fastcall scene_stage_constructor_004522b0(void* self, void* unused_edx);
std::uint32_t __cdecl formatter_compare_005a134b(std::uint32_t element,
                                                 std::uint32_t arg1,
                                                 const void* scene_rtti,
                                                 const void* camera_rtti,
                                                 std::uint32_t arg4);
std::uint32_t __fastcall scene_elem_kind_00469b50(void* object,
                                                  void* unused_edx);
extern const std::uint8_t rtti_scene_elem_005cf908[8u];
extern const std::uint8_t rtti_camera_elem_005cf928[8u];

} // namespace porsche
