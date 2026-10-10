#pragma once
#include <cstdint>

namespace porsche {
// Porsche.exe ddd748fd...: 005a246e forwards code to the full CRT shutdown
// path at 005a2490 with both policy arguments zero. The final ExitProcess
// boundary is nonreturning in production.
[[noreturn]] void __cdecl process_exit_005a246e(std::uint32_t code);
}
