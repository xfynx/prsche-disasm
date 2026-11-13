"""Extend the shared 572 fixture with a five-body original-x86 texture oracle."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent;BASE=RUN.parent/'572-startup-service-lifecycle'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'));import capstone
scope=json.loads((RUN/'scope-evidence.json').read_bytes());rows={x['va']:x for x in scope['bodies']};cfg=json.loads((BASE/'native-config.json').read_bytes())
sp=importlib.util.spec_from_file_location('native575',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(sp);sp.loader.exec_module(native)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()==cfg['original_sha256']
vas=[0x5550e0,0x5552a0,0x554f60,0x555040,0x5554b0,0x555440];sizes={v:rows[f'{v:08x}']['bytes'] for v in vas[:-1]};sizes[0x555440]=76
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
data_map={0x6a3a44:'&render_texture_slot_count_006a3a44',0x6a3a48:'&render_texture_dirty_006a3a48',0x6a3a58:'&render_texture_pending_006a3a58',0x6a3a50:'&render_texture_notify_callback_006a3a50',0x6a341c:'render_texture_slots_006a33f8+0x24',0x6a3410:'render_texture_slots_006a33f8+0x18',0x6a3408:'render_texture_slots_006a33f8+0x10',0x6a3400:'render_texture_slots_006a33f8+8',0x6a3404:'render_texture_slots_006a33f8+0xc',0x6a33fc:'render_texture_slots_006a33f8+4',0x6a3420:'render_texture_slots_006a33f8+0x28',0x6a3424:'render_texture_slots_006a33f8+0x2c',0x6bd968:'render_thrash_exports_006bd910+22',0x6bd940:'render_thrash_exports_006bd910+12',0x6bd954:'render_thrash_exports_006bd910+17',0x5deb74:'&shared_runtime_word_005deb74',0x5deb78:'&shared_runtime_word_005deb78',0x5debf0:'&diagnostic_handler_005debf0',0x5bc294:'render_texture_cleanup_file_005bc294',0x5bc2ec:'original_messages',0x5bc33c:'original_messages+80'}
chunks=[];patches=[];witness=[]
for n,va in enumerate(vas):
 data=native.pe_at(raw,va,sizes[va]);sha=hashlib.sha256(data).hexdigest();witness.append(dict(va=f'{va:08x}',bytes=len(data),sha256=sha,token=f'@BODY_{va:08X}@'))
 if va in [int(x,16) for x in rows]:assert rows[f'{va:08x}']['sha256']==sha
 chunks.append(f'const B body_{va:08x}[]={{@BODY_{va:08X}@}};code[{n}]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[{n}]!=nullptr,"raw code");memcpy(code[{n}],body_{va:08x},sizeof body_{va:08x});')
 for ins in md.disasm(data,va):
  pos=ins.address-va;op=ins.op_str
  if ins.mnemonic=='call' and op.startswith('0x'):
   target=int(op,16);assert target in vas,(hex(va),hex(target));dest=vas.index(target)
   patches.append(f'require(word(code[{n}],{pos+1})==0x{int.from_bytes(ins.bytes[1:],"little"):08x},"raw call");put(code[{n}],{pos+1},ptr(code[{dest}])-ptr(code[{n}]+{pos+5}));')
  for value,dest in data_map.items():
   if not re.search(r'\b'+hex(value)+r'\b',op):continue
   needle=value.to_bytes(4,'little');assert ins.bytes.count(needle)==1;at=pos+ins.bytes.index(needle)
   patches.append(f'require(word(code[{n}],{at})==0x{value:08x},"raw data");put(code[{n}],{at},ptr({dest}));')
fixture=(BASE/'native-fixture.cpp.in').read_text(encoding='utf-8').split('static U __stdcall tset(U arg)')[0]
fixture=fixture.replace('#include "startup_lifecycle_572.hpp"','#include "startup_lifecycle_572.hpp"\n#include "render_texture_scheduler_575.hpp"\n#include "texture_process_575.hpp"\n#include "porsche/files.hpp"\n#include "porsche/render_display.hpp"\n#include "porsche/shared_runtime_globals.hpp"\n#include <cstdarg>')
fixture=fixture.replace('static B* code[3]','static B* code[6]').replace('nodes[32][3][32]','nodes[32][3][96]')
fixture=fixture.replace('U globals[7],exports[43],fill_calls,nesting,service,mode;','U globals[7],exports[43],fill_calls,nesting,service,mode,notify,diagfile,diagline;')
fixture=fixture.replace('U tag,argc,args[7];','U tag,argc,args[12];').replace('while(i<7)','while(i<12)')
fixture=fixture.replace('s.mode=startup_lifecycle_mode_005de6b8;','s.mode=startup_lifecycle_mode_005de6b8;s.notify=ptr(reinterpret_cast<void*>(render_texture_notify_callback_006a3a50));s.diagfile=shared_runtime_word_005deb74;s.diagline=shared_runtime_word_005deb78;')
fixture+=(RUN/'fixture-scheduler.inc').read_text(encoding='utf-8').replace('@RAW_CHUNKS@','\n '.join(chunks)).replace('@RAW_PATCHES@','\n '.join(patches))
(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
cfg.update(run=575,experiment='local/experiments/v2-render-texture-scheduler-575',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='render_texture_scheduler_original_x86_vs_cpp=PASS',timeout_seconds=240)
cfg['sources']=[(RUN/x).relative_to(ROOT).as_posix() for x in ('render_texture_scheduler_575.cpp','texture_process_575.cpp')]+cfg['sources']+['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp']
cfg['include_dirs'].insert(0,RUN.relative_to(ROOT).as_posix());cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ('scope-evidence.json','scope-inspect.py','prepare.py','fixture-scheduler.inc','texture-process-evidence.json','message-ownership.json','message-ownership.py')]+['local/experiments/v2-frontier-469-rea/001/function-005550e0.json','local/experiments/v2-frontier-469-rea/001/receipt.json']
cfg['original_bodies']=witness
for va,size,token in [(0x5bc294,30,'@FILE_005BC294@'),(0x5bc2ec,120,'@MESSAGES_005BC2EC@')]:
 data=native.pe_at(raw,va,size);cfg['original_bodies'].append(dict(va=f'{va:08x}',bytes=size,sha256=hashlib.sha256(data).hexdigest(),token=token,kind='original-data-witness'))
source=cfg['sources'][0];pair=cfg['sources'][1]
edits=[('dirty-gate',source,'if(render_texture_dirty_006a3a48!=0)return -1;','if(render_texture_dirty_006a3a48==0)return -1;'),('slot-score',source,'slot(index)+0x18u','slot(index)+0x1cu'),('score-gate',source,'score>static_cast<I>(rounds)','score>=static_cast<I>(rounds)'),('advance',source,'current[index]=load(node);','current[index]=0;'),('create-args',source,'(width,width,a,b,flags)','(width,a,a,b,flags)'),('captured-flags',source,'captured|2u','load(node+0x2cu)|2u'),('pair-high-flags',pair,'write(object+8,0);\n            write(object+0x0c,0);\n            write(object+0x2c,flags&0xfffffffdu);','write(object+8,0);\n            write(object+0x0c,0);\n            write(object+0x2c,flags&0x000000fdu);'),('pair-palette',pair,'(flags&8u)?read(object+0x1c):0','0'),('descriptor-value',pair,'d.texture_value=read(texture+0x24);','d.texture_value=read(texture+0x20);'),('callback-slot-reload',pair,'render_texture_notify_00555040(texture,reinterpret_cast<void*>(read(record+0x2c)));\n        record=slot(read(object+4));','render_texture_notify_00555040(texture,reinterpret_cast<void*>(read(record+0x2c)));')]
for name,path,a,b in edits:assert (ROOT/path).read_text(encoding='utf-8').count(a)==1,(name,a)
cfg['mutations']=[dict(name=n,source=p,old=a,new=b,expected_exit=1,failure_marker='divergence') for n,p,a,b in edits]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('575 prepared five original bodies/1111B, ten controls')
