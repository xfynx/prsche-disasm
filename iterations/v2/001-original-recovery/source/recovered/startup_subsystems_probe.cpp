#include "porsche/startup_subsystems.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

namespace {
std::uint32_t keyboard_type0,keyboard_type1;
std::int32_t joy_devices;
std::string calls;
void record(const std::string& event){if(!calls.empty())calls+=',';calls+=event;}
}
namespace porsche {
std::uint32_t window_channels_initialized_0069e5a0=0;
std::uint32_t __cdecl startup_get_keyboard_type(std::uint32_t kind){
    const auto value=kind?keyboard_type1:keyboard_type0;
    record("[\"keyboard\","+std::to_string(kind)+","+std::to_string(value)+"]");
    return value;
}
std::int32_t __cdecl startup_joy_get_num_devs(){
    record("[\"joy_count\","+std::to_string(static_cast<std::uint32_t>(joy_devices))+"]");return joy_devices;
}
std::uint32_t __cdecl startup_joy_get_dev_caps(std::uint32_t id,void* caps,std::uint32_t bytes){
    record("[\"joy_caps\","+std::to_string(id)+","+std::to_string(bytes)+"]");
    std::memset(caps,0,bytes);return 0;
}
}
int main(){
    std::uint32_t type0,type1,initial;std::int32_t devices;
    while(std::cin>>type0>>type1>>devices>>initial){
        keyboard_type0=type0;keyboard_type1=type1;joy_devices=devices;calls.clear();
        porsche::startup_joystick_initialized_005deac4=0;
        porsche::startup_joystick_count_006a5bf4=0;
        porsche::startup_keyboard_value_0069e5a0=initial;
        const auto key_result=porsche::startup_keyboard_detect_00564e70();
        porsche::startup_joystick_enumerate_00564ab0();
        porsche::startup_joystick_thunk_00564850();
        std::cout<<"{\"key_result\":"<<key_result<<",\"keyboard_value\":"
                 <<porsche::startup_keyboard_value_0069e5a0<<",\"joystick_initialized\":"
                 <<static_cast<unsigned>(porsche::startup_joystick_initialized_005deac4)
                 <<",\"joystick_count\":"<<porsche::startup_joystick_count_006a5bf4
                 <<",\"calls\":["<<calls<<"]}\n";
    }
}
