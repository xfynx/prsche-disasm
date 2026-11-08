// Run552 native comparison harness. Included by the generated native-fixture.cpp.in
// after the executable slab and its relocations are prepared.
static U cases_552,events_552;
static U seed_552=0x13572468u;
static U next_552(){seed_552=seed_552*1664525u+1013904223u;return seed_552>>9;}
static float rnd_552(){return (static_cast<float>(static_cast<I>(next_552()%4001u))-2000.0f)/256.0f;}
alignas(64) static B orig[0x10000];
alignas(64) static B cpp[0x10000];
#define STATE 0x0000u
#define STREAM 0x2000u
#define OUTB 0x9000u
#define AUX 0xb000u
alignas(16) static B floating_area[512];
struct Fpu{unsigned short control,status;B tag,pad[3],values[80];U mxcsr;};
static Fpu fpu_orig,fpu_cpp;
static unsigned short control_552=0x027f;
static U mxcsr_552=0x1f80u;
static void fpu_capture(Fpu& f){
    __asm fxsave floating_area
    f.control=static_cast<unsigned short>(rd(floating_area));
    f.status=static_cast<unsigned short>(rd(floating_area+2));
    f.tag=floating_area[4];f.mxcsr=rd(floating_area+24);std::memset(f.pad,0,3);
    for(U i=0;i<8;++i){
        std::memcpy(f.values+i*10,floating_area+32+i*16,10);
        if((f.tag&(1u<<(((f.status>>11)+i)&7u)))==0)std::memset(f.values+i*10,0,10);
    }
}
static void fpu_begin(){
    __asm {
        fninit
        ldmxcsr mxcsr_552
        fldcw control_552
    }
}
static void fpu_end(Fpu& f){
    fpu_capture(f);
    __asm fninit
}
static void same_fpu(const char* why){
    // Porsche.exe has no fldcw in .text, so the original x87 runs at 0x027F
    // (53-bit precision). The recovered C++ compiles to SSE2 binary64 and must
    // leave the x87 control word untouched while matching the same rounding mode.
    if(fpu_orig.control!=fpu_cpp.control||fpu_cpp.control!=control_552||
       (fpu_orig.mxcsr&0x6000u)!=(fpu_cpp.mxcsr&0x6000u)){
        std::printf("divergence %s ctl=%04x/%04x want=%04x mx=%08x/%08x\n",why,
                    fpu_orig.control,fpu_cpp.control,control_552,fpu_orig.mxcsr,fpu_cpp.mxcsr);
        std::fflush(stdout);ExitProcess(1);
    }
    ++events_552;
}
static void same(const char* why,U base,U size){
    U shown=0;
    for(U i=0;i<size;++i){
        if(orig[base+i]!=cpp[base+i]){
            if(shown<6)std::printf("  diff %s offset %#x orig=%02x cpp=%02x\n",why,base+i,orig[base+i],cpp[base+i]);
            ++shown;
        }
    }
    if(shown){
        std::printf("divergence %s (%u bytes differ)\n",why,shown);
        std::fflush(stdout);ExitProcess(1);
    }
    ++cases_552;
}
static U stream_off_552;
static void seed_block(){
    std::memset(orig,0,sizeof(orig));
    for(U off=0x10u;off<0xd40u;off+=4u){const float v=rnd_552();std::memcpy(orig+off,&v,4);}
    for(U i=0;i<0x4000u;++i)orig[STREAM+i]=static_cast<B>(next_552());
}
static void mirror(){
    std::memcpy(cpp,orig,sizeof(orig));
    wr(orig+STATE,ptr(orig+STREAM)+stream_off_552+1u);
    wr(cpp+STATE,ptr(cpp+STREAM)+stream_off_552+1u);
    wr(orig+STATE+4u,orig[STREAM+stream_off_552]);
    wr(cpp+STATE+4u,orig[STREAM+stream_off_552]);
    wr(orig+STATE+8u,8u);
    wr(cpp+STATE+8u,8u);
}
static void same_state(const char* why){
    const U o=rd(orig+STATE),c=rd(cpp+STATE);
    require(o>=ptr(orig+STREAM)&&o<=ptr(orig+STREAM)+0x4000u,"orig bit pointer");
    require(c>=ptr(cpp+STREAM)&&c<=ptr(cpp+STREAM)+0x4000u,"cpp bit pointer");
    if(o-ptr(orig+STREAM)!=c-ptr(cpp+STREAM)){
        std::printf("divergence %s bit offset orig=%u cpp=%u\n",why,o-ptr(orig+STREAM),c-ptr(cpp+STREAM));
        std::fflush(stdout);ExitProcess(1);
    }
    if(rd(orig+STATE+4u)!=rd(cpp+STATE+4u)||rd(orig+STATE+8u)!=rd(cpp+STATE+8u)){
        std::printf("divergence %s payload %08x/%08x remaining %u/%u\n",why,
                    rd(orig+STATE+4u),rd(cpp+STATE+4u),rd(orig+STATE+8u),rd(cpp+STATE+8u));
        std::fflush(stdout);ExitProcess(1);
    }
    {
        static const U regions[][2]={{4,0x140},{0x140,0x170},{0x170,0x680},{0x680,0xd40},{0xd40,0x1000}};
        for(const auto& region : regions){
            for(U off=region[0];off<region[1];++off){
                if(orig[STATE+off]!=cpp[STATE+off]){
                    U a=rd(orig+STATE+(off&~3u)),b=rd(cpp+STATE+(off&~3u));
                    std::printf("  region %#x..%#x first diff %#x words %08x/%08x\n",region[0],region[1],off,a,b);
                    break;
                }
            }
        }
    }
    same(why,STATE+4u,0xffcu);
}
using DecodeFn=void(__cdecl*)(U,U);
using DequantFn=void(__cdecl*)(U,U,U,I);
using SkipFn=void(__cdecl*)(U,U);
using SmoothFn=void(__cdecl*)(U);
using SynthFn=void(__cdecl*)(U,U,I);
using WindowFn=void(__cdecl*)(U,U);
using InitFn=void(__cdecl*)(U,U);
#define ORIG_DECODE reinterpret_cast<DecodeFn>(slab+OFF_59A910)
#define ORIG_DEQUANT reinterpret_cast<DequantFn>(slab+OFF_59ABE0)
#define ORIG_SKIP reinterpret_cast<SkipFn>(slab+OFF_59AD80)
#define ORIG_SMOOTH reinterpret_cast<SmoothFn>(slab+OFF_59ADC0)
#define ORIG_SYNTH reinterpret_cast<SynthFn>(slab+OFF_59AE00)
#define ORIG_WINDOW reinterpret_cast<WindowFn>(slab+OFF_59B580)
#define ORIG_INIT reinterpret_cast<InitFn>(slab+OFF_59A800)
static void scene_skip(){
    static const U rounds[]={0,1,2,3,4,7,8,12,31};
    for(U bits : rounds){
        for(U shape=0;shape<3;++shape){
            std::memset(orig,0,sizeof(orig));
            for(U i=0;i<0x4000u;++i)orig[STREAM+i]=static_cast<B>(next_552());
            const U remaining=shape==0?8u:shape==1?next_552()&31u:next_552()&7u;
            wr(orig+STATE+4u,next_552());
            wr(orig+STATE+8u,remaining);
            wr(orig+STATE,ptr(orig+STREAM));
            std::memcpy(cpp,orig,sizeof(orig));
            wr(cpp+STATE,ptr(cpp+STREAM));
            fpu_begin();ORIG_SKIP(ptr(orig+STATE),bits);fpu_end(fpu_orig);
            fpu_begin();audio_coded_skip_bits_0059ad80(ptr(cpp+STATE),bits);fpu_end(fpu_cpp);
            same_fpu("skip fpu");
            same_state("skip bits");
        }
    }
}
static void scene_smooth(){
    for(U round=0;round<4;++round){
        seed_block();
        for(U i=0;i<0x300u;i+=4u){const float v=rnd_552();std::memcpy(orig+AUX+i,&v,4);}
        std::memcpy(cpp,orig,sizeof(orig));
        fpu_begin();ORIG_SMOOTH(ptr(orig+AUX)+0x14u-round);fpu_end(fpu_orig);
        fpu_begin();audio_coded_smooth_0059adc0(ptr(cpp+AUX)+0x14u-round);fpu_end(fpu_cpp);
        same_fpu("smooth fpu");
        same("smooth",AUX,0x300u);
    }
}
static void scene_dequant(U flag){
    for(U round=0;round<8;++round){
        seed_block();
        stream_off_552=(next_552()%64u);
        wr(orig+STATE+0xcu,static_cast<U>(next_552()%40u));
        for(U i=0;i<0x1b0u;i+=4u){const float v=rnd_552();std::memcpy(orig+AUX+i,&v,4);}
        mirror();
        std::memcpy(orig+OUTB,orig+AUX,0x1b0u);std::memcpy(cpp+OUTB,cpp+AUX,0x1b0u);
        fpu_begin();std::printf("dq orig f=%u r=%u off=%u\n",flag,round,stream_off_552);
        ORIG_DEQUANT(ptr(orig+STATE),flag,ptr(orig+OUTB),2);fpu_end(fpu_orig);
        std::printf("dq cpp\n");
        fpu_begin();audio_coded_dequantize_0059abe0(ptr(cpp+STATE),flag,ptr(cpp+OUTB),2);fpu_end(fpu_cpp);
        std::printf("dq done\n");
        same_fpu("dequant fpu");
        same_state("dequant state");
        same("dequant output",OUTB,0x1b0u);
    }
}
static void scene_window(){
    for(U round=0;round<6;++round){
        seed_block();
        for(U i=0;i<12u;++i){const float v=rnd_552();std::memcpy(orig+AUX+i*4,&v,4);}
        for(U i=0;i<12u;++i){const float v=rnd_552();std::memcpy(orig+AUX+0x40+i*4,&v,4);}
        std::memcpy(cpp,orig,sizeof(orig));
        fpu_begin();ORIG_WINDOW(ptr(orig+AUX),ptr(orig+AUX+0x40));fpu_end(fpu_orig);
        fpu_begin();audio_coded_window_0059b580(ptr(cpp+AUX),ptr(cpp+AUX+0x40));fpu_end(fpu_cpp);
        same_fpu("window fpu");
        same("window",AUX,0x80u);
    }
}
static void scene_synth(){
    static const U counts[][2]={{0,1},{0xc,1},{0x18,1},{0x24,0x21}};
    for(U round=0;round<3;++round){
        seed_block();
        for(U i=0;i<0x1000u;i+=4u){const float v=rnd_552();std::memcpy(orig+STATE+i,&v,4);}
        for(U i=0;i<12u;++i){const float v=rnd_552();std::memcpy(orig+STATE+0x110+i*4,&v,4);}
        for(U i=0;i<12u;++i){const float v=rnd_552();std::memcpy(orig+STATE+0x140+i*4,&v,4);}
        std::memcpy(cpp,orig,sizeof(orig));
        for(const auto& item : counts){
            fpu_begin();ORIG_SYNTH(ptr(orig+STATE),item[0],static_cast<I>(item[1]));fpu_end(fpu_orig);
            fpu_begin();audio_coded_synthesize_0059ae00(ptr(cpp+STATE),item[0],static_cast<I>(item[1]));fpu_end(fpu_cpp);
            same_fpu("synthesis fpu");
            same("synthesis state",STATE,0x1000u);
        }
    }
}
static void scene_frames(U init_first,U frames){
    for(U round=0;round<4;++round){
        seed_block();
        stream_off_552=(next_552()%96u);
        wr(orig+STATE+0xcu,static_cast<U>(next_552()%40u));
        mirror();
        fpu_begin();
        if(init_first)ORIG_INIT(ptr(orig+STREAM)+stream_off_552,ptr(orig+STATE));
        for(U i=0;i<frames;++i)ORIG_DECODE(ptr(orig+STATE),0);
        fpu_end(fpu_orig);
        fpu_begin();
        if(init_first)audio_adpcm_initialize_0059a800(ptr(cpp+STREAM)+stream_off_552,ptr(cpp+STATE));
        for(U i=0;i<frames;++i)audio_coded_decode_0059a910(ptr(cpp+STATE),0);
        fpu_end(fpu_cpp);
        same_fpu("frames fpu");
        same_state("frames state");
        ++events_552;
    }
}
static void scene_fpu_modes(){
    for(U rc=0;rc<4;++rc){
        control_552=static_cast<unsigned short>(0x027f|(rc<<10));
        mxcsr_552=0x1f80u|(rc<<13);
        seed_block();
        stream_off_552=(next_552()%96u);
        wr(orig+STATE+0xcu,static_cast<U>(next_552()%40u));
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("fpu-mode fpu");
        same_state("fpu-mode state");
        control_552=0x027fu;
        mxcsr_552=0x1f80u;
        events_552+=8;
    }
}
static void put_bits(B* stream,U bit,U width,U value){
    for(U i=0;i<width;++i)if((value>>i)&1u)stream[(bit+i)/8u]=static_cast<B>(stream[(bit+i)/8u]|(1u<<((bit+i)%8u)));
}
static void scene_field_stream(U mask){
    static const U starts[4]={64,192,320,448};
    for(U round=0;round<4;++round){
        seed_block();
        std::memset(orig+STREAM,0,0x4000);
        for(const U start : starts){
            put_bits(orig+STREAM,start,8,next_552()&0xffu);
            put_bits(orig+STREAM,start+8,4,next_552()&0xfu);
            put_bits(orig+STREAM,start+12,6,next_552()&0x3fu);
            put_bits(orig+STREAM,start+18,1,next_552()&1u);
            put_bits(orig+STREAM,start+19,1,next_552()&1u);
        }
        stream_off_552=0;
        wr(orig+STATE+0xcu,20u);
        if(mask&1u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(mask&2u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        if(mask&8u)std::memset(orig+STATE+0x170,0,0x510);
        if(mask&16u)for(U i=0;i<0x100u;i+=4u){const float one=1.0f;std::memcpy(orig+STATE+0x10+i,&one,4);}
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("field-stream fpu");
        same_state("field-stream state");
    }
}
static void scene_fields(U parity,U mode,U mask){
    for(U round=0;round<2;++round){
        seed_block();
        std::memset(orig+STREAM,0,0x4000);
        if(parity)put_bits(orig+STREAM,82,1,1);
        if(mode)put_bits(orig+STREAM,83,1,1);
        stream_off_552=0;
        wr(orig+STATE+0xcu,20u);
        if(mask&1u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(mask&2u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        if(mask&8u)std::memset(orig+STATE+0x170,0,0x510);
        if(mask&16u)for(U i=0;i<0x100u;i+=4u){const float one=1.0f;std::memcpy(orig+STATE+0x10+i,&one,4);}
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("fields fpu");
        same_state("fields state");
    }
}
static void scene_bytes(U header_zero,U blocks_zero,U mask){
    for(U round=0;round<2;++round){
        seed_block();
        if(header_zero)std::memset(orig+STREAM,0,8);
        if(blocks_zero)std::memset(orig+STREAM+8,0,0x4000-8);
        stream_off_552=0;
        wr(orig+STATE+0xcu,20u);
        if(mask&1u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(mask&2u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        if(mask&8u)std::memset(orig+STATE+0x170,0,0x510);
        if(mask&16u)for(U i=0;i<0x100u;i+=4u){const float one=1.0f;std::memcpy(orig+STATE+0x10+i,&one,4);}
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("bytes fpu");
        same_state("bytes state");
    }
}
static void scene_bits(U bit,U width,U value,U scale_zero){
    for(U round=0;round<2;++round){
        seed_block();
        std::memset(orig+STREAM,0,0x4000);
        put_bits(orig+STREAM,bit,width,value);
        stream_off_552=0;
        wr(orig+STATE+0xcu,20u);
        if(scale_zero)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("bits fpu");
        same_state("bits state");
    }
}
static void scene_zero_stream(U mask){
    for(U round=0;round<2;++round){
        seed_block();
        std::memset(orig+STREAM,0,0x4000);
        stream_off_552=0;
        wr(orig+STATE+0xcu,20u);
        if(mask&1u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(mask&2u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("zero-stream fpu");
        same_state("zero-stream state");
    }
}
static void scene_probe(U mask){
    for(U round=0;round<4;++round){
        seed_block();
        stream_off_552=(next_552()%96u);
        wr(orig+STATE+0xcu,static_cast<U>(next_552()%40u));
        if(mask&1u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(mask&2u)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        if(mask&4u)for(U i=0;i<0x100u;i+=4u)std::memset(orig+STATE+0x10+i,0,4);
        if(mask&8u)std::memset(orig+STATE+0x170,0,0x510);
        if(mask&16u)for(U i=0;i<0x100u;i+=4u){const float one=1.0f;std::memcpy(orig+STATE+0x10+i,&one,4);}
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("probe fpu");
        if(round==0){
            for(U i=0;i<8;++i)std::printf("out%d %08x %08x\n",i,
                rd(orig+STATE+0x680+i*4),rd(cpp+STATE+0x680+i*4));
        }
        same_state("probe state");
    }
}
static void scene_flat(U zero_matrix,U zero_scale){
    for(U round=0;round<4;++round){
        seed_block();
        stream_off_552=(next_552()%96u);
        wr(orig+STATE+0xcu,static_cast<U>(next_552()%40u));
        if(zero_matrix)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x140+i*4,0,4);
        if(zero_scale)for(U i=0;i<12u;++i)std::memset(orig+STATE+0x110+i*4,0,4);
        mirror();
        fpu_begin();ORIG_DECODE(ptr(orig+STATE),0);fpu_end(fpu_orig);
        fpu_begin();audio_coded_decode_0059a910(ptr(cpp+STATE),0);fpu_end(fpu_cpp);
        same_fpu("flat fpu");
        same_state("flat state");
    }
}
int main(){
    std::setvbuf(stdout,nullptr,_IONBF,0);
    setup_slab();
    SetUnhandledExceptionFilter([](EXCEPTION_POINTERS* p)->LONG{
        std::printf("fault %p slab_off=%#x code=%08x\n",p->ExceptionRecord->ExceptionAddress,
                    static_cast<U>(reinterpret_cast<U>(p->ExceptionRecord->ExceptionAddress)-ptr(slab)),
                    p->ExceptionRecord->ExceptionCode);
        std::fflush(stdout);
        return EXCEPTION_EXECUTE_HANDLER;
    });
    std::printf("scene skip\n");scene_skip();
    std::printf("scene smooth\n");scene_smooth();
    std::printf("scene dequant1\n");scene_dequant(1);
    std::printf("scene dequant0\n");scene_dequant(0);
    std::printf("scene window\n");scene_window();
    std::printf("scene synth\n");scene_synth();
    std::printf("scene zero-stream\n");scene_zero_stream(0);
    std::printf("scene bits-parity\n");scene_bits(82,1,1,0);
    std::printf("scene bits-mode\n");scene_bits(83,1,1,0);
    std::printf("scene bits-coeff\n");scene_bits(76,6,5,0);
    std::printf("scene bits-lag\n");scene_bits(64,8,100,0);
    std::printf("scene bits-lag255\n");scene_bits(64,8,255,0);
    std::printf("scene bits-lag0\n");scene_bits(64,8,0,0);
    std::printf("scene bits-step\n");scene_bits(72,4,8,0);
    std::printf("scene field-stream\n");scene_field_stream(1u|2u|8u|16u);
    std::printf("scene fields p1m0\n");scene_fields(1,0,1u|2u|8u|16u);
    std::printf("scene fields p1m1\n");scene_fields(1,1,1u|2u|8u|16u);
    std::printf("scene fields p0m1\n");scene_fields(0,1,1u|2u|8u|16u);
    std::printf("scene bytes-header-blockzeros\n");scene_bytes(0,1,1u|2u|8u|16u);
    std::printf("scene bytes-headerzeros\n");scene_bytes(1,0,1u|2u|8u|16u);
    std::printf("scene zero-stream-scale\n");scene_zero_stream(2u);
    std::printf("scene probe-scale-coef\n");scene_probe(1u|2u|4u);
    std::printf("scene probe-one-coef\n");scene_probe(1u|2u|8u|16u);
    std::printf("scene probe-scale-tape\n");scene_probe(1u|2u|8u);
    std::printf("scene flat01\n");scene_flat(0,1);
    std::printf("scene flat10\n");scene_flat(1,0);
    std::printf("scene flat00\n");scene_flat(0,0);
    std::printf("scene frames1\n");scene_frames(0,1);
    std::printf("scene frames2\n");scene_frames(0,2);
    std::printf("scene init1\n");scene_frames(1,1);
    std::printf("scene init3\n");scene_frames(1,3);
    std::printf("scene modes\n");scene_fpu_modes();
    std::printf("audio_coded_kernel_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases_552,events_552);
    std::fflush(stdout);
    return 0;
}
