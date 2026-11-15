"""Static index, bytes and current compiled-source ownership census; no execution."""
from pathlib import Path
import hashlib,importlib.util,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native565',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
build_path=RUN.parent/'576-render-texture-scheduler-integration/build-001.json'
cfg_path=build_path.with_name('build-config.json');build=json.loads(build_path.read_bytes());cfg=json.loads(cfg_path.read_bytes())
_,pins=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
roots=build['compiled_source_roots'];dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/x for x in cfg['source_include_dirs']);closure=dep.source_hashes(roots)
index=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
records={r['entry_va']:r for r in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
targets=['00554960','00554d70','00554820','005556b0','00554310','00555780']
raw=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_bytes())
selected={va:records[va] for va in targets};collisions=[]
for r in registry['functions']:
    if r.get('module')!='Porsche.exe' or 'entry_va' not in r:continue
    ranges=records.get(r['entry_va'],{}).get('ranges',[[r['entry_va'],r['entry_va']]])
    for va,row in selected.items():
        if any(int(a,16)<=int(y,16) and int(b,16)>=int(x,16) for a,b in ranges for x,y in row['ranges']):collisions.append({'target':va,'entry':r['entry_va'],'status':r.get('status')})
hits=[];data_hits=[];neighbor_hits=[]
for name in closure:
    if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
    for n,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
        if any(x in line.lower() for x in targets):hits.append({'file':name,'line':n,'text':line.strip()})
        if any(x in line.lower() for x in ('006a3a54','005df2c8')):data_hits.append({'file':name,'line':n,'text':line.strip()})
        if any(0x6a3a40<=int(x,16)<0x6a3a64 or 0x5df2b0<=int(x,16)<0x5df2d8 for x in re.findall(r'(?<![0-9a-fA-F])([0-9a-fA-F]{8})(?![0-9a-fA-F])',line)):
            neighbor_hits.append({'file':name,'line':n,'text':line.strip()})
calls=[r for r in map(json.loads,(index/'calls.jsonl').read_text().splitlines()) if r.get('from_function') in targets or r.get('to_function') in targets]
references=[r for r in map(json.loads,(index/'references.jsonl').read_text().splitlines()) if r.get('to_va') in ('006a3a54','005df2c8')]
pe_offset=struct.unpack_from('<I',raw,0x3c)[0];image_base=struct.unpack_from('<I',raw,pe_offset+52)[0];nsec=struct.unpack_from('<H',raw,pe_offset+6)[0];optional=struct.unpack_from('<H',raw,pe_offset+20)[0];zero_tail=None
for i in range(nsec):
    at=pe_offset+24+optional+i*40;vsize,rva,raw_size,raw_at=struct.unpack_from('<IIII',raw,at+8);offset=0x6a3a54-image_base-rva
    if 0<=offset and offset+4<=vsize:
        assert offset>=raw_size;zero_tail=dict(section=raw[at:at+8].rstrip(b'\0').decode(),virtual_offset=offset,raw_bytes=raw_size,virtual_bytes=vsize)
assert zero_tail
comparator=native.pe_at(raw,0x5df2c8,4);assert comparator==bytes.fromhex('10435500')
rea=ROOT/'local/experiments/v2-frontier-469-rea/001';receipt=json.loads((rea/'receipt.json').read_bytes());assert receipt['exit_code']==0
rea_pins={}
for va in ('00554960','00554d70'):
    path=rea/f'function-{va}.json';assert sha(path)==receipt['output_sha256'][path.name];rea_pins[str(path.relative_to(ROOT)).replace('\\','/')]=sha(path)
result=dict(module_sha256=hashlib.sha256(raw).hexdigest(),build=str(build_path.relative_to(ROOT)),
    build_sha256=sha(build_path),registry_sha256=sha(registry_path),effective_pins=len(pins),roots=len(roots),closure_files=len(closure),
    collisions=collisions,ownership_hits=hits,data_hits=data_hits,neighbor_hits=neighbor_hits,calls=calls,data_references=references,rea_dossiers=rea_pins,
    state_006a3a54=dict(va='006a3a54',bytes=4,initial='00000000',section=zero_tail,adjacent=['006a3a50..53 callback','006a3a58..5b pending']),
    state_005df2c8=dict(va='005df2c8',bytes=4,raw_hex=comparator.hex(),initial_original_va='00554310',host_binding='typed function pointer, never original raw VA'),
    bodies=[dict(va=va,bytes=row['body_bytes'],raw_hex=(body:=native.pe_at(raw,int(va,16),row['body_bytes'])).hex(),sha256=hashlib.sha256(body).hexdigest(),ranges=row['ranges']) for va,row in selected.items()])
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(dict(roots=len(roots),closure_files=len(closure),pins=len(pins),collisions=collisions,hits=len(hits),data_hits=data_hits,neighbors=len(neighbor_hits),calls=len(calls))))
