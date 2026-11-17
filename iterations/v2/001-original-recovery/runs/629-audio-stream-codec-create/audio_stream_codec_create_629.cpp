// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0056aff0..0056b223, 564 bytes, sha256 3c48bdf3f3510051a89235a9fc15545580bdfe77c1e893f47ffa594572f765be.
#include "audio_stream_codec_create_629.hpp"

#include <cstring>

namespace porsche {

const char stream_err_invalid_filters_005bd8b8[48] = "STREAM_create - invalid number of filters (%d)\n";
const char stream_err_invalid_taps_005bd8e8[45] = "STREAM_create - invalid number of taps (%d)\n";
const char stream_err_too_many_requests_005bd918[40] = "STREAM_create - too many requests (%d)\n";
const char stream_err_min_requests_005bd940[55] = "STREAM_create - a minimum of two requests is required\n";
const char stream_source_file_005bd978[19] = "\\real\\cmn\\stream.c";
const char stream_err_buf_small_005bd98c[41] = "STREAM_create - stream buffer too small\n";

namespace {

using U = std::uint32_t;
using I = std::int32_t;

void write_u32(U addr, U value) {
    std::memcpy(reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr)), &value, sizeof value);
}

void report_stream_error(U line, const char* fmt) {
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    diagnostic_handler_005debf0(fmt);
}

void report_stream_error_arg(U line, const char* fmt, U arg) {
    diagnostic_file_005deb74_set(stream_source_file_005bd978);
    diagnostic_line_005deb78 = line;
    reinterpret_cast<void(__cdecl*)(const char*, U)>(diagnostic_handler_005debf0)(fmt, arg);
}

} // namespace

std::uint32_t __cdecl audio_stream_codec_create_0056aff0(
    std::uint32_t num_requests,
    std::uint32_t num_filters,
    std::uint32_t num_taps,
    std::uint32_t stream_buf,
    std::uint32_t buf_bytes) {
    const U min_bytes = audio_stream_codec_bytes_0056afc0(num_requests, num_filters, num_taps);
    if (static_cast<I>(buf_bytes - min_bytes) < 0x6000) {
        report_stream_error(0x3a8u, stream_err_buf_small_005bd98c);
        return 0u;
    }

    const I req_count = static_cast<I>(num_requests);
    if (req_count < 2) {
        report_stream_error(0x3aeu, stream_err_min_requests_005bd940);
        return 0u;
    }
    if (req_count > 0x100) {
        report_stream_error_arg(0x3b4u, stream_err_too_many_requests_005bd918, num_requests);
        return 0u;
    }

    const I flt_count = static_cast<I>(num_filters);
    if (flt_count < 1 || flt_count > 0x10) {
        report_stream_error_arg(0x3bau, stream_err_invalid_filters_005bd8b8, num_filters);
        return 0u;
    }

    const I tap_count = static_cast<I>(num_taps);
    if (tap_count < 1 || tap_count > flt_count) {
        report_stream_error_arg(0x3c0u, stream_err_invalid_taps_005bd8e8, num_taps);
        return 0u;
    }

    write_u32(stream_buf + 0x00u, 0x4d525453u);
    const U lock_word = static_cast<U>(reinterpret_cast<std::uintptr_t>(heap_lock_create_005321f0()));
    write_u32(stream_buf + 0x04u, lock_word);

    const U requests_base = stream_buf + 0x170u;
    const U requests_bytes = num_requests * 0x128u;
    const U filters_base = requests_base + requests_bytes;
    const U taps_base = filters_base + num_filters * 0x0cu;
    const U ring_start = ((taps_base + (num_taps << 4)) & 0xffffffe0u) + 0x20u;
    const U buf_end = stream_buf + buf_bytes;

    write_u32(stream_buf + 0x08u, requests_base);
    write_u32(stream_buf + 0x0cu, num_requests);
    write_u32(stream_buf + 0x10u, filters_base);
    write_u32(stream_buf + 0x14u, num_filters);
    write_u32(stream_buf + 0x18u, taps_base);
    write_u32(stream_buf + 0x1cu, num_taps);
    write_u32(stream_buf + 0x20u, ring_start);
    write_u32(stream_buf + 0x24u, buf_end);
    write_u32(stream_buf + 0x28u, 0u);
    write_u32(stream_buf + 0x2cu, 0x96u);
    write_u32(stream_buf + 0x30u, 0x32u);
    write_u32(stream_buf + 0x34u, 0u);
    write_u32(stream_buf + 0x38u, 0u);
    write_u32(stream_buf + 0x3cu, 0u);
    write_u32(stream_buf + 0x40u, ring_start);
    write_u32(stream_buf + 0x44u, ring_start);
    write_u32(stream_buf + 0x48u, ring_start);
    write_u32(stream_buf + 0x4cu, 0u);
    write_u32(stream_buf + 0x50u, 0u);
    write_u32(stream_buf + 0x54u, 0u);
    write_u32(stream_buf + 0x58u, requests_base);
    std::memset(reinterpret_cast<void*>(static_cast<std::uintptr_t>(stream_buf + 0x5cu)), 0, 0x41u * 4u);
    write_u32(stream_buf + 0x160u, 0u);

    for (I i = 0; i < req_count; ++i) {
        const U req = requests_base + static_cast<U>(i) * 0x128u;
        write_u32(req + 0x00u, static_cast<U>(i));
        write_u32(req + 0x04u, 0u);
        write_u32(req + 0x0cu, req + 0x128u);
    }
    write_u32(requests_base + requests_bytes - 0x11cu, 0u);

    for (I i = 0; i < flt_count; ++i) {
        const U flt = filters_base + static_cast<U>(i) * 0x0cu;
        write_u32(flt + 0x00u, 0u);
        write_u32(flt + 0x04u, 0u);
        write_u32(flt + 0x08u, 1u);
    }

    for (I i = 0; i < tap_count; ++i) {
        const U tap = taps_base + static_cast<U>(i) * 0x10u;
        write_u32(tap + 0x00u, stream_buf);
        write_u32(tap + 0x04u, static_cast<U>(i + 1));
        write_u32(tap + 0x08u, 0u);
    }

    return taps_base;
}

} // namespace porsche
