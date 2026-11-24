// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
#pragma once

#include <cstdint>

#include "porsche/application_services.hpp"
#include "porsche/application_state.hpp"
#include "porsche/fe_stream.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_search.hpp"
#include "porsche/startup_sequence.hpp"
#include "../537-render-resource-descriptor-cleanup/render_resource_descriptor_537.hpp"
#include "../608-frame-audio-channel-volume/frame_audio_channel_volume_608.hpp"
#include "../643-audio-transition-finish/audio_transition_finish_643.hpp"
#include "../658-resource-loadat-and-reset/resource_loadat_658.hpp"
#include "../661-bigheader-and-audio-probe-configure/bigheader_audio_configure_661.hpp"
#include "../670-bigheader-loud-and-startup-diag/bigheader_loud_startup_diag_670.hpp"
#include "../682-render-clock-and-crt-stricmp/render_clock_stricmp_682.hpp"
#include "../690-audio-probe-start-and-period-control/application_audio_probe_690.hpp"
#include "../790-sim-audio-queue-and-record-evict/sim_audio_queue_790.hpp"
#include "../794-sim-audio-queue-teardown/sim_audio_queue_teardown_794.hpp"

namespace porsche {

// Newly owned .data string literals (202 bytes total, pinned byte-for-byte vs Porsche.exe).
extern const char audio_copspeak_buf_tag_005d1d60[12];
extern const char audio_cant_find_fmt_005d1d6c[17];
extern const char audio_1sht_index_tag_005d1d80[11];
extern const char audio_copspeak_temp_tag_005d1d8c[14];
extern const char audio_oneshots_txt_005d1d9c[13];
extern const char audio_zzzx_viv_fmt_005d1dac[13];
extern const char audio_lang_eng_005d1dbc[4];
extern const char audio_trck_index_tag_005d1dc0[11];
extern const char audio_track_viv_fmt_005d1dcc[12];
extern const char audio_sd6b_bnk_fmt_005d1dd8[13];
extern const char audio_car_bnk_fmt_005d1de8[11];
extern const char audio_ldex_tag_005d1df4[5];
extern const char audio_lden_tag_005d1dfc[5];
extern const char audio_rain_bnk_name_005d1e04[9];
extern const char audio_ocar_index_tag_005d1e10[11];
extern const char audio_zzzwzzz_viv_fmt_005d1e1c[14];

// Loader-zero .bss audio state owned by Run798 (14 bytes total).
extern std::uint32_t audio_queue_flag_00656af8;
extern std::int16_t audio_channel_flag_00657378;
extern std::uint32_t audio_music_track_count_0065737c;
extern const char* audio_speech_path_prefix_0065b31c;

// Original entry 005665b0..005666e4 (309 bytes).
const char* __cdecl big_find_entry_005665b0(const void* big,
                                          const char* name,
                                          std::uint32_t index,
                                          std::uint32_t* out_offset,
                                          std::uint32_t* out_size);

// Original entry 004affd0..004b04cd (1278 bytes); declared in startup_sequence.hpp.
void __cdecl startup_sequence_call_004affd0();

} // namespace porsche
