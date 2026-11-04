// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete535b50/74B,535ba0/32B,536180/92B,5361e0/55B;1RW/12RO.
#include "render_resource_533.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/render_settings.hpp"
#include <cstring>
namespace porsche {
using U=std::uint32_t;using B=std::uint8_t;
B render_resource_texture_fallback_0069dd1c=0;
const U render_resource_table_005bb6c8[3]={
    reinterpret_cast<U>(&render_resource_destroy_00535ba0),
    reinterpret_cast<U>(&render_resource_create_pair_005361e0),
    reinterpret_cast<U>(&render_resource_create_00536180)
};
namespace {
void put(void* self,U offset,U value){std::memcpy(static_cast<B*>(self)+offset,&value,4);}
void flag(B value){*static_cast<volatile B*>(&render_resource_texture_fallback_0069dd1c)=value;}
}
void* __fastcall render_resource_bound_child_ctor_00535b50(void* self,void*,void* driver){
    put(self,0,reinterpret_cast<U>(render_resource_table_005bb6c8));
    put(self,0x10,0);put(self,4,reinterpret_cast<U>(driver));put(self,8,0);put(self,0xc,0);
    if(render_settings_set_state_006bd97c(0x41,0)==0){flag(1);return self;}
    const U result=render_settings_set_state_006bd97c(0x42,0);
    flag(0);
    if(result==0)flag(1);
    return self;
}
void* __fastcall render_resource_destroy_00535ba0(void* self,void*,U flags){
    put(self,0,reinterpret_cast<U>(render_resource_table_005bb6c8));
    if((static_cast<B>(flags)&1)!=0)(void)application_release_0059f050(self);
    return self;
}
void* __fastcall render_resource_create_00536180(void* self,void*,const void* descriptor,U flags,const char* name){
    if(descriptor){
        void* allocated=startup_network_allocate_0059ef90(0x54);
        if(!allocated)return nullptr;
        return render_resource_node_ctor_00535bc0(allocated,nullptr,descriptor,self,flags,name);
    }
    void* allocated=startup_network_allocate_0059ef90(0x54);
    if(!allocated)return nullptr;
    return render_resource_node_empty_ctor_00535ed0(allocated,nullptr,self,flags,name);
}
void* __fastcall render_resource_create_pair_005361e0(void* self,void*,const void* first,const void* second,U flags,const char* name){
    void* allocated=startup_network_allocate_0059ef90(0x54);
    if(!allocated)return nullptr;
    return render_resource_node_pair_ctor_00535d80(allocated,nullptr,first,second,self,flags,name);
}
}
