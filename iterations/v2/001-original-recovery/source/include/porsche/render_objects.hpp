#pragma once
#include "porsche/render_startup.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstdint>

namespace porsche {
// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// 0x467700..0x46771f is complete. This raw entry retains its original x86 vptr word.
void* __cdecl render_construct_core_raw_00467700(void* object,
    const char* publisher,const char* title);

// Native bridge for render_startup's C++ virtual dispatch. The original vtable
// word is replaced by MSVC's native table only after the raw constructor runs.
// Slot zero forwards to the still-unrecovered original 0x4b76f0 boundary.
void __cdecl render_core_first_004b76f0(RenderCore* core);

// Exact prefix of 0x4677e0 through the CALL at 0x467844, stopping before
// GetDesktopWindow at 0x46784f. Not a full display constructor.
void __cdecl render_display_prefix_004677e0(RenderDisplay* object,
    const char* name,std::uint32_t selected,std::uint32_t flags,
    const char* resolution);
void __cdecl render_display_member_00466380(void* member);
std::uint32_t __cdecl render_clock_00555bc0();
}
