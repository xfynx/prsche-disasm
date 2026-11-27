// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

static_assert(sizeof(void*) == 4, "original x86 pointer ABI");

// Loader-zero pointer snapshots. The first array is bounded by the second
// base, and the second by the count cell at 005e8bd0: nine DWORDs each.
extern std::uint32_t frame_reset_order_table_005e8b88[9u];
extern std::uint32_t frame_reset_pair_table_005e8bac[9u];

// Loader-zero secondary-player table. Its next independent cells begin at
// 005e8e24, leaving 0x200 bytes / 128 DWORD slots at 005e8c24..005e8e23.
extern std::uint32_t frame_reset_secondary_table_005e8c24[128u];

// Existing Run400 caller declaration uses this exact symbol.
void __cdecl frame_reset_service_004110a0();

// Direct child remains a typed frontier. The original caller pushes index,
// then object, and performs caller cleanup of both arguments.
void __cdecl frame_player_reset_00410730(std::uint32_t object,
                                         std::int32_t index);

} // namespace porsche
