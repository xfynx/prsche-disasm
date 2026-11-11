from pathlib import Path
import hashlib, importlib.util, json, sys
root=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(root/'local/tools/python-unicorn'))
import capstone
spec=importlib.util.spec_from_file_location('native',root/'scripts/research/verify-v2-native-batch.py')
native=importlib.util.module_from_spec(spec);spec.loader.exec_module(native)
raw=(root/'local/game/Porsche.exe').read_bytes()
module_hash=hashlib.sha256(raw).hexdigest()
assert module_hash=='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
bodies=[]
for va,size in [(0x4ad8b0,152),(0x5666f0,127),(0x5665b0,309),(0x567720,31),(0x567550,267)]:
    blob=native.pe_at(raw,va,size)
    ins=[{'va':f'{x.address:08x}','raw':x.bytes.hex(),'asm':f'{x.mnemonic} {x.op_str}'.strip()} for x in md.disasm(blob,va)]
    assert sum(len(bytes.fromhex(x['raw'])) for x in ins)==size
    bodies.append({'va':f'{va:08x}','bytes':size,'sha256':hashlib.sha256(blob).hexdigest(),'raw_hex':blob.hex(),'instructions':ins})
result={'module_sha256':module_hash,'kind':'static-trace-not-native-proof','bodies':bodies,
 'observations':['004ad8b0 passes stack local as argument 4 and null argument 5 to 005666f0',
 '005666f0 forwards all five words to 005665b0 and can call a diagnostic callback after a zero return',
 '005665b0 writes argument 4 on all normal return paths: zero for no match; decoded 4-byte or 3-byte entry field for match',
 '004ad8b0 passes the local as argument 4 to 00567720 only when signed root+70 is nonnegative; 00567720 forwards it as argument 4 to 00567550 with fifth argument zero',
 '00567550 may fail before reading argument 4; on its fifth-argument-zero branch it forwards argument 4 to 0056b690',
 'These conclusions exclude faults, nonreturning or arbitrary-memory-mutating child/diagnostic callbacks, and unproved malformed-resource behavior']}
(Path(__file__).with_name('output-trace-evidence.json')).write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
print('module',module_hash,'bodies',[(x['va'],x['bytes'],x['sha256']) for x in bodies])
