"""Exact touched-byte ledger; does not infer a contiguous periodic-control array."""
import hashlib
import json
import re
import struct
from pathlib import Path

ROOT=Path(__file__).resolve().parents[5]
RUN=Path(__file__).resolve().parent
scope=json.loads((RUN/'scope-evidence.json').read_bytes())
raw=(ROOT/'local/game/Porsche.exe').read_bytes()
assert hashlib.sha256(raw).hexdigest()==scope['module_sha256']
owners=[
 ('canonical_device',0x6b48b0,0x18c,'source/recovered/Porsche.exe/application_audio_device.cpp'),
 ('thread_callbacks460',0x6b4a3c,8,'runs/460-audio-thread-worker/audio_thread_worker_460.cpp'),
 ('pixel_palette380',0x6b4b20,1024,'runs/380-pixel-helpers/pixel_helpers.cpp'),
 ('notify_kind462',0x6b4886,1,'runs/462-audio-directsound-initialize/audio_directsound_state_462.cpp'),
 ('device_buffers455',0x6b4888,16,'runs/455-audio-device-lifecycle/audio_device_lifecycle_455.cpp'),
 ('device_callback455',0x6b4898,4,'runs/455-audio-device-lifecycle/audio_device_lifecycle_455.cpp'),
 ('voice_table435',0x6b489c,4,'runs/435-audio-stop-voice/audio_stop_435.cpp'),
 ('resource_count452',0x6b48a0,4,'runs/452-audio-record-resources/audio_record_resources_452.cpp'),
 ('resource_map452',0x6b48a4,4,'runs/452-audio-record-resources/audio_record_resources_452.cpp'),
]
touched={}
for group in range(32):
    for offset,size in ((0,4),(4,1),(5,1),(8,4),(12,4)):
        for i in range(size):touched[0x6b4a08+group*16+offset+i]=f'period_group{group:02d}'
    touched[0x6b4886+group]=f'notify_group{group:02d}'
holes=[];views=[]
for address,consumer in sorted(touched.items()):
    match=[o for o in owners if o[1]<=address<o[1]+o[2]]
    assert len(match)<=1,(hex(address),match)
    if match:
        owner,start,size,source=match[0]
        views.append(dict(va=f'{address:08x}',owner=owner,offset=address-start,consumer=consumer))
    else:holes.append(address)
spans=[]
for address in holes:
    if spans and spans[-1]['va']+spans[-1]['bytes']==address:spans[-1]['bytes']+=1
    else:spans.append(dict(va=address,bytes=1))
assert sum(s['bytes'] for s in spans)==193
# Complete new spans are loader-zero in the pinned original virtual section.
pe=struct.unpack_from('<I',raw,0x3c)[0];base=struct.unpack_from('<I',raw,pe+52)[0]
count=struct.unpack_from('<H',raw,pe+6)[0];optional=struct.unpack_from('<H',raw,pe+20)[0]
for span in spans:
    matched=False
    for i in range(count):
        off=pe+24+optional+i*40;vs,rva,rs,rp=struct.unpack_from('<IIII',raw,off+8)
        if rva<=span['va']-base and span['va']-base+span['bytes']<=rva+vs:
            assert span['va']-base>=rva+rs
            span['initial']='PE-loader-zero';span['section']=raw[off:off+8].rstrip(b'\0').decode();matched=True
    assert matched
# Reuse the bounded scalar/literal-array declaration census as a supplement to
# the full current closure name search and explicit physical-owner ledger.
pattern=re.compile(r'\b(std::(?:u?int)(?:8|16|32|64)_t|float|double|char|unsigned\s+char|unsigned\s+int|int|U|B)\s+([A-Za-z_]\w*_(00[0-9a-fA-F]{6}))\s*(?:\[\s*(0x[0-9a-fA-F]+|\d+)\s*\])?\s*(?:=|;|\{)')
recognized=[];collisions=[]
for name in scope['closure_sha256']:
    path=ROOT/name
    if path.suffix not in ('.cpp','.hpp','.h','.inc'):continue
    for match in pattern.finditer(path.read_text(encoding='utf-8-sig')):
        kind,symbol,address,n=match.groups()
        width=next((int(v)//8 for v in ('8','16','32','64') if kind.endswith(v+'_t')),None)
        if width is None:width=8 if kind=='double' else 1 if kind in ('char','B','unsigned char') else 4
        row=dict(source=name,symbol=symbol,va=int(address,16),bytes=width*int(n or '1',0));recognized.append(row)
        for span in spans:
            if row['va']<span['va']+span['bytes'] and span['va']<row['va']+row['bytes']:collisions.append(dict(owner=row,span=span))
assert not collisions,collisions
report=dict(kind='sparse-original-owner-ledger-before-implementation',module_sha256=scope['module_sha256'],
 source_closure=len(scope['closure_sha256']),recognized_declarations=len(recognized),new_body_bytes=286,
 touched_bytes=len(touched),reused_bytes=len(views),new_bytes=len(holes),
 existing_owners=[dict(owner=o[0],va=f'{o[1]:08x}',bytes=o[2],source=o[3]) for o in owners],
 new_spans=[{**s,'va':f'{s["va"]:08x}'} for s in spans],views=views,
 limits=['All32 low-byte groups; upper argument bits require separate address-domain proof',
         '395 network descriptor/context arrays are research-only unsized extern views, not canonical owners',
         'New span census covers recognized declarations; explicit owner objects handled separately; no unknown pointer/struct capacity inferred'])
(RUN/'owner-ledger.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
print('558 touched',len(touched),'reused',len(views),'new',len(holes),'spans',len(spans),'recognized',len(recognized))
print([(hex(s['va']),s['bytes']) for s in spans])
