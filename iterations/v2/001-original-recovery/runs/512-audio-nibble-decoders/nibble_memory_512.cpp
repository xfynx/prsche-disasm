#include "nibble_memory_512.hpp"
#include <cstring>
namespace porsche { namespace nibble512 {
__declspec(noinline) std::uint32_t read32(std::uint32_t p){std::uint32_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),4);return v;}
__declspec(noinline) std::uint32_t read8(std::uint32_t p){std::uint8_t v;std::memcpy(&v,reinterpret_cast<const void*>(p),1);return v;}
__declspec(noinline) void write32(std::uint32_t p,std::uint32_t v){std::memcpy(reinterpret_cast<void*>(p),&v,4);}
} }
