// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run835: recovered bodies for entry_fe_service_00465790 and its closed
// view-slot / sector / quadtree / track-portal dependencies (17 functions, 4,563B).

#include "entry_fe_service_835.hpp"

#include "porsche/application_alloc.hpp"
#include "porsche/application_context_base.hpp"
#include "porsche/application_state.hpp"
#include "porsche/context_effects.hpp"
#include "porsche/context_services.hpp"
#include "porsche/heap.hpp"

#include <cstring>

namespace porsche {

ViewModeCameraPreset005cf610 view_mode_camera_presets_005cf610[21] = {
    {0x00000000u, 0x3ecccccdu, 0x3f666666u, 0x00000002u},
    {0x00000000u, 0x3ecccccdu, 0x3f666666u, 0x00000000u},
    {0x00000000u, 0x3f933333u, 0xc0533333u, 0x0000002du},
    {0x00000000u, 0x3faccccdu, 0xc0900000u, 0x0000002du},
    {0x00000000u, 0x3f933333u, 0xc099999au, 0x0000002du},
    {0x00000000u, 0x40000000u, 0xc0c00000u, 0x0000002du},
    {0x00000000u, 0x40000000u, 0xc0c00000u, 0x0000002du},
    {0x00000000u, 0x409ccccdu, 0xc0d66666u, 0x0000002du},
    {0xbfe00000u, 0x3e800000u, 0xc0700000u, 0x0000003cu},
    {0x00000000u, 0x3fc3d70au, 0x40833333u, 0x00000038u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x0000003cu},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000014u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000014u},
    {0x00000000u, 0x41700000u, 0xc0000000u, 0x00000014u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000010u},
    {0x00000000u, 0x3f800000u, 0xbeff7ceeu, 0x00000012u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000018u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000018u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000014u},
    {0x00000000u, 0x00000000u, 0x00000000u, 0x00000014u},
    {0xffffffffu, 0xffffffffu, 0xffffffffu, 0xffffffffu},
};

std::uint32_t sector_query_count_006289ec = 0u;
std::uint32_t sector_cache_hits_006289f0 = 0u;
float quadtree_cell_sizes_00628be8[16] = {};
float quadtree_origin_offset_00628c30 = 0.0f;

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

static_assert(sizeof(void*) == 4u, "original x86 pointer size required");

struct DwordVector12 {
    U begin;
    U end;
    U capacity_end;
};
static_assert(sizeof(DwordVector12) == 12u, "DwordVector12 must be 12 bytes");

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

inline std::uint16_t load_u16(const void* base, U offset = 0u) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline std::int16_t load_i16(const void* base, U offset = 0u) noexcept {
    std::int16_t value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline float load_f32(const void* base, U offset = 0u) noexcept {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

inline B load_u8(const void* base, U offset = 0u) noexcept {
    return *(static_cast<const B*>(base) + offset);
}

inline std::int8_t load_i8(const void* base, U offset = 0u) noexcept {
    return static_cast<std::int8_t>(*(static_cast<const B*>(base) + offset));
}

inline void store_u32(void* base, U offset, U value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline void store_u16(void* base, U offset, std::uint16_t value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline void store_i16(void* base, U offset, std::int16_t value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline void store_f32(void* base, U offset, float value) noexcept {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

inline void store_u8(void* base, U offset, B value) noexcept {
    *(static_cast<B*>(base) + offset) = value;
}

inline void release_pool_block(void* ptr, U count, U elem_bytes) {
    const U bytes = count * elem_bytes;
    if (bytes > 0x100u) {
        context_table_release_0059ecd0(ptr);
        return;
    }
    B* const pool_base =
        static_cast<B*>(application_context_heap_state_005e4fe8()) + 0x28u;
    void* const lock = ptr_from32(load_u32(pool_base, 0u));
    heap_enter_005322b0(lock);
    const U bucket = (bytes - 1u) >> 3u;
    const U head = load_u32(pool_base, 0x0cu + bucket * 4u);
    store_u32(ptr, 4u, head);
    store_u32(pool_base, 0x0cu + bucket * 4u, addr32(ptr));
    heap_leave_005322c0(lock);
}

inline void release_dword_vector_storage(DwordVector12* vec) {
    if (vec == nullptr) {
        return;
    }
    const U count =
        static_cast<U>(static_cast<I>(vec->capacity_end - vec->begin) >> 2);
    if (count != 0u) {
        release_pool_block(ptr_from32(vec->begin), count, 4u);
    }
}

inline void quadtree_cell_center(
    U packed_tag, float* out_size, float* out_cx, float* out_cz) noexcept {
    const float sz = quadtree_cell_sizes_00628be8[packed_tag >> 28u];
    const U gx = packed_tag & 0x3fffu;
    const U gz = (packed_tag >> 14u) & 0x3fffu;
    *out_size = sz;
    *out_cx = (static_cast<float>(static_cast<double>(gx)) + 0.5f) * sz -
        quadtree_origin_offset_00628c30;
    *out_cz = (static_cast<float>(static_cast<double>(gz)) + 0.5f) * sz -
        quadtree_origin_offset_00628c30;
}

inline bool quadtree_is_internal(const void* node) noexcept {
    return load_u32(node, 0x04u) != 0u || load_u32(node, 0x08u) != 0u ||
        load_u32(node, 0x0cu) != 0u || load_u32(node, 0x10u) != 0u;
}

inline U find_track_region_index(const void* region_vec, I seg) noexcept {
    const U begin = load_u32(region_vec, 0u);
    const U end = load_u32(region_vec, 4u);
    const I count = static_cast<I>(end - begin) / 0x28;
    for (I idx = 0; idx < count; ++idx) {
        const void* const entry = ptr_from32(begin + static_cast<U>(idx) * 0x28u);
        if (load_i32(entry, 0u) <= seg && seg <= load_i32(entry, 0x10u)) {
            return static_cast<U>(idx);
        }
    }
    return 0xffffffffu;
}

using SurfaceGetCenterFn = void(__fastcall*)(void*, void*, float*);
using SurfaceContainsFn = B(__fastcall*)(void*, void*, const float*);
using SurfaceGetNormalFn = void(__fastcall*)(void*, void*, float*);
using SurfaceGetVertexFn = const float*(__fastcall*)(void*, void*, I);
using SurfaceVertexCountFn = I(__fastcall*)(void*, void*);

inline void surface_get_center(void* surface, float* out_vec3) {
    const void* const vt = ptr_from32(load_u32(surface, 0u));
    reinterpret_cast<SurfaceGetCenterFn>(ptr_from32(load_u32(vt, 0x04u)))(
        surface, nullptr, out_vec3);
}

inline B surface_contains(void* surface, const float* pos) {
    const void* const vt = ptr_from32(load_u32(surface, 0u));
    return reinterpret_cast<SurfaceContainsFn>(ptr_from32(load_u32(vt, 0x0cu)))(
        surface, nullptr, pos);
}

inline void surface_get_normal(void* surface, float* out_vec3) {
    const void* const vt = ptr_from32(load_u32(surface, 0u));
    reinterpret_cast<SurfaceGetNormalFn>(ptr_from32(load_u32(vt, 0x14u)))(
        surface, nullptr, out_vec3);
}

inline const float* surface_get_vertex(void* surface, I index) {
    const void* const vt = ptr_from32(load_u32(surface, 0u));
    return reinterpret_cast<SurfaceGetVertexFn>(ptr_from32(load_u32(vt, 0x18u)))(
        surface, nullptr, index);
}

inline I surface_vertex_count(void* surface) {
    const void* const vt = ptr_from32(load_u32(surface, 0u));
    return reinterpret_cast<SurfaceVertexCountFn>(ptr_from32(load_u32(vt, 0x20u)))(
        surface, nullptr);
}

inline void* quadtree_root_from_frame_service() noexcept {
    const void* const root = ptr_from32(frame_service_root_00628960);
    const void* const slot24 = ptr_from32(load_u32(root, 0x24u));
    return ptr_from32(load_u32(slot24, 0u));
}

} // namespace

// 0042bcb0..0042bcc0 (17B)
void __cdecl assign_dword_if_nonnull_0042bcb0(U* dst, const U* src) {
    if (dst != nullptr) {
        *dst = *src;
    }
}

// 0046db70..0046db94 (37B)
U* __cdecl copy_dword_range_0046db70(const U* first, const U* last, U* dst) {
    while (first != last) {
        if (dst != nullptr) {
            *dst = *first;
        }
        ++first;
        ++dst;
    }
    return dst;
}

// 0056e8d1..0056e8f4 (36B)
float __cdecl vec3_dot_inner_0056e8d1(const float* a, const float* b) {
    return (a[1] * b[1] + a[0] * b[0]) + a[2] * b[2];
}

// 00532910..00532922 (19B)
float __cdecl vec3_dot_00532910(const float* a, const float* b) {
    return vec3_dot_inner_0056e8d1(a, b);
}

// 0048a060..0048a095 (54B)
float __cdecl ray_plane_param_0048a060(
    const float* normal, const float* plane_pt, const float* ray_origin) {
    const float plane_dot =
        (plane_pt[1] * normal[1] + plane_pt[2] * normal[2]) + normal[0] * plane_pt[0];
    const float numer =
        -((-plane_dot + ray_origin[2] * normal[2]) + normal[0] * ray_origin[0]);
    return numer / normal[1];
}

// 00484450..004844f2 (163B)
B __fastcall quadtree_node_contains_xz_00484450(void* self, void*, const float* pos) {
    const U tag = load_u32(self, 0u);
    const float sz = quadtree_cell_sizes_00628be8[tag >> 28u];
    const float x_min =
        static_cast<float>(static_cast<double>(tag & 0x3fffu)) * sz -
        quadtree_origin_offset_00628c30;
    const float z_min =
        static_cast<float>(static_cast<double>((tag >> 14u) & 0x3fffu)) * sz -
        quadtree_origin_offset_00628c30;
    if (x_min <= pos[0] && pos[0] <= x_min + sz &&
        z_min <= pos[2] && pos[2] <= z_min + sz) {
        return 1u;
    }
    return 0u;
}

// 00484500..00484627 (296B)
void* __fastcall quadtree_lookup_leaf_00484500(void* self, void*, const float* pos) {
    if (!quadtree_is_internal(self)) {
        return self;
    }
    float sz = 0.0f;
    float cx = 0.0f;
    float cz = 0.0f;
    quadtree_cell_center(load_u32(self, 0u), &sz, &cx, &cz);

    void* cur = self;
    while (cur != nullptr) {
        if (load_u32(cur, 0x14u) != 0u) {
            return cur;
        }
        const float step = sz * 0.25f;
        if (pos[0] < cx) {
            cx -= step;
            if (pos[2] < cz) {
                cz -= step;
                cur = ptr_from32(load_u32(cur, 0x0cu));
            } else {
                cz += step;
                cur = ptr_from32(load_u32(cur, 0x04u));
            }
        } else {
            cx += step;
            if (pos[2] < cz) {
                cz -= step;
                cur = ptr_from32(load_u32(cur, 0x10u));
            } else {
                cz += step;
                cur = ptr_from32(load_u32(cur, 0x08u));
            }
        }
        sz *= 0.5f;
    }
    return self;
}

// 00484630..004848af (640B)
void __fastcall quadtree_collect_leaves_00484630(
    void* self, void*, const float* pos, float radius, void* out_vec) {
    void* cur = self;
    while (quadtree_is_internal(cur)) {
        float sz = 0.0f;
        float cx = 0.0f;
        float cz = 0.0f;
        quadtree_cell_center(load_u32(cur, 0u), &sz, &cx, &cz);

        if (pos[0] - radius < cx) {
            if (pos[2] - radius < cz) {
                void* const sw = ptr_from32(load_u32(cur, 0x0cu));
                if (sw != nullptr) {
                    quadtree_collect_leaves_00484630(sw, nullptr, pos, radius, out_vec);
                }
            }
            if (cz <= radius + pos[2]) {
                void* const nw = ptr_from32(load_u32(cur, 0x04u));
                if (nw != nullptr) {
                    quadtree_collect_leaves_00484630(nw, nullptr, pos, radius, out_vec);
                }
            }
        }
        if (radius + pos[0] < cx) {
            return;
        }
        if (pos[2] - radius < cz) {
            void* const se = ptr_from32(load_u32(cur, 0x10u));
            if (se != nullptr) {
                quadtree_collect_leaves_00484630(se, nullptr, pos, radius, out_vec);
            }
        }
        if (radius + pos[2] < cz) {
            return;
        }
        cur = ptr_from32(load_u32(cur, 0x08u));
        if (cur == nullptr) {
            return;
        }
    }

    auto* const vec = static_cast<DwordVector12*>(out_vec);
    if (vec->end != vec->capacity_end) {
        if (vec->end != 0u) {
            store_u32(ptr_from32(vec->end), 0u, addr32(cur));
        }
        vec->end += 4u;
        return;
    }

    const I old_count = static_cast<I>(vec->end - vec->begin) >> 2;
    const I new_cap = (old_count == 0) ? 1 : (old_count * 2);
    U* const new_buf = (new_cap != 0)
        ? static_cast<U*>(application_context_member_storage_004211d0(
              static_cast<U>(new_cap) * 4u, 0u))
        : nullptr;

    U* write_it = new_buf;
    const U* const old_begin = static_cast<const U*>(ptr_from32(vec->begin));
    const U* const old_end = static_cast<const U*>(ptr_from32(vec->end));
    for (const U* read_it = old_begin; read_it != old_end; ++read_it) {
        assign_dword_if_nonnull_0042bcb0(write_it, read_it);
        ++write_it;
    }
    const U cur_val = addr32(cur);
    if (write_it != nullptr) {
        *write_it = cur_val;
    }
    U* const after_insert = write_it + 1;
    release_dword_vector_storage(vec);
    vec->begin = addr32(new_buf);
    vec->end = addr32(after_insert);
    vec->capacity_end = addr32(new_buf + new_cap);
}

// 004816f0..00481791 (162B)
void* __fastcall track_portal_query_004816f0(void* self, void*, I seg, I delta) {
    const void* const region_vec = ptr_from32(load_u32(self, 0x18u));
    const U r_idx = find_track_region_index(region_vec, seg);
    const void* const entry = ptr_from32(load_u32(region_vec, 0u) + r_idx * 0x28u);
    const I min_seg = load_i32(entry, 0u);
    const I max_seg = load_i32(entry, 0x10u);
    const I target = seg + delta;
    if (target < min_seg || max_seg < target) {
        const I boundary = (max_seg < target) ? max_seg : min_seg;
        const I portal_idx = load_i8(ptr_from32(load_u32(self, 0x14u)), static_cast<U>(boundary));
        if (portal_idx >= 0) {
            const void* const portal_vec = ptr_from32(load_u32(self, 0x1cu));
            return ptr_from32(load_u32(portal_vec, 0u) + static_cast<U>(portal_idx) * 0x38u);
        }
    }
    return nullptr;
}

// 004817d0..0048190e (319B)
std::int16_t __fastcall track_segment_advance_004817d0(
    void* self, void*, I seg, I delta, I portal_hint) {
    const void* const region_vec = ptr_from32(load_u32(self, 0x18u));
    U r_idx = find_track_region_index(region_vec, seg);
    I cur = seg + delta;
    const I orig_delta = delta;

    for (;;) {
        const void* const entry = ptr_from32(load_u32(region_vec, 0u) + r_idx * 0x28u);
        const I min_seg = load_i32(entry, 0u);
        const I max_seg = load_i32(entry, 0x10u);
        if (min_seg <= cur && cur <= max_seg) {
            const I seg_count = load_i32(self, 0u);
            if (seg_count <= cur) {
                cur = seg_count - 1;
            }
            if (cur < 0) {
                cur = 0;
            }
            return static_cast<std::int16_t>(cur);
        }

        const I boundary = (max_seg < cur) ? max_seg : min_seg;
        const I portal_idx = load_i8(ptr_from32(load_u32(self, 0x14u)), static_cast<U>(boundary));
        if (portal_idx < 0) {
            return static_cast<std::int16_t>(boundary);
        }
        const void* const portal_vec = ptr_from32(load_u32(self, 0x1cu));
        const void* const portal =
            ptr_from32(load_u32(portal_vec, 0u) + static_cast<U>(portal_idx) * 0x38u);
        if (portal_hint < 0) {
            const U want_flag = (orig_delta <= 0) ? 1u : 0u;
            const I branch_count = load_i32(portal, 0x20u);
            for (I b = 0; b < branch_count; ++b) {
                const void* const br = ptr_from32(load_u32(portal, static_cast<U>(b) * 4u));
                if (load_u32(br, 0x0cu) == want_flag) {
                    portal_hint = b;
                }
            }
            if (portal_hint < 0) {
                return static_cast<std::int16_t>(seg);
            }
        }
        const void* const chosen =
            ptr_from32(load_u32(portal, static_cast<U>(portal_hint) * 4u));
        const I next_region = load_i32(chosen, 4u);
        cur = load_i32(chosen, 0u) + (cur - boundary) - 1;
        if (next_region < 0) {
            return static_cast<std::int16_t>(seg);
        }
        r_idx = static_cast<U>(next_region);
        portal_hint = -1;
    }
}

// 00473240..0047332e (239B)
void* __fastcall sector_find_surface_00473240(void* self, void*, const float* pos) {
    ++sector_query_count_006289ec;
    void* leaf = ptr_from32(load_u32(self, 0x2cu));
    if (leaf == nullptr ||
        quadtree_node_contains_xz_00484450(leaf, nullptr, pos) == 0u ||
        load_u32(leaf, 0x14u) == 0u) {
        leaf = quadtree_lookup_leaf_00484500(quadtree_root_from_frame_service(), nullptr, pos);
        store_u32(self, 0x2cu, addr32(leaf));
    } else {
        ++sector_cache_hits_006289f0;
    }

    if (leaf == nullptr) {
        return nullptr;
    }
    const void* const entries = ptr_from32(load_u32(leaf, 0x14u));
    if (entries == nullptr) {
        return nullptr;
    }

    const U begin = load_u32(entries, 0u);
    const U end = load_u32(entries, 4u);
    void* best = nullptr;
    float best_dy = 1e38f;
    for (U it = begin; it != end; it += 8u) {
        const void* const rec = ptr_from32(it);
        void* const surf = ptr_from32(load_u32(rec, 4u));
        if (surface_contains(surf, pos) != 0u && load_u8(rec, 0u) == 1u) {
            if ((load_u16(surf, 0x0au) & 0x000fu) != 0u) {
                float pt[3]{};
                surface_get_center(surf, pt);
                float dy = pt[1] - pos[1];
                if (dy <= 0.0f) {
                    dy = -dy;
                }
                if (dy < best_dy) {
                    best_dy = dy;
                    best = surf;
                }
            }
        }
    }
    return best;
}

// 00473420..00473648 (553B)
void* __fastcall sector_collect_surfaces_00473420(
    void* self, void*, const float* pos, float radius) {
    (void)self;
    B dummy = 0u;
    auto* const result = static_cast<DwordVector12*>(startup_network_allocate_0059ef90(0x0cu));
    if (result != nullptr) {
        context_empty_range_00505810(result, nullptr, addr32(&dummy));
    }
    DwordVector12 leaves{};
    context_empty_range_00505810(&leaves, nullptr, addr32(&dummy));
    quadtree_collect_leaves_00484630(
        quadtree_root_from_frame_service(), nullptr, pos, radius, &leaves);

    const U leaf_count =
        static_cast<U>(static_cast<I>(leaves.end - leaves.begin) >> 2);
    for (U i = 0u; i < leaf_count; ++i) {
        const void* const leaf = ptr_from32(load_u32(ptr_from32(leaves.begin), i * 4u));
        if (leaf == nullptr) {
            continue;
        }
        const void* const entries = ptr_from32(load_u32(leaf, 0x14u));
        const U e_begin = load_u32(entries, 0u);
        const U e_end = load_u32(entries, 4u);
        for (U it = e_begin; it != e_end; it += 8u) {
            const void* const rec = ptr_from32(it);
            void* const surf = ptr_from32(load_u32(rec, 4u));
            if (surface_contains(surf, pos) == 0u || load_u8(rec, 0u) != 1u) {
                continue;
            }
            const std::uint16_t flags = load_u16(surf, 0x0au);
            if ((flags & 0x8000u) == 0u || (flags & 0x000fu) != 0u) {
                continue;
            }
            if (result->end != result->capacity_end) {
                if (result->end != 0u) {
                    store_u32(ptr_from32(result->end), 0u, addr32(surf));
                }
                result->end += 4u;
            } else {
                const I old_count = static_cast<I>(result->end - result->begin) >> 2;
                const I new_cap = (old_count == 0) ? 1 : (old_count * 2);
                U* const new_buf = (new_cap != 0)
                    ? static_cast<U*>(application_context_member_storage_004211d0(
                          static_cast<U>(new_cap) * 4u, 0u))
                    : nullptr;
                const U* const old_begin = static_cast<const U*>(ptr_from32(result->begin));
                const U* const old_end = static_cast<const U*>(ptr_from32(result->end));
                U* const mid = copy_dword_range_0046db70(old_begin, old_end, new_buf);
                const U surf_val = addr32(surf);
                assign_dword_if_nonnull_0042bcb0(mid, &surf_val);
                U* const after = copy_dword_range_0046db70(old_end, old_end, mid + 1);
                const I old_cap = static_cast<I>(result->capacity_end - result->begin) >> 2;
                if (old_cap != 0) {
                    application_context_clear_004237d0(
                        ptr_from32(result->begin), static_cast<U>(old_cap) << 2u, 0u);
                }
                result->begin = addr32(new_buf);
                result->end = addr32(after);
                result->capacity_end = addr32(new_buf + new_cap);
            }
        }
    }

    release_dword_vector_storage(&leaves);
    return result;
}

// 00474060..004740cb (108B)
void __fastcall sector_track_step_00474060(
    void* self, void*, const float* pos, B reuse_cached) {
    void* const prev = ptr_from32(load_u32(self, 0x28u));
    if (prev != nullptr && surface_contains(prev, pos) != 0u && reuse_cached != 0u) {
        store_u8(self, 9u, (load_u32(self, 0x28u) != addr32(prev)) ? 1u : 0u);
        return;
    }
    void* const cur = sector_find_surface_00473240(self, nullptr, pos);
    store_u32(self, 0x28u, addr32(cur));
    store_u8(self, 2u, 0u);
    if (cur != nullptr) {
        store_u8(self, 10u, 0u);
        store_u16(self, 0x24u, load_u16(cur, 0x0au));
        store_u8(self, 9u, (cur != prev) ? 1u : 0u);
    } else {
        store_u8(self, 10u, 1u);
        store_u16(self, 0x24u, 0u);
        store_u8(self, 9u, (prev != nullptr) ? 1u : 0u);
    }
}

// 00461370..00461582 (531B)
B __cdecl view_slot_height_query_00461370(
    I slot_index, const float* origin, float* out_height) {
    B found = 0u;
    B* const slot = view_slot_table_00627e80 + static_cast<U>(slot_index) * 0x10cu;
    const void* const car = ptr_from32(load_u32(slot, 0u));
    const float car_y = load_f32(car, 0x334u);
    const float target_y = car_y + *out_height;

    const float query_pos[3] = {origin[0], car_y, origin[2]};
    auto* const surfaces = static_cast<DwordVector12*>(
        sector_collect_surfaces_00473420(slot + 0xdcu, nullptr, query_pos, 1.0f));

    for (U it = surfaces->begin; it != surfaces->end; it += 4u) {
        void* const surf = ptr_from32(load_u32(ptr_from32(it), 0u));
        bool all_above_false = true;
        if (0 < surface_vertex_count(surf)) {
            I j = 0;
            do {
                const float* const v = surface_get_vertex(surf, j);
                const float vy_minus1 = v[1] - 1.0f;
                if (!(vy_minus1 <= target_y && vy_minus1 <= origin[1])) {
                    all_above_false = false;
                }
                ++j;
            } while (j < surface_vertex_count(surf));
        }
        if (all_above_false) {
            continue;
        }

        float center[3]{};
        surface_get_center(surf, center);
        const void* const car_cur = ptr_from32(load_u32(slot, 0u));
        const float car_y_cur = load_f32(car_cur, 0x334u);
        if (car_y_cur - 2.0f <= center[1] && center[1] <= car_y_cur + 2.0f) {
            continue;
        }

        float normal[3]{};
        surface_get_normal(surf, normal);
        const float* const v0 = surface_get_vertex(surf, 0);
        const float plane_y = ray_plane_param_0048a060(normal, v0, origin);
        if (plane_y - 1.0f < target_y) {
            float adjusted = (plane_y - car_y) - 1.0f;
            if (adjusted <= 1.0f) {
                adjusted = 1.0f;
            }
            *out_height = adjusted;
            found = 1u;
        }
    }

    if (surfaces != nullptr) {
        release_dword_vector_storage(surfaces);
        (void)application_release_0059f050(surfaces);
    }
    return found;
}

// 004618b0..00461a29 (378B)
void __cdecl view_slot_camera_transform_004618b0(I slot_index) {
    B* const slot = view_slot_table_00627e80 + static_cast<U>(slot_index) * 0x10cu;
    const I mode = load_i16(slot, 0xbcu);
    const auto& preset = view_mode_camera_presets_005cf610[mode];
    float local_offset[3]{};
    std::memcpy(&local_offset[0], &preset.vec_x_bits, 4u);
    std::memcpy(&local_offset[1], &preset.vec_y_bits, 4u);
    std::memcpy(&local_offset[2], &preset.vec_z_bits, 4u);

    const B* const car0 = static_cast<const B*>(ptr_from32(load_u32(slot, 0u)));
    float world_offset[3]{};
    transform_vectors_00532a40(1, local_offset, car0 + 0x364u, world_offset);

    float h_car = world_offset[1];
    float h_cam = world_offset[1];
    const B* const car1 = static_cast<const B*>(ptr_from32(load_u32(slot, 0u)));
    (void)view_slot_height_query_00461370(
        slot_index, reinterpret_cast<const float*>(car1 + 0x330u), &h_car);
    (void)view_slot_height_query_00461370(
        slot_index, reinterpret_cast<const float*>(slot + 0x24u), &h_cam);
    if (h_cam < h_car) {
        world_offset[1] = h_cam;
    } else {
        world_offset[1] = h_car;
    }

    const void* const car2 = ptr_from32(load_u32(slot, 0u));
    store_f32(slot, 0x24u, world_offset[0] + load_f32(car2, 0x330u));
    const void* const car3 = ptr_from32(load_u32(slot, 0u));
    store_f32(slot, 0x28u, world_offset[1] + load_f32(car3, 0x334u));
    const void* const car4 = ptr_from32(load_u32(slot, 0u));
    store_f32(slot, 0x2cu, world_offset[2] + load_f32(car4, 0x338u));

    store_f32(slot, 0x08u, world_offset[0]);
    store_f32(slot, 0x0cu, world_offset[1]);
    store_f32(slot, 0x10u, world_offset[2]);

    const void* const car5 = ptr_from32(load_u32(slot, 0u));
    store_f32(slot, 0x7cu, -load_f32(car5, 0x364u));
    store_f32(slot, 0x80u, -load_f32(car5, 0x368u));
    store_f32(slot, 0x84u, -load_f32(car5, 0x36cu));
    store_u32(slot, 0x88u, load_u32(car5, 0x370u));
    store_u32(slot, 0x8cu, load_u32(car5, 0x374u));
    store_u32(slot, 0x90u, load_u32(car5, 0x378u));
    store_f32(slot, 0x94u, -load_f32(car5, 0x37cu));
    store_f32(slot, 0x98u, -load_f32(car5, 0x380u));
    store_f32(slot, 0x9cu, -load_f32(car5, 0x384u));
}

// 00463260..00463402 (419B)
void __cdecl view_route_select_00463260(I slot_index) {
    B* const slot = view_slot_table_00627e80 + static_cast<U>(slot_index) * 0x10cu;
    const I base_step = static_cast<I>((1.0f - load_f32(slot, 0xccu)) * 15.0f);
    const B* const car = static_cast<const B*>(ptr_from32(load_u32(slot, 0u)));
    const I car_seg = load_i16(car, 0x08u);
    const B* const road_base = static_cast<const B*>(ptr_from32(load_u32(track_road_data_00628bc0, 0x0cu)));
    float dot = vec3_dot_00532910(
        reinterpret_cast<const float*>(car + 0x37cu),
        reinterpret_cast<const float*>(road_base + car_seg * 0x50 + 0x1c));
    if (global_00657430 != 0u) {
        dot = -dot;
    }
    I dir = (dot < 0.0f) ? -1 : 1;
    if (load_f32(car, 0xd60u) < 0.0f) {
        dir = -dir;
    }

    if (fe_loop_word_00606850 != 0x14u) {
        I limit = base_step + 1;
        if (limit > 8) {
            limit = 8;
        }
        if (dir < 0) {
            limit = -limit;
        }
        I step = (limit > 0) ? 0 : limit;
        while ((limit > 0) ? (step < limit) : (step <= 0)) {
            if (track_portal_query_004816f0(
                    track_road_data_00628bc0, nullptr, load_i16(car, 0x08u), step) != nullptr) {
                limit = step;
                break;
            }
            ++step;
        }
        const std::int16_t target_seg = track_segment_advance_004817d0(
            track_road_data_00628bc0, nullptr, load_i16(car, 0x08u), limit - dir, -1);
        store_i16(slot, 0xdcu, target_seg);
        const B* const seg_rec =
            static_cast<const B*>(ptr_from32(load_u32(track_road_data_00628bc0, 0x0cu))) +
            target_seg * 0x50 + 4;
        store_u32(slot, 0x24u, load_u32(seg_rec, 0u));
        store_u32(slot, 0x28u, load_u32(seg_rec, 4u));
        store_u32(slot, 0x2cu, load_u32(seg_rec, 8u));
        const float y_off =
            (load_f32(slot, 0x30u) == 0.0f) ? 3.0f : load_f32(slot, 0x30u);
        store_f32(slot, 0x28u, y_off + load_f32(slot, 0x28u));
        store_u32(slot, 0x60u, 0u);
        store_u32(slot, 0x64u, 0u);
        store_u32(slot, 0x68u, 0u);
    }

    sector_track_step_00474060(
        slot + 0xdcu, nullptr, reinterpret_cast<const float*>(slot + 0x24u), 1u);
}

// 00465790..004659df (592B)
void __cdecl entry_fe_service_00465790(U first, U second) {
    frame_reset_word_006280f0 = 0u;
    frame_reset_word_006280ec = 0u;
    frame_reset_word_006280e8 = 0u;
    frame_reset_word_00628100 = 0u;
    frame_reset_word_006280fc = 0u;
    frame_reset_word_006280f8 = 0u;
    entry_fe_flag_word_006280e0 = 0u;
    entry_fe_flag_word_006280e4 = 0u;

    B* const slot = view_slot_table_00627e80 + first * 0x10cu;
    const std::int16_t prev_mode = load_i16(slot, 0xbcu);
    if (prev_mode < 2 || prev_mode > 7) {
        view_route_counter_00465cf0(static_cast<I>(first) + 1);
    }

    std::int16_t mode = static_cast<std::int16_t>(second & 0xffffu);
    store_i16(slot, 0xbcu, mode);
    if (mode >= 0x15) {
        const U state_off = (0x00658294u - application_state_base_va) + first * 0x580u;
        mode = load_i16(application_state_006573e8.words_.data(), state_off);
        store_i16(slot, 0xbcu, mode);
    }

    if (load_i16(slot, 0xbcu) == 11) {
        view_route_select_00463260(static_cast<I>(first));
    }

    store_u8(slot, 0xc1u, 0x32u);
    store_u32(slot, 0x3cu, 0u);
    store_u32(slot, 0x40u, 0x42160000u);
    store_u32(slot, 0x34u, 0u);
    store_u32(slot, 0x38u, 0x42160000u);
    store_u32(slot, 0x78u, 0x42160000u);
    store_u32(slot, 0x44u, 0x3f800000u);
    store_u32(slot, 0x48u, 0x3ca3d70au);
    store_u32(slot, 0x58u, 0x42160000u);
    store_u32(slot, 0x5cu, 0x3f000000u);
    store_u32(slot, 0x30u, 0x40400000u);
    store_u32(slot, 0x60u, 0u);
    store_u32(slot, 0x64u, 0u);
    store_u32(slot, 0x68u, 0u);
    store_u16(slot, 0xc6u, 0u);
    store_u16(slot, 0xc8u, 0u);

    const std::int16_t active_mode = load_i16(slot, 0xbcu);
    const U preset_flags = view_mode_camera_presets_005cf610[active_mode].flags;
    B flags_c0 = load_u8(slot, 0xc0u);
    flags_c0 = static_cast<B>((flags_c0 & 0x81u) | ((preset_flags & 0x3fu) << 1u));
    store_u8(slot, 0xc0u, flags_c0);

    const B flags_c3 = load_u8(slot, 0xc3u);
    const B low_mode_bit = (load_i16(slot, 0xbcu) <= 1) ? 1u : 0u;
    store_u8(slot, 0xc3u, static_cast<B>((flags_c3 & 0xf7u) | (low_mode_bit << 3u)));

    const std::int16_t final_mode = load_i16(slot, 0xbcu);
    if (final_mode < 2 || final_mode > 7) {
        const B* const net = static_cast<const B*>(startup_network_00628c70);
        if (net != nullptr && load_u32(net, 8u) != 0u && load_u8(net, 0xbfu) == 0u) {
            if (load_u8(net, 0xbdu) == 0u) {
                view_slot_camera_transform_004618b0(static_cast<I>(first));
            }
        } else if (static_cast<I>(global_005e99f4) < 2) {
            view_slot_camera_transform_004618b0(static_cast<I>(first));
        }
    }
}

} // namespace porsche
