// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00561180..005611c3 and 005612a0..005615b6.
#include "audio_voice_start_751.hpp"

#include <cstring>

namespace porsche {
namespace {

using B = std::uint8_t;
using I = std::int32_t;
using U = std::uint32_t;

template <typename T> T read(const B* p, U offset) noexcept {
    T value{};
    std::memcpy(&value, p + offset, sizeof value);
    return value;
}

template <typename T> void write(B* p, U offset, T value) noexcept {
    std::memcpy(p + offset, &value, sizeof value);
}

B* backend_voice(U slot) noexcept {
    return reinterpret_cast<B*>(static_cast<std::uintptr_t>(audio_backend_channels_006b4a00)) + slot * 0x70u;
}

} // namespace

I __cdecl audio_voice_loudest_channel_00561180(U voice_slot, I channel_count) {
    I best_index = -1;
    std::int16_t best_value = -1;
    const B* voice = backend_voice(voice_slot);
    for (I i = 0; i < channel_count; ++i) {
        const std::int16_t value = read<std::int16_t>(voice, 4u + static_cast<U>(i) * 2u);
        if (best_value < value) {
            best_value = value;
            best_index = i;
        }
    }
    return best_index;
}

I __cdecl audio_stream_voice_start_005612a0(
    U stream_slot,
    const void* header_ptr,
    const void* params_ptr,
    const void* descriptor_ptr) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) return -10;

    const auto* header = static_cast<const B*>(header_ptr);
    const auto* params = static_cast<const B*>(params_ptr);
    const auto* descriptor = static_cast<const B*>(descriptor_ptr);
    const I channel_count = static_cast<I>(header[2u]);
    B* slot = reinterpret_cast<B*>(static_cast<std::uintptr_t>(audio_stream_slots_006b7cc0[stream_slot]));

    audio_backend_lock_005896d0();
    write<U>(slot, 0x34u, read<U>(header, 0u));
    write<U>(slot, 0x04u, 0u);
    write<U>(slot, 0x20u, 0u);
    write<U>(slot, 0x24u, 0u);
    write<std::uint16_t>(slot, 0x1eu, 0u);
    write<std::uint16_t>(slot, 0x1cu, 0xffffu);

    const U subchannel_count = slot[0x36u];
    for (U i = 0u; i < subchannel_count; ++i) {
        write<std::uint16_t>(slot, 0x08u + i * 2u, 0xffffu);
        write<std::uint16_t>(slot, 0x10u + i * 2u, 0u);
        write<U>(slot, 0x38u + i * 4u, read<U>(params, 0x14u + i * 4u));
    }

    U cursor = 0u;
    U record[4]{};
    U candidate = audio_group_step_0058a970(&cursor, record);
    while (candidate != 0u) {
        U first = 0u;
        U last = 0u;
        audio_backend_candidate_range_0058a4b0(candidate, &first, &last);
        U handle = 0u;
        const I voice_slot = audio_backend_allocate_voice_005898f0(
            channel_count, 0x65u, &handle, first, last);
        if (voice_slot < 0) {
            write<I>(slot, 0u, -9);
        } else {
            write<U>(slot, 0u, handle);
            write<std::int16_t>(
                slot,
                0x1au,
                static_cast<std::int16_t>(audio_voice_loudest_channel_00561180(
                    static_cast<U>(voice_slot), channel_count)));

            B* voice = backend_voice(static_cast<U>(voice_slot));
            const std::uint16_t pitch = descriptor[0x0bu] != 0u
                ? read<std::uint16_t>(descriptor, 0x18u)
                : static_cast<std::uint16_t>(
                      static_cast<U>(static_cast<I>(static_cast<std::int8_t>(descriptor[7u])) - 0x40) << 8u);
            write<std::uint16_t>(voice, 0x14u, pitch);
            write<std::uint16_t>(voice, 0x68u, read<std::uint16_t>(params, 0u));
            write<std::uint16_t>(voice, 0x6cu, read<std::uint16_t>(descriptor, 0x0cu));
            write<U>(
                voice,
                0x2cu,
                static_cast<U>(static_cast<I>(static_cast<std::int8_t>(descriptor[8u]))) << 16u);
            voice[0x3cu] = params[3u];
            voice[0x3eu] = params[4u];
            voice[0x3fu] = descriptor[9u];
            voice[0x44u] = params[5u];
            voice[0x45u] = descriptor[0x0au];
            voice[0x0eu] = 0xffu;
            write<U>(voice, 0x24u, 0u);
            write<U>(voice, 0x30u, 0u);
            write<U>(voice, 0x38u, 0x7fffffffu);
            write<U>(voice, 0x34u, 0x007f0000u);
            voice[0x40u] = 1u;
            voice[0x41u] = 0u;
            voice[0x42u] = 0u;
            voice[0x43u] = 1u;
            voice[0x1eu] = 0u;
            voice[0x1bu] = 0u;
            voice[0x1fu] = descriptor[7u];
            write<U>(voice, 0x50u, 0u);
            write<U>(voice, 0x54u, 0u);
            write<U>(voice, 0x58u, 0u);
            write<U>(voice, 0x5cu, 0u);
            write<U>(voice, 0x60u, 0u);
            write<std::uint16_t>(voice, 0x6au, 0u);
            write<std::int16_t>(
                voice,
                0x66u,
                static_cast<std::int16_t>(static_cast<I>(static_cast<std::int8_t>(params[6u])) * 100));

            audio_voice_recompute_pitch_00589f40(static_cast<U>(voice_slot));
            audio_voice_recompute_gain_00589df0(static_cast<U>(voice_slot));
            audio_voice_recompute_send_00589d70(0u, static_cast<U>(voice_slot));
            const I started = audio_voice_backend_start_005897c0(
                stream_slot,
                static_cast<U>(voice_slot),
                candidate,
                read<std::uint16_t>(descriptor, 0x0eu),
                read<std::uint16_t>(descriptor, 0x12u),
                read<std::uint16_t>(descriptor, 0x14u),
                header,
                params + 0x0cu,
                params + 0x14u);
            if (started >= 0) {
                audio_backend_unlock_005896f0();
                return read<I>(slot, 0u);
            }
            for (I i = 0; i < channel_count; ++i) {
                audio_backend_voice_finalize_00589c00(static_cast<U>(
                    static_cast<I>(read<std::int16_t>(voice, 4u + static_cast<U>(i) * 2u))));
            }
            write<I>(slot, 0u, started);
        }
        candidate = audio_group_step_0058a970(&cursor, record);
    }

    audio_backend_unlock_005896f0();
    return read<I>(slot, 0u);
}

} // namespace porsche
