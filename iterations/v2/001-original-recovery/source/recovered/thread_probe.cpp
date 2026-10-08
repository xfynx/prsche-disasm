#include "porsche/file_threads.hpp"
#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t BASE=0x03600000;
constexpr std::size_t ARENA_BYTES=0x20000;
unsigned char* arena;
std::vector<std::string> calls;
std::uint32_t lock_no,current_id,duplicate_result,created_handle,priority_result,resume_result,sleep_target,sleep_count,allocate_fail;
porsche::ThreadLaunch* pending_launch;
std::vector<std::string> split(const std::string&s){std::vector<std::string>r;std::istringstream in(s);std::string v;while(std::getline(in,v,'|'))r.push_back(v);return r;}
std::uint32_t number(const std::string&s){return static_cast<std::uint32_t>(std::stoul(s,nullptr,0));}
std::uint32_t ptr(const void*p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
std::string hex(const void*p,std::size_t n){static const char*d="0123456789abcdef";auto*b=static_cast<const unsigned char*>(p);std::string s;s.reserve(2*n);for(std::size_t i=0;i<n;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}
void __cdecl no_argument(){calls.push_back("[\"callback0\"]");auto*r=reinterpret_cast<porsche::ThreadRecord*>(arena+0x200);if(sleep_target){r->slot=1;r->serial=99;}}
void __cdecl with_argument(std::uint32_t arg){calls.push_back("[\"callback1\","+std::to_string(arg)+"]");auto*r=reinterpret_cast<porsche::ThreadRecord*>(arena+0x200);if(sleep_target){r->slot=1;r->serial=99;}}
}
namespace porsche {
void __cdecl heap_enter_005322b0(void*p){calls.push_back("[\"enter\","+std::to_string(ptr(p))+"]");}
void __cdecl heap_leave_005322c0(void*p){calls.push_back("[\"leave\","+std::to_string(ptr(p))+"]");}
void* __cdecl heap_lock_create_005321f0(){auto*p=reinterpret_cast<void*>(static_cast<std::uintptr_t>(0x2001000+lock_no++*16));calls.push_back("[\"lock_create\","+std::to_string(ptr(p))+"]");return p;}
void __cdecl heap_fill_0053c290(void*p,std::uint32_t value,std::uint32_t size){calls.push_back("[\"fill\","+std::to_string(ptr(p))+","+std::to_string(value)+","+std::to_string(size)+"]");std::memset(p,value&255,size);}
void* __cdecl file_object_allocate_0056e5f0(std::uint32_t*size){const auto requested=*size;*size=(*size+4095u)&~4095u;auto*p=allocate_fail?nullptr:arena+0x1000;calls.push_back("[\"allocate\","+std::to_string(requested)+","+std::to_string(*size)+","+std::to_string(ptr(p))+"]");return p;}
std::uint32_t __stdcall platform_current_thread_id(){calls.push_back("[\"current_id\"]");return current_id;}
void* __stdcall platform_current_process(){calls.push_back("[\"current_process\"]");return reinterpret_cast<void*>(0x4001000);}
void* __stdcall platform_current_thread(){calls.push_back("[\"current_thread\"]");return reinterpret_cast<void*>(0x4002000);}
std::uint32_t __stdcall platform_duplicate_handle(void*a,void*b,void*c,void**out,std::uint32_t access,std::int32_t inherit,std::uint32_t options){calls.push_back("[\"duplicate\","+std::to_string(ptr(a))+","+std::to_string(ptr(b))+","+std::to_string(ptr(c))+","+std::to_string(out==&main_thread_006a57d0?0x6a57d0:ptr(out))+","+std::to_string(access)+","+std::to_string(inherit)+","+std::to_string(options)+"]");if(duplicate_result)*out=reinterpret_cast<void*>(0x4003000);return duplicate_result;}
void* __stdcall platform_create_thread(void*security,std::uint32_t stack,ThreadBootstrap bootstrap,void*argument,std::uint32_t flags,std::uint32_t*id){auto*launch=static_cast<ThreadLaunch*>(argument);pending_launch=launch;calls.push_back("[\"create_thread\","+std::to_string(ptr(security))+","+std::to_string(stack)+","+std::to_string(bootstrap==thread_bootstrap_0055f4f0?0x55f4f0:ptr(reinterpret_cast<void*>(bootstrap)))+","+std::to_string(ptr(launch->record))+","+std::to_string(launch->no_argument?0x2200e00:0)+","+std::to_string(launch->worker?0x2200e10:0)+","+std::to_string(launch->argument)+","+std::to_string(flags)+"]");*id=0x56781234;return reinterpret_cast<void*>(static_cast<std::uintptr_t>(created_handle));}
std::uint32_t __stdcall platform_resume_thread(void*p){calls.push_back("[\"resume\","+std::to_string(ptr(p))+"]");if(!sleep_target&&pending_launch)pending_launch->handshake=nullptr;return resume_result;}
std::uint32_t __stdcall platform_thread_priority(void*p,std::int32_t v){calls.push_back("[\"priority\","+std::to_string(ptr(p))+","+std::to_string(v)+"]");return priority_result;}
std::uint32_t __stdcall platform_close_handle(void*p){calls.push_back("[\"close\","+std::to_string(ptr(p))+"]");return 1;}
std::uint32_t __stdcall platform_sleep(std::uint32_t n,std::int32_t alertable){calls.push_back("[\"sleep\","+std::to_string(n)+","+std::to_string(alertable)+"]");if(++sleep_count>=sleep_target&&pending_launch)pending_launch->handshake=nullptr;return 0;}
void __cdecl thread_exit_register_00557380(void(__cdecl*callback)()){calls.push_back("[\"exit_register\","+std::to_string(callback==thread_shutdown_0055f1c0?0x55f1c0:ptr(reinterpret_cast<void*>(callback)))+"]");}
void __cdecl thread_shutdown_0055f1c0(){}
}

int main(){using namespace porsche;arena=static_cast<unsigned char*>(VirtualAlloc(reinterpret_cast<void*>(BASE),ARENA_BYTES,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;std::string line;while(std::getline(std::cin,line)){
auto f=split(line);if(f.size()!=9)return 2;const char mode=f[0][0];std::uint32_t a[8];for(int i=0;i<8;++i)a[i]=number(f[i+1]);
std::memset(arena,0xcc,ARENA_BYTES);calls.clear();lock_no=0;sleep_count=0;pending_launch=nullptr;current_id=0x1234;duplicate_result=1;created_handle=0x4004000;priority_result=1;resume_result=1;sleep_target=0;allocate_fail=0;
main_thread_006a57d0=nullptr;main_thread_id_006a57d4=0;thread_start_lock_006a57d8=nullptr;threads_initialized_006a57dc=0;thread_exit_registered_006a57e0=0;thread_entries_006a57e4=nullptr;thread_capacity_006a57e8=0;thread_table_lock_006a57ec=nullptr;thread_serial_005df6a0=1;
auto*record=reinterpret_cast<ThreadRecord*>(arena+0x200);auto*table=reinterpret_cast<ThreadEntry*>(arena+0x1000);auto*launch=reinterpret_cast<ThreadLaunch*>(arena+0x9000);std::uint32_t result=0;
if(mode=='T'){thread_table_lock_006a57ec=a[2]?reinterpret_cast<void*>(0x2002000):nullptr;thread_entries_006a57e4=a[1]?table:nullptr;allocate_fail=a[3];result=thread_table_init_0055f3b0(a[0]);}
else if(mode=='I'){threads_initialized_006a57dc=a[1];allocate_fail=a[2];duplicate_result=a[3];thread_exit_registered_006a57e0=a[4];thread_init_0055f320(a[0]);}
else if(mode=='R'){thread_capacity_006a57e8=static_cast<std::int32_t>(a[0]);thread_entries_006a57e4=table;thread_table_lock_006a57ec=reinterpret_cast<void*>(0x2002000);thread_serial_005df6a0=a[2];for(std::uint32_t i=0;i<std::min(a[0],3u);++i){table[i].serial=(a[1]&(1u<<i))?7:0;table[i].handle=nullptr;table[i].id=0;}result=thread_register_0055f560(record,reinterpret_cast<void*>(static_cast<std::uintptr_t>(a[3])),a[4]);}
else if(mode=='U'){thread_capacity_006a57e8=static_cast<std::int32_t>(a[2]);thread_entries_006a57e4=table;thread_table_lock_006a57ec=reinterpret_cast<void*>(0x2002000);for(int i=0;i<3;++i){table[i].serial=a[3];table[i].handle=reinterpret_cast<void*>(static_cast<std::uintptr_t>(a[4]));table[i].id=0x56781234;}thread_unregister_0055f2b0(static_cast<std::int32_t>(a[0]),a[1]);}
else if(mode=='G'){record->handle=reinterpret_cast<void*>(static_cast<std::uintptr_t>(a[1]));record->id=a[0];result=a[2]?thread_id_0055f7e0(record):ptr(thread_handle_0055f730(record));}
else if(mode=='C'){threads_initialized_006a57dc=a[2];main_thread_id_006a57d4=a[3];record->id=a[4];current_id=a[1];auto identity=a[0]==0xfffffffeu?ptr(record):a[0];result=file_current_thread_0055f780(identity);}
else if(mode=='P'){threads_initialized_006a57dc=a[2];main_thread_006a57d0=reinterpret_cast<void*>(static_cast<std::uintptr_t>(a[4]));record->handle=reinterpret_cast<void*>(static_cast<std::uintptr_t>(a[3]));priority_result=a[5];auto identity=a[0]==0xfffffffeu?ptr(record):a[0];result=thread_priority_0055f8b0(identity,a[1]);}
else if(mode=='S'){threads_initialized_006a57dc=a[5];thread_start_lock_006a57d8=reinterpret_cast<void*>(0x2001000);thread_table_lock_006a57ec=reinterpret_cast<void*>(0x2002000);thread_entries_006a57e4=table;thread_capacity_006a57e8=3;thread_serial_005df6a0=a[6];for(int i=0;i<3;++i){table[i].serial=0;table[i].handle=nullptr;table[i].id=0;}created_handle=a[3];sleep_target=a[4];result=static_cast<std::uint32_t>(file_thread_start_0055f5f0(with_argument,a[0],a[1],a[2],-1,record));}
else if(mode=='B'){thread_table_lock_006a57ec=reinterpret_cast<void*>(0x2002000);thread_entries_006a57e4=table;thread_capacity_006a57e8=2;record->slot=0;record->serial=7;table[0].serial=7;table[0].handle=reinterpret_cast<void*>(0x4005000);table[0].id=0x1234;launch->handshake=reinterpret_cast<void*>(0x4006000);launch->record=record;launch->no_argument=a[0]?no_argument:nullptr;launch->worker=with_argument;launch->argument=a[2];sleep_target=a[1];result=thread_bootstrap_0055f4f0(launch);}
else return 2;
std::vector<unsigned char>copy(arena,arena+ARENA_BYTES);if(mode=='B'){std::uint32_t v=a[0]?0x2200e00:0,w=0x2200e10;std::memcpy(copy.data()+0x9000+8,&v,4);std::memcpy(copy.data()+0x9000+12,&w,4);}
std::cout<<"{\"return\":"<<result<<",\"globals\":["<<ptr(main_thread_006a57d0)<<","<<main_thread_id_006a57d4<<","<<ptr(thread_start_lock_006a57d8)<<","<<threads_initialized_006a57dc<<","<<thread_exit_registered_006a57e0<<","<<ptr(thread_entries_006a57e4)<<","<<thread_capacity_006a57e8<<","<<ptr(thread_table_lock_006a57ec)<<","<<thread_serial_005df6a0<<"],\"arena\":\""<<hex(copy.data(),copy.size())<<"\",\"calls\":[";for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"]}\n";
}return 0;}
