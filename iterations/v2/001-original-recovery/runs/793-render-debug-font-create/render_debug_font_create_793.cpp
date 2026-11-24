// Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Original 0053c6c0..0053c8a9 (490B), 0053d920..0053d969 (74B), 0053d970..0053d9b9 (74B),
// 0053e5c0..0053e842 (643B), 00573a90..00573aa0 (17B), 00573ab0..00573abd (14B),
// 00573ac0..00573add (30B), and 00573ae0..00573b1a (59B).
#include "render_debug_font_create_793.hpp"

#include <cstring>

namespace porsche {

static_assert(sizeof(void*) == 4u, "original x86 layout requires 32-bit pointers");

const char font_setstate_invalid_state_005bbb20[34] =
    "FONT_setstate - Invalid state %d\n";

const std::uint16_t font_ascii_to_sjis_fullwidth_005dfcc8[96] = {
    0x8140u, 0x8149u, 0x8167u, 0x8194u, 0x8190u, 0x8193u, 0x8195u, 0x8166u,
    0x8169u, 0x816au, 0x8196u, 0x817bu, 0x8143u, 0x817cu, 0x8144u, 0x815eu,
    0x824fu, 0x8250u, 0x8251u, 0x8252u, 0x8253u, 0x8254u, 0x8255u, 0x8256u,
    0x8257u, 0x8258u, 0x8146u, 0x8147u, 0x8183u, 0x8181u, 0x8184u, 0x8148u,
    0x8197u, 0x8260u, 0x8261u, 0x8262u, 0x8263u, 0x8264u, 0x8265u, 0x8266u,
    0x8267u, 0x8268u, 0x8269u, 0x826au, 0x826bu, 0x826cu, 0x826du, 0x826eu,
    0x826fu, 0x8270u, 0x8271u, 0x8272u, 0x8273u, 0x8274u, 0x8275u, 0x8276u,
    0x8277u, 0x8278u, 0x8279u, 0x816du, 0x815fu, 0x816eu, 0x81aau, 0x8151u,
    0x8165u, 0x8281u, 0x8282u, 0x8283u, 0x8284u, 0x8285u, 0x8286u, 0x8287u,
    0x8288u, 0x8289u, 0x828au, 0x828bu, 0x828cu, 0x828du, 0x828eu, 0x828fu,
    0x8290u, 0x8291u, 0x8292u, 0x8293u, 0x8294u, 0x8295u, 0x8296u, 0x8297u,
    0x8298u, 0x8299u, 0x829au, 0x816fu, 0x8162u, 0x8170u, 0x8160u, 0x81a6u,
};

namespace {

std::uint32_t read_u32(const void* base, std::size_t offset) {
    std::uint32_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

std::int32_t read_i32(const void* base, std::size_t offset) {
    std::int32_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

std::uint16_t read_u16(const void* base, std::size_t offset) {
    std::uint16_t value = 0u;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

std::int8_t read_i8(const void* base, std::size_t offset) {
    std::int8_t value = 0;
    std::memcpy(&value, static_cast<const std::uint8_t*>(base) + offset, sizeof(value));
    return value;
}

void write_u32(void* base, std::size_t offset, std::uint32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_i32(void* base, std::size_t offset, std::int32_t value) {
    std::memcpy(static_cast<std::uint8_t*>(base) + offset, &value, sizeof(value));
}

void write_ptr(void* base, std::size_t offset, const void* ptr) {
    const std::uint32_t raw = static_cast<std::uint32_t>(
        reinterpret_cast<std::uintptr_t>(ptr));
    write_u32(base, offset, raw);
}

const void* read_ptr(const void* base, std::size_t offset) {
    const std::uint32_t raw = read_u32(base, offset);
    return reinterpret_cast<const void*>(static_cast<std::uintptr_t>(raw));
}

float fixed16_to_float(std::uint32_t value) {
    return static_cast<float>(
        static_cast<double>(static_cast<std::int64_t>(value)) * (1.0 / 65536.0));
}

void set_flag_bit(void* font, std::uint32_t mask, std::uint32_t value) {
    std::uint32_t flags = read_u32(font, 0xbcu);
    if (value == 1u) {
        flags |= mask;
    } else {
        flags &= ~mask;
    }
    write_u32(font, 0xbcu, flags);
}

void set_dirty_u32(void* font, std::size_t offset, std::uint32_t value) {
    if (read_u32(font, offset) != value) {
        write_u32(font, offset, value);
        static_cast<std::uint8_t*>(font)[0xacu] = 1u;
    }
}

void* select_char_reader(
    const std::uint8_t* base, std::int32_t encoding, std::int32_t num_chars) {
    if (encoding == 1) {
        return reinterpret_cast<void*>(&font_read_u16_cursor_00573a90);
    }
    if (encoding == 2) {
        return reinterpret_cast<void*>(&font_read_sjis_cursor_00573ae0);
    }
    if (num_chars > 0xff || render_buffer_read_word_0056e2a8(base + 0x20u, 2) > 0xffu) {
        return reinterpret_cast<void*>(&font_read_sjis_cursor_00573ae0);
    }
    return reinterpret_cast<void*>(&font_read_u8_cursor_00573ab0);
}

} // namespace

std::uint32_t __cdecl font_read_u16_cursor_00573a90(const std::uint8_t** cursor) {
    const std::uint8_t* const p = *cursor;
    const std::uint16_t ch = read_u16(p, 0u);
    *cursor = p + 2;
    return static_cast<std::uint32_t>(ch);
}

std::uint32_t __cdecl font_read_u8_cursor_00573ab0(const std::uint8_t** cursor) {
    const std::uint8_t* const p = *cursor;
    const std::uint8_t ch = *p;
    *cursor = p + 1;
    return static_cast<std::uint32_t>(ch);
}

std::uint32_t __cdecl font_ascii_to_sjis_fullwidth_00573ac0(std::uint32_t ch) {
    const std::uint16_t lo = static_cast<std::uint16_t>(ch & 0xffffu);
    if (lo < 0x20u || lo > 0x7fu) {
        return ch;
    }
    return static_cast<std::uint32_t>(font_ascii_to_sjis_fullwidth_005dfcc8[lo - 0x20u]);
}

std::uint32_t __cdecl font_read_sjis_cursor_00573ae0(const std::uint8_t** cursor) {
    const std::uint8_t* p = *cursor;
    const std::uint8_t b0 = *p++;
    if ((b0 & 0x80u) != 0u) {
        const std::uint8_t b1 = *p++;
        *cursor = p;
        return (static_cast<std::uint32_t>(b0) << 8u) | static_cast<std::uint32_t>(b1);
    }
    const std::uint32_t mapped = font_ascii_to_sjis_fullwidth_00573ac0(b0) & 0xffffu;
    *cursor = p;
    return mapped;
}

const void* __cdecl font_bsearch_glyph_0053d970(
    std::uint32_t key, const void* table, std::int32_t count, std::int32_t stride) {
    if (count == 0) {
        return nullptr;
    }
    const auto* base = static_cast<const std::uint8_t*>(table);
    std::int32_t rem = count;
    while (rem != 0) {
        const std::uint8_t* const mid = base + (rem >> 1) * stride;
        const std::uint32_t code = render_buffer_read_word_0056e2a8(mid, 2);
        const std::int32_t diff = static_cast<std::int32_t>(key - code);
        if (diff == 0) {
            return mid;
        }
        if (diff > 0) {
            base = mid + stride;
            --rem;
        }
        rem >>= 1;
    }
    return nullptr;
}

const void* __cdecl font_find_glyph_0053d920(const void* font, std::uint32_t ch) {
    const std::int32_t num_chars = read_i32(font, 0x1cu);
    const auto* const table = static_cast<const std::uint8_t*>(read_ptr(font, 0x28u));
    const std::int32_t idx = static_cast<std::int32_t>(ch - 0x20u);
    if (idx < num_chars) {
        const std::uint8_t* const entry = table + idx * 11;
        if (render_buffer_read_word_0056e2a8(entry, 2) == ch) {
            return entry;
        }
    }
    return font_bsearch_glyph_0053d970(ch, table, num_chars, 11);
}

void __cdecl font_setstate_0053e5c0(void* font, std::int32_t state, std::uint32_t value) {
    switch (state) {
    case 0:
        font_setstatef_0053e890(font, 1, 0.0f);
        font_setstatef_0053e890(font, 2, 1.0f);
        font_setstatef_0053e890(font, 3, 1.0f);
        return;
    case 1:
    case 2:
    case 3:
    case 4:
        font_setstatef_0053e890(font, state, fixed16_to_float(value));
        return;
    case 5:
        set_flag_bit(font, 1u, value);
        return;
    case 6:
        set_flag_bit(font, 2u, value);
        return;
    case 7:
        set_flag_bit(font, 4u, value);
        return;
    case 8:
        set_dirty_u32(font, 0x5cu, value);
        return;
    case 9:
        set_dirty_u32(font, 0x60u, value);
        return;
    case 10:
        set_dirty_u32(font, 0x64u, value);
        return;
    case 11:
        set_dirty_u32(font, 0x68u, value);
        return;
    case 12:
        write_u32(font, 0x4cu, value);
        write_u32(font, 0x50u, value);
        write_u32(font, 0x54u, value);
        write_u32(font, 0x58u, value);
        return;
    case 13:
        write_u32(font, 0x4cu, value);
        return;
    case 14:
        write_u32(font, 0x50u, value);
        return;
    case 15:
        write_u32(font, 0x54u, value);
        return;
    case 16:
        write_u32(font, 0x58u, value);
        return;
    default:
        diagnostic_file_005deb74_set("\\real\\cmn\\fontattr.c");
        diagnostic_line_005deb78 = 0xb6u;
        reinterpret_cast<void(__cdecl*)(const char*, std::int32_t)>(
            diagnostic_handler_005debf0)(font_setstate_invalid_state_005bbb20, state);
        return;
    }
}

void* __cdecl render_debug_font_create_0053c6c0(const void* font_data) {
    using AllocFn = void*(__cdecl*)(std::int32_t bytes);
    auto* const ops = static_cast<void* const*>(render_service_ops_005dec08);
    const auto alloc_fn = reinterpret_cast<AllocFn>(ops[5]);
    void* const font = alloc_fn(0xec);
    if (font == nullptr) {
        return nullptr;
    }
    std::memset(font, 0, 0xecu);

    const auto* const base = static_cast<const std::uint8_t*>(font_data);
    write_i32(font, 0x20u, 0x64);
    write_i32(font, 0x38u, 0);
    write_ptr(font, 0x24u, base);

    const std::int32_t f10 = read_i8(base, 0x10u);
    const std::int32_t f11 = read_i8(base, 0x11u);
    const std::int32_t f12 = read_i8(base, 0x12u);
    const std::int32_t f13 = read_i8(base, 0x13u);
    write_i32(font, 0x04u, f10);
    write_i32(font, 0x08u, f11);
    write_i32(font, 0x0cu, f12);
    write_i32(font, 0x10u, f13);
    write_i32(font, 0x14u, f12 + f13);
    write_i32(font, 0x18u, f12 + f13);

    const std::uint32_t off1c = read_u32(base, 0x1cu);
    const std::uint32_t off14 = read_u32(base, 0x14u);
    write_ptr(font, 0x2cu, base + off1c);
    write_ptr(font, 0x28u, base + off14);

    const std::int32_t num_chars = static_cast<std::int32_t>(read_u16(base, 0x0au));
    write_i32(font, 0x1cu, num_chars);
    const std::int32_t encoding = (read_i32(base, 0x0cu) >> 16) & 3;
    write_ptr(font, 0x30u, select_char_reader(base, encoding, num_chars));

    font_state_set_pair_0053eea0(font, 0u, 0u);
    font_setstate_0053e5c0(font, 0, 0u);
    font_setstate_0053e5c0(font, 5, 0u);
    font_setstate_0053e5c0(font, 6, 0u);
    font_setstate_0053e5c0(font, 7, 0u);
    font_setstate_0053e5c0(font, 12, 0xffffffffu);
    font_setstate_0053e5c0(font, 8, 0xffffffffu);
    font_setstate_0053e5c0(font, 9, 0x00ffffffu);
    font_setstate_0053e5c0(font, 10, 0xff000000u);
    font_setstate_0053e5c0(font, 11, 0xff000000u);
    font_setstatef_0053e890(font, 18, 0.0f);
    font_setstatef_0053e890(font, 19, 0.0f);
    font_setstatef_0053e890(font, 20, 0.0f);
    font_setstatef_0053e890(font, 21, 0.0f);
    font_setstatef_0053e890(font, 22, 0.0f);
    font_setstatef_0053e890(font, 23, 1.0f);
    static_cast<std::uint8_t*>(font)[0xacu] = 1u;

    const void* glyph = nullptr;
    for (std::uint32_t ch = 0x41u; ch <= 0x45u; ++ch) {
        glyph = font_find_glyph_0053d920(font, ch);
        if (glyph != nullptr) {
            break;
        }
    }
    if (glyph != nullptr) {
        const auto* const g = static_cast<const std::uint8_t*>(glyph);
        const std::int32_t y_offset = read_i8(g, 0x0au);
        const std::int32_t height = static_cast<std::int32_t>(g[3]);
        const std::int32_t prev_ascent = read_i32(font, 0x0cu);
        const std::int32_t new_ascent = height + y_offset;
        write_i32(font, 0x10u, prev_ascent - height - y_offset);
        write_i32(font, 0x0cu, new_ascent);
    }

    return font;
}

} // namespace porsche
