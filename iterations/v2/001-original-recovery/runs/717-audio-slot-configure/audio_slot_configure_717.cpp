// Porsche.exe SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Full original0058f220..0058f286,103B; no new owned cells.
#include "audio_slot_configure_717.hpp"
#include <cstring>
namespace porsche {
std::uint32_t __cdecl audio_group_configure_0058f220(std::uint32_t byte13,
    std::uint32_t word56,std::uint32_t at58,std::uint32_t at5c,
    std::uint32_t at60,std::uint32_t pointer0) {
    if(audio_ds_device_006ad760==0u) return 0u;
    const std::int32_t slot=audio_resource_free_slot_0058f5b0();
    if(slot<=0) return 0u;
    auto* row=audio_resource_slots_006ad7b8+static_cast<std::uint32_t>(slot)*24u;
    row[0x16]=static_cast<std::uint8_t>(byte13);
    row[0x17]=8u;
    const auto word=static_cast<std::uint16_t>(word56);
    std::memcpy(row+0x14,&word,2u);
    std::memcpy(row+8,&at58,4u);
    std::memcpy(row+0xc,&at5c,4u);
    std::memcpy(row+0x10,&at60,4u);
    std::memcpy(row,&pointer0,4u);
    const std::int32_t result=audio_resource_create_slot_0058e500(static_cast<std::uint32_t>(slot));
    if(result<=0) std::memset(row,0,4u);
    return static_cast<std::uint32_t>(result);
}
}
