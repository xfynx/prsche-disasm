#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <cstdarg>
#define PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
#include "porsche/shared_runtime_globals.hpp"
#include "porsche/files.hpp"
#include "render_resource_descriptor_537.hpp"
#include "render_descriptor.hpp"
#include "porsche/render_display.hpp"
using U=std::uint32_t;using B=std::uint8_t;using namespace porsche;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U word(const void* p,U o=0){U v;memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
static void put(void* p,U o,U v){memcpy(static_cast<B*>(p)+o,&v,4);}
static U cases,events_total,kind,flags,offset,value,precision,rounding,depth,initial_status,scene,format_type,reader_calls;
static bool cpp_side;static B* code[8];static U raw_node_table[1],raw_switch[11];
alignas(16) static B floating[512];
struct Arena {B node[128],descriptor[3][96],texture[2][96],output[96],counter[2][16],parent[48];};
static Arena arena;
static B* node(){return arena.node+offset;}
static B* descriptor(U n=0){return arena.descriptor[n]+offset;}
static B* texture(U n=0){return arena.texture[n]+offset;}
static U identity(U p){return p==ptr(raw_node_table)||p==ptr(render_resource_node_table_005bb6d4)?0x5bb6d4:p;}
struct Fpu {unsigned short control,status;B tag,padding[3],values[80];};
struct State {Arena arena;B slots[1536];U diagnostic[3],reader_calls;};
struct Event {U tag,argc,args[7];State state;Fpu fpu;};
struct Trace {U count,result,abi,exception[3];Event events[12];State final;Fpu fpu;};
static Trace trace,expected;
static void require(bool ok,const char* s){if(!ok){printf("divergence %s case=%u kind=%u flags=%u scene=%u type=%x value=%x offset=%u cpp=%u\n",s,cases,kind,flags,scene,format_type,value,offset,cpp_side);fflush(stdout);ExitProcess(1);}}
static void snapshot(State& s){s.arena=arena;put(s.arena.node,offset,identity(word(s.arena.node,offset)));memcpy(s.slots,render_texture_slots_006a33f8,1536);s.diagnostic[0]=shared_runtime_word_005deb74;s.diagnostic[1]=shared_runtime_word_005deb78;s.diagnostic[2]=ptr(reinterpret_cast<void*>(diagnostic_handler_005debf0));s.reader_calls=reader_calls;}
@SHARED_ABI_X87_HELPERS@
static void event(U tag,std::initializer_list<U> args){require(trace.count<12,"event bound");auto& e=trace.events[trace.count++];e.tag=tag;e.argc=static_cast<U>(args.size());U i=0;for(U a:args)e.args[i++]=a;while(i<7)e.args[i++]=0;snapshot(e.state);capture(e.fpu);}
static void control(){if(flags&32){unsigned short cw=static_cast<unsigned short>(0x7f|((precision==0?3u:0u)<<8)|(((rounding+1)%4)<<10));__asm fldcw cw}}
static void __cdecl diagnostic(const char* format,...){va_list a;va_start(a,format);U type=va_arg(a,U);va_end(a);require(format==render_palette_message_005bb81c,"actual diagnostic format pointer");event(0x5debf0,{ptr(format),type});if(flags&1)put(descriptor(),0,0x22);if(flags&2)put(descriptor(),0,0x6006);control();}
namespace porsche {
// Link-only views for unrelated functions in the actual521 TU; fail closed.
U render_thrash_exports_006bd910[43]{};
B cursor_snapshot_prefix_005de650[12]{},cursor_snapshot_suffix_005de65e[30]{};
void* window_shutdown_handle_0069dd18=nullptr;
U window_shutdown_state_005de67c=0,window_shutdown_config_005de620[12]{},splash_progress_format_005dead0=0;
B window_shutdown_source_005de65c=0,window_shutdown_source_005de65d=0;
void* __cdecl render_descriptor_allocate_00535700(U,U,U,U,U){require(false,"unexecuted521 allocate");return nullptr;}
void __stdcall window_shutdown_display_callback_006bd9b0(U){require(false,"unexecuted521 display callback");}
void __cdecl window_shutdown_runtime_state_00534430(){require(false,"unexecuted521 window shutdown");}
void (__cdecl* diagnostic_handler_005debf0)(const char*)=reinterpret_cast<void (__cdecl*)(const char*)>(&diagnostic);
U __cdecl render_descriptor_read_be_0056e290(const void* p,U bytes){event(0x56e290,{ptr(p),bytes});const U i=reader_calls++;if(flags&1)put(descriptor(),0xc,word(descriptor(),0xc)^0x2000);if(flags&2)put(descriptor(),0x10,0x11223344^i);control();const U results[]={0,0x18fb,0x1afb,0xffffffff};return results[(scene+i)%4];}
void __cdecl render_resource_texture_destroy_00554cc0(void* p){event(0x554cc0,{ptr(p)});if(flags&1)put(node(),0x20,ptr(arena.counter[1]+offset));if(flags&2)put(node(),8,ptr(texture(1)));control();}
U __cdecl application_release_0059f050(void* p){event(0x59f050,{ptr(p)});if(flags&4)put(node(),0x20,ptr(arena.counter[1]+offset));control();return value^0x91827364;}
void* __cdecl startup_network_allocate_0059ef90(U bytes){event(0x59ef90,{bytes});require(bytes==4,"exact4B counter allocation");if(flags&8)put(node(),0x14,value^0xa5a55a5a);control();return arena.counter[0]+offset;}
std::int32_t __cdecl formatter_entry_005a0fbf(char* out,const char* format,...){va_list a;va_start(a,format);int index=va_arg(a,int);va_end(a);event(0x5a0fbf,{ptr(format),static_cast<U>(index)});const int n=std::sprintf(out,format,index);require(n>=0&&n<20,"20B original generated name bound");control();return n;}
void* __cdecl render_display_texture_alloc_00554960(U w,U h,U first,U second,U f,const char* name){event(0x554960,{w,h,first,second,f,ptr(name)});if(flags&4)put(node(),8,ptr(texture(1)));control();return texture();}
void __cdecl render_display_texture_copy_00554d70(void* p,void* pixels,U aux){event(0x554d70,{ptr(p),ptr(pixels),aux});if(flags&2)put(node(),8,ptr(texture(1)));control();}
}
@SHARED_RELOCATORS@
static const B jump_initial[44]={@JUMP_TABLE@},lookup_initial[253]={@LOOKUP@},bits_initial[128]={@BITS@},name_initial[6]={@NAME_FORMAT@};
static const B message_initial[41]={@MESSAGE@},file_initial[19]={@FILE@};
static void init(){
    require(memcmp(render_palette_message_005bb81c,message_initial,41)==0,"raw41B diagnostic message");require(memcmp(render_palette_file_005bb848,file_initial,19)==0,"raw19B diagnostic source");
    require(memcmp(render_descriptor_bits_005de890,bits_initial,128)==0,"actual521128B bits initial");require(memcmp(render_resource_node_name_format_005de748,name_initial,6)==0,"5366B format initial");
    B zero[1536]{};require(memcmp(render_texture_slots_006a33f8,zero,1536)==0,"production zero1536B table before reset");
    MEMORY_BASIC_INFORMATION region{};require(VirtualQuery(render_texture_slots_006a33f8,&region,sizeof region)&&region.Protect==PAGE_READWRITE,"writable original slots");
    static const B a[]={@DTOR@},b[]={@FORMAT@},c[]={@PALETTE@},d[]={@QUERY@},e[]={@CTOR@},f[]={@PAIR@},g[]={@EMPTY@},h[]={@STATE_CTOR@};
    const B* bodies[]={a,b,c,d,e,f,g,h};const U sizes[]={75,183,136,80,365,336,224,29};
    for(U n=0;n<8;++n){code[n]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[n]!=nullptr,"raw code allocation");memcpy(code[n],bodies[n],sizes[n]);}
    raw_node_table[0]=ptr(code[0]);for(U i=0;i<11;++i)raw_switch[i]=ptr(code[1])+word(jump_initial,4*i)-0x556690;
    absolute(code[0],75,0x5bb6d4,raw_node_table,1);relative(code[0],75,0x535d30,0x554cc0,reinterpret_cast<void*>(&render_resource_texture_destroy_00554cc0),1);relative(code[0],75,0x535d30,0x59f050,reinterpret_cast<void*>(&application_release_0059f050),2);
    absolute(code[1],183,0x556774,lookup_initial,1);absolute(code[1],183,0x556748,raw_switch,1);relative(code[1],183,0x556690,0x56e290,reinterpret_cast<void*>(&render_descriptor_read_be_0056e290),2);
    relative(code[2],136,0x537fb0,0x537f90,reinterpret_cast<void*>(&render_descriptor_bits_00537f90),1);absolute(code[2],136,0x5deb74,&shared_runtime_word_005deb74,1);absolute(code[2],136,0x5deb78,&shared_runtime_word_005deb78,1);absolute(code[2],136,0x5debf0,&diagnostic_handler_005debf0,1);absolute(code[2],136,0x5bb81c,render_palette_message_005bb81c,1);absolute(code[2],136,0x5bb848,render_palette_file_005bb848,1);
    absolute(code[3],80,0x6a3400,render_texture_slots_006a33f8+8,1);
    const U va[]={0x535bc0,0x535d80,0x535ed0},sz[]={365,336,224};
    for(U i=0;i<3;++i){B* p=code[4+i];U n=sz[i];absolute(p,n,0x5bb6d4,raw_node_table,1);absolute(p,n,0x5de748,render_resource_node_name_format_005de748,1);relative(p,n,va[i],0x5379d0,code[7],1);relative(p,n,va[i],0x59ef90,reinterpret_cast<void*>(&startup_network_allocate_0059ef90),1);relative(p,n,va[i],0x5a0fbf,reinterpret_cast<void*>(&formatter_entry_005a0fbf),1);
        if(i!=2){relative(p,n,va[i],0x556690,code[1],2);relative(p,n,va[i],0x554960,reinterpret_cast<void*>(&render_display_texture_alloc_00554960),1);relative(p,n,va[i],0x554d70,reinterpret_cast<void*>(&render_display_texture_copy_00554d70),1);relative(p,n,va[i],0x554de0,code[3],1);}if(i==0)relative(p,n,va[i],0x537fb0,code[2],1);
    }
    for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"instruction cache");
}
static void reset(){memset(&arena,0x69+(value&7),sizeof arena);trace={};reader_calls=0;shared_runtime_word_005deb74=0x11223344;shared_runtime_word_005deb78=value;diagnostic_handler_005debf0=reinterpret_cast<void (__cdecl*)(const char*)>(&diagnostic);
    for(U i=0;i<32;++i)for(U j=0;j<48;j+=4)put(render_texture_slots_006a33f8,i*48+j,value^(i*0x1020304u+j));
    put(node(),0,cpp_side?ptr(render_resource_node_table_005bb6d4):ptr(raw_node_table));put(node(),8,scene&1?0:ptr(texture()));put(node(),0x20,scene&8?0:ptr(arena.counter[0]+offset));put(arena.counter[0],offset,value);put(arena.counter[1],offset,value^1);
    for(U i=0;i<3;++i){put(descriptor(i),0,format_type);put(descriptor(i),4,value);put(descriptor(i),0xc,scene&1?0x2000:0);put(descriptor(i),0x10,0xfedcba98);}
    put(arena.parent,0x10,value&0x7fff);
    for(U i=0;i<2;++i){put(texture(i),4,scene%32);for(U j:{0x14u,0x18u,0x1cu,0x20u,0x24u,0x2cu})put(texture(i),j,value^(j*0x10203u+i));}
    if(kind==2){switch(scene%8){case 0:put(descriptor(),0,0x22);break;case 1:put(descriptor(),0,0x6001);put(descriptor(1),0,0x24);break;case 2:put(descriptor(1),0,0xffffa001);put(descriptor(),0,0x29);break;case 3:put(descriptor(),0,0xc001);put(descriptor(2),0,0x2e);break;case 4:put(descriptor(),0,1);break;case 5:put(descriptor(),0,0);break;case 6:put(descriptor(),0,0x6000);put(descriptor(1),0,0x2c);break;case 7:put(descriptor(),0,0x6001);put(descriptor(1),0,0x6001);put(descriptor(2),0,0);break;}}
    if(kind==3){const U alias=(scene/64)%5;if(alias==1)put(texture(),0x14,scene%32);if(alias==2)put(texture(),0x20,scene%32);}
    if(kind>=4){put(descriptor(),0,1);put(descriptor(1),0,2);put(texture(),0x2c,8);put(texture(1),0x2c,0);}
}
static void compare(){for(U side=0;side<2;++side){cpp_side=side!=0;reset();seed_fpu();void* fn=nullptr;void* receiver=node();U args[5]={},count=0,cleanup=0;
    if(kind==0){fn=side?reinterpret_cast<void*>(&render_resource_node_destroy_00535d30):code[0];args[0]=flags;count=1;}
    else if(kind==1){fn=side?reinterpret_cast<void*>(&render_resource_node_format_00556690):code[1];args[0]=scene&8?0:ptr(descriptor());count=1;cleanup=4;}
    else if(kind==2){fn=side?reinterpret_cast<void*>(&render_resource_node_palette_00537fb0):code[2];args[0]=scene&8?0:ptr(descriptor(scene%8==2?1:0));count=1;cleanup=4;}
    else if(kind==3){fn=side?reinterpret_cast<void*>(&render_resource_texture_query_00554de0):code[3];args[0]=scene&32?0:ptr(texture());const U alias=(scene/64)%5;args[1]=alias==0?ptr(arena.output+offset):alias==1?ptr(texture()):alias==2?ptr(texture()+4):alias==3?ptr(texture()+0x14):ptr(render_texture_slots_006a33f8+(scene%32)*48+4);count=2;cleanup=8;}
    else if(kind==4){fn=side?reinterpret_cast<void*>(&render_resource_node_ctor_00535bc0):code[4];args[0]=ptr(descriptor());args[1]=ptr(arena.parent);args[2]=value;args[3]=ptr("bounded-original-name");count=4;}
    else if(kind==5){fn=side?reinterpret_cast<void*>(&render_resource_node_pair_ctor_00535d80):code[5];args[0]=ptr(descriptor());args[1]=ptr(descriptor(1));args[2]=ptr(arena.parent);args[3]=value;args[4]=ptr("bounded-original-name");count=5;}
    else {fn=side?reinterpret_cast<void*>(&render_resource_node_empty_ctor_00535ed0):code[6];args[0]=ptr(arena.parent);args[1]=value;args[2]=ptr("bounded-original-name");count=3;}
    U result=0;bool completed=true;__try {trace.abi=invoke(fn,receiver,args,count,cleanup,result);}__except(exception_record(GetExceptionInformation())){completed=false;}
    trace.result=completed?result:0;if(!completed)require(kind==0&&(scene&8)&&trace.exception[0]==0xc0000005&&trace.exception[1]==0&&trace.exception[2]==0,"null-counter original read fault");
    snapshot(trace.final);capture(trace.fpu);require(!trace.abi,"RET/stack/preserved registers");
    if(!side)expected=trace;else {require(trace.count==expected.count&&trace.result==expected.result,"event count/used result");require(memcmp(trace.exception,expected.exception,12)==0,"fault type/address");for(U i=0;i<trace.count;++i)require(memcmp(&trace.events[i],&expected.events[i],sizeof(Event))==0,"callee order/input/state/x87");require(memcmp(&trace.final,&expected.final,sizeof(State))==0,"final bytes/alias/order/diagnostic");require(memcmp(&trace.fpu,&expected.fpu,sizeof(Fpu))==0,"final x87");events_total+=trace.count;}}
    ++cases;
}
int main(){init();const U values[]={0,1,2,0xffffffff,0x80000000,0x7fffffff};const U edits[]={0,1,2,4,8,32,47};
    for(kind=0;kind<7;++kind)for(U edit:edits)for(offset=0;offset<4;++offset)for(U v:values){flags=edit;value=v;const U scenes=kind==3?320:kind==1?16:kind>=4?4:16;const U types=kind==1?256:1;
        for(scene=0;scene<scenes;++scene)for(format_type=0;format_type<types;++format_type){precision=cases%3==0?0:cases%3==1?2:3;rounding=cases%4;depth=(cases/12)%3*3;initial_status=cases&1?0x3f:0;compare();}}
    __asm fninit
    printf("render_descriptor_cleanup_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
