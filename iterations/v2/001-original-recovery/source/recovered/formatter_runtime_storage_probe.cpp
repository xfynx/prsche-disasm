#include "porsche/formatter_runtime_storage.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Private link identities only; unresolved fatal effects must never execute.
namespace porsche {
void __cdecl formatter_default_float_failure_005abee8(
    const void*, char*, int, int, int) { std::abort(); }
void __cdecl formatter_default_text_failure_005abee8(char*) { std::abort(); }
}
static void bytes(const char* name, const void* data, std::size_t size) {
    std::printf("{\"name\":\"%s\",\"hex\":\"", name);
    const auto* p = static_cast<const unsigned char*>(data);
    for (std::size_t i = 0; i < size; ++i) std::printf("%02x", p[i]);
    std::puts("\"}");
}
int main() {
    using namespace porsche;
    bool ok = formatter_cleanup_stream_005e5508 == &formatter_iob_entries_005e54e8[1] &&
              formatter_cleanup_stream_005e5528 == &formatter_iob_entries_005e54e8[2] &&
              formatter_iob_entries_005e54e8[0].cursor == reinterpret_cast<char*>(formatter_iob_buffer_006c0520) &&
              formatter_iob_entries_005e54e8[0].base == reinterpret_cast<char*>(formatter_iob_buffer_006c0520) &&
              formatter_cleanup_invalid_handle_record_005e5f50 == formatter_invalid_handle_record_bytes_005e5f50 &&
              formatter_null_narrow_005e57a0 == formatter_null_narrow_bytes_005c1a34 &&
              formatter_null_wide_005e57a4 == formatter_null_wide_bytes_005c1a24 &&
              formatter_float_boundary_005e5788 == &formatter_default_float_failure_005abee8 &&
              formatter_float_post_005e578c == &formatter_default_text_failure_005abee8 &&
              formatter_float_post_005e5794 == &formatter_default_text_failure_005abee8;
    if (!ok) return 1;
    unsigned char iob[20 * 32];
    std::memcpy(iob, formatter_iob_entries_005e54e8, sizeof(iob));
    const std::uint32_t original_buffer = 0x006c0520;
    std::memcpy(iob, &original_buffer, 4);
    std::memcpy(iob + 8, &original_buffer, 4);
    bytes("iob", iob, sizeof(iob));
    bytes("buffer", formatter_iob_buffer_006c0520, sizeof(formatter_iob_buffer_006c0520));
    bytes("invalid_record", formatter_invalid_handle_record_bytes_005e5f50, 36);
    bytes("preceding_bank", &formatter_cleanup_preceding_handle_bank_006c01dc, 4);
    bytes("handle_table", formatter_cleanup_handle_table_006c01e0, 64 * 4);
    bytes("handle_limit", &formatter_cleanup_handle_limit_006c02e0, 4);
    bytes("null_narrow", formatter_null_narrow_bytes_005c1a34, 7);
    bytes("null_wide", formatter_null_wide_bytes_005c1a24, 14);
    std::puts("{\"native_pointer_identities\":true,\"unresolved_callbacks_executed\":false}");
    return 0;
}
