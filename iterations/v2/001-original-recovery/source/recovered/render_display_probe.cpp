#include "porsche/render_display.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

namespace {
std::string calls;
std::uint32_t clock_index,member_index;
std::int32_t depth;
std::uint32_t driver_result;
bool full_entry;
alignas(4) std::uint8_t resource[8],driver[0x24];
alignas(4) std::uint8_t surface_memory[0x224],surface_object[0x240],texture[0x100],temporary[0x100],readback[0x4000];
porsche::DisplayModeRecord mode_record{};
void record(const std::string& text){calls+=text+';';}
void put32(void* base,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,4);
}
std::string hex(const void* base,std::size_t size) {
    constexpr char digits[]="0123456789abcdef";std::string out;out.reserve(size*2);
    const auto* bytes=static_cast<const unsigned char*>(base);
    for(std::size_t i=0;i<size;++i){out+=digits[bytes[i]>>4];out+=digits[bytes[i]&15];}
    return out;
}
}
namespace porsche {
RenderDisplay* render_display_00628130;
std::uint32_t render_width_00657a48,render_height_00657a4c;
void __cdecl render_core_first_004b76f0(RenderCore*) {}
void __cdecl render_display_member_00466380(void* member) {
    record(member_index==0?"member14":"member34");
    std::memset(member,member_index==0?0xa1:0xb2,0x20);++member_index;
}
std::uint32_t __cdecl render_clock_00555bc0(){record("clock");return clock_index++?0x456:0x123;}
std::uint32_t __cdecl render_get_desktop_005b2274(){record("desktop");return 0x1111;}
std::uint32_t __cdecl render_get_window_dc_005b226c(std::uint32_t window) {
    record("windowdc|"+std::to_string(window));return 0x2222;
}
std::int32_t __cdecl render_get_device_caps_005b2044(std::uint32_t dc,std::int32_t index) {
    record("caps|"+std::to_string(dc)+"|"+std::to_string(index));return depth;
}
void __cdecl render_release_dc_005b2268(std::uint32_t window,std::uint32_t dc) {
    record("releasedc|"+std::to_string(window)+"|"+std::to_string(dc));
}
void __cdecl render_message_box_005b2270(std::uint32_t,const char* text,const char* title,std::uint32_t flags) {
    record(std::string("message|")+title+"|"+text+"|"+std::to_string(flags));
}
void __cdecl render_format_depth_005a0fbf(char* out,std::int32_t input) {
    record("depthformat|"+std::to_string(input));
    std::strcpy(out,"Please set your display to 256 colors or higher.\n");
}
void __cdecl render_depth_failure_00557370(){record("depthfailure");}
void* __cdecl render_display_allocate_0059ef90(std::uint32_t size) {
    record("alloc|"+std::to_string(size));
    return size==8?resource:size==0x224?surface_memory:driver;
}
void* __cdecl render_display_resource_ctor_00540390(void* memory,std::uint32_t zero) {
    record("resourcector|"+std::to_string(zero));put32(memory,4,0x11223344);return memory;
}
void* __cdecl render_display_driver_ctor_00557100(void* memory,void* res) {
    record("driverctor|0");put32(memory,0,0x5bc41c);
    put32(memory,0x20,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(res)));
    return memory;
}
void* __cdecl render_display_driver_alt_ctor_00556a90(void* memory,void* res) {
    record("driverctor|1");put32(memory,0,0x5bc3f0);
    put32(memory,0x20,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(res)));
    return memory;
}
std::uint8_t __cdecl render_display_driver_start_vslot1(void* drv) {
    record(std::string("driverstart|")+(drv==driver?"1":"0"));
    if(full_entry)put32(drv,0x18,0x03105000);
    return static_cast<std::uint8_t>(driver_result);
}
void __cdecl render_driver_failure_005a246e(std::uint32_t code) {
    record("driverfailure|"+std::to_string(code));
}
void __cdecl render_display_prevideo_0044e2c0(){record("prevideo");}
void __cdecl render_display_video_base_00537600(std::uint32_t a,std::uint32_t b,
    std::uint32_t c,std::uint32_t width,std::uint32_t height,std::uint32_t f) {
    record("videobase|"+std::to_string(a)+"|"+std::to_string(b)+"|"+std::to_string(c)+"|"+
           std::to_string(width)+"|"+std::to_string(height)+"|"+std::to_string(f));
}
std::uint32_t __cdecl render_display_video_mode_005376c0(std::uint32_t width,
    std::uint32_t height,std::uint32_t mode,std::uint32_t two,std::uint32_t one) {
    record("videomode|"+std::to_string(width)+"|"+std::to_string(height)+"|"+
           std::to_string(mode)+"|"+std::to_string(two)+"|"+std::to_string(one));
    return 0x43;
}
void __cdecl render_display_video_result_00468030(RenderDisplay*,std::uint32_t result) {
    record("videoresult|"+std::to_string(result));
}
void __cdecl render_display_texture_reset_0053c3d0(){record("texture-reset");}
int __cdecl render_display_texture_reserve_00553fc0(std::uint32_t bytes) {
    record("reserve|"+std::to_string(bytes));return 0;
}
void __cdecl render_display_texture_report_005a177b(const char* format,std::uint32_t bytes) {
    record(std::string("texture-report|")+format+"|"+std::to_string(bytes));
}
void* __cdecl render_display_surface_ctor_00538d10(void*,std::uint32_t field) {
    (void)field;record("surface-ctor");return surface_object;
}
void __cdecl render_display_surface_init_00538da0(void*,float width,float height,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t) {
    (void)width;(void)height;record("surface-init");
}
void __cdecl render_display_surface_config_005392d0(void*,std::uint32_t a,std::uint32_t b,std::uint32_t c) {
    (void)a;(void)b;(void)c;record("surface-config");
}
void* __cdecl render_display_surface_transform_00539f40(void*,std::uint32_t a,std::uint32_t b,std::uint32_t c) {
    (void)a;(void)b;(void)c;record("surface-transform");return surface_object;
}
void __cdecl render_display_transform_init_00539b80(void*){record("transform-init");}
void __cdecl render_display_transform_compose_00539b30(void*,void*,std::uint32_t a,std::uint32_t b) {
    (void)a;(void)b;record("transform-compose");
}
void __cdecl render_display_transform_attach_00539b00(void*,void*){record("transform-attach");}
void __cdecl render_display_local_transform_00466e80(void*,std::uint32_t zero) {record("local-transform|"+std::to_string(zero));}
std::uint32_t __cdecl render_display_getstate_006bd984(std::uint32_t key) {
    record("getstate|"+std::to_string(key));
    if(key==2)return 0x102; if(key==7)return 0x107; if(key==10)return 0x10a;
    if(key==3)return 0x103; mode_record={0,0,render_display_selected_0069ed08};
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&mode_record));
}
void __cdecl render_display_setstate_006bd97c(std::uint32_t key,std::uint32_t value) {
    record("setstate|"+std::to_string(key)+"|"+std::to_string(value));
}
void __cdecl render_display_thr_cleanup_00555390(){record("thr-cleanup");}
void __cdecl render_display_window_006bd9b0(std::uint32_t mode){record("window|"+std::to_string(mode));}
void __cdecl render_display_set_texture_006bd954(std::uint32_t value){record("set-texture|"+std::to_string(value));}
void __cdecl render_display_clear_window_006bd91c(){record("clear-window");}
void* __cdecl render_display_texture_create_00535950(std::uint32_t w,std::uint32_t h,std::uint32_t bits,std::uint32_t flags) {
    record("texture-create|"+std::to_string(w)+"|"+std::to_string(h)+"|"+
           std::to_string(bits)+"|"+std::to_string(flags));return texture;
}
void __cdecl render_display_texture_bind_00534480(void*){record("texture-bind");}
void __cdecl render_display_fill_00537e00(std::uint32_t color){record("fill|"+std::to_string(color));}
void __cdecl render_display_select_buffer_00556910(std::uint32_t i,std::uint32_t z,std::uint32_t one) {
    record("select-buffer|"+std::to_string(i)+"|"+std::to_string(z)+"|"+std::to_string(one));
}
void* __cdecl render_display_texture_alloc_00554960(std::uint32_t w,std::uint32_t h,std::uint32_t f,
    std::uint32_t a,std::uint32_t b,const char* name) {
    record(std::string("texture-alloc|")+std::to_string(w)+"|"+std::to_string(h)+"|"+
           std::to_string(f)+"|"+std::to_string(a)+"|"+std::to_string(b)+"|"+name);return temporary;
}
void __cdecl render_display_texture_update_005550e0(){record("texture-update");}
void __cdecl render_display_texture_copy_00554d70(void*,void*,std::uint32_t z){record("texture-copy|"+std::to_string(z));}
void __cdecl render_display_texture_release_00555440(void*){record("texture-release");}
void __cdecl render_display_draw_quad_006bd9a8(const void*,const void*,const void*,const void*){record("draw-quad");}
void __cdecl render_display_flush_006bd970(){record("flush");}
void __cdecl render_display_sync_006bd978(std::uint32_t zero){record("sync|"+std::to_string(zero));}
void* __cdecl render_display_buffer_alloc_00531ca0(const char*,std::uint32_t bytes,std::uint32_t zero) {
    record("readback-alloc|"+std::to_string(bytes)+"|"+std::to_string(zero));return readback;
}
void __cdecl render_display_read_rect_006bd96c(std::uint32_t x,std::uint32_t y,std::uint32_t w,
    std::uint32_t h,void*){record("readrect|"+std::to_string(x)+"|"+std::to_string(y)+"|"+
    std::to_string(w)+"|"+std::to_string(h));}
bool __cdecl render_display_compare_pixel_00468110(std::uint32_t pixel,std::uint32_t format) {
    return pixel==format;
}
void __cdecl render_display_release_texture_00533f80(void*){record("texture-free");}
std::uint32_t __cdecl render_display_present_0044e870(std::uint32_t ok){record("present|"+std::to_string(ok));return 0x44556677;}
std::uint32_t __cdecl render_display_driver_present_vslot0(void*,std::uint32_t ok) {
    record("driver-present|"+std::to_string(ok));return 0x44556677;
}
void __cdecl render_display_finish_driver_00537850(void*,std::uint32_t one){record("driver-finish|"+std::to_string(one));}
void __cdecl render_display_finish_init_004b0eb0(){record("finish-init");}
}
int main() {
    using namespace porsche;
    std::uint32_t seed,flags,actual_w,actual_h,actual_m,request_w,request_h,request_m,selected;
    while(std::cin>>seed>>flags>>depth>>driver_result>>actual_w>>actual_h>>actual_m>>
                   request_w>>request_h>>request_m>>selected>>full_entry) {
        RenderDisplay display{};std::memset(display.bytes,static_cast<int>(seed&255),sizeof(display.bytes));
        std::memset(resource,static_cast<int>(seed&255),sizeof(resource));
        std::memset(driver,static_cast<int>(seed&255),sizeof(driver));
        std::memset(surface_memory,static_cast<int>(seed&255),sizeof(surface_memory));
        std::memset(surface_object,static_cast<int>(seed&255),sizeof(surface_object));
        std::memset(texture,static_cast<int>(seed&255),sizeof(texture));
        std::memset(temporary,static_cast<int>(seed&255),sizeof(temporary));
        std::memset(readback,0,sizeof(readback));
        mode_record={0,0,selected};
        clock_index=0;member_index=0;calls.clear();
        render_display_00628130=nullptr;render_display_clock_005deb1c=0xabcdef01;
        render_display_name_0069ecf8=0x5555;
        render_display_callback1_0069ecfc=0x6666;render_display_callback2_0069ed00=0x7777;
        render_display_selected_0069ed08=0x8888;
        render_display_texture_width_005deac8=0;render_display_texture_height_005deacc=0;
        render_display_actual_width_00619784=actual_w;render_display_actual_height_00619788=actual_h;
        render_display_actual_mode_0061978c=actual_m;
        render_display_requested_width_00657a48=request_w;
        render_display_requested_height_00657a4c=request_h;
        render_display_requested_mode_00657a50=request_m;
        if(full_entry)render_construct_display_004677e0(&display,"dx7",selected,flags,"800x600");
        else render_display_through_004679c7(&display,"dx7",selected,flags,"800x600");
        put32(display.bytes,0x54,0x03101014);
        put32(display.bytes,0x6c,0x03102000);
        put32(display.bytes,0x70,0x03103000);
        if(full_entry)put32(display.bytes,0x7c,0x03402000);
        put32(driver,0x20,0x03102000);
        std::cout<<"{\"display\":\""<<hex(display.bytes,sizeof(display.bytes))
                 <<"\",\"resource\":\""<<hex(resource,sizeof(resource))
                 <<"\",\"driver\":\""<<hex(driver,sizeof(driver))
                 <<"\",\"global_display\":"<<(render_display_00628130==&display)
                 <<",\"clock_global\":"<<render_display_clock_005deb1c
                 <<",\"name_global\":"<<(render_display_name_0069ecf8==0x5555?0x5555:0x03200000)
                 <<",\"callback1\":"<<render_display_callback1_0069ecfc
                 <<",\"callback2\":"<<render_display_callback2_0069ed00
                 <<",\"selected\":"<<render_display_selected_0069ed08
                 <<",\"texture_width\":"<<render_display_texture_width_005deac8
                 <<",\"texture_height\":"<<render_display_texture_height_005deacc
                 <<",\"calls\":\""<<hex(calls.data(),calls.size())<<"\"}\n";
    }
}
