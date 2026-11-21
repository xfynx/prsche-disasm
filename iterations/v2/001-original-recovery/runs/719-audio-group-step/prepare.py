import hashlib,json,pathlib,struct
root=pathlib.Path(__file__).resolve().parents[5]
run=pathlib.Path(__file__).resolve().parent
rel=run.relative_to(root).as_posix()
def dump(name,v): (run/name).write_text(json.dumps(v,indent=2)+'\n',encoding='utf-8',newline='\n')
pe=(root/'local/game/Porsche.exe').read_bytes(); sha=hashlib.sha256(pe).hexdigest()
assert sha=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
u32=lambda p:struct.unpack_from('<I',pe,p)[0]
u16=lambda p:struct.unpack_from('<H',pe,p)[0]
nt=u32(0x3c);base=u32(nt+52);s0=nt+24+u16(nt+20)
def raw(va,n):
 for i in range(u16(nt+6)):
  s=s0+i*40;d=va-base-u32(s+12)
  if 0<=d and d+n<=u32(s+8):return bytes(pe[u32(s+20)+d+j] if d+j<u32(s+16) else 0 for j in range(n))
 raise ValueError(hex(va))
body=raw(0x58a970,233);bh=hashlib.sha256(body).hexdigest()
registry=json.loads((root/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text(encoding='utf-8'))['functions']
index={f['entry_va']:f for f in map(json.loads,(root/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf-8').splitlines())}
overlaps=[]
for f in registry:
 if f['module']!='Porsche.exe':continue
 for lo,hi in f.get('body_ranges',[])+index.get(f['entry_va'],{}).get('ranges',[]):
  if int(lo,16)<=0x58aa58 and int(hi,16)>=0x58a970:overlaps.append(f['entry_va'])
assert not overlaps
listing=(root/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm').read_text(encoding='utf-8')
start=listing.index('; FUNCTION 0058a970');end=listing.index('; FUNCTION 0058aa60',start)
(run/'original-listing.asm').write_text(listing[start:end],encoding='utf-8',newline='\n')
dump('scope-evidence.json',{'schema':1,'module':'Porsche.exe','module_sha256':sha,'query':'0058a970 in binary-index Porsche functions.jsonl, disassembly.asm; typed caller Run71500599610',
 'bodies':[{'va':'0058a970','end':'0058aa58','bytes':233,'sha256':bh,'body_ranges':[['0058a970','0058aa58']],'abi':'cdecl uint32(uint32* cursor,const void* record); plain RET; EBX/EBP/ESI/EDI and ESP preserved','callers':['Run71500599610, offsets0x4d and0xad'],'callees':[]}],
 'ownership':{'new_cells':[],'owner':'source/recovered/Porsche.exe/application_audio_device.cpp, ApplicationAudioDeviceStateStorage application_audio_device_state_006b48c0','references':[{'va':'006b48e7','offset':'0x27','bytes':1,'role':'count'},{'va':'006b48e8+signed cursor','offset':'0x28+cursor','bytes':1,'role':'sample flags'}],'registry_entries':len(registry),'overlaps':overlaps,'raw_state_prefix':raw(0x6b48c0,0x128).hex(),'closure':'Actual canonical owner TU compiled in fixture; all unused backend edges fail closed. Full accepted Run714 compiler-root/header closure verified in Run718, canonical owner source included. No duplicated state.'},
 'bounds':'Stable disjoint record/cursor/owner storage; count0..255; signed negative cursor only when resulting sample address stays in canonical storage. No invalid-pointer, concurrency or alias composition claim.'})
mut=[]
def m(name,old,new):mut.append({'name':name,'source':rel+'/audio_group_step_719.cpp','old':old,'new':new,'expected_exit':1,'failure_marker':'divergence'})
m('count-offset','[0x27u]','[0x26u]')
m('unsigned-initial-cursor','static_cast<I>(*out) >= static_cast<I>(count)','*out >= count')
m('mask-offset','bytes[0x18u]','bytes[0x17u]')
m('low-mask','mask & 0x1cu','mask & 0x0cu')
m('high-mask','sample & 0xe0u','sample & 0xc0u')
m('subtype-gate','(low & 0x10u) != 0u','(low & 0x10u) == 0u')
m('subtype-mask','sample & 0x3u','sample & 0x1u')
m('record-gate','bytes[3u] != 1u','bytes[3u] == 1u')
m('high-gate','(result & 0xc0u)','(result & 0x80u)')
m('cursor-increment','*out = index + 1u','*out = index + 2u')
m('low-intersection','low_mask == 0u || result != 0u','true')
m('high-intersection','(mask & 0xe0u) == 0u || high_result != 0u','true')
m('subtype-intersection','(mask & 0x3u) == 0u || subtype_result != 0u','true')
dump('native-config.json',{'run':719,'experiment':'local/experiments/v2-audio-group-step-719','original_pe':'local/game/Porsche.exe','original_sha256':sha,
 'sources':[rel+'/audio_group_step_719.cpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp'],
 'fixture':rel+'/native-fixture.cpp.in','include_dirs':[rel,'iterations/v2/001-original-recovery/source/include'],'headers':[rel+'/scope-evidence.json'],
 'original_bodies':[{'va':'0058a970','bytes':233,'sha256':bh,'token':'@BODY_0058a970@'}],
 'pass_marker':'audio_group_step_original_x86_vs_cpp=PASS','timeout_seconds':240,'mutations':mut})
print('prepared719',bh)
