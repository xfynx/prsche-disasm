// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056b860..0056ba10, 433 bytes, sha256 7934318957f3fd74c440f7f8f20b10299a959d2361223fd6d1e167561b2f27a5.
// Original 0056ba20..0056ba74, 85 bytes, sha256 0c7048ca80924f5deb797afa63eee427b9363c92c115e0099a1f48dfe63b8b99.
// Original 0056ba80..0056bae0, 97 bytes, sha256 09c69111b2176f2560a92a51ae1f75ff6a6d32875a6357dd8580559ee99bc3d6.
#include "audio_stream_codec_advance_659.hpp"

#include <cstring>

namespace porsche {

const char stream_err_unable_to_close_005bdbfc[40] =
    "STREAM - unable to initiate file close\n";
const char stream_err_unable_to_open_005bdc24[39] =
    "STREAM - unable to initiate file open\n";
const char stream_err_unable_to_open_file_005bdc4c[35] =
    "STREAM - unable to open file '%s'\n";

namespace {

using U = std::uint32_t;

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, reinterpret_cast<const void*>(static_cast<std::uintptr_t>(addr)), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

inline void* ptr_from_va(U addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline void report_stream_error(U line, const char* msg) {
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    diagnostic_handler_005debf0(msg);
}

inline void report_stream_open_file_error(U line, const char* path) {
    const char* const format = stream_err_unable_to_open_file_005bdc4c;
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    // Original 0056ba5b pushes two args through the canonical 1-arg cell.
    __asm {
        mov eax, path
        push eax
        mov ecx, format
        push ecx
        call dword ptr [diagnostic_handler_005debf0]
        add esp, 8
    }
}

} // namespace

void __cdecl audio_stream_codec_open_done_0056ba20(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec) {
    (void)op_handle;
    (void)status;

    const U codec_va = va_from_ptr(codec);
    const U handle = operation_complete_00567df0(read_u32(codec_va + 0x168u));
    write_u32(codec_va + 0x160u, handle);
    if (handle == 0u) {
        report_stream_open_file_error(
            0x1e7u,
            reinterpret_cast<const char*>(ptr_from_va(codec_va + 0x5cu)));
        return;
    }

    audio_stream_codec_refill_0056baf0(codec, read_u32(codec_va + 0x30u));
}

void __cdecl audio_stream_codec_close_done_0056ba80(
    std::uint32_t op_handle,
    std::int32_t status,
    void* codec) {
    (void)op_handle;
    (void)status;

    const U codec_va = va_from_ptr(codec);
    (void)operation_complete_00567df0(read_u32(codec_va + 0x168u));
    const U op_id = request_open_00568aa0(
        reinterpret_cast<const char*>(ptr_from_va(codec_va + 0x5cu)),
        1u,
        read_u32(codec_va + 0x30u),
        codec);
    write_u32(codec_va + 0x168u, op_id);
    if (op_id == 0u) {
        report_stream_error(0x206u, stream_err_unable_to_open_005bdc24);
        return;
    }

    operation_callback_005680c0(op_id, &audio_stream_codec_open_done_0056ba20);
}

void __cdecl audio_stream_codec_advance_0056b860(
    void* codec,
    std::uint32_t offset) {
    const U codec_va = va_from_ptr(codec);
    void* const lock = ptr_from_va(read_u32(codec_va + 0x04u));
    heap_enter_005322b0(lock);

    U req = read_u32(codec_va + 0x50u);
    bool have_req = false;
    if (req != 0u) {
        if (read_u32(req + 0x04u) != 1u) {
            req = read_u32(req + 0x0cu);
            if (req != 0u) {
                write_u32(codec_va + 0x50u, req);
                have_req = true;
            }
        } else {
            have_req = true;
        }
    }

    if (have_req) {
        write_u32(req + 0x124u, read_u32(codec_va + 0x44u));
        write_u32(req + 0x04u, 2u);
    } else {
        write_u32(codec_va + 0x28u, 0u);
    }

    heap_leave_005322c0(lock);
    if (!have_req) {
        return;
    }

    const U write44 = read_u32(codec_va + 0x44u);
    write_u32(codec_va + 0x48u, write44);
    if (read_u32(req + 0x10u) == 1u) {
        write_u32(codec_va + 0x164u, 0u);
        audio_stream_codec_refill_0056baf0(codec, offset);
        return;
    }

    write_u32(codec_va + 0x164u, read_u32(req + 0x11cu));
    char* const codec_path = reinterpret_cast<char*>(ptr_from_va(codec_va + 0x5cu));
    const char* const req_path = reinterpret_cast<const char*>(ptr_from_va(req + 0x14u));
    if (std::strcmp(req_path, codec_path) == 0) {
        audio_stream_codec_refill_0056baf0(codec, offset);
        return;
    }

    std::memcpy(codec_path, req_path, std::strlen(req_path) + 1u);
    const U file_handle = read_u32(codec_va + 0x160u);
    if (file_handle == 0u) {
        const U op_id = request_open_00568aa0(codec_path, 1u, offset, codec);
        write_u32(codec_va + 0x168u, op_id);
        if (op_id == 0u) {
            report_stream_error(0x291u, stream_err_unable_to_open_005bdc24);
            return;
        }
        operation_callback_005680c0(op_id, &audio_stream_codec_open_done_0056ba20);
        return;
    }

    const U op_id = request_close_00568ae0(ptr_from_va(file_handle), offset, codec);
    write_u32(codec_va + 0x168u, op_id);
    if (op_id == 0u) {
        report_stream_error(0x29cu, stream_err_unable_to_close_005bdbfc);
        return;
    }
    operation_callback_005680c0(op_id, &audio_stream_codec_close_done_0056ba80);
}

} // namespace porsche
