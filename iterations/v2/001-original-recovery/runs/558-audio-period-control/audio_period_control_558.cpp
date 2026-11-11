// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// 565c70/90B,565cd0/137B,590250/56B are PARTIAL for upper address bits.
// All32 low-byte groups use exact sparse owners; no contiguous slot array.
// 590290/3B is complete. Pointer views are modern host transport, not PE data.
#include "audio_period_control_558.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original pointer width and genuine3B zero leaf require MSVC x86
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
alignas(4) std::uint8_t audio_period_sparse_006b4887[1]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a44[10]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a50[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a60[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a70[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a80[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4a90[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4aa0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4ab0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4ac0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4ad0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4ae0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4af0[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4b00[14]{}; // exact PE-loader-zero touched span
alignas(4) std::uint8_t audio_period_sparse_006b4b10[14]{}; // exact PE-loader-zero touched span
volatile B* const audio_period_value_views_558[32]={
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x158,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x168,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x178,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x188,
    audio_period_sparse_006b4a44+0x4,
    audio_period_sparse_006b4a50+0x8,
    audio_period_sparse_006b4a60+0x8,
    audio_period_sparse_006b4a70+0x8,
    audio_period_sparse_006b4a80+0x8,
    audio_period_sparse_006b4a90+0x8,
    audio_period_sparse_006b4aa0+0x8,
    audio_period_sparse_006b4ab0+0x8,
    audio_period_sparse_006b4ac0+0x8,
    audio_period_sparse_006b4ad0+0x8,
    audio_period_sparse_006b4ae0+0x8,
    audio_period_sparse_006b4af0+0x8,
    audio_period_sparse_006b4b00+0x8,
    audio_period_sparse_006b4b10+0x8,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x8,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x18,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x28,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x38,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x48,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x58,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x68,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x78,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x88,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x98,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xa8,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xb8,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xc8,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xd8
};
volatile B* const audio_period_byte4_views_558[32]={
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x15c,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x16c,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x17c,
    reinterpret_cast<volatile B*>(&audio_thread_callbacks_006b4a3c)+0x0,
    audio_period_sparse_006b4a44+0x8,
    audio_period_sparse_006b4a50+0xc,
    audio_period_sparse_006b4a60+0xc,
    audio_period_sparse_006b4a70+0xc,
    audio_period_sparse_006b4a80+0xc,
    audio_period_sparse_006b4a90+0xc,
    audio_period_sparse_006b4aa0+0xc,
    audio_period_sparse_006b4ab0+0xc,
    audio_period_sparse_006b4ac0+0xc,
    audio_period_sparse_006b4ad0+0xc,
    audio_period_sparse_006b4ae0+0xc,
    audio_period_sparse_006b4af0+0xc,
    audio_period_sparse_006b4b00+0xc,
    audio_period_sparse_006b4b10+0xc,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xc,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x1c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x2c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x3c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x4c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x5c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x6c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x7c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x8c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x9c,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xac,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xbc,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xcc,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xdc
};
volatile B* const audio_period_byte5_views_558[32]={
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x15d,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x16d,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x17d,
    reinterpret_cast<volatile B*>(&audio_thread_callbacks_006b4a3c)+0x1,
    audio_period_sparse_006b4a44+0x9,
    audio_period_sparse_006b4a50+0xd,
    audio_period_sparse_006b4a60+0xd,
    audio_period_sparse_006b4a70+0xd,
    audio_period_sparse_006b4a80+0xd,
    audio_period_sparse_006b4a90+0xd,
    audio_period_sparse_006b4aa0+0xd,
    audio_period_sparse_006b4ab0+0xd,
    audio_period_sparse_006b4ac0+0xd,
    audio_period_sparse_006b4ad0+0xd,
    audio_period_sparse_006b4ae0+0xd,
    audio_period_sparse_006b4af0+0xd,
    audio_period_sparse_006b4b00+0xd,
    audio_period_sparse_006b4b10+0xd,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xd,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x1d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x2d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x3d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x4d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x5d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x6d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x7d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x8d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x9d,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xad,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xbd,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xcd,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xdd
};
volatile B* const audio_period_arg4_views_558[32]={
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x160,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x170,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x180,
    reinterpret_cast<volatile B*>(&audio_thread_callbacks_006b4a3c)+0x4,
    audio_period_sparse_006b4a50+0x0,
    audio_period_sparse_006b4a60+0x0,
    audio_period_sparse_006b4a70+0x0,
    audio_period_sparse_006b4a80+0x0,
    audio_period_sparse_006b4a90+0x0,
    audio_period_sparse_006b4aa0+0x0,
    audio_period_sparse_006b4ab0+0x0,
    audio_period_sparse_006b4ac0+0x0,
    audio_period_sparse_006b4ad0+0x0,
    audio_period_sparse_006b4ae0+0x0,
    audio_period_sparse_006b4af0+0x0,
    audio_period_sparse_006b4b00+0x0,
    audio_period_sparse_006b4b10+0x0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x10,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x20,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x30,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x40,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x50,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x60,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x70,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x80,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x90,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xa0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xb0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xc0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xd0,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xe0
};
volatile B* const audio_period_arg5_views_558[32]={
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x164,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x174,
    reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x184,
    audio_period_sparse_006b4a44+0x0,
    audio_period_sparse_006b4a50+0x4,
    audio_period_sparse_006b4a60+0x4,
    audio_period_sparse_006b4a70+0x4,
    audio_period_sparse_006b4a80+0x4,
    audio_period_sparse_006b4a90+0x4,
    audio_period_sparse_006b4aa0+0x4,
    audio_period_sparse_006b4ab0+0x4,
    audio_period_sparse_006b4ac0+0x4,
    audio_period_sparse_006b4ad0+0x4,
    audio_period_sparse_006b4ae0+0x4,
    audio_period_sparse_006b4af0+0x4,
    audio_period_sparse_006b4b00+0x4,
    audio_period_sparse_006b4b10+0x4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x14,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x24,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x34,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x44,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x54,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x64,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x74,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x84,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0x94,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xa4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xb4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xc4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xd4,
    reinterpret_cast<volatile B*>(render_pixel_palette_006b4b20)+0xe4
};
volatile B* const audio_period_notify_views_558[32]={
    reinterpret_cast<volatile B*>(&audio_ds_notify_kind_006b4886)+0x0,
    audio_period_sparse_006b4887+0x0,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x0,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x1,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x2,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x3,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x4,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x5,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x6,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x7,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x8,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0x9,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xa,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xb,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xc,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xd,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xe,
    reinterpret_cast<volatile B*>(&audio_device_buffers_006b4888)+0xf,
    reinterpret_cast<volatile B*>(&audio_device_callback_006b4898)+0x0,
    reinterpret_cast<volatile B*>(&audio_device_callback_006b4898)+0x1,
    reinterpret_cast<volatile B*>(&audio_device_callback_006b4898)+0x2,
    reinterpret_cast<volatile B*>(&audio_device_callback_006b4898)+0x3,
    reinterpret_cast<volatile B*>(&audio_backend_voice_table_006b489c)+0x0,
    reinterpret_cast<volatile B*>(&audio_backend_voice_table_006b489c)+0x1,
    reinterpret_cast<volatile B*>(&audio_backend_voice_table_006b489c)+0x2,
    reinterpret_cast<volatile B*>(&audio_backend_voice_table_006b489c)+0x3,
    reinterpret_cast<volatile B*>(&audio_resource_map_count_006b48a0)+0x0,
    reinterpret_cast<volatile B*>(&audio_resource_map_count_006b48a0)+0x1,
    reinterpret_cast<volatile B*>(&audio_resource_map_count_006b48a0)+0x2,
    reinterpret_cast<volatile B*>(&audio_resource_map_count_006b48a0)+0x3,
    reinterpret_cast<volatile B*>(&audio_resource_map_006b48a4)+0x0,
    reinterpret_cast<volatile B*>(&audio_resource_map_006b48a4)+0x1
};
namespace {
// Volatile character representations preserve cross-owner aliases and field
// order. Atomic/inter-thread observations remain outside this native contract.
U load32(const volatile B* p){return U(p[0])|(U(p[1])<<8)|(U(p[2])<<16)|(U(p[3])<<24);}
void write32(volatile B* p,U value){p[0]=static_cast<B>(value);p[1]=static_cast<B>(value>>8);p[2]=static_cast<B>(value>>16);p[3]=static_cast<B>(value>>24);}
volatile B* device(){return reinterpret_cast<volatile B*>(&application_audio_device_state_006b48c0)+0x10;}
I signed_count(){const volatile B* p=device()+0xe4;const U value=U(p[0])|(U(p[1])<<8);return value<0x8000?static_cast<I>(value):static_cast<I>(value)-65536;}
I signed_byte(B value){return value<128?static_cast<I>(value):static_cast<I>(value)-256;}
}
__declspec(naked) I __cdecl audio_period_value_accept_00590290(U,U){
    __asm {
        xor eax,eax
        ret
    }
}
// Original565cd0: caller ignores EAX, but the genuine leaf's signed result
// controls the branch. The low24 upper address bits are not silently masked.
void __cdecl frame_services_boundary_00565cd0(U flags,U value){
    const U selector=flags&0xffffff1fu;
    if((flags&0xe0u)==0)flags|=0xe0u;
    if(flags&0x20u)*audio_period_byte4_views_558[selector]=static_cast<B>(value);
    if(flags&0x80u)*audio_period_byte5_views_558[selector]=static_cast<B>(value);
    if(audio_period_value_accept_00590290(flags,value)<0)return;
    if(device()[0xdc]==0)return;
    if(signed_count()<=0)return;
    U index=0,offset=0;
    do{
        const U channels=load32(device()+0x140);
        const volatile B* record=reinterpret_cast<const volatile B*>(channels+offset);
        const I setting=signed_byte(record[selector+0x45]);
        const U handle=load32(record);
        (void)audio_period_channel_notify_005902a0(handle,selector,setting);
        ++index;offset+=0x70u;
    }while(static_cast<I>(index)<signed_count());
}
I __cdecl audio_period_callback_set_00590250(U flags){
    const B active=device()[0xdc];
    const U selector=flags&0xffffff1fu; // exact original AND AL,1F semantics
    *audio_period_notify_views_558[selector]=static_cast<B>(flags);
    audio_device_callback_006b4898=reinterpret_cast<U>(&audio_period_callback_005901b0);
    if(active)audio_period_callback_005901b0(static_cast<I>(flags),load32(audio_period_value_views_558[selector]));
    return 0;
}
void __cdecl application_audio_period_control_00565c70(U flags,U value,U third,U fourth,U fifth){
    const U selector=flags&0xffffff1fu; // preserve the unproved upper address domain
    if((flags&0xe0u)==0)flags|=0xe0u;
    write32(audio_period_value_views_558[selector],third);
    write32(audio_period_arg4_views_558[selector],fourth);
    write32(audio_period_arg5_views_558[selector],fifth);
    (void)audio_period_callback_set_00590250(flags);
    frame_services_boundary_00565cd0(flags,third==0?0:value);
}
}
