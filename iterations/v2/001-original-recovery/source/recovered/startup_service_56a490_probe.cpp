#include "porsche/startup_service_56a490.hpp"

#include <cstdint>
#include <iostream>
#include <vector>

namespace {
std::uint32_t free_result = 0;
std::vector<std::uint32_t> freed;
}

namespace porsche {
std::uint32_t __cdecl free_00531f90(void* value) {
    freed.push_back(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value)));
    return free_result;
}
}

int main() {
    std::uint32_t pointer_bits, word118, word11c, result;
    while (std::cin >> pointer_bits >> word118 >> word11c >> result) {
        porsche::startup_service_pointer_006af114 = reinterpret_cast<void*>(
            static_cast<std::uintptr_t>(pointer_bits));
        porsche::startup_service_word_006af118 = word118;
        porsche::startup_service_word_006af11c = word11c;
        free_result = result;
        freed.clear();

        porsche::startup_service_release_0056a490();

        const auto pointer_after = static_cast<std::uint32_t>(
            reinterpret_cast<std::uintptr_t>(porsche::startup_service_pointer_006af114));
        std::cout << "{\"state\":[" << pointer_after << ','
                  << porsche::startup_service_word_006af118 << ','
                  << porsche::startup_service_word_006af11c
                  << "],\"free\":[";
        for (std::size_t i=0;i<freed.size();++i) {
            if (i) std::cout << ',';
            std::cout << freed[i];
        }
        std::cout << "]}\n";
    }
    return std::cin.eof()?0:2;
}
