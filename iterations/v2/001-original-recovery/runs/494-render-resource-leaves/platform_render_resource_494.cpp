#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstddef>
#include "render_resource_494.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/window_shutdown.hpp"
namespace porsche {
static_assert(sizeof(MEMORYSTATUS)==32&&offsetof(MEMORYSTATUS,dwTotalPhys)==8,
    "original x86 MEMORYSTATUS layout");
void __stdcall render_resource_global_memory_status_005b2140(void* status){
    ::GlobalMemoryStatus(static_cast<LPMEMORYSTATUS>(status));
}
std::uint32_t __stdcall window_shutdown_close_handle_006bd92c(void* handle){
    using Unlock=std::uint32_t(__stdcall*)(void*);
    return reinterpret_cast<Unlock>(render_thrash_exports_006bd910[7])(handle);
}
}
