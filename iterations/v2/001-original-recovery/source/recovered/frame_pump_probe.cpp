#include "porsche/frame_pump.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_display.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <vector>

namespace {
struct Event { std::uint32_t id; std::array<std::uint32_t,6> args{}; };
std::vector<Event> events;
std::uint32_t movie_value;
struct MovieObject {
    virtual void reserved_00() {}
    virtual void reserved_04() {}
    virtual void reserved_08() {}
    virtual void reserved_0c() {}
    virtual void reserved_10() {}
    virtual void reserved_14() {}
    virtual void reserved_18() {}
    virtual std::uint32_t slot1c(std::uint32_t value) { events.push_back({11,{0x2201000,value}}); return 0; }
    virtual std::uint32_t slot20() { events.push_back({10,{0x2201000,movie_value}}); return movie_value; }
};
struct Service { MovieObject* base; void* frame; };
MovieObject movie_object{};
Service movie_service{};
void push(std::uint32_t id,std::array<std::uint32_t,6> args={}) { events.push_back({id,args}); }
void print_case() {
    std::printf("{\"trace\":[");
    for (std::size_t i=0;i<events.size();++i) {
        if(i) std::putchar(',');
        std::printf("[%u",events[i].id);
        for(auto value:events[i].args) std::printf(",%u",value);
        std::putchar(']');
    }
    std::printf("],\"state\":[%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u],\"arena\":[",
      porsche::frame_pump_word_006573b8,porsche::frame_pump_word_006573bc,
      porsche::frame_pump_word_006573c0,porsche::frame_pump_word_006573c4,
      porsche::frame_pump_word_006573d0,porsche::frame_pump_word_006573d4,
      porsche::frame_pump_word_006573d8,porsche::frame_pump_byte_006573e0,
      porsche::frame_pump_byte_006573e1,porsche::frame_pump_byte_006573e2,
      porsche::frame_pump_byte_006573e4,porsche::frame_pump_word_00655a08,
      movie_value);
    for (std::uint32_t i=0;i<0x30;++i) {
        if(i) std::putchar(',');
        std::printf("%u",porsche::frame_pump_storage_bytes_006573b8()[i]);
    }
    std::printf("]}\n");
}
}

namespace porsche {
void* game_setup_movie_service_0069ed0c=nullptr;
std::uint32_t __cdecl window_shutdown_prepare_00534550(){push(1);return 0;}
std::uint32_t __cdecl frame_pump_boundary_004ab150(){push(2);return 0;}
std::uint32_t __cdecl frame_pump_boundary_004ab200(){push(14);return 0;}
std::uint32_t __cdecl frame_pump_boundary_005693e0(){push(3);return 0;}
void __cdecl frame_pump_boundary_00568f30(std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d,std::uint32_t e,std::uint32_t f){push(15,{a,b,c,d,e,f});}
void __cdecl frame_pump_boundary_005360a0(void* self,std::uint32_t one){push(12,{static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self)),one});}
void __cdecl frame_pump_boundary_005363a0(void* self){push(13,{static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(self))});}
void __stdcall render_display_flush_006bd970(){push(4);}
void __stdcall render_display_setstate_006bd97c(std::uint32_t a,std::uint32_t b){push(5,{a,b});}
void __stdcall render_display_window_006bd9b0(std::uint32_t a){push(6,{a});}
void __stdcall render_display_clear_window_006bd91c(){push(7);}
void __stdcall render_display_sync_006bd978(std::uint32_t a){push(9,{a});}
void __stdcall game_setup_render_update_006bd948(){push(8);}
}

int main(){
    std::uint32_t words[13];
    while(scanf_s("%u %u %u %u %u %u %u %u %u %u %u %u %u",&words[0],&words[1],&words[2],&words[3],&words[4],&words[5],&words[6],&words[7],&words[8],&words[9],&words[10],&words[11],&words[12])==13){
        using namespace porsche;
        events.clear();
        for (std::uint32_t i=0;i<0x30;++i) frame_pump_storage_bytes_006573b8()[i]=static_cast<std::uint8_t>(0x40+i);
        frame_pump_word_006573b8=words[0];frame_pump_word_006573bc=words[1];
        frame_pump_word_006573c0=words[2];frame_pump_word_006573c4=words[3];
        frame_pump_word_006573d0=words[4];frame_pump_word_006573d4=words[5];
        frame_pump_word_006573d8=words[6];frame_pump_byte_006573e0=static_cast<std::uint8_t>(words[7]);
        frame_pump_byte_006573e1=static_cast<std::uint8_t>(words[8]);frame_pump_byte_006573e2=static_cast<std::uint8_t>(words[9]);
        frame_pump_byte_006573e4=static_cast<std::uint8_t>(words[10]);frame_pump_word_00655a08=words[11];movie_value=words[12];
        movie_service={&movie_object,reinterpret_cast<void*>(0x12345678)};
        game_setup_movie_service_0069ed0c=&movie_service;
        frame_pump_004b0d70(); print_case();
    }
}
