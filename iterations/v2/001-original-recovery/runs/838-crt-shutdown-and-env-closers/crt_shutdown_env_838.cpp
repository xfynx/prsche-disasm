// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Bounded CRT shutdown closure: 005a36d6, 005a76fd, 005a7706, 005a7673, 005acbea,
// 005a9dc8, 005a2024, 005a2055, 005a7648, 005a7568, 005a75c5.
// Bounded environment lookup closure: 005a3071, 005a9a4a, 005aa28f, 005aa416,
// 005aa46e, 005ad832, 005ad79b, 005a9a0b, 005ad042.
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <malloc.h>

#include "crt_shutdown_env_838.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/exit_shutdown.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/formatter_cleanup.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include "porsche/formatter_locale.hpp"
#include "porsche/formatter_lowio.hpp"
#include "porsche/formatter_output.hpp"
#include "porsche/formatter_runtime.hpp"
#include "porsche/formatter_search.hpp"
#include "porsche/formatter_stdio.hpp"

namespace porsche {

std::int32_t crt_nstream_006c1520 = 0;
FormatterOriginalDescriptor32** crt_piob_006c0508 = nullptr;

std::uint32_t crt_env_initialized_006c1528 = 0;
char** crt_environ_006afcc8 = nullptr;
char** crt_initenv_006afccc = nullptr;
wchar_t** crt_wenviron_006afcd0 = nullptr;
std::uint32_t crt_compare_use_mode_006b0028 = 0;

namespace {

using U = std::uint32_t;

const std::uint8_t* lowio_record(U file_id) {
    return formatter_cleanup_handle_table_006c01e0[file_id >> 5] + (file_id & 31u) * 36u;
}

std::uint8_t* mutable_lowio_record(U file_id) {
    return const_cast<std::uint8_t*>(lowio_record(file_id));
}

U stream_file_id(const FormatterOriginalDescriptor32* stream) {
    const auto* raw = reinterpret_cast<const std::uint8_t*>(stream);
    return static_cast<U>(raw[16]) | (static_cast<U>(raw[17]) << 8) |
           (static_cast<U>(raw[18]) << 16) | (static_cast<U>(raw[19]) << 24);
}

char* stream_tmpfname(FormatterOriginalDescriptor32* stream) {
    const auto* raw = reinterpret_cast<const std::uint8_t*>(stream);
    const U v = static_cast<U>(raw[28]) | (static_cast<U>(raw[29]) << 8) |
                (static_cast<U>(raw[30]) << 16) | (static_cast<U>(raw[31]) << 24);
    return reinterpret_cast<char*>(static_cast<std::uintptr_t>(v));
}

void clear_stream_tmpfname(FormatterOriginalDescriptor32* stream) {
    auto* raw = reinterpret_cast<std::uint8_t*>(stream);
    raw[28] = 0u;
    raw[29] = 0u;
    raw[30] = 0u;
    raw[31] = 0u;
}

std::uint32_t alloc_stack_bytes(int wide_count) {
    return (static_cast<std::uint32_t>(wide_count) * 2u + 3u) & ~3u;
}

int is_lone_lead_byte(const FormatterLocaleCPInfo& cpinfo, std::uint8_t ch) {
    if (cpinfo.max_character_bytes < 2u) {
        return 0;
    }
    for (int i = 0; cpinfo.lead_ranges[i] != 0u && cpinfo.lead_ranges[i + 1] != 0u; i += 2) {
        if (ch >= cpinfo.lead_ranges[i] && ch <= cpinfo.lead_ranges[i + 1]) {
            return 1;
        }
    }
    return 0;
}

} // namespace

void __cdecl exit_shutdown_static_callback_005a36d6() {
    (void)crt_flushall_005a76fd();
    if ((exit_shutdown_mode_word_006afce0 & 0xffu) != 0u) {
        (void)crt_fcloseall_005a9dc8();
    }
}

int __cdecl crt_flushall_005a76fd() {
    return crt_flsall_005a7706(1);
}

int __cdecl crt_flsall_005a7706(int flush_flag) {
    int count = 0;
    int err = 0;
    exit_registry_lock_api_005a4ba4(2u);
    for (std::int32_t i = 0; i < crt_nstream_006c1520; ++i) {
        auto* stream = crt_piob_006c0508[i];
        if (stream != nullptr && (stream->flags & 0x83u) != 0u) {
            formatter_stdio_lock_index_005a3719(i, stream);
            stream = crt_piob_006c0508[i];
            if ((stream->flags & 0x83u) != 0u) {
                if (flush_flag == 1) {
                    if (crt_fflush_nolock_005a7673(stream) != -1) {
                        ++count;
                    }
                } else if (flush_flag == 0 && (stream->flags & 0x02u) != 0u) {
                    if (crt_fflush_nolock_005a7673(stream) == -1) {
                        err = -1;
                    }
                }
            }
            formatter_stdio_unlock_index_005a376b(i, crt_piob_006c0508[i]);
        }
    }
    exit_registry_unlock_api_005a4c05(2u);
    return (flush_flag == 1) ? count : err;
}

int __cdecl crt_fflush_nolock_005a7673(FormatterOriginalDescriptor32* stream) {
    if (formatter_stdio_flush_005a76a1(stream) != 0) {
        return -1;
    }
    if ((stream->flags & 0x4000u) != 0u) {
        return (crt_commit_005acbea(stream_file_id(stream)) == 0) ? 0 : -1;
    }
    return 0;
}

int __cdecl crt_commit_005acbea(std::uint32_t file_id) {
    if (file_id >= formatter_cleanup_handle_limit_006c02e0 || (lowio_record(file_id)[4] & 0x01u) == 0u) {
        *formatter_lowio_errno_005a669e() = 9;
        return -1;
    }
    formatter_lowio_lock_005ab726(file_id);
    int retval = -1;
    if ((lowio_record(file_id)[4] & 0x01u) != 0u) {
        const auto os_handle = reinterpret_cast<HANDLE>(formatter_lowio_handle_005ab6e4(file_id));
        U dos_err = 0u;
        if (!::FlushFileBuffers(os_handle)) {
            dos_err = formatter_crt_get_last_error();
        }
        if (dos_err == 0u) {
            retval = 0;
        } else {
            *formatter_lowio_doserrno_005a66a7() = dos_err;
            *formatter_lowio_errno_005a669e() = 9;
            retval = -1;
        }
    } else {
        *formatter_lowio_errno_005a669e() = 9;
    }
    formatter_lowio_unlock_005ab785(file_id);
    return retval;
}

int __cdecl crt_fcloseall_005a9dc8() {
    int count = 0;
    exit_registry_lock_api_005a4ba4(2u);
    for (std::int32_t i = 3; i < crt_nstream_006c1520; ++i) {
        auto* stream = crt_piob_006c0508[i];
        if (stream != nullptr) {
            if ((stream->flags & 0x83u) != 0u) {
                if (crt_fclose_005a2024(stream) != -1) {
                    ++count;
                }
            }
            if (i >= 20) {
                ::DeleteCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(
                    reinterpret_cast<std::uint8_t*>(crt_piob_006c0508[i]) + 32));
                formatter_crt_free_005a3b9d(crt_piob_006c0508[i]);
                crt_piob_006c0508[i] = nullptr;
            }
        }
    }
    exit_registry_unlock_api_005a4c05(2u);
    return count;
}

int __cdecl crt_fclose_005a2024(FormatterOriginalDescriptor32* stream) {
    int result = -1;
    if ((stream->flags & 0x40u) != 0u) {
        stream->flags = 0u;
    } else {
        formatter_stdio_lock_pointer_005a36ea(stream);
        result = crt_fclose_lk_005a2055(stream);
        formatter_stdio_unlock_pointer_005a373c(stream);
    }
    return result;
}

int __cdecl crt_fclose_lk_005a2055(FormatterOriginalDescriptor32* stream) {
    int result = -1;
    if ((stream->flags & 0x83u) != 0u) {
        result = formatter_stdio_flush_005a76a1(stream);
        crt_freebuf_005a7648(stream);
        if (crt_close_005a7568(stream_file_id(stream)) < 0) {
            result = -1;
        } else {
            char* tmp = stream_tmpfname(stream);
            if (tmp != nullptr) {
                formatter_crt_free_005a3b9d(tmp);
                clear_stream_tmpfname(stream);
            }
        }
    }
    stream->flags = 0u;
    return result;
}

void __cdecl crt_freebuf_005a7648(FormatterOriginalDescriptor32* stream) {
    if ((stream->flags & 0x83u) != 0u && (stream->flags & 0x08u) != 0u) {
        formatter_crt_free_005a3b9d(stream->base);
        stream->flags &= ~0x0408u;
        stream->cursor = nullptr;
        stream->base = nullptr;
        stream->remaining = 0;
    }
}

int __cdecl crt_close_005a7568(std::uint32_t file_id) {
    if (file_id >= formatter_cleanup_handle_limit_006c02e0 || (lowio_record(file_id)[4] & 0x01u) == 0u) {
        *formatter_lowio_errno_005a669e() = 9;
        *formatter_lowio_doserrno_005a66a7() = 0u;
        return -1;
    }
    formatter_lowio_lock_005ab726(file_id);
    const int result = crt_close_lk_005a75c5(file_id);
    formatter_lowio_unlock_005ab785(file_id);
    return result;
}

int __cdecl crt_close_lk_005a75c5(std::uint32_t file_id) {
    U dos_err = 0u;
    if (formatter_lowio_handle_005ab6e4(file_id) != 0xffffffffu &&
        !((file_id == 1u || file_id == 2u) &&
          formatter_lowio_handle_005ab6e4(1u) == formatter_lowio_handle_005ab6e4(2u))) {
        if (!::CloseHandle(reinterpret_cast<HANDLE>(formatter_lowio_handle_005ab6e4(file_id)))) {
            dos_err = formatter_crt_get_last_error();
        }
    }
    (void)formatter_lowio_detach_005ab665(file_id);
    mutable_lowio_record(file_id)[4] = 0u;
    if (dos_err != 0u) {
        (void)formatter_output_map_error_005a662b(dos_err);
        return -1;
    }
    return 0;
}

const char* __cdecl application_diagnostic_environment_inner_005a3071(const char* varname) {
    if (crt_env_initialized_006c1528 == 0u) {
        return nullptr;
    }
    char** env = crt_environ_006afcc8;
    if (env == nullptr) {
        if (crt_wenviron_006afcd0 == nullptr) {
            return nullptr;
        }
        if (crt_mbtow_environ_005a9a4a() != 0) {
            return nullptr;
        }
        env = crt_environ_006afcc8;
        if (env == nullptr) {
            return nullptr;
        }
    }
    if (varname == nullptr) {
        return nullptr;
    }
    const U length = formatter_strlen_005a6730(varname);
    while (*env != nullptr) {
        if (formatter_strlen_005a6730(*env) > length &&
            (*env)[length] == '=' &&
            crt_mbsnbicoll_005a9a0b(*env, varname, length) == 0) {
            return *env + length + 1;
        }
        ++env;
    }
    return nullptr;
}

int __cdecl crt_mbtow_environ_005a9a4a() {
    wchar_t** wenv = crt_wenviron_006afcd0;
    while (*wenv != nullptr) {
        const int bytes = formatter_locale_from_wide(
            0u, 0u, reinterpret_cast<const std::uint16_t*>(*wenv), -1, nullptr, 0, nullptr, nullptr);
        if (bytes == 0) {
            return -1;
        }
        auto* mb = static_cast<char*>(exit_registry_malloc_005a3be5(static_cast<U>(bytes)));
        if (mb == nullptr) {
            return -1;
        }
        if (formatter_locale_from_wide(
                0u, 0u, reinterpret_cast<const std::uint16_t*>(*wenv), -1, mb, bytes, nullptr, nullptr) == 0) {
            return -1;
        }
        (void)crt_setenv_005aa28f(mb, 0);
        ++wenv;
    }
    return 0;
}

int __cdecl crt_setenv_005aa28f(char* option, int update_os) {
    if (option == nullptr) {
        return -1;
    }
    const char* eq = crt_mbschr_005ad79b(option, '=');
    if (eq == nullptr || eq == option) {
        return -1;
    }
    const int remove = (eq[1] == '\0') ? 1 : 0;
    char** env = crt_environ_006afcc8;
    if (env == crt_initenv_006afccc) {
        env = crt_copy_environ_005aa46e(env);
        crt_environ_006afcc8 = env;
    }
    if (env == nullptr) {
        if (update_os != 0 && crt_wenviron_006afcd0 != nullptr) {
            if (crt_mbtow_environ_005a9a4a() != 0) {
                return -1;
            }
        } else {
            if (remove != 0) {
                return 0;
            }
            crt_environ_006afcc8 = static_cast<char**>(exit_registry_malloc_005a3be5(4u));
            if (crt_environ_006afcc8 == nullptr) {
                return -1;
            }
            crt_environ_006afcc8[0] = nullptr;
            if (crt_wenviron_006afcd0 == nullptr) {
                crt_wenviron_006afcd0 = static_cast<wchar_t**>(exit_registry_malloc_005a3be5(4u));
                if (crt_wenviron_006afcd0 == nullptr) {
                    return -1;
                }
                crt_wenviron_006afcd0[0] = nullptr;
            }
        }
    }

    const int name_len = static_cast<int>(eq - option);
    char** const base_env = crt_environ_006afcc8;
    int ix = crt_findenv_005aa416(option, name_len);
    if (ix >= 0 && base_env[0] != nullptr) {
        if (remove != 0) {
            formatter_crt_free_005a3b9d(base_env[ix]);
            int j = ix;
            while (base_env[j] != nullptr) {
                base_env[j] = base_env[j + 1];
                ++j;
            }
            auto** shrunk = static_cast<char**>(
                exit_registry_reallocate_005a8029(base_env, static_cast<U>(j) * 4u));
            if (shrunk != nullptr) {
                crt_environ_006afcc8 = shrunk;
            }
        } else {
            base_env[ix] = option;
        }
    } else {
        if (remove != 0) {
            return 0;
        }
        if (ix < 0) {
            ix = -ix;
        }
        auto** grown = static_cast<char**>(
            exit_registry_reallocate_005a8029(base_env, static_cast<U>(ix) * 4u + 8u));
        if (grown == nullptr) {
            return -1;
        }
        grown[ix] = option;
        grown[ix + 1] = nullptr;
        crt_environ_006afcc8 = grown;
    }

    if (update_os != 0) {
        const U opt_len = formatter_strlen_005a6730(option);
        auto* copy = static_cast<char*>(exit_registry_malloc_005a3be5(opt_len + 2u));
        if (copy != nullptr) {
            (void)formatter_error_copy_005aa4e0(copy, option);
            char* copy_eq = copy + (eq - option);
            *copy_eq = '\0';
            const char* value = (remove != 0) ? nullptr : (copy_eq + 1);
            (void)::SetEnvironmentVariableA(copy, value);
            formatter_crt_free_005a3b9d(copy);
        }
    }
    return 0;
}

int __cdecl crt_findenv_005aa416(const char* name, int len) {
    char** env = crt_environ_006afcc8;
    while (*env != nullptr) {
        if (crt_mbsnbicoll_005a9a0b(name, *env, static_cast<U>(len)) == 0 &&
            ((*env)[len] == '=' || (*env)[len] == '\0')) {
            return static_cast<int>(env - crt_environ_006afcc8);
        }
        ++env;
    }
    return -static_cast<int>(env - crt_environ_006afcc8);
}

char** __cdecl crt_copy_environ_005aa46e(char** env) {
    if (env == nullptr) {
        return nullptr;
    }
    int count = 0;
    for (char** p = env; *p != nullptr; ++p) {
        ++count;
    }
    auto** copy = static_cast<char**>(exit_registry_malloc_005a3be5(static_cast<U>(count) * 4u + 4u));
    if (copy == nullptr) {
        formatter_fatal_005a2e22(9);
    }
    for (int i = 0; i < count; ++i) {
        copy[i] = crt_strdup_005ad832(env[i]);
    }
    copy[count] = nullptr;
    return copy;
}

char* __cdecl crt_strdup_005ad832(const char* s) {
    if (s == nullptr) {
        return nullptr;
    }
    const U len = formatter_strlen_005a6730(s);
    auto* copy = static_cast<char*>(exit_registry_malloc_005a3be5(len + 1u));
    if (copy == nullptr) {
        return nullptr;
    }
    (void)formatter_error_copy_005aa4e0(copy, s);
    return copy;
}

const char* __cdecl crt_mbschr_005ad79b(const char* s, std::uint32_t c) {
    if (formatter_locale_codepage_006c02ec.multibyte == 0u) {
        return formatter_search_character_005a2780(s, static_cast<int>(c));
    }
    exit_registry_lock_api_005a4ba4(25u);
    const std::uint8_t* p = reinterpret_cast<const std::uint8_t*>(s);
    std::uint16_t ch = 0u;
    for (;;) {
        ch = *p;
        if (ch == 0u) {
            exit_registry_unlock_api_005a4c05(25u);
            return (c == ch) ? reinterpret_cast<const char*>(p) : nullptr;
        }
        if ((formatter_locale_codepage_006c02ec.class_bits[1u + ch] & 0x04u) != 0u) {
            const std::uint8_t lo = p[1];
            ++p;
            if (lo == 0u) {
                exit_registry_unlock_api_005a4c05(25u);
                return nullptr;
            }
            const U pair = (static_cast<U>(ch) << 8) | static_cast<U>(lo);
            if (c == pair) {
                exit_registry_unlock_api_005a4c05(25u);
                return reinterpret_cast<const char*>(p - 1);
            }
        } else {
            if (c == ch) {
                exit_registry_unlock_api_005a4c05(25u);
                return reinterpret_cast<const char*>(p);
            }
        }
        ++p;
    }
}

int __cdecl crt_mbsnbicoll_005a9a0b(const char* s1, const char* s2, std::uint32_t count) {
    if (count == 0u) {
        return 0;
    }
    const int ret = crt_compare_string_a_005ad042(
        formatter_locale_codepage_006c02ec.locale,
        1u,
        s1,
        static_cast<int>(count),
        s2,
        static_cast<int>(count),
        formatter_locale_codepage_006c02ec.codepage);
    if (ret == 0) {
        return 0x7fffffff;
    }
    return ret - 2;
}

int __cdecl crt_compare_string_a_005ad042(
    std::uint32_t locale,
    std::uint32_t cmp_flags,
    const char* s1,
    int count1,
    const char* s2,
    int count2,
    std::uint32_t code_page) {
    static const wchar_t kDummyW[2] = {0, 0};
    static const char kDummyA[2] = {0, 0};

    if (crt_compare_use_mode_006b0028 == 0u) {
        if (::CompareStringW(0u, 0u, kDummyW, 1, kDummyW, 1) != 0) {
            crt_compare_use_mode_006b0028 = 1u;
        } else if (::CompareStringA(0u, 0u, kDummyA, 1, kDummyA, 1) != 0) {
            crt_compare_use_mode_006b0028 = 2u;
        } else {
            return 0;
        }
    }

    if (count1 > 0) {
        count1 = static_cast<int>(formatter_locale_bounded_length_005ad2bf(s1, static_cast<U>(count1)));
    }
    if (count2 > 0) {
        count2 = static_cast<int>(formatter_locale_bounded_length_005ad2bf(s2, static_cast<U>(count2)));
    }

    if (crt_compare_use_mode_006b0028 == 2u) {
        return ::CompareStringA(locale, cmp_flags, s1, count1, s2, count2);
    }
    if (crt_compare_use_mode_006b0028 != 1u) {
        return 0;
    }

    if (code_page == 0u) {
        code_page = formatter_locale_default_codepage_006afd90;
    }

    if (count1 == 0 || count2 == 0) {
        if (count1 == count2) {
            return 2;
        }
        if (count2 > 1) {
            return 1;
        }
        if (count1 > 1) {
            return 3;
        }
        FormatterLocaleCPInfo cpinfo{};
        if (formatter_locale_codepage_info(code_page, &cpinfo) == 0) {
            return 0;
        }
        if (count1 > 0) {
            return is_lone_lead_byte(cpinfo, static_cast<std::uint8_t>(s1[0])) ? 2 : 3;
        }
        if (count2 > 0) {
            return is_lone_lead_byte(cpinfo, static_cast<std::uint8_t>(s2[0])) ? 2 : 1;
        }
    }

    const int wlen1 = formatter_locale_to_wide(code_page, 9u, s1, count1, nullptr, 0);
    if (wlen1 == 0) {
        return 0;
    }
    std::uint16_t* wbuf1 = nullptr;
    __try {
        wbuf1 = static_cast<std::uint16_t*>(_alloca(alloc_stack_bytes(wlen1)));
    } __except (1) {
        wbuf1 = nullptr;
    }
    if (wbuf1 == nullptr) {
        return 0;
    }
    if (formatter_locale_to_wide(code_page, 1u, s1, count1, wbuf1, wlen1) == 0) {
        return 0;
    }

    const int wlen2 = formatter_locale_to_wide(code_page, 9u, s2, count2, nullptr, 0);
    if (wlen2 == 0) {
        return 0;
    }
    std::uint16_t* wbuf2 = nullptr;
    __try {
        wbuf2 = static_cast<std::uint16_t*>(_alloca(alloc_stack_bytes(wlen2)));
    } __except (1) {
        wbuf2 = nullptr;
    }
    if (wbuf2 == nullptr) {
        return 0;
    }
    if (formatter_locale_to_wide(code_page, 1u, s2, count2, wbuf2, wlen2) == 0) {
        return 0;
    }

    return ::CompareStringW(
        locale,
        cmp_flags,
        reinterpret_cast<LPCWSTR>(wbuf1),
        wlen1,
        reinterpret_cast<LPCWSTR>(wbuf2),
        wlen2);
}

} // namespace porsche
