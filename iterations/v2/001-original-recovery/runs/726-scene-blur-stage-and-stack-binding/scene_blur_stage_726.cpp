#include "scene_blur_stage_726.hpp"
#include "scene_stage_stack_core_721.hpp"
#include "startup_sequence_resource_table_649.hpp"
#include "porsche/render_startup.hpp"
#include <cstring>

namespace porsche {
std::uint32_t scene_blur_matrix_0061bc78[8]{};
std::uint32_t* scene_blur_clock_0061bcac = nullptr;
void* scene_blur_program_0061bcb0 = nullptr;
void* scene_blur_mode_0061bcb4 = nullptr;
void* scene_blur_resource_0061bcb8 = nullptr;
namespace {
void put(void* base, unsigned offset, std::uint32_t word) {
    std::memcpy(static_cast<unsigned char*>(base) + offset, &word, 4);
}
}
void* __fastcall scene_mode_ctor_005379f0(void* self, void*) {
    put(self, 0u, 1u);
    put(self, 4u, 2u);
    put(self, 8u, 0u);
    put(self, 12u, 0u);
    put(self, 16u, 0u);
    put(self, 20u, 0xffffffffu);
    return self;
}
void __fastcall scene_mode_set_00537a50(void* self, void*, std::uint32_t value) {
    put(self, 8u, value);
}
void __cdecl scene_stage_reset_00451490() {
    void* program = render_allocate_0059ef90(0x28u);
    if (program != nullptr) {
        program = scene_blur_program_ctor_00468240(program, nullptr, 14u, 4u, 1u, 0u, 4u);
    }
    scene_blur_program_0061bcb0 = program;
    scene_blur_program_setup_004685e0(program, nullptr, 0u, 0u, 0u, 0u, 0u, 0u);

    void* mode = render_allocate_0059ef90(0x18u);
    if (mode != nullptr) mode = scene_mode_ctor_005379f0(mode, nullptr);
    scene_blur_mode_0061bcb4 = mode;
    scene_mode_set_00537a50(mode, nullptr, 1u);

    scene_blur_matrix_0061bc78[0] = 0u;
    scene_blur_matrix_0061bc78[1] = 0u;
    scene_blur_matrix_0061bc78[2] = 0x3f800000u;
    scene_blur_matrix_0061bc78[3] = 0u;
    scene_blur_matrix_0061bc78[4] = 0x3f800000u;
    scene_blur_matrix_0061bc78[5] = 0x3f800000u;
    scene_blur_matrix_0061bc78[6] = 0u;
    scene_blur_matrix_0061bc78[7] = 0x3f800000u;
    scene_blur_clock_0061bcac = &startup_sequence_word_00606ac4;
    scene_blur_resource_0061bcb8 = startup_context_table_lookup_0044d320(
        startup_context_table_owner_00613e04, nullptr, 0u, 0x52554c42u);
}
__declspec(naked) void __cdecl scene_stage_reset_004552b0() {
    // Explicit ABI transport; no compiler-frame offsets or epilog register writes.
    __asm {
        push 0
        mov eax, esp
        push eax
        call scene_stage_stack_core_004552b0
        add esp, 8
        xor ecx, ecx
        ret
    }
}
}
