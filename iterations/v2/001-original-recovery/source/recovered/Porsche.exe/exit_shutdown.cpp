#include "porsche/exit_shutdown.hpp"
#include "porsche/exit_registry.hpp"
#include <cstdint>

namespace porsche {
std::uint32_t exit_shutdown_mode_word_006afce0=0;
std::uint32_t exit_shutdown_started_006afce4=0;
std::uint32_t exit_shutdown_process_state_006afce8=0;

void __cdecl exit_shutdown_walk_range_005a2547(void(__cdecl** begin)(),void(__cdecl** end)()){
    auto current=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(begin));
    const auto limit=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(end));
    while(current<limit){
        auto callback=*reinterpret_cast<void(__cdecl**)()>(static_cast<std::uintptr_t>(current));
        if(callback)callback();
        current+=4u;
    }
}

void __cdecl exit_shutdown_execute_005a2490(std::uint32_t code,std::int32_t skip_exit_callbacks,
    std::uint32_t return_after_callbacks){
    exit_registry_lock_enter_005a2535();
    if(exit_shutdown_process_state_006afce8==1){
        auto* process=exit_shutdown_get_current_process();
        exit_shutdown_terminate_process(process,code);
    }
    exit_shutdown_started_006afce4=1;
    exit_shutdown_mode_word_006afce0=(exit_shutdown_mode_word_006afce0&0xffffff00u)|
        static_cast<std::uint8_t>(return_after_callbacks);
    if(skip_exit_callbacks==0){
        auto* base=exit_registry_base_006c1534;
        if(base){
            // LEA/SUB wrap in 32 bits. CMP reloads the base after every
            // callback, which can mutate the shared registry while locked.
            auto current=static_cast<std::uint32_t>(
                reinterpret_cast<std::uintptr_t>(exit_registry_next_006c1530))-4u;
            auto lower=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(base));
            while(current>=lower){
                const auto callback=*reinterpret_cast<const std::uint32_t*>(
                    static_cast<std::uintptr_t>(current));
                if(callback)reinterpret_cast<void(__cdecl*)()>(
                    static_cast<std::uintptr_t>(callback))();
                current-=4u;
                lower=static_cast<std::uint32_t>(
                    reinterpret_cast<std::uintptr_t>(exit_registry_base_006c1534));
            }
        }
        void(__cdecl* onexit_callbacks[])()={nullptr,exit_shutdown_static_callback_005a36d6};
        exit_shutdown_walk_range_005a2547(onexit_callbacks,onexit_callbacks+2);
    }
    void(__cdecl* cexit_callbacks[])()={nullptr,exit_shutdown_static_callback_005ac147};
    exit_shutdown_walk_range_005a2547(cexit_callbacks,cexit_callbacks+2);
    if(return_after_callbacks){exit_registry_lock_leave_005a253e();return;}
    exit_shutdown_process_state_006afce8=1;
    // Original ExitProcess is terminal; this typed boundary only records it.
    exit_shutdown_exit_process(code);
}
}
