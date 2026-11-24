// Fixture-only callers exercising the canonical 005a177b ABI bindings.
#include <cstdint>
#include "bindings.hpp"

namespace porsche {
void __cdecl render_display_texture_report_005a177b(const char* format, std::uint32_t value);
void __cdecl scene_texture_alloc_report_005a177b(const char* format, std::uint32_t value);
}

extern "C" void __cdecl call_render_report_815(const char* format, std::uint32_t value) {
    porsche::render_display_texture_report_005a177b(format, value);
}

extern "C" void __cdecl call_scene_report_815(const char* format, std::uint32_t value) {
    porsche::scene_texture_alloc_report_005a177b(format, value);
}

extern "C" void* __cdecl render_report_addr_815() {
    return reinterpret_cast<void*>(&porsche::render_display_texture_report_005a177b);
}

extern "C" void* __cdecl scene_report_addr_815() {
    return reinterpret_cast<void*>(&porsche::scene_texture_alloc_report_005a177b);
}
