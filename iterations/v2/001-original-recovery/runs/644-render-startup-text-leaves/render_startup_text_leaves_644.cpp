// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0053c640..0053c67e (63B), sha256 1fe0282d153ec649985395c4268d00a03d7ebe04dabe7b74e2bb9590c6fb8e44.
// Original 00556370..005563ac (61B), sha256 c12c9c9d5915787318e64cf669a9a5b456953b75f535ac11a77f08ad6fb4e98d.
// Original 005563b0..005563c7 (24B), sha256 47751c5602ae077354ba167ccdadd22adc369c89e36e1eff2f3b3118dc4e7301.
// Original 00554930..00554942 (19B), sha256 f0371c0f73abddc0371be14aa211249c37993dcaeebf13c0bed76aada43ee513.
// Original 00555640..0055569e (95B), sha256 02dadddf4d21375ee725664664ec7593c9ecccb5abb039d48c5fe2f05941ab8b.
#include "render_startup_text_leaves_644.hpp"

#include <cstring>

#include "format_preferences_579.hpp"
#include "porsche/heap.hpp"
#include "render_resource_allocation_546.hpp"
#include "render_resource_descriptor_537.hpp"
#include "splash_sprite_horizflip_611.hpp"
#include "texture_children_577.hpp"

namespace porsche {

namespace {

inline std::uint32_t read_u32(const std::uint8_t* ptr) noexcept {
    std::uint32_t value = 0u;
    std::memcpy(&value, ptr, sizeof value);
    return value;
}

} // namespace

void* __cdecl shape_find_entry_0053c640(const void* shape, const void* tag) {
    const std::uint32_t key = render_buffer_read_word_0056e2a8(tag, 4);
    const auto* const base = static_cast<const std::uint8_t*>(shape);
    std::uint32_t count = read_u32(base + 8u);
    while (count > 0u) {
        --count;
        const std::uint32_t entry_off = 0x10u + count * 8u;
        if (read_u32(base + entry_off) == key) {
            const std::uint32_t data_off = read_u32(base + entry_off + 4u);
            return const_cast<std::uint8_t*>(base + data_off);
        }
    }
    return nullptr;
}

void __cdecl render_memmove_00556370(void* dst, const void* src, std::uint32_t size) {
    const std::uint32_t dst_addr = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(dst));
    const std::uint32_t src_addr = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(src));
    const std::uint32_t src_end = src_addr + size;
    if (dst_addr > src_addr && dst_addr < src_end) {
        auto* d = static_cast<std::uint8_t*>(dst) + size;
        const auto* s = static_cast<const std::uint8_t*>(src) + size;
        for (std::uint32_t remaining = size; remaining != 0u; --remaining) {
            *--d = *--s;
        }
        return;
    }
    heap_copy_dispatch_005323e0(dst, src, size);
}

void __cdecl render_copy_bytes_005563b0(const void* src, void* dst, std::uint32_t size) {
    render_memmove_00556370(dst, src, size);
}

void __cdecl render_texture_format_16bit_mode_00554930(std::int32_t mode_flag) {
    render_texture_format_preferences_005dedcc[10] = (mode_flag != 0) ? 2u : 4u;
}

void __cdecl render_texture_slot_bind_00555640(
    std::int32_t stage_index,
    std::uint32_t value,
    std::uint32_t width,
    std::uint32_t height,
    std::uint32_t format_a,
    std::uint32_t format_b,
    std::uint32_t flags) {
    if (width == 0u || width != height || (width & (width - 1u)) != 0u) {
        return;
    }
    if (stage_index >= 3 || stage_index < 0) {
        return;
    }
    (void)render_texture_select_00554820(&format_a, &format_b);
    const std::uint32_t slot = render_texture_slot_00554bd0(width, format_a, format_b, flags);
    const std::uint32_t offset = slot * 48u + 0x18u + static_cast<std::uint32_t>(stage_index) * 4u;
    std::memcpy(render_texture_slots_006a33f8 + offset, &value, sizeof value);
}

} // namespace porsche
