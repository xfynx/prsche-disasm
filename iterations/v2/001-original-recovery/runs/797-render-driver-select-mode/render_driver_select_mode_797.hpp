// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "../371-cursor-snapshot/cursor_snapshot.hpp"
#include "../374-render-descriptor/render_descriptor.hpp"
#include "../515-render-driver-constructors/render_driver_515.hpp"
#include "../518-render-driver-start/render_driver_start_518.hpp"
#include "../521-render-initialize/render_initialize_521.hpp"
#include "../523-render-resource-buffer/render_buffer_523.hpp"
#include "../581-render-driver-state/render_driver_state_581.hpp"
#include "porsche/render_display.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/render_settings.hpp"
#include "porsche/splash_progress.hpp"
#include "porsche/window_shutdown.hpp"

namespace porsche {

// Owned initialized .data scalars at 005ded4c..005ded4f and 005dedf4..005dedf7.
extern std::uint32_t render_driver_state2_enabled_005ded4c;
extern std::uint32_t render_driver_tex_offset_005dedf4;

// Original 00538b30..00538c7d (334B, __thiscall -> __fastcall, ret 4; uint8).
// Declared in ../515-render-driver-constructors/render_driver_515.hpp.
std::uint8_t __fastcall render_driver_select_mode_00538b30(
    void* self, void* unused_edx, std::uint32_t mode_index);

// Original 00537830..00537844 (21B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state28_00537830(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537890..005378b6 (39B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state2_00537890(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 005378c0..005378d4 (21B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state3c_005378c0(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 005378e0..005378f4 (21B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state9_005378e0(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537900..00537914 (21B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state15_00537900(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537920..00537936 (23B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_alias_e_00537920(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537940..00537956 (23B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_alias_16_00537940(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537960..00537976 (23B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_alias_17_00537960(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 00537980..00537994 (21B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state_f_00537980(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 005379a0..005379c3 (36B, __thiscall -> __fastcall, ret 4; void).
void __fastcall render_driver_set_state18_005379a0(
    void* cfg, void* unused_edx, std::uint32_t value);

// Original 005404a0..005404d2 (51B, __cdecl, ret 0; void).
void __cdecl render_driver_set_tex_state_005404a0(
    std::uint32_t key, std::uint32_t value);

} // namespace porsche
