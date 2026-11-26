#pragma once

#include <cstdint>

namespace porsche {

extern std::uint32_t transform_cached_mode_005df358;
extern std::uint32_t transform_destination_stride_005df360;
extern const void* transform_matrix_006a3b38;
extern std::uint32_t transform_matrix_dirty_006a3b5c;

const void* __cdecl set_transform_matrix_00559a40(const void* matrix);
std::uint32_t __cdecl set_transform_destination_stride_00559ab0(std::uint32_t stride);

void __cdecl transform_vectors_00532a40(
    std::int32_t count, const float* source, const void* matrix, float* destination);

std::uint32_t __cdecl transform_vector_dispatch_0055a930(
    std::uint32_t mode, std::int32_t count, const float* source, float* destination);

} // namespace porsche
