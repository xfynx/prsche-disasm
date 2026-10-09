#include "porsche/window_create.hpp"
#include "porsche/window_callback_bindings.hpp"

namespace porsche {
// Full 0053ac20..0053b03f. Every nontrivial callee below is an explicit
// boundary. The worker's own HWND/message-loop algorithm is separate.
std::uint32_t __cdecl window_init_0053ac20(std::uint32_t width,std::uint32_t height,std::uint32_t fullscreen) {
    if (!window_register_prefix_0053ac20()) return 0;
    if (!window_handlers_registered_0069e598) {
        window_input_lock_0069e564=window_lock_create_005321f0();
        window_input_capacity_0069e560=0x20;
        window_input_read_0069e0d8=0;
        window_input_write_0069e568=0;
        constexpr std::uint32_t handlers[][2]={
            {0x1c,0x53b040},{6,0x53b050},{5,0x53b360},{3,0x53b360},
            {0x10,0x53b230},{2,0x53b290},{0xf,0x53b7d0},{0x14,0x53b870},
            {0x1a,0x53b2e0},{0x112,0x53b2a0},{0x466,0x53b260},
            {0x102,0x53b3d0},{0x100,0x53b450},{0x104,0x53b450},
            {0x101,0x53b6b0},{0x105,0x53b6b0},{0x201,0x53b710},
            {0x207,0x53b710},{0x204,0x53b710},{0x203,0x53b710},
            {0x209,0x53b710},{0x206,0x53b710},{0x202,0x53b770},
            {0x208,0x53b770},{0x205,0x53b770},{0x200,0x53b770},
            {0x218,0x53b8b0}};
        // Original literal code addresses become native C++ callback addresses.
        // No guest VA is stored as an executable pointer in the rebuilt table.
        for(const auto& row:handlers) {
            const auto callback=window_callback_resolve(row[1]);
            if(!callback)return 0; // An incomplete reconstruction cannot start.
            window_handler_register_0053a800(row[0],static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(callback)));
        }
        window_handlers_registered_0069e598=1;
    } else if (window_hwnd_006b7bf8 && fullscreen!=window_fullscreen_006b7c01) {
        window_resize_0053bec0(width,height);
        return 1;
    }
    window_running_006b7c14=1;
    window_width_006b77b4=width;
    window_height_006b77b8=height;
    window_fullscreen_006b7c01=static_cast<std::uint8_t>(fullscreen);
    std::uint32_t state[7]{};
    if (!window_thread_start_0055f420(reinterpret_cast<void*>(&window_worker_thread_entry),0,1,0xffffffffu,state))return 0;
    while(!window_thread_handle_0069e574) {
        window_timed_callback_005366e0(0);
        window_idle_0055f740(0);
    }
    if(window_hwnd_006b7bf8)window_prepare_0053bcb0();
    window_thread_wait_0055fb30(window_thread_handle_0069e574);
    while(window_thread_handle_0069e574) {
        window_idle_0055f740(0);
        window_timed_callback_005366e0(0);
    }
    window_thread_handle_0069e574=nullptr;
    for(std::uint32_t i=0;i<7;++i)window_worker_state_006bd9e0[i]=state[i];
    if(!window_fullscreen_006b7c01) {
        window_set_foreground(window_hwnd_006b7bf8);
        window_resize_0053bec0(width,height);
        window_saved_parameter_0069e57c=0;
        window_saved_parameter_0069e580=0;
    } else {
        window_system_parameters(0x10,0,&window_saved_parameter_0069e57c,0);
        window_system_parameters(0x54,0,&window_saved_parameter_0069e580,0);
        if(window_saved_parameter_0069e57c)window_system_parameters(0x11,0,nullptr,2);
        if(window_saved_parameter_0069e580)window_system_parameters(0x56,0,nullptr,2);
    }
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(window_hwnd_006b7bf8));
}
}
