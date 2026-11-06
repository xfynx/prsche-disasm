"""Prepare one shared native packet using immutable543/540 transport helpers."""
import hashlib,importlib.util,json,struct
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
rel=lambda p:p.relative_to(ROOT).as_posix()
load=lambda p:json.loads(p.read_bytes())
sha=lambda b:hashlib.sha256(b).hexdigest()
scope=load(ROOT/'local/reports/resource-next-546-evidence.json')
spec=importlib.util.spec_from_file_location('native546',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
pe=(ROOT/'local/game/Porsche.exe').read_bytes();assert sha(pe)==scope['original_sha256']
targets=[(0x553fc0,134),(0x554b50,64),(0x554b20,44),(0x554b90,59),(0x554ad0,79),(0x554bd0,228),(0x555330,81),(0x555390,100),(0x555400,64),(0x556880,79)]
bodies=[]
for va,size in targets:
 raw=native.pe_at(pe,va,size);bodies.append(dict(va=f'{va:08x}',bytes=size,sha256=sha(raw),token=f'@BODY_{va:08X}@',raw_hex=raw.hex()))
scope['admitted_raw_bodies']=bodies
scope['data_ownership']='6 original bodies608B;207B data=preferred4+sentinel4+format56+heapname5+capacitymessage138;raw format/jump transport separate from sparse production ownership'
scope['native_composition']='six originals plus actual543 reset/release and canonical521 format;569a70 is a controlled typed boundary pending root export regression'
(RUN/'scope-evidence.json').write_text(json.dumps(scope,indent=2)+'\n',encoding='utf8',newline='\n')
text=(RUN/'fixture-body.inc').read_text(encoding='utf8')
near=(RUN.parent/'543-render-slot-reset/native-fixture.cpp.in').read_text(encoding='utf8')
text=text.replace('@ABI_X87_HELPERS@',near[near.index('static void capture(Fpu& f)'):near.index('static int exception_record')])
text=text.replace('@RELOCATORS@',near[near.index('static void absolute(B*'):near.index('static void init()')])
rows=[]
for i,b in enumerate(bodies):
 rows.append(f'static const B body{i}[]={{'+b['token']+'};')
 rows.append(f'code[{i}]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[{i}]!=nullptr,"code allocation");memcpy(code[{i}],body{i},{b["bytes"]});')
text=text.replace('@RAW_BODIES@','\n    '.join(rows))
for token,va,size in [('FORMAT_DATA',0x5df16c,280),('JUMP_DATA',0x5568d0,52),('HEAP_NAME',0x5bbfdc,5),('CAPACITY_MESSAGE',0x5bc208,138)]:
 text=text.replace('@'+token+'@',','.join(f'0x{x:02x}' for x in native.pe_at(pe,va,size)))
calls={va:f'code[{i}]' for i,(va,_) in enumerate(targets)}
calls.update({0x53c290:'reinterpret_cast<void*>(&heap_fill_0053c290)',0x5699f0:'reinterpret_cast<void*>(&application_heap_destroy_005699f0)',0x569a70:'reinterpret_cast<void*>(&application_heap_slot_00569a70)',0x5697f0:'reinterpret_cast<void*>(&heap_init_005697f0)',0x531ca0:'reinterpret_cast<void*>(&allocate_00531ca0)',0x55ec50:'reinterpret_cast<void*>(&render_texture_diagnostic_0055ec50)',0x5a246e:'reinterpret_cast<void*>(&process_exit_005a246e)'})
absolute={0x6a3a5c:'&render_texture_arena_006a3a5c',0x6a3a60:'&render_texture_heap_id_006a3a60',0x6a3a44:'&render_texture_slot_count_006a3a44',0x6a3a48:'&render_texture_dirty_006a3a48',0x6a3a58:'&render_texture_pending_006a3a58',0x6a3a64:'&render_texture_epoch_006a3a64',0x6a3a40:'&render_texture_count_006a3a40',0x5df2c4:'&render_texture_preferred_bytes_005df2c4',0x5b2144:'&alloc_target',0x5b2148:'&free_target',0x5bbfdc:'render_texture_heap_name_005bbfdc',0x5bc208:'render_texture_capacity_message_005bc208',0x6bd988:'render_thrash_exports_006bd910+30',0x5df16c:'raw_table',0x5568d0:'raw_jump'}
for va in [0x6a33f8,0x6a33fc,0x6a3400,0x6a3404,0x6a3408,0x6a340c,0x6a3420,0x6a3a04]:absolute[va]=f'raw_slots+{va-0x6a33f8}'
relocs=[];decoder=Cs(CS_ARCH_X86,CS_MODE_32)
for i,b in enumerate(bodies):
 raw=bytes.fromhex(b['raw_hex']);va=int(b['va'],16);size=b['bytes']
 for old,new in absolute.items():
  count=raw.count(struct.pack('<I',old))
  if count:relocs.append(f'absolute(code[{i}],{size},0x{old:x},{new},{count});')
 counts={}
 for ins in decoder.disasm(raw,va):
  if ins.mnemonic=='call' and ins.op_str.startswith('0x'):
   target=int(ins.op_str,16);assert target in calls,(hex(va),hex(target));counts[target]=counts.get(target,0)+1
 for target,count in counts.items():relocs.append(f'relative(code[{i}],{size},0x{va:x},0x{target:x},{calls[target]},{count});')
text=text.replace('@BODY_RELOCATIONS@','\n    '.join(relocs))
(RUN/'native-fixture.cpp.in').write_text(text,encoding='utf8',newline='\n')
source=rel(RUN/'render_resource_allocation_546.cpp');production=(ROOT/source).read_text(encoding='utf8')
controls=[
('reserve-zero','if(!bytes){render_texture_preferred_bytes_005df2c4=0xc00000;return 0;}','if(!bytes){return 0;}'),
('reserve-reset','if(render_texture_arena_006a3a5c)render_texture_reset_00555390();','if(!render_texture_arena_006a3a5c)render_texture_reset_00555390();'),
('reserve-api-mode','platform_virtual_alloc(nullptr,bytes,0x1000,4)','platform_virtual_alloc(nullptr,bytes,0x3000,4)'),
('reserve-null-store','render_texture_arena_006a3a5c=reinterpret_cast<U>(arena);','if(arena)render_texture_arena_006a3a5c=reinterpret_cast<U>(arena);'),
('reserve-success','    return 1;','    return 0;'),
('reserve-ignore-init','    return 1;','    return render_texture_heap_id_006a3a60?0:1;'),
('reserve-capacity-before-id','const U id=application_heap_slot_00569a70();\n    const U size=render_texture_preferred_bytes_005df2c4;','const U size=render_texture_preferred_bytes_005df2c4;\n    const U id=application_heap_slot_00569a70();'),
('reserve-arena-before-id','const U id=application_heap_slot_00569a70();\n    const U size=render_texture_preferred_bytes_005df2c4;\n    arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);','arena=reinterpret_cast<void*>(render_texture_arena_006a3a5c);\n    const U id=application_heap_slot_00569a70();\n    const U size=render_texture_preferred_bytes_005df2c4;'),
('reserve-id-after-init','render_texture_heap_id_006a3a60=id;\n    (void)heap_init_005697f0','(void)heap_init_005697f0'),
('lazy-default','if(!bytes)bytes=0xc00000;','if(!bytes)bytes=0x80000;'),
('lazy-threshold','static_cast<S>(bytes)>0x80000','static_cast<S>(bytes)>=0x80000'),
('lazy-decrement','bytes-=0x40000','bytes-=0x80000'),
('lazy-final','render_texture_preferred_bytes_005df2c4=bytes;\n    return result;','render_texture_preferred_bytes_005df2c4=0xc00000;\n    return result;'),
('bytes-size','allocate_00531ca0(name,static_cast<S>(bytes),render_texture_heap_id_006a3a60)','allocate_00531ca0(name,static_cast<S>(bytes+1),render_texture_heap_id_006a3a60)'),
('node-id','render_texture_heap_id_006a3a60|0x10','render_texture_heap_id_006a3a60'),
('node-null-fill','heap_fill_0053c290(result,0,56);','if(result)heap_fill_0053c290(result,0,56);'),
('node-fill-size','heap_fill_0053c290(result,0,56);','heap_fill_0053c290(result,0,48);'),
('header-mask','(old_flags&0xa000)|(flags<<28)','(old_flags&0x8000)|(flags<<28)'),
('header-zero','put16(output,8,0);put16(output,0xa,0);','put16(output,8,1);put16(output,0xa,0);'),
('header-format','render_descriptor_format_00556880(format)&0xff','format&0xff'),
('slot-last','flags)found=index;','flags){found=index;break;}'),
('slot-full-flags','o+4)==flags','o+4)==(flags&0xff)'),
('slot-sentinel','index==32?render_texture_width_sentinel_006a3a08:','index==32?0:'),
('slot-signed-width','static_cast<S>(width_at(0))>0','width_at(0)>0'),
('slot-count','++render_texture_slot_count_006a3a44;','--render_texture_slot_count_006a3a44;'),
('slot-bits','render_texture_format_bits_005df16c[formatA]*width*width','render_texture_format_bits_005df16c[formatA]*width'),
('slot-division','static_cast<U>(static_cast<S>(value)/static_cast<S>(divisor))','value/divisor'),
('slot-levels','U levels=flags&0xff,total=size;','U levels=0,total=size;'),
('capacity-exit','process_exit_005a246e(0xffffffff)','process_exit_005a246e(0)'),
('capacity-channel','render_texture_diagnostic_0055ec50(6,','render_texture_diagnostic_0055ec50(5,'),
]
mutations=[]
for name,old,new in controls:
 assert production.count(old)==1,(name,production.count(old));mutations.append(dict(name=name,source=source,old=old,new=new,expected_exit=1,failure_marker='divergence'))
cfg=load(RUN.parent/'540-render-texture-cleanup-reader/native-config.json')
cfg.update(run=546,experiment='local/experiments/v2-render-resource-allocation-546',sources=[source,rel(RUN.parent/'543-render-slot-reset/render_slot_reset_543.cpp'),rel(RUN.parent/'521-render-initialize/render_descriptor_view_521.cpp')],fixture=rel(RUN/'native-fixture.cpp.in'),headers=[rel(RUN/'render_resource_allocation_546.hpp'),rel(RUN/'scope-evidence.json')],original_bodies=[{k:v for k,v in b.items() if k!='raw_hex'} for b in bodies],pass_marker='render_resource_allocation_original_x86_vs_cpp=PASS',timeout_seconds=240,mutations=mutations)
cfg['include_dirs']=[rel(RUN),rel(RUN.parent/'543-render-slot-reset'),*cfg['include_dirs']]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf8',newline='\n')
print(f'prepared546:6new/608B,543+521 reuse,10rawbodies,{len(mutations)}controls')
