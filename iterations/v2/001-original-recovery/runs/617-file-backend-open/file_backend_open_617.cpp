// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00568900..005689a9, 170 bytes, sha256 22c0e608b84a8d6c56614a4dbd829fd386348103e2a099a8a2072dfd2b9b205c.
#include "file_backend_open_617.hpp"

namespace porsche {

void* __cdecl file_backend_open_00568900(const char* path, std::uint32_t mode, std::uint32_t flags) {
    const char* const pipe = formatter_search_character_005a2780(path, 0x7c);
    FileOpenContext_617 ctx{};
    ctx.prefix_ptr = ctx.prefix_buf;
    ctx.full_path = path;
    ctx.status = 0u;
    ctx.handle_or_tail = nullptr;
    if (pipe != nullptr) {
        const std::uint32_t prefix_len = static_cast<std::uint32_t>(pipe - path);
        (void)formatter_error_copy_n_005a28a0(ctx.prefix_buf, path, prefix_len);
        ctx.prefix_buf[prefix_len] = '\0';
        ctx.full_path = pipe + 1;
    } else {
        ctx.status = disk_physical_open_005919a0(path, mode, 0u, &ctx.handle_or_tail);
        ctx.prefix_buf[0] = '\0';
    }
    if (flags != 0u && ctx.status == 0u) {
        (void)network_callback_enumerate_locked_00580e60(
            &free_auxiliary_006a5c38,
            reinterpret_cast<NetworkCallbackVisit488>(0x005689b0u),
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&ctx)));
    }
    return ctx.handle_or_tail;
}

} // namespace porsche
