#include "render_descriptor.hpp"
#include "render_initialize_521.hpp"
#include "cursor_snapshot.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/render_display.hpp"
#include "porsche/splash_progress.hpp"
#include <cstring>
namespace porsche {
void* render_descriptor_fallback_0069dd14=nullptr;
std::uint32_t render_descriptor_flags_005deb60=0;
std::uint32_t render_descriptor_option_005deb88=0;
const std::uint8_t render_descriptor_bits_005de890[128]={
    0,4,8,15,24,32,16,0,0,0,0,0,0,0,0,0,
    15,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    15,32,24,0,24,0,0,0,0,16,32,0,32,15,32,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    4,8,15,24,1,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,
    0,0,0,0,0,0,0,0,16,1,4,8,0,32,15,24};
namespace {
using U=std::uint32_t;using B=std::uint8_t;
U read(const void* p,U offset){U v;std::memcpy(&v,static_cast<const B*>(p)+offset,4);return v;}
void write(void* p,U offset,U v){std::memcpy(static_cast<B*>(p)+offset,&v,4);}
// A canonical descriptor never escapes as a host pointer. Only the internal
// DWORD-format helper receives the equivalent four-byte input value.
struct PointerDescriptor {
    B* p;
    bool null()const{return p==nullptr;}
    B byte(U o)const{return p[o];}
    void byte(U o,B v)const{p[o]=v;}
    U word(U o)const{return read(p,o);}
    void word(U o,U v)const{write(p,o,v);}
};
struct CanonicalDescriptor {
    bool null()const{return false;}
    B& cell(U o)const{
        if(o<12)return cursor_snapshot_prefix_005de650[o];
        if(o==12)return window_shutdown_source_005de65c;
        if(o==13)return window_shutdown_source_005de65d;
        if(o<44)return cursor_snapshot_suffix_005de65e[o-14];
        return reinterpret_cast<B*>(&window_shutdown_state_005de67c)[o-44];
    }
    B byte(U o)const{return cell(o);}
    void byte(U o,B v)const{cell(o)=v;}
    U word(U o)const{U v;B* b=reinterpret_cast<B*>(&v);for(U i=0;i<4;++i)b[i]=cell(o+i);return v;}
    void word(U o,U v)const{const B* b=reinterpret_cast<const B*>(&v);for(U i=0;i<4;++i)cell(o+i)=b[i];}
};
template<class Descriptor>void copy_forward(Descriptor descriptor){
    for(U i=0;i<12;++i)window_shutdown_config_005de620[i]=descriptor.word(4*i);
}
}
std::uint32_t __cdecl render_descriptor_format_00556880(std::uint32_t format){
    switch(format&0x7fffffffu){
    case 1:return 0x7a;case 2:return 0x7b;case 3:case 11:return 0x7e;
    case 4:return 0x78;case 5:return 0x7f;case 6:return 0x7d;
    case 7:return 0x6d;case 12:return 0xf8;case 13:return 0xfd;
    default:return 0;
    }
}
std::uint32_t __cdecl render_descriptor_bits_00537f90(const void* descriptor_format){
    return render_descriptor_bits_005de890[read(descriptor_format,0)&0x7fu];
}
namespace {
template<class Descriptor>U window_core(Descriptor descriptor){
    const U mode=descriptor.byte(16);
    window_shutdown_display_callback_006bd9b0(mode);
    using Lock=void* (__stdcall*)();
    window_shutdown_handle_0069dd18=reinterpret_cast<Lock>(
        static_cast<std::uintptr_t>(render_thrash_exports_006bd910[21]))();
    auto* buffer=window_shutdown_handle_0069dd18;
    if(!buffer)return 0;
    const U width=read(buffer,12),height=read(buffer,16),format=read(buffer,8);
    descriptor.word(0,0x57494e44);descriptor.word(4,width);descriptor.word(8,height);
    descriptor.byte(12,static_cast<B>(render_descriptor_format_00556880(format)));
    const U format_word=descriptor.word(12);
    const U bits=render_descriptor_bits_00537f90(&format_word);descriptor.byte(13,static_cast<B>(bits));
    const U storage_bits=bits==15?16:bits;descriptor.byte(14,static_cast<B>(storage_bits));
    buffer=window_shutdown_handle_0069dd18;
    const float bits_float=static_cast<float>(storage_bits);
    const U row_width=read(buffer,12);descriptor.byte(16,static_cast<B>(mode));descriptor.word(28,row_width);
    const U pitch=read(buffer,4);U float_word;std::memcpy(&float_word,&bits_float,4);
    descriptor.word(20,0);descriptor.word(24,0);
    descriptor.byte(15,static_cast<B>((float_word>>23)+0x7eu));
    const U row_height=read(buffer,16),pixels=read(buffer,0);
    descriptor.word(32,row_height);descriptor.word(36,pitch);
    descriptor.word(40,0);descriptor.word(44,pixels);return 1;
}
template<class Descriptor>U bind_core(Descriptor descriptor){
    window_shutdown_runtime_state_00534430();
    if(descriptor.null()){
        std::memset(window_shutdown_config_005de620,0,48);
        auto* bytes=reinterpret_cast<B*>(window_shutdown_config_005de620);
        bytes[12]=window_shutdown_source_005de65c;bytes[13]=window_shutdown_source_005de65d;return 1;
    }
    U result=1;const U mode=descriptor.byte(16);
    if(mode!=0&&mode!=255)result=window_core(descriptor);
    if(result){copy_forward(descriptor);return result;}
    if(!render_descriptor_fallback_0069dd14)
        render_descriptor_fallback_0069dd14=render_descriptor_create_00535950(
            8,8,splash_progress_format_005dead0,render_descriptor_flags_005deb60);
    // Original allocation failure has no guard; the valid fallback span is an
    // explicit comparison domain, not a silently invented success policy.
    copy_forward(PointerDescriptor{static_cast<B*>(render_descriptor_fallback_0069dd14)});return result;
}
}
std::uint32_t __cdecl render_descriptor_window_00534360(void* descriptor){return window_core(PointerDescriptor{static_cast<B*>(descriptor)});}
std::uint32_t __cdecl render_descriptor_bind_00534480(void* descriptor){return bind_core(PointerDescriptor{static_cast<B*>(descriptor)});}
std::uint32_t __cdecl render_descriptor_bind_canonical_00534480(){return bind_core(CanonicalDescriptor{});}
void* __cdecl render_descriptor_create_00535950(U width,U height,U format,U flags){
    return render_descriptor_allocate_00535700(width,height,format,flags,render_descriptor_option_005deb88);
}
void __cdecl render_display_texture_bind_00534480(void* descriptor){(void)render_descriptor_bind_00534480(descriptor);}
std::int32_t __cdecl splash_progress_bind_texture_00534480(U descriptor){
    return static_cast<std::int32_t>(render_descriptor_bind_00534480(reinterpret_cast<void*>(static_cast<std::uintptr_t>(descriptor))));
}
void* __cdecl render_display_texture_create_00535950(U width,U height,U format,U flags){
    return render_descriptor_create_00535950(width,height,format,flags);
}
U __cdecl splash_progress_create_texture_00535950(U width,U height,U format,U flags){
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(render_descriptor_create_00535950(width,height,format,flags)));
}
}
