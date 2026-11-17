// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

// Original 0053a780..0053a7e4 (101B, stdcall1 uint32),
// 0053bf20..0053bf4d (46B, cdecl0 void), and
// 004b0eb0..004b0ed6 (39B, cdecl0 void).
std::uint32_t __stdcall window_handler_find_0053a780(std::uint32_t message);
void __cdecl window_keyboard_hook_disable_0053bf20();
void __cdecl render_display_finish_init_004b0eb0();

// Unrecovered WM_ACTIVATEAPP callback at original VA 0x004b0ee0..0x004b0f99 (186B).
// Declared here for address transport only with exact original 6-arg stdcall ABI
// (RET 0x18 / WindowHandler); intentionally unimplemented in this packet.
std::uint32_t __stdcall render_display_activate_callback_004b0ee0(
    void* configuration,
    void* hwnd,
    std::uint32_t message,
    std::uint32_t wparam,
    std::int32_t lparam,
    std::int32_t* result);

} // namespace porsche
