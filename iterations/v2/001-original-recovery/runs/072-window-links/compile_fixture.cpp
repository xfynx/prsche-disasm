#include "porsche/file_events.hpp"
#include "porsche/file_device.hpp"
#include "porsche/file_worker.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/heap_locks.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_position.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_runtime.hpp"
#include "porsche/window_state.hpp"
#include "porsche/window_worker.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <type_traits>

static_assert(sizeof(void*)==4);
static_assert(std::is_same_v<decltype(&porsche::window_lock_create_005321f0),
                             void* (__cdecl*)()>);
static_assert(std::is_same_v<decltype(&porsche::window_worker_wait_0055fb20),
                             std::uint32_t (__cdecl*)()>);
static_assert(std::is_same_v<decltype(&porsche::window_worker_wait_0055fb90),
                             std::uint32_t (__cdecl*)(std::uint32_t)>);
static_assert(std::is_same_v<decltype(&porsche::window_worker_wait_0055fc10),
                             std::uint32_t (__cdecl*)(std::uint32_t)>);
static_assert(std::is_same_v<decltype(&porsche::window_thread_wait_0055fb30),
                             void (__cdecl*)(void*)>);

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* window_configuration_address_006b77a0=&window_configuration_storage_006b77a0;
void*& worker_configuration_006b77a0=window_configuration_address_006b77a0;
std::uint32_t& window_running_006b7c14=window_configuration_storage_006b77a0.running_006b7c14;
std::uint32_t& window_width_006b77b4=window_configuration_storage_006b77a0.width_006b77b4;
std::uint32_t& window_height_006b77b8=window_configuration_storage_006b77a0.height_006b77b8;
std::uint8_t& window_fullscreen_006b7c01=window_configuration_storage_006b77a0.fullscreen_006b7c01;
void*& window_hwnd_006b7bf8=window_configuration_storage_006b77a0.hwnd_006b7bf8;
std::int32_t& window_pos_x_006b7c08=window_configuration_storage_006b77a0.pos_x_006b7c08;
std::int32_t& window_pos_y_006b7c0c=window_configuration_storage_006b77a0.pos_y_006b7c0c;
void* thread_start_lock_006a57d8=nullptr;
void* class_lock_0069e59c=nullptr;
std::uint32_t class_refcount_0069e594=0;
std::uint32_t window_saved_parameter_0069e57c=0,window_saved_parameter_0069e580=0;

// Explicit non-platform edges required by the accepted heap-lock and position
// translation units. The fixture seeds the lock free list and does not call the
// allocator, thread initializer, or window-position removal boundary.
std::uint32_t threads_initialized_006a57dc=1;
void __cdecl thread_init_0055f320(std::uint32_t) { std::abort(); }
// This link-only fixture does not execute the real worker. Keep the typed
// thunk target explicitly closed instead of supplying a successful stub.
std::uint32_t __cdecl window_worker_0053b8d0() { std::abort(); }
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t*) { std::abort(); }
void __cdecl heap_fill_0053c290(void* dst,std::uint32_t value,std::uint32_t bytes) {
    std::memset(dst,static_cast<int>(value&0xff),bytes);
}
void __cdecl window_channel_005739b0(std::uint32_t,std::uint32_t) { std::abort(); }
std::uint32_t __cdecl window_position_remove_0053a8e0(std::uint32_t,std::uint32_t,
    std::uint32_t,std::uint32_t) { std::abort(); }

static std::uint32_t callback_count=0;
std::uint32_t __cdecl callback(std::uint32_t arg,std::uint32_t elapsed) {
    ++callback_count;return arg+elapsed;
}
}

int main() {
    using namespace porsche;

    HeapLockCell free_cell{};
    heap_lock_free_0069cb04=&free_cell;
    void* lock=window_lock_create_005321f0();
    if(lock!=&free_cell)return 1;
    const auto lock_word=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(lock));
    (void)window_message_pump_005322b0(lock_word);
    (void)window_worker_game_pump_005322b0(lock_word);
    (void)window_message_dispatch_005322c0(lock_word);
    (void)window_worker_game_dispatch_005322c0(lock_word);
    heap_lock_destroy_005322d0(lock);

    const auto event_word=window_worker_wait_0055fb20();
    if(!event_word)return 1;
    auto* event=reinterpret_cast<void*>(static_cast<std::uintptr_t>(event_word));
    window_thread_wait_0055fb30(event);
    if(window_worker_wait_0055fb90(event_word)!=event_word)return 2;
    if(!window_worker_wait_0055fc10(event_word))return 3;

    current_tick_006b7c40=20;last_callback_tick_0069de24=0;callback_count=0;
    timed_callbacks_0069dd20[0]={callback,5,10,0};
    if(window_timed_callback_005366e0(2)!=12 || callback_count!=1)return 4;
    current_tick_006b7c40=30;last_callback_tick_0069de24=0;
    timed_callbacks_0069dd20[0]={callback,3,25,0};
    if(window_position_timed_005366e0(4)!=9 || callback_count!=2)return 5;

    window_idle_0055f740(0);
    if(window_position_idle_0055f740(0)!=0)return 6;
    window_prepare_0053bcb0(); // Actual cleanup callee takes its proven no-window/no-lock path.

    // Force link references for the center/resize forwarding edge without
    // creating a GUI window; its USER32 calls are covered by the compile/link.
    volatile auto resize_link=&window_resize_0053bec0;
    if(!resize_link)return 7;
    return 0;
}
