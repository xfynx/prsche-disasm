#include "porsche/heap.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_event_queue.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_worker.hpp"
#include "porsche/window_scheduler.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/render_event_route.hpp"
#include "porsche/object_cleanup.hpp"
#include "porsche/window_event_translation.hpp"

#include <array>
#include <cstring>
#include <cstdlib>

namespace porsche {
namespace {
using ExitCallback = void(__cdecl*)();
std::array<ExitCallback,8> exit_callbacks{};
std::size_t exit_callback_count=0;
bool exit_dispatcher_registered=false;

void __cdecl run_host_exit_callbacks() {
    while(exit_callback_count)exit_callbacks[--exit_callback_count]();
}
}

// These typed boundaries exist only to make the complete recovered window
// object graph linkable. None may silently fabricate successful game state.
void __cdecl window_register_diagnostic(const char*,std::uint32_t) { std::abort(); }
const std::uint8_t* __cdecl window_event_key_state_0055feb0(std::uint32_t) { std::abort(); }
// 00557380 forwards the callback into the process-exit registry at 005a2400.
// This fixture boundary registers its explicit callbacks with the host CRT;
// the recovered registration algorithm itself remains an open dependency.
void __cdecl thread_exit_register_00557380(ExitCallback callback) {
    if(!callback || exit_callback_count==exit_callbacks.size())std::abort();
    exit_callbacks[exit_callback_count++]=callback;
    if(!exit_dispatcher_registered) {
        if(std::atexit(run_host_exit_callbacks)!=0)std::abort();
        exit_dispatcher_registered=true;
    }
}

// 005a112b is the original CRT qsort import boundary. The callback body and
// comparator remain production code; only the replacement library call is
// supplied here for valid startup message IDs.
void __cdecl window_handler_sort_005a112b(void* base,std::uint32_t count,
    std::uint32_t width,std::int32_t(__cdecl* compare)(const void*,const void*)) {
    qsort(base,count,width,reinterpret_cast<int(__cdecl*)(const void*,const void*)>(compare));
}

// Run077 startup reaches this boundary at 0053222a with value == 0.
// Run068 proves nonzero inputs repeat a DWORD pattern, so this fixture-only
// host service deliberately rejects all inputs beyond the observed zero fill.
void __cdecl heap_fill_0053c290(void* target,std::uint32_t value,std::uint32_t size) {
    if(value!=0)std::abort();
    if(size && !target)std::abort();
    std::memset(target,0,size);
}
void __cdecl heap_format_005a0fbf(char*,const char*,const char*) { std::abort(); }
void __cdecl heap_copy_005b0100(void*,const void*,std::uint32_t) { std::abort(); }
void __cdecl heap_copy_005b02c0(void*,const void*,std::uint32_t) { std::abort(); }
void __cdecl heap_copy_005b0480(void*,const void*,std::uint32_t) { std::abort(); }

// Explicit BSS fixture owners for the renderer's input range. No renderer
// TU is linked in this window-only fixture. Original zero state gates input.
std::uint32_t render_driver_bounds_a_006a643c,render_driver_bounds_b_006a6438;
std::uint32_t render_driver_bounds_c_006a6430,render_driver_bounds_d_006a6434;
std::uint32_t render_driver_limit_a_006a6448,render_driver_limit_b_006a6444;
std::uint32_t render_driver_limit_c_006a6440;
void __cdecl render_event_invoke_callback_005debec(std::uint32_t,std::uint32_t) { std::abort(); }
void __cdecl window_worker_callback() { std::abort(); }
std::uint32_t __cdecl window_worker_idle_callback(std::uint32_t period,std::uint32_t delay,std::uint32_t callback) {
    if(callback!=0x0053bae0)std::abort();
    return window_scheduler_register_005365e0(&window_shutdown_callback_0053bae0,period,delay);
}
void __cdecl window_scheduler_diagnostic_00565340(const char*) { std::abort(); }
std::uint32_t __stdcall window_shutdown_close_handle_006bd92c(void*) { std::abort(); }
void __stdcall window_shutdown_display_callback_006bd9b0(std::uint32_t) { std::abort(); }
void __cdecl application_instance_exit_005a246e(std::uint32_t) { std::abort(); }

}
