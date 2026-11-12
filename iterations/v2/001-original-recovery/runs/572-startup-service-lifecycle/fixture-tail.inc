static U __stdcall tset(U arg){event(0x6bd954,{arg});if(flags&1024)render_texture_pending_006a3a58=0xdeadbeef;return 0x89abcdef;}
static U __stdcall tset_alt(U arg){event(0x6bd955,{arg});if(flags&1024)render_texture_pending_006a3a58=0xdeadbeef;return 0x13579bdf;}
namespace porsche {
void __cdecl render_display_texture_update_005550e0(){event(0x5550e0,{});if(flags&512){startup_service_active_0069dd1e=0x42;startup_lifecycle_mode_005de6b8=0;render_texture_dirty_006a3a48=1;}}
void __cdecl render_texture_process_005554b0(void* p){event(0x5554b0,{ptr(p)});if(flags&512){put(p,0x10,0x11223344);render_thrash_exports_006bd910[17]=ptr(reinterpret_cast<void*>(&tset_alt));}}
}
static void init(){
 const B raw_mode[]={@MODE_005DE6B8@};require(sizeof raw_mode==1&&raw_mode[0]==1&&startup_lifecycle_mode_005de6b8==1,"PE initial mode before resets");
 require(startup_service_active_0069dd1e==0,"canonical service initial zero");
 static const B a[]={@BODY_00536050@},b[]={@BODY_005360A0@},c[]={@BODY_00555440@};const B* bodies[]={a,b,c};const U sizes[]={46,43,76};
 for(U n=0;n<3;++n){code[n]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[n]!=nullptr,"raw allocation");memcpy(code[n],bodies[n],sizes[n]);}
 absolute(code[0],46,0x5de6b8,&startup_lifecycle_mode_005de6b8,1);absolute(code[0],46,0x69dd1e,&startup_service_active_0069dd1e,1);
 relative(code[0],46,0x536050,0x5550e0,reinterpret_cast<void*>(&render_display_texture_update_005550e0),1);relative(code[0],46,0x536050,0x555440,code[2],1);
 absolute(code[1],43,0x5de6b8,&startup_lifecycle_mode_005de6b8,1);absolute(code[1],43,0x69dd1e,&startup_service_active_0069dd1e,1);
 relative(code[1],43,0x5360a0,0x555330,reinterpret_cast<void*>(&render_texture_invalidate_00555330),1);relative(code[1],43,0x5360a0,0x5550e0,reinterpret_cast<void*>(&render_display_texture_update_005550e0),1);relative(code[1],43,0x5360a0,0x555440,code[2],1);
 absolute(code[2],76,0x6a3a48,&render_texture_dirty_006a3a48,1);absolute(code[2],76,0x6a3a58,&render_texture_pending_006a3a58,2);absolute(code[2],76,0x6bd954,render_thrash_exports_006bd910+17,3);
 relative(code[2],76,0x555440,0x5554b0,reinterpret_cast<void*>(&render_texture_process_005554b0),1);
 for(B* p:code)require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"instruction cache");
}
static void compare(){
 Trace original{};U result=0;
 for(U side=0;side<3;++side){
  if(kind==2&&side==2)continue;
  cpp_side=side!=0;reset();startup_service_active_0069dd1e=static_cast<B>(scene);startup_lifecycle_mode_005de6b8=static_cast<B>(layout);render_thrash_exports_006bd910[17]=ptr(reinterpret_cast<void*>(&tset));
  seed_fpu();B* receiver=arena.storage[0]+offset;U args[2]={};void* fn=nullptr;U argc=0,cleanup=0;
  if(kind==0){fn=side==0?code[0]:side==1?reinterpret_cast<void*>(&startup_lifecycle_end_raw_00536050):reinterpret_cast<void*>(&game_setup_movie_service_end_00536050);if(side==2){args[0]=ptr(receiver);argc=1;cleanup=4;}}
  if(kind==1){fn=side==0?code[1]:side==1?reinterpret_cast<void*>(&startup_lifecycle_frame_raw_005360a0):reinterpret_cast<void*>(&frame_pump_boundary_005360a0);if(side==2){args[0]=ptr(receiver);args[1]=input_value;argc=2;cleanup=8;}else{args[0]=input_value;argc=1;}}
  if(kind==2){fn=side==0?code[2]:reinterpret_cast<void*>(&render_display_texture_release_00555440);args[0]=input_value==17?ptr(arena.storage[1]+offset):input_value;put(arena.storage[1]+offset,0x10,0x55667788);argc=1;cleanup=4;}
  bool complete=true;__try{trace.abi=invoke(fn,receiver,args,argc,cleanup,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
  require(complete&&trace.abi==0,"mapped input/stack/nonvolatile ABI");snapshot(trace.final);capture(trace.fpu);
  if(side==0)original=trace;else{require(memcmp(&trace,&original,sizeof trace)==0,"state/ordered callback/FPU");events_total+=trace.count;}
 }
 ++cases;
}
int main(){
 init();initial_count=2;precision=2;rounding=0;depth=1;initial_status=0;
 for(kind=0;kind<3;++kind)for(offset=0;offset<4;++offset)for(dirty_mode=0;dirty_mode<2;++dirty_mode)for(scene=0;scene<2;++scene)for(layout=0;layout<2;++layout)for(U f:{0u,256u,512u,1024u,1792u})for(U v:{0u,1u,16u,17u,0x100u,0x101u}){flags=f;value=0x9b8a7c6d;input_value=v;compare();}
 __asm fninit
 printf("startup_lifecycle_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
