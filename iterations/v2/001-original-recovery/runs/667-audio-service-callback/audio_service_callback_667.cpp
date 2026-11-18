// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00590d80..00590de7, 104 bytes, sha256 8d05ef0d7dc7fb01f6ff07f3f64ab901b4890eeaf97e23870cff21218485acbe.
// Original 00590df0..00590e1f, 48 bytes, sha256 3126b8aefba75d0ce69e086636d63e1f55194d18fe3b2e570152594c9944177f.
// Original 00590e20..00590e65, 70 bytes, sha256 1c113e1fd292ae26b1de3d9b5633b5d7aacd12527f257ef82977f12ce8266195.
// Original 005616b0..005616c3, 20 bytes, sha256 8454f13e18341fff4b667c812cfede9856f5c3c323a8508fe17a3124450ae117.
// Original 00566a40..00566adb, 156 bytes, sha256 7e0cb2106195ba17c37772484b72d5d7e46577a3b38b855ead3d0de57de6ccbc.
// Original 00566910..00566a30, 289 bytes, sha256 7105ede4827ddbec607c7f6ba7f4df3dac588fb58add9f65a2ec3f031fd5e94d.
// Original 004ad950..004ad9b4, 101 bytes, sha256 9799fa1351b18bda7d713eed1d273852f7b4617e28663eb702718625693582a7.
// Original 004ad9c0..004ade19, 1114 bytes, sha256 5f2705f6a9c0969a8dd25e851ec1dacc131263f2edad7a0122c795ca25d207e5.
#include "audio_service_callback_667.hpp"

#include <cstring>

namespace porsche {

const char audio_service_tag_vic_005d1bd4[4] = "vic";
const char audio_service_tag_win_005d1bd8[4] = "win";
const char audio_service_tag_lose_005d1bdc[5] = "lose";

namespace {

using U = std::uint32_t;
using I = std::int32_t;
using B = std::uint8_t;

inline void* ptr_from_va(U addr) noexcept {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

inline U va_from_ptr(const void* ptr) noexcept {
    return static_cast<U>(reinterpret_cast<std::uintptr_t>(ptr));
}

inline U read_u32(U addr) noexcept {
    U value = 0u;
    std::memcpy(&value, ptr_from_va(addr), sizeof value);
    return value;
}

inline void write_u32(U addr, U value) noexcept {
    std::memcpy(ptr_from_va(addr), &value, sizeof value);
}

inline std::uint16_t read_u16(U addr) noexcept {
    std::uint16_t value = 0u;
    std::memcpy(&value, ptr_from_va(addr), sizeof value);
    return value;
}

inline B read_u8(U addr) noexcept {
    B value = 0u;
    std::memcpy(&value, ptr_from_va(addr), sizeof value);
    return value;
}

inline void write_u8(U addr, B value) noexcept {
    std::memcpy(ptr_from_va(addr), &value, sizeof value);
}

inline I abs32_mod(U sum, I divisor) noexcept {
    const U sign_mask = (static_cast<I>(sum) < 0) ? 0xffffffffu : 0u;
    const I abs_val = static_cast<I>((sum ^ sign_mask) - sign_mask);
    return abs_val % divisor;
}

inline void ramp_stop_with_end_marker(U root) {
    if (read_u32(root + 0x8cu) == 0u) {
        return;
    }
    const U ms = (root != 0u && read_u32(root + 0x88u) != 0u)
        ? read_u32(root + 0xa4u)
        : 0u;
    (void)audio_stream_service_ramp_00566ae0(
        static_cast<I>(read_u32(root + 0x70u)), static_cast<I>(ms), 0);
    const U end_val = splash_progress_resource_end_004ad6c0();
    write_u32(audio_resource_query_root_00656ab4 + 0x20u, end_val);
}

inline std::uint32_t finish_stopped_root() {
    const U root = audio_resource_query_root_00656ab4;
    write_u32(root + 0x18u, 1u);
    write_u32(audio_resource_query_root_00656ab4 + 0x10u, 0u);
    write_u32(audio_resource_query_root_00656ab4 + 0x28u, 0u);
    write_u32(audio_resource_query_root_00656ab4 + 0x14u, 0xffffffffu);
    write_u32(audio_resource_query_root_00656ab4 + 0x0cu, 0xffffffffu);
    return 0u;
}

} // namespace

std::uint64_t __cdecl audio_u32_mul64_00590d80(std::uint32_t lhs, std::uint32_t rhs) {
    return static_cast<std::uint64_t>(lhs) * static_cast<std::uint64_t>(rhs);
}

std::uint32_t __cdecl audio_u64_div32_00590df0(
    std::uint32_t lo, std::uint32_t hi, std::uint32_t divisor) {
    U quotient = 0u;
    U rem = hi;
    U x = lo;
    for (U i = 0u; i < 0x20u; ++i) {
        const U msb = x >> 31u;
        quotient <<= 1u;
        rem = (rem << 1u) + msb;
        x <<= 1u;
        if (rem >= divisor) {
            rem -= divisor;
            ++quotient;
        }
    }
    return quotient;
}

std::uint32_t __cdecl audio_service_stream_lookup_00590e20(std::int32_t stream_handle) {
    if (stream_handle < 0) {
        return 0u;
    }
    const U chan = audio_stream_service_lookup_00566d60(stream_handle & 0xff);
    if (chan == 0u) {
        return 0u;
    }
    if (static_cast<std::int8_t>(read_u8(chan + 0x16u)) <= 0) {
        return 0u;
    }
    U entry = read_u32(chan + 0x00u);
    I idx = 0;
    do {
        if (static_cast<I>(read_u32(entry + 0x04u)) == stream_handle) {
            return entry;
        }
        ++idx;
        entry += 0x2cu;
    } while (idx < static_cast<I>(static_cast<std::int8_t>(read_u8(chan + 0x16u))));
    return 0u;
}

std::uint32_t __cdecl audio_stream_slot_total_005616b0(std::uint32_t index) {
    const U slot_ptr = audio_stream_slots_006b7cc0[index];
    return read_u32(slot_ptr + 0x24u) + read_u32(slot_ptr + 0x20u);
}

std::int32_t __cdecl audio_service_slot_info_00566a40(
    std::int32_t slot, std::uint32_t* out_info) {
    const U out_va = va_from_ptr(out_info);
    write_u32(out_va + 0x08u, 0u);
    write_u32(out_va + 0x04u, 0u);
    write_u32(out_va + 0x00u, 0u);
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    const U chan = audio_stream_service_lookup_00566d60(slot);
    if (chan == 0u) {
        return -8;
    }
    audio_backend_lock_005896d0();
    const B slot_count_raw = read_u8(chan + 0x16u);
    write_u32(out_va + 0x00u, static_cast<U>(static_cast<I>(static_cast<std::int8_t>(slot_count_raw))));
    if (read_u8(chan + 0x16u) != 0u) {
        const U entries = read_u32(chan + 0x00u);
        write_u32(out_va + 0x04u, read_u32(entries + 0x04u));
        const U denom = static_cast<U>(read_u16(chan + 0x2cu));
        if (denom != 0u) {
            const U total = audio_stream_slot_total_005616b0(read_u32(chan + 0x0cu));
            write_u32(out_va + 0x08u, (total * 1000u) / denom);
        }
    }
    audio_backend_unlock_005896f0();
    return 0;
}

std::int32_t __cdecl audio_service_stream_info_00566910(
    std::int32_t stream_handle, std::uint32_t* out_info) {
    const U out_va = va_from_ptr(out_info);
    write_u32(out_va + 0x00u, 0u);
    write_u32(out_va + 0x04u, 0u);
    write_u32(out_va + 0x08u, 0u);
    write_u32(out_va + 0x0cu, 0u);
    if (application_audio_device_state_006b48c0[0xdcu] == 0u) {
        return -10;
    }
    if (stream_handle < 0) {
        return -8;
    }
    const U chan = audio_stream_service_lookup_00566d60(stream_handle & 0xff);
    if (chan == 0u) {
        return -8;
    }
    audio_backend_lock_005896d0();
    const U entry = audio_service_stream_lookup_00590e20(stream_handle);
    if (entry == 0u) {
        write_u32(out_va + 0x00u, 3u);
        audio_backend_unlock_005896f0();
        return 0;
    }
    if (static_cast<I>(read_u32(entry + 0x08u)) < 0) {
        write_u32(out_va + 0x00u, 0u);
        audio_backend_unlock_005896f0();
        return 0;
    }
    U denom = 0u;
    if (read_u32(chan + 0x00u) == entry) {
        write_u32(out_va + 0x00u, 2u);
        denom = static_cast<U>(read_u16(chan + 0x2cu));
    } else {
        write_u32(out_va + 0x00u, 1u);
        denom = static_cast<U>(read_u16(chan + 0x30u));
    }
    const std::uint64_t p0 = audio_u32_mul64_00590d80(read_u32(entry + 0x14u), 1000u);
    write_u32(out_va + 0x04u,
              audio_u64_div32_00590df0(static_cast<U>(p0), static_cast<U>(p0 >> 32u), denom));
    const U diff = read_u32(entry + 0x18u) - read_u32(entry + 0x14u);
    const std::uint64_t p1 = audio_u32_mul64_00590d80(diff, 1000u);
    write_u32(out_va + 0x08u,
              audio_u64_div32_00590df0(static_cast<U>(p1), static_cast<U>(p1 >> 32u), denom));
    write_u32(out_va + 0x0cu, (read_u32(entry + 0x1cu) * 1000u) / denom);
    audio_backend_unlock_005896f0();
    return 0;
}

void __cdecl audio_service_split_004ad950(void* object) {
    const U obj = va_from_ptr(object);
    U s = read_u32(obj + 0x00u);
    write_u32(obj + 0x08u, 0u);
    write_u32(obj + 0x0cu, 0u);
    write_u32(obj + 0x10u, 0u);
    write_u32(obj + 0x14u, 0u);
    B c = read_u8(s);
    I len = 0;
    U seen_dash = 0u;
    while (c != 0u) {
        if (c == 0x2du) {
            if (seen_dash != 0u) {
                ++s;
                write_u32(obj + 0x08u, s);
                break;
            }
            seen_dash = 1u;
            len = 0;
        } else if (len < 0x1f) {
            write_u8(obj + 0x20u + static_cast<U>(len), c);
            ++len;
        }
        ++s;
        c = read_u8(s);
    }
    write_u8(obj + 0x20u + static_cast<U>(len), 0u);
    write_u32(obj + 0x04u, obj + 0x20u);
}

std::uint32_t __cdecl application_audio_service_callback_004ad9c0(
    std::uint32_t, std::uint32_t) {
    U root = audio_resource_query_root_00656ab4;
    if (read_u32(root + 0x88u) == 0u) {
        return 0u;
    }
    if (window_worker_activation_00565560() == 0u) {
        return 0u;
    }

    root = audio_resource_query_root_00656ab4;
    const I slot = static_cast<I>(read_u32(root + 0x70u));
    if (slot < 0) {
        write_u32(root + 0x8cu, 0u);
    } else {
        (void)audio_service_slot_info_00566a40(
            slot, reinterpret_cast<U*>(ptr_from_va(root + 0x8cu)));
        root = audio_resource_query_root_00656ab4;
        if (static_cast<I>(read_u32(root + 0x8cu)) >= 1) {
            const I stream_handle = static_cast<I>(read_u32(root + 0x90u));
            (void)audio_service_stream_info_00566910(
                stream_handle, reinterpret_cast<U*>(ptr_from_va(root + 0x98u)));
        }
    }

    root = audio_resource_query_root_00656ab4;
    if (root != 0u &&
        read_u32(root + 0x88u) != 0u &&
        read_u32(root + 0x1cu) == 0u &&
        read_u32(root + 0x14u) != 2u &&
        read_u32(root + 0x8cu) != 0u &&
        static_cast<I>(read_u32(root + 0xa0u)) > static_cast<I>(read_u32(root + 0xa4u)) &&
        read_u32(root + 0x84u) != 0u &&
        static_cast<I>(read_u32(root + 0xa4u)) < 0x226) {
        write_u32(root + 0x1cu, 0xfffffffbu);
        ramp_stop_with_end_marker(audio_resource_query_root_00656ab4);
        write_u32(audio_resource_query_root_00656ab4 + 0x14u, 2u);
        root = audio_resource_query_root_00656ab4;
    }

    const U state = read_u32(root + 0x14u);
    if (state == 0u) {
        if (read_u32(root + 0x8cu) != 0u) {
            return 0u;
        }
        const I cur_idx = static_cast<I>(read_u32(root + 0x0cu));
        if (cur_idx <= -1) {
            return 0u;
        }
        const I count = static_cast<I>(read_u32(root + 0x08u));
        if (count == 1) {
            write_u32(root + 0x0cu, 0u);
        } else if (count > 0) {
            if (read_u32(root + 0x24u) != 0u) {
                const U prng = render_seed_prng_next_00538040();
                const U tick = platform_get_tick_count();
                const I rem = abs32_mod(tick + prng, count - 1);
                const I old_idx = static_cast<I>(read_u32(root + 0x0cu));
                const I next_idx = static_cast<I>(
                    static_cast<U>(rem) + static_cast<U>(old_idx) + 1u) % count;
                write_u32(root + 0x0cu, static_cast<U>(next_idx));
            } else {
                const I next_idx = static_cast<I>(static_cast<U>(cur_idx) + 1u) % count;
                write_u32(root + 0x0cu, static_cast<U>(next_idx));
            }
        }
        root = audio_resource_query_root_00656ab4;
        (void)audio_stream_service_volume_00567810(
            static_cast<I>(read_u32(root + 0x70u)), 0u);
        root = audio_resource_query_root_00656ab4;
        if (static_cast<I>(read_u32(root + 0x08u)) > 0) {
            audio_service_play_004ad8b0();
            write_u32(audio_resource_query_root_00656ab4 + 0x18u, 1u);
            write_u32(audio_resource_query_root_00656ab4 + 0x10u, 1u);
        }
        return 0u;
    }

    if (state == 2u) {
        if (read_u32(root + 0x6cu) == 0u) {
            write_u32(root + 0x1cu, 0xfffffffcu);
            ramp_stop_with_end_marker(audio_resource_query_root_00656ab4);
            return finish_stopped_root();
        }
        if (static_cast<I>(read_u32(root + 0x70u)) < 0) {
            write_u32(root + 0x1cu, 0xfffffffdu);
            ramp_stop_with_end_marker(audio_resource_query_root_00656ab4);
            return finish_stopped_root();
        }
        if (read_u32(root + 0x8cu) == 0u) {
            return 0u;
        }
        const U split_base = root + 0x168u;
        const U cur_pos = read_u32(root + 0xa0u);
        write_u32(split_base + 0x08u, cur_pos);
        const U split_obj = split_base + 0x0cu;
        const U rem_pos = read_u32(audio_resource_query_root_00656ab4 + 0x9cu);
        write_u32(split_obj + 0x18u, rem_pos + cur_pos);
        write_u32(split_obj + 0x00u, read_u32(audio_resource_query_root_00656ab4 + 0x28u));
        audio_service_split_004ad950(ptr_from_va(split_obj));

        const auto* tag_lose = reinterpret_cast<const char*>(
            ptr_from_va(read_u32(audio_resource_query_root_00656ab4 + 0x28u)));
        bool is_special =
            (formatter_text_compare_n_005a2210(tag_lose, audio_service_tag_lose_005d1bdc, 4u) == 0);
        if (!is_special) {
            const auto* tag_win = reinterpret_cast<const char*>(
                ptr_from_va(read_u32(audio_resource_query_root_00656ab4 + 0x28u)));
            is_special =
                (formatter_text_compare_n_005a2210(tag_win, audio_service_tag_win_005d1bd8, 3u) == 0);
        }
        if (!is_special) {
            const auto* tag_vic = reinterpret_cast<const char*>(
                ptr_from_va(read_u32(audio_resource_query_root_00656ab4 + 0x28u)));
            is_special =
                (formatter_text_compare_n_005a2210(tag_vic, audio_service_tag_vic_005d1bd4, 3u) == 0);
        }

        const U cur_root = audio_resource_query_root_00656ab4;
        const I target = is_special
            ? static_cast<I>(frame_services_words_005d1740[0])
            : static_cast<I>(read_u32(cur_root + 0x00u));
        (void)audio_stream_service_ramp_00566ae0(
            static_cast<I>(read_u32(cur_root + 0x70u)), 5, target);
        write_u32(audio_resource_query_root_00656ab4 + 0x14u, 0u);
        return 0u;
    }

    if (read_u32(root + 0x8cu) != 0u) {
        if (audio_stream_service_status_00567850(static_cast<I>(read_u32(root + 0x70u))) != 0) {
            return 0u;
        }
        root = audio_resource_query_root_00656ab4;
    }
    const I reset_slot = static_cast<I>(read_u32(root + 0x70u));
    if (reset_slot >= 0) {
        (void)audio_stream_service_reset_00567740(static_cast<U>(reset_slot));
        root = audio_resource_query_root_00656ab4;
    }
    write_u32(root + 0x28u, 0u);
    root = audio_resource_query_root_00656ab4;
    if (read_u32(root + 0x14u) != 1u) {
        write_u32(root + 0x14u, 0u);
        return 0u;
    }

    write_u32(root + 0x20u, 0u);
    root = audio_resource_query_root_00656ab4;
    U out_size = 0u;
    const U cur_idx = read_u32(root + 0x0cu);
    const I entry_idx = static_cast<I>(static_cast<std::int8_t>(read_u8(root + cur_idx + 0xe8u)));
    const U located = audio_resource_locate_005666f0(
        read_u32(root + 0x88u), 0u, static_cast<U>(entry_idx), va_from_ptr(&out_size), 0u);
    write_u32(audio_resource_query_root_00656ab4 + 0x28u, located);
    root = audio_resource_query_root_00656ab4;
    const I start_slot = static_cast<I>(read_u32(root + 0x70u));
    if (start_slot >= 0) {
        const I start_ret = audio_service_stream_start_00567720(
            static_cast<U>(start_slot), 0x3e8u, root + 0xa8u, out_size);
        write_u32(audio_resource_query_root_00656ab4 + 0x74u, static_cast<U>(start_ret));
        root = audio_resource_query_root_00656ab4;
    }
    write_u32(root + 0x14u, 2u);
    root = audio_resource_query_root_00656ab4;
    write_u32(root + 0x170u, 0u);
    write_u32(root + 0x18cu, 0u);
    const U split_base = root + 0x168u;
    write_u32(split_base + 0x0cu, 0u);
    write_u32(split_base + 0x10u, 0u);
    write_u32(split_base + 0x14u, 0u);
    write_u32(split_base + 0x18u, 0u);
    write_u32(split_base + 0x20u, 0u);
    write_u32(audio_resource_query_root_00656ab4 + 0x14u, 2u);
    return 0u;
}

} // namespace porsche
