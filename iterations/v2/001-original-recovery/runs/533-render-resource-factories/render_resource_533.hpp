#pragma once
#include <cstdint>
namespace porsche {
extern std::uint8_t render_resource_texture_fallback_0069dd1c;
extern const std::uint32_t render_resource_table_005bb6c8[3];
void* __fastcall render_resource_bound_child_ctor_00535b50(void*,void*,void* driver);
void* __fastcall render_resource_destroy_00535ba0(void*,void*,std::uint32_t flags);
void* __fastcall render_resource_create_00536180(void*,void*,const void* descriptor,std::uint32_t flags,const char* name);
void* __fastcall render_resource_create_pair_005361e0(void*,void*,const void* first,const void* second,std::uint32_t flags,const char* name);
// Actual original children; flags and signed stage domains remain unresolved.
void* __fastcall render_resource_node_ctor_00535bc0(void*,void*,const void*,void* parent,std::uint32_t flags,const char* name);
void* __fastcall render_resource_node_empty_ctor_00535ed0(void*,void*,void* parent,std::uint32_t flags,const char* name);
void* __fastcall render_resource_node_pair_ctor_00535d80(void*,void*,const void*,const void*,void* parent,std::uint32_t flags,const char* name);
}
