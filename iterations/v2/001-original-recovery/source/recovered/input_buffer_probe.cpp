#include "porsche/input_buffer.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>

namespace {
using namespace porsche;
std::uint32_t status, value;
const char* trace;
InputBufferVtable table{};
InputBufferDevice device{&table};
void dump(const void* address, std::size_t size) {
    const auto* bytes = static_cast<const std::uint8_t*>(address);
    for (std::size_t i = 0; i < size; ++i)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << unsigned(bytes[i]);
}
std::uint32_t __stdcall property(void*, std::uint32_t id, InputBufferProperty* data) {
    trace = "P";
    if (id != 2 || data->size_00 != 0x14 || data->header_size_04 != 0x10 ||
        data->object_08 || data->how_0c) trace = "E";
    data->value_10 = value;
    return status;
}
std::uint32_t __stdcall capabilities(void*, void* data) {
    trace = *static_cast<std::uint32_t*>(data) == 0x244 ? "C" : "E";
    return status;
}
}
namespace porsche {
std::uint32_t __cdecl input_caps_success_unrecovered_0056fdf9(
    InputBufferDevice*, void*, const void*) { trace = "U"; return 0xffffffffu; }
}
int main() {
    table.get_property_14 = property;
    table.get_capabilities_3c = capabilities;
    unsigned kind;
    while (std::cin >> kind >> status >> value) {
        trace = "-";
        std::uint8_t output[0x21c];
        std::memset(output, 0xa5, sizeof(output));
        const auto result = kind == 0 ? input_property_mode8_0056fff0(&device)
                                      : input_caps_0056fdb0(&device, output);
        std::cout << std::dec << result << ' ' << trace << ' ';
        dump(output, sizeof(output));
        std::cout << '\n';
    }
}
