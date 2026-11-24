// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/application_services.hpp"
#include "porsche/application_state.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/heap.hpp"
#include "../400-frame-loop-clusters/frame_loop_clusters_400.hpp"
#include "../707-view-teardown-child-leaves/view_teardown_child_leaves_707.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// 12-byte engine-table slice descriptor at +0x2d4..+0x454 inside the 0x758-byte
// 004acc10 Engine Audio state block.
struct EngineAudioTableSlice813 {
    std::int16_t start_00;
    std::int16_t end_02;
    void* data_04;
    std::uint8_t tag_08;
    std::uint8_t pad_09[3];
};
static_assert(sizeof(EngineAudioTableSlice813) == 0x0c);

// 12-byte vector header (prefix matches FrameVector_400 {begin, end}).
struct SimVector12_813 {
    std::uint32_t begin;
    std::uint32_t end;
    std::uint32_t capacity_end;
};
static_assert(sizeof(SimVector12_813) == 12);

// Reused canonical symbols (matching 478/643/658/661/670/690/697/703 declarations).
extern void* audio_channel_banks_00656aa8[2];
extern char* application_audio_path_prefix_0065b318;
extern const char application_audio_spl_text_005d1a04[5];
extern const char audio_bank_suffix_text_005d146c[5];

std::int32_t __cdecl audio_bank_finalize_004a6bc0(
    const char* text, std::int32_t bank_result, const void* handle, std::uint32_t kind);
std::uint32_t __cdecl resource_loadat_quiet_0059db50(
    const char* name, void* buffer, std::uint32_t max_bytes);
void* __cdecl resource_load_bigheader_0059dea0(
    const char* name, std::uint32_t flags);
void* __cdecl resource_load_bigheader_quiet_0059df70(
    const char* name, std::uint32_t flags);
std::uint32_t __cdecl audio_resource_data_offset_00566880(std::uint32_t source);
std::uint32_t __cdecl audio_resource_locate_005666f0(
    std::uint32_t source, std::uint32_t name, std::uint32_t index,
    std::uint32_t out_offset, std::uint32_t out_size);

// Newly owned read-only .data literals from 004acc10 (pinned byte-for-byte vs Porsche.exe).
extern const char audio_file_ver_err_005d1ad4[33];
extern const char audio_file_id_err_005d1af8[28];
extern const char audio_engine_tables_tag_005d1b14[14];
extern const char audio_clt_ext_005d1b24[5];
extern const char audio_cct_ext_005d1b2c[5];
extern const char audio_elt_ext_005d1b34[5];
extern const char audio_ect_ext_005d1b3c[5];
extern const char audio_engine_oom_fmt_005d1b44[28];
extern const char audio_sd7a_viv_fmt_005d1b60[11];
extern const char audio_sd7a16_viv_fmt_005d1b6c[13];
extern const char audio_name_viv_fmt_005d1b7c[9];
extern const char audio_name16_viv_fmt_005d1b88[11];
extern const char audio_engine_tag_005d1b94[13];

// Loader-zero .bss cells owned by Run813 for 00425330 / 00419dc0 / 0041e2c0 / 00434f00.
// frame_callback_vector_0060c9f4 and frame_compact_vector_0060c9c4 are declared
// in frame_loop_clusters_400.hpp and defined in sim_audio_and_frame_teardown_813.cpp.
extern void* sim_teardown_secondary_0060c7e8;
extern void* sim_teardown_buf_0060ab10;
extern void* sim_teardown_buf_0060ab18;
extern void* sim_teardown_buf_0060ab1c;

extern std::int32_t sim_lists_refcount_0060c978;
extern void* sim_lists_free_buf_0060c974;
extern void* sim_lists_table_0060c964;
extern void* sim_lists_table_0060c968;
extern SimVector12_813* sim_lists_vec_0060c818;
extern SimVector12_813* sim_lists_vec_0060c904;

extern SimVector12_813* sim_pool_vec_00610a80;
extern void* sim_pool_lock_00610a88;

extern VirtualDeleteSlot0_400* sim_obj_0060c9ac;
extern VirtualDeleteSlot0_400* sim_obj_0060c9b0;
extern VirtualDeleteSlot0_400* sim_obj_0060c9bc;
extern VirtualDeleteSlot0_400* sim_obj_0060c9c0;
extern VirtualDeleteSlot0_400* sim_obj_0060c9f0;
extern VirtualDeleteSlot0_400* sim_obj_0060c9fc;
extern VirtualDeleteSlot0_400* sim_obj_0060ca0c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca14;
extern VirtualDeleteSlot0_400* sim_obj_0060ca18;
extern VirtualDeleteSlot0_400* sim_obj_0060ca1c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca20;
extern VirtualDeleteSlot0_400* sim_obj_0060ca24;
extern VirtualDeleteSlot0_400* sim_obj_0060ca28;
extern VirtualDeleteSlot0_400* sim_obj_0060ca2c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca30;
extern VirtualDeleteSlot0_400* sim_obj_0060ca34;
extern VirtualDeleteSlot0_400* sim_obj_0060ca38;
extern VirtualDeleteSlot0_400* sim_obj_0060ca3c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca40;
extern VirtualDeleteSlot0_400* sim_obj_0060ca44;
extern VirtualDeleteSlot0_400* sim_obj_0060ca48;
extern VirtualDeleteSlot0_400* sim_obj_0060ca4c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca50;
extern VirtualDeleteSlot0_400* sim_obj_0060ca54;
extern VirtualDeleteSlot0_400* sim_obj_0060ca58;
extern VirtualDeleteSlot0_400* sim_obj_0060ca5c;
extern VirtualDeleteSlot0_400* sim_obj_0060ca60;
extern VirtualDeleteSlot0_400* sim_obj_0060ca64;
extern VirtualDeleteSlot0_400* sim_obj_0060ca68;
extern VirtualDeleteSlot0_400* sim_obj_0060ca7c;

// Recovered functions (matching application_sim_teardown_691.hpp declarations).
void __cdecl application_sim_boundary_004acc10(std::int32_t first, std::uint32_t buffer_va);
void __cdecl application_sim_boundary_00425330();
void __cdecl sim_teardown_globals_00419dc0();
void __cdecl sim_teardown_lists_0041e2c0();
std::uint32_t* __cdecl sim_teardown_copy_dwords_00436710(
    const std::uint32_t* src_begin,
    const std::uint32_t* src_end,
    std::uint32_t* dst);
void __cdecl sim_teardown_pool_00434f00();

} // namespace porsche
