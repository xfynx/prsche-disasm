// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run552: original 0059a910 frame decoder and its five children.
// The original computes every x87 operation at 53-bit precision: Porsche.exe has
// no fldcw/fnstcw in .text and a Windows process starts with control word 0x027F
// (precision control 53 bits). The recovered expressions therefore use binary64
// intermediates at exactly the original operation order and round to float only
// where the original stores a dword. No guards, clamps or bounds were added.
#include "audio_coded_kernel_552.hpp"
#include "../504-audio-coded-constructors/audio_coded_constructors_504.hpp"
#include "../519-audio-stream-capture-fill/audio_stream_capture_fill_519.hpp"
#include <cstring>
namespace porsche {
#include "audio_coded_tables_552.inc"
namespace {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U word(U p){U v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
void store(U p,U v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
float f32(U p){float v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
float table(const std::uint32_t* t,U index){return f32(reinterpret_cast<U>(t)+index*4u);}
// One original x87 product is a binary64 result; keep it out of float promotions.
double prod(float a,float b){return static_cast<double>(a)*static_cast<double>(b);}
// One fully unrolled original 0059ae00 loop iteration (extract.py generated).
#include "audio_coded_matrix_552.inc"
// 0059ad80: consume bits without mask; at most one byte refill.
void skip_bits(U state,U bits){
    U payload=word(state+4u);
    U remaining=word(state+8u);
    payload>>=bits&31u;
    remaining-=bits;
    store(state+8u,remaining);store(state+4u,payload);
    if(static_cast<I>(remaining)<8){
        const U pointer=word(state);
        const U next=*reinterpret_cast<const B*>(pointer);
        const U combined=(next<<(remaining&31u))|payload;
        store(state,pointer+1u);
        remaining+=8u;
        store(state+4u,combined);store(state+8u,remaining);
    }
}
}
void __cdecl audio_coded_skip_bits_0059ad80(U state,U bits){skip_bits(state,bits);}
// 0059adc0: 54-point symmetric 3-tap smoothing of one dequantized parity.
void __cdecl audio_coded_smooth_0059adc0(U base){
    float* f=reinterpret_cast<float*>(base);
    const double near=table(audio_coded_window_005c1808,1);
    const double mid=table(audio_coded_window_005c1808,2);
    const double far=table(audio_coded_window_005c1808,3);
    for(U i=0;i<54;++i){
        const U n=2u*i;
        double sum=(static_cast<double>(f[n-5])+static_cast<double>(f[n+5]))*far;
        sum=sum-(static_cast<double>(f[n-3])+static_cast<double>(f[n+3]))*mid;
        sum=sum+(static_cast<double>(f[n-1])+static_cast<double>(f[n+1]))*near;
        f[n]=static_cast<float>(sum);
    }
}
// 0059abe0: context byte table -> (next context, skip bits, level) records.
// flag!=0 decodes one parity in stride slots; flag==0 emits the 2-bit fallback.
void __cdecl audio_coded_dequantize_0059abe0(U state,U flag,U out,I stride){
    if(flag){
        U context=0;I index=0;
        for(;;){
            const U payload=word(state+4u)&0xffu;
            const U symbol=audio_coded_context_005e35c4[(context<<8)+payload];
            const U* record=audio_coded_level_005e37c8+symbol*3u;
            context=record[0];
            skip_bits(state,record[1]);
            if(symbol>3){
                store(out+static_cast<U>(index)*4u,record[2]);
                index+=stride;
            }else if(symbol>1){
                // Zero-run path: the original never adds the single stride here.
                U count=audio_adpcm_read_bits_0059a8c0(state,6)+7u;
                I limit=static_cast<I>(count*static_cast<U>(stride))+index;
                if(limit>0x6c)count=static_cast<U>((0x6c-index)/stride);
                if(static_cast<I>(count)>0){
                    U cell=out+static_cast<U>(index)*4u;
                    for(I n=0;n<static_cast<I>(count);++n){store(cell,0);cell+=static_cast<U>(stride)*4u;}
                    index+=static_cast<I>(count)*stride;
                }
            }else{
                I level=7;
                while(audio_adpcm_read_bits_0059a8c0(state,1)==1u)++level;
                const float value=(audio_adpcm_read_bits_0059a8c0(state,1)==1u)
                    ?static_cast<float>(level):static_cast<float>(-level);
                std::memcpy(reinterpret_cast<void*>(out+static_cast<U>(index)*4u),&value,4);
                index+=stride;
            }
            if(index>=0x6c)break;
        }
    }else{
        for(I index=0;index<0x6c;index+=stride){
            const U bits=word(state+4u)&3u;
            float value=0.0f;U skip=1;
            if(bits==1u){value=-2.0f;skip=2;}
            else if(bits==3u){value=2.0f;skip=2;}
            std::memcpy(reinterpret_cast<void*>(out+static_cast<U>(index)*4u),&value,4);
            skip_bits(state,skip);
        }
    }
}
// 0059b580: 12-output lattice recursion over source[0..11]; out is read back.
void __cdecl audio_coded_window_0059b580(U source,U out){
    const float* q=reinterpret_cast<const float*>(source);
    float* o=reinterpret_cast<float*>(out);
    float h[12],pre[12];
    for(U k=0;k<11;++k)h[k]=q[10u-k];
    h[11]=1.0f; // original stack cell esp+0x10 seeded with 1.0 before the loop
    for(U k=0;k<12;++k){
        double acc=-(static_cast<double>(h[0])*static_cast<double>(q[11]));
        for(U j=1;j<=11;++j){
            const double v=q[11u-j];
            acc=acc-v*static_cast<double>(h[j]);
            h[j-1u]=static_cast<float>(acc*v+static_cast<double>(h[j]));
        }
        h[11]=static_cast<float>(acc); // original fst esp+0x10 alias of the 12th cell
        pre[k]=static_cast<float>(acc);
        for(U j=0;j<k;++j)acc=acc-static_cast<double>(pre[k-1u-j])*static_cast<double>(o[j]);
        o[k]=static_cast<float>(acc);
    }
}
// 0059ae00: 12-value window then count blocks of 12 accumulated outputs.
void __cdecl audio_coded_synthesize_0059ae00(U state,U offset,I count){
    float window_values[12];
    audio_coded_window_0059b580(state+0x110u,reinterpret_cast<U>(window_values));
    float* matrix=reinterpret_cast<float*>(state+0x140u);
    float* out=reinterpret_cast<float*>(state+0x680u+offset*4u);
    for(I block=0;block<count;++block){
        audio_coded_matrix_block_0059ae00(window_values,matrix,out);
        out+=12;
    }
}
// 0059a910: one original coded-audio frame, 4x108 blended samples plus synthesis.
void __cdecl audio_coded_decode_0059a910(U state,U unused){
    (void)unused;
    alignas(16) B frame[0x240];
    float* d=reinterpret_cast<float*>(frame+0x2c);
    const U scale_index=audio_adpcm_read_bits_0059a8c0(state,6);
    const U sign=static_cast<I>(scale_index)<
                 static_cast<I>(word(state+0xcu))?1u:0u;
    const double quarter=table(&audio_coded_quarter_005b2468,0);
    d[0]=static_cast<float>((static_cast<double>(table(audio_coded_scale_005e34c4,scale_index))-
        static_cast<double>(f32(state+0x110u)))*quarter);
    for(U i=0;i<3;++i)
        d[1u+i]=static_cast<float>((static_cast<double>(table(audio_coded_scale_005e34c4,
            audio_adpcm_read_bits_0059a8c0(state,6)))-static_cast<double>(f32(state+0x114u+i*4u)))*quarter);
    for(U i=0;i<8;++i)
        d[4u+i]=static_cast<float>((static_cast<double>(table(audio_coded_scale_005e34c4,
            16u+audio_adpcm_read_bits_0059a8c0(state,5)))-static_cast<double>(f32(state+0x120u+i*4u)))*quarter);
    U counter=0xd8u;
    float* out=reinterpret_cast<float*>(state+0x680u);
    do{
        const U lag=audio_adpcm_read_bits_0059a8c0(state,8);
        const U step=audio_adpcm_read_bits_0059a8c0(state,4);
        const float first=static_cast<float>(static_cast<double>(static_cast<unsigned long long>(step))*
                          static_cast<double>(table(audio_coded_window_005c1808,0)));
        const U coefficient=audio_adpcm_read_bits_0059a8c0(state,6);
        float second=f32(state+0x10u+coefficient*4u);
        const U parity=audio_adpcm_read_bits_0059a8c0(state,1)<<2;
        const U mode=audio_adpcm_read_bits_0059a8c0(state,1);
        audio_coded_dequantize_0059abe0(state,sign,reinterpret_cast<U>(frame+0x70u+parity),
                                        static_cast<I>(2));
        if(mode){
            for(U i=0;i<0x1b0u;i+=8u)store(reinterpret_cast<U>(frame)+0x74u-parity+i,0);
        }else{
            for(U i=0;i<5u;++i){
                store(reinterpret_cast<U>(frame)+0x5cu+i*4u,0);
                store(reinterpret_cast<U>(frame)+0x220u+i*4u,0);
            }
            audio_coded_smooth_0059adc0(reinterpret_cast<U>(frame)+0x74u-parity);
            second=static_cast<float>(static_cast<double>(second)*1.75);
        }
        const float* tape=reinterpret_cast<const float*>(state+0x170u);
        const float* decoded=reinterpret_cast<const float*>(frame+0x70u);
        const U base=counter-lag;
        for(U i=0;i<108u;++i)
            out[i]=static_cast<double>(first)*static_cast<double>(tape[base+i])+
                   static_cast<double>(second)*static_cast<double>(decoded[i]);
        out+=108;
        counter+=0x6cu;
    }while(counter<0x288u);
    audio_stream_copy_forward_00598a50(state+0x170u,state+0x830u,0x510u);
    for(U pass=0;pass<4;++pass){
        for(U i=0;i<12;++i){
            float* cell=reinterpret_cast<float*>(state+0x110u+i*4u);
            *cell=static_cast<float>(static_cast<double>(*cell)+static_cast<double>(d[i]));
        }
        audio_coded_synthesize_0059ae00(state,pass*0xcu,pass==3u?0x21:1);
    }
}
}
