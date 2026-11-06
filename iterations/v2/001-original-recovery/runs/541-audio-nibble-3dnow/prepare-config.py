"""Pin541 raw ranges/data and exact canonical multiobject link contract."""
from pathlib import Path
import importlib.util,json,hashlib,sys,struct
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
def load(name,p):
 s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
native=load('native541config',ROOT/'scripts/research/verify-v2-native-batch.py')
coff=load('coff541config',ROOT/'scripts/research/build-v2-compile-corpus.py')
raw=(ROOT/'local/game/Porsche.exe').read_bytes();sha=lambda b:hashlib.sha256(b).hexdigest()
assert sha(raw)=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
old=json.loads((RUN.parent/'538-audio-nibble-continuation/native-config.json').read_text())
work=ROOT/'local/experiments/v2-audio-nibble-continuation-538/002'
symbols={}
for i in [2,3,12,1,0]:
 for symbol in coff.coff_symbols(work/f'od-{i}.obj')['defined']:symbols[symbol]=i
def symbol(fragment):
 found=[s for s in symbols if fragment in s];assert len(found)==1,found;return found[0]
exports={'decode':'?audio_nibble_decode_3dnow_0059a730@porsche@@YAXI@Z',
 'lut':symbol('audio_mixer_nibble_lookup_006b04c0'),
 'window':symbol('audio_nibble_read_window_005e3b28'),
 'tail':symbol('audio_nibble_read_tail_006b0800'),
 'initialize':symbol('audio_mixer_initialize_nibble_table_0059b8d0'),
 'loop':symbol('audio_nibble_loop_process_0059c890'),
 'continue':symbol('audio_nibble_loop_continue_0059c690'),
 'drain':symbol('audio_nibble_drain_0059d5f0')}
undefined=['?read32@nibble512@porsche@@YAII@Z','?read8@nibble512@porsche@@YAII@Z','?write32@nibble512@porsche@@YAXII@Z',exports['window'],exports['lut']]
bodies=[dict(name=name,va=f'{va:08x}',bytes=count,sha256=sha(native.pe_at(raw,va,count)),role='new' if name=='decode' else 'canonical-regression') for name,va,count in [('decode',0x59a730,201),('initialize',0x59b8d0,53),('loop',0x59c890,344),('continue',0x59c690,505),('drain',0x59d5f0,94)]]
data=[dict(name='window',va='005e3b28',bytes=80,kind='file-backed',sha256=sha(native.pe_at(raw,0x5e3b28,80))),dict(name='lut',va='006b04c0',bytes=832,kind='loader-zero',sha256=sha(bytes(832))),dict(name='tail',va='006b0800',bytes=192,kind='loader-zero',sha256=sha(bytes(192)))]
support=[dict(source=old['sources'][i],object_stem=stem) for i,stem in [(2,'nibble512'),(3,'memory512'),(12,'configuration512'),(1,'process534'),(0,'continuation538')]]
mutations=[
 ('count_guard','while(static_cast<I>(read32(state))>0)','while(static_cast<I>(read32(state))>1)'),
 ('block_count','read32(state)-28u','read32(state)-27u'),
 ('input_step','input+=15u','input+=14u'),
 ('output_step','output+=112u','output+=108u'),
 ('coefficient_pair','window+16u+high*4u','window+12u+high*4u'),
 ('row_shift','(read8(input)&15u)*64u','(read8(input)&15u)*32u'),
 ('low_nibble','const U lower=read8(encoded)&15u','const U lower=read8(encoded)>>4'),
 ('odd_add_order','_emit 0e6h\n+ _emit 09eh\n+ _emit 0fh\n+ _emit 0fh\n+ _emit 0e5h'.replace('\n+ ','\n '),'_emit 0e5h\n _emit 09eh\n _emit 0fh\n _emit 0fh\n _emit 0e6h'),
 ('history_save','movd [eax+4],mm2\n movd [eax+8],mm3','movd [eax+4],mm3\n movd [eax+8],mm2'),
 ('missing_femms',' _emit 0fh\n _emit 0eh',' nop'),
 ('premature_even_store','const U lower=read8(encoded)&15u;','nibble512::write32(output+index*8u,0);const U lower=read8(encoded)&15u;')]
cfg=dict(experiment='local/experiments/v2-audio-nibble-3dnow-541',original_pe='local/game/Porsche.exe',original_sha256=sha(raw),source='audio_nibble_3dnow_541.cpp',header='audio_nibble_3dnow_541.hpp',cpu_model=11,original_bodies=bodies,original_data=data,original_symbols={**{r['name']:r['va'] for r in bodies},**{r['name']:r['va'] for r in data}},exports=exports,data_exports=['lut','window','tail'],candidate_exports={'decode':exports['decode']},expected_candidate_undefined=sorted(undefined),support_sources=support,include_dirs=[RUN.relative_to(ROOT).as_posix(),*old['include_dirs']],mutations=[dict(name=name,**{'from':a,'to':b,'count':1}) for name,a,b in mutations],new_original_body_bytes=201,new_state_bytes=0)
cfg['candidate_auxiliary_symbols']=['__Avx2WmemEnabledWeakValue']
(RUN/'config.json').write_text(json.dumps(cfg,indent=2)+'\n',encoding='utf-8',newline='\n')
print(json.dumps(dict(exports=exports,undefined=undefined,support_sources=support)))
