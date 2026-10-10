#include "porsche/splash_progress.hpp"
#include "porsche/application_state.hpp"
#include "porsche/render_display.hpp"
#include "porsche/startup_services.hpp"

#include <array>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
struct FakeTexture { std::array<std::uint8_t,0x40> bytes{}; } texture;
struct FakeResource { std::array<std::uint8_t,0x1000> bytes{}; } background,alternate,loading,text;
struct FakePlayer { std::uint32_t marker{}; } player;
struct Selection { std::uint32_t reserved{},first{},capacity{},end{}; } selection;
struct FakeLock { std::uint32_t marker{}; } lock_context;
std::vector<std::string> events;
std::int32_t counter_begin_first{},counter_end_first{},pump_count{},pumps_left{};
std::int32_t mode_format{};
bool alt_exists{},text_exists{},player_exists{},player_visible{};
bool selected_valid{};
std::string root_path="FE\\",alternate_root="ALT\\";

std::uint32_t address(const void* value) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
void store32(void* base,std::size_t offset,std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,sizeof(value));
}
void store16(void* base,std::size_t offset,std::int16_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base)+offset,&value,sizeof(value));
}
void fill_resource(FakeResource& resource) {
    std::memset(resource.bytes.data(),0,resource.bytes.size());
    for(std::uint32_t field=0x0c;field<0x380;field+=8) {
        const auto slot=static_cast<std::uint32_t>((field-0x0c)/8);
        store32(resource.bytes.data(),field,0x500+slot*0x10);
    }
    for(std::uint32_t offset=0x500;offset<0xf00;offset+=0x10) {
        store16(resource.bytes.data(),offset+4,static_cast<std::int16_t>(offset&0x7f));
        store16(resource.bytes.data(),offset+6,static_cast<std::int16_t>((offset>>1)&0x7f));
        store16(resource.bytes.data(),offset+8,static_cast<std::int16_t>((offset&0x3f)-0x20));
        store16(resource.bytes.data(),offset+10,static_cast<std::int16_t>((offset&0x1f)-0x10));
    }
}
std::string pointer_label(const void* p) {
    const auto v=reinterpret_cast<std::uintptr_t>(p);
    const auto check=[&](const FakeResource& r,const char* name)->std::string {
        const auto b=reinterpret_cast<std::uintptr_t>(r.bytes.data());
        if(v>=b && v<b+r.bytes.size())
            return std::string(name)+"+"+std::to_string(v-b);
        return {};
    };
    for(const auto pair : {std::pair<const FakeResource*,const char*>{&background,"bg"},
                           {&alternate,"alt"},{&loading,"loading"},{&text,"text"}}) {
        auto label=check(*pair.first,pair.second);if(!label.empty())return label;
    }
    const auto tex=reinterpret_cast<std::uintptr_t>(texture.bytes.data());
    if(v>=tex && v<tex+texture.bytes.size())return "texture+"+std::to_string(v-tex);
    if(v==0x4444)return "lock-handle";
    if(p==&player)return "player";
    if(p==&selection)return "selection";
    if(p==&lock_context)return "lock-context";
    return "ptr";
}
void record(const std::string& event) { events.push_back(event); }
std::string normalize_path(const char* path) { return path?std::string(path):"<null>"; }
}

namespace porsche {
void* startup_network_00628c70=nullptr;
namespace { const char* fixture_install_paths[60]{}; }
const char*& game_setup_load_base_0065b334=fixture_install_paths[37];
const char*& splash_progress_alternate_base_0065b350=fixture_install_paths[44];
std::uint32_t render_display_texture_width_005deac8=640;
std::uint32_t render_display_texture_height_005deacc=480;

std::uint32_t __cdecl splash_progress_create_texture_00535950(
    std::uint32_t w,std::uint32_t h,std::uint32_t format,std::uint32_t flags) {
    std::memset(texture.bytes.data(),0,texture.bytes.size());
    store32(texture.bytes.data(),0x28,0x12345678);
    record("create:"+std::to_string(w)+":"+std::to_string(h)+":"+
        std::to_string(format)+":"+std::to_string(flags));
    return address(texture.bytes.data());
}
void __cdecl splash_progress_dispatch_004edc00(std::uint32_t id,void** cursor,
    std::uint32_t source,std::int32_t progress) {
    auto* words=static_cast<std::uint32_t*>(*cursor);
    words[0]=id;words[1]=source;words[2]=static_cast<std::uint32_t>(progress);
    *cursor=words+3;
    record("dispatch:"+std::to_string(id)+":"+std::to_string(source)+":"+
        std::to_string(progress));
}
void __cdecl splash_progress_release_stack_0048d550(void* allocation) {
    auto* p=static_cast<std::uint32_t*>(allocation);
    record("records:"+std::to_string(p[0])+":"+std::to_string(p[1])+":"+
        std::to_string(p[2])+":"+std::to_string(p[3]));
}
std::int32_t __cdecl splash_progress_resource_begin_004ad670() {
    record("resource-begin");
    if(pumps_left>0 && pump_count==0)return counter_begin_first;
    return 0;
}
std::int32_t __cdecl splash_progress_resource_end_004ad6c0() {
    record("resource-end");
    if(pumps_left>0 && pump_count==0)return counter_end_first;
    return 0;
}
void __cdecl splash_progress_pump_005366e0(std::uint32_t zero) {
    record("pump:"+std::to_string(zero));++pump_count;--pumps_left;
}
std::int32_t __cdecl splash_progress_bind_texture_00534480(std::uint32_t texture_word) {
    record("bind:"+pointer_label(reinterpret_cast<void*>(static_cast<std::uintptr_t>(texture_word))));
    return 1;
}
void __cdecl splash_progress_format_005a0fbf(char* out,const char* format,...) {
    va_list args;va_start(args,format);std::vsnprintf(out,256,format,args);va_end(args);
    record("format:"+normalize_path(out));
}
std::int32_t __cdecl splash_progress_file_exists_0059dc30(const char* path) {
    const auto p=normalize_path(path);
    const bool exists=p.find("ALT\\")!=std::string::npos?alt_exists:text_exists;
    record("exists:"+p+":"+(exists?"1":"0"));return exists?1:0;
}
void* __cdecl splash_progress_load_resource_0059d8e0(const char* path,std::uint32_t flags) {
    const auto p=normalize_path(path);FakeResource* resource=&background;const char* label="bg";
    if(p.find("MLoading")!=std::string::npos){resource=&loading;label="loading";}
    else if(p.find("loadtext")!=std::string::npos){resource=&text;label="text";}
    else if(p.find("ALT\\")!=std::string::npos){resource=&alternate;label="alt";}
    record(std::string("load:")+label+":"+p+":"+std::to_string(flags));return resource->bytes.data();
}
std::uint32_t __cdecl splash_progress_render_format_005032d0() {
    record("render-format:"+std::to_string(mode_format));return static_cast<std::uint32_t>(mode_format);
}
void __cdecl splash_progress_draw_tile_00563440(const void* item,std::int32_t x,
    std::int32_t y,std::int32_t w,std::int32_t h) {
    record("tile:"+pointer_label(item)+":"+std::to_string(x)+":"+std::to_string(y)+":"+
        std::to_string(w)+":"+std::to_string(h));
}
void __cdecl splash_progress_update_sprite_00563320(void* item) {
    record("flip:"+pointer_label(item));
}
void __cdecl splash_progress_draw_sprite_00563160(void* item,std::int32_t a,
    std::int32_t b,std::int32_t c,std::int32_t d) {
    record("sprite:"+pointer_label(item)+":"+std::to_string(a)+":"+std::to_string(b)+":"+
        std::to_string(c)+":"+std::to_string(d));
}
void __cdecl splash_progress_free_00531f90(void* resource) {
    record("free:"+pointer_label(resource));
}
void __cdecl splash_progress_draw_overlay_00562810(void* item,std::int32_t a,
    std::int32_t b,std::int32_t c,std::int32_t d) {
    record("overlay:"+pointer_label(item)+":"+std::to_string(a)+":"+std::to_string(b)+":"+
        std::to_string(c)+":"+std::to_string(d));
}
void __cdecl splash_progress_draw_text_00562680(std::int32_t x,std::int32_t y,
    std::uint32_t value,std::uint32_t font,std::uint32_t color) {
    record("text:"+std::to_string(x)+":"+std::to_string(y)+":"+std::to_string(value)+":"+
        std::to_string(font)+":"+std::to_string(color));
}
void __cdecl splash_progress_enter_lock_005322b0(void* lock) {
    record("enter:"+pointer_label(lock));
}
void __cdecl splash_progress_leave_lock_005322c0(void* lock) {
    record("leave:"+pointer_label(lock));
}
std::int32_t __cdecl splash_progress_find_item_0048d720(std::int32_t index) {
    record("find:"+std::to_string(index));return player_exists?static_cast<std::int32_t>(address(&player)):0;
}
std::uint8_t __fastcall splash_progress_item_visible_00490390(void* item) {
    record("visible:"+pointer_label(item));return player_visible?1:0;
}
void* __cdecl splash_progress_item_data_004903f0(void* item,std::int16_t key) {
    record("item-data:"+pointer_label(item)+":"+std::to_string(key));
    return selected_valid?&selection:nullptr;
}
void __cdecl splash_progress_frame_begin_004b0d70() { record("frame-state"); }
void __cdecl splash_progress_driver_frame_begin_00534540() { record("driver-begin"); }
void __cdecl splash_progress_driver_draw_0053d570(std::uint32_t texture_word,
    std::int32_t x,std::int32_t y) {
    record("present:"+std::to_string(texture_word)+":"+std::to_string(x)+":"+std::to_string(y));
}
void __cdecl splash_progress_driver_frame_end_00534550() { record("driver-end"); }
void __stdcall splash_progress_thrash_window_006bd9b0(std::uint32_t mode) {
    record("window:"+std::to_string(mode));
}
void __stdcall splash_progress_thrash_clear_window_006bd91c() { record("clear"); }
void __stdcall splash_progress_thrash_sync_006bd978(std::uint32_t zero) {
    record("sync:"+std::to_string(zero));
}
void __stdcall splash_progress_thrash_pageflip_006bd948() { record("pageflip"); }
void __cdecl splash_progress_release_texture_00533f80(std::uint32_t texture_word) {
    record("release-texture:"+std::to_string(texture_word));
}
} // namespace porsche

int main() {
    using namespace porsche;
    std::string name;std::int32_t phase,game_type,no_loading,format,format_mode,count;
    int initial_enabled,initial_texture,network_mode,config_live,alt_ok,text_ok,wait,player_mode;
    int mirror,reverse;std::uint32_t width,height,label,player_value;
    auto& state=application_state_006573e8;
    while(std::cin>>name>>phase>>initial_enabled>>initial_texture>>game_type>>no_loading>>format>>width>>height
        >>network_mode>>config_live>>alt_ok>>text_ok>>wait>>format_mode>>count>>player_mode
        >>mirror>>reverse>>label>>player_value) {
        events.clear();fill_resource(background);fill_resource(alternate);fill_resource(loading);fill_resource(text);
        std::memset(state.bytes(),0,application_state_bytes);
        splash_progress_texture_00655a24=initial_texture?address(texture.bytes.data()):0;
        splash_progress_enabled_00655a28=static_cast<std::uint8_t>(initial_enabled);
        splash_progress_format_005dead0=static_cast<std::uint32_t>(format);
        state.word(0x006573e8u)=static_cast<std::uint32_t>(game_type);
        state.word(0x00657440u)=static_cast<std::uint32_t>(no_loading);
        state.word(0x0065741cu)=0xabcdef01;
        game_setup_load_base_0065b334=root_path.c_str();
        splash_progress_alternate_base_0065b350=alternate_root.c_str();
        state.word(0x00657c84u)=(player_mode&8)?1u:0u;
        state.word(0x00658084u)=static_cast<std::uint32_t>(count);
        state.word(0x00658608u)=player_value;
        state.word(0x00658608u-0x408u)=label;
        state.word(0x0065742cu)=static_cast<std::uint32_t>(mirror);
        state.word(0x00657430u)=static_cast<std::uint32_t>(reverse);
        render_display_texture_width_005deac8=width;render_display_texture_height_005deacc=height;

        std::array<std::uint8_t,0x300> config{};
        if(network_mode!=0) {
            store32(config.data(),8,config_live?1u:0u);
            config[0xbe]=(network_mode&1)?1:0;config[0xbf]=(network_mode&2)?1:0;
            store32(config.data(),0xdc,(network_mode&4)?0xffffffffu:0u);
            if(network_mode&8){store32(config.data(),0x10,address(&lock_context));lock_context.marker=0x4444;}
            else store32(config.data(),0x10,0);
            startup_network_00628c70=config.data();
        } else startup_network_00628c70=nullptr;

        store16(background.bytes.data(),0x504,32);store16(background.bytes.data(),0x506,32);
        store16(alternate.bytes.data(),0x504,32);store16(alternate.bytes.data(),0x506,32);
        store16(text.bytes.data(),0x504,32);store16(text.bytes.data(),0x506,32);
        std::memset(texture.bytes.data(),0,texture.bytes.size());store32(texture.bytes.data(),0x28,0x12345678);
        player.marker=0x99;alt_exists=alt_ok!=0;text_exists=text_ok!=0;
        player_exists=(player_mode&1)!=0;player_visible=(player_mode&2)!=0;selected_valid=(player_mode&4)!=0;
        selection={0,address(alternate.bytes.data()),1,selected_valid?1u:0u};
        mode_format=format_mode;counter_begin_first=2;counter_end_first=1;
        pump_count=0;pumps_left=wait?1:0;

        splash_progress_004a4a70(phase);
        const auto texture_state=splash_progress_texture_00655a24==0?"none":
            splash_progress_texture_00655a24==address(texture.bytes.data())?"fixture":"other";
        std::cout<<name<<' '<<static_cast<unsigned>(splash_progress_enabled_00655a28)<<' '
            <<texture_state<<' '<<static_cast<unsigned>(state.word(0x006573e8u))<<' '
            <<render_display_texture_width_005deac8<<' '<<render_display_texture_height_005deacc<<' '
            <<events.size();
        for(const auto& e:events)std::cout<<' '<<e;
        std::cout<<'\n';
    }
}
