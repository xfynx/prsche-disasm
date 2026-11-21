"""Run731 immutable native-input and original-range ownership audit."""
from pathlib import Path
import hashlib,json,subprocess
ROOT=Path(__file__).resolve().parents[5]; RUN=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def rel(p):return p.relative_to(ROOT).as_posix()
receipt=ROOT/'local/experiments/v2-scene-tree-constructors-731/002/receipt.json'
proof=json.loads(receipt.read_text());assert proof['status']=='PASS'
for key in ['inputs_sha256','outputs_sha256']:
    for p,h in proof[key].items():assert sha(ROOT/p)==h,(key,p)
index={x['entry_va']:x for x in map(json.loads,(ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
registry=json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text())['functions']
new=[(0x455830,0x4558a6),(0x4558b0,0x455926)]; overlaps=[]
for item in registry:
    if item['module']!='Porsche.exe':continue
    for a,b in item.get('body_ranges',index.get(item['entry_va'],{}).get('ranges',[[item['entry_va'],item['entry_va']]])):
        if any(int(a,16)<=d and c<=int(b,16) for c,d in new):overlaps.append(item['entry_va'])
assert not overlaps,overlaps
dump=ROOT/'local/tools/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x86/dumpbin.exe';coff={}
for name in ['od-4','o2-4']:
    for flag,suffix in [('/DISASM','disasm'),('/HEADERS','headers')]:
        p=receipt.parent/f'{name}-{suffix}.txt'
        if not p.exists():p.write_bytes(subprocess.check_output([str(dump),flag,str(receipt.parent/(name+'.obj'))]))
        coff[rel(p)]=sha(p)
    text=(receipt.parent/f'{name}-headers.txt').read_text(errors='replace')
    assert '.bss name' not in text and '.data name' not in text
listing=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
lines=[]
for line in listing.read_text().splitlines():
    try:va=int(line.split(' ')[0],16)
    except ValueError:continue
    if any(a<=va<=b for a,b in new):lines.append(line)
out=RUN/'original-listing.asm'
if not out.exists():out.write_text('\n'.join(lines)+'\n',encoding='utf-8',newline='\n')
assert lines and lines[0].startswith('00455830') and lines[-1].startswith('00455924')
data=dict(run=731,status='PASS',receipt=rel(receipt),receipt_sha256=sha(receipt),cases_per_optimization=2121,material_controls=7,
    body_bytes=238,body_overlap=overlaps,new_storage_bytes=0,true_frontier=[],
    source_pins={p:h for p,h in proof['inputs_sha256'].items() if '/runs/' in p and not p.startswith('local/')},
    coff_pins=coff,original_listing_sha256=sha(out),
    boundary='Valid disjoint holder/context/pool nodes, NULL ignoredsecond argument; first-byte external or holder+9 alias; real721/726/716 composition, controlled canonical heap callbacks; refill must provide valid node. Other aliases/faults/live heap remain open.')
(RUN/'evidence.json').write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8',newline='\n')
print('Run731 provenance/ownership/no-new-data COFF PASS')
