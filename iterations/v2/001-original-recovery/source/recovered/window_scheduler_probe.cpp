#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/window_scheduler.hpp"

#include <cstdint>
#include <iostream>

namespace porsche {
TimedCallbackSlot timed_callbacks_0069dd20[16]{};
std::uint32_t last_callback_tick_0069de24=0;
std::uint32_t current_tick_006b7c40=0;
std::uint32_t diagnostic_count=0;
std::uint32_t diagnostic_message=0;

void __cdecl window_scheduler_diagnostic_00565340(const char* message) {
    ++diagnostic_count;
    diagnostic_message=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(message));
}
}

int main() {
    std::uint32_t operation,depth,tick,callback,period,delay;
    while(std::cin>>operation>>depth>>tick>>callback>>period>>delay) {
        porsche::window_scheduler_depth_0069de20=depth;
        porsche::current_tick_006b7c40=tick;
        porsche::class_error_file_005deb74=0x11111111;
        porsche::class_error_line_005deb78=0x22222222;
        porsche::diagnostic_count=0;
        porsche::diagnostic_message=0;
        for(auto& slot:porsche::timed_callbacks_0069dd20) {
            std::uint32_t callback_bits;
            std::cin>>callback_bits>>slot.period>>slot.next_tick>>slot.active;
            slot.callback=reinterpret_cast<porsche::TimedCallback>(
                static_cast<std::uintptr_t>(callback_bits));
        }
        std::uint32_t result;
        if(operation==0) {
            result=porsche::window_scheduler_register_005365e0(
                reinterpret_cast<porsche::TimedCallback>(static_cast<std::uintptr_t>(callback)),period,delay);
        } else {
            auto* slot=porsche::window_scheduler_remove_005366a0(
                reinterpret_cast<porsche::TimedCallback>(static_cast<std::uintptr_t>(callback)));
            result=0x0069dd20+static_cast<std::uint32_t>(slot-porsche::timed_callbacks_0069dd20)*16;
        }
        std::cout<<result<<' '<<porsche::window_scheduler_depth_0069de20<<' '
            <<porsche::current_tick_006b7c40<<' '<<porsche::class_error_file_005deb74<<' '
            <<porsche::class_error_line_005deb78<<' '<<porsche::diagnostic_count<<' '
            <<porsche::diagnostic_message;
        for(const auto& slot:porsche::timed_callbacks_0069dd20)
            std::cout<<' '<<static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(slot.callback))
                <<' '<<slot.period<<' '<<slot.next_tick<<' '<<slot.active;
        std::cout<<'\n';
    }
}
