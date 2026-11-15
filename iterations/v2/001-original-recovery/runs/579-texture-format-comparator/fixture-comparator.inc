// PE-derived evidence is checked before this fixture mutates any owner.
static const B raw_format_payload_579[]={@RAW_FORMAT_PAYLOAD@};
static const B raw_palette_payload_579[]={@RAW_PALETTE_PAYLOAD@};
static const B raw_format_pointers_579[]={@RAW_FORMAT_POINTERS@};
static const B raw_palette_pointers_579[]={@RAW_PALETTE_POINTERS@};
static const B raw_format_flags_579[]={@RAW_FORMAT_FLAGS@};
static const B raw_palette_flags_579[]={@RAW_PALETTE_FLAGS@};
static U comparator_cases_579,comparator_events_579;
static U comparator_quality5_579=1;
static U __stdcall state_set_alt_579(U key,U v);
static void transfer_setup();

static U __stdcall state_get_579(U key){
    ++state_gets;event(0x6bd984,{key});return state_value;
}
static U __stdcall state_get_alt_579(U key){
    ++state_gets;event(0x6bd985,{key});return state_value^0x10203040u;
}
static U __stdcall state_set_579(U key,U v){
    ++state_sets;event(0x6bd97c,{key,v});state_value=v;
    if((comparator_mutation&1u)&&state_sets==1)render_thrash_exports_006bd910[27]=ptr(reinterpret_cast<void*>(&state_set_alt_579));
    return state_sets==1?0x89abcdefu:0x76543210u;
}
static U __stdcall state_set_alt_579(U key,U v){
    ++state_sets;event(0x6bd97d,{key,v});state_value=v;return 0x13579bdfu;
}

static void comparator_init(){
    require(sizeof raw_format_payload_579==460&&memcmp(raw_format_payload_579,render_texture_format_preferences_005dedcc,460)==0,"raw format payload vs host");
    require(sizeof raw_palette_payload_579==200&&memcmp(raw_palette_payload_579,render_texture_palette_preferences_005defe0,200)==0,"raw palette payload vs host");
    require(sizeof raw_format_pointers_579==72&&sizeof raw_palette_pointers_579==36,"raw pointer table sizes");
    for(U i=0;i<18;++i){
        U raw_va=word(raw_format_pointers_579,i*4);U host=ptr(render_texture_format_preference_table_005def98[i]);U expected=0;
        if(i==0)expected=0x006a3a28u;
        else if(i!=10)expected=0x005dedccu+(host-ptr(render_texture_format_preferences_005dedcc));
        require(raw_va==expected,"format pointer relocation witness");
    }
    for(U i=0;i<9;++i){
        U raw_va=word(raw_palette_pointers_579,i*4);U host=ptr(render_texture_palette_preference_table_005df0a8[i]);U expected=i==0?0x006a3a38u:0x005defe0u+(host-ptr(render_texture_palette_preferences_005defe0));
        if(i==7)expected=0;
        require(raw_va==expected,"palette pointer relocation witness");
    }
    require(render_texture_format_preference_table_005def98[10]==nullptr,"format null table slot");
    require(sizeof raw_format_flags_579==360&&sizeof raw_palette_flags_579==144,"raw sparse flag table sizes");
    memcpy(packed_format_flags,raw_format_flags_579,sizeof packed_format_flags);
    memcpy(packed_palette_flags,raw_palette_flags_579,sizeof packed_palette_flags);
    for(U i=0;i<18;++i)require(word(packed_format_flags,i*20)==render_texture_format_flags_005df15c[i],"format sparse first field");
    for(U i=0;i<9;++i)require(word(packed_palette_flags,i*16)==render_texture_palette_flags_005df0cc[i],"palette sparse first field");
    require(render_texture_empty_format_006a3a28==0&&render_texture_empty_palette_006a3a38==0,"original PE BSS sentinels");
    raw_get_import=ptr(reinterpret_cast<void*>(&render_settings_get_state_006bd984));
    raw_set_import=ptr(reinterpret_cast<void*>(&render_settings_set_state_006bd97c));

    @RAW_COMPARATOR_BODIES@
    @RAW_COMPARATOR_PATCHES@
    for(B* p:{code[5],code[6]})require(FlushInstructionCache(GetCurrentProcess(),p,4096)!=0,"comparator instruction cache");
}

static void setup_comparator_579(){
    memset(&trace,0,sizeof trace);memset(&arena,0,sizeof arena);
    selector_calls=depth_calls=copy_calls=allocator_calls=0;state_gets=state_sets=0;
    state_value=0x2468ace0u;render_texture_driver_info_006a3a54=reinterpret_cast<const U*>(arena.info[0]);
    render_thrash_exports_006bd910[27]=ptr(reinterpret_cast<void*>(&state_set_579));
    render_thrash_exports_006bd910[29]=ptr(reinterpret_cast<void*>(&state_get_579));
    put(arena.info[0],0x30,ptr(arena.types[0]));put(arena.info[0],0x38,ptr(arena.palettes[0]));
    for(U i=0;i<32;++i){put(arena.types[0],i*4,i==5?comparator_quality5_579:((i%2)?1u:5u));put(arena.palettes[0],i*4,(i%2)?1u:5u);}
}

static void compare_comparator_579(U src,U srcpal,U dst,U dstpal,U mutation){
    Trace& original=expected;U result0=0,complete0=0;comparator_mutation=mutation;
    for(U side=0;side<2;++side){
        cpp_side=side!=0;setup_comparator_579();comparator_mutation=mutation;
        seed_fpu();U args[4]={src,srcpal,dst,dstpal},result=0,abi=0;void* fn=side?reinterpret_cast<void*>(&render_texture_compare_00554310):reinterpret_cast<void*>(code[5]);
        bool complete=true;__try{abi=invoke(fn,nullptr,args,4,16,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
        require(abi==0,"comparator callee-saved/stack ABI");trace.abi=abi;snapshot(trace.final);capture(trace.fpu);
        if(src==1&&srcpal==0&&dst==1&&dstpal==1)require(result==10000u&&trace.count==0,"indexed early reject sentinel/order");
        if(!side){original=trace;result0=result;complete0=complete;}
        else{require(complete==static_cast<bool>(complete0),"comparator completion");require(result==result0,"comparator return");require(memcmp(&trace,&original,sizeof trace)==0,"comparator state/events/FPU");comparator_events_579+=trace.count;}
    }
    ++comparator_cases_579;
}

static void compare_state_probe_579(U mutation){
    Trace& original=expected;U result0=0,complete0=0;comparator_mutation=mutation;
    for(U side=0;side<2;++side){
        cpp_side=side!=0;setup_comparator_579();comparator_mutation=mutation;seed_fpu();U result=0,abi=0;
        void* fn=side?reinterpret_cast<void*>(&render_texture_state_probe_00554530):reinterpret_cast<void*>(code[6]);
        bool complete=true;__try{abi=invoke(fn,nullptr,nullptr,0,0,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
        require(abi==0,"stateprobe callee-saved/stack ABI");trace.abi=abi;snapshot(trace.final);capture(trace.fpu);
        if(!side){original=trace;result0=result;complete0=complete;}
        else{require(complete==static_cast<bool>(complete0),"stateprobe completion");require(result==result0,"stateprobe first-set EAX");require(memcmp(&trace,&original,sizeof trace)==0,"stateprobe restore/callback state");comparator_events_579+=trace.count;}
    }
    ++comparator_cases_579;
}

static void compare_selector_579(U source,U palette,U mutate){
    Trace& original=expected;U result0=0,complete0=0;comparator_mutation=mutate;
    for(U side=0;side<2;++side){
        cpp_side=side!=0;transfer_setup();comparator_mutation=mutate;state_value=0x31415926u;state_gets=state_sets=0;
        render_thrash_exports_006bd910[27]=ptr(reinterpret_cast<void*>(&state_set_579));
        render_thrash_exports_006bd910[29]=ptr(reinterpret_cast<void*>(&state_get_579));
        render_texture_comparator_005df2c8=side?render_texture_compare_00554310:reinterpret_cast<decltype(render_texture_comparator_005df2c8)>(code[5]);
        for(U i=0;i<2;++i){
            put(arena.info[i],0x0c,0x40);put(arena.info[i],0x2c,3);put(arena.info[i],0x30,ptr(arena.types[i]));put(arena.info[i],0x34,3);put(arena.info[i],0x38,ptr(arena.palettes[i]));
            for(U j=0;j<3;++j){put(arena.types[i],j*4,(i==0)?source:((j==1)?2u:9u));put(arena.palettes[i],j*4,(i==0)?palette:j);}
        }
        render_texture_driver_info_006a3a54=reinterpret_cast<const U*>(arena.info[0]);
        seed_fpu();B* out=arena.storage[0];put(out,0,source);put(out,4,palette);U args[2]={ptr(out),ptr(out+4)},result=0,abi=0;void* fn=side?reinterpret_cast<void*>(&render_texture_select_00554820):reinterpret_cast<void*>(code[2]);
        bool complete=true;__try{abi=invoke(fn,nullptr,args,2,8,result);}__except(exception_record(GetExceptionInformation())){complete=false;}
        require(abi==0,"composed selector ABI");trace.abi=abi;snapshot(trace.final);capture(trace.fpu);
        if(!side){original=trace;result0=result;complete0=complete;}
        else{require(complete==static_cast<bool>(complete0),"composed selector completion");require(result==result0,"composed selector return");require(memcmp(&trace,&original,sizeof trace)==0,"composed selector state/events/FPU");comparator_events_579+=trace.count;}
    }
    ++comparator_cases_579;
}

static void comparator_run(){
    // Bounded format-only coverage, including invalid indexed transitions.
    for(U s=0;s<18;++s)for(U d=0;d<18;++d){
        U sp=(s==1||s==2||s==9)?1u:0u;U dp=(d==1||d==2||d==9)?1u:0u;
        if((s*18u+d)%7u==0||s==d)compare_comparator_579(s,sp,d,dp,(s+d)&1u);
    }
    // All bounded palette pairs for indexed formats, with score/capability flags.
    for(U s:{1u,2u,9u})for(U d:{1u,2u,9u})for(U sp=0;sp<9;++sp)for(U dp=0;dp<9;++dp)
        compare_comparator_579(s,sp,d,dp,(sp+dp)&1u);
    // Targeted cases for missing ranks, a duplicate rank pair, source bit 8,
    // the destination quality capability, and the indexed early exit.
    compare_comparator_579(17,0,0,0,0);
    compare_comparator_579(1,7,1,1,0);
    compare_comparator_579(1,0,1,1,0);
    compare_comparator_579(6,1,5,0,0);
    compare_comparator_579(0x106,1,5,0,0);
    comparator_quality5_579=0;compare_comparator_579(0,0,5,0,0);comparator_quality5_579=1;
    U* duplicate=render_texture_format_preference_table_005def98[3];U saved[5];memcpy(saved,duplicate,sizeof saved);
    duplicate[0]=6;duplicate[1]=5;duplicate[2]=6;duplicate[3]=5;duplicate[4]=0;
    compare_comparator_579(0x103,0,5,0,0);
    memcpy(duplicate,saved,sizeof saved);
    compare_comparator_579(1,0,1,1,0);
    compare_state_probe_579(0);compare_state_probe_579(1);
    compare_selector_579(1,1,0);compare_selector_579(2,2,1);
}
