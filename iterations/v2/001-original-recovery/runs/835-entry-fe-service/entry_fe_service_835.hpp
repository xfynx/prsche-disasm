// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run835: entry_fe_service_00465790 closed cluster (17 functions, 4,563B code,
// 336B .data table at 005cf610..005cf75f, 76B .bss).
#pragma once

#include <cstdint>

namespace porsche {

struct ViewModeCameraPreset005cf610 {
    std::uint32_t vec_x_bits;
    std::uint32_t vec_y_bits;
    std::uint32_t vec_z_bits;
    std::uint32_t flags;
};
static_assert(sizeof(ViewModeCameraPreset005cf610) == 16u,
    "ViewModeCameraPreset005cf610 must be 16 bytes");

// Owned original .data and .bss storage.
extern ViewModeCameraPreset005cf610 view_mode_camera_presets_005cf610[21];
extern std::uint32_t sector_query_count_006289ec;
extern std::uint32_t sector_cache_hits_006289f0;
extern float quadtree_cell_sizes_00628be8[16];
extern float quadtree_origin_offset_00628c30;

// Canonical externs owned elsewhere.
extern std::uint8_t view_slot_table_00627e80[0x218u];
extern std::uint32_t entry_fe_flag_word_006280e0;
extern std::uint32_t entry_fe_flag_word_006280e4;
extern std::uint32_t frame_reset_word_006280e8;
extern std::uint32_t frame_reset_word_006280ec;
extern std::uint32_t frame_reset_word_006280f0;
extern std::uint32_t frame_reset_word_006280f8;
extern std::uint32_t frame_reset_word_006280fc;
extern std::uint32_t frame_reset_word_00628100;
extern std::uint32_t frame_service_root_00628960;
extern void* track_road_data_00628bc0;
extern void* startup_network_00628c70;
extern std::uint32_t global_005e99f4;
extern std::uint32_t fe_loop_word_00606850;
extern std::uint32_t global_00657430;

void __cdecl view_route_counter_00465cf0(std::int32_t index);
// Opaque 63B transform wrapper boundary (retains 005df364/005df3e4 outside scope).
void __cdecl transform_vectors_00532a40(
    std::int32_t count, const float* input_vec3, const void* matrix_3x3, float* output_vec3);

// Recovered original functions (17 bodies, 4,563B).
void __cdecl entry_fe_service_00465790(std::uint32_t first, std::uint32_t second);
void __cdecl view_route_select_00463260(std::int32_t slot_index);
void __cdecl view_slot_camera_transform_004618b0(std::int32_t slot_index);
std::uint8_t __cdecl view_slot_height_query_00461370(
    std::int32_t slot_index, const float* origin, float* out_height);
void __cdecl assign_dword_if_nonnull_0042bcb0(std::uint32_t* dst, const std::uint32_t* src);
std::uint32_t* __cdecl copy_dword_range_0046db70(
    const std::uint32_t* first, const std::uint32_t* last, std::uint32_t* dst);
void* __fastcall sector_find_surface_00473240(void* self, void* unused_edx, const float* pos);
void* __fastcall sector_collect_surfaces_00473420(
    void* self, void* unused_edx, const float* pos, float radius);
void __fastcall sector_track_step_00474060(
    void* self, void* unused_edx, const float* pos, std::uint8_t reuse_cached);
void* __fastcall track_portal_query_004816f0(
    void* self, void* unused_edx, std::int32_t seg, std::int32_t delta);
std::int16_t __fastcall track_segment_advance_004817d0(
    void* self, void* unused_edx, std::int32_t seg, std::int32_t delta, std::int32_t portal_hint);
std::uint8_t __fastcall quadtree_node_contains_xz_00484450(
    void* self, void* unused_edx, const float* pos);
void* __fastcall quadtree_lookup_leaf_00484500(
    void* self, void* unused_edx, const float* pos);
void __fastcall quadtree_collect_leaves_00484630(
    void* self, void* unused_edx, const float* pos, float radius, void* out_vec);
float __cdecl ray_plane_param_0048a060(
    const float* normal, const float* plane_pt, const float* ray_origin);
float __cdecl vec3_dot_00532910(const float* a, const float* b);
float __cdecl vec3_dot_inner_0056e8d1(const float* a, const float* b);

} // namespace porsche
