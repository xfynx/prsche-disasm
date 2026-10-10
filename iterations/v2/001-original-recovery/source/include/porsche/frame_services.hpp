#pragma once

#include <array>
#include <cstdint>

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Raw storage observed at 00656180: the consumers establish a stride of two
// DWORDs across exactly 73 records; field meaning is not inferred here.
extern std::array<std::uint32_t, 146> frame_services_records_00656180;
extern std::uint8_t& frame_services_byte_00656868;
extern std::uint8_t& frame_services_byte_00656869;

// Raw initialized .data values used by the indexed bodies. These views are
// neutral address/type aliases pending recovery of their broader consumers.
extern std::uint32_t frame_services_word_005d14b0;
extern std::array<std::uint32_t, 5>& frame_services_words_005d1740;

// Complete no-argument cdecl bodies. The EAX values are exposed because the
// original leaves the final loaded DWORD in EAX, although indexed callers
// currently treat the functions as void.
std::uint32_t __cdecl frame_services_004ab150();
std::uint32_t __cdecl frame_services_004ab200();

// Unrecovered effect boundaries. Signatures model observed stack arguments;
// internals remain external to this packet.
void __cdecl frame_services_boundary_004af900(std::uint32_t zero0,
                                               std::uint32_t zero1);
std::uint32_t __cdecl frame_services_boundary_00566340(
    std::uint32_t record_word, std::uint32_t zero);
std::uint32_t __cdecl frame_services_boundary_004ae3c0(std::uint32_t zero);
void __cdecl frame_services_boundary_00565cd0(std::uint32_t zero0,
                                               std::uint32_t zero1);
void __cdecl frame_services_boundary_004ad510();
void __cdecl frame_services_boundary_004ae8c0(std::uint32_t shifted_product);
void __cdecl frame_services_boundary_004ae4d0(std::uint32_t zero0,
                                               std::uint32_t zero1);

} // namespace porsche
