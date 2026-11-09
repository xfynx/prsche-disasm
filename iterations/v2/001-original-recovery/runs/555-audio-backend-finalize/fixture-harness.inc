alignas(16) static B floating[512];static B environment[28];
struct Fpu{unsigned short control,status,tag;B pad[2],values[80];U mxcsr;};
struct Snapshot{B pan[1025],device[0x18c],output[32];Fpu fp;U abi,result;};
static Snapshot actual,expected;
alignas(16) static B output[32];
static U precision=2,rounding,depth,sticky,mxcsr=0x1f80;
static U count_value,pattern,alias_kind,alignment,operation,phase_value,leaf_value;
static U random_value=0x13572468;
static U next(){random_value=random_value*1664525u+1013904223u;return random_value;}
static void fp_seed(){
    __asm fninit
    __asm fxsave floating
    const unsigned short control=static_cast<unsigned short>(0x7f|(precision<<8)|(rounding<<10));
    const U top=(8-depth)&7;
    const unsigned short status=static_cast<unsigned short>((top<<11)|sticky);
    std::memcpy(floating,&control,2);std::memcpy(floating+2,&status,2);
    floating[4]=0;wr(floating+24,mxcsr);
    for(U i=0;i<depth;++i){
        floating[4]|=static_cast<B>(1u<<((top+i)&7));
        wr(floating+32+i*16,0x10203041u+i);wr(floating+36+i*16,0x87654321u+i);
        const unsigned short exponent=static_cast<unsigned short>(0x3fff+i);
        std::memcpy(floating+40+i*16,&exponent,2);
    }
    __asm fxrstor floating
}
static void fp_capture(Fpu& f){
    __asm fxsave floating
    __asm fnstenv environment
    f.control=static_cast<unsigned short>(rd(floating));f.status=static_cast<unsigned short>(rd(floating+2));
    f.tag=static_cast<unsigned short>(rd(environment+8));f.mxcsr=rd(floating+24);std::memset(f.pad,0,2);
    for(U i=0;i<8;++i){
        std::memcpy(f.values+i*10,floating+32+i*16,10);
        if(!(floating[4]&(1u<<(((f.status>>11)+i)&7))))std::memset(f.values+i*10,0,10);
    }
    __asm fninit
}
// Synthetic cdecl carrier; only the polynomial's EAX is a used return.
static U invoke(void* fn,U argc,U a,U b,U& result){U saved_sp,saved_frame,fail=0,value;__asm {
    push ebx
    push esi
    push edi
    mov saved_sp,esp
    mov saved_frame,ebp
    cmp argc,2
    jb no_two
    push b
no_two:
    cmp argc,1
    jb no_one
    push a
no_one:
    mov ebx,13579bdfh
    mov esi,2468ace0h
    mov edi,10203040h
    call fn
    mov value,eax
    mov eax,argc
    lea esp,[esp+eax*4]
    cmp esp,saved_sp
    jne bad
    cmp ebp,saved_frame
    jne bad
    cmp ebx,13579bdfh
    jne bad
    cmp esi,2468ace0h
    jne bad
    cmp edi,10203040h
    jne bad
    pushfd
    pop eax
    test eax,400h
    jz done
bad:mov fail,1
done:mov esp,saved_sp
    pop edi
    pop esi
    pop ebx
    }result=value;return fail;
}
static void word16(U offset,U value){const unsigned short x=static_cast<unsigned short>(value);std::memcpy(application_audio_device_state_006b48c0.data()+offset,&x,2);}
static void reset(){
    __asm fninit
    actual={};
    for(U i=0;i<1025;++i)reinterpret_cast<B*>(&audio_backend_pan_storage_006b181f)[i]=static_cast<B>(i*37+pattern*13+0x5a);
    for(U i=0;i<sizeof actual.device;++i)application_audio_device_state_006b48c0.preceding_data()[i]=static_cast<B>(i*17+pattern*7+3);
    for(U i=0;i<sizeof output;++i)output[i]=static_cast<B>(i*29+0x51);
    wr(application_audio_device_state_006b48c0.data()+0x1c,count_value);
    const U count=count_value&255;
    // Count0 deliberately uses its separately proven preceding-table byte.
    // Distinct wrap thresholds keep original IDIV denominators nonzero.
    if(count==0){word16(0x2a,0xc000);word16(0x2c,0x4000);}
    else for(U i=0;i<=count;++i){
        U angle=(i+1)*65536u/(count+1);
        if(pattern==1)angle=i*65535u/count;
        if(pattern==2)angle=(i+1)*256u;
        if(pattern==3)angle=0xff00u-(count-1u-i)*256u;
        if(i==count)angle=0xffff;
        word16(0x2c+count*8+i*2,angle);
    }
}
static void execute(bool cpp){
    reset();fp_seed();U ignored;
    if(operation==0){
        actual.abi=invoke(cpp?reinterpret_cast<void*>(&audio_backend_pan_curve_0058e0b0):slab+0x200,1,leaf_value,0,actual.result);
    }else if(operation==1){
        actual.abi=invoke(cpp?reinterpret_cast<void*>(&application_audio_backend_finalize_0058e0e0):slab,0,0,0,ignored);
    }else{
        U destination=ptr(output)+alignment;
        if(alias_kind==1)destination=ptr(&audio_backend_pan_storage_006b181f)+alignment;
        if(alias_kind==2)destination=ptr(audio_backend_pan_storage_006b181f.table)+((phase_value>>8)&255)*4+alignment;
        if(alias_kind==3)destination=ptr(application_audio_device_state_006b48c0.data())+0x1c+alignment;
        if(alias_kind==4)destination=ptr(application_audio_device_state_006b48c0.data())+0x2c+alignment;
        // All copies are exactly the original forward order, including overlap.
        actual.abi=invoke(cpp?reinterpret_cast<void*>(&audio_backend_pan_copy_0058e290):slab+0x300,2,phase_value,destination,ignored);
    }
    fp_capture(actual.fp);
    std::memcpy(actual.pan,&audio_backend_pan_storage_006b181f,1025);
    std::memcpy(actual.device,application_audio_device_state_006b48c0.preceding_data(),sizeof actual.device);
    std::memcpy(actual.output,output,sizeof output);
}
static void check(){
    execute(false);expected=actual;execute(true);
    if(actual.abi||expected.abi||std::memcmp(&actual,&expected,sizeof actual)){
        const B* a=reinterpret_cast<const B*>(&actual);const B* b=reinterpret_cast<const B*>(&expected);U off=0;
        while(off<sizeof actual&&a[off]==b[off])++off;
        std::printf("divergence pan op=%u case=%u count=%08x pattern=%u phase=%08x leaf=%08x alias=%u align=%u PC=%u RC=%u depth=%u sticky=%x offset=%u bytes=%02x/%02x EAX=%08x/%08x\n",operation,cases,count_value,pattern,phase_value,leaf_value,alias_kind,alignment,precision,rounding,depth,sticky,off,off<sizeof actual?a[off]:0,off<sizeof actual?b[off]:0,actual.result,expected.result);
        std::fflush(stdout);ExitProcess(1);
    }++cases;events+=operation==1?256:1;
}
// Actual original builder->consumer compositions, comparing every row and all
// intermediate table/device/output state after the builder and after each copy.
static void composed(bool cpp,Snapshot (&states)[257]){
    reset();fp_seed();U value;
    U abi=invoke(cpp?reinterpret_cast<void*>(&application_audio_backend_finalize_0058e0e0):slab,0,0,0,value);
    fp_capture(states[0].fp);states[0].abi=abi;
    std::memcpy(states[0].pan,&audio_backend_pan_storage_006b181f,1025);
    std::memcpy(states[0].device,application_audio_device_state_006b48c0.preceding_data(),sizeof states[0].device);
    std::memcpy(states[0].output,output,sizeof output);
    for(U row=0;row<256;++row){
        fp_seed();states[row+1].abi=invoke(cpp?reinterpret_cast<void*>(&audio_backend_pan_copy_0058e290):slab+0x300,2,(row<<8)|0xff,ptr(output)+alignment,value);
        fp_capture(states[row+1].fp);
        std::memcpy(states[row+1].pan,&audio_backend_pan_storage_006b181f,1025);
        std::memcpy(states[row+1].device,application_audio_device_state_006b48c0.preceding_data(),sizeof states[row+1].device);
        std::memcpy(states[row+1].output,output,sizeof output);
    }
}
static void compose_check(){
    static Snapshot a[257],b[257];std::memset(a,0,sizeof a);std::memset(b,0,sizeof b);
    composed(false,a);composed(true,b);
    for(U i=0;i<257;++i)require(a[i].abi==0&&b[i].abi==0&&std::memcmp(a+i,b+i,sizeof(Snapshot))==0,"actual builder/poly/consumer intermediate composition");
    cases+=257;events+=512;
}
int main(){
    SetErrorMode(SEM_FAILCRITICALERRORS|SEM_NOGPFAULTERRORBOX);setup();
    SetUnhandledExceptionFilter([](EXCEPTION_POINTERS* p)->LONG{std::printf("divergence fault=%08x eip=%p case=%u\n",p->ExceptionRecord->ExceptionCode,p->ExceptionRecord->ExceptionAddress,cases);std::fflush(stdout);ExitProcess(1);return EXCEPTION_EXECUTE_HANDLER;});
    operation=0;
    for(U v:{0u,1u,2u,63u,64u,126u,127u,128u,255u,0x7fffffffu,0x80000000u,0xfffffffeu,0xffffffffu}){leaf_value=v;check();}
    for(U i=0;i<4096;++i){leaf_value=next();check();}
    for(U count=0;count<=4;++count)for(U high:{0u,0x12345600u,0xffffff00u})for(pattern=0;pattern<4;++pattern){count_value=count|high;operation=1;check();compose_check();}
    operation=2;
    for(count_value=0;count_value<=4;++count_value)for(U row=0;row<256;++row)for(U low:{0u,1u,255u}){phase_value=(row<<8)|low;for(alignment=0;alignment<4;++alignment){check();}}
    for(count_value=1;count_value<=4;++count_value)for(alias_kind=1;alias_kind<=4;++alias_kind)for(alignment=0;alignment<4;++alignment)for(U phase:{0u,0x1234u,0x8001u,0xfeffu}){phase_value=phase;check();}
    alias_kind=alignment=0;count_value=0;for(U phase:{0x80000000u,0x7fffffffu,0xffffffffu}){phase_value=phase;check();}
    for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc)for(U d=0;d<=8;++d)for(U flags:{0u,0x25u,0x453fu}){
        precision=pc;rounding=rc;depth=d;sticky=flags;mxcsr=0x1f80|(rc<<13)|(flags&63);
        operation=0;leaf_value=0x80000001u;check();leaf_value=127;check();
        for(count_value=0;count_value<=4;++count_value){operation=1;check();operation=2;phase_value=0x8000;check();}
    }
    __asm fninit
    std::printf("audio_backend_finalize_original_x86_vs_cpp=PASS cases=%u events=%u\n",cases,events);return 0;
}
