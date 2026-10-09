#include "porsche/render_settings.hpp"
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
std::uint8_t render_mode_state_00619790[0x71]{};
std::uint32_t render_display_actual_width_00619784{};
std::uint32_t render_display_actual_height_00619788{};
std::uint32_t render_display_actual_mode_0061978c{};

namespace {
RenderSettingsDevice device{};
std::array<std::uint32_t,11> get_results{};
std::array<std::uint32_t,24> set_results{};
std::size_t get_index{},set_index{};
std::uint32_t trident_result{},voodoo_result{};
struct Event { std::string kind,key; std::uint32_t arg1{},arg2{},result{}; };
std::vector<Event> events;
template<class T> void put_device(std::size_t offset,T value) {
    std::memcpy(device.bytes+offset,&value,sizeof(value));
}
void print_events() {
    std::cout << '[';
    for(std::size_t i=0;i<events.size();++i) {
        const auto& e=events[i]; if(i) std::cout << ',';
        std::cout << "{\"kind\":\"" << e.kind << "\"";
        if(e.kind=="get") std::cout << ",\"key\":" << e.arg1 << ",\"result\":" << e.result;
        else if(e.kind=="set") std::cout << ",\"key\":" << e.arg1 << ",\"value\":" << e.arg2 << ",\"result\":" << e.result;
        else if(e.kind=="config") std::cout << ",\"key\":\"" << e.key << "\",\"destination\":" << e.arg1 << ",\"result\":" << e.result;
        std::cout << '}';
    }
    std::cout << ']';
}
}

const RenderSettingsDevice* __cdecl render_settings_current_device_006bd934() {
    events.push_back({"device"}); return &device;
}
std::uint32_t __stdcall render_settings_get_state_006bd984(std::uint32_t key) {
    const auto result=get_results.at(get_index++);
    events.push_back({"get",{},key,0,result}); return result;
}
std::uint32_t __stdcall render_settings_set_state_006bd97c(std::uint32_t key,std::uint32_t value) {
    const auto result=set_results.at(set_index++);
    events.push_back({"set",{},key,value,result}); return result;
}
std::int32_t __cdecl render_settings_read_config_005a1e10(char* output,const char* key) {
    const auto result=std::strcmp(key,"Trident Blade")==0 ? trident_result : voodoo_result;
    std::memcpy(output,"setting\0",8);
    events.push_back({"config",key,128,0,static_cast<std::uint32_t>(result)});
    return static_cast<std::int32_t>(result);
}
}

int main() {
    using namespace porsche;
    for (;;) {
        std::uint32_t id{},flags{},field44{},type{},surface{},global_value{},width{},height{},format{},seed{};
        std::int32_t min_a{},min_b{};
        if (!(std::cin>>id>>flags>>min_a>>min_b>>field44>>type>>surface>>global_value
            >>width>>height>>format>>trident_result>>voodoo_result>>seed)) break;
        for(auto& v:get_results) std::cin>>v;
        for(auto& v:set_results) std::cin>>v;
        std::memset(device.bytes,static_cast<int>(seed&0xff),sizeof(device.bytes));
        put_device(0x00,id);put_device(0x0c,flags);put_device(0x14,min_a);put_device(0x20,min_b);
        put_device(0x44,field44);put_device(0x6c,type);put_device(0x70,surface);
        std::memset(render_mode_state_00619790,static_cast<int>(seed&0xff),sizeof(render_mode_state_00619790));
        render_display_actual_width_00619784=width;render_display_actual_height_00619788=height;
        render_display_actual_mode_0061978c=format;render_settings_value_00657da4=global_value;
        get_index=set_index=0;events.clear();
        render_mode_apply_settings_0044e890();
        std::cout << "{\"state\":[";
        for(std::size_t i=0;i<sizeof(render_mode_state_00619790);++i)
            std::cout << (i?",":"") << static_cast<unsigned>(render_mode_state_00619790[i]);
        std::cout << "],\"device_buffer\":[";
        for(std::size_t i=0;i<32;++i) std::cout << (i?",":"") << static_cast<unsigned>(device.bytes[0x80+i]);
        std::cout << "],\"mode\":[" << width << ',' << height << ',' << format << "],\"calls\":";
        print_events();std::cout << "}\n";
    }
}
