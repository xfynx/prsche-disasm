#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "render_driver_start_518.hpp"
namespace porsche {
static_assert(sizeof(HKEY)==4&&sizeof(LSTATUS)==4,"original x86 registry import ABI");
std::uint32_t __stdcall render_driver_reg_flush_005b2004(std::uint32_t key){
    return static_cast<std::uint32_t>(::RegFlushKey(reinterpret_cast<HKEY>(static_cast<std::uintptr_t>(key))));
}
}
