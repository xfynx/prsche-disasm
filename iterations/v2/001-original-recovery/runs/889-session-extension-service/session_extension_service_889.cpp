// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run889: session_extension_service_00406520 (385B) and closed extension
// constructors/destructors (16 functions, 1,322B code).
#include "session_extension_service_889.hpp"

#include "frame_loop_clusters_400.hpp"
#include "player_service_tables_831.hpp"
#include "porsche/application_alloc.hpp"
#include "porsche/network_vtables.hpp"
#include "session_extension_pool_864.hpp"
#include "session_input_reset_853.hpp"
#include "session_reset_gate_856.hpp"

#include <cmath>
#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;
using HelperDeleteFn = void*(__fastcall*)(void*, void*, U);

U addr32(const void* p) {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(p));
}

template <typename Fn>
U fn32(Fn fn) {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(fn));
}

void* ptr32(U address) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(address));
}

U load_u32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

I load_i32(const void* base, U offset) {
    I value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

std::int16_t load_i16(const void* base, U offset) {
    std::int16_t value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

B load_u8(const void* base, U offset) {
    return static_cast<const B*>(base)[offset];
}

float load_f32(const void* base, U offset) {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store_u32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_i32(void* base, U offset, I value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_u16(void* base, U offset, std::uint16_t value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_u8(void* base, U offset, B value) {
    static_cast<B*>(base)[offset] = value;
}

void store_f32(void* base, U offset, float value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_ptr(void* base, U offset, const void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

void delete_subobject_at_08(void* self) {
    void* const sub = load_ptr(self, 0x08u);
    if (sub != nullptr) {
        const auto* const vtable = *static_cast<HelperDeleteFn* const*>(sub);
        vtable[1](sub, nullptr, 1u);
        store_u32(self, 0x08u, 0u);
    }
}

void delete_old_subobject_before_replace(void* self) {
    void* const old_sub = load_ptr(self, 0x08u);
    if (old_sub != nullptr) {
        const auto* const vtable = *static_cast<HelperDeleteFn* const*>(old_sub);
        vtable[1](old_sub, nullptr, 1u);
    }
}

const SessionExtensionModeItem_889 kModeItems0_005cb7d0[4] = {
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000000u, 0x41800000u, 0x3e99999au, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000001u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x42000000u, 0x3ecccccdu, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000002u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3e99999au, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000003u, 0x00000002u, 0x00000001u, 0x00000001u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3ecccccdu, 0x00000000u, 0x000000c0u, 0x00000000u}},
};

const SessionExtensionModeItem_889 kModeItems1_005cb8a0[5] = {
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x42000000u, 0x3f333333u, 0x00000100u, 0x000000c0u, 0x00000000u}},
    {{0x00000002u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3f333333u, 0x00000000u, 0x000000e0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000003u, 0x00000002u, 0x00000001u, 0x00000001u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3f333333u, 0x00000000u, 0x00000100u, 0x00000000u}},
};

const SessionExtensionModeItem_889 kModeItems2_005cb9a8[4] = {
    {{0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x41800000u, 0x3f000000u, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000002u, 0x00000002u, 0x42000000u, 0x3f000000u, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x42000000u, 0x3f000000u, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000001u, 0x00000001u, 0x00000002u, 0x00000002u, 0x42000000u, 0x3f000000u, 0x00000000u, 0x000000c0u, 0x00000000u}},
};

const SessionExtensionModeItem_889 kModeItems3_005cba78[4] = {
    {{0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000002u, 0x00000002u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x42000000u, 0x3f333333u, 0x00000100u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000001u, 0x00000000u, 0x00000001u, 0x00000001u, 0x00000002u, 0x00000002u, 0x42000000u, 0x3f333333u, 0x00000000u, 0x00000100u, 0x00000000u}},
};

const SessionExtensionModeItem_889 kModeItems4_005cbb48[4] = {
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x41800000u, 0x3e99999au, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x42000000u, 0x3e99999au, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3e99999au, 0x00000000u, 0x000000c0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000001u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3e99999au, 0x00000000u, 0x000000c0u, 0x00000000u}},
};

const SessionExtensionModeItem_889 kModeItems5_005cbc18[5] = {
    {{0x00000001u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x00000080u, 0x00000002u}},
    {{0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x41800000u, 0x3f333333u, 0x00000200u, 0x000000c0u, 0x00000000u}},
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x42000000u, 0x3f333333u, 0x00000100u, 0x000000c0u, 0x00000000u}},
    {{0x00000002u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3f333333u, 0x00000000u, 0x000000e0u, 0x00000000u}},
    {{0x00000000u, 0x00000000u, 0x00000002u, 0x00000002u, 0x00000000u, 0x00000001u, 0x00000001u, 0x00000001u, 0x42000000u, 0x3f333333u, 0x00000000u, 0x00000100u, 0x00000000u}},
};

} // namespace

const SessionExtensionModeEntry_889 session_extension_mode_table_005cbd20[6] = {
    {4u, kModeItems0_005cb7d0},
    {5u, kModeItems1_005cb8a0},
    {4u, kModeItems2_005cb9a8},
    {4u, kModeItems3_005cba78},
    {4u, kModeItems4_005cbb48},
    {5u, kModeItems5_005cbc18},
};

std::uint32_t session_extension_any_mode20_005e67a0 = 0u;
std::int32_t session_extension_tick_rate_005e7540 = 0;

const std::uint32_t session_extension_vtable_005b25b0[2] = {
    fn32(&network_purecall_005a1056),
    fn32(&session_extension_base_dtor_00406800),
};

const std::uint32_t session_extension_vtable_005b25a0[3] = {
    fn32(&render_registry_item_noop_00514990),
    fn32(&session_extension_helper_dtor_004066b0),
    fn32(&session_extension_helper_slot2_00403d80),
};

const std::uint32_t session_extension_vtable_005b2594[2] = {
    fn32(&render_registry_item_noop_00514990),
    fn32(&session_extension_base_dtor_00406800),
};

const std::uint32_t session_extension_vtable_005b2500[3] = {
    fn32(&network_purecall_005a1056),
    fn32(&session_extension_helper_dtor_004066b0),
    fn32(&session_extension_helper_slot2_00403d80),
};

const std::uint32_t session_extension_vtable_005b2544[3] = {
    fn32(&session_extension_a_tick_00405690),
    fn32(&session_extension_ab_dtor_00405950),
    fn32(&session_extension_ab_reset_00403990),
};

const std::uint32_t session_extension_vtable_005b2560[3] = {
    fn32(&session_extension_b_tick_004058a0),
    fn32(&session_extension_ab_dtor_00405950),
    fn32(&session_extension_ab_reset_00403990),
};

const std::uint32_t session_extension_vtable_005b2588[2] = {
    fn32(&session_extension_c_tick_00406020),
    fn32(&session_extension_cd_dtor_004064c0),
};

const std::uint32_t session_extension_vtable_005b2510[2] = {
    fn32(&session_extension_d_tick_00403e40),
    fn32(&session_extension_cd_dtor_004064c0),
};

const std::uint32_t session_extension_vtable_005b2570[3] = {
    fn32(&network_purecall_005a1056),
    fn32(&session_extension_ab_dtor_00405950),
    fn32(&session_extension_ab_reset_00403990),
};

const std::uint32_t session_extension_vtable_005b24d0[3] = {
    fn32(&network_purecall_005a1056),
    fn32(&session_extension_ab_dtor_00405950),
    fn32(&session_extension_ab_reset_00403990),
};

const std::uint32_t session_extension_vtable_005b24b0[2] = {
    fn32(&network_purecall_005a1056),
    fn32(&session_extension_cd_dtor_004064c0),
};

// 00406520..004066a0 (385B).
void __cdecl session_extension_service_00406520() {
    session_extension_clear_0040b490();
    I mode20_count = 0;
    for (I index = 0; index < application_active_player_count_005e8b58; ++index) {
        void* const player = ptr32(application_player_object_table_005e8b34[index]);
        const U flags = load_u32(player, 0x52cu);
        if ((flags & 0x04u) != 0u) {
            void* const obj = startup_network_allocate_0059ef90(0xb0u);
            session_player_extension_slots_005e6774[index] =
                (obj != nullptr) ? session_extension_a_ctor_004056b0(obj, nullptr, player) : nullptr;
        } else if ((flags & 0x08u) != 0u) {
            void* const obj = startup_network_allocate_0059ef90(0xc0u);
            session_player_extension_slots_005e6774[index] =
                (obj != nullptr) ? session_extension_b_ctor_00405910(obj, nullptr, player) : nullptr;
        } else if ((flags & 0x10u) != 0u) {
            void* const obj = startup_network_allocate_0059ef90(0x24u);
            session_player_extension_slots_005e6774[index] =
                (obj != nullptr) ? session_extension_c_ctor_00406490(obj, nullptr, player) : nullptr;
        } else if ((flags & 0x20u) != 0u) {
            void* const obj = startup_network_allocate_0059ef90(0x6cu);
            if (obj != nullptr) {
                const U mode20_index = static_cast<U>(mode20_count++);
                session_player_extension_slots_005e6774[index] =
                    session_extension_d_ctor_00403e00(obj, nullptr, player, mode20_index);
            } else {
                session_player_extension_slots_005e6774[index] = nullptr;
            }
        } else {
            void* const obj = startup_network_allocate_0059ef90(0x18u);
            if (obj != nullptr) {
                store_u32(obj, 0x00u, addr32(session_extension_vtable_005b25b0));
                store_ptr(obj, 0x04u, player);
                store_u32(obj, 0x08u, 0u);
                store_u32(obj, 0x0cu, 0u);
                void* const helper = session_extension_allocate_0040b530(8u);
                if (helper != nullptr) {
                    session_extension_helper_ctor_0040b510(helper, nullptr, load_ptr(obj, 0x04u));
                    store_u32(helper, 0x00u, addr32(session_extension_vtable_005b25a0));
                }
                delete_old_subobject_before_replace(obj);
                void* const obj_player = load_ptr(obj, 0x04u);
                store_ptr(obj, 0x08u, helper);
                store_u32(obj, 0x0cu, 0u);
                store_u32(obj, 0x10u, 0u);
                store_i32(obj, 0x14u, static_cast<I>(load_i16(obj_player, 0x08u)));
                store_u32(obj, 0x00u, addr32(session_extension_vtable_005b2594));
            }
            session_player_extension_slots_005e6774[index] = obj;
        }
    }
    session_extension_any_mode20_005e67a0 = (mode20_count > 0) ? 1u : 0u;
}

// 004056b0..004056c8 (25B).
void* __fastcall session_extension_a_ctor_004056b0(
    void* self, void* /*unused_edx*/, void* player) {
    session_extension_ab_base_ctor_00405c30(self, nullptr, player);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2544));
    return self;
}

// 00405910..00405949 (58B).
void* __fastcall session_extension_b_ctor_00405910(
    void* self, void* /*unused_edx*/, void* player) {
    session_extension_ab_base_ctor_00405c30(self, nullptr, player);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2560));
    store_u32(self, 0xb0u, 0u);
    store_u32(self, 0xb4u, 0u);
    store_u32(self, 0xb8u, 0u);
    store_u32(self, 0xbcu, 0u);
    store_u32(self, 0x10u, 1u);
    return self;
}

// 00406490..004064b0 (33B).
void* __fastcall session_extension_c_ctor_00406490(
    void* self, void* /*unused_edx*/, void* player) {
    session_extension_base_ctor_00406790(self, nullptr, player);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2588));
    store_u32(self, 0x18u, 0u);
    store_u32(self, 0x1cu, 0u);
    return self;
}

// 00403e00..00403e34 (53B).
void* __fastcall session_extension_d_ctor_00403e00(
    void* self, void* /*unused_edx*/, void* player, U mode20_index) {
    session_extension_d_base_ctor_00403800(self, nullptr, player, mode20_index);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2510));
    store_u32(self, 0x58u, 0u);
    store_u32(self, 0x60u, 0u);
    store_u32(self, 0x5cu, 0u);
    store_u32(self, 0x68u, 0u);
    store_u32(self, 0x64u, 0xffffffffu);
    return self;
}

// 00405c30..00405d6b (316B).
void* __fastcall session_extension_ab_base_ctor_00405c30(
    void* self, void* /*unused_edx*/, void* player) {
    session_extension_ab_core_ctor_00403cb0(self, nullptr, player);
    store_ptr(self, 0x90u, &session_extension_mode_table_005cbd20[0]);
    store_u32(self, 0x8cu, 0u);
    store_u32(self, 0x94u, 0u);
    store_u32(self, 0x98u, 0u);
    store_ptr(self, 0x9cu, session_extension_mode_table_005cbd20[0].items);
    store_u32(self, 0xa4u, 0u);
    store_u32(self, 0xacu, 0u);
    store_u32(self, 0xa0u, 0u);
    store_u32(self, 0xa8u, 0u);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2570));
    store_u32(self, 0x7cu, 0u);
    store_u32(self, 0x80u, 0u);

    if (global_00657414 != 0u) {
        const void* const cur_item = load_ptr(self, 0x9cu);
        const float rate_scale = load_f32(session_reset_object_005e752c, 0x04u);
        store_f32(self, 0x84u, rate_scale * load_f32(cur_item, 0x20u));
        store_i32(self, 0x88u, static_cast<I>(load_i16(load_ptr(self, 0x04u), 0x08u)));
        if (load_i32(self, 0x98u) < 0) {
            store_u32(self, 0x98u, 0u);
        }
        store_u32(self, 0x94u, 0u);

        const auto* const table_entry =
            static_cast<const SessionExtensionModeEntry_889*>(load_ptr(self, 0x90u));
        const SessionExtensionModeItem_889* const item = table_entry->items;
        store_ptr(self, 0x9cu, item);

        // Preserve x87 FILD + FMUL + float32 store + FISTP + FDIVR scaling.
        const float prod = static_cast<float>(
            static_cast<double>(session_extension_tick_rate_005e7540) *
            static_cast<double>(load_f32(item, 0x24u)));
        const I rounded = static_cast<I>(std::lrintf(prod));
        const I scaled = rounded << 5;
        store_f32(self, 0x8cu, static_cast<float>(scaled));

        const double inv = 1.0 / static_cast<double>(scaled);
        store_f32(self, 0xa8u, static_cast<float>(inv));
        if (global_006573f0 == 2u) {
            store_f32(self, 0xa8u, static_cast<float>(inv * static_cast<double>(1.2f)));
        } else if (global_006573f0 == 4u) {
            store_f32(self, 0xa8u, static_cast<float>(inv * static_cast<double>(0.66f)));
        }
        store_u32(self, 0xa4u, 0u);
    }
    return self;
}

// 00403cb0..00403cfb (76B).
void* __fastcall session_extension_ab_core_ctor_00403cb0(
    void* self, void* /*unused_edx*/, void* player) {
    session_extension_base_ctor_00406790(self, nullptr, player);
    store_u32(self, 0x70u, 0u);
    store_u32(self, 0x74u, 0u);
    store_u32(self, 0x78u, 0u);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b24d0));
    for (U pair = 0u; pair < 6u; ++pair) {
        store_u32(self, 0x1cu + pair * 8u, 0xffffffffu);
        store_u32(self, 0x20u + pair * 8u, 0xffffffffu);
    }
    store_u32(self, 0x18u, 0u);
    store_u32(self, 0x64u, 0u);
    store_u32(self, 0x6cu, 0u);
    store_u32(self, 0x68u, 0xfffffd80u);
    return self;
}

// 00403800..0040384e (79B).
void* __fastcall session_extension_d_base_ctor_00403800(
    void* self, void* /*unused_edx*/, void* player, U mode20_index) {
    session_extension_base_ctor_00406790(self, nullptr, player);
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b24b0));
    store_u32(self, 0x1cu, mode20_index);
    store_u32(self, 0x18u, ((load_u8(player, 0x52cu) & 0x40u) != 0u) ? 1u : 0u);
    store_u32(self, 0x20u, 0u);
    store_u32(self, 0x24u, 0u);
    store_u16(self, 0x50u, 0u);
    store_u32(self, 0x54u, 0u);
    store_u32(self, 0x30u, 0xffffffffu);
    return self;
}

// 00406790..004067f7 (104B).
void* __fastcall session_extension_base_ctor_00406790(
    void* self, void* /*unused_edx*/, void* player) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b25b0));
    store_ptr(self, 0x04u, player);
    store_u32(self, 0x08u, 0u);
    store_u32(self, 0x0cu, 0u);
    void* const helper = session_extension_allocate_0040b530(8u);
    if (helper != nullptr) {
        session_extension_helper_ctor_0040b510(helper, nullptr, load_ptr(self, 0x04u));
        store_u32(helper, 0x00u, addr32(session_extension_vtable_005b25a0));
    }
    delete_old_subobject_before_replace(self);
    void* const owner_player = load_ptr(self, 0x04u);
    store_ptr(self, 0x08u, helper);
    store_u32(self, 0x0cu, 0u);
    store_u32(self, 0x10u, 0u);
    store_i32(self, 0x14u, static_cast<I>(load_i16(owner_player, 0x08u)));
    return self;
}

// 0040b510..0040b521 (18B).
void* __fastcall session_extension_helper_ctor_0040b510(
    void* self, void* /*unused_edx*/, void* player) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2500));
    store_ptr(self, 0x04u, player);
    return self;
}

// 00406800..00406833 (52B).
void* __fastcall session_extension_base_dtor_00406800(
    void* self, void* /*unused_edx*/, U flags) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b25b0));
    delete_subobject_at_08(self);
    if ((flags & 1u) != 0u) {
        application_release_0059f050(self);
    }
    return self;
}

// 00406840..0040685f (32B).
void __fastcall session_extension_base_fini_00406840(
    void* self, void* /*unused_edx*/) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b25b0));
    delete_subobject_at_08(self);
}

// 004066b0..004066cf (32B).
void* __fastcall session_extension_helper_dtor_004066b0(
    void* self, void* /*unused_edx*/, U flags) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b2500));
    if ((flags & 1u) != 0u) {
        session_extension_release_0040b570(self);
    }
    return self;
}

// 004064c0..004064dd (30B).
void* __fastcall session_extension_cd_dtor_004064c0(
    void* self, void* /*unused_edx*/, U flags) {
    session_extension_base_fini_00406840(self, nullptr);
    if ((flags & 1u) != 0u) {
        application_release_0059f050(self);
    }
    return self;
}

// 00405950..00405973 (36B).
void* __fastcall session_extension_ab_dtor_00405950(
    void* self, void* /*unused_edx*/, U flags) {
    store_u32(self, 0x00u, addr32(session_extension_vtable_005b24d0));
    session_extension_base_fini_00406840(self, nullptr);
    if ((flags & 1u) != 0u) {
        application_release_0059f050(self);
    }
    return self;
}

// 00403d80..00403d82 (3B).
U __fastcall session_extension_helper_slot2_00403d80(
    void* /*self*/, void* /*unused_edx*/) {
    return 0u;
}

} // namespace porsche
