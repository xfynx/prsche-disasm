// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Complete bodies 005a38c7..005a38e7 and 005a38e8..005a397b.
#include "crt_putenv_854.hpp"

#include "crt_shutdown_env_838.hpp"
#include "porsche/exit_registry.hpp"
#include "porsche/formatter_bootstrap.hpp"
#include "porsche/formatter_locale.hpp"
#include "porsche/formatter_runtime.hpp"

namespace porsche {

int __cdecl crt_putenv_005a38c7(const char* entry) {
    exit_registry_lock_api_005a4ba4(12u);
    const int result = crt_putenv_inner_005a38e8(entry);
    exit_registry_unlock_api_005a4c05(12u);
    return result;
}

int __cdecl crt_putenv_inner_005a38e8(const char* entry) {
    if (crt_env_initialized_006c1528 == 0u) {
        return -1;
    }

    const std::uint32_t length = formatter_strlen_005a6730(entry);
    auto* narrow = static_cast<char*>(exit_registry_malloc_005a3be5(length + 1u));
    if (narrow == nullptr) {
        return -1;
    }
    (void)formatter_error_copy_005aa4e0(narrow, entry);
    if (crt_setenv_005aa28f(narrow, 1) != 0) {
        return -1;
    }

    if (crt_wenviron_006afcd0 == nullptr) {
        return 0;
    }
    const int wide_count = formatter_locale_to_wide(1u, 0u, entry, -1, nullptr, 0);
    if (wide_count == 0) {
        return -1;
    }
    auto* wide = static_cast<wchar_t*>(
        exit_registry_malloc_005a3be5(static_cast<std::uint32_t>(wide_count) * 2u));
    if (wide == nullptr) {
        return -1;
    }
    if (formatter_locale_to_wide(
            1u, 0u, entry, -1, reinterpret_cast<std::uint16_t*>(wide), wide_count) == 0) {
        return -1;
    }
    return (crt_wsetenv_005aa039(wide, 0) == 0) ? 0 : -1;
}

} // namespace porsche
