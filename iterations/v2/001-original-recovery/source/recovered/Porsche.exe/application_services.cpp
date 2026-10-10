#include "porsche/application_services.hpp"

#include "porsche/application_heap.hpp"
#include "porsche/application_state.hpp"
#include "porsche/engine_service_427a60.hpp"
#include "porsche/fe_stream.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

std::uint32_t application_audio_config_00655d34 = 0;
std::uint32_t application_audio_mode_00655d38 = 0;
std::uint8_t application_audio_flag_00655d3c = 0;
std::uint32_t application_audio_buffer_00655d44 = 0;
ApplicationAudioRecord006564a0 application_audio_records_006564a0[8]{};
std::uint32_t application_audio_active_005d1734 = 1;

std::uint32_t __cdecl application_main_memory_dialog(const char* text,
                                                       const char* title) {
    return static_cast<std::uint32_t>(
        application_service_message_box_api(text, title));
}

void __cdecl application_main_create_directory(std::uint32_t path_va) {
    const char* path = path_va == 0x0065b360u
        ? engine_service_root_0065b360
        : reinterpret_cast<const char*>(static_cast<std::uintptr_t>(path_va));
    (void)application_service_create_directory_api(path);
}

void __cdecl application_main_setup_heaps(std::uint32_t first,
                                           std::uint32_t second) {
    std::int32_t signed_first{};
    std::memcpy(&signed_first, &first, sizeof(signed_first));
    application_audio_setup_004a6840(signed_first, second);
}

// Porsche.exe 004a6840..004a6956 (279 bytes). Direct state accesses, branch
// order, allocator calls, and cleanup come from the original x86 body. Audio
// device/configuration effects remain typed boundaries.
void __cdecl application_audio_setup_004a6840(std::int32_t first,
                                               std::uint32_t second) {
    auto& arena = application_state_006573e8;
    const auto mode = arena.word(0x00657c98u);
    arena.word(0x00657c9cu) = 0;
    if (mode == 3)
        arena.word(0x00657c94u) = 1;

    application_audio_mode_00655d38 = mode;
    application_audio_flag_00655d3c = 0;
    application_audio_config_00655d34 = static_cast<std::uint32_t>(first);
    application_audio_buffer_00655d44 = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(allocate_00531ca0(
            "audio heap", 0x40000, 0)));

    for (auto& record : application_audio_records_006564a0) {
        record.raw_00 = 0xffffffffu;
        record.raw_08 = 0;
    }

    if (application_audio_probe_initialize_004a66b0() == 0) {
        free_00531f90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(
            application_audio_buffer_00655d44)));
        application_audio_buffer_00655d44 = 0;
        application_audio_flag_00655d3c = 0;
        arena.word(0x00657c9cu) = 0;
        application_audio_config_00655d34 = 0;
        application_audio_active_005d1734 = 0;
        arena.word(0x00657c94u) = 1;
        arena.word(0x00657c98u) = 3;
        application_audio_mode_00655d38 = 3;
        return;
    }

    if (first > 0)
        application_audio_probe_configure_004ae100(
            first, second, 0x005d13f8u);

    if (arena.word(0x00657c94u) == 0) {
        application_audio_active_005d1734 = 1;
        application_audio_probe_start_004a8b80();
        return;
    }

    application_audio_probe_prepare_004ae2b0();
    application_audio_probe_finish_004ab4b0();
    (void)application_audio_probe_measure_00565890();
    free_00531f90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(
        application_audio_buffer_00655d44)));
    application_audio_buffer_00655d44 = 0;
    application_audio_active_005d1734 = 0;
}

} // namespace porsche
