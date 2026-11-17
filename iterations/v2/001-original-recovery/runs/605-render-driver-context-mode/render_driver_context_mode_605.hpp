#pragma once

#include <cstdint>
#include "porsche/render_loader.hpp"
#include "porsche/game_setup.hpp"
#include "../479-audio-mixer-ramp-stop/audio_mixer_ramp_stop_479.hpp"

namespace porsche {

// File-backed .data DWORDs owned by 005381d0 (0x005dea60, 0x005dea78).
extern std::int32_t render_driver_exp_bias_005dea60;
extern std::uint32_t render_driver_exp_dirty_005dea78;

// Original entry 005381d0..00538222 (83 bytes).
std::int32_t __cdecl render_driver_shift_bias_005381d0(std::int32_t shift);

// Original entry 00549220..005492ed (206 bytes).
void __fastcall render_driver_context_mode_00549220(void* self, void* edx, std::uint32_t mode);

} // namespace porsche
