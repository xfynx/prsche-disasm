#include "porsche/window_runtime.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::uint32_t change_tick;
std::vector<std::string> calls;
std::int32_t metric_width,metric_height,rect_delta;
bool create_success;
std::uint32_t __cdecl callback0(std::uint32_t a, std::uint32_t elapsed) {
    calls.push_back("[0,"+std::to_string(a)+","+std::to_string(elapsed)+"]");
    if (change_tick) porsche::current_tick_006b7c40 = change_tick;
    return 1;
}
std::uint32_t __cdecl callback1(std::uint32_t a, std::uint32_t elapsed) {
    calls.push_back("[1,"+std::to_string(a)+","+std::to_string(elapsed)+"]");
    return 2;
}
}
namespace porsche {
std::int32_t __stdcall window_get_system_metrics(std::int32_t index) {
    calls.push_back("[\"metrics\","+std::to_string(index)+"]");
    return index?metric_height:metric_width;
}
std::uint32_t __stdcall window_adjust_rect(WindowRect* rect,std::uint32_t style,std::int32_t menu,std::uint32_t exstyle) {
    calls.push_back("[\"adjust\","+std::to_string(rect->left)+","+std::to_string(rect->top)+","+
        std::to_string(rect->right)+","+std::to_string(rect->bottom)+","+std::to_string(style)+","+
        std::to_string(menu)+","+std::to_string(exstyle)+"]");
    rect->left-=rect_delta;rect->top-=rect_delta;rect->right+=rect_delta;rect->bottom+=rect_delta;
    return 1;
}
void* __stdcall window_create_ex(std::uint32_t exstyle,const char* cls,const char* title,std::uint32_t style,
    std::int32_t x,std::int32_t y,std::int32_t w,std::int32_t h,void* parent,void* menu,void* instance,void* parameter) {
    calls.push_back("[\"create\","+std::to_string(exstyle)+",\""+cls+"\",\""+title+"\","+
        std::to_string(style)+","+std::to_string(x)+","+std::to_string(y)+","+std::to_string(w)+","+
        std::to_string(h)+","+std::to_string(reinterpret_cast<std::uintptr_t>(parent))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(menu))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(instance))+","+
        std::to_string(reinterpret_cast<std::uintptr_t>(parameter))+"]");
    return create_success?reinterpret_cast<void*>(0x1230000):nullptr;
}
void* __stdcall window_set_cursor(void* value) {
    calls.push_back("[\"set_cursor\","+std::to_string(reinterpret_cast<std::uintptr_t>(value))+"]");return nullptr;
}
std::int32_t __stdcall window_show_cursor(std::int32_t value) {
    calls.push_back("[\"show_cursor\","+std::to_string(value)+"]");return 0;
}
void __cdecl window_channel_005739b0(std::uint32_t channel,std::uint32_t value) {
    calls.push_back("[\"channel\","+std::to_string(channel)+","+std::to_string(value)+"]");
}
}
int main(int argc,char** argv) {
    if(argc>1 && std::string(argv[1])=="--defaults") {
        std::cout<<"["<<porsche::window_style_005dea88<<","
                 <<static_cast<unsigned>(porsche::window_style_flag_005dead4)<<"]\n";
        return 0;
    }
    std::string line;
    while (std::getline(std::cin,line)) {
        std::istringstream in(line);
        if (argc>1) {
            std::uint32_t fullscreen,positioned,flag20,override,channels,success,style,state;
            std::int32_t x,y,w,h;
            in>>fullscreen>>positioned>>flag20>>override>>channels>>success>>style>>x>>y>>w>>h
              >>metric_width>>metric_height>>rect_delta>>state;
            if (!in) return 3;
            std::uint8_t config[0x480]{};
            auto set=[&](std::uint32_t offset,std::int32_t value){std::memcpy(config+offset,&value,4);};
            auto get=[&](std::uint32_t offset){std::int32_t value;std::memcpy(&value,config+offset,4);return value;};
            set(0x14,w);set(0x18,h);set(0x458,positioned);config[0x461]=static_cast<std::uint8_t>(fullscreen);
            set(0x468,x);set(0x46c,y);
            porsche::window_style_005dea88=style;porsche::window_style_flag_005dead4=flag20?0x20:0;
            porsche::window_override_0069e5b0=override;porsche::window_override_x_006bda00=35;
            porsche::window_override_y_006bda04=45;
            porsche::window_class_name_0069e5a8="Class";
            porsche::window_instance_006b7794=reinterpret_cast<void*>(0x1234000);
            porsche::window_create_state_005de024=state;
            porsche::window_channels_initialized_0069e5a0=channels;create_success=success!=0;calls.clear();
            void* result=porsche::window_create_0053bb00(config);
            std::cout<<"{\"result\":"<<reinterpret_cast<std::uintptr_t>(result)
                     <<",\"x\":"<<get(0x468)<<",\"y\":"<<get(0x46c)
                     <<",\"state\":"<<porsche::window_create_state_005de024<<",\"calls\":[";
            for(std::size_t i=0;i<calls.size();++i){if(i)std::cout<<',';std::cout<<calls[i];}
            std::cout<<"]}\n";
            continue;
        }
        std::uint32_t last,tick,next0,period0,enabled0,active0,next1,period1,enabled1,active1,arg;
        in>>last>>tick>>next0>>period0>>enabled0>>active0>>next1>>period1>>enabled1>>active1>>arg>>change_tick;
        if (!in) return 2;
        std::memset(porsche::timed_callbacks_0069dd20,0,sizeof(porsche::timed_callbacks_0069dd20));
        auto& first=porsche::timed_callbacks_0069dd20[0];
        first.callback=enabled0?callback0:nullptr;first.period=period0;first.next_tick=next0;first.active=active0;
        auto& second=porsche::timed_callbacks_0069dd20[1];
        second.callback=enabled1?callback1:nullptr;second.period=period1;second.next_tick=next1;second.active=active1;
        porsche::last_callback_tick_0069de24=last;porsche::current_tick_006b7c40=tick;calls.clear();
        auto result=porsche::timed_callbacks_005366e0(arg);
        std::cout<<"{\"result\":"<<result<<",\"last\":"<<porsche::last_callback_tick_0069de24
                 <<",\"tick\":"<<porsche::current_tick_006b7c40<<",\"slots\":["
                 <<first.next_tick<<","<<first.active<<","<<second.next_tick<<","<<second.active
                 <<"],\"calls\":[";
        for (std::size_t i=0;i<calls.size();++i) {if(i)std::cout<<',';std::cout<<calls[i];}
        std::cout<<"],\"noop\":"<<porsche::startup_noop_005367b0(1,2,3)<<"}\n";
    }
}
