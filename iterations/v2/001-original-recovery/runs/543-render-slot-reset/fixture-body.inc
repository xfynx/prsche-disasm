#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include "render_slot_reset_543.hpp"
#include "porsche/render_loader.hpp"
#include "porsche/application_heap_state.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_device.hpp"
using U=std::uint32_t;using B=std::uint8_t;using namespace porsche;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U word(const void* p,U o=0){U v;memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
static void put(void* p,U o,U v){memcpy(static_cast<B*>(p)+o,&v,4);}
static U cases,events_total,kind,flags,offset,value,precision,rounding,depth,initial_status,scene,layout,dirty_mode,initial_count,fill_calls,nesting;
static bool cpp_side;static B* code[3];static U virtual_free_target;
alignas(16) static B floating[512];
struct Arena {B nodes[32][3][32],storage[2][64];};
static Arena arena;
namespace porsche {
// Fixture views. Production owners remain537,540 and the canonical loader.
B render_texture_slots_006a33f8[1536]{};
U render_texture_count_006a3a40=0;
U render_thrash_exports_006bd910[43]{};
}
struct Fpu {unsigned short control,status;B tag,padding[3],values[80];};
struct State {Arena arena;B slots[1536];U globals[7],exports[43],fill_calls,nesting;};
struct Event {U tag,argc,args[7];State state;Fpu fpu;};
struct Trace {U count,abi,exception[3];Event events[80];State final;Fpu fpu;};
static Trace trace,expected;
static void require(bool ok,const char* s){if(!ok){printf("divergence %s case=%u kind=%u flags=%x scene=%u layout=%u count=%x dirty=%u value=%x offset=%u cpp=%u\n",s,cases,kind,flags,scene,layout,initial_count,dirty_mode,value,offset,cpp_side);fflush(stdout);ExitProcess(1);}}
static void snapshot(State& s){s.arena=arena;memcpy(s.slots,render_texture_slots_006a33f8,1536);const U g[]={render_texture_slot_count_006a3a44,render_texture_dirty_006a3a48,render_texture_pending_006a3a58,render_texture_arena_006a3a5c,render_texture_heap_id_006a3a60,render_texture_epoch_006a3a64,render_texture_count_006a3a40};memcpy(s.globals,g,sizeof g);memcpy(s.exports,render_thrash_exports_006bd910,172);s.fill_calls=fill_calls;s.nesting=nesting;}
@ABI_X87_HELPERS@
static void event(U tag,std::initializer_list<U> args){require(trace.count<80,"bounded event count");auto& e=trace.events[trace.count++];e.tag=tag;e.argc=static_cast<U>(args.size());U i=0;for(U a:args)e.args[i++]=a;while(i<7)e.args[i++]=0;snapshot(e.state);capture(e.fpu);}
static void control(){if(flags&32){unsigned short cw=static_cast<unsigned short>(0x7f|((precision==0?3u:0u)<<8)|(((rounding+1)%4)<<10));__asm fldcw cw}}
static void release(){U result=0,abi=invoke(cpp_side?reinterpret_cast<void*>(&render_texture_arena_release_00555400):code[2],nullptr,nullptr,0,0,result);require(abi==0,"nested release ABI");}
static U __stdcall treset_alternate(){require(false,"alternate reset callback must remain unexecuted");return 0;}
static U __stdcall treset(){event(0x6bd988,{});
    if(flags&1)render_texture_slot_count_006a3a44=scene&1?0xffffffff:2;
    if(flags&2){put(render_texture_slots_006a33f8,0x24,ptr(arena.nodes[31][0]+offset));render_texture_pending_006a3a58=value^0xabcdef01;render_texture_epoch_006a3a64=value^0xa5a5a5a5;render_texture_dirty_006a3a48=0;}
    if(flags&128)render_thrash_exports_006bd910[30]=ptr(reinterpret_cast<void*>(&treset_alternate));
    control();return value^0x12345678;
}
namespace porsche {
void __cdecl heap_fill_0053c290(void* p,U byte,U bytes){event(0x53c290,{ptr(p),byte,bytes});require(byte==0&&bytes==48,"exact clear48B transport");require(ptr(p)>=ptr(render_texture_slots_006a33f8)&&ptr(p)+48<=ptr(render_texture_slots_006a33f8)+1536,"normal slot clear bounds");memset(p,static_cast<int>(byte),bytes);++fill_calls;
    if((flags&4)&&fill_calls==1)render_texture_slot_count_006a3a44=scene&1?0xffffffff:3;
    if(flags&64){render_texture_epoch_006a3a64=value^fill_calls;render_texture_count_006a3a40=value+fill_calls;render_texture_dirty_006a3a48=0x80000001;render_texture_pending_006a3a58=0xdeadbeef;render_texture_arena_006a3a5c=ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x55667788;}
    control();
}
U __cdecl application_heap_destroy_005699f0(U id){event(0x5699f0,{id});
    if(flags&8){render_texture_arena_006a3a5c=scene&1?0:ptr(arena.storage[1]+offset);render_texture_heap_id_006a3a60=value^0x87654321;}
    if((flags&16)&&!nesting){++nesting;render_texture_arena_006a3a5c=0;release();--nesting;render_texture_arena_006a3a5c=ptr(arena.storage[1]+offset);}
    control();return value^0x98765432;
}
U __stdcall platform_virtual_free(void* p,U bytes,U mode){event(0x5b2148,{ptr(p),bytes,mode});require(bytes==0&&mode==0x8000,"original MEM_RELEASE ABI");
    if((flags&16)&&!nesting){++nesting;release();--nesting;}
    if(flags&8){render_texture_arena_006a3a5c=ptr(arena.storage[0]+offset);render_texture_heap_id_006a3a60=value^0x10203040;}
    control();return scene&1?0:1;
}
}
@RELOCATORS@
static void init(){require(render_texture_slot_count_006a3a44==0&&render_texture_dirty_006a3a48==0&&render_texture_pending_006a3a58==0&&render_texture_arena_006a3a5c==0&&render_texture_heap_id_006a3a60==0&&render_texture_epoch_006a3a64==0,"six production loaderzero globals before reset");
    static const B a[]={@INVALIDATE@},b[]={@RESET@},c[]={@RELEASE@};const B* bodies[]={a,b,c};const U sizes[]={81,100,64};
    for(U n=0;n<3;++n){code[n]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[n]!=nullptr,"raw code allocation");memcpy(code[n],bodies[n],sizes[n]);}
    virtual_free_target=ptr(reinterpret_cast<void*>(&platform_virtual_free));
    absolute(code[0],81,0x6a3a48,&render_texture_dirty_006a3a48,2);absolute(code[0],81,0x6bd988,render_thrash_exports_006bd910+30,1);absolute(code[0],81,0x6a3a44,&render_texture_slot_count_006a3a44,1);absolute(code[0],81,0x6a3a58,&render_texture_pending_006a3a58,1);absolute(code[0],81,0x6a3420,render_texture_slots_006a33f8+0x28,1);
    relative(code[1],100,0x555390,0x555330,code[0],1);relative(code[1],100,0x555390,0x53c290,reinterpret_cast<void*>(&heap_fill_0053c290),1);relative(code[1],100,0x555390,0x555400,code[2],1);absolute(code[1],100,0x6a3a64,&render_texture_epoch_006a3a64,2);absolute(code[1],100,0x6a3a44,&render_texture_slot_count_006a3a44,3);absolute(code[1],100,0x6a3a40,&render_texture_count_006a3a40,1);absolute(code[1],100,0x6a3a48,&render_texture_dirty_006a3a48,1);absolute(code[1],100,0x6a33f8,render_texture_slots_006a33f8,1);
    relative(code[2],64,0x555400,0x5699f0,reinterpret_cast<void*>(&application_heap_destroy_005699f0),1);absolute(code[2],64,0x6a3a5c,&render_texture_arena_006a3a5c,3);absolute(code[2],64,0x6a3a60,&render_texture_heap_id_006a3a60,2);absolute(code[2],64,0x5b2148,&virtual_free_target,1);
    for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"instruction cache");
}
static void reset(){trace={};fill_calls=nesting=0;memset(&arena,0x65+(value&7),sizeof arena);
    for(U i=0;i<32;++i){B* record=render_texture_slots_006a33f8+i*48;for(U j=0;j<48;j+=4)put(record,j,value^(i*0x1020304u+j));
        for(U n=0;n<3;++n){B* p=arena.nodes[i][n]+offset;put(p,0,n<2?ptr(arena.nodes[i][n+1]+offset):0);}
        if(layout==0)put(record,0x24,0);
        else if(layout==1){put(record,0x24,ptr(arena.nodes[i][2]+offset));}
        else if(layout==2)put(record,0x24,ptr(arena.nodes[i][0]+offset));
        else if(layout==3)put(record,0x24,ptr(arena.nodes[0][0]+offset));
        else if(layout==4){put(record,0x14,0);put(record,0x24,ptr(record+0x14));}
        else {if(i<31){put(record,0x24,ptr(record+0x28));put(record,0x28,ptr(arena.nodes[i][0]+offset));}else put(record,0x24,ptr(arena.nodes[i][0]+offset));}
    }
    render_texture_slot_count_006a3a44=initial_count;render_texture_dirty_006a3a48=dirty_mode==0?0:dirty_mode==1?1:0x80000000;render_texture_pending_006a3a58=value^0x13579bdf;render_texture_epoch_006a3a64=value;render_texture_count_006a3a40=value^0x2468ace0;render_texture_heap_id_006a3a60=value^0x91827364;render_texture_arena_006a3a5c=scene&2?0:ptr(arena.storage[0]+offset);for(U& x:render_thrash_exports_006bd910)x=0;render_thrash_exports_006bd910[30]=ptr(reinterpret_cast<void*>(&treset));
}
static void compare(){for(U side=0;side<2;++side){cpp_side=side!=0;reset();seed_fpu();void* fn=side?(kind==0?reinterpret_cast<void*>(&render_texture_invalidate_00555330):kind==1?reinterpret_cast<void*>(&render_texture_reset_00555390):reinterpret_cast<void*>(&render_texture_arena_release_00555400)):code[kind];U result=0;
    bool completed=true;__try{trace.abi=invoke(fn,nullptr,nullptr,0,0,result);}__except(exception_record(GetExceptionInformation())){completed=false;}
    require(completed,"valid finite slot/node transport must not fault");require(trace.abi==0,"cdecl0 stack/preserved registers");snapshot(trace.final);capture(trace.fpu);
    if(!side)expected=trace;else{require(trace.count==expected.count,"event count");for(U i=0;i<trace.count;++i)require(memcmp(&trace.events[i],&expected.events[i],sizeof(Event))==0,"callback argument/order/late state/x87");require(memcmp(&trace.final,&expected.final,sizeof(State))==0,"final slot/node/global bytes");require(memcmp(&trace.fpu,&expected.fpu,sizeof(Fpu))==0,"final x87");events_total+=trace.count;}}
    ++cases;
}
int main(){init();const U counts[]={0xfffffffd,0xffffffff,0,1,2,3,7,31,32,0x80000000};const U edits[]={0,1,2,4,8,16,32,64,128};const U values[]={0,1,0xffffffff,0x80000000,0x7fffffff,0x12345678};
    for(kind=0;kind<2;++kind)for(U count:counts)for(layout=0;layout<6;++layout)for(offset=0;offset<4;++offset)for(dirty_mode=0;dirty_mode<3;++dirty_mode)for(U edit:edits){initial_count=count;flags=edit;scene=(cases/3)%4;value=values[cases%6];precision=cases%3==0?0:cases%3==1?2:3;rounding=cases%4;depth=(cases/12)%3*3;initial_status=cases&1?0x3f:0;compare();}
    kind=2;initial_count=32;layout=2;for(scene=0;scene<8;++scene)for(U edit:edits)for(offset=0;offset<4;++offset)for(U v:values){flags=edit;value=v;dirty_mode=cases%3;precision=cases%3==0?0:cases%3==1?2:3;rounding=cases%4;depth=(cases/12)%3*3;initial_status=cases&1?0x3f:0;compare();}
    __asm fninit
    printf("render_slot_reset_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
