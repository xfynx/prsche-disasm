#include "porsche/shared_runtime_globals.hpp"

#include <cstring>

namespace porsche {
static_assert(sizeof(const char*) == sizeof(std::uint32_t),
    "original diagnostic pointer alias requires the x86 ABI");

std::uint32_t shared_runtime_word_005deb1c = 0;
std::uint32_t& copy_flag_005deb1c = shared_runtime_word_005deb1c;
std::uint32_t& render_display_clock_005deb1c = shared_runtime_word_005deb1c;

std::uint32_t shared_runtime_word_005deb74 = 0;
std::uint32_t& application_diagnostic_source_005deb74 = shared_runtime_word_005deb74;
std::uint32_t& render_error_file_005deb74 = shared_runtime_word_005deb74;
std::uint32_t& class_error_file_005deb74 = shared_runtime_word_005deb74;

const char* diagnostic_file_005deb74() noexcept {
    std::uint32_t bits{};
    std::memcpy(&bits, &shared_runtime_word_005deb74, sizeof(bits));
    return reinterpret_cast<const char*>(static_cast<std::uintptr_t>(bits));
}

void diagnostic_file_005deb74_set(const char* value) noexcept {
    const auto bits = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
    std::memcpy(&shared_runtime_word_005deb74, &bits, sizeof(bits));
}

std::uint32_t shared_runtime_word_005deb78 = 0;
std::uint32_t& application_diagnostic_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& diagnostic_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& render_error_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& class_error_line_005deb78 = shared_runtime_word_005deb78;
} // namespace porsche
