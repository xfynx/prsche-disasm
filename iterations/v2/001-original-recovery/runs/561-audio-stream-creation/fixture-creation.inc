// Draft shared-fixture continuation. The raw bodies are relocated only in the
// oracle slab. Canonical state and accepted 508/559 providers are shared.
#include "../485-network-callback-lifecycle/network_callback_lifecycle_485.hpp"
#include "porsche/exit_registry.hpp"
static B* creation_slab;
static U scenario, variant, index_value, selected_slot, codec_result;
namespace porsche {
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
void __stdcall platform_enter_critical_section(void*){}
void __stdcall platform_leave_critical_section(void*){}
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
U __cdecl audio_stream_codec_create_0056aff0(U a,U b,U c,U d,U e){auto& x=before(101,a,b,c,d,e);snapshot(x.after);return codec_result;}
I __cdecl audio_stream_codec_frames_0056c840(U a){auto& x=before(102,a);snapshot(x.after);return 12;}
I __cdecl audio_stream_codec_set_005912e0(U a,I b){auto& x=before(103,a,static_cast<U>(b));snapshot(x.after);return 0;}
void __cdecl audio_stream_codec_reset_0056c420(U a){auto& x=before(104,a);snapshot(x.after);}
void __cdecl audio_stream_codec_destroy_0056b3b0(U a){auto& x=before(105,a);snapshot(x.after);}
void __cdecl audio_stream_service_release_00566e10(U){ExitProcess(90);}
void __cdecl audio_stream_service_consumed_00566e40(U,U){ExitProcess(90);}
void __cdecl audio_stream_service_tick_00567270(){ExitProcess(90);}
}
extern "C" I __stdcall DirectSoundCreate(const void*,U*,void*){ExitProcess(90);return 0;}
#pragma comment(linker,"/alternatename:_GetForegroundWindow@0=_unused_foreground_561@0")
#pragma comment(linker,"/alternatename:_GetDesktopWindow@0=_unused_desktop_561@0")
extern "C" void* __stdcall unused_foreground_561(){ExitProcess(90);return nullptr;}
extern "C" void* __stdcall unused_desktop_561(){ExitProcess(90);return nullptr;}
static void init_creation(){
 creation_slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));
 require(creation_slab!=nullptr,"creation slab");
 @CREATION_BODIES@
 @CREATION_RELOCATIONS@
 require(FlushInstructionCache(GetCurrentProcess(),creation_slab,4096)!=0,"creation cache");
}
static void init_creation_state(){
 std::memset(&audio_stream_service_storage_006b7740,0,80);
 std::memset(creation_areas,0,sizeof creation_areas);std::memset(creation_pool,0,sizeof creation_pool);
 for(U i=0;i<64;++i)creation_descriptor[i]=static_cast<B>(0x31+i*13);
 std::memset(application_audio_device_state_006b48c0.preceding_data(),0,0x18c);
 std::memset(audio_stream_slots_006b7cc0,0,sizeof audio_stream_slots_006b7cc0);
 if(variant&4)for(auto& slot:audio_stream_slots_006b7cc0)slot=1;
 application_audio_device_state_006b48c0[0xdc]=(variant&1)?0:1;
 for(U i=0;i<selected_slot&&i<16;++i)audio_stream_service_storage_006b7740.slots[i]=ptr(creation_areas[1]);
 codec_result=0x10203040;
}
static void execute_creation(bool cpp){
 reset();init_creation_state();U args[7]={};void* fn=nullptr;U argc=0;
 switch(scenario){
 case 0:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_lookup_00566d60):creation_slab+0x400;args[0]=index_value;argc=1;break;
 case 1:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_count_005673b0):creation_slab+0x500;break;
 case 2:fn=cpp?reinterpret_cast<void*>(&application_audio_stream_create_005673d0):creation_slab;args[0]=ptr(creation_descriptor);args[1]=2;args[2]=256;args[3]=ptr(creation_areas[0]);args[4]=4096;args[5]=codec_result;args[6]=(variant&2)?1:0;argc=7;break;
 case 3:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_register_0058ff50):creation_slab+0x700;args[0]=0x12345678;argc=1;break;
 case 4:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_unregister_0058ff70):creation_slab+0x800;args[0]=0x12345678;argc=1;break;
 case 5:fn=cpp?reinterpret_cast<void*>(&application_audio_stream_stop_00567690):creation_slab+0x200;args[0]=index_value;argc=1;break;
 case 6:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_reset_00567740):creation_slab+0x300;args[0]=index_value;argc=1;break;
 case 7:fn=cpp?reinterpret_cast<void*>(&audio_stream_service_shutdown_00566d40):creation_slab+0x600;break;
 default:ExitProcess(91);
 }
 if(scenario==3||scenario==4){application_audio_device_state_006b48c0[0xe1]=static_cast<B>(index_value);for(U i=0;i<index_value&&i<16;++i)wr(application_audio_device_state_006b48c0.data()+0x108+i*4,(i==selected_slot)?0x12345678:0x99880000+i);}
 if(scenario==5||scenario==6){
   const U object=ptr(creation_areas[0]);audio_stream_service_storage_006b7740.slots[0]=object;
   store(object,8,0xffffffffu);store(object,0xc,0);store(object,4,codec_result);
   std::memset(reinterpret_cast<B*>(object)+0x34,0xa5,0x54);
   reinterpret_cast<B*>(object)[0x18]=(variant&2)?1:0;
   audio_stream_slots_006b7cc0[0]=ptr(creation_areas[1]);
   application_audio_device_state_006b48c0[0xe1]=1;
   wr(application_audio_device_state_006b48c0.data()+0x108,ptr(reinterpret_cast<void*>(&audio_stream_service_tick_00567270)));
   if(scenario==6&&(variant&4)){
     const U pool=ptr(creation_pool),base=ptr(creation_areas[1]),entry=pool+128;
     audio_backend_pool_006b4a18=pool;store(pool,0,base);store(pool,4,entry);store(pool,0xc,200);store(pool,0x14,0xfffffffeu);
     store(entry,0,100);store(entry,4,16);store(entry-8,0,200);store(entry-8,4,16);
     store(object,0x9c,base+100);store(object,0xa0,base+200);reinterpret_cast<B*>(object)[0x32]=2;
   }
 }
 if(scenario==7){
   for(U i=0;i<16;++i){const U object=ptr(creation_areas[0])+i*256;audio_stream_service_storage_006b7740.slots[i]=object;store(object,8,0xffffffffu);store(object,0xc,i);reinterpret_cast<B*>(object)[0x18]=1;audio_stream_slots_006b7cc0[i]=ptr(creation_areas[1])+i*64;}
   application_audio_device_state_006b48c0[0xe1]=1;
   wr(application_audio_device_state_006b48c0.data()+0x108,ptr(reinterpret_cast<void*>(&audio_stream_service_tick_00567270)));
 }
 trace.abi|=invoke(fn,args,argc);snapshot(trace.final);
}
static void check_creation(){
 execute_creation(false);expected=trace;U old=captured_return;execute_creation(true);
 if(trace.abi||expected.abi||std::memcmp(&trace,&expected,sizeof trace)||captured_return!=old){std::printf("divergence creation case=%u scenario=%u variant=%u slot=%u index=%u eax=%08x/%08x\n",cases,scenario,variant,selected_slot,index_value,captured_return,old);std::fflush(stdout);ExitProcess(1);}++cases;events_total+=trace.count;
}
int main(){
 SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);
 const B* initial=reinterpret_cast<const B*>(&audio_stream_service_storage_006b7740);for(U i=0;i<80;++i)require(initial[i]==0,"loader zero");
 require(ptr(initial)<0x7fffffc0u,"signed slot address domain");
 init_creation();
 for(scenario=0;scenario<=1;++scenario)for(selected_slot=0;selected_slot<=16;++selected_slot)for(U value: {0u,1u,15u,16u,0xffffffffu,0x80000000u}){index_value=value;check_creation();}
 scenario=2;for(variant=0;variant<8;++variant)for(selected_slot=0;selected_slot<=16;++selected_slot)check_creation();
 for(scenario=3;scenario<=4;++scenario)for(index_value=0;index_value<=15;++index_value)for(selected_slot=0;selected_slot<=index_value;++selected_slot)check_creation();
 for(scenario=5;scenario<=6;++scenario)for(variant=0;variant<8;++variant)for(selected_slot=0;selected_slot<=1;++selected_slot)for(U value: {0u,1u,15u,16u,0xffffffffu}){index_value=value;check_creation();}
 scenario=7;variant=0;selected_slot=0;index_value=0;check_creation();
 variant=0;selected_slot=0;index_value=0;
 for(U precision: {0u,2u,3u})for(rc=0;rc<4;++rc)for(U d: {0u,1u,5u,8u})for(U st: {0u,0x25u,0x453fu}){pc=precision;depth=d;sticky=st;for(scenario=0;scenario<=6;++scenario)check_creation();}
 std::printf("audio_stream_creation_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
