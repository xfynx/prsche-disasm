#include "porsche/formatter_runtime.hpp"

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

namespace {
struct Pair { const char* name; std::uint64_t dividend, divisor; };
constexpr Pair kCases[] = {
    {"zero_dividend",0,1}, {"identity",0xffffffffffffffffull,1},
    {"small_divisor",0xfedcba9876543210ull,10},
    {"high_quotient_word",0xfedcba9876543210ull,0x10000ull},
    {"near_32_boundary",0x00000001ffffffffull,0xffffffffull},
    {"divisor_high_min",0xffffffffffffffffull,0x100000000ull},
    {"divisor_high_low_one",0xfedcba9876543210ull,0x100000001ull},
    {"divisor_high_mid",0xffffffffffffffffull,0x7fffffff12345678ull},
    {"divisor_high_top",0xffffffffffffffffull,0x8000000000000000ull},
    {"dividend_below_divisor",0x00000001ffffffffull,0x100000000ull},
    {"exact_high_divisor",0x8000000000000000ull,0x4000000000000000ull},
    {"high_word_one",0x0000000100000000ull,0x00000000ffffffffull},
    {"zero_remainder",0x8000000000000000ull,0x100000000ull},
    {"quotient_round_down",0xffffffffffffffffull,0x80000000ffffffffull},
    {"normalize_overestimate_correct",0x0000000200000001ull,0x0000000100000001ull},
    {"normalize_overestimate_remainder",0x0000000400000003ull,0x0000000100000001ull},
};

std::string hex64(std::uint64_t value) {
    char out[17]{};
    static constexpr char digits[] = "0123456789abcdef";
    for (int i=15;i>=0;--i) { out[i]=digits[value&15]; value>>=4; }
    return out;
}

void integers() {
    for (const auto& c : kCases) {
        std::cout << "{\"kind\":\"integer\",\"name\":\"" << c.name
                  << "\",\"dividend\":\"" << hex64(c.dividend)
                  << "\",\"divisor\":\"" << hex64(c.divisor)
                  << "\",\"quotient\":\""
                  << hex64(porsche::formatter_unsigned_divide_005a67b0(c.dividend,c.divisor))
                  << "\",\"remainder\":\""
                  << hex64(porsche::formatter_unsigned_remainder_005a6820(c.dividend,c.divisor))
                  << "\"}\n";
    }
}

void lengths() {
    constexpr std::uint32_t sizes[] = {0,1,2,3,4,5,7,8,15,16,31,32,63,255};
    for (std::uint32_t align=0;align<4;++align) {
        for (const auto length : sizes) {
            alignas(4) unsigned char storage[320]{};
            auto* text = reinterpret_cast<char*>(storage+align);
            for (std::uint32_t i=0;i<length;++i)
                text[i]=static_cast<char>((i*73u+align*19u)%255u+1u);
            text[length]='\0';
            std::cout << "{\"kind\":\"strlen\",\"name\":\"a" << align << "_n" << length
                      << "\",\"align\":" << align << ",\"length\":" << length
                      << ",\"result\":" << porsche::formatter_strlen_005a6730(text)
                      << "}\n";
        }
    }
}
} // namespace

int main() { std::cout.setf(std::ios::unitbuf); integers(); lengths(); }
