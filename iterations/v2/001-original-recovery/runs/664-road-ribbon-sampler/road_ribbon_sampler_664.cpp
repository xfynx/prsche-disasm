// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00532860..00532870 (17B), 00434aa0..00434d8d (750B), 00434a90..00434a94 (5B),
// and loader-zero .data BSS globals (00628bc0, 0060fde0..00610a5f).
#include "road_ribbon_sampler_664.hpp"

#include <cmath>
#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

void* track_road_data_00628bc0 = nullptr;
RoadRibbonPoint road_ribbon_points_0060fde0[200] = {};

namespace {

constexpr std::uint32_t kRoadSliceStride = 0x50u;
constexpr std::int32_t kRoadRibbonMaxPoints = 200;

inline const std::uint8_t* read_ptr(const void* base, std::size_t offset) {
    std::uintptr_t raw = 0u;
    std::memcpy(&raw, static_cast<const std::uint8_t*>(base) + offset, sizeof(raw));
    return reinterpret_cast<const std::uint8_t*>(raw);
}

inline std::int32_t read_i32(const void* base, std::size_t offset) {
    std::int32_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

inline float read_f32(const void* base, std::size_t offset) {
    float value = 0.0f;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

inline void read_slice_xyz(const std::uint8_t* slices,
                           std::size_t byte_offset,
                           float& x,
                           float& y,
                           float& z) {
    const std::uint8_t* const point = slices + byte_offset + 0x04u;
    x = read_f32(point, 0x00u);
    y = read_f32(point, 0x04u);
    z = read_f32(point, 0x08u);
}

// Original 00532860 leaves unrounded x87 ST(0) on return; 00434aa0 subtracts float32
// prev_angle before rounding the new angle to float32.
double __cdecl math_angle_turns_f64(float y, float x) {
    // Original 005bb2c8 (8B .rdata): 0x3fc45f3080000000 (0.1591549515724182).
    alignas(8) static const std::uint64_t kTurnsScaleBits = 0x3fc45f3080000000ULL;
    double result = 0.0;
    __asm {
        fld dword ptr [y]
        fld dword ptr [x]
        fpatan
        fmul qword ptr [kTurnsScaleBits]
        fstp qword ptr [result]
    }
    return result;
}

inline double wrapped_turn_delta(double angle, float prev_angle) {
    double delta = std::fabs(angle - static_cast<double>(prev_angle));
    if (delta > 0.5) {
        delta = std::fabs(1.0 - delta);
    }
    return delta;
}

} // namespace

float __cdecl math_angle_turns_00532860(float y, float x) {
    return static_cast<float>(math_angle_turns_f64(y, x));
}

void __cdecl road_ribbon_sample_00434aa0() {
    const void* const root = track_road_data_00628bc0;
    const std::uint8_t* slices = read_ptr(root, 0x0cu);
    const std::int32_t slice_count = read_i32(root, 0x00u);

    float p0_x = 0.0f;
    float p0_y = 0.0f;
    float p0_z = 0.0f;
    read_slice_xyz(slices, 0x00u, p0_x, p0_y, p0_z);

    float p1_x = 0.0f;
    float p1_y = 0.0f;
    float p1_z = 0.0f;
    read_slice_xyz(slices, kRoadSliceStride, p1_x, p1_y, p1_z);

    float prev_angle = math_angle_turns_00532860(p1_z - p0_z, p1_x - p0_x);
    float prev_x = p0_x;
    float prev_y = p0_y;
    float prev_z = p0_z;
    (void)prev_y;

    float total_accum = 0.0f;
    if (slice_count > 1) {
        std::size_t slice_off = kRoadSliceStride;
        for (std::int32_t i = 1; i < slice_count; ++i) {
            slices = read_ptr(root, 0x0cu);
            float cur_x = 0.0f;
            float cur_y = 0.0f;
            float cur_z = 0.0f;
            read_slice_xyz(slices, slice_off, cur_x, cur_y, cur_z);

            const double angle = math_angle_turns_f64(cur_z - prev_z, cur_x - prev_x);
            total_accum = static_cast<float>(
                static_cast<double>(total_accum) + wrapped_turn_delta(angle, prev_angle));
            prev_angle = static_cast<float>(angle);
            prev_x = cur_x;
            prev_y = cur_y;
            prev_z = cur_z;
            slice_off += kRoadSliceStride;
        }
    }

    slices = read_ptr(root, 0x0cu);
    read_slice_xyz(slices, 0x00u, p0_x, p0_y, p0_z);
    read_slice_xyz(slices, kRoadSliceStride, p1_x, p1_y, p1_z);
    prev_angle = math_angle_turns_00532860(p1_z - p0_z, p1_x - p0_x);

    // Original 005b3284 (4B .rdata): 0x3ba3d70a (0.004999999888241291f == 0.005f).
    const float step = total_accum * 0.005f;

    road_ribbon_points_0060fde0[0] = {p0_x, p0_y, p0_z, 1.0f};
    std::int32_t out_idx = 1;
    float accum = 0.0f;
    float emit_x = p0_x;
    float emit_y = p0_y;
    float emit_z = p0_z;
    prev_x = p0_x;
    prev_z = p0_z;

    if (slice_count > 1) {
        std::size_t slice_off = kRoadSliceStride;
        for (std::int32_t i = 1; i < slice_count; ++i) {
            if (out_idx >= kRoadRibbonMaxPoints) {
                return;
            }
            slices = read_ptr(root, 0x0cu);
            float cur_x = 0.0f;
            float cur_y = 0.0f;
            float cur_z = 0.0f;
            read_slice_xyz(slices, slice_off, cur_x, cur_y, cur_z);

            const double angle = math_angle_turns_f64(cur_z - prev_z, cur_x - prev_x);
            accum = static_cast<float>(
                static_cast<double>(accum) + wrapped_turn_delta(angle, prev_angle));
            prev_angle = static_cast<float>(angle);

            if (accum >= step) {
                accum -= step;
                road_ribbon_points_0060fde0[out_idx] = {emit_x, emit_y, emit_z, 1.0f};
                ++out_idx;
            }

            emit_x = cur_x;
            emit_y = cur_y;
            emit_z = cur_z;
            prev_x = cur_x;
            prev_z = cur_z;
            slice_off += kRoadSliceStride;
        }
    }

    if (out_idx < kRoadRibbonMaxPoints) {
        const std::size_t last_off = static_cast<std::size_t>(slice_count - 1) * kRoadSliceStride;
        for (; out_idx < kRoadRibbonMaxPoints; ++out_idx) {
            slices = read_ptr(root, 0x0cu);
            float last_x = 0.0f;
            float last_y = 0.0f;
            float last_z = 0.0f;
            read_slice_xyz(slices, last_off, last_x, last_y, last_z);
            road_ribbon_points_0060fde0[out_idx] = {last_x, last_y, last_z, 1.0f};
        }
    }
}

void __cdecl startup_sequence_call_00434a90() {
    road_ribbon_sample_00434aa0();
}

} // namespace porsche
