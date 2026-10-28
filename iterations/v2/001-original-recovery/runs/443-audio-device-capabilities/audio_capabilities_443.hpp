#pragma once
#include <cstdint>
namespace porsche {
extern std::uint32_t audio_ds_device_006ad760;
extern std::uint32_t audio_ds_primary_006ad764;
extern std::uint8_t audio_ds_hardware_006ad778;
extern std::int8_t audio_ds_property_available_006ad779;
extern std::uint32_t audio_ds_property_006aefdc;
extern std::uint32_t audio_ds_temporary_006aefe0;
extern const std::uint8_t audio_property_interface_guid_005bfd40[16];
extern const std::uint8_t audio_property_set_guid_005c17d8[16];
std::int32_t __cdecl audio_probe_capabilities_0058e650(
    std::uint32_t* capacity,std::int32_t* property_available);
std::uint32_t __cdecl audio_active_window_0058f860();
void __cdecl audio_probe_property_0058ea90(std::uint32_t query_support);
void __cdecl audio_release_property_0058eba0();
// Original DSOUND ordinal1 thunk at00597f70: stdcall3, not cdecl0.
std::int32_t __stdcall audio_direct_sound_create_00597f70(
    const void* device_guid,std::uint32_t* object,void* outer);
// Modern platform transport for the two original USER32 IAT slots.
void* __stdcall audio_platform_foreground_window();
void* __stdcall audio_platform_desktop_window();
}
