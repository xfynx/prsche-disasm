// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00589df0..00589e7b, 140 bytes, sha256 0d231a017eb74cdeb3fa399a75d1e4261c974bed5c6ea0d80eb6a5c1909f3a8b.
// Original 00590d10..00590d4d, 62 bytes, sha256 c1f7496256814cbfc7e853b578fdf63897783d1891b7fb94e687a0efd47b6bdf.
// Original 005662b0..0056633c, 141 bytes, sha256 5f3ca5b7f89d16fc1fe668eda3d67508504711d16ee60e474c0bb8ac80b7bcea.
// Original 00566340..00566371, 50 bytes, sha256 5c68e6e28b7b603a2ab29ff76062a7e6886ebfb9018d1e19a2b0f4f67d58ca99.
// Original 004af900..004af96f, 112 bytes, sha256 952dcbe96c15902c7e429038640ecbec7c2c2cac5820bc4444abba0b064261fd.
#include "frame_audio_channel_volume_608.hpp"

namespace porsche {

std::int8_t frame_audio_mode_006573a4 = 0;
std::uint32_t frame_audio_tag_00657388 = 0u;
std::int32_t frame_audio_primary_handle_006573a8 = 0;
std::int32_t frame_audio_secondary_handle_006573ac = 0;
std::int32_t frame_audio_extra_handles_00656ae8[2] = {};

void __cdecl audio_voice_recompute_gain_00589df0(std::uint32_t voice_slot) {
    std::uint8_t* const rec = reinterpret_cast<std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
    const std::int32_t v34 = *reinterpret_cast<const std::int32_t*>(rec + 0x34u) >> 16;
    const std::int32_t v2c = *reinterpret_cast<const std::int32_t*>(rec + 0x2cu) >> 16;
    const std::int32_t v3c = *reinterpret_cast<const std::int8_t*>(rec + 0x3cu);
    const std::int32_t v_master = static_cast<std::int8_t>(application_audio_device_state_006b48c0[0xddu]);
    const std::int32_t prod1 = v34 * v2c * v3c * v_master;
    const std::int32_t hi1 = static_cast<std::int32_t>((static_cast<std::int64_t>(prod1) * 0x4186143dll) >> 32);
    const std::int32_t sar1 = hi1 >> 19;
    const std::int32_t q1 = sar1 + static_cast<std::int32_t>(static_cast<std::uint32_t>(sar1) >> 31u);
    rec[0x3du] = static_cast<std::uint8_t>(q1);
    const std::int8_t* const env_table = *reinterpret_cast<const std::int8_t* const*>(rec + 0x5cu);
    if (env_table != nullptr) {
        const std::uint8_t idx = rec[0x4au];
        const std::int32_t d_signed = static_cast<std::int8_t>(rec[0x3du]);
        const std::int32_t prod2 = static_cast<std::int32_t>(env_table[idx]) * d_signed;
        const std::int32_t hi2 = static_cast<std::int32_t>((static_cast<std::int64_t>(prod2) * static_cast<std::int32_t>(0x81020409u)) >> 32) + prod2;
        const std::int32_t sar2 = hi2 >> 6;
        const std::int32_t q2 = sar2 + static_cast<std::int32_t>(static_cast<std::uint32_t>(sar2) >> 31u);
        rec[0x3du] = static_cast<std::uint8_t>(q2);
    }
    const std::uint8_t* const lut_table = *reinterpret_cast<const std::uint8_t* const*>(rec + 0x54u);
    if (lut_table != nullptr) {
        const std::int32_t d_signed = static_cast<std::int8_t>(rec[0x3du]);
        rec[0x3du] = lut_table[d_signed];
    }
}

std::uint32_t __cdecl audio_voice_apply_gain_00590d10(std::uint32_t voice_slot) {
    std::uint8_t* const hw_rec = reinterpret_cast<std::uint8_t*>(audio_backend_voice_table_006b489c) + voice_slot * 0xf8u;
    const std::uint8_t* const ch_rec = reinterpret_cast<const std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
    const std::int32_t gain = *reinterpret_cast<const std::int8_t*>(ch_rec + 0x3du);
    const std::uint32_t arg0 = *reinterpret_cast<const std::uint32_t*>(hw_rec + 0xa0u);
    using HwApplyGain_608 = void (__cdecl *)(std::uint32_t, std::int32_t);
    const HwApplyGain_608 fn = *reinterpret_cast<const HwApplyGain_608*>(hw_rec + 0xd4u);
    fn(arg0, gain);
    return 0u;
}

std::int32_t __cdecl audio_channel_volume_005662b0(std::uint32_t handle, std::uint32_t volume) {
    const std::int32_t ch = audio_backend_find_channel_00589d20(handle);
    if (ch < 0) {
        return ch;
    }
    std::uint32_t voice_slot = 0xffffffffu;
    if (audio_backend_next_voice_00590340(ch, &voice_slot) == 0u) {
        return ch;
    }
    const std::uint32_t scaled_vol = volume << 16u;
    do {
        std::uint8_t* const rec = reinterpret_cast<std::uint8_t*>(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
        if (*reinterpret_cast<const std::uint32_t*>(rec + 0x2cu) == scaled_vol) {
            return 0;
        }
        *reinterpret_cast<std::uint32_t*>(rec + 0x2cu) = scaled_vol;
        *reinterpret_cast<std::uint32_t*>(rec + 0x24u) = 0u;
        audio_voice_recompute_gain_00589df0(voice_slot);
        (void)audio_voice_apply_gain_00590d10(voice_slot);
    } while (audio_backend_next_voice_00590340(ch, &voice_slot) != 0u);
    return ch;
}

std::uint32_t __cdecl frame_services_boundary_00566340(std::uint32_t handle, std::uint32_t volume) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return 0xfffffff6u;
    }
    audio_backend_lock_005896d0();
    const std::int32_t res = audio_channel_volume_005662b0(handle, volume);
    audio_backend_unlock_005896f0();
    return static_cast<std::uint32_t>(res);
}

void __cdecl frame_services_boundary_004af900(std::uint32_t tag, std::uint32_t mode) {
    if (tag != 0u) {
        if (static_cast<std::uint32_t>(static_cast<std::int32_t>(frame_audio_mode_006573a4)) != mode) {
            return;
        }
        if (tag != frame_audio_tag_00657388) {
            return;
        }
    }
    const std::int32_t h0 = frame_audio_primary_handle_006573a8;
    if (h0 != -1) {
        (void)frame_services_boundary_00566340(static_cast<std::uint32_t>(h0), 0u);
    }
    const std::int32_t h1 = frame_audio_secondary_handle_006573ac;
    if (h1 != -1) {
        (void)frame_services_boundary_00566340(static_cast<std::uint32_t>(h1), 0u);
    }
    for (std::uint32_t i = 0u; i < 2u; ++i) {
        const std::int32_t hx = frame_audio_extra_handles_00656ae8[i];
        if (hx != -1) {
            (void)audio_channel_stop_00565d60(static_cast<std::uint32_t>(hx));
            frame_audio_extra_handles_00656ae8[i] = -1;
        }
    }
}

} // namespace porsche
