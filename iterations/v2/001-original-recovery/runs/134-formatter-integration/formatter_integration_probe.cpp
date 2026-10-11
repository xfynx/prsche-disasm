#include "porsche/formatter_cleanup.hpp"
#include "porsche/formatter_entry.hpp"
#include "porsche/formatter_parser.hpp"
#include "porsche/formatter_original.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace porsche {
std::int32_t __cdecl formatter_entry32_adapter_005a0fbf(
    char*, const char*, const std::uint32_t*, const std::uint8_t[16], FormatterOriginalDescriptor32*);

struct Trace {
    std::uint32_t event_count=0, events[8]{};
    std::uint32_t writes=0, write_file=0, write_len=0;
    std::uint8_t write_data[16]{};
    std::uint32_t prepares=0, prepare_file=0, prepare_flags=0;
    std::uint32_t aux=0, divide=0, remainder=0, lengths=0;
    std::int32_t write_result=1;
} trace;

static std::uint8_t invalid_record[36]{};
static std::uint8_t handle_bank[32*36]{};
const std::uint8_t* formatter_cleanup_invalid_handle_record_005e5f50=invalid_record;
const std::uint8_t* formatter_cleanup_preceding_handle_bank_006c01dc=handle_bank;
const std::uint8_t* formatter_cleanup_handle_table_006c01e0[1]={handle_bank};
std::uint32_t formatter_cleanup_handle_limit_006c02e0=32;
FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5508=nullptr;
FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5528=nullptr;

static const char null_narrow[]="(null)";
static const unsigned short null_wide[]={'(','n','u','l','l',')',0};
const char* formatter_null_narrow_005e57a0=null_narrow;
const unsigned short* formatter_null_wide_005e57a4=null_wide;

void __cdecl float_stub(const void*,char* out,int,int,int) { std::memcpy(out,"1.0",4); }
void __cdecl float_post_stub(char*) {}
std::uint64_t __stdcall divide_stub(std::uint64_t a,std::uint64_t b) {
    ++trace.divide; return b ? a/b : 0;
}
std::uint64_t __stdcall remainder_stub(std::uint64_t a,std::uint64_t b) {
    ++trace.remainder; return b ? a%b : 0;
}
int __cdecl length_stub(const char* s) { ++trace.lengths; return static_cast<int>(std::strlen(s)); }
FormatterFloatBoundary formatter_float_boundary_005e5788=float_stub;
FormatterTextBoundary formatter_float_post_005e5794=float_post_stub;
FormatterTextBoundary formatter_float_post_005e578c=float_post_stub;




int __cdecl formatter_wide_encode_boundary_005abf5e(char* dst,std::uint32_t ch) {
    if(ch>0x7f) return -1; dst[0]=static_cast<char>(ch); return 1;
}

std::int32_t __cdecl formatter_cleanup_file_write_005a9e49(
    std::uint32_t file,const void* bytes,std::int32_t length) {
    trace.events[trace.event_count++]=2; ++trace.writes; trace.write_file=file;
    trace.write_len=static_cast<std::uint32_t>(length);
    if(length>0&&length<=static_cast<int>(sizeof(trace.write_data)))
        std::memcpy(trace.write_data,bytes,static_cast<std::size_t>(length));
    return trace.write_result;
}
std::int32_t __cdecl formatter_cleanup_file_aux_005a9ab8(
    std::uint32_t,std::uint32_t,std::uint32_t) {
    trace.events[trace.event_count++]=3; ++trace.aux; return 0;
}
std::int32_t __cdecl formatter_cleanup_prepare_descriptor_005abef1(
    FormatterOriginalDescriptor32* d) {
    trace.events[trace.event_count++]=1; ++trace.prepares;
    trace.prepare_flags=d->flags;
    std::memcpy(&trace.prepare_file,d->opaque_tail,4);
    return 0;
}
} // namespace porsche

namespace {
using namespace porsche;
struct Input { const char* name; const char* format; std::uint32_t a[4]; unsigned n; bool string_arg; };
const Input inputs[]={
    {"literal","plain text",{0,0,0,0},0,false},
    {"signed_width","%+06d",{0xffffffd6,0,0,0},1,false},
    {"hex_alt","%#x",{0x1234,0,0,0},1,false},
    {"star_width_precision","%*.*x",{8,4,0x2a,0},3,false},
    {"string_precision","%.3s",{0,0,0,0},1,true},
    {"count_store","abc%nX",{0,0,0,0},1,false},
    {"unsigned_word","%u",{0xffffffff,0,0,0},1,false},
    {"int64_signed","%I64d",{0xffffffd6,0xffffffff,0,0},2,false},
    {"unknown_conversion","%qZ",{0,0,0,0},0,false},
    {"literal_high_byte","\xe9",{0,0,0,0},0,false},
};

void reset_trace() { trace=Trace{}; }
void print_hex(const std::uint8_t* p,std::size_t n) { for(std::size_t i=0;i<n;++i) std::printf("%02x",p[i]); }
void print_events() { std::printf("["); for(std::uint32_t i=0;i<trace.event_count;++i) std::printf("%s%u",i?",":"",trace.events[i]); std::printf("]"); }

void run_entry_case(const Input& in) {
    reset_trace(); char text[]="abcdef"; char output[128]; std::memset(output,0xcc,sizeof(output));
    std::uint32_t words[4]={in.a[0],in.a[1],in.a[2],in.a[3]};
    if(in.string_arg) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(text));
    std::int32_t stored=0x12345678;
    if(std::strcmp(in.name,"count_store")==0) words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&stored));
    const std::uint8_t tail[16]={0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf};
    FormatterOriginalDescriptor32 final_descriptor;
    const auto result=formatter_entry32_adapter_005a0fbf(output,in.format,words,tail,&final_descriptor);
    std::size_t used=0; while(used<sizeof(output)&&output[used]) ++used;
    char actual_output[128]; std::memset(actual_output,0xcc,sizeof(actual_output));
    std::uint32_t actual_words[4]={in.a[0],in.a[1],in.a[2],in.a[3]};
    std::int32_t actual_stored=0x12345678;
    if(in.string_arg) actual_words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(text));
    if(std::strcmp(in.name,"count_store")==0)
        actual_words[0]=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&actual_stored));
    reset_trace();
    const auto actual_result=formatter_entry_raw_005a0fbf(actual_output,in.format,actual_words);
    std::size_t actual_used=0; while(actual_used<sizeof(actual_output)&&actual_output[actual_used]) ++actual_used;
    std::printf("{\"case\":\"%s\",\"result\":%d,\"used\":%u,\"remaining\":%d,\"cursor_offset\":%d,\"base_offset\":%d,\"flags\":%u,\"output\":\"",
        in.name,result,static_cast<unsigned>(used),final_descriptor.remaining,
        static_cast<int>(final_descriptor.cursor-output),static_cast<int>(final_descriptor.base-output),final_descriptor.flags);
    print_hex(reinterpret_cast<const std::uint8_t*>(output),used+1);
    std::printf("\",\"stored\":%d,\"actual_result\":%d,\"actual_used\":%u,\"actual_output\":\"",
        stored,actual_result,static_cast<unsigned>(actual_used));
    print_hex(reinterpret_cast<const std::uint8_t*>(actual_output),actual_used+1);
    std::printf("\",\"actual_stored\":%d,\"tail\":\"",actual_stored); print_hex(final_descriptor.opaque_tail,16);
    std::printf("\",\"write_calls\":%u,\"write_file\":%u,\"write_length\":%u,\"write_bytes\":\"\",\"prepare_calls\":%u,\"prepare_file\":%u,\"prepare_flags\":%u,\"aux_calls\":%u,\"aux_file\":0,\"aux_offset\":0,\"aux_origin\":0,\"divide\":%u,\"remainder\":%u,\"lengths\":%u,\"events\":",
        trace.writes,trace.write_file,trace.write_len,trace.prepares,trace.prepare_file,trace.prepare_flags,
        trace.aux,trace.divide,trace.remainder,trace.lengths);
    print_events(); std::printf("}\n");
}

void run_cleanup_bridge() {
    reset_trace(); trace.write_result=1;
    char output[16]; std::memset(output,0xcc,sizeof(output));
    FormatterOriginalDescriptor32 d;
    d.cursor=output; d.remaining=0; d.base=output; d.flags=2;
    const std::uint32_t file=5,opaque14=0x14151617,buffer=8,opaque1c=0x1c1d1e1f;
    std::memcpy(d.opaque_tail,&file,4); std::memcpy(d.opaque_tail+4,&opaque14,4);
    std::memcpy(d.opaque_tail+8,&buffer,4); std::memcpy(d.opaque_tail+12,&opaque1c,4);
    std::int32_t count=0;
    const auto* eax=formatter_original_emit_005a4ab2('K',&d,&count);
    std::printf("{\"case\":\"emit_cleanup_connected\",\"count\":%d,\"eax_is_count_pointer\":%s,\"remaining\":%d,\"flags\":%u,\"cursor_offset\":%d,\"base_offset\":%d,\"tail\":\"",
        count,eax==reinterpret_cast<std::uint32_t*>(&count)?"true":"false",d.remaining,d.flags,
        static_cast<int>(d.cursor-output),static_cast<int>(d.base-output)); print_hex(d.opaque_tail,16);
    std::printf("\",\"write_calls\":%u,\"write_file\":%u,\"write_length\":%u,\"write_bytes\":\"",
        trace.writes,trace.write_file,trace.write_len); print_hex(trace.write_data,trace.write_len);
    std::printf("\",\"prepare_calls\":%u,\"prepare_file\":%u,\"prepare_flags\":%u,\"aux_calls\":%u,\"aux_file\":0,\"aux_offset\":0,\"aux_origin\":0,\"events\":",
        trace.prepares,trace.prepare_file,trace.prepare_flags,trace.aux); print_events(); std::printf("}\n");
}

void run_parser_cleanup_bridge() {
    reset_trace(); trace.write_result=1;
    char output[8]; std::memset(output,0xcc,sizeof(output));
    const unsigned char format[]={'A','B',0};
    std::uint32_t raw[1]={0};
    FormatterOriginalDescriptor32 d;
    d.cursor=output; d.remaining=1; d.base=output; d.flags=2;
    const std::uint32_t file=5,opaque14=0x14151617,buffer=8,opaque1c=0x1c1d1e1f;
    std::memcpy(d.opaque_tail,&file,4); std::memcpy(d.opaque_tail+4,&opaque14,4);
    std::memcpy(d.opaque_tail+8,&buffer,4); std::memcpy(d.opaque_tail+12,&opaque1c,4);
    const auto result=formatter_parser_005a4371(&d,format,raw);
    std::printf("{\"case\":\"parser_cleanup_connected\",\"result\":%d,\"remaining\":%d,\"flags\":%u,\"cursor_offset\":%d,\"base_offset\":%d,\"output\":\"",
        result,d.remaining,d.flags,static_cast<int>(d.cursor-output),static_cast<int>(d.base-output));
    print_hex(reinterpret_cast<const std::uint8_t*>(output),4);
    std::printf("\",\"tail\":\""); print_hex(d.opaque_tail,16);
    std::printf("\",\"write_calls\":%u,\"write_file\":%u,\"write_length\":%u,\"write_bytes\":\"",
        trace.writes,trace.write_file,trace.write_len); print_hex(trace.write_data,trace.write_len);
    std::printf("\",\"prepare_calls\":%u,\"prepare_file\":%u,\"prepare_flags\":%u,\"aux_calls\":%u,\"events\":",
        trace.prepares,trace.prepare_file,trace.prepare_flags,trace.aux); print_events(); std::printf("}\n");
}
} // namespace

int main() { for(const auto& in:inputs) run_entry_case(in); run_cleanup_bridge(); run_parser_cleanup_bridge(); }
