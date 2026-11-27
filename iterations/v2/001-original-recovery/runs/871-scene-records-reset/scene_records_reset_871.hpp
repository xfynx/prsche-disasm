#pragma once
#include <cstdint>

namespace porsche {
void __cdecl session_scene_records_reset_00459260();
// These calls consume ECX and return ST0. They remain real game frontiers.
float __fastcall scene_route_first_sample_0045cfd0(void* self, void* unused_edx);
float __fastcall scene_route_second_sample_0045d000(void* self, void* unused_edx);
void __fastcall scene_record_emitter_reset_004581a0(void* self, void* unused_edx,
                                                 float second, float first);
double __fastcall scene_record_sample_00459510(void* record, void* unused_edx);
double __fastcall scene_record_sample_00459560(void* record, void* unused_edx);
double __fastcall scene_record_sample_004595b0(void* record, void* unused_edx);
}
