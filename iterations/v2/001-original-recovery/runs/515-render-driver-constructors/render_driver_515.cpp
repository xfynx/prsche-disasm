// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Twelve complete bodies299B;4B writablecontext and136B readonly native table views.
#include "render_driver_515.hpp"
#include "render_surface_init_511.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/network_vtables.hpp"
#include "porsche/render_loader.hpp"
#include <cstring>
namespace porsche {
extern std::uint32_t render_display_texture_width_005deac8,render_display_texture_height_005deacc;
void* render_driver_context_0069e0d4=nullptr;
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U get(const void* p,U o){U v;std::memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
void put(void* p,U o,U v){std::memcpy(static_cast<B*>(p)+o,&v,4);}
U pointer(const void* p){return reinterpret_cast<U>(p);}
U call0(U index){return reinterpret_cast<U(__stdcall*)()>(render_thrash_exports_006bd910[index])();}
U call1(U index,U a){return reinterpret_cast<U(__stdcall*)(U)>(render_thrash_exports_006bd910[index])(a);}
U call2(U index,U a,U b){return reinterpret_cast<U(__stdcall*)(U,U)>(render_thrash_exports_006bd910[index])(a,b);}
U call4(U index,U a,U b,U c,U d){return reinterpret_cast<U(__stdcall*)(U,U,U,U)>(render_thrash_exports_006bd910[index])(a,b,c,d);}
}
// Exactly11/11/11/1 original slots, with actual native executable providers.
// There is no invented C++ class/RTTI prefix or original VA used as a host pointer.
#define SLOT515(function) reinterpret_cast<std::uint32_t>(&function)
const U render_driver_base_table_005bb860[11]={
    SLOT515(render_driver_base_destroy_00538ab0),SLOT515(render_driver_base_start_0050dd60),
    SLOT515(render_driver_context_from_field1c_00538c80),SLOT515(network_purecall_005a1056),
    SLOT515(network_purecall_005a1056),SLOT515(render_driver_flush_00538cc0),
    SLOT515(network_purecall_005a1056),SLOT515(render_driver_select_mode_00538b30),
    SLOT515(render_driver_selected_00538c90),SLOT515(render_driver_cap3c_00538cb0),SLOT515(render_driver_cap44_00538ca0)};
const U render_driver_alt_table_005bc3f0[11]={
    SLOT515(render_driver_alt_destroy_00556ab0),SLOT515(render_driver_alt_start_00556b10),
    SLOT515(render_driver_window_00557220),SLOT515(render_driver_pageflip_00557230),
    SLOT515(render_driver_clip_00556cd0),SLOT515(render_driver_flush_00538cc0),
    SLOT515(render_surface_bounds_00556d00),SLOT515(render_driver_select_mode_00538b30),
    SLOT515(render_driver_selected_00538c90),SLOT515(render_driver_cap3c_00538cb0),SLOT515(render_driver_cap44_00538ca0)};
const U render_driver_main_table_005bc41c[11]={
    SLOT515(render_driver_main_destroy_00557120),SLOT515(render_driver_main_start_00557180),
    SLOT515(render_driver_window_00557220),SLOT515(render_driver_pageflip_00557230),
    SLOT515(render_driver_clip_00556cd0),SLOT515(render_driver_flush_00538cc0),
    SLOT515(render_surface_bounds_00556d00),SLOT515(render_driver_select_mode_00538b30),
    SLOT515(render_driver_selected_00538c90),SLOT515(render_driver_cap3c_00538cb0),SLOT515(render_driver_cap44_00538ca0)};
const U render_driver_helper_table_005bb85c[1]={SLOT515(render_driver_probe_00556d20)};
#undef SLOT515
static_assert(sizeof(render_driver_base_table_005bb860)+sizeof(render_driver_alt_table_005bc3f0)+sizeof(render_driver_main_table_005bc41c)+sizeof(render_driver_helper_table_005bb85c)==136,"original x86 table extents");
void* __cdecl render_driver_base_ctor_00538a30(void* object,void*){
    put(object,0x14,0);put(object,0,pointer(render_driver_base_table_005bb860));
    void* context=startup_network_allocate_0059ef90(0x1182c);
    if(context){put(context,0x117e0,0);put(context,0x117e4,0);put(context,0x117e8,0x3f800000);put(context,0x1180c,0);put(context,0x11810,0);}
    render_driver_context_0069e0d4=context;
    void* helper=startup_network_allocate_0059ef90(4);
    if(helper)put(helper,0,pointer(render_driver_helper_table_005bb85c));
    put(object,0x18,pointer(helper));return object;
}
void* __cdecl render_display_driver_alt_ctor_00556a90(void* object,void* resource){
    render_driver_base_ctor_00538a30(object,resource);
    put(object,0x20,pointer(resource));put(object,0,pointer(render_driver_alt_table_005bc3f0));return object;
}
void* __cdecl render_display_driver_ctor_00557100(void* object,void* resource){
    render_driver_base_ctor_00538a30(object,resource);
    put(object,0x20,pointer(resource));put(object,0,pointer(render_driver_main_table_005bc41c));return object;
}
std::uint8_t __fastcall render_driver_base_start_0050dd60(void*,void*){return 0;}
U __fastcall render_driver_context_from_field1c_00538c80(void* self,void*){const U context=get(self,0x1c);render_driver_context_0069e0d4=reinterpret_cast<void*>(context);return context;}
U __fastcall render_driver_selected_00538c90(void* self,void*){return get(self,0xc);}
U __fastcall render_driver_cap44_00538ca0(void* self,void*){return get(reinterpret_cast<void*>(get(self,0x10)),0x44);}
U __fastcall render_driver_cap3c_00538cb0(void* self,void*){return get(reinterpret_cast<void*>(get(self,0x10)),0x3c);}
U __fastcall render_driver_flush_00538cc0(void*,void*){(void)call0(24);(void)call1(40,3);(void)call0(3);return call1(40,2);}
U __fastcall render_driver_window_00557220(void*,void*){return call1(40,2);}
U __fastcall render_driver_pageflip_00557230(void*,void*){return call0(14);}
U __fastcall render_driver_clip_00556cd0(void* self,void*){
    const U selected=get(reinterpret_cast<void*>(get(self,4)),0);
    (void)call2(27,3,selected);
    const U height=render_display_texture_height_005deacc,width=render_display_texture_width_005deac8;
    (void)call4(41,0,0,width,height);return call0(3);
}
std::uint8_t __cdecl render_display_driver_start_vslot1(void* driver){U table=get(driver,0),result;
    __asm {mov ecx,driver}
    __asm {mov eax,table}
    __asm {call dword ptr [eax+4]}
    __asm {mov result,eax}
    return static_cast<std::uint8_t>(result);
}
U __cdecl render_display_driver_present_vslot0(void* driver,U){
    void* const helper=reinterpret_cast<void*>(get(driver,0x18));U table=get(helper,0),result;
    __asm {mov ecx,helper}
    __asm {mov eax,table}
    __asm {call dword ptr [eax]}
    __asm {mov result,eax}
    return result; // The outer caller retains/forwards readOK independently.
}
void __cdecl render_window_driver_select_mode_vslot7(void* driver,U index){U table=get(driver,0);
    __asm {push index}
    __asm {mov ecx,driver}
    __asm {mov eax,table}
    __asm {call dword ptr [eax+1ch]}
}
void __cdecl render_mode_driver_prepare_vslot9(void* driver){U table=get(driver,0);
    __asm {mov ecx,driver}
    __asm {mov eax,table}
    __asm {call dword ptr [eax+24h]}
}
}
