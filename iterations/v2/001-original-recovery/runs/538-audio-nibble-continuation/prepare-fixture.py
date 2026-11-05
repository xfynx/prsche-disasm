"""Reuse frozen534 fixture without modifying passed inputs."""
from pathlib import Path
import json,hashlib
RUN=Path(__file__).resolve().parent
ROOT=RUN.parents[4]
OLD=RUN.parent/'534-audio-nibble-process'
s=(OLD/'native-fixture-guarded.cpp.in').read_text(encoding='utf-8')
s=s.replace('#include "audio_nibble_process_534.hpp"','#include "audio_nibble_continuation_538.hpp"')
s=s.replace('static U nib_lut[208];','static U cont_start=28,cont_end=83,cont_scratch=0;\nstatic U nib_lut[208];')
s=s.replace('Fpu fpu;};\nstruct Trace','U scratch[30];Fpu fpu;};\nstruct Trace',1)
anchor='x.args[4]=e;'
s=s.replace(anchor,anchor+'''
    // Only scratch address identity differs between relocated x86 and C++.
    // Normalize these known pointer cells; bytes are compared after full write.
    if(cont_scratch){for(U* cell:{x.args+3,reinterpret_cast<U*>(x.nibble+0x1c)})if(*cell>=cont_scratch&&*cell<=cont_scratch+112u)*cell=0xfff00000u+*cell-cont_scratch;}
''')
s=s.replace('fpu(x.fpu);','fpu(x.fpu);if(cont_scratch&&x.object[7]>=cont_scratch&&x.object[7]<=cont_scratch+112u)x.object[7]=0xfff00000u+x.object[7]-cont_scratch;')
line=next(l for l in s.splitlines() if l.startswith('I __cdecl audio_nibble_loop_continue_0059c690'))
s=s.replace(line,'')
s=s.replace('    event(1100+identity,state,read(state),read(state+12),read(state+16));++nib_calls;','''    const U decode_output=read(state+16);
    if((active_kind==84||active_kind==81)&&!(decode_output>=ptr(data)&&decode_output<ptr(data)+sizeof(data))&&!(decode_output>=ptr(arena)&&decode_output<ptr(arena)+sizeof(arena)))cont_scratch=decode_output;
    event(1100+identity,state,read(state),read(state+12),decode_output);++nib_calls;''')
s=s.replace('    if(nib_mutate&1)write(current_object+0x24,read(current_object+0x28)+28);','''    event(1150+identity,state,read(state),read(state+12),read(state+16));
    if(decode_output==cont_scratch){auto& x=actual.events[actual.count-1];std::memcpy(x.scratch+2,reinterpret_cast<void*>(decode_output),112);if(nib_backend==0)std::memcpy(x.scratch,reinterpret_cast<void*>(decode_output-8),8);}
    if((nib_mutate&1)&&nib_calls==1)write(current_object+0x30,read(current_object+0x28)+29);''')
s=s.replace('    if((nib_mutate&16)&&active_kind==82)reinterpret_cast<B*>(current_object)[0x38]=1;','''    if((nib_mutate&16)&&nib_calls==1)write(current_object+0x2c,29);
    if((nib_mutate&32)&&nib_calls==1){write(current_object+0x3c,0x3f123456);write(current_object+0x40,0xbe654321);}
''')
s=s.replace('active_kind==81?0x38','(active_kind==81||active_kind==84)?0x38')
s=s.replace('nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE','nullptr,8192,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE')
s=s.replace('    const B raw_DRAIN[]','    const B raw_CONTINUE[]={@CONTINUE@};std::memcpy(slab+0x1000,raw_CONTINUE,sizeof(raw_CONTINUE));\n    const B raw_DRAIN[]')
s=s.replace('relative(0x646,0x59c9d6,0x59c690,reinterpret_cast<void*>(&audio_nibble_loop_continue_0059c690));','relative(0x646,0x59c9d6,0x59c690,slab+0x1000);\n    relative(0x1038,0x59c6c8,0x59d5f0,slab+0x700);')
s=s.replace('slab,4096)!=0','slab,8192)!=0')
s=s.replace('nib_calls=0;\n    U nib_params','nib_calls=0;cont_scratch=0;\n    U nib_params')
s=s.replace('else if(kind==81)audio_mixer_construct_nibble_loop','else if(kind==81||kind==84)audio_mixer_construct_nibble_loop')
s=s.replace('kind==81?0x4c','(kind==81||kind==84)?0x4c')
s=s.replace('else if(kind==81){write(current_object+0x2c,nib_limit);write(current_object+0x34,nib_carry);}','else if(kind==81||kind==84){write(current_object+0x2c,cont_start);write(current_object+0x30,cont_end);write(current_object+0x34,nib_carry);}')
s=s.replace('kind==81?0x38','(kind==81||kind==84)?0x38')
s=s.replace('else if(nib_alias==7)destination=ptr(data+1532);','else if(nib_alias==7)destination=ptr(data+1532);else if(nib_alias==9)destination=current_object+0x34;')
s=s.replace('write(current_object+0x10,0);write(current_object+0x14,0);','write(current_object+0x10,0);write(current_object+0x14,0);write(current_object+0x3c,0x3e123456);write(current_object+0x40,0xbe654321);')
s=s.replace('    else if(kind==83){fn=','    else if(kind==84)fn=cpp?reinterpret_cast<void*>(&audio_nibble_loop_continue_0059c690):slab+0x1000;\n    else if(kind==83){fn=')
start=s.index('    for(U backend=0;backend<2;++backend)for(U h=0;h<256;')
end=s.index('    require(VirtualFree',start)
s=s[:start]+'''    // Direct continuation: every nibble header, aligned/partial loop starts,
    // end boundary block, carry and over-decode tails, and real534composition.
    for(U backend=0;backend<2;++backend)for(U h=0;h<256;++h)for(U begin:{0u,1u,27u,28u,29u,55u}){
        nib_backend=backend;nib_header=h;cont_start=begin;cont_end=83;nib_position=56;nib_requested=57;check(84);
        nib_position=0;nib_requested=112;check(81);
    }nib_header=0;
    for(U backend=0;backend<3;++backend)for(U carry:{0u,1u,3u,27u})for(U n:{0u,1u,2u,27u,28u,29u,56u,57u,84u,0xffffffffu,0xfffffffeu})for(U alias=0;alias<4;++alias){
        nib_backend=backend;nib_carry=carry;nib_requested=n;nib_alias=alias;cont_start=29;cont_end=83;nib_position=56;check(84);
    }nib_carry=nib_alias=0;
    nib_backend=2;cont_start=28;cont_end=84;nib_position=56;nib_requested=1;check(84);
    nib_alias=9;nib_carry=3;check(84);nib_alias=nib_carry=0;
    cont_start=0xffffffe4u;cont_end=0xffffffffu;nib_position=0xffffffe4u;nib_requested=29;check(84);
    nib_carry=0xfffffffeu;cont_start=28;cont_end=83;nib_position=56;nib_requested=1;check(84);nib_carry=0;
    nib_backend=2;cont_start=28;cont_end=83;nib_position=0;nib_requested=29;
    for(U flags=0;flags<64;++flags){nib_mutate=flags;check(84);}nib_mutate=0;
    //15*position must wrap before signed division; only one bounded decode.
    for(U pos:{0u,28u,0x10000000u,0x11111110u,0x80000000u,0xffffffe4u})for(U n:{0u,1u,27u,28u}){
        nib_position=pos;cont_start=pos;cont_end=pos+83u;nib_requested=n;check(84);
    }nib_position=56;cont_start=29;cont_end=83;nib_requested=57;
    for(U pc:{0u,2u,3u})for(U rc=0;rc<4;++rc)for(U d:{0u,1u,6u,7u})for(U backend=0;backend<2;++backend){precision=pc;rounding=rc;depth=d;nib_backend=backend;check(84);nib_position=0;check(81);nib_position=56;}precision=3;rounding=depth=0;
    for(U rc=0;rc<4;++rc)for(U z=0;z<2;++z)for(U a=0;a<2;++a){mx_round=rc;ftz=z;daz=a;nib_backend=1;nib_header=0xf1;check(84);}
'''+s[end:]
s=s.replace('audio_nibble_process_original_x86_vs_cpp=PASS','audio_nibble_continuation_original_x86_vs_cpp=PASS')
s=s.replace('stream505_501=PASS continuation=PASS','composition534=PASS continuation538=PASS scratch112=PASS')
(RUN/'native-fixture.cpp.in').write_text(s,encoding='utf-8',newline='\n')
c=json.loads((OLD/'native-config-guarded.json').read_text());c.update(run=538,experiment='local/experiments/v2-audio-nibble-continuation-538',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_nibble_continuation_original_x86_vs_cpp=PASS')
c['sources'].insert(0,(RUN/'audio_nibble_continuation_538.cpp').relative_to(ROOT).as_posix());c['include_dirs'].insert(0,RUN.relative_to(ROOT).as_posix())
c['headers']=[(RUN/'scope-evidence.json').relative_to(ROOT).as_posix()]
c['original_bodies'].append(dict(va='0059c690',bytes=505,token='@CONTINUE@',sha256='d583a51611bddc8f00520539fe09cbf1b925a47687c9bc32140a3521980c4e08'))
src=c['sources'][0]
controls=[('address-wrap','integer(position*15u)/28','integer(position)/28*15'),('drain-late','late_carry-used','carry-used'),('boundary-inclusive','late_end-late_position+1u','late_end-late_position'),('boundary-test','integer(position+27u)<integer(end)','integer(position+28u)<integer(end)'),('history-first','store(object+0x10,first)','store(object+0x10,0)'),('history-second','store(object+0x14,second)','store(object+0x14,0)'),('align-start','integer(start)/28','integer(start)/27'),('partial-remainder','if(remainder!=0)','if(false)'),('partial-source','112u-extra*4u','108u-extra*4u'),('partial-carry','store(object+0x34,late_count+1u);\n                    }','store(object+0x34,late_count);\n                    }'),('saved-output','store(object+0x1c,saved_output)','store(object+0x1c,saved_output+4u)'),('tail-output','word(object+0x1c)+remaining*4u','word(object+0x1c)'),('late-position','word(object+0x28)+28u);remaining','position+28u);remaining')]
c['mutations']=[dict(name=name,source=src,old=old,new=new,expected_exit=1,failure_marker='divergence') for name,old,new in controls]
(RUN/'native-config.json').write_text(json.dumps(c,indent=2)+'\n',encoding='utf-8',newline='\n')
print('fixture and config prepared')
