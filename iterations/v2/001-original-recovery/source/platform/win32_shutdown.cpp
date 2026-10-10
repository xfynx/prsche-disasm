#include "porsche/exit_shutdown.hpp"

#include <windows.h>

namespace porsche {
// Original 005a2490 reaches KERNEL32 IAT 005b2094/005b216c/005b21a8.
// Platform bindings only; the recovered CRT caller owns callback/state order.
void* __cdecl exit_shutdown_get_current_process() {
    return ::GetCurrentProcess();
}

std::int32_t __cdecl exit_shutdown_terminate_process(
    void* process, std::uint32_t code) {
    return ::TerminateProcess(static_cast<HANDLE>(process), code);
}

void __cdecl exit_shutdown_exit_process(std::uint32_t code) {
    ::ExitProcess(code);
}
} // namespace porsche
