#include "porsche/window_position.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {
namespace {
std::int32_t wrap_add(std::int32_t a,std::int32_t b) {
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(a)+static_cast<std::uint32_t>(b));
}
std::int32_t wrap_sub(std::int32_t a,std::int32_t b) {
    return static_cast<std::int32_t>(static_cast<std::uint32_t>(a)-static_cast<std::uint32_t>(b));
}
}
// 0053bcb0..0053bd3f. Calls retained as typed boundaries where their own
// algorithms or USER32 behavior are outside this recovered body.
void __cdecl window_position_cleanup_0053bcb0() {
    if(window_hwnd_006b7bf8) {
        if(window_saved_parameter_0069e57c)
            window_system_parameters(0x11,window_saved_parameter_0069e57c,nullptr,2);
        if(window_saved_parameter_0069e580)
            window_system_parameters(0x56,window_saved_parameter_0069e580,nullptr,2);
        window_position_remove_0053a8e0(0x466,0,0,0);
        while(window_hwnd_006b7bf8) {
            window_position_idle_0055f740(0);
            window_position_timed_005366e0(0);
        }
    }
    if(class_refcount_0069e594) {
        --class_refcount_0069e594;
        if(!class_refcount_0069e594)
            window_position_unregister_class(window_class_name_0069e5a8,
                                               window_instance_006b7794);
    }
}

// 0053bd40..0053bebd. RECT locals are initialized by the two PUSHes at
// bd7e/bd80 and stores at bd81..bd95. Calls below retain Win32 boundaries.
void __cdecl window_position_resize_0053bd40(std::int32_t x,std::int32_t y,
                                             std::int32_t width,std::int32_t height) {
    auto hwnd=window_hwnd_006b7bf8;
    WindowPositionRect rect{};
    if(width==0 || height==0) {
        window_position_get_client_rect(hwnd,&rect);
        width=rect.right;
        height=rect.bottom;
    }
    rect.right=width;
    rect.bottom=height;
    const auto exstyle=static_cast<std::uint32_t>(window_position_get_window_long(hwnd,-20));
    rect.left=0;
    rect.top=0;
    const auto style=static_cast<std::uint32_t>(window_position_get_window_long(hwnd,-16));
    window_position_adjust_window_rect_ex(&rect,style,0,exstyle);

    std::int32_t left=0,top=0;
    if(window_override_0069e5b0) {
        left=window_override_x_006bda00;
        top=window_override_y_006bda04;
    } else if(x!=0 && y!=0) {
        left=wrap_add(x,rect.left);
        top=wrap_add(y,rect.top);
    } else {
        WindowPositionRect work{};
        window_position_system_parameters(0x30,0,&work,0);
        const auto work_width=wrap_sub(wrap_sub(work.right,work.left),wrap_sub(rect.right,rect.left));
        const auto work_height=wrap_sub(wrap_sub(work.bottom,work.top),wrap_sub(rect.bottom,rect.top));
        left=wrap_add(work_width>>1,work.left);
        top=wrap_add(work_height>>1,work.top);
    }
    window_position_set_window_pos(hwnd,nullptr,left,top,
        wrap_sub(rect.right,rect.left),wrap_sub(rect.bottom,rect.top),0x14);

    WindowPositionRect client{};
    window_position_get_client_rect(hwnd,&client);
    auto* point_a=reinterpret_cast<WindowPositionPoint*>(&client.left);
    auto* point_b=reinterpret_cast<WindowPositionPoint*>(&client.right);
    window_position_client_to_screen(hwnd,point_a);
    window_position_client_to_screen(hwnd,point_b);
    window_pos_x_006b7c08=left;
    window_pos_y_006b7c0c=top;
    window_width_006b77b4=static_cast<std::uint32_t>(wrap_sub(point_b->x,point_a->x));
    window_height_006b77b8=static_cast<std::uint32_t>(wrap_sub(point_b->y,point_a->y));
}

// 0053bec0..0053bef6. Signed divide-by-two correction matches CDQ/SUB/SAR.
void __cdecl window_position_center_0053bec0(std::int32_t width,std::int32_t height) {
    const auto screen_height=window_position_get_system_metrics(1);
    const std::int32_t diff_y=screen_height-height;
    const auto center_y=(diff_y-(diff_y<0?-1:0))>>1;
    const auto screen_width=window_position_get_system_metrics(0);
    const std::int32_t diff_x=screen_width-width;
    const auto center_x=(diff_x-(diff_x<0?-1:0))>>1;
    window_position_resize_0053bd40(center_x,center_y,width,height);
}
}
