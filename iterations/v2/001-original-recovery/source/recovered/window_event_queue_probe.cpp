#include "porsche/window_event_queue.hpp"
#include "porsche/window_messages.hpp"
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace porsche {
void* window_input_lock_0069e564{};
std::uint32_t window_input_capacity_0069e560{}, window_input_read_0069e0d8{},
              window_input_write_0069e568{};
std::string events;

void __cdecl heap_enter_005322b0(void* lock) {
    std::ostringstream s; s << "E" << std::hex << reinterpret_cast<std::uintptr_t>(lock);
    if (!events.empty()) events += ','; events += s.str();
}
void __cdecl heap_leave_005322c0(void* lock) {
    std::ostringstream s; s << "L" << std::hex << reinterpret_cast<std::uintptr_t>(lock);
    if (!events.empty()) events += ','; events += s.str();
}
std::uint32_t __cdecl window_event_translate_00560080(std::uint32_t payload,
                                                       std::uint32_t type) {
    std::ostringstream s; s << "T" << std::hex << payload << ':' << type;
    if (!events.empty()) events += ','; events += s.str();
    return (payload ^ (type * 13u) ^ 0x39u) & 0xffu;
}
}

int main() {
    using namespace porsche;
    unsigned op, capacity, read, write, lock, value16, payload, type;
    std::string ring;
    while (std::cin >> op >> capacity >> read >> write >> std::hex >> lock
                    >> value16 >> payload >> type >> ring >> std::dec) {
        if (ring.size() != 256) return 2;
        window_input_capacity_0069e560 = capacity;
        window_input_read_0069e0d8 = read;
        window_input_write_0069e568 = write;
        window_input_lock_0069e564 = reinterpret_cast<void*>(static_cast<std::uintptr_t>(lock));
        events.clear();
        for (std::size_t i=0; i<128; ++i) {
            const auto byte = std::stoul(ring.substr(i*2,2),nullptr,16);
            window_event_ring_0069e4e0[i] = static_cast<std::uint8_t>(byte);
        }
        std::uint32_t result = 0;
        if (op == 0)
            (void)window_message_enqueue_0053a9e0(value16,payload,type);
        else
            result = window_event_dequeue_0053aa60();
        std::cout << result << ' ' << window_input_read_0069e0d8 << ' '
                  << window_input_write_0069e568 << ' ' << events << ' ';
        for (const auto byte : window_event_ring_0069e4e0)
            std::cout << std::hex << std::setw(2) << std::setfill('0')
                      << static_cast<unsigned>(byte);
        std::cout << std::dec << '\n';
    }
}
