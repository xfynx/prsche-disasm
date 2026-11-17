// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00565dd0..00565e6e, 159 bytes, sha256 b3b76f0e2fbd62511e3209d964eea4fe11d2024a362242bdfa68a9116c246293.
// Original 00566ae0..00566b37, 88 bytes, sha256 8824374bc7b6abd7085028e9464bb1eea95a3f7d28e99117d09aa97553565f24.
// Original 004ae3c0..004ae464, 165 bytes, sha256 5a830abdc012cff5c0047770e3600566fdd7ff32434942aebd6952010ba49ab1.
#include "frame_audio_stream_ramp_607.hpp"

namespace porsche {

namespace {

inline std::uint8_t* ptr_from_va(std::uint32_t va) noexcept {
    return reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(va));
}

} // namespace

std::int32_t __cdecl audio_channel_ramp_00565dd0(
    std::uint32_t handle, std::int32_t steps, std::int32_t target) {
    if (application_audio_device_state_006b48c0[0xdc] == 0u) {
        return -10;
    }
    audio_backend_lock_005896d0();
    const std::int32_t ch = audio_backend_find_channel_00589d20(handle);
    if (ch >= 0) {
        const std::int32_t div = (steps > 0) ? steps : 1;
        std::uint32_t voice_slot = 0xffffffffu;
        if (audio_backend_next_voice_00590340(ch, &voice_slot) != 0u) {
            const std::int32_t scaled_target =
                static_cast<std::int32_t>(static_cast<std::uint32_t>(target) << 16u);
            do {
                std::uint8_t* const rec =
                    ptr_from_va(audio_backend_channels_006b4a00) + voice_slot * 0x70u;
                const std::int32_t cur = *reinterpret_cast<const std::int32_t*>(rec + 0x2c);
                *reinterpret_cast<std::int32_t*>(rec + 0x28) = scaled_target;
                const std::int32_t diff = static_cast<std::int32_t>(
                    static_cast<std::uint32_t>(scaled_target) - static_cast<std::uint32_t>(cur));
                *reinterpret_cast<std::int32_t*>(rec + 0x24) = diff / div;
            } while (audio_backend_next_voice_00590340(ch, &voice_slot) != 0u);
        }
    }
    audio_backend_unlock_005896f0();
    return ch;
}

std::int32_t __cdecl audio_stream_service_ramp_00566ae0(
    std::int32_t slot, std::int32_t ms, std::int32_t target) {
    if (application_audio_device_state_006b48c0[0xdc] == 0u) {
        return -10;
    }
    const std::uint32_t obj = audio_stream_service_lookup_00566d60(slot);
    if (obj == 0u) {
        return -8;
    }
    std::uint8_t* const obj_bytes = ptr_from_va(obj);
    obj_bytes[0xe4u] = static_cast<std::uint8_t>(target);
    const std::int32_t steps = ms / 10;
    const std::uint32_t handle = *reinterpret_cast<const std::uint32_t*>(obj_bytes + 0x08u);
    (void)audio_channel_ramp_00565dd0(handle, steps, target);
    return 0;
}

std::uint32_t __cdecl frame_services_boundary_004ae3c0(std::uint32_t mode) {
    std::uint32_t root = audio_resource_query_root_00656ab4;
    if (root == 0u) {
        return 0u;
    }
    if (*reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x0cu) <= -1) {
        return root;
    }
    if (mode == 0u) {
        const std::int32_t slot =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        if (slot >= 0) {
            (void)audio_stream_service_reset_00567740(static_cast<std::uint32_t>(slot));
            root = audio_resource_query_root_00656ab4;
        }
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x20u) = 0u;
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x28u) = 0u;
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x14u) = 0u;
        const std::uint32_t final_root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::int32_t*>(ptr_from_va(final_root) + 0x0cu) = -1;
        return root;
    }
    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x14u) == 0u) {
        const std::int32_t slot =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        if (slot >= 0) {
            (void)audio_stream_service_ramp_00566ae0(slot, static_cast<std::int32_t>(mode), 0);
            const std::uint32_t edx_root = audio_resource_query_root_00656ab4;
            *reinterpret_cast<std::uint32_t*>(ptr_from_va(edx_root) + 0x20u) = mode;
        } else {
            *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x20u) = 0u;
        }
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x28u) = 0u;
        root = audio_resource_query_root_00656ab4;
    }
    *reinterpret_cast<std::int32_t*>(ptr_from_va(root) + 0x14u) = -1;
    const std::uint32_t final_root = audio_resource_query_root_00656ab4;
    *reinterpret_cast<std::int32_t*>(ptr_from_va(final_root) + 0x0cu) = -1;
    return root;
}

} // namespace porsche
