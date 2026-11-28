// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run885: scene_flare_ctor_0045d800 and closed setup/config/keyframe helpers
// (20 functions, 4,819B code, 0 new .bss cells).

#include "scene_flare_ctor_885.hpp"

#include "flare_cleanup_slots_882.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/application_state.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_float_helpers.hpp"
#include "porsche/formatter_stdio.hpp"
#include "porsche/formatter_text.hpp"
#include "porsche/install_paths.hpp"
#include "porsche/object_update.hpp"
#include "scene_blur_stage_726.hpp"
#include "scene_flare_resolve_786.hpp"
#include "scene_sky_cleanup_883.hpp"
#include "scene_stage_58b80_ctor_821.hpp"
#include "scene_stage_constructor_781.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

static_assert(sizeof(void*) == 4u, "original x86 pointer size required");

constexpr U kSkyConfigBytes = 0x71dcu;
constexpr char kSkyConfigTag[] = "SkyCnfig";
constexpr char kSkyBinFmt[] = "%sSky\\%s.bin";
constexpr char kSkyDefaultBinFmt[] = "%sSky\\default.bin";
constexpr char kSkyTxtFmt[] = "%sSky\\%s.txt";
constexpr char kSkyDefaultTxtFmt[] = "%sSky\\default.txt";
constexpr char kFlarePosDatFmt[] = "%sflarepos.dat";
constexpr char kAdditiveWarn[] = "Additive mode no longer supported...use multiadditive\n";

constexpr char kWeatherNames[5][20] = {
    "low",
    "medium",
    "high",
    "amazing",
    "all",
};

struct SkyCfgModeEntry {
    const char* name;
    U flags;
};

constexpr SkyCfgModeEntry kSkyCfgModes[] = {
    {"basic", 2u},
    {"multinormal", 4u},
    {"additive", 0x100u},
    {"multiadditive", 8u},
    {"multiattenuate", 0x10u},
    {"multimodulate", 0x20u},
    {"freecloud", 0x40u},
    {"config", 1u},
    {"basicwater", 0x202u},
    {"multinormalwater", 0x204u},
    {"multiadditivewater", 0x208u},
    {"multiattenuatewater", 0x210u},
    {"multimodulatewater", 0x220u},
};

struct FlareTextCfg {
    void* entries[20]; // +0x00 .. +0x4f
    I count;           // +0x50
    char* buf;         // +0x54
    char* buf_end;     // +0x58
    char* cursor;      // +0x5c
    I buf_len;         // +0x60
};
static_assert(sizeof(FlareTextCfg) == 0x64u, "FlareTextCfg must be 0x64 bytes");

inline U addr32(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline void* ptr_from32(U raw) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(raw));
}

inline U load_u32(const void* base, U offset = 0u) noexcept {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline I load_i32(const void* base, U offset = 0u) noexcept {
    I value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline float load_f32(const void* base, U offset = 0u) noexcept {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline void store_u32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline void store_u8(void* base, U offset, B value) noexcept {
    *(static_cast<B*>(base) + offset) = value;
}

inline void store_f32(void* base, U offset, float value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline I& app_state_i32(U va) noexcept {
    static_assert(sizeof(I) == sizeof(U));
    return reinterpret_cast<I&>(
        application_state_006573e8.words_[(va - application_state_base_va) / 4u]);
}

inline void cfg_advance_token(FlareTextCfg* cfg) noexcept {
    do {
        while (cfg->cursor < cfg->buf_end && *cfg->cursor != '\0') {
            ++cfg->cursor;
        }
        if (cfg->cursor < cfg->buf_end) {
            ++cfg->cursor;
        }
    } while (*cfg->cursor == '#' && cfg->cursor < cfg->buf_end);
}

inline bool contains_token_substr(const char* haystack, const char* needle) {
    const U needle_len = static_cast<U>(std::strlen(needle));
    for (const char* p = haystack; *p != '\0'; ++p) {
        if (formatter_text_compare_n_005a2210(needle, p, needle_len) == 0) {
            return true;
        }
    }
    return false;
}

inline void* init_cursor_a_or_c(
    void* self, void* keys, void* resource, bool write_f32_one) noexcept {
    store_u32(self, 0x00u, addr32(keys));
    store_u32(self, 0x04u, addr32(resource));
    store_u8(self, 0x18u, 0u);
    I count = 0;
    while (count < 400 && load_i32(keys, static_cast<U>(count) * 8u) >= 0) {
        ++count;
    }
    store_u32(self, 0x08u, static_cast<U>(count));
    if (count < 2) {
        store_u32(keys, 0x00u, 0u);
        store_u32(keys, 0x08u, 4u);
        if (write_f32_one) {
            store_u32(keys, 0x04u, 0u);
            store_u32(keys, 0x0cu, 0x3f800000u);
        } else {
            store_u8(keys, 0x04u, 0u);
            store_u8(keys, 0x0cu, 0u);
        }
        store_u32(self, 0x08u, 2u);
    }
    store_u32(self, 0x14u, 0u);
    store_u32(self, 0x0cu, 0u);
    store_u32(self, 0x10u, 1u);
    return self;
}

inline void* alloc_effect_b(
    const void* cfg_entry, void* sky, void* res, U variant, U flags) {
    void* const mem = startup_network_allocate_0059ef90(0x88u);
    if (mem == nullptr) {
        return nullptr;
    }
    return scene_flare_effect_b_ctor_0045b5a0(
        mem, nullptr, const_cast<void*>(cfg_entry), sky, res,
        variant, (flags & 0x200u) == 0x200u ? 1u : 0u);
}

} // namespace

// 0053bfd0..0053bfd5 (6B)
U __stdcall get_tick_count_0053bfd0() {
    return platform_get_tick_count();
}

// 005327f0..005327fc (13B)
double __cdecl math_fcos_tau_005327f0(float turns) {
    static const std::uint64_t kTauBits = 0x401921fb20000000ull; // 6.28318452835083
    double result = 0.0;
    __asm {
        fld dword ptr [turns]
        fmul qword ptr [kTauBits]
        fcos
        fstp qword ptr [result]
    }
    return result;
}

// 00461090..00461102 (115B)
void __cdecl scene_flare_sun_dir_00461090(
    float x, float y, float turns, float elev, float scale,
    float* out_vec4, float radius) {
    const float c = static_cast<float>(math_fcos_tau_005327f0(turns));
    const double s = math_fsin_tau_005327e0(turns);
    out_vec4[3] = 1.0f;
    out_vec4[0] = static_cast<float>(
        (s * static_cast<double>(y) + static_cast<double>(c) * static_cast<double>(x)) *
        static_cast<double>(radius));
    out_vec4[1] = static_cast<float>(
        (static_cast<double>(elev) -
         (static_cast<double>(y) * static_cast<double>(y) +
          static_cast<double>(x) * static_cast<double>(x)) *
             static_cast<double>(scale)) *
        static_cast<double>(radius));
    out_vec4[2] = static_cast<float>(
        (static_cast<double>(c) * static_cast<double>(y) - s * static_cast<double>(x)) *
        static_cast<double>(radius));
}

// 00460c70..00460c7a (11B)
void* __fastcall scene_sky_chunk_get_00460c70(void* self, void*, I index) {
    return ptr_from32(load_u32(self, 8u + static_cast<U>(index) * 4u));
}

// 00460780..00460a0a (651B)
void* __fastcall scene_flare_pos_ctor_00460780(void* self, void*, void* resource) {
    store_u32(self, 0x194u, get_tick_count_0053bfd0());
    store_u32(self, 0x13cu, addr32(resource));
    store_u32(self, 0x198u, 0u);
    store_u32(self, 0x19cu, 0u);
    store_u32(self, 0x144u, 0u);
    store_u8(self, 0x18cu, 0u);
    store_u8(self, 0x18du, 0u);
    store_u32(self, 0x190u, 0u);

    const void* const cfg = ptr_from32(load_u32(resource, 0x104u));
    const float f_cdc = load_f32(cfg, 0xcdcu);
    const float f_ce0 = load_f32(cfg, 0xce0u);
    const bool out_of_band =
        (f_cdc <= -0.02f || 0.02f <= f_cdc || f_ce0 <= -0.02f || 0.02f <= f_ce0);
    store_u8(self, 0x140u, out_of_band ? 1u : 0u);

    store_u32(self, 0x104u, 0x3f800000u);
    store_u32(self, 0x10cu, 0x3f800000u);
    store_u32(self, 0x110u, 0x3f800000u);
    store_u32(self, 0x118u, 0x3f800000u);
    store_u32(self, 0x0fcu, 0u);
    store_u32(self, 0x100u, 0u);
    store_u32(self, 0x108u, 0u);
    store_u32(self, 0x114u, 0u);
    std::memset(static_cast<B*>(self) + 0x148u, 0, 0x40u);
    store_u32(self, 0x188u, 2u);

    for (I i = 0; i < 14; ++i) {
        void* const mode_mem = startup_network_allocate_0059ef90(0x18u);
        void* const mode_obj = (mode_mem != nullptr)
            ? scene_mode_ctor_005379f0(mode_mem, nullptr)
            : nullptr;
        store_u32(self, 0x38u + static_cast<U>(i) * 4u, addr32(mode_obj));
        scene_mode_set_00537a50(mode_obj, nullptr, 1u);

        void* const prog_mem = startup_network_allocate_0059ef90(0x28u);
        void* const prog_obj = (prog_mem != nullptr)
            ? scene_blur_program_ctor_00468240(
                  prog_mem, nullptr, 0x16u, 4u, 1u,
                  addr32(static_cast<B*>(self) + 0xbcu), 4u)
            : nullptr;
        store_u32(self, static_cast<U>(i) * 4u, addr32(prog_obj));
        scene_blur_program_setup_004685e0(prog_obj, nullptr, 0u, 0u, addr32(mode_obj), 0u, 0u, 0u);
        store_u32(self, 0x70u + static_cast<U>(i) * 4u, 0u);
        store_u8(self, 0xa8u + static_cast<U>(i), 0u);
    }

    const void* const res_cfg = ptr_from32(load_u32(ptr_from32(load_u32(self, 0x13cu)), 0x104u));
    auto* const sun_dst = reinterpret_cast<float*>(static_cast<B*>(self) + 0x11cu);
    scene_flare_sun_dir_00461090(
        load_f32(res_cfg, 0xcdcu), load_f32(res_cfg, 0xce0u),
        load_f32(res_cfg, 0x3cu), load_f32(res_cfg, 0x48u),
        load_f32(res_cfg, 0x44u), sun_dst, load_f32(res_cfg, 0xce4u));
    store_u32(self, 0x0b8u, 0u);
    std::memcpy(static_cast<B*>(self) + 0x12cu, sun_dst, 0x10u);

    char path[400]{};
    (void)formatter_entry_005a0fbf(path, kFlarePosDatFmt, startup_resource_prefix_0065b30c);
    void* pos_data = resource_open_quiet_0059d9b0(path, 0u);
    store_u32(self, 0x0b8u, addr32(pos_data));
    if (pos_data == nullptr) {
        pos_data = application_context_member_block_0059ecb0(0x38u, 0u, 0u);
        store_u32(self, 0x0b8u, addr32(pos_data));
        static constexpr U kDefaultFlarePos[9] = {
            0x3f800000u, 0x3f400000u, 0xbf400000u,
            0x3f000000u, 0xbf000000u, 0x3e800000u,
            0xbe800000u, 0x00000000u, 0xbf800000u,
        };
        for (U off = 0u; off < 0x38u; off += 4u) {
            store_u32(pos_data, off, (off < 0x24u) ? kDefaultFlarePos[off / 4u] : 0u);
        }
    }
    return self;
}

// 004601f0..0046021d (46B)
void __cdecl scene_flare_pos_init_004601f0(void* resource) {
    void* const mem = startup_network_allocate_0059ef90(0x1a0u);
    scene_sky_cleanup_state_00627e5c = (mem != nullptr)
        ? scene_flare_pos_ctor_00460780(mem, nullptr, resource)
        : nullptr;
}

// 0045fb00..0045fb09 (10B)
void* __fastcall scene_flare_cfg_entry_0045fb00(void* self, void*, I index) {
    return ptr_from32(load_u32(self, static_cast<U>(index) * 4u));
}

// 0045fb10..0045fb7e (111B)
I __fastcall scene_flare_cfg_tokenize_0045fb10(void* self, void*, char* begin, char* end) {
    (void)self;
    char* write_it = begin;
    char* read_it = begin;
    if (read_it < end) {
        for (;;) {
            while (read_it < end) {
                const char c = *read_it;
                if (c != '\n' && c != '\r' && c != ' ' && c != '\t') {
                    break;
                }
                ++read_it;
            }
            char c = *read_it;
            if (c != '\n' && c != '\r' && c != '\t') {
                do {
                    if (read_it >= end) {
                        goto finish;
                    }
                    *write_it++ = c;
                    c = *++read_it;
                } while (c != '\n' && c != '\r' && c != '\t');
            }
            if (read_it >= end) {
                break;
            }
            *write_it++ = '\0';
            ++read_it;
            if (read_it >= end) {
                break;
            }
        }
    }
finish:
    if (write_it[-1] != '\0') {
        *write_it++ = '\0';
    }
    return static_cast<I>(write_it - begin);
}

// 0045fb80..00460168 (1,513B)
void* __fastcall scene_flare_cfg_ctor_0045fb80(
    void* self, void*, const char* name, I weather_idx) {
    auto* const cfg = static_cast<FlareTextCfg*>(self);
    std::memset(cfg->entries, 0, sizeof(cfg->entries));
    cfg->count = 0;

    char path[200]{};
    (void)formatter_entry_005a0fbf(path, kSkyTxtFmt, install_paths_table_0065b2a0[6], name);
    cfg->buf = static_cast<char*>(resource_open_quiet_0059d9b0(path, 0u));
    if (cfg->buf == nullptr) {
        (void)formatter_entry_005a0fbf(path, kSkyDefaultTxtFmt, install_paths_table_0065b2a0[6]);
        cfg->buf = static_cast<char*>(resource_open_quiet_0059d9b0(path, 0u));
        if (cfg->buf == nullptr) {
            return cfg;
        }
    }

    if (install_paths_size_00556640(cfg->buf) == 0u) {
        return cfg;
    }
    const U raw_len = install_paths_size_00556640(cfg->buf);
    const I tok_len = scene_flare_cfg_tokenize_0045fb10(
        cfg, nullptr, cfg->buf, cfg->buf + raw_len);
    cfg->buf_len = tok_len;
    cfg->buf_end = cfg->buf + tok_len;
    for (char* p = cfg->buf; p < cfg->buf_end; ++p) {
        *p = static_cast<char>(formatter_float_lower_005a2248(static_cast<unsigned char>(*p)));
    }
    cfg->cursor = cfg->buf;
    if (cfg->cursor >= cfg->buf_end) {
        return cfg;
    }

    const char* const weather_name = kWeatherNames[weather_idx];
    while (cfg->cursor < cfg->buf_end) {
        cfg_advance_token(cfg);
        if (contains_token_substr(cfg->cursor, weather_name) ||
            contains_token_substr(cfg->cursor, kWeatherNames[4])) {
            cfg_advance_token(cfg);
            const char* const mode_tok = cfg->cursor;
            U mode_flags = 0x800u;
            for (const auto& m : kSkyCfgModes) {
                if (std::strcmp(mode_tok, m.name) == 0) {
                    mode_flags = m.flags;
                    if (mode_flags == 0x100u) {
                        (void)formatter_stdio_printf_005a177b(kAdditiveWarn);
                    }
                    break;
                }
            }
            cfg_advance_token(cfg);
            void* const item = startup_network_allocate_0059ef90(0x0cu);
            if (item != nullptr) {
                store_u32(item, 0u, mode_flags);
                store_u32(item, 4u, addr32(cfg->cursor));
                store_u32(item, 8u, addr32(cfg->cursor));
            }
            cfg->entries[cfg->count++] = item;
        }
        while (formatter_text_compare_n_005a2210(cfg->cursor, "begin", 5u) != 0 &&
               cfg->cursor < cfg->buf_end) {
            cfg_advance_token(cfg);
        }
    }
    return cfg;
}

// 00460170..004601a2 (51B)
void __fastcall scene_flare_cfg_dtor_00460170(void* self, void*) {
    auto* const cfg = static_cast<FlareTextCfg*>(self);
    for (U i = 0u; i < 20u; ++i) {
        if (cfg->entries[i] != nullptr) {
            (void)application_release_0059f050(cfg->entries[i]);
        }
    }
    if (cfg->buf != nullptr) {
        (void)free_00531f90(cfg->buf);
    }
}

// 0045cb80..0045cc14 (149B)
void* __fastcall scene_route_sky_aux_ctor_0045cb80(void* self, void*, void* sky) {
    const I idx = scene_sky_find_name_00460b50(sky, nullptr, "ltmp");
    if (idx == -1) {
        for (U off = 0u; off < 0x310u; off += 4u) {
            store_u32(self, off, 0xffu);
        }
        return self;
    }
    const B* const chunk = static_cast<const B*>(scene_sky_chunk_get_00460c70(sky, nullptr, idx));
    U src_off = 0x10u;
    U dst_off = 0u;
    for (I row = 0; row < 7; ++row) {
        for (I col = 0; col < 7; ++col) {
            const U word = load_u32(chunk, src_off);
            src_off += 4u;
            store_u32(self, dst_off + 0x00u, word >> 24u);
            store_u32(self, dst_off + 0x04u, (word >> 16u) & 0xffu);
            store_u32(self, dst_off + 0x08u, (word >> 8u) & 0xffu);
            store_u32(self, dst_off + 0x0cu, word & 0xffu);
            dst_off += 0x10u;
        }
    }
    return self;
}

// 0045cc40..0045ccaa (107B)
void __cdecl scene_route_sky_bytes_init_0045cc40(const char* name, void* sky, void* resource) {
    (void)name;
    void* const aux_mem = startup_network_allocate_0059ef90(0x310u);
    scene_route_sky_aux_00627e3c = (aux_mem != nullptr)
        ? scene_route_sky_aux_ctor_0045cb80(aux_mem, nullptr, sky)
        : nullptr;

    void* const bytes = startup_network_allocate_0059ef90(0x24u);
    if (bytes != nullptr) {
        store_u8(bytes, 0x00u, 0u);
        store_u32(bytes, 0x04u, 0u);
        store_u32(bytes, 0x08u, 0xffffffffu);
        store_u32(bytes, 0x0cu, 0xffffffffu);
        store_u32(bytes, 0x10u, 0u);
        store_u32(bytes, 0x14u, 0u);
        store_u32(bytes, 0x18u, addr32(resource));
        store_u32(bytes, 0x20u, 0u);
        store_u32(bytes, 0x1cu, 0u);
        scene_route_sky_bytes_00627e38 = bytes;
        return;
    }
    scene_route_sky_bytes_00627e38 = nullptr;
}

// 0045a2c0..0045a326 (103B)
void* __fastcall scene_flare_cursor_a_ctor_0045a2c0(
    void* self, void*, void* keys, void* resource) {
    return init_cursor_a_or_c(self, keys, resource, true);
}

// 0045a490..0045a530 (161B)
void* __fastcall scene_flare_cursor_b_ctor_0045a490(
    void* self, void*, void* keys, void* resource) {
    store_u32(self, 0x00u, addr32(keys));
    store_u32(self, 0x14u, addr32(resource));
    store_u8(self, 0x18u, 0u);
    I count = 0;
    while (count < 400 && load_i32(keys, static_cast<U>(count) * 0x30u) >= 0) {
        ++count;
    }
    store_u32(self, 0x04u, static_cast<U>(count));
    if (count < 2) {
        std::memset(keys, 0, 0x60u);
        store_u32(keys, 0x30u, 4u);
        store_u32(self, 0x04u, 2u);
    }
    store_u32(self, 0x10u, 0u);
    store_u32(self, 0x08u, 0u);
    store_u32(self, 0x0cu, 1u);
    return self;
}

// 0045a970..0045a9d2 (99B)
void* __fastcall scene_flare_cursor_c_ctor_0045a970(
    void* self, void*, void* keys, void* resource) {
    return init_cursor_a_or_c(self, keys, resource, false);
}

// 00459950..004599b9 (106B)
void __cdecl scene_flare_aux_init_00459950() {
    void* const aux = startup_network_allocate_0059ef90(4u);
    if (aux == nullptr) {
        scene_flare_aux_00627e1c = nullptr;
        return;
    }
    const void* const cfg = ptr_from32(load_u32(scene_flare_resource_00627e18, 0x104u));
    I idx = app_state_i32(0x00657d9cu);
    bool found = false;
    while (idx >= 0) {
        if (load_u32(cfg, 0xce8u + static_cast<U>(idx) * 0x3cu) != 0u) {
            found = true;
            break;
        }
        --idx;
    }
    if (!found) {
        idx = 0;
    }
    store_u32(aux, 0u, addr32(static_cast<const B*>(cfg) + 0xce8u + static_cast<U>(idx) * 0x3cu));
    scene_flare_aux_00627e1c = aux;
}

// 00459700..00459947 (584B)
void __fastcall scene_flare_resource_upgrade_00459700(
    void* self, void*, I version) {
    void* const new_cfg =
        application_context_member_block_0059ecb0(kSkyConfigBytes, 0u, addr32(kSkyConfigTag));
    const U sz = context_table_size_0059ece0(new_cfg);
    void* const old_cfg = ptr_from32(load_u32(self, 0x104u));
    std::memcpy(new_cfg, old_cfg, sz);
    store_u32(new_cfg, 0u, 9u);

    if (version < 1) {
        store_u32(new_cfg, 0x04u, 0u);
        store_u32(new_cfg, 0x08u, 0u);
        store_u32(new_cfg, 0x0cu, 2u);
        store_u32(new_cfg, 0x10u, 2u);
        store_u32(new_cfg, 0x14u, 0xc2c80000u);
        store_u32(new_cfg, 0x18u, 0x437a0000u);
        std::memset(static_cast<B*>(new_cfg) + 0x1cu, 0, 0x20u);
        store_u32(new_cfg, 0x3cu, 0u);
        store_u32(new_cfg, 0x40u, 0x447a0000u);
        store_u32(new_cfg, 0x48u, 0x42960000u);
        store_u32(new_cfg, 0x44u, 0x39d1b717u);
    }
    if (version < 3) {
        store_u32(new_cfg, 0xb3cu, 0u);
        store_u32(new_cfg, 0xb40u, 0x447a0000u);
        store_u32(new_cfg, 0xb44u, 0xb951b717u);
        store_u32(new_cfg, 0xb48u, 0xc2960000u);
    }
    if (version < 5) {
        store_u32(new_cfg, 0xce0u, 0u);
        store_u32(new_cfg, 0xcdcu, 0u);
    }
    if (version < 6) {
        store_u32(new_cfg, 0xce4u, 0x3dcccccd);
    }
    if (version < 7) {
        for (U r = 0u; r < 4u; ++r) {
            const U base = 0xce8u + r * 0x3cu;
            std::memset(static_cast<B*>(new_cfg) + base, 0, 0x3cu);
            store_u32(new_cfg, base + 0x08u, 0x437e0000u);
            store_u32(new_cfg, base + 0x14u, 0x437e0000u);
            store_u32(new_cfg, base + 0x24u, 0x437e0000u);
            store_u32(new_cfg, base + 0x30u, 0x437e0000u);
        }
        store_u32(new_cfg, 0xce8u, 1u);
    }
    if (version < 8) {
        store_u32(new_cfg, 0xdd8u, 1u);
    }
    if (version < 9) {
        if (version < 0) {
            for (U i = 0u; i < 400u; ++i) {
                store_u32(new_cfg, 0xddcu + i * 8u + 0u, 0xffffffffu);
                store_u32(new_cfg, 0xddcu + i * 8u + 4u, 0u);
            }
        } else {
            std::memcpy(static_cast<B*>(new_cfg) + 0xddcu,
                static_cast<const B*>(new_cfg) + 0x4cu, 100u * 4u);
        }
        if (version < 2) {
            for (U i = 0u; i < 400u; ++i) {
                const U base = 0x1a5cu + i * 0x30u;
                std::memset(static_cast<B*>(new_cfg) + base, 0, 0x30u);
                store_u32(new_cfg, base, 0xffffffffu);
            }
        } else {
            std::memcpy(static_cast<B*>(new_cfg) + 0x1a5cu,
                static_cast<const B*>(new_cfg) + 0x1dcu, 600u * 4u);
        }
        if (version < 4) {
            for (U i = 0u; i < 400u; ++i) {
                const U base = 0x655cu + i * 8u;
                store_u32(new_cfg, base, 0xffffffffu);
                store_u8(new_cfg, base + 4u, 0u);
            }
        } else {
            std::memcpy(static_cast<B*>(new_cfg) + 0x655cu,
                static_cast<const B*>(new_cfg) + 0xb4cu, 100u * 4u);
        }
    }

    context_table_release_0059ecd0(old_cfg);
    store_u32(self, 0x104u, addr32(new_cfg));
}

// 00459660..004596ff (160B)
void* __fastcall scene_flare_resource_ctor_00459660(
    void* self, void*, const char* name) {
    store_u8(self, 0u, 0u);
    store_u32(self, 0x108u, 0xffffffffu);
    char* const path = static_cast<char*>(self) + 1;
    (void)formatter_entry_005a0fbf(path, kSkyBinFmt, install_paths_table_0065b2a0[6], name);
    void* res = resource_open_quiet_0059d9b0(path, 0u);
    if (res == nullptr) {
        (void)formatter_entry_005a0fbf(path, kSkyDefaultBinFmt, install_paths_table_0065b2a0[6]);
        res = resource_open_0059d8e0(path, 0u);
    }
    store_u32(self, 0x104u, addr32(res));
    if (res == nullptr) {
        void* const fresh =
            application_context_member_block_0059ecb0(kSkyConfigBytes, 0u, addr32(kSkyConfigTag));
        store_u32(self, 0x104u, addr32(fresh));
        scene_flare_resource_upgrade_00459700(self, nullptr, 0);
        return self;
    }
    const I ver = load_i32(res, 0u);
    if (ver < 9) {
        scene_flare_resource_upgrade_00459700(self, nullptr, ver);
    }
    return self;
}

// 00459600..0045962d (46B)
void __cdecl scene_flare_resource_init_00459600(const char* name) {
    void* const mem = startup_network_allocate_0059ef90(0x10cu);
    scene_flare_resource_00627e18 = (mem != nullptr)
        ? scene_flare_resource_ctor_00459660(mem, nullptr, name)
        : nullptr;
}

// 0045d800..0045db08 (777B)
void* __fastcall scene_flare_ctor_0045d800(void* self, void*, const char* name) {
    store_u32(self, 0x2cu, 0u);
    store_u32(self, 0x30u, 0x3a83126fu);
    store_u32(self, 0x50u, 0u);
    store_u8(self, 0x54u, 0u);
    store_u32(self, 0x5cu, 0u);
    store_u8(self, 0x60u, 1u);
    store_u32(self, 0x38u, 0u);
    store_u32(self, 0x3cu, 0u);
    store_u32(self, 0x40u, 0u);
    std::memset(self, 0, 10u * 4u);
    store_u32(self, 0x28u, 0u);

    scene_flare_resource_init_00459600(name);
    void* const res = scene_flare_resource_00627e18;
    store_u32(self, 0x34u, addr32(res));
    scene_route_sky_bytes_init_0045cc40(name, scene_route_sky_00627e4c, res);
    scene_flare_pos_init_004601f0(ptr_from32(load_u32(self, 0x34u)));
    scene_flare_aux_init_00459950();

    void* const cur_a_mem = startup_network_allocate_0059ef90(0x1cu);
    void* const cur_a = (cur_a_mem != nullptr)
        ? scene_flare_cursor_a_ctor_0045a2c0(
              cur_a_mem, nullptr,
              static_cast<B*>(ptr_from32(load_u32(ptr_from32(load_u32(self, 0x34u)), 0x104u))) + 0xddcu,
              ptr_from32(load_u32(self, 0x34u)))
        : nullptr;
    store_u32(self, 0x44u, addr32(cur_a));

    void* const cur_b_mem = startup_network_allocate_0059ef90(0x1cu);
    void* const cur_b = (cur_b_mem != nullptr)
        ? scene_flare_cursor_b_ctor_0045a490(
              cur_b_mem, nullptr,
              static_cast<B*>(ptr_from32(load_u32(ptr_from32(load_u32(self, 0x34u)), 0x104u))) + 0x1a5cu,
              ptr_from32(load_u32(self, 0x34u)))
        : nullptr;
    store_u32(self, 0x48u, addr32(cur_b));

    void* const cur_c_mem = startup_network_allocate_0059ef90(0x1cu);
    void* const cur_c = (cur_c_mem != nullptr)
        ? scene_flare_cursor_c_ctor_0045a970(
              cur_c_mem, nullptr,
              static_cast<B*>(ptr_from32(load_u32(ptr_from32(load_u32(self, 0x34u)), 0x104u))) + 0x655cu,
              ptr_from32(load_u32(self, 0x34u)))
        : nullptr;
    store_u32(self, 0x4cu, addr32(cur_c));

    FlareTextCfg cfg{};
    (void)scene_flare_cfg_ctor_0045fb80(&cfg, nullptr, name, app_state_i32(0x00657d9cu));
    for (I i = 0; i < cfg.count; ++i) {
        void* const entry = scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i);
        const U flags = load_u32(entry, 0u);
        if ((flags & 2u) != 0u) {
            void* const mem = startup_network_allocate_0059ef90(0x5cu);
            void* const eff = (mem != nullptr)
                ? scene_flare_effect_a_ctor_0045adf0(
                      mem, nullptr, scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                      scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)),
                      (flags & 0x200u) == 0x200u ? 1u : 0u)
                : nullptr;
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        } else if ((flags & 4u) != 0u) {
            void* const eff = alloc_effect_b(
                scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)), 0u, flags);
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        } else if ((flags & 8u) != 0u) {
            void* const eff = alloc_effect_b(
                scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)), 1u, flags);
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        } else if ((flags & 0x10u) != 0u) {
            void* const eff = alloc_effect_b(
                scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)), 2u, flags);
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        } else if ((flags & 0x20u) != 0u) {
            void* const eff = alloc_effect_b(
                scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)), 3u, flags);
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        } else if ((flags & 0x40u) != 0u) {
            void* const mem = startup_network_allocate_0059ef90(0xfcu);
            void* const eff = (mem != nullptr)
                ? scene_flare_effect_c_ctor_0045bf80(
                      mem, nullptr, scene_flare_cfg_entry_0045fb00(&cfg, nullptr, i),
                      scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)))
                : nullptr;
            const U slot_idx = load_u32(self, 0x28u);
            store_u32(self, slot_idx * 4u, addr32(eff));
            store_u32(self, 0x28u, slot_idx + 1u);
        }
    }

    void* const final_mem = startup_network_allocate_0059ef90(0x58u);
    void* const final_eff = (final_mem != nullptr)
        ? scene_flare_final_effect_ctor_00459b50(
              final_mem, nullptr, scene_route_sky_00627e4c, ptr_from32(load_u32(self, 0x34u)))
        : nullptr;
    const U final_slot = load_u32(self, 0x28u);
    store_u32(self, final_slot * 4u, addr32(final_eff));
    store_u32(self, 0x28u, final_slot + 1u);

    scene_flare_cfg_dtor_00460170(&cfg, nullptr);
    return self;
}

} // namespace porsche
