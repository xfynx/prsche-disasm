#include "porsche/startup_service_516950.hpp"

#include <cstdint>
#include <iostream>

std::uint32_t native_argc=0;
std::uint32_t native_target=0;
std::uint32_t native_gpr[7]{}; // eax, ebx, ecx, edx, esi, edi, ebp
std::uint32_t native_flags=0;
std::uint32_t native_call_esp=0;
std::uint32_t native_return_esp=0;
std::uint32_t native_args_after[4]{};

__declspec(naked) void __cdecl invoke_noop_capture() {
    __asm {
        push ebx
        push esi
        push edi
        push ebp

        cmp native_argc, 0
        je args_ready
        cmp native_argc, 1
        je one_arg
        cmp native_argc, 2
        je two_args
        cmp native_argc, 4
        je four_args
        // The harness only supplies 0, 1, 2, or 4 arguments.
        int 3
    four_args:
        push 044444444h
        push 033333333h
        push 022222222h
        push 011111111h
        jmp args_ready
    two_args:
        push 022222222h
        push 011111111h
        jmp args_ready
    one_arg:
        push 011111111h
    args_ready:
        mov eax, 0a1a2a3a4h
        mov ebx, 0b1b2b3b4h
        mov ecx, 0c1c2c3c4h
        mov edx, 0d1d2d3d4h
        mov esi, 0e1e2e3e4h
        mov edi, 0f1f2f3f4h
        mov ebp, 01718191ah
        mov native_call_esp, esp
        push 0246h
        popfd
        call dword ptr [native_target]

        mov native_return_esp, esp
        mov native_gpr, eax
        mov native_gpr+16, esi
        mov native_gpr+20, edi
        mov native_gpr+24, ebp
        mov native_gpr+4, ebx
        mov native_gpr+8, ecx
        mov native_gpr+12, edx
        pushfd
        pop dword ptr [native_flags]
        mov eax, dword ptr [esp]
        mov native_args_after[0], eax
        mov eax, dword ptr [esp+4]
        mov native_args_after[4], eax
        mov eax, dword ptr [esp+8]
        mov native_args_after[8], eax
        mov eax, dword ptr [esp+12]
        mov native_args_after[12], eax

        mov eax, native_argc
        shl eax, 2
        add esp, eax
        pop ebp
        pop edi
        pop esi
        pop ebx
        ret
    }
}

int main(int argc,char** argv) {
    (void)argc;
    (void)argv;
    native_target=static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(&porsche::startup_service_noop_00516950));
    constexpr std::uint32_t counts[]={0,1,2,4};
    for(const auto count:counts) {
        native_argc=count;
        invoke_noop_capture();
        std::cout<<"{\"argc\":"<<count<<",\"gpr\":["<<std::dec
                 <<native_gpr[0]<<','<<native_gpr[1]<<','<<native_gpr[2]<<','
                 <<native_gpr[3]<<','<<native_gpr[4]<<','<<native_gpr[5]<<','
                 <<native_gpr[6]<<"],\"eflags\":"<<native_flags
                 <<",\"esp_delta\":"<<static_cast<std::int32_t>(native_return_esp-native_call_esp)
                 <<",\"args_after\":["<<native_args_after[0]<<','
                 <<native_args_after[1]<<','<<native_args_after[2]<<','
                 <<native_args_after[3]<<"]}\n";
    }
    return 0;
}
