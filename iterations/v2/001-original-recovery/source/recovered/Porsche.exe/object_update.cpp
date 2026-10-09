#include "porsche/object_update.hpp"

#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_state.hpp"
#include "porsche/object_cleanup.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {
void __cdecl window_cleanup_update_005588a0(void* configuration) {
    object_update_005588a0(configuration);
}
std::uint32_t object_update_word_006a3afc=0;
std::uint32_t object_update_word_006a3b00=0;
std::uint32_t object_update_word_006a3b04=0;
std::uint32_t object_update_word_005deb58=0;

namespace {
std::uint32_t load(const std::uint8_t* state,std::size_t offset) {
    return *reinterpret_cast<const std::uint32_t*>(state+offset);
}
void clear_word(std::uint8_t* state,std::size_t offset) {
    *reinterpret_cast<std::uint32_t*>(state+offset)=0;
}
using UpdateMethod=void (__stdcall *)(void*,std::uint32_t);
}

void __cdecl object_update_005588a0(void* configuration) {
    auto* const state=static_cast<std::uint8_t*>(configuration ? configuration
        : static_cast<void*>(&window_configuration_storage_006b77a0));
    const auto object=load(state,0x43c);
    if(object==0) {
        object_update_word_005deb58=0;
        return;
    }

    const auto vtable=*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(object));
    const auto method=*reinterpret_cast<UpdateMethod*>(static_cast<std::uintptr_t>(vtable+0x80));
    const auto argument=load(state,0x440);
    method(reinterpret_cast<void*>(static_cast<std::uintptr_t>(object)),argument);
    clear_word(state,0x43c);
    clear_word(state,0x440);
    state[0x444]=0;

    const auto elapsed=platform_get_tick_count()-object_update_word_006a3b04;
    object_update_word_006a3afc=elapsed;
    if(static_cast<std::int32_t>(elapsed)>
       static_cast<std::int32_t>(object_update_word_006a3b00))
        object_update_word_006a3b00=elapsed;

    heap_leave_005322c0(thread_start_lock_006a57d8);
    object_update_word_005deb58=0;
}
} // namespace porsche
