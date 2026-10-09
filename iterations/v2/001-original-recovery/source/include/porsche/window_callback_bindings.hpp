#pragma once
#include <cstddef>
#include <cstdint>
#include "porsche/window_procedure.hpp"

namespace porsche {
struct WindowCallbackRelocation {
    std::uint32_t original_va;
    WindowHandler native_callback;
};

// Complete mapping for callback VAs recovered from the 0053ac20 registration
// table. Unknown addresses resolve to nullptr and are never invoked as guest VAs.
const WindowCallbackRelocation* window_callback_relocations(std::size_t* count);
WindowHandler window_callback_resolve(std::uint32_t original_va);

// Convert message/original-VA pairs to native callback entries. If any address
// is unresolved or capacity is insufficient, no output entries are written.
bool window_callback_relocate_table(const std::uint32_t* message_va_pairs,
    std::size_t count, WindowHandlerEntry* output, std::size_t output_capacity,
    std::uint32_t* unresolved_va);
}
