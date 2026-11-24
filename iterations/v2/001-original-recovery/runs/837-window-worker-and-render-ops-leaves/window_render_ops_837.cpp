// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#include "window_render_ops_837.hpp"

#include "porsche/fe_stream.hpp"
#include "porsche/window_scheduler.hpp"
#include "porsche/window_shutdown.hpp"
#include "porsche/window_worker.hpp"

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 pointer ABI");

std::uint32_t render_alloc_flags_005deb60 = 0u;
std::uint32_t render_service_palette_0069eb98 = 0u;

namespace {

std::uint32_t fn_addr(const void* fn) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(fn));
}

} // namespace

// 005dec18..005dec47 (12 dwords); unrecovered surface callbacks remain 0 until recovered.
std::uint32_t render_service_default_ops_005dec18[12] = {
    0u, // 0053cb10
    0u, // 0053cb40
    0u, // 0053ce90
    fn_addr(reinterpret_cast<const void*>(&render_service_set_flag_0053cec0)),
    0u, // 0053ced0
    fn_addr(reinterpret_cast<const void*>(&render_service_alloc_0053d360)),
    fn_addr(reinterpret_cast<const void*>(&render_service_free_0053d380)),
    0u,
    0u,
    0u,
    0u,
    0u,
};

void* render_service_ops_005dec08 = &render_service_default_ops_005dec18[0];

// 005dfb60..005dfb8f (12 dwords); unrecovered surface callbacks remain 0 until recovered.
std::uint32_t render_mouse_ops_table_005dfb60[12] = {
    0u, // 00571b90
    0u, // 00571d10
    0u, // 00572230
    0u, // 00572290
    0u, // 005722c0
    fn_addr(reinterpret_cast<const void*>(&render_mouse_alloc_00572610)),
    fn_addr(reinterpret_cast<const void*>(&render_mouse_free_00572630)),
    0xffffffffu,
    0u,
    0u,
    0u,
    0u,
};

std::uint32_t __cdecl render_service_set_flag_0053cec0(std::uint32_t value) {
    render_service_palette_0069eb98 = value;
    return 1u;
}

void* __cdecl render_service_alloc_0053d360(std::int32_t size) {
    return allocate_00531ca0("SOFTFONT", size, render_alloc_flags_005deb60);
}

void __cdecl render_service_free_0053d380(void* ptr) {
    (void)free_00531f90(ptr);
}

void* __cdecl render_mouse_alloc_00572610(std::int32_t size) {
    return allocate_00531ca0("FONT_dtexfalloc", size, render_alloc_flags_005deb60);
}

void __cdecl render_mouse_free_00572630(void* ptr) {
    (void)free_00531f90(ptr);
}

void __cdecl window_worker_callback() {
    if (worker_callback_0069e5a4 != 0u) {
        reinterpret_cast<void(__cdecl*)()>(
            static_cast<std::uintptr_t>(worker_callback_0069e5a4))();
    }
}

std::uint32_t __cdecl window_worker_idle_callback(
    std::uint32_t period, std::uint32_t delay, std::uint32_t callback) {
    const TimedCallback target = (callback == 0x0053bae0u)
        ? &window_shutdown_callback_0053bae0
        : reinterpret_cast<TimedCallback>(static_cast<std::uintptr_t>(callback));
    return window_scheduler_register_005365e0(target, period, delay);
}

} // namespace porsche
