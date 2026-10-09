#include "porsche/object_cleanup.hpp"
#include "porsche/window_state.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
using Object=std::array<std::uint32_t,3>;
std::array<std::uint32_t,11> vtable{};
Object main_object{},resource_a{},resource_b{};
std::vector<std::string> calls;
void* active_state{};
std::uint32_t read_word(const void* p,std::size_t offset) {
    std::uint32_t value{};std::memcpy(&value,static_cast<const std::uint8_t*>(p)+offset,4);return value;
}
void write_word(void* p,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(p)+offset,&value,4);
}
void __stdcall method_8(void* p) {
    calls.push_back(p==resource_a.data()?"v8:a":p==resource_b.data()?"v8:b":"v8:main");
}
void __stdcall method_28(void* p) { calls.push_back(p==main_object.data()?"v28:main":"v28:other"); }
void reset_object(Object& object) { object[0]=reinterpret_cast<std::uint32_t>(vtable.data()); }
void reset(porsche::OriginalWindowConfiguration& state) {
    std::memset(&state,0,sizeof(state));calls.clear();active_state=&state;
    reset_object(main_object);reset_object(resource_a);reset_object(resource_b);
    vtable[2]=reinterpret_cast<std::uint32_t>(&method_8);
    vtable[10]=reinterpret_cast<std::uint32_t>(&method_28);
    write_word(&state,0,reinterpret_cast<std::uint32_t>(main_object.data()));
    write_word(&state,0x450,0xaaaa5555);write_word(&state,0x454,0x5555aaaa);
}
void emit(const char* label,const void* state) {
    auto label_word=[](std::uint32_t value) {
        if(value==reinterpret_cast<std::uint32_t>(main_object.data()))return std::string("main");
        if(value==reinterpret_cast<std::uint32_t>(resource_a.data()))return std::string("a");
        if(value==reinterpret_cast<std::uint32_t>(resource_b.data()))return std::string("b");
        return std::to_string(value);
    };
    std::cout<<label;
    for(auto offset:{0u,0x43cu,0x448u,0x44cu,0x450u,0x454u})std::cout<<' '<<label_word(read_word(state,offset));
    std::cout<<' '<<calls.size();for(const auto& call:calls)std::cout<<' '<<call;std::cout<<'\n';
}
}

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void __cdecl window_cleanup_update_005588a0(void* state) {
    calls.push_back(state==active_state?"update:state":"update:other");
}
}

int main() {
    using namespace porsche;auto& state=window_configuration_storage_006b77a0;
    reset(state);window_exit_object_cleanup_00557990(&state);emit("empty",&state);
    reset(state);write_word(&state,0x43c,reinterpret_cast<std::uint32_t>(resource_b.data()));
    write_word(&state,0x44c,reinterpret_cast<std::uint32_t>(resource_a.data()));
    write_word(&state,0x448,reinterpret_cast<std::uint32_t>(resource_b.data()));
    window_exit_object_cleanup_00557990(&state);emit("two_handles",&state);
    reset(state);write_word(&state,0x43c,reinterpret_cast<std::uint32_t>(resource_a.data()));
    window_cleanup_handle_00558c80(nullptr,resource_a.data());emit("null_state_fallback",&state);
}
