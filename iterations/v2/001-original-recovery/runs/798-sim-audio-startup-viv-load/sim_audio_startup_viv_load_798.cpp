// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004affd0..004b04cd, 1278 bytes, sha256 3978d09462187c8f78f4367445a3529ddf7c6c40d768817367b529d47f34f435.
// Original 005665b0..005666e4, 309 bytes, sha256 8eeb31246d86716d09326c52b6124bf8701f6676a4c581d10811b0486c7ffea1.
#include "sim_audio_startup_viv_load_798.hpp"

#include <cstdio>
#include <cstring>

namespace porsche {

const char audio_copspeak_buf_tag_005d1d60[12] = "CopSpeakBuf";
const char audio_cant_find_fmt_005d1d6c[17] = "can't find '%s'\n";
const char audio_1sht_index_tag_005d1d80[11] = "1sht index";
const char audio_copspeak_temp_tag_005d1d8c[14] = "copspeak temp";
const char audio_oneshots_txt_005d1d9c[13] = "oneshots.txt";
const char audio_zzzx_viv_fmt_005d1dac[13] = "%szzzx%s.viv";
const char audio_lang_eng_005d1dbc[4] = "eng";
const char audio_trck_index_tag_005d1dc0[11] = "trck index";
const char audio_track_viv_fmt_005d1dcc[12] = "%strack.viv";
const char audio_sd6b_bnk_fmt_005d1dd8[13] = "sd6b%.4s.bnk";
const char audio_car_bnk_fmt_005d1de8[11] = "%s%.4s.bnk";
const char audio_ldex_tag_005d1df4[5] = "ldex";
const char audio_lden_tag_005d1dfc[5] = "lden";
const char audio_rain_bnk_name_005d1e04[9] = "rain.bnk";
const char audio_ocar_index_tag_005d1e10[11] = "ocar index";
const char audio_zzzwzzz_viv_fmt_005d1e1c[14] = "%szzzwzzz.viv";

std::uint32_t audio_queue_flag_00656af8 = 0u;
std::int16_t audio_channel_flag_00657378 = 0;
std::uint32_t audio_music_track_count_0065737c = 0u;
const char* audio_speech_path_prefix_0065b31c = nullptr;

const char* __cdecl big_find_entry_005665b0(const void* big,
                                          const char* name,
                                          std::uint32_t index,
                                          std::uint32_t* out_offset,
                                          std::uint32_t* out_size) {
    const std::uint32_t big_va = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(big));
    const std::uint32_t total = audio_resource_size_00566560(big_va);
    const std::uint8_t* cur = static_cast<const std::uint8_t*>(big);
    const std::uint8_t* const end = cur + total;
    const std::uint32_t kind = audio_resource_kind_00566520(big_va);

    if (kind == 1u || kind == 2u) {
        const std::uint32_t field_bytes = (kind == 2u) ? 4u : 3u;
        const std::uint32_t name_off = field_bytes * 2u;
        cur += (kind == 2u) ? 0x10u : 6u;
        std::uint32_t cur_idx = 0u;
        while (cur < end) {
            const char* const entry_name = reinterpret_cast<const char*>(cur + name_off);
            const bool match = (name != nullptr)
                ? (formatter_search_compare_005ae3c0(entry_name, name) == 0)
                : (cur_idx == index);
            if (match) {
                if (out_offset != nullptr) {
                    *out_offset = render_descriptor_read_be_0056e290(cur, field_bytes);
                }
                if (out_size != nullptr) {
                    *out_size = render_descriptor_read_be_0056e290(cur + field_bytes, field_bytes);
                }
                return entry_name;
            }
            ++cur_idx;
            cur += name_off + std::strlen(entry_name) + 1u;
        }
    }

    if (out_offset != nullptr) {
        *out_offset = 0u;
    }
    if (out_size != nullptr) {
        *out_size = 0u;
    }
    return nullptr;
}

void __cdecl startup_sequence_call_004affd0() {
    for (std::uint32_t i = 0u; i < 5u; ++i) {
        audio_queue_banks_00657308[i].active_04 = 0u;
        audio_queue_banks_00657308[i].entries_08 = nullptr;
    }

    frame_audio_primary_handle_006573a8 = -1;
    frame_audio_secondary_handle_006573ac = -1;
    audio_state_word_0065738c = -1;
    audio_state_word_006573a0 = -1;
    audio_state_word_0065739c = -1;
    audio_channel_flag_00657378 = -1;
    frame_audio_extra_handles_00656ae8[0] = -1;
    frame_audio_extra_handles_00656ae8[1] = -1;

    audio_pool_base_00656acc = nullptr;
    audio_queue_tail_00657300 = 0u;
    audio_queue_read_pos_00656af4 = 0u;
    audio_queue_consumer_00656ac8 = 0u;
    audio_queue_head_00656ae4 = 0u;
    audio_queue_flag_00656af8 = 0u;
    audio_pool_cursor_00656ae0 = 0;
    audio_pool_split_00657380 = 0;
    audio_pool_end_0065737a = 0;
    audio_queue_stall_00656af0 = 0u;
    audio_pool_limit_00656afc = 0x7ffc;
    frame_audio_tag_00657388 = 0u;
    audio_state_dword_00657390 = 0u;
    audio_state_dword_00657394 = 0u;
    frame_audio_mode_006573a4 = 0;
    audio_state_byte_006573a5 = 0u;
    audio_state_byte_006573a6 = 2u;
    audio_state_byte_006573a7 = 0u;

    if (application_audio_active_005d1734 == 0u) {
        return;
    }

    char path[80];
    (void)formatter_entry_005a0fbf(path, audio_zzzwzzz_viv_fmt_005d1e1c, application_audio_path_prefix_0065b318);
    void* const ocar_viv = resource_load_bigheader_0059dea0(path, 0x10u);
    if (ocar_viv != nullptr) {
        const std::int32_t max_idx =
            static_cast<std::int32_t>(application_state_006573e8.word(0x00658080u)) * 2 + 1;
        audio_queue_banks_00657308[1].max_index_0c = max_idx;
        std::uint32_t* const tbl = static_cast<std::uint32_t*>(
            allocate_00531ca0(audio_ocar_index_tag_005d1e10, max_idx * 8, 0u));
        audio_queue_banks_00657308[1].entries_08 = tbl;
        if (big_find_entry_005665b0(ocar_viv, audio_rain_bnk_name_005d1e04, 0u, &tbl[0], &tbl[1]) == nullptr) {
            tbl[0] = 0u;
            tbl[1] = 0u;
        }
        const std::int32_t car_entries = max_idx - 1;
        for (std::int32_t i = 0; i < car_entries; ++i) {
            const char* const suffix = ((i & 1) == 0) ? audio_lden_tag_005d1dfc : audio_ldex_tag_005d1df4;
            const char* const car_prefix =
                reinterpret_cast<const char*>(&application_state_006573e8.word(0x00658374u)) +
                (i >> 1) * 0x580;
            char name_buf[20];
            (void)formatter_entry_005a0fbf(name_buf, audio_car_bnk_fmt_005d1de8, car_prefix, suffix);
            if (big_find_entry_005665b0(ocar_viv, name_buf, 0u, &tbl[i * 2 + 2], &tbl[i * 2 + 3]) == nullptr) {
                (void)formatter_entry_005a0fbf(name_buf, audio_sd6b_bnk_fmt_005d1dd8, suffix);
            }
            if (big_find_entry_005665b0(ocar_viv, name_buf, 0u, &tbl[i * 2 + 2], &tbl[i * 2 + 3]) == nullptr) {
                tbl[i * 2 + 2] = 0u;
                tbl[i * 2 + 3] = 0u;
            }
        }
        (void)free_00531f90(ocar_viv);
        audio_queue_banks_00657308[1].active_04 =
            open_0059e040(path, 1u, 0x64u, reinterpret_cast<void**>(&audio_queue_banks_00657308[1].tag_00)) ? 1u : 0u;
    }

    audio_music_track_count_0065737c = 0u;
    (void)formatter_entry_005a0fbf(path, audio_track_viv_fmt_005d1dcc, application_audio_path_prefix_0065b318);
    void* const trk_viv = resource_load_bigheader_quiet_0059df70(path, 0x10u);
    if (trk_viv != nullptr) {
        audio_queue_banks_00657308[0].max_index_0c = 0x3e8;
        std::uint32_t* const tbl = static_cast<std::uint32_t*>(
            allocate_00531ca0(audio_trck_index_tag_005d1dc0, 0x1f40, 0u));
        audio_queue_banks_00657308[0].entries_08 = tbl;
        audio_music_track_count_0065737c = 0x3e8u;
        for (std::int32_t i = 0; i < 0x3e8; ++i) {
            tbl[i * 2] = 0u;
            tbl[i * 2 + 1] = 0u;
        }
        const std::uint32_t trk_va = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(trk_viv));
        std::int32_t n = static_cast<std::int32_t>(audio_resource_data_offset_00566880(trk_va));
        for (std::int32_t i = 0; i < n; ++i) {
            std::uint32_t off_val = 0u;
            std::uint32_t sz_val = 0u;
            const std::uint32_t name_va = audio_resource_locate_005666f0(
                trk_va,
                0u,
                static_cast<std::uint32_t>(i),
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&off_val)),
                static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&sz_val)));
            const char* const name = reinterpret_cast<const char*>(static_cast<std::uintptr_t>(name_va));
            const std::int32_t slot = crt_atoi_005a1f4a(name + std::strlen(name) - 7);
            tbl[slot * 2] = off_val;
            tbl[slot * 2 + 1] = sz_val;
            n = static_cast<std::int32_t>(audio_resource_data_offset_00566880(trk_va));
        }
        (void)free_00531f90(trk_viv);
        audio_queue_banks_00657308[0].active_04 =
            open_0059e040(path, 1u, 0x64u, reinterpret_cast<void**>(&audio_queue_banks_00657308[0].tag_00)) ? 1u : 0u;
    }

    (void)formatter_entry_005a0fbf(path, audio_zzzx_viv_fmt_005d1dac, audio_speech_path_prefix_0065b31c, audio_lang_eng_005d1dbc);
    void* const cop_viv = resource_load_bigheader_0059dea0(path, 0x10u);
    if (cop_viv != nullptr) {
        std::uint32_t txt_off = 0u;
        std::uint32_t txt_sz = 0u;
        if (big_find_entry_005665b0(cop_viv, audio_oneshots_txt_005d1d9c, 0u, &txt_off, &txt_sz) != nullptr &&
            txt_sz != 0u) {
            char* const txt = static_cast<char*>(
                allocate_00531ca0(audio_copspeak_temp_tag_005d1d8c, static_cast<std::int32_t>(txt_sz), 0x10u));
            audio_queue_banks_00657308[2].active_04 =
                open_0059e040(path, 1u, 0x64u, reinterpret_cast<void**>(&audio_queue_banks_00657308[2].tag_00)) ? 1u : 0u;
            (void)read_00533bf0(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(audio_queue_banks_00657308[2].tag_00)),
                txt_off,
                txt,
                txt_sz,
                0x64u);

            std::int32_t pair_count = 0;
            bool in_quote = false;
            for (std::uint32_t k = 0u; k < txt_sz; ++k) {
                if (txt[k] == '"') {
                    if (in_quote) {
                        ++pair_count;
                    }
                    in_quote = !in_quote;
                }
            }
            audio_queue_banks_00657308[2].max_index_0c = pair_count;
            std::uint32_t* const tbl = static_cast<std::uint32_t*>(
                allocate_00531ca0(audio_1sht_index_tag_005d1d80, pair_count * 8, 0u));
            audio_queue_banks_00657308[2].entries_08 = tbl;

            in_quote = false;
            char* tok = txt;
            std::int32_t slot = 0;
            for (std::uint32_t k = 0u; k < txt_sz; ++k) {
                if (txt[k] == '"') {
                    if (!in_quote) {
                        tok = txt + k + 1u;
                    } else {
                        txt[k] = '\0';
                        if (big_find_entry_005665b0(cop_viv, tok, 0u, &tbl[slot * 2], &tbl[slot * 2 + 1]) == nullptr) {
                            (void)std::printf(audio_cant_find_fmt_005d1d6c, tok);
                            tbl[slot * 2 + 1] = 0u;
                        }
                        ++slot;
                    }
                    in_quote = !in_quote;
                }
            }
            (void)free_00531f90(txt);
        }
        (void)free_00531f90(cop_viv);
    }

    audio_pool_base_00656acc = static_cast<std::uint8_t*>(
        allocate_00531ca0(audio_copspeak_buf_tag_005d1d60, 0x8000, 0u));
}

} // namespace porsche
