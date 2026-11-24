// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004a8570..004a865e, 239 bytes, sha256 dabdb9c61557dac4649780d64f9a80aae3f81a1a3ce152a428191cc397b960ef.
// Original 004a83e0..004a8481, 162 bytes, sha256 eb06bb362d427e4716f426d2158d4a046dfa423bc6bfdbec82896a4f7bda738e.
// Original 004af8d0..004af8f7, 40 bytes, sha256 cc94905c890ba406238e9b68c450170bf99dc2cd33196ccc06481d468a08cec2.
// Original 004b05a0..004b0670, 209 bytes, sha256 688a6f78f8c69bfc4c48ad3224758297c94ba3db851fb11fe57bf5b8abe383aa.
// Original 004b0cf0..004b0d2a, 59 bytes, sha256 275a7f4d77944c94401a3b728910b33934553081ffe2fbc5d70d14321799599d.
#include "sim_audio_queue_790.hpp"

namespace porsche {

std::uint32_t audio_queue_head_00656ae4 = 0u;
std::uint32_t audio_queue_read_pos_00656af4 = 0u;
AudioQueueRequest00656b00 audio_queue_ring_00656b00[64] = {};
std::uint32_t audio_queue_tail_00657300 = 0u;
AudioQueueBank00657308 audio_queue_banks_00657308[5] = {};

std::int32_t __cdecl audio_record_evict_slot_004a83e0(std::int32_t threshold) {
    std::int32_t oldest_time = static_cast<std::int32_t>(startup_sequence_word_00606ac4) - 0x10;
    std::int32_t best_slot = -1;
    for (std::int32_t i = 0; i < 32; ++i) {
        const SimAudioRecord00656528& rec = application_audio_records_00656528[i];
        if (rec.channel_04 != -1) {
            const std::int32_t t = static_cast<std::int32_t>(rec.raw_0c);
            if (t < oldest_time) {
                oldest_time = t;
                best_slot = i;
            }
        }
    }
    if (best_slot == -1) {
        for (std::int32_t i = 0; i < 32; ++i) {
            const SimAudioRecord00656528& rec = application_audio_records_00656528[i];
            if (rec.channel_04 != -1 && threshold > static_cast<std::int32_t>(rec.raw_00)) {
                best_slot = i;
            }
        }
    }
    if (best_slot >= 0) {
        SimAudioRecord00656528& rec = application_audio_records_00656528[best_slot];
        if (rec.channel_04 != -1) {
            if (rec.handle_08 != -1) {
                application_audio_shutdown_channels_005659f0(rec.handle_08);
                rec.handle_08 = -1;
                if (rec.data_14 != 0u) {
                    (void)free_00531f90(reinterpret_cast<void*>(static_cast<std::uintptr_t>(rec.data_14)));
                    rec.data_14 = 0u;
                }
            }
            rec.channel_04 = -1;
        }
    }
    return best_slot;
}

void __cdecl audio_queue_request_init_004af8d0(AudioQueueRequest00656b00* req) {
    req->raw_00 = 0u;
    req->handle_04 = -1;
    req->index_18 = -1;
    req->raw_08 = 0u;
    req->raw_0c = 0u;
    req->flag_1c = 0u;
    req->flag_1d = 0u;
    req->bank_1e = 2;
    req->flag_1f = 0u;
    req->id_14 = -1;
}

std::int32_t __cdecl audio_queue_enqueue_004b05a0(AudioQueueRequest00656b00* req) {
    const std::uint32_t tail = audio_queue_tail_00657300;
    const std::uint32_t read_pos = audio_queue_read_pos_00656af4;
    const std::uint32_t pending = (tail - read_pos) & 0x3fu;
    if (static_cast<std::int8_t>(pending) > 0x20) {
        return -1;
    }
    const std::uint32_t next_tail = (static_cast<std::int32_t>(tail) >= 0x3f) ? 0u : (tail + 1u);
    if (next_tail == audio_queue_head_00656ae4) {
        return -1;
    }
    const AudioQueueBank00657308& bank = audio_queue_banks_00657308[req->bank_1e];
    if (bank.active_04 == 0u || bank.entries_08 == nullptr) {
        return -1;
    }
    const std::int32_t idx = req->index_18;
    if (idx < 0 || idx > bank.max_index_0c) {
        return -1;
    }
    req->raw_10 = bank.tag_00;
    req->raw_08 = bank.entries_08[idx * 2];
    const std::uint32_t size_val = bank.entries_08[idx * 2 + 1];
    req->raw_0c = size_val;
    if (size_val == 0u) {
        return -1;
    }
    const std::uint32_t slot = audio_queue_tail_00657300;
    audio_queue_ring_00656b00[slot] = *req;
    audio_queue_tail_00657300 = (static_cast<std::int32_t>(slot) >= 0x3f) ? 0u : (slot + 1u);
    return static_cast<std::int32_t>(slot);
}

std::int32_t __cdecl audio_queue_count_active_004b0cf0() {
    std::uint32_t cur = audio_queue_head_00656ae4;
    const std::uint32_t tail = audio_queue_tail_00657300;
    std::int32_t count = 0;
    if (cur == tail) {
        return 0;
    }
    do {
        const AudioQueueRequest00656b00& req = audio_queue_ring_00656b00[cur];
        if (req.bank_1e > -1 && req.flag_1d != 0u) {
            ++count;
        }
        cur = (static_cast<std::int32_t>(cur) >= 0x3f) ? 0u : (cur + 1u);
    } while (cur != tail);
    return count;
}

std::int32_t __cdecl application_sim_boundary_004a8570(std::int32_t first,
                                                       std::int32_t second,
                                                       std::int32_t flag) {
    for (std::int32_t i = 0; i < 32; ++i) {
        SimAudioRecord00656528& rec = application_audio_records_00656528[i];
        if (rec.channel_04 == second && rec.raw_00 == static_cast<std::uint32_t>(first)) {
            rec.raw_0c = startup_sequence_word_00606ac4;
            return rec.handle_08;
        }
    }

    std::int32_t free_slot = 0;
    while (free_slot < 32 && application_audio_records_00656528[free_slot].channel_04 != -1) {
        ++free_slot;
    }

    const std::uint8_t flag_byte = static_cast<std::uint8_t>(flag & 0xff);
    if (flag_byte == 0u && free_slot == 32) {
        free_slot = audio_record_evict_slot_004a83e0(first);
    }

    if (free_slot <= -1 || free_slot >= 32) {
        return -1;
    }

    if (flag_byte != 0u) {
        application_audio_records_00656528[free_slot].raw_00 = static_cast<std::uint32_t>(first);
    } else {
        if (audio_queue_count_active_004b0cf0() >= 6) {
            return -1;
        }
        AudioQueueRequest00656b00 req;
        audio_queue_request_init_004af8d0(&req);
        req.index_18 = second;
        req.flag_1d = 1u;
        req.bank_1e = static_cast<std::int8_t>(first & 0xff);
        if (audio_queue_enqueue_004b05a0(&req) == -1) {
            return -1;
        }
        application_audio_records_00656528[free_slot].raw_00 = static_cast<std::uint32_t>(first);
    }

    application_audio_records_00656528[free_slot].channel_04 = second;
    application_audio_records_00656528[free_slot].raw_0c = startup_sequence_word_00606ac4;
    return -1;
}

} // namespace porsche
