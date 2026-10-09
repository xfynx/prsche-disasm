#pragma once
#include <cstdint>
#include "porsche/window_create.hpp"
#include "porsche/window_procedure.hpp"

namespace porsche {
// Shared state identities owned by window_create/window_worker implementations.
extern std::uint32_t worker_message_state_0069e578;

// Original CRT qsort boundary; no replacement algorithm is wired into production.
void __cdecl window_handler_sort_005a112b(void*,std::uint32_t,std::uint32_t,
    std::int32_t (__cdecl*)(const void*,const void*));

// Win32 boundaries called by the recovered message-handler functions.
void __stdcall window_handler_post_quit_message(std::uint32_t);

// All eight registered callbacks use the original six-argument stdcall ABI
// and return with RET 0x18.
std::uint32_t __stdcall window_handler_0053b040(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b230(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b260(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b290(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b2a0(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b2e0(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b870(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);
std::uint32_t __stdcall window_handler_0053b8b0(void*,void*,std::uint32_t,
    std::uint32_t,std::int32_t,std::int32_t*);

// Original 0053a800 table mutation entry; declared here for standalone probes.
std::uint32_t __stdcall window_handler_register_0053a800(std::uint32_t, std::uint32_t);
}
