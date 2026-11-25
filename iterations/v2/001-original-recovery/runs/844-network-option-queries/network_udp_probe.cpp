#include "network_udp_probe.hpp"
#include "porsche/formatter_text.hpp"

namespace porsche {
const char network_udp_excluded_prefixes_005c11d8[12] = {
    '0', '.', 0, 0, '1', '2', '7', '.', 0, 0, 0, 0,
};

std::uint32_t __cdecl network_udp_start_005839d0() {
    std::uint8_t socket_data[0x190];
    if (network_wsa_startup_005894e6(0x101, socket_data) != 0)
        return 0;

    std::uint32_t available = 0;
    if (network_read_local_address_00583740(network_udp_local_address_006b4a80) != 0 &&
        formatter_text_compare_n_005a2210(network_udp_local_address_006b4a80,
                                        network_udp_excluded_prefixes_005c11d8 + 4, 4) != 0 &&
        formatter_text_compare_n_005a2210(network_udp_local_address_006b4a80,
                                        network_udp_excluded_prefixes_005c11d8, 2) != 0) {
        const auto socket = network_wsa_socket_00587bd8(2, 1, 0);
        if (socket != 0xffffffffu) {
            available = 1;
            network_wsa_close_socket_00587bc0(socket);
        }
    }
    network_wsa_cleanup_005894e0();
    return available;
}
}
