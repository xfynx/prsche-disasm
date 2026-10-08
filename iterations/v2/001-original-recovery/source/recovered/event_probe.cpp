#include "porsche/file_events.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t BASE=0x03500000;
constexpr std::size_t ARENA_BYTES=0x1000;
unsigned char* arena;
std::uint32_t raw_wait,raw_action,raw_other;
std::vector<std::string> calls;
std::vector<std::string> split(const std::string&s){std::vector<std::string> r;std::istringstream in(s);std::string x;while(std::getline(in,x,'|'))r.push_back(x);return r;}
std::uint32_t num(const std::string&s){return static_cast<std::uint32_t>(std::stoul(s,nullptr,0));}
std::string hex(const void*p,std::size_t n){static const char d[]="0123456789abcdef";const auto*b=static_cast<const unsigned char*>(p);std::string out;out.reserve(n*2);for(std::size_t i=0;i<n;++i){out+=d[b[i]>>4];out+=d[b[i]&15];}return out;}
std::uint32_t ptr(const void*p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
}
namespace porsche {
void* __stdcall platform_create_event(void*security,std::int32_t manual,std::int32_t initial,const char*name){calls.push_back("[\"create\","+std::to_string(ptr(security))+","+std::to_string(manual)+","+std::to_string(initial)+","+std::to_string(ptr(name))+"]");return reinterpret_cast<void*>(static_cast<std::uintptr_t>(raw_other));}
std::uint32_t __stdcall platform_set_event(void*e){calls.push_back("[\"set\","+std::to_string(ptr(e))+"]");return raw_action;}
std::uint32_t __stdcall platform_reset_event(void*e){calls.push_back("[\"reset\","+std::to_string(ptr(e))+"]");return raw_action;}
std::uint32_t __stdcall platform_wait_events(std::uint32_t n,void* const*handles,std::int32_t all,std::uint32_t timeout,std::int32_t alertable){std::string s="[\"wait\","+std::to_string(n)+",[";for(std::uint32_t i=0;i<n;++i)s+=(i?",":"")+std::to_string(ptr(handles[i]));s+="],"+std::to_string(all)+","+std::to_string(timeout)+","+std::to_string(alertable)+"]";calls.push_back(s);return raw_wait;}
std::uint32_t __stdcall platform_close_handle(void*e){calls.push_back("[\"close\","+std::to_string(ptr(e))+"]");return raw_other;}
std::uint32_t __stdcall platform_last_error(){calls.push_back("[\"error\"]");return raw_other;}
std::uint32_t __stdcall platform_sleep(std::uint32_t n,std::int32_t alertable){calls.push_back("[\"sleep\","+std::to_string(n)+","+std::to_string(alertable)+"]");return raw_other;}
}
int main(){using namespace porsche;arena=static_cast<unsigned char*>(VirtualAlloc(reinterpret_cast<void*>(BASE),ARENA_BYTES,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;std::string line;while(std::getline(std::cin,line)){
    const auto f=split(line);if(f.size()!=10)return 2;const auto va=num(f[0]),count=num(f[1]),ticks=num(f[4]);if(count>3)return 2;
    raw_wait=num(f[2]);timer_rate_005deb48=num(f[3]);raw_action=num(f[8]);raw_other=num(f[9]);calls.clear();std::memset(arena,0xcc,ARENA_BYTES);
    auto**handles=reinterpret_cast<void**>(arena+0x100);for(int i=0;i<3;++i)handles[i]=reinterpret_cast<void*>(static_cast<std::uintptr_t>(num(f[5+i])));
    void* event=handles[0];std::uint32_t result=0;
    switch(va){
    case 0x55f740:result=file_sleep_0055f740(ticks);break;
    case 0x55fb20:result=ptr(file_auto_event_0055fb20());break;
    case 0x55fb30:result=file_event_signal_0055fb30(event);break;
    case 0x55fb40:result=file_try_event_0055fb40(event);break;
    case 0x55fb60:result=ptr(file_wait_many_0055fb60(count,handles,ticks));break;
    case 0x55fb90:result=ptr(file_worker_wait_0055fb90(event));break;
    case 0x55fbb0:result=file_timed_event_0055fbb0(event,ticks);break;
    case 0x55fbf0:result=ptr(file_wait_many_infinite_0055fbf0(count,handles));break;
    case 0x55fc10:result=file_close_event_0055fc10(event);break;
    case 0x55fc20:result=ptr(file_manual_event_0055fc20());break;
    case 0x55fc30:result=file_worker_signal_0055fc30(event);break;
    case 0x55fc40:result=file_reset_event_0055fc40(event);break;
    case 0x55fc60:result=ptr(file_wait_event_0055fc60(event));break;
    case 0x55fc80:result=file_signal_close_0055fc80(event);break;
    case 0x55fce0:result=file_last_error_0055fce0();break;
    default:return 2;
    }
    std::cout<<"{\"return\":"<<result<<",\"rate\":"<<timer_rate_005deb48<<",\"arena\":\""<<hex(arena,ARENA_BYTES)<<"\",\"calls\":[";
    for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"]}\n";
}return 0;}
