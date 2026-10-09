#include "porsche/window_runtime.hpp"
#include <cstring>

namespace porsche {
TimedCallbackSlot timed_callbacks_0069dd20[16]{};
std::uint32_t last_callback_tick_0069de24 = 0;
std::uint32_t current_tick_006b7c40 = 0;

// 005366e0..00536763. The original refreshes current_tick for every slot;
// a callback may change it before the next slot is tested.
std::uint32_t __cdecl timed_callbacks_005366e0(std::uint32_t argument) {
    if (last_callback_tick_0069de24 == current_tick_006b7c40) return 0;
    last_callback_tick_0069de24 = current_tick_006b7c40;
    std::uint32_t combined = 0;
    for (auto& slot : timed_callbacks_0069dd20) {
        if (slot.callback &&
            static_cast<std::int32_t>(current_tick_006b7c40) >= static_cast<std::int32_t>(slot.next_tick) &&
            slot.active == 0) {
            slot.active = 1;
            const std::uint32_t elapsed = current_tick_006b7c40 - slot.next_tick;
            combined |= slot.callback(argument, elapsed);
            slot.next_tick = current_tick_006b7c40 + slot.period;
            slot.active = 0;
        }
    }
    return combined;
}

// 005367b0..005367b2: xor eax,eax; ret (cdecl, caller cleans its arguments).
std::uint32_t __cdecl startup_noop_005367b0(std::uint32_t, std::uint32_t, std::uint32_t) {
    return 0;
}

std::uint32_t window_style_005dea88=0x10000000u;
std::uint8_t window_style_flag_005dead4=9;
std::uint32_t window_override_0069e5b0=0;
std::int32_t window_override_x_006bda00=0;
std::int32_t window_override_y_006bda04=0;
const char* window_class_name_0069e5a8=nullptr;
void* window_instance_006b7794=nullptr;
std::uint32_t window_create_state_005de024=0;
std::uint32_t window_channels_initialized_0069e5a0=0;

static std::int32_t config_word(const std::uint8_t* config,std::uint32_t offset) {
    std::int32_t result;
    std::memcpy(&result,config+offset,sizeof(result));
    return result;
}
static void set_config_word(std::uint8_t* config,std::uint32_t offset,std::int32_t value) {
    std::memcpy(config+offset,&value,sizeof(value));
}

// 0053bb00..0053bcaa. Configuration offsets and branch order are from the
// original instructions, not guessed Win32 defaults. The external procedures
// are typed recording boundaries in the differential fixture.
void* __cdecl window_create_0053bb00(void* configuration) {
    auto* config=static_cast<std::uint8_t*>(configuration);
    const bool fullscreen=config[0x461]!=0;
    std::uint32_t style=window_style_005dea88;
    std::uint32_t exstyle;
    std::int32_t x,y,width,height;
    if (fullscreen) {
        if (window_override_0069e5b0) {
            set_config_word(config,0x468,window_override_x_006bda00);
            set_config_word(config,0x46c,window_override_y_006bda04);
        } else {
            set_config_word(config,0x468,0);
            set_config_word(config,0x46c,0);
        }
        width=window_get_system_metrics(0);
        height=window_get_system_metrics(1);
        style|=0x80000000u;
        exstyle=8;
    } else {
        style|=0x00ca0000u;
        if (window_style_flag_005dead4 & 0x20) {
            style|=0x00050000u;
            exstyle=0x40000;
        } else {
            style|=0x00800000u;
            exstyle=0x40100;
        }
        if (config_word(config,0x458)) {
            x=config_word(config,0x468);
            y=config_word(config,0x46c);
        } else {
            x=-8192;y=-8192;
        }
        WindowRect rect{x,y,x+config_word(config,0x14),y+config_word(config,0x18)};
        window_adjust_rect(&rect,style,0,exstyle);
        if (window_override_0069e5b0) {
            set_config_word(config,0x468,window_override_x_006bda00);
            set_config_word(config,0x46c,window_override_y_006bda04);
        } else {
            set_config_word(config,0x468,rect.left);
            set_config_word(config,0x46c,rect.top);
        }
        width=rect.right-rect.left;
        height=rect.bottom-rect.top;
    }
    x=config_word(config,0x468);
    y=config_word(config,0x46c);
    void* handle=window_create_ex(exstyle,window_class_name_0069e5a8,window_class_name_0069e5a8,
        style,x,y,width,height,nullptr,nullptr,window_instance_006b7794,nullptr);
    if (handle) {
        window_set_cursor(nullptr);
        if (fullscreen) window_show_cursor(0);
        window_create_state_005de024=0;
        if (!window_channels_initialized_0069e5a0) {
            window_channel_005739b0(0,0);
            window_channel_005739b0(1,0);
            window_channel_005739b0(2,0);
        }
    }
    return handle;
}
}
