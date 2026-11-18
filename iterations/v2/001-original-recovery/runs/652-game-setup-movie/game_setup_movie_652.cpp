// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 00472860..004729a0 (321B), 0059e440..0059e64d (526B),
// 004dd4a0..004dd5f4 (341B), and owned .data strings 005d998c (14B), 005d999c (14B).
#include "game_setup_movie_652.hpp"

#include <cstring>

namespace {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

struct StringRange652 {
    std::uint32_t begin;
    std::uint32_t current;
    std::uint32_t end;
};
static_assert(sizeof(StringRange652) == 12u);

std::uint32_t addr_of(const void* p) {
    return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
}

void* ptr_of(std::uint32_t addr) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(addr));
}

std::uint32_t load32(const void* base, std::uint32_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void store32(void* base, std::uint32_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void* load_ptr(const void* base, std::uint32_t offset) {
    return ptr_of(load32(base, offset));
}

void assign_string_range(void* object, const char* src) {
    const std::uint32_t len = static_cast<std::uint32_t>(std::strlen(src));
    const std::uint32_t begin = load32(object, 0x00u);
    const std::uint32_t cur = load32(object, 0x04u);
    const std::uint32_t cur_len = cur - begin;

    if (len <= cur_len) {
        if (len != 0u) {
            std::memcpy(ptr_of(begin), src, len);
        }
        const std::uint32_t new_cur = load32(object, 0x00u) + len;
        const std::uint32_t old_cur = load32(object, 0x04u);
        if (new_cur != old_cur) {
            (void)porsche::context_move_005a1a40(ptr_of(new_cur), ptr_of(old_cur), 1u);
            const std::uint32_t reloaded_cur = load32(object, 0x04u);
            store32(object, 0x04u, reloaded_cur + (new_cur - old_cur));
        }
    } else {
        if (cur_len != 0u) {
            std::memcpy(ptr_of(begin), src, cur_len);
        }
        const std::uint32_t reload_len = load32(object, 0x04u) - load32(object, 0x00u);
        (void)porsche::context_string_insert_00472860(
            object, nullptr, src + reload_len, src + len);
    }
}

} // namespace

namespace porsche {

const char game_setup_movie_mad_fmt_005d998c[14] = "%sinPC-av.mad";
const char game_setup_porsche_fsh_fmt_005d999c[14] = "%sporsche.fsh";

void* __fastcall context_string_insert_00472860(
    void* self, void* edx_unused, const char* first, const char* last) {
    (void)edx_unused;

    if (first == last) {
        return self;
    }

    const std::uint32_t begin = load32(self, 0x00u);
    const std::uint32_t cur = load32(self, 0x04u);
    const std::uint32_t end = load32(self, 0x08u);
    const std::uint32_t first_addr = addr_of(first);
    const std::uint32_t last_addr = addr_of(last);
    const std::uint32_t old_len = cur - begin;
    const std::uint32_t insert_len = last_addr - first_addr;
    const std::uint32_t max_len = (end - begin) - 1u;

    if (old_len + insert_len <= max_len) {
        const std::uint32_t cur_at_move = load32(self, 0x04u);
        (void)context_move_005a1a40(
            ptr_of(cur_at_move + 1u),
            first + 1,
            last_addr - (first_addr + 1u));
        const std::uint32_t cur_after_move = load32(self, 0x04u);
        *static_cast<std::uint8_t*>(ptr_of(cur_after_move + insert_len)) = 0u;
        const std::uint32_t cur_for_head = load32(self, 0x04u);
        *static_cast<std::uint8_t*>(ptr_of(cur_for_head)) =
            static_cast<std::uint8_t>(*first);
        const std::uint32_t cur_final = load32(self, 0x04u) + insert_len;
        store32(self, 0x04u, cur_final);
        return self;
    }

    const std::uint32_t grow_base = (old_len < insert_len) ? insert_len : old_len;
    const std::uint32_t alloc_bytes = grow_base + old_len + 1u;
    std::uint32_t new_buf = 0u;
    if (alloc_bytes != 0u) {
        new_buf = addr_of(application_context_member_storage_004211d0(alloc_bytes, 0u));
    }

    const std::uint32_t src_begin = load32(self, 0x00u);
    const std::uint32_t src_cur = load32(self, 0x04u);
    const std::int32_t copy_len = static_cast<std::int32_t>(src_cur - src_begin);
    std::uint32_t dst = new_buf;
    if (copy_len > 0) {
        const auto* const src_bytes = static_cast<const std::uint8_t*>(ptr_of(src_begin));
        auto* const dst_bytes = static_cast<std::uint8_t*>(ptr_of(dst));
        for (std::int32_t i = 0; i < copy_len; ++i) {
            dst_bytes[i] = src_bytes[i];
        }
        dst += static_cast<std::uint32_t>(copy_len);
    }

    (void)context_move_005a1a40(ptr_of(dst), first, insert_len);
    const std::uint32_t new_cur = (dst - first_addr) + last_addr;
    *static_cast<std::uint8_t*>(ptr_of(new_cur)) = 0u;

    const std::uint32_t old_begin = load32(self, 0x00u);
    const std::uint32_t old_bytes = load32(self, 0x08u) - old_begin;
    if (old_begin != 0u && old_bytes != 0u) {
        auto* const mgr = static_cast<std::uint8_t*>(
            application_context_heap_state_005e4fe8());
        if (old_bytes > 0x100u) {
            context_table_release_0059ecd0(ptr_of(old_begin));
        } else {
            auto* const pool = mgr + 0x28u;
            heap_enter_005322b0(load_ptr(pool, 0x00u));
            const std::uint32_t head_off = (((old_bytes - 1u) >> 3u) * 4u) + 0x0cu;
            store32(ptr_of(old_begin), 0x04u, load32(pool, head_off));
            store32(pool, head_off, old_begin);
            heap_leave_005322c0(load_ptr(pool, 0x00u));
        }
    }

    store32(self, 0x00u, new_buf);
    store32(self, 0x04u, new_cur);
    store32(self, 0x08u, new_buf + alloc_bytes);
    return self;
}

bool __cdecl game_setup_resource_open_result_0059e440(const char* path, void* object) {
    char local_path[260];
    if (file_roots_enabled_006af370 == 0) {
        const char* src = path;
        char* dst = local_path;
        do {
            *dst++ = *src;
        } while (*src++ != '\0');
        assign_string_range(object, local_path);
        return true;
    }

    // Porsche.exe 005cc588 is the null-terminated literal "%s%s".
    formatter_entry_005a0fbf(local_path, "%s%s", file_root_006af168, path);
    if (file_exists_00561b80(local_path) != 0) {
        assign_string_range(object, local_path);
        return true;
    }

    if (file_fallback_006af26c[0] != '\0') {
        formatter_entry_005a0fbf(local_path, "%s%s", file_fallback_006af26c, path);
        if (file_exists_00561b80(local_path) != 0) {
            assign_string_range(object, local_path);
            return true;
        }
    }

    // Reload missing_file_006afbe4 after earlier calls in case it changed.
    if (missing_file_006afbe4 != nullptr) {
        missing_file_006afbe4(path, -2);
    }

    assign_string_range(object, file_null_name_005e8e50);
    return false;
}

void __cdecl game_setup_resource_open_0059e440(const char* path, void* object) {
    (void)game_setup_resource_open_result_0059e440(path, object);
}

void __cdecl game_setup_movie_004dd4a0() {
    char mad_path[100]{};
    char fsh_path[100]{};

    game_setup_update_00560030();
    formatter_entry_005a0fbf(fsh_path, game_setup_porsche_fsh_fmt_005d999c,
                             game_setup_load_base_0065b334);
    (void)resource_open_quiet_0059d9b0(fsh_path, 0u);
    formatter_entry_005a0fbf(mad_path, game_setup_movie_mad_fmt_005d998c,
                             game_setup_earts_base_0065b32c, mad_path);

    void* const begin_service = *reinterpret_cast<void* const*>(
        static_cast<const std::uint8_t*>(game_setup_movie_service_0069ed0c) + 4);
    game_setup_movie_service_begin_00536080(begin_service);

    if (game_setup_file_exists_0059dc30(mad_path) != 0u) {
        StringRange652 movie{0u, 0u, 0u};
        game_setup_object_init_00403520(&movie, 8u);
        *static_cast<std::uint8_t*>(ptr_of(movie.current)) = 0u;
        game_setup_resource_open_0059e440(mad_path, &movie);

        for (std::uint32_t i = 0u; i < 3u; ++i) {
            game_setup_render_begin_006bd9b0(2u);
            game_setup_render_reset_006bd91c();
            game_setup_render_prepare_006bd970();
            game_setup_render_update_006bd948();
            game_setup_render_finish_006bd978(0u);
        }

        std::uint32_t stop = 0u;
        void* const stream = ptr_of(movie.begin);
        game_setup_movie_004dc850(stream, &stop, 0u, 3u, 0u);

        const std::uint32_t bytes = movie.end - movie.begin;
        if (movie.begin != 0u && bytes != 0u) {
            if (bytes > 0x100u) {
                context_table_release_0059ecd0(ptr_of(movie.begin));
            } else {
                auto* const pool = static_cast<std::uint8_t*>(
                    application_context_heap_state_005e4fe8()) + 0x28u;
                heap_enter_005322b0(load_ptr(pool, 0x00u));
                const std::uint32_t head_off = (((bytes - 1u) >> 3u) * 4u) + 0x0cu;
                store32(ptr_of(movie.begin), 0x04u, load32(pool, head_off));
                store32(pool, head_off, movie.begin);
                heap_leave_005322c0(load_ptr(pool, 0x00u));
            }
        }
    }

    void* const end_service = *reinterpret_cast<void* const*>(
        static_cast<const std::uint8_t*>(game_setup_movie_service_0069ed0c) + 4);
    game_setup_movie_service_end_00536050(end_service);
}

} // namespace porsche
