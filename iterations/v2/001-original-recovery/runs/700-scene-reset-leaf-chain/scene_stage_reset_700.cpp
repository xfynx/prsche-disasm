// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run700: recovered bodies 00458b80 (38B) and 00467f40 (77B).
//
// Original body SHA-256 (raw PE file bytes, verified by the native runner):
//   00458b80 5f7024df69e4e24bea2fed2dabca34ba7fce328375c3c03623099688d65719c2
//   00467f40 5ccc6766cf272339e922c9f87b794b28a1e8ee8b1917ee69daad8a0e85b9731b
#include "scene_stage_reset_700.hpp"

#include "porsche/render_display.hpp"
#include "porsche/render_startup.hpp"

namespace porsche {

void* scene_stage_58b80_00627e08 = nullptr;

const char texture_alloc_ok_005cf848[42u] = {
    0x49u, 0x6eu, 0x63u, 0x72u, 0x65u, 0x61u, 0x73u, 0x65u, 0x64u, 0x20u,
    0x74u, 0x65u, 0x78u, 0x74u, 0x75u, 0x72u, 0x65u, 0x20u, 0x61u, 0x6cu,
    0x6cu, 0x6fu, 0x63u, 0x61u, 0x74u, 0x69u, 0x6fu, 0x6eu, 0x20u, 0x70u,
    0x61u, 0x73u, 0x73u, 0x65u, 0x64u, 0x20u, 0x5bu, 0x25u, 0x64u, 0x5du,
    0x0au, 0x00u};
const char texture_alloc_fail_005cf81c[42u] = {
    0x49u, 0x6eu, 0x63u, 0x72u, 0x65u, 0x61u, 0x73u, 0x65u, 0x64u, 0x20u,
    0x74u, 0x65u, 0x78u, 0x74u, 0x75u, 0x72u, 0x65u, 0x20u, 0x61u, 0x6cu,
    0x6cu, 0x6fu, 0x63u, 0x61u, 0x74u, 0x69u, 0x6fu, 0x6eu, 0x20u, 0x46u,
    0x41u, 0x49u, 0x4cu, 0x45u, 0x44u, 0x20u, 0x5bu, 0x25u, 0x64u, 0x5du,
    0x0au, 0x00u};

// 00458b80..00458ba5. Allocates a 0x10-byte stage object, constructs it via
// the opaque 00458c90 `this` call, and publishes the returned pointer. The
// original writes zero on allocation failure.
void __cdecl scene_stage_reset_00458b80() {
    void* stage = render_allocate_0059ef90(0x10u);
    if (stage != nullptr) {
        stage = scene_stage_58b80_ctor_00458c90(stage, nullptr);
        scene_stage_58b80_00627e08 = stage;
    } else {
        scene_stage_58b80_00627e08 = nullptr;
    }
}

// 00467f40..00467f8c. thiscall(this = display) with an unused EDX; the
// original never reads ECX/EDX. Resets the texture pool, attempts to reserve
// 0x1800000 bytes, reports the result with the matching original .rdata
// string, and installs the fixed 0x004677d0 callback. No original global is
// written by this body.
void __fastcall scene_reset_00467f40(void* self, void* unused_edx) {
    (void)self;
    (void)unused_edx;
    render_display_texture_reset_0053c3d0();
    const int reserved =
        render_display_texture_reserve_00553fc0(0x01800000u);
    if (reserved != 0) {
        scene_texture_alloc_report_005a177b(texture_alloc_ok_005cf848,
                                             0x01800000u);
    } else {
        scene_texture_alloc_report_005a177b(texture_alloc_fail_005cf81c,
                                             0x01800000u);
    }
    scene_texture_callback_005556a0(reinterpret_cast<void*>(0x004677d0u));
}

} // namespace porsche
