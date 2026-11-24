// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Owns loader-zero .bss storage:
// - application_player_object_table_005e8b34 (005e8b34..005e8b57, 36B)
// - application_player_setup_table_005e75a0 (005e75a0..005e8ab7, 5400B)
// - frame_service_root_00628960 (00628960..00628963, 4B)
// - resource_open_transform_006ad750 (006ad750..006ad753, 4B)
// Plus render_event_invoke_callback_005debec (00572983..00572988, 6B call-site adapter).
#include "player_service_tables_831.hpp"

namespace porsche {

std::uint32_t application_player_object_table_005e8b34[9u] = {};
std::uint32_t application_player_setup_table_005e75a0[9u * 0x96u] = {};
std::uint32_t frame_service_root_00628960 = 0u;
ResourceOpenTransform resource_open_transform_006ad750 = nullptr;

void __cdecl render_event_invoke_callback_005debec(std::uint32_t callback,
                                                    std::uint32_t mode_flags) {
    reinterpret_cast<void(__cdecl*)(std::uint32_t)>(
        static_cast<std::uintptr_t>(callback))(mode_flags);
}

} // namespace porsche
