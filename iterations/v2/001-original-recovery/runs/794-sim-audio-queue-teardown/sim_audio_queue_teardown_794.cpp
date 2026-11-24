// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004afd30..004afe45, 278 bytes, sha256 4a87d5a9fe979386f4c84ce1d24b6fbca862fbf7ec00ee5c800ea362a843e6fc.
// Original 004afe50..004affc3, 372 bytes, sha256 5eb2b00cdc49c3bf87ec35b17534d645e78d9030a7c450fcd7050ece4b171623.
// Original 004af970..004afd2d, 958 bytes, sha256 95b46253f990146be2ff668bf9d8a2ffac726a14d85eb9d0334498632f93a63f.
// Original 004a8490..004a8560, 209 bytes, sha256 93f0768b0dfdfe8ba681038811c5758ac5fd718fa867fcd954ac1bdcc28f4207.
#include "sim_audio_queue_teardown_794.hpp"

#include <cstdio>
#include <cstring>

namespace porsche {

const char audio_speech_fail_text_005d19dc[30] = "SNDbankadd failed on speech!\n";
const char audio_sfxbank_tag_005d19fc[8] = "SFXBANK";

std::uint32_t audio_queue_consumer_00656ac8 = 0u;
std::uint8_t* audio_pool_base_00656acc = nullptr;
std::int16_t audio_pool_cursor_00656ae0 = 0;
std::uint8_t audio_queue_stall_00656af0 = 0u;
std::int16_t audio_pool_limit_00656afc = 0;
std::int16_t audio_pool_end_0065737a = 0;
std::int16_t audio_pool_split_00657380 = 0;
std::int32_t audio_state_word_0065738c = 0;
std::uint32_t audio_state_dword_00657390 = 0u;
std::uint32_t audio_state_dword_00657394 = 0u;
std::int32_t audio_state_word_0065739c = 0;
std::int32_t audio_state_word_006573a0 = 0;
std::uint8_t audio_state_byte_006573a5 = 0u;
std::uint8_t audio_state_byte_006573a6 = 0u;
std::uint8_t audio_state_byte_006573a7 = 0u;
std::uint8_t audio_queue_inflight_count_006573b4 = 0u;

namespace {

void reclaim_pool_span(std::int32_t handle_offset, std::uint32_t byte_len) {
    const std::int32_t end_pos = static_cast<std::int32_t>(byte_len) + handle_offset;
    if (audio_pool_split_00657380 != 0) {
        if (end_pos == static_cast<std::int32_t>(audio_pool_split_00657380)) {
            audio_pool_limit_00656afc = 0x7ffc;
            audio_pool_split_00657380 = 0;
            audio_pool_cursor_00656ae0 = 0;
        } else {
            audio_pool_cursor_00656ae0 = static_cast<std::int16_t>(
                audio_pool_cursor_00656ae0 + static_cast<std::int16_t>(byte_len & 0xffffu));
            audio_pool_limit_00656afc = audio_pool_cursor_00656ae0;
        }
        return;
    }
    if (end_pos == static_cast<std::int32_t>(audio_pool_end_0065737a)) {
        audio_pool_end_0065737a = 0;
        audio_pool_cursor_00656ae0 = 0;
    } else {
        audio_pool_cursor_00656ae0 = static_cast<std::int16_t>(
            audio_pool_cursor_00656ae0 + static_cast<std::int16_t>(byte_len & 0xffffu));
    }
}

void flush_and_reset_queue() {
    if (audio_queue_consumer_00656ac8 != audio_queue_read_pos_00656af4) {
        std::uint32_t cur = audio_queue_head_00656ae4;
        const std::uint32_t tail = audio_queue_tail_00657300;
        while (cur != tail) {
            audio_queue_ring_00656b00[cur].bank_1e = -1;
            cur = (static_cast<std::int32_t>(cur) >= 0x3f) ? 0u : (cur + 1u);
        }
        do {
            audio_queue_pump_004af970();
            (void)timed_callbacks_005366e0(0u);
        } while (audio_queue_consumer_00656ac8 != audio_queue_read_pos_00656af4);
    }

    if (frame_audio_primary_handle_006573a8 != -1) {
        (void)audio_channel_stop_00565d60(static_cast<std::uint32_t>(frame_audio_primary_handle_006573a8));
    }
    if (frame_audio_secondary_handle_006573ac != -1) {
        (void)audio_channel_stop_00565d60(static_cast<std::uint32_t>(frame_audio_secondary_handle_006573ac));
    }
    for (std::uint32_t i = 0u; i < 2u; ++i) {
        const std::int32_t hx = frame_audio_extra_handles_00656ae8[i];
        if (hx != -1) {
            (void)audio_channel_stop_00565d60(static_cast<std::uint32_t>(hx));
            frame_audio_extra_handles_00656ae8[i] = -1;
        }
    }

    frame_audio_primary_handle_006573a8 = -1;
    frame_audio_secondary_handle_006573ac = -1;
    frame_audio_tag_00657388 = 0u;
    audio_state_word_0065738c = -1;
    audio_state_word_006573a0 = -1;
    audio_state_dword_00657390 = 0u;
    audio_state_dword_00657394 = 0u;
    frame_audio_mode_006573a4 = 0;
    audio_state_byte_006573a5 = 0u;
    audio_state_byte_006573a6 = 2u;
    audio_state_byte_006573a7 = 0u;
    audio_state_word_0065739c = -1;
    audio_queue_tail_00657300 = 0u;
    audio_queue_read_pos_00656af4 = 0u;
    audio_queue_consumer_00656ac8 = 0u;
    audio_queue_head_00656ae4 = 0u;
    audio_pool_cursor_00656ae0 = 0;
    audio_pool_split_00657380 = 0;
    audio_pool_end_0065737a = 0;
    audio_pool_limit_00656afc = 0x7ffc;
}

} // namespace

void __cdecl audio_bank_record_set_004a8490(std::int32_t first,
                                            std::int32_t second,
                                            const void* data_ptr,
                                            std::uint32_t size) {
    SimAudioRecord00656528* found = nullptr;
    for (std::int32_t i = 0; i < 32; ++i) {
        SimAudioRecord00656528& rec = application_audio_records_00656528[i];
        if (rec.channel_04 == second &&
            rec.raw_00 == static_cast<std::uint32_t>(first) &&
            rec.handle_08 == -1) {
            found = &rec;
            break;
        }
    }
    if (found == nullptr) {
        return;
    }
    if (size == 0u) {
        found->handle_08 = -1;
        found->channel_04 = -1;
        return;
    }
    void* const buf = allocate_00531ca0(audio_sfxbank_tag_005d19fc,
                                        static_cast<std::int32_t>(size),
                                        0x10u);
    std::memcpy(buf, data_ptr, size);
    const std::int32_t open_res = audio_bank_open_00565b60(
        reinterpret_cast<std::uint32_t*>(&found->handle_08), buf);
    if (open_res == 8) {
        found->data_14 = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(buf));
        found->channel_04 = second;
        found->raw_0c = startup_sequence_word_00606ac4;
        return;
    }
    if (first == 2) {
        (void)std::puts(audio_speech_fail_text_005d19dc);
    }
    if (open_res >= 0) {
        application_audio_shutdown_channels_005659f0(found->handle_08);
    }
    found->handle_08 = -1;
    found->channel_04 = -1;
}

void __cdecl audio_queue_pump_004af970() {
    AudioQueueRequest00656b00& req = audio_queue_ring_00656b00[audio_queue_consumer_00656ac8];
    bool valid = true;

    if (req.handle_04 > -1) {
        if (req.id_14 != -1) {
            const std::int32_t st = operation_status_00567af0(static_cast<std::uint32_t>(req.id_14));
            if (st == 0) {
                return;
            }
            if (st != 1) {
                valid = false;
            }
            const std::uint32_t completed = operation_complete_00567df0(static_cast<std::uint32_t>(req.id_14));
            req.id_14 = -1;
            --audio_queue_inflight_count_006573b4;
            if (completed != req.raw_0c) {
                valid = false;
            }
        }

        const std::uint8_t* const hdr = audio_pool_base_00656acc + req.handle_04;
        std::uint32_t magic = 0u;
        std::memcpy(&magic, hdr, sizeof(magic));
        if (magic != 0x6c4b4e42u) {
            valid = false;
        }
        if (hdr[4] != 4u) {
            valid = false;
        }

        if (!valid) {
            if (req.flag_1d != 0u && req.bank_1e > -1) {
                audio_bank_record_set_004a8490(static_cast<std::int32_t>(req.bank_1e), req.index_18, nullptr, 0u);
            }
            std::uint32_t* const entries = const_cast<std::uint32_t*>(audio_queue_banks_00657308[req.bank_1e].entries_08);
            entries[req.index_18 * 2] = 0u;
            entries[req.index_18 * 2 + 1] = 0u;
            if (req.handle_04 >= 0 && static_cast<std::int32_t>(req.raw_0c) > 0) {
                reclaim_pool_span(req.handle_04, req.raw_0c);
                req.handle_04 = -1;
            }
        } else {
            if (req.bank_1e > -1) {
                if (req.flag_1d == 0u && req.index_18 <= -1) {
                    const std::int32_t id = static_cast<std::int32_t>(req.raw_08) + 0x4000;
                    if (application_sim_boundary_004a8570(static_cast<std::int32_t>(req.bank_1e), id, 0) == -1) {
                        audio_bank_record_set_004a8490(
                            static_cast<std::int32_t>(req.bank_1e),
                            id,
                            audio_pool_base_00656acc + req.handle_04,
                            req.raw_0c);
                        if (application_sim_boundary_004a8570(static_cast<std::int32_t>(req.bank_1e), id, 1) == -1) {
                            audio_queue_stall_00656af0 = 1u;
                            return;
                        }
                    }
                } else {
                    if (application_sim_boundary_004a8570(static_cast<std::int32_t>(req.bank_1e), req.index_18, 0) == -1) {
                        audio_bank_record_set_004a8490(
                            static_cast<std::int32_t>(req.bank_1e),
                            req.index_18,
                            audio_pool_base_00656acc + req.handle_04,
                            req.raw_0c);
                    }
                }
            }
            if (req.handle_04 >= 0 && static_cast<std::int32_t>(req.raw_0c) > 0) {
                reclaim_pool_span(req.handle_04, req.raw_0c);
                req.handle_04 = -1;
            }
            audio_queue_stall_00656af0 = 0u;
        }
    } else {
        if (req.flag_1d != 0u || (req.index_18 > -1 && req.bank_1e > -1)) {
            audio_bank_record_set_004a8490(static_cast<std::int32_t>(req.bank_1e), req.index_18, nullptr, 0u);
        }
    }

    audio_queue_consumer_00656ac8 =
        (static_cast<std::int32_t>(audio_queue_consumer_00656ac8) >= 0x3f)
            ? 0u
            : (audio_queue_consumer_00656ac8 + 1u);
}

void __cdecl application_sim_boundary_004afd30() {
    flush_and_reset_queue();
}

void __cdecl application_sim_boundary_004afe50() {
    flush_and_reset_queue();
    for (std::uint32_t i = 0u; i < 5u; ++i) {
        AudioQueueBank00657308& bank = audio_queue_banks_00657308[i];
        if (bank.active_04 != 0u) {
            (void)close_00533da0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(bank.tag_00)), 0x64u);
            bank.active_04 = 0u;
        }
        if (bank.entries_08 != nullptr) {
            (void)free_00531f90(const_cast<std::uint32_t*>(bank.entries_08));
            bank.entries_08 = nullptr;
        }
    }
    if (audio_pool_base_00656acc != nullptr) {
        (void)free_00531f90(audio_pool_base_00656acc);
        audio_pool_base_00656acc = nullptr;
    }
}

} // namespace porsche
