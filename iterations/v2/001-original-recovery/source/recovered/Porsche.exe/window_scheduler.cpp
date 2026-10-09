#include "porsche/window_scheduler.hpp"
#include "porsche/shared_runtime_globals.hpp"

namespace porsche {

std::uint32_t window_scheduler_depth_0069de20=0;

std::uint32_t __cdecl window_scheduler_register_005365e0(
    TimedCallback callback, std::uint32_t period, std::uint32_t initial_delay) {
    // The original increments this scalar during the scan, then decrements it
    // on both exits. Nested entry therefore skips one more free slot.
    const std::uint32_t original_depth=window_scheduler_depth_0069de20;
    ++window_scheduler_depth_0069de20;

    std::int32_t selected=-1;
    std::uint32_t free_slots_to_skip=original_depth;
    for (std::uint32_t i=0;i<16;++i) {
        auto& slot=timed_callbacks_0069dd20[i];
        if (slot.callback==callback) {
            // The original keeps scanning, so the last duplicate wins.
            selected=static_cast<std::int32_t>(i);
        } else if (!slot.callback && selected<0) {
            if (free_slots_to_skip) --free_slots_to_skip;
            else selected=static_cast<std::int32_t>(i);
        }
    }

    if (selected<0) {
        class_error_file_005deb74=0x005bb6d8;
        class_error_line_005deb78=0x63;
        window_scheduler_diagnostic_00565340(
            reinterpret_cast<const char*>(static_cast<std::uintptr_t>(0x005bb6ec)));
    } else {
        auto& slot=timed_callbacks_0069dd20[static_cast<std::uint32_t>(selected)];
        slot.callback=callback;
        slot.period=period;
        slot.next_tick=current_tick_006b7c40+initial_delay;
        slot.active=0;
    }

    --window_scheduler_depth_0069de20;
    return window_scheduler_depth_0069de20;
}

TimedCallbackSlot* __cdecl window_scheduler_remove_005366a0(TimedCallback callback) {
    std::uint32_t index=0;
    while (index<16 && timed_callbacks_0069dd20[index].callback!=callback) ++index;
    auto* slot=timed_callbacks_0069dd20+index;
    if (index<16 && slot->callback==callback) slot->callback=nullptr;
    return slot;
}

}
