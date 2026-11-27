// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "world_row_reset_872.hpp"
#include "../821-scene-stage-58b80-ctor/scene_stage_58b80_ctor_821.hpp"
#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
using Byte = unsigned char;

void copy_vector(Byte* destination, const void* source) {
    const auto* bytes = static_cast<const Byte*>(source);
    // The original interleaves reads and writes, including for overlapping vectors.
    for (unsigned offset = 0; offset < 12; offset += 4) {
        std::uint32_t component;
        std::memcpy(&component, bytes + offset, 4);
        std::memcpy(destination + offset, &component, 4);
    }
}
}

void __fastcall session_world_row_reset_00478d90(
    void* row, void*, const void* first, const void* second, const void* third, std::uint32_t value) {
    auto* bytes = static_cast<Byte*>(row);
    std::memcpy(bytes + 0x34, &value, 4);
    copy_vector(bytes, first);
    copy_vector(bytes + 0x0c, second);
    copy_vector(bytes + 0x18, third);

    float first_x, third_x, squared;
    std::memcpy(&first_x, bytes, 4);
    std::memcpy(&third_x, bytes + 0x18, 4);
    __asm {
        fld third_x
        fsub first_x
        fld st(0)
        fmul st, st(1)
        fadd st, st
        fstp squared
        fstp st(0)
    }
    const float distance = static_cast<float>(math_fsqrt_005327d0(squared));
    std::memcpy(bytes + 0x30, &distance, 4);
    std::memcpy(bytes + 0x24, bytes, 4);
    std::memset(bytes + 0x28, 0, 4);
    std::memcpy(bytes + 0x2c, bytes + 8, 4);
    const std::uint32_t tail[6] = {0, 0x14, 0, 0, 0, 0};
    std::memcpy(bytes + 0x38, tail, sizeof tail);
}
}
