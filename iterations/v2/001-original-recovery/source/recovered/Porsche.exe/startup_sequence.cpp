#include "porsche/startup_sequence.hpp"

#include "porsche/game_setup.hpp"
#include "porsche/startup_services.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>

namespace porsche {

std::uint32_t startup_sequence_word_00606ac0=0;
std::uint32_t startup_sequence_word_00606ac4=0;

namespace {
std::uint32_t read_u32(const void* base,std::size_t offset) {
    std::uint32_t value{};
    std::memcpy(&value,static_cast<const std::uint8_t*>(base)+offset,sizeof(value));
    return value;
}
}

void __cdecl startup_sequence_004b67b0() {
    // MOV ECX,[0069ed0c]+4; CALL 00536080. The explicit fastcall adapter
    // places the observed receiver in ECX; EDX is unused by the callee body.
    auto* const service=static_cast<std::uint8_t*>(game_setup_movie_service_0069ed0c);
    const auto receiver_va=read_u32(service,4);
    auto* const receiver=reinterpret_cast<void*>(static_cast<std::uintptr_t>(receiver_va));
    startup_sequence_service_00536080(receiver,nullptr);
    startup_sequence_call_0044dfb0();
    startup_sequence_call_0056a490();
    startup_sequence_call_00516950();
    startup_sequence_call_00413cf0();
    startup_sequence_call_00427a60();
    splash_progress_004a4a70(1);
    splash_progress_004a4a70(2);
    startup_sequence_call_00516950();

    startup_sequence_word_00606ac0=0;
    startup_sequence_word_00606ac4=0;

    startup_sequence_call_004a4700();
    startup_sequence_call_004b0d70();
    startup_sequence_call_004affd0();
    startup_sequence_call_004b0d70();
    startup_sequence_call_004b0d70();
    startup_sequence_call_00516950();
    startup_sequence_call_004b0d70();
    startup_sequence_call_00468fb0();
    splash_progress_004a4a70(4);
    splash_progress_004a4a70(5);
    startup_sequence_call_004b0d70();
    startup_sequence_call_00471b70();
    splash_progress_004a4a70(6);
    startup_sequence_call_004b0d70();
    startup_sequence_call_004a8cd0();
    startup_sequence_call_004b0d70();
    splash_progress_004a4a70(7);
    startup_sequence_call_004b0d70();
    startup_sequence_call_00414db0();
    startup_sequence_call_004b0d70();
    startup_sequence_call_004690d0();
    startup_sequence_call_004b0d70();
    startup_sequence_call_00434a90();
    startup_sequence_call_00424460();
    startup_sequence_call_004b0d70();
    startup_sequence_call_00415dc0();
    startup_sequence_call_004b0fa0();
    startup_sequence_call_004121b0();
    startup_sequence_call_004b0fa0();
    const auto report_value=startup_sequence_value_00569a90();
    startup_sequence_report_005a177b(0x005d6e3cu,report_value);

    auto* const network=static_cast<const std::uint8_t*>(startup_network_00628c70);
    if(network!=nullptr && read_u32(network,8)!=0 && network[0xbf]==0)
        startup_sequence_call_0048cdf0();

    splash_progress_004a4a70(10);
    startup_sequence_call_004b0fa0();
    startup_sequence_text_0044df10(0x00657444u);
    startup_sequence_transfer_004691c0();
}

} // namespace porsche
