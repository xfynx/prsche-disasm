#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t render_library_cache_0069e5f0[8][45];
extern std::uint32_t render_library_started_006a64b8;
extern const char render_library_environment_005c0e10[18];
void __cdecl render_library_unload_00575600();
std::uint32_t __cdecl render_initialize_library_00575640(std::uint32_t);
std::uint32_t __cdecl render_initialize_shutdown_00575930(std::uint32_t);
// Original timed consumer supplies two cdecl words; this leaf ignores both.
std::uint32_t __cdecl render_library_disable_state_005756c0(std::uint32_t,std::uint32_t);
void __cdecl render_library_cache_restore_00594cd0(std::uint32_t);
std::uint32_t __stdcall render_library_fallback_getstate_00574f80(std::uint32_t);
std::uint32_t __stdcall render_library_fallback_tfree_00574f90(std::uint32_t);
}
