#pragma once
#include <cstdint>
namespace porsche {
struct FrameControlSlotFields_494 {
    std::uint32_t active,device,state;
};
// Semantic cells only: original VA 0069cb90+0x90*i+{0,8,12}. No host full-record
// pointer is an original pointer. Reserved/gap bytes, including 0069dd14/18/1d,
// remain outside this owner. Future producers must reuse/unify these views.
extern FrameControlSlotFields_494 frame_control_slot_fields_494[32];
void __cdecl frame_control_slot_release_005338d0(std::int32_t slot);
std::uint32_t __cdecl render_resource_total_phys_0053c3d0();
void __cdecl render_display_texture_reset_0053c3d0();
std::uint32_t __cdecl render_resource_release_texture_00533f80(void* texture);
void __cdecl render_display_release_texture_00533f80(void* texture);
void __cdecl splash_progress_release_texture_00533f80(std::uint32_t texture);
// The original has two stack arguments. No one-argument compatibility shim.
void __cdecl render_display_present_0044e870(std::uint32_t result,std::uint32_t read_ok);
void __stdcall render_resource_global_memory_status_005b2140(void* status);
}
