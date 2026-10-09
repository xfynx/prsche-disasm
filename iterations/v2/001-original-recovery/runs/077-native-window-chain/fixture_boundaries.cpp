#include "porsche/heap.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_event_queue.hpp"
#include "porsche/window_handlers.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_worker.hpp"

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
std::uint32_t __cdecl window_event_translate_00560080(std::uint32_t,std::uint32_t) { std::abort(); }
std::uint8_t __cdecl window_message_translate_key_0069e5a0(std::uint32_t) { std::abort(); }
std::uint32_t __cdecl window_message_mouse_event_005728b0(std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t) { std::abort(); }
bool window_message_has_resize_notification_005df9b8() { std::abort(); }
std::uint32_t __cdecl window_message_resize_notification_005df9b8() { std::abort(); }
std::uint32_t __cdecl window_position_remove_0053a8e0(std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t) { std::abort(); }
std::uint32_t __cdecl window_worker_activation_00565560() { std::abort(); }
std::uint32_t __cdecl window_worker_focus_00573980() { std::abort(); }
void __cdecl window_worker_callback() { std::abort(); }
std::uint32_t __cdecl window_worker_idle_callback(std::uint32_t,std::uint32_t,std::uint32_t) { std::abort(); }
std::uint32_t __cdecl window_worker_prepare_exit_00558350(void*) { std::abort(); }
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

}
