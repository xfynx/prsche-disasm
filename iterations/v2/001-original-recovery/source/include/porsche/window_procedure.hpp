#pragma once
#include <cstdint>
#include "porsche/window_state.hpp"

namespace porsche {
// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
using WindowHandler = std::uint32_t (__stdcall *)(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
struct WindowHandlerEntry { std::uint32_t message; WindowHandler handler; };
static_assert(sizeof(WindowHandlerEntry)==8);
extern WindowHandlerEntry window_handlers_0069e0e0[128];
extern std::uint32_t window_handler_count_0069e570;
using SearchCompare = std::int32_t (__cdecl *)(const void*,const void*);
std::int32_t __cdecl window_message_compare_0053a7f0(const void*,const void*);
void* __cdecl original_binary_search_005a2f23(const void*,void*,std::uint32_t,
    std::uint32_t,SearchCompare);
std::int32_t __stdcall window_default_procedure(void*,std::uint32_t,std::uint32_t,std::int32_t);
std::int32_t __stdcall window_procedure_0053aba0(void*,std::uint32_t,std::uint32_t,std::int32_t);
}
