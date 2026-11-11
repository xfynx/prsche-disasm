"""Create a small original-x86 oracle on the shared batch runner."""
from pathlib import Path
import hashlib,importlib.util,json,re,sys
ROOT=Path(__file__).resolve().parents[5];RUN=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
import capstone
scope=json.loads((RUN/'scope-evidence.json').read_bytes());rows={x['va']:x for x in scope['bodies']}
vas=['0056b380','0056b4c0','0056c840','005912e0'];positions={int(v,16):i*0x100 for i,v in enumerate(vas)}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
chunks=[];patches=[]
absolute={0x5debf0:'ptr(&diagnostic_handler_005debf0)',0x5deb74:'ptr(&shared_runtime_word_005deb74)',0x5deb78:'ptr(&shared_runtime_word_005deb78)',0x6b499c:'ptr(application_audio_device_state_006b48c0.data())+0xdc',0x5bdaf4:'ptr(greedy_message)',0x5bdec8:'ptr(frame_message)'}
for va in vas:
    row=rows[va];addr=int(va,16);raw=bytes.fromhex(row['raw_hex']);off=positions[addr]
    chunks.append(f'const B body_{va}[]={{@BODY_{va.upper()}@}};std::memcpy(slab+{off},body_{va},sizeof body_{va});')
    for ins in md.disasm(raw,addr):
        pos=off+ins.address-addr;op=ins.op_str
        if ins.mnemonic=='call' and op.startswith('0x'):
            target=int(op,16);dest=(f'slab+{positions[target]}' if target in positions else 'reinterpret_cast<void*>(&audio_stream_service_lookup_00566d60)' if target==0x566d60 else 'reinterpret_cast<void*>(&audio_stream_greedy_transition_0056b540)' if target==0x56b540 else None)
            assert dest is not None,(va,op)
            patches.append(f'require(rd(slab+{pos+1})==0x{int.from_bytes(ins.bytes[1:],"little"):08x},"original call");wr(slab+{pos+1},ptr({dest})-ptr(slab+{pos+5}));')
        for value,dest in absolute.items():
            if not re.search(r'\b'+hex(value)+r'\b',op):continue
            needle=value.to_bytes(4,'little');assert ins.bytes.count(needle)==1
            at=pos+ins.bytes.index(needle);patches.append(f'require(rd(slab+{at})==0x{value:08x},"original data");wr(slab+{at},{dest});')
template=(RUN/'fixture-access.inc').read_text(encoding='utf-8').replace('@ACCESS_BODIES@','\n '.join(chunks)).replace('@ACCESS_RELOCATIONS@','\n '.join(patches))
(RUN/'native-fixture.cpp.in').write_text(template,encoding='utf-8',newline='\n')
old=json.loads((RUN.parent/'561-audio-stream-creation/native-config.json').read_bytes())
old.update(run=565,experiment='local/experiments/v2-audio-codec-access-565',fixture=(RUN/'native-fixture.cpp.in').relative_to(ROOT).as_posix(),pass_marker='audio_codec_access_original_x86_vs_cpp=PASS',timeout_seconds=180)
old['sources']=[(RUN/'audio_codec_access_565.cpp').relative_to(ROOT).as_posix(),*old['sources']]
old['include_dirs'].insert(0,RUN.relative_to(ROOT).as_posix())
old['headers']=[(RUN/x).relative_to(ROOT).as_posix() for x in ('scope-evidence.json','scope-inspect.py','prepare.py','fixture-access.inc')]
old['original_bodies']=[dict(va=v,bytes=rows[v]['bytes'],sha256=rows[v]['sha256'],token=f'@BODY_{v.upper()}@') for v in vas]
spec=importlib.util.spec_from_file_location('native565',ROOT/'scripts/research/verify-v2-native-batch.py');native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
pe=(ROOT/'local/game/Porsche.exe').read_bytes();assert hashlib.sha256(pe).hexdigest()==old['original_sha256']
for va,name in [(0x5bd978,'PATH'),(0x5bdaf4,'GREEDY'),(0x5bdec8,'FRAME')]:
    data=native.pe_at(pe,va,128).split(b'\0',1)[0]+b'\0'
    old['original_bodies'].append(dict(va=f'{va:08x}',bytes=len(data),sha256=hashlib.sha256(data).hexdigest(),token=f'@STRING_{name}@'))
source=old['sources'][0]
edits=[('magic','0x4d525453u','0x4d525452u'),('output-order','std::memcpy(original,&handle,4);\n    std::memcpy(object,&value,4);','std::memcpy(object,&value,4);\n    std::memcpy(original,&handle,4);'),('frame-order','word(object+0x24)-word(object+0x20)','word(object+0x20)-word(object+0x24)'),('greedy-compare','current<level','current<=level'),('old-compare','current<previous','current<=previous'),('disabled','return -10;','return -9;'),('missing','return -8;','return -7;'),('index-mask','static_cast<I>(index)','static_cast<I>(index & 15u)')]
content=(ROOT/source).read_text(encoding='utf-8')
for name,before,after in edits:assert content.count(before)==1,(name,before)
old['mutations']=[dict(name=n,source=source,old=a,new=b,expected_exit=1,failure_marker='divergence') for n,a,b in edits]
(RUN/'native-config.json').write_text(json.dumps(old,indent=2)+'\n',encoding='utf-8',newline='\n')
print('565 fixture: 4 bodies, 305 bytes, 8 controls')
