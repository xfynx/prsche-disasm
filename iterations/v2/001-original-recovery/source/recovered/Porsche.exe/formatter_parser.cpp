#include "porsche/formatter_parser.hpp"

#include <cstdint>
#include <cstring>

namespace porsche {

namespace {
// Raw-backed initial table at Porsche.exe:005e52d0; bytes are source-hash pinned.
constexpr std::uint8_t kInitialCtypeTable[512] = {
    0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,
    0x20,0x00,0x28,0x00,0x28,0x00,0x28,0x00,0x28,0x00,0x28,0x00,0x20,0x00,0x20,0x00,
    0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,
    0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,
    0x48,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
    0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
    0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,
    0x84,0x00,0x84,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
    0x10,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x01,0x00,
    0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
    0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
    0x01,0x00,0x01,0x00,0x01,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
    0x10,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x02,0x00,
    0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
    0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,
    0x02,0x00,0x02,0x00,0x02,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x20,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
// Bytes are mapped from the original raw-backed .rdata table at 005c19c8.
// The parser uses the first 0x59 bytes both as classes for ASCII 0x20..0x78
// and all 128 bytes as signed state transitions.
constexpr std::uint8_t kTable[128] = {
    0x06,0x00,0x00,0x06,0x00,0x01,0x00,0x00, 0x10,0x00,0x03,0x06,0x00,0x06,0x02,0x10,
    0x04,0x45,0x45,0x45,0x05,0x05,0x05,0x05, 0x05,0x35,0x30,0x00,0x50,0x00,0x00,0x00,
    0x00,0x20,0x28,0x38,0x50,0x58,0x07,0x08, 0x00,0x37,0x30,0x30,0x57,0x50,0x07,0x00,
    0x00,0x20,0x20,0x08,0x00,0x00,0x00,0x00, 0x08,0x60,0x68,0x60,0x60,0x60,0x60,0x00,
    0x00,0x70,0x70,0x78,0x78,0x78,0x78,0x08, 0x07,0x08,0x00,0x00,0x07,0x00,0x08,0x08,
    0x08,0x00,0x00,0x08,0x00,0x08,0x00,0x07, 0x08,0x00,0x00,0x00,0x28,0x00,0x6e,0x00,
    0x75,0x00,0x6c,0x00,0x6c,0x00,0x29,0x00, 0x00,0x00,0x00,0x00,0x28,0x6e,0x75,0x6c,
    0x6c,0x29,0x00,0x00,0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f
};
constexpr std::uint32_t F_LEFT=4, F_ZERO=8, F_SIGNED=0x40, F_ALT=0x80,
    F_NEG=0x100, F_OCTAL_ALT=0x200, F_WIDE=0x800, F_I64=0x8000;

void emit(FormatterOriginalDescriptor32* d, std::int32_t* count, int ch) {
    formatter_original_emit_005a4ab2(ch, d, count);
}
void repeat(FormatterOriginalDescriptor32* d, std::int32_t* count, int ch, int n) {
    formatter_original_repeat_005a4ae7(ch, n, d, count);
}
void span(FormatterOriginalDescriptor32* d, std::int32_t* count,
          const void* p, int n) {
    formatter_original_span_005a4b18(static_cast<const std::uint8_t*>(p), n, d, count);
}
int class_of(std::uint8_t c) {
    const auto sc = static_cast<std::int8_t>(c);
    if (sc < 0x20 || sc > 0x78) return 0;
    return kTable[static_cast<unsigned>(c - 0x20)] & 0x0f;
}
std::int32_t wrap_sub(std::int32_t a, std::int32_t b) {
    const std::uint32_t bits=static_cast<std::uint32_t>(a)-static_cast<std::uint32_t>(b);
    std::int32_t result; std::memcpy(&result,&bits,sizeof(result)); return result;
}
std::int32_t wrap_decimal(std::int32_t value, std::int32_t digit) {
    const std::uint32_t bits=static_cast<std::uint32_t>(value)*10u+static_cast<std::uint32_t>(digit);
    std::int32_t result; std::memcpy(&result,&bits,sizeof(result)); return result;
}
}

int __cdecl formatter_parser_005a4371(FormatterOriginalDescriptor32* d,
                                      const unsigned char* fmt,
                                      std::uint32_t* raw_va) {
    int state=0, count=0;
    std::uint32_t* va=raw_va;
    std::uint8_t c=*fmt;
    const unsigned char* p=fmt;
    char scratch[512];
    char sign_prefix[4];
    int data_length=0, prefix_length=0, width=0, precision=0, float_mode=0, wide_output=0,
        suppress_output=0;
    std::uint32_t flags=0;
    while (true) {
        if (c==0 || count<0) return count;
        ++p;
        state = static_cast<std::int8_t>(kTable[static_cast<unsigned>(class_of(c))*8u + static_cast<unsigned>(state)]) >> 4;
        switch (state) {
        case 0:
            wide_output=0;
            if ((formatter_ctype_table_005e52d0[static_cast<unsigned>(c)*2u+1u] & 0x80u) != 0) {
                emit(d,&count,static_cast<std::int8_t>(c));
                c=*p++;
            }
            emit(d,&count,static_cast<std::int8_t>(c));
            break;
        case 1:
            precision=-1; flags=0; width=0; data_length=0; prefix_length=0; float_mode=0;
            wide_output=0; suppress_output=0;
            break;
        case 2:
            if(c==' ') flags|=2; else if(c=='#') flags|=F_ALT; else if(c=='+') flags|=1;
            else if(c=='-') flags|=F_LEFT; else if(c=='0') flags|=F_ZERO;
            break;
        case 3:
            if(c=='*') { width=static_cast<std::int32_t>(formatter_original_next_u32_005a4b50(&va)); if(width<0){flags|=F_LEFT;width=wrap_sub(0,width);} }
            else width=wrap_decimal(width,static_cast<std::int8_t>(c)-'0');
            break;
        case 4: precision=0; break;
        case 5:
            if(c=='*') { precision=static_cast<std::int32_t>(formatter_original_next_u32_005a4b50(&va)); if(precision<0) precision=-1; }
            else precision=wrap_decimal(precision,static_cast<std::int8_t>(c)-'0');
            break;
        case 6:
            if(c=='I') { if(p[0]!='6'||p[1]!='4') { state=0; emit(d,&count,static_cast<std::int8_t>(c)); } else { p+=2; flags|=F_I64; } }
            else if(c=='h') flags|=0x20; else if(c=='l') flags|=0x10; else if(c=='w') flags|=F_WIDE;
            break;
        case 7: {
            const char* data=scratch;
            char conv=static_cast<char>(c);
            int conversion=0, base=0;
            bool nonzero_integer_prefix=false;
            std::uint64_t value=0;
            if(conv=='X') { conversion=16; }
            else if(conv=='C' || conv=='c') {
                if(conv=='C' && !(flags&0x830)) flags|=F_WIDE;
                if(!(flags&0x810)) { scratch[0]=static_cast<char>(formatter_original_next_u32_005a4b50(&va)); data_length=1; }
                else { int r=formatter_wide_encode_boundary_005abf5e(scratch,formatter_original_next_u16_005a4b6d(&va)); data_length=r; if(r<0) suppress_output=1; }
                goto output;
            }
            if(conv=='E'||conv=='G') { flags|=0x40; float_mode=1; conv=static_cast<char>(conv+0x20); }
            if(conv=='e'||conv=='f'||conv=='g') {
                flags|=0x40;
                if(precision<0) precision=6; else if(precision==0&&conv=='g') precision=1;
                std::uint32_t words[2]={va[0],va[1]}; va+=2;
                formatter_float_boundary_005e5788(words,scratch,conv,precision,float_mode);
                if((flags&F_ALT)&&precision==0) formatter_float_post_005e5794(scratch);
                if(conv=='g'&&!(flags&F_ALT)) formatter_float_post_005e578c(scratch);
                if(scratch[0]=='-'){flags|=F_NEG;data=scratch+1;} data_length=formatter_length_boundary_005a6730(data); goto output;
            }
            if(conv=='S'&&!(flags&0x830)) flags|=F_WIDE;
            if(conv=='Z') {
                const auto* counted=reinterpret_cast<const std::uint16_t*>(formatter_original_next_u32_005a4b50(&va));
                if(!counted || !*reinterpret_cast<const std::uint32_t*>(counted+2)) { data=formatter_null_narrow_005e57a0; data_length=formatter_length_boundary_005a6730(data); }
                else {
                    data=reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(counted+2));
                    const auto signed_length=static_cast<std::int32_t>(static_cast<std::int16_t>(*counted));
                    data_length=(flags&F_WIDE)?static_cast<std::int32_t>(static_cast<std::uint32_t>(signed_length)>>1):signed_length;
                    wide_output=(flags&F_WIDE)!=0;
                }
                goto output;
            }
            if(conv=='s'||conv=='S') {
                int limit=precision<0?0x7fffffff:precision;
                auto* ptr=reinterpret_cast<const unsigned char*>(formatter_original_next_u32_005a4b50(&va));
                if(flags&0x810) {
                    auto* ws=reinterpret_cast<const std::uint16_t*>(ptr);
                    if(!ws) ws=formatter_null_wide_005e57a4;
                    int n=0; while(n<limit&&ws[n]) ++n; data=reinterpret_cast<const char*>(ws);data_length=n;wide_output=1;
                } else {
                    if(!ptr) ptr=reinterpret_cast<const unsigned char*>(formatter_null_narrow_005e57a0);
                    int n=0;while(n<limit&&ptr[n])++n;data=reinterpret_cast<const char*>(ptr);data_length=n;
                }
                goto output;
            }
            if(conv=='n') { auto* out=reinterpret_cast<std::uint32_t*>(formatter_original_next_u32_005a4b50(&va)); if(flags&0x20)*reinterpret_cast<std::uint16_t*>(out)=static_cast<std::uint16_t>(count);else *out=static_cast<std::uint32_t>(count);suppress_output=1;break; }
            if(conv=='o') { conversion=8; if(flags&F_ALT)flags|=F_OCTAL_ALT; }
            else if(conv=='d'||conv=='i') { flags|=F_SIGNED; conversion=10; }
            else if(conv=='u') conversion=10;
            else if(conv=='p') { precision=8;conversion=16; }
            else if(conv=='x') conversion=16;
            else if(conv!='X') { data_length=0; goto output; }
            if(conv=='x') conversion=16;
            base=conversion;
            if(flags&F_I64) value=formatter_original_next_u64_005a4b5d(&va);
            else {
                std::uint32_t raw=formatter_original_next_u32_005a4b50(&va);
                if(flags&0x20) value=(flags&F_SIGNED)?static_cast<std::uint64_t>(static_cast<std::int16_t>(raw)):static_cast<std::uint16_t>(raw);
                else value=(flags&F_SIGNED)?static_cast<std::uint64_t>(static_cast<std::int32_t>(raw)):raw;
            }
            if((flags&F_SIGNED)&&(value&0x8000000000000000ull)!=0){value=0-value;flags|=F_NEG;}
            // 005a48f5..005a48fb clears an alternate hexadecimal prefix for zero.
            nonzero_integer_prefix=value!=0;
            if(precision<0) precision=1; else flags&=~F_ZERO;
            if(value==0&&precision<=0) data_length=0;
            else {
                char* end=scratch+511; char* q=end;
                do {
                    const auto rem=formatter_unsigned_remainder_boundary_005a6820(value,static_cast<std::uint32_t>(base));
                    value=formatter_unsigned_divide_boundary_005a67b0(value,static_cast<std::uint32_t>(base));
                    const auto digit=static_cast<unsigned>(rem);
                    *--q=static_cast<char>(digit<10?'0'+digit:'0'+digit+(conv=='x'?39:7)); --precision;
                } while(precision>0||value!=0);
                data=q; data_length=static_cast<int>(end-q);
            }
            if((flags&F_OCTAL_ALT)&&(data_length==0||*data!='0')) {
                if(data_length==0) { scratch[510]='0';data=scratch+510;data_length=1; }
                else { --data;*const_cast<char*>(data)='0';++data_length; }
            }
            if(data_length==0) data=scratch;
            goto output;
output:
            if(suppress_output) { suppress_output=0; break; }
            // Original 005a4985..005a4a79 shares prefix and padding for
            // narrow and wide output; only the payload emitter differs.
            if((flags&F_SIGNED)&&!(flags&F_NEG)) { if(flags&1)sign_prefix[prefix_length++]='+';else if(flags&2)sign_prefix[prefix_length++]=' '; }
            else if(flags&F_NEG)sign_prefix[prefix_length++]='-';
            if(conversion==16&&(flags&F_ALT)&&nonzero_integer_prefix){sign_prefix[prefix_length++]='0';sign_prefix[prefix_length++]=(conv=='x'?'x':'X');}
            const int pad=wrap_sub(wrap_sub(width,prefix_length),data_length);
            if((flags&0xc)==0)repeat(d,&count,' ',pad);
            span(d,&count,sign_prefix,prefix_length);
            if((flags&F_ZERO)&&!(flags&F_LEFT))repeat(d,&count,'0',pad);
            if(wide_output && data_length>0) {
                const auto* ws=reinterpret_cast<const std::uint16_t*>(data);
                for(int n=0;n<data_length;++n){char encoded[4];int bytes=formatter_wide_encode_boundary_005abf5e(encoded,ws[n]);if(bytes<1)break;span(d,&count,encoded,bytes);}
            } else {
                span(d,&count,data,data_length);
            }
            if(flags&F_LEFT)repeat(d,&count,' ',pad);
            break;
        }
        default: break;
        }
        if(count<0) return count;
        c=*p;
        continue;
    }
}

const std::uint8_t* formatter_ctype_table_005e52d0 = kInitialCtypeTable;
} // namespace porsche
