// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Six complete originals1358B;1444B writable/18B readonly original state.
#include "render_library_lifecycle_528.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/window_scheduler.hpp"
#include "porsche/window_position.hpp"
#include "../348-diagnostic-parsers/diagnostic_parsers.hpp"
namespace porsche {
std::uint32_t render_library_cache_0069e5f0[8][45]{};
std::uint32_t render_library_started_006a64b8=0;
const char render_library_environment_005c0e10[18]="THRASH_DRIVERNAME";
void __cdecl thread_exit_register_00557380(void(__cdecl*)());
namespace {
using U=std::uint32_t;
U index(U value){const auto signed_value=static_cast<std::int32_t>(value);return signed_value<0||signed_value>=8?0:value;}
U setstate(U key,U value){using F=U(__stdcall*)(U,U);return reinterpret_cast<F>(render_thrash_exports_006bd910[27])(key,value);}
}
void __cdecl render_library_cache_restore_00594cd0(U value){
    const U row=index(value);
    render_cleanup_token_0069e5ec=row;
    render_library_handle_0069e5e8=render_library_cache_0069e5f0[row][0];
    render_thrash_exports_006bd910[9]=render_library_cache_0069e5f0[row][1];
    render_thrash_exports_006bd910[32]=render_library_cache_0069e5f0[row][2];
    render_thrash_exports_006bd910[19]=render_library_cache_0069e5f0[row][3];
    render_thrash_exports_006bd910[10]=render_library_cache_0069e5f0[row][4];
    render_thrash_exports_006bd910[42]=render_library_cache_0069e5f0[row][5];
    render_thrash_exports_006bd910[18]=render_library_cache_0069e5f0[row][6];
    render_thrash_exports_006bd910[22]=render_library_cache_0069e5f0[row][7];
    render_thrash_exports_006bd910[15]=render_library_cache_0069e5f0[row][8];
    render_thrash_exports_006bd910[12]=render_library_cache_0069e5f0[row][9];
    render_thrash_exports_006bd910[30]=render_library_cache_0069e5f0[row][10];
    render_thrash_exports_006bd910[40]=render_library_cache_0069e5f0[row][11];
    render_thrash_exports_006bd910[1]=render_library_cache_0069e5f0[row][12];
    render_thrash_exports_006bd910[37]=render_library_cache_0069e5f0[row][13];
    render_thrash_exports_006bd910[28]=render_library_cache_0069e5f0[row][14];
    render_thrash_exports_006bd910[3]=render_library_cache_0069e5f0[row][15];
    render_thrash_exports_006bd910[24]=render_library_cache_0069e5f0[row][16];
    render_thrash_exports_006bd910[14]=render_library_cache_0069e5f0[row][17];
    render_thrash_exports_006bd910[26]=render_library_cache_0069e5f0[row][19];
    render_thrash_exports_006bd910[41]=render_library_cache_0069e5f0[row][20];
    render_thrash_exports_006bd910[27]=render_library_cache_0069e5f0[row][21];
    render_thrash_exports_006bd910[2]=render_library_cache_0069e5f0[row][22];
    render_thrash_exports_006bd910[4]=render_library_cache_0069e5f0[row][23];
    render_thrash_exports_006bd910[29]=render_library_cache_0069e5f0[row][24];
    render_thrash_exports_006bd910[36]=render_library_cache_0069e5f0[row][25];
    render_thrash_exports_006bd910[34]=render_library_cache_0069e5f0[row][26];
    render_thrash_exports_006bd910[17]=render_library_cache_0069e5f0[row][27];
    render_thrash_exports_006bd910[21]=render_library_cache_0069e5f0[row][28];
    render_thrash_exports_006bd910[7]=render_library_cache_0069e5f0[row][29];
    render_thrash_exports_006bd910[23]=render_library_cache_0069e5f0[row][30];
    render_thrash_exports_006bd910[8]=render_library_cache_0069e5f0[row][31];
    render_thrash_exports_006bd910[38]=render_library_cache_0069e5f0[row][32];
    render_thrash_exports_006bd910[13]=render_library_cache_0069e5f0[row][33];
    render_thrash_exports_006bd910[6]=render_library_cache_0069e5f0[row][34];
    render_thrash_exports_006bd910[39]=render_library_cache_0069e5f0[row][35];
    render_thrash_exports_006bd910[35]=render_library_cache_0069e5f0[row][36];
    render_thrash_exports_006bd910[31]=render_library_cache_0069e5f0[row][37];
    render_thrash_exports_006bd910[16]=render_library_cache_0069e5f0[row][38];
    render_thrash_exports_006bd910[11]=render_library_cache_0069e5f0[row][39];
    render_thrash_exports_006bd910[33]=render_library_cache_0069e5f0[row][40];
    render_thrash_exports_006bd910[5]=render_library_cache_0069e5f0[row][41];
    render_thrash_exports_006bd910[20]=render_library_cache_0069e5f0[row][42];
    render_thrash_exports_006bd910[25]=render_library_cache_0069e5f0[row][43];
    render_thrash_exports_006bd910[0]=render_library_cache_0069e5f0[row][44];
}
void __cdecl render_loader_reset_00594f00(U value){
    const U row=index(value);
    render_library_cache_0069e5f0[row][0]=render_library_handle_0069e5e8;
    render_library_cache_0069e5f0[row][1]=render_thrash_exports_006bd910[9];
    render_library_cache_0069e5f0[row][2]=render_thrash_exports_006bd910[32];
    render_library_cache_0069e5f0[row][3]=render_thrash_exports_006bd910[19];
    render_library_cache_0069e5f0[row][4]=render_thrash_exports_006bd910[10];
    render_library_cache_0069e5f0[row][5]=render_thrash_exports_006bd910[42];
    render_library_cache_0069e5f0[row][6]=render_thrash_exports_006bd910[18];
    render_library_cache_0069e5f0[row][7]=render_thrash_exports_006bd910[22];
    render_library_cache_0069e5f0[row][8]=render_thrash_exports_006bd910[15];
    render_library_cache_0069e5f0[row][9]=render_thrash_exports_006bd910[12];
    render_library_cache_0069e5f0[row][10]=render_thrash_exports_006bd910[30];
    render_library_cache_0069e5f0[row][11]=render_thrash_exports_006bd910[40];
    render_library_cache_0069e5f0[row][12]=render_thrash_exports_006bd910[1];
    render_library_cache_0069e5f0[row][13]=render_thrash_exports_006bd910[37];
    render_library_cache_0069e5f0[row][14]=render_thrash_exports_006bd910[28];
    render_library_cache_0069e5f0[row][15]=render_thrash_exports_006bd910[3];
    render_library_cache_0069e5f0[row][16]=render_thrash_exports_006bd910[24];
    render_library_cache_0069e5f0[row][17]=render_thrash_exports_006bd910[14];
    render_library_cache_0069e5f0[row][19]=render_thrash_exports_006bd910[26];
    render_library_cache_0069e5f0[row][20]=render_thrash_exports_006bd910[41];
    render_library_cache_0069e5f0[row][21]=render_thrash_exports_006bd910[27];
    render_library_cache_0069e5f0[row][22]=render_thrash_exports_006bd910[2];
    render_library_cache_0069e5f0[row][23]=render_thrash_exports_006bd910[4];
    render_library_cache_0069e5f0[row][24]=render_thrash_exports_006bd910[29];
    render_library_cache_0069e5f0[row][25]=render_thrash_exports_006bd910[36];
    render_library_cache_0069e5f0[row][26]=render_thrash_exports_006bd910[34];
    render_library_cache_0069e5f0[row][27]=render_thrash_exports_006bd910[17];
    render_library_cache_0069e5f0[row][28]=render_thrash_exports_006bd910[21];
    render_library_cache_0069e5f0[row][29]=render_thrash_exports_006bd910[7];
    render_library_cache_0069e5f0[row][30]=render_thrash_exports_006bd910[23];
    render_library_cache_0069e5f0[row][31]=render_thrash_exports_006bd910[8];
    render_library_cache_0069e5f0[row][32]=render_thrash_exports_006bd910[38];
    render_library_cache_0069e5f0[row][33]=render_thrash_exports_006bd910[13];
    render_library_cache_0069e5f0[row][34]=render_thrash_exports_006bd910[6];
    render_library_cache_0069e5f0[row][35]=render_thrash_exports_006bd910[39];
    render_library_cache_0069e5f0[row][36]=render_thrash_exports_006bd910[35];
    render_library_cache_0069e5f0[row][37]=render_thrash_exports_006bd910[31];
    render_library_cache_0069e5f0[row][38]=render_thrash_exports_006bd910[16];
    render_library_cache_0069e5f0[row][39]=render_thrash_exports_006bd910[11];
    render_library_cache_0069e5f0[row][40]=render_thrash_exports_006bd910[33];
    render_library_cache_0069e5f0[row][41]=render_thrash_exports_006bd910[5];
    render_library_cache_0069e5f0[row][42]=render_thrash_exports_006bd910[20];
    render_library_cache_0069e5f0[row][43]=render_thrash_exports_006bd910[25];
    render_library_cache_0069e5f0[row][44]=render_thrash_exports_006bd910[0];
}
void __cdecl render_library_unload_00575600(){
    const U handle=render_library_handle_0069e5e8;
    const U token=render_cleanup_token_0069e5ec;
    if(handle)render_win_free_library_005b2088(handle);
    render_library_handle_0069e5e8=0;
    render_library_cache_restore_00594cd0(0);
    render_loader_reset_00594f00(token);
}
U __cdecl render_initialize_library_00575640(U name){
    if(render_library_handle_0069e5e8)render_library_unload_00575600();
    const char* selected=reinterpret_cast<const char*>(name);
    if(!selected)return 1;
    if(*selected=='!')++selected;
    else {
        const char* environment=application_diagnostic_environment_005a3050(render_library_environment_005c0e10);
        if(environment)selected=environment;
    }
    if(!*selected)return 0;
    if(!render_cleanup_token_0069e5ec){
        render_cleanup_token_0069e5ec=1;
        thread_exit_register_00557380(&render_library_unload_00575600);
    }
    return render_load_thrash_00574fa0(selected);
}
U __cdecl render_library_disable_state_005756c0(U,U){(void)setstate(0x25,0);return 0;}
U __cdecl render_initialize_shutdown_00575930(U cleanup){
    if(render_library_started_006a64b8){
        if(setstate(0x25,0))(void)window_scheduler_remove_005366a0(&render_library_disable_state_005756c0);
        using Shutdown=U(__stdcall*)();
        (void)reinterpret_cast<Shutdown>(render_thrash_exports_006bd910[10])();
        if(cleanup)window_position_cleanup_0053bcb0();
        render_library_started_006a64b8=0;
    }
    return 0;
}
U __stdcall render_library_fallback_getstate_00574f80(U){return 0;}
U __stdcall render_library_fallback_tfree_00574f90(U){
    // Keep distinct original callback identities under native fixture ICF.
    // The game link additionally retains its global /OPT:NOICF guard.
    __asm {nop}
    return 0;
}
}
