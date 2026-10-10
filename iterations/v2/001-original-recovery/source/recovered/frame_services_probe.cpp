#include "porsche/application_state.hpp"
#include "porsche/frame_services.hpp"
#include "porsche/startup_service_516950.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {
struct Event { std::uint32_t id, a, b; };
std::vector<Event> events;
std::uint8_t after_ae3c0_flag{};
std::array<std::uint32_t,5> after_4ad510{};
std::array<std::uint32_t,5> after_4ae4d0{};
void event(std::uint32_t id,std::uint32_t a=0,std::uint32_t b=0) {
    events.push_back({id,a,b});
}
void print_result(std::uint32_t result) {
    using namespace porsche;
    std::cout << "{\"return\":" << result << ",\"trace\":[";
    for(std::size_t i=0;i<events.size();++i) {
        if(i) std::cout << ',';
        std::cout << '[' << events[i].id << ',' << events[i].a << ',' << events[i].b << ']';
    }
    std::cout << "],\"records\":[";
    for(std::size_t i=0;i<frame_services_records_00656180.size();++i) {
        if(i) std::cout << ',';
        std::cout << frame_services_records_00656180[i];
    }
    std::cout << "],\"flags\":[" << static_cast<unsigned>(frame_services_byte_00656868)
              << ',' << static_cast<unsigned>(frame_services_byte_00656869)
              << "],\"scale\":" << frame_services_word_005d14b0
              << ",\"render\":[";
    for(std::size_t i=0;i<frame_services_words_005d1740.size();++i) {
        if(i) std::cout << ',';
        std::cout << frame_services_words_005d1740[i];
    }
    std::cout << "],\"arena\":[" << application_state_006573e8.word(0x00657c94u);
    for(const auto va:{0x00657ca0u,0x00657ca4u,0x00657ca8u,0x00657cacu,0x00657cb0u})
        std::cout << ',' << application_state_006573e8.word(va);
    std::cout << "]}\n";
}
}

namespace porsche {
void __cdecl frame_services_boundary_004af900(std::uint32_t a,std::uint32_t b) { event(1,a,b); }
std::uint32_t __cdecl frame_services_boundary_00566340(std::uint32_t a,std::uint32_t b) { event(2,a,b); return 0xdeadbeefu; }
std::uint32_t __cdecl frame_services_boundary_004ae3c0(std::uint32_t a) {
    event(3,a); frame_services_byte_00656868=after_ae3c0_flag; return 0x12345678u;
}
void __cdecl frame_services_boundary_00565cd0(std::uint32_t a,std::uint32_t b) { event(4,a,b); }
void __cdecl frame_services_boundary_004ad510() {
    event(5);
    frame_services_words_005d1740=after_4ad510;
}
void __cdecl frame_services_boundary_004ae8c0(std::uint32_t a) { event(6,a); }
void __cdecl frame_services_boundary_004ae4d0(std::uint32_t a,std::uint32_t b) {
    event(7,a,b);
    frame_services_words_005d1740=after_4ae4d0;
}
void __cdecl startup_service_noop_00516950() { event(8); }
} // namespace porsche

int main() {
    std::array<std::uint32_t,28> input{};
    while(std::cin >> input[0]) {
        bool complete=true;
        for(std::size_t i=1;i<input.size();++i) if(!(std::cin >> input[i])) { complete=false; break; }
        if(!complete) return 2;
        using namespace porsche;
        events.clear();
        std::fill(frame_services_records_00656180.begin(),frame_services_records_00656180.end(),0xffffffffu);
        for(std::size_t i=0;i<73;++i) frame_services_records_00656180[i*2+1]=0xa0000000u+static_cast<std::uint32_t>(i);
        frame_services_records_00656180[0]=input[6];
        frame_services_records_00656180[4]=input[7];
        after_ae3c0_flag=static_cast<std::uint8_t>(input[4]);
        frame_services_byte_00656868=static_cast<std::uint8_t>(input[2]);
        frame_services_byte_00656869=static_cast<std::uint8_t>(input[3]);
        frame_services_word_005d14b0=input[5];
        for(std::size_t i=0;i<5;++i) {
            application_state_006573e8.word(0x00657ca0u+static_cast<std::uint32_t>(i*4))=input[8+i];
            frame_services_words_005d1740[i]=input[13+i];
            after_4ad510[i]=input[18+i];
            after_4ae4d0[i]=input[23+i];
        }
        application_state_006573e8.word(0x00657c94u)=input[1];
        const auto result=input[0]==0?frame_services_004ab150():frame_services_004ab200();
        print_result(result);
    }
    return 0;
}
