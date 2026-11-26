#include "camera_transform_848.hpp"

namespace porsche {

std::uint32_t transform_cached_mode_005df358 = 0xffffffffu;
std::uint32_t transform_destination_stride_005df360 = 32u;
const void* transform_matrix_006a3b38 = nullptr;
std::uint32_t transform_matrix_dirty_006a3b5c = 0u;

const void* __cdecl set_transform_matrix_00559a40(const void* matrix) {
    const void* const previous = transform_matrix_006a3b38;
    transform_matrix_006a3b38 = matrix;
    if (matrix == nullptr) {
        transform_cached_mode_005df358 = 0xffffffffu;
    } else {
        transform_matrix_dirty_006a3b5c = 1u;
    }
    return previous;
}

std::uint32_t __cdecl set_transform_destination_stride_00559ab0(std::uint32_t stride) {
    const std::uint32_t previous = transform_destination_stride_005df360;
    transform_destination_stride_005df360 = stride;
    if (stride == 0u) {
        transform_cached_mode_005df358 = 0xffffffffu;
    }
    return previous;
}

void __cdecl transform_vectors_00532a40(
    std::int32_t count, const float* source, const void* matrix, float* destination) {
    const void* const previous_matrix = set_transform_matrix_00559a40(matrix);
    const std::uint32_t previous_stride = set_transform_destination_stride_00559ab0(12u);
    transform_vector_dispatch_0055a930(2u, count, source, destination);
    set_transform_matrix_00559a40(previous_matrix);
    set_transform_destination_stride_00559ab0(previous_stride);
}

} // namespace porsche
