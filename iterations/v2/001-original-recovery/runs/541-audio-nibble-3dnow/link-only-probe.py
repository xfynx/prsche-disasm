"""One approved non-executed MSVC dead-strip probe; retain all metadata."""
from pathlib import Path
import json,struct,hashlib,subprocess,re
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
BASE=ROOT/'local/experiments/v2-audio-nibble-3dnow-541/003/Od'
OUT=ROOT/'local/experiments/v2-audio-nibble-3dnow-541/link-only-004'
assert not OUT.exists(),'immutable probe exists';OUT.mkdir(parents=True)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
cfg=json.loads((RUN/'config.json').read_text());objects=[BASE/'baseline.obj',*[BASE/('support-'+i['object_stem']+'.obj') for i in cfg['support_sources']],BASE/'image_entry.obj']
def read_coff(path):
 data=path.read_bytes();machine,nsections,_,table,count,optional,_=struct.unpack_from('<HHIIIHH',data);assert machine==0x14c and optional==0
 strings=table+count*18
 def name(raw):
  if raw[:4]==bytes(4):start=strings+struct.unpack_from('<I',raw,4)[0];return data[start:data.index(0,start)].decode()
  return raw.rstrip(b'\0').decode()
 symbols={};i=0
 while i<count:
  p=table+i*18;raw,value,section,kind,storage,aux=struct.unpack_from('<8sIhHBB',data,p)
  symbols[i]=dict(index=i,name=name(raw),value=value,section=section,kind=kind,storage=storage,aux=data[p+18:p+18*(aux+1)].hex());i+=aux+1
 sections=[]
 for i in range(nsections):
  p=20+i*40;raw=data[p:p+8];size,start,relocs=struct.unpack_from('<III',data,p+16);nr=struct.unpack_from('<H',data,p+32)[0];flags=struct.unpack_from('<I',data,p+36)[0]
  section_symbols=[s for s in symbols.values() if s['section']==i+1]
  definitions=[s for s in section_symbols if s['value']==0 and s['kind']&0x20 and s['storage'] in [2,3]]
  selections=[dict(symbol=s['name'],selection=bytes.fromhex(s['aux'])[14]) for s in section_symbols if s['storage']==3 and len(s['aux'])>=36]
  sections.append(dict(index=i+1,name=raw.rstrip(b'\0').decode(),flags=flags,comdat=bool(flags&0x1000),key_candidates=definitions,selections=selections,relocations=[dict(offset=struct.unpack_from('<I',data,relocs+j*10)[0],target=symbols[struct.unpack_from('<I',data,relocs+j*10+4)[0]],kind=struct.unpack_from('<H',data,relocs+j*10+8)[0]) for j in range(nr)]))
 return dict(object=path.relative_to(ROOT).as_posix(),sha256=sha(path),symbols=list(symbols.values()),sections=sections)
coffs=[read_coff(p) for p in objects]
providers={s['name'] for obj in coffs for s in obj['symbols'] if s['storage']==2 and s['section']>0}
unresolved=sorted({s['name'] for obj in coffs for s in obj['symbols'] if s['storage']==2 and s['section']==0 and s['value']==0}-providers)
relocations=[]
for obj in coffs:
 for section in obj['sections']:
  for relocation in section['relocations']:
   if relocation['target']['name'] in unresolved:
    relocations.append(dict(object=obj['object'],section=section['index'],section_name=section['name'],comdat=section['comdat'],key_candidates=section['key_candidates'],selections=section['selections'],offset=relocation['offset'],kind=relocation['kind'],target=relocation['target']['name']))
link=ROOT/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x86/link.exe'
command=[str(link),'/nologo','/MACHINE:X86','/SUBSYSTEM:CONSOLE','/ENTRY:image_entry_541','/NODEFAULTLIB','/OPT:REF','/OPT:NOICF','/FORCE:UNRESOLVED','/FIXED','/DYNAMICBASE:NO','/BASE:0x10000000','/OUT:'+str(OUT/'link-only-image.exe'),'/MAP:'+str(OUT/'link-only-image.map'),*[f'/EXPORT:{k}={v}'+(',DATA' if k in cfg['data_exports'] else '') for k,v in cfg['exports'].items()],*map(str,objects)]
proc=subprocess.run(command,cwd=OUT,capture_output=True,timeout=120);(OUT/'link.log').write_bytes(proc.stdout+proc.stderr)
report=dict(kind='isolated-link-only-never-executed',command=command,exit_code=proc.returncode,inputs_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),RUN/'config.json',link,*objects]},unresolved=unresolved,undefined_relocation_sources=relocations,objects=coffs,executed=False)
issues=[]
if proc.returncode:issues.append('link did not produce clean return')
if (OUT/'link-only-image.map').exists():
 maptext=(OUT/'link-only-image.map').read_text(errors='replace')
 for row in relocations:
  keys=row['key_candidates'];row['map_key_hits']=[k['name'] for k in keys if k['name'] in maptext]
  if not row['comdat']:issues.append('nonCOMDAT relocation source')
  if len(keys)!=1 or keys[0]['storage']!=2:issues.append('ambiguous/nonpublic COMDAT key')
  if row['map_key_hits']:issues.append('relocation source retained in MAP')
else:issues.append('no MAP')
report['discard_proof_issues']=issues;report['discard_proven']=not issues
(OUT/'report.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(dict(exit_code=proc.returncode,unresolved=len(unresolved),relocation_sources=len(relocations),discard_proven=not issues,issues=sorted(set(issues)),executed=False)))
