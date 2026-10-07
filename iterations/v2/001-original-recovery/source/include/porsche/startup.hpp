#pragma once
#include <cstdint>

// Porsche.exe SHA ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original global VAs are identities, not required addresses in the probe.
namespace porsche {
static_assert(sizeof(void*) == 4, "Original Windows x86 ABI required");
extern char* argv_0065b20c[32];
extern std::int32_t argc_0065b294;

// 0x004b6a50: still unrecovered. Only the verification executable supplies a
// recording boundary; there is no game target with a replacement implementation.
std::int32_t __cdecl app_main_004b6a50(std::int32_t argc, char** argv);

// 0x004b6710..0x004b67a4, RET 0x10. The three unused parameters are retained.
std::int32_t __stdcall win_main_004b6710(void* instance, void* previous,
                                      char* command_line, std::int32_t show);
}
