#pragma once
#include <cstdint>
namespace porsche { namespace nibble512 {
// Opaque U32-address transport preserves cross-object aliases at/O2.
std::uint32_t read32(std::uint32_t address);
std::uint32_t read8(std::uint32_t address);
void write32(std::uint32_t address,std::uint32_t value);
} }
