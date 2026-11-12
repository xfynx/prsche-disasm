static void init(){
 require(startup_service_active_0069dd1e==0,"new byte loader zero before resets");
 require(render_texture_slot_count_006a3a44==0&&render_texture_dirty_006a3a48==0&&render_texture_pending_006a3a58==0,"canonical state loader zero");
 static const B body[]={@BODY_00536080@};code[0]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[0]!=nullptr,"raw code allocation");memcpy(code[0],body,sizeof body);
 relative(code[0],sizeof body,0x536080,0x555330,reinterpret_cast<void*>(&render_texture_invalidate_00555330),1);
 absolute(code[0],sizeof body,0x69dd1e,&startup_service_active_0069dd1e,1);
 require(FlushInstructionCache(GetCurrentProcess(),code[0],sizeof body)!=0,"instruction cache");
}
static void compare(){
 Trace original{};Fpu fp_original{};
 for(U side=0;side<3;++side){
  cpp_side=side!=0;reset();startup_service_active_0069dd1e=0x6d;seed_fpu();B* receiver=arena.storage[0]+offset;U arg=ptr(receiver),result=0;
  void* fn=side==0?code[0]:side==1?reinterpret_cast<void*>(&startup_sequence_service_00536080):reinterpret_cast<void*>(&game_setup_movie_service_begin_00536080);
  bool completed=true;__try{trace.abi=invoke(fn,receiver,side==2?&arg:nullptr,side==2?1:0,side==2?4:0,result);}__except(exception_record(GetExceptionInformation())){completed=false;}
  require(completed,"valid receiver and slot transport");require(trace.abi==0,"stack and nonvolatiles");snapshot(trace.final);capture(trace.fpu);
  if(side==0){original=trace;fp_original=trace.fpu;}
  else {require(memcmp(&trace,&original,sizeof trace)==0,"ordered state/child events");require(memcmp(&trace.fpu,&fp_original,sizeof fp_original)==0,"final FPU");events_total+=trace.count;}
 }
 ++cases;
}
int main(){
 init();kind=0;layout=2;initial_count=2;precision=2;rounding=0;depth=1;initial_status=0;
 for(offset=0;offset<4;++offset)for(dirty_mode=0;dirty_mode<3;++dirty_mode)for(U edit:{0u,1u,2u,256u,257u})for(U v:{0u,0xffffffffu,0x12345678u}){flags=edit;scene=cases%2;value=v;compare();}
 __asm fninit
 printf("startup_service_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
