#pragma once
#include <cstdint>
#include "../871-scene-records-reset/scene_records_reset_871.hpp"

namespace porsche {
struct RouteKeyframe875 {
    std::int32_t position;
    std::uint32_t fields[11];
};
struct RouteCursor875 {
    RouteKeyframe875* keys;
    std::int32_t count;
    std::int32_t current;
    std::int32_t next;
};
void __fastcall route_select_key_0045a540(RouteCursor875*, void*, std::int32_t index);
double __fastcall route_key_weight_0045a560(RouteCursor875*, void*, std::int32_t position);
double __fastcall route_key_sample_0045a8e0(RouteCursor875*, void*, float weight);
double __fastcall route_key_sample_0045a940(RouteCursor875*, void*, float weight);
}
