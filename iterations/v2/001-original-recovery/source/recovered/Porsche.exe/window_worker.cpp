#include "porsche/window_worker.hpp"

namespace porsche {
std::uint32_t worker_message_state_0069e578=0;
std::int32_t& window_pos_x_006b7c08=window_configuration_storage_006b77a0.pos_x_006b7c08;
std::int32_t& window_pos_y_006b7c0c=window_configuration_storage_006b77a0.pos_y_006b7c0c;
std::uint32_t worker_callback_0069e5a4=0;
std::uint32_t worker_accelerator_006bd9dc=0;

// 0053b8d0..0053bad8. The imported USER32 calls and unresolved helpers are
// kept as observable boundaries; branch and state updates follow the original.
std::uint32_t __cdecl window_worker_0053b8d0(void* configuration) {
    (void)configuration; // Original thread argument is unused; 0x6b77a0 is loaded directly.
    auto* config=static_cast<std::uint8_t*>(worker_configuration_006b77a0);
    void* const hwnd=window_create_0053bb00(config);
    const std::uint32_t tick=window_worker_wait_0055fb20();
    std::uint32_t result=0;
    window_thread_handle_0069e574=reinterpret_cast<void*>(static_cast<std::uintptr_t>(tick));
    window_worker_wait_0055fb90(tick);
    window_worker_wait_0055fc10(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(window_thread_handle_0069e574)));
    const bool fullscreen=window_fullscreen_006b7c01!=0;
    worker_message_state_0069e578=0;
    window_thread_handle_0069e574=nullptr;
    window_hwnd_006b7bf8=hwnd;

    WindowWorkerRect client{},screen{};
    if(!fullscreen) {
        window_worker_get_client_rect(hwnd,&client);
        window_worker_client_to_screen(hwnd,&screen);
        if(window_override_0069e5b0) {
            window_pos_x_006b7c08=window_override_x_006bda00;
            window_pos_y_006b7c0c=window_override_y_006bda04;
        } else {
            window_pos_x_006b7c08=screen.left;
            window_pos_y_006b7c0c=screen.top;
        }
    } else {
        window_worker_set_foreground_window(hwnd);
        if(window_override_0069e5b0) {
            window_pos_x_006b7c08=window_override_x_006bda00;
            window_pos_y_006b7c0c=window_override_y_006bda04;
        } else {
            window_pos_x_006b7c08=0;
            window_pos_y_006b7c0c=0;
        }
    }
    window_worker_set_active_window(hwnd);
    window_running_006b7c14=1;

    if(hwnd==window_hwnd_006b7bf8) {
        WindowWorkerMessage message{};
        for(;;) {
            if(window_worker_get_message(&message,nullptr,0,0)) {
                window_worker_game_pump_005322b0(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(class_lock_0069e59c)));
                const bool handled=!worker_accelerator_006bd9dc &&
                    window_worker_accelerator_0053b530(
                        message.message,message.wparam)!=0;
                if(!handled) {
                    window_worker_translate_message(&message);
                }
                window_worker_dispatch_message(&message);
                window_worker_game_dispatch_005322c0(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(class_lock_0069e59c)));
            } else if(worker_callback_0069e5a4) {
                window_worker_callback();
            } else {
                window_worker_idle_callback(1,10,0x53bae0);
            }

            if(worker_message_state_0069e578) {
                worker_message_state_0069e578=0;
                if(window_hwnd_006b7bf8 &&
                   *reinterpret_cast<const std::uint32_t*>(config+0x10)!=0)
                    window_worker_prepare_exit_00558350(config);
                result=window_worker_destroy_window(window_hwnd_006b7bf8);
                window_hwnd_006b7bf8=nullptr;
            }
            if(window_fullscreen_006b7c01) {
                if(window_worker_activation_00565560()) {
                    const auto focus=window_worker_focus_00573980();
                    result=focus?focus:static_cast<std::uint32_t>(window_worker_show_cursor(0));
                } else if(!window_worker_is_iconic(window_hwnd_006b7bf8)) {
                    result=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(
                        window_worker_set_foreground_window(window_hwnd_006b7bf8)));
                }
            }
            if(hwnd!=window_hwnd_006b7bf8)break;
        }
    }
    return result;
}
}
