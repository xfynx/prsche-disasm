#pragma once
#include "porsche/render_mode.hpp"
#include <cstdint>

namespace porsche {
// Opaque renderer object returned by original IAT slot 0x006bd934. Fields used
// by the consumer are at the original byte offsets, not a guessed class layout.
struct RenderSettingsDevice {
    std::uint8_t bytes[0x100];
};

// Original 0x44e890 is a parameterless cdecl consumer. Its persistent renderer
// bytes are owned by Run063's canonical state block.
void __cdecl render_mode_apply_settings_0044e890();

// The original call graph/API boundaries remain explicit and typed.
const RenderSettingsDevice* __cdecl render_settings_current_device_006bd934();
std::uint32_t __stdcall render_settings_get_state_006bd984(std::uint32_t key);
std::uint32_t __stdcall render_settings_set_state_006bd97c(
    std::uint32_t key, std::uint32_t value);
std::int32_t __cdecl render_settings_read_config_005a1e10(
    char* output, const char* key);

// Direct original global read at 0x00657da4; this storage has no prior source
// owner in the v2 renderer modules.
extern std::uint32_t& render_settings_value_00657da4;
}
