#include "porsche/startup_input.hpp"
#include <windows.h>
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr std::uintptr_t base=0x03600000;
constexpr std::size_t bytes=0x10000;
constexpr std::uint32_t ex=0x02200000;
std::uint8_t* arena;
std::int32_t create_result,device_result,query_result,format_result,cooperative_result;
std::uint32_t lock_count;
std::vector<std::string> calls;
std::uint32_t ptr(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
void event(std::string value){calls.emplace_back(std::move(value));}
std::string call_list(){std::string out;for(std::size_t i=0;i<calls.size();++i){if(i)out+=',';out+=calls[i];}return out;}
std::uint32_t canon(const void* p){
    auto n=ptr(p);
    if(p==&porsche::startup_direct_input_006a5b14)return 0x006a5b14;
    if(p==&porsche::startup_keyboard_device_006a5b18)return 0x006a5b18;
    if(p==&porsche::class_lock_0069e59c)return 0x0069e59c;
    if(p==&porsche::window_hwnd_006b7bf8)return 0x006b7bf8;
    if(n>=base&&n<base+bytes)return n;
    return n;
}
std::uint32_t canon_guid(const void* p){
    const auto n=ptr(p);
    if(n==0x5bf970u+0)return 0x5bf970;
    if(p && std::memcmp(p,"\x20\x82\x72\x55\x3c\xd3\xcf\x11\xbf\xc7\x44\x45\x53\x54\0\0",16)==0)return 0x5bf970;
    if(p && std::memcmp(p,"\x61\x2b\x1d\x6f\xa0\xd5\xcf\x11\xbf\xc7\x44\x45\x53\x54\0\0",16)==0)return 0x5bf9b0;
    if(p && std::memcmp(p,"\x82\xe6\x44\x59\x2e\xc9\xcf\x11\xbf\xc7\x44\x45\x53\x54\0\0",16)==0)return 0x5bf8c0;
    return n;
}
std::uint32_t canon_data(const void* p){
    if(p && *static_cast<const std::uint32_t*>(p)==0x18 &&
       *reinterpret_cast<const std::uint32_t*>(static_cast<const std::uint8_t*>(p)+16)==3)return 0x56f9e0;
    return ptr(p);
}
std::string hex(const std::uint8_t* p,std::size_t n){static constexpr char d[]="0123456789abcdef";std::string s(n*2,'0');for(std::size_t i=0;i<n;++i){s[2*i]=d[p[i]>>4];s[2*i+1]=d[p[i]&15];}return s;}
void* obj(std::uint32_t offset){return arena+offset;}
std::uint32_t __stdcall com_release(void* self){event("[\"release\","+std::to_string(ptr(self))+"]");return 1;}
std::uint32_t __stdcall com_unacquire(void* self){event("[\"unacquire\","+std::to_string(ptr(self))+"]");return 1;}
std::int32_t __stdcall di_create_device(void* self,const void* guid,void** out,void* outer){
    const auto out_id=(out==reinterpret_cast<void**>(0x006a5b14u))?0x006a5b14u:
        ((out==reinterpret_cast<void**>(0x006a5b18u))?0x006a5b18u:0x3008000u);
    event("[\"create_device\","+std::to_string(ptr(self))+","+std::to_string(canon_guid(guid))+","+
          std::to_string(out_id)+","+std::to_string(ptr(outer))+ "]");
    if(device_result==0)*out=obj(0x4010);return device_result;
}
std::int32_t __stdcall query_device(void* self,const void* guid,void** out){
    const auto out_id=(out==&porsche::startup_keyboard_device_006a5b18)?0x006a5b18u:0x3008000u;
    event("[\"query_interface\","+std::to_string(ptr(self))+","+std::to_string(canon_guid(guid))+","+std::to_string(out_id)+"]");
    if(query_result==0)*out=obj(0x4020);return query_result;
}
std::int32_t __stdcall set_format(void* self,const void* format){
    event("[\"set_format\","+std::to_string(ptr(self))+","+std::to_string(canon_data(format))+ "]");return format_result;
}
std::int32_t __stdcall set_cooperative(void* self,void* hwnd,std::uint32_t flags){
    event("[\"set_cooperative\","+std::to_string(ptr(self))+","+std::to_string(ptr(hwnd))+","+std::to_string(flags)+"]");return cooperative_result;
}
void install_tables(){
    auto* di_table=reinterpret_cast<void**>(arena+0x5000);auto* device_a_table=reinterpret_cast<void**>(arena+0x5100);
    auto* device2_table=reinterpret_cast<void**>(arena+0x5200);
    std::fill(di_table,di_table+16,nullptr);std::fill(device_a_table,device_a_table+16,nullptr);std::fill(device2_table,device2_table+16,nullptr);
    di_table[2]=reinterpret_cast<void*>(&com_release);di_table[3]=reinterpret_cast<void*>(&di_create_device);device_a_table[0]=reinterpret_cast<void*>(&query_device);
    device_a_table[2]=reinterpret_cast<void*>(&com_release);device2_table[2]=reinterpret_cast<void*>(&com_release);
    device2_table[8]=reinterpret_cast<void*>(&com_unacquire);device2_table[11]=reinterpret_cast<void*>(&set_format);
    device2_table[13]=reinterpret_cast<void*>(&set_cooperative);
    *reinterpret_cast<void**>(obj(0x4000))=di_table;*reinterpret_cast<void**>(obj(0x4010))=device_a_table;
    *reinterpret_cast<void**>(obj(0x4020))=device2_table;
}
}

namespace porsche {
std::uint32_t worker_accelerator_006bd9dc=0;
std::uint32_t window_input_capacity_0069e560=0,window_input_read_0069e0d8=0,window_input_write_0069e568=0;
void* class_lock_0069e59c=nullptr;
void* hwnd_storage=nullptr;void*& window_hwnd_006b7bf8=hwnd_storage;
const char* diagnostic_file_005deb74=nullptr;std::uint32_t diagnostic_line_005deb78=0;
void(__cdecl* diagnostic_handler_005debf0)(const char*)=nullptr;
void* __stdcall startup_input_get_module_handle(){event("[\"get_module\",0]");return reinterpret_cast<void*>(0x4001000);}
std::int32_t __stdcall startup_input_direct_input_create(void* module,std::uint32_t version,void** output,void* outer){
    event("[\"direct_input_create\","+std::to_string(ptr(module))+","+std::to_string(version)+","+
          std::to_string(output==&startup_direct_input_006a5b14?0x006a5b14u:ptr(output))+","+std::to_string(ptr(outer))+"]");
    if(create_result==0)*output=obj(0x4000);return create_result;
}
void __cdecl thread_exit_register_00557380(void(__cdecl* callback)()){
    event("[\"callback_register\","+std::to_string(callback==startup_input_exit_cleanup_0055fe40?0x55fe40u:ptr(reinterpret_cast<void*>(callback)))+"]");
}
void* __cdecl heap_lock_create_005321f0(){const auto result=reinterpret_cast<void*>(0x2001000u+lock_count++*16u);event("[\"lock_create\","+std::to_string(ptr(result))+"]");return result;}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(base),bytes,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!arena)return 3;
    std::uint32_t init,registered,has_di,has_device,create,create_device,query,format,cooperative,has_lock,capacity,read,write,callback,hwnd,cleanup_after;
    while(std::cin>>init>>registered>>has_di>>has_device>>create>>create_device>>query>>format>>cooperative>>has_lock>>capacity>>read>>write>>callback>>hwnd>>cleanup_after){
        std::memset(arena,0xcc,bytes);calls.clear();lock_count=0;install_tables();
        porsche::startup_direct_input_006a5b14=has_di?obj(0x4000):nullptr;
        porsche::startup_keyboard_device_006a5b18=has_device?obj(0x4020):nullptr;
        porsche::startup_input_initialized_006a5b1c=init;porsche::startup_input_cleanup_registered_006a5b20=registered;
        porsche::startup_input_key_callback_005df6a4=callback?reinterpret_cast<void*>(0x5abc1234):nullptr;
        porsche::worker_accelerator_006bd9dc=1;porsche::class_lock_0069e59c=has_lock?reinterpret_cast<void*>(0x2003000):nullptr;
        porsche::window_hwnd_006b7bf8=hwnd?reinterpret_cast<void*>(hwnd):nullptr;
        porsche::window_input_capacity_0069e560=capacity;porsche::window_input_read_0069e0d8=read;porsche::window_input_write_0069e568=write;
        porsche::diagnostic_file_005deb74=nullptr;porsche::diagnostic_line_005deb78=0;porsche::diagnostic_handler_005debf0=nullptr;
        create_result=static_cast<std::int32_t>(create);device_result=static_cast<std::int32_t>(create_device);
        query_result=static_cast<std::int32_t>(query);format_result=static_cast<std::int32_t>(format);cooperative_result=static_cast<std::int32_t>(cooperative);
        const auto result=porsche::startup_input_initialize_0055fcf0();
        if(cleanup_after)porsche::startup_input_exit_cleanup_0055fe40();
        std::array<std::uint8_t,bytes> snapshot{};std::memcpy(snapshot.data(),arena,bytes);
        const auto normalize=[&](std::size_t offset,std::uint32_t value){std::memcpy(snapshot.data()+offset,&value,4);};
        normalize(0x5000+2*4,0x02200220);normalize(0x5000+3*4,0x02200200);
        normalize(0x5100,0x02200210);normalize(0x5100+2*4,0x02200220);
        normalize(0x5200+2*4,0x02200220);normalize(0x5200+8*4,0x02200230);
        normalize(0x5200+11*4,0x02200240);normalize(0x5200+13*4,0x02200250);
        const std::string globals="["+std::to_string(ptr(porsche::startup_direct_input_006a5b14))+","+
            std::to_string(ptr(porsche::startup_keyboard_device_006a5b18))+","+
            std::to_string(porsche::startup_input_initialized_006a5b1c)+","+
            std::to_string(porsche::startup_input_cleanup_registered_006a5b20)+","+
            std::to_string(porsche::worker_accelerator_006bd9dc)+","+
            std::to_string(ptr(porsche::class_lock_0069e59c))+","+
            std::to_string(porsche::window_input_capacity_0069e560)+","+
            std::to_string(porsche::window_input_read_0069e0d8)+","+
            std::to_string(porsche::window_input_write_0069e568)+","+
            std::to_string(ptr(porsche::startup_input_key_callback_005df6a4))+","+
            std::to_string(ptr(porsche::diagnostic_file_005deb74))+","+
            std::to_string(porsche::diagnostic_line_005deb78)+"]";
        std::cout<<"{\"return\":"<<result<<",\"globals\":"<<globals<<",\"arena\":\""<<hex(snapshot.data(),bytes)
                 <<"\",\"calls\":["<<call_list()<<"]}\n";
    }
    return 0;
}
