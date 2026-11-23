// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00536870..00536947 (216B), 0053c8d0..0053c8d9 (10B),
// 0053c8e0..0053c90c (45B), and 0053d840..0053d895 (86B).
#include "render_calibrate_service_782.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

std::uint32_t render_calibration_initialized_0069de40 = 0u;
std::uint32_t render_calibration_cookie_0069de48 = 0u;
std::uint8_t render_calibration_flag_0069de4c = 0u;
void* render_service_font_0069eb90 = nullptr;
std::uint32_t render_service_initialized_0069eb94 = 0u;
std::int32_t render_service_capacity_0069eba0 = 0;
std::int32_t* render_service_indices_0069eba4 = nullptr;

namespace {

void store_u32(void* dst, std::uint32_t value) {
    std::memcpy(dst, &value, sizeof value);
}

void store_ptr(void* dst, const void* value) {
    const std::uint32_t raw = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(value));
    store_u32(dst, raw);
}

void* load_ptr(const void* src) {
    std::uint32_t raw = 0u;
    std::memcpy(&raw, src, sizeof raw);
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(raw));
}

} // namespace

void __cdecl render_service_set_ops_0053c8d0(void* ops_table) {
    render_service_ops_005dec08 = ops_table;
}

void __cdecl render_service_init_indices_0053d840(std::int32_t count) {
    if (render_service_indices_0069eba4 != nullptr) {
        return;
    }
    render_service_capacity_0069eba0 = count;
    if (count == 0) {
        count = 0x190;
        render_service_capacity_0069eba0 = 0x190;
    }
    using AllocFn = std::int32_t*(__cdecl*)(std::int32_t bytes);
    auto* const ops = static_cast<void* const*>(render_service_ops_005dec08);
    const auto alloc_fn = reinterpret_cast<AllocFn>(ops[5]);
    const std::int32_t bytes =
        static_cast<std::int32_t>(static_cast<std::uint32_t>(count) << 2u);
    render_service_indices_0069eba4 = alloc_fn(bytes);
    for (std::int32_t i = 0; i < render_service_capacity_0069eba0; ++i) {
        render_service_indices_0069eba4[i] = i;
    }
}

void __cdecl render_initialize_service_0053c8e0() {
    if (render_service_initialized_0069eb94 != 0u) {
        return;
    }
    render_service_init_indices_0053d840(0);
    render_service_font_0069eb90 =
        render_debug_font_create_0053c6c0(&render_debug_font_005dfd8c[0]);
    render_service_initialized_0069eb94 = 1u;
}

void __cdecl render_driver_calibrate_00536870() {
    if (render_calibration_initialized_0069de40 != 0u) {
        return;
    }
    render_service_set_ops_0053c8d0(&render_mouse_ops_table_005dfb60[0]);
    render_initialize_service_0053c8e0();
    render_calibration_initialized_0069de40 = 1u;

    void* const outer = load_ptr(game_setup_movie_service_0069ed0c);
    void* const inner = load_ptr(static_cast<const std::uint8_t*>(outer) + 0x18u);
    void* const vtable = load_ptr(inner);
    using ProbeFn = std::uint8_t(__fastcall*)(void* self, void* unused_edx);
    const auto probe_fn = reinterpret_cast<ProbeFn>(load_ptr(vtable));
    if (probe_fn(inner, nullptr) != 0u) {
        render_calibration_flag_0069de4c = 1u;
    }

    void* const raw = startup_network_allocate_0059ef90(0x2cu);
    if (raw != nullptr) {
        void* const font = render_service_font_0069eb90;
        auto* const obj_bytes = static_cast<std::uint8_t*>(raw);
        render_resource_node_state_ctor_005379d0(obj_bytes + 8u, nullptr);
        store_ptr(obj_bytes, &render_calibration_vtable_005bb708[0]);
        store_ptr(obj_bytes + 4u, font);

        std::uint32_t cookie = 0u;
        std::memcpy(
            &cookie,
            static_cast<const std::uint8_t*>(game_setup_movie_service_0069ed0c) + 4u,
            sizeof cookie);
        render_calibration_cookie_0069de48 = cookie;

        if (render_calibration_flag_0069de4c != 0u) {
            void* const stored_font = load_ptr(obj_bytes + 4u);
            font_setstatef_0053e890(stored_font, 0x14, -0.5f);
            font_setstatef_0053e890(stored_font, 0x15, -0.5f);
        }
        render_calibration_object_0069de44 = raw;
        render_font_prepare_00571a10(render_service_font_0069eb90);
    } else {
        render_calibration_object_0069de44 = nullptr;
        render_font_prepare_00571a10(render_service_font_0069eb90);
    }
}

} // namespace porsche
