// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00555a10..00555bbe (431B), 00555fa0..005560ad (270B),
// and 005560b0..005561c5 (278B).
#include "render_clock_calibration_679.hpp"

#include <cmath>
#include <intrin.h>

extern "C" {
std::int32_t __stdcall QueryPerformanceFrequency(std::int64_t* frequency);
std::int32_t __stdcall QueryPerformanceCounter(std::int64_t* performance_count);
}

namespace porsche {

namespace {

std::int32_t __stdcall os_query_performance_frequency(std::int64_t* frequency) {
    return ::QueryPerformanceFrequency(frequency);
}

std::int32_t __stdcall os_query_performance_counter(std::int64_t* performance_count) {
    return ::QueryPerformanceCounter(performance_count);
}

std::int32_t round_to_i32(float value) {
    return static_cast<std::int32_t>(std::lrintf(value));
}

} // namespace

RenderClockQueryPerformanceFrequency render_clock_query_performance_frequency =
    os_query_performance_frequency;
RenderClockQueryPerformanceCounter render_clock_query_performance_counter =
    os_query_performance_counter;

std::uint32_t cpu_has_p6_005deb14 = 0u;
std::uint32_t cpu_has_rdtsc_005deb24 = 1u;
std::uint32_t cpu_is_cyrix_005deb34 = 0u;
std::uint32_t cpu_is_amd_005deb38 = 0u;

std::int32_t __cdecl render_clock_quantize_hz_00555a10(std::int32_t raw_hz) {
    // Shared .rdata constants in Porsche.exe (not redefined as globals here):
    // 005b3f30 (0x3d088889), 005b2468 (0x3e800000 = 0.25f), 005b2408 (0x41f00000 = 30.0f),
    // 005bc374 (0x3cf5c290), 005bc370 (0x42055555), 005b27a4 (0x3f8ccccd),
    // 005b24a8 (0x3f800000 = 1.0f), 005b24c0 (0x0 = 0.0), 005bc368 (0xc000000000000000 = -2.0).
    constexpr float kInvThirty = 0x1.111112p-5f;
    constexpr float kQuarter = 0.25f;
    constexpr float kThirty = 30.0f;
    constexpr float kInvThirtyThree = 0x1.eb852p-6f;
    constexpr float kThirtyThree = 0x1.0aaaaap+5f;
    constexpr float kWeightHigh = 0x1.19999ap+0f;

    const std::int32_t mhz =
        static_cast<std::int32_t>(static_cast<std::uint32_t>(raw_hz) + 500000u) / 1000000;
    const float step = (mhz <= 292) ? 75.0f : 50.0f;
    const float f_mhz = static_cast<float>(mhz);

    const std::int32_t n30 = round_to_i32(static_cast<float>(
        static_cast<double>(mhz) * static_cast<double>(kInvThirty) + static_cast<double>(kQuarter)));
    const std::int32_t cand30 = round_to_i32(static_cast<float>(
        static_cast<double>(n30) * static_cast<double>(kThirty)));

    const std::int32_t n33 = round_to_i32(static_cast<float>(
        static_cast<double>(f_mhz) * static_cast<double>(kInvThirtyThree) +
        static_cast<double>(kQuarter)));
    const std::int32_t cand33 = round_to_i32(static_cast<float>(
        static_cast<double>(n33) * static_cast<double>(kThirtyThree)));

    const std::int32_t n_step = round_to_i32(static_cast<float>(
        static_cast<double>(f_mhz) / static_cast<double>(step) + static_cast<double>(kQuarter)));
    const std::int32_t cand_step = round_to_i32(static_cast<float>(
        static_cast<double>(n_step) * static_cast<double>(step)));

    float err30 = static_cast<float>(
        static_cast<double>(cand30 - mhz) * static_cast<double>(kWeightHigh));
    if (err30 < 0.0f) {
        err30 = static_cast<float>(static_cast<double>(err30) * -2.0);
    }

    const float w33 = (mhz > 392) ? kWeightHigh : 1.0f;
    float err33 = static_cast<float>(
        static_cast<double>(cand33 - mhz) * static_cast<double>(w33));
    if (err33 < 0.0f) {
        err33 = static_cast<float>(static_cast<double>(err33) * -2.0);
    }

    const float w_step = (mhz > 392) ? 1.0f : kWeightHigh;
    double err_step = static_cast<double>(cand_step - mhz) * static_cast<double>(w_step);
    if (err_step < 0.0) {
        err_step *= -2.0;
    }

    float best_err = err33;
    std::int32_t best_cand = cand33;
    if (err30 < err33 && mhz > 52 && mhz < 188) {
        best_err = err30;
        best_cand = cand30;
    }
    if (err_step < static_cast<double>(best_err)) {
        best_cand = cand_step;
    }

    return static_cast<std::int32_t>(static_cast<std::uint32_t>(best_cand) * 1000000u);
}

std::int32_t __cdecl render_clock_measure_qpc_rdtsc_00555fa0() {
    std::int64_t freq = 0;
    (void)render_clock_query_performance_frequency(&freq);
    const std::int32_t freq_low = static_cast<std::int32_t>(static_cast<std::uint64_t>(freq));

    std::uint32_t min1 = 0u;
    std::uint32_t min2 = 0u;
    for (std::int32_t iter = 0; iter < 5; ++iter) {
        std::int64_t start_qpc = 0;
        (void)render_clock_query_performance_counter(&start_qpc);
        const std::uint32_t start_low = static_cast<std::uint32_t>(start_qpc);

        std::int32_t countdown = 1000000;
        std::uint32_t last_ret = 0u;
        for (;;) {
            std::int64_t cur_qpc = 0;
            last_ret = static_cast<std::uint32_t>(render_clock_query_performance_counter(&cur_qpc));
            const std::uint32_t cur_low = static_cast<std::uint32_t>(cur_qpc);
            if (cur_low == start_low) {
                --countdown;
                if (countdown == 0) {
                    break;
                }
            }
            if (static_cast<std::int32_t>(cur_low - start_low) >= 1) {
                break;
            }
        }

        const std::uint32_t tsc_start = (cpu_has_rdtsc_005deb24 != 0u)
            ? static_cast<std::uint32_t>(__rdtsc())
            : last_ret;

        std::int64_t t0_qpc = 0;
        (void)render_clock_query_performance_counter(&t0_qpc);
        const std::uint32_t t0_low = static_cast<std::uint32_t>(t0_qpc);

        countdown = 1000000;
        const std::int32_t target_delta = freq_low / 5;
        for (;;) {
            std::int64_t t1_qpc = 0;
            last_ret = static_cast<std::uint32_t>(render_clock_query_performance_counter(&t1_qpc));
            const std::uint32_t t1_low = static_cast<std::uint32_t>(t1_qpc);
            if (t1_low == t0_low) {
                --countdown;
                if (countdown == 0) {
                    break;
                }
            }
            if (static_cast<std::int32_t>(t1_low - t0_low) >= target_delta) {
                break;
            }
        }

        const std::uint32_t tsc_end = (cpu_has_rdtsc_005deb24 != 0u)
            ? static_cast<std::uint32_t>(__rdtsc())
            : last_ret;
        const std::int32_t delta = static_cast<std::int32_t>(tsc_end - tsc_start);

        if (iter != 0) {
            if (delta < static_cast<std::int32_t>(min1) || min1 == 0u) {
                min2 = min1;
                min1 = static_cast<std::uint32_t>(delta);
            } else if (delta < static_cast<std::int32_t>(min2) || min2 == 0u) {
                min2 = static_cast<std::uint32_t>(delta);
            }
        }
    }

    if (min2 == 0u) {
        min2 = min1;
    }
    (void)min2;
    return 0x7f000000;
}

std::int32_t __cdecl render_clock_measure_div_loop_005560b0() {
    constexpr float kOneMillion = 1000000.0f;
    constexpr float kFactorAmd = 0x1.830204p-15f;
    constexpr float kFactorP6 = 0x1.5acd56p-15f;
    constexpr float kFactorPentium = 0x1.e1dedp-15f;
    constexpr float kFactorCyrix = 0x1.e0a8a8p-15f;
    constexpr float kFactorDefault = 0x1.e9e528p-15f;

    std::int32_t min1 = 0;
    std::int32_t min2 = 0;

    for (std::int32_t iter = 0; iter < 5; ++iter) {
        application_audio_wait_0053c380(1);
        (void)audio_probe_clock_0053c2e0();

        const std::int32_t threshold = static_cast<std::int32_t>(timer_rate_005deb48) >> 2;
        const auto* const clock_ptr =
            static_cast<const volatile std::uint32_t*>(&clock_worker_iterations_006b7c7c);
        const std::uint32_t start_iter = *clock_ptr;

        std::int32_t count = 0;
        for (;;) {
            volatile std::int32_t dummy_div = 0x5555aaaa;
            dummy_div = dummy_div / 0x21;
            (void)dummy_div;
            const std::uint32_t cur_iter = *clock_ptr;
            ++count;
            if (static_cast<std::int32_t>(cur_iter - start_iter) >= threshold) {
                break;
            }
        }

        if (iter != 0) {
            if (count < min1 || min1 == 0) {
                min2 = min1;
                min1 = count;
            } else if (count < min2 || min2 == 0) {
                min2 = count;
            }
        }
    }

    if (min2 == 0) {
        min2 = min1;
    }

    const std::int32_t scaled_count =
        static_cast<std::int32_t>(static_cast<std::uint32_t>(min2) << 2);

    float factor = kFactorDefault;
    if (cpu_is_amd_005deb38 != 0u) {
        factor = kFactorAmd;
    } else if (cpu_has_p6_005deb14 != 0u) {
        factor = kFactorP6;
    } else if (copy_flag_005deb10 != 0u) {
        factor = kFactorPentium;
    } else if (cpu_is_cyrix_005deb34 != 0u) {
        factor = kFactorCyrix;
    }

    const float scaled_hz = static_cast<float>(
        static_cast<double>(scaled_count) * static_cast<double>(factor) *
        static_cast<double>(kOneMillion));
    return round_to_i32(scaled_hz);
}

} // namespace porsche
