#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/render_settings.hpp"
#include "porsche/render_state_init.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
RenderDisplay* render_display_00628130{};
std::uint32_t render_display_mode_index_00619780{};
std::uint32_t render_display_actual_width_00619784{}, render_display_actual_height_00619788{};
std::uint32_t render_display_actual_mode_0061978c{};

namespace {
RenderSettingsDevice device{};
std::array<std::uint8_t, 0x100> display_bytes{};
std::array<std::uint8_t, 0x20> driver_bytes{};
std::array<std::array<std::uint32_t, 10>, 4> mode_records{};
std::array<std::uint32_t, 11> get_results{};
std::array<std::uint32_t, 24> set_results{};
std::size_t get_at{}, set_at{};
std::uint32_t trident_result{}, voodoo_result{}, clock_result{};
struct Event { std::string kind, key; std::uint32_t a{}, b{}, result{}; };
std::vector<Event> events;

template<class T> void write_at(std::uint8_t* bytes, std::size_t offset, T value) {
    std::memcpy(bytes + offset, &value, sizeof(value));
}
void print_events() {
    std::cout << '[';
    for (std::size_t i=0; i<events.size(); ++i) {
        const auto& e=events[i]; if (i) std::cout << ',';
        std::cout << "{\"kind\":\"" << e.kind << "\"";
        if (e.kind=="get") std::cout << ",\"key\":" << e.a << ",\"result\":" << e.result;
        else if (e.kind=="set")
            std::cout << ",\"key\":" << e.a << ",\"value\":" << e.b << ",\"result\":" << e.result;
        else if (e.kind=="mode_set")
            std::cout << ",\"key\":" << e.a << ",\"value\":" << e.b;
        else if (e.kind=="config")
            std::cout << ",\"key\":\"" << e.key << "\",\"destination\":" << e.a << ",\"result\":" << e.result;
        else if (e.kind=="clock") std::cout << ",\"result\":" << e.result;
        std::cout << '}';
    }
    std::cout << ']';
}
}

void __cdecl render_mode_driver_prepare_vslot9(void*) { events.push_back({"driver"}); }
const RenderSettingsDevice* __cdecl render_settings_current_device_006bd934() {
    events.push_back({"device"}); return &device;
}
std::uint32_t __stdcall render_settings_get_state_006bd984(std::uint32_t key) {
    const auto value=get_results.at(get_at++); events.push_back({"get",{},key,0,value}); return value;
}
std::uint32_t __stdcall render_settings_set_state_006bd97c(std::uint32_t key,std::uint32_t value) {
    const auto result=set_results.at(set_at++); events.push_back({"set",{},key,value,result}); return result;
}
std::int32_t __cdecl render_settings_read_config_005a1e10(char* output,const char* key) {
    const auto result=std::strcmp(key,"Trident Blade")==0 ? trident_result : voodoo_result;
    std::memcpy(output,"setting\0",8);
    events.push_back({"config",key,128,0,static_cast<std::uint32_t>(result)});
    return static_cast<std::int32_t>(result);
}
void __stdcall render_mode_setstate_iat_006bd918(std::uint32_t key,std::uint32_t value) {
    events.push_back({"mode_set",{},key,value,0});
}
std::uint32_t __cdecl render_mode_clock_00555bc0() {
    events.push_back({"clock",{},0,0,clock_result}); return clock_result;
}
}

int main() {
    using namespace porsche;
    std::uint32_t index{},fullscreen{},alternate{},seed{},clock{};
    std::uint32_t device_id{},flags{},min_a{},min_b{},field44{},device_type{},surface{};
    std::uint32_t global_value{},trident{},voodoo{};
    std::int32_t setting5c{},setting60{},setting68{},setting6c{},setting70{},setting78{},setting80{};
    std::array<std::uint32_t,11> gets{};
    std::array<std::uint32_t,24> sets{};
    while (std::cin >> index >> fullscreen >> alternate >> seed >> clock
        >> device_id >> flags >> min_a >> min_b >> field44 >> device_type >> surface
        >> global_value >> trident >> voodoo
        >> setting5c >> setting60 >> setting68 >> setting6c >> setting70 >> setting78 >> setting80) {
        for(auto& v:gets) std::cin>>v;
        for(auto& v:sets) std::cin>>v;
        std::memset(display_bytes.data(),0,sizeof(display_bytes));
        std::memset(driver_bytes.data(),0,sizeof(driver_bytes));
        display_bytes[0x60]=static_cast<std::uint8_t>(fullscreen);
        write_at(display_bytes.data(),0x70,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(driver_bytes.data())));
        const std::uint32_t format[4]={16,15,32,24};
        for(std::size_t r=0;r<mode_records.size();++r) {
            mode_records[r]={800u+static_cast<std::uint32_t>(r)*320u,
                600u+static_cast<std::uint32_t>(r)*120u,format[r],0x44000000u+seed+r,
                0x55000000u+seed+r,2u+static_cast<std::uint32_t>(r),
                0x77000000u+seed+r,0x88000000u+seed+r,0x99000000u+seed+r,
                0xaa000000u+seed+r};
        }
        write_at(driver_bytes.data(),8,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(mode_records.data())));
        std::memset(device.bytes,static_cast<int>(seed&0xff),sizeof(device.bytes));
        write_at(device.bytes,0x00,device_id);write_at(device.bytes,0x0c,flags);
        write_at(device.bytes,0x14,static_cast<std::int32_t>(min_a));
        write_at(device.bytes,0x20,static_cast<std::int32_t>(min_b));
        write_at(device.bytes,0x44,field44);write_at(device.bytes,0x6c,device_type);write_at(device.bytes,0x70,surface);
        render_display_00628130=reinterpret_cast<RenderDisplay*>(display_bytes.data());
        std::memset(render_mode_state_00619790,static_cast<int>(seed&0xff),sizeof(render_mode_state_00619790));
        render_mode_state_00619790[0x70]=static_cast<std::uint8_t>(alternate);
        render_display_mode_index_00619780=seed^0x11111111u;
        render_display_actual_width_00619784=seed^0x22222222u;
        render_display_actual_height_00619788=seed^0x33333333u;
        render_display_actual_mode_0061978c=seed^0x44444444u;
        render_display_clock_005deb1c=seed^0x55555555u;
        render_mode_time_value_005ce908=seed^0x66666666u;
        render_mode_option_0069dd1d=static_cast<std::uint8_t>(seed);
        render_mode_setting_00657d5c=setting5c;render_mode_setting_00657d60=setting60;
        render_mode_setting_00657d68=setting68;render_mode_setting_00657d6c=setting6c;
        render_mode_setting_00657d70=setting70;render_mode_setting_00657d78=setting78;
        render_mode_setting_00657d80=setting80;
        render_settings_value_00657da4=global_value;
        get_results=gets;set_results=sets;get_at=set_at=0;
        trident_result=trident;voodoo_result=voodoo;clock_result=clock;events.clear();
        std::uint32_t queried[10];for(auto& v:queried)v=0xa5a5a5a5u;
        render_mode_query_0044e720(index,queried);
        render_mode_commit_0044ebf0(index);
        render_mode_update_state_0044ed10();
        std::cout << "{\"query\":[";
        for(int i=0;i<10;++i)std::cout<<(i?",":"")<<queried[i];
        std::cout << "],\"state\":[";
        for(std::size_t i=0;i<sizeof(render_mode_state_00619790);++i)
            std::cout<<(i?",":"")<<static_cast<unsigned>(render_mode_state_00619790[i]);
        std::cout << "],\"globals\":[" << render_display_mode_index_00619780 << ','
            << render_display_actual_width_00619784 << ',' << render_display_actual_height_00619788 << ','
            << render_display_actual_mode_0061978c << ',' << render_mode_time_value_005ce908 << ','
            << render_display_clock_005deb1c << ',' << static_cast<unsigned>(render_mode_option_0069dd1d)
            << ',' << render_mode_setting_00657d5c << ',' << render_mode_setting_00657d60 << ','
            << render_mode_setting_00657d68 << ',' << render_mode_setting_00657d6c << ','
            << render_mode_setting_00657d70 << ',' << render_mode_setting_00657d78 << ','
            << render_mode_setting_00657d80 << "],\"device_tail\":[";
        for(std::size_t i=0;i<32;++i)std::cout<<(i?",":"")<<static_cast<unsigned>(device.bytes[0x80+i]);
        std::cout << "],\"calls\":";print_events();std::cout << "}\n";
    }
}
