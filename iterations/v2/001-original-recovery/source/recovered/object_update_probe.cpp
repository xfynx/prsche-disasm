#include "porsche/object_update.hpp"
#include "porsche/file_threads.hpp"
#include "porsche/heap.hpp"
#include "porsche/window_state.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
using Object=std::array<std::uint32_t,1>;
std::array<std::uint32_t,33> vtable{};
Object object_a{},object_b{};
porsche::OriginalWindowConfiguration alternate{};
std::vector<std::string> calls;
std::uint32_t next_tick{};

std::uint32_t read_word(const void* p,std::size_t offset) {
    std::uint32_t value{};std::memcpy(&value,static_cast<const std::uint8_t*>(p)+offset,4);return value;
}
void write_word(void* p,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(p)+offset,&value,4);
}
std::string object_name(std::uint32_t value) {
    if(value==reinterpret_cast<std::uint32_t>(object_a.data()))return "a";
    if(value==reinterpret_cast<std::uint32_t>(object_b.data()))return "b";
    return std::to_string(value);
}
void __stdcall method_80(void* object,std::uint32_t argument) {
    const auto value=reinterpret_cast<std::uint32_t>(object);
    calls.push_back("method80:"+object_name(value)+":"+std::to_string(argument));
}
void reset(porsche::OriginalWindowConfiguration& global_state,
           porsche::OriginalWindowConfiguration& state,std::uint32_t tick,
           std::uint32_t anchor,std::uint32_t maximum,std::uint32_t diagnostic,
           std::uint32_t elapsed) {
    std::memset(&global_state,0,sizeof(global_state));
    std::memset(&state,0,sizeof(state));
    calls.clear();next_tick=tick;
    object_a[0]=reinterpret_cast<std::uint32_t>(vtable.data());
    object_b[0]=reinterpret_cast<std::uint32_t>(vtable.data());
    vtable[32]=reinterpret_cast<std::uint32_t>(&method_80);
    porsche::object_update_word_006a3afc=elapsed;
    porsche::object_update_word_006a3b00=maximum;
    porsche::object_update_word_006a3b04=anchor;
    porsche::object_update_word_005deb58=diagnostic;
}
void emit(const char* label,const void* state) {
    std::cout<<label<<' '<<object_name(read_word(state,0x43c))<<' '
        <<read_word(state,0x440)<<' '<<static_cast<unsigned>(static_cast<const std::uint8_t*>(state)[0x444])
        <<' '<<porsche::object_update_word_006a3afc<<' '
        <<porsche::object_update_word_006a3b00<<' '
        <<porsche::object_update_word_006a3b04<<' '
        <<porsche::object_update_word_005deb58<<' '<<calls.size();
    for(const auto& call:calls)std::cout<<' '<<call;
    std::cout<<'\n';
}
}

namespace porsche {
OriginalWindowConfiguration window_configuration_storage_006b77a0{};
void* thread_start_lock_006a57d8=reinterpret_cast<void*>(0x12345678);
std::uint32_t __stdcall platform_get_tick_count() {
    calls.push_back("clock:"+std::to_string(next_tick));return next_tick;
}
void __cdecl heap_leave_005322c0(void* lock) {
    calls.push_back(lock==thread_start_lock_006a57d8?"leave:lock":"leave:other");
}
}

int main() {
    using namespace porsche;auto& global=window_configuration_storage_006b77a0;
    std::string name,mode;std::uint32_t tick,anchor,maximum,diagnostic,elapsed,obj_code,aux;unsigned flag;
    while(std::cin>>name>>mode>>tick>>anchor>>maximum>>diagnostic>>elapsed>>obj_code>>aux>>flag) {
        auto& state=mode=="alt"?alternate:global;
        reset(global,state,tick,anchor,maximum,diagnostic,elapsed);
        const auto obj=obj_code==1?reinterpret_cast<std::uint32_t>(object_a.data()):
            obj_code==2?reinterpret_cast<std::uint32_t>(object_b.data()):0u;
        write_word(&state,0x43c,obj);write_word(&state,0x440,aux);
        reinterpret_cast<std::uint8_t*>(&state)[0x444]=static_cast<std::uint8_t>(flag);
        object_update_005588a0(mode=="null"?nullptr:&state);
        emit(name.c_str(),&state);
    }
}
