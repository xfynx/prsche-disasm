// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Candidate 00567550/267B; native comparison and intake are pending.
#include "../561-audio-stream-creation/audio_stream_creation_561.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error This original x86 ABI requires MSVC x86.
#endif
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;
U __cdecl audio_stream_codec_memory_0056b690(U,U,U,U);
U __cdecl audio_stream_codec_file_0056c040(U,U,U,U);
__declspec(naked) I __cdecl audio_service_stream_start_00567550(U,U,U,U,U){
 __asm {
  mov al, byte ptr [application_audio_device_state_006b48c0+0xdc]
  push ebx
  xor ebx,ebx
  push ebp
  cmp al,bl
  push edi
  jne active
  pop edi
  pop ebp
  mov eax,0xfffffff6
  pop ebx
  ret
 active:
  mov eax,dword ptr [esp+0x10]
  push eax
  call audio_stream_service_lookup_00566d60
  mov edi,eax
  add esp,4
  cmp edi,ebx
  jne has_slot
  pop edi
  pop ebp
  mov eax,0xfffffff8
  pop ebx
  ret
 has_slot:
  mov cl,byte ptr [edi+0x15]
  mov al,byte ptr [edi+0x16]
  cmp al,cl
  jl has_space
  pop edi
  pop ebp
  mov eax,0xfffffff3
  pop ebx
  ret
 has_space:
  mov eax,dword ptr [esp+0x20]
  cmp eax,ebx
  jne test_file
  mov edx,dword ptr [esp+0x1c]
  mov eax,dword ptr [esp+0x18]
  mov ecx,dword ptr [edi+4]
  push 0x6c454353
  push edx
  push eax
  push ecx
  call audio_stream_codec_memory_0056b690
  add esp,0x10
  mov ebp,eax
  jmp got_codec
 test_file:
  cmp eax,1
  jne direct_codec
  mov edx,dword ptr [esp+0x18]
  mov eax,dword ptr [edi+4]
  push 0x6c454353
  push ebx
  push edx
  push eax
  call audio_stream_codec_file_0056c040
  add esp,0x10
  mov ebp,eax
  jmp got_codec
 direct_codec:
  mov ebp,dword ptr [esp+0x1c]
 got_codec:
  cmp ebp,ebx
  jne attach
  pop edi
  pop ebp
  or eax,0xffffffff
  pop ebx
  ret
 attach:
  push esi
  call audio_backend_lock_005896d0
  movsx eax,byte ptr [edi+0x16]
  lea ecx,[eax+eax*4]
  lea edx,[eax+ecx*2]
  mov eax,dword ptr [edi]
  lea esi,[eax+edx*4]
  mov dword ptr [esi],ebp
  mov ecx,dword ptr [edi+0x10]
  add ecx,0x100
  mov dword ptr [edi+0x10],ecx
  mov eax,dword ptr [edi+0x10]
  cmp eax,ebx
  jge generation_ok
  mov dword ptr [edi+0x10],ebx
 generation_ok:
  mov edx,dword ptr [edi+0x10]
  mov ecx,dword ptr [esp+0x14]
  or edx,ecx
  mov dword ptr [esi+4],edx
  mov ax,word ptr [esp+0x18]
  mov word ptr [esi+0x28],ax
  mov cl,byte ptr [edi+0x16]
  inc cl
  mov byte ptr [edi+0x16],cl
  mov dword ptr [esi+0x10],ebx
  or eax,0xffffffff
  mov dword ptr [esi+8],eax
  mov dword ptr [esi+0xc],eax
  mov dword ptr [esi+0x14],ebx
  mov dword ptr [esi+0x1c],ebx
  mov dword ptr [esi+0x20],ebx
  mov dword ptr [esi+0x24],ebx
  call audio_backend_unlock_005896f0
  mov eax,dword ptr [esi+4]
  pop esi
  pop edi
  pop ebp
  pop ebx
  ret
 }
}
}
