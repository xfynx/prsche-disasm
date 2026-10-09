#include "porsche/window_support.hpp"
#include "porsche/window_create.hpp"

namespace porsche {

// 006a64a0 is in the PE .data virtual zero-fill tail. Keep it as an opaque
// canonical DWORD; 00573980 is a getter and the producer is outside this unit.
std::uint32_t window_support_opaque_value_006a64a0=0;

// 0053a8e0. Preserve the observed API argument order: original arg2 is pushed
// as WPARAM and arg1 as LPARAM. arg3 selects SendNotifyMessageA when nonzero.
std::uint32_t __cdecl window_position_remove_0053a8e0(
    std::uint32_t arg0,std::uint32_t arg1,std::uint32_t arg2,std::uint32_t arg3) {
    const auto hwnd=window_hwnd_006b7bf8;
    if(!hwnd)return 0;
    if(arg3) return window_support_send_notify_message_a(
        hwnd,arg0,arg2,static_cast<std::int32_t>(arg1))==0 ? 1u : 0u;
    if(window_support_post_message_a(hwnd,arg0,arg2,
        static_cast<std::int32_t>(arg1))!=0)return 1;
    return window_support_get_last_error()==0 ? 1u : 0u;
}

// 00565560.
std::uint32_t __cdecl window_worker_activation_00565560() {
    return window_running_006b7c14!=0 && window_hwnd_006b7bf8!=nullptr ? 1u : 0u;
}

// 00573980.
std::uint32_t __cdecl window_worker_focus_00573980() {
    return window_support_opaque_value_006a64a0;
}

}
