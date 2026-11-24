// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 005ac147..005ac153 (13B, supplement), 005e5ec8..005e5f3f (120B .data),
// 005e4ffc..005e5033 (56B .data), and diagnostic_handler_005debf0 call-site adapters
// inside 0059e9d0 (0059eaa2..0059eab0), 0053ac20 (0053ad05..0053ad13), 00565030 (00565068..0056508b).
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "crt_exit_diag_828.hpp"

#include <cstdarg>
#include <cstdio>

namespace porsche {

void* exit_shutdown_prev_filter_006afed0 = nullptr;

// Exact 56-byte .data literal at 005e4ffc..005e5033.
extern const char application_memory_insufficient_fmt_005e4ffc[56] =
    "Insufficient memory to launch application (%d MBytes).\n";

// Exact 120-byte .data table at 005e5ec8..005e5f3f (10 x 12-byte CRT XcptActTab entries).
extern const std::uint8_t formatter_crt_signal_table_005e5ec8[120] = {
    0x05u, 0x00u, 0x00u, 0xc0u, 0x0bu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x1du, 0x00u, 0x00u, 0xc0u, 0x04u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x96u, 0x00u, 0x00u, 0xc0u, 0x04u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x8du, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x8eu, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x8fu, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x90u, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x91u, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x92u, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x93u, 0x00u, 0x00u, 0xc0u, 0x08u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
};

void __cdecl exit_shutdown_static_callback_005ac147() {
    (void)SetUnhandledExceptionFilter(
        reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(exit_shutdown_prev_filter_006afed0));
}

void __cdecl application_memory_diagnostic(std::uint32_t mbytes) {
    reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t)>(
        diagnostic_handler_005debf0)(application_memory_insufficient_fmt_005e4ffc, mbytes);
}

void __cdecl window_register_diagnostic(const char* format, std::uint32_t error) {
    reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t)>(
        diagnostic_handler_005debf0)(format, error);
}

void __cdecl timer_diagnostic_boundary(const char* message, ...) {
    char buf[512];
    std::va_list ap;
    va_start(ap, message);
    (void)std::vsnprintf(buf, sizeof(buf), message, ap);
    va_end(ap);
    reinterpret_cast<void(__cdecl*)(const char*, const char*)>(
        diagnostic_handler_005debf0)("%s", buf);
}

} // namespace porsche
