// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_services_next.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/files.hpp"
#include "porsche/startup_sequence.hpp"
#include "porsche/window_runtime.hpp"
#include "../434-audio-canonical-bindings/audio_canonical_434.hpp"
#include "../608-frame-audio-channel-volume/frame_audio_channel_volume_608.hpp"
#include "../691-app-sim-teardown-audio-unload/application_sim_teardown_691.hpp"
#include "../703-audio-finalize-period-callback/audio_finalize_period_703.hpp"
#include "../790-sim-audio-queue-and-record-evict/sim_audio_queue_790.hpp"

namespace porsche {

// Newly owned .data string literals (38 bytes total, pinned byte-for-byte vs Porsche.exe).
extern const char audio_speech_fail_text_005d19dc[30];
extern const char audio_sfxbank_tag_005d19fc[8];

// Loader-zero .bss audio pool/queue state owned by Run794 (43 bytes total).
extern std::uint32_t audio_queue_consumer_00656ac8;
extern std::uint8_t* audio_pool_base_00656acc;
extern std::int16_t audio_pool_cursor_00656ae0;
extern std::uint8_t audio_queue_stall_00656af0;
extern std::int16_t audio_pool_limit_00656afc;
extern std::int16_t audio_pool_end_0065737a;
extern std::int16_t audio_pool_split_00657380;
extern std::int32_t audio_state_word_0065738c;
extern std::uint32_t audio_state_dword_00657390;
extern std::uint32_t audio_state_dword_00657394;
extern std::int32_t audio_state_word_0065739c;
extern std::int32_t audio_state_word_006573a0;
extern std::uint8_t audio_state_byte_006573a5;
extern std::uint8_t audio_state_byte_006573a6;
extern std::uint8_t audio_state_byte_006573a7;
extern std::uint8_t audio_queue_inflight_count_006573b4;

// Original entry 004a8490..004a8560 (209 bytes).
void __cdecl audio_bank_record_set_004a8490(std::int32_t first,
                                            std::int32_t second,
                                            const void* data_ptr,
                                            std::uint32_t size);

// Original entry 004af970..004afd2d (958 bytes).
void __cdecl audio_queue_pump_004af970();

// Original entry 004afd30..004afe45 (278 bytes); declared in application_sim_teardown_691.hpp.
void __cdecl application_sim_boundary_004afd30();

// Original entry 004afe50..004affc3 (372 bytes); declared in application_sim_teardown_691.hpp.
void __cdecl application_sim_boundary_004afe50();

} // namespace porsche
