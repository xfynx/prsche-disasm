#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include "render_resource_allocation_546.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/application_heap_state.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_device.hpp"
#include "porsche/process_exit.hpp"
using U=std::uint32_t;using S=std::int32_t;using B=std::uint8_t;using namespace porsche;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U word(const void* p,U o=0){U v;memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
static void put(void* p,U o,U v){memcpy(static_cast<B*>(p)+o,&v,4);}
namespace porsche {B render_texture_slots_006a33f8[1536]{};U render_texture_count_006a3a40=0;U render_thrash_exports_006bd910[43]{};}
static U cases,events_total,kind,edits,offset,value,precision,rounding,depth,initial_status;
static U scene,failures,initial_arena,initial_capacity,occupied,match_mode,input_width,input_format,input_formatB,input_flags,sentinel_mode;
static U api_calls,allocation_calls,fill_calls,guard_mode;static bool cpp_side;
static B* code[10];static B* raw_slots;static B* raw_pages;static U alloc_target,free_target,raw_jump[13];
static B raw_table[280];static void* protected_page;static DWORD protected_old;
alignas(16) static B floating[512];
struct Arena {B storage[2][96],node[96],header[96];};static Arena arena;
static B* slots(){return cpp_side?render_texture_slots_006a33f8:raw_slots;}
static U sentinel(){return cpp_side?render_texture_width_sentinel_006a3a08:word(raw_slots,1552);}
static U identity(U p){
    if(p>=ptr(raw_slots)&&p<ptr(raw_slots)+1536)return 0x6a33f8+p-ptr(raw_slots);
    if(p>=ptr(render_texture_slots_006a33f8)&&p<ptr(render_texture_slots_006a33f8)+1536)return 0x6a33f8+p-ptr(render_texture_slots_006a33f8);
    if(p==ptr(const_cast<U*>(&render_texture_width_sentinel_006a3a08))||p==ptr(raw_slots)+1552)return 0x6a3a08;
    return p;
}
struct Fpu {unsigned short control,status;B tag,padding[3],values[80];};
struct State {Arena arena;B slots[1536];U globals[9],api_calls,allocation_calls,fill_calls;};
struct Event {U tag,argc,args[12];State state;Fpu fpu;};
struct Trace {U count,result,abi,completed,exception[3];Event events[128];State final;Fpu fpu;};
static Trace trace,expected;
static void require(bool ok,const char* s){if(!ok){printf("divergence %s case=%u kind=%u edits=%x scene=%u failures=%u capacity=%x occupied=%u match=%u format=%x flags=%x sentinel=%u cpp=%u\n",s,cases,kind,edits,scene,failures,initial_capacity,occupied,match_mode,input_format,input_flags,sentinel_mode,cpp_side);fflush(stdout);ExitProcess(1);}}
static void snapshot(State& s){s.arena=arena;memcpy(s.slots,slots(),1536);const U g[]={render_texture_slot_count_006a3a44,render_texture_dirty_006a3a48,render_texture_pending_006a3a58,render_texture_arena_006a3a5c,render_texture_heap_id_006a3a60,render_texture_epoch_006a3a64,render_texture_count_006a3a40,render_texture_preferred_bytes_005df2c4,sentinel()};memcpy(s.globals,g,sizeof g);s.api_calls=api_calls;s.allocation_calls=allocation_calls;s.fill_calls=fill_calls;}
@ABI_X87_HELPERS@
static void event(U tag,std::initializer_list<U> args){require(trace.count<128,"finite event bound");auto& e=trace.events[trace.count++];e.tag=tag;e.argc=static_cast<U>(args.size());U i=0;for(U a:args)e.args[i++]=identity(a);while(i<12)e.args[i++]=0;snapshot(e.state);capture(e.fpu);}
static void control(){if(edits&32){unsigned short cw=static_cast<unsigned short>(0x7f|((precision==0?3u:0u)<<8)|(((rounding+1)%4)<<10));__asm fldcw cw}}
static void unprotect(){if(protected_page){DWORD old;VirtualProtect(protected_page,4096,protected_old,&old);protected_page=nullptr;}}
static int record_exception(EXCEPTION_POINTERS* e){
    const U code=e->ExceptionRecord->ExceptionCode,access=static_cast<U>(e->ExceptionRecord->ExceptionInformation[0]),address=static_cast<U>(e->ExceptionRecord->ExceptionInformation[1]);
    unprotect();trace.exception[0]=code;trace.exception[1]=e->ExceptionRecord->NumberParameters?access:0;trace.exception[2]=e->ExceptionRecord->NumberParameters>1?identity(address):0;return EXCEPTION_EXECUTE_HANDLER;
}
static U __stdcall treset(){event(0x6bd988,{});if(edits&1){render_texture_slot_count_006a3a44=2;render_texture_pending_006a3a58=value^0x351;render_texture_epoch_006a3a64=value^0xa5a5a5a5;}control();return value;}
namespace porsche {
// Unexecuted521 endpoints/data, same fixture views as accepted540. The admitted
// composition calls only its canonical556880 body; no platform startup is proved.
B cursor_snapshot_prefix_005de650[12]{},cursor_snapshot_suffix_005de65e[30]{};
void* window_shutdown_handle_0069dd18=nullptr;U window_shutdown_state_005de67c=0,window_shutdown_config_005de620[12]{},splash_progress_format_005dead0=0;
B window_shutdown_source_005de65c=0,window_shutdown_source_005de65d=0;
void* __cdecl render_descriptor_allocate_00535700(U,U,U,U,U){require(false,"unexecuted521 allocate");return nullptr;}
void __stdcall window_shutdown_display_callback_006bd9b0(U){require(false,"unexecuted521 display");}
void __cdecl window_shutdown_runtime_state_00534430(){require(false,"unexecuted521 shutdown");}
void __cdecl heap_fill_0053c290(void* p,U byte,U bytes){event(0x53c290,{ptr(p),byte,bytes});require(byte==0&&(bytes==48||bytes==56),"clear transport");
    if(!p){RaiseException(0xe0546002,0,0,nullptr);return;}
    require((bytes==48&&ptr(p)>=ptr(slots())&&ptr(p)+48<=ptr(slots())+1536)||(bytes==56&&p==arena.node+offset),"bounded fill destination");
    memset(p,static_cast<int>(byte),bytes);++fill_calls;
    if(edits&2){render_texture_slot_count_006a3a44=2;render_texture_arena_006a3a5c=ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x22222222;}
    control();
}
U __cdecl application_heap_destroy_005699f0(U id){event(0x5699f0,{id});if(edits&4){render_texture_arena_006a3a5c=scene&1?0:ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x44444444;}control();return value;}
U __stdcall platform_virtual_free(void* p,U size,U mode){event(0x5b2148,{ptr(p),size,mode});require(size==0&&mode==0x8000,"release arguments");if(edits&8){render_texture_arena_006a3a5c=ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x88888888;}control();return scene&1?0:1;}
void* __stdcall platform_virtual_alloc(void* p,U bytes,U mode,U protection){event(0x5b2144,{ptr(p),bytes,mode,protection});require(!p&&mode==0x1000&&protection==4,"VirtualAlloc ABI/flags");++api_calls;
    if(edits&8){render_texture_preferred_bytes_005df2c4=value^0x888;render_texture_arena_006a3a5c=ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x12345678;}
    control();return api_calls<=failures?nullptr:arena.storage[0]+offset;
}
U __cdecl application_heap_slot_00569a70(){event(0x569a70,{});if(edits&16){render_texture_preferred_bytes_005df2c4=value;render_texture_arena_006a3a5c=scene&1?0:ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x16161616;}control();return value^0x12345;}
S __cdecl heap_init_005697f0(U id,const char* name,void* p,S bytes,U q,U alignment,S a,S b,U c,S d,S e,void* callback){
    require(name==render_texture_heap_name_005bbfdc,"DTEX pointer identity");event(0x5697f0,{id,ptr(name),ptr(p),static_cast<U>(bytes),q,alignment,static_cast<U>(a),static_cast<U>(b),c,static_cast<U>(d),static_cast<U>(e),ptr(callback)});
    require(q==64&&alignment==64&&a==0&&b==0&&c==0&&d==0&&e==0&&!callback,"twelve heap-init arguments");
    if(edits&64){render_texture_preferred_bytes_005df2c4=value^0x64646464;render_texture_arena_006a3a5c=scene&1?0:ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value;}
    control();return scene&1?0:-1;
}
void* __cdecl allocate_00531ca0(const char* name,S bytes,U id){event(0x531ca0,{ptr(name),static_cast<U>(bytes),id});++allocation_calls;if(edits&64){render_texture_heap_id_006a3a60=value^0x6400;render_texture_arena_006a3a5c=0;render_texture_preferred_bytes_005df2c4=value^0x64;}control();return scene&2?nullptr:arena.node+offset;}
void __cdecl render_texture_diagnostic_0055ec50(U channel,const char* message,...){require(message==render_texture_capacity_message_005bc208,"capacity message pointer");event(0x55ec50,{channel,ptr(message)});if(edits&128){render_texture_slot_count_006a3a44=value;put(slots(),0,value^0x128);}control();}
[[noreturn]] void __cdecl process_exit_005a246e(U status){event(0x5a246e,{status});RaiseException(0xe0546001,0,0,nullptr);ExitProcess(2);}
}
@RELOCATORS@
static void init(){
    require(render_texture_preferred_bytes_005df2c4==0xc00000&&render_texture_width_sentinel_006a3a08==0,"production initialized capacity/sentinel");
    static const B table_initial[]={@FORMAT_DATA@};static const B jump_initial[]={@JUMP_DATA@};
    static const B heap_name_initial[]={@HEAP_NAME@},capacity_message_initial[]={@CAPACITY_MESSAGE@};
    require(memcmp(render_texture_heap_name_005bbfdc,heap_name_initial,5)==0&&memcmp(render_texture_capacity_message_005bc208,capacity_message_initial,138)==0,"raw original string bytes");
    for(U i=0;i<14;++i)require(render_texture_format_bits_005df16c[i]==word(table_initial,i*20),"raw original sparse format DWORD");
    memcpy(raw_table,table_initial,280);raw_pages=static_cast<B*>(VirtualAlloc(nullptr,12288,0x3000,0x04));require(raw_pages!=nullptr,"raw slot transport allocation");raw_slots=raw_pages+4096-1552;
    @RAW_BODIES@
    for(U i=0;i<13;++i)raw_jump[i]=ptr(code[9])+word(jump_initial,i*4)-0x556880;
    alloc_target=ptr(reinterpret_cast<void*>(&platform_virtual_alloc));free_target=ptr(reinterpret_cast<void*>(&platform_virtual_free));
    @BODY_RELOCATIONS@
    for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"instruction cache");
}
static void reset(){trace={};api_calls=allocation_calls=fill_calls=0;protected_page=nullptr;memset(&arena,0x69+(value&7),sizeof arena);memset(raw_slots,0x53,1572);memset(render_texture_slots_006a33f8,0x53,1536);
    for(U i=0;i<32;++i){B* record=slots()+i*48;for(U j=0;j<48;j+=4)put(record,j,value^(i*0x1020304u+j));put(record,0x24,0);put(record,0x10,i<occupied?input_width:0);
        put(record,8,match_mode==1||match_mode==2?input_format:input_format+1);put(record,0xc,input_formatB);put(record,4,input_flags);
        if(match_mode==2&&i+1!=occupied&&i!=0)put(record,0xc,input_formatB^1);
    }
    render_texture_width_sentinel_006a3a08=sentinel_mode==1?1:sentinel_mode==2?0x80000000:0;put(raw_slots,1552,render_texture_width_sentinel_006a3a08);
    render_texture_preferred_bytes_005df2c4=initial_capacity;render_texture_slot_count_006a3a44=value;render_texture_dirty_006a3a48=scene&1;render_texture_pending_006a3a58=value^0x33333333;render_texture_epoch_006a3a64=value;render_texture_count_006a3a40=value^0x4040;render_texture_heap_id_006a3a60=value;render_texture_arena_006a3a5c=initial_arena?ptr(arena.storage[0]+offset):0;
    for(U& x:render_thrash_exports_006bd910)x=0;render_thrash_exports_006bd910[30]=ptr(reinterpret_cast<void*>(&treset));
    // Reset loops use a small admitted count, independent of the slot scan cases.
    if(kind<4)render_texture_slot_count_006a3a44=2;
}
static void arm_sentinel(){if(!guard_mode)return;void* address=cpp_side?reinterpret_cast<void*>(ptr(const_cast<U*>(&render_texture_width_sentinel_006a3a08))):raw_slots+1552;protected_page=reinterpret_cast<void*>(ptr(address)&~4095u);require(VirtualProtect(protected_page,4096,PAGE_NOACCESS,&protected_old)!=0,"protect sentinel page");}
static void compare(){for(U side=0;side<2;++side){cpp_side=side!=0;reset();seed_fpu();
    void* production[]={reinterpret_cast<void*>(&render_display_texture_reserve_00553fc0),reinterpret_cast<void*>(&render_texture_lazy_reserve_00554b50),reinterpret_cast<void*>(&render_texture_bytes_00554b20),reinterpret_cast<void*>(&render_texture_node_00554b90),reinterpret_cast<void*>(&render_texture_header_00554ad0),reinterpret_cast<void*>(&render_texture_slot_00554bd0)};
    U args[5]={0},count=0;
    if(kind==0){args[0]=input_width;count=1;}
    else if(kind==2){args[0]=input_width;args[1]=ptr(render_texture_heap_name_005bbfdc);count=2;}
    else if(kind==3){args[0]=ptr(render_texture_heap_name_005bbfdc);count=1;}
    else if(kind==4){args[0]=ptr(arena.header+offset);args[1]=input_width;args[2]=input_formatB;args[3]=input_format;args[4]=input_flags;count=5;}
    else if(kind==5){args[0]=input_width;args[1]=input_format;args[2]=input_formatB;args[3]=input_flags;count=4;}
    void* fn=side?production[kind]:code[kind];U result=0;arm_sentinel();
    trace.completed=1;__try{trace.abi=invoke(fn,nullptr,args,count,count*4,result);}__except(record_exception(GetExceptionInformation())){trace.completed=0;}
    unprotect();if(trace.completed){require(trace.abi==0,"cdecl stack/nonvolatile ABI");trace.result=kind==4?0:result;}snapshot(trace.final);capture(trace.fpu);
    if(guard_mode){require(!trace.completed&&trace.exception[0]==EXCEPTION_ACCESS_VIOLATION&&trace.exception[1]==0&&trace.exception[2]==0x6a3a08,"sentinel read occurs before capacity/match return");require(trace.count==0,"sentinel fault precedes diagnostics");}
    if(!side)expected=trace;else{
        require(trace.count==expected.count&&trace.result==expected.result&&trace.completed==expected.completed,"return/exception/events");
        require(memcmp(trace.exception,expected.exception,sizeof trace.exception)==0,"exception transport");
        for(U i=0;i<trace.count;++i)require(memcmp(&trace.events[i],&expected.events[i],sizeof(Event))==0,"event arguments/intermediate state/x87");
        require(memcmp(&trace.final,&expected.final,sizeof(State))==0,"final data bytes");require(memcmp(&trace.fpu,&expected.fpu,sizeof(Fpu))==0,"final x87");events_total+=trace.count;
    }}++cases;
}
static void execute_case(){precision=cases%3==0?0:cases%3==1?2:3;rounding=cases%4;depth=(cases/12)%3*3;initial_status=cases&1?0x3f:0;value=cases%4==0?0:cases%4==1?0xffffffff:cases%4==2?0x80000000:0x12345678;compare();}
int main(){init();const U capacities[]={0,0x40000,0x80000,0x80001,0xc0000,0x100000,0x80000000,0xffffffff};const U controls[]={0,1,2,4,8,16,32,64};
    occupied=2;input_width=0x1800000;input_format=4;input_formatB=5;input_flags=2;match_mode=0;guard_mode=sentinel_mode=0;
    for(kind=0;kind<4;++kind)for(U capacity:capacities)for(U failure:{0u,1u,3u,100u})for(initial_arena=0;initial_arena<2;++initial_arena)for(U edit:controls){initial_capacity=capacity;failures=failure;edits=edit;scene=cases%4;offset=cases%4;input_width=kind==0?capacity:cases&1?0xffffffff:37;execute_case();}
    kind=4;edits=0;occupied=0;for(offset=0;offset<4;++offset)for(input_format=0;input_format<16;++input_format)for(U high:{0u,0x80000000u})for(U w:{0u,1u,0x12345678u,0xffffffffu})for(U f:{0u,1u,15u,0xffffffffu}){input_format|=high;input_width=w;input_formatB=w^0xface0000;input_flags=f;execute_case();input_format&=0x7fffffff;}
    kind=5;input_width=8;initial_arena=0;initial_capacity=0xc00000;failures=0;scene=0;edits=0;
    for(occupied=0;occupied<=32;++occupied)for(match_mode=0;match_mode<3;++match_mode)for(input_format=0;input_format<14;++input_format)for(U f:{0u,1u,2u,255u,0x80000100u}){input_flags=f;input_formatB=cases&1?3:0x80000000;input_width=cases%4==0?8:cases%4==1?0x4001:cases%4==2?0xffffffff:0x80000001;offset=cases%4;sentinel_mode=cases%3;execute_case();}
    occupied=32;match_mode=0;input_width=8;input_format=4;input_formatB=7;input_flags=2;guard_mode=1;sentinel_mode=0;edits=0;
    for(U m:{0u,1u,2u})for(U e:{0u,128u}){match_mode=m;edits=e;execute_case();}
    guard_mode=0;edits=128;match_mode=0;execute_case();
    __asm fninit
    printf("render_resource_allocation_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
