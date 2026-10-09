#include "porsche/render_event_route.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_create.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_state.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

namespace porsche {
std::uint32_t render_thrash_exports_006bd910[43]{};
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* class_lock_0069e59c{};
namespace {
struct Event {std::uint32_t kind,a,b,c,d;};
std::vector<Event> events;
std::uint32_t client_ok{},offset_x{},offset_y{},about[16]{};
}
const std::uint32_t* __cdecl render_loader_about_006bd934(std::uint32_t) {return about;}
void __cdecl heap_enter_005322b0(void* lock) {
    events.push_back({1,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(lock)),0,0,0});
}
void __cdecl heap_leave_005322c0(void* lock) {
    events.push_back({5,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(lock)),0,0,0});
}
std::uint32_t __stdcall window_position_client_to_screen(void* hwnd,WindowPositionPoint* point) {
    const auto in_x=point->x,in_y=point->y;
    if(client_ok){point->x+=static_cast<std::int32_t>(offset_x);point->y+=static_cast<std::int32_t>(offset_y);}
    events.push_back({2,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(hwnd)),
      static_cast<std::uint32_t>(in_x),static_cast<std::uint32_t>(in_y),client_ok});
    return client_ok;
}
std::int32_t __stdcall render_event_set_cursor_pos(std::int32_t x,std::int32_t y) {
    events.push_back({3,static_cast<std::uint32_t>(x),static_cast<std::uint32_t>(y),0,0});return 1;
}
void* __stdcall render_event_set_cursor(void* cursor) {
    events.push_back({4,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(cursor)),0,0,0});return nullptr;
}
void __cdecl render_event_invoke_callback_005debec(std::uint32_t callback,std::uint32_t mode) {
    events.push_back({6,callback,mode,0,0});
}
}

int main() {
    using namespace porsche;
    std::uint32_t route,gate,lock,callback,x,y,flags,down;
    std::uint32_t bounds[4],last[2],client,dx,dy,driver_args[6];
    while(std::cin>>route>>gate>>lock>>callback>>x>>y>>flags>>down
      >>bounds[0]>>bounds[1]>>bounds[2]>>bounds[3]>>last[0]>>last[1]
      >>client>>dx>>dy>>driver_args[0]>>driver_args[1]>>driver_args[2]
      >>driver_args[3]>>driver_args[4]>>driver_args[5]) {
        events.clear();client_ok=client;offset_x=dx;offset_y=dy;
        render_event_dispatch_gate_005deaac=gate;
        render_event_callback_pointer_005debec=callback;
        class_lock_0069e59c=reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock));
        window_configuration_storage_006b77a0.hwnd_006b7bf8=reinterpret_cast<void*>(0x87654321);
        render_driver_bounds_a_006a643c=bounds[0];render_driver_bounds_b_006a6438=bounds[1];
        render_driver_bounds_c_006a6430=bounds[2];render_driver_bounds_d_006a6434=bounds[3];
        render_driver_limit_a_006a6448=last[0];render_driver_limit_b_006a6444=last[1];
        render_driver_limit_c_006a6440=0xdeadbeef;
        std::uint32_t result=0;
        if(route==0) result=window_message_mouse_event_005728b0(x,y,flags,down);
        else render_display_video_base_00537600(driver_args[0],driver_args[1],driver_args[2],
            driver_args[3],driver_args[4],driver_args[5]);
        std::cout<<"{\"events\":[";
        for(std::size_t i=0;i<events.size();++i){const auto&e=events[i];if(i)std::cout<<',';
            std::cout<<'['<<e.kind<<','<<e.a<<','<<e.b<<','<<e.c<<','<<e.d<<']';}
        std::cout<<"],\"state\":["<<render_driver_limit_c_006a6440<<','
          <<render_driver_limit_a_006a6448<<','<<render_driver_limit_b_006a6444
          <<"],\"result\":"<<result<<"}\n";
    }
}
