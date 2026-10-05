"""Replay original spatial CHILD CONSTRUCTOR only; insertion remains unported.

0x483bd0 has no allocation calls. Supplied destination buffers are initialized
with nonzero sentinels; the original code is neither patched nor substituted.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import struct

spec = importlib.util.spec_from_file_location('support', Path(__file__).with_name('replay-support-polygons.py'))
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
DEST = response.CAR + 0x1000


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, required=True)
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (response.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()) if m['file']=='Porsche.exe']
    data = (response.ROOT/'local/game'/module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest() != response.SHA or module['sha256'] != response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    uc = response.machine(module, data, ((0x483bd0, 0x483c99),))
    parents = [0, 0xffffffff, 0xf0000000, 0x0fffffff, 0x00003fff, 0x0fffc000, 0x10000000, 0x88888888]
    rng = random.Random(0x483bd0)
    parents.extend(rng.randrange(0x100000000) for _ in range(24))
    rows = []
    for parent in parents:
        for selector in (0, 1, 2, 3, 4, 65535, 0x7fffffff, 0xffffffff):
            support.words(uc, DEST, [0xdeadbeef]*6)
            returned = support.execute(uc, 0x483bd0, [parent, selector], DEST)
            actual = list(struct.unpack('<6I', uc.mem_read(DEST, 24)))
            x = ((parent & 0x3fff)*2 + int(selector in (1, 3))) & 0x3fff
            z = (((parent >> 14) & 0x3fff)*2 + int(selector in (0, 1))) & 0x3fff
            packed = (((parent & 0xf0000000)+0x10000000) & 0xffffffff) | (z << 14) | x
            assert returned == DEST
            assert actual == [packed, 0, 0, 0, 0, 0], (parent, selector, actual)
            rows.append([parent, selector, *actual])
    args.run_dir.mkdir(parents=True, exist_ok=True)
    (args.run_dir/'insertion-child-fixtures.tsv').write_text('parent\tselector\tpacked\tchild0\tchild1\tchild2\tchild3\trecords\n'+
        ''.join('\t'.join(map(str,row))+'\n' for row in rows), encoding='utf-8')
    report = {'module': 'Porsche.exe', 'sha256': response.SHA, 'entry': '0x483bd0',
              'child_constructor_cases_passed': len(rows),
              'excluded': ['allocation', 'recursive insertion 0x484ae0', 'polygon intersection callbacks', 'runtime binding']}
    (args.run_dir/'insertion-child-replay.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    print(f'{len(rows)} original-x86 child constructor cases passed; recursive insertion remains open')


if __name__ == '__main__':
    main()
