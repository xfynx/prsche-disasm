#include "porsche/file_device.hpp"
#include <windows.h>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace { constexpr std::uintptr_t BASE=0x03300000,ARENA=0x10000; unsigned char* mem; std::vector<std::string> calls; std::uint32_t thread_result,event_counter,alloc_result,free_result,system_page,lock_counter;
std::vector<std::string> split(const std::string&s,char c){std::vector<std::string>r;std::istringstream i(s);std::string x;while(std::getline(i,x,c))r.push_back(x);return r;}
std::string hex(const void*p,size_t n){static const char*d="0123456789abcdef";auto*b=(const unsigned char*)p;std::string r;r.reserve(n*2);for(size_t i=0;i<n;++i)r+=d[b[i]>>4],r+=d[b[i]&15];return r;}
void rec(const std::string&s){calls.push_back(s);} std::uint32_t num(const std::string&s){return std::stoul(s,nullptr,0);}
}
namespace porsche {
FileDevice* devices_006a5c7c; IoList free_operations_006a5c58,free_auxiliary_006a5c38; const char* diagnostic_file_005deb74; std::uint32_t diagnostic_line_005deb78; void(__cdecl*diagnostic_handler_005debf0)(const char*);
std::uint32_t __cdecl operation_key_005684c0(IoNode*n,std::uint32_t){auto*o=(FileOperation*)n;return ((o->id>>5)&0xffffffu)|((std::uint32_t)o->group<<24);}
void __cdecl heap_enter_005322b0(void*p){rec("[\"enter\","+std::to_string((std::uintptr_t)p)+"]");} void __cdecl heap_leave_005322c0(void*p){rec("[\"leave\","+std::to_string((std::uintptr_t)p)+"]");} void* __cdecl heap_lock_create_005321f0(){rec("[\"create\"]");return (void*)(std::uintptr_t)(0x02002000+lock_counter++*16);}
void __stdcall platform_system_info(void*p){std::memset(p,0,36);*(std::uint32_t*)((unsigned char*)p+4)=system_page,lock_counter;rec("[\"system_info\"]");}
void* __stdcall platform_virtual_alloc(void*p,std::uint32_t n,std::uint32_t t,std::uint32_t pr){rec("[\"virtual_alloc\","+std::to_string((std::uintptr_t)p)+","+std::to_string(n)+","+std::to_string(t)+","+std::to_string(pr)+"]");return (void*)(std::uintptr_t)alloc_result;}
std::uint32_t __stdcall platform_virtual_free(void*p,std::uint32_t n,std::uint32_t t){rec("[\"virtual_free\","+std::to_string((std::uintptr_t)p)+","+std::to_string(n)+","+std::to_string(t)+"]");return free_result;}
void* __cdecl file_auto_event_0055fb20(){auto p=(void*)(std::uintptr_t)(0x04001000+event_counter++*16);rec("[\"auto_event\","+std::to_string((std::uintptr_t)p)+"]");return p;}
void* __cdecl file_manual_event_0055fc20(){auto p=(void*)(std::uintptr_t)(0x04002000+event_counter++*16);rec("[\"manual_event\","+std::to_string((std::uintptr_t)p)+"]");return p;}
void __cdecl file_wait_event_0055fc60(void*p){rec("[\"wait_event\","+std::to_string((std::uintptr_t)p)+"]");} void __cdecl file_reset_event_0055fc40(void*p){rec("[\"reset_event\","+std::to_string((std::uintptr_t)p)+"]");}
void __cdecl file_worker_00568530(std::uint32_t){}
std::int32_t __cdecl file_thread_start_0055f5f0(FileWorker worker,std::uint32_t i,std::uint32_t stack,std::uint32_t priority,std::int32_t affinity,void*out){rec("[\"thread\","+std::to_string(worker==file_worker_00568530?0x00568530:(std::uint32_t)(std::uintptr_t)worker)+","+std::to_string(i)+","+std::to_string(stack)+","+std::to_string(priority)+","+std::to_string(affinity)+","+std::to_string((std::uintptr_t)out)+"]");if(thread_result)devices_006a5c7c[i].initialized=1;return thread_result;}
void __cdecl diagnostic_stub(const char*m){rec("[\"diagnostic\","+std::to_string(diagnostic_line_005deb78)+",\""+hex(m,std::strlen(m))+"\"]");}
}
std::string snapshot() {
    using namespace porsche;std::vector<unsigned char> copy(mem,mem+ARENA);
    auto fix=[&](std::size_t pos) { IoKey key;std::memcpy(&key,copy.data()+pos,4);std::uint32_t va=key==io_default_key_00580670?0x00580670:key==operation_key_005684c0?0x005684c0:(std::uint32_t)(std::uintptr_t)key;std::memcpy(copy.data()+pos,&va,4); };
    fix(0x2010);fix(0x2050);for(int i=0;i<32;++i){fix(0x100+i*112+0x34);fix(0x100+i*112+0x50);}return hex(copy.data(),copy.size());
}
int main(){using namespace porsche;mem=(unsigned char*)VirtualAlloc((void*)BASE,ARENA,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE);if(!mem)return 3;std::string line;while(std::getline(std::cin,line)){auto f=split(line,'|');if(f.size()<1)return 2;std::memset(mem,0xcc,ARENA);calls.clear();event_counter=0;lock_counter=0;thread_result=f[0]=="P"?num(f[4]):num(f[3]);file_page_size_006a6418=0;diagnostic_handler_005debf0=diagnostic_stub;
 if(f[0]=="P"){if(f.size()<6)return 2;auto page=num(f[1]),cached=num(f[2]),size=num(f[3]);alloc_result=num(f[4]);free_result=num(f[5]);system_page=page;file_page_size_006a6418=cached?page:0;std::uint32_t n=size;auto*p=file_object_allocate_0056e5f0(&n);auto fr=file_object_free_0056e640(p);std::cout<<"{\"returns\":["<<n<<","<<(std::uintptr_t)p<<","<<fr<<","<<file_page_size_006a6418<<"],\"arena\":\""<<snapshot()<<"\",\"calls\":[";}
 else {if(f.size()<7)return 2;auto i=num(f[1]);devices_006a5c7c=(FileDevice*)(mem+0x100);std::memset(devices_006a5c7c,0xcc,32*sizeof(FileDevice));std::memset(&free_operations_006a5c58,0,sizeof(IoList));std::memset(&free_auxiliary_006a5c38,0,sizeof(IoList));free_operations_006a5c58.lock=(void*)0x02001000;auto*l=(IoList*)(mem+0x2000),*b=(IoList*)(mem+0x2040);io_init_00580630(l,f[4]=="1"?operation_key_005684c0:nullptr,num(f[5]));io_borrow_00580680(b,f[4]=="1"?operation_key_005684c0:nullptr,num(f[5]),l);devices_006a5c7c[i].initialized=num(f[2]);thread_result=num(f[3]);file_start_device_00568390(i);if(f[6]=="1")file_start_device_00568390(i);std::cout<<"{\"returns\":["<<io_default_key_00580670((IoNode*)(mem+0x4000),num(f[5]))<<"],\"arena\":\""<<snapshot()<<"\",\"calls\":[";}
 for(size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"]}\n";}return 0;}
