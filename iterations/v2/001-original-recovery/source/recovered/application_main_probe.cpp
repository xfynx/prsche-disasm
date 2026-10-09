#include "porsche/application_main.hpp"
#include "porsche/application_heap.hpp"
#include "porsche/application_fe.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/render_activate.hpp"
#include "porsche/render_startup.hpp"
#include "porsche/render_display.hpp"
#include "porsche/resource_paths.hpp"
#include "porsche/startup_services.hpp"
#include <cstdint>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace porsche {
std::uint32_t global_006573e8,global_00657424,global_00657428,global_0065743c;
std::uint32_t global_006577d8,global_006577dc,global_00606a88,global_00606874,global_005e99f4;
std::uint32_t global_00657a60;
std::uint8_t global_00657a64,global_00657e34;
// Controlled fixture scratch, not a claim about the original field extent.
char global_00657a84[0x100];
std::uint32_t fe_enabled_0065b298;
std::uint32_t render_display_mode_index_00619780;
RenderCore* render_core_0065b39c=nullptr;
RenderDisplay* render_display_00628130=nullptr;
char render_selector_00657a38[16]{};
std::uint32_t render_width_00657a48=800,render_height_00657a4c=600,render_selected_00657a58;
const char* render_display_name_0065b304=nullptr;
std::uint32_t render_display_requested_mode_00657a50;
void* startup_network_00628c70=nullptr;

static std::vector<std::string> events;
static std::uint32_t fixture_setup_result=0,fixture_setup_repeat=0,fixture_setup_count=0,fixture_tick=0;
static std::uint32_t fixture_fe_mode=0;
static std::uint32_t fixture_post_mode=0;
static std::uint8_t fixture_network_ready=0;
static std::uint32_t fixture_alloc_ok=1;
static std::uint32_t fixture_tick_calls=0;
static std::uint32_t fixture_stream[3]={0,0,0};
static std::uint8_t fixture_network[0x268]{};
static int page_token;
static void ev(const char* s){events.emplace_back(s);}
static void prepare_network(std::uint8_t ready){std::memset(fixture_network,0,sizeof(fixture_network));*reinterpret_cast<std::uint32_t*>(fixture_network+8)=1;fixture_network[0xbe]=ready;*reinterpret_cast<std::int32_t*>(fixture_network+0xdc)=ready?0:-1;}

void* __cdecl application_page_alloc_0059ed40(std::uint32_t* bytes){ev("0059ed40");if(fixture_alloc_ok){*bytes=0x08000000;return &page_token;}return nullptr;}
std::uint32_t __cdecl application_page_release_0059ed90(void*){ev("0059ed90");return 1;}
void __cdecl startup_cd_relaunch_004a5c30(){ev("004a5c30");}
void __cdecl startup_services_004a5410(){ev("004a5410");}
void __cdecl startup_exit_005a246e(std::uint32_t){ev("005a246e");}
std::int32_t __cdecl resource_paths_0059d650(){ev("0059d650");return 0;}
std::uint32_t* __cdecl fe_build_004b6660(std::int32_t,char**){ev("004b6660");fixture_stream[0]=fixture_fe_mode?48u:0u;fixture_stream[1]=fixture_fe_mode;fixture_stream[2]=0;return fixture_stream;}
void __cdecl fe_apply_004b4b80(const std::uint32_t* p){if(*p==48)global_006573e8=p[1];}
std::int32_t __cdecl fe_record_words_004b4cd0(const std::uint32_t* p){return *p==48?2:1;}
std::uint32_t __cdecl free_00531f90(void*){ev("00531f90");return 1;}
void __cdecl application_fe_apply_release_004b6ad8(std::uint32_t* p){while(*p){fe_apply_004b4b80(p);p+=fe_record_words_004b4cd0(p);}free_00531f90(p);}
void __cdecl application_main_fill_fe_arena_0053c290(std::uint32_t,std::uint32_t,std::uint32_t){ev("0053c290");}
std::uint32_t __cdecl application_main_memory_dialog(const char*,const char*){ev("MessageBoxA");return 0;}
void __cdecl application_main_create_directory(std::uint32_t){ev("CreateDirectoryA");}
void __cdecl application_main_setup_heaps(std::uint32_t,std::uint32_t){ev("004a6840");}
void __cdecl application_main_log(const char*){ev("005a177b");}
std::int32_t __cdecl application_main_setup_context(void*){ev("004d1a90");return 0;}
std::int32_t __cdecl application_main_game_setup(void*,const char*,std::uint32_t*,std::uint32_t){ev("004d3420");return static_cast<std::int32_t>(fixture_setup_count++?fixture_setup_repeat:fixture_setup_result);}
void __cdecl application_main_setup_finish(void*){ev("004d1ba0");}
void __cdecl application_main_front_end_display(std::uint32_t*){ev("004b4da0");}
void __cdecl application_main_network_poll(std::uint32_t,std::uint32_t){ev("0048dcb0");prepare_network(fixture_network_ready);if(!startup_network_00628c70)startup_network_00628c70=fixture_network;}
void __cdecl application_main_network_wait(std::uint32_t,std::uint32_t,std::uint8_t* state){ev("0048e1a0");*state=0;prepare_network(fixture_network_ready);}
void __cdecl application_main_network_action(std::int32_t a,std::int32_t b){events.emplace_back("0048da60:"+std::to_string(a)+":"+std::to_string(b));}
void __cdecl application_main_function_004dd600(){ev("004dd600");}
void __cdecl application_main_function_004b67b0(){ev("004b67b0");global_00606a88=fixture_tick;}
void __cdecl application_main_function_004b68f0(){ev("004b68f0");}
void __cdecl application_main_function_004a4a70(std::uint32_t){ev("004a4a70");}
void __cdecl application_main_function_004acb80(){ev("004acb80");}
void __cdecl application_main_function_004a88a0(){ev("004a88a0");}
void __cdecl application_main_function_00471b60(){ev("00471b60");}
void __cdecl application_main_function_00414eb0(){ev("00414eb0");}
void __cdecl application_main_function_004640b0(){ev("004640b0");}
void __cdecl application_main_function_00413ea0(){ev("00413ea0");}
void __cdecl application_main_function_004a6e30(){ev("004a6e30");}
void __cdecl application_main_function_0048cdf0(){ev("0048cdf0");}
void __cdecl application_main_function_00425780(){ev("00425780");}
void __cdecl application_main_function_005366e0(std::uint32_t){ev("005366e0");}
void __cdecl application_main_function_004152e0(){ev("004152e0");if(fixture_post_mode)global_006573e8=fixture_post_mode;}
void __cdecl application_main_function_00412030(){ev("00412030");}
void __cdecl application_main_function_0048dad0(){ev("0048dad0");}
void __cdecl application_main_function_0048e6f0(){ev("0048e6f0");}
void __cdecl application_main_function_004a6960(){ev("004a6960");}
void __cdecl application_main_function_00563d30(){ev("00563d30");}
void __cdecl application_main_function_004a54b0(){ev("004a54b0");}
void __cdecl application_main_function_00467740(){ev("00467740");}
void __cdecl application_main_function_004a54e0(){ev("004a54e0");}
void __cdecl application_main_fill_fe_arena_0053c290(std::uint32_t,std::uint32_t,std::uint32_t);
void __cdecl application_main_create_directory(std::uint32_t);
void __cdecl application_main_setup_heaps(std::uint32_t,std::uint32_t);
void __cdecl application_main_log(const char*);
std::int32_t __cdecl application_main_setup_context(void*);
std::int32_t __cdecl application_main_game_setup(void*,const char*,std::uint32_t*,std::uint32_t);
void __cdecl application_main_setup_finish(void*);
void __cdecl application_main_front_end_display(std::uint32_t*);

void __cdecl application_main_function_004b67b0();
void __cdecl render_startup_00467470(){ev("00467470");}
void __cdecl render_display_reconfigure_00467fc0(RenderDisplay*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t){ev("00467fc0");}
}

using namespace porsche;
int main(){
    std::string line;
    while(std::getline(std::cin,line)){
        std::istringstream in(line);std::uint32_t setup,tick,network,enabled,mode,alloc,wait_mode,existing,post_mode,setup_repeat,config_name;
        if(!(in>>setup>>tick>>network>>enabled>>mode>>alloc>>wait_mode>>existing>>post_mode>>setup_repeat>>config_name))return 2;
        events.clear();fixture_setup_result=setup;fixture_setup_repeat=setup_repeat;fixture_setup_count=0;fixture_tick=tick;fixture_fe_mode=mode;fixture_post_mode=post_mode;fixture_network_ready=network?1:0;fixture_alloc_ok=alloc;
        global_006573e8=0;fixture_fe_mode=mode;global_00657424=0;global_00657428=0;global_0065743c=0;
        global_006577d8=17;global_006577dc=19;global_00606a88=0;global_00606874=0;global_005e99f4=0;
        global_00657a60=wait_mode==3?0x100u:static_cast<std::uint32_t>(wait_mode==1);global_00657a64=wait_mode==2;global_00657e34=0;std::memset(global_00657a84,0,sizeof(global_00657a84));if(config_name)std::memcpy(global_00657a84,"LobbyX",7);
        fe_enabled_0065b298=enabled;startup_network_00628c70=nullptr;if(existing){prepare_network(existing>1?1:0);startup_network_00628c70=fixture_network;}render_display_00628130=nullptr;
        int ret=app_main_004b6a50(0,nullptr);
        std::cout<<"{\"ret\":"<<ret<<",\"calls\":[";
        for(std::size_t i=0;i<events.size();++i)std::cout<<(i?",":"")<<'"'<<events[i]<<'"';
        auto* n=static_cast<std::uint8_t*>(startup_network_00628c70);
        std::cout<<"],\"globals\":["<<global_006573e8<<','<<global_00657424<<','<<global_00657428<<','
          <<global_0065743c<<','<<global_006577d8<<','<<global_006577dc<<','<<static_cast<unsigned>(global_00657e34)<<','
          <<static_cast<unsigned>(global_00657a60)<<','<<static_cast<unsigned>(global_00657a64)<<','<<global_00606a88<<','<<global_00606874<<','<<global_005e99f4<<"],\"network\":["
          <<(n?1:0)<<','<<(n?*reinterpret_cast<std::uint32_t*>(n+8):0)<<','<<(n?static_cast<unsigned>(n[0xbc]):0)<<','
          <<(n?static_cast<unsigned>(n[0xbe]):0)<<','<<(n?static_cast<unsigned>(n[0xbf]):0)<<','
          <<(n?static_cast<unsigned>(n[0xc4]):0)<<','<<(n?static_cast<unsigned>(n[0xc5]):0)<<','
          <<(n?*reinterpret_cast<std::int32_t*>(n+0xdc):0)<<"],\"network_name\":\""<<(n?reinterpret_cast<char*>(n+0x59):"")<<"\"}\n";
        startup_network_00628c70=nullptr;
    }
}
