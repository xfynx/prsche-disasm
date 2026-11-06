// Targeted new550 scenes use the unchanged534 transport/ABI/FPU scaffold.
// No historical534 scene is rerun. Kernels below are controlled opaque endpoints.
alignas(16) static B codec_area[4096];static B* codec_slab;
static U codec_kind,codec_request,codec_carry,codec_position,codec_limit,codec_pending,codec_chunks,codec_marker,codec_mutate,codec_alias,codec_alignment,codec_calls;
static bool codec_cpp;
struct CodecState{B object[4096],data[4096],records[2][256];U slots[16],calls;Fpu fp;};
struct CodecEvent{U tag,args[4];CodecState state;};
struct CodecTrace{U result,abi,count;CodecEvent events[40];CodecState state;};
static CodecTrace codec_actual,codec_expected;
static U codec_base(){return codec_kind==0?0xd4c:codec_kind==1?0xd50:0xdc;}
static U codec_processed(){return codec_kind==1?0xd58:0xe4;}
static void codec_snapshot(CodecState& s){std::memcpy(s.object,codec_area,sizeof codec_area);std::memcpy(s.data,data,sizeof data);for(U t=0;t<2;++t)std::memcpy(s.records[t],reinterpret_cast<void*>(records[t]),256);std::memcpy(s.slots,audio_stream_slots_006b7cc0,64);s.calls=codec_calls;fpu(s.fp);}
static void codec_event(U tag,U a=0,U b=0,U c=0,U d=0){require(codec_actual.count<40,"codec finite events");auto& e=codec_actual.events[codec_actual.count++];e.tag=tag;e.args[0]=a;e.args[1]=b;e.args[2]=c;e.args[3]=d;codec_snapshot(e.state);}
static void codec_control(){if(codec_mutate&32){unsigned short cw=static_cast<unsigned short>(0x7f|(precision<<8)|(((rounding+1)%4)<<10));__asm fldcw cw}}
static void codec_released(U value){
    codec_event(600,value);const U base=codec_base();
    if(codec_mutate&1)write(current_object+base,5);
    if(codec_mutate&2)hstore(current_object+base+12,1);
    if(codec_mutate&4)write(records[0]+96+8,ptr(data+1200));
    if(codec_mutate&8)audio_stream_slots_006b7cc0[0]=records[1];
    codec_control();
}
static void codec_consumed(U index,U count){
    codec_event(700,index,count);
    if(codec_mutate&1)write(current_object+codec_processed(),7);
    if(codec_mutate&2)write(current_object+(codec_kind==1?0xd54:0xe0),1);
    if(codec_mutate&4)write(current_object+codec_base(),0);
    codec_control();
}
static void codec_kernel(U a,U b,U c,U identity){
    codec_event(900+identity,a,b,c);++codec_calls;require(codec_calls<=8,"codec finite kernels");
    const U destination=identity==0?a+0x680:b,block=identity==0?432:160;
    for(U i=0;i<block;++i)write(destination+i*4u,0x00010001u+i*0x10001u);
    if(codec_kind==0){if(codec_mutate&1)write(current_object+0xd50,9);if(codec_mutate&2)write(current_object+0xd54,11);}
    else{const U base=codec_base();if(codec_mutate&1)write(current_object+base,5);if(codec_mutate&2)hstore(current_object+base+12,1);if(codec_mutate&4)write(current_object+codec_processed(),7);}
    codec_control();codec_event(910+identity,a,b,c);
}
namespace porsche {
void __cdecl audio_adpcm_decode_0059a910(U state,U flag){require(flag==0,"actual ADPCM second argument");codec_kernel(state,flag,0,0);}
void __cdecl audio_resampler_decode_00597810(U input,U output,U state){require(state==current_object+0x10&&output==current_object+0xf0,"actual resampler args");codec_kernel(input,output,state,1);}
}
static void codec_init(){
    codec_slab=static_cast<B*>(VirtualAlloc(nullptr,8192,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(codec_slab!=nullptr,"codec raw slab");
    @CODEC_RAW@
    @CODEC_RELOC@
    const B masks_raw[]={@MASKS550@};require(std::memcmp(masks_raw,audio_adpcm_bit_masks_005e34a0,36)==0,"raw canonical masks");
    const B scale_raw[]={@SCALE550@},factor_raw[]={@FACTOR550@},bias_raw[]={@BIAS550@};
    require(std::memcmp(scale_raw,&audio_adpcm_scale_005b2608,4)==0&&std::memcmp(factor_raw,&audio_adpcm_factor_scale_005b27b4,4)==0&&std::memcmp(bias_raw,&audio_adpcm_factor_bias_005c1804,4)==0,"raw canonical initializer scalars");
    require(FlushInstructionCache(GetCurrentProcess(),codec_slab,8192)!=0,"codec raw cache");
}
static void codec_reset(){
    codec_actual={};codec_calls=0;active_kind=100+codec_kind;current_object=ptr(codec_area)+128+codec_alignment;current_params=ptr(data+64);
    std::memset(codec_area,0x69,sizeof codec_area);for(U i=0;i<sizeof(data);++i)data[i]=static_cast<B>(i*17+31);
    for(U i=0;i<16;++i)audio_stream_slots_006b7cc0[i]=0;
    for(U t=0;t<2;++t){records[t]=ptr(record_bytes[t])+256;std::memset(reinterpret_cast<void*>(records[t]),0,256);
        hstore(records[t]+8,0xffff);hstore(records[t]+0x10,codec_chunks);hstore(records[t]+0x18,4);hstore(records[t]+0x1a,0);hstore(records[t]+0x1c,0);
        write(records[t]+0x20,0x100);write(records[t]+0x24,0x80000003);write(records[t]+0x2c,ptr(reinterpret_cast<void*>(&released)));write(records[t]+0x30,ptr(reinterpret_cast<void*>(&consumed)));
        for(U n=0;n<4;++n){const U cell=records[t]+(n+3)*24;write(cell+4,codec_limit?codec_limit:7);write(cell+8,ptr(data+1024+t*176+n*16));}
    }
    audio_stream_slots_006b7cc0[0]=records[0];audio_stream_slots_006b7cc0[1]=records[1];
    for(U i=0;i<512;++i)data[1024+i]=static_cast<B>(i*13+7);for(U i=0;i<16;++i){data[1024+i*16]=static_cast<B>(codec_marker);data[1200+i*16]=static_cast<B>(codec_marker);}
    if(codec_kind==0){write(current_object+0xd4c,codec_limit);write(current_object+0xd50,codec_carry);write(current_object+0xd54,codec_position);}
    else{const U base=codec_base();write(current_object+(codec_kind==1?0xd4c:0xd8),ptr(data+1024));write(current_object+base,codec_limit);write(current_object+base+4,0);write(current_object+codec_processed(),codec_pending);hstore(current_object+base+12,codec_position);hstore(current_object+base+14,codec_carry);reinterpret_cast<B*>(current_object)[codec_kind==1?0xd60:0xec]=0;}
    const U block=codec_kind==2?160:432,start=codec_kind==2?0xf0:0x68c;
    for(U i=0;i<block;++i)write(current_object+start+i*4u,0x00010001u+i*0x10001u);
    // Finite metadata alias cases use one copied small word, never guessed guards.
    // A copied metadata alias changes cached carry1 to2 and cursor toFFFF:
    // ADPCM must reload carry, both stream cursors must wrap after increment.
    write(current_object+start+(block-1)*4u,0x0002ffff);
}
static void codec_execute(bool cpp){
    codec_cpp=cpp;codec_reset();U output=ptr(data+2048)+codec_alignment;
    if(codec_alias==1)output=current_object+(codec_kind==2?0xf0:0x68c);
    if(codec_alias==2)output=ptr(data+1024)+codec_alignment;
    if(codec_alias==3)output=current_object+(codec_kind==0?0xd50:codec_kind==1?0xd5c:0xe8);
    const U args[5]={current_object,codec_request,0x12345678,output,0x87654321};
    void* fn=cpp?(codec_kind==0?reinterpret_cast<void*>(&audio_adpcm_process_00597e30):codec_kind==1?reinterpret_cast<void*>(&audio_adpcm_stream_process_0059c1e0):reinterpret_cast<void*>(&audio_resampler_stream_process_0059b690)):codec_slab+(codec_kind==0?0:codec_kind==1?0x200:0x400);
    seed();codec_actual.abi=invoke(fn,args,5,codec_actual.result);codec_snapshot(codec_actual.state);
}
static void codec_check(){
    codec_execute(false);codec_expected=codec_actual;codec_execute(true);
    if(codec_actual.abi||codec_expected.abi||std::memcmp(&codec_actual,&codec_expected,sizeof codec_actual)!=0){const B* a=reinterpret_cast<const B*>(&codec_actual);const B* b=reinterpret_cast<const B*>(&codec_expected);U n=0;while(n<sizeof codec_actual&&a[n]==b[n])++n;std::printf("divergence codec case=%u kind=%u request=%08x carry=%u position=%08x limit=%08x pending=%u chunks=%u marker=%u mutate=%u alias=%u align=%u byte=%u actual=%02x original=%02x\n",cases,codec_kind,codec_request,codec_carry,codec_position,codec_limit,codec_pending,codec_chunks,codec_marker,codec_mutate,codec_alias,codec_alignment,n,n<sizeof codec_actual?a[n]:0,n<sizeof codec_actual?b[n]:0);std::fflush(stdout);ExitProcess(1);}
    ++cases;events_total+=codec_actual.count;
}
int main(){
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);init();codec_init();
    codec_pending=codec_chunks=codec_marker=codec_mutate=codec_alias=codec_alignment=0;
    codec_kind=0;for(U position:{0u,1u,100u,0x7fffffffu,0x80000000u,0xfffffff0u})for(U span:{0u,1u,17u,433u})for(U count:{0u,1u,2u,17u,431u,432u,433u})for(U carry:{0u,1u,7u,432u}){
        codec_position=position;codec_limit=position+span;codec_request=count;codec_carry=carry;codec_check();}
    for(codec_kind=1;codec_kind<3;++codec_kind)for(U position:{0u,1u,7u,0xffffu})for(U limit:{0u,1u,7u,161u,433u})for(U count:{0u,1u,2u,17u,159u,160u,161u,433u,0xffffffffu})for(U carry:{0u,1u,7u})for(U chunks:{0u,1u,3u}){
        codec_position=position;codec_limit=limit;codec_request=count;codec_carry=carry;codec_chunks=chunks;codec_marker=cases&1;codec_pending=cases&2?7:0;codec_check();}
    for(codec_kind=0;codec_kind<3;++codec_kind)for(codec_mutate=0;codec_mutate<64;++codec_mutate){codec_position=0;codec_limit=codec_kind?7:433;codec_request=17;codec_carry=0;codec_chunks=2;codec_pending=7;codec_marker=codec_mutate&1;codec_check();}
    codec_mutate=0;for(codec_kind=0;codec_kind<3;++codec_kind)for(codec_alias=0;codec_alias<4;++codec_alias)for(codec_alignment=0;codec_alignment<4;++codec_alignment){codec_position=0;codec_limit=433;codec_request=codec_alias==3?1:17;codec_carry=codec_alias==3?1:7;codec_chunks=0;codec_pending=0;codec_marker=0;codec_check();}
    codec_alias=codec_alignment=codec_mutate=0;for(codec_kind=0;codec_kind<3;++codec_kind)for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc)for(U d:{0u,1u,6u,7u}){precision=pc;rounding=rc;depth=d;codec_position=0;codec_limit=7;codec_request=17;codec_carry=0;codec_chunks=2;codec_marker=1;codec_pending=7;codec_check();}
    __asm fninit
    std::printf("audio_codec_process_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
