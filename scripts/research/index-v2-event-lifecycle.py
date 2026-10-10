"""Index the two separately callable auxiliary-event entries missed by Ghidra."""
import argparse
import hashlib
import json
import re
from pathlib import Path

from v2_manual_index import records
from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
CORPUS = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d'
INDEX = ROOT / 'research/binary-index/manual-functions.jsonl'
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/126-event-integration'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--update-index', action='store_true')
    args = parser.parse_args()
    image = (ROOT / 'local/game/Porsche.exe').read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    modules = [json.loads(line) for line in
               (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()]
    module = next(row for row in modules if row['sha256'] == SHA)
    def offset(va):
        rva = va - int(module['image_base'], 16)
        section = next(row for row in module['sections']
                       if row['rva'] <= rva < row['rva'] + row['raw_size'])
        return section['raw_offset'] + rva - section['rva']
    automatic = [json.loads(line) for line in (CORPUS / 'functions.jsonl').read_text().splitlines()]
    listing = (CORPUS / 'disassembly.asm').read_text(encoding='utf-8').splitlines()
    indexed = records()
    added = []
    for start, end, reason in (
        (0x53c0f0, 0x53c167, 'Worker literal passed at0053c08f to0055f420; no automatic entry.'),
        (0x53c170, 0x53c1c6, 'Shutdown callback registered at0053c060; shared tail also belongs to automatic0053c1d0. This entry is not new code coverage.'),
    ):
        assert not any(int(row['entry_va'], 16) == start for row in automatic)
        body = image[offset(start):offset(end) + 1]
        assert len(body) == end - start + 1 and body[-1] == 0xc3
        cursor = start
        for line in listing:
            match = re.match(r'^([0-9a-f]{8})\s+([0-9a-f]+)\s+', line)
            if match and start <= int(match[1], 16) <= end:
                va, raw = int(match[1], 16), bytes.fromhex(match[2])
                assert va == cursor and image[offset(va):offset(va)+len(raw)] == raw
                cursor += len(raw)
        assert cursor == end + 1
        row = {'module': 'Porsche.exe', 'path': 'Porsche.exe', 'sha256': SHA,
               'entry_va': f'{start:08x}', 'name': f'recovered_{start:08x}',
               'status': 'manual-disassembly-index', 'ranges': [[f'{start:08x}', f'{end:08x}']],
               'file_offset': offset(start), 'body_bytes': len(body),
               'body_sha256': hashlib.sha256(body).hexdigest(), 'reason': reason,
               'signature': 'cdecl, zero arguments; full terminal RET included'}
        found = [entry for entry in indexed if entry['sha256'] == SHA and entry['entry_va'] == row['entry_va']]
        if found:
            assert found == [row], 'Existing entry evidence differs'
        elif args.update_index:
            with INDEX.open('ab') as stream:
                stream.write((json.dumps(row) + '\n').encode())
        added.append(row)
    for site, raw in ((0x53c08f, '68f0c05300'), (0x53c060, '6870c15300'),
                      (0x53c25c, 'e90fffffff')):
        assert image[offset(site):offset(site)+5] == bytes.fromhex(raw)
    report = {'schema': 1, 'kind': 'static entry evidence; not runtime acceptance',
              'module_sha256': SHA, 'entries': added, 'manual_function_count': len(records()),
              'shared_tail': {'entry': '0053c170', 'automatic_owner': '0053c1d0',
                              'new_instruction_coverage': False},
              'source_sha256': source_hashes([Path(__file__), INDEX,
                  CORPUS/'functions.jsonl', CORPUS/'disassembly.asm',
                  ROOT/'research/binary-index/static/binaries.jsonl'])}
    RUN.mkdir(parents=True, exist_ok=True)
    (RUN / 'event-index.json').write_bytes((json.dumps(report, indent=2)+'\n').encode())
    print(json.dumps({'entries': len(added), 'manual_functions': len(records())}))


if __name__ == '__main__':
    main()
