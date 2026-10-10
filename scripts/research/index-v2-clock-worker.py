"""Index the timer-thread entry omitted by the automatic function catalog."""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

from v2_source_dependencies import source_hashes
from v2_manual_index import records

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
START, END = 0x565270, 0x56533e
CORPUS = ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d'
INDEX = ROOT/'research/binary-index/manual-functions.jsonl'
RUN = ROOT/'iterations/v2/001-original-recovery/runs/110-clock-worker-index'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--update-index', action='store_true')
    args = parser.parse_args()
    data = (ROOT/'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA
    # Resolve only raw-backed addresses; BSS is never read as file bytes.
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    section_count = struct.unpack_from('<H', data, pe+6)[0]
    optional_size = struct.unpack_from('<H', data, pe+20)[0]
    sections = pe+24+optional_size
    def offset(va):
        for i in range(section_count):
            size, rva, raw_size, raw_offset = struct.unpack_from('<IIII', data, sections+i*40+8)
            delta = va-0x400000-rva
            if 0 <= delta < max(size, raw_size):
                if delta >= raw_size:
                    raise ValueError('BSS address has no source file bytes')
                return raw_offset+delta
        raise ValueError('Address outside PE sections')
    body = data[offset(START):offset(END)+1]
    assert len(body) == 207 and body[-1] == 0xc3
    automatic = [json.loads(line) for line in (CORPUS/'functions.jsonl').read_text().splitlines()]
    for row in automatic:
        for lo, hi in row['ranges']:
            assert int(hi,16) < START or int(lo,16) > END, row['entry_va']
    lines = (CORPUS/'disassembly.asm').read_text(encoding='utf8').splitlines()
    instructions = []
    for line in lines:
        m = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]+)\s+(.*)$', line)
        if m and START <= int(m[1],16) <= END:
            instructions.append((int(m[1],16),bytes.fromhex(m[2]),m[3]))
    cursor = START
    for va, raw, text in instructions:
        assert va == cursor and data[offset(va):offset(va)+len(raw)] == raw
        cursor += len(raw)
    assert cursor == END+1
    assert data[offset(0x565135):offset(0x565135)+5] == b'\x68'+struct.pack('<I',START)
    assert data[offset(0x56513a):offset(0x56513a)+5] == b'\xe8'+struct.pack('<i',0x55f420-0x56513f)
    imports = [json.loads(line) for line in (ROOT/'research/binary-index/static/imports.jsonl').read_text().splitlines()]
    tick_import = [x for x in imports if x['path']=='Porsche.exe' and x['iat_rva']=='0x1b2080']
    assert len(tick_import)==1 and tick_import[0]['symbol']=='GetTickCount'
    record = {'module':'Porsche.exe','path':'Porsche.exe','sha256':SHA,
        'entry_va':f'{START:08x}','name':f'recovered_{START:08x}',
        'status':'manual-disassembly-index','ranges':[[f'{START:08x}',f'{END:08x}']],
        'file_offset':offset(START),'body_bytes':len(body),
        'body_sha256':hashlib.sha256(body).hexdigest(),
        'reason':'Timer setup00565030 passes this entry at00565135 to0055f420. Contiguous207-byte ASM through RET; Run110 records static clock/state evidence, not a recovered C++ body.',
        'signature':'cdecl, zero arguments; thread bootstrap CALL/no-argument convention requires separate integration proof'}
    indexed = records()
    found = [x for x in indexed if x['sha256']==SHA and x['entry_va']==record['entry_va']]
    if args.update_index:
        if found:
            assert found == [record], 'Existing evidence differs; inspect before replacement'
        else:
            with INDEX.open('ab') as stream:
                stream.write((json.dumps(record)+'\n').encode())
        assert any(x['entry_va']==record['entry_va'] for x in records())
    report = {'schema':1,'kind':'static original clock-worker evidence; no C++ recovery or runtime acceptance',
        'sha256':SHA,'function':record,'automatic_index_omitted_entry':True,
        'contiguous_listing_instructions':len(instructions),'caller':{'function':'00565030','push_site':'00565135','call_site':'0056513a','callee':'0055f420'},
        'tick_import':tick_import[0],
        'observed_updates':{'006b7c40':'increment by1 per enabled loop iteration',
            '006b7c7c':'increment by1 per enabled loop iteration',
            '006b7c44':'signed accumulator carry via SAR16; raw scale1193 per GetTickCount delta',
            '006a5bfc':'event create/wait/close handle; cleared on return',
            '005deb48':'cleared on return; canonical owner timer_rate_005deb48 in file_events.cpp'},
        'callback_slots':{'start':'006b7c20','count':8,'stride':4,'call':'zero-argument indirect CALL when non-null'},
        'next_trace':'Recover worker00565270 and setup00565030/cleanup00564fa0; integrate real event/timer producers before WM_CLOSE terminal-path validation.',
        'native_cpp_equal_original_x86':False,
        'source_sha256':source_hashes([Path(__file__),INDEX,CORPUS/'functions.jsonl',CORPUS/'disassembly.asm',ROOT/'research/binary-index/static/imports.jsonl',RUN/'README.md'])}
    RUN.mkdir(parents=True,exist_ok=True)
    (RUN/'clock-worker-index.json').write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print(json.dumps({'indexed':bool(found or args.update_index),'body_bytes':len(body),'instructions':len(instructions),'manual_functions':len(records())}))


if __name__=='__main__':
    main()
