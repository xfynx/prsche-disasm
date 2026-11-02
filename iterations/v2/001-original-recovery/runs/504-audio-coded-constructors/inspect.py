"""Bounded raw/index/ownership evidence for proposed Run504; no recovery code."""
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
OUT = ROOT/'local/experiments/v2-audio-coded-constructors-504/inspection-002'
sys.path.insert(0,str(ROOT/'scripts/research'))
import capstone
import v2_source_dependencies as dependencies

spec = importlib.util.spec_from_file_location('native504',ROOT/'scripts/research/verify-v2-native-batch.py')
native = importlib.util.module_from_spec(spec)
spec.loader.exec_module(native)
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
SPANS = {0x597f20:65,0x59c360:90,0x597dc0:93,0x59c9f0:91,0x59c610:118,0x59b830:100,
         0x597db0:8,0x597e20:11,0x59a800:190,0x59a8c0:74,
         0x5984d0:351,0x59a3e0:235,0x599a00:39,
         0x597c40:363,0x597e30:232,0x59c1e0:384,0x59c3c0:592,0x59c890:352,0x59b690:404,
         0x59a5a0:185,0x59a660:200,0x59a730:201,0x59a910:706,0x59abe0:397,
         0x598760:472}


def main():
    assert not OUT.exists(), 'immutable inspection exists'
    raw = (ROOT/'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    md = capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
    index_dir = ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    indexed = {int(row['entry_va'],16):row for row in map(json.loads,(index_dir/'functions.jsonl').read_text().splitlines())}
    references = list(map(json.loads,(index_dir/'references.jsonl').read_text().splitlines()))
    functions = []
    for va,size in SPANS.items():
        data = native.pe_at(raw,va,size)
        instructions = [dict(va=f'{ins.address:08x}',raw=ins.bytes.hex(),asm=f'{ins.mnemonic} {ins.op_str}'.strip()) for ins in md.disasm(data,va)]
        functions.append(dict(va=f'{va:08x}',raw_span_bytes=size,sha256=hashlib.sha256(data).hexdigest(),
            indexed=indexed.get(va),instructions=instructions,
            returns=[ins for ins in instructions if ins['asm'].startswith('ret')],
            direct_calls=[ins for ins in instructions if ins['asm'].startswith('call')]))
    build_path = ROOT/'iterations/v2/001-original-recovery/runs/491-callback-pixel-pcm-integration/build-001.json'
    config_path = build_path.with_name('build-config.json')
    build,config = json.loads(build_path.read_text()),json.loads(config_path.read_text())
    roots = list(build['compiled_source_roots'])
    roots.extend(['iterations/v2/001-original-recovery/runs/493-audio-pcm-constructors/audio_pcm_constructors_493.cpp',
                  'iterations/v2/001-original-recovery/runs/501-audio-pcm-stream-lookup/audio_pcm_stream_lookup_501.cpp'])
    dependencies.EXTRA_INCLUDE_DIRS = tuple(ROOT/path for path in config['source_include_dirs']) + (ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe',)
    closure = dependencies.source_hashes(roots)
    candidates = [*SPANS.keys(),0x5e34a0,0x5b2608,0x5b27b4,0x5c1804]
    hits = {}
    for va in candidates:
        pattern = re.compile(f'{va:08x}|{va:06x}',re.I)
        found = []
        for filename in closure:
            path = ROOT/filename
            if path.suffix not in ['.cpp','.h','.hpp','.inc']:
                continue
            for number,line in enumerate(path.read_text(encoding='utf-8').splitlines(),1):
                if pattern.search(line):
                    found.append(dict(file=filename,line=number,text=line.strip()))
        hits[f'{va:08x}'] = found
    registry = json.loads((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_text())
    overlaps = []
    for row in registry['functions']:
        if row.get('module') != 'Porsche.exe' or 'entry_va' not in row:
            continue
        accepted = int(row['entry_va'],16)
        accepted_ranges = indexed.get(accepted,{}).get('ranges',[[row['entry_va'],row['entry_va']]])
        for va in list(SPANS)[:10]:
            if any(int(a,16) < va+SPANS[va] and va <= int(b,16) for a,b in accepted_ranges):
                overlaps.append(dict(candidate=f'{va:08x}',accepted=row['entry_va'],source=row['source']))
    assert not overlaps, overlaps
    pe = struct.unpack_from('<I',raw,60)[0]
    table = pe+24+struct.unpack_from('<H',raw,pe+20)[0]
    sections = []
    for i in range(struct.unpack_from('<H',raw,pe+6)[0]):
        pos = table+i*40
        vsize,rva,rsize,offset = struct.unpack_from('<IIII',raw,pos+8)
        sections.append(dict(name=raw[pos:pos+8].split(b'\0')[0].decode(),rva=rva,bytes=vsize,flags=struct.unpack_from('<I',raw,pos+36)[0]))
    data = []
    for va,size in [(0x5e34a0,36),(0x5b2608,4),(0x5b27b4,4),(0x5c1804,4)]:
        cell = native.pe_at(raw,va,size)
        data.append(dict(va=f'{va:08x}',bytes=size,raw=cell.hex(),sha256=hashlib.sha256(cell).hexdigest(),
                         words=list(struct.unpack('<'+'I'*(size//4),cell)),
                         section=next(sec for sec in sections if sec['rva']<=va-0x400000<sec['rva']+sec['bytes']),
                         value=struct.unpack('<f',cell)[0] if size==4 else None))
    targets = {f'{va:08x}' for va in [0x59a8c0,0x5e34a0,0x5b2608,0x5b27b4,0x5c1804]}
    report = dict(schema=1,kind='scope-proposal-raw-evidence',original_sha256=SHA,
        queries=[f'{va:08x}' for va in SPANS],functions=functions,data=data,
        relevant_references=[row for row in references if row.get('to_va') in targets],
        cache469_hits=[f'{va:08x}' for va in SPANS if (ROOT/f'local/experiments/v2-frontier-469-rea/001/function-{va:08x}.json').exists()],
        ownership=dict(build491_sha256=hashlib.sha256(build_path.read_bytes()).hexdigest(),
                       source_roots=len(roots),closure_files=len(closure),source_sha256=closure,
                       registry_candidate_overlaps=overlaps,
                       address_hits=hits,registry_sha256=hashlib.sha256((ROOT/'iterations/v2/001-original-recovery/source/recovered/functions.json').read_bytes()).hexdigest()),
        inspect_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        boundaries=['No recovery implementation/native proof in this inspection',
                    'Callback raw spans384/592/352 include trailing padding; exact callback recovery extents remain deferred',
                    '36-byte mask span is nine actual0..8 cells; do not infer a33-entry bitmask table or broad data arena'])
    OUT.mkdir(parents=True)
    (OUT/'inspect.py').write_bytes(Path(__file__).read_bytes())
    (OUT/'evidence.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    (RUN/'scope-evidence.json').write_bytes((OUT/'evidence.json').read_bytes())
    print(json.dumps(dict(functions=len(functions),source_roots=len(roots),closure_files=len(closure),data=data,
                         data_ownership_hits={f'{va:08x}':hits[f'{va:08x}'] for va in [0x5e34a0,0x5b2608,0x5b27b4,0x5c1804]})))


if __name__ == '__main__':
    main()
