// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

namespace porsche {

using RenderWindowCallbackEntry = void (__cdecl *)();

// File-backed .data callback table at original VA 0x005e1960 (32 bytes, 8 DWORDs):
// [0x005756d0, 0x00557460, 0x0053a800, 0x0053a780,
//  0x005756e0, 0x00575730, 0x00575770, 0x005757d0].
extern RenderWindowCallbackEntry render_window_callbacks_005e1960[8];

// Loader-zero .data DWORD owned by 00575820 at original VA 0x006a64bc (4 bytes).
extern std::uint32_t render_window_exit_registered_006a64bc;

// Original 005757f0..00575809 (26 bytes), 00575810..00575818 (9 bytes),
// and 00575820..0057592d (270 bytes).
std::uint32_t __cdecl render_window_abort_cleanup_005757f0();
void __cdecl render_window_exit_cleanup_00575810();
std::uint32_t __cdecl render_initialize_window_00575820(std::uint32_t first);

// Unrecovered entries referenced by render_window_callbacks_005e1960.
// Declared here for address transport only with exact original x86 ABIs;
// intentionally unimplemented in this packet.
void __cdecl render_window_callback_005756d0();
std::uint32_t __stdcall window_handler_find_0053a780(std::uint32_t message);
std::uint32_t __stdcall render_window_callback_005756e0(std::uint32_t arg);
void __stdcall render_window_callback_00575730(std::uint32_t arg);
void __stdcall render_window_callback_00575770(std::uint32_t arg0, std::uint32_t arg1);
void __stdcall render_window_callback_005757d0(std::uint32_t arg0, std::uint32_t arg1);

} // namespace porsche
