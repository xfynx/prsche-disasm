#include "porsche/window_exit_cleanup.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_state.hpp"

#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
std::vector<std::string> calls;
std::array<std::uintptr_t,3> virtual_table{};
std::array<std::uintptr_t,1> object{};
void __stdcall virtual_exit(void* value) {
    calls.push_back(value==object.data()?"vtable:object":"vtable:other");
}
void reset(porsche::OriginalWindowConfiguration& config) {
    std::memset(&config,0,sizeof(config));
    calls.clear();
    virtual_table={}; object={};
    virtual_table[2]=reinterpret_cast<std::uintptr_t>(&virtual_exit);
    object[0]=reinterpret_cast<std::uintptr_t>(virtual_table.data());
    const auto object_address=reinterpret_cast<std::uintptr_t>(object.data());
    std::memcpy(&config, &object_address, sizeof(object_address));
    const std::uint32_t sentinels[2]={0x11111111,0x22222222};
    std::memcpy(reinterpret_cast<std::uint8_t*>(&config)+4,&sentinels[0],4);
    std::memcpy(reinterpret_cast<std::uint8_t*>(&config)+0x24,&sentinels[1],4);
}
void emit(const char* label,const porsche::OriginalWindowConfiguration& config) {
    const auto* bytes=reinterpret_cast<const std::uint8_t*>(&config);
    std::cout<<label<<' ';
    for (const auto offset : {0u,4u,0x10u,0x24u}) {
        std::uint32_t value{}; std::memcpy(&value,bytes+offset,4);
        std::cout<<value<<' ';
    }
    std::cout<<calls.size();
    for(const auto& call:calls)std::cout<<' '<<call;
    std::cout<<'\n';
}
}

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* thread_start_lock_006a57d8=reinterpret_cast<void*>(0x12345678);
void __cdecl heap_enter_005322b0(void* p) { calls.push_back(p==thread_start_lock_006a57d8?"enter:lock":"enter:other"); }
void __cdecl heap_leave_005322c0(void* p) { calls.push_back(p==thread_start_lock_006a57d8?"leave:lock":"leave:other"); }
std::uint32_t __cdecl free_00531f90(void* p) { calls.push_back("free:"+std::to_string(reinterpret_cast<std::uintptr_t>(p))); return 1; }
void __cdecl window_exit_object_cleanup_00557990(void* p) { calls.push_back(p==&window_configuration_storage_006b77a0?"cleanup:self":"cleanup:other"); }
}

int main() {
    using namespace porsche;
    auto& config=window_configuration_storage_006b77a0;
    reset(config); std::uint32_t zero{}; std::memcpy(&config,&zero,4);
    window_exit_cleanup_00558350(&config); emit("empty",config);
    reset(config); window_exit_cleanup_00558350(&config); emit("no_allocation",config);
    reset(config); const std::uint32_t allocation=0x76543210;
    std::memcpy(reinterpret_cast<std::uint8_t*>(&config)+0x10,&allocation,4);
    window_exit_cleanup_00558350(nullptr); emit("fallback_with_allocation",config);
}
