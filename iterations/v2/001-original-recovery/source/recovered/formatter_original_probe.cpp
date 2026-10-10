#include "porsche/formatter_original.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace {
std::uint32_t cleanup_calls;
std::uint32_t cleanup_last_character;
bool cleanup_descriptor_nonnull;
}

namespace porsche {
std::int32_t __cdecl formatter_original_cleanup_boundary_005a4259(
    std::uint32_t emitted_character, FormatterOriginalDescriptor32* descriptor) {
    ++cleanup_calls;
    cleanup_last_character = emitted_character;
    cleanup_descriptor_nonnull = descriptor != nullptr;
    return -1; // Recording-only; no capacity-exhaustion case invokes it.
}
}

using porsche::FormatterOriginalDescriptor32;

static void print_bytes(const std::uint8_t* bytes, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) std::printf("%02x", bytes[i]);
}

static void print_desc(const char* name, const FormatterOriginalDescriptor32& d,
                       const std::uint8_t* out, std::size_t used, std::int32_t count,
                       bool return_is_counter = false, bool boundary_case = false) {
    const auto* cursor = reinterpret_cast<const std::uint8_t*>(d.cursor);
    const auto* base = reinterpret_cast<const std::uint8_t*>(d.base);
    std::printf("{\"case\":\"%s\",\"cursor\":%td,\"remaining\":%d,\"base\":%td,\"flags\":%u,\"tail\":\"",
        name, cursor - out, d.remaining, base - out, d.flags);
    print_bytes(d.opaque_tail, sizeof(d.opaque_tail));
    std::printf("\",\"bytes\":\""); print_bytes(out, used);
    std::printf("\",\"count\":%d", count);
    if (return_is_counter) std::printf(",\"return_is_counter\":true");
    if (boundary_case) std::printf(",\"cleanup_calls\":%u,\"cleanup_character\":%u,\"cleanup_descriptor_is_argument\":%s",
        cleanup_calls, cleanup_last_character, cleanup_descriptor_nonnull?"true":"false");
    std::printf("}\n");
}

int main() {
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 10,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0xa0+i);
        std::int32_t count=5;
        const auto* result=porsche::formatter_original_emit_005a4ab2(-1,&d,&count);
        print_desc(result==reinterpret_cast<const std::uint32_t*>(&count)?"emit_ff":"emit_bad",d,out.data(),1,count,
                   result==reinterpret_cast<const std::uint32_t*>(&count));
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 0,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x80+i);
        std::int32_t count=3;
        const auto* result=porsche::formatter_original_emit_005a4ab2(-1,&d,&count);
        print_desc(result==reinterpret_cast<const std::uint32_t*>(&count)?"emit_overflow":"emit_bad",d,out.data(),0,count,
                   result==reinterpret_cast<const std::uint32_t*>(&count),true);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 4,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x30+i);
        std::int32_t count=INT32_MAX;
        porsche::formatter_original_emit_005a4ab2('W',&d,&count);
        print_desc("emit_count_wrap",d,out.data(),1,count);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 8,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x40+i);
        std::int32_t count=2;
        porsche::formatter_original_repeat_005a4ae7('A',3,&d,&count);
        print_desc("repeat_3",d,out.data(),3,count);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 8,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x10+i);
        std::int32_t count=7;
        porsche::formatter_original_repeat_005a4ae7('Z',-2,&d,&count);
        print_desc("repeat_negative",d,out.data(),0,count);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 8,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x50+i);
        std::int32_t count=-2;
        porsche::formatter_original_repeat_005a4ae7('Q',4,&d,&count);
        print_desc("repeat_abort_minus1",d,out.data(),1,count);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 8,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x70+i);
        const std::uint8_t input[]={0x41,0x00,0xff,0x7f}; std::int32_t count=1;
        porsche::formatter_original_span_005a4b18(input,4,&d,&count);
        print_desc("span_binary",d,out.data(),4,count);
    }
    {
        std::array<std::uint8_t, 64> out{}; out.fill(0xcc);
        FormatterOriginalDescriptor32 d{reinterpret_cast<char*>(out.data()), 8,
            reinterpret_cast<char*>(out.data()), 0x42, {}};
        for (std::size_t i=0;i<sizeof(d.opaque_tail);++i) d.opaque_tail[i]=static_cast<std::uint8_t>(0x20+i);
        const std::uint8_t input[]={'x','y','z'}; std::int32_t count=0;
        porsche::formatter_original_span_005a4b18(input,2,&d,&count);
        print_desc("span_length_2",d,out.data(),2,count);
    }
    {
        std::uint32_t raw[]={0x12345678,0x89abcdef,0x01234567}; auto* p=raw;
        const auto value=porsche::formatter_original_next_u32_005a4b50(&p);
        std::printf("{\"case\":\"next_u32\",\"value\":%u,\"cursor_words\":%td}\n",value,p-raw);
    }
    {
        std::uint32_t raw[]={0x12345678,0x89abcdef,0x01234567}; auto* p=raw;
        const auto value=porsche::formatter_original_next_u64_005a4b5d(&p);
        std::printf("{\"case\":\"next_u64\",\"value\":%llu,\"cursor_words\":%td}\n",
            static_cast<unsigned long long>(value),p-raw);
    }
    {
        std::uint32_t raw[]={0x89abcdef,0x01234567}; auto* p=raw;
        const auto value=porsche::formatter_original_next_u16_005a4b6d(&p);
        std::printf("{\"case\":\"next_u16\",\"value\":%u,\"cursor_words\":%td}\n",value,p-raw);
    }
    std::printf("{\"case\":\"cleanup_boundary\",\"cleanup_calls\":%u,\"character\":%u,\"descriptor_nonnull\":%s}\n",
        cleanup_calls,cleanup_last_character,cleanup_descriptor_nonnull?"true":"false");
}
