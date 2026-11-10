// New559 scenes reuse the immutable556 ABI/heap/FPU scaffold, and unchanged550
// canonical support sources. No historical556/550 case set is rerun.
#include "../485-network-callback-lifecycle/network_callback_lifecycle_485.hpp"
#include "porsche/exit_registry.hpp"
static B* service_slab;static U service_which,values[5],service_alias,service_pattern,service_mode,service_return,actual_application;
namespace porsche {
// Unexecuted dependencies of unchanged canonical support TUs fail closed.
void* __stdcall platform_create_thread(void*,U,ThreadBootstrap,void*,U,U*){ExitProcess(90);return nullptr;}
U __stdcall platform_thread_priority(void*,I){ExitProcess(90);return 0;}
void __stdcall audio_platform_sleep_455(U){ExitProcess(90);}
void __cdecl audio_thread_mix_0058f8e0(){ExitProcess(90);}
void __cdecl exit_registry_lock_api_005a4ba4(U){ExitProcess(90);}
void __cdecl exit_registry_unlock_api_005a4c05(U){ExitProcess(90);}
U __cdecl exit_registry_allocation_size_005a8161(const void*){ExitProcess(90);return 0;}
void* __cdecl exit_registry_reallocate_005a8029(void*,U){ExitProcess(90);return nullptr;}
void* __cdecl exit_registry_malloc_005a3be5(U){ExitProcess(90);return nullptr;}
void __cdecl exit_registry_fatal_005a2e22(U){ExitProcess(90);}
I __cdecl application_audio_probe_measure_00565890(){ExitProcess(90);return 0;}
I __cdecl audio_device_initialize_ds_0058ebe0(){ExitProcess(90);return 0;}
void __cdecl application_audio_backend_finalize_0058e0e0(){ExitProcess(90);}
void __stdcall platform_initialize_critical_section(void*){ExitProcess(90);}
void __stdcall platform_delete_critical_section(void*){ExitProcess(90);}
void __stdcall platform_enter_critical_section(void*){ExitProcess(90);}
void __stdcall platform_leave_critical_section(void*){ExitProcess(90);}
U __cdecl audio_backend_cpu_features_00597070(){ExitProcess(90);return 0;}
void __stdcall render_display_draw_quad_006bd9a8(const void*,const void*,const void*,const void*){ExitProcess(90);}
void __cdecl audio_mixer_accumulate_3dnow_0059bc40(U,U,U,U){ExitProcess(90);}
void __cdecl audio_mixer_decode_s16_3dnow_0059bb90(U,U,U){ExitProcess(90);}
void __cdecl audio_stream_transform_00597660(U,U){ExitProcess(90);}
void __cdecl network_callbacks_stop_00560380(){ExitProcess(90);}
void __cdecl io_init_00580630(IoList*,U(__cdecl*)(IoNode*,U),U){ExitProcess(90);}
void __cdecl thread_exit_register_00557380(void(__cdecl*)()){ExitProcess(90);}
I __cdecl audio_nibble_loop_continue_0059c690(U,U,U,U,U){ExitProcess(90);return 0;}
void __cdecl audio_nibble_decode_3dnow_0059a730(U){ExitProcess(90);}
void __cdecl audio_adpcm_decode_0059a910(U,U){ExitProcess(90);}
void __cdecl audio_resampler_decode_00597810(U,U,U){ExitProcess(90);}
// This is the ONLY reachable unowned child of the new seven-body packet.
I __cdecl application_audio_stream_create_005673d0(B* descriptor,U a,U b,U c,U d,U e,U f){
    auto& event=before(90,actual_application?0xd35c0000u:ptr(descriptor),a,b,c,d);event.args[5]=e;event.args[6]=f;
    std::memcpy(event.descriptor,descriptor,28);
    if(actual_application)event.descriptor[0x16]=event.descriptor[0x17]=0;
    ++child_calls;
    if(service_mode&1)descriptor[4]^=0x5a;
    if(service_mode&2)store(objects[1],0x88,buffers[3]);
    if(service_mode&4)audio_resource_query_root_00656ab4=objects[1];
    if(service_mode&8){const unsigned short cw=static_cast<unsigned short>(0x7f|(pc<<8)|(((rc+1)%4)<<10));__asm fldcw cw}
    snapshot(event.after);return static_cast<I>(service_return);
}
}
extern "C" I __stdcall DirectSoundCreate(const void*,U*,void*){ExitProcess(90);return 0;}
#pragma comment(linker,"/alternatename:_GetForegroundWindow@0=_unused_foreground_559@0")
#pragma comment(linker,"/alternatename:_GetDesktopWindow@0=_unused_desktop_559@0")
extern "C" void* __stdcall unused_foreground_559(){ExitProcess(90);return nullptr;}
extern "C" void* __stdcall unused_desktop_559(){ExitProcess(90);return nullptr;}
static void init_service(){
    service_slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(service_slab!=nullptr,"service oracle allocation");
    @SERVICE_BODIES@
    @SERVICE_RELOCATIONS@
    // Compose the opposite side with actual raw559 children, not the compiled
    // helpers that were still controlled endpoints in the immutable556 proof.
    wr(slab+0x6a,ptr(service_slab+0x400)-ptr(slab+0x6e));
    wr(slab+0x78,ptr(service_slab)-ptr(slab+0x7c));
    wr(slab+0x9a,ptr(service_slab+0x600)-ptr(slab+0x9e));
    require(FlushInstructionCache(GetCurrentProcess(),slab,4096)!=0,"556 composed instruction cache");
    require(FlushInstructionCache(GetCurrentProcess(),service_slab,4096)!=0,"service instruction cache");
}
static void* service_function(bool cpp,U op){
    if(!cpp)return service_slab+op*0x100;
    switch(op){case 0:return reinterpret_cast<void*>(&application_audio_stream_descriptor_00561960);case 1:return reinterpret_cast<void*>(&audio_stream_record_bytes_005611d0);case 2:return reinterpret_cast<void*>(&audio_stream_storage_bytes_005611e0);case 3:return reinterpret_cast<void*>(&audio_stream_service_bytes_005678a0);case 4:return reinterpret_cast<void*>(&application_audio_stream_estimate_005678c0);case 5:return reinterpret_cast<void*>(&audio_stream_codec_bytes_0056afc0);default:return reinterpret_cast<void*>(&application_audio_stream_begin_00567660);}
}
static void service_execute(bool cpp){
    reset();U args[5];std::memcpy(args,values,sizeof args);actual_application=service_which==7;
    if(service_which==0||service_which==6){
        args[0]=buffers[0]+align_value;
        if(service_alias==1)args[0]=objects[0]+0x6c+align_value;
        if(service_alias==2)args[0]=buffers[1]+align_value;
        for(U i=0;i<32;++i)reinterpret_cast<B*>(args[0])[i]=static_cast<B>(service_pattern+i*37);
    }
    if(service_which==7){
        // Original and compiled556 parents now call the actual559 descriptor,
        // estimate and begin wrappers. Only creator math remains controlled;
        // original caller's opaque two stack bytes retain the frozenPARTIAL seam.
        run_one(cpp,0);captured_return=0;
    }else if(service_which==8){
        args[0]=buffers[0]+align_value;for(U i=0;i<32;++i)reinterpret_cast<B*>(args[0])[i]=static_cast<B>(service_pattern+i*37);
        trace.abi|=invoke(service_function(cpp,0),args,1);
        trace.abi|=invoke(service_function(cpp,6),args,5);
    }else{
        const U argc=service_which==6?5:service_which==5?3:(service_which==3||service_which==4)?2:1;
        trace.abi|=invoke(service_function(cpp,service_which),args,argc);
    }
    snapshot(trace.final);
}
static void service_check(){
    service_execute(false);expected=trace;const U expected_return=captured_return;service_execute(true);
    if(trace.abi||expected.abi||captured_return!=expected_return||std::memcmp(&trace,&expected,sizeof trace)){
        const B* a=reinterpret_cast<const B*>(&trace);const B* b=reinterpret_cast<const B*>(&expected);U off=0;while(off<sizeof trace&&a[off]==b[off])++off;
        std::printf("divergence service case=%u op=%u values=%08x/%08x/%08x/%08x/%08x mode=%u alias=%u align=%u pattern=%u PC=%u RC=%u depth=%u sticky=%x byte=%u bytes=%02x/%02x EAX=%08x/%08x\n",cases,service_which,values[0],values[1],values[2],values[3],values[4],service_mode,service_alias,align_value,service_pattern,pc,rc,depth,sticky,off,off<sizeof trace?a[off]:0,off<sizeof trace?b[off]:0,captured_return,expected_return);std::fflush(stdout);ExitProcess(1);
    }++cases;events_total+=trace.count;
}
int main(){
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);
    require(application_audio_selected_channel_00655d30==0&&audio_resource_query_root_00656ab4==0,"production initial state before scene resets");
    // The borrowed556 oracle slots are initialized here, exactly as its frozen
    // generated fixture, while service helpers occupy their separate slab.
    slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(slab!=nullptr,"556 oracle slab");
    @BORROWED556_BODIES@
    init_service();
    resources=3;channel_bits=0xffffffffu;configuration=1234567;service_return=42;
    const U edges[]={0u,1u,7u,8u,31u,32u,0xffffu,0x7fffffffu,0x80000000u,0xfffffff0u,0xffffffffu};
    for(service_which=1;service_which<6;++service_which)for(U a:edges)for(U b:edges)for(U c:edges){values[0]=a;values[1]=b;values[2]=c;service_check();}
    service_which=0;for(service_pattern=0;service_pattern<256;++service_pattern)for(align_value=0;align_value<4;++align_value)for(service_alias=0;service_alias<3;++service_alias){service_check();}
    service_alias=0;align_value=0;for(service_which=6;service_which<=8;service_which+=2)for(U value:edges)for(service_mode=0;service_mode<16;++service_mode){for(U i=0;i<5;++i)values[i]=value+i*0x1234567u;service_return=value;service_pattern=value;service_check();}
    service_which=7;service_mode=0;effect=0;for(U cfg:{0u,39u,40u,1023u,1024u,0x80000000u,0xffffffffu})for(U ret:{0u,42u,0xffffffffu})for(service_mode=0;service_mode<16;++service_mode){configuration=cfg;service_return=ret;ignored=ret^cfg;service_check();}
    service_mode=0;effect=0;service_pattern=0xa5;configuration=1234567;service_return=42;for(U i=0;i<5;++i)values[i]=0x80000001u+i;
    for(U precision:{0u,2u,3u})for(rc=0;rc<4;++rc)for(U d:{0u,1u,5u,8u})for(U st:{0u,0x25u,0x453fu}){
        pc=precision;depth=d;sticky=st;for(service_which=0;service_which<=8;++service_which)service_check();
    }
    __asm fninit
    std::printf("audio_stream_service_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
