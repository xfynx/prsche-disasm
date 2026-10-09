#include "porsche/splash_progress.hpp"

#include "porsche/application_state.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/render_display.hpp"
#include "porsche/startup_services.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

std::uint32_t splash_progress_texture_00655a24=0;
std::uint8_t splash_progress_enabled_00655a28=0;
// 005dead0 is a raw-backed .data DWORD in the indexed Porsche.exe. Its
// original value is zero (inspect-pe-range.py, VA 005dead0, size 4).
std::uint32_t splash_progress_format_005dead0=0;
// 0065b350 is a pointer cell in the virtual BSS tail; its initial DWORD is zero. The
// alternate-root producer is outside this consumer; preserve nullptr here.
const char* splash_progress_alternate_base_0065b350=nullptr;

namespace {
std::uint32_t arena_word(std::uint32_t va) {
    return application_state_006573e8.word(va);
}
std::int32_t arena_i32(std::uint32_t va) {
    return static_cast<std::int32_t>(arena_word(va));
}
std::uint8_t arena_byte(std::uint32_t va) {
    return application_state_006573e8.byte(va);
}
std::uint32_t read_u32(const void* base,std::size_t offset) {
    std::uint32_t value{};
    std::memcpy(&value,static_cast<const std::uint8_t*>(base)+offset,sizeof(value));
    return value;
}
std::int16_t read_i16(const void* base,std::size_t offset) {
    std::int16_t value{};
    std::memcpy(&value,static_cast<const std::uint8_t*>(base)+offset,sizeof(value));
    return value;
}
void* relative_item(void* base,std::size_t field) {
    const auto delta=read_u32(base,field);
    return static_cast<void*>(static_cast<std::uint8_t*>(base)+delta);
}
std::int32_t trunc_ftol(double value) {
    // Porsche.exe's 005a0f98 saves the x87 control word, sets RC=chop,
    // executes FISTP qword, restores the control word, and returns the low
    // DWORD. All values reaching this consumer fit the signed 32-bit range.
    return static_cast<std::int32_t>(value);
}
bool network_renderable(const std::uint8_t* config) {
    return config!=nullptr && read_u32(config,8)!=0 && config[0xbf]==0 &&
        config[0xbe]!=0 && static_cast<std::int32_t>(read_u32(config,0xdc))>=0;
}
void draw_strip(void* resource,std::uint32_t first_field,std::uint32_t step,
                std::int32_t y,std::int32_t tile_size) {
    for(std::uint32_t x=0;x<0x280;x+=step) {
        const auto field=static_cast<std::size_t>(first_field)+(x/step)*8u;
        auto* item=static_cast<std::uint8_t*>(resource)+read_u32(resource,field);
        splash_progress_draw_tile_00563440(item,static_cast<std::int32_t>(x),y,
            static_cast<std::int32_t>(tile_size),static_cast<std::int32_t>(tile_size));
    }
}
}

void __cdecl splash_progress_004a4a70(std::int32_t phase) {
    if(phase==0) {
        splash_progress_enabled_00655a28=1;
    } else if(phase==10) {
        splash_progress_enabled_00655a28=0;
        return;
    } else if(splash_progress_enabled_00655a28==0) {
        return;
    }

    if(splash_progress_texture_00655a24==0) {
        splash_progress_texture_00655a24=splash_progress_create_texture_00535950(
            0x280,0x1e0,splash_progress_format_005dead0,0x10);
    }

    auto* const config=static_cast<std::uint8_t*>(startup_network_00628c70);
    if(network_renderable(config) && phase>0 && splash_progress_enabled_00655a28!=0) {
        std::uint32_t local_records[24]{};
        void* cursor=local_records;
        splash_progress_dispatch_004edc00(0x256,&cursor,arena_word(0x0065741c),phase);
        static_cast<std::uint32_t*>(cursor)[0]=0;
        if(cursor!=local_records) splash_progress_release_stack_0048d550(local_records);
    }

    if(arena_word(0x00657440)==1) return;

    auto begin=splash_progress_resource_begin_004ad670();
    auto end_count=splash_progress_resource_end_004ad6c0();
    while(end_count<begin) {
        splash_progress_pump_005366e0(0);
        begin=splash_progress_resource_begin_004ad670();
        end_count=splash_progress_resource_end_004ad6c0();
    }
    (void)splash_progress_bind_texture_00534480(splash_progress_texture_00655a24);

    const auto game_type=arena_i32(0x006573e8);
    if(phase==0 || (phase==5 && game_type!=9)) {
        void* alternate_resource=nullptr;
        if(phase==5) {
            char alternate_path[96]{};
            splash_progress_format_005a0fbf(alternate_path,"%s%s.fsh",
                splash_progress_alternate_base_0065b350,
                application_state_006573e8.characters(0x00657444));
            if(splash_progress_file_exists_0059dc30(alternate_path)!=0)
                alternate_resource=splash_progress_load_resource_0059d8e0(alternate_path,0);
        }

        std::uint32_t variant=0;
        if(game_type==4) {
            const auto mode=splash_progress_render_format_005032d0();
            if(mode==0x209) variant=1;
            else if(mode==0x20a) variant=2;
            else if(mode==0x20b) variant=3;
        }
        char background_path[100]{};
        const char* background_format=phase==0?"%sera%d.fsh":"%sera%dtr.fsh";
        splash_progress_format_005a0fbf(background_path,background_format,
            game_setup_load_base_0065b334,static_cast<std::int32_t>(variant));
        auto* background=splash_progress_load_resource_0059d8e0(background_path,0);

        draw_strip(background,0x14,0x20,0,0x20);
        draw_strip(background,0xb4,0x40,0x20,0x40);
        draw_strip(background,0x104,0x80,0x60,0x80);
        draw_strip(background,0x12c,0x80,0xe0,0x80);
        draw_strip(background,0x154,0x80,0x160,0x80);

        if(phase==5 && alternate_resource!=nullptr) {
            auto* item0=relative_item(alternate_resource,0x14);
            if(arena_word(0x0065742c)==1) splash_progress_update_sprite_00563320(item0);
            const auto width0=read_i16(item0,8),height0=read_i16(item0,10);
            splash_progress_draw_sprite_00563160(item0,
                width0<0?-width0:width0,height0<0?-height0:height0,
                read_i16(item0,4),read_i16(item0,6));
            if(arena_word(0x0065742c)==1) splash_progress_update_sprite_00563320(item0);

            auto* item1=relative_item(alternate_resource,0x1c);
            const auto width1=read_i16(item1,8),height1=read_i16(item1,10);
            splash_progress_draw_sprite_00563160(item1,
                width1<0?-width1:width1,height1<0?-height1:height1,
                read_i16(item1,4),read_i16(item1,6));

            const auto third_offset=arena_word(0x00657430)==1?0x2c:0x24;
            auto* item2=relative_item(alternate_resource,third_offset);
            if(item2!=nullptr) {
                if(arena_word(0x0065742c)==1) splash_progress_update_sprite_00563320(item2);
                const auto width2=read_i16(item2,8),height2=read_i16(item2,10);
                std::int32_t adjusted_width=width2<0?-width2:width2;
                const auto previous_width=read_i16(item1,8);
                const auto previous_abs_width=previous_width<0?-previous_width:previous_width;
                if(arena_word(0x0065742c)==1)
                    adjusted_width=read_i16(item1,4)-adjusted_width+2*previous_abs_width;
                splash_progress_draw_sprite_00563160(item2,
                    adjusted_width,height2<0?-height2:height2,
                    read_i16(item2,4),read_i16(item2,6));
            }
        }
        splash_progress_free_00531f90(background);
        if(alternate_resource!=nullptr) splash_progress_free_00531f90(alternate_resource);
    }

    if(network_renderable(config) && (phase==0 || phase==5)) {
        const auto segment=phase>4?0x2cu:0x14u;
        char loading_path[100]{};
        splash_progress_format_005a0fbf(loading_path,"%sMLoading.fsh",
            game_setup_load_base_0065b334);
        auto* loading=splash_progress_load_resource_0059d8e0(loading_path,0);
        for(std::uint32_t j=0;j<3;++j) {
            auto* item=static_cast<std::uint8_t*>(loading)+
                read_u32(loading,segment+j*8u);
            const std::int32_t x=static_cast<std::int32_t>(j*0x100u);
            splash_progress_draw_tile_00563440(item,x,0x142,
                j<2?0x100:0x80,0x9e);
        }
        if(loading!=nullptr) splash_progress_free_00531f90(loading);
    }

    if((phase==0 || phase==5) && arena_word(0x00657c84)!=0) {
        char text_path[100]{};
        splash_progress_format_005a0fbf(text_path,"%sloadtext.fsh",
            game_setup_load_base_0065b334);
        auto* text_resource=splash_progress_file_exists_0059dc30(text_path)!=0?
            splash_progress_load_resource_0059d8e0(text_path,0):nullptr;
        if(arena_word(0x00657c84)!=0) {
            const auto index=arena_word(0x00657c84);
            auto* item=static_cast<std::uint8_t*>(text_resource)+
                read_u32(text_resource,0x0c+index*8u);
            const auto y=-static_cast<std::int32_t>(read_i16(item,10));
            const auto x=-static_cast<std::int32_t>(read_i16(item,8));
            splash_progress_draw_overlay_00562810(item,x,y,
                read_i16(item,4),read_i16(item,6));
        }
        if(text_resource!=nullptr) splash_progress_free_00531f90(text_resource);
    }

    if(phase>=0) {
        const double phase_offset=static_cast<double>(phase)*
            static_cast<double>(12.4f);
        const auto text_x=trunc_ftol(phase_offset);
        splash_progress_draw_text_00562680(0x12e,0x1d3,
            static_cast<std::uint16_t>(text_x),6,0xffffbb00u);
    }

    if(network_renderable(config) && splash_progress_enabled_00655a28!=0) {
        auto** context_slot=reinterpret_cast<void**>(config+0x10);
        if(*context_slot!=nullptr) {
            const auto lock=read_u32(*context_slot,0);
            splash_progress_enter_lock_005322b0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
        }
        const auto count=arena_i32(0x00658084);
        for(std::int32_t index=0;index<count;++index) {
            const auto record_va=0x00658608u+static_cast<std::uint32_t>(index)*0x580u;
            const auto record_offset=static_cast<std::size_t>(record_va-application_state_base_va);
            const auto* record=application_state_006573e8.bytes()+record_offset;
            const auto label=read_u32(record-0x408,0);
            const auto player_word=static_cast<std::uint32_t>(
                splash_progress_find_item_0048d720(index));
            auto* player=player_word==0?nullptr:
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(player_word));
            if(player==nullptr || splash_progress_item_visible_00490390(player)==0) {
                const auto x=static_cast<std::int32_t>(label*0x4au+0x20u);
                const auto y=trunc_ftol(0x16c*0x1.0p-16f*0x1.0p+16f);
                splash_progress_draw_text_00562680(x,y,0x36,0x40,0);
            } else {
                auto* selected=splash_progress_item_data_004903f0(player,0);
                std::uint32_t item_address=0;
                if(selected!=nullptr) {
                    const auto end=read_u32(selected,0x0c);
                    const auto capacity=read_u32(selected,8);
                    const auto first=read_u32(selected,4);
                    if(end>=capacity) item_address=first;
                }
                auto* item=reinterpret_cast<void*>(static_cast<std::uintptr_t>(item_address));
                if(item!=nullptr) {
                    auto* sprite=relative_item(item,0x14);
                    const auto left=static_cast<std::int32_t>(label*0x4au+0x20u);
                    splash_progress_draw_overlay_00562810(sprite,left,0x16c,
                        read_i16(sprite,4),read_i16(sprite,6));
                    const auto player_value=read_u32(record,0);
                    const auto product_bits=static_cast<std::uint32_t>(
                        static_cast<std::int32_t>(player_value))*54u;
                    const auto product=static_cast<std::int32_t>(product_bits);
                    const auto progress=product/10;
                    const auto progress_float=static_cast<float>(progress);
                    const auto remaining=trunc_ftol(54.0f-progress_float);
                    const auto label_x=static_cast<std::int32_t>(label*0x4au+0x20u);
                    const auto progress_x=trunc_ftol(
                        static_cast<float>(label_x)+progress_float);
                    splash_progress_draw_text_00562680(progress_x,0x1b4,
                        static_cast<std::uint32_t>(remaining),6,0xff312000u);
                    splash_progress_draw_text_00562680(label_x,0x1b4,
                        static_cast<std::uint32_t>(progress),6,0xffffbb00u);
                }
            }
        }
        if(*context_slot!=nullptr) {
            const auto lock=read_u32(*context_slot,0);
            splash_progress_leave_lock_005322c0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock)));
        }
    }

    splash_progress_frame_begin_004b0d70();
    splash_progress_thrash_window_006bd9b0(2);
    splash_progress_thrash_clear_window_006bd91c();
    splash_progress_thrash_sync_006bd978(0);
    splash_progress_driver_frame_begin_00534540();
    const auto texture_object=reinterpret_cast<const void*>(
        static_cast<std::uintptr_t>(splash_progress_texture_00655a24));
    const auto texture_handle=read_u32(texture_object,0x28);
    splash_progress_driver_draw_0053d570(texture_handle,
        (static_cast<std::int32_t>(render_display_texture_width_005deac8)-0x280)/2,
        (static_cast<std::int32_t>(render_display_texture_height_005deacc)-0x1e0)/2);
    splash_progress_driver_frame_end_00534550();
    splash_progress_thrash_pageflip_006bd948();

    // The original's trailing phase==10 release block is unreachable: the
    // entry branch above clears the byte and returns before any render work.
}

} // namespace porsche
