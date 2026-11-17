// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00567810..0056784f, 64 bytes, sha256 3de16d2b4c489ecfe4d745626df141a55b789b4119960fcd8912a781fb3ba9a1.
// Original 00567850..00567893, 68 bytes, sha256 cd1370530c5f9be45cce0af175ed88cd1cd22968c918b6605dbccf780d5b94a1.
// Original 00591320..00591372, 83 bytes, sha256 78e8298a6550549ec14a007e8300da151c9eff76f4808396bd6d3a36c26f78ec.
#include "audio_stream_channel_status_637.hpp"

namespace porsche {

namespace {

inline std::uint8_t* ptr_from_va(std::uint32_t va) noexcept {
    return reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(va));
}

} // namespace

std::int32_t __cdecl audio_stream_service_volume_00567810(
    std::int32_t slot, std::uint32_t volume) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const std::uint32_t obj = audio_stream_service_lookup_00566d60(slot);
    if (obj == 0u) {
        return -8;
    }
    std::uint8_t* const obj_bytes = ptr_from_va(obj);
    obj_bytes[0xe4u] = static_cast<std::uint8_t>(volume);
    const std::uint32_t handle = *reinterpret_cast<const std::uint32_t*>(obj_bytes + 0x08u);
    (void)frame_services_boundary_00566340(handle, volume);
    return 0;
}

std::int32_t __cdecl audio_stream_service_status_00567850(std::int32_t slot) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const std::uint32_t obj = audio_stream_service_lookup_00566d60(slot);
    if (obj == 0u) {
        return -8;
    }
    const std::uint8_t* const obj_bytes = ptr_from_va(obj);
    const std::uint32_t handle = *reinterpret_cast<const std::uint32_t*>(obj_bytes + 0x08u);
    const std::int32_t status = audio_channel_status_00591320(handle);
    if (status >= 0) {
        return status;
    }
    return static_cast<std::int32_t>(static_cast<std::int8_t>(obj_bytes[0xe4u]));
}

std::int32_t __cdecl audio_channel_status_00591320(std::uint32_t handle) {
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    audio_backend_lock_005896d0();
    const std::int32_t idx = audio_backend_find_channel_00589d20(handle);
    audio_backend_unlock_005896f0();
    if (idx < 0) {
        return -8;
    }
    const std::uint8_t* const rec =
        ptr_from_va(audio_backend_channels_006b4a00) + static_cast<std::uint32_t>(idx) * 0x70u;
    return static_cast<std::int32_t>(static_cast<std::int8_t>(rec[0x3du]));
}

} // namespace porsche
