#include "porsche/formatter_runtime_storage.hpp"

namespace porsche {
// Original 006c0520 is zero-fill BSS storage. Keeping it a separately named
// byte buffer makes the two native pointer relocations explicit.
std::uint8_t formatter_iob_buffer_006c0520[0x1000]{};

FormatterOriginalDescriptor32 formatter_iob_entries_005e54e8[20] = {
    {reinterpret_cast<char*>(formatter_iob_buffer_006c0520), 0,
     reinterpret_cast<char*>(formatter_iob_buffer_006c0520), 0x101,
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10, 0, 0, 0, 0, 0, 0}},
    {nullptr, 0, nullptr, 2,
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {nullptr, 0, nullptr, 2,
     {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
};

const std::uint8_t formatter_invalid_handle_record_bytes_005e5f50[36] = {
    0xff, 0xff, 0xff, 0xff, 0x00, 0x0a
};
const char formatter_null_narrow_bytes_005c1a34[7] = "(null)";
const std::uint16_t formatter_null_wide_bytes_005c1a24[7] = {
    '(', 'n', 'u', 'l', 'l', ')', 0
};

FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5508 =
    &formatter_iob_entries_005e54e8[1];
FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5528 =
    &formatter_iob_entries_005e54e8[2];
const std::uint8_t* formatter_cleanup_invalid_handle_record_005e5f50 =
    formatter_invalid_handle_record_bytes_005e5f50;
const std::uint8_t* formatter_cleanup_preceding_handle_bank_006c01dc = nullptr;
const std::uint8_t* formatter_cleanup_handle_table_006c01e0[64]{};
std::uint32_t formatter_cleanup_handle_limit_006c02e0 = 0;

const char* formatter_null_narrow_005e57a0 = formatter_null_narrow_bytes_005c1a34;
const std::uint16_t* formatter_null_wide_005e57a4 = formatter_null_wide_bytes_005c1a24;
FormatterFloatBoundary formatter_float_boundary_005e5788 =
    &formatter_default_float_failure_005abee8;
FormatterTextBoundary formatter_float_post_005e5794 =
    &formatter_default_text_failure_005abee8;
FormatterTextBoundary formatter_float_post_005e578c =
    &formatter_default_text_failure_005abee8;

static_assert(sizeof(formatter_iob_entries_005e54e8) == 20 * 32);
static_assert(sizeof(formatter_cleanup_handle_table_006c01e0) == 64 * sizeof(void*));
static_assert(sizeof(formatter_invalid_handle_record_bytes_005e5f50) == 36);

} // namespace porsche
