#pragma once

#include <cstdint>

namespace porsche {

extern std::uint32_t network_shared_context_count_006ad748;
void __cdecl network_shared_context_service_00587cc0();
void __cdecl network_shared_context_receive_00582320(void*, const void*);

std::uint32_t __cdecl network_shared_context_create_00587bf0(
    void* context, const void* identity, const void* transport_guid, std::uint32_t endpoint,
    const char* name, const char* short_name);

} // namespace porsche
