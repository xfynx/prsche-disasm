#include "porsche/file_worker.hpp"
#include <windows.h>
#include <cstdarg>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t BASE=0x03400000;
constexpr std::size_t ARENA_BYTES=0x10000;
unsigned char* mem;
std::vector<std::string> calls;
std::vector<std::string> states;
void __cdecl completed(std::uint32_t,std::int32_t,void*);
std::uint32_t backend_value,error_value,signal_count,stop_after,wait_count;
std::string hex(const void* p,std::size_t n){const auto*b=static_cast<const unsigned char*>(p);static const char*d="0123456789abcdef";std::string s;s.reserve(n*2);for(std::size_t i=0;i<n;++i){s+=d[b[i]>>4];s+=d[b[i]&15];}return s;}
std::string texthex(const char*p){return hex(p,std::strlen(p));}
std::vector<std::string> split(const std::string&s){std::vector<std::string> v;std::istringstream in(s);std::string x;while(std::getline(in,x,'|'))v.push_back(x);return v;}
std::uint32_t num(const std::string&s){return static_cast<std::uint32_t>(std::stoul(s,nullptr,0));}
void record(const std::string&s){calls.push_back(s);auto*base=mem+0x100;unsigned char snap[0x70+3*48+28];std::memcpy(snap,base,0x70);const std::uint32_t key1=0x5684c0,key2=0x580670;std::memcpy(snap+0x34,&key1,4);std::memcpy(snap+0x50,&key2,4);for(int i=0;i<3;++i){std::memcpy(snap+0x70+i*48,mem+0x1000+i*0x80,48);if(reinterpret_cast<porsche::FileOperation*>(mem+0x1000+i*0x80)->callback==completed){const std::uint32_t callback=0x2200100;std::memcpy(snap+0x70+i*48+0x20,&callback,4);}}std::memcpy(snap+0x70+3*48,&porsche::free_auxiliary_006a5c38,28);states.push_back(hex(snap,sizeof(snap)));}
std::string pointer(const void*p){return std::to_string(reinterpret_cast<std::uintptr_t>(p));}
void __cdecl completed(std::uint32_t id,std::int32_t status,void* ctx){record("[\"callback\","+std::to_string(id)+","+std::to_string(status)+","+pointer(ctx)+"]");}
}
namespace porsche {
FileDevice* devices_006a5c7c;
IoList free_operations_006a5c58,free_auxiliary_006a5c38;
const char* diagnostic_file_005deb74;
std::uint32_t diagnostic_line_005deb78;
void(__cdecl*diagnostic_handler_005debf0)(const char*);
std::uint32_t __cdecl operation_key_005684c0(IoNode*n,std::uint32_t){auto*o=reinterpret_cast<FileOperation*>(n);return ((o->id>>5)&0xffffffu)|(std::uint32_t(o->group)<<24);}
std::uint32_t __cdecl io_default_key_00580670(IoNode*n,std::uint32_t){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(n));}
void __cdecl heap_enter_005322b0(void*p){record("[\"enter\","+pointer(p)+"]");}
void __cdecl heap_leave_005322c0(void*p){record("[\"leave\","+pointer(p)+"]");}
void* __cdecl heap_lock_create_005321f0(){return nullptr;}
void __cdecl file_worker_signal_0055fc30(void*p){record("[\"signal\","+pointer(p)+"]");if(++signal_count>=stop_after)file_shutdown_006a5c80=1;}
void __cdecl file_worker_wait_0055fb90(void*p){record("[\"wait\","+pointer(p)+"]");++wait_count;file_shutdown_006a5c80=1;}
std::uint32_t __cdecl file_last_error_0055fce0(){record("[\"error\"]");return error_value;}
void* __cdecl file_backend_open_00568900(const char*p,std::uint32_t a,std::uint32_t b){record("[\"open\","+pointer(p)+","+std::to_string(a)+","+std::to_string(b)+"]");return reinterpret_cast<void*>(static_cast<std::uintptr_t>(backend_value));}
std::uint32_t __cdecl file_backend_seek_00592140(void*p,std::uint32_t a){record("[\"seek\","+pointer(p)+","+std::to_string(a)+"]");return backend_value;}
std::uint32_t __cdecl file_backend_read_00591df0(void*p,void*b,std::uint32_t n){record("[\"read\","+pointer(p)+","+pointer(b)+","+std::to_string(n)+"]");return backend_value;}
std::uint32_t __cdecl file_backend_write_00591fa0(void*p,void*b,std::uint32_t n){record("[\"write\","+pointer(p)+","+pointer(b)+","+std::to_string(n)+"]");return backend_value;}
std::uint32_t __cdecl file_backend_info_00591ce0(void*p,void*a,void*b,std::uint32_t*c,void*d){record("[\"info\","+pointer(p)+","+pointer(a)+","+pointer(b)+",33619712,"+pointer(d)+"]");if(backend_value)*c=0x12345678;return backend_value;}
std::uint32_t __cdecl file_backend_005924d0(void*p,std::uint32_t a){record("[\"backend_d0\","+pointer(p)+","+std::to_string(a)+"]");return backend_value;}
std::uint32_t __cdecl file_backend_00592490(void*p){record("[\"backend_90\","+pointer(p)+"]");return backend_value;}
std::uint32_t __cdecl file_backend_00591980(void*p){record("[\"backend_80\","+pointer(p)+"]");return backend_value;}
std::uint32_t __cdecl file_physical_close_00592290(void*p){record("[\"close\","+pointer(p)+"]");return backend_value;}
void __cdecl diagnostic_stub(const char* message,...){va_list args;va_start(args,message);const auto type=va_arg(args,std::uint32_t);va_end(args);record("[\"diagnostic\","+std::to_string(diagnostic_line_005deb78)+",\""+texthex(message)+"\",\""+texthex(diagnostic_file_005deb74)+"\","+std::to_string(type)+"]");}
}

int main(){using namespace porsche;mem=static_cast<unsigned char*>(VirtualAlloc(reinterpret_cast<void*>(BASE),ARENA_BYTES,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!mem)return 3;std::string line;
while(std::getline(std::cin,line)){
auto f=split(line);if(f.size()!=8)return 2;const auto mode=num(f[0]),opcode=num(f[1]),flags=num(f[2]),group=num(f[3]);backend_value=num(f[4]);error_value=num(f[5]);const auto shutdown=num(f[6]),count=num(f[7]);
std::memset(mem,0xcc,ARENA_BYTES);calls.clear();states.clear();signal_count=0;wait_count=0;stop_after=count?count+1:2;file_shutdown_006a5c80=shutdown;diagnostic_handler_005debf0=reinterpret_cast<void(__cdecl*)(const char*)>(diagnostic_stub);
devices_006a5c7c=reinterpret_cast<FileDevice*>(mem+0x100);auto&dev=*devices_006a5c7c;std::memset(&dev,0,sizeof(dev));dev.initialized=mode==5?0:1;dev.queued.lock=reinterpret_cast<void*>(0x02001000);dev.completed.lock=dev.queued.lock;dev.queued.key=operation_key_005684c0;dev.completed.key=io_default_key_00580670;dev.queued_event=reinterpret_cast<void*>(0x04001000);dev.completed_event=reinterpret_cast<void*>(0x04002000);dev.field6c=mode==4?0:mode==11?0xffffffffu:0xff;
std::memset(&free_operations_006a5c58,0,sizeof(IoList));std::memset(&free_auxiliary_006a5c38,0,sizeof(IoList));free_auxiliary_006a5c38.lock=reinterpret_cast<void*>(0x02003000);
const auto n=mode==2?3u:mode==1||mode==5||mode==12?0u:1u;for(std::uint32_t i=0;i<n;++i){auto*o=reinterpret_cast<FileOperation*>(mem+0x1000+i*0x80);std::memset(o,0xcc,sizeof(*o));o->next=nullptr;o->id=0x81234000+i*0x20;o->type=opcode;o->flags=mode==6||mode==10?0:flags;o->status=static_cast<std::int8_t>(mode==10?flags:0x7e);o->group=static_cast<std::uint8_t>(group);o->field14=0xabcdef12;o->handle=0x12340000+i*0x100;o->context=reinterpret_cast<void*>(0x03406000+i*4);o->callback=mode==9?nullptr:completed;o->offset=mode==6?flags:0x31+i;o->count=0x41+i;o->buffer=mode==8?nullptr:mem+0x4000+i*0x100;
if(opcode==0||opcode==3||opcode==9){auto*name=reinterpret_cast<char*>(mem+0x3000+i*0x100);std::memcpy(name,"worker.bin",11);if(mode!=8)o->buffer=name;}
if(opcode==10){auto*aux=reinterpret_cast<IoNode*>(mem+0x2000);aux->next=nullptr;free_auxiliary_006a5c38.head=free_auxiliary_006a5c38.tail=aux;free_auxiliary_006a5c38.count=1;o->buffer=aux;}
io_append_00580730(&dev.queued,reinterpret_cast<IoNode*>(o));}
calls.clear();states.clear();if(mode==12){io_prepend_005806e0(&dev.completed,nullptr);io_locked_remove_005808f0(&free_auxiliary_006a5c38,nullptr);}else file_worker_00568530(0);
std::vector<unsigned char> copy(mem,mem+ARENA_BYTES);auto fix=[&](std::size_t off,std::uint32_t va){std::memcpy(copy.data()+off,&va,4);};fix(0x100+0x24+0x10,0x5684c0);fix(0x100+0x40+0x10,0x580670);for(std::uint32_t i=0;i<n;++i)fix(0x1000+i*0x80+0x20,mode==9?0:0x2200100);
std::cout<<"{\"arena\":\""<<hex(copy.data(),copy.size())<<"\",\"aux\":\""<<hex(&free_auxiliary_006a5c38,sizeof(IoList))<<"\",\"shutdown\":"<<file_shutdown_006a5c80<<",\"calls\":[";for(std::size_t i=0;i<calls.size();++i)std::cout<<(i?",":"")<<calls[i];std::cout<<"],\"states\":[";for(std::size_t i=0;i<states.size();++i)std::cout<<(i?",":"")<<'"'<<states[i]<<'"';std::cout<<"]}\n";
}return 0;}
