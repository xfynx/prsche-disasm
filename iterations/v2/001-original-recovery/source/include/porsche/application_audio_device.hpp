#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace porsche {

// The original owns a zero-filled state span at 006b48c0. Only offsets
// explicitly touched by 00565680/005656d0/00565720 are interpreted; all gaps
// remain opaque bytes. 006a5c30 is a separate lazy-initialization flag.
struct ApplicationAudioDeviceStateStorage {
    std::array<std::uint8_t, 0x18c> backing{};

    std::uint8_t* data() noexcept { return backing.data() + 0x10; }
    const std::uint8_t* data() const noexcept { return backing.data() + 0x10; }
    std::uint8_t* preceding_data() noexcept { return backing.data(); }
    std::uint8_t& operator[](std::size_t offset) noexcept { return backing[offset + 0x10]; }
    const std::uint8_t& operator[](std::size_t offset) const noexcept {
        return backing[offset + 0x10];
    }
    constexpr std::size_t size() const noexcept { return 0x17c; }
};
static_assert(sizeof(ApplicationAudioDeviceStateStorage) == 0x18c);

extern ApplicationAudioDeviceStateStorage application_audio_device_state_006b48c0;
extern std::uint32_t application_audio_descriptor_initialized_006a5c30;
extern char application_audio_author_text_005e2470[60];
extern char* application_audio_marker_pointer_005e246c;

// Complete original bodies; backend/device effects remain explicit boundaries.
std::int32_t __cdecl application_audio_query_config_00565680(
    std::uint8_t* descriptor_124_bytes);
std::uint32_t __cdecl application_audio_apply_config_005656d0(
    const std::uint8_t* descriptor_124_bytes);
std::int32_t __cdecl application_audio_create_device_00565720(
    std::uint32_t buffer_va, std::uint32_t buffer_bytes,
    std::uint32_t device_flags);

// Typed boundaries for still-unrecovered audio/backend callees.
std::int32_t __cdecl application_audio_backend_initialize_0058a4f0();
void __cdecl application_audio_backend_apply_0058a690();
void __cdecl application_audio_backend_configure_0058fef0(
    std::uint32_t buffer_va, std::uint32_t buffer_bytes);
void __cdecl application_audio_backend_configure_0058aa90(
    std::uint32_t buffer_va, std::uint32_t buffer_bytes);
std::uint32_t __cdecl application_audio_backend_allocate_0058aae0(
    std::uint32_t bytes);
void __cdecl application_audio_backend_start_0058e2d0();
std::int32_t __cdecl application_audio_backend_start_device_0058fdb0();
void __cdecl application_audio_backend_stop_device_0058fe80();
void __cdecl application_audio_backend_stop_0058e2e0();
void __cdecl application_audio_backend_finalize_0058e0e0();

inline constexpr std::size_t kApplicationAudioDeviceStateBytes = 0x17c;
static_assert(kApplicationAudioDeviceStateBytes == 0x17c);
static_assert(sizeof(void*) == 4, "original audio marker pointer is x86");

} // namespace porsche
