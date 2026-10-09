#include "porsche/game_setup.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/startup_services.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace porsche {
void* game_setup_movie_service_0069ed0c=nullptr;
void* startup_network_00628c70=nullptr;
}

namespace {
std::vector<std::string> trace;
std::uint8_t service_storage[0x200]{};
std::uint8_t network_storage[0x100]{};
std::uint32_t report_value=0x13579bdf;

void record(const char* value) { trace.emplace_back(value); }
void record_value(const char* name,std::uint32_t value) {
    char buffer[96]{};
    std::snprintf(buffer,sizeof(buffer),"%s:%08x",name,value);
    trace.emplace_back(buffer);
}
void set_word(void* base,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,sizeof(value));
}
}

namespace porsche {
void __fastcall startup_sequence_service_00536080(void* receiver,void*) {
    const auto offset=static_cast<std::uint32_t>(
        static_cast<std::uint8_t*>(receiver)-service_storage);
    record_value("00536080",offset);
}
void __cdecl startup_sequence_call_0044dfb0(){record("0044dfb0");}
void __cdecl startup_sequence_call_0056a490(){record("0056a490");}
void __cdecl startup_sequence_call_00516950(){record("00516950");}
void __cdecl startup_sequence_call_00413cf0(){record("00413cf0");}
void __cdecl startup_sequence_call_00427a60(){record("00427a60");}
void __cdecl splash_progress_004a4a70(std::int32_t phase) {
    record_value("004a4a70",static_cast<std::uint32_t>(phase));
}
void __cdecl startup_sequence_call_004a4700(){record("004a4700");}
void __cdecl startup_sequence_call_004b0d70(){record("004b0d70");}
void __cdecl startup_sequence_call_004affd0(){record("004affd0");}
void __cdecl startup_sequence_call_00468fb0(){record("00468fb0");}
void __cdecl startup_sequence_call_00471b70(){record("00471b70");}
void __cdecl startup_sequence_call_004a8cd0(){record("004a8cd0");}
void __cdecl startup_sequence_call_00414db0(){record("00414db0");}
void __cdecl startup_sequence_call_004690d0(){record("004690d0");}
void __cdecl startup_sequence_call_00434a90(){record("00434a90");}
void __cdecl startup_sequence_call_00424460(){record("00424460");}
void __cdecl startup_sequence_call_00415dc0(){record("00415dc0");}
void __cdecl startup_sequence_call_004b0fa0(){record("004b0fa0");}
void __cdecl startup_sequence_call_004121b0(){record("004121b0");}
std::uint32_t __cdecl startup_sequence_value_00569a90(){
    record("00569a90");
    return report_value;
}
void __cdecl startup_sequence_report_005a177b(std::uint32_t format_va,
                                               std::uint32_t value) {
    record_value("005a177b.format",format_va);
    record_value("005a177b.value",value);
}
void __cdecl startup_sequence_call_0048cdf0(){record("0048cdf0");}
void __cdecl startup_sequence_text_0044df10(std::uint32_t text_va) {
    record_value("0044df10",text_va);
}
void __cdecl startup_sequence_transfer_004691c0(){record("tail.004691c0");}
}

int main(int argc,char** argv) {
    const std::string scenario=argc>1?argv[1]:"connected";
    if(argc>2) report_value=static_cast<std::uint32_t>(std::strtoul(argv[2],nullptr,16));
    porsche::startup_sequence_word_00606ac0=0xa5a5a5a5u;
    porsche::startup_sequence_word_00606ac4=0x5a5a5a5au;
    porsche::game_setup_movie_service_0069ed0c=service_storage;
    set_word(service_storage,4,static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(service_storage+0x80)));
    porsche::startup_network_00628c70=nullptr;
    std::memset(network_storage,0,sizeof(network_storage));
    if(scenario!="none") {
        if(scenario=="connected" || scenario=="blocked") set_word(network_storage,8,1);
        if(scenario=="blocked") network_storage[0xbf]=1;
        porsche::startup_network_00628c70=network_storage;
    }

    std::uintptr_t stack_before=0,stack_after=0;
    __asm mov eax, esp
    __asm mov stack_before, eax
    porsche::startup_sequence_004b67b0();
    __asm mov eax, esp
    __asm mov stack_after, eax

    std::cout<<"{\"trace\":[";
    for(std::size_t i=0;i<trace.size();++i) {
        if(i) std::cout<<',';
        std::cout<<'"'<<trace[i]<<'"';
    }
    std::cout<<"],\"state\":["<<std::hex
             <<porsche::startup_sequence_word_00606ac0<<','
             <<porsche::startup_sequence_word_00606ac4<<"],\"stack_equal\":"
             <<(stack_before==stack_after?"true":"false")<<"}\n";
    return 0;
}
