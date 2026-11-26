#pragma once

#include <cstdint>

namespace porsche {

struct SessionResetObject0040e3b0;

extern const void* session_reset_payload_005e66b0;
extern SessionResetObject0040e3b0* session_reset_object_005e752c;
extern std::uint32_t& global_00657414;

void __fastcall session_reset_children_0040e3b0(
    SessionResetObject0040e3b0* self, void* /*unused_edx*/, const void* payload);
void __cdecl frame_reset_service_004030b0();

} // namespace porsche
