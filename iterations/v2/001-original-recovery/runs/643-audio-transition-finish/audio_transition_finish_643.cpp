// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 004ae4d0..004ae8b2, 995 bytes, sha256 27ecec51cc35cf224f517e0118bfddb570c61d1da214b9043441c67db1bdb8f8.
// Original 004ae8c0..004ae985, 198 bytes, sha256 57f95780bf516b9675752b33690814dcdab2e2cb2ed37ea1dd85dd3afcc1c306.
// Owned .data 005d1c1c..005d1c20, 5 bytes, sha256 b36afdab285bc9e84db530a17a7aabae6776c3ce10adb4b928efdac585135d1e.
// Owned .data 0065b928..0065b92b, 4 bytes loader-zero.
#include "audio_transition_finish_643.hpp"

#include <cstddef>

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Original x86 naked forwarding required for 004ae4d0 alias.
#endif

namespace porsche {

char audio_transition_wildcard_fmt_005d1c1c[5] = "*-%s";
std::uint32_t audio_transition_word_0065b928 = 0u;

namespace {

inline std::uint8_t* ptr_from_va(std::uint32_t va) noexcept {
    return reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(va));
}

inline std::int32_t abs32_mod(std::uint32_t sum, std::int32_t divisor) noexcept {
    const std::uint32_t sign_mask =
        (static_cast<std::int32_t>(sum) < 0) ? 0xffffffffu : 0u;
    const std::int32_t abs_val =
        static_cast<std::int32_t>((sum ^ sign_mask) - sign_mask);
    return abs_val % divisor;
}

} // namespace

void __cdecl application_audio_transition_finish_004ae4d0(
    std::uint32_t pattern_arg, std::uint32_t mode) {
    std::uint32_t root = audio_resource_query_root_00656ab4;
    if (root == 0u) {
        return;
    }

    const std::int32_t saved_count =
        *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u);
    std::uint8_t saved_entries[128];
    if (saved_count > 0) {
        const std::uint8_t* const src = ptr_from_va(root) + 0xe8u;
        for (std::int32_t i = 0; i < saved_count; ++i) {
            saved_entries[i] = src[i];
        }
    }

    if (pattern_arg != 0u) {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x08u) = 0u;
        root = audio_resource_query_root_00656ab4;
        for (std::int32_t i = 0;
             i < *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x04u);
             ++i) {
            if (*reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u) >= 0x80) {
                break;
            }
            const std::uint32_t source =
                *reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x88u);
            const std::uint32_t located = audio_resource_locate_005666f0(
                source, 0u, static_cast<std::uint32_t>(i), 0u, 0u);
            const std::uint32_t matched = audio_transition_pattern_match_004a5f90(
                reinterpret_cast<const char*>(static_cast<std::uintptr_t>(located)),
                reinterpret_cast<char*>(static_cast<std::uintptr_t>(pattern_arg)));
            if (matched != 0u) {
                std::uint8_t* const write_root = ptr_from_va(audio_resource_query_root_00656ab4);
                const std::uint32_t cur =
                    *reinterpret_cast<const std::uint32_t*>(write_root + 0x08u);
                write_root[0xe8u + cur] = static_cast<std::uint8_t>(i);
                std::uint8_t* const inc_root = ptr_from_va(audio_resource_query_root_00656ab4);
                *reinterpret_cast<std::uint32_t*>(inc_root + 0x08u) += 1u;
            }
            root = audio_resource_query_root_00656ab4;
        }

        if (*reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u) == 0) {
            const char* const pat_str =
                reinterpret_cast<const char*>(static_cast<std::uintptr_t>(pattern_arg));
            std::size_t len = 0u;
            while (pat_str[len] != '\0') {
                ++len;
            }
            if (len < 0x3du) {
                char formatted_pattern[128];
                const std::uint32_t raw_args[1] = { pattern_arg };
                (void)formatter_entry_raw_005a0fbf(
                    formatted_pattern, audio_transition_wildcard_fmt_005d1c1c, raw_args);
                root = audio_resource_query_root_00656ab4;
                if (root != 0u) {
                    *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x08u) = 0u;
                    root = audio_resource_query_root_00656ab4;
                    for (std::int32_t i = 0;
                         i < *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x04u);
                         ++i) {
                        if (*reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u) >= 0x80) {
                            break;
                        }
                        const std::uint32_t source =
                            *reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x88u);
                        const std::uint32_t located = audio_resource_locate_005666f0(
                            source, 0u, static_cast<std::uint32_t>(i), 0u, 0u);
                        const std::uint32_t matched = audio_transition_pattern_match_004a5f90(
                            reinterpret_cast<const char*>(static_cast<std::uintptr_t>(located)),
                            formatted_pattern);
                        if (matched != 0u) {
                            std::uint8_t* const write_root =
                                ptr_from_va(audio_resource_query_root_00656ab4);
                            const std::uint32_t cur =
                                *reinterpret_cast<const std::uint32_t*>(write_root + 0x08u);
                            write_root[0xe8u + cur] = static_cast<std::uint8_t>(i);
                            std::uint8_t* const inc_root =
                                ptr_from_va(audio_resource_query_root_00656ab4);
                            *reinterpret_cast<std::uint32_t*>(inc_root + 0x08u) += 1u;
                        }
                        root = audio_resource_query_root_00656ab4;
                    }
                }
            }
        }
    }

    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x00u) == 0u) {
        return;
    }
    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x08u) == 0u) {
        return;
    }

    if (audio_transition_word_0065b928 != 0u) {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x24u) = 1u;
    } else {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x24u) =
            application_state_006573e8.word(0x00657a5cu);
    }

    root = audio_resource_query_root_00656ab4;
    const std::int32_t cur_count =
        *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u);
    std::int32_t selected_slot = 0;

    if (mode == 1u && cur_count > 0) {
        const std::uint32_t prng = render_seed_prng_next_00538040();
        const std::uint32_t tick = platform_get_tick_count();
        root = audio_resource_query_root_00656ab4;
        const std::int32_t divisor =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u);
        const std::int32_t rem = abs32_mod(tick + prng, divisor);
        const std::int32_t picked = static_cast<std::int32_t>(
            static_cast<std::int8_t>(ptr_from_va(root)[0xe8u + rem]));
        std::int32_t write_pos = 0;
        if (saved_count > 0) {
            for (; write_pos < saved_count; ++write_pos) {
                ptr_from_va(root)[0xe8u + write_pos] = saved_entries[write_pos];
                root = audio_resource_query_root_00656ab4;
            }
        }
        ptr_from_va(root)[0xe8u + write_pos] = static_cast<std::uint8_t>(picked);
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::int32_t*>(ptr_from_va(root) + 0x08u) = saved_count;
        root = audio_resource_query_root_00656ab4;
        selected_slot = write_pos;
    } else if (mode == 2u && cur_count > 0) {
        const std::uint32_t prng = render_seed_prng_next_00538040();
        const std::uint32_t tick = platform_get_tick_count();
        root = audio_resource_query_root_00656ab4;
        const std::int32_t divisor =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u);
        const std::int32_t rem = abs32_mod(tick + prng, divisor);
        const std::int32_t picked = static_cast<std::int32_t>(
            static_cast<std::int8_t>(ptr_from_va(root)[0xe8u + rem]));
        ptr_from_va(root)[0xe8u] = static_cast<std::uint8_t>(picked);
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x08u) = 0u;
        root = audio_resource_query_root_00656ab4;
        selected_slot = 0;
    } else if (cur_count == 1) {
        selected_slot = 0;
    } else if (pattern_arg != 0u) {
        const std::uint32_t prng = render_seed_prng_next_00538040();
        const std::uint32_t tick = platform_get_tick_count();
        root = audio_resource_query_root_00656ab4;
        const std::int32_t divisor =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x08u);
        selected_slot = abs32_mod(tick + prng, divisor);
    } else {
        const std::int32_t n = cur_count;
        const std::uint32_t prng = render_seed_prng_next_00538040();
        const std::uint32_t tick = platform_get_tick_count();
        const std::int32_t rem = abs32_mod(tick + prng, n - 1);
        root = audio_resource_query_root_00656ab4;
        const std::int32_t cur_slot =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x0cu);
        const std::int32_t sum_idx = static_cast<std::int32_t>(
            static_cast<std::uint32_t>(rem) + static_cast<std::uint32_t>(cur_slot) + 1u);
        selected_slot = sum_idx % n;
    }

    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x14u) != 0u) {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x14u) = 1u;
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::int32_t*>(ptr_from_va(root) + 0x0cu) = selected_slot;
    } else if (*reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x0cu) > -1) {
        const std::int32_t slot =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        (void)audio_stream_service_ramp_00566ae0(slot, 500, 0);
        *reinterpret_cast<std::uint32_t*>(
            ptr_from_va(audio_resource_query_root_00656ab4) + 0x20u) = 500u;
        *reinterpret_cast<std::uint32_t*>(
            ptr_from_va(audio_resource_query_root_00656ab4) + 0x14u) = 1u;
        *reinterpret_cast<std::int32_t*>(
            ptr_from_va(audio_resource_query_root_00656ab4) + 0x0cu) = selected_slot;
        *reinterpret_cast<std::uint32_t*>(
            ptr_from_va(audio_resource_query_root_00656ab4) + 0x28u) = 0u;
    } else {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x20u) = 0u;
        root = audio_resource_query_root_00656ab4;
        const std::int32_t slot =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        (void)audio_stream_service_volume_00567810(slot, 0u);
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::int32_t*>(ptr_from_va(root) + 0x0cu) = selected_slot;
        root = audio_resource_query_root_00656ab4;
        const std::int32_t idx =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x0cu);
        const std::int32_t entry_id = static_cast<std::int32_t>(
            static_cast<std::int8_t>(ptr_from_va(root)[0xe8u + idx]));
        const std::uint32_t source =
            *reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x88u);
        std::uint32_t entry_size = static_cast<std::uint32_t>(saved_count);
        const std::uint32_t located = audio_resource_locate_005666f0(
            source, 0u, static_cast<std::uint32_t>(entry_id),
            static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&entry_size)), 0u);
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x28u) = located;
        root = audio_resource_query_root_00656ab4;
        const std::int32_t channel =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        if (channel >= 0) {
            const std::int32_t started = audio_service_stream_start_00567720(
                static_cast<std::uint32_t>(channel), 1000u, root + 0xa8u, entry_size);
            root = audio_resource_query_root_00656ab4;
            *reinterpret_cast<std::int32_t*>(ptr_from_va(root) + 0x74u) = started;
            root = audio_resource_query_root_00656ab4;
        }
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x14u) = 2u;
        root = audio_resource_query_root_00656ab4;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x170u) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x18cu) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x174u) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x178u) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x17cu) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x180u) = 0u;
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x188u) = 0u;
    }

    *reinterpret_cast<std::uint32_t*>(
        ptr_from_va(audio_resource_query_root_00656ab4) + 0x10u) = 1u;
    *reinterpret_cast<std::uint32_t*>(
        ptr_from_va(audio_resource_query_root_00656ab4) + 0x1cu) = 0u;
    if (pattern_arg != 0u) {
        *reinterpret_cast<std::uint32_t*>(
            ptr_from_va(audio_resource_query_root_00656ab4) + 0x18u) = 1u;
    }
}

__declspec(naked) void __cdecl frame_services_boundary_004ae4d0(
    std::uint32_t, std::uint32_t) {
    __asm jmp application_audio_transition_finish_004ae4d0
}

void __cdecl frame_services_boundary_004ae8c0(std::uint32_t shifted_product) {
    std::uint32_t root = audio_resource_query_root_00656ab4;
    if (root == 0u) {
        return;
    }
    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x00u) == shifted_product) {
        return;
    }
    if (shifted_product == 0u) {
        *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x00u) = 0u;
        (void)frame_services_boundary_004ae3c0(0u);
        return;
    }

    bool did_ramp = false;
    if (*reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x20u) != 0u) {
        const std::int32_t channel =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        if (channel >= 0) {
            const std::int32_t status = audio_stream_service_status_00567850(channel);
            root = audio_resource_query_root_00656ab4;
            if (status > 0) {
                const std::int32_t cur_vol =
                    *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x00u);
                if (cur_vol > 0) {
                    const std::int32_t ramp_ms =
                        *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x20u);
                    const std::int32_t prod1 = static_cast<std::int32_t>(
                        static_cast<std::uint32_t>(ramp_ms) *
                        static_cast<std::uint32_t>(status));
                    const std::int32_t rem_ms = prod1 / cur_vol;
                    if (rem_ms != 0) {
                        const std::int32_t prod2 = static_cast<std::int32_t>(
                            static_cast<std::uint32_t>(rem_ms) * shifted_product);
                        const std::int32_t start_vol = prod2 / ramp_ms;
                        const std::int32_t ch2 =
                            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
                        (void)audio_stream_service_volume_00567810(
                            ch2, static_cast<std::uint32_t>(start_vol));
                        root = audio_resource_query_root_00656ab4;
                        const std::int32_t ch3 =
                            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
                        (void)audio_stream_service_ramp_00566ae0(ch3, rem_ms, 0);
                        root = audio_resource_query_root_00656ab4;
                        did_ramp = true;
                    }
                }
            }
        }
    }

    if (!did_ramp) {
        const std::int32_t channel =
            *reinterpret_cast<const std::int32_t*>(ptr_from_va(root) + 0x70u);
        if (channel >= 0 &&
            *reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x14u) != 2u) {
            (void)audio_stream_service_volume_00567810(channel, shifted_product);
            root = audio_resource_query_root_00656ab4;
        }
    }

    const std::uint32_t old_vol =
        *reinterpret_cast<const std::uint32_t*>(ptr_from_va(root) + 0x00u);
    *reinterpret_cast<std::uint32_t*>(ptr_from_va(root) + 0x00u) = shifted_product;
    if (old_vol == 0u) {
        application_audio_transition_finish_004ae4d0(0u, 0u);
    }
}

} // namespace porsche
