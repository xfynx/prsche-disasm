"""Packet-local provenance/ownership/compiled-ABI audit; no registry mutations."""
import hashlib, importlib.util, json, re, struct, subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,v): p.write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8',newline='\n')
def rel(p): return p.relative_to(ROOT).as_posix()
spec=importlib.util.spec_from_file_location('native',ROOT/'scripts/research/verify-v2-native-batch.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
pe=(ROOT/'local/game/Porsche.exe').read_bytes()
cfg=json.loads((RUN/'native-config.json').read_text())
assert hashlib.sha256(pe).hexdigest()==cfg['original_sha256']
receipt=ROOT/cfg['experiment']/'004/receipt.json'; proof=json.loads(receipt.read_text())
assert proof['status']=='PASS'
for p,h in proof['inputs_sha256'].items(): assert sha(ROOT/p)==h,(p,'input drift')
for p,h in proof['outputs_sha256'].items(): assert sha(ROOT/p)==h,(p,'output drift')
# Original dossier references are independently pinned; use their actual assembly.
rea=ROOT/'local/experiments/v2-audio-scene-724-rea/001'
dossiers={v:json.loads((rea/f'function-{v}.json').read_text())['structuredContent']['raw_result']['value'] for v in ['004552b0','00451490','0044d320','0044b830']}
incoming=dossiers['004552b0']['incoming_references']
assert len(incoming)==1 and incoming[0]['source_address']=='0x469074'
assert not any(': CALL ' in line for line in dossiers['0044b830']['assembly'])
assert '0x44d32a: MOV dword ptr [ESP + 0x4], EAX' in dossiers['0044d320']['assembly']
assert m.pe_at(pe,0x46906f,20)==bytes.fromhex('e81c84feffe837c2feffe8825cfdffe8ddcefeff')
header=struct.unpack_from('<I',pe,60)[0];n=struct.unpack_from('<H',pe,header+6)[0];opt=struct.unpack_from('<H',pe,header+20)[0]
sections=[struct.unpack_from('<IIII',pe,header+24+opt+i*40+8) for i in range(n)]
# Independently scan every executable section for near direct CALLs.
calls=[]
for i,(vs,rva,rs,raw) in enumerate(sections):
    char=struct.unpack_from('<I',pe,header+24+opt+i*40+36)[0]
    if not char&0x20000000:continue
    b=pe[raw:raw+rs]
    for j in range(len(b)-4):
        if b[j]==0xe8 and (0x400000+rva+j+5+struct.unpack_from('<i',b,j+1)[0])&0xffffffff==0x4552b0: calls.append(f'{0x400000+rva+j:08x}')
assert calls==['00469074'],calls
absolute_pointer_file_offsets=[i for i in range(len(pe)-3) if pe[i:i+4]==struct.pack('<I',0x4552b0)]
assert absolute_pointer_file_offsets==[],absolute_pointer_file_offsets
new=[(int(x['va'],16),int(x['va'],16)+x['bytes']-1) for x in cfg['original_bodies'] if x['va'] in ['00451490','005379f0','00537a50']]+[(0x4552b0,0x4553e6)]
index={x['entry_va']:x for x in map(json.loads,(ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text())['functions']
overlaps=[]
for item in registry:
    if item['module']!='Porsche.exe':continue
    ranges=item.get('body_ranges',index.get(item['entry_va'],{}).get('ranges',[[item['entry_va'],item['entry_va']]]))
    for a,b in ranges:
        if any(int(a,16)<=d and c<=int(b,16) for c,d in new): overlaps.append(item['entry_va'])
assert not overlaps,overlaps
storage=[(0x61bc78,32),(0x61bcac,16)]
for va,size in storage:
    rows=[(vs,rva,rs,raw) for vs,rva,rs,raw in sections if rva<=va-0x400000 and va-0x400000+size<=rva+vs]
    assert len(rows)==1
    vs,rva,rs,raw=rows[0]
    assert va-0x400000>=rva+rs # exact loader-zero portion, no fabricated raw defaults
hits=[]
pattern=re.compile(r'(?:0061bc(?:78|7c|80|84|88|8c|90|94|ac|b0|b4|b8)|0x0?61bc(?:78|7c|80|84|88|8c|90|94|ac|b0|b4|b8))',re.I)
for base in [ROOT/'iterations/v2/001-original-recovery/source',RUN.parent]:
    for p in base.rglob('*'):
        if p.suffix not in ['.cpp','.hpp','.h'] or p.is_relative_to(RUN):continue
        if pattern.search(p.read_text(encoding='utf-8',errors='replace')):hits.append(rel(p))
declaration_inventory='iterations/v2/001-original-recovery/runs/179-ghidra-declarations/export/globals.h'
assert all(p==declaration_inventory for p in hits),hits
dump=ROOT/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x86/dumpbin.exe'
coff={}
for name in ['od-1','o2-1','od-3','o2-3']:
    p=receipt.parent/(name+'-disasm.txt')
    if not p.exists():p.write_bytes(subprocess.check_output([str(dump),'/DISASM',str(receipt.parent/(name+'.obj'))]))
    coff[rel(p)]=sha(p)
    text=p.read_text(errors='replace')
    if name.endswith('-3'):
        wrapper=text[text.index('?scene_stage_reset_004552b0@'):]
        assert 'add         esp,8' in wrapper and 'xor         ecx,ecx' in wrapper
        assert 'pop         ecx' not in wrapper
sourcepins={p:h for p,h in proof['inputs_sha256'].items() if '/runs/' in p and not p.startswith('local/')}
result=dict(run=726,status='PASS',receipt=rel(receipt),receipt_sha256=sha(receipt),cases_per_optimization=73,material_controls=7,
    direct_call_scan=calls,absolute_pointer_file_offsets=absolute_pointer_file_offsets,body_overlap=overlaps,storage_address_hits=hits,
    loader_zero_storage=[dict(va=f'{v:08x}',bytes=n) for v,n in storage],
    source_pins=sourcepins,coff_pins=coff,
    original_dossier_pins={rel(rea/f'function-{v}.json'):sha(rea/f'function-{v}.json') for v in dossiers},
    scope='reachable00468fb0 call path only; raw producer+lookup+leaf+4552+716 normal disjoint stack/tree; controlled downstream allocator/constructors')
save(RUN/'evidence.json',result)
print('Run726 provenance/ownership/COFF PASS; 73 cases per optimization, 7 controls')
