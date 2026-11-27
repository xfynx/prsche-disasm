// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 00460a50..00460aaf and 00460cd0..00460d31, original RET4.
#include "scene_sky_878.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/render_startup.hpp"
#include "../786-scene-flare-entries-resolve/scene_flare_resolve_786.hpp"
#include <cstring>
namespace porsche {
void* __fastcall render_resource_node_empty_ctor_00535ed0(void*,void*,void*,std::uint32_t,const char*);
namespace {
using U=std::uint32_t;using B=unsigned char;
void* get(const void* p,U off){void* v;std::memcpy(&v,static_cast<const B*>(p)+off,4);return v;}
void put(void* p,U off,void* v){std::memcpy(static_cast<B*>(p)+off,&v,4);}
}
void* __fastcall scene_sky_ctor_00460a50(void* self,void*,void* archive){
    put(self,4,archive);
    for(U i=0;i<40;++i){put(self,8+i*4,nullptr);put(self,0x198+i*4,nullptr);}
    void* memory=startup_network_allocate_0059ef90(0x54);
    void* node=nullptr;
    if(memory)node=render_resource_node_empty_ctor_00535ed0(memory,nullptr,get(render_display_00628130,0x74),0,nullptr);
    put(self,0,node);return self;
}
void __fastcall scene_sky_update_00460cd0(void* self,void*,void* archive){
    put(self,4,archive);
    for(U i=0;i<40;++i){
        if(get(self,8+i*4)){
            void* chunk=scene_chunk_find_tag_0053c680(get(self,4),reinterpret_cast<const char*>(static_cast<B*>(self)+0xa8+i*6));
            put(self,8+i*4,chunk);
            void* node=get(self,0x198+i*4);
            if(node)scene_sky_texture_update_0044d9a0(node,chunk,0x534b5920,1);
        }
    }
}
}
