#pragma once
#include <cstdint>

namespace porsche {
// Active startup table at 005e4700: +4=00531f70, +8=00531f90.
void* __cdecl application_allocator_entry_00531f70(const char* source,
    std::uint32_t bytes,std::uint32_t heap_index);
void* __cdecl startup_network_allocate_0059ef90(std::uint32_t bytes);
void* __cdecl application_allocate_in_heap_0059efc0(std::uint32_t bytes,std::uint32_t heap_index);
void* __cdecl application_allocate_array_0059eff0(std::uint32_t bytes);
void* __cdecl application_allocate_array_in_heap_0059f020(std::uint32_t bytes,std::uint32_t heap_index);
std::uint32_t __cdecl application_release_0059f050(void* address);
}
