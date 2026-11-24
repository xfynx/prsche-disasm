// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Original 004123e0..00412724 (837B, supplement), 00412730..0041279f (112B),
// 004127a0..004128a8 (265B), 004128b0..00412c95 (998B), 00412cf0..00412df4 (261B),
// 004938a0..00493950 (177B), 00493980..00493a0b (140B), 00533810..00533874 (101B),
// 00533880..005338c5 (70B), 00533910..00533b34 (549B), 00533b40..00533b63 (36B).
#include "ff_effect_frame_tick_819.hpp"

#include <cstring>

namespace porsche {

std::int32_t ff_effect_cooldown_005e9540 = 0;

const char startup_audio_heap_fmt_005d1400[26] = "audio heap used %d bytes\n";
const char startup_mem_left_fmt_005d6e3c[36] = "Memory left after gamestartup = %d\n";

namespace {

constexpr std::size_t kOffEnabled = 0x04u;       // 005e940c
constexpr std::size_t kOffSlotIdx = 0x08u;       // 005e9410
constexpr std::size_t kOffCarPtr = 0x0cu;        // 005e9414
constexpr std::size_t kOffResetFlag = 0x10u;     // 005e9418
constexpr std::size_t kOffZeroSpdFlag = 0x14u;   // 005e941c
constexpr std::size_t kOffTable = 0x18u;         // 005e9420
constexpr std::size_t kOffRumbling = 0x118u;     // 005e9520
constexpr std::size_t kOffPrevFreq = 0x11cu;     // 005e9524
constexpr std::size_t kOffPrevMag = 0x120u;      // 005e9528
constexpr std::size_t kOffTimer = 0x124u;        // 005e952c
constexpr std::size_t kOffSpringActive = 0x128u; // 005e9530
constexpr std::size_t kOffGear = 0x12cu;         // 005e9534
constexpr std::size_t kOffLastColl = 0x130u;     // 005e9538

inline std::uint32_t load_u32(const void* base, std::size_t off) {
    std::uint32_t v = 0u;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + off, sizeof(v));
    return v;
}

inline std::int32_t load_i32(const void* base, std::size_t off) {
    std::int32_t v = 0;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + off, sizeof(v));
    return v;
}

inline std::uint16_t load_u16(const void* base, std::size_t off) {
    std::uint16_t v = 0u;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + off, sizeof(v));
    return v;
}

inline float load_f32(const void* base, std::size_t off) {
    float v = 0.0f;
    std::memcpy(&v, static_cast<const std::uint8_t*>(base) + off, sizeof(v));
    return v;
}

inline std::int32_t ff_state_i32(std::size_t off) {
    return load_i32(frame_control_ff_state_005e9408, off);
}

inline std::uint32_t ff_state_u32(std::size_t off) {
    return load_u32(frame_control_ff_state_005e9408, off);
}

inline void ff_state_set_i32(std::size_t off, std::int32_t val) {
    std::memcpy(frame_control_ff_state_005e9408 + off, &val, sizeof(val));
}

inline void ff_state_set_u32(std::size_t off, std::uint32_t val) {
    std::memcpy(frame_control_ff_state_005e9408 + off, &val, sizeof(val));
}

inline std::int16_t ff_slot_word(std::uint32_t row, std::size_t word_index) {
    std::int16_t v = 0;
    std::memcpy(&v, frame_control_ff_state_005e9408 + kOffTable + row * 8u + word_index * 2u, sizeof(v));
    return v;
}

inline double calc_wheel_force_sum(const void* car, std::uint16_t target_kind, int& count) {
    double sum = 0.0;
    const std::uint8_t* const car_bytes = static_cast<const std::uint8_t*>(car);
    for (std::uint32_t i = 0u; i < 20u; ++i) {
        const std::uint8_t* const wheel = reinterpret_cast<const std::uint8_t*>(
            static_cast<std::uintptr_t>(load_u32(car_bytes, 0x768u + i * 4u)));
        if (load_u16(wheel, 0x26u) == target_kind) {
            ++count;
            const double scale = 1.5f - static_cast<double>(load_f32(wheel, 0x60u)) * 0.004999999888241291f;
            double inner = 0.0f;
            std::int32_t n = 0;
            for (std::uint32_t j = 0u; j < 10u; ++j) {
                if (wheel[0x48u + j] != 0u) {
                    inner += static_cast<double>(load_f32(car_bytes, 0x4e4u + j * 4u));
                    ++n;
                }
            }
            if (n > 1) {
                inner /= static_cast<double>(n);
            }
            sum += inner * scale + static_cast<double>(load_f32(wheel, 0x164u));
        }
    }
    return sum;
}

void release_rumble_slot() {
    if (ff_state_i32(kOffRumbling) != 0) {
        const std::uint32_t row = ff_state_u32(kOffSlotIdx);
        frame_control_slot_release_005338d0(ff_slot_word(row, 1u));
    }
    ff_state_set_i32(kOffRumbling, 0);
    ff_state_set_i32(kOffPrevFreq, 0);
    ff_state_set_i32(kOffPrevMag, 0);
}

void release_rumble_and_spring() {
    release_rumble_slot();
    if (ff_state_i32(kOffSpringActive) != 0) {
        const std::uint32_t row = ff_state_u32(kOffSlotIdx);
        frame_control_slot_release_005338d0(ff_slot_word(row, 3u));
    }
    ff_state_set_i32(kOffSpringActive, 0);
}

std::int32_t ftol_trunc(double v) {
    return static_cast<std::int32_t>(v);
}

using EffectStartFn = std::uint32_t(__stdcall*)(void*, std::uint32_t, std::uint32_t);
using EffectSetParamsFn = std::uint32_t(__stdcall*)(void*, void*, std::uint32_t);

} // namespace

void __cdecl startup_sequence_report_005a177b(std::uint32_t format_va, std::uint32_t value) {
    const char* fmt = nullptr;
    if (format_va == 0x005d1400u) {
        fmt = startup_audio_heap_fmt_005d1400;
    } else if (format_va == 0x005d6e3cu) {
        fmt = startup_mem_left_fmt_005d6e3c;
    } else {
        fmt = reinterpret_cast<const char*>(static_cast<std::uintptr_t>(format_va));
    }
    (void)formatter_stdio_printf_005a177b(fmt, value);
}

std::uint32_t __cdecl ff_effect_start_retry_00533880(
    void* input_dev, void* effect_obj, std::uint32_t iterations, std::uint32_t flags) {
    void* const* vt = *static_cast<void* const* const*>(effect_obj);
    auto start_fn = reinterpret_cast<EffectStartFn>(vt[7]);
    std::uint32_t hr = start_fn(effect_obj, iterations, flags);
    if (hr == 0x8007000cu || hr == 0x8007001eu || hr == 0x80040205u) {
        auto* const dev = static_cast<InputDevice*>(input_dev);
        hr = dev->vtable->acquire_1c(dev);
        if (hr == 0u) {
            void* const* vt2 = *static_cast<void* const* const*>(effect_obj);
            hr = reinterpret_cast<EffectStartFn>(vt2[7])(effect_obj, iterations, flags);
        }
    }
    return hr;
}

std::uint32_t __cdecl ff_effect_slot_active_00533b40(std::int32_t slot) {
    if (slot < 0) {
        return 0u;
    }
    const FeEffectEntry& entry = frame_control_effects_0069cb10[slot];
    if (entry.duration_08 != 0xffffffffu) {
        return 0u;
    }
    return entry.field_80;
}

void __cdecl ff_effect_slot_start_00533810(std::int32_t slot) {
    if (slot < 0 || slot >= 32) {
        return;
    }
    FeEffectEntry& entry = frame_control_effects_0069cb10[slot];
    const std::int32_t dev_slot = entry.input_slot_8c;
    if (dev_slot == -1) {
        return;
    }
    const std::uint32_t hr = ff_effect_start_retry_00533880(
        input_slots_006be040[dev_slot].device, entry.effect_object_88, 1u, 0u);
    entry.field_80 = (hr == 0u || hr == 1u) ? 1u : 0u;
}

std::uint32_t __cdecl ff_effect_update_params_00533910(
    std::int32_t slot,
    std::uint32_t start_mode,
    const void* type_specific_ptr,
    std::uint32_t* duration_ptr,
    const std::uint32_t* gain_ptr,
    const std::int32_t* button_ptr,
    const std::uint32_t* direction_deg_ptr,
    const std::uint32_t* envelope_4words_ptr) {
    if (slot < 0 || slot >= 32) {
        return 0u;
    }
    FeEffectEntry& entry = frame_control_effects_0069cb10[slot];
    if (entry.input_slot_8c == -1) {
        return 0u;
    }

    std::uint32_t flags = 0u;
    if (direction_deg_ptr != nullptr) {
        const std::int32_t dir = static_cast<std::int32_t>(*direction_deg_ptr) * 100;
        if (entry.direction_78 != dir) {
            flags = 0x40u;
            entry.direction_78 = dir;
        }
    }
    if (duration_ptr != nullptr) {
        std::uint32_t dur = *duration_ptr;
        if (dur != 0xffffffffu && dur > 0x16e360u) {
            dur = 0x16e360u;
            *duration_ptr = dur;
        }
        if (entry.duration_08 != dur) {
            flags |= 1u;
            entry.duration_08 = dur;
        }
    }
    if (gain_ptr != nullptr) {
        const std::uint32_t gain = *gain_ptr * 100u;
        if (entry.gain_10 != gain) {
            flags |= 4u;
            entry.gain_10 = gain;
        }
    }
    if (type_specific_ptr != nullptr) {
        const std::uint32_t bytes = entry.type_bytes_2c;
        if (std::memcmp(entry.type_specific_34, type_specific_ptr, bytes) != 0) {
            std::memcpy(entry.type_specific_34, type_specific_ptr, bytes);
            flags |= 0x100u;
        }
    }
    if (button_ptr != nullptr) {
        const std::int32_t raw_btn = *button_ptr;
        entry.trigger_button_14 = static_cast<std::uint32_t>(
            (raw_btn == -1) ? -1 : (raw_btn + 0x30));
        flags |= 8u;
    }
    if (envelope_4words_ptr != nullptr) {
        std::uint32_t cur[4] = {};
        std::memcpy(cur, entry.spare_64 + 4u, 16u);
        if (std::memcmp(cur, envelope_4words_ptr, 16u) != 0) {
            std::memcpy(entry.spare_64 + 4u, envelope_4words_ptr, 16u);
            flags |= 0x80u;
        }
    }

    if (flags == 0u) {
        if (start_mode == 1u) {
            if (ff_effect_slot_active_00533b40(slot) == 0u) {
                ff_effect_slot_start_00533810(slot);
            }
        } else if (start_mode == 3u) {
            frame_control_slot_download_00533760(slot);
        }
        return 0u;
    }

    void* const effect_obj = entry.effect_object_88;
    void* const* vt = *static_cast<void* const* const*>(effect_obj);
    (void)reinterpret_cast<EffectSetParamsFn>(vt[6])(effect_obj, &entry, flags);

    if (start_mode == 3u) {
        frame_control_slot_download_00533760(slot);
        return 1u;
    }
    if (start_mode == 1u || start_mode == 2u) {
        if (ff_effect_slot_active_00533b40(slot) == 0u) {
            ff_effect_slot_start_00533810(slot);
        }
    }
    return 1u;
}

double __cdecl ff_effect_calc_grip_004938a0(const void* car) {
    int count = 1;
    const double base = static_cast<double>(load_f32(car, 0x4e8u));
    const double sum = base + calc_wheel_force_sum(car, 1u, count);
    return sum / static_cast<double>(count);
}

double __cdecl ff_effect_calc_road_00493980(const void* car) {
    int count = 0;
    return calc_wheel_force_sum(car, 9u, count);
}

void __cdecl ff_effect_scale_steer_00412730(
    const void* car, std::int32_t* out_abs, std::int32_t* out_signed) {
    double val = (load_u16(car, 0x418u) == 0u)
        ? static_cast<double>(load_f32(car, 0x11c0u))
        : (static_cast<double>(load_f32(car, 0xd64u)) * 0.125);
    val = (-val) * 32500.0f;
    if (val > 10000.0f) {
        val = 10000.0f;
    } else if (val < -10000.0f) {
        val = -10000.0f;
    }
    const std::int32_t iv = ftol_trunc(val);
    *out_signed = iv;
    *out_abs = (iv < 0) ? -iv : iv;
}

void __cdecl ff_effect_update_engine_004127a0(const void* car) {
    const float rpm = load_f32(car, 0xdb4u);
    const std::int32_t rpm_norm = ftol_trunc(
        static_cast<double>(rpm) * 0.0026666666381061077f + 10.0f);
    std::int32_t excess = ftol_trunc(static_cast<double>(rpm) - 5000.0f);
    if (excess < 0) {
        excess = 0;
    }
    const std::int32_t shift = excess / 180;
    std::uint32_t mag = (10u << shift) + 0x6a4u;
    if (mag > 0x1388u) {
        mag = 0x1388u;
    }
    mag += 0xbb8u;

    const double grip = ff_effect_calc_grip_004938a0(car);
    std::uint32_t total_mag = static_cast<std::uint32_t>(
        ftol_trunc(grip * 100.0f + static_cast<double>(static_cast<std::int32_t>(mag))));
    if (total_mag > 0x2710u) {
        total_mag = 0x2710u;
    }

    const std::uint32_t period = static_cast<std::uint32_t>(
        ftol_trunc(1000000.0 / static_cast<double>(rpm_norm) + 0.5));
    const std::uint32_t periodic[4] = {total_mag, 0u, 0u, period};

    const std::uint32_t row = ff_state_u32(kOffSlotIdx);
    (void)ff_effect_update_params_00533910(
        ff_slot_word(row, 2u), 1u, periodic, nullptr,
        &ff_init_config_00657c08, nullptr, nullptr, nullptr);
}

void __cdecl ff_effect_update_speed_gear_004128b0(const void* car) {
    double spd = static_cast<double>(load_f32(car, 0x35cu));
    if (spd < 0.0f) {
        spd = -spd;
    }
    const float kmh = static_cast<float>(spd * 2.240000009536743f);
    if (kmh < 2.0f) {
        release_rumble_slot();
        return;
    }

    struct SpeedBand { float limit; std::int32_t freq; std::int32_t mag; };
    static constexpr SpeedBand kBands[] = {
        {5.0f,   6,  0x9c4},
        {10.0f,  6,  0xbb8},
        {15.0f,  7,  0xdac},
        {20.0f,  8,  0xfa0},
        {30.0f,  9,  0x1194},
        {40.0f,  10, 0x1388},
        {60.0f,  11, 0x1194},
        {80.0f,  12, 0xfa0},
        {100.0f, 13, 0xfa0},
        {140.0f, 14, 0xdac},
        {170.0f, 15, 0xdac},
        {200.0f, 16, 0xdac},
    };
    std::int32_t freq = 17;
    std::int32_t mag = 0xbb8;
    for (const auto& band : kBands) {
        if (kmh < band.limit) {
            freq = band.freq;
            mag = band.mag;
            break;
        }
    }

    std::uint32_t gear = load_u32(car, 0x464u);
    ff_state_set_u32(kOffGear, gear);
    const double road = ff_effect_calc_road_00493980(car);
    if (!(road < 30.0f) && gear < 3u) {
        gear = 3u;
        ff_state_set_u32(kOffGear, gear);
    }
    if (!(road < 45.0f) && gear < 2u) {
        gear = 2u;
        ff_state_set_u32(kOffGear, gear);
    }
    if (!(road < 60.0f) || load_u32(car, 0xdb0u) == 0u) {
        gear = 7u;
        ff_state_set_u32(kOffGear, gear);
    }

    switch (gear) {
    case 1u:
    case 8u:
        release_rumble_slot();
        ff_state_set_i32(kOffPrevMag, mag);
        ff_state_set_i32(kOffPrevFreq, freq);
        return;
    case 2u:
    case 10u:
        mag -= 0x1f4;
        ++freq;
        break;
    case 3u:
        mag -= 0x3e8;
        freq -= 2;
        break;
    case 4u:
        mag += 0x3e8;
        ++freq;
        break;
    case 5u:
        mag -= 0x5dc;
        freq += 4;
        break;
    case 6u:
        ff_state_set_i32(kOffPrevMag, mag);
        ff_state_set_i32(kOffPrevFreq, freq);
        return;
    case 7u:
    case 11u:
        mag += 0x7d0;
        freq -= 5;
        break;
    case 9u:
        freq -= 3;
        break;
    default:
        release_rumble_slot();
        ff_state_set_i32(kOffPrevMag, mag);
        ff_state_set_i32(kOffPrevFreq, freq);
        return;
    }

    if (ff_state_i32(kOffRumbling) == 0 ||
        ff_state_i32(kOffPrevFreq) != freq ||
        ff_state_i32(kOffPrevMag) != mag) {
        const std::uint32_t period = static_cast<std::uint32_t>(
            ftol_trunc(1000000.0 / static_cast<double>(static_cast<std::uint32_t>(freq)) + 0.5));
        const std::uint32_t periodic[4] = {
            static_cast<std::uint32_t>(mag), 0u, 0u, period};
        const std::uint32_t row = ff_state_u32(kOffSlotIdx);
        (void)ff_effect_update_params_00533910(
            ff_slot_word(row, 1u), 1u, periodic, nullptr,
            &ff_init_config_00657be8, nullptr, nullptr, nullptr);
        ff_state_set_i32(kOffRumbling, 1);
    }
    ff_state_set_i32(kOffPrevMag, mag);
    ff_state_set_i32(kOffPrevFreq, freq);
}

void __cdecl ff_effect_trigger_collision_00412cf0(
    std::int32_t* direction_ptr,
    std::uint32_t* duration_ptr,
    const std::uint32_t* strength_ptr) {
    if (ff_init_config_00657c28 == 0u) {
        return;
    }
    const std::int32_t now = static_cast<std::int32_t>(startup_clock_word_006559e0);
    if (now < ff_state_i32(kOffLastColl)) {
        return;
    }

    const std::int32_t dur_ticks = static_cast<std::int32_t>(*duration_ptr << 7u);
    const std::int32_t next_tick = (dur_ticks / 900000) + now;
    ff_state_set_i32(kOffLastColl, next_tick);

    const std::uint32_t row = ff_state_u32(kOffSlotIdx);
    const std::uint32_t* const dev_caps = static_cast<const std::uint32_t*>(
        fe_input_getstate_00532e10(row, 2u));
    if ((*dev_caps & 0xff00u) == 0x600u) {
        const std::int32_t dir = *direction_ptr;
        if (dir == 0 || dir == 360 || dir == 180) {
            *direction_ptr = ((startup_clock_word_006559e0 & 1u) != 0u) ? 90 : 270;
        } else if (dir > 0 && dir < 180) {
            *direction_ptr = 90;
        } else {
            *direction_ptr = 270;
        }
    }

    const std::uint32_t dur_u = *duration_ptr;
    const std::uint32_t str_u = *strength_ptr;
    const std::uint32_t ramp[4] = {
        str_u, dur_u >> 1u, str_u, dur_u - str_u};
    (void)ff_effect_update_params_00533910(
        ff_slot_word(row, 0u), 1u, strength_ptr, duration_ptr,
        &ff_init_config_00657c28, nullptr,
        reinterpret_cast<const std::uint32_t*>(direction_ptr), ramp);
}

void __cdecl ff_effect_frame_tick_004123e0() {
    const void* const car = reinterpret_cast<const void*>(
        static_cast<std::uintptr_t>(ff_state_u32(kOffCarPtr)));
    if (car == nullptr || ff_state_i32(kOffEnabled) == 0 ||
        static_cast<std::int32_t>(application_state_006573e8.word(0x00657424u)) >= 2 ||
        ff_init_gain_00657bc8 == 0u) {
        return;
    }

    if (static_cast<double>(load_f32(car, 0x424u)) < 0.0f) {
        if (ff_state_i32(kOffZeroSpdFlag) == 0) {
            release_rumble_and_spring();
            ff_state_set_i32(kOffZeroSpdFlag, 1);
        }
        return;
    }

    ff_state_set_i32(kOffZeroSpdFlag, 0);
    if (load_u16(car, 0x418u) != 0u) {
        release_rumble_and_spring();
        ff_state_set_i32(kOffResetFlag, 1);
        return;
    }

    if (ff_state_i32(kOffResetFlag) != 0) {
        if (static_cast<double>(load_f32(car, 0x35cu)) != 0.0f) {
            std::uint32_t strength = 10000u;
            std::uint32_t duration = 500u;
            std::int32_t dir = ((startup_clock_word_006559e0 & 1u) != 0u) ? 45 : 315;
            ff_effect_trigger_collision_00412cf0(&dir, &duration, &strength);
            ff_effect_cooldown_005e9540 = 2;
        }
        ff_state_set_i32(kOffResetFlag, 0);
    }

    const std::int32_t timer = ff_state_i32(kOffTimer);
    if (timer != 0) {
        ff_state_set_i32(kOffTimer, timer - 1);
        if (timer - 1 == 0) {
            release_rumble_slot();
        }
    }

    if (ff_state_i32(kOffResetFlag) == 0 &&
        ff_state_i32(kOffZeroSpdFlag) == 0 &&
        ff_init_config_00657be8 != 0u) {
        ff_effect_update_speed_gear_004128b0(car);
    }

    if (ff_effect_cooldown_005e9540 > 0) {
        --ff_effect_cooldown_005e9540;
    } else if (ff_init_config_00657c48 != 0u) {
        std::int32_t abs_val = 0;
        std::int32_t signed_val = 0;
        ff_effect_scale_steer_00412730(car, &abs_val, &signed_val);

        const std::int32_t c0 = ftol_trunc(static_cast<double>(load_f32(car, 0x55cu)));
        const float f560 = load_f32(car, 0x560u);
        std::int32_t c1 = c0;
        if (static_cast<double>(f560) < 0.0f) {
            c1 = ftol_trunc(static_cast<double>(c0) - static_cast<double>(f560));
        } else if (static_cast<double>(f560) > 0.0f) {
            c1 = ftol_trunc(static_cast<double>(c0) + static_cast<double>(f560));
        }
        const float f564 = load_f32(car, 0x564u);
        const std::int32_t c2 = (static_cast<double>(f564) != 0.0f)
            ? ftol_trunc(static_cast<double>(f564))
            : 0;

        std::int32_t cond[17] = {};
        cond[0] = c2;
        cond[1] = c1;
        cond[2] = c1;
        cond[3] = c1;
        cond[4] = c1;
        cond[5] = 0;
        cond[12] = signed_val;
        cond[13] = abs_val;
        cond[14] = abs_val;
        cond[15] = abs_val;
        cond[16] = abs_val;

        const std::uint32_t row = ff_state_u32(kOffSlotIdx);
        (void)ff_effect_update_params_00533910(
            ff_slot_word(row, 3u), 1u, cond, nullptr,
            &ff_init_config_00657c48, nullptr, nullptr, nullptr);
        ff_state_set_i32(kOffSpringActive, 1);
        ff_effect_cooldown_005e9540 = 0;
    }

    if (ff_init_config_00657c08 != 0u) {
        ff_effect_update_engine_004127a0(car);
    }
}

} // namespace porsche
