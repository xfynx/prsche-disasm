// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Five complete originals274B; one4B loader-zero calibration pointer.
#include "render_driver_destruction_525.hpp"
#include "render_initialize_521.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/window_shutdown.hpp"
#include <cstring>
namespace porsche {
void* render_calibration_object_0069de44=nullptr;
namespace {
using U=std::uint32_t;
U get(const void* p,U offset){U v;std::memcpy(&v,static_cast<const unsigned char*>(p)+offset,4);return v;}
void table(void* p,const U* value){const U v=reinterpret_cast<U>(value);std::memcpy(p,&v,4);}
void* derived_destroy(void* self,U flags,const U* vtable){
    table(self,vtable);
    render_calibration_release_00536950();
    (void)application_release_0059f050(reinterpret_cast<void*>(get(self,4)));
    (void)window_shutdown_prepare_00534550();
    (void)render_initialize_shutdown_00575930(1);
    (void)render_initialize_library_00575640(0);
    render_video_mode_005deaa8=0;
    (void)render_driver_cleanup_00538ce0(self,nullptr);
    if(flags&1u)(void)application_release_0059f050(self);
    return self;
}
}
std::uint32_t __fastcall render_driver_cleanup_00538ce0(void* self,void*){
    table(self,render_driver_base_table_005bb860);
    (void)application_release_0059f050(render_driver_context_0069e0d4);
    return application_release_0059f050(reinterpret_cast<void*>(get(self,0x18)));
}
void* __fastcall render_driver_base_destroy_00538ab0(void* self,void*,std::uint32_t flags){
    (void)render_driver_cleanup_00538ce0(self,nullptr);
    if(flags&1u)(void)application_release_0059f050(self);
    return self;
}
void* __fastcall render_driver_alt_destroy_00556ab0(void* self,void*,std::uint32_t flags){return derived_destroy(self,flags,render_driver_alt_table_005bc3f0);}
void* __fastcall render_driver_main_destroy_00557120(void* self,void*,std::uint32_t flags){return derived_destroy(self,flags,render_driver_main_table_005bc41c);}
void __cdecl render_calibration_release_00536950(){
    void* object=render_calibration_object_0069de44;
    if(object){const std::uint32_t vtable=get(object,0);
        // Original thiscall1 virtual destructor, flags1 and callee RET4.
        __asm {push 1}
        __asm {mov ecx,object}
        __asm {mov eax,vtable}
        __asm {call dword ptr [eax]}
    }
}
}
