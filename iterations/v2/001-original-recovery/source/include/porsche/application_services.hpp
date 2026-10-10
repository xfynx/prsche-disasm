#pragma once

#include <cstdint>

namespace porsche {

// Direct app_main service calls whose exact imports are visible in the
// original 004b6a50 body.
std::uint32_t __cdecl application_main_memory_dialog(const char* text,
                                                       const char* title);
void __cdecl application_main_create_directory(std::uint32_t path_va);

// app_main's two-DWORD setup boundary calls the recovered original
// 004a6840 audio setup body (the first value is signed by its comparisons).
void __cdecl application_main_setup_heaps(std::uint32_t first,
                                           std::uint32_t second);
void __cdecl application_audio_setup_004a6840(std::int32_t first,
                                               std::uint32_t second);

struct ApplicationAudioRecord006564a0 {
    std::uint32_t raw_00;
    std::uint32_t opaque_04;
    std::uint32_t raw_08;
    std::uint32_t opaque_0c;
};
static_assert(sizeof(ApplicationAudioRecord006564a0) == 0x10);

extern std::uint32_t application_audio_config_00655d34;
extern std::uint32_t application_audio_mode_00655d38;
extern std::uint8_t application_audio_flag_00655d3c;
extern std::uint32_t application_audio_buffer_00655d44;
extern ApplicationAudioRecord006564a0 application_audio_records_006564a0[8];
extern std::uint32_t application_audio_active_005d1734;

// Typed unresolved audio effects called by 004a6840. Their implementations
// remain external; probes control their return values and record their calls.
std::uint8_t __cdecl application_audio_probe_initialize_004a66b0();
void __cdecl application_audio_probe_configure_004ae100(
    std::int32_t first, std::uint32_t second, std::uint32_t config_va);
void __cdecl application_audio_probe_start_004a8b80();
void __cdecl application_audio_probe_prepare_004ae2b0();
void __cdecl application_audio_probe_finish_004ab4b0();
std::int32_t __cdecl application_audio_probe_measure_00565890();

// Exact Win32 API facade. Production binds these to USER32/KERNEL32; the
// isolated probe substitutes capture functions and does not touch the host.
std::int32_t __cdecl application_service_message_box_api(
    const char* text, const char* title);
std::int32_t __cdecl application_service_create_directory_api(
    const char* path);

} // namespace porsche
