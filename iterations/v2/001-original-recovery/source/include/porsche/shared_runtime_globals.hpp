#pragma once

#include <cstdint>
#include <cstring>

namespace porsche {

// One native DWORD for each recovered original address. The public names are
// typed views used by their existing consumers; all views alias these words.
extern std::uint32_t shared_runtime_word_005deb1c;
extern std::uint32_t& copy_flag_005deb1c;
extern std::uint32_t& render_display_clock_005deb1c;

extern std::uint32_t shared_runtime_word_005deb74;
extern std::uint32_t& application_diagnostic_source_005deb74;
const char* diagnostic_file_005deb74() noexcept;
void diagnostic_file_005deb74_set(const char* value) noexcept;
extern std::uint32_t& render_error_file_005deb74;
extern std::uint32_t& class_error_file_005deb74;

extern std::uint32_t shared_runtime_word_005deb78;
extern std::uint32_t& application_diagnostic_line_005deb78;
extern std::uint32_t& diagnostic_line_005deb78;
extern std::uint32_t& render_error_line_005deb78;
extern std::uint32_t& class_error_line_005deb78;

} // namespace porsche

// Standalone differential probes compile a fixture main together with one or
// more recovered TUs. This opt-in fixture block supplies the same alias graph
// without pulling in the production owner TU. The dedicated Run080 probe
// instead links shared_runtime_globals.cpp directly.
#ifdef PORSCHE_DEFINE_SHARED_RUNTIME_GLOBALS_FIXTURE
static_assert(sizeof(const char*) == sizeof(std::uint32_t),
    "original diagnostic pointer alias requires the x86 fixture ABI");
namespace porsche {
std::uint32_t shared_runtime_word_005deb1c{};
std::uint32_t& copy_flag_005deb1c = shared_runtime_word_005deb1c;
std::uint32_t& render_display_clock_005deb1c = shared_runtime_word_005deb1c;

std::uint32_t shared_runtime_word_005deb74{};
std::uint32_t& application_diagnostic_source_005deb74 = shared_runtime_word_005deb74;
const char* diagnostic_file_005deb74() noexcept {
    std::uint32_t bits{};
    std::memcpy(&bits, &shared_runtime_word_005deb74, sizeof(bits));
    return reinterpret_cast<const char*>(static_cast<std::uintptr_t>(bits));
}
void diagnostic_file_005deb74_set(const char* value) noexcept {
    const auto bits = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
    std::memcpy(&shared_runtime_word_005deb74, &bits, sizeof(bits));
}
std::uint32_t& render_error_file_005deb74 = shared_runtime_word_005deb74;
std::uint32_t& class_error_file_005deb74 = shared_runtime_word_005deb74;

std::uint32_t shared_runtime_word_005deb78{};
std::uint32_t& application_diagnostic_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& diagnostic_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& render_error_line_005deb78 = shared_runtime_word_005deb78;
std::uint32_t& class_error_line_005deb78 = shared_runtime_word_005deb78;
} // namespace porsche
#endif
