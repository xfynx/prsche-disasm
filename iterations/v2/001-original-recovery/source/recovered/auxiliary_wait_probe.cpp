#include "porsche/auxiliary_wait.hpp"

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

static_assert(sizeof(void*) == 4, "Run 122 is an original-x86 ABI fixture");

namespace {
std::vector<std::uint32_t> signaled;
std::uint32_t pointer_bits(const void* value) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(value));
}
}

namespace porsche {
std::uint32_t __cdecl file_event_signal_0055fb30(void* event) {
    signaled.push_back(pointer_bits(event));
    return 1;
}
}

int main() {
    std::uint32_t handle_bits = 0;
    while (std::cin >> std::hex >> handle_bits) {
        porsche::auxiliary_wait_event_0069e5dc =
            reinterpret_cast<void*>(static_cast<std::uintptr_t>(handle_bits));
        signaled.clear();
        porsche::auxiliary_wait_signal_0053c270();
        std::cout << std::hex << pointer_bits(porsche::auxiliary_wait_event_0069e5dc)
                  << ' ' << signaled.size();
        for (const std::uint32_t handle : signaled)
            std::cout << ' ' << handle;
        std::cout << std::endl;
    }
    return 0;
}
