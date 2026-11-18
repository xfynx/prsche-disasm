// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00574eb0..00574f79 (202B), 00414bd0..00414c1a (75B),
// and 00414c30..00414cab (124B).
#include "render_loader_directx_673.hpp"

#include <cstddef>
#include <cstring>

#pragma comment(lib, "version.lib")

extern "C" {
std::int32_t __stdcall GetVersionExA(void* version_information);
std::uint32_t __stdcall GetFileVersionInfoSizeA(const char* filename, std::uint32_t* handle);
std::int32_t __stdcall GetFileVersionInfoA(
    const char* filename, std::uint32_t handle, std::uint32_t len, void* data);
std::int32_t __stdcall VerQueryValueA(
    const void* block, const char* sub_block, void** buffer, std::uint32_t* len);
}

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

namespace {

struct OriginalOsVersionInfoA {
    std::uint32_t dwOSVersionInfoSize;
    std::uint32_t dwMajorVersion;
    std::uint32_t dwMinorVersion;
    std::uint32_t dwBuildNumber;
    std::uint32_t dwPlatformId;
    char szCSDVersion[128];
};

static_assert(sizeof(OriginalOsVersionInfoA) == 0x94u);
static_assert(offsetof(OriginalOsVersionInfoA, dwPlatformId) == 0x10u);

std::int32_t __stdcall os_get_version_ex_a(void* version_information) {
    return ::GetVersionExA(version_information);
}

std::uint32_t __stdcall os_get_file_version_info_size_a(
    const char* filename, std::uint32_t* handle) {
    return ::GetFileVersionInfoSizeA(filename, handle);
}

std::int32_t __stdcall os_get_file_version_info_a(
    const char* filename, std::uint32_t handle, std::uint32_t len, void* data) {
    return ::GetFileVersionInfoA(filename, handle, len, data);
}

std::int32_t __stdcall os_ver_query_value_a(
    const void* block, const char* sub_block, void** buffer, std::uint32_t* len) {
    return ::VerQueryValueA(block, sub_block, buffer, len);
}

std::int32_t read_i32(const void* base, std::size_t offset) {
    std::int32_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void write_i32(void* base, std::size_t offset, std::int32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_u32(void* base, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

} // namespace

RenderDirectxGetVersionExA render_directx_get_version_ex_a = os_get_version_ex_a;
RenderDirectxGetFileVersionInfoSizeA render_directx_get_file_version_info_size_a =
    os_get_file_version_info_size_a;
RenderDirectxGetFileVersionInfoA render_directx_get_file_version_info_a =
    os_get_file_version_info_a;
RenderDirectxVerQueryValueA render_directx_ver_query_value_a = os_ver_query_value_a;

void __cdecl render_loader_directx_00574eb0(std::uint32_t result[2], const char* dll) {
    result[1] = 0u;
    result[0] = 0u;

    OriginalOsVersionInfoA osvi;
    std::memset(&osvi, 0, sizeof(osvi));
    osvi.dwOSVersionInfoSize = sizeof(osvi);
    (void)render_directx_get_version_ex_a(&osvi);
    if (osvi.dwPlatformId == 2u) {
        return;
    }

    std::uint32_t handle = 0u;
    const std::uint32_t size = render_directx_get_file_version_info_size_a(dll, &handle);
    if (size == 0u) {
        return;
    }

    void* const buffer = exit_registry_malloc_005a3be5(size);
    if (buffer == nullptr) {
        return;
    }

    if (render_directx_get_file_version_info_a(dll, handle, size, buffer) != 0) {
        void* info = nullptr;
        // Porsche.exe 005d11e8 is the shared 2-byte .data string "\\" (also read by 004a5980/0051c050/0052c430).
        if (render_directx_ver_query_value_a(buffer, "\\", &info, nullptr) != 0) {
            const auto* const bytes = static_cast<const std::uint8_t*>(info);
            std::uint32_t low = 0u;
            std::uint32_t high = 0u;
            std::memcpy(&low, bytes + 0x0cu, sizeof(low));
            std::memcpy(&high, bytes + 0x08u, sizeof(high));
            result[0] = low;
            result[1] = high;
        }
    }

    formatter_crt_free_005a3b9d(buffer);
}

void* __cdecl startup_sorted_table_create_00414bd0(
    const char* name, std::int32_t capacity) {
    const std::int32_t bytes = static_cast<std::int32_t>(
        (static_cast<std::uint32_t>(capacity) << 4) + 0x18u);
    void* const table = allocate_00531ca0(name, bytes, 0u);
    write_i32(table, 0u, capacity);
    write_i32(table, 4u, 0);
    if (capacity > 0) {
        std::int32_t index = 0;
        do {
            const std::uint32_t offset = static_cast<std::uint32_t>(index) * 16u;
            write_i32(table, offset + 8u, 0x7ffe);
            write_u32(table, offset + 12u, 0u);
            ++index;
        } while (index < read_i32(table, 0u));
    }
    return table;
}

void __cdecl startup_sorted_table_insert_00414c30(
    void* table, std::uint32_t value0, std::uint32_t value1, std::int32_t key) {
    auto* const base = static_cast<std::uint8_t*>(table);
    const std::int32_t old_count = read_i32(table, 4u);
    const std::int32_t new_count = static_cast<std::int32_t>(
        static_cast<std::uint32_t>(old_count) + 1u);
    write_i32(table, 4u, new_count);

    std::int32_t insert_index = 0;
    if (new_count > 0) {
        std::int32_t index = 0;
        while (index < new_count) {
            const std::int32_t entry_key = read_i32(
                table, 8u + static_cast<std::uint32_t>(index) * 16u);
            insert_index = index;
            if (key < entry_key) {
                if (old_count > index) {
                    std::uint8_t* dst =
                        base + 8u + static_cast<std::uint32_t>(old_count) * 16u;
                    for (std::int32_t remaining = old_count - index;
                         remaining > 0; --remaining) {
                        std::uint8_t* const src = dst - 16u;
                        heap_copy_dispatch_005323e0(dst, src, 16u);
                        dst = src;
                    }
                }
                break;
            }
            ++index;
        }
    }

    const std::uint32_t offset = static_cast<std::uint32_t>(insert_index) * 16u;
    write_i32(table, offset + 8u, key);
    write_u32(table, offset + 12u, value0);
    write_u32(table, (static_cast<std::uint32_t>(insert_index) + 1u) * 16u, value1);
}

} // namespace porsche
