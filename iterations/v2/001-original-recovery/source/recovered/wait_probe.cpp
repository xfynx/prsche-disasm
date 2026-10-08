#include "porsche/file_wait.hpp"
#include <windows.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace {
using namespace porsche;
constexpr std::uintptr_t BASE=0x03500000;
unsigned char* arena;
std::vector<std::string> calls;
std::uint32_t steps,iteration,pending_value,found_value,thread_value,mutation,fixture_id;
std::int32_t status_value;
std::string ptr(const void* p){return std::to_string(reinterpret_cast<std::uintptr_t>(p));}
void record(const std::string& s){calls.push_back(s);}
std::string hex(const void* p,std::size_t n){auto* b=static_cast<const unsigned char*>(p);const char* digits="0123456789abcdef";std::string out;for(std::size_t i=0;i<n;++i){out+=digits[b[i]>>4];out+=digits[b[i]&15];}return out;}
}
namespace porsche {
FileDevice* devices_006a5c7c;
void __cdecl heap_enter_005322b0(void* p){record("[\"enter\","+ptr(p)+"]");}
void __cdecl heap_leave_005322c0(void* p){record("[\"leave\","+ptr(p)+"]");}
FileOperation* __cdecl operation_find_00567b80(FileDevice* d,std::uint32_t id,std::int32_t* pending){
    record("[\"find\","+ptr(d)+","+std::to_string(id)+"]");
    *pending=static_cast<std::int32_t>(iteration++<steps ? pending_value : 0);
    if(mutation==1)d->initialized=0;
    return found_value ? reinterpret_cast<FileOperation*>(arena+0x3000) : nullptr;
}
std::int32_t __cdecl operation_status_00567af0(std::uint32_t id){record("[\"status\","+std::to_string(id)+"]");return status_value;}
std::int32_t __cdecl file_current_thread_0055f780(std::uint32_t id){
    record("[\"thread\","+std::to_string(id)+"]");
    if(mutation==2)devices_006a5c7c=reinterpret_cast<FileDevice*>(arena+0x1000);
    return static_cast<std::int32_t>(thread_value);
}
std::uint32_t __cdecl file_pump_005366e0(std::uint32_t arg){record("[\"pump\","+std::to_string(arg)+"]");return 0xfedcba98;}
std::uint32_t __cdecl file_sleep_0055f740(std::uint32_t arg){record("[\"sleep\","+std::to_string(arg)+"]");return 0;}
void* __cdecl file_wait_event_0055fc60(void* p){record("[\"wait_event\","+ptr(p)+"]");return nullptr;}
std::uint32_t __cdecl file_reset_event_0055fc40(void* p){record("[\"reset_event\","+ptr(p)+"]");return 0;}
}
int main(){using namespace porsche;
    arena=static_cast<unsigned char*>(VirtualAlloc(reinterpret_cast<void*>(BASE),0x10000,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;
    std::string line;while(std::getline(std::cin,line)){
        std::istringstream in(line);std::vector<std::uint32_t> args;std::string word;while(std::getline(in,word,'|'))args.push_back(static_cast<std::uint32_t>(std::stoull(word)));
        if(args.size()!=9)return 2;
        fixture_id=args[0];steps=args[2];pending_value=args[3];found_value=args[4];thread_value=args[5];status_value=static_cast<std::int32_t>(args[6]);mutation=args[7];iteration=0;
        std::memset(arena,0xcc,0x10000);calls.clear();devices_006a5c7c=reinterpret_cast<FileDevice*>(arena);
        for(std::uint32_t i=0;i<32;++i){devices_006a5c7c[i].initialized=args[1];devices_006a5c7c[i].queued.lock=reinterpret_cast<void*>(args[8]);devices_006a5c7c[i].completed_event=reinterpret_cast<void*>(0x04003000+i*16);auto* other=reinterpret_cast<FileDevice*>(arena+0x1000)+i;other->completed_event=reinterpret_cast<void*>(0x04004000+i*16);}
        const auto result=file_wait_00567f70(fixture_id);
        std::cout<<"{\"result\":"<<result<<",\"devices\":"<<ptr(devices_006a5c7c)<<",\"arena\":\""<<hex(arena,0x3000)<<"\",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"]}\n";
    }return 0;
}
