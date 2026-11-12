"""Static index, bytes and current compiled-source ownership census; no execution."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'))
import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native565',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
build_path=RUN.parent/'567-audio-codec-control-integration/build-001.json'
cfg_path=build_path.with_name('build-config.json');build=json.loads(build_path.read_bytes());cfg=json.loads(cfg_path.read_bytes())
_,pins=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
roots=build['compiled_source_roots'];dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/x for x in cfg['source_include_dirs']);closure=dep.source_hashes(roots)
index=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
records={r['entry_va']:r for r in map(json.loads,(index/'functions.jsonl').read_text().splitlines())}
targets=['0056b540','005681b0']
raw=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(raw).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
registry_path=ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json';registry=json.loads(registry_path.read_bytes())
selected={va:records[va] for va in targets};collisions=[]
for r in registry['functions']:
    if r.get('module')!='Porsche.exe' or 'entry_va' not in r:continue
    ranges=records.get(r['entry_va'],{}).get('ranges',[[r['entry_va'],r['entry_va']]])
    for va,row in selected.items():
        if any(int(a,16)<=int(y,16) and int(b,16)>=int(x,16) for a,b in ranges for x,y in row['ranges']):collisions.append({'target':va,'entry':r['entry_va'],'status':r.get('status')})
hits=[]
for name in closure:
    if Path(name).suffix not in ['.cpp','.hpp','.h','.inc']:continue
    for n,line in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
        if any(x in line.lower() for x in targets):hits.append({'file':name,'line':n,'text':line.strip()})
calls=[r for r in map(json.loads,(index/'calls.jsonl').read_text().splitlines()) if r.get('from_function') in targets or r.get('to_function') in targets]
result=dict(module_sha256=hashlib.sha256(raw).hexdigest(),build=str(build_path.relative_to(ROOT)),
    build_sha256=sha(build_path),registry_sha256=sha(registry_path),effective_pins=len(pins),roots=len(roots),closure_files=len(closure),
    collisions=collisions,ownership_hits=hits,calls=calls,
    bodies=[dict(va=va,bytes=row['body_bytes'],raw_hex=(body:=native.pe_at(raw,int(va,16),row['body_bytes'])).hex(),sha256=hashlib.sha256(body).hexdigest(),ranges=row['ranges']) for va,row in selected.items()])
(RUN/'scope-evidence.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(dict(roots=len(roots),closure_files=len(closure),pins=len(pins),collisions=collisions,hits=len(hits),calls=len(calls))))
