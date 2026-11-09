// New553 scenes only; unchanged550 scaffold supplies accepted ABI/transport.
static B* kernel_slab;
alignas(16) static B kernel_area[2048];
static U kernel_input,kernel_output,kernel_state,kernel_period,kernel_gain,kernel_old,kernel_pattern,kernel_effect,kernel_alias,kernel_align,kernel_countdown,kernel_frames,kernel_rand_count,kernel_mode;
static U kernel_random_seed;
struct KernelSnapshot{B input[16],state[200],output[640],metadata[24];Fpu fp;};
struct KernelEvent{U value;KernelSnapshot before,after;};
struct KernelTrace{U abi,result,count;KernelEvent events[480];KernelSnapshot frames[3];B area[2048];Fpu fp;};
static KernelTrace kernel_actual,kernel_expected;
static void kernel_snapshot(KernelSnapshot& s){
    fpu(s.fp);std::memcpy(s.input,reinterpret_cast<void*>(kernel_input),16);std::memcpy(s.state,reinterpret_cast<void*>(kernel_state),200);std::memcpy(s.output,reinterpret_cast<void*>(kernel_output),640);if(kernel_mode)std::memcpy(s.metadata,reinterpret_cast<void*>(current_object+0xd8),24);else std::memset(s.metadata,0,24);
}
namespace porsche {
I __cdecl audio_resampler_rand_005a17c9(){
    require(kernel_actual.count<480,"finite controlled rand stream");auto& event=kernel_actual.events[kernel_actual.count++];kernel_snapshot(event.before);
    kernel_random_seed=kernel_random_seed*214013u+2531011u;const U value=(kernel_random_seed>>16)&0x7fffu;
    event.value=value;++kernel_rand_count;
    // Real cdecl0 endpoint effects: mutate consumed state and rounding in order.
    if(kernel_effect&1){write(kernel_state+0xc0,kernel_rand_count&3);write(kernel_state+0x68,0);write(kernel_state+0x6c,0x3fe00000);}
    if(kernel_effect&2){const unsigned short cw=static_cast<unsigned short>(0x7f|(precision<<8)|(((rounding+kernel_rand_count)%4)<<10));__asm fldcw cw}
    kernel_snapshot(event.after);return static_cast<I>(value);
}
}
static void kernel_init(){
    @DATA_CHECK553@
    kernel_slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(kernel_slab!=nullptr,"raw LPC kernel slab");
    const B raw_kernel[]={@KERNEL553@};std::memcpy(kernel_slab,raw_kernel,sizeof raw_kernel);
    const B raw_ftol[]={@FTOL553@};std::memcpy(kernel_slab+0x300,raw_ftol,sizeof raw_ftol);
    @KERNEL_RELOC553@
    // Actual550 raw caller must reach the original kernel, C++ reaches production.
    require(codec_slab[0x400+0xae]==0xe8,"actual550 kernel callsite");
    wr(codec_slab+0x400+0xaf,ptr(kernel_slab)-ptr(codec_slab+0x400+0xb3));
    require(FlushInstructionCache(GetCurrentProcess(),kernel_slab,4096)!=0,"raw LPC cache");
}
static void putdouble(U address,double value){std::memcpy(reinterpret_cast<void*>(address),&value,8);}
static void kernel_reset(){
    __asm fninit
    kernel_actual={};kernel_rand_count=0;kernel_random_seed=0x1234567u;
    std::memset(kernel_area,0xa5,sizeof kernel_area);
    kernel_input=ptr(kernel_area+32)+kernel_align;kernel_state=ptr(kernel_area+128)+kernel_align;kernel_output=ptr(kernel_area+512)+kernel_align;
    std::memset(reinterpret_cast<void*>(kernel_state),0,200);std::memset(reinterpret_cast<void*>(kernel_input),0,16);
    if(kernel_alias==1)kernel_input=kernel_state+0x20;
    if(kernel_alias==2)kernel_output=kernel_state+0x68;
    if(kernel_alias==3)kernel_output=kernel_input;
    if(kernel_alias==4)kernel_input=kernel_state;
    const unsigned short period=static_cast<unsigned short>(kernel_period);std::memcpy(reinterpret_cast<void*>(kernel_input),&period,2);
    reinterpret_cast<B*>(kernel_input)[2]=static_cast<B>(kernel_gain);
    for(U i=0;i<10;++i)reinterpret_cast<B*>(kernel_input)[i+3]=kernel_pattern==0?0:kernel_pattern==1?static_cast<B>((i&1)?-17:23):static_cast<B>((i*37+0x80)&255);
    if(kernel_old){putdouble(kernel_state,kernel_old==1?13.25:0.0);putdouble(kernel_state+8,kernel_old==1?0.3125:2.0);
        for(U i=0;i<10;++i){putdouble(kernel_state+0x18+i*8,(static_cast<I>(i)-4)*0.015625);putdouble(kernel_state+0x68+i*8,(static_cast<I>(i)-5)*0.125);}}
    write(kernel_state+0xc0,kernel_countdown);
}
static void kernel_execute(bool cpp){
    kernel_reset();seed();
    if(kernel_mode==0){
        const U args[3]={kernel_input,kernel_output,kernel_state};
        for(U frame=0;frame<kernel_frames;++frame){U ignored;kernel_actual.abi|=invoke(cpp?reinterpret_cast<void*>(&audio_resampler_decode_00597810):kernel_slab,args,3,ignored);kernel_snapshot(kernel_actual.frames[frame]);}
    }else{
        // Canonical504 ctor establishes all200 state bytes before actual550 use.
        reset(0);codec_kind=2;codec_alignment=kernel_align;codec_limit=1000;codec_request=0;codec_pending=codec_position=codec_carry=codec_chunks=codec_marker=codec_mutate=codec_alias=0;codec_reset();
        U params[8]={};params[5]=1;audio_mixer_construct_resampler_0059b830(current_object,params);
        for(U i=0;i<200;++i)require(reinterpret_cast<B*>(current_object+0x10)[i]==0,"canonical504 zero-state producer");
        kernel_state=current_object+0x10;kernel_output=current_object+0xf0;
        write(current_object+0xd8,kernel_input);write(current_object+0xdc,1000);write(current_object+0xe0,0);write(current_object+0xe4,0);
        hstore(current_object+0xe8,0);hstore(current_object+0xea,0);reinterpret_cast<B*>(current_object)[0xec]=0;
        for(U frame=0;frame<kernel_frames;++frame){const U args[5]={current_object,frame==0?17u:frame==1?160u:143u,0,ptr(kernel_area+1024),0};
            kernel_actual.abi|=invoke(cpp?reinterpret_cast<void*>(&audio_resampler_stream_process_0059b690):codec_slab+0x400,args,5,kernel_actual.result);kernel_snapshot(kernel_actual.frames[frame]);}
    }
    fpu(kernel_actual.fp);std::memcpy(kernel_actual.area,kernel_area,sizeof kernel_area);
}
static void kernel_check(){
    kernel_execute(false);kernel_expected=kernel_actual;kernel_execute(true);
    if(kernel_actual.abi||kernel_expected.abi||std::memcmp(&kernel_actual,&kernel_expected,sizeof kernel_actual)){
        const B* a=reinterpret_cast<const B*>(&kernel_actual);const B* b=reinterpret_cast<const B*>(&kernel_expected);U off=0;while(off<sizeof kernel_actual&&a[off]==b[off])++off;
        std::printf("divergence LPC case=%u mode=%u period=%u gain=%u old=%u pattern=%u countdown=%08x PC=%u RC=%u depth=%u effect=%u alias=%u align=%u frames=%u offset=%u bytes=%02x/%02x SW=%04x/%04x events=%u/%u\n",cases,kernel_mode,kernel_period,kernel_gain,kernel_old,kernel_pattern,kernel_countdown,precision,rounding,depth,kernel_effect,kernel_alias,kernel_align,kernel_frames,off,off<sizeof kernel_actual?a[off]:0,off<sizeof kernel_actual?b[off]:0,kernel_actual.fp.status,kernel_expected.fp.status,kernel_actual.count,kernel_expected.count);std::fflush(stdout);ExitProcess(1);
    }++cases;events_total+=kernel_actual.count;
}
int main(){
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);init();codec_init();kernel_init();
    kernel_frames=1;
    for(U period:{0u,1u,255u,256u,768u,3392u,65535u})for(U gain:{0u,1u,127u,255u})for(kernel_old=0;kernel_old<3;++kernel_old)for(kernel_pattern=0;kernel_pattern<3;++kernel_pattern){kernel_period=period;kernel_gain=gain;kernel_check();}
    kernel_frames=1;kernel_period=768;kernel_gain=255;kernel_old=1;kernel_pattern=2;
    for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc)for(U d:{0u,1u,4u,6u,7u})for(U countdown:{0u,1u,159u,0xffffffffu}){precision=pc;rounding=rc;depth=d;kernel_countdown=countdown;kernel_check();}
    depth=0;kernel_countdown=0;kernel_period=0;kernel_old=0;
    for(kernel_effect=0;kernel_effect<4;++kernel_effect)for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc){precision=pc;rounding=rc;kernel_check();}
    kernel_effect=0;precision=2;rounding=0;kernel_frames=3;kernel_period=3392;kernel_old=1;
    for(kernel_alias=0;kernel_alias<5;++kernel_alias)for(kernel_align=0;kernel_align<4;++kernel_align){kernel_check();}
    kernel_alias=kernel_align=0;kernel_mode=1;kernel_frames=3;depth=0;
    for(U period:{0u,768u,3392u})for(kernel_pattern=0;kernel_pattern<3;++kernel_pattern)for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc){kernel_period=period;precision=pc;rounding=rc;kernel_check();}
    __asm fninit
    std::printf("audio_resampler_kernel_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
