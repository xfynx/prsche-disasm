#pragma once
#include "porsche/fe_stream.hpp"

namespace porsche {
// Main 004b6a50 callsite 004b6ad8: apply packed records from 004b6660,
// advance by 004b4cd0's reported word count, then release the stream at 004b6afa.
void __cdecl application_fe_apply_release_004b6ad8(std::uint32_t* stream);
}
