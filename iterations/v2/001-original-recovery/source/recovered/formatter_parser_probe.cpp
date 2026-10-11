#include "porsche/formatter_parser.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace porsche {
FormatterFloatBoundary formatter_float_boundary_005e5788=nullptr;
FormatterTextBoundary formatter_float_post_005e5794=nullptr;
FormatterTextBoundary formatter_float_post_005e578c=nullptr;
FormatterUnsigned64Boundary formatter_unsigned_divide_boundary_005a67b0=nullptr;
FormatterUnsigned64Boundary formatter_unsigned_remainder_boundary_005a6820=nullptr;
FormatterLengthBoundary formatter_length_boundary_005a6730=nullptr;
static const char null_text[]="(null)";
static const unsigned short null_wide[]={'(','n','u','l','l',')',0};
const char* formatter_null_narrow_005e57a0=null_text;
const unsigned short* formatter_null_wide_005e57a4=null_wide;
static std::uint8_t ctype_table[512];
static const std::uint8_t* initial_ctype_table=nullptr;
static char float_text[] = "-1.25";
static int float_calls, float_post_alt_calls, float_post_g_calls;
static int wide_calls;
static int cleanup_calls;
static std::uint32_t cleanup_character;
static bool cleanup_descriptor_valid;
static std::uint32_t divide_calls,remainder_calls;
static std::uint64_t divide_hash,remainder_hash;
static unsigned length_calls;
static std::uint64_t length_hash;
static std::uint32_t last_float_low, last_float_high;
static int last_float_conversion, last_float_precision, last_float_mode;
static unsigned short last_wide_value;
static char text_arg[]="abcdef";
static unsigned short wide_arg[]={'A','B',0};
struct CountedString { std::uint16_t length; std::uint16_t pad; const char* data; };
static CountedString counted_arg{3,0,"xyz"};
static CountedString counted_null_arg{3,0,nullptr};
static CountedString counted_wide_arg{4,0,reinterpret_cast<const char*>(wide_arg)};
static std::int32_t count_arg=0x12345678;

static void __cdecl float_boundary(const void* value, char* out, int conv, int precision, int mode) {
    std::memcpy(&last_float_low, value, 4); std::memcpy(&last_float_high, static_cast<const char*>(value)+4, 4);
    last_float_conversion=conv; last_float_precision=precision; last_float_mode=mode;
    std::memcpy(out,float_text,sizeof(float_text)); ++float_calls;
}
static void __cdecl post_alt(char*) { ++float_post_alt_calls; }
static void __cdecl post_g(char*) { ++float_post_g_calls; }
static int __cdecl wide_encode(char* out, std::uint32_t raw) {
    const auto ch=static_cast<unsigned short>(raw);
    last_wide_value=ch; ++wide_calls;
    if(ch>0x7f) return -1;
    out[0]=static_cast<char>(ch); return 1;
}
static void hash_word(std::uint64_t& hash,std::uint32_t word) {
    for(unsigned i=0;i<4;++i){hash^=static_cast<std::uint8_t>(word>>(i*8));hash*=1099511628211ull;}
}
static int __cdecl length_boundary(const char* text) {
    int n=0;while(text[n]){length_hash^=static_cast<std::uint8_t>(text[n]);length_hash*=1099511628211ull;++n;}
    hash_word(length_hash,static_cast<std::uint32_t>(n));++length_calls;return n;
}
static std::uint64_t __stdcall divide_boundary(std::uint64_t a,std::uint64_t b) {
    const auto out=a/b; ++divide_calls; hash_word(divide_hash,static_cast<std::uint32_t>(a));hash_word(divide_hash,static_cast<std::uint32_t>(a>>32));
    hash_word(divide_hash,static_cast<std::uint32_t>(b));hash_word(divide_hash,static_cast<std::uint32_t>(b>>32));hash_word(divide_hash,static_cast<std::uint32_t>(out));hash_word(divide_hash,static_cast<std::uint32_t>(out>>32));return out;
}
static std::uint64_t __stdcall remainder_boundary(std::uint64_t a,std::uint64_t b) {
    const auto out=a%b; ++remainder_calls; hash_word(remainder_hash,static_cast<std::uint32_t>(a));hash_word(remainder_hash,static_cast<std::uint32_t>(a>>32));
    hash_word(remainder_hash,static_cast<std::uint32_t>(b));hash_word(remainder_hash,static_cast<std::uint32_t>(b>>32));hash_word(remainder_hash,static_cast<std::uint32_t>(out));hash_word(remainder_hash,static_cast<std::uint32_t>(out>>32));return out;
}

int __cdecl formatter_wide_encode_boundary_005abf5e(char* out, std::uint32_t raw) {
    return wide_encode(out,raw);
}

std::int32_t __cdecl formatter_original_cleanup_boundary_005a4259(
    std::uint32_t character, FormatterOriginalDescriptor32* descriptor) {
    ++cleanup_calls;cleanup_character=character;cleanup_descriptor_valid=descriptor!=nullptr;return -1;
}

struct Case { const char* name; const char* format; std::uint32_t words[4]; int n; };

static void run(const Case& c) {
    char output[256]; std::memset(output,0xcc,sizeof(output));
    const bool lead_case=std::strncmp(c.name,"lead_",5)==0;
    std::memset(ctype_table,0,sizeof(ctype_table));
    formatter_ctype_table_005e52d0=initial_ctype_table;
    if(lead_case&&std::strcmp(c.name,"lead_initial_pair")!=0) {
        formatter_ctype_table_005e52d0=ctype_table;
        if(std::strcmp(c.name,"lead_pair_disabled")!=0) ctype_table[0xe9u*2u+1u]=0x80;
    }
    int initial_remaining=128;
    if(std::strcmp(c.name,"cleanup_abort")==0||std::strcmp(c.name,"lead_zero_capacity")==0) initial_remaining=0;
    if(std::strcmp(c.name,"lead_one_capacity")==0) initial_remaining=1;
    FormatterOriginalDescriptor32 d{output,initial_remaining,output,0x42,{}};
    for(unsigned i=0;i<16;++i)d.opaque_tail[i]=static_cast<unsigned char>(0xa0+i);
    std::uint32_t words[4]={c.words[0],c.words[1],c.words[2],c.words[3]};
    if(std::strcmp(c.name,"string_precision")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(text_arg));
    if(std::strcmp(c.name,"string_star_negative")==0) words[1]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(text_arg));
    if(std::strcmp(c.name,"wide_string")==0||std::strcmp(c.name,"wide_upper_S")==0||std::strcmp(c.name,"wide_zero_pad")==0||std::strcmp(c.name,"wide_left_pad")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(wide_arg));
    if(std::strcmp(c.name,"counted_string")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&counted_arg));
    if(std::strcmp(c.name,"counted_null")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&counted_null_arg));
    if(std::strcmp(c.name,"counted_wide")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&counted_wide_arg));
    count_arg=0x12345678;
    if(std::strcmp(c.name,"count_store")==0||std::strcmp(c.name,"count_store_short")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&count_arg));
    float_calls=float_post_alt_calls=float_post_g_calls=wide_calls=0;
    cleanup_calls=0;cleanup_character=0;cleanup_descriptor_valid=false;
    divide_calls=remainder_calls=0;divide_hash=remainder_hash=1469598103934665603ull;
    length_calls=0;length_hash=1469598103934665603ull;
    last_float_low=last_float_high=0;last_float_conversion=last_float_precision=last_float_mode=0;last_wide_value=0;
    formatter_float_boundary_005e5788=float_boundary;
    formatter_float_post_005e5794=post_alt;
    formatter_float_post_005e578c=post_g;
    formatter_unsigned_divide_boundary_005a67b0=divide_boundary;
    formatter_unsigned_remainder_boundary_005a6820=remainder_boundary;
    formatter_length_boundary_005a6730=length_boundary;
    const int result=formatter_parser_005a4371(&d,
        reinterpret_cast<const unsigned char*>(c.format),words);
    const unsigned used=static_cast<unsigned>(d.cursor-output);
    std::printf("{\"case\":\"%s\",\"result\":%d,\"remaining\":%d,\"used\":%u,\"raw_words\":0,\"bytes\":\"",
        c.name,result,d.remaining,used);
    for(unsigned i=0;i<used;++i)std::printf("%02x",static_cast<unsigned char>(output[i]));
    std::printf("\",\"base_offset\":%d,\"flags\":%u,\"tail\":\"",static_cast<int>(d.base-output),d.flags);
    for(const auto byte:d.opaque_tail)std::printf("%02x",byte);
    std::printf("\",\"stored\":%d,\"float_calls\":%d,\"float_low\":%u,\"float_high\":%u,\"float_conv\":%d,\"float_precision\":%d,\"float_mode\":%d,\"post_alt\":%d,\"post_g\":%d,\"wide_calls\":%d,\"wide_value\":%u,\"cleanup_calls\":%d,\"cleanup_character\":%u,\"cleanup_descriptor_valid\":%s,\"divide_calls\":%u,\"divide_hash\":\"%016llx\",\"remainder_calls\":%u,\"remainder_hash\":\"%016llx\",\"length_calls\":%u,\"length_hash\":\"%016llx\"}\n",
        count_arg,float_calls,last_float_low,last_float_high,last_float_conversion,last_float_precision,last_float_mode,
        float_post_alt_calls,float_post_g_calls,wide_calls,last_wide_value,cleanup_calls,cleanup_character,cleanup_descriptor_valid?"true":"false",divide_calls,static_cast<unsigned long long>(divide_hash),
        remainder_calls,static_cast<unsigned long long>(remainder_hash),length_calls,static_cast<unsigned long long>(length_hash));
}
}

int main() {
    using namespace porsche;
    initial_ctype_table=formatter_ctype_table_005e52d0;
    const Case cases[]={
        {"literal","plain text",{0,0,0,0},0},
        {"signed","%+06d",{static_cast<std::uint32_t>(-42),0,0,0},1},
        {"hex_alt","%#x",{0x1234,0,0,0},1},
        {"hex_alt_zero","%#x",{0,0,0,0},1},{"upperhex_alt_zero","%#X",{0,0,0,0},1},
        {"hex_alt_zero_precision","%#.0x",{0,0,0,0},1},{"pointer_alt_zero","%#p",{0,0,0,0},1},
        {"oct_zero_alt","%#o",{0,0,0,0},1},
        {"star_width_precision","%*.*x",{8,4,0x2a,0},3},
        {"string_precision","%.3s",{0,0,0,0},1},
        {"null_string","%s",{0,0,0,0},1},
        {"count_store","abc%nX",{0,0,0,0},1},
        {"float_boundary","%f",{0,0x3ff00000,0,0},2},
        {"float_g_alt","%#.0g",{0,0x3ff00000,0,0},2},
        {"unknown","%qZ",{0,0,0,0},0},
        {"literal_after_percent","%I?",{0,0,0,0},0},
        {"unsigned_high","%u",{0xffffffff,0,0,0},1},
        {"signed_min","%d",{0x80000000,0,0,0},1},
        {"zero_precision","%.0d",{0,0,0,0},1},
        {"zero_left","%-06d",{12,0,0,0},1},
        {"negative_width","%*d",{0xfffffffb,12,0,0},2},
        {"negative_precision","%.*d",{0xfffffffe,12,0,0},2},
        {"upperhex_alt","%#X",{0xdeadbeef,0,0,0},1},
        {"pointer","%p",{0xdeadbeef,0,0,0},1},
        {"int64_signed","%I64d",{0xffffffd6,0xffffffff,0,0},2},
        {"char","%c",{65,0,0,0},1},
        {"wide_char","%C",{65,0,0,0},1},
        {"wide_string","%ls",{0,0,0,0},1},
        {"percent","%%",{0,0,0,0},0},
        {"float_upper_e","%E",{0,0x3ff00000,0,0},2},
        {"float_upper_g","%G",{0,0x3ff00000,0,0},2},
        {"float_g_trim","%g",{0,0x3ff00000,0,0},2},
        {"wide_upper_S","%S",{0,0,0,0},1},
        {"wide_zero_pad","%05ls",{0,0,0,0},1},{"wide_left_pad","%-5ls",{0,0,0,0},1},
        {"counted_string","%Z",{0,0,0,0},1},
        {"high_byte_literal","\xe9",{0,0,0,0},0},
        {"lead_initial_pair","\xe9" "%u",{0x1234,0,0,0},1},
        {"lead_pair_enabled","\xe9" "%u",{0x1234,0,0,0},1},
        {"lead_pair_disabled","\xe9" "%u",{0x1234,0,0,0},1},
        {"lead_terminal","\xe9",{0,0,0,0},0},
        {"lead_zero_capacity","\xe9" "AB",{0,0,0,0},0},
        {"lead_one_capacity","\xe9" "AB",{0,0,0,0},0},
        {"width_int_min","%*d",{0x80000000,12,0,0},2},
        {"width_overflow","%2147483648d",{12,0,0,0},1},
        {"precision_int_min","%.*d",{0x80000000,12,0,0},2},
        {"octal_precision_alt","%#.0o",{0,0,0,0},1},
        {"octal_nonzero_alt","%#o",{8,0,0,0},1},
        {"zero_char","%c",{0,0,0,0},1},
        {"wide_char_failure","%C",{0x80,0,0,0},1},
        {"long_char","%lc",{65,0,0,0},1},
        {"count_store_short","abc%hnX",{0,0,0,0},1},
        {"counted_null","%Z",{0,0,0,0},1},
        {"counted_wide","%wZ",{0,0,0,0},1},
        {"string_star_negative","%.*s",{0xffffffff,0,0,0},2},
        {"signed_i","%i",{0xffffffd6,0,0,0},1},
        {"short_signed","%hd",{0xffffffff,0,0,0},1},
        {"short_unsigned","%hu",{0xffffffff,0,0,0},1},
        {"int64_unsigned","%I64u",{0,1,0,0},2},
        {"float_lower_e","%.2e",{0,0x3ff00000,0,0},2},
        {"float_alt_zero","%#.0f",{0,0x3ff00000,0,0},2},
        {"cleanup_abort","X",{0,0,0,0},0}
    };
    for(const auto& c:cases) run(c);
}
