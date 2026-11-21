#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t scene_blur_matrix_0061bc78[8];
extern std::uint32_t* scene_blur_clock_0061bcac;
extern void* scene_blur_program_0061bcb0;
extern void* scene_blur_mode_0061bcb4;
extern void* scene_blur_resource_0061bcb8;

void* __fastcall scene_blur_program_ctor_00468240(void* self, void* unused_edx,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e);
void __fastcall scene_blur_program_setup_004685e0(void* self, void* unused_edx,
    std::uint32_t a, std::uint32_t b, std::uint32_t c,
    std::uint32_t d, std::uint32_t e, std::uint32_t f);
void* __fastcall scene_mode_ctor_005379f0(void* self, void* unused_edx);
void __fastcall scene_mode_set_00537a50(void* self, void* unused_edx, std::uint32_t value);
void __cdecl scene_stage_reset_00451490();

// Scoped production binding: sole original caller00468fb0, immediately after
// 451490/44d320/44b830 left the exact four scratch-stack bytes zero. Standalone
// arbitrary-stack behavior is retained only by the explicit Run721 input core.
void __cdecl scene_stage_reset_004552b0();
}
