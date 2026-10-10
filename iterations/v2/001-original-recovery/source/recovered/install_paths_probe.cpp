#include "porsche/install_paths.hpp"
#include "porsche/game_setup.hpp"
#include "porsche/fe_stream.hpp"
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>

namespace {
constexpr std::uintptr_t arena_address=0x03600000;
constexpr std::size_t arena_bytes=0x10000;
constexpr std::size_t blob_offset=0x1000;
std::uint8_t* arena=nullptr;
std::uint8_t* blob=nullptr;
std::string opened_path;
std::uint32_t open_zero=0,free_count=0,free_pointer=0;
std::uint32_t address(const void* p){return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));}
std::string encode(const std::uint8_t* p,std::size_t n){static constexpr char d[]="0123456789abcdef";std::string s(n*2,'0');for(std::size_t i=0;i<n;++i){s[i*2]=d[p[i]>>4];s[i*2+1]=d[p[i]&15];}return s;}
}

namespace porsche {
void* __cdecl game_setup_resource_file_open_0059d8e0(const char* path,std::uint32_t zero){opened_path=path?path:"<null>";open_zero=zero;return blob;}
std::uint32_t __cdecl free_00531f90(void* resource){++free_count;free_pointer=address(resource);return 1;}
}

int main(){
    arena=static_cast<std::uint8_t*>(VirtualAlloc(reinterpret_cast<void*>(arena_address),arena_bytes,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    if(!arena)return 3;
    blob=arena+blob_offset;
    std::string operation;
    while(std::cin>>operation){
        if(operation=="LOAD"||operation=="SIZE"){
            std::uint32_t length;std::string hex;
            if(!(std::cin>>length>>hex)||length>0x3000||hex.size()!=length*2u)return 4;
            // Unicorn's fresh mapped pages are zero-filled; keep bytes beyond
            // the returned fixture length consistent for the ignored EAX tail.
            std::memset(arena,0,arena_bytes);
            std::memcpy(blob-12,&length,4);
            for(std::uint32_t i=0;i<length;++i){
                auto digit=[](char c)->std::uint8_t{return static_cast<std::uint8_t>(c<='9'?c-'0':(c|32)-'a'+10);};
                blob[i]=static_cast<std::uint8_t>((digit(hex[2u*i])<<4)|digit(hex[2u*i+1u]));
            }
            if(operation=="SIZE"){
                const auto result=porsche::install_paths_size_00556640(blob);
                std::cout<<"{\"op\":\"SIZE\",\"result\":"<<result<<"}\n";
                continue;
            }
            opened_path.clear();open_zero=0xffffffffu;
            for(std::uint32_t i=0;i<60u;++i)porsche::install_paths_table_0065b2a0[i]=reinterpret_cast<char*>(static_cast<std::uintptr_t>(0x1000u+i));
            const auto result=porsche::install_paths_load_004b6ff0();
            std::cout<<"{\"op\":\"LOAD\",\"result\":"<<result<<",\"blob_offset\":"<<(address(porsche::install_paths_blob_0065b29c)-address(arena))
              <<",\"open_path\":\""<<opened_path<<"\",\"open_zero\":"<<open_zero<<",\"table_offsets\":[";
            for(std::uint32_t i=0;i<60u;++i){if(i)std::cout<<',';const auto p=address(porsche::install_paths_table_0065b2a0[i]);if(!p)std::cout<<"null";else std::cout<<static_cast<std::int32_t>(p-address(blob));}
            std::cout<<"],\"bytes\":\""<<encode(blob,length)<<"\"}\n";
        }else if(operation=="CLEAN"){
            std::uint32_t nonnull;if(!(std::cin>>nonnull)||nonnull>1)return 5;
            porsche::install_paths_blob_0065b29c=nonnull?blob:nullptr;free_count=0;free_pointer=0;
            const auto result=porsche::install_paths_cleanup_004b7070();
            const auto final=address(porsche::install_paths_blob_0065b29c);
            std::cout<<"{\"op\":\"CLEAN\",\"result\":"<<result<<",\"blob_offset\":"<<(final?static_cast<std::int32_t>(final-address(arena)):-1)
              <<",\"free_count\":"<<free_count<<",\"free_pointer_offset\":"<<(free_count?static_cast<std::int32_t>(free_pointer-address(arena)):-1)<<"}\n";
        }else return 6;
    }
    return 0;
}
