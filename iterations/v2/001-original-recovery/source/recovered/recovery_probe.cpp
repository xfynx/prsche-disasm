// Console verification boundary. This is not a game entry point.
#include "porsche/startup.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::string captured;
std::string hex(const char* data, std::size_t size) {
    static const char digits[] = "0123456789abcdef";
    std::string out;
    for (std::size_t i = 0; i < size; ++i) {
        const auto b = static_cast<unsigned char>(data[i]);
        out += digits[b >> 4]; out += digits[b & 15];
    }
    return out;
}
}
namespace porsche {
// A recording substitute exists only in this verification file. It is never
// presented as recovered 0x004b6a50 or linked into a game executable.
std::int32_t __cdecl app_main_004b6a50(std::int32_t argc, char** argv) {
    std::ostringstream out;
    out << "{\"argc\":" << argc << ",\"argv\":[";
    for (std::int32_t i = 0; i < argc; ++i) {
        if (i) out << ',';
        out << '"' << hex(argv[i], std::char_traits<char>::length(argv[i])) << '"';
    }
    out << ']';
    captured = out.str();
    return 0x12345678;
}
}
int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        const bool is_null = line == "null";
        std::vector<char> input;
        if (!is_null) {
            if (line.size() % 2) return 2;
            for (std::size_t i = 0; i < line.size(); i += 2) {
                const auto pair = line.substr(i, 2);
                std::size_t used = 0;
                const auto value = std::stoul(pair, &used, 16);
                if (used != 2) return 2;
                input.push_back(static_cast<char>(value));
            }
        }
        input.push_back('\0');
        const auto result = porsche::win_main_004b6710(
            nullptr, nullptr, is_null ? nullptr : input.data(), 10);
        std::cout << captured << ",\"buffer\":\""
                  << (is_null ? std::string() : hex(input.data(), input.size()))
                  << "\",\"result\":" << result << "}\n";
    }
}
