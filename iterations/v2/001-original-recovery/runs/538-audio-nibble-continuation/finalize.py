"""Derive frozen538 handoff from a passing shared-runner receipt."""
from pathlib import Path
import json,hashlib,re,importlib.util,sys
RUN=Path(__file__).resolve().parent;ROOT=RUN.parents[4]
sys.path=[p for p in sys.path if Path(p or '.').resolve()!=RUN]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def rel(p):return p.relative_to(ROOT).as_posix()
def save(p,v):p.write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8',newline='\n')
work=ROOT/'local/experiments/v2-audio-nibble-continuation-538/002'
receipt=work/'receipt.json';native=json.loads(receipt.read_text(encoding='utf-8'));assert native['status']=='PASS'
for group in ['inputs_sha256','outputs_sha256']:
 for name,expected in native[group].items():assert sha(ROOT/name)==expected,name
s=importlib.util.spec_from_file_location('coff538',ROOT/'scripts/research/build-v2-compile-corpus.py');coff=importlib.util.module_from_spec(s);s.loader.exec_module(coff)
symbols={v:coff.coff_symbols(work/f'{v}-0.obj') for v in ['od','o2']}
symbol='?audio_nibble_loop_continue_0059c690@porsche@@YAHIIIII@Z'
for row in symbols.values():assert symbol in row['defined'];assert '?audio_nibble_drain_0059d5f0@porsche@@YAHIIII@Z' in row['undefined']
save(RUN/'coff.json',dict(native_receipt=rel(receipt),sources={'0':dict(source=rel(RUN/'audio_nibble_continuation_538.cpp'),variants=symbols)}))
counts=[];events=[]
for v in ['od','o2']:
 log=(work/f'{v}-native.log').read_text();counts.append(int(re.search(r'cases=(\d+)',log)[1]));events.append(int(re.search(r'events=(\d+)',log)[1]))
save(RUN/'ready.json',dict(status='READY-PASS-FROZEN',native_config=rel(RUN/'native-config.json'),native_receipt=rel(receipt),native_receipt_sha256=sha(receipt),original_functions=1,original_bytes=505,new_writable_bytes=0,new_readonly_bytes=0,native_cases=sum(counts),native_events=sum(events),mutations=len(native['mutation_controls']),pinned_inputs=len(native['inputs_sha256']),pinned_outputs=len(native['outputs_sha256']),sources_to_add=[rel(RUN/'audio_nibble_continuation_538.cpp')],original_entry='0059c690',calling_convention='cdecl5,RET0,EAX=1; args3/5 unused',closed_frontier=symbol,boundaries=['Scratch112B+8Bhistory prefix is uninitialized until actual full decoder write; only fully written bounded tails accepted','Actual512x87/SSE and534loop composition;3DNow59a730 remains controlled endpoint','External stack aliases, invalid local tails/arbitrary faults/unmaskedFP/concurrency/fullproducer/live/startup/gameplay remain open']))
print(json.dumps(dict(cases=sum(counts),events=sum(events),mutations=len(native['mutation_controls']),pins=len(native['inputs_sha256']),receipt_sha256=sha(receipt))))
