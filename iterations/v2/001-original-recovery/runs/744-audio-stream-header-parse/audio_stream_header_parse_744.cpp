// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00561900..00561950, 81 bytes, sha256 a0dd4bc847d8f676477cad8a482f7dbd4d1486c8d73a15c2e2294f64405fa775.
// Original 00590ef0..00590f63, 116 bytes, sha256 55f41f84cd6acbf0d8566b3907a7bd6598c3d31284b04c899848ebf44cb13adc.
// Original 00590f70..005912d6, 871 bytes, sha256 218d61a3188611e419dc12bc56b359fd23b3decd345949ee87b13bf867f5c5cb.
// Original 00599720..00599756, 55 bytes, sha256 696f4431bf114c2ad5bbe778e5b96ad4082718fb40dbc902e7e970042d72c4bd.
#include "audio_stream_header_parse_744.hpp"

#include <cstring>

namespace porsche {

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline std::uint16_t read_u16(U addr) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u16(U addr, std::uint16_t value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline B read_u8(U addr) noexcept {
    B value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u8(U addr, B value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline I sar_8(U value) noexcept {
    const U shifted = (value & 0x80000000u) != 0u ? ((value >> 8u) | 0xff000000u) : (value >> 8u);
    return static_cast<I>(shifted);
}

} // namespace

std::uint32_t __cdecl audio_stream_info_init_00561900(void* info) {
    const U info_va = va_from_ptr(info);
    write_u16(info_va + 0x00u, 0u);
    write_u8(info_va + 0x02u, 0u);
    write_u8(info_va + 0x03u, 0x7fu);
    write_u8(info_va + 0x04u, 0x40u);
    write_u8(info_va + 0x05u, 0u);
    write_u8(info_va + 0x06u, 0u);
    write_u8(info_va + 0x07u, 0u);
    write_u8(info_va + 0x08u, 0u);
    for (U k = 0u; k < 4u; ++k) {
        write_u32(info_va + 0x34u + k * 4u, 0u);
        write_u32(info_va + 0x44u + k * 4u, 0u);
    }
    for (U k = 0u; k < 4u; ++k) {
        write_u16(info_va + 0x0cu + k * 2u, 0u);
        write_u32(info_va + 0x14u + k * 4u, 0u);
    }
    return 0u;
}

std::int32_t __cdecl audio_stream_header_byte_rate_00590ef0(const void* header) {
    const U header_va = va_from_ptr(header);
    const U channels = read_u8(header_va + 0x02u);
    const U sample_rate = read_u16(header_va + 0x00u);
    const U codec_mode = read_u8(header_va + 0x03u);
    const U product = channels * sample_rate;

    U factor = 0u;
    if (codec_mode == 3u || codec_mode == 10u) {
        factor = 0x88u;
    } else if (codec_mode == 4u) {
        factor = 0x33u;
    } else if (codec_mode == 2u || codec_mode == 9u) {
        factor = 0x100u;
    } else if (codec_mode == 0u || codec_mode == 8u) {
        factor = 0x200u;
    }
    return sar_8(product * factor);
}

std::uint32_t __cdecl audio_stream_codec_from_format_00599720(
    std::uint32_t format_tag,
    std::uint32_t bits_per_sample) {
    if (format_tag == 0u) {
        if (bits_per_sample == 16u) {
            return 0u;
        }
        if (bits_per_sample == 8u) {
            return 2u;
        }
        return 0u;
    }
    if (format_tag == 7u) {
        return 3u;
    }
    if (format_tag == 9u) {
        return 4u;
    }
    return 0u;
}

std::uint32_t __cdecl audio_stream_header_parse_00590f70(
    const void* data,
    void* header,
    void* info,
    std::uint32_t* out_flags) {
    const U data_va = va_from_ptr(data);
    const U header_va = va_from_ptr(header);
    const U info_va = va_from_ptr(info);

    U raw_flags = 0u;
    U bits_per_sample = 16u;
    U format_tag = 0u;
    U explicit_flags = 0u;
    U base_vol[4] = {};

    for (U k = 0u; k < 4u; ++k) {
        write_u32(info_va + 0x14u + k * 4u, 0u);
        write_u32(info_va + 0x24u + k * 4u, 0u);
    }
    (void)audio_stream_info_init_00561900(info);

    U token_state[6] = {};
    token_state[0] = data_va + ((read_u8(data_va + 3u) & 2u) != 0u ? 8u : 4u);

    write_u16(header_va + 0x00u, 0x5622u);
    write_u8(header_va + 0x02u, 1u);
    write_u8(header_va + 0x03u, 10u);
    if (out_flags != nullptr) {
        *out_flags = 0u;
    }

    U env_cursor = info_va + 0x44u;
    while (audio_token_read_00599760(token_state) != 0) {
        const U tag = token_state[1];
        const U val = token_state[2];
        switch (tag) {
            case 0x81u:
                bits_per_sample = val;
                break;
            case 0x83u:
                format_tag = val;
                break;
            case 0xa0u:
                write_u8(header_va + 0x03u, static_cast<B>(val));
                break;
            case 0x9cu:
            case 0x9du:
            case 0x9eu:
            case 0x9fu:
                base_vol[tag - 0x9cu] = val;
                break;
            case 0x98u:
            case 0x99u:
            case 0x9au:
            case 0x9bu: {
                const U slot = tag - 0x98u;
                const U payload = token_state[3];
                const U len = token_state[4];
                const U alloc = application_audio_backend_allocate_0058aae0(len);
                write_u32(info_va + 0x14u + slot * 4u, alloc);
                (void)audio_stream_copy_forward_00598a50(alloc, payload, len);
                write_u32(info_va + 0x24u + slot * 4u, len);
                break;
            }
            case 0x80u:
                write_u8(info_va + 0x07u, static_cast<B>(val));
                break;
            case 0x82u:
                write_u8(header_va + 0x02u, static_cast<B>(val));
                break;
            case 0x84u:
                write_u16(header_va + 0x00u, static_cast<std::uint16_t>(val));
                break;
            case 0x85u:
                *out_flags = val;
                break;
            case 0x13u:
                write_u8(info_va + 0x05u, static_cast<B>(val));
                break;
            case 0x0au:
                write_u8(info_va + 0x06u, static_cast<B>(val));
                break;
            case 0x06u:
                write_u8(info_va + 0x02u, static_cast<B>(val));
                break;
            case 0x8cu:
                explicit_flags = val & 0xffu;
                break;
            case 0xa1u:
                raw_flags = val & 0xffu;
                break;
            case 0x14u:
                write_u32(env_cursor - 0x10u, token_state[3]);
                write_u32(env_cursor, token_state[4]);
                env_cursor += 4u;
                break;
            default:
                break;
        }
    }

    if (raw_flags != 0u && explicit_flags == 0u) {
        explicit_flags = 0u;
        if ((raw_flags & 0x01u) != 0u) {
            explicit_flags = 1u;
        }
        if ((raw_flags & 0x02u) != 0u) {
            explicit_flags |= 2u;
        }
        if ((raw_flags & 0x80u) != 0u) {
            explicit_flags |= 0x20u;
        }
        if ((raw_flags & 0x40u) != 0u) {
            explicit_flags |= 0x40u;
        }
    }

    write_u8(info_va + 0x08u, static_cast<B>(explicit_flags));
    const I channels = static_cast<I>(read_u8(header_va + 0x02u));
    for (I ch = 0; ch < channels; ++ch) {
        const std::uint16_t base = static_cast<std::uint16_t>(base_vol[ch] & 0xffffu);
        std::uint16_t final_val = base;
        if (channels != 2 || application_audio_device_state_006b48c0[0x1cu] != 2u) {
            const U table_idx = static_cast<U>(ch + channels * 4);
            const U adj_off = 0x154u + table_idx * 2u;
            const std::uint16_t adj = static_cast<std::uint16_t>(
                static_cast<U>(application_audio_device_state_006b48c0[adj_off]) |
                (static_cast<U>(application_audio_device_state_006b48c0[adj_off + 1u]) << 8u));
            final_val = static_cast<std::uint16_t>(adj + base);
        }
        write_u16(info_va + 0x0cu + static_cast<U>(ch) * 2u, final_val);
    }

    if (read_u8(info_va + 0x07u) == 0u) {
        const U codec = audio_stream_codec_from_format_00599720(format_tag, bits_per_sample);
        write_u8(header_va + 0x03u, static_cast<B>(codec));
    }

    return 0u;
}

} // namespace porsche
