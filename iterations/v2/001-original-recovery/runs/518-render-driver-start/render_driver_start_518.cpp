// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 556b10/157B,557180/157B,540440/62B,5405f0/99B. No new original storage.
#include "render_driver_start_518.hpp"
#include "render_driver_515.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/render_settings.hpp"
#include <cstring>
namespace porsche {
extern std::uint32_t render_display_name_0069ecf8,render_display_selected_0069ed08;
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U get(const void* p,U o){U v;std::memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
void put(void* p,U o,U v){std::memcpy(static_cast<B*>(p)+o,&v,4);}
void* pointer(U v){return reinterpret_cast<void*>(v);}
U word(const void* p){return reinterpret_cast<U>(p);}
void old_child_flags1(void* child){const U table=get(child,0);
    __asm {push 1}
    __asm {mov ecx,child}
    __asm {mov eax,table}
    __asm {call dword ptr [eax]}
}
std::uint8_t start(void* self,U variant){
    const U name=render_display_name_0069ecf8;
    render_driver_name_006a64b4=name;
    put(self,0xc,1);
    const U selected=render_display_selected_0069ed08;
    const U active_name=render_driver_name_006a64b4;
    if(render_driver_initialize_00556bb0(variant,active_name,selected,1)==0)return 0;
    (void)render_resource_bind_driver_00540440(pointer(get(self,0x20)),nullptr,self);
    (void)render_driver_reg_flush_005b2004(0x80000000);
    const void* const descriptor=render_settings_current_device_006bd934();
    put(self,0x10,word(descriptor));put(self,8,get(descriptor,0x40));
    void* allocated=startup_network_allocate_0059ef90(0x38);
    void* buffer=allocated?render_driver_buffer_ctor_00537700(allocated,nullptr):nullptr;
    put(self,4,word(buffer));
    render_driver_calibrate_00536870();
    const U mode=get(self,0xc);
    render_driver_context_mode_00549220(render_driver_context_0069e0d4,nullptr,mode);
    render_driver_apply_states_00538af0(self,nullptr);
    (void)render_driver_context_defaults_005405f0(render_driver_context_0069e0d4,nullptr);
    return 1;
}
}
std::uint8_t __fastcall render_driver_alt_start_00556b10(void* self,void*){return start(self,1);}
std::uint8_t __fastcall render_driver_main_start_00557180(void* self,void*){return start(self,0);}
void* __fastcall render_resource_bind_driver_00540440(void* resource,void*,void* driver){
    void* const old=pointer(get(resource,4));
    put(resource,0,word(driver));
    if(old)old_child_flags1(old);
    void* allocated=startup_network_allocate_0059ef90(0x14);
    void* result=allocated?render_resource_bound_child_ctor_00535b50(allocated,nullptr,pointer(get(resource,0))):nullptr;
    put(resource,4,word(result));return result;
}
std::uint32_t __fastcall render_driver_context_defaults_005405f0(void* context,void*){
    put(context,0x11810,0xffffffff);put(context,0x11828,0xffffffff);put(context,0x11824,0xffffffff);
    (void)render_settings_set_state_006bd97c(0x29,8);
    const U reset=get(context,0x11828);
    put(context,0x11824,8);
    if(reset){(void)render_settings_set_state_006bd97c(0x10029,0);put(context,0x11828,0);}
    const U result=render_settings_set_state_006bd97c(0x2a,0);
    put(context,0x11810,0);return result;
}
}
