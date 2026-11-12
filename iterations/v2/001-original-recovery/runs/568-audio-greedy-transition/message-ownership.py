"""Check the exact 568 PE message and search every accepted 567 source/header."""
from pathlib import Path
import hashlib,importlib.util,json,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'));import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native568',ROOT/'scripts/research/verify-v2-native-batch.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
build_path=RUN.parent/'567-audio-codec-control-integration/build-001.json';cfg_path=build_path.with_name('build-config.json')
build=json.loads(build_path.read_bytes());cfg=json.loads(cfg_path.read_bytes());_,pins=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/x for x in cfg['source_include_dirs']);closure=dep.source_hashes(build['compiled_source_roots'])
pe=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(pe).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
raw=m.pe_at(pe,0x5bdb24,128).split(b'\0',1)[0]+b'\0';assert raw==b'STREAM_setgreedystate - invalid stream handle\n\0'
hits=[]
for name in closure:
 if Path(name).suffix.lower() not in ('.cpp','.hpp','.h','.inc'):continue
 for line,text in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
  if '5bdb24' in text.lower() or 'STREAM_setgreedystate' in text:hits.append(dict(file=name,line=line,text=text.strip()))
neighbor=m.pe_at(pe,0x5bdaf4,47);assert neighbor.endswith(b'\0') and 0x5bdaf4+len(neighbor)==0x5bdb23
result=dict(build=str(build_path.relative_to(ROOT)).replace('\\','/'),roots=len(build['compiled_source_roots']),closure_files=len(closure),effective_pins=len(pins),va='005bdb24',bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),raw_hex=raw.hex(),source_hits=hits,prior_message_va='005bdaf4',prior_message_bytes=len(neighbor),prior_end_exclusive='005bdb23',relation='one byte gap before new message')
(RUN/'message-ownership.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(result))
