static void patch_call(U va,void* target,U original){
 U offset=va-0x567550;require(slab[offset]==0xe8,"call opcode");
 I old=static_cast<I>(rd(slab+offset+1));require(va+5+static_cast<U>(old)==original,"raw call target");
 wr(slab+offset+1,ptr(target)-ptr(slab+offset+5));
}
static void init_slab(){
 slab=static_cast<B*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));require(slab!=nullptr,"slab");
 const B body[]={@BODY_00567550@};std::memcpy(slab,body,sizeof body);
 require(rd(slab+1)==0x006b499c,"active absolute");wr(slab+1,ptr(application_audio_device_state_006b48c0.data())+0xdc);
 patch_call(0x56756c,reinterpret_cast<void*>(&audio_stream_service_lookup_00566d60),0x566d60);
 patch_call(0x5675b1,reinterpret_cast<void*>(&audio_stream_codec_memory_0056b690),0x56b690);
 patch_call(0x5675d1,reinterpret_cast<void*>(&audio_stream_codec_file_0056c040),0x56c040);
 patch_call(0x5675ed,reinterpret_cast<void*>(&audio_backend_lock_005896d0),0x5896d0);
 patch_call(0x56764e,reinterpret_cast<void*>(&audio_backend_unlock_005896f0),0x5896f0);
 require(FlushInstructionCache(GetCurrentProcess(),slab,4096)!=0,"cache");
}
static void execute(bool cpp){
 __asm fninit
 std::memset(&trace,0,sizeof trace);std::memset(arena,0x5a,sizeof arena);std::memset(&audio_stream_service_storage_006b7740,0,80);
 B* object=arena+128+alignment;B* elements=arena+640;
 wr(object,ptr(elements));wr(object+4,0x13572468);wr(object+0x10,old_level);
 object[0x15]=static_cast<B>(threshold);object[0x16]=static_cast<B>(index_bits);
 audio_stream_service_storage_006b7740.slots[0]=(variant&2)?0:ptr(object);
 application_audio_device_state_006b48c0[0xdc]=(variant&1)?0:1;
 application_audio_device_state_006b48c0[0xdf]=0x75;
 class_error_file_005deb74=0x11112222;class_error_line_005deb78=0x33334444;
 seed();U args[5]={0,0x12345678,0x78563412,level,which};
 void* f=cpp?reinterpret_cast<void*>(&audio_service_stream_start_00567550):slab;
 trace.abi=invoke(f,args,5);snapshot(trace.final);
}
static void check(){execute(false);expected=trace;U expected_return=captured_return;execute(true);
 if(trace.abi||expected.abi||std::memcmp(&trace,&expected,sizeof trace)||captured_return!=expected_return){std::printf("divergence case=%u mode=%u variant=%u index=%08x limit=%08x gen=%08x value=%08x eax=%08x/%08x\n",cases,which,variant,index_bits,threshold,old_level,level,captured_return,expected_return);std::fflush(stdout);ExitProcess(1);}++cases;events_total+=trace.count;}
int main(){
 SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);AddVectoredExceptionHandler(1,&fault);
 const B* zero=reinterpret_cast<const B*>(&audio_stream_service_storage_006b7740);for(U i=0;i<80;++i)require(zero[i]==0,"initial slots");
 require(application_audio_device_state_006b48c0[0xdc]==0&&application_audio_device_state_006b48c0[0xdf]==0,"initial device bytes");
 init_slab();const U gens[]={0,0x7ffffeffu,0x7fffff00u,0xffffff00u,0xffffffffu};
 for(which=0;which<3;++which)for(variant=0;variant<8;++variant)for(alignment=0;alignment<4;++alignment)for(U gen:gens)for(U cursor: {0u,1u,2u}){old_level=gen;index_bits=cursor;threshold=2;level=(variant&4)?0:0x34567890;check();}
 which=0;alignment=0;for(U val:{0u,1u,0xfffffffeu,0xffffffffu,0x7fffffffu,0x80000000u})for(variant=0;variant<4;++variant){index_bits=val;threshold=val;old_level=val;level=0x34567890;check();}
 which=1;variant=0;alignment=0;index_bits=0;threshold=2;old_level=0x12345678;level=0x34567890;
 for(U precision:{0u,2u,3u})for(rc=0;rc<4;++rc)for(U d:{0u,1u,5u,8u})for(U st:{0u,0x25u,0x453fu}){pc=precision;depth=d;sticky=st;check();}
 __asm fninit
 std::printf("audio_service_continuation_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events_total);return 0;
}
