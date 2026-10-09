#include "porsche/application_state.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>

namespace {
struct GuardedArena {
    std::uint8_t before[32];
    porsche::ApplicationStateArena state;
    std::uint8_t after[32];
};
static_assert(sizeof(porsche::ApplicationStateArena)==porsche::application_state_bytes);
static_assert(offsetof(GuardedArena,state)==32);
static_assert(offsetof(GuardedArena,after)==32+porsche::application_state_bytes);

std::string hex_bytes(const std::uint8_t* p,std::size_t n) {
    static constexpr char digits[]="0123456789abcdef";
    std::string out;out.reserve(n*2);
    for(std::size_t i=0;i<n;++i){out.push_back(digits[p[i]>>4]);out.push_back(digits[p[i]&15]);}
    return out;
}
bool all_byte(const std::uint8_t* p,std::size_t n,std::uint8_t value) {
    return std::all_of(p,p+n,[=](std::uint8_t b){return b==value;});
}
}

int main() {
    unsigned dispatch=0;
    std::uint32_t value=0,offset=0,count=0;
    while(std::cin>>dispatch>>value>>offset>>count) {
        (void)dispatch; // Selects the original x86 implementation in the verifier.
        GuardedArena guarded{};
        std::fill(std::begin(guarded.before),std::end(guarded.before),static_cast<std::uint8_t>(0xa5));
        std::fill(std::begin(guarded.after),std::end(guarded.after),static_cast<std::uint8_t>(0x5a));
        auto& state=guarded.state;
        for(std::size_t i=0;i<porsche::application_state_bytes;++i)
            state.bytes()[i]=static_cast<std::uint8_t>((i*37u+11u)&0xffu);

        state.word(0x006573e8u)=0x11223344u;
        state.byte(0x006573e9u)=0x55u;
        auto* selector=state.characters(0x00657a38u);
        selector[0]='A';selector[1]='B';selector[2]='C';selector[3]='D';selector[4]='\0';
        auto* config_name=state.characters(0x00657a84u);
        config_name[0]='T';config_name[1]='E';config_name[2]='S';config_name[3]='T';config_name[4]='\0';
        state.word(0x00657a60u)=0x10203040u;
        state.byte(0x00657a64u)=0x7fu;
        state.byte(0x00657e34u)=0xa3u;
        const bool alias_ok=state.words()[0]==state.word(0x006573e8u) &&
            state.word(0x006573e8u)==0x11225544u &&
            state.word(0x00657a38u)==0x44434241u && selector[4]=='\0' &&
            config_name[0]=='T' && config_name[4]=='\0' &&
            state.word(0x00657a60u)==0x10203040u && state.byte(0x00657a64u)==0x7fu &&
            state.byte(0x00657e34u)==0xa3u;

        porsche::application_state_fill_0053c290(state,
            porsche::application_state_base_va+offset,value,count);
        const bool guards_ok=all_byte(guarded.before,sizeof(guarded.before),0xa5) &&
            all_byte(guarded.after,sizeof(guarded.after),0x5a);
        std::cout<<"{\"dispatch\":"<<dispatch<<",\"offset\":"<<offset<<",\"count\":"<<count
            <<",\"alias_ok\":"<<(alias_ok?"true":"false")
            <<",\"guards_ok\":"<<(guards_ok?"true":"false")
            <<",\"bytes_hex\":\""<<hex_bytes(state.bytes(),porsche::application_state_bytes)<<"\"}\n";
    }
}
