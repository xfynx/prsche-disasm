// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00534b90..00534d35 (422B). Proof-only: raw callback VAs are not
// suitable for the host game graph until their native bindings are recovered.
#include "render_depthconv_745.hpp"

#include <cstddef>
#include <cstdint>

namespace porsche {

std::int32_t __cdecl render_shape_type_to_depth_index_005345e0(std::uint32_t shape_type);
std::uint32_t __cdecl render_descriptor_bits_00537f90(const void* descriptor_format);
std::uint32_t* __cdecl render_getclutptr_from_resource_005346d0(
    const void* descriptor, std::uint32_t* palette);
void __cdecl render_palette_8888_to_1555_alpha_00570330(
    std::uint16_t*, const std::uint32_t*, std::int32_t);
void __cdecl render_palette_888_to_1555_00570370(
    std::uint16_t*, const std::uint32_t*, std::int32_t);
void __cdecl render_palette_8888_to_565_alpha_005704c0(
    std::uint16_t*, const std::uint32_t*, std::int32_t);
void __cdecl render_palette_888_to_565_00570510(
    std::uint16_t*, const std::uint32_t*, std::int32_t);
void __cdecl render_palette_8888_to_4444_00570540(
    std::uint16_t*, const std::uint32_t*, std::int32_t);

namespace {

// Raw original .data tables 005de2fc..005de4fb. They remain VA tokens here;
// the standalone proof checks exact table selection without pretending that
// unrecovered original addresses are callable host pointers.
constexpr std::uint32_t kDirectCallbacks[64] = {
    0x005700d0u,0x00570150u,0x005703a0u,0x005703a0u,0x00570150u,0x00570150u,0x00570150u,0x005703a0u,
    0x005700f0u,0x00570190u,0x005703f0u,0x005703f0u,0x00570650u,0x00570750u,0x005703f0u,0x005703f0u,
    0x00570420u,0x00570420u,0x00570470u,0x00570420u,0x00570420u,0x00570780u,0x00570780u,0x00570260u,
    0x005701b0u,0x005701b0u,0x005702a0u,0x00570470u,0x00570690u,0x00570820u,0x005705a0u,0x005702a0u,
    0x00570a00u,0x00570a00u,0x00570a00u,0x00570a00u,0x00570700u,0x00570a00u,0x00570a00u,0x00570a00u,
    0x005704c0u,0x005704c0u,0x00570330u,0x005704c0u,0x00570720u,0x00570a80u,0x00570540u,0x00570330u,
    0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x00570470u,0x005708a0u,
    0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570470u,
};

constexpr std::uint32_t kAlternateCallbacks[64] = {
    0x005700d0u,0x00570150u,0x005703a0u,0x005703a0u,0x00570150u,0x00570150u,0x00570150u,0x005703a0u,
    0x005700f0u,0x00570190u,0x005703f0u,0x005703f0u,0x00570650u,0x00570750u,0x005703f0u,0x005703f0u,
    0x00570420u,0x00570420u,0x00570470u,0x00570420u,0x00570420u,0x00570780u,0x00570780u,0x00570260u,
    0x005701b0u,0x005701b0u,0x005702f0u,0x00570470u,0x00570690u,0x00570820u,0x005705a0u,0x005702f0u,
    0x00570a00u,0x00570a00u,0x00570a00u,0x00570a00u,0x00570700u,0x00570a00u,0x00570a00u,0x00570a00u,
    0x00570510u,0x00570510u,0x00570370u,0x00570510u,0x00570720u,0x00570a80u,0x00570540u,0x00570370u,
    0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x005708a0u,0x00570470u,0x005708a0u,
    0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570260u,0x00570470u,
};

constexpr std::uint8_t kIntermediateTypes[64] = {
    0x7a,0x7b,0x7e,0x78,0x7b,0x7b,0x7b,0x7e,0x7a,0x7b,0x7e,0x78,0x7f,0x7d,0x6d,0x7e,
    0x78,0x78,0x7e,0x78,0x78,0x7d,0x7d,0x42,0x7b,0x7b,0x7e,0x78,0x7f,0x7d,0x6d,0x7e,
    0x7d,0x7d,0x7d,0x7d,0x7f,0x7d,0x7d,0x7d,0x78,0x78,0x7e,0x78,0x7f,0x7d,0x6d,0x7e,
    0x7d,0x7d,0x7d,0x7d,0x7d,0x7d,0x6d,0x7d,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x42,
};

} // namespace

void* __cdecl render_shape_row_converter_00534b90(
    const void* shape, std::uint32_t target_type, std::int32_t direct_mode) {
    const auto shape_type = static_cast<std::uint32_t>(
        *static_cast<const std::uint8_t*>(shape));
    const auto source_index = render_shape_type_to_depth_index_005345e0(shape_type);
    const auto target_index = render_shape_type_to_depth_index_005345e0(target_type);
    const std::size_t index = static_cast<std::size_t>(source_index * 8 + target_index);
    const std::uint32_t mapped_type = kIntermediateTypes[index];
    if (mapped_type != target_type) {
        return nullptr;
    }

    const auto callback_source_index =
        render_shape_type_to_depth_index_005345e0(shape_type);
    const auto callback_target_index =
        render_shape_type_to_depth_index_005345e0(target_type);
    const std::size_t callback_index = static_cast<std::size_t>(
        callback_source_index * 8 + callback_target_index);
    const std::uint32_t callback_va = (direct_mode != 0)
        ? kDirectCallbacks[callback_index] : kAlternateCallbacks[callback_index];
    const auto source_bits = render_descriptor_bits_00537f90(shape);
    const auto target_bits = render_descriptor_bits_00537f90(&mapped_type);
    if (source_bits < 9u && target_bits > 8u) {
        const std::uint32_t count = 1u << (source_bits & 31u);
        render_depthconv_palette_ptr_005de2f8 =
            render_getclutptr_from_resource_005346d0(
                shape, render_depthconv_palette_scratch_006bda20);
        if (target_type == 0x6du) {
            render_palette_8888_to_4444_00570540(
                reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
        } else if (target_bits == 15u) {
            if (direct_mode != 0) {
                render_palette_8888_to_1555_alpha_00570330(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            } else {
                render_palette_888_to_1555_00570370(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            }
        } else if (target_bits == 16u) {
            if (direct_mode != 0) {
                render_palette_8888_to_565_alpha_005704c0(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            } else {
                render_palette_888_to_565_00570510(
                    reinterpret_cast<std::uint16_t*>(render_depthconv_palette_scratch_006bda20),
                    render_depthconv_palette_ptr_005de2f8, static_cast<std::int32_t>(count));
            }
        }
    }
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(callback_va));
}

} // namespace porsche
