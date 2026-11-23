// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_audio_device.hpp"
#include "porsche/network_lifecycle.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../598-startup-clock-callback/startup_clock_callback_598.hpp"
#include "../691-app-sim-teardown-audio-unload/application_sim_teardown_691.hpp"

namespace porsche {

// 1-byte BSS registration guard at 00656ab0 (explicitly unowned gap noted in Run478).
extern std::uint8_t sim_audio_callback_registered_00656ab0;

// Recovered functions (5 bodies, 203 code bytes total; 4 match application_sim_teardown_691.hpp).
void __cdecl application_sim_boundary_004a4760();
void __cdecl application_sim_boundary_004ae470(
    std::int32_t first,
    std::uint32_t* second);
std::int32_t __cdecl application_sim_boundary_004b04d0(
    std::int32_t first,
    std::int32_t second);
void __cdecl application_sim_boundary_004ad4d0();
void __cdecl audio_device_register_callback_005610e0(std::uint32_t callback_va);

} // namespace porsche
