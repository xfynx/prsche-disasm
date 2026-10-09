#include "porsche/startup_subsystems.hpp"
#include "porsche/window_runtime.hpp"

namespace porsche {
std::uint8_t startup_joystick_initialized_005deac4=0;
std::int32_t startup_joystick_count_006a5bf4=0;
std::uint32_t& startup_keyboard_value_0069e5a0=window_channels_initialized_0069e5a0;

// 00564e70..00564ea6: preserve the two GetKeyboardType queries and exact
// family/subtype range; the constant is original data at 005df934.
std::int32_t __cdecl startup_keyboard_detect_00564e70(){
    if(startup_get_keyboard_type(0)!=7)return 0;
    const auto subtype=startup_get_keyboard_type(1);
    if(subtype<0x0d01||subtype>0x0d04)return 0;
    startup_keyboard_value_0069e5a0=0x005df934;
    return 1;
}

// 00564ab0..00564af5. JOYCAPS bytes are written only to the original
// per-iteration stack scratch buffer; neither its contents nor API status
// affects state in this function.
void __cdecl startup_joystick_enumerate_00564ab0(){
    startup_joystick_initialized_005deac4=1;
    startup_joystick_count_006a5bf4=startup_joy_get_num_devs();
    if(startup_joystick_count_006a5bf4<=0)return;
    std::uint8_t caps[0x194];
    for(std::int32_t id=0;id<startup_joystick_count_006a5bf4;++id)
        startup_joy_get_dev_caps(static_cast<std::uint32_t>(id),caps,sizeof(caps));
}

// 00564850 is a five-byte tail-jump to 00564ab0.
void __cdecl startup_joystick_thunk_00564850(){startup_joystick_enumerate_00564ab0();}
}
