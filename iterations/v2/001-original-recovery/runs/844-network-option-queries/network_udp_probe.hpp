#pragma once
#include <cstdint>

namespace porsche {
extern const char network_udp_excluded_prefixes_005c11d8[12];
extern char network_udp_local_address_006b4a80[];

std::uint32_t __cdecl network_udp_start_005839d0();
std::uint32_t __cdecl network_read_local_address_00583740(char*);
std::int32_t __stdcall network_wsa_startup_005894e6(std::uint16_t, void*);
std::int32_t __stdcall network_wsa_cleanup_005894e0();
std::uint32_t __stdcall network_wsa_socket_00587bd8(std::int32_t, std::int32_t, std::int32_t);
std::int32_t __stdcall network_wsa_close_socket_00587bc0(std::uint32_t);
}
