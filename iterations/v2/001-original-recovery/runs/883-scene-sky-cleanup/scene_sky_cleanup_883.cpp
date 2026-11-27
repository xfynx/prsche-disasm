// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "scene_sky_cleanup_883.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/context_effects.hpp"
#include <cstdint>
#include <cstring>
namespace porsche {
void* scene_sky_cleanup_state_00627e5c=nullptr;
namespace {
void* get(const void* p,unsigned off){void* v;std::memcpy(&v,static_cast<const unsigned char*>(p)+off,4);return v;}
}
void __fastcall scene_sky_row_destroy_00468960(void* self,void*){
    application_release_0059f050(get(self,4));
    void* object=get(self,0);
    if(object){using D=void(__fastcall*)(void*,void*,std::uint32_t);auto table=static_cast<D*>(get(object,0));table[0](object,nullptr,1);}
}
void __cdecl scene_sky_cleanup_00460220(){
    void* base=scene_sky_cleanup_state_00627e5c;
    if(base){
        context_table_release_0059ecd0(get(base,0xb8));
        for(unsigned i=0;i<14;++i){
            application_release_0059f050(get(base,0x38+i*4));
            void* row=get(base,i*4);
            if(row){scene_sky_row_destroy_00468960(row,nullptr);application_release_0059f050(row);}
        }
        application_release_0059f050(base);
    }
    scene_sky_cleanup_state_00627e5c=nullptr;
}
}
