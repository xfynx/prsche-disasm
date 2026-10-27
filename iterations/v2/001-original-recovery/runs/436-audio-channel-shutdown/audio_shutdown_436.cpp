// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005659f0..00565ace, 223 bytes, cdecl(int32)->int32.
#include "audio_shutdown_436.hpp"
#include <cstring>

namespace porsche {
namespace {
std::uint16_t state_word(std::size_t offset) {
    std::uint16_t value;
    std::memcpy(&value, application_audio_device_state_006b48c0.data() + offset, 2);
    return value;
}
std::uint32_t state_dword(std::size_t offset) {
    std::uint32_t value;
    std::memcpy(&value, application_audio_device_state_006b48c0.data() + offset, 4);
    return value;
}
template<class T> T read_at(std::uint32_t address) {
    T value;
    std::memcpy(&value, reinterpret_cast<const void*>(address), sizeof(value));
    return value;
}
} // namespace

std::int32_t __cdecl application_audio_stop_channel_005659f0(std::int32_t index) {
    if (application_audio_device_state_006b48c0[0xdc] == 0)
        return -10;
    if (index == -1) {
        // This unsigned group count is distinct from the signed channel count.
        for (std::int32_t child = 0; child < state_word(0x18); ++child)
            (void)application_audio_stop_channel_005659f0(child);
        return 0;
    }
    if (application_audio_validate_channel_00590070(index) != 0)
        return -8;

    audio_backend_lock_005896d0();
    const std::uint32_t group_offset = static_cast<std::uint32_t>(index) * 12u;
    const std::uint32_t captured_table = state_dword(0x144);
    const std::uint32_t captured_header = read_at<std::uint32_t>(
        captured_table + group_offset);
    if (audio_backend_channel_count_006b49a4 > 0) {
        std::uint32_t table = audio_backend_channels_006b4a00;
        std::uint32_t offset = 0;
        std::int32_t slot = 0;
        do {
            if (static_cast<std::int32_t>(read_at<std::int8_t>(table + offset + 0x0e)) == index) {
                (void)audio_channel_stop_00565d60(read_at<std::uint32_t>(table + offset));
                table = audio_backend_channels_006b4a00;
            }
            ++slot;
            offset += 0x70u;
        } while (slot < audio_backend_channel_count_006b49a4);
    }
    const std::uint32_t header_word = read_at<std::uint16_t>(captured_header + 6u);
    (void)application_audio_release_group_00565990(index, header_word);
    const std::uint32_t group = state_dword(0x144) + group_offset;
    const std::uint32_t zero = 0;
    std::memcpy(reinterpret_cast<void*>(group), &zero, sizeof(zero));
    *reinterpret_cast<std::uint8_t*>(group + 8u) = 0;
    audio_backend_unlock_005896f0();
    return 0;
}

// Source-level bridge for the accepted void caller. This is not another
// recovered original function and must not increase original-body counts.
void __cdecl application_audio_shutdown_channels_005659f0(std::int32_t index) {
    (void)application_audio_stop_channel_005659f0(index);
}
} // namespace porsche
