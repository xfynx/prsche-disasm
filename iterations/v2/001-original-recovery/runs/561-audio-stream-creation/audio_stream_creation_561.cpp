// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Eight original bodies909B; exact integer/state/order and80B original zero state.
#include "audio_stream_creation_561.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 ABI/stack/wrap semantics require MSVC x86
#endif
namespace porsche {
AudioStreamServiceStorage561 audio_stream_service_storage_006b7740{};
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
// 005673d0/384B SHA256 a4146c8718ee20b9dbad9b6b9f591018509a8c4261ff035482db37497f480727
__declspec(naked) I __cdecl application_audio_stream_create_005673d0(B*,U,U,U,U,U,U){
    __asm {
        push ecx // 005673d0
        mov al, byte ptr [application_audio_device_state_006b48c0+0xec] // 005673d1
        push ebx // 005673d6
        push ebp // 005673d7
        push esi // 005673d8
        test al, al // 005673d9
        push edi // 005673db
        jne L005673e9 // 005673dc
        pop edi // 005673de
        pop esi // 005673df
        pop ebp // 005673e0
        mov eax, 0xfffffff6 // 005673e1
        pop ebx // 005673e6
        pop ecx // 005673e7
        ret // 005673e8
    L005673e9:
        xor ecx, ecx // 005673e9
        mov eax, offset audio_stream_service_storage_006b7740 // 005673eb
        mov dword ptr [esp + 0x10], ecx // 005673f0
    L005673f4:
        cmp dword ptr [eax], 0 // 005673f4
        je L00567413 // 005673f7
        add eax, 4 // 005673f9
        inc ecx // 005673fc
        cmp eax, offset audio_stream_service_storage_006b7740+0x40 // 005673fd
        jl L005673f4 // 00567402
        pop edi // 00567404
        pop esi // 00567405
        pop ebp // 00567406
        mov dword ptr [esp + 4], ecx // 00567407
        mov eax, 0xfffffff7 // 0056740b
        pop ebx // 00567410
        pop ecx // 00567411
        ret // 00567412
    L00567413:
        mov ebx, dword ptr [esp + 0x1c] // 00567413
        mov esi, dword ptr [esp + 0x24] // 00567417
        mov edx, dword ptr [esp + 0x20] // 0056741b
        mov edi, dword ptr [esp + 0x28] // 0056741f
        lea eax, [ebx + ebx*4] // 00567423
        mov dword ptr [esp + 0x10], ecx // 00567426
        mov ebp, esi // 0056742a
        mov ecx, 0xffffff08 // 0056742c
        lea eax, [ebx + eax*2] // 00567431
        add esi, 0xf8 // 00567434
        shl eax, 2 // 0056743a
        sub ecx, eax // 0056743d
        mov dword ptr [ebp], esi // 0056743f
        push edx // 00567442
        add esi, eax // 00567443
        add edi, ecx // 00567445
        call audio_stream_storage_bytes_005611e0 // 00567447
        mov dword ptr [esp + 0x28], eax // 0056744c
        mov eax, dword ptr [esp + 0x24] // 00567450
        push eax // 00567454
        call audio_stream_storage_bytes_005611e0 // 00567455
        push eax // 0056745a
        push esi // 0056745b
        push offset audio_stream_service_consumed_00566e40 // 0056745c
        push offset audio_stream_service_release_00566e10 // 00567461
        call audio_stream_construct_00561200 // 00567466
        add esp, 0x18 // 0056746b
        mov dword ptr [ebp + 0xc], eax // 0056746e
        mov eax, dword ptr [ebp + 0xc] // 00567471
        test eax, eax // 00567474
        jge L00567481 // 00567476
        mov eax, dword ptr [ebp + 0xc] // 00567478
        pop edi // 0056747b
        pop esi // 0056747c
        pop ebp // 0056747d
        pop ebx // 0056747e
        pop ecx // 0056747f
        ret // 00567480
    L00567481:
        mov ecx, dword ptr [ebp + 0xc] // 00567481
        mov eax, dword ptr [esp + 0x30] // 00567484
        mov dl, byte ptr [esp + 0x10] // 00567488
        test eax, eax // 0056748c
        mov byte ptr [ecx + audio_stream_service_storage_006b7740+0x40], dl // 0056748e
        je L005674a3 // 00567494
        mov eax, dword ptr [esp + 0x2c] // 00567496
        mov dword ptr [ebp + 4], eax // 0056749a
        mov byte ptr [ebp + 0x18], 1 // 0056749d
        jmp L005674e4 // 005674a1
    L005674a3:
        mov eax, dword ptr [esp + 0x24] // 005674a3
        lea ecx, [ebx + 2] // 005674a7
        sub edi, eax // 005674aa
        add eax, esi // 005674ac
        push edi // 005674ae
        push eax // 005674af
        push 1 // 005674b0
        push 1 // 005674b2
        push ecx // 005674b4
        call audio_stream_codec_create_0056aff0 // 005674b5
        mov dword ptr [ebp + 4], eax // 005674ba
        mov byte ptr [ebp + 0x18], 0 // 005674bd
        push eax // 005674c1
        call audio_stream_codec_frames_0056c840 // 005674c2
        mov ecx, eax // 005674c7
        mov eax, 0x55555556 // 005674c9
        imul ecx // 005674ce
        mov ecx, dword ptr [ebp + 4] // 005674d0
        mov eax, edx // 005674d3
        shr eax, 0x1f // 005674d5
        add edx, eax // 005674d8
        push edx // 005674da
        push ecx // 005674db
        call audio_stream_codec_set_005912e0 // 005674dc
        add esp, 0x20 // 005674e1
    L005674e4:
        mov dword ptr [ebp + 0x10], 0 // 005674e4
        mov dword ptr [ebp + 8], 0xffffffff // 005674eb
        mov byte ptr [ebp + 0x15], bl // 005674f2
        mov esi, dword ptr [esp + 0x18] // 005674f5
        lea edi, [ebp + 0xdc] // 005674f9
        mov ecx, 7 // 005674ff
        rep movsd // 00567504
        mov byte ptr [ebp + 0x19], 0 // 00567506
        call audio_stream_service_count_005673b0 // 0056750a
        test eax, eax // 0056750f
        jne L0056752a // 00567511
        push offset audio_stream_service_tick_00567270 // 00567513
        call audio_stream_service_register_0058ff50 // 00567518
        add esp, 4 // 0056751d
        mov dword ptr [application_audio_device_state_006b48c0+0x14c], offset audio_stream_service_shutdown_00566d40 // 00567520
    L0056752a:
        mov esi, dword ptr [esp + 0x10] // 0056752a
        mov dword ptr [ebp + 0x9c], 0 // 0056752e
        push esi // 00567538
        mov dword ptr [esi*4 + audio_stream_service_storage_006b7740], ebp // 00567539
        call audio_stream_service_reset_00567740 // 00567540
        add esp, 4 // 00567545
        mov eax, esi // 00567548
        pop edi // 0056754a
        pop esi // 0056754b
        pop ebp // 0056754c
        pop ebx // 0056754d
        pop ecx // 0056754e
        ret // 0056754f
    }
}
// 00567690/135B SHA256 2e6d1b32b6fd2f55e76dece000ab09e9aeaed63edf827ef01a02337355683eb0
__declspec(naked) I __cdecl application_audio_stream_stop_00567690(U){
    __asm {
        mov al, byte ptr [application_audio_device_state_006b48c0+0xec] // 00567690
        push esi // 00567695
        test al, al // 00567696
        push edi // 00567698
        jne L005676a3 // 00567699
        pop edi // 0056769b
        mov eax, 0xfffffff6 // 0056769c
        pop esi // 005676a1
        ret // 005676a2
    L005676a3:
        mov edi, dword ptr [esp + 0xc] // 005676a3
        push edi // 005676a7
        call audio_stream_service_lookup_00566d60 // 005676a8
        mov esi, eax // 005676ad
        add esp, 4 // 005676af
        test esi, esi // 005676b2
        jne L005676be // 005676b4
        pop edi // 005676b6
        mov eax, 0xfffffff8 // 005676b7
        pop esi // 005676bc
        ret // 005676bd
    L005676be:
        push edi // 005676be
        call audio_stream_service_reset_00567740 // 005676bf
        add esp, 4 // 005676c4
        call audio_stream_service_count_005673b0 // 005676c7
        cmp eax, 1 // 005676cc
        jne L005676e8 // 005676cf
        push offset audio_stream_service_tick_00567270 // 005676d1
        call audio_stream_service_unregister_0058ff70 // 005676d6
        add esp, 4 // 005676db
        mov dword ptr [application_audio_device_state_006b48c0+0x14c], 0 // 005676de
    L005676e8:
        mov eax, dword ptr [esi + 0xc] // 005676e8
        push eax // 005676eb
        call network_lifecycle_device_release_005617d0 // 005676ec
        add esp, 4 // 005676f1
        mov al, byte ptr [esi + 0x18] // 005676f4
        test al, al // 005676f7
        jne L00567707 // 005676f9
        mov ecx, dword ptr [esi + 4] // 005676fb
        push ecx // 005676fe
        call audio_stream_codec_destroy_0056b3b0 // 005676ff
        add esp, 4 // 00567704
    L00567707:
        mov dword ptr [edi*4 + audio_stream_service_storage_006b7740], 0 // 00567707
        pop edi // 00567712
        xor eax, eax // 00567713
        pop esi // 00567715
        ret // 00567716
    }
}
// 00567740/202B SHA256 c5aa1c0c676c04d3cdc3b8f50c1db76f2ee92befebf890144fee3052afc7cc6c
__declspec(naked) I __cdecl audio_stream_service_reset_00567740(U){
    __asm {
        mov al, byte ptr [application_audio_device_state_006b48c0+0xec] // 00567740
        push esi // 00567745
        test al, al // 00567746
        jne L00567751 // 00567748
        mov eax, 0xfffffff6 // 0056774a
        pop esi // 0056774f
        ret // 00567750
    L00567751:
        mov eax, dword ptr [esp + 8] // 00567751
        push eax // 00567755
        call audio_stream_service_lookup_00566d60 // 00567756
        mov esi, eax // 0056775b
        add esp, 4 // 0056775d
        test esi, esi // 00567760
        jne L0056776b // 00567762
        mov eax, 0xfffffff8 // 00567764
        pop esi // 00567769
        ret // 0056776a
    L0056776b:
        mov eax, dword ptr [esi + 8] // 0056776b
        test eax, eax // 0056776e
        jl L0056777e // 00567770
        mov ecx, dword ptr [esi + 0xc] // 00567772
        push ecx // 00567775
        call network_lifecycle_device_cancel_00561730 // 00567776
        add esp, 4 // 0056777b
    L0056777e:
        mov dword ptr [esi + 8], 0xffffffff // 0056777e
        mov al, byte ptr [esi + 0x18] // 00567785
        test al, al // 00567788
        jne L00567798 // 0056778a
        mov edx, dword ptr [esi + 4] // 0056778c
        push edx // 0056778f
        call audio_stream_codec_reset_0056c420 // 00567790
        add esp, 4 // 00567795
    L00567798:
        mov eax, dword ptr [esi + 0x9c] // 00567798
        push ebp // 0056779e
        push edi // 0056779f
        lea edi, [esi + 0x9c] // 005677a0
        test eax, eax // 005677a6
        je L005677c6 // 005677a8
        xor eax, eax // 005677aa
        mov al, byte ptr [esi + 0x32] // 005677ac
        mov ebp, eax // 005677af
        test ebp, ebp // 005677b1
        jle L005677c6 // 005677b3
    L005677b5:
        mov ecx, dword ptr [edi] // 005677b5
        push ecx // 005677b7
        call audio_backend_pool_release_0058ac30 // 005677b8
        add esp, 4 // 005677bd
        add edi, 4 // 005677c0
        dec ebp // 005677c3
        jne L005677b5 // 005677c4
    L005677c6:
        mov byte ptr [esi + 0x16], 0 // 005677c6
        mov byte ptr [esi + 0x17], 0 // 005677ca
        mov byte ptr [esi + 0x14], 0 // 005677ce
        lea edx, [esi + 0x2c] // 005677d2
        push 4 // 005677d5
        push edx // 005677d7
        call application_audio_backend_configure_0058fef0 // 005677d8
        lea eax, [esi + 0x30] // 005677dd
        push 4 // 005677e0
        push eax // 005677e2
        call application_audio_backend_configure_0058fef0 // 005677e3
        lea ecx, [esi + 0x34] // 005677e8
        push 0x54 // 005677eb
        push ecx // 005677ed
        call application_audio_backend_configure_0058fef0 // 005677ee
        add esi, 0x88 // 005677f3
        push 0x54 // 005677f9
        push esi // 005677fb
        call application_audio_backend_configure_0058fef0 // 005677fc
        add esp, 0x20 // 00567801
        xor eax, eax // 00567804
        pop edi // 00567806
        pop ebp // 00567807
        pop esi // 00567808
        ret // 00567809
    }
}
// 00566d60/24B SHA256 3ddc738832144ec637d2d86032d3b23fe80329720373db6b93b23a0eab7ff15e
__declspec(naked) U __cdecl audio_stream_service_lookup_00566d60(I){
    __asm {
        mov eax, dword ptr [esp + 4] // 00566d60
        cmp eax, 0x10 // 00566d64
        jge L00566d75 // 00566d67
        test eax, eax // 00566d69
        jl L00566d75 // 00566d6b
        mov eax, dword ptr [eax*4 + audio_stream_service_storage_006b7740] // 00566d6d
        ret // 00566d74
    L00566d75:
        xor eax, eax // 00566d75
        ret // 00566d77
    }
}
// 005673b0/25B SHA256 9066ebaa884a5f2d0bcde2594bb6a8acb9808973e263732be8ccec20f7819e38
__declspec(naked) U __cdecl audio_stream_service_count_005673b0(){
    __asm {
        xor eax, eax // 005673b0
        mov ecx, offset audio_stream_service_storage_006b7740 // 005673b2
    L005673b7:
        cmp dword ptr [ecx], 0 // 005673b7
        je L005673bd // 005673ba
        inc eax // 005673bc
    L005673bd:
        add ecx, 4 // 005673bd
        cmp ecx, offset audio_stream_service_storage_006b7740+0x40 // 005673c0
        jl L005673b7 // 005673c6
        ret // 005673c8
    }
}
// 00566d40/22B SHA256 47e3aaca0dbc0abbb7cddaae0f3532949fec9c1447bf247fd0bb8a79b22a8c1c
__declspec(naked) U __cdecl audio_stream_service_shutdown_00566d40(){
    __asm {
        push esi // 00566d40
        xor esi, esi // 00566d41
    L00566d43:
        push esi // 00566d43
        call application_audio_stream_stop_00567690 // 00566d44
        add esp, 4 // 00566d49
        inc esi // 00566d4c
        cmp esi, 0x10 // 00566d4d
        jl L00566d43 // 00566d50
        xor eax, eax // 00566d52
        pop esi // 00566d54
        ret // 00566d55
    }
}
// 0058ff50/31B SHA256 6b71afe44405ea2070324e3b6801cff15af320f64ef68f74f18f20e9d2233f80
__declspec(naked) void __cdecl audio_stream_service_register_0058ff50(AudioStreamServiceCallback561){
    __asm {
        movsx eax, byte ptr [application_audio_device_state_006b48c0+0xf1] // 0058ff50
        mov ecx, dword ptr [esp + 4] // 0058ff57
        mov dword ptr [eax*4 + application_audio_device_state_006b48c0+0x118], ecx // 0058ff5b
        mov al, byte ptr [application_audio_device_state_006b48c0+0xf1] // 0058ff62
        inc al // 0058ff67
        mov byte ptr [application_audio_device_state_006b48c0+0xf1], al // 0058ff69
        ret // 0058ff6e
    }
}
// 0058ff70/86B SHA256 28057bd93ffdf59babbedf8f48309786422b0f2a0bc9b7c0ea0a8e737c62e3b2
__declspec(naked) void __cdecl audio_stream_service_unregister_0058ff70(AudioStreamServiceCallback561){
    __asm {
        push ebx // 0058ff70
        mov bl, byte ptr [application_audio_device_state_006b48c0+0xf1] // 0058ff71
        movsx ecx, bl // 0058ff77
        xor eax, eax // 0058ff7a
        push esi // 0058ff7c
        test ecx, ecx // 0058ff7d
        jle L0058ffc3 // 0058ff7f
        mov esi, dword ptr [esp + 0xc] // 0058ff81
        mov edx, offset application_audio_device_state_006b48c0+0x118 // 0058ff85
    L0058ff8a:
        cmp dword ptr [edx], esi // 0058ff8a
        je L0058ff99 // 0058ff8c
        inc eax // 0058ff8e
        add edx, 4 // 0058ff8f
        cmp eax, ecx // 0058ff92
        jl L0058ff8a // 0058ff94
        pop esi // 0058ff96
        pop ebx // 0058ff97
        ret // 0058ff98
    L0058ff99:
        dec bl // 0058ff99
        movsx ecx, bl // 0058ff9b
        cmp eax, ecx // 0058ff9e
        mov byte ptr [application_audio_device_state_006b48c0+0xf1], bl // 0058ffa0
        jge L0058ffc3 // 0058ffa6
        lea ecx, [eax*4 + application_audio_device_state_006b48c0+0x118] // 0058ffa8
    L0058ffaf:
        mov edx, dword ptr [ecx + 4] // 0058ffaf
        inc eax // 0058ffb2
        mov dword ptr [ecx], edx // 0058ffb3
        add ecx, 4 // 0058ffb5
        movsx edx, byte ptr [application_audio_device_state_006b48c0+0xf1] // 0058ffb8
        cmp eax, edx // 0058ffbf
        jl L0058ffaf // 0058ffc1
    L0058ffc3:
        pop esi // 0058ffc3
        pop ebx // 0058ffc4
        ret // 0058ffc5
    }
}
}
