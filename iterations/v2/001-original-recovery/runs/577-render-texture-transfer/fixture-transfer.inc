// Diagnostic endpoints only; production uses its existing canonical owners.
static const B raw_comparator[]={@RAW_COMPARATOR@},raw_formats[]={@RAW_FORMAT_TABLE@};
static U transfer_flags,transfer_scene,depth_mode,input_width,input_format,input_format2,input_format3,input_format4,input_byte,input_bytes;
namespace porsche {
// Existing 540 and 537 fixture views; real game graph owns these.
const char render_texture_cleanup_file_005bc294[30]="\\real\\patch3\\cmn\\dyntexture.c";
static void __cdecl diagnostic577(const char*){require(false,"unexpected texture diagnostic");}
void (__cdecl* diagnostic_handler_005debf0)(const char*)=diagnostic577;
// Unused 521 source dependencies are fail-closed.
B cursor_snapshot_prefix_005de650[12]{},cursor_snapshot_suffix_005de65e[30]{};
void* window_shutdown_handle_0069dd18=nullptr;U window_shutdown_state_005de67c=0,window_shutdown_config_005de620[12]{},splash_progress_format_005dead0=0;
B window_shutdown_source_005de65c=0,window_shutdown_source_005de65d=0;
void* __cdecl render_descriptor_allocate_00535700(U,U,U,U,U){require(false,"unused 521 allocate");return nullptr;}
void __stdcall window_shutdown_display_callback_006bd9b0(U){require(false,"unused 521 display");}
void __cdecl window_shutdown_runtime_state_00534430(){require(false,"unused 521 shutdown");}
void __cdecl heap_fill_0053c290(void* p,U byte,U bytes){event(0x53c290,{ptr(p),byte,bytes});require(byte==0&&(bytes==48||bytes==56),"fill shape");if(!p){RaiseException(0xe0577002,0,0,nullptr);return;}memset(p,0,bytes);++fill_calls;}
void* __cdecl allocate_00531ca0(const char* name,std::int32_t bytes,U id){event(0x531ca0,{ptr(name),static_cast<U>(bytes),id});++allocator_calls;if(bytes==56)return arena.nodes[0][0];if(bytes==0x400)return arena.pal[0];return arena.storage[0];}
void* __stdcall platform_virtual_alloc(void* p,U bytes,U mode,U protect){event(0x5b2144,{ptr(p),bytes,mode,protect});return nullptr;}
U __cdecl application_heap_slot_00569a70(){require(false,"blocked heap slot not executed");return 0;}
std::int32_t __cdecl heap_init_005697f0(U,const char*,void*,std::int32_t,U,U,std::int32_t,std::int32_t,U,std::int32_t,std::int32_t,void*){require(false,"unused heap init");return 0;}
void __cdecl render_texture_diagnostic_0055ec50(U,const char*,...){require(false,"unmapped full table");}
void __cdecl process_exit_005a246e(U){require(false,"unmapped process exit");}
void __cdecl heap_copy_dispatch_005323e0(void* out,const void* in,U bytes){event(0x5323e0,{ptr(out),ptr(in),bytes});++copy_calls;memmove(out,in,bytes);}
std::int32_t __cdecl render_texture_compare_00554310(U fmt,U pal,U type,U p){
 event(0x554310,{fmt,pal,type,p});++selector_calls;
 if((transfer_flags&2)&&selector_calls==1)render_texture_driver_info_006a3a54=reinterpret_cast<U*>(arena.info[1]);
 return (transfer_flags&1)?-7:static_cast<std::int32_t>(type*10u+p);
}
std::int32_t __cdecl render_texture_depth_convert_005350e0(U a,U b,U c,U d,U src,U dst,U sp,U dp,std::int32_t count){
 event(0x5350e0,{a,b,c,d,src,dst,sp,dp,static_cast<U>(count)});++depth_calls;
 if(transfer_flags&4){B* node=arena.nodes[0][0];put(node,0x1c,ptr(arena.pal[1]));put(node,0x2c,word(node,0x2c)^0x40000000u);}
 return static_cast<std::int32_t>(depth_mode);
}
}
static const U* __stdcall about577(){event(0x6bd934,{});return reinterpret_cast<U*>(arena.info[0]);}
static void transfer_init(){
 require(render_texture_driver_info_006a3a54==nullptr,"original driver-info zero before reset");
 require(render_texture_comparator_005df2c8==render_texture_compare_00554310,"original comparator relocation before override");
 require(sizeof raw_comparator==4&&word(raw_comparator)==0x00554310,"PE original callback word before relocation");
 require(sizeof raw_formats==280,"raw sparse format bytes");
 memcpy(raw_format_table,raw_formats,sizeof raw_format_table);
 for(U i=0;i<14;++i)require(word(raw_format_table,i*20)==render_texture_format_bits_005df16c[i],"PE versus canonical sparse formats");
 @RAW_CHUNKS@
 @RAW_PATCHES@
 for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"original instructions");
}
static void transfer_setup(){
 reset();selector_calls=depth_calls=copy_calls=allocator_calls=0;std::memset(render_texture_slots_006a33f8,0,1536);
 render_texture_slot_count_006a3a44=0;render_texture_count_006a3a40=0;render_texture_dirty_006a3a48=0;
 render_texture_driver_info_006a3a54=nullptr;render_texture_comparator_005df2c8=render_texture_compare_00554310;
 render_thrash_exports_006bd910[9]=ptr(reinterpret_cast<void*>(&about577));
 render_texture_arena_006a3a5c=ptr(arena.storage[0]);render_texture_heap_id_006a3a60=0;
 if(transfer_scene==5){render_texture_arena_006a3a5c=0;render_texture_preferred_bytes_005df2c4=0x80000;}
 for(U k=0;k<2;++k){put(arena.info[k],0xc,0x40);put(arena.info[k],0x2c,k?1:2);put(arena.info[k],0x30,ptr(arena.types[k]));put(arena.info[k],0x34,2);put(arena.info[k],0x38,ptr(arena.palettes[k]));for(U i=0;i<16;++i){put(arena.types[k],i*4,1);put(arena.palettes[k],i*4,1);}}
 for(U i=0;i<sizeof arena.pixels;++i)arena.pixels[i]=static_cast<B>(i+input_byte);
 for(U j=0;j<2;++j)for(U i=0;i<1024;++i)arena.pal[j][i]=static_cast<B>(i+j*17);
 std::memset(arena.name,'X',sizeof arena.name);const U name_length=(transfer_scene==1)?0:(transfer_scene==2)?7:(transfer_scene==3)?8:2;arena.name[name_length]=0;
}
static void transfer_compare(){
 U result0=0,complete0=0;
 for(U side=0;side<2;++side){
  cpp_side=side!=0;transfer_setup();seed_fpu();U args[9]={};U argc=0,result=0,abi=0;void* fn=nullptr;
  B* node=arena.nodes[0][0];B* src=arena.pixels;B* dest=arena.storage[0];
  if(kind==0){fn=side?reinterpret_cast<void*>(&render_display_texture_alloc_00554960):code[0];args[0]=input_width;args[1]=input_format2;args[2]=input_format3;args[3]=input_format4;args[4]=value;args[5]=ptr(arena.name);argc=6;}
  if(kind==1){fn=side?reinterpret_cast<void*>(&render_display_texture_copy_00554d70):code[1];put(node,4,0);put(node,0x18,ptr(dest));put(node,0x1c,ptr(arena.pal[0]));put(node,0x24,input_format);put(node,0x28,input_format2);put(node,0x2c,0x87650002u);put(render_texture_slots_006a33f8,8,input_format3);put(render_texture_slots_006a33f8,0xc,input_format4);put(render_texture_slots_006a33f8,0x14,input_bytes);args[0]=ptr(node);args[1]=(transfer_scene&1)?0:ptr(src);args[2]=(transfer_scene&2)?0:ptr(arena.pal[1]);argc=3;}
  if(kind==2){fn=side?reinterpret_cast<void*>(&render_texture_select_00554820):code[2];put(arena.storage[0],0,input_format);put(arena.storage[0],4,input_format2);args[0]=ptr(arena.storage[0]);args[1]=(transfer_scene&1)?args[0]:ptr(arena.storage[0]+4);if(transfer_scene&2)args[1]=0;if(transfer_scene&4)args[0]=0;argc=2;}
  if(kind==3){fn=side?reinterpret_cast<void*>(&render_texture_convert_005556b0):code[3];args[0]=input_format;args[1]=input_format2;args[2]=input_format3;args[3]=input_format4;args[4]=ptr(src);args[5]=ptr(dest);args[6]=ptr(arena.pal[0]);args[7]=ptr(arena.pal[1]);args[8]=input_bytes;argc=9;}
  if(kind==4){fn=side?reinterpret_cast<void*>(&render_texture_expand_00555780):code[4];args[0]=ptr(dest);args[1]=ptr(src);args[2]=input_bytes;argc=3;}
  bool complete=true;__try{abi=invoke(fn,nullptr,args,argc,argc*4,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
  require(abi==0,"callee-saved/stack ABI");trace.abi=abi;snapshot(trace.final);capture(trace.fpu);
  if(side==0){expected=trace;result0=result;complete0=complete;}else{require(complete==static_cast<bool>(complete0),"completion/fault boundary");require(memcmp(&trace,&expected,sizeof trace)==0,"state/events/FPU/fault");if((kind==0||kind==2)&&complete)require(result==result0,"used return");events_total+=trace.count;}
 }
 ++cases;
}
int main(){
 transfer_init();precision=2;rounding=1;depth=5;initial_status=0x25;offset=0;initial_count=0;layout=0;dirty_mode=0;value=0x44000008;
 // Driver/global write occurs even when dimensions are rejected; null name/node
 // fail behavior is covered by the controlled allocation-reserve failure scene.
 kind=0;for(U f: {0u,1u,2u})for(U s: {0u,1u,2u,3u,5u})for(U w: {0u,3u,8u}){transfer_flags=f;transfer_scene=s;input_width=w;input_format2=(s==3)?4:w;input_format3=0x101;input_format4=0x202;depth_mode=1;transfer_compare();}
 // Direct selector: output alias, nullable output, strict equal/negative scores,
 // and a callback that swaps the cached device pointer during traversal.
 kind=2;for(U f: {0u,1u,2u})for(U s: {0u,1u,2u,4u}){transfer_flags=f;transfer_scene=s;input_format=1;input_format2=2;transfer_compare();}
 // Parent copy with captured palette, callback mutation and flag preservation.
 kind=1;for(U f: {0u,4u})for(U s: {0u,1u,2u}){transfer_flags=f;transfer_scene=s;input_format=1;input_format2=1;input_format3=1;input_format4=1;input_bytes=8;depth_mode=1;transfer_compare();}
 // Converter preserves masked formats and signed wrapped byte-count ratio.
 kind=3;transfer_scene=0;transfer_flags=0;for(U mode: {0u,1u})for(U b: {0u,1u,3u,8u,0x10000000u}){depth_mode=mode;input_format=0x108;input_format2=0x101;input_format3=0x107;input_format4=0x101;input_bytes=b;if(!mode&&b>8)continue;transfer_compare();}
 // All 256 original byte/nibble combinations plus odd, negative and SIMD-edge counts.
 kind=4;transfer_flags=0;transfer_scene=0;for(input_byte=0;input_byte<256;++input_byte){input_bytes=2;transfer_compare();}for(U b: {0u,1u,3u,0xffffffffu,0x80000000u}){input_bytes=b;transfer_compare();}for(U byte: {0u,0xffu})for(U b: {30u,32u,34u,62u,64u,66u,128u,512u}){input_byte=byte;input_bytes=b;transfer_compare();}
 __asm fninit
 printf("render_texture_transfer_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
