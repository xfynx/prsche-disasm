#include "porsche/fe_stream.hpp"
#include <cstring>
#include <algorithm>

// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Function identities and data tables are retained. Unknown callees remain extern.
namespace porsche {
#include "fe_tables.inc"
std::uint32_t fe_enabled_0065b298;
std::uint32_t fe_action_state_005e9130[0x21e];

static bool space(char c) { return c==' ' || c=='\t' || c=='\r'; }
static std::int16_t limit(char* p, char* base, std::int32_t size, std::int32_t cap) {
    return static_cast<std::int16_t>(std::min(cap, static_cast<std::int32_t>(base+size-p)));
}
static char stripped(char*& p, char delimiter, std::int16_t cap, char* out) {
    std::int16_t count=0;
    while (*p!=delimiter && *p!='\0' && count<cap) {
        if (!space(*p)) { *out++=*p; ++count; }
        ++p;
    }
    const char stop=*p++;
    *out='\0';
    return stop;
}
std::uint32_t __cdecl fe_read_token_004b51e0(char** cursor, char delimiter,
                                         std::int16_t cap, char* out) {
    char* p=*cursor;
    std::int16_t count=0;
    while (*p!=delimiter && *p!='\0' && count<cap) {
        if (!space(*p)) { *out++=*p; ++count; }
        ++p;
    }
    *cursor=p+1;
    *out='\0';
    return (static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p+1)) & 0xffff0000u)
         | static_cast<std::uint16_t>(count);
}
std::uint32_t __cdecl fe_value_004b5250(const char* p) {
    std::uint32_t value=0, packed=0, radix=10, sign=1;
    std::int32_t components=0;
    while (*p) {
        const auto c=static_cast<signed char>(*p);
        switch (c) {
        case ',':
            packed=components<2 ? ((value<<12)|packed)<<4 : packed|(value<<8);
            radix=10; ++components;
            [[fallthrough]];
        case ' ': value=0; sign=1; break;
        case '-': sign=0xffffffffu; break;
        case 'X': case 'x': if (!value) radix=16; break;
        default:
            if (c>='0' && c<='9') value=radix*value+static_cast<std::uint32_t>(c-'0')*sign;
            else if (radix==16 && c>='A' && c<='F') value=16*value+static_cast<std::uint32_t>(c-'A'+10)*sign;
            else if (radix==16 && c>='a' && c<='f') value=16*value+static_cast<std::uint32_t>(c-'a'+10)*sign;
            else if (!value && ((c>='A' && c<='Z') || (c>='a' && c<='z'))) {
                FeValue* v=fe_values_005d63a0;
                while (v->name && compare_005ae3c0(p,v->name)!=0) ++v;
                value=v->value;
                p+=std::strlen(p)-1;
            }
        }
        ++p;
    }
    return value+packed;
}
std::int32_t __cdecl fe_action_004b5430(const char* name) {
    for (std::int32_t i=0;fe_actions_005cc5c8[i].name;++i)
        if (!compare_005ae3c0(name,fe_actions_005cc5c8[i].name)) return i;
    return 0;
}
static FeDefinition* definition(const char* name) {
    auto* d=fe_definitions_005d1e40;
    while (d->name && compare_005ae3c0(name,d->name)!=0) ++d;
    return d;
}
static void append_string(std::uint32_t*& out, const char* text) {
    auto* p=reinterpret_cast<char*>(out);
    do { *p++=*text; if (p>reinterpret_cast<char*>(out)) ++out; } while (*text++);
}
static void short_string(std::uint32_t*& out, char* value) {
    char token[128]; char* p=value;
    stripped(p,'\n',static_cast<std::int16_t>(std::min<std::size_t>(15,std::strlen(value))),token);
    append_string(out,token);
}
static void number_list(std::uint32_t*& out, char* value, std::uint32_t* count) {
    char* p=value;
    while (*p) {
        char token[64];
        const auto cap=static_cast<std::int16_t>(std::min<std::size_t>(63,std::strlen(value)));
        const auto stop=stripped(p,',',cap,token);
        if (*token) { *out++=fe_value_004b5250(token); ++*count; }
        if (!stop) break;
    }
}
void __cdecl fe_assignment_004b5470(char** cursor, char* base, std::int32_t size,
                                  std::uint32_t** output) {
    char text[1024], scratch[128];
    char*& p=*cursor; std::uint32_t*& out=*output;
    auto cap=static_cast<std::int16_t>(std::min<std::int32_t>(63,static_cast<std::int32_t>(p-base)-1));
    p-=2;
    std::int16_t n=0;
    while (*p!='\n' && *p && n<cap) { --p; ++n; }
    ++p; char* dst=text;
    while (n--) { if (!space(*p)) *dst++=*p; ++p; }
    *dst='\0'; ++p;
    auto* d=definition(text);
    if (!d->name) { stripped(p,'\n',limit(p,base,size,63),text); return; }
    auto op=d->opcode;
    if (op==7) { stripped(p,'\n',limit(p,base,size,63),text); fe_enabled_0065b298=fe_value_004b5250(text); return; }
    if (op==0x21e) {
        stripped(p,']',limit(p,base,size,63),text);
        char* last=text;
        const auto range_length=static_cast<std::int32_t>(std::strlen(text));
        for (std::int32_t i=0;i<range_length-1;++i) {
            if (text[i]=='t' || text[i]=='T') { text[i]='\0'; last=text+i+2; }
        }
        const auto first=static_cast<std::int32_t>(fe_value_004b5250(text));
        const auto final=last==text ? first : static_cast<std::int32_t>(fe_value_004b5250(last));
        stripped(p,'=',limit(p,base,size,63),text);
        d=definition(text); op=d->opcode;
        stripped(p,'\n',limit(p,base,size,1023),text);
        auto value=fe_value_004b5250(text);
        if (op==0x21f) {
            for (std::int32_t i=0;compare_005ae3c0(fe_car_names_005d61e8[i],"BAD!");++i)
                if (!compare_005ae3c0(fe_car_names_005d61e8[i],text)) value=static_cast<std::uint32_t>(i);
        }
        if (d->name) for (std::int32_t index=first;index<=final && index<9;++index) {
            if (index<0) continue;
            *out++=static_cast<std::uint32_t>(op); *out++=static_cast<std::uint32_t>(index);
            if (op>=0x21e) *out++=value;
            else if (op>=0x147) { auto* count=out++; *count=0; number_list(out,text,count); }
            else if (op>0x139) short_string(out,text);
        }
        return;
    }
    if (op>0x14d) {
        *out++=static_cast<std::uint32_t>(op);
        stripped(p,',',63,scratch);
        const auto action=static_cast<std::uint32_t>(fe_action_004b5430(scratch));
        fe_read_token_004b51e0(&p,'\n',limit(p,base,size,63),scratch);
        *out++=action|(fe_value_004b5250(scratch)<<8); return;
    }
    if (op>=0x142) {
        *out++=static_cast<std::uint32_t>(op); auto* count=out++; *count=0;
        stripped(p,'\n',limit(p,base,size,1023),text); number_list(out,text,count); return;
    }
    if (op>0x10d) {
        *out++=static_cast<std::uint32_t>(op);
        stripped(p,'\n',limit(p,base,size,63),text); short_string(out,text); return;
    }
    if (op>1) {
        *out++=static_cast<std::uint32_t>(op);
        stripped(p,'\n',limit(p,base,size,63),text); *out++=fe_value_004b5250(text); return;
    }
    if (op==1) { stripped(p,'\n',limit(p,base,size,15),scratch); fe_file_004b5ee0(scratch,output); }
}
void __cdecl fe_file_004b5ee0(const char* name, std::uint32_t** output) {
    void* handle=nullptr; open_0059e040(name,1,100,&handle);
    if (!handle) return;
    const auto size=size_00533de0(handle,100);
    if (!size) return; // Original leaves the zero-length handle open.
    auto* data=static_cast<char*>(allocate_00531ca0(name,size,0));
    if (data) read_00533bf0(handle,0,data,static_cast<std::uint32_t>(size),100);
    close_00533da0(handle,100);
    if (!data) return;
    char* p=data;
    while (p<data+size) {
        const char c=*p++;
        if (c=='#') {
            while (*p!='\n' && *p && p<data+size) ++*p;
            ++*p; // Deliberately preserves the original byte mutation.
        } else if (c=='=' || c=='[') fe_assignment_004b5470(&p,data,size,output);
        else if (c=='@') {
            char file[64]; stripped(p,'\n',limit(p,data,size,48),file);
            std::strcat(file,".txt"); fe_file_004b5ee0(file,output);
        }
    }
    free_00531f90(data);
}
void __cdecl fe_arguments_004b60d0(std::int32_t argc, char** argv, std::uint32_t** output) {
    if (!argc) return;
    do {
        char* base=*argv++; const auto size=static_cast<std::int32_t>(std::strlen(base)); char* p=base;
        while (*p && p-base<size) {
            const char c=*p++;
            if (c=='=' || c=='[') fe_assignment_004b5470(&p,base,size,output);
            else if (c=='@') { char file[64]; stripped(p,'\n',limit(p,base,size,48),file); std::strcat(file,".txt"); fe_file_004b5ee0(file,output); }
        }
    } while (--argc);
}
std::uint32_t* __cdecl fe_build_004b6660(std::int32_t argc, char** argv) {
    auto* start=static_cast<std::uint32_t*>(allocate_00531ca0("FE Data Stream",0x8000,0x10));
    auto* out=start; fe_file_004b5ee0("fe.txt",&out); fe_arguments_004b60d0(argc,argv,&out);
    *out++=0; resize_00569640(start,static_cast<std::int32_t>(reinterpret_cast<char*>(out)-reinterpret_cast<char*>(start)));
    return start;
}
void __cdecl fe_apply_004b4b80(const std::uint32_t* record) {
    auto op=static_cast<std::int32_t>(*record);
    if (op>=0x14e && op<0x21e) {
        fe_action_state_005e9130[op]=record[1];
        if (auto callback=fe_actions_005cc5c8[record[1]&255].apply) callback(static_cast<std::int32_t>(record[1])>>8);
        return;
    }
    std::uint32_t* target=nullptr;
    for (auto* d=fe_definitions_005d1e40;d->opcode;++d) if (d->opcode==op) target=d->target;
    if (!target) return;
    if (op>=0x21e) { target[static_cast<std::int32_t>(record[1])*0x160]=record[2]; return; }
    if (op<0x142) {
        if (op<=0x10d) *target=record[1];
        else { if (op>0x139) { target+=static_cast<std::int32_t>(record[1])*0x160; ++record; }
               std::strcpy(reinterpret_cast<char*>(target),reinterpret_cast<const char*>(record+1)); }
    } else {
        if (op>0x146) { target+=static_cast<std::int32_t>(record[1])*0x160; ++record; }
        for (std::int32_t i=0;i<static_cast<std::int32_t>(record[1]);++i) target[i]=record[i+2];
    }
}
std::int32_t __cdecl fe_record_words_004b4cd0(const std::uint32_t* record) {
    const auto op=static_cast<std::int32_t>(*record);
    if (op>=0x21e) return 3;
    if (op>=0x14e) return 2;
    if (op>=0x142) { const auto offset=op>0x146 ? 1 : 0; return offset+2+static_cast<std::int32_t>(record[offset+1]); }
    if (op>0x10d) { const auto offset=op>0x139 ? 1 : 0; const auto length=std::strlen(reinterpret_cast<const char*>(record+offset+1))+1; return offset+2+static_cast<std::int32_t>((length-1)/4); }
    return 2;
}
}
