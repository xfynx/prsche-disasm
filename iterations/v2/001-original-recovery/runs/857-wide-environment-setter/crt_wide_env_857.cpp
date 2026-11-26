// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "crt_wide_env_857.hpp"
#include "crt_shutdown_env_838.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/formatter_crt_runtime.hpp"
#include "porsche/formatter_locale.hpp"

namespace porsche {

wchar_t** crt_winitenv_006afcd4 = nullptr;
CrtSetEnvironmentVariableW857 crt_set_environment_variable_w_api_857 = &::SetEnvironmentVariableW;

wchar_t* __cdecl crt_wcschr_005ad663(const wchar_t* text, std::uint32_t ch) {
    const wchar_t target = static_cast<wchar_t>(ch);
    while (*text != L'\0' && *text != target) {
        ++text;
    }
    return (*text == target) ? const_cast<wchar_t*>(text) : nullptr;
}

std::uint32_t __cdecl crt_wcslen_005ad5de(const wchar_t* text) {
    const wchar_t* cursor = text;
    while (*cursor != L'\0') {
        ++cursor;
    }
    return static_cast<std::uint32_t>(cursor - text);
}

wchar_t* __cdecl crt_wcscpy_005ad5b9(wchar_t* destination, const wchar_t* source) {
    wchar_t* result = destination;
    do {
        *destination++ = *source;
    } while (*source++ != L'\0');
    return result;
}

wchar_t* __cdecl crt_wcsdup_005ad76d(const wchar_t* text) {
    if (text == nullptr) {
        return nullptr;
    }
    auto* copy = static_cast<wchar_t*>(
        exit_registry_malloc_005a3be5((crt_wcslen_005ad5de(text) + 1u) * 2u));
    return copy == nullptr ? nullptr : crt_wcscpy_005ad5b9(copy, text);
}

wchar_t** __cdecl crt_copy_wenviron_005aa228(wchar_t** env) {
    if (env == nullptr) {
        return nullptr;
    }
    std::uint32_t count = 0u;
    while (env[count] != nullptr) {
        ++count;
    }
    auto** copy = static_cast<wchar_t**>(
        exit_registry_malloc_005a3be5(count * 4u + 4u));
    if (copy == nullptr) {
        formatter_fatal_005a2e22(9);
    }
    for (std::uint32_t i = 0u; i < count; ++i) {
        copy[i] = crt_wcsdup_005ad76d(env[i]);
    }
    copy[count] = nullptr;
    return copy;
}

int __cdecl crt_wfindenv_005aa1cc(const wchar_t* name, int length) {
    wchar_t** cursor = crt_wenviron_006afcd0;
    while (*cursor != nullptr) {
        if (crt_wcsnicoll_005ad68c(name, *cursor, static_cast<std::uint32_t>(length)) == 0 &&
            ((*cursor)[length] == L'=' || (*cursor)[length] == L'\0')) {
            return static_cast<int>(cursor - crt_wenviron_006afcd0);
        }
        ++cursor;
    }
    return -static_cast<int>(cursor - crt_wenviron_006afcd0);
}

int __cdecl crt_mbtow_environ_wide_005ad5fb() {
    char** cursor = crt_environ_006afcc8;
    while (*cursor != nullptr) {
        const int count = formatter_locale_to_wide(1u, 0u, *cursor, -1, nullptr, 0);
        if (count == 0) {
            return -1;
        }
        auto* wide = static_cast<wchar_t*>(
            exit_registry_malloc_005a3be5(static_cast<std::uint32_t>(count) * 2u));
        if (wide == nullptr || formatter_locale_to_wide(
                1u, 0u, *cursor, -1, reinterpret_cast<std::uint16_t*>(wide), count) == 0) {
            return -1;
        }
        (void)crt_wsetenv_005aa039(wide, 0);
        ++cursor;
    }
    return 0;
}

int __cdecl crt_wsetenv_005aa039(wchar_t* option, int update_os) {
    if (option == nullptr) {
        return -1;
    }
    wchar_t* equals = crt_wcschr_005ad663(option, L'=');
    if (equals == nullptr || equals == option) {
        return -1;
    }
    const int remove = (equals[1] == L'\0') ? 1 : 0;
    wchar_t** env = crt_wenviron_006afcd0;
    if (env == crt_winitenv_006afcd4) {
        env = crt_copy_wenviron_005aa228(env);
        crt_wenviron_006afcd0 = env;
    }
    if (env == nullptr) {
        if (update_os != 0 && crt_environ_006afcc8 != nullptr) {
            if (crt_mbtow_environ_wide_005ad5fb() != 0) {
                return -1;
            }
        } else {
            if (remove != 0) {
                return 0;
            }
            if (crt_environ_006afcc8 == nullptr) {
                crt_environ_006afcc8 = static_cast<char**>(exit_registry_malloc_005a3be5(4u));
                if (crt_environ_006afcc8 == nullptr) {
                    return -1;
                }
                crt_environ_006afcc8[0] = nullptr;
            }
            if (crt_wenviron_006afcd0 == nullptr) {
                crt_wenviron_006afcd0 = static_cast<wchar_t**>(exit_registry_malloc_005a3be5(4u));
                if (crt_wenviron_006afcd0 == nullptr) {
                    return -1;
                }
                crt_wenviron_006afcd0[0] = nullptr;
            }
        }
    }

    const int name_length = static_cast<int>(equals - option);
    wchar_t** const base = crt_wenviron_006afcd0;
    int index = crt_wfindenv_005aa1cc(option, name_length);
    if (index >= 0 && base[0] != nullptr) {
        if (remove != 0) {
            formatter_crt_free_005a3b9d(base[index]);
            wchar_t** slot = base + index;
            while (*slot != nullptr) {
                ++index;
                *slot = slot[1];
                ++slot;
            }
            auto** shrunk = static_cast<wchar_t**>(
                exit_registry_reallocate_005a8029(base, static_cast<std::uint32_t>(index) * 4u));
            if (shrunk != nullptr) {
                crt_wenviron_006afcd0 = shrunk;
            }
        } else {
            base[index] = option;
        }
    } else {
        if (remove != 0) {
            return 0;
        }
        if (index < 0) {
            index = -index;
        }
        auto** grown = static_cast<wchar_t**>(exit_registry_reallocate_005a8029(
            base, static_cast<std::uint32_t>(index) * 4u + 8u));
        if (grown == nullptr) {
            return -1;
        }
        grown[index] = option;
        grown[index + 1] = nullptr;
        crt_wenviron_006afcd0 = grown;
    }

    if (update_os != 0) {
        auto* copy = static_cast<wchar_t*>(exit_registry_malloc_005a3be5(
            crt_wcslen_005ad5de(option) * 2u + 4u));
        if (copy != nullptr) {
            (void)crt_wcscpy_005ad5b9(copy, option);
            copy[name_length] = L'\0';
            const wchar_t* value = remove != 0 ? nullptr : copy + name_length + 1;
            (void)crt_set_environment_variable_w_api_857(copy, value);
            formatter_crt_free_005a3b9d(copy);
        }
    }
    return 0;
}

} // namespace porsche
