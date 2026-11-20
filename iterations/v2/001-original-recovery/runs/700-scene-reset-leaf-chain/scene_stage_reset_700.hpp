// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run700 packet: two bounded scene-stage reset leaves newly exposed by the
// integrated Run693 view lifecycle. The exported symbols are the exact names
// the accepted caller (application_view_lifecycle_693.cpp, 00468fb0) resolves.
#pragma once

#include <cstdint>

namespace porsche {

// Accepted caller declarations (must match 693 exactly; do not redefine).
void __cdecl scene_stage_reset_00458b80();
void __fastcall scene_reset_00467f40(void* self, void* unused_edx);

// Owned original .bss cell 0x00627e08: the constructed stage-58b80 object.
extern void* scene_stage_58b80_00627e08;

// Owned original .rdata strings, exact raw PE bytes (42 bytes each, NUL
// terminated). 00467f40 passes these as the format argument of 005a177b.
extern const char texture_alloc_ok_005cf848[42u];
extern const char texture_alloc_fail_005cf81c[42u];

// Opaque engine callees. Signatures describe only the observed call-site ABI;
// their algorithms remain outside this recovery. Canonical providers are
// reused by name (application_alloc.hpp / render_display.hpp); the remaining
// three are declared here and stay unresolved in the game graph.
void* __fastcall scene_stage_58b80_ctor_00458c90(void* self, void* unused_edx);
void __cdecl scene_texture_alloc_report_005a177b(const char* format,
                                                  std::uint32_t size);
void __cdecl scene_texture_callback_005556a0(void* callback);

} // namespace porsche
