// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00590290..00590292, 3 bytes, sha256 4bc724f3b1d0caf4fe369c18cba3102e6c4ea057f63fe1587e3973134a7f755e.
// Original 00589d70..00589de8, 121 bytes, sha256 ad5c9f92237398e9a6c81fe662d10fe76b36470105f4feea9919df13f31a75fb.
// Original 00598eb0..00598f12, 99 bytes, sha256 c2d6d7a1fa958a0c418754fcc07c32149f26638de4b5b3fef49d8d850cc242c9.
// Original 005902a0..0059033c, 157 bytes, sha256 d9c5cf7a14b041080a02afa2d9a157e1c7995f449693217867c8a97caada2b53.
// Original 00565cd0..00565d58, 137 bytes, sha256 37db905daea42465abe5c02e1237f35e96dbf83374682a9d086f610a85fb488f.
#include "frame_audio_send_level_610.hpp"

namespace porsche {

std::int32_t __cdecl audio_send_validate_00590290(std::uint32_t, std::uint32_t) {
    return 0;
}

void __cdecl audio_voice_recompute_send_00589d70(std::uint32_t bus, std::uint32_t voice_slot) {
    std::uint8_t* const rec = reinterpret_cast<std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
    const std::int32_t v45 = *reinterpret_cast<const std::int8_t*>(rec + bus + 0x45u);
    const std::int32_t v44 = *reinterpret_cast<const std::int8_t*>(rec + bus + 0x44u);
    const std::int32_t prod0 = v45 * v44;
    const std::uint32_t bus_off = bus << 4u;
    const std::int32_t b0c = static_cast<std::int8_t>(application_audio_device_state_006b48c0[0x14cu + bus_off]);
    const std::int32_t b0d = static_cast<std::int8_t>(application_audio_device_state_006b48c0[0x14du + bus_off]);
    const std::int32_t prodL = b0c * prod0;
    const std::int32_t hiL = static_cast<std::int32_t>((static_cast<std::int64_t>(prodL) * static_cast<std::int32_t>(0x82061029u)) >> 32) + prodL;
    const std::int32_t sarL = hiL >> 13;
    const std::int32_t qL = sarL + static_cast<std::int32_t>(static_cast<std::uint32_t>(sarL) >> 31u);
    rec[bus + 0x46u] = static_cast<std::uint8_t>(qL);
    const std::int32_t prodR = b0d * prod0;
    const std::int32_t hiR = static_cast<std::int32_t>((static_cast<std::int64_t>(prodR) * static_cast<std::int32_t>(0x82061029u)) >> 32) + prodR;
    const std::int32_t sarR = hiR >> 13;
    const std::int32_t qR = sarR + static_cast<std::int32_t>(static_cast<std::uint32_t>(sarR) >> 31u);
    rec[bus + 0x47u] = static_cast<std::uint8_t>(qR);
}

std::uint32_t __cdecl audio_voice_apply_send_00598eb0(std::uint32_t voice_slot, std::uint32_t bus) {
    const std::uint8_t* const ch_rec = reinterpret_cast<const std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
    std::uint8_t* const hw_rec = reinterpret_cast<std::uint8_t*>(audio_backend_voice_table_006b489c) + voice_slot * 0xf8u;
    const std::uint32_t arg0 = *reinterpret_cast<const std::uint32_t*>(hw_rec + 0xa4u);
    const std::int32_t val = ((*hw_rec & 0x10u) != 0u)
        ? static_cast<std::int32_t>(*reinterpret_cast<const std::int8_t*>(ch_rec + bus + 0x47u))
        : static_cast<std::int32_t>(*reinterpret_cast<const std::int8_t*>(ch_rec + bus + 0x46u));
    using HwApplySend_610 = void (__cdecl *)(std::uint32_t, std::int32_t);
    const HwApplySend_610 fn = *reinterpret_cast<const HwApplySend_610*>(hw_rec + 0xd8u);
    fn(arg0, val);
    return 0u;
}

std::int32_t __cdecl audio_channel_send_level_005902a0(std::uint32_t handle, std::uint32_t bus, std::int32_t level) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    audio_backend_lock_005896d0();
    const std::int32_t ch = audio_backend_find_channel_00589d20(handle);
    if (ch >= 0) {
        std::uint32_t voice_slot = 0xffffffffu;
        if (audio_backend_next_voice_00590340(ch, &voice_slot) != 0u) {
            const std::uint8_t level_byte = static_cast<std::uint8_t>(level);
            do {
                std::uint8_t* const rec = reinterpret_cast<std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
                rec[bus + 0x45u] = level_byte;
                audio_voice_recompute_send_00589d70(bus, voice_slot);
                (void)audio_voice_apply_send_00598eb0(voice_slot, bus);
            } while (audio_backend_next_voice_00590340(ch, &voice_slot) != 0u);
        }
    }
    audio_backend_unlock_005896f0();
    return ch;
}

void __cdecl frame_services_boundary_00565cd0(std::uint32_t bus_flags, std::uint32_t level) {
    std::uint32_t flags = bus_flags;
    const std::uint32_t bus = flags & 0xffffff1fu;
    if ((flags & 0xe0u) == 0u) {
        flags |= 0xe0u;
    }
    if ((flags & 0x20u) != 0u) {
        application_audio_device_state_006b48c0[0x14cu + (bus << 4u)] = static_cast<std::uint8_t>(level);
    }
    if ((flags & 0x80u) != 0u) {
        application_audio_device_state_006b48c0[0x14du + (bus << 4u)] = static_cast<std::uint8_t>(level);
    }
    if (audio_send_validate_00590290(flags, level) < 0) {
        return;
    }
    if (application_audio_device_state_006b48c0[0xdcu] != 0u && audio_backend_channel_count_006b49a4 > 0) {
        std::int32_t idx = 0;
        std::uint32_t offset = 0u;
        do {
            const std::uint8_t* const rec = reinterpret_cast<const std::uint8_t*>(audio_backend_channels_006b4a00) + offset;
            const std::int32_t ch_level = *reinterpret_cast<const std::int8_t*>(rec + bus + 0x45u);
            const std::uint32_t handle = *reinterpret_cast<const std::uint32_t*>(rec);
            (void)audio_channel_send_level_005902a0(handle, bus, ch_level);
            ++idx;
            offset += 0x70u;
        } while (idx < static_cast<std::int32_t>(audio_backend_channel_count_006b49a4));
    }
}

} // namespace porsche
