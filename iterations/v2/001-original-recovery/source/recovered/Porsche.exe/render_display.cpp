#include "porsche/render_display.hpp"
#include <cstdint>
#include <cstring>

namespace porsche {
std::uint32_t render_display_clock_005deb1c;
std::uint32_t render_display_name_0069ecf8;
std::uint32_t render_display_callback1_0069ecfc,render_display_callback2_0069ed00;
std::uint32_t render_display_selected_0069ed08;
std::uint32_t render_display_actual_width_00619784,render_display_actual_height_00619788;
std::uint32_t render_display_actual_mode_0061978c;
std::uint32_t& render_display_requested_width_00657a48=render_width_00657a48;
std::uint32_t& render_display_requested_height_00657a4c=render_height_00657a4c;
std::uint32_t render_display_requested_mode_00657a50;
std::uint32_t render_display_texture_width_005deac8,render_display_texture_height_005deacc;

RenderDisplay* __cdecl render_display_through_004679c7(RenderDisplay* object,
    const char* name,std::uint32_t selected,std::uint32_t flags,const char*) {
    auto* bytes=object->bytes;
    // 0x4677e0..0x467849: exact prefix already independently captured by Run026.
    render_display_prefix_004677e0(object,name,selected,flags,nullptr);

    // 0x46784f..0x46786d: desktop depth check, including the original failure branch.
    const auto desktop=render_get_desktop_005b2274();
    const auto dc=render_get_window_dc_005b226c(desktop);
    const auto depth=render_get_device_caps_005b2044(dc,12);
    render_release_dc_005b2268(desktop,dc);
    if(depth<8) {
        char text[128];
        render_format_depth_005a0fbf(text,depth);
        render_message_box_005b2270(0,text,"Invalid screen depth",0x51030);
        render_depth_failure_00557370();
    }

    // 0x4678ae..0x4678dd: exact callback globals and allocator order.
    render_display_name_0069ecf8=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(name));
    render_display_callback1_0069ecfc=0x004672c0;
    render_display_callback2_0069ed00=0x004672e0;
    render_display_selected_0069ed08=selected;
    auto* resource=render_display_allocate_0059ef90(8);
    if(resource) render_display_resource_ctor_00540390(resource,0);
    const auto resource_word=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(resource));
    std::memcpy(bytes+0x6c,&resource_word,4);

    // 0x4678f8..0x467935: the low byte set in the prefix selects one of the
    // two measured driver constructors. Their callees and vtables stay typed.
    auto* driver_memory=render_display_allocate_0059ef90(0x24);
    auto* driver=bytes[0x60]
        ? (driver_memory?render_display_driver_alt_ctor_00556a90(driver_memory,resource):nullptr)
        : (driver_memory?render_display_driver_ctor_00557100(driver_memory,resource):nullptr);
    const auto driver_word=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(driver));
    std::memcpy(bytes+0x70,&driver_word,4);
    const auto started=render_display_driver_start_vslot1(driver);
    if(!started) {
        render_message_box_005b2270(0,"3D graphics hardware could not be initialized.","Error:",0);
        render_driver_failure_005a246e(1);
    }

    // 0x467958..0x4679cc: query actual display values and apply original
    // windowed/fullscreen branch. The final call is the exclusive proof boundary.
    render_display_prevideo_0044e2c0();
    render_display_video_base_00537600(0,0,0,render_display_actual_width_00619784,
        render_display_actual_height_00619788,0);
    auto width=render_display_requested_width_00657a48;
    auto height=render_display_requested_height_00657a4c;
    const auto mode=render_display_requested_mode_00657a50;
    if(width!=render_display_actual_width_00619784 ||
       height!=render_display_actual_height_00619788 ||
       mode!=render_display_actual_mode_0061978c) {
        if(width==0) {
            width=render_display_actual_width_00619784;
            height=render_display_actual_height_00619788;
        }
        std::uint32_t result=0;
        if(!bytes[0x60])
            result=render_display_video_mode_005376c0(width,height,mode,2,1);
        render_display_video_result_00468030(object,result);
    }
    return object;
}

namespace {
std::uint32_t read32(const void* pointer,std::size_t offset) {
    std::uint32_t value;std::memcpy(&value,static_cast<const std::uint8_t*>(pointer)+offset,4);return value;
}
}

RenderDisplay* __cdecl render_construct_display_004677e0(void* raw,const char* name,
    std::uint32_t selected,std::uint32_t flags,const char* resolution) {
    auto* self=static_cast<std::uint8_t*>(raw);
    auto* display=render_display_through_004679c7(static_cast<RenderDisplay*>(raw),name,selected,flags,resolution);

    // 0x4679cc..0x467a3a: bind the driver's surface, reset THRASH resources,
    // report the exact 24 MiB allocation result, and create the display surface.
    auto* driver=reinterpret_cast<void*>(static_cast<std::uintptr_t>(read32(self,0x70)));
    auto* resource=reinterpret_cast<void*>(static_cast<std::uintptr_t>(read32(self,0x6c)));
    const auto surface_word=read32(resource,4);
    std::memcpy(self+0x74,&surface_word,4);
    render_display_texture_reset_0053c3d0();
    const auto reserved=render_display_texture_reserve_00553fc0(0x01800000);
    render_display_texture_report_005a177b(reserved
        ? "Increased texture allocation passed [%d]\n"
        : "Increased texture allocation FAILED [%d]\n",0x01800000);
    render_display_texture_width_005deac8=render_display_actual_width_00619784;
    render_display_texture_height_005deacc=render_display_actual_height_00619788;
    auto* surface_memory=render_display_allocate_0059ef90(0x224);
    const auto driver_word=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(driver));
    auto* surface=surface_memory
        ? render_display_surface_ctor_00538d10(surface_memory,driver_word):nullptr;
    const auto surface_address=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(surface));
    std::memcpy(self+0x7c,&surface_address,4);
    render_display_surface_init_00538da0(surface,
        static_cast<float>(render_display_texture_width_005deac8),
        static_cast<float>(render_display_texture_height_005deacc),0,0,0x3f800000,0x40800000);
    render_display_surface_config_005392d0(surface,0x3f800000,0,0x41200000);
    auto* transform=render_display_surface_transform_00539f40(surface,0xbf800000,0x3f800000,0xbdcccccd);
    render_display_transform_init_00539b80(transform);
    std::uint32_t matrix[16]{};
    render_display_transform_compose_00539b30(matrix,transform,
        0x3f800000,0xbf800000);
    render_display_surface_transform_00539f40(surface,0,0,0);
    render_display_transform_attach_00539b00(surface,transform);
    render_display_local_transform_00466e80(static_cast<void*>(surface?static_cast<std::uint8_t*>(surface)+0xb8:nullptr),0);

    // Four 8-word vertices are initialized exactly as the local constants at
    // 0x467b0c..0x467bd9; the descriptor format comes from getstate(0x1d).
    const std::uint32_t vertices[32]={
        0,0x3f7fff00,0x37800080,0xffffffff,0,0,0,0x43000000,
        0,0x3f7fff00,0x37800080,0xffffffff,0,0x3f800000,0,0x43000000,
        0x43000000,0x3f7fff00,0x37800080,0xffffffff,0,0x3f800000,0x3f800000,0,
        0x43000000,0x3f7fff00,0x37800080,0xffffffff,0,0,0x3f800000,0
    };

    const auto saved2=render_display_getstate_006bd984(2);
    const auto saved7=render_display_getstate_006bd984(7);
    const auto saved10=render_display_getstate_006bd984(10);
    const auto saved3=render_display_getstate_006bd984(3);
    render_display_thr_cleanup_00555390();
    render_display_setstate_006bd97c(2,0);
    render_display_setstate_006bd97c(7,0);
    render_display_setstate_006bd97c(10,2);
    const auto mode_address=render_display_getstate_006bd984(0x1d);
    auto* mode=reinterpret_cast<const std::uint8_t*>(static_cast<std::uintptr_t>(mode_address));
    render_display_window_006bd9b0(2);
    render_display_setstate_006bd97c(3,0xff000000);
    render_display_set_texture_006bd954(0);
    render_display_clear_window_006bd91c();
    auto* texture=render_display_texture_create_00535950(8,8,16,0);
    render_display_texture_bind_00534480(texture);
    render_display_fill_00537e00(0xff000000);
    for(std::uint32_t i=0;i<4;++i)render_display_select_buffer_00556910(i,0,1);
    auto* temporary=render_display_texture_alloc_00554960(8,8,4,0,0,"UV Test");
    render_display_texture_update_005550e0();
    render_display_texture_copy_00554d70(temporary,
        static_cast<std::uint8_t*>(texture)+0x38,0);
    render_display_texture_release_00555440(temporary);
    render_display_draw_quad_006bd9a8(vertices,vertices+8,vertices+16,vertices+24);
    render_display_flush_006bd970();
    render_display_sync_006bd978(0);
    render_display_window_006bd9b0(2);

    const auto format=read32(mode,8);
    std::uint32_t width=2;
    if(format==5)width=3;else if(format==6)width=4;
    else if(format==3||format==4||format==7)width=2;
    std::uint32_t bits=16;
    if(format==1)bits=4;else if(format==2||format==8)bits=8;
    else if(format==5)bits=24;else if(format==6)bits=32;
    const auto bytes=width*0x8c;
    auto* readback=render_display_buffer_alloc_00531ca0("%s",bytes,0);
    render_display_read_rect_006bd96c(0,0,0x80,1,readback);
    const auto decoder=(bits==4)?0u:2u; // byte table at 0x467f14: 0,2,2,...
    const std::uint32_t step=width;
    std::uint32_t matches=0,mismatches=0;
    for(std::uint32_t i=0;i<0x80;++i) {
        const auto* p=static_cast<const std::uint8_t*>(readback)+i*step;
        std::uint32_t pixel=0;
        if(decoder==0)pixel=p[0];
        else if(decoder==1)std::memcpy(&pixel,p,4);
        else {std::uint16_t word;std::memcpy(&word,p,2);pixel=word;}
        if(render_display_compare_pixel_00468110(pixel,format))++matches;else ++mismatches;
    }
    const std::uint32_t read_ok=static_cast<std::uint32_t>(matches==mismatches);
    render_display_thr_cleanup_00555390();
    render_display_release_texture_00533f80(texture);
    render_display_setstate_006bd97c(2,saved2);
    render_display_setstate_006bd97c(7,saved7);
    render_display_setstate_006bd97c(10,saved10);
    render_display_setstate_006bd97c(3,saved3);
    const auto present=render_display_driver_present_vslot0(driver,read_ok);
    render_display_present_0044e870(present);
    render_display_finish_driver_00537850(static_cast<std::uint8_t*>(driver)+4,1);
    render_display_setstate_006bd97c(7,1);
    if(!self[0x60])render_display_finish_init_004b0eb0();
    return display;
}
}
