// Fixture-only callers exercising the canonical 005712f0 ABI binding.
#include <cstdint>
#include "bindings.hpp"
#include "../817-splash-draw-sprite/sprite_draw_817.hpp"

extern "C" std::int32_t __cdecl call_row_stride_822(const void* shape) {
    return porsche::render_shape_row_stride_005712f0(shape);
}

extern "C" void* __cdecl row_stride_addr_822() {
    return reinterpret_cast<void*>(&porsche::render_shape_row_stride_005712f0);
}
