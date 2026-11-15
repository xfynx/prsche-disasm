"""Use the shared 572/575 scaffold for five original transfer bodies."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent;BASE=RUN.parent/'572-startup-service-lifecycle';OLD=RUN.parent/'575-render-texture-scheduler'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'));import capstone
scope=json.loads((RUN/'scope-evidence.json').read_bytes());rows={x['va']:x for x in scope['bodies']};cfg=json.loads((OLD/'native-config.json').read_bytes())
sp=importlib.util.spec_from_file_location('native577',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(sp);sp.loader.exec_module(native)
raw=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()==cfg['original_sha256']
vas=[0x554960,0x554d70,0x554820,0x5556b0,0x555780];md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);chunks=[];patches=[];witness=[]
absolute={0x6a3a54:'&render_texture_driver_info_006a3a54',0x5df2c8:'&render_texture_comparator_005df2c8',0x6a3a40:'&render_texture_count_006a3a40',0x6a340c:'render_texture_slots_006a33f8+0x14',0x6a3400:'render_texture_slots_006a33f8+8',0x6a3404:'render_texture_slots_006a33f8+0xc',0x6a341c:'render_texture_slots_006a33f8+0x24',0x6a33f8:'render_texture_slots_006a33f8',0x6bd934:'render_thrash_exports_006bd910+9',0x5df16c:'raw_format_table'}
calls={0x554b90:'reinterpret_cast<void*>(&render_texture_node_00554b90)',0x554bd0:'reinterpret_cast<void*>(&render_texture_slot_00554bd0)',0x554b20:'reinterpret_cast<void*>(&render_texture_bytes_00554b20)',0x554ad0:'reinterpret_cast<void*>(&render_texture_header_00554ad0)',0x5350e0:'reinterpret_cast<void*>(&render_texture_depth_convert_005350e0)',0x5323e0:'reinterpret_cast<void*>(&heap_copy_dispatch_005323e0)'}
for n,va in enumerate(vas):
 row=rows[f'{va:08x}'];data=bytes.fromhex(row['raw_hex']);assert hashlib.sha256(data).hexdigest()==row['sha256'];witness.append(dict(va=f'{va:08x}',bytes=len(data),sha256=row['sha256'],token=f'@BODY_{va:08X}@'))
 chunks.append(f'const B body_{va:08x}[]={{@BODY_{va:08X}@}};code[{n}]=static_cast<B*>(VirtualAlloc(nullptr,4096,0x3000,0x40));require(code[{n}]!=nullptr,"raw code");memcpy(code[{n}],body_{va:08x},sizeof body_{va:08x});')
 for ins in md.disasm(data,va):
  pos=ins.address-va;op=ins.op_str
  if ins.mnemonic=='call' and op.startswith('0x'):
   target=int(op,16);dest=f'code[{vas.index(target)}]' if target in vas else calls[target]
   patches.append(f'require(word(code[{n}],{pos+1})==0x{int.from_bytes(ins.bytes[1:],"little"):08x},"raw call");put(code[{n}],{pos+1},ptr({dest})-ptr(code[{n}]+{pos+5}));')
  for value,dest in absolute.items():
   if not re.search(r'\b'+hex(value)+r'\b',op):continue
   needle=value.to_bytes(4,'little');assert ins.bytes.count(needle)==1;at=pos+ins.bytes.index(needle)
   patches.append(f'require(word(code[{n}],{at})==0x{value:08x},"raw data");put(code[{n}],{at},ptr({dest}));')
fixture=(BASE/'native-fixture.cpp.in').read_text(encoding='utf-8').split('static U __stdcall tset(U arg)')[0]
fixture=fixture.replace('#include "startup_lifecycle_572.hpp"','#include "startup_lifecycle_572.hpp"\n#include "render_texture_transfer_577.hpp"\n#include "texture_children_577.hpp"\n#include "render_resource_allocation_546.hpp"\n#include "texture_process_575.hpp"\n#include "porsche/render_display.hpp"\n#include "porsche/files.hpp"\n#include "porsche/process_exit.hpp"\n#include <cstdlib>')
fixture=fixture.replace('static B* code[3]','static B* code[5]').replace('nodes[32][3][32],storage[2][64]','nodes[32][3][96],storage[2][4096],info[2][128],types[2][128],palettes[2][128],pixels[4096],pal[2][1024],name[32]')
fixture=fixture.replace('static Arena arena;','static Arena arena;static B raw_format_table[280];static U selector_calls,depth_calls,copy_calls,allocator_calls;')
fixture=fixture.replace('U tag,argc,args[7];','U tag,argc,args[12];').replace('while(i<7)','while(i<12)')
fixture=fixture.replace('U globals[7],exports[43],fill_calls,nesting,service,mode;','U globals[7],exports[43],fill_calls,nesting,service,mode,driver,comparator,selector_calls,depth_calls,copy_calls,allocator_calls;')
fixture=fixture.replace('s.mode=startup_lifecycle_mode_005de6b8;','s.mode=startup_lifecycle_mode_005de6b8;s.driver=ptr(render_texture_driver_info_006a3a54);s.comparator=ptr(reinterpret_cast<const void*>(render_texture_comparator_005df2c8));s.selector_calls=selector_calls;s.depth_calls=depth_calls;s.copy_calls=copy_calls;s.allocator_calls=allocator_calls;')
def remove(text,signature):
 start=text.index(signature);at=text.index('{',start);end=at+1;depth=1
 while depth:depth+=(text[end]=='{')-(text[end]=='}');end+=1
 return text[:start]+text[end:]
fixture=remove(fixture,'void __cdecl heap_fill_0053c290(void* p,U byte,U bytes)')
fixture+=(RUN/'fixture-transfer.inc').read_text(encoding='utf-8').replace('@RAW_CHUNKS@','\n '.join(chunks)).replace('@RAW_PATCHES@','\n '.join(patches));(RUN/'native-fixture.cpp.in').write_text(fixture,encoding='utf-8',newline='\n')
cfg.update(run=577,experiment='local/experiments/v2-render-texture-transfer-577',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='render_texture_transfer_original_x86_vs_cpp=PASS',timeout_seconds=240)
cfg['sources']=[(RUN/x).relative_to(ROOT).as_posix() for x in ('render_texture_transfer_577.cpp','texture_children_577.cpp')]+cfg['sources']+['iterations/v2/001-original-recovery/runs/546-render-resource-allocation/render_resource_allocation_546.cpp','iterations/v2/001-original-recovery/runs/521-render-initialize/render_descriptor_view_521.cpp']
allocation_cfg=json.loads((RUN.parent/'546-render-resource-allocation'/'native-config.json').read_bytes())
cfg['include_dirs']=list(dict.fromkeys([RUN.relative_to(ROOT).as_posix(),*allocation_cfg['include_dirs'],*cfg['include_dirs']]))
cfg['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ('scope-evidence.json','scope-inspect.py','prepare.py','fixture-transfer.inc','child-evidence.json')]+['local/experiments/v2-frontier-469-rea/001/function-00554960.json','local/experiments/v2-frontier-469-rea/001/function-00554d70.json','local/experiments/v2-frontier-469-rea/001/receipt.json']
cfg['original_bodies']=witness
for va,size,token in [(0x5df16c,280,'@RAW_FORMAT_TABLE@'),(0x5df2c8,4,'@RAW_COMPARATOR@')]:
 data=native.pe_at(raw,va,size);cfg['original_bodies'].append(dict(va=f'{va:08x}',bytes=size,sha256=hashlib.sha256(data).hexdigest(),token=token,kind='original-data-witness'))
source=cfg['sources'][0];child=cfg['sources'][1]
edits=[('driver-before-validation',source,'if(!width||width!=height||(width&(width-1u)))return nullptr;','if(!width||width!=height||(width&(width-1u))){render_texture_driver_info_006a3a54=nullptr;return nullptr;}'),('name-before-null',source,'void* texture=render_texture_node_00554b90(name);','void* texture=render_texture_node_00554b90(name);\n    if(!texture)return nullptr;'),('driver-flags',source,'(load(info+0xcu)>>4)&4u','(load(info+0xcu)>>5)&4u'),('copy-flags',source,'(load(node+0x2cu)&0xfffffffdu)|1u','(load(node+0x2cu)&0xffffffffu)|1u'),('strict-best',child,'if (score < best)','if (score <= best)'),('selector-reload',child,'if (score < best) { best = score; selected = type; selected_palette = pal; }\n                        info = render_texture_driver_info_006a3a54;','if (score < best) { best = score; selected = type; selected_palette = pal; }\n                        info = info;'),('ratio-signed',child,'static_cast<std::int32_t>(bytes * 8u) / static_cast<std::int32_t>(render_texture_format_bits_005df16c[c])','static_cast<std::int32_t>((bytes * 8u) / render_texture_format_bits_005df16c[c])'),('nibble',child,'byte & 15u','byte & 7u')]
for name,path,a,b in edits:assert (ROOT/path).read_text(encoding='utf-8').count(a)==1,(name,a)
cfg['mutations']=[dict(name=n,source=p,old=a,new=b,expected_exit=1,failure_marker='divergence') for n,p,a,b in edits]
(RUN/'native-config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n');print('577 prepared five originals/995B, eight controls')
