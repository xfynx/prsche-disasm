#include "porsche/formatter_entry.hpp"

#include <cstdint>
#include <cstring>
#include <iostream>

namespace {
struct Script {
    std::uint32_t remaining_after_core;
    std::uint32_t cursor_offset;
    std::uint32_t result;
};
Script active{};
struct Trace {
    std::uint32_t called = 0;
    std::uint32_t cleanup_called = 0;
    std::uint32_t initial_remaining = 0;
    std::uint32_t initial_cursor_offset = 0;
    std::uint32_t initial_base_offset = 0;
    std::uint32_t initial_flags = 0;
    std::uint32_t format_ok = 0;
    std::uint32_t raw[3]{};
    std::uint32_t cleanup_zero = 0xffffffffu;
    std::uint32_t cleanup_remaining = 0;
    std::uint32_t cleanup_cursor_offset = 0;
    std::uint32_t cleanup_base_offset = 0;
    std::uint32_t cleanup_flags = 0;
} trace;
char* current_output = nullptr;
}
static const char format_text[] = "fmt:%08x/%08x/%08x";
alignas(4) static char output_buffer[64];

namespace porsche {
std::int32_t __cdecl formatter_core_005a4371(
    FormatterDescriptor005a0fbf* d, const char* format,
    const std::uint32_t* raw) {
    trace.called++;
    trace.initial_remaining = static_cast<std::uint32_t>(d->remaining);
    trace.initial_cursor_offset = static_cast<std::uint32_t>(d->cursor-current_output);
    trace.initial_base_offset = static_cast<std::uint32_t>(d->base-current_output);
    trace.initial_flags = d->flags;
    trace.format_ok = (format && std::strcmp(format, "fmt:%08x/%08x/%08x") == 0);
    for (unsigned i=0; i<3; ++i) std::memcpy(&trace.raw[i], raw+i, 4);
    d->cursor = current_output + active.cursor_offset;
    std::memcpy(&d->remaining, &active.remaining_after_core, 4);
    return static_cast<std::int32_t>(active.result);
}

void __cdecl formatter_cleanup_005a4259(
    std::uint32_t zero, FormatterDescriptor005a0fbf* d) {
    trace.cleanup_called++;
    trace.cleanup_zero = zero;
    trace.cleanup_remaining = static_cast<std::uint32_t>(d->remaining);
    trace.cleanup_cursor_offset = static_cast<std::uint32_t>(d->cursor-current_output);
    trace.cleanup_base_offset = static_cast<std::uint32_t>(d->base-current_output);
    trace.cleanup_flags = d->flags;
}
} // namespace porsche

static std::uint32_t before_sp, after_sp, saved_eax;
static std::uint32_t saved_ebx, saved_esi, saved_edi, saved_ebp;
__declspec(naked) static void invoke_formatter() {
    __asm {
        push ebx
        push esi
        push edi
        push ebp
        mov ebx, 0xb1b2b3b4
        mov esi, 0xe1e2e3e4
        mov edi, 0xf1f2f3f4
        mov ebp, 0x1718191a
        mov before_sp, esp
        push 0xc3d4e5f6
        push 0x8192a3b4
        push 0x11223344
        push offset format_text
        push offset output_buffer
        call porsche::formatter_entry_005a0fbf
        add esp, 20
        mov saved_eax, eax
        mov after_sp, esp
        mov saved_ebx, ebx
        mov saved_esi, esi
        mov saved_edi, edi
        mov saved_ebp, ebp
        pop ebp
        pop edi
        pop esi
        pop ebx
        ret
    }
}

int main() {
    const Script cases[] = {
        {0x00000000, 0, 0x00000000},
        {0x00000001, 7, 0x7fffffff},
        {0x00000002, 31, 0x80000000},
        {0x7fffffff, 3, 0xdeadbeef},
        {0x80000000, 19, 0x13579bdf},
        {0x80000001, 11, 0xffffffff},
        {0xffffffff, 23, 0x2468ace0},
    };
    for (unsigned i=0; i<sizeof(cases)/sizeof(cases[0]); ++i) {
        active = cases[i];
        trace = {};
        std::memset(output_buffer, 0x58, sizeof(output_buffer));
        current_output = output_buffer;
        invoke_formatter();
        std::cout << "{\"case\":" << i << ",\"core_calls\":" << trace.called
          << ",\"initial_remaining\":" << trace.initial_remaining
          << ",\"initial_cursor_offset\":" << trace.initial_cursor_offset
          << ",\"initial_base_offset\":" << trace.initial_base_offset
          << ",\"initial_flags\":" << trace.initial_flags
          << ",\"format_ok\":" << trace.format_ok << ",\"raw\":["
          << trace.raw[0] << ',' << trace.raw[1] << ',' << trace.raw[2]
          << "],\"cleanup_calls\":" << trace.cleanup_called
          << ",\"cleanup_zero\":" << trace.cleanup_zero
          << ",\"cleanup_remaining\":" << trace.cleanup_remaining
          << ",\"cleanup_cursor_offset\":" << trace.cleanup_cursor_offset
          << ",\"cleanup_base_offset\":" << trace.cleanup_base_offset
          << ",\"cleanup_flags\":" << trace.cleanup_flags
          << ",\"result\":" << saved_eax
          << ",\"before_sp\":" << before_sp << ",\"after_sp\":" << after_sp
          << ",\"saved\":[" << saved_ebx << ',' << saved_esi << ','
          << saved_edi << ',' << saved_ebp << ']'
          << ",\"clear_offsets\":[";
        bool comma=false;
        for (unsigned k=0;k<sizeof(output_buffer);++k) if (output_buffer[k]==0) {
            if (comma) std::cout << ',';
            std::cout << k; comma=true;
        }
        std::cout << "]}\n";
    }
}
