// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_services_next.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/startup_sequence.hpp"
#include "../691-app-sim-teardown-audio-unload/application_sim_teardown_691.hpp"

namespace porsche {

struct AudioQueueRequest00656b00 {
    std::uint32_t raw_00;
    std::int32_t handle_04;
    std::uint32_t raw_08;
    std::uint32_t raw_0c;
    std::uint32_t raw_10;
    std::int32_t id_14;
    std::int32_t index_18;
    std::uint8_t flag_1c;
    std::uint8_t flag_1d;
    std::int8_t bank_1e;
    std::uint8_t flag_1f;
};
static_assert(sizeof(AudioQueueRequest00656b00) == 0x20, "queue request size 0x20");

struct AudioQueueBank00657308 {
    std::uint32_t tag_00;
    std::uint32_t active_04;
    const std::uint32_t* entries_08;
    std::int32_t max_index_0c;
};
static_assert(sizeof(AudioQueueBank00657308) == 0x10, "queue bank size 0x10");

// Loader-zero .bss queue state owned by Run790 (2140 bytes total).
extern std::uint32_t audio_queue_head_00656ae4;
extern std::uint32_t audio_queue_read_pos_00656af4;
extern AudioQueueRequest00656b00 audio_queue_ring_00656b00[64];
extern std::uint32_t audio_queue_tail_00657300;
extern AudioQueueBank00657308 audio_queue_banks_00657308[5];

// Original entry 004a83e0..004a8481 (162 bytes).
std::int32_t __cdecl audio_record_evict_slot_004a83e0(std::int32_t threshold);

// Original entry 004af8d0..004af8f7 (40 bytes).
void __cdecl audio_queue_request_init_004af8d0(AudioQueueRequest00656b00* req);

// Original entry 004b05a0..004b0670 (209 bytes).
std::int32_t __cdecl audio_queue_enqueue_004b05a0(AudioQueueRequest00656b00* req);

// Original entry 004b0cf0..004b0d2a (59 bytes).
std::int32_t __cdecl audio_queue_count_active_004b0cf0();

// Original entry 004a8570..004a865e (239 bytes); declared in application_sim_teardown_691.hpp.
std::int32_t __cdecl application_sim_boundary_004a8570(std::int32_t first,
                                                       std::int32_t second,
                                                       std::int32_t flag);

} // namespace porsche
