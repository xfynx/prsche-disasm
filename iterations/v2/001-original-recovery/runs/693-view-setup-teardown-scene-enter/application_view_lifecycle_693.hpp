// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run693 packet: application view-slot setup (004640b0), display teardown
// (00467740) and scene-enter transfer (00468fb0).
//
// The exported function symbols are the exact names the accepted callers
// (application_main.cpp 004b6a50, startup_sequence.cpp 004b67b0) resolve.
#pragma once

#include <cstdint>

namespace porsche {

// Owned original .data cells, with the raw original initializer bytes.
// 0x005cf584: dword 1. 0x005cf5d8: byte 2. 0x005cf760: "castle" + NUL.
extern std::uint32_t view_route_flag_005cf584;
extern std::uint8_t view_route_string_005cf5d8;
extern char view_castle_string_005cf760[7u];

// Owned original .data cell 0x005cf620..0x005cf62b. The original file bytes
// are {0x00000000, 0x3ecccccd, 0x3f666666} (0.0f, 0.4f, 0.9f as raw dwords);
// 004640b0 overwrites all three from the selected route object.
extern std::uint32_t view_setup_camera_005cf620[3u];

// Owned original .bss cells. Both view slots use the original 0x10c stride:
// slot one at 0x00627e80, slot two at 0x00627f8c. 0x00627ecc..0x00627ed7 is
// written by the post-loop tail of 004640b0 and lives inside the slot-one
// span at offset 0x4c.
extern std::uint8_t view_slot_table_00627e80[0x218u];

// Route object registry cells 0x005e8c00..0x005e8c23 (zero-initialized .bss,
// filled at runtime). The registry writer at 0040f25d appends at
// [count*4 + 0x005e8c00] with the count at 0x005e8bfc; the parallel registry
// table base at 0x005e8c24 bounds this slice to nine cells. Deeper extent is
// unproven and remains a boundary.
extern void* route_object_registry_table_005e8c00[9u];

// Owned original .bss cells written by 00468fb0: the 0x38-byte scene buffer
// pointer, the transfer slot pointer filled from 0044b960, and the scene flag.
extern void* scene_buffer_0062814c;
extern void* scene_transfer_state_0061976c;
extern std::uint8_t scene_flag_00619800;

// Opaque engine/service callees. Signatures reflect only the observed call
// site ABI (RET immersions verified in the original disassembly); their
// algorithms remain outside this recovery.
void __fastcall view_slot_service_00473100(void* self, void* unused_edx,
                                           std::uint32_t mode);
void __fastcall view_slot_snapshot_00473190(void* self, void* unused_edx,
                                            const void* source);
void __cdecl view_route_counter_00465cf0(std::int32_t index);
void __cdecl view_route_finish_00463c30();

void __cdecl view_teardown_sync_004b7140();
void __cdecl view_teardown_probe_00465e20();
void __fastcall view_teardown_release_00538d80(void* self, void* unused_edx);
void __fastcall view_teardown_release_00540420(void* self, void* unused_edx);
void __fastcall view_teardown_reset_00466500(void* self, void* unused_edx);
void __cdecl view_teardown_finish_0047f190();

void __fastcall scene_reset_00467f40(void* self, void* unused_edx);
void* __fastcall scene_transfer_slot_0044b960(void* self, void* unused_edx);
void __cdecl scene_route_select_00475d70(std::uint32_t from, std::uint32_t to);
void __cdecl scene_route_root_0044fae0(void* root);
void __cdecl scene_route_bind_0045dbd0(void* root, std::uint32_t mode);
void __cdecl scene_stage_reset_00448b10();
void __cdecl scene_stage_reset_0044f240();
void __cdecl scene_stage_reset_00451490();
void __cdecl scene_stage_reset_004552b0();
void __cdecl scene_stage_reset_0043ed00();
void __cdecl scene_stage_reset_00455f60();
void __cdecl scene_stage_reset_00458b80();
void* __cdecl scene_transfer_enter_004521c0();

} // namespace porsche
