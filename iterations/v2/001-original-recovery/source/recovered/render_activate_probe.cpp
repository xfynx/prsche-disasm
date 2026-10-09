#include "porsche/render_activate.hpp"
#include <cstring>
#include <iostream>

namespace porsche {
std::uint32_t render_display_actual_width_00619784;
std::uint32_t render_display_actual_height_00619788;
std::uint32_t render_display_actual_mode_0061978c;
struct Trace { std::uint32_t calls,args[5],result_calls,result; } trace{};

std::uint32_t __cdecl render_activate_video_mode_005376c0(
    std::uint32_t w,std::uint32_t h,std::uint32_t mode,std::uint32_t transition,
    std::uint32_t one) {
    trace.calls++;
    trace.args[0]=w;trace.args[1]=h;trace.args[2]=mode;
    trace.args[3]=transition;trace.args[4]=one;
    return trace.result;
}
void __cdecl render_display_video_result_00468030(RenderDisplay* display,
    std::uint32_t result) {
    trace.result_calls++;
    std::memcpy(display->bytes+0x68,&result,4);
}
}

int main() {
    std::uint32_t aw,ah,am,w,h,m,transition,fullscreen,result;
    while(std::cin>>aw>>ah>>am>>w>>h>>m>>transition>>fullscreen>>result) {
        using namespace porsche;
        RenderDisplay display{};
        display.bytes[0x60]=static_cast<std::uint8_t>(fullscreen);
        render_display_actual_width_00619784=aw;
        render_display_actual_height_00619788=ah;
        render_display_actual_mode_0061978c=am;
        trace={};trace.result=result;
        render_display_reconfigure_00467fc0(&display,w,h,m,transition);
        std::uint32_t field{};std::memcpy(&field,display.bytes+0x68,4);
        std::cout<<trace.calls<<' '<<trace.result_calls<<' '<<trace.args[0]<<' '
          <<trace.args[1]<<' '<<trace.args[2]<<' '<<trace.args[3]<<' '
          <<trace.args[4]<<' '<<field<<'\n';
    }
}
