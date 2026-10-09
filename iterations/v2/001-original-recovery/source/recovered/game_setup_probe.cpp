#include "porsche/game_setup.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

namespace {
struct Event { std::uint32_t id; std::vector<std::uint32_t> args; };
struct Case {
    std::uint32_t earts_exists, load_exists, begin, end, movie_stop;
} current{};
std::vector<Event> events;
std::array<std::uint8_t, 0x2000> resource{};
std::uint8_t display_bytes[0x80]{};
std::uint8_t movie_service[16]{};
std::uint8_t movie_service_target[16]{};
std::uint8_t movie_temp[16]{};

std::uint32_t hash_text(const char* p) {
    std::uint32_t h = 2166136261u;
    while (*p) { h = (h ^ static_cast<std::uint8_t>(*p++)) * 16777619u; }
    return h;
}
std::uint32_t rel(const void* p, const void* base) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p) -
                                      reinterpret_cast<std::uintptr_t>(base));
}
void record(std::uint32_t id, std::initializer_list<std::uint32_t> args = {}) {
    events.push_back({id, std::vector<std::uint32_t>(args)});
}
}

namespace porsche {
const char* game_setup_earts_base_0065b32c = "boot/";
const char* game_setup_load_base_0065b334 = "ui/";
void* game_setup_movie_service_0069ed0c = movie_service;
RenderDisplay* render_display_00628130 =
    reinterpret_cast<RenderDisplay*>(display_bytes);

void __cdecl render_display_reconfigure_00467fc0(RenderDisplay* display,
        std::uint32_t w, std::uint32_t h, std::uint32_t mode,
        std::uint32_t transition) {
    record(1, {display != nullptr, w, h, mode, transition});
}
std::uint32_t __cdecl free_00531f90(void* p) {
    record(20, {rel(p, resource.data())}); return 1;
}
std::uint32_t __cdecl window_shutdown_prepare_00534550() {
    record(19); return 0;
}

void __cdecl game_setup_update_00560030() { record(2); }
void __cdecl game_setup_string_005a0fbf(char* out, const char* fmt,
                                        const char* base, char*) {
    record(3, {hash_text(fmt), hash_text(base)});
    std::snprintf(out, 0x104, fmt, base);
}
void __cdecl game_setup_movie_service_begin_00536080(void* self) {
    record(4, {rel(self, movie_service_target)});
}
void __cdecl game_setup_movie_service_end_00536050(void* self) {
    record(5, {rel(self, movie_service_target)});
}
std::uint32_t __cdecl game_setup_file_exists_0059dc30(const char* path) {
    const auto h = hash_text(path);
    const auto exists = std::strstr(path, "earts-av.mad")
        ? current.earts_exists : current.load_exists;
    record(6, {h, exists}); return exists;
}
void __cdecl game_setup_object_init_00403520(void* obj, std::uint32_t bytes) {
    auto* words = static_cast<std::uint32_t*>(obj);
    const auto address = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(movie_temp));
    words[0] = address; words[1] = address; words[2] = address + 8;
    record(7, {bytes});
}
void __cdecl game_setup_resource_open_0059e440(const char* path, void* obj) {
    auto* words = static_cast<std::uint32_t*>(obj);
    words[0] = current.begin; words[1] = 0x55667788; words[2] = current.end;
    record(8, {hash_text(path), words[0], words[2]});
}
void __stdcall game_setup_render_begin_006bd9b0(std::uint32_t mode) { record(9, {mode}); }
void __stdcall game_setup_render_reset_006bd91c() { record(10); }
void __stdcall game_setup_render_prepare_006bd970() { record(11); }
void __stdcall game_setup_render_update_006bd948() { record(12); }
void __stdcall game_setup_render_finish_006bd978(std::uint32_t zero) { record(13, {zero}); }
void __cdecl game_setup_movie_004dd4a0() { record(14); }
void __cdecl game_setup_movie_delta_004237d0(void* begin, std::uint32_t bytes,
                                              std::uint32_t zero) {
    record(15, {static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(begin)), bytes, zero});
}
void* __cdecl game_setup_resource_file_open_0059d8e0(const char* path,
                                                      std::uint32_t zero) {
    record(16, {hash_text(path), zero});
    for (std::uint32_t i=0; i<resource.size()-0x180; i+=8) {
        const auto value=0x100u+i;
        std::memcpy(resource.data()+0x14+i,&value,4);
        std::memcpy(resource.data()+0xb4+i,&value,4);
        std::memcpy(resource.data()+0x104+i,&value,4);
        std::memcpy(resource.data()+0x12c+i,&value,4);
        std::memcpy(resource.data()+0x154+i,&value,4);
    }
    return resource.data();
}
void __cdecl game_setup_draw_resource_00563440(const void* item,
        std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t d) {
    record(17, {rel(item, resource.data()), a,b,c,d});
}
void __cdecl game_setup_draw_begin_00534540() { record(18); }
void __cdecl game_setup_movie_004dc850(void* stream, std::uint32_t* stop,
        std::uint32_t a2,std::uint32_t a3,std::uint32_t a4) {
    record(21, {static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(stream)),
                stop != nullptr, a2,a3,a4});
    if (stop) *stop=current.movie_stop;
}
}

int main() {
    while (std::cin >> current.earts_exists >> current.load_exists
                    >> current.begin >> current.end >> current.movie_stop) {
        events.clear();
        *reinterpret_cast<void**>(movie_service + 4) = movie_service_target;
        porsche::game_setup_004dd600();
        std::cout << "[";
        for (std::size_t i=0;i<events.size();++i) {
            if (i) std::cout << ',';
            std::cout << "{\"id\":" << events[i].id << ",\"args\":[";
            for (std::size_t j=0;j<events[i].args.size();++j) {
                if (j) std::cout << ',';
                std::cout << events[i].args[j];
            }
            std::cout << "]}";
        }
        std::cout << "]\n";
    }
    return std::cin.eof()?0:2;
}
