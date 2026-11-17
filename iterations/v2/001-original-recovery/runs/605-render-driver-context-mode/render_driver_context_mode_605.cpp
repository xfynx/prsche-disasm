// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 005381d0..00538222, 83 bytes, sha256 f4af57344683d0fa91792730db76c6f0f56a82700a5b535ec9ccd9ebfe85ae96.
// Original 00549220..005492ed, 206 bytes, sha256 7b7b61e0e3be7e2f30dddf2272d1aa8e804b5ab1bbd31f16d305a8655b01154a.
#include "render_driver_context_mode_605.hpp"
#include <cstring>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x87 instruction boundaries require MSVC x86
#endif

namespace porsche {

std::int32_t render_driver_exp_bias_005dea60 = 0x00800000;
std::uint32_t render_driver_exp_dirty_005dea78 = 0xffffffffu;

namespace {

bool x87_scaled_less_605(const std::int32_t* val_ptr, const float* limit_ptr) {
    std::uint16_t sw = 0u;
    __asm {
        mov ecx, val_ptr
        mov edx, limit_ptr
        fild dword ptr [ecx]
        fmul dword ptr [audio_mixer_gain_scale_005b246c]
        fcomp dword ptr [edx]
        fnstsw ax
        mov sw, ax
    }
    return (sw & 0x0100u) != 0u;
}

void x87_store_int_float_605(std::int32_t v, void* dst) {
    __asm {
        mov edx, dst
        fild dword ptr v
        fstp dword ptr [edx]
    }
}

} // namespace

std::int32_t __cdecl render_driver_shift_bias_005381d0(std::int32_t shift) {
    const std::int32_t prev = render_driver_exp_bias_005dea60 >> 23;
    if (shift < 0) {
        render_driver_exp_bias_005dea60 = 0;
        render_driver_exp_dirty_005dea78 = 0xffffffffu;
        return prev;
    }
    if (shift > 16) {
        render_driver_exp_bias_005dea60 = 0x08000000;
        render_driver_exp_dirty_005dea78 = 0xffffffffu;
        return prev;
    }
    render_driver_exp_bias_005dea60 = static_cast<std::int32_t>(static_cast<std::uint32_t>(shift) << 23u);
    render_driver_exp_dirty_005dea78 = 0xffffffffu;
    return prev;
}

void __fastcall render_driver_context_mode_00549220(void* self, void*, std::uint32_t mode) {
    float info[4] = {};
    const auto set_state = reinterpret_cast<std::uint32_t(__stdcall*)(std::uint32_t, float*)>(
        render_thrash_exports_006bd910[27]);
    std::int32_t shift = 0;
    if (set_state(0x3fu, info) != 0u) {
        const auto* const* service =
            reinterpret_cast<const std::uint8_t* const*>(game_setup_movie_service_0069ed0c);
        const std::uint8_t* inner = *service;
        const std::uint8_t* modes = nullptr;
        std::memcpy(&modes, inner + 8, sizeof(modes));
        const std::uint8_t* entry = modes + mode * 40u;
        const auto* val0 = reinterpret_cast<const std::int32_t*>(entry);
        const auto* val1 = reinterpret_cast<const std::int32_t*>(entry + 4);
        if (x87_scaled_less_605(val0, &info[1]) && x87_scaled_less_605(val1, &info[3])) {
            std::uint32_t flags = 0u;
            std::memcpy(&flags, static_cast<const std::uint8_t*>(self) + 0x117e4, sizeof(flags));
            flags |= 0x10000u;
            std::memcpy(static_cast<std::uint8_t*>(self) + 0x117e4, &flags, sizeof(flags));
            shift = 1;
        }
    }
    (void)render_driver_shift_bias_005381d0(shift);
    x87_store_int_float_605(1 << shift, static_cast<std::uint8_t*>(self) + 0x117e8);
    const auto about_fn =
        reinterpret_cast<const std::uint8_t*(__stdcall*)()>(render_thrash_exports_006bd910[9]);
    const std::uint8_t* about = about_fn();
    if (about[0x4c] == 'D' && about[0x4d] == 'X' && about[0x4e] == '7') {
        std::uint32_t flags = 0u;
        std::memcpy(&flags, static_cast<const std::uint8_t*>(self) + 0x117e4, sizeof(flags));
        flags |= 0x20000u;
        std::memcpy(static_cast<std::uint8_t*>(self) + 0x117e4, &flags, sizeof(flags));
    }
}

} // namespace porsche
