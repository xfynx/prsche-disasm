#pragma once
#include "porsche/render_objects.hpp"
#include <cstdint>

namespace porsche {
// Win32 Advapi32 call shapes used by the recovered consumers. The fixture can
// inject an in-memory implementation; production defaults to the imported API.
struct RenderRegistryApi {
    std::int32_t (__stdcall *open_key_ex_a)(std::uint32_t,const char*,std::uint32_t,
        std::uint32_t,std::uint32_t*);
    std::int32_t (__stdcall *create_key_a)(std::uint32_t,const char*,std::uint32_t*);
    std::int32_t (__stdcall *close_key)(std::uint32_t);
    std::int32_t (__stdcall *query_value_ex_a)(std::uint32_t,const char*,std::uint32_t*,
        std::uint32_t*,std::uint8_t*,std::uint32_t*);
    std::int32_t (__stdcall *set_value_ex_a)(std::uint32_t,const char*,std::uint32_t,
        std::uint32_t,const std::uint8_t*,std::uint32_t);
};

void __cdecl render_registry_bind_api(const RenderRegistryApi* api);
std::uint32_t __cdecl render_registry_first_result_004b76f0(RenderCore* core);
void __cdecl render_registry_defaults_004b7150(RenderCore* core);

// These names/signatures satisfy the existing startup and native-vtable bridge.
void __cdecl render_core_first_004b76f0(RenderCore* core);
void __cdecl render_registry_activate_004b7220(RenderCore* core);
void __cdecl render_registry_text_004b7240(RenderCore* core,std::uint32_t index,char* out);
std::uint32_t __cdecl render_registry_choice_004b7340(RenderCore* core,std::uint32_t index);
}
