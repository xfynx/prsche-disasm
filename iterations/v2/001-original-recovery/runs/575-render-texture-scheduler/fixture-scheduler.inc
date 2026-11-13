// Shared 572 scaffold; these are controlled driver/diagnostic seams only.
static const B raw_file[]={@FILE_005BC294@},raw_messages[]={@MESSAGES_005BC2EC@};
static const char original_messages[]="[DTEX] Error - trying to upload a texture thats already uploaded.\n Texture %s.\n\0D3D Error - Not enough texture memory.\n";
namespace porsche {
const char render_texture_cleanup_file_005bc294[30]="\\real\\patch3\\cmn\\dyntexture.c";
static void __cdecl diagnostic575(const char*,...);
void (__cdecl* diagnostic_handler_005debf0)(const char*)=reinterpret_cast<void(__cdecl*)(const char*)>(&diagnostic575);
}
static U __stdcall upload575(U texture,U pixels,U palette){event(0x6bd940,{texture,pixels,palette});
 if(flags&32){B* p=arena.nodes[0][0]+offset;put(p,0x2c,word(p,0x2c)^0x10000000u);}
 return 0x2468ace0u;
}
static U __stdcall upload_alt575(U texture,U pixels,U palette){event(0x6bd941,{texture,pixels,palette});return 0x12345678u;}
static U __stdcall create575(U a,U b,U c,U d,U e){event(0x6bd968,{a,b,c,d,e});
 if(flags&2)render_texture_slot_count_006a3a44=1;
 if(flags&4){B* p=arena.nodes[0][0]+offset;put(p,4,1);put(p,0x2c,word(p,0x2c)^0x100u);render_thrash_exports_006bd910[12]=ptr(reinterpret_cast<void*>(&upload_alt575));}
 return (flags&1)?0:0x10203040u;
}
static U __stdcall set575(U value0){event(0x6bd954,{value0});
 if(flags&16){B* p=arena.nodes[0][0]+offset;put(p,0x10,0x11112222);put(p,0x18,0x33334444);put(p,0x1c,0x55556666);put(p,0x2c,word(p,0x2c)^0x20000000u);render_thrash_exports_006bd910[12]=ptr(reinterpret_cast<void*>(&upload_alt575));}
 return 0x13572468u;
}
static void __cdecl notify575(TextureNotifyDescriptor575* a,TextureNotifyDescriptor575* b){
 event(0x6a3a50,{a?1u:0u,b?1u:0u,a?a->slot_value:0u,a?a->texture_value:0u,a?a->payload:0u,a?a->texture:0u,b?b->slot_value:0u,b?b->texture_value:0u,b?b->payload:0u,b?b->texture:0u});
 if((flags&4)&&a){B* p=reinterpret_cast<B*>(a->texture);put(p,4,1);B* new_tail=arena.nodes[1][2]+offset;put(new_tail,0xc,0);put(render_texture_slots_006a33f8+48,0x2c,ptr(new_tail));}
 if((flags&8)&&a){B* p=reinterpret_cast<B*>(a->texture);put(p,0x2c,word(p,0x2c)^0x400u);}
}
namespace porsche {
static void __cdecl diagnostic575(const char* message,...){
 if(std::strcmp(message,original_messages)==0){va_list ap;va_start(ap,message);const U texture=ptr(va_arg(ap,const char*));va_end(ap);event(0x5bc2ec,{texture});}
 else{require(std::strcmp(message,original_messages+80)==0,"diagnostic message");event(0x5bc33c,{});}
 if(flags&256)render_texture_slot_count_006a3a44=1;
}
}
static void scheduler_init(){
 require(render_texture_notify_callback_006a3a50==nullptr,"initial callback zero");
 require(render_texture_slot_count_006a3a44==0&&render_texture_dirty_006a3a48==0,"initial canonical count/dirty");
 require(sizeof raw_file==sizeof render_texture_cleanup_file_005bc294&&!memcmp(raw_file,render_texture_cleanup_file_005bc294,sizeof raw_file),"raw file label");
 require(sizeof raw_messages==sizeof original_messages&&!memcmp(raw_messages,original_messages,sizeof raw_messages),"raw adjacent messages");
 @RAW_CHUNKS@
 @RAW_PATCHES@
 for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"instruction cache");
}
static void scheduler_setup(){
 reset();shared_runtime_word_005deb74=0x11112222;shared_runtime_word_005deb78=0x33334444;
 render_texture_notify_callback_006a3a50=(flags&64)?nullptr:notify575;
 render_thrash_exports_006bd910[12]=ptr(reinterpret_cast<void*>(&upload575));render_thrash_exports_006bd910[17]=ptr(reinterpret_cast<void*>(&set575));render_thrash_exports_006bd910[22]=ptr(reinterpret_cast<void*>(&create575));
 for(U i=0;i<32;++i){B* r=render_texture_slots_006a33f8+i*48;put(r,4,0x100+i);put(r,8,0x200+i);put(r,0xc,0x300+i);put(r,0x10,0x400+i);put(r,0x18,0);put(r,0x1c,1);put(r,0x20,2);
  for(U j=0;j<3;++j){B* p=arena.nodes[i][j]+offset;put(p,4,i);put(p,0x10,0);put(p,0x18,0x22000000+i);put(p,0x1c,0x33000000+i);put(p,0x24,0x44000000+i);put(p,0x2c,0x87650008u);p[0x30]='A';p[0x31]=0;}
  B* head=arena.nodes[i][2]+offset;B* tail=arena.nodes[i][1]+offset;put(r,0x28,ptr(head));put(r,0x2c,ptr(tail));put(tail,0xc,ptr(head));put(head,8,ptr(tail));put(tail,0x10,0x76543210u);
 }
 if(kind==4||kind==5){B* p=arena.nodes[0][0]+offset;B* tail=arena.nodes[0][1]+offset;B* head=arena.nodes[0][2]+offset;
  if(scene&1){put(p,0x10,0x12345678);put(p,8,ptr(tail));put(p,0xc,ptr(head));put(tail,0xc,ptr(p));put(head,8,ptr(p));}
  else {put(p,0x10,0);put(tail,0xc,scene&2?0:ptr(head));}
  if(scene&4)put(p,0x2c,0x8765000au);
 }
 if(kind==2&&(flags&128))put(arena.nodes[0][0]+offset,0x10,0x24681357);
}
static void scheduler_compare(){
 U original_result=0;
 for(U side=0;side<(kind==0?3u:2u);++side){
  cpp_side=side!=0;scheduler_setup();seed_fpu();U args[2]={};U argc=0,cleanup=0,result=0;void* fn=nullptr;
  if(kind==0)fn=side==0?code[0]:side==1?reinterpret_cast<void*>(&render_texture_scheduler_005550e0):reinterpret_cast<void*>(&render_display_texture_update_005550e0);
  if(kind==1){fn=side==0?code[1]:reinterpret_cast<void*>(&render_texture_score_005552a0);args[0]=ptr(arena.nodes[(scene&1)?31:0][0]+offset);args[1]=input_value;argc=2;cleanup=8;}
  if(kind==2){fn=side==0?code[2]:reinterpret_cast<void*>(&render_texture_prepare_00554f60);args[0]=ptr(arena.nodes[0][0]+offset);argc=1;cleanup=4;}
  if(kind==3){fn=side==0?code[3]:reinterpret_cast<void*>(&render_texture_notify_00555040);args[0]=(scene&1)?ptr(arena.nodes[0][0]+offset):0;args[1]=(scene&2)?ptr(arena.nodes[(scene&4)?0:1][0]+offset):0;if(scene==8){args[0]=1;args[1]=1;}argc=2;cleanup=8;}
  if(kind==4){fn=side==0?code[4]:reinterpret_cast<void*>(&render_texture_process_005554b0);args[0]=(scene&8)?0:ptr(arena.nodes[0][0]+offset);argc=1;cleanup=4;}
  if(kind==5){fn=side==0?code[5]:reinterpret_cast<void*>(&render_display_texture_release_00555440);args[0]=(scene&8)?0:ptr(arena.nodes[0][0]+offset);argc=1;cleanup=4;}
  bool complete=true;__try{trace.abi=invoke(fn,nullptr,args,argc,cleanup,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
  require(complete&&trace.abi==0,"mapped/ABI");snapshot(trace.final);capture(trace.fpu);
  if(side==0){expected=trace;original_result=result;}else{require(memcmp(&trace,&expected,sizeof trace)==0,"state/calls/FPU");if((kind==0&&side==1)||kind==1||kind==2)require(result==original_result,"used EAX");events_total+=trace.count;}
 }
 ++cases;
}
int main(){
 scheduler_init();precision=2;rounding=1;depth=5;initial_status=0x25;value=0x99887766;offset=0;
 kind=0;for(U count: {0u,1u,2u,3u,32u})for(U lay: {0u,1u,2u})for(U f: {0u,1u,2u,4u,8u,32u,64u,128u,256u}){if(count==32&&lay!=0)continue;if(count<2&&(f&2))continue;initial_count=count;layout=lay;flags=f;dirty_mode=0;scene=0;scheduler_compare();}
 kind=0;initial_count=2;layout=1;flags=0;dirty_mode=1;scene=0;scheduler_compare();
 kind=1;initial_count=2;layout=0;flags=0;dirty_mode=0;for(scene=0;scene<2;++scene)for(U v: {0xffffffffu,0u,1u,2u,3u,0x80000000u}){input_value=v;scheduler_compare();}
 kind=2;initial_count=2;layout=0;dirty_mode=0;scene=0;for(U f: {0u,1u,4u,8u,32u,64u,128u}){flags=f;scheduler_compare();}
 kind=3;for(scene=0;scene<9;++scene)for(U f: {0u,4u,8u,64u}){if(scene==8&&f!=64)continue;flags=f;scheduler_compare();}
 for(kind=4;kind<=5;++kind)for(scene=0;scene<10;++scene)for(U f: {0u,4u,8u,16u,32u,64u})for(dirty_mode=0;dirty_mode<2;++dirty_mode){flags=f;scheduler_compare();}
 __asm fninit
 printf("render_texture_scheduler_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
