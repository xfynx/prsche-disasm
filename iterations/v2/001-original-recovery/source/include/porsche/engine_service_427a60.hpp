#pragma once

#include <cstdint>

namespace porsche {

// The original consumer reads this pointer cell at 0065b360. Its production
// storage owner has not yet been identified in the recovered source tree.
extern const char*& engine_service_root_0065b360;

// Complete linear caller at 00427a60. External file/resource/UI algorithms
// remain their existing typed boundaries.
void __cdecl engine_service_00427a60();

// Unrecovered leaf boundaries called by this consumer. Return values are
// modeled only where the original consumes them.
std::int32_t __cdecl engine_service_file_exists_0059dd00(const char* path);
void __cdecl engine_service_consume_resource_0048cb50(
    std::uint32_t zero, void* resource, std::int32_t file_exists);

} // namespace porsche
