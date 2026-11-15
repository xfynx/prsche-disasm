"""Static Run581 scope census against the immutable original and Run578 closure."""
from pathlib import Path
import hashlib, importlib.util, json, re, struct, sys

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader

spec=importlib.util.spec_from_file_location('native',ROOT/'scripts/research/verify-v2-native-batch.py')
native=importlib.util.module_from_spec(spec); spec.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
md=Cs(CS_ARCH_X86,CS_MODE_32)
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
build_path=ROOT/'iterations/v2/001-original-recovery/runs/578-texture-transfer-integration/build-001.json'
build=json.loads(build_path.read_bytes()); cfg=json.loads(build_path.with_name('build-config.json').read_bytes())
_,pins=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/p for p in cfg['source_include_dirs'])
closure=dep.source_hashes(build['compiled_source_roots'])
index=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
functions={x['entry_va']:x for x in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
refs=list(map(json.loads,(index/'references.jsonl').read_text().splitlines()))
calls=list(map(json.loads,(index/'calls.jsonl').read_text().splitlines()))
raw=(ROOT/'local/game/Porsche.exe').read_bytes()
assert hashlib.sha256(raw).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json'
registry=json.loads(registry_path.read_bytes())

targets={'00538af0':41,'00537850':21,'005405c0':48,'00540550':49,'00540590':41,
         '00540480':17,'005404e0':17,'00540500':None,'00516950':1}
details={}
for va,size in targets.items():
    row=functions.get(va)
    if size is None: size=row['body_bytes'] if row else None
    if size is None: continue
    body=native.pe_at(raw,int(va,16),size)
    ins=list(md.disasm(body,int(va,16)))
    details[va]={'body_bytes':size,'sha256':hashlib.sha256(body).hexdigest(),'raw_hex':body.hex(),
      'index_status':'indexed' if row else 'unindexed; local supplement from raw PE',
      'indexed_range':row.get('ranges') if row else None,
      'instructions':[{'va':f'{x.address:08x}','bytes':x.bytes.hex(),'mnemonic':x.mnemonic,'operands':x.op_str} for x in ins],
      'returns':[{'va':f'{x.address:08x}','bytes':x.bytes.hex()} for x in ins if x.mnemonic=='ret']}
    for ret in details[va]['returns']:
        i=next(x for x in ins if f'{x.address:08x}'==ret['va'])
        ret['cleanup_bytes']=int(i.op_str,0) if i.op_str else 0

adjacent_details={}
for va in ('00537890','00540660'):
    row=functions[va]; size=row['body_bytes']; body=native.pe_at(raw,int(va,16),size)
    ins=list(md.disasm(body,int(va,16)))
    adjacent_details[va]={'body_bytes':size,'ranges':row['ranges'],'sha256':hashlib.sha256(body).hexdigest(),
      'raw_hex':body.hex(),'instructions':[{'va':f'{x.address:08x}','bytes':x.bytes.hex(),
        'mnemonic':x.mnemonic,'operands':x.op_str} for x in ins],
      'returns':[{'va':f'{x.address:08x}','cleanup_bytes':int(x.op_str,0) if x.op_str else 0}
        for x in ins if x.mnemonic=='ret'],
      'disposition':'adjacent data consumer retained for follow-up; not implemented in Run581'}

def pe_map(va,size):
    pe=struct.unpack_from('<I',raw,0x3c)[0]; base=struct.unpack_from('<I',raw,pe+52)[0]
    nsec=struct.unpack_from('<H',raw,pe+6)[0]; opt=struct.unpack_from('<H',raw,pe+20)[0]
    rva=int(va,16)-base
    for i in range(nsec):
        at=pe+24+opt+i*40; vs,srva,rs,ro=struct.unpack_from('<IIII',raw,at+8)
        if srva<=rva and rva+size<=srva+max(vs,rs):
            rel=rva-srva
            return {'section':raw[at:at+8].rstrip(b'\0').decode(errors='replace'),
              'file_offset':ro+rel,'raw_hex':raw[ro+rel:ro+rel+size].hex(),
              'loader_zero':rel>=rs or rel+size>rs}
    return {'unmapped':True}

# Walk the PE base-relocation table and retain exact callback-slot relocation evidence.
pe=struct.unpack_from('<I',raw,0x3c)[0]; opt=pe+24; magic=struct.unpack_from('<H',raw,opt)[0]
dd=opt+(96 if magic==0x10b else 112); rel_rva,rel_size=struct.unpack_from('<II',raw,dd+40)
image_base=struct.unpack_from('<I',raw,opt+28)[0]; nsec=struct.unpack_from('<H',raw,pe+6)[0]; optsz=struct.unpack_from('<H',raw,pe+20)[0]
def rva_offset(rva):
    for si in range(nsec):
        at=pe+24+optsz+si*40; vs,srva,rs,ro=struct.unpack_from('<IIII',raw,at+8)
        if srva<=rva<srva+max(vs,rs):return ro+rva-srva
    return None
relocs=[]; cursor=rva_offset(rel_rva)
if cursor is not None:
    end=cursor+rel_size
    while cursor+8<=end:
        page,block=struct.unpack_from('<II',raw,cursor)
        if block<8 or cursor+block>end:break
        for q in range(cursor+8,cursor+block,2):
            ent=struct.unpack_from('<H',raw,q)[0]; kind,off=ent>>12,ent&0xfff
            if kind:relocs.append({'va':f'{image_base+page+off:08x}','type':kind})
        cursor+=block
relocmap={x['va']:x['type'] for x in relocs}

pair_span=('005ded30','005ded60'); callback_span=('005ded60','005ded78')
pair=pe_map(pair_span[0],int(pair_span[1],16)-int(pair_span[0],16))
table=pe_map(callback_span[0],int(callback_span[1],16)-int(callback_span[0],16))
pair_words=[f'{x:08x}' for x in struct.unpack('<12I',bytes.fromhex(pair['raw_hex']))]
table_values=struct.unpack('<6I',bytes.fromhex(table['raw_hex']))
callback_slots=[]
for i,value in enumerate(table_values):
    va=f'{int(callback_span[0],16)+i*4:08x}'
    callback_slots.append({'slot':va,'raw_target':f'{value:08x}','relocation_type':relocmap.get(va),
      'target_function_indexed':f'{value:08x}' in functions,
      'target_body_sha256':details.get(f'{value:08x}',{}).get('sha256')})

data_refs=[x for x in refs if re.fullmatch(r'[0-9a-fA-F]{8}',x.get('to_va','')) and
  int('005ded30',16)<=int(x['to_va'],16)<int('005ded78',16)]
related_calls=[x for x in calls if x.get('from_function') in targets or x.get('to_function') in targets]
source_hits=[]; address_pattern=re.compile(r'(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])')
for name in closure:
    if Path(name).suffix not in ('.cpp','.hpp','.h','.inc'):continue
    for no,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
        if any(int('005ded30',16)<=int(v,16)<int('005ded78',16) for v in address_pattern.findall(line)):
            source_hits.append({'file':name,'line':no,'text':line.strip()})
registry_hits=[]
for f in registry['functions']:
    if f.get('module')!='Porsche.exe' or 'entry_va' not in f:continue
    ranges=functions.get(f['entry_va'],{}).get('ranges',[[f['entry_va'],f['entry_va']]])
    for target_va,size in targets.items():
        if size is None or target_va not in details:continue
        tr=details[target_va].get('indexed_range') or [[target_va,f'{int(target_va,16)+size-1:08x}']]
        if any(int(a,16)<=int(y,16) and int(b,16)>=int(x,16) for a,b in ranges for x,y in tr):
            registry_hits.append({'target':target_va,'owner':f['entry_va'],'status':f.get('status')})
state_function_overlaps=[]
for f in registry['functions']:
    if f.get('module')!='Porsche.exe' or 'entry_va' not in f: continue
    ranges=functions.get(f['entry_va'],{}).get('ranges',[[f['entry_va'],f['entry_va']]])
    if any(int(a,16)<int(pair_span[1],16) and int(b,16)>=int(pair_span[0],16)
      for a,b in ranges): state_function_overlaps.append({'entry':f['entry_va'],'status':f.get('status')})

evidence={'scope':'Run581 static scope only; no implementation/acceptance claim',
 'provenance':{'original':'local/game/Porsche.exe','module_sha256':hashlib.sha256(raw).hexdigest(),
  'build578':build_path.relative_to(ROOT).as_posix(),'build578_sha256':sha(build_path),
  'registry_sha256':sha(registry_path),'effective_pins':len(pins),'compiled_roots':len(build['compiled_source_roots']),
  'transitive_source_closure_files':len(closure),'index':'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'},
 'bodies':details,'canonical_data':{'pair_span':pair_span,'pair_raw':pair,'pair_words':pair_words,
  'callback_span':callback_span,'callback_raw':table,'callback_slots':callback_slots,
  'pair_pointer_table_relocation_count':sum(relocmap.get(x['slot'])==3 for x in callback_slots),
  'references_into_candidate_span':data_refs,'candidate_state_span_function_overlaps':state_function_overlaps},
 'adjacent_data_consumers':adjacent_details,
 'related_calls':related_calls,'existing_source_closure_hits':source_hits,
 'registry_body_overlaps':registry_hits,
 'new_target_registry_collisions':[x for x in registry_hits if x['target'] in ('00538af0','00537850','005405c0','00540550','00540590')],
 'reused_target_owners':[{'va':va,'status':next((f['status'] for f in registry['functions'] if f.get('entry_va')==va),None)}
   for va in ('00540480','005404e0','00516950')]}
(RUN/'scope-evidence.json').write_text(json.dumps(evidence,indent=2)+'\n',encoding='utf-8',newline='\n')

# Explicit supplemental records for the two code bodies absent from the checked-in index.
supplement_targets=['00540550','00540590']
supplement={}
for va in supplement_targets:
    x=details[va]; ins=x['instructions']; start=int(va,16); end=start+x['body_bytes']
    supplement[va]={'status':'absent from indexed function records; exact raw body bounded from PE and independently decoded',
      'start_va':va,'end_va_exclusive':f'{end:08x}','last_byte_va':f'{end-1:08x}',
      'raw_bytes':x['body_bytes'],'raw_sha256':x['sha256'],'raw_hex':x['raw_hex'],'section':'PE .text',
      'instructions':ins,'conditional_edges':[{'from':i['va'],'target':i['operands'].split()[-1]}
        for i in ins if i['mnemonic'].startswith('j') and i['mnemonic'] not in ('jmp',)],
      'ret_sites':[{'va':r['va'],'cleanup_bytes':int(next(i['operands'] for i in ins if i['va']==r['va']),0)
        if next(i['operands'] for i in ins if i['va']==r['va']) else 0} for r in x['returns']]}
supplement['provenance']={'module_sha256':hashlib.sha256(raw).hexdigest(),
  'index':'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d','analysis':'raw PE bytes via verified PE VA mapping; Capstone x86-32 decode'}
supplement['callback_table']={'va':'005ded60','raw_hex':table['raw_hex'],'sha256':hashlib.sha256(bytes.fromhex(table['raw_hex'])).hexdigest(),
  'relocations':callback_slots}
(RUN/'original-index-supplement.json').write_text(json.dumps(supplement,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps({'roots':len(build['compiled_source_roots']),'closure':len(closure),'pins':len(pins),
 'function_bytes':{k:v['body_bytes'] for k,v in details.items()},'registry_overlaps':registry_hits,
 'pair_words':pair_words,'callback_slots':[(x['slot'],x['raw_target'],x['relocation_type']) for x in callback_slots],
 'source_hits':source_hits}))
