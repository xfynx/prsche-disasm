// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a66b0..004a683d, 398 bytes, sha256 a9ac30a2e2c2ddb8191cf4198eaf8c3932d6f3f4f2bbc5e7238cf3ce3b297e91.
// Owns 128-byte .rdata table 005b4ac0..005b4b3f, sha256 1971f9131f19a90589aa38b61716f75b521469ab8ef7799874f5de89f991ef01.
#include "application_audio_init_625.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

// Immutable source bytes covering 005b4ac0..005b4b3f. 004a66b0 indexes the
// table bases at 005b4ae4, 005b4af0, 005b4afc, 005b4b08, 005b4b14,
// 005b4b20, and 005b4b2c with a four-byte stride. Keep the surrounding bytes
// so negative mode indices down to -8 preserve the original adjacent reads.
extern const std::uint8_t application_audio_mode_data_005b4ac0[0x80] = {
    0x66,0x66,0x46,0x41,0x78,0x52,0x5c,0x00,0x80,0x56,0x4a,0x00,0x60,0x56,0x4a,0x00,
    0x70,0x56,0x4a,0x00,0xc0,0x52,0x5c,0x00,0x80,0x56,0x4a,0x00,0x60,0x56,0x4a,0x00,
    0x70,0x56,0x4a,0x00,0x00,0x7d,0x00,0x00,0x22,0x56,0x00,0x00,0x80,0x3e,0x00,0x00,
    0x20,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
    0x10,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
    0x0c,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x14,0x00,0x00,0x00,0x32,0x00,0x00,0x00,
    0x64,0x00,0x00,0x00,0x3c,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x91,0x00,0x00,0x00,
    0x91,0x00,0x00,0x00,0x91,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x40
};

namespace {

constexpr std::uint32_t kAudioModeDataVa = 0x005b4ac0u;

std::size_t table_offset(std::uint32_t table_va, std::int32_t mode,
    std::size_t width) noexcept {
    const auto address = static_cast<std::int64_t>(table_va) +
        static_cast<std::int64_t>(mode) * 4;
    const auto offset = address - static_cast<std::int64_t>(kAudioModeDataVa);
    if (offset < 0 || static_cast<std::uint64_t>(offset) + width >
        sizeof(application_audio_mode_data_005b4ac0)) {
        return 0u;
    }
    return static_cast<std::size_t>(offset);
}

std::uint8_t table_byte(std::uint32_t va, std::int32_t mode) noexcept {
    return application_audio_mode_data_005b4ac0[table_offset(va, mode, 1u)];
}

std::uint32_t table_dword(std::uint32_t va, std::int32_t mode) noexcept {
    const auto offset = table_offset(va, mode, 4u);
    return static_cast<std::uint32_t>(application_audio_mode_data_005b4ac0[offset]) |
        (static_cast<std::uint32_t>(application_audio_mode_data_005b4ac0[offset + 1u]) << 8u) |
        (static_cast<std::uint32_t>(application_audio_mode_data_005b4ac0[offset + 2u]) << 16u) |
        (static_cast<std::uint32_t>(application_audio_mode_data_005b4ac0[offset + 3u]) << 24u);
}

std::int32_t signed_dword(std::uint32_t value) noexcept {
    std::int32_t result{};
    std::memcpy(&result, &value, sizeof(result));
    return result;
}

std::uint16_t get_u16(const AudioInitDescriptor& descriptor, std::size_t offset) noexcept {
    return static_cast<std::uint16_t>(descriptor[offset]) |
        static_cast<std::uint16_t>(static_cast<std::uint16_t>(descriptor[offset + 1u]) << 8u);
}

void put_u16(AudioInitDescriptor& descriptor, std::size_t offset, std::uint16_t value) noexcept {
    descriptor[offset] = static_cast<std::uint8_t>(value);
    descriptor[offset + 1u] = static_cast<std::uint8_t>(value >> 8u);
}

} // namespace

std::uint8_t __cdecl application_audio_probe_initialize_004a66b0() {
    const std::int32_t mode =
        signed_dword(application_state_006573e8.word(0x00657c98u));
    application_audio_prepare_00565950();

    AudioInitDescriptor descriptor{};
    if (application_audio_query_config_00565680(descriptor.data()) < 0) {
        application_audio_device_configured_00655d40 = 0u;
        return 0u;
    }

    if (mode < 3) {
        const std::uint32_t gate =
            application_state_006573e8.word(0x00657c9cu);
        put_u16(descriptor, 0x18u, 0x0040u);
        descriptor[0x27u] = 1u;
        descriptor[0x28u] = 0x24u;
        descriptor[0x1fu] = 0u;
        application_audio_device_configured_00655d40 = 0u;
        descriptor[0x1du] = table_byte(0x005b4b08u, mode);
        descriptor[0x23u] = 0u;

        if (gate != 0u && descriptor[0x08u] != 0u) {
            const std::int32_t count = static_cast<std::int32_t>(descriptor[0x0au]);
            if (count > 0) {
                const std::uint32_t mask = table_dword(0x005b4b2cu, mode);
                for (std::int32_t i = 0; i < count; ++i) {
                    const std::uint8_t candidate =
                        descriptor[0x0bu + static_cast<std::size_t>(i)];
                    if ((static_cast<std::uint32_t>(candidate) & mask) == mask) {
                        const std::int32_t cap =
                            signed_dword(table_dword(0x005b4af0u, mode));
                        descriptor[0x27u] = 2u;
                        descriptor[0x29u] = 0x24u;
                        descriptor[0x28u] = candidate;
                        application_audio_device_configured_00655d40 = 1u;
                        std::int32_t sample_count =
                            static_cast<std::int32_t>(descriptor[0x08u]);
                        if (sample_count > cap) {
                            sample_count = cap;
                        }
                        descriptor[0x1fu] = static_cast<std::uint8_t>(sample_count);
                        const std::uint8_t range = static_cast<std::uint8_t>(
                            table_byte(0x005b4afcu, mode) - descriptor[0x1fu] +
                            table_byte(0x005b4af0u, mode));
                        descriptor[0x23u] = 1u;
                        descriptor[0x1du] = range;
                        break;
                    }
                }
            }
        }

        descriptor[0x25u] = table_byte(0x005b4b20u, mode);
        descriptor[0x21u] = table_byte(0x005b4b14u, mode);
        const std::int32_t maximum =
            signed_dword(table_dword(0x005b4ae4u, mode));
        const std::int32_t requested =
            static_cast<std::int32_t>(get_u16(descriptor, 0x02u));
        std::uint16_t adjusted = static_cast<std::uint16_t>(requested);
        if (maximum <= requested) {
            adjusted = static_cast<std::uint16_t>(maximum);
        }
        put_u16(descriptor, 0x1au, adjusted);
        descriptor[0x1cu] = 2u;
        descriptor[0x24u] = 0u;
        descriptor[0x22u] = 0u;
    }

    application_audio_apply_config_005656d0(descriptor.data());
    const std::int32_t result = application_audio_create_device_00565720(
        application_audio_buffer_00655d44, 0x40000u, 3u);
    if (result < 0) {
        return 0u;
    }

    if (mode < 2) {
        if (application_audio_device_configured_00655d40 != 0u) {
            const std::int32_t rate = signed_dword(timer_rate_005deb48);
            const std::int32_t interval = rate / 2;
            application_audio_wait_0053c380(interval);
        }
        application_audio_post_setup_004ab470();
    }
    return 1u;
}

} // namespace porsche
