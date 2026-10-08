"""Export the original worker dispatch table; verify module and body SHA."""
import hashlib
import json
from pathlib import Path
import struct
from v2_manual_index import records
ROOT=Path(__file__).resolve().parents[2]
module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines() if json.loads(x)['file']=='Porsche.exe')
data=(ROOT/'local/game'/module['path']).read_bytes()
assert hashlib.sha256(data).hexdigest()==module['sha256']
worker=next(r for r in records(module['sha256']) if r['entry_va']=='00568530')
section=next(s for s in module['sections'] if s['rva']<=0x1688d0<s['rva']+s['raw_size'])
offset=section['raw_offset']+0x1688d0-section['rva']
table=data[offset:offset+44]
targets=struct.unpack('<11I',table)
assert all(0x568530<=v<=0x5688cc for v in targets)
report={'schema':1,'module':'Porsche.exe','sha256':module['sha256'],'worker':worker,
        'table_va':'005688d0','table_file_offset':offset,'table_bytes':table.hex(),
        'table_sha256':hashlib.sha256(table).hexdigest(),
        'cells':[{'opcode':i,'cell_va':f'{0x5688d0+i*4:08x}','target_va':f'{t:08x}'} for i,t in enumerate(targets)],
        'proof':['Unsigned selector <=10 at 005685f0/005685f3, indirect dispatch 005685f9.',
                 'Shutdown 006a5c80 checked before loop 00568560 and after iteration 005688b1.',
                 'Group compared signed against device+6c at 005685a4/005685a6.',
                 'Completed prepend 00568859 precedes callback 005688a0 and signal 005688a9.',
                 'Canceled flags bit2 bypass dispatch; callback -1, otherwise MOVSX int8 at 00568893.']}
run=ROOT/'iterations/v2/001-original-recovery/runs/007-file-worker'
run.mkdir(parents=True,exist_ok=True)
(run/'dispatch.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
print(json.dumps({'table_sha256':report['table_sha256'],'targets':[f'{v:08x}' for v in targets]}))
