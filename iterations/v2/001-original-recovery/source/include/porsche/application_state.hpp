#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace porsche {

inline constexpr std::uint32_t application_state_base_va = 0x006573e8u;
inline constexpr std::size_t application_state_bytes = 0x3e24u;
inline constexpr std::size_t application_state_word_count =
    application_state_bytes / sizeof(std::uint32_t);
static_assert(application_state_bytes % sizeof(std::uint32_t) == 0);

// A single C++ object owns the recovered BSS span. Aligned word views refer to
// actual uint32_t elements; byte and char views access those elements' object
// representation, which is permitted by the C++ aliasing rules.
class ApplicationStateArena {
public:
    std::uint32_t& word(std::uint32_t va);
    const std::uint32_t& word(std::uint32_t va) const;
    std::uint8_t& byte(std::uint32_t va);
    const std::uint8_t& byte(std::uint32_t va) const;
    char* characters(std::uint32_t va);
    const char* characters(std::uint32_t va) const;
    std::uint8_t* bytes() noexcept;
    const std::uint8_t* bytes() const noexcept;
    std::array<std::uint32_t, application_state_word_count>& words() noexcept;
    const std::array<std::uint32_t, application_state_word_count>& words() const noexcept;

    // Exposed only so the canonical reference owner can use constant-address
    // initializers. This avoids startup-order reads when generated FE tables
    // take addresses of their global references.
    // The containing static object is zero-initialized before dynamic global
    // reference initialization; keeping this member trivial avoids a second
    // initialization-order dependency for aliases in application_globals.cpp.
    std::array<std::uint32_t, application_state_word_count> words_;

private:
    std::size_t checked_offset(std::uint32_t va, std::size_t length) const;
};

// Canonical arena storage shared by FE, application-main, and renderer aliases.
extern ApplicationStateArena application_state_006573e8;

// Faithful repeated-dword fill semantics of the verified 0053c290 dispatch
// family for this arena. Full cells repeat all four little-endian bytes of
// value; unaligned prefixes and tails use the corresponding low byte/word.
// It writes exactly count bytes and deliberately uses no host memset.
void application_state_fill_0053c290(ApplicationStateArena& state,
    std::uint32_t target_va, std::uint32_t value, std::uint32_t count);

// Boundedness of the string stored at 0x00657a84 is unknown. This returns a
// char view into the arena; callers must follow the original NUL-terminated
// access pattern and must not assume a capacity from this API.
char* application_main_config_string_00657a84() noexcept;

} // namespace porsche
