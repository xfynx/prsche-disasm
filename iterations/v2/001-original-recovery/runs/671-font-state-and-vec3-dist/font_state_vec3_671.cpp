// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0053eea0..0053eeb2 (19B), 0053e890..0053e970 (225B),
// 00532b20..00532b44 (37B), and 005323a0..005323d4 (53B).
#include "font_state_vec3_671.hpp"

#include <cstring>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 instruction boundaries require MSVC x86
#endif

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char font_setstatef_invalid_state_005bbb44[35] =
    "FONT_setstatef - Invalid state %d\n";

namespace {

void write_u32(void* base, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_f32(void* base, std::size_t offset, float value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_i32(void* base, std::size_t offset, std::int32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

float read_f32(const void* base, std::size_t offset) {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

} // namespace

void __cdecl font_state_set_pair_0053eea0(
    void* obj, std::uint32_t first, std::uint32_t second) {
    write_u32(obj, 0x3cu, first);
    write_u32(obj, 0x40u, second);
}

void __cdecl font_setstatef_0053e890(
    void* font, std::int32_t state, float value) {
    switch (state) {
    case 1:
        write_f32(font, 0xb0u, value);
        return;
    case 2:
        write_f32(font, 0xb4u, value);
        return;
    case 3:
        write_f32(font, 0xb8u, value);
        return;
    case 4: {
        float denom = read_f32(font, 0xb8u);
        float ratio = value;
        std::int32_t quantized = 0;
        __asm {
            fld dword ptr [denom]
            fdivr dword ptr [ratio]
            fstp dword ptr [ratio]
            fld dword ptr [ratio]
            fistp dword ptr [quantized]
        }
        write_i32(font, 0x14u, quantized);
        return;
    }
    case 18:
        write_f32(font, 0xd0u, value);
        return;
    case 19:
        write_f32(font, 0xd4u, value);
        return;
    case 20:
        write_f32(font, 0xd8u, value);
        return;
    case 21:
        write_f32(font, 0xdcu, value);
        return;
    case 22:
        write_f32(font, 0xe0u, value);
        return;
    case 23:
        write_f32(font, 0xe4u, value);
        return;
    default:
        // Porsche.exe 005bbb08 is shared across 0053e5c0, 0053e890, 0053e9c0, 0053ebd0.
        diagnostic_file_005deb74_set("\\real\\cmn\\fontattr.c");
        diagnostic_line_005deb78 = 0xf1u;
        reinterpret_cast<void(__cdecl*)(const char*, std::int32_t)>(
            diagnostic_handler_005debf0)(font_setstatef_invalid_state_005bbb44, state);
        return;
    }
}

float __cdecl vec3_length_00532b20(const float* vec) {
    float result = 0.0f;
    __asm {
        mov eax, vec
        fld dword ptr [eax]
        fmul dword ptr [eax]
        fld dword ptr [eax + 4]
        fmul dword ptr [eax + 4]
        faddp st(1), st(0)
        fld dword ptr [eax + 8]
        fmul dword ptr [eax + 8]
        faddp st(1), st(0)
        fsqrt
        fstp dword ptr [result]
    }
    return result;
}

float __cdecl vec3_distance_005323a0(const float* a, const float* b) {
    const float diff[3] = {
        b[0] - a[0],
        b[1] - a[1],
        b[2] - a[2],
    };
    return vec3_length_00532b20(diff);
}

} // namespace porsche
