#pragma once
#include "render_resource_node_536.hpp"
#include <cstdint>
namespace porsche {
// Original554bd0 proves32 normal48B slots. Corrupt/out-of-range indices are
// unchecked, as in554de0; this array does not introduce a runtime validity rule.
extern std::uint8_t render_texture_slots_006a33f8[32*48];
extern const char render_palette_message_005bb81c[41];
extern const char render_palette_file_005bb848[19];
// Real unaccepted original children remain strongly unresolved.
void __cdecl render_resource_texture_destroy_00554cc0(void* texture);
std::uint32_t __cdecl render_descriptor_read_be_0056e290(const void* source,std::uint32_t count);
}
