// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run821: 00458c90 cluster (16 functions, 3,677B code, 33B .data).
#include "scene_stage_58b80_ctor_821.hpp"

#include "font_state_vec3_671.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/render_mode.hpp"
#include "render_seed_prng_638.hpp"
#include "scene_blur_program_736.hpp"
#include "scene_blur_stage_726.hpp"
#include "scene_stage_reset_805.hpp"
#include "startup_context_table_helpers_646.hpp"
#include "startup_sequence_resource_table_649.hpp"

#include <cstddef>
#include <cstring>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Exact original x87 FPU behavior requires MSVC x86
#endif

namespace porsche {

const char scene_stage_particle_tags_005ceeb8[33] =
    "0ons1ons2ons3ons0nar1nar2nar3nar";

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

float bits_to_float(U bits) {
    float value = 0.0f;
    std::memcpy(&value, &bits, sizeof(value));
    return value;
}

U float_to_bits(float value) {
    U bits = 0u;
    std::memcpy(&bits, &value, sizeof(bits));
    return bits;
}

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

float load_f32(const void* base, U offset) {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void store8(void* base, U offset, B value) {
    *(static_cast<B*>(base) + offset) = value;
}

void store16(void* base, U offset, std::uint16_t value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_f32(void* base, U offset, float value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_ptr(void* base, U offset, const void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

U ptr_to_u32(const void* ptr) {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

void swap_vec4(float* lhs, float* rhs) {
    U tmp[4]{};
    std::memcpy(tmp, lhs, sizeof(tmp));
    std::memcpy(lhs, rhs, sizeof(tmp));
    std::memcpy(rhs, tmp, sizeof(tmp));
}

U bswap32(U value) {
    return ((value & 0x00ff0000u) >> 8) |
           ((value & 0xff000000u) >> 24) |
           ((value & 0x000000ffu) << 24) |
           ((value & 0x0000ff00u) << 8);
}

void build_emitter_spec(
    U* spec_words, B* tail_flag, const U head10[10], I mode_word,
    U w11, U w12, U w13, U w14, U w15, U w16, U w17, U w18,
    void* lookup, B flag) {
    std::memcpy(spec_words, head10, 10u * sizeof(U));
    spec_words[10] = float_to_bits(static_cast<float>(mode_word));
    spec_words[11] = w11;
    spec_words[12] = w12;
    spec_words[13] = w13;
    spec_words[14] = w14;
    spec_words[15] = w15;
    spec_words[16] = w16;
    spec_words[17] = w17;
    spec_words[18] = w18;
    std::memcpy(&spec_words[19], &lookup, sizeof(lookup));
    *tail_flag = flag;
}

} // namespace

// 005327d0..005327d6 (7B, __cdecl, ret 0).
double __cdecl math_fsqrt_005327d0(float value) {
    double result = 0.0;
    __asm {
        fld dword ptr [value]
        fsqrt
        fstp qword ptr [result]
    }
    return result;
}

// 005327e0..005327ec (13B, __cdecl, ret 0).
double __cdecl math_fsin_tau_005327e0(float turns) {
    static const std::uint64_t kTauBits = 0x401921fb20000000ull; // 6.28318452835083
    double result = 0.0;
    __asm {
        fld dword ptr [turns]
        fmul qword ptr [kTauBits]
        fsin
        fstp qword ptr [result]
    }
    return result;
}

// 0056e8f5..0056e939 (69B, __cdecl, ret 0).
float* __cdecl vec3_cross_raw_0056e8f5(const float* a, const float* b, float* dst) {
    __asm {
        mov eax, a
        mov edx, b
        mov ebx, dst
        fld dword ptr [eax + 4]
        fmul dword ptr [edx + 8]
        fld dword ptr [eax + 8]
        fmul dword ptr [edx]
        fld dword ptr [eax]
        fmul dword ptr [edx + 4]
        fxch st(2)
        fld dword ptr [eax + 8]
        fmul dword ptr [edx + 4]
        fld dword ptr [eax]
        fmul dword ptr [edx + 8]
        fld dword ptr [eax + 4]
        fmul dword ptr [edx]
        fxch st(2)
        fsubp st(3), st(0)
        fsubp st(3), st(0)
        fsubp st(3), st(0)
        fstp dword ptr [ebx]
        fstp dword ptr [ebx + 4]
        fstp dword ptr [ebx + 8]
    }
    return const_cast<float*>(a + 3);
}

// 00532880..00532897 (24B, __cdecl, ret 0).
void __cdecl vec3_cross_00532880(const float* a, const float* b, float* out) {
    vec3_cross_raw_0056e8f5(a, b, out);
}

// 005328d0..00532901 (50B, __cdecl, ret 0).
void __cdecl vec3_normalize_005328d0(const float* src, float* dst) {
    static const float kOne = 1.0f;
    const float len = vec3_length_00532b20(src);
    __asm {
        mov eax, dst
        fld dword ptr [len]
        fdivr dword ptr [kOne]
        mov edx, src
        fld st(0)
        fmul dword ptr [edx]
        fstp dword ptr [eax]
        fld dword ptr [edx + 4]
        fmul st(0), st(1)
        fstp dword ptr [eax + 4]
        fld dword ptr [edx + 8]
        fmul st(0), st(1)
        fstp dword ptr [eax + 8]
        fstp st(0)
    }
}

// 005328a0..005328c9 (42B, __cdecl, ret 0).
void __cdecl vec3_cross_normalize_005328a0(const float* a, const float* b, float* out) {
    float cross_tmp[3]{};
    vec3_cross_00532880(a, b, cross_tmp);
    vec3_normalize_005328d0(cross_tmp, out);
}

// 0053c490..0053c520 (145B, __cdecl, ret 0).
void __cdecl vec4_weighted_add_0053c490(
    I count, const float* a, const float* b, float* out) {
    double ratio = 0.0;
    double prev_w = static_cast<double>(a[3]) - 1.0;
    if (count > 0) {
        I remaining = count;
        do {
            const float aw = a[3];
            if (b[3] == aw) {
                out[0] = a[0] + b[0];
                out[1] = a[1] + b[1];
                out[2] = b[2] + a[2];
            } else {
                if (prev_w != static_cast<double>(aw)) {
                    ratio = static_cast<double>(aw) / static_cast<double>(b[3]);
                    prev_w = static_cast<double>(aw);
                }
                out[0] = static_cast<float>(static_cast<double>(b[0]) * ratio + static_cast<double>(a[0]));
                out[1] = static_cast<float>(static_cast<double>(b[1]) * ratio + static_cast<double>(a[1]));
                out[2] = static_cast<float>(static_cast<double>(b[2]) * ratio + static_cast<double>(a[2]));
            }
            out[3] = aw;
            a += 4;
            out += 4;
            --remaining;
        } while (remaining != 0);
    }
}

// 0053c5d0..0053c60e (63B, __cdecl, ret 0).
void __cdecl vec4_scale_0053c5d0(
    I count, const float* src, float scale, float* dst) {
    if (count > 0) {
        I remaining = count;
        do {
            const float x = src[0];
            const float y = src[1];
            const float z = src[2];
            dst[3] = src[3];
            dst[0] = scale * x;
            dst[1] = y * scale;
            dst[2] = z * scale;
            src += 4;
            dst += 4;
            --remaining;
        } while (remaining != 0);
    }
}

// 005561d0..005561f6 (39B, __cdecl, ret 0).
float __cdecl rand_unit_005561d0() {
    const U sample = render_seed_prng_next_00538040() & 0xffffu;
    return static_cast<float>(sample) * 1.52587890625e-05f;
}

// 00456790..004567cd (62B, __thiscall, ret 0).
void __fastcall scene_particle_slot_init_00456790(void* self, void* unused_edx) {
    (void)unused_edx;
    for (U i = 0u; i < 0xc9u; ++i) {
        const U base = 0x4b40u + i * 0x30u;
        store32(self, base - 0x04u, 0u);
        store32(self, base + 0x00u, 0u);
        store32(self, base + 0x04u, 0x3f800000u);
        store32(self, base + 0x08u, 0x3f800000u);
        store32(self, base + 0x0cu, 0u);
        store32(self, base + 0x10u, 0x3f800000u);
        store32(self, base + 0x14u, 0u);
        store32(self, base + 0x18u, 0u);
        store32(self, base + 0x1cu, 0x3f800000u);
        store32(self, base + 0x20u, 0u);
        store32(self, base + 0x24u, 0x3f800000u);
        store32(self, base + 0x28u, 0x3f800000u);
    }
}

// 00456ed0..0045702f (354B, __thiscall, ret 4).
void* __fastcall scene_particle_emitter_ctor_00456ed0(
    void* self, void* unused_edx, const void* spec) {
    (void)unused_edx;
    store32(self, 0x0000u, 0u);
    store32(self, 0x0004u, 0u);
    store32(self, 0x0008u, 0u);
    store32(self, 0x85c4u, 0u);
    store32(self, 0x85c8u, 0u);
    store8(self, 0x85fcu, 0u);
    store32(self, 0x8600u, 0u);
    std::memcpy(static_cast<B*>(self) + 0x8604u, spec, 0x15u * sizeof(U));

    for (I i = 0; i < 0x80; ++i) {
        const float sin_sample = static_cast<float>(
            math_fsin_tau_005327e0(static_cast<float>(i) * 0.0078125f));
        store_f32(self, 0x8658u + static_cast<U>(i) * 4u, sin_sample);
    }

    std::memset(static_cast<B*>(self) + 0x83a0u, 0, 0x64u * sizeof(U) + 1u);

    for (U i = 0u; i < 8u; ++i) {
        const I rand_ms = static_cast<I>(
            static_cast<double>(rand_unit_005561d0()) * 1000.0);
        store32(self, 0x8534u + i * 4u, static_cast<U>(rand_ms));
        const U vec_base = 0x8558u + i * 0x0cu;
        store32(self, vec_base - 4u, 0u);
        store32(self, vec_base + 0u, 0u);
        store32(self, vec_base + 4u, 0u);
    }

    store32(self, 0x85b4u, 0u);
    scene_particle_slot_init_00456790(self, nullptr);

    for (U i = 0u; i < 0x4b3u; ++i) {
        store32(self, 0x70d4u + i * 4u, 0xffffffffu);
    }
    for (U i = 0u; i < 0x4b3u; ++i) {
        store32(self, 0x0018u + i * 0x10u, 0x3f800000u);
    }

    void* mode_mem = startup_network_allocate_0059ef90(0x18u);
    void* mode = mode_mem != nullptr ? scene_mode_ctor_005379f0(mode_mem, nullptr) : nullptr;
    store_ptr(self, 0x85b8u, mode);
    scene_mode_set_00537a50(mode, nullptr, 1u);

    void* prog_mem = startup_network_allocate_0059ef90(0x28u);
    void* prog = prog_mem != nullptr
        ? scene_blur_program_ctor_00468240(prog_mem, nullptr, 9u, 3u, 1u, 0u, 0u)
        : nullptr;
    store_ptr(self, 0x85c0u, prog);
    scene_blur_program_setup_004685e0(
        prog,
        nullptr,
        0u,
        load32(self, 0x8650u),
        ptr_to_u32(load_ptr(self, 0x85b8u)),
        ptr_to_u32(static_cast<B*>(self) + 0x4b3cu),
        ptr_to_u32(static_cast<B*>(self) + 0x70d4u),
        0u);
    return self;
}

// 004580e0..0045814c (109B, __thiscall, ret 0).
void __fastcall scene_splt_zero_tables_004580e0(void* self, void* unused_edx) {
    (void)unused_edx;
    for (U i = 0u; i < 0xc9u; ++i) {
        store8(self, 0x4200u + i, 0u);
        const U a = 0x4460u + i * 0x0cu;
        store32(self, a + 4u, 0u);
        store32(self, a + 0u, 0u);
        store32(self, a - 4u, 0u);
        store32(self, a + 0x0970u, 0u);
        store32(self, a + 0x096cu, 0u);
        store32(self, a + 0x0968u, 0u);
        store32(self, a + 0x12dcu, 0u);
        store32(self, a + 0x12d8u, 0u);
        store32(self, a + 0x12d4u, 0u);
        const U d = 0x63c4u + i * 4u;
        store32(self, d - 0x324u, 0u);
        store32(self, d, 0u);
        store16(self, 0x42cau + i * 2u, 0u);
    }
}

// 00458150..0045819d (78B, __thiscall, ret 0).
void __fastcall scene_splt_init_uvs_00458150(void* self, void* unused_edx) {
    (void)unused_edx;
    for (U i = 0u; i < 0xc9u; ++i) {
        const U base = 0x25c0u + i * 0x18u;
        if ((i & 1u) == 1u) {
            store32(self, base - 0x04u, 0u);
            store32(self, base + 0x00u, 0x3f800000u);
            store32(self, base + 0x04u, 0u);
            store32(self, base + 0x08u, 0u);
            store32(self, base + 0x0cu, 0x3f800000u);
            store32(self, base + 0x10u, 0x3f800000u);
        } else {
            store32(self, base - 0x04u, 0x3f800000u);
            store32(self, base + 0x00u, 0u);
            store32(self, base + 0x04u, 0x3f800000u);
            store32(self, base + 0x08u, 0x3f800000u);
            store32(self, base + 0x0cu, 0u);
            store32(self, base + 0x10u, 0u);
        }
    }
}

// 00457920..00457e5a (1339B, __thiscall, ret 4).
void __fastcall scene_splt_quad_init_00457920(
    void* self, void* unused_edx, const float* quad) {
    (void)unused_edx;
    float accum[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    auto* v0 = reinterpret_cast<float*>(static_cast<B*>(self) + 0x6710u);
    auto* v1 = reinterpret_cast<float*>(static_cast<B*>(self) + 0x6720u);
    auto* v2 = reinterpret_cast<float*>(static_cast<B*>(self) + 0x6730u);
    auto* v3 = reinterpret_cast<float*>(static_cast<B*>(self) + 0x6740u);
    std::memcpy(v0, quad + 0, 16u);
    std::memcpy(v1, quad + 4, 16u);
    std::memcpy(v2, quad + 8, 16u);
    std::memcpy(v3, quad + 12, 16u);

    const double kSortEps = static_cast<double>(bits_to_float(0x3da3d70au));
    const double y0_eps = static_cast<double>(v0[1]) + kSortEps;
    if (y0_eps < static_cast<double>(v2[1])) {
        swap_vec4(v0, v2);
    } else if (y0_eps < static_cast<double>(v3[1])) {
        swap_vec4(v0, v3);
    }
    if (static_cast<double>(v1[1]) + kSortEps < static_cast<double>(v3[1])) {
        swap_vec4(v1, v3);
    }
    if (v0[0] < v1[0]) {
        swap_vec4(v0, v1);
    }
    if (v3[0] < v2[0]) {
        swap_vec4(v3, v2);
    }

    vec4_weighted_add_0053c490(1, accum, v0, accum);
    vec4_weighted_add_0053c490(1, accum, v1, accum);
    vec4_weighted_add_0053c490(1, accum, v2, accum);
    vec4_weighted_add_0053c490(1, accum, v3, accum);
    vec4_scale_0053c5d0(1, accum, 0.25f, accum);

    const float e1[3] = {v1[0] - v0[0], v1[1] - v0[1], v1[2] - v0[2]};
    store_f32(self, 0x675cu, accum[0]);
    store_f32(self, 0x6760u, accum[1]);
    store_f32(self, 0x6764u, accum[2]);
    const float e2[3] = {v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]};
    vec3_cross_normalize_005328a0(
        e1, e2, reinterpret_cast<float*>(static_cast<B*>(self) + 0x6750u));

    const float dx = v0[0] - v1[0];
    store_f32(self, 0x6768u, dx);
    const double dy = static_cast<double>(v1[1]) - static_cast<double>(v2[1]);
    const double dz = static_cast<double>(v1[2]) - static_cast<double>(v2[2]);
    const float sum_sq = static_cast<float>(dy * dy + dz * dz);
    const double len = math_fsqrt_005327d0(sum_sq);
    const float len_f = static_cast<float>(len);
    store_f32(self, 0x676cu, len_f);

    const float scale769 = bits_to_float(0x3f44ec4fu);
    const double clamp_val = len * static_cast<double>(dx) * static_cast<double>(scale769);
    store_f32(self, 0x67b0u, static_cast<float>(clamp_val));
    if (clamp_val > 1.0) {
        store32(self, 0x67b0u, 0x3f800000u);
    }

    auto* neg_x = reinterpret_cast<float*>(static_cast<B*>(self) + 0x677cu);
    neg_x[0] = -1.0f;
    neg_x[1] = 0.0f;
    neg_x[2] = 0.0f;
    vec3_cross_normalize_005328a0(
        reinterpret_cast<const float*>(static_cast<B*>(self) + 0x6750u),
        neg_x,
        reinterpret_cast<float*>(static_cast<B*>(self) + 0x6770u));

    const float b0 = load_f32(self, 0x6770u);
    const float b1 = load_f32(self, 0x6774u);
    const float b2 = load_f32(self, 0x6778u);
    const float c0 = load_f32(self, 0x675cu);
    const float c1 = load_f32(self, 0x6760u);
    const float c2 = load_f32(self, 0x6764u);

    const double t1 = static_cast<double>(b1) * static_cast<double>(len_f);
    const double h1 = t1 * 0.5;
    store_f32(self, 0x67a0u, static_cast<float>(static_cast<double>(c1) + h1));
    const float y_min = static_cast<float>(static_cast<double>(c1) - h1);
    store_f32(self, 0x67a4u, y_min);

    const double hx = static_cast<double>(neg_x[0]) * static_cast<double>(dx) * 0.5;
    store_f32(self, 0x67acu, static_cast<float>(static_cast<double>(c0) + hx));
    store_f32(self, 0x67a8u, static_cast<float>(static_cast<double>(c0) - hx));

    const double t0 = static_cast<double>(b0) * static_cast<double>(len_f);
    const float t0_f = static_cast<float>(t0);
    store_f32(self, 0x6788u, static_cast<float>(static_cast<double>(c0) - t0 * 0.5));
    store_f32(self, 0x678cu, y_min);

    const double t2 = static_cast<double>(b2) * static_cast<double>(len_f);
    const float t2_f = static_cast<float>(t2);
    store_f32(self, 0x6790u, static_cast<float>(static_cast<double>(c2) - t2 * 0.5));
    store_f32(self, 0x6794u, static_cast<float>(static_cast<double>(c0) - static_cast<double>(t0_f) * 0.25));
    store_f32(self, 0x6798u, static_cast<float>(static_cast<double>(c1) - t1 * 0.25));
    store_f32(self, 0x679cu, static_cast<float>(static_cast<double>(c2) - static_cast<double>(t2_f) * 0.25));
}

// 004577a0..00457918 (377B, __thiscall, ret 8).
void* __fastcall scene_splt_emitter_ctor_004577a0(
    void* self, void* unused_edx, const float* quad, U tex_handle) {
    (void)unused_edx;
    store32(self, 0x67d8u, 0u);
    store32(self, 0x0000u, 0u);
    store32(self, 0x0004u, 0u);
    store32(self, 0x0008u, 0u);
    store32(self, 0x67dcu, 0u);
    store32(self, 0x66f4u, 0u);
    store8(self, 0x66f8u, 0u);
    store8(self, 0x66f9u, 0u);
    store32(self, 0x67e0u, 0u);
    store8(self, 0x66fau, 0u);
    store32(self, 0x66fcu, 0xbf800000u);
    store32(self, 0x67ccu, 0u);
    store8(self, 0x6700u, 1u);
    store32(self, 0x67b0u, 0x3f800000u);
    store32(self, 0x67d0u, 0u);
    store32(self, 0x67d4u, 0u);
    store32(self, 0x67c0u, 0u);
    store32(self, 0x67c4u, 0u);
    store32(self, 0x67c8u, 0u);
    store32(self, 0x67b4u, 0u);
    store32(self, 0x67b8u, 0u);
    store32(self, 0x67bcu, 0u);

    scene_splt_quad_init_00457920(self, nullptr, quad);
    store32(self, 0x66e8u, 0u);
    store32(self, 0x66ecu, 0u);
    store32(self, 0x66f0u, 0u);
    scene_splt_zero_tables_004580e0(self, nullptr);
    scene_splt_init_uvs_00458150(self, nullptr);

    for (U i = 0u; i < 0xc9u; ++i) {
        const U base = 0x3898u + i * 0x0cu;
        store32(self, base - 4u, 0xffffffffu);
        store32(self, base + 0u, 0xffffffffu);
        store32(self, base + 4u, 0xffffffffu);
    }
    for (U i = 0u; i < 0xc9u; ++i) {
        const U base = 0x0028u + i * 0x30u;
        store32(self, base - 0x10u, 0x3f800000u);
        store32(self, base + 0x00u, 0x3f800000u);
        store32(self, base + 0x10u, 0x3f800000u);
    }

    void* mode_mem = startup_network_allocate_0059ef90(0x18u);
    void* mode = mode_mem != nullptr ? scene_mode_ctor_005379f0(mode_mem, nullptr) : nullptr;
    store_ptr(self, 0x6704u, mode);
    scene_mode_set_00537a50(mode, nullptr, 1u);

    void* prog_mem = startup_network_allocate_0059ef90(0x28u);
    void* prog = prog_mem != nullptr
        ? scene_blur_program_ctor_00468240(prog_mem, nullptr, 9u, 3u, 1u, 0u, 0u)
        : nullptr;
    store_ptr(self, 0x670cu, prog);
    scene_blur_program_setup_004685e0(
        prog,
        nullptr,
        0u,
        tex_handle,
        ptr_to_u32(load_ptr(self, 0x6704u)),
        ptr_to_u32(static_cast<B*>(self) + 0x25bcu),
        ptr_to_u32(static_cast<B*>(self) + 0x3894u),
        0u);
    return self;
}

// 00458c90..00459019 (906B, __thiscall, ret 0).
void* __fastcall scene_stage_58b80_ctor_00458c90(void* self, void* unused_edx) {
    (void)unused_edx;
    store32(self, 0x00u, 0u);

    const U snow_quality = load32(render_mode_state_00619790, 0x64u);
    const U snow_raw_tag = load32(scene_stage_particle_tags_005ceeb8, snow_quality * 4u);
    const I snow_mode = static_cast<I>(load32(render_mode_state_00619790, 0x60u));
    void* snow_tex = startup_context_table_lookup_0044d320(
        scene_stage_particle_table_owner_00613e08, nullptr, 0u, bswap32(snow_raw_tag));
    if (snow_tex == nullptr) {
        snow_tex = startup_context_table_lookup_0044d320(
            scene_stage_particle_table_owner_00613e08, nullptr, 0u, 0x776f6e73u);
    }
    const U snow_head[10] = {
        0xc1700000u, 0x41700000u, 0x41f00000u, 0xc0400000u, 0x41200000u,
        0x41500000u, 0x3f800000u, 0x41f00000u, 0x41f00000u, 0x41e80000u,
    };
    U snow_spec[21]{};
    build_emitter_spec(
        snow_spec, reinterpret_cast<B*>(&snow_spec[20]), snow_head, snow_mode,
        0x3e4ccccdu, 0x3e4ccccdu, 0x3c23d70au, 0xbd23d70au,
        0u, 0x3ca3d70au, 0xbca3d70au, 0x3e19999au,
        snow_tex, 1u);
    void* snow_mem = startup_network_allocate_0059ef90(0x8858u);
    void* snow = snow_mem != nullptr
        ? scene_particle_emitter_ctor_00456ed0(snow_mem, nullptr, snow_spec)
        : nullptr;
    store_ptr(self, 0x04u, snow);

    const U rain_quality = load32(render_mode_state_00619790, 0x64u);
    const U rain_raw_tag = load32(scene_stage_particle_tags_005ceeb8 + 0x10, rain_quality * 4u);
    const I rain_mode = static_cast<I>(load32(render_mode_state_00619790, 0x60u));
    void* rain_tex = startup_context_table_lookup_0044d320(
        scene_stage_particle_table_owner_00613e08, nullptr, 0u, bswap32(rain_raw_tag));
    if (rain_tex == nullptr) {
        rain_tex = startup_context_table_lookup_0044d320(
            scene_stage_particle_table_owner_00613e08, nullptr, 0u, 0x6e696172u);
    }
    const U rain_head[10] = {
        0xc1700000u, 0x41700000u, 0x41f00000u, 0xc0400000u, 0x41200000u,
        0x41500000u, 0x40200000u, 0x41700000u, 0x41700000u, 0x41480000u,
    };
    U rain_spec[21]{};
    build_emitter_spec(
        rain_spec, reinterpret_cast<B*>(&rain_spec[20]), rain_head, rain_mode,
        0x3e4ccccdu, 0x3f000000u, 0u, 0xbf4ccccdu,
        0u, 0u, 0xbea3d70bu, 0u,
        rain_tex, 0u);
    void* rain_mem = startup_network_allocate_0059ef90(0x8858u);
    void* rain = rain_mem != nullptr
        ? scene_particle_emitter_ctor_00456ed0(rain_mem, nullptr, rain_spec)
        : nullptr;
    store_ptr(self, 0x08u, rain);

    const U splt_quad_bits[16] = {
        0x3f800000u, 0x3fb33334u, 0xbf0ccccdu, 0x3f800000u,
        0xbf800000u, 0x3fb33334u, 0xbf0ccccdu, 0x3f800000u,
        0xbf800000u, 0x3f4ccccdu, 0xbf733333u, 0x3f800000u,
        0x3f800000u, 0x3f4ccccdu, 0xbf733333u, 0x3f800000u,
    };
    float splt_quad[16]{};
    std::memcpy(splt_quad, splt_quad_bits, sizeof(splt_quad));

    void* splt_tex = startup_context_table_lookup_0044d320(
        startup_context_table_owner_00613e04, nullptr, 0u, 0x544c5053u);
    void* splt_mem = startup_network_allocate_0059ef90(0x67e4u);
    void* splt = splt_mem != nullptr
        ? scene_splt_emitter_ctor_004577a0(
              splt_mem, nullptr, splt_quad,
              static_cast<U>(reinterpret_cast<std::uintptr_t>(splt_tex)))
        : nullptr;
    store_ptr(self, 0x0cu, splt);
    return self;
}

} // namespace porsche
