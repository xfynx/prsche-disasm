#pragma once

#include <cstdint>

namespace porsche {

// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Neutral storage views for the globals touched by 004b0d70. The aligned
// DWORDs and byte references share one 0x30-byte object at 006573b8.
extern std::uint32_t& frame_pump_word_006573b8;
extern std::uint32_t& frame_pump_word_006573bc;
extern std::uint32_t& frame_pump_word_006573c0;
extern std::uint32_t& frame_pump_word_006573c4;
extern std::uint32_t& frame_pump_word_006573d0;
extern std::uint32_t& frame_pump_word_006573d4;
extern std::uint32_t& frame_pump_word_006573d8;
extern std::uint8_t& frame_pump_byte_006573e0;
extern std::uint8_t& frame_pump_byte_006573e1;
extern std::uint8_t& frame_pump_byte_006573e2;
extern std::uint8_t& frame_pump_byte_006573e4;
extern std::uint32_t frame_pump_word_00655a08;
std::uint8_t* frame_pump_storage_bytes_006573b8() noexcept;

// The original function is a no-argument stateful pump. Its unnamed callees
// remain explicit boundaries until their own algorithms are recovered.
void __cdecl frame_pump_004b0d70();

std::uint32_t __cdecl frame_pump_boundary_004ab150();
std::uint32_t __cdecl frame_pump_boundary_004ab200();
std::uint32_t __cdecl frame_pump_boundary_005693e0();
void __cdecl frame_pump_boundary_00568f30(std::uint32_t a0,
    std::uint32_t a1, std::uint32_t a2, std::uint32_t a3,
    std::uint32_t a4, std::uint32_t a5);
void __cdecl frame_pump_boundary_005360a0(void* self, std::uint32_t one);
void __cdecl frame_pump_boundary_005363a0(void* self);

} // namespace porsche
