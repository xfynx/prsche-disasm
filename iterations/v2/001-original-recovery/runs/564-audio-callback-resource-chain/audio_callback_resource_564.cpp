// Porsche.exe ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
// Candidate only: proof and shared-graph acceptance are pending.
#include <cstdint>
#include <cstring>
#include "porsche/files.hpp"
#include "porsche/shared_runtime_globals.hpp"
#include "../478-audio-resource-controls/audio_resource_controls_478.hpp"
#include "../374-render-descriptor/render_descriptor.hpp"
namespace porsche {
using U=std::uint32_t;using I=std::int32_t;using B=std::uint8_t;
U __cdecl render_descriptor_read_be_0056e290(const void*,U);
I __cdecl formatter_search_compare_005ae3c0(const char*,const char*);
I __cdecl audio_service_stream_start_00567550(U,U,U,U,U);
static U addr(const void* p){return reinterpret_cast<U>(p);}
static U load(U p){U x;std::memcpy(&x,reinterpret_cast<const void*>(p),4);return x;}
static void store(U p,U x){std::memcpy(reinterpret_cast<void*>(p),&x,4);}
static U be(U p,U n){return render_descriptor_read_be_0056e290(reinterpret_cast<const void*>(p),n);}
U __cdecl audio_resource_kind_00566520(U source){
 if(be(source,2)==0xc0fb)return 1;
 return be(source,4)==0x42494746?2:0;
}
U __cdecl audio_resource_size_00566560(U source){
 U kind=audio_resource_kind_00566520(source);
 if(kind==1)return be(source+2,2)+4;
 if(kind==2)return be(source+12,4);
 return 0;
}
U __cdecl audio_resource_find_005665b0(U source,U name,U wanted,U out1,U out2){
 U end=source+audio_resource_size_00566560(source),kind=audio_resource_kind_00566520(source),index=0;
 U cursor=source+(kind==1?6u:16u);
 if(kind==1||kind==2){
  while(cursor<end){
   U prefix=kind==1?6u:8u;
   bool match=name?formatter_search_compare_005ae3c0(reinterpret_cast<const char*>(cursor+prefix),reinterpret_cast<const char*>(name))==0:index==wanted;
   if(match){
    U count=kind==1?3u:4u;
    if(out1)store(out1,be(cursor,count));
    if(out2)store(out2,be(cursor+count,count));
    return cursor+prefix;
   }
   U p=cursor+prefix;while(*reinterpret_cast<const B*>(p))++p;
   cursor=p+1;++index;
  }
 }
 if(out1)store(out1,0);if(out2)store(out2,0);return 0;
}
extern const char audio_resource_file_005bd54c[]="\\real\\cmn\\locatbig.c";
extern const char audio_resource_missing_name_005bd524[]="BIG_locateentry: ENTRY \"%s\" NOT FOUND\n";
extern const char audio_resource_missing_index_005bd4fc[]="BIG_locateentry: ENTRY #%d NOT FOUND\n";
U __cdecl audio_resource_locate_005666f0(U source,U name,U index,U out1,U out2){
 U found=audio_resource_find_005665b0(source,name,index,out1,out2);
 if(!found&&render_descriptor_option_005deb88){
  diagnostic_file_005deb74_set(audio_resource_file_005bd54c);
  shared_runtime_word_005deb78=name?0xef:0xf1;
  auto fn=reinterpret_cast<void(__cdecl*)(const char*,...)>(diagnostic_handler_005debf0);
  if(name)fn(audio_resource_missing_name_005bd524,reinterpret_cast<const char*>(name));
  else fn(audio_resource_missing_index_005bd4fc,index);
 }
 return found;
}
I __cdecl audio_service_stream_start_00567720(U channel,U mode,U data,U size){return audio_service_stream_start_00567550(channel,mode,data,size,0);}
void __cdecl audio_service_play_004ad8b0(){
 U size;U object=audio_resource_query_root_00656ab4;
 U index=static_cast<U>(static_cast<I>(*reinterpret_cast<const std::int8_t*>(object+load(object+12)+0xe8)));
 U result=audio_resource_locate_005666f0(load(object+0x88),0,index,addr(&size),0);
 object=audio_resource_query_root_00656ab4;store(object+0x28,result);
 object=audio_resource_query_root_00656ab4;U channel=load(object+0x70);
 if(static_cast<I>(channel)>=0){I v=audio_service_stream_start_00567720(channel,1000,object+0xa8,size);object=audio_resource_query_root_00656ab4;store(object+0x74,static_cast<U>(v));object=audio_resource_query_root_00656ab4;}
 store(object+0x14,2);object=audio_resource_query_root_00656ab4;
 store(object+0x170,0);store(object+0x18c,0);store(object+0x174,0);store(object+0x178,0);store(object+0x17c,0);store(object+0x180,0);store(object+0x188,0);
}
}
