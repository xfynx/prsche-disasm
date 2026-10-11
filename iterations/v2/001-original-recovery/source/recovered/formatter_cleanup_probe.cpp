#include "porsche/formatter_cleanup.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace porsche {
FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5508=nullptr;
FormatterOriginalDescriptor32* formatter_cleanup_stream_005e5528=nullptr;
static std::uint8_t invalid_record[36];
static std::uint8_t handle_bank[32*36];
const std::uint8_t* formatter_cleanup_invalid_handle_record_005e5f50=invalid_record;
const std::uint8_t* formatter_cleanup_preceding_handle_bank_006c01dc=nullptr;
const std::uint8_t* formatter_cleanup_handle_table_006c01e0[2]={handle_bank,nullptr};
std::uint32_t formatter_cleanup_handle_limit_006c02e0=32;
static FormatterOriginalDescriptor32* active_descriptor=nullptr;
static char* active_output=nullptr;
static const char* active_case=nullptr;

struct Trace {
    std::uint32_t write_calls=0, write_file=0, write_length=0;
    std::uint32_t aux_calls=0, aux_file=0, aux_offset=0, aux_origin=0;
    std::uint32_t prepare_calls=0;
    std::uint32_t prepare_file=0, prepare_flags=0;
    std::uint32_t event_count=0;
    std::uint32_t events[8]{};
    char write_bytes[64]{};
    std::int32_t write_return=1, aux_return=0, prepare_return=0;
} trace;

std::int32_t __cdecl formatter_cleanup_file_write_005a9e49(
    std::uint32_t file_id,const void* bytes,std::int32_t length) {
    ++trace.write_calls;trace.write_file=file_id;
    trace.events[trace.event_count++]=2;
    trace.write_length=static_cast<std::uint32_t>(length);
    if(length>0&&length<=static_cast<int>(sizeof(trace.write_bytes)))
        std::memcpy(trace.write_bytes,bytes,static_cast<std::size_t>(length));
    if(std::strcmp(active_case,"prepare_mutates_to_buffer") == 0)
        active_descriptor->base=active_output+12;
    return trace.write_return;
}
std::int32_t __cdecl formatter_cleanup_file_aux_005a9ab8(
    std::uint32_t file_id,std::uint32_t offset,std::uint32_t origin) {
    ++trace.aux_calls;trace.aux_file=file_id;trace.aux_offset=offset;trace.aux_origin=origin;
    trace.events[trace.event_count++]=3;
    if(std::strcmp(active_case,"prepare_aux_mutates_base") == 0)
        active_descriptor->base=active_output+13;
    return trace.aux_return;
}
std::int32_t __cdecl formatter_cleanup_prepare_descriptor_005abef1(
    FormatterOriginalDescriptor32* descriptor) {
    ++trace.prepare_calls;trace.prepare_flags=descriptor->flags;
    trace.events[trace.event_count++]=1;
    trace.prepare_file=0;
    std::memcpy(&trace.prepare_file,descriptor->opaque_tail,sizeof(trace.prepare_file));
    if(std::strcmp(active_case,"prepare_mutates_to_buffer") == 0) {
        descriptor->flags=8; descriptor->base=active_output+4; descriptor->cursor=active_output+5;
        const std::uint32_t size=5; std::memcpy(descriptor->opaque_tail+8,&size,4);
    } else if(std::strcmp(active_case,"prepare_aux_mutates_base") == 0) {
        descriptor->flags=8; descriptor->base=active_output+5; descriptor->cursor=active_output+5;
        const std::uint32_t size=10; std::memcpy(descriptor->opaque_tail+8,&size,4);
    }
    return trace.prepare_return;
}

} // namespace porsche

namespace {
struct TestCase {
    const char* name;
    std::uint32_t flags,file_id,character,handle_limit,handle_flags,invalid_flags;
    std::int32_t remaining,cursor_offset,buffer_size,write_return;
    bool special_a,special_b,through_emitter;
};
const TestCase cases[]={
    {"early_zero_flags",0,7,0x141,32,0,0,9,2,8,1,false,false,false},
    {"early_42_wrapper",0x42,0xffffffffu,'Q',32,0,0,100,1,9,1,false,false,false},
    {"flag1_without10",1,2,'!',32,0,0,12,3,6,1,false,false,false},
    {"flag1_with10_reset",0x11,3,'R',32,0,0,8,3,7,1,false,false,false},
    {"ordinary_direct_success",2,4,0x1a3,32,0,0,7,1,6,1,false,false,false},
    {"ordinary_direct_short",2,5,'S',32,0,0,7,0,6,0,false,false,false},
    {"ordinary_direct_negative",0x80,6,'T',32,0,0,7,0,6,-1,false,false,false},
    {"special_a_character_handle",2,3,'A',32,0x40,0,5,0,6,1,true,false,false},
    {"special_b_noncharacter_handle",2,4,'B',32,0,0,5,0,6,1,false,true,false},
    {"special_out_of_range",2,32,'C',32,0x40,0,5,0,6,1,true,false,false},
    {"flag4_prepare_boundary",4,2,'D',32,0,0,5,0,6,1,false,false,false},
    {"buffer_write_success",8,7,'N',32,0,0,11,3,16,3,false,false,false},
    {"buffer_write_short",8,8,'O',32,0,0,11,3,16,2,false,false,false},
    {"buffer_write_failure",0x108,9,'P',32,0,0,11,2,16,-1,false,false,false},
    {"buffer_empty_aux",8,0xffffffffu,'E',32,0,0x20,11,0,16,0,false,false,false},
    {"buffer_empty_no_aux",8,0xffffffffu,'F',32,0,0,11,0,16,0,false,false,false},
    {"buffer_empty_nonnegative_id",8,2,'G',32,0x20,0,11,0,16,0,false,false,false},
    {"buffer_empty_signed_bank_negative",8,0xfffffffeu,'M',32,0x20,0,11,0,16,0,false,false,false},
    {"buffer_size_zero_wrap",8,10,'H',32,0,0,11,0,0,0,false,false,false},
    {"early40_flag",0x40,11,'I',32,0,0,11,1,16,1,false,false,false},
    {"emitter_cleanup_bridge",0x42,12,'J',32,0,0,0,0,16,1,false,false,true},
    {"prepare_mutates_to_buffer",2,4,'L',32,0,0,5,0,8,1,false,false,false},
    {"prepare_aux_mutates_base",2,4,'M',32,0x20,0,5,0,8,0,false,false,false},
};

void reset_storage(const TestCase& c) {
    using namespace porsche;
    std::memset(invalid_record,0,sizeof(invalid_record));
    std::memset(handle_bank,0,sizeof(handle_bank));
    invalid_record[4]=static_cast<std::uint8_t>(c.invalid_flags);
    if(c.file_id<32)handle_bank[(c.file_id&31u)*36u+4u]=static_cast<std::uint8_t>(c.handle_flags);
    formatter_cleanup_handle_limit_006c02e0=c.handle_limit;
    formatter_cleanup_preceding_handle_bank_006c01dc=handle_bank;
    if(c.file_id==0xfffffffeu)handle_bank[30u*36u+4u]=static_cast<std::uint8_t>(c.handle_flags);
    formatter_cleanup_stream_005e5508=nullptr;formatter_cleanup_stream_005e5528=nullptr;
    trace=Trace{};trace.write_return=c.write_return;
}

void print_hex(const std::uint8_t* bytes,std::size_t n) {
    for(std::size_t i=0;i<n;++i)std::printf("%02x",bytes[i]);
}

void run(const TestCase& c) {
    using namespace porsche;
    reset_storage(c);
    std::uint8_t output[64];
    for(unsigned i=0;i<sizeof(output);++i)output[i]=static_cast<std::uint8_t>(0x40u+i);
    FormatterOriginalDescriptor32 d{};
    d.cursor=reinterpret_cast<char*>(output+c.cursor_offset);
    d.remaining=c.remaining;d.base=reinterpret_cast<char*>(output);d.flags=c.flags;
    std::memcpy(d.opaque_tail,&c.file_id,4);
    const std::uint32_t opaque14=0x14151617u,buffer_size=static_cast<std::uint32_t>(c.buffer_size),opaque1c=0x1c1d1e1fu;
    std::memcpy(d.opaque_tail+4,&opaque14,4);
    std::memcpy(d.opaque_tail+8,&buffer_size,4);
    std::memcpy(d.opaque_tail+12,&opaque1c,4);
    active_descriptor=&d; active_output=reinterpret_cast<char*>(output); active_case=c.name;
    if(c.special_a)formatter_cleanup_stream_005e5508=&d;
    if(c.special_b)formatter_cleanup_stream_005e5528=&d;
    std::int32_t count=0;
    std::int32_t result;
    if(c.through_emitter) {
        formatter_original_emit_005a4ab2(static_cast<std::int32_t>(c.character),&d,&count);
        result=count;
    } else result=formatter_cleanup_005a4259(c.character,&d);
    std::printf("{\"case\":\"%s\",\"result\":%d,\"count\":%d,\"cursor_offset\":%d,\"base_offset\":%d,\"remaining\":%d,\"flags\":%u,\"descriptor_tail\":\"",
        c.name,result,count,static_cast<int>(d.cursor-reinterpret_cast<char*>(output)),
        static_cast<int>(d.base-reinterpret_cast<char*>(output)),d.remaining,d.flags);
    print_hex(d.opaque_tail,sizeof(d.opaque_tail));
    std::printf("\",\"output\":\"");print_hex(output,16);
    std::printf("\",\"write_calls\":%u,\"write_file\":%u,\"write_length\":%u,\"write_bytes\":\"",
        trace.write_calls,trace.write_file,trace.write_length);print_hex(reinterpret_cast<const std::uint8_t*>(trace.write_bytes),trace.write_length>64?64:trace.write_length);
    std::printf("\",\"aux_calls\":%u,\"aux_file\":%u,\"aux_offset\":%u,\"aux_origin\":%u,\"prepare_calls\":%u,\"prepare_file\":%u,\"prepare_flags\":%u,\"events\":[",
        trace.aux_calls,trace.aux_file,trace.aux_offset,trace.aux_origin,trace.prepare_calls,trace.prepare_file,trace.prepare_flags);
    for(std::uint32_t i=0;i<trace.event_count;++i)std::printf("%s%u",i?",":"",trace.events[i]);
    std::printf("]}\n");
}
} // namespace

int main() { for(const auto& c:cases)run(c); }
