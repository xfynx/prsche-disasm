"""Read-only source/COFF audit for the static Run552 instruction translation."""
import argparse
import hashlib
import importlib.util
import json
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
import capstone as cs

sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()
parser = argparse.ArgumentParser()
parser.add_argument('--attempt', required=True)
args = parser.parse_args()
out = ROOT / 'local/experiments/v2-audio-adpcm-kernel-552' / args.attempt
evidence = json.loads((RUN / 'translation-evidence.json').read_bytes())
scope = json.loads((RUN / 'scope-evidence.json').read_bytes())
md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_32)
md.detail = True


def coff(path):
    data = path.read_bytes()
    machine, count, _, offset, symbols_count, optional, _ = struct.unpack_from('<HHIIIHH', data)
    assert machine == 0x14c and optional == 0
    strings = offset + symbols_count * 18
    symbols = {}
    i = 0
    while i < symbols_count:
        name, value, sec, kind, storage, aux = struct.unpack_from('<8sIhHBB', data, offset+i*18)
        if name[:4] == b'\0'*4:
            at = strings+struct.unpack_from('<I', name, 4)[0]
            name = data[at:data.index(b'\0', at)]
        else:
            name = name.rstrip(b'\0')
        symbols[i] = {'name': name.decode('ascii'), 'value': value, 'section': sec, 'storage': storage}
        i += aux+1
    sections = []
    for i in range(count):
        start = 20+i*40
        size, raw, rel = struct.unpack_from('<III', data, start+16)
        nr = struct.unpack_from('<H', data, start+32)[0]
        reloc = {}
        for j in range(nr):
            at, symbol, kind = struct.unpack_from('<IIH', data, rel+j*10)
            reloc[at] = (symbols[symbol]['name'], kind)
        sections.append((data[raw:raw+size], reloc))
    return symbols, sections


data = {int(k): v for k,v in evidence['data_bindings'].items()}
calls = {0x59a910:'audio_coded_decode_0059a910',0x59abe0:'audio_coded_dequantize_0059abe0',
         0x59ad80:'audio_coded_skip_bits_0059ad80',0x59adc0:'audio_coded_smooth_0059adc0',
         0x59ae00:'audio_coded_synthesize_0059ae00',0x59b580:'audio_coded_window_0059b580',
         0x59a8c0:'audio_adpcm_read_bits_0059a8c0',0x598a50:'audio_stream_copy_forward_00598a50'}
results = []
for variant in ('od','o2'):
    path = out / (variant+'-0.obj')
    symbols, sections = coff(path)
    for b in evidence['bodies']:
        va = int(b['va'],16)
        symbol = next(s for s in symbols.values() if s['storage']==2 and s['name'].startswith('?'+calls[va]+'@'))
        raw, reloc = sections[symbol['section']-1]
        assert symbol['value'] == 0
        actual = list(md.disasm(raw,0))
        mapping = {}
        cursor = 0
        for record in b['instructions']:
            mapping[int(record['va'],16)] = cursor
            cursor += 11 if record['va']=='0059ad2e' else 1
        assert len(actual)==cursor, (variant,b['va'],len(actual),cursor)
        for record in b['instructions']:
            orig_va = int(record['va'],16)
            index = mapping[orig_va]
            a = actual[index]
            original = next(md.disasm(bytes.fromhex(record['raw']),orig_va))
            if orig_va == 0x59ad2e:
                expansion = actual[index:index+11]
                expected = [('pushfd',''),('test','eax, 1'),('je',None),('cmp','eax, 1'),
                            ('je',None),('popfd',''),('jmp',None),('popfd',''),
                            ('jmp',None),('popfd',''),('jmp',None)]
                for ins,(mnemonic,operands) in zip(expansion,expected):
                    assert ins.mnemonic==mnemonic and (operands is None or ins.op_str==operands)
                for which,target in ((2,index+7),(4,index+9),(6,mapping[0x59ad47]),
                                     (8,mapping[0x59ad35]),(10,mapping[0x59ad3f])):
                    assert expansion[which].operands[0].imm == actual[target].address
                continue
            assert a.mnemonic == original.mnemonic, (variant,record,a.mnemonic)
            if a.mnemonic == 'call':
                name, kind = reloc[a.address+a.imm_offset]
                assert kind==20 and name.startswith('?'+calls[original.operands[0].imm]+'@')
                continue
            if a.mnemonic.startswith('j'):
                assert a.operands[0].imm == actual[mapping[original.operands[0].imm]].address
                continue
            assert len(a.operands)==len(original.operands)
            for x,y in zip(a.operands,original.operands):
                assert x.type==y.type and x.size==y.size, (variant,record,a.op_str)
                if x.type==cs.x86.X86_OP_REG:
                    assert x.reg==y.reg
                elif x.type==cs.x86.X86_OP_IMM:
                    assert x.imm==y.imm
                elif x.type==cs.x86.X86_OP_MEM:
                    assert (x.mem.base,x.mem.index,x.mem.scale,x.mem.segment)==(y.mem.base,y.mem.index,y.mem.scale,y.mem.segment)
                    if y.mem.disp in data:
                        binding = data[y.mem.disp].split('+')
                        name,kind = reloc[a.address+a.disp_offset]
                        assert kind==6 and name.startswith('?'+binding[0]+'@')
                        assert x.mem.disp==(int(binding[1],0) if len(binding)>1 else 0)
                    else:
                        assert x.mem.disp==y.mem.disp, (variant,record,a.op_str)
        results.append({'variant':variant,'va':b['va'],'instructions':len(actual),
                        'original_bytes':b['bytes'],'object_sha256':sha(path),'PASS':True})

# Inspect all original accepted source/header owners, not only source/recovered.
ownership_hits = []
patterns = [re.compile(r'(?<![0-9a-f])(?:00)?'+f'{va:x}'+r'(?![0-9a-f])', re.I) for va in data]
for name,expected in scope['closure_sha256'].items():
    path = ROOT / name
    assert sha(path)==expected, 'accepted source closure drift: '+name
    text = path.read_text(encoding='utf-8-sig')
    for line_no,line in enumerate(text.splitlines(),1):
        if any(p.search(line) for p in patterns):
            ownership_hits.append({'file':name,'line':line_no,'text':line})
assert not ownership_hits, ownership_hits
source = (RUN/'audio_coded_kernel_552.cpp').read_text()
assert not any(word in source for word in ('VirtualAlloc','memcpy','raw_DECODE','1.75','fldcw','fninit'))
report = {'PASS':True,'original_sha256':evidence['original_sha256'],
          'audit_source_sha256':sha(Path(__file__)),'source_sha256':sha(RUN/'audio_coded_kernel_552.cpp'),
          'static_instruction_checks':results,'accepted_closure_owners_checked':len(scope['closure_sha256']),
          'data_owner_hits':ownership_hits,'limits':['masked FP exceptions; 0..5 incoming live x87 slots',
          'malformed/unmasked/extra-capacity or invalid-stack domains not accepted']}
target = ROOT/'local/reports'/('552-fp-static-audit-'+args.attempt+'.json')
target.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
print('Run552 static source/COFF audit PASS:',len(results),'bodies/variants; closure',len(scope['closure_sha256']))
