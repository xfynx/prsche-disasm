#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "application_audio_lifecycle_556.hpp"
#include "porsche/heap.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include <cstdio>
#include <cstring>
#include <initializer_list>
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;using namespace porsche;
static B* slab;alignas(64) static B arena[8192];alignas(16)static B floating[512],environment[28];
struct Fpu{unsigned short control,status,tag,pad;B values[80];U mxcsr;};
struct State{B heap[8192];TimedCallbackSlot slots[16];U root,selected,depth,tick,file,line;Fpu fp;};
struct Event{U tag,args[5];B descriptor[28];State before,after;};
struct Trace{U abi,count;Event events[24];State final;};
static Trace trace,expected;static U cases,events_total,which,configuration,ignored,argc_value=2,flags,channel_bits,resources,registered,playing,table_mode,effect,retbits=42,estimate=0x1234,pc=2,rc,depth,sticky,align_value,chain;
static U objects[2],buffers[4],heap_events,child_calls,descriptor_address;static bool setup;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U rd(const void* p){U value;std::memcpy(&value,p,4);return value;}
static void wr(void* p,U value){std::memcpy(p,&value,4);}
static U word(U p,U offset){return rd(reinterpret_cast<void*>(p+offset));}
static void store(U p,U offset,U value){wr(reinterpret_cast<void*>(p+offset),value);}
static void require(bool ok,const char* why){if(!ok){std::printf("divergence lifecycle %s case=%u which=%u\n",why,cases,which);std::fflush(stdout);ExitProcess(1);}}
static LONG WINAPI fault(EXCEPTION_POINTERS* p){std::printf("native-fault %08lx eip=%08lx case=%u which=%u effect=%u\n",p->ExceptionRecord->ExceptionCode,p->ContextRecord->Eip,cases,which,effect);std::fflush(stdout);ExitProcess(98);return EXCEPTION_CONTINUE_SEARCH;}
static void snapshot(State& s){
    __asm fxsave floating
    __asm fnstenv environment
    __asm fldenv environment
    s.fp.control=static_cast<unsigned short>(rd(floating));s.fp.status=static_cast<unsigned short>(rd(floating+2));s.fp.tag=static_cast<unsigned short>(rd(environment+8));s.fp.pad=0;s.fp.mxcsr=rd(floating+24);
    for(U i=0;i<8;++i){std::memcpy(s.fp.values+i*10,floating+32+i*16,10);if((floating[4]&(1u<<(((s.fp.status>>11)+i)&7)))==0)std::memset(s.fp.values+i*10,0,10);}
    std::memcpy(s.heap,arena,sizeof arena);std::memcpy(s.slots,timed_callbacks_0069dd20,sizeof s.slots);s.root=audio_resource_query_root_00656ab4;s.selected=application_audio_selected_channel_00655d30;s.depth=window_scheduler_depth_0069de20;s.tick=current_tick_006b7c40;s.file=class_error_file_005deb74;s.line=class_error_line_005deb78;
}
static Event& before(U tag,U a=0,U b=0,U c=0,U d=0,U e=0){require(trace.count<24,"finite events");auto& item=trace.events[trace.count++];item.tag=tag;item.args[0]=a;item.args[1]=b;item.args[2]=c;item.args[3]=d;item.args[4]=e;snapshot(item.before);return item;}
static void control(){if(effect&8){unsigned short cw=static_cast<unsigned short>(0x7f|(pc<<8)|(((rc+child_calls)%4)<<10));__asm fldcw cw}}
namespace porsche {
// Unexecuted references of the canonical window-runtime owner TU fail closed.
I __stdcall window_get_system_metrics(I){ExitProcess(90);return 0;}
U __stdcall window_adjust_rect(WindowRect*,U,I,U){ExitProcess(90);return 0;}
void* __stdcall window_create_ex(U,const char*,const char*,U,I,I,I,I,void*,void*,void*,void*){ExitProcess(90);return nullptr;}
void* __stdcall window_set_cursor(void*){ExitProcess(90);return nullptr;}
I __stdcall window_show_cursor(I){ExitProcess(90);return 0;}
void __cdecl window_channel_005739b0(U,U){ExitProcess(90);}
// Four real stream-provider seams. Their algorithms remain unresolved in game.
U __cdecl application_audio_stream_estimate_005678c0(U a,U b){auto& e=before(10,a,b);++child_calls;if(effect&1)audio_resource_query_root_00656ab4=objects[1];control();snapshot(e.after);return estimate;}
I __cdecl application_audio_stream_descriptor_00561960(B* p){descriptor_address=ptr(p);auto& e=before(20,0xd35c0000u);++child_calls;
    // Original561960 leaves0x16..0x17 unwritten. Preserve them; this PARTIAL proof
    // masks only these two opaque caller-stack bytes before comparing arguments.
    for(U i=0;i<28;++i)if(i!=0x16&&i!=0x17)p[i]=static_cast<B>(i*17+3);
    if(effect&2)audio_resource_query_root_00656ab4=objects[1];control();snapshot(e.after);return static_cast<I>(0x87654321u);
}
I __cdecl application_audio_stream_begin_00567660(B* p,U a,U b,U c,U d){require(ptr(p)==descriptor_address,"descriptor identity across calls");auto& e=before(30,0xd35c0000u,a,b,c,d);std::memcpy(e.descriptor,p,28);e.descriptor[0x16]=e.descriptor[0x17]=0;++child_calls;if(effect&4)audio_resource_query_root_00656ab4=objects[1];control();snapshot(e.after);return static_cast<I>(retbits);}
I __cdecl application_audio_stream_stop_00567690(U channel){auto& e=before(40,channel);++child_calls;if(effect&1)audio_resource_query_root_00656ab4=objects[1];if(effect&2)store(audio_resource_query_root_00656ab4,0x88,buffers[3]);control();snapshot(e.after);return static_cast<I>(retbits);}
U __cdecl application_audio_service_callback_004ad9c0(U,U){ExitProcess(90);return 0;}
void __cdecl window_scheduler_diagnostic_00565340(const char* message){auto& e=before(50,ptr(message));++child_calls;if(effect&4)audio_resource_query_root_00656ab4=objects[1];control();snapshot(e.after);}
void __cdecl heap_enter_005322b0(void*){if(setup)return;auto& e=before(60);++heap_events;if((effect&32)&&heap_events==1)store(audio_resource_query_root_00656ab4,0x88,buffers[3]);snapshot(e.after);}
void __cdecl heap_leave_005322c0(void*){if(setup)return;auto& e=before(70);if((effect&16)&&heap_events==1)audio_resource_query_root_00656ab4=objects[1];control();snapshot(e.after);}
void* __cdecl heap_lock_create_005321f0(){return reinterpret_cast<void*>(1);}
void __cdecl heap_format_005a0fbf(char* out,const char* format,const char* name){std::snprintf(out,256,format,name);}
void __cdecl heap_fill_0053c290(void* p,U value,U bytes){std::memset(p,static_cast<int>(value&255),bytes);}
void __cdecl heap_copy_005b0100(void*,const void*,U){ExitProcess(90);}
void __cdecl heap_copy_005b02c0(void*,const void*,U){ExitProcess(90);}
void __cdecl heap_copy_005b0480(void*,const void*,U){ExitProcess(90);}
I __cdecl audio_channel_stop_00565d60(U){ExitProcess(90);return 0;}
}
static U __cdecl idle(U,U){ExitProcess(90);return 0;}
static void seed(){
    unsigned short cw=static_cast<unsigned short>(0x7f|(pc<<8)|(rc<<10));__asm fninit __asm fldcw cw
    __asm fxsave floating
    const U top=(8-depth)&7;const unsigned short sw=static_cast<unsigned short>((top<<11)|sticky);std::memcpy(floating+2,&sw,2);floating[4]=0;
    for(U i=0;i<depth;++i){floating[4]|=static_cast<B>(1u<<((top+i)&7));wr(floating+32+i*16,0x10203041+i);wr(floating+36+i*16,0x87654321+i);const unsigned short exp=static_cast<unsigned short>(0x3fff+i);std::memcpy(floating+40+i*16,&exp,2);}
    __asm fxrstor floating
}
static void reset(){
    __asm fninit
    setup=true;trace={};child_calls=heap_events=descriptor_address=0;std::memset(arena,0x69,sizeof arena);for(auto& p:heaps_006b4f20)p=nullptr;
    const auto result=heap_init_005697f0(0,"556",arena,sizeof arena,8,8,0,0,0,0,0,nullptr);require(result>2000,"canonical heap initialized");
    for(U i=0;i<2;++i){const U base=ptr(allocate_00531ca0(nullptr,0xb0+4,0));objects[i]=base+align_value;std::memset(reinterpret_cast<void*>(objects[i]),0xa5,0xb0);}
    for(U i=0;i<4;++i){buffers[i]=ptr(allocate_00531ca0(nullptr,64,0));require(buffers[i]!=0,"canonical buffers");}
    for(U i=0;i<2;++i){store(objects[i],0x70,i==0?channel_bits:7);store(objects[i],0x78,registered);store(objects[i],0x7c,playing);store(objects[i],0x84,0x12131415+i);store(objects[i],0x6c,(resources&1)?buffers[i*2]:0);store(objects[i],0x88,(resources&2)?buffers[i*2+1]:0);}
    audio_resource_query_root_00656ab4=(flags&1)?0:objects[0];application_audio_selected_channel_00655d30=0xdeadbeef;
    std::memset(timed_callbacks_0069dd20,0,sizeof timed_callbacks_0069dd20);window_scheduler_depth_0069de20=0;current_tick_006b7c40=0xfffffff8;class_error_file_005deb74=0x12345678;class_error_line_005deb78=0x87654321;
    if(table_mode==1){timed_callbacks_0069dd20[3].callback=application_audio_service_callback_004ad9c0;timed_callbacks_0069dd20[8].callback=application_audio_service_callback_004ad9c0;}
    if(table_mode==2)for(auto& s:timed_callbacks_0069dd20)s={idle,17,29,3};
    heaps_006b4f20[0]->lock=reinterpret_cast<void*>(1);setup=false;seed();
}
static U invoke(void* fn,const U* args,U argc){U saved_sp,saved_frame,fail=0;__asm{
    push ebx
    push esi
    push edi
    mov saved_sp,esp
    mov saved_frame,ebp
    mov ecx,argc
    mov eax,args
    test ecx,ecx
    je call_target
push_args:dec ecx
    push dword ptr [eax+ecx*4]
    test ecx,ecx
    jne push_args
call_target:mov ebx,13579bdfh
    mov esi,2468ace0h
    mov edi,10203040h
    call fn
    mov eax,argc
    lea esp,[esp+eax*4]
    cmp esp,saved_sp
    jne bad
    cmp ebp,saved_frame
    jne bad
    cmp ebx,13579bdfh
    jne bad
    cmp esi,2468ace0h
    jne bad
    cmp edi,10203040h
    je done
bad:mov fail,1
done:mov esp,saved_sp
    pop edi
    pop esi
    pop ebx
    }return fail;}
static void run_one(bool cpp,U item){const U args[2]={configuration,ignored};void* function=cpp?(item==0?reinterpret_cast<void*>(&application_audio_transition_configure_004ae010):item==1?reinterpret_cast<void*>(&application_audio_probe_prepare_004ae2b0):reinterpret_cast<void*>(&application_audio_shutdown_device_004ae310)):slab+(item==0?0:item==1?0x100:0x200);trace.abi|=invoke(function,args,item==0?argc_value:0);}
static void execute(bool cpp){reset();run_one(cpp,which);if(chain){run_one(cpp,1);if(chain==2)run_one(cpp,2);}snapshot(trace.final);}
static void check(){
    execute(false);expected=trace;execute(true);
    if(trace.abi||expected.abi||std::memcmp(&trace,&expected,sizeof trace)){
        const B* a=reinterpret_cast<const B*>(&trace);const B* b=reinterpret_cast<const B*>(&expected);U off=0;while(off<sizeof trace&&a[off]==b[off])++off;
        std::printf("divergence lifecycle case=%u which=%u cfg=%08x channel=%08x registered=%u playing=%u resources=%u effect=%u table=%u flags=%u align=%u PC=%u RC=%u depth=%u sticky=%x chain=%u byte=%u values=%02x/%02x events=%u/%u\n",cases,which,configuration,channel_bits,registered,playing,resources,effect,table_mode,flags,align_value,pc,rc,depth,sticky,chain,off,off<sizeof trace?a[off]:0,off<sizeof trace?b[off]:0,trace.count,expected.count);std::fflush(stdout);ExitProcess(1);
    }++cases;events_total+=trace.count;
}
int main(){
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);
    require(application_audio_selected_channel_00655d30==0&&audio_resource_query_root_00656ab4==0,"new/canonical production loaderzero state before reset");
    slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(slab!=nullptr,"raw bodies allocation");
    @ORIGINAL_BODIES@
    @ORIGINAL_RELOCATIONS@
    require(FlushInstructionCache(GetCurrentProcess(),slab,4096)!=0,"raw cache");
    for(which=0;which<3;++which)for(U ch:{0u,1u,0x7fffffffu,0x80000000u,0xffffffffu})for(registered=0;registered<2;++registered)for(playing=0;playing<2;++playing)for(resources=0;resources<4;++resources)for(table_mode=0;table_mode<3;++table_mode){channel_bits=ch;configuration=1234567;check();}
    which=0;registered=playing=0;resources=3;channel_bits=0xffffffffu;table_mode=0;
    for(U cfg:{0u,1u,39u,40u,41u,99u,100u,101u,1023u,1024u,1025u,0x7fffffffu,0x80000000u,0xffffffffu,0xfffffc01u})for(U rv:{0u,42u,0xffffffffu})for(U est:{0u,0x1234u,0xffffffffu})for(U ac:{1u,2u}){configuration=cfg;retbits=rv;estimate=est;argc_value=ac;ignored=cases*0x1234567u;check();}
    argc_value=2;configuration=0x80000000;estimate=0xffffffff;retbits=0x7fffffff;resources=3;channel_bits=0xffffffffu;
    for(which=0;which<3;++which)for(effect=0;effect<64;++effect){channel_bits=which==0?0xffffffffu:42u;align_value=0;registered=1;table_mode=effect&1?2:1;check();}
    effect=table_mode=registered=0;resources=3;channel_bits=0xffffffffu;configuration=1234567;which=0;
    for(U precision:{0u,2u,3u})for(rc=0;rc<4;++rc)for(U d:{0u,1u,5u,7u})for(U st:{0u,0x25u,0x453fu}){pc=precision;depth=d;sticky=st;effect=8;check();}
    pc=2;rc=depth=sticky=effect=0;configuration=1024;retbits=42;channel_bits=0xffffffffu;
    for(which=0;which<3;++which)for(flags=0;flags<2;++flags)for(align_value=0;align_value<4;++align_value){if(which==2&&align_value)continue;check();}
    flags=align_value=0;which=0;for(chain=1;chain<3;++chain){check();}
    __asm fninit
    std::printf("application_audio_lifecycle_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
