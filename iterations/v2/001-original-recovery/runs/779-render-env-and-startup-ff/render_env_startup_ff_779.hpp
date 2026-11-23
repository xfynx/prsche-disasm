// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../521-render-initialize/render_initialize_521.hpp"
#include "../673-render-loader-directx-and-startup-alloc/render_loader_directx_673.hpp"
#include "../676-startup-input-slot-and-math-leaves/startup_input_slot_math_676.hpp"
#include "../695-ff-effect-initialize/ff_effect_initialize_695.hpp"
#include "porsche/application_main.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/startup_sequence.hpp"

namespace porsche {

// Owned read-only .rdata string at 005c0838..005c083d (6B): "%s=%s".
extern const char render_environment_fmt_005c0838[6];

// Loader-zero .bss pointer cell at 00606ad0..00606ad3 (4B); allocated by
// unrecovered 00414db0 and read by 004121b0.
extern void* startup_frame_tick_table_00606ad0;

// Unbounded .bss table from 691-app-sim-teardown-audio-unload (005e8b34).
extern std::uint32_t application_player_object_table_005e8b34[];

// Typed unrecovered CRT / callback boundaries.
std::int32_t __cdecl crt_putenv_005a38c7(const char* entry);
void __cdecl ff_effect_frame_tick_004123e0();

// Original 00573030..00573061 (50B, __cdecl, ret 0; returns 0).
// Declared in ../521-render-initialize/render_initialize_521.hpp.
std::uint32_t __cdecl render_environment_00573030(
    const char* name, const char* value, std::uint32_t ignored);

// Original 004121b0..0041222b (124B, __cdecl, ret 0; void).
// Declared in porsche/startup_sequence.hpp.
void __cdecl startup_sequence_call_004121b0();

} // namespace porsche
