// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run810: 0044d270 (165B), 00537f30 (8B), 00537f60 (37B),
//         0059f880 (19B), 0059f8a0 (69B), 0059fb90 (46B).
#include "scene_stage_table_load_810.hpp"

#include "porsche/application_heap.hpp"

#include <cstring>

namespace porsche {
namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;
using ScalarDeleteFn = void*(__fastcall*)(void*, void*, U);

struct MappedFileState {
    void* owner_obj;
    void* data;
    U handle;
    U size;
    U mapped_flag;
};
static_assert(sizeof(MappedFileState) == 0x14u);

I load32s(const void* base, U offset) {
    I value = 0;
    std::memcpy(&value, static_cast<const B*>(base) + offset, sizeof(value));
    return value;
}

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

void store32(void* base, U offset, U value) {
    std::memcpy(static_cast<B*>(base) + offset, &value, sizeof(value));
}

void store_ptr(void* base, U offset, const void* ptr) {
    std::memcpy(static_cast<B*>(base) + offset, &ptr, sizeof(ptr));
}

} // namespace

std::uint32_t __cdecl scene_shape_table_count_00537f30(const void* table) {
    return load32(table, 0x08u);
}

void __cdecl scene_shape_table_tag_00537f60(
    const void* table, std::int32_t index, std::uint32_t* out_tag) {
    const I count = load32s(table, 0x08u);
    if (index < count) {
        *out_tag = load32(table, 0x10u + static_cast<U>(index) * 8u);
        return;
    }
    *out_tag = 0u;
}

void __fastcall scene_mapped_file_init_0059f880(void* self, void* /*unused_edx*/) {
    B* const bytes = static_cast<B*>(self);
    store32(bytes, 0x00u, 0u);
    store32(bytes, 0x04u, 0u);
    store32(bytes, 0x08u, 0u);
    store32(bytes, 0x0cu, 0u);
    bytes[0x10u] = 0u;
}

void __fastcall scene_mapped_file_close_0059f8a0(void* self, void* /*unused_edx*/) {
    B* const bytes = static_cast<B*>(self);
    void* const data = load_ptr(bytes, 0x04u);
    if (data != nullptr) {
        void* const owner = load_ptr(bytes, 0x00u);
        if (owner != nullptr) {
            void* const vptr = load_ptr(owner, 0x00u);
            ScalarDeleteFn dtor = nullptr;
            std::memcpy(&dtor, vptr, sizeof(dtor));
            (void)dtor(owner, nullptr, 1u);
            store_ptr(bytes, 0x00u, nullptr);
            store_ptr(bytes, 0x04u, nullptr);
            store32(bytes, 0x08u, 0u);
            return;
        }
        (void)application_page_release_0059ed90(data);
        store_ptr(bytes, 0x04u, nullptr);
        store32(bytes, 0x08u, 0u);
    }
}

void* __fastcall scene_mapped_file_data_0059fb90(void* self, void* /*unused_edx*/) {
    B* const bytes = static_cast<B*>(self);
    if (bytes[0x10u] == 0u) {
        if (load_ptr(bytes, 0x00u) == nullptr) {
            const U size = load32(bytes, 0x0cu);
            if (size != 0u) {
                application_page_protect_005af040(
                    load_ptr(bytes, 0x04u), size, 1u);
            }
        }
        bytes[0x10u] = 1u;
    }
    return load_ptr(bytes, 0x04u);
}

void __fastcall scene_stage_table_load_0044d270(
    void* self, void* /*unused_edx*/, const char* path, std::uint32_t zero) {
    MappedFileState mapped{};
    scene_mapped_file_init_0059f880(&mapped, nullptr);
    scene_mapped_file_open_0059f8f0(&mapped, nullptr, path, 0u);
    const void* const table = scene_mapped_file_data_0059fb90(&mapped, nullptr);
    if (table == nullptr) {
        scene_mapped_file_close_0059f8a0(&mapped, nullptr);
        return;
    }

    const U count = scene_shape_table_count_00537f30(table);
    for (U idx = 0u; idx < count; ++idx) {
        U entry_tag = 0u;
        scene_shape_table_tag_00537f60(table, static_cast<I>(idx), &entry_tag);
        const U entry_off = load32(table, 0x14u + idx * 8u);
        const void* const entry_ptr = static_cast<const B*>(table) + entry_off;
        (void)scene_stage_entry_register_0044d380(
            self, nullptr, entry_ptr, 0u, entry_tag, 0u, 1u, 1u, zero);
    }
    scene_mapped_file_close_0059f8a0(&mapped, nullptr);
}

} // namespace porsche
