#include "porsche/mouse_input.hpp"

#include "porsche/heap.hpp"
#include "porsche/render_driver_calls.hpp"
#include "porsche/render_event_route.hpp"
#include "porsche/window_create.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {
namespace {
std::int32_t signed_word(std::uint32_t word) noexcept {
    std::int32_t value;
    static_assert(sizeof(value)==sizeof(word));
    std::memcpy(&value,&word,sizeof(value));
    return value;
}

std::int32_t clamp_original(std::int32_t value,std::int32_t low,
                            std::int32_t high) noexcept {
    // Mirrors the original signed JG/JGE branches, including low > high.
    auto result=value>low?value:low;
    if(result>=high)result=high;
    return result;
}
}

void __cdecl mouse_input_consumer_005728b0(
    std::uint32_t x_word,std::uint32_t y_word,std::uint32_t button_mask,
    std::uint32_t transition) {
    if(!render_event_dispatch_gate_005deaac)return;
    auto* lock=class_lock_0069e59c;
    if(!lock)return;

    const auto x=signed_word(x_word);
    const auto y=signed_word(y_word);
    const auto adjusted_x=clamp_original(
        x,signed_word(render_driver_bounds_a_006a643c),
        signed_word(render_driver_bounds_c_006a6430));
    const auto adjusted_y=clamp_original(
        y,signed_word(render_driver_bounds_b_006a6438),
        signed_word(render_driver_bounds_d_006a6434));

    heap_enter_005322b0(lock);
    render_driver_limit_c_006a6440=button_mask;
    if(adjusted_x!=x || adjusted_y!=y) {
        render_event_set_cursor_position_0053a970(
            &window_configuration_storage_006b77a0,adjusted_x,adjusted_y);
    }
    if(adjusted_x!=signed_word(render_driver_limit_a_006a6448) ||
       adjusted_y!=signed_word(render_driver_limit_b_006a6444)) {
        render_driver_limit_a_006a6448=static_cast<std::uint32_t>(adjusted_x);
        render_driver_limit_b_006a6444=static_cast<std::uint32_t>(adjusted_y);
    }
    heap_leave_005322c0(lock);

    // The original tests arg3/down after unlocking. 005367b0 is the original
    // initialized no-op target; button_mask is passed through unchanged.
    if(transition!=0 && render_event_callback_pointer_005debec) {
        const auto callback=render_event_callback_pointer_005debec;
        if(callback==0x005367b0) {
            (void)render_event_default_callback_005367b0(button_mask);
        } else {
            render_event_invoke_callback_005debec(callback,button_mask);
        }
    }
}
}
