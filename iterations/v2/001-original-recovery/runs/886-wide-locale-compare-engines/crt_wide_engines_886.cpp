// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 005ae901..005ae9f8 (248B), 005ae6b6..005ae8d0 (539B),
// 005aea71..005aeae5 (117B), 005aecef..005aed40 (82B),
// 005ae1f7..005ae3bb (453B), 005aeae6..005aecee (521B),
// 005ae8d1..005ae900 (48B), and .data table 005e52d4..005e54d9 (518B).
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <malloc.h>

#include "crt_wide_engines_886.hpp"
#include "porsche/context_services.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include "porsche/formatter_locale.hpp"
#include "porsche/formatter_text.hpp"

namespace porsche {

const std::uint16_t crt_ctype_table_005e52d8[257] = {
    0x0000u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u,
    0x0020u, 0x0020u, 0x0028u, 0x0028u, 0x0028u, 0x0028u, 0x0028u, 0x0020u,
    0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u,
    0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u, 0x0020u,
    0x0020u, 0x0048u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u,
    0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u,
    0x0010u, 0x0084u, 0x0084u, 0x0084u, 0x0084u, 0x0084u, 0x0084u, 0x0084u,
    0x0084u, 0x0084u, 0x0084u, 0x0010u, 0x0010u, 0x0010u, 0x0010u, 0x0010u,
    0x0010u, 0x0010u, 0x0081u, 0x0081u, 0x0081u, 0x0081u, 0x0081u, 0x0081u,
    0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u,
    0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0001u,
    0x0001u, 0x0001u, 0x0001u, 0x0001u, 0x0010u, 0x0010u, 0x0010u, 0x0010u,
    0x0010u, 0x0010u, 0x0082u, 0x0082u, 0x0082u, 0x0082u, 0x0082u, 0x0082u,
    0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u,
    0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0002u,
    0x0002u, 0x0002u, 0x0002u, 0x0002u, 0x0010u, 0x0010u, 0x0010u, 0x0010u,
    0x0020u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u, 0x0000u,
    0x0000u,
};

const std::uint16_t* crt_pctype_ptr_005e52d4 = &crt_ctype_table_005e52d8[1];

std::uint32_t crt_string_type_use_mode_006b0050 = 0u;
std::uint32_t crt_compare_w_use_mode_006b0058 = 0u;
std::uint32_t crt_lcmap_use_mode_006b0064 = 0u;

namespace {

std::uint32_t align4_bytes(int n) {
    return (static_cast<std::uint32_t>(n) + 3u) & ~3u;
}

std::uint16_t ascii_lower_w(std::uint16_t ch) {
    if (ch >= 0x41u && ch <= 0x5au) {
        return static_cast<std::uint16_t>(ch + 0x20u);
    }
    return ch;
}

} // namespace

int __cdecl crt_wcsnlen_005ae8d1(const wchar_t* s, int max_count) {
    const wchar_t* p = s;
    int remaining = max_count - 1;
    if (max_count != 0) {
        while (*p != L'\0') {
            ++p;
            if (remaining-- == 0) {
                break;
            }
        }
    }
    if (*p == L'\0') {
        return static_cast<int>(p - s);
    }
    return max_count;
}

int __cdecl crt_get_string_type_w_005ae1f7(
    std::uint32_t info_type, const wchar_t* src, int src_count,
    std::uint16_t* char_type, std::uint32_t code_page, std::uint32_t lcid) {
    static const wchar_t kDummyW[2] = {0, 0};
    static const char kDummyA[2] = {0, 0};

    if (crt_string_type_use_mode_006b0050 == 0u) {
        std::uint16_t dummy = 0u;
        if (formatter_locale_type_w(1u, reinterpret_cast<const std::uint16_t*>(kDummyW), 1, &dummy) != 0) {
            crt_string_type_use_mode_006b0050 = 1u;
        } else if (formatter_locale_type_a(0u, 1u, kDummyA, 1, &dummy) != 0) {
            crt_string_type_use_mode_006b0050 = 2u;
        } else {
            return 0;
        }
    }

    if (crt_string_type_use_mode_006b0050 == 1u) {
        return formatter_locale_type_w(
            info_type, reinterpret_cast<const std::uint16_t*>(src), src_count, char_type);
    }
    if (crt_string_type_use_mode_006b0050 != 2u) {
        return 0;
    }

    if (code_page == 0u) {
        code_page = formatter_locale_default_codepage_006afd90;
    }

    const int mblen = formatter_locale_from_wide(
        code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(src), src_count,
        nullptr, 0, nullptr, nullptr);
    if (mblen == 0) {
        return 0;
    }

    char* mb = nullptr;
    __try {
        mb = static_cast<char*>(_alloca(align4_bytes(mblen)));
        (void)formatter_crt_memset_005abe90(mb, 0, static_cast<std::uint32_t>(mblen));
    } __except (1) {
        mb = nullptr;
    }
    if (mb == nullptr) {
        return 0;
    }

    if (formatter_locale_from_wide(
            code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(src), src_count,
            mb, mblen, nullptr, nullptr) == 0) {
        return 0;
    }

    std::uint16_t* out_buf = nullptr;
    __try {
        out_buf = static_cast<std::uint16_t*>(_alloca(align4_bytes(mblen * 2 + 2)));
    } __except (1) {
        out_buf = nullptr;
    }
    if (out_buf == nullptr) {
        return 0;
    }

    if (lcid == 0u) {
        lcid = formatter_text_locale_006afd80;
    }

    out_buf[src_count] |= 0xffffu;
    out_buf[src_count - 1] |= 0xffffu;

    const int ok = formatter_locale_type_a(lcid, info_type, mb, mblen, out_buf);
    if (out_buf[src_count - 1] != 0xffffu && out_buf[src_count] == 0xffffu) {
        (void)context_move_005a1a40(char_type, out_buf, static_cast<std::uint32_t>(src_count * 2));
        return ok;
    }
    return 0;
}

int __cdecl crt_iswctype_lk_005aecef(std::uint16_t ch, std::uint16_t mask) {
    if (ch == 0xffffu) {
        return 0;
    }
    std::uint16_t bits = 0u;
    if (ch < 0x100u) {
        bits = crt_pctype_ptr_005e52d4[ch];
    } else {
        std::uint16_t queried = 0u;
        if (crt_get_string_type_w_005ae1f7(
                1u, reinterpret_cast<const wchar_t*>(&ch), 1, &queried, 0u, 0u) == 0) {
            return 0;
        }
        bits = queried;
    }
    return static_cast<int>(bits & mask);
}

int __cdecl crt_lc_map_string_w_005aeae6(
    std::uint32_t locale, std::uint32_t map_flags,
    const wchar_t* src, int src_count,
    wchar_t* dst, int dst_count,
    std::uint32_t code_page) {
    static const wchar_t kDummyW[2] = {0, 0};
    static const char kDummyA[2] = {0, 0};

    if (crt_lcmap_use_mode_006b0064 == 0u) {
        if (formatter_locale_map_w(0u, 0x100u, reinterpret_cast<const std::uint16_t*>(kDummyW), 1, nullptr, 0) != 0) {
            crt_lcmap_use_mode_006b0064 = 1u;
        } else if (formatter_locale_map_a(0u, 0x100u, kDummyA, 1, nullptr, 0) != 0) {
            crt_lcmap_use_mode_006b0064 = 2u;
        } else {
            return 0;
        }
    }

    if (src_count > 0) {
        src_count = crt_wcsnlen_005ae8d1(src, src_count);
    }

    if (crt_lcmap_use_mode_006b0064 == 1u) {
        return formatter_locale_map_w(
            locale, map_flags, reinterpret_cast<const std::uint16_t*>(src), src_count, dst, dst_count);
    }
    if (crt_lcmap_use_mode_006b0064 != 2u) {
        return 0;
    }

    if (code_page == 0u) {
        code_page = formatter_locale_default_codepage_006afd90;
    }

    const int mb_in_len = formatter_locale_from_wide(
        code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(src), src_count,
        nullptr, 0, nullptr, nullptr);
    if (mb_in_len == 0) {
        return 0;
    }

    char* mb_in = nullptr;
    __try {
        mb_in = static_cast<char*>(_alloca(align4_bytes(mb_in_len)));
    } __except (1) {
        mb_in = nullptr;
    }
    if (mb_in == nullptr) {
        return 0;
    }

    if (formatter_locale_from_wide(
            code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(src), src_count,
            mb_in, mb_in_len, nullptr, nullptr) == 0) {
        return 0;
    }

    const int mb_out_len = formatter_locale_map_a(locale, map_flags, mb_in, mb_in_len, nullptr, 0);
    if (mb_out_len == 0) {
        return 0;
    }

    char* mb_out = nullptr;
    __try {
        mb_out = static_cast<char*>(_alloca(align4_bytes(mb_out_len)));
    } __except (1) {
        mb_out = nullptr;
    }
    if (mb_out == nullptr) {
        return 0;
    }

    if (formatter_locale_map_a(locale, map_flags, mb_in, mb_in_len, mb_out, mb_out_len) == 0) {
        return 0;
    }

    if ((map_flags & 0x400u) != 0u) {
        if (dst_count != 0) {
            const int n = (dst_count < mb_out_len) ? dst_count : mb_out_len;
            (void)formatter_error_copy_n_005a28a0(
                reinterpret_cast<char*>(dst), mb_out, static_cast<std::uint32_t>(n));
        }
        return mb_out_len;
    }

    return formatter_locale_to_wide(
        code_page, 1u, mb_out, mb_out_len,
        dst_count == 0 ? nullptr : reinterpret_cast<std::uint16_t*>(dst),
        dst_count == 0 ? 0 : dst_count);
}

std::uint16_t __cdecl crt_towlower_lk_005aea71(std::uint16_t ch) {
    if (ch == 0xffffu) {
        return 0xffffu;
    }
    if (formatter_text_locale_006afd80 == 0u) {
        return ascii_lower_w(ch);
    }
    if (ch < 0x100u && crt_iswctype_lk_005aecef(ch, 1u) == 0) {
        return ch;
    }
    std::uint16_t mapped = 0u;
    if (crt_lc_map_string_w_005aeae6(
            formatter_text_locale_006afd80, 0x100u,
            reinterpret_cast<const wchar_t*>(&ch), 1,
            reinterpret_cast<wchar_t*>(&mapped), 1, 0u) == 0) {
        return ch;
    }
    return mapped;
}

int __cdecl crt_wcsnicoll_default_005ae901(
    const wchar_t* left, const wchar_t* right, std::uint32_t count) {
    if (count == 0u) {
        return 0;
    }
    std::uint16_t f = 0u;
    std::uint16_t l = 0u;
    if (formatter_text_locale_006afd80 == 0u) {
        do {
            f = ascii_lower_w(static_cast<std::uint16_t>(*left++));
            l = ascii_lower_w(static_cast<std::uint16_t>(*right++));
        } while (--count != 0u && f != 0u && f == l);
    } else {
        formatter_text_increment_005b2258(&formatter_text_locale_readers_006c02e8);
        int has_lock = 0;
        if (formatter_text_locale_writer_006c02e4 != 0u) {
            formatter_text_decrement_005b2254(&formatter_text_locale_readers_006c02e8);
            exit_registry_lock_api_005a4ba4(19u);
            has_lock = 1;
        }
        do {
            f = crt_towlower_lk_005aea71(static_cast<std::uint16_t>(*left++));
            l = crt_towlower_lk_005aea71(static_cast<std::uint16_t>(*right++));
        } while (--count != 0u && f != 0u && f == l);
        if (has_lock != 0) {
            exit_registry_unlock_api_005a4c05(19u);
        } else {
            formatter_text_decrement_005b2254(&formatter_text_locale_readers_006c02e8);
        }
    }
    return static_cast<int>(f) - static_cast<int>(l);
}

int __cdecl crt_wcsnicoll_locale_005ae6b6(
    std::uint32_t locale, std::uint32_t cmp_flags,
    const wchar_t* s1, int count1,
    const wchar_t* s2, int count2,
    std::uint32_t code_page) {
    static const wchar_t kDummyW[2] = {0, 0};
    static const char kDummyA[2] = {0, 0};

    if (crt_compare_w_use_mode_006b0058 == 0u) {
        if (::CompareStringW(0u, 0u, kDummyW, 1, kDummyW, 1) != 0) {
            crt_compare_w_use_mode_006b0058 = 1u;
        } else if (::CompareStringA(0u, 0u, kDummyA, 1, kDummyA, 1) != 0) {
            crt_compare_w_use_mode_006b0058 = 2u;
        } else {
            return 0;
        }
    }

    if (count1 > 0) {
        count1 = crt_wcsnlen_005ae8d1(s1, count1);
    }
    if (count2 > 0) {
        count2 = crt_wcsnlen_005ae8d1(s2, count2);
    }

    if (count1 == 0 || count2 == 0) {
        const int diff = count1 - count2;
        if (diff == 0) {
            return 2;
        }
        return (diff >= 0) ? 3 : 1;
    }

    if (crt_compare_w_use_mode_006b0058 == 1u) {
        return ::CompareStringW(
            locale, cmp_flags,
            reinterpret_cast<LPCWSTR>(s1), count1,
            reinterpret_cast<LPCWSTR>(s2), count2);
    }
    if (crt_compare_w_use_mode_006b0058 != 2u) {
        return 0;
    }

    if (code_page == 0u) {
        code_page = formatter_locale_default_codepage_006afd90;
    }

    const int mblen1 = formatter_locale_from_wide(
        code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(s1), count1,
        nullptr, 0, nullptr, nullptr);
    if (mblen1 == 0) {
        return 0;
    }

    char* mb1 = nullptr;
    __try {
        mb1 = static_cast<char*>(_alloca(align4_bytes(mblen1)));
    } __except (1) {
        mb1 = nullptr;
    }
    if (mb1 == nullptr) {
        return 0;
    }

    if (formatter_locale_from_wide(
            code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(s1), count1,
            mb1, mblen1, nullptr, nullptr) == 0) {
        return 0;
    }

    const int mblen2 = formatter_locale_from_wide(
        code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(s2), count2,
        nullptr, 0, nullptr, nullptr);
    if (mblen2 == 0) {
        return 0;
    }

    char* mb2 = nullptr;
    __try {
        mb2 = static_cast<char*>(_alloca(align4_bytes(mblen2)));
    } __except (1) {
        mb2 = nullptr;
    }
    if (mb2 == nullptr) {
        return 0;
    }

    if (formatter_locale_from_wide(
            code_page, 0x220u, reinterpret_cast<const std::uint16_t*>(s2), count2,
            mb2, mblen2, nullptr, nullptr) == 0) {
        return 0;
    }

    return ::CompareStringA(locale, cmp_flags, mb1, mblen1, mb2, mblen2);
}

} // namespace porsche
