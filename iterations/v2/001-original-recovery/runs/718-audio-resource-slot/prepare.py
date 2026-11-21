"""Create Run718 pinned evidence/config using immutable original bytes."""
import hashlib, json, pathlib, struct
root = pathlib.Path(__file__).resolve().parents[5]
run = pathlib.Path(__file__).resolve().parent
rel = run.relative_to(root).as_posix()
def dump(name, obj):
    (run/name).write_text(json.dumps(obj, indent=2)+'\n', encoding='utf-8', newline='\n')
pe = (root/'local/game/Porsche.exe').read_bytes()
sha = hashlib.sha256(pe).hexdigest()
assert sha == 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
u32=lambda p: struct.unpack_from('<I', pe, p)[0]
u16=lambda p: struct.unpack_from('<H', pe, p)[0]
nt=u32(0x3c); base=u32(nt+52); section0=nt+24+u16(nt+20)
def raw(va,n):
    for i in range(u16(nt+6)):
        s=section0+i*40; vs=u32(s+8); rva=u32(s+12); size=u32(s+16); off=u32(s+20)
        d=va-base-rva
        if 0<=d and d+n<=vs:
            return bytes(pe[off+d+j] if d+j<size else 0 for j in range(n))
    raise ValueError(hex(va))
body=raw(0x58f7a0,60); bh=hashlib.sha256(body).hexdigest()
registry=json.loads((root/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text(encoding='utf-8'))['functions']
overlaps=[]
for f in registry:
    if f['module'] != 'Porsche.exe': continue
    if int(f['entry_va'],16)==0x58f7a0: overlaps.append(f)
    for lo,hi in f.get('body_ranges',[]):
        if int(lo,16)<=0x58f7db and int(hi,16)>=0x58f7a0: overlaps.append(f)
assert not overlaps
supp=[]
for p in (root/'iterations/v2/001-original-recovery/runs').glob('*/original-index-supplement.json'):
    supp.append({'path':p.relative_to(root).as_posix(),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()})
listing=(root/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm').read_text(encoding='utf-8')
start=listing.index('; FUNCTION 0058f7a0'); end=listing.index('; FUNCTION 0058f7e0',start)
(run/'original-listing.asm').write_text(listing[start:end],encoding='utf-8',newline='\n')
dump('scope-evidence.json',{'schema':1,'module':'Porsche.exe','module_sha256':sha,
 'query':'0058f7a0|0058f220|0058a970 in binary-index ghidra Porsche functions.jsonl and disassembly.asm',
 'bodies':[{'va':'0058f7a0','end':'0058f7db','bytes':60,'sha256':bh,'body_ranges':[['0058f7a0','0058f7db']],
 'abi':'cdecl void*(uint32 key), plain RET; EBX/ESI/EDI/EBP and ESP preserved',
 'callers':['00599610 Run715, CALL at0059966e'], 'callees':[],
 'absolute_relocations':[{'va':'006b48a0','count':1,'owner':'Run452 audio_resource_map_count_006b48a0'}, {'va':'006b48a4','count':2,'owner':'Run452 audio_resource_map_006b48a4'}]}],
 'ownership':{'new_cells':[], 'registry_entries':len(registry),'registry_overlaps':overlaps,'supplements':supp,
 'closure':'Canonical Run452 TU owns count/map/slots; Run443 TU owns device. Both actual owner sources are compiled in native fixture. Production only includes Run452 declarations. No duplicate data definitions.',
 'raw_state':[{'va':hex(v),'bytes':raw(v,4).hex()} for v in [0x6b48a0,0x6b48a4]]},
 'semantics':'Scan unsigned low16 count rows, stride8; first zero key receives key argument; preserve payload DWORD. Return rereads map base after store; zero on full/zero count. No null guard or reserved-key rejection.',
 'bounds':'Readable/writable map extent count*8, up to65535 rows; disjoint global map/count cells; stable single-thread state. Null map tested only at count0. Faults/concurrency/global-storage aliasing remain open.'})
mut=[]
def mutation(name,old,new):
    mut.append({'name':name,'source':rel+'/audio_resource_slot_718.cpp','old':old,'new':new,'expected_exit':1,'failure_marker':'divergence'})
mutation('low15-count','& 0xffffu','& 0x7fffu')
mutation('ignore-upper16-mask','& 0xffffu','& 0xffffffffu')
mutation('stride4','base + index * 8u','base + index * 4u')
mutation('skip-first-empty','if (value == 0u)','if (value == 0u && index != 0u)')
mutation('wrong-key','&key, 4u','&index, 4u')
mutation('clear-payload','return reinterpret_cast<void*>(audio_resource_map_006b48a4 + index * 8u);','std::uint32_t zero = 0; std::memcpy(reinterpret_cast<void*>(row + 4u), &zero, 4u); return reinterpret_cast<void*>(audio_resource_map_006b48a4 + index * 8u);')
mutation('return-next-row','audio_resource_map_006b48a4 + index * 8u','audio_resource_map_006b48a4 + (index + 1u) * 8u')
mutation('reject-zero-key','const std::uint32_t count =','if (key == 0u) return nullptr;\n    const std::uint32_t count =')
dump('native-config.json',{'run':718,'experiment':'local/experiments/v2-audio-resource-slot-718','original_pe':'local/game/Porsche.exe','original_sha256':sha,
 'sources':[rel+'/audio_resource_slot_718.cpp','iterations/v2/001-original-recovery/runs/452-audio-record-resources/audio_record_resources_452.cpp','iterations/v2/001-original-recovery/runs/443-audio-device-capabilities/audio_capabilities_443.cpp'],
 'fixture':rel+'/native-fixture.cpp.in','include_dirs':[rel], 'headers':[rel+'/scope-evidence.json'],
 'original_bodies':[{'va':'0058f7a0','bytes':60,'sha256':bh,'token':'@BODY_0058f7a0@'}],
 'pass_marker':'audio_resource_slot_original_x86_vs_cpp=PASS','timeout_seconds':240,'mutations':mut})
print('prepared',rel,bh)
