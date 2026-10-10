#include "porsche/auxiliary_wait.hpp"

#include "porsche/files.hpp"

namespace porsche {

void* auxiliary_wait_event_0069e5dc = nullptr;

void __cdecl auxiliary_wait_signal_0053c270() {
    void* const event = auxiliary_wait_event_0069e5dc;
    if (event != nullptr)
        (void)file_event_signal_0055fb30(event);
}

} // namespace porsche
