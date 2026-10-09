#include "porsche/window_input_bindings.hpp"
#include "porsche/window_messages.hpp"
#include "porsche/window_runtime.hpp"
#include <cstdio>

namespace porsche { std::uint32_t window_channels_initialized_0069e5a0; }
int main() {
    unsigned scan, table, initial, enabled;
    while(std::scanf("%u %u %u %u", &scan,&table,&initial,&enabled)==4) {
        porsche::window_channels_initialized_0069e5a0=table?0x005df934:0;
        porsche::window_resize_count_006a5c2c=initial;
        porsche::window_resize_notification_pointer_005df9b8=
            enabled?&porsche::window_resize_counter_005654d0:nullptr;
        porsche::window_resize_counter_005654d0();
        if(porsche::window_message_has_resize_notification_005df9b8())
            porsche::window_message_resize_notification_005df9b8();
        std::printf("%u %u %u\n",
            static_cast<unsigned>(porsche::window_message_translate_key_0069e5a0(scan)),
            porsche::window_resize_count_006a5c2c,
            porsche::window_message_has_resize_notification_005df9b8()?1:0);
    }
}
