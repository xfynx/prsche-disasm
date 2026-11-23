// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00589e80..00589f31, 178 bytes, sha256 7313cfa93428141920de670f8bcb67e3592467fdc9be164bbe5bace00af31578.
// Original 00589f40..00589fd5, 150 bytes, sha256 5e19d342e400ba717d25caf9282beda2c015719a7a057eceaa6a3cecb23143c5.
#include "audio_voice_pitch_777.hpp"

#include <cstring>

namespace porsche {

// Original table 005e1d3c..005e1e3b (256 bytes, sha256 24e944a9313649312e7251afb205894bcf816f2e8005ae004e5a30a5806baa15).
// Negative indices -255..-1 read via end address 005e1e3c + idx = 005e1d3c + 256 + idx.
const std::uint8_t audio_pitch_scale_table_005e1d3c[256] = {
    0x00u, 0x01u, 0x02u, 0x02u, 0x03u, 0x04u, 0x04u, 0x05u, 0x06u, 0x07u, 0x07u, 0x08u, 0x09u, 0x09u, 0x0au, 0x0bu,
    0x0cu, 0x0cu, 0x0du, 0x0eu, 0x0eu, 0x0fu, 0x10u, 0x11u, 0x11u, 0x12u, 0x13u, 0x14u, 0x14u, 0x15u, 0x16u, 0x17u,
    0x17u, 0x18u, 0x19u, 0x1au, 0x1au, 0x1bu, 0x1cu, 0x1du, 0x1eu, 0x1eu, 0x1fu, 0x20u, 0x21u, 0x21u, 0x22u, 0x23u,
    0x24u, 0x25u, 0x25u, 0x26u, 0x27u, 0x28u, 0x29u, 0x29u, 0x2au, 0x2bu, 0x2cu, 0x2du, 0x2du, 0x2eu, 0x2fu, 0x30u,
    0x31u, 0x32u, 0x32u, 0x33u, 0x34u, 0x35u, 0x36u, 0x37u, 0x37u, 0x38u, 0x39u, 0x3au, 0x3bu, 0x3cu, 0x3du, 0x3du,
    0x3eu, 0x3fu, 0x40u, 0x41u, 0x42u, 0x43u, 0x43u, 0x44u, 0x45u, 0x46u, 0x47u, 0x48u, 0x49u, 0x4au, 0x4bu, 0x4bu,
    0x4cu, 0x4du, 0x4eu, 0x4fu, 0x50u, 0x51u, 0x52u, 0x53u, 0x54u, 0x55u, 0x56u, 0x56u, 0x57u, 0x58u, 0x59u, 0x5au,
    0x5bu, 0x5cu, 0x5du, 0x5eu, 0x5fu, 0x60u, 0x61u, 0x62u, 0x63u, 0x64u, 0x65u, 0x66u, 0x67u, 0x68u, 0x69u, 0x6au,
    0x6bu, 0x6cu, 0x6cu, 0x6du, 0x6eu, 0x6fu, 0x70u, 0x71u, 0x72u, 0x73u, 0x74u, 0x75u, 0x77u, 0x78u, 0x79u, 0x7au,
    0x7bu, 0x7cu, 0x7du, 0x7eu, 0x7fu, 0x80u, 0x81u, 0x82u, 0x83u, 0x84u, 0x85u, 0x86u, 0x87u, 0x88u, 0x89u, 0x8au,
    0x8bu, 0x8cu, 0x8eu, 0x8fu, 0x90u, 0x91u, 0x92u, 0x93u, 0x94u, 0x95u, 0x96u, 0x97u, 0x98u, 0x9au, 0x9bu, 0x9cu,
    0x9du, 0x9eu, 0x9fu, 0xa0u, 0xa1u, 0xa3u, 0xa4u, 0xa5u, 0xa6u, 0xa7u, 0xa8u, 0xa9u, 0xabu, 0xacu, 0xadu, 0xaeu,
    0xafu, 0xb0u, 0xb2u, 0xb3u, 0xb4u, 0xb5u, 0xb6u, 0xb7u, 0xb9u, 0xbau, 0xbbu, 0xbcu, 0xbdu, 0xbfu, 0xc0u, 0xc1u,
    0xc2u, 0xc4u, 0xc5u, 0xc6u, 0xc7u, 0xc8u, 0xcau, 0xcbu, 0xccu, 0xcdu, 0xcfu, 0xd0u, 0xd1u, 0xd2u, 0xd4u, 0xd5u,
    0xd6u, 0xd8u, 0xd9u, 0xdau, 0xdbu, 0xddu, 0xdeu, 0xdfu, 0xe1u, 0xe2u, 0xe3u, 0xe5u, 0xe6u, 0xe7u, 0xe8u, 0xeau,
    0xebu, 0xecu, 0xeeu, 0xefu, 0xf0u, 0xf2u, 0xf3u, 0xf5u, 0xf6u, 0xf7u, 0xf9u, 0xfau, 0xfbu, 0xfdu, 0xfeu, 0xffu
};

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline std::uint16_t read_u16(U addr) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline std::int16_t read_i16(U addr) noexcept {
    std::int16_t value = 0;
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

inline std::int8_t read_i8(U addr) noexcept {
    std::int8_t value = 0;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline I sar_n(I value, U shift) noexcept {
    const U uv = static_cast<U>(value);
    if (shift == 0u) {
        return value;
    }
    if (shift >= 32u) {
        return (value < 0) ? -1 : 0;
    }
    const U fill = (value < 0) ? (0xffffffffu << (32u - shift)) : 0u;
    return static_cast<I>((uv >> shift) | fill);
}

} // namespace

std::int32_t __cdecl audio_voice_pitch_scale_00589e80(std::int32_t cents) {
    I scale = 0x1000;
    if (cents >= 0x4b0) {
        const U q = static_cast<U>(
            (static_cast<std::uint64_t>(0x1b4e81b5u) * static_cast<U>(cents)) >> 39u);
        cents = static_cast<I>(static_cast<U>(cents) - q * 1200u);
        scale = (q >= 32u) ? 0 : static_cast<I>(static_cast<U>(scale) << q);
    }
    if (cents <= -0x4b0) {
        const U neg_cents = 0u - static_cast<U>(cents);
        const U q = static_cast<U>(
            (static_cast<std::uint64_t>(0x1b4e81b5u) * neg_cents) >> 39u);
        cents = static_cast<I>(static_cast<U>(cents) + q * 1200u);
        scale = sar_n(scale, q);
    }

    const I prod = static_cast<I>(static_cast<U>(cents) * 13981u);
    I idx = sar_n(prod, 16u);
    if (idx < -255) {
        idx = -255;
    }
    if (idx < 0) {
        const I entry = static_cast<I>(audio_pitch_scale_table_005e1d3c[256 + idx]) + 0x100;
        return sar_n(static_cast<I>(static_cast<U>(entry) * static_cast<U>(scale)), 9u);
    }
    const I entry = static_cast<I>(audio_pitch_scale_table_005e1d3c[idx]) + 0x100;
    return sar_n(static_cast<I>(static_cast<U>(entry) * static_cast<U>(scale)), 8u);
}

void __cdecl audio_voice_recompute_pitch_00589f40(std::uint32_t voice_slot) {
    const U rec_va = audio_backend_channels_006b4a00 + voice_slot * 0x70u;
    if (read_i16(rec_va + 0x6au) == 0) {
        const I mod0_scale = static_cast<I>(read_i16(rec_va + 0x66u));
        I cents = static_cast<I>(read_i16(rec_va + 0x68u));
        if (mod0_scale != 0) {
            const U ptr0 = read_u32(rec_va + 0x58u);
            const I idx0 = static_cast<I>(read_i8(rec_va + 0x3fu));
            const I sample0 = (ptr0 != 0u) ? static_cast<I>(read_i8(ptr0 + static_cast<U>(idx0))) : idx0;
            cents += sar_n((sample0 - 0x40) * mod0_scale, 6u);
        }

        const U ptr1 = read_u32(rec_va + 0x60u);
        if (ptr1 != 0u) {
            const U idx1 = static_cast<U>(read_u8(rec_va + 0x4bu));
            const I sample1 = static_cast<I>(read_i8(ptr1 + idx1));
            const I mod1_scale = static_cast<I>(read_i16(rec_va + 0x64u));
            cents += sar_n((sample1 - 0x40) * mod1_scale, 6u);
        }

        const I scaled = audio_voice_pitch_scale_00589e80(cents);
        write_u16(rec_va + 0x6au, static_cast<std::uint16_t>(scaled));
    }

    const U base_rate = static_cast<U>(read_u16(rec_va + 0x6cu));
    const U pitch_mul = static_cast<U>(read_u16(rec_va + 0x6au));
    const I out_rate = sar_n(static_cast<I>(base_rate * pitch_mul), 12u);
    write_u16(rec_va + 0x6eu, static_cast<std::uint16_t>(out_rate));
}

} // namespace porsche
