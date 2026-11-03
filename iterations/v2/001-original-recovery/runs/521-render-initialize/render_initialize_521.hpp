#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t render_video_mode_005deaa8;
extern std::uint32_t render_video_state_005dead8;
std::uint8_t __cdecl render_driver_initialize_00556bb0(std::uint32_t first,std::uint32_t name,std::uint32_t selected,std::uint32_t mode);
std::uint32_t __cdecl render_input_callback_00560060();
// Exact same534480 algorithm over the existing split canonical descriptor.
std::uint32_t __cdecl render_descriptor_bind_canonical_00534480();
// Six real original children; algorithms deliberately remain strong frontiers.
std::uint32_t __cdecl render_environment_00573030(const char* name,const char* value,std::uint32_t ignored);
std::uint32_t __cdecl render_initialize_library_00575640(std::uint32_t name);
std::uint32_t __cdecl render_initialize_window_00575820(std::uint32_t first);
void __cdecl render_initialize_callbacks_005759f0();
void __cdecl render_initialize_service_0053c8e0();
std::uint32_t __cdecl render_input_dispatch_00586cd0(std::uint32_t event);
}
