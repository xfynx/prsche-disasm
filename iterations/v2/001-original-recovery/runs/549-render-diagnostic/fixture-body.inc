#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include "render_diagnostic_549.hpp"
#include "../353-diagnostic-mono/diagnostic_mono.hpp"
#include "../546-render-resource-allocation/render_resource_allocation_546.hpp"
#include "porsche/application_heap.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/heap.hpp"
#include "porsche/file_device.hpp"
#include "porsche/process_exit.hpp"
using U=std::uint32_t;using S=std::int32_t;using B=std::uint8_t;using namespace porsche;
static U ptr(const void* p){return reinterpret_cast<U>(p);}
static U word(const void* p,U o=0){U v;memcpy(&v,static_cast<const B*>(p)+o,4);return v;}
static void put(void* p,U o,U v){memcpy(static_cast<B*>(p)+o,&v,4);}
static U cases,events_total,kind,channel,channel_flags,initial_started,device_mask,callback_mask,output_length,edits,startup_mode;
static U precision,rounding,depth,initial_status,value,callback_calls,core_calls,observed_bytes;
static bool cpp_side;static B* code[2];static B* raw_slots;static B* raw_pages;static B raw_table[280];
static char* current_buffer;static const char* current_format;
static char output_copy[2048];
static const char fixture_format[]="opaque format: %s %d %f %n"; // never parsed by the controlled core
static const char environment_value[]="controlled configuration";
alignas(16) static B floating[512];
namespace porsche {B render_texture_slots_006a33f8[1536]{};U render_texture_slot_count_006a3a44=0,render_texture_arena_006a3a5c=0,render_texture_heap_id_006a3a60=0;}
static B* slots(){return cpp_side?render_texture_slots_006a33f8:raw_slots;}
struct Fpu {unsigned short control,status;B tag,padding[3],values[80];};
struct State {DiagnosticDeviceImage devices;DiagnosticChannel channels[64];U started,slot_count,core_calls,callback_calls,observed;B slots[1536];char output[2048];};
struct Event {U tag,argc,args[12];State state;Fpu fpu;};
struct Trace {U count,abi,completed,exception[3];Event events[32];State final;Fpu fpu;};
static Trace trace,expected;
static void require(bool ok,const char* s){if(!ok){printf("divergence %s case=%u kind=%u ch=%u flags=%x started=%x mask=%x callbacks=%x bytes=%u edits=%x startup=%u cpp=%u\n",s,cases,kind,channel,channel_flags,initial_started,device_mask,callback_mask,output_length,edits,startup_mode,cpp_side);fflush(stdout);ExitProcess(1);}}
static void snapshot(State& s){s.devices=application_diagnostic_device_image_005e1c88;memcpy(s.channels,application_diagnostic_channels_005df4a0,sizeof s.channels);s.started=application_diagnostic_started_006a57cc;s.slot_count=render_texture_slot_count_006a3a44;s.core_calls=core_calls;s.callback_calls=callback_calls;s.observed=observed_bytes;memcpy(s.slots,slots(),1536);memset(s.output,0,sizeof s.output);if(observed_bytes)memcpy(s.output,output_copy,observed_bytes);}
@ABI_X87_HELPERS@
static void event(U tag,std::initializer_list<U> args){require(trace.count<32,"finite events");auto& e=trace.events[trace.count++];e.tag=tag;e.argc=static_cast<U>(args.size());U i=0;for(U a:args)e.args[i++]=a;while(i<12)e.args[i++]=0;snapshot(e.state);capture(e.fpu);}
static void control(){if(edits&32){unsigned short cw=static_cast<unsigned short>(0x7f|((precision==0?3u:0u)<<8)|(((rounding+1)%4)<<10));__asm fldcw cw}}
template<U index,U alternative=0>static void __cdecl device(U actual_channel,const char* text){
    require(actual_channel==channel&&text==current_buffer,"device(channel,same stackbuffer) transport");memcpy(output_copy,text,observed_bytes);event(0x549100+index+alternative*16,{actual_channel,0xc54900,observed_bytes});++callback_calls;
    if((edits&8)&&index==0){application_diagnostic_devices_005e1c8c[1].flags=0;application_diagnostic_devices_005e1c8c[2].callback=0;application_diagnostic_devices_005e1c8c[7].flags|=1;application_diagnostic_devices_005e1c8c[7].callback=ptr(reinterpret_cast<void*>(&device<7,1>));}
    if((edits&16)&&output_length){current_buffer[0]=static_cast<char>('A'+index);current_buffer[output_length-1]=static_cast<char>('a'+index);}
    if(edits&64){application_diagnostic_channels_005df4a0[channel].flags&=~1u;application_diagnostic_started_006a57cc=0;}
    memcpy(output_copy,text,observed_bytes);
    control();
}
static U callbacks[8];
namespace porsche {
void __cdecl application_diagnostic_device_callback_00586ca0(U,const char*){require(false,"unexecuted default debugger");}
void __cdecl application_diagnostic_device_callback_00586cb0(U,const char*){require(false,"unexecuted default console");}
void __cdecl application_diagnostic_device_callback_00586cc0(U,const char*){require(false,"unexecuted default mono");}
void __cdecl application_diagnostic_device_set_0055ed20(U index,U enabled){event(0x55ed20,{index,enabled});application_diagnostic_devices_005e1c8c[index].flags=(application_diagnostic_devices_005e1c8c[index].flags&~1u)|(enabled?1u:0u);control();}
void __cdecl application_diagnostic_channel_set_0055efd0(U index,U enabled){event(0x55efd0,{index,enabled});application_diagnostic_channels_005df4a0[index].flags=(application_diagnostic_channels_005df4a0[index].flags&~1u)|(enabled?1u:0u);control();}
const char* __cdecl application_diagnostic_environment_005a3050(const char* key){const U id=strcmp(key,"PRINT_DEVICE")==0?1:strcmp(key,"PRINT_CHANNEL")==0?2:0;require(id!=0,"canonical environment key");event(0x5a3050,{id});control();return startup_mode?environment_value:nullptr;}
void __cdecl application_diagnostic_device_parse_0055ed50(const char* text){require(text==environment_value,"controlled device configuration");event(0x55ed50,{ptr(text)});for(U i=0;i<8;++i){application_diagnostic_devices_005e1c8c[i].flags=(0x80000000u|((device_mask>>i)&1));application_diagnostic_devices_005e1c8c[i].callback=(callback_mask&(1u<<i))?callbacks[i]:0;}control();}
void __cdecl application_diagnostic_channel_parse_0055f060(const char* text){require(text==environment_value,"controlled channel configuration");event(0x55f060,{ptr(text)});application_diagnostic_channels_005df4a0[channel].flags=channel_flags;control();}
int __cdecl formatter_core_005a4371(FormatterDescriptor005a0fbf* descriptor,const char* format,const U* arguments){
    require(descriptor->cursor==descriptor->base&&descriptor->remaining==0x7fffffff&&descriptor->flags==0x42,"canonical formatter descriptor prefix");
    require(format==current_format,"format identity");current_buffer=descriptor->cursor;
    if(kind==0)event(0x5a4371,{ptr(format),arguments[0],arguments[1],arguments[2],arguments[3],arguments[4],arguments[5],arguments[6],arguments[7]});else event(0x5a4371,{ptr(format)});
    ++core_calls;for(U i=0;i<output_length;++i)current_buffer[i]=output_copy[i]=static_cast<char>(' '+(i+value)%95);output_copy[output_length]=0;
    descriptor->cursor+=output_length;descriptor->remaining-=static_cast<S>(output_length);
    // The canonical entry owns the final NUL. Count it only after that return;
    // callbacks/snapshots never inspect the original unwritten local tail.
    observed_bytes=output_length+1;
    if(edits&1){application_diagnostic_channels_005df4a0[channel].flags&=~1u;application_diagnostic_devices_005e1c8c[7].flags|=1;application_diagnostic_devices_005e1c8c[7].callback=ptr(reinterpret_cast<void*>(&device<7,1>));}
    if(edits&2)for(U i=0;i<8;++i){application_diagnostic_devices_005e1c8c[i].flags^=1;application_diagnostic_devices_005e1c8c[i].callback=callbacks[7-i];}
    if(edits&4)application_diagnostic_started_006a57cc=0;
    control();return value&1?-7:0;
}
int __cdecl formatter_cleanup_005a4259(U,FormatterOriginalDescriptor32*){require(false,"unexecuted bounded formatter cleanup");return 0;}
// Unexecuted353 dependencies. Only its accepted vsprintf wrapper is admitted.
void* __cdecl heap_lock_create_005321f0(){require(false,"unexecuted mono lock");return nullptr;}
void __cdecl heap_enter_005322b0(void*){require(false,"unexecuted mono enter");}
void __cdecl heap_leave_005322c0(void*){require(false,"unexecuted mono leave");}
void __cdecl heap_copy_dispatch_005323e0(void*,const void*,U){require(false,"unexecuted mono copy");}
void __cdecl heap_fill_0053c290(void*,U,U){require(false,"unexecuted fill");}
// Unexecuted546 dependencies. Capacity path calls only actual slot/diagnostic.
void __cdecl render_texture_reset_00555390(){require(false,"unexecuted arena reset");}
U __cdecl application_heap_slot_00569a70(){require(false,"unexecuted heap slot/export");return 0;}
void* __stdcall platform_virtual_alloc(void*,U,U,U){require(false,"unexecuted arena API");return nullptr;}
S __cdecl heap_init_005697f0(U,const char*,void*,S,U,U,S,S,U,S,S,void*){require(false,"unexecuted heap init");return 0;}
void* __cdecl allocate_00531ca0(const char*,S,U){require(false,"unexecuted heap allocation");return nullptr;}
U __cdecl render_descriptor_format_00556880(U){require(false,"unexecuted header format");return 0;}
[[noreturn]]void __cdecl process_exit_005a246e(U status){event(0x5a246e,{status});RaiseException(0xe0549001,0,0,nullptr);ExitProcess(2);}
}
@RELOCATORS@
static void initial_data(){
    static const B raw_devices[]={@INITIAL_DEVICES@},raw_channels[]={@INITIAL_CHANNELS@};
    const U dbase=application_diagnostic_devices_005e1c8c[0].name-0xc,cbase=application_diagnostic_channels_005df4a0[0].name-0x7c;
    require(application_diagnostic_started_006a57cc==0&&ptr(&application_diagnostic_device_image_005e1c88.devices[0])==ptr(application_diagnostic_devices_005e1c8c),"canonical345 initial/alias");
    for(U i=0;i<100;i+=4){U expected=word(raw_devices,i);if(expected>=0x5c1588&&expected<0x5c15a1)expected=dbase+expected-0x5c1588;
        if(expected==0x586ca0)expected=ptr(reinterpret_cast<void*>(&application_diagnostic_device_callback_00586ca0));if(expected==0x586cb0)expected=ptr(reinterpret_cast<void*>(&application_diagnostic_device_callback_00586cb0));if(expected==0x586cc0)expected=ptr(reinterpret_cast<void*>(&application_diagnostic_device_callback_00586cc0));
        require(word(&application_diagnostic_device_image_005e1c88,i)==expected,"raw original device image before resets");}
    for(U i=0;i<512;i+=4){U expected=word(raw_channels,i);if(expected>=0x5bcbe4&&expected<0x5bcc86)expected=cbase+expected-0x5bcbe4;require(word(application_diagnostic_channels_005df4a0,i)==expected,"raw original channel image before resets");}
}
static void init(){initial_data();callbacks[0]=ptr(reinterpret_cast<void*>(&device<0>));callbacks[1]=ptr(reinterpret_cast<void*>(&device<1>));callbacks[2]=ptr(reinterpret_cast<void*>(&device<2>));callbacks[3]=ptr(reinterpret_cast<void*>(&device<3>));callbacks[4]=ptr(reinterpret_cast<void*>(&device<4>));callbacks[5]=ptr(reinterpret_cast<void*>(&device<5>));callbacks[6]=ptr(reinterpret_cast<void*>(&device<6>));callbacks[7]=ptr(reinterpret_cast<void*>(&device<7>));
    static const B diagnostic[]={@DIAGNOSTIC@},slot[]={@SLOT@};code[0]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));code[1]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[0]&&code[1],"raw code allocation");memcpy(code[0],diagnostic,116);memcpy(code[1],slot,228);
    raw_pages=static_cast<B*>(VirtualAlloc(nullptr,8192,0x3000,0x04));require(raw_pages!=nullptr,"raw slots");raw_slots=raw_pages;static const B table[]={@FORMAT_DATA@};memcpy(raw_table,table,280);
    absolute(code[0],116,0x6a57cc,&application_diagnostic_started_006a57cc,1);absolute(code[0],116,0x5df4a4,reinterpret_cast<B*>(application_diagnostic_channels_005df4a0)+4,1);absolute(code[0],116,0x5e1c8c,application_diagnostic_devices_005e1c8c,1);absolute(code[0],116,0x5e1cec,application_diagnostic_devices_005e1c8c+8,1);
    relative(code[0],116,0x55ec50,0x55eba0,reinterpret_cast<void*>(&application_secondary_start),1);relative(code[0],116,0x55ec50,0x5a299e,reinterpret_cast<void*>(&application_diagnostic_mono_vsprintf_005a299e),1);
    @SLOT_RELOCATIONS@
    require(FlushInstructionCache(GetCurrentProcess(),code[0],4096)!=0&&FlushInstructionCache(GetCurrentProcess(),code[1],4096)!=0,"instruction cache");
}
static void reset(){trace={};current_buffer=nullptr;memset(output_copy,0,sizeof output_copy);observed_bytes=core_calls=callback_calls=0;current_format=kind?render_texture_capacity_message_005bc208:fixture_format;
    application_diagnostic_started_006a57cc=initial_started;application_diagnostic_device_image_005e1c88.preceding_name=value^0x88;
    for(U i=0;i<8;++i){application_diagnostic_devices_005e1c8c[i].callback=(callback_mask&(1u<<i))?callbacks[i]:0;application_diagnostic_devices_005e1c8c[i].flags=0x80000000u|((device_mask>>i)&1);application_diagnostic_devices_005e1c8c[i].name=value^(0xabc000+i);}
    for(U i=0;i<64;++i){application_diagnostic_channels_005df4a0[i].name=value^(0x9abc00+i);application_diagnostic_channels_005df4a0[i].flags=0x80000000u|((i+value)&3);}
    application_diagnostic_channels_005df4a0[channel].flags=channel_flags;render_texture_slot_count_006a3a44=32;render_texture_width_sentinel_006a3a08=0;render_texture_arena_006a3a5c=render_texture_heap_id_006a3a60=0;
    memset(raw_slots,0,1572);memset(render_texture_slots_006a33f8,0,1536);for(U i=0;i<32;++i){put(slots(),i*48+0x10,8);put(slots(),i*48+8,5);}
}
static int record_exception(EXCEPTION_POINTERS* e){trace.exception[0]=e->ExceptionRecord->ExceptionCode;trace.exception[1]=e->ExceptionRecord->NumberParameters?static_cast<U>(e->ExceptionRecord->ExceptionInformation[0]):0;trace.exception[2]=e->ExceptionRecord->NumberParameters>1?static_cast<U>(e->ExceptionRecord->ExceptionInformation[1]):0;return EXCEPTION_EXECUTE_HANDLER;}
static void compare(){for(U side=0;side<2;++side){cpp_side=side!=0;reset();seed_fpu();U args[11]={};U count=kind?4:11;
    if(kind){args[0]=8;args[1]=4;args[2]=5;args[3]=2;}else{args[0]=channel;args[1]=ptr(current_format);for(U i=0;i<9;++i)args[i+2]=value^(0x1020304u*i+0x11223344);}
    void* fn=kind?(side?reinterpret_cast<void*>(&render_texture_slot_00554bd0):code[1]):side?reinterpret_cast<void*>(&render_texture_diagnostic_0055ec50):code[0];U result=0;
    trace.completed=1;__try{trace.abi=invoke(fn,nullptr,args,count,count*4,result);}__except(record_exception(GetExceptionInformation())){trace.completed=0;}
    if(kind)require(!trace.completed&&trace.exception[0]==0xe0549001,"capacity noreturn transport");else require(trace.completed&&trace.abi==0,"cdeclvarargs stack/nonvolatile ABI");
    snapshot(trace.final);capture(trace.fpu);if(!side)expected=trace;else{require(trace.completed==expected.completed&&trace.count==expected.count,"completed/event count");require(memcmp(trace.exception,expected.exception,sizeof trace.exception)==0,"exception identity");for(U i=0;i<trace.count;++i)require(memcmp(&trace.events[i],&expected.events[i],sizeof(Event))==0,"arguments/intermediate device/channel/buffer/FP state");require(memcmp(&trace.final,&expected.final,sizeof(State))==0,"final canonical state and written output");require(memcmp(&trace.fpu,&expected.fpu,sizeof(Fpu))==0,"final x87");events_total+=trace.count;}}
    ++cases;
}
static void execute_case(){precision=cases%3==0?0:cases%3==1?2:3;rounding=cases%4;depth=(cases/12)%3*3;initial_status=cases&1?0x3f:0;value=cases&1?0x80000000:0xffffffff;compare();}
int main(){init();const U masks[]={0,1,2,0x80,0x55,0xaa,0xff},controls[]={0,1,2,4,8,16,32,64,128};
    kind=0;for(U started:{0u,1u,0x80000000u})for(U ch:{0u,2u,6u,15u,16u,63u})for(U f:{0u,1u,2u,3u,0x80000000u,0x80000001u})for(U mask:masks)for(U len:{0u,1u,127u,2047u}){initial_started=started;channel=ch;channel_flags=f;device_mask=mask;callback_mask=cases&1?0xff:0x55;output_length=len;edits=controls[cases%9];startup_mode=cases%3;execute_case();}
    kind=1;channel=6;for(U started:{0u,1u,0x80000000u})for(U f:{0u,1u})for(U mask:masks)for(U len:{0u,2047u})for(U edit:controls){initial_started=started;channel_flags=f;device_mask=mask;callback_mask=0xff;output_length=len;edits=edit;startup_mode=cases%3;execute_case();}
    __asm fninit
    printf("render_diagnostic_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
