// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run786: 00452120..004521b9 (154B), 0045dd80..0045dd85 (6B), 0045cfb0..0045cfb5 (6B),
//         00460b10..00460b4a (59B), 00460b50..00460c51 (258B),
//         0053c680..0053c6be (63B), 00460c80..00460cc4 (69B).
#include "scene_flare_resolve_786.hpp"

#include "porsche/render_startup.hpp"
#include "splash_sprite_horizflip_611.hpp"
#include "startup_context_table_helpers_646.hpp"
#include "startup_sequence_resource_table_649.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using B = std::uint8_t;

constexpr U kNullTag = 0x6e756c6cu; // "null"
constexpr U kSkyMagic = 0x534b5920u; // "SKY "
constexpr U kSkySlotCount = 40u;

U load32(const void* base, U offset) {
    U value = 0u;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

void* load_ptr(const void* base, U offset) {
    void* ptr = nullptr;
    std::memcpy(&ptr, static_cast<const B*>(base) + offset, sizeof(ptr));
    return ptr;
}

void store_ptr(void* base, U offset, void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

U bswap32(U value) {
    return ((value & 0x000000ffu) << 24u) |
           ((value & 0x0000ff00u) << 8u) |
           ((value & 0x00ff0000u) >> 8u) |
           ((value & 0xff000000u) >> 24u);
}

} // namespace

void* scene_flare_table_00627e48 = nullptr;
void* scene_route_sky_00627e4c = nullptr;

void* __cdecl scene_flare_table_get_0045dd80() {
    return scene_flare_table_00627e48;
}

void* __fastcall scene_route_sky_get_0045cfb0(void* /*unused_ecx*/, void* /*unused_edx*/) {
    return scene_route_sky_00627e4c;
}

void* __cdecl scene_chunk_find_tag_0053c680(const void* archive, const char* name) {
    const U tag = render_buffer_read_word_0056e2a8(name, 4);
    const U count = load32(archive, 0x08u);
    for (U i = count; i > 0u; --i) {
        const U idx = i - 1u;
        if (load32(archive, 0x10u + idx * 8u) == tag) {
            return const_cast<B*>(static_cast<const B*>(archive)) +
                   load32(archive, 0x14u + idx * 8u);
        }
    }
    return nullptr;
}

std::int32_t __fastcall scene_sky_find_name_00460b50(
    void* self, void* /*unused_edx*/, const char* name) {
    for (U i = 0u; i < kSkySlotCount; ++i) {
        if (load_ptr(self, 0x08u + i * 4u) != nullptr) {
            const auto* slot_name = reinterpret_cast<const char*>(
                static_cast<const B*>(self) + 0xa8u + i * 6u);
            if (std::strcmp(slot_name, name) == 0) {
                return static_cast<std::int32_t>(i);
            }
        }
    }

    void* const chunk = scene_chunk_find_tag_0053c680(load_ptr(self, 0x04u), name);
    if (chunk == nullptr) {
        return -1;
    }

    for (U i = 0u; i < kSkySlotCount; ++i) {
        if (load_ptr(self, 0x08u + i * 4u) == nullptr) {
            store_ptr(self, 0x08u + i * 4u, chunk);
            auto* const dst_name = reinterpret_cast<char*>(
                static_cast<B*>(self) + 0xa8u + i * 6u);
            std::strcpy(dst_name, name);
            return static_cast<std::int32_t>(i);
        }
    }
    return 0;
}

std::int32_t __fastcall scene_sky_find_tag_00460b10(
    void* self, void* /*unused_edx*/, std::uint32_t tag) {
    char name_buf[5]{};
    name_buf[0] = static_cast<char>((tag >> 24u) & 0xffu);
    name_buf[1] = static_cast<char>((tag >> 16u) & 0xffu);
    name_buf[2] = static_cast<char>((tag >> 8u) & 0xffu);
    name_buf[3] = static_cast<char>(tag & 0xffu);
    name_buf[4] = '\0';
    return scene_sky_find_name_00460b50(self, nullptr, name_buf);
}

void* __fastcall scene_sky_texture_get_00460c80(
    void* self, void* /*unused_edx*/, std::int32_t index) {
    const U tex_off = 0x198u + static_cast<U>(index) * 4u;
    if (load_ptr(self, tex_off) == nullptr) {
        void* const driver = load_ptr(render_display_00628130, 0x74u);
        void* const chunk = load_ptr(self, 0x08u + static_cast<U>(index) * 4u);
        void* const tex = scene_sky_texture_create_0044da10(chunk, kSkyMagic, 1u, driver, 0u);
        store_ptr(self, tex_off, tex);
    }
    return load_ptr(self, tex_off);
}

void __fastcall scene_flare_entries_resolve_00452120(void* self, void* /*unused_edx*/) {
    for (U off = 0x04u; off < 0x0cu; off += 4u) {
        const void* entry = load_ptr(self, 0x00u);
        const U tag = load32(entry, off);
        if (tag == kNullTag) {
            store_ptr(self, off, nullptr);
            continue;
        }
        const std::int32_t idx = scene_sky_find_tag_00460b10(
            scene_route_sky_get_0045cfb0(scene_flare_table_get_0045dd80(), nullptr),
            nullptr, tag);
        if (idx != -1) {
            void* const tex = scene_sky_texture_get_00460c80(
                scene_route_sky_get_0045cfb0(scene_flare_table_get_0045dd80(), nullptr),
                nullptr, idx);
            store_ptr(self, off, tex);
        } else {
            void* const resolved = startup_context_table_lookup_0044d320(
                startup_context_table_owner_00613e04, nullptr, 0u, bswap32(tag));
            store_ptr(self, off, resolved);
        }
    }
}

} // namespace porsche
