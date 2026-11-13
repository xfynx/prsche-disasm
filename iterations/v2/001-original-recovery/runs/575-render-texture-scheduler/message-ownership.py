"""Check the 120-byte adjacent PE strings and search the entire accepted closure."""
from pathlib import Path
import hashlib,importlib.util,json,re,struct,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts/research'));import v2_source_dependencies as dep
from v2_shared_manifests import ManifestReader
spec=importlib.util.spec_from_file_location('native575',ROOT/'scripts/research/verify-v2-native-batch.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
build_path=RUN.parent/'574-startup-lifecycle-integration/build-001.json';cfg_path=build_path.with_name('build-config.json')
build=json.loads(build_path.read_bytes());cfg=json.loads(cfg_path.read_bytes());_,pins=ManifestReader(ROOT).resolve(build,'source','crlf-to-lf','crlf-to-lf')
dep.EXTRA_INCLUDE_DIRS=tuple(ROOT/x for x in cfg['source_include_dirs']);closure=dep.source_hashes(build['compiled_source_roots'])
pe=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(pe).hexdigest()=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
raw=m.pe_at(pe,0x5bc2ec,120);expected=b'[DTEX] Error - trying to upload a texture thats already uploaded.\n Texture %s.\n\0D3D Error - Not enough texture memory.\n\0';assert raw==expected
hits=[];callback_hits=[]
for name in closure:
 if Path(name).suffix.lower() not in ('.cpp','.hpp','.h','.inc'):continue
 for line,text in enumerate((ROOT/name).read_text(encoding='utf-8-sig').splitlines(),1):
  tokens=re.findall(r'(?<![0-9a-fA-F])(?:0x)?([0-9a-fA-F]{8})(?![0-9a-fA-F])',text)
  if any(0x5bc2ec<=int(t,16)<0x5bc364 for t in tokens) or 'D3D Error - Not enough texture memory' in text or '[DTEX] Error - trying to upload a texture' in text:
   hits.append(dict(file=name,line=line,text=text.strip()))
  if any(0x6a3a50<=int(t,16)<0x6a3a54 for t in tokens) or 'render_texture_notify_callback_006a3a50' in text:
   callback_hits.append(dict(file=name,line=line,text=text.strip()))
pe_offset=struct.unpack_from('<I',pe,0x3c)[0];base=struct.unpack_from('<I',pe,pe_offset+52)[0];sections=struct.unpack_from('<H',pe,pe_offset+6)[0];optional=struct.unpack_from('<H',pe,pe_offset+20)[0];zero_tail=None
for i in range(sections):
 at=pe_offset+24+optional+i*40;virtual_size,rva,raw_size,raw_at=struct.unpack_from('<IIII',pe,at+8);offset=0x6a3a50-base-rva
 if 0<=offset and offset+4<=virtual_size:
  assert offset>=raw_size;zero_tail=dict(section=pe[at:at+8].rstrip(b'\0').decode(),virtual_offset=offset,raw_bytes=raw_size,virtual_bytes=virtual_size)
assert zero_tail
result=dict(build=str(build_path.relative_to(ROOT)).replace('\\','/'),roots=len(build['compiled_source_roots']),closure_files=len(closure),effective_pins=len(pins),va='005bc2ec',bytes=len(raw),sha256=hashlib.sha256(raw).hexdigest(),raw_hex=raw.hex(),source_hits=hits,split=[80,40],previous_canonical_file_va='005bc294',previous_canonical_file_bytes=30,callback_va='006a3a50',callback_bytes=4,callback_initial='00000000',callback_zero_tail=zero_tail,callback_source_hits=callback_hits,adjacent_owners=['006a3a48..006a3a4b dirty','006a3a58..006a3a5b pending'])
(RUN/'message-ownership.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(result))
