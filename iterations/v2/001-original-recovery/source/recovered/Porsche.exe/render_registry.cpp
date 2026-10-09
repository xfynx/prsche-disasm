#include "porsche/render_registry.hpp"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <windows.h>

namespace porsche {
namespace {
constexpr std::uint32_t registry_root=0x80000002u;
constexpr std::uint32_t registry_access=0x000f003fu;
// The failed/oversized text path loads this byte from original .data VA 005e8e50.
constexpr std::uint8_t registry_text_fallback=0xd1;

struct RegistryDefault {
    const char* name;
    std::uint32_t type;
    const void* value;
};
constexpr char default_driver[]="dx";
constexpr char default_mode[]="640x480";
constexpr char default_language[]="English";
constexpr char default_primary[]="porsche-entry.earacing.com";
constexpr char default_version[]="0.0";
constexpr std::uint32_t zero=0,one=1;
constexpr RegistryDefault defaults[]={
    {"Thrash Driver",1,default_driver},
    {"D3D Device",4,&zero},
    {"Thrash Resolution",1,default_mode},
    {"Hardware Acceleration",4,&one},
    {"Triple Buffer",4,&zero},
    {"Language",1,default_language},
    {"Primary Address",1,default_primary},
    {"Client Version",1,default_version},
    {"Server Version",1,default_version}
};

std::int32_t __stdcall real_open(std::uint32_t key,const char* path,std::uint32_t reserved,
    std::uint32_t access,std::uint32_t* result) {
    return static_cast<std::int32_t>(::RegOpenKeyExA(reinterpret_cast<HKEY>(key),path,
        reserved,access,reinterpret_cast<PHKEY>(result)));
}
std::int32_t __stdcall real_create(std::uint32_t key,const char* path,std::uint32_t* result) {
    return static_cast<std::int32_t>(::RegCreateKeyA(reinterpret_cast<HKEY>(key),path,
        reinterpret_cast<PHKEY>(result)));
}
std::int32_t __stdcall real_close(std::uint32_t key) {
    return static_cast<std::int32_t>(::RegCloseKey(reinterpret_cast<HKEY>(key)));
}
std::int32_t __stdcall real_query(std::uint32_t key,const char* name,std::uint32_t* reserved,
    std::uint32_t* type,std::uint8_t* data,std::uint32_t* bytes) {
    return static_cast<std::int32_t>(::RegQueryValueExA(reinterpret_cast<HKEY>(key),name,
        reinterpret_cast<LPDWORD>(reserved),reinterpret_cast<LPDWORD>(type),data,
        reinterpret_cast<LPDWORD>(bytes)));
}
std::int32_t __stdcall real_set(std::uint32_t key,const char* name,std::uint32_t reserved,
    std::uint32_t type,const std::uint8_t* data,std::uint32_t bytes) {
    return static_cast<std::int32_t>(::RegSetValueExA(reinterpret_cast<HKEY>(key),name,
        reserved,type,data,bytes));
}
const RenderRegistryApi real_api{real_open,real_create,real_close,real_query,real_set};
const RenderRegistryApi* active_api=&real_api;

std::uint8_t* bytes(RenderCore* core) {return reinterpret_cast<std::uint8_t*>(core);}
std::uint32_t read32(const std::uint8_t* p,std::size_t offset) {
    std::uint32_t v;std::memcpy(&v,p+offset,sizeof(v));return v;
}
void write32(std::uint8_t* p,std::size_t offset,std::uint32_t value) {
    std::memcpy(p+offset,&value,sizeof(value));
}
const RegistryDefault& entry(std::uint32_t index) {return defaults[index];}
std::uint32_t default_size(const RegistryDefault& value) {
    return value.type==1?static_cast<std::uint32_t>(std::strlen(static_cast<const char*>(value.value))):4u;
}
void format_path(char* out,const char* company,const char* product) {
    std::sprintf(out,"SOFTWARE\\%s\\%s",company,product);
}
}

void __cdecl render_registry_bind_api(const RenderRegistryApi* api) {
    active_api=api?api:&real_api;
}

void __cdecl render_core_first_004b76f0(RenderCore* core) {
    (void)render_registry_first_result_004b76f0(core);
}

void __cdecl render_registry_defaults_004b7150(RenderCore* core) {
    const auto hkey=read32(bytes(core),0x114);
    for(const auto& value:defaults) {
        active_api->set_value_ex_a(hkey,value.name,0,value.type,
            static_cast<const std::uint8_t*>(value.value),default_size(value));
    }
}

std::uint32_t __cdecl render_registry_first_result_004b76f0(RenderCore* core) {
    auto* object=bytes(core);
    const auto* company=reinterpret_cast<const char*>(static_cast<std::uintptr_t>(read32(object,4)));
    const auto* title=reinterpret_cast<const char*>(static_cast<std::uintptr_t>(read32(object,0x0c)));
    auto* path=reinterpret_cast<char*>(object+0x10);
    auto* hkey=reinterpret_cast<std::uint32_t*>(object+0x114);

    // The two legacy product names are rejected when they already exist.
    constexpr const char* aliases[]={"Need for Speed - Porsche 2000","Need for Speed - Porsche"};
    for(const auto* alias:aliases) {
        format_path(path,company,alias);
        if(active_api->open_key_ex_a(registry_root,path,0,registry_access,hkey)==0) {
            object[0x110]=1;
            return 1;
        }
    }

    format_path(path,company,title);
    const auto open_status=active_api->open_key_ex_a(registry_root,path,0,registry_access,hkey);
    if(open_status!=0 && active_api->create_key_a(registry_root,path,hkey)==0)
        render_registry_defaults_004b7150(core);
    object[0x110]=1;
    return static_cast<std::uint32_t>(open_status==0);
}

void __cdecl render_registry_activate_004b7220(RenderCore* core) {
    auto* object=bytes(core);
    active_api->close_key(read32(object,0x114));
    object[0x110]=0;
}

void __cdecl render_registry_text_004b7240(RenderCore* core,std::uint32_t index,char* out) {
    const auto& value=entry(index);
    const auto hkey=read32(bytes(core),0x114);
    std::uint8_t local[0x100];
    std::uint32_t size=0xff;
    auto status=active_api->query_value_ex_a(hkey,value.name,nullptr,nullptr,local,&size);
    if(status!=0) {
        active_api->set_value_ex_a(hkey,value.name,0,value.type,
            static_cast<const std::uint8_t*>(value.value),default_size(value));
        status=active_api->query_value_ex_a(hkey,value.name,nullptr,nullptr,local,&size);
    }
    (void)status;
    if(size<sizeof(local)) std::memcpy(out,local,size);
    else out[0]=static_cast<char>(registry_text_fallback);
}

std::uint32_t __cdecl render_registry_choice_004b7340(RenderCore* core,std::uint32_t index) {
    const auto& value=entry(index);
    const auto hkey=read32(bytes(core),0x114);
    std::uint32_t result=index,size=4;
    if(active_api->query_value_ex_a(hkey,value.name,nullptr,nullptr,
        reinterpret_cast<std::uint8_t*>(&result),&size)!=0) {
        active_api->set_value_ex_a(hkey,value.name,0,value.type,
            static_cast<const std::uint8_t*>(value.value),default_size(value));
        active_api->query_value_ex_a(hkey,value.name,nullptr,nullptr,
            reinterpret_cast<std::uint8_t*>(&result),&size);
    }
    return result;
}
}
