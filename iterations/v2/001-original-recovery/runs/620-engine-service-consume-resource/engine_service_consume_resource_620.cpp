// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00490420..004904c9, 170 bytes, sha256 2c42d1267e04151a57553731059aec27f6795d7dac1434c38a288e773ca31e7e.
// Original 0048cb50..0048ccb8, 361 bytes, sha256 79dedd42e351df5b312758d6828d7e9bf7cf5c3792f0e375cce92dd1d8f2d1f9.
#include "engine_service_consume_resource_620.hpp"

#include <cstring>

namespace porsche {

const char data_packet_tag_005d072c[12] = "CDataPacket";

namespace {

std::int32_t read_i32(const std::uint8_t* base, std::size_t offset) {
    std::int32_t value = 0;
    std::memcpy(&value, base + offset, sizeof value);
    return value;
}

void write_i32(std::uint8_t* base, std::size_t offset, std::int32_t value) {
    std::memcpy(base + offset, &value, sizeof value);
}

bool is_network_ready(const std::uint8_t* net) {
    return net != nullptr && read_i32(net, 0x08u) != 0 && net[0xbfu] == 0u;
}

bool is_session_active(const std::uint8_t* net) {
    return is_network_ready(net) && net[0xbeu] != 0u && read_i32(net, 0xdcu) >= 0;
}

bool has_packet_for_resource(const void* list_ptr, std::uint16_t resource16) {
    const auto* const head = *reinterpret_cast<const std::uint32_t* const*>(list_ptr);
    for (const auto* node = reinterpret_cast<const std::uint32_t*>(head[0]);
         node != head;
         node = reinterpret_cast<const std::uint32_t*>(node[0])) {
        const auto* const pkt = reinterpret_cast<const std::uint8_t*>(node[2]);
        std::uint16_t pkt_tag = 0u;
        std::memcpy(&pkt_tag, pkt, sizeof pkt_tag);
        if (pkt_tag == resource16) {
            return node[2] != 0u;
        }
    }
    return false;
}

void* create_data_packet(std::uint16_t resource16, void* value, std::int32_t count) {
    auto* const packet = static_cast<std::uint8_t*>(render_allocate_0059ef90(0x10u));
    if (packet == nullptr) {
        return nullptr;
    }
    std::memcpy(packet, &resource16, sizeof resource16);
    void* const buf = allocate_00531ca0(data_packet_tag_005d072c, count, 0u);
    std::memcpy(packet + 0x04u, &buf, sizeof buf);
    write_i32(packet, 0x08u, count);
    write_i32(packet, 0x0cu, 0);
    if (value != nullptr) {
        heap_copy_dispatch_005323e0(buf, value, static_cast<std::uint32_t>(count));
    }
    return packet;
}

void insert_packet_at_tail(void* list_ptr, void* packet) {
    std::uint32_t packet_word = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(packet));
    std::uint32_t end_iter = 0u;
    const std::uint32_t* const end_ptr = network_member_end_00529050(list_ptr, nullptr, &end_iter);
    std::uint32_t before_iter = 0u;
    (void)network_member_copy_0050e140(&before_iter, nullptr, end_ptr);
    std::uint32_t insert_out = 0u;
    (void)network_member_insert_004937f0(list_ptr, nullptr, &insert_out, before_iter, &packet_word);
}

} // namespace

void __fastcall network_item_add_packet_00490420(
    void* item, void* unused_edx,
    std::uint32_t resource, void* value, std::int32_t count) {
    (void)unused_edx;
    void* const list_ptr = static_cast<std::uint8_t*>(item) + 0x5cu;
    const auto resource16 = static_cast<std::uint16_t>(resource);
    if (has_packet_for_resource(list_ptr, resource16)) {
        return;
    }
    void* const packet = create_data_packet(resource16, value, count);
    insert_packet_at_tail(list_ptr, packet);
}

void __cdecl engine_service_consume_resource_0048cb50(
    std::uint32_t resource, void* value, std::int32_t count) {
    auto* net = static_cast<std::uint8_t*>(startup_network_00628c70);
    if (!is_session_active(net) && count > 0) {
        return;
    }

    std::int32_t active_id = -2;
    if (is_network_ready(net)) {
        active_id = read_i32(net, 0xdcu);
    }

    if (is_network_ready(net)) {
        const auto* const head260 = *reinterpret_cast<const std::uint32_t* const*>(net + 0x260u);
        for (const auto* node = reinterpret_cast<const std::uint32_t*>(head260[0]);
             node != head260;
             node = reinterpret_cast<const std::uint32_t*>(node[0])) {
            auto* const item = reinterpret_cast<std::uint8_t*>(node[2]);
            if (read_i32(item, 0x40u) == active_id) {
                if (item != nullptr) {
                    const auto res16 = static_cast<std::int16_t>(resource);
                    if (network_item_data_004903f0(item, nullptr, res16) == nullptr) {
                        network_item_add_packet_00490420(item, nullptr, resource, value, count);
                        auto* const found = static_cast<std::uint8_t*>(
                            network_item_data_004903f0(item, nullptr, res16));
                        write_i32(found, 0x0cu, read_i32(found, 0x0cu) + count);
                    }
                    net = static_cast<std::uint8_t*>(startup_network_00628c70);
                }
                break;
            }
        }
    }

    const auto resource16 = static_cast<std::uint16_t>(resource);
    if (has_packet_for_resource(net + 0x264u, resource16)) {
        return;
    }
    void* const packet = create_data_packet(resource16, value, count);
    net = static_cast<std::uint8_t*>(startup_network_00628c70);
    insert_packet_at_tail(net + 0x264u, packet);
}

} // namespace porsche
