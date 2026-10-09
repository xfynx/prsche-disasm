#include "porsche/application_state.hpp"

#include <stdexcept>
#include <type_traits>

namespace porsche {
static_assert(sizeof(std::uint32_t) == 4);
static_assert(std::is_same<std::uint8_t, unsigned char>::value);

ApplicationStateArena application_state_006573e8;

std::size_t ApplicationStateArena::checked_offset(std::uint32_t va,
    std::size_t length) const {
    if (va < application_state_base_va)
        throw std::out_of_range("application-state VA precedes arena");
    const auto offset = static_cast<std::size_t>(va - application_state_base_va);
    if (offset > application_state_bytes || length > application_state_bytes - offset)
        throw std::out_of_range("application-state view exceeds arena");
    return offset;
}

std::uint32_t& ApplicationStateArena::word(std::uint32_t va) {
    const auto offset = checked_offset(va, sizeof(std::uint32_t));
    if ((offset % alignof(std::uint32_t)) != 0)
        throw std::invalid_argument("application-state word view is unaligned");
    return words_[offset / sizeof(std::uint32_t)];
}

const std::uint32_t& ApplicationStateArena::word(std::uint32_t va) const {
    const auto offset = checked_offset(va, sizeof(std::uint32_t));
    if ((offset % alignof(std::uint32_t)) != 0)
        throw std::invalid_argument("application-state word view is unaligned");
    return words_[offset / sizeof(std::uint32_t)];
}

std::uint8_t& ApplicationStateArena::byte(std::uint32_t va) {
    return bytes()[checked_offset(va, 1)];
}

const std::uint8_t& ApplicationStateArena::byte(std::uint32_t va) const {
    return bytes()[checked_offset(va, 1)];
}

char* ApplicationStateArena::characters(std::uint32_t va) {
    return reinterpret_cast<char*>(bytes() + checked_offset(va, 1));
}

const char* ApplicationStateArena::characters(std::uint32_t va) const {
    return reinterpret_cast<const char*>(bytes() + checked_offset(va, 1));
}

std::uint8_t* ApplicationStateArena::bytes() noexcept {
    return reinterpret_cast<std::uint8_t*>(words_.data());
}

const std::uint8_t* ApplicationStateArena::bytes() const noexcept {
    return reinterpret_cast<const std::uint8_t*>(words_.data());
}

std::array<std::uint32_t, application_state_word_count>&
ApplicationStateArena::words() noexcept {
    return words_;
}

const std::array<std::uint32_t, application_state_word_count>&
ApplicationStateArena::words() const noexcept {
    return words_;
}

void application_state_fill_0053c290(ApplicationStateArena& state,
    std::uint32_t target_va, std::uint32_t value, std::uint32_t count) {
    if (target_va < application_state_base_va)
        throw std::out_of_range("application-state fill precedes arena");
    const auto first = static_cast<std::size_t>(target_va - application_state_base_va);
    if (first > application_state_bytes || count > application_state_bytes - first)
        throw std::out_of_range("application-state fill exceeds arena");
    auto* destination = state.bytes() + first;
    auto va=target_va;
    auto remaining=static_cast<std::size_t>(count);
    const auto store_low=[&](std::size_t bytes) {
        for(std::size_t i=0;i<bytes;++i)
            destination[static_cast<std::size_t>(va-target_va)+i]=
                static_cast<std::uint8_t>((value>>(8u*static_cast<unsigned>(i)))&0xffu);
        va+=static_cast<std::uint32_t>(bytes);
        remaining-=bytes;
    };
    if((va&1u)!=0 && remaining>=1)store_low(1);
    if((va&2u)!=0 && remaining>=2)store_low(2);
    if((va&4u)!=0 && remaining>=4)store_low(4);
    while(remaining>=4)store_low(4);
    if(remaining>=2)store_low(2);
    if(remaining>=1)store_low(1);
}

} // namespace porsche
