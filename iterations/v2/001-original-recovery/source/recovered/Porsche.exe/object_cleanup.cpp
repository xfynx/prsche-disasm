#include "porsche/object_cleanup.hpp"
#include "porsche/window_state.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {
namespace {
std::uint32_t word(const std::uint8_t* state,std::size_t offset) {
    return *reinterpret_cast<const std::uint32_t*>(state+offset);
}
void clear(std::uint8_t* state,std::size_t offset) {
    *reinterpret_cast<std::uint32_t*>(state+offset)=0;
}
using ObjectMethod=void (__stdcall *)(void*);
void invoke_object_method(std::uint32_t object,std::size_t slot) {
    const auto vtable=*reinterpret_cast<const std::uint32_t*>(static_cast<std::uintptr_t>(object));
    const auto method=*reinterpret_cast<ObjectMethod*>(static_cast<std::uintptr_t>(vtable+slot));
    method(reinterpret_cast<void*>(static_cast<std::uintptr_t>(object)));
}
}

void __cdecl window_exit_object_cleanup_00557990(void* configuration) {
    auto* const state=static_cast<std::uint8_t*>(configuration);
    if(word(state,0x448)!=0) {
        const auto object=word(state,0);
        if(object!=0)invoke_object_method(object,0x28);
    }

    clear(state,0x454);
    const auto handle_44c=word(state,0x44c);
    clear(state,0x450);
    if(handle_44c!=0)window_cleanup_handle_00558c80(state,
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(handle_44c)));

    const auto handle_448=word(state,0x448);
    if(handle_448!=0)window_cleanup_handle_00558c80(state,
        reinterpret_cast<void*>(static_cast<std::uintptr_t>(handle_448)));

    clear(state,0x44c);
    clear(state,0x448);
}

void __cdecl window_cleanup_handle_00558c80(void* configuration,void* handle) {
    auto* state=static_cast<std::uint8_t*>(configuration ? configuration
        : static_cast<void*>(&window_configuration_storage_006b77a0));
    auto* const object=static_cast<std::uint8_t*>(handle);
    if(word(state,0x43c)==static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(handle)))
        window_cleanup_update_005588a0(state);
    invoke_object_method(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(object)),0x8);
}
} // namespace porsche
