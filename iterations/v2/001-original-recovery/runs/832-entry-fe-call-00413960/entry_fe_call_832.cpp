// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run832: 00413960 cluster (14 functions, 710B code, 0B data/bss).
#include "entry_fe_call_832.hpp"

#include "entry_fe_scene_leaves_702.hpp"
#include "porsche/application_state.hpp"

#include <cstddef>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

constexpr std::size_t slot_off(U va) {
    return static_cast<std::size_t>(va - 0x00627e80u);
}

U load32(const void* base, U off) {
    U v = 0u;
    std::memcpy(&v, static_cast<const B*>(base) + off, sizeof(v));
    return v;
}

float load_f32(const void* base, U off) {
    float v = 0.0f;
    std::memcpy(&v, static_cast<const B*>(base) + off, sizeof(v));
    return v;
}

std::uint16_t slot_u16(U va) {
    std::uint16_t v = 0u;
    std::memcpy(&v, view_slot_table_00627e80 + slot_off(va), sizeof(v));
    return v;
}

U slot_u32(U va) {
    return load32(view_slot_table_00627e80, static_cast<U>(slot_off(va)));
}

float slot_f32(U va) {
    return load_f32(view_slot_table_00627e80, static_cast<U>(slot_off(va)));
}

B& slot_u8(U va) {
    return view_slot_table_00627e80[slot_off(va)];
}

void put_slot_u32(U va, U v) {
    std::memcpy(view_slot_table_00627e80 + slot_off(va), &v, sizeof(v));
}

void put_slot_f32(U va, float v) {
    std::memcpy(view_slot_table_00627e80 + slot_off(va), &v, sizeof(v));
}

using CamVec3SlotFn = void* (__fastcall*)(void* self, void* unused_edx, void* out_vec3);
using CamMat9SlotFn = void* (__fastcall*)(void* self, void* unused_edx, void* out_mat9);

void* cam_vtable_slot(const void* cam, U byte_offset) {
    void* vtable = nullptr;
    std::memcpy(&vtable, cam, sizeof(vtable));
    void* fn = nullptr;
    std::memcpy(&fn, static_cast<const B*>(vtable) + byte_offset, sizeof(fn));
    return fn;
}

} // namespace

// 00469a80..00469a86 (7B, __thiscall, ret 0).
U __fastcall camera_elem_u32_80_00469a80(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x80u);
}

// 00469a90..00469a96 (7B, __thiscall, ret 0).
float __fastcall camera_elem_f32_84_00469a90(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load_f32(self, 0x84u);
}

// 00469aa0..00469aa6 (7B, __thiscall, ret 0).
U __fastcall camera_elem_u32_88_00469aa0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x88u);
}

// 00469ab0..00469ab6 (7B, __thiscall, ret 0).
U __fastcall camera_elem_u32_8c_00469ab0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x8cu);
}

// 00469ac0..00469ac3 (4B, __thiscall, ret 0).
U __fastcall camera_elem_u32_78_00469ac0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x78u);
}

// 00469ad0..00469ad6 (7B, __thiscall, ret 0).
U __fastcall camera_elem_u32_90_00469ad0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x90u);
}

// 00469ae0..00469ae6 (7B, __thiscall, ret 0).
float __fastcall camera_elem_f32_94_00469ae0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load_f32(self, 0x94u);
}

// 00469af0..00469af6 (7B, __thiscall, ret 0).
U __fastcall camera_elem_u32_98_00469af0(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x98u);
}

// 00469b00..00469b06 (7B, __thiscall, ret 0).
float __fastcall camera_elem_f32_9c_00469b00(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load_f32(self, 0x9cu);
}

// 00469b10..00469b16 (7B, __thiscall, ret 0).
float __fastcall camera_elem_f32_a0_00469b10(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load_f32(self, 0xa0u);
}

// 00469b20..00469b3e (33B, __thiscall, ret 4).
void* __fastcall camera_elem_vec3_b4_00469b20(
    void* self, void* unused_edx, void* out_vec3) {
    (void)unused_edx;
    std::memcpy(out_vec3, static_cast<const B*>(self) + 0xb4u, 12u);
    return out_vec3;
}

// 0046af50..0046af53 (4B, __thiscall, ret 0).
U __fastcall camera_elem_u32_7c_0046af50(const void* self, void* unused_edx) {
    (void)unused_edx;
    return load32(self, 0x7cu);
}

// 0046d980..0046d9a6 (39B, __cdecl, ret 0).
void* __cdecl scene_camera_elem_at_0046d980(U index) {
    const auto signed_idx = static_cast<I>(static_cast<std::int16_t>(index & 0xffffu));
    const U* vec_base = reinterpret_cast<const U*>(
        static_cast<std::uintptr_t>(scene_elem_vector_00628168[0]));
    const U element = vec_base[signed_idx];
    const U casted = formatter_compare_005a134b(
        element, 0u, rtti_scene_elem_005cf908, rtti_camera_elem_005cf928, 0u);
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(casted));
}

// 00413960..00413b77 (536B, __cdecl, ret 0).
void __cdecl entry_fe_call_00413960(U value) {
    void* cam = scene_camera_elem_at_0046d980(value);
    if (cam == nullptr) {
        return;
    }

    if (application_state_006573e8.word(0x006573e8u) == 3u &&
        application_state_006573e8.word(0x00657408u) != 0u &&
        camera_elem_u32_78_00469ac0(cam, nullptr) == 0x0bu) {
        if (slot_u16(0x00627f3cu) == 0x0au) {
            return;
        }
        entry_fe_service_00465790(0u, 0x0au);
        slot_u8(0x00627f40u) = static_cast<B>(slot_u8(0x00627f40u) | 0x08u);
        return;
    }

    U local_30[3]{};
    U local_mat[9]{};

    if (camera_elem_u32_7c_0046af50(cam, nullptr) == 0u) {
        put_slot_u32(0x00627ec4u, 0u);
        if (camera_elem_u32_8c_00469ab0(cam, nullptr) != 0u) {
            auto fn38 = reinterpret_cast<CamVec3SlotFn>(cam_vtable_slot(cam, 0x38u));
            const void* v = fn38(cam, nullptr, local_30);
            put_slot_u32(0x00627eecu, load32(v, 0u));
            put_slot_u32(0x00627ef0u, load32(v, 4u));
            put_slot_u32(0x00627ef4u, load32(v, 8u));
        }
        const U f9 = camera_elem_u32_98_00469af0(cam, nullptr);
        put_slot_u32(0x00627eb4u, f9);
        if (f9 != 0u) {
            put_slot_f32(0x00627ef8u, camera_elem_f32_9c_00469b00(cam, nullptr));
        }
        if (camera_elem_u32_88_00469aa0(cam, nullptr) == 0u) {
            slot_u8(0x00627f40u) = static_cast<B>(slot_u8(0x00627f40u) & 0xf7u);
        }
    } else {
        entry_fe_service_00465790(0u, camera_elem_u32_78_00469ac0(cam, nullptr));
        if (camera_elem_u32_8c_00469ab0(cam, nullptr) != 0u) {
            auto fn38 = reinterpret_cast<CamVec3SlotFn>(cam_vtable_slot(cam, 0x38u));
            const void* v = fn38(cam, nullptr, local_30);
            const U x = load32(v, 0u);
            const U y = load32(v, 4u);
            const U z = load32(v, 8u);
            put_slot_u32(0x00627ea4u, x);
            put_slot_u32(0x00627ea8u, y);
            put_slot_u32(0x00627eecu, x);
            put_slot_u32(0x00627eacu, z);
            put_slot_u32(0x00627ef0u, y);
            put_slot_u32(0x00627ef4u, z);
        }
        const U f9 = camera_elem_u32_98_00469af0(cam, nullptr);
        put_slot_u32(0x00627eb4u, f9);
        if (f9 != 0u) {
            const float val = camera_elem_f32_9c_00469b00(cam, nullptr);
            put_slot_f32(0x00627eb8u, val);
            put_slot_f32(0x00627ef8u, val);
        }
        if (camera_elem_u32_88_00469aa0(cam, nullptr) == 0u) {
            auto fn40 = reinterpret_cast<CamMat9SlotFn>(cam_vtable_slot(cam, 0x40u));
            const void* m = fn40(cam, nullptr, local_mat);
            std::memcpy(view_slot_table_00627e80 + slot_off(0x00627efcu), m, 9u * sizeof(U));
            slot_u8(0x00627f40u) = static_cast<B>(slot_u8(0x00627f40u) & 0xf7u);
        }
    }

    const U f_ad = camera_elem_u32_90_00469ad0(cam, nullptr);
    put_slot_u32(0x00627ebcu, f_ad);
    if (f_ad != 0u) {
        put_slot_f32(0x00627ec0u, camera_elem_f32_94_00469ae0(cam, nullptr));
    }

    const float f_a9 = camera_elem_f32_84_00469a90(cam, nullptr);
    put_slot_f32(0x00627eb0u, f_a9);
    if (slot_u16(0x00627f3cu) == 0x0bu) {
        if (camera_elem_u32_80_00469a80(cam, nullptr) != 0u) {
            put_slot_f32(0x00627ea8u, slot_f32(0x00627ea8u) + slot_f32(0x00627eb0u));
        }
        put_slot_f32(0x00627f4cu, camera_elem_f32_a0_00469b10(cam, nullptr));
        const void* v = camera_elem_vec3_b4_00469b20(cam, nullptr, local_30);
        put_slot_u32(0x00627ee0u, load32(v, 0u));
        put_slot_u32(0x00627ee4u, load32(v, 4u));
        put_slot_u32(0x00627ee8u, load32(v, 8u));
    }
}

} // namespace porsche
