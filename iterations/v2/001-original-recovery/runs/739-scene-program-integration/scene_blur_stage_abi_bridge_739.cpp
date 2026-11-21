// Canonical ABI bridge for Run736 -> Run738 scene_blur_program_stage_00468440.
// Run736 (004685e0) declares parameter 4 as std::uint32_t whereas Run738
// (00468440) defines parameter 4 as void*.
#include "scene_blur_program_736.hpp"
#include "scene_blur_stage_child_738.hpp"

#include <cstdint>

namespace porsche {

void __fastcall scene_blur_program_stage_00468440(
    void* self,
    void* unused_edx,
    std::uint32_t a,
    std::uint32_t b,
    std::uint32_t c,
    std::uint32_t d,
    std::uint32_t e,
    std::uint32_t f) {
    scene_blur_program_stage_00468440(
        self,
        unused_edx,
        a,
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(b)),
        c,
        d,
        e,
        f);
}

}  // namespace porsche
