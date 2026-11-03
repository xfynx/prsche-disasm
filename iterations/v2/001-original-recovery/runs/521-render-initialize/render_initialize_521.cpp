// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Complete556bb0/285B and560060/20B. No speculative child algorithms.
#include "render_initialize_521.hpp"
#include "cursor_snapshot.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/startup_services.hpp"
#include "porsche/startup_input.hpp"
#include "porsche/window_event_queue.hpp"
#include <cstring>
namespace porsche {
std::uint32_t render_video_mode_005deaa8=0;
std::uint32_t render_video_state_005dead8=2;
extern std::uint32_t render_display_texture_width_005deac8,render_display_texture_height_005deacc;
extern std::uint32_t splash_progress_format_005dead0;
namespace {
using U=std::uint32_t;
// Exact90B original writable spans. Children read these strings; original
// mutation/concurrent domains remain open instead of claiming readonly PE data.
char sst_video_005df330[16]="SST_VIDEO_24BPP";
char glide_plug_005df318[24]="FX_GLIDE_SHAMELESS_PLUG";
char glide_splash_005df304[19]="FX_GLIDE_NO_SPLASH";
char sst_dual_005df2f4[13]="SST_DUALHEAD";
char sstv2_dual_005df2e4[15]="SSTV2_DUALHEAD";
char empty_005e8e50[1]="";
char one_005ccc44[2]="1";
U prefix_word(U offset){U v;std::memcpy(&v,cursor_snapshot_prefix_005de650+offset,4);return v;}
}
std::uint8_t __cdecl render_driver_initialize_00556bb0(U first,U name,U selected,U mode){
    (void)render_environment_00573030(sst_video_005df330,empty_005e8e50,0);
    (void)render_environment_00573030(glide_plug_005df318,empty_005e8e50,0);
    (void)render_environment_00573030(glide_splash_005df304,one_005ccc44,1);
    (void)render_environment_00573030(sst_dual_005df2f4,one_005ccc44,1);
    (void)render_environment_00573030(sstv2_dual_005df2e4,one_005ccc44,1);
    if(render_initialize_library_00575640(name)==0)return 0;
    if(render_initialize_window_00575820(static_cast<std::uint8_t>(first)!=0)==0)return 0;
    if(selected){using Select=U(__stdcall*)(U);
        (void)reinterpret_cast<Select>(render_thrash_exports_006bd910[42])(selected);}
    using Mode=U(__stdcall*)(U,U,U);
    (void)reinterpret_cast<Mode>(render_thrash_exports_006bd910[18])(mode,2,1);
    render_initialize_callbacks_005759f0();
    const U bound=render_descriptor_bind_canonical_00534480();
    (void)window_shutdown_prepare_00534550();
    if(bound){
        const U width=prefix_word(4),height=prefix_word(8);
        render_video_mode_005deaa8=mode;
        const U bits=window_shutdown_source_005de65d;
        render_display_texture_width_005deac8=width;
        render_display_texture_height_005deacc=height;
        splash_progress_format_005dead0=bits;
        render_video_state_005dead8=2;
    }
    render_initialize_service_0053c8e0();
    startup_subsystem_00536e50();
    (void)startup_input_initialize_0055fcf0();
    startup_subsystem_00564e70();
    (void)startup_input_set_key_state_0055fe50(10,reinterpret_cast<void*>(&render_input_callback_00560060));
    return 1;
}
std::uint32_t __cdecl render_input_callback_00560060(){
    const U event=window_event_dequeue_0053aa60()&0xffffu;
    return render_input_dispatch_00586cd0(event);
}
}
