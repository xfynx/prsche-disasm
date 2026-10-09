#include "porsche/render_loader.hpp"
#include <cstddef>

namespace porsche {
std::uint32_t render_thrash_exports_006bd910[43];
std::uint32_t render_library_handle_0069e5e8;
std::uint32_t render_cleanup_token_0069e5ec;
std::uint32_t render_driver_name_006a64b4;
std::uint32_t render_error_flag_005deb70;
std::uint32_t render_error_file_005deb74;
std::uint32_t render_error_line_005deb78;

namespace {
constexpr std::uint32_t source_file=0x005c0dd0;
constexpr std::uint32_t fallback_getstate=0x00574f80;
constexpr std::uint32_t fallback_tfree=0x00574f90;
constexpr std::size_t slot(std::uint32_t va) {return (va-0x006bd910)/4;}
struct Export {const char* symbol;std::uint32_t slot_va;bool required;};
// Exact GetProcAddress call/store order at 0x57503f..0x5752cd.
constexpr Export exports[]={
 {"_THRASH_about@0",0x6bd934,true},
 {"_THRASH_clearwindow@0",0x6bd91c,true},
 {"_THRASH_clip@16",0x6bd9b4,true},
 {"_THRASH_drawline@8",0x6bd950,true},
 {"_THRASH_drawlinemesh@12",0x6bd93c,true},
 {"_THRASH_drawlinestrip@12",0x6bd994,true},
 {"_THRASH_drawpoint@4",0x6bd924,true},
 {"_THRASH_drawpointmesh@12",0x6bd960,true},
 {"_THRASH_drawquad@16",0x6bd9a8,true},
 {"_THRASH_drawquadmesh@12",0x6bd944,true},
 {"_THRASH_drawtri@12",0x6bd928,true},
 {"_THRASH_drawtrifan@12",0x6bd98c,true},
 {"_THRASH_drawtrimesh@12",0x6bd9ac,true},
 {"_THRASH_drawtristrip@12",0x6bd99c,true},
 {"_THRASH_drawsprite@8",0x6bd974,false},
 {"_THRASH_drawspritemesh@12",0x6bd910,false},
 {"_THRASH_flushwindow@0",0x6bd970,true},
 {"_THRASH_init@0",0x6bd95c,true},
 {"_THRASH_is@0",0x6bd990,true},
 {"_THRASH_lockwindow@0",0x6bd964,true},
 {"_THRASH_pageflip@0",0x6bd948,true},
 {"_THRASH_readrect@20",0x6bd96c,true},
 {"_THRASH_restore@0",0x6bd938,true},
 {"_THRASH_selectdisplay@4",0x6bd9b8,true},
 {"_THRASH_setstate@8",0x6bd97c,true},
 {"_THRASH_getstate@4",0x6bd984,false},
 {"_THRASH_settexture@4",0x6bd954,true},
 {"_THRASH_setvideomode@12",0x6bd958,true},
 {"_THRASH_sync@4",0x6bd978,true},
 {"_THRASH_talloc@20",0x6bd968,true},
 {"_THRASH_tfree@4",0x6bd94c,false},
 {"_THRASH_treset@0",0x6bd988,true},
 {"_THRASH_tupdate@12",0x6bd940,true},
 {"_THRASH_unlockwindow@4",0x6bd92c,true},
 {"_THRASH_window@4",0x6bd9b0,true},
 {"_THRASH_writerect@20",0x6bd930,true},
};
static_assert(sizeof(render_thrash_exports_006bd910)/4==43);
void report(const char* message,std::uint32_t line) {
    render_error_file_005deb74=source_file;
    render_error_line_005deb78=line;
    render_loader_report_00565340(message);
}
}

std::uint32_t __cdecl render_load_thrash_00574fa0(const char* driver_name) {
    if (!driver_name) {
        report("THRASH_opendll - NO LIBRARY SPECIFIED.\n",0x76);
        return 0;
    }
    char path[512];
    render_loader_format_005a0fbf(path,"%s",driver_name);
    render_library_handle_0069e5e8=render_win_load_library_005b2050(path);
    if (!render_library_handle_0069e5e8) {
        render_loader_format_005a0fbf(path,"%sz",driver_name);
        render_library_handle_0069e5e8=render_win_load_library_005b2050(path);
        if (!render_library_handle_0069e5e8) {
            std::uint32_t version[2]={0,0};
            const std::uint32_t last_error=render_win_last_error_005b213c();
            render_loader_directx_00574eb0(version,"ddraw.dll");
            char message[512];
            const std::uint32_t major=version[1]&0xffff;
            if (major<7) render_loader_format_005a0fbf(message,
                "You have DirectX %d. Please install DirectX 7.\nCould not load \"%s\"",major,driver_name);
            else render_loader_format_005a0fbf(message,
                "THRASH_opendll - LOADLIBRARY FAILED ON \"%s\".\nGETLASTERROR CODE IS %d.  CHECK THIS DLL IS INSTALLED.\nDIRECT X VERSION IS %d\n",
                driver_name,last_error,major);
            report(message,0x111);
            render_error_flag_005deb70=0;
            return 0;
        }
    }
    bool valid=true;
    for (const Export& entry:exports) {
        const std::uint32_t value=render_win_get_proc_005b205c(render_library_handle_0069e5e8,entry.symbol);
        render_thrash_exports_006bd910[slot(entry.slot_va)]=value;
        if (entry.required && !value) valid=false;
    }
    render_thrash_exports_006bd910[slot(0x6bd9a0)]=render_thrash_exports_006bd910[slot(0x6bd984)];
    render_thrash_exports_006bd910[slot(0x6bd998)]=render_thrash_exports_006bd910[slot(0x6bd984)];
    render_thrash_exports_006bd910[slot(0x6bd918)]=render_thrash_exports_006bd910[slot(0x6bd97c)];
    render_thrash_exports_006bd910[slot(0x6bd920)]=render_thrash_exports_006bd910[slot(0x6bd97c)];
    if (!valid) {
        render_win_free_library_005b2088(render_library_handle_0069e5e8);
        report("THRASH_opendll - not a 3rash DLL",0xf8);
        render_error_flag_005deb70=0;
        return 0;
    }
    const std::uint32_t module=render_win_get_module_005b2138(path);
    if (module)render_win_disable_thread_calls_005b21b4(module);
    if (!render_thrash_exports_006bd910[slot(0x6bd984)])
        render_thrash_exports_006bd910[slot(0x6bd984)]=fallback_getstate;
    if (!render_thrash_exports_006bd910[slot(0x6bd94c)])
        render_thrash_exports_006bd910[slot(0x6bd94c)]=fallback_tfree;
    render_error_flag_005deb70=0;
    render_driver_name_006a64b4=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(driver_name));
    render_loader_set_state_006bd97c(render_thrash_exports_006bd910[slot(0x6bd97c)],0x1f,0x6b);
    render_loader_reset_00594f00(render_cleanup_token_0069e5ec);
    const std::uint32_t* about=render_loader_about_006bd934(render_thrash_exports_006bd910[slot(0x6bd934)]);
    if (about && (*about==0x33444658 || *about==0x33444632))render_error_flag_005deb70=1;
    return 1;
}
}
