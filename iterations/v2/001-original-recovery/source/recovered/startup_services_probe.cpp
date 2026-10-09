#include "porsche/startup_services.hpp"
#include "porsche/files.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <initializer_list>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t NETWORK=0x03600400,ALLOCATED=0x03600200;
std::vector<std::string> calls;
std::string filename;
std::uint32_t allocation_result,drive_check,drive_type,process_result;
bool terminal;
std::string hex(const void* p,std::size_t n){const char*d="0123456789abcdef";const auto*b=static_cast<const std::uint8_t*>(p);std::string s;s.reserve(n*2);for(std::size_t i=0;i<n;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
std::string quoted(const std::string& s){std::string out="\"";for(char c:s){if(c=='\\'||c=='\"')out+='\\';out+=c;}return out+'\"';}
void event(std::uint32_t va,std::initializer_list<std::int64_t> args={}){std::string s="["+std::to_string(va);for(auto v:args)s+=","+std::to_string(v);s+="]";calls.push_back(s);}
}
namespace porsche {
void (__cdecl* diagnostic_handler_005debf0)(const char*)=nullptr;
void __cdecl startup_heap_0059e9d0(std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d){event(0x59e9d0,{a,b,c,d});}
void __cdecl startup_queue_0059edb0(std::uint32_t a,std::uint32_t b){event(0x59edb0,{a,b});}
void __cdecl startup_capacity_00565030(std::uint32_t a){event(0x565030,{a});}
void* __cdecl startup_network_allocate_0059ef90(std::uint32_t n){event(0x59ef90,{n});return allocation_result?reinterpret_cast<void*>(ALLOCATED):nullptr;}
void __cdecl startup_network_construct_0048fc80(void* p){event(0x48fc80,{ptr(p)});}
void __cdecl startup_event_0055fcf0(){event(0x55fcf0);}
void __cdecl startup_subsystem_00564e70(){event(0x564e70);}
void __cdecl startup_subsystem_00564ab0(){event(0x564ab0);}
void __cdecl startup_subsystem_00564850(std::uint32_t a){event(0x564850,{a});}
void __cdecl startup_subsystem_00536e50(){event(0x536e50);}
void __cdecl startup_subsystem_005367b0(std::uint32_t a,std::uint32_t b,std::uint32_t c){event(0x5367b0,{a,b,c});}
void __cdecl startup_subsystem_004b6ff0(){event(0x4b6ff0);}
void __cdecl startup_subsystem_00563ad0(std::uint32_t a,std::uint32_t b,std::uint32_t c){event(0x563ad0,{a,b,c});}
void __cdecl startup_name_005655f0(const char* s){calls.push_back("[\"name\","+quoted(s)+"]");}
std::uint32_t __stdcall startup_module_filename(void* module,char* out,std::uint32_t capacity){calls.push_back("[\"module\","+std::to_string(ptr(module))+","+std::to_string(capacity)+"]");if(filename.empty())return 0;std::memcpy(out,filename.c_str(),filename.size()+1);return static_cast<std::uint32_t>(filename.size());}
std::int32_t __cdecl startup_drive_character_005a2c24(std::int32_t ch){event(0x5a2c24,{ch});return static_cast<std::int32_t>(drive_check);}
void __cdecl startup_drive_format_005a0fbf(char* out,const char*,std::int32_t ch){calls.push_back("[\"drive_format\","+std::to_string(ch)+"]");out[0]=static_cast<char>(ch);out[1]=':';out[2]='\\';out[3]=0;}
void __cdecl startup_command_format_005a0fbf(char* out,const char*,const char* drive){calls.push_back("[\"command_format\","+quoted(drive)+"]");auto s=std::string(drive)+"Autorun.exe";std::memcpy(out,s.c_str(),s.size()+1);}
std::uint32_t __stdcall startup_drive_type(const char* drive){calls.push_back("[\"drive_type\","+quoted(drive)+"]");return drive_type;}
std::uint32_t __stdcall startup_create_process(const char*,char* command,void*,void*,std::int32_t inherit,std::uint32_t flags,void*,const char*,void* startup,void* process){
    calls.push_back("[\"create_process\","+quoted(command)+","+std::to_string(inherit)+","+std::to_string(flags)+","+quoted(hex(startup,68))+","+quoted(hex(process,16))+"]");
    return process_result;
}
void __cdecl startup_exit_005a246e(std::uint32_t code){event(0x5a246e,{code});terminal=true;}
}
int main(){
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream in(line);int mode,existing;std::uint32_t allocated,check,kind,created;
        in>>mode>>existing>>allocated>>check>>kind>>created>>filename;if(!in)return 2;
        if(filename=="-")filename.clear();
        calls.clear();terminal=false;allocation_result=allocated;drive_check=check;drive_type=kind;process_result=created;
        porsche::startup_network_00628c70=existing?reinterpret_cast<void*>(NETWORK):nullptr;
        porsche::diagnostic_handler_005debf0=nullptr;
        if(mode==0)porsche::startup_services_004a5410();
        else if(mode==1)porsche::startup_cd_relaunch_004a5c30();else return 3;
        std::cout<<"{\"globals\":["<<ptr(reinterpret_cast<void*>(porsche::diagnostic_handler_005debf0))<<","<<ptr(porsche::startup_network_00628c70)<<"],\"terminal\":"<<(terminal?"true":"false")<<",\"calls\":[";
        for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];
        std::cout<<"]}\n";
    }
}
