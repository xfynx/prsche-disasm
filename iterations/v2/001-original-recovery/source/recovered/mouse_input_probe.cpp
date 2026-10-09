#include "porsche/mouse_input.hpp"
#include "porsche/render_driver_calls.hpp"
#include "porsche/render_event_route.hpp"
#include "porsche/window_create.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> events;
std::uint32_t canonical(const void* pointer) {
    if(pointer==&porsche::window_configuration_storage_006b77a0)return 0x006b77a0;
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(pointer));
}
void push(std::uint32_t tag,std::uint32_t a=0,std::uint32_t b=0,
          std::uint32_t c=0) {
    std::ostringstream line;
    line<<'['<<tag<<','<<a<<','<<b<<','<<c<<']';
    events.push_back(line.str());
}
std::int32_t as_i32(std::uint32_t value) {
    std::int32_t out;std::memcpy(&out,&value,sizeof(out));return out;
}
}

namespace porsche {
std::uint32_t render_driver_bounds_a_006a643c{},render_driver_bounds_b_006a6438{};
std::uint32_t render_driver_bounds_c_006a6430{},render_driver_bounds_d_006a6434{};
std::uint32_t render_driver_limit_a_006a6448{},render_driver_limit_b_006a6444{};
std::uint32_t render_driver_limit_c_006a6440{};
std::uint32_t render_event_dispatch_gate_005deaac{};
std::uint32_t render_event_callback_pointer_005debec{};
void* class_lock_0069e59c{};
OriginalWindowConfiguration window_configuration_storage_006b77a0{};

void __cdecl heap_enter_005322b0(void* lock) { push(1,canonical(lock)); }
void __cdecl heap_leave_005322c0(void* lock) { push(3,canonical(lock)); }
void __cdecl render_event_set_cursor_position_0053a970(
    void* config,std::int32_t x,std::int32_t y) {
    push(2,canonical(config),static_cast<std::uint32_t>(x),static_cast<std::uint32_t>(y));
}
void __cdecl render_event_invoke_callback_005debec(std::uint32_t callback,
                                                    std::uint32_t argument) {
    push(4,callback,argument);
}
std::uint32_t __cdecl render_event_default_callback_005367b0(std::uint32_t) {
    return 0;
}
}

int main() {
    std::uint32_t gate,lock,callback,x,y,mask,transition;
    std::uint32_t low_x,low_y,high_x,high_y,last_x,last_y;
    while(std::cin>>gate>>lock>>callback>>x>>y>>mask>>transition>>low_x>>low_y
                  >>high_x>>high_y>>last_x>>last_y) {
        events.clear();
        using namespace porsche;
        render_event_dispatch_gate_005deaac=gate;
        render_event_callback_pointer_005debec=callback;
        class_lock_0069e59c=lock?reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)):nullptr;
        render_driver_bounds_a_006a643c=low_x;render_driver_bounds_b_006a6438=low_y;
        render_driver_bounds_c_006a6430=high_x;render_driver_bounds_d_006a6434=high_y;
        render_driver_limit_a_006a6448=last_x;render_driver_limit_b_006a6444=last_y;
        render_driver_limit_c_006a6440=0xdeadbeef;
        mouse_input_consumer_005728b0(x,y,mask,transition);
        std::cout<<"{\"events\":[";
        for(std::size_t i=0;i<events.size();++i) {
            if(i)std::cout<<',';
            std::cout<<events[i];
        }
        std::cout<<"],\"state\":["<<render_driver_limit_c_006a6440<<','
                 <<render_driver_limit_a_006a6448<<','
                 <<render_driver_limit_b_006a6444<<"]}\n";
    }
}
