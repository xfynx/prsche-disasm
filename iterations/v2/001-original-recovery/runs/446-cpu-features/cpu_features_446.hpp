#pragma once
#include <cstdint>
namespace porsche {
// Original cdecl0 mask, consumed as a low byte by Run442.
std::uint32_t __cdecl audio_backend_cpu_features_00597070();
// ISA helpers preserve the original extra register/flags contracts.
std::uint32_t __cdecl cpu_id_toggle_0059a4d0();
void __cdecl cpu_query_0059a4ed(std::uint32_t* output,std::uint32_t leaf);
std::int32_t __stdcall cpu_platform_version_446(void* version148);
}
