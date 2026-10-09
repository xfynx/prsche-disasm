#include "porsche/render_window.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

namespace porsche {
std::uint32_t render_display_mode_index_00619780;
RenderDisplay* render_display_00628130;
namespace {
std::vector<std::vector<std::int64_t>> events;
std::uint32_t record_seed;
std::int32_t cursor_values[4];
std::uint32_t cursor_count,cursor_index;
void event(std::initializer_list<std::int64_t> values) { events.emplace_back(values); }
}

void __cdecl window_position_resize_0053bd40(std::int32_t x,std::int32_t y,
    std::int32_t width,std::int32_t height) {
    event({1,x,y,width,height});
}
void __cdecl render_window_query_mode_info_0044e720(std::uint32_t index,
    std::uint32_t* record10) {
    event({2,index,render_display_00628130?1:0});
    for(std::uint32_t i=0;i<10;++i)record10[i]=record_seed+i;
}
void __cdecl render_window_driver_select_mode_vslot7(void* driver,std::uint32_t index) {
    event({3,index,driver?1:0});
}
void __cdecl render_window_commit_mode_0044ebf0(std::uint32_t index) { event({4,index}); }
void __cdecl render_window_time_update_0044ed10() { event({5}); }
void __cdecl render_window_video_base_00537600(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t width,std::uint32_t height,std::uint32_t f) {
    event({6,a,b,c,width,height,f});
}
std::int32_t __stdcall render_window_show_cursor(std::int32_t show) {
    const auto value=cursor_index<cursor_count?cursor_values[cursor_index]:-1;
    ++cursor_index;event({7,show,value});return value;
}
}

int main() {
    std::uint32_t result,current,fullscreen,seed,count;
    std::int32_t c0,c1,c2,c3;
    while(std::cin>>result>>current>>fullscreen>>seed>>count>>c0>>c1>>c2>>c3) {
        using namespace porsche;
        RenderDisplay display{};
        std::uint32_t driver_marker=0x44525652;
        const auto driver=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&driver_marker));
        std::memcpy(display.bytes+0x70,&driver,4);
        display.bytes[0x60]=static_cast<std::uint8_t>(fullscreen);
        render_display_00628130=&display;
        render_display_mode_index_00619780=current;
        events.clear();record_seed=seed;
        cursor_count=count;cursor_index=0;
        cursor_values[0]=c0;cursor_values[1]=c1;cursor_values[2]=c2;cursor_values[3]=c3;
        render_display_video_result_00468030(&display,result);
        std::uint32_t field{};std::memcpy(&field,display.bytes+0x68,4);
        std::cout<<"{\"field\":"<<field<<",\"events\":[";
        for(std::size_t i=0;i<events.size();++i) {
            if(i)std::cout<<',';std::cout<<'[';
            for(std::size_t j=0;j<events[i].size();++j) {
                if(j)std::cout<<',';std::cout<<events[i][j];
            }
            std::cout<<']';
        }
        std::cout<<"]}\n";
    }
}
