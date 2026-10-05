"""Replay the original static-support degeneracy branches and audit Base ordinals.

The branch slice executes unchanged Porsche.exe bytes. Supplied finite vertices
make the outcomes bounded; constructors and resource lookup are separate work.
"""
import argparse
import collections
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('support', HERE / 'replay-support-polygons.py')
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_ESI, UC_X86_REG_ESP
spec = importlib.util.spec_from_file_location('crp', HERE / 'inspect_crp.py')
crp = importlib.util.module_from_spec(spec)
spec.loader.exec_module(crp)


def replay(data, module, points):
    uc = response.machine(module, data, ((0x4755ae, 0x47580b), (0x475909, 0x47590a)))
    base = response.CAR + 0x800
    for index, point in enumerate(points):
        uc.mem_write(base + index * 16, struct.pack('<4f', *point, 0))
    uc.mem_write(response.STACK + 0x2c, struct.pack('<I', len(points)))
    uc.mem_write(response.STACK + 0x54, struct.pack('<3I', base, base + 16, base + 32))
    uc.reg_write(UC_X86_REG_ECX, base)
    uc.reg_write(UC_X86_REG_EDX, base + 16)
    uc.reg_write(UC_X86_REG_ESI, base + 32)
    uc.reg_write(UC_X86_REG_ESP, response.STACK)
    terminal = {}

    def stop(_uc, address, _size, _user):
        if address in (0x475909, 0x47562d, 0x47580a):
            terminal['address'] = address
            _uc.emu_stop()

    uc.hook_add(UC_HOOK_CODE, stop)
    uc.emu_start(0x4755ae, response.EXIT, count=100)
    if 'address' not in terminal:
        raise RuntimeError('original degeneracy slice exceeded its boundary')
    return terminal['address'] != 0x475909


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, default=Path('iterations/012-campaign-fidelity/runs/018-original-support-runtime'))
    parser.add_argument('--source-dir', type=Path, default=Path('iterations/012-campaign-fidelity/research/original-collision'))
    args = parser.parse_args()
    modules = [json.loads(line) for line in (response.ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()]
    module, = [entry for entry in modules if entry['file'] == 'Porsche.exe']
    data = (response.ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest() != response.SHA:
        raise RuntimeError('original Porsche.exe SHA256 mismatch')
    cases = [
        ('triangle_valid', [[0,0,0],[1,0,0],[0,0,1]]),
        ('triangle_equal_xz', [[0,0,0],[0,2,0],[0,4,0]]),
        ('triangle_duplicate_01', [[0,0,0],[0,0,0],[0,0,1]]),
        ('triangle_duplicate_02', [[0,0,0],[1,0,0],[0,0,0]]),
        ('triangle_duplicate_12', [[0,0,0],[1,0,0],[1,0,0]]),
        ('triangle_same_xz_two', [[0,0,0],[0,2,0],[1,0,1]]),
        ('quad_valid', [[0,0,0],[1,0,0],[0,0,1],[1,0,1]]),
        ('quad_equal_xz_first_three', [[0,0,0],[0,2,0],[0,4,0],[1,0,1]]),
        ('quad_duplicate_01', [[0,0,0],[0,0,0],[0,0,1],[1,0,1]]),
    ]
    results = [(name, points, replay(data, module, points)) for name, points in cases]
    histogram = collections.Counter()
    masks = collections.Counter()
    base_flags = collections.Counter()
    library_static = collections.Counter()
    out_of_bounds = 0
    source_hashes = {}
    for path in sorted((response.ROOT/'local/game/GameData/Track').glob('*.crp')):
        raw = path.read_bytes()
        source_hashes[path.name] = hashlib.sha256(raw).hexdigest()
        decoded = crp.dec(raw)
        article_count = crp.u32(decoded, 4) >> 5
        start = crp.u32(decoded, 12) * 16
        for index in range(article_count):
            article = crp.entry(decoded, start + index * 16)
            for entry in article.get('entries', []):
                if entry['tag'] == 'Base':
                    payload = decoded[entry['target']:entry['target']+entry['length']]
                    ordinal = crp.u32(payload, 4)
                    count = crp.u32(payload, 12)
                    base_flags['library_bit_8000' if crp.u32(payload, 0) & 0x8000 else 'ordinary'] += 1
                    if crp.u32(payload, 0) & 0x8000:
                        library_static[(bool(payload[0x64]), bool(crp.u32(payload, 0x44)))] += 1
                    histogram[ordinal] += 1
                    masks[count] += 1
                    out_of_bounds += ordinal >= count
    args.run_dir.mkdir(parents=True, exist_ok=True)
    report = dict(module='Porsche.exe', sha256=response.SHA,
                  original_branch_cases=[dict(name=n, points=p, accepted=a) for n,p,a in results],
                  base_ordinal_histogram=dict(histogram), base_mask_count_histogram=dict(masks),
                  base_scene_group_histogram=dict(base_flags),
                  library_initial_mask_tag_histogram={str(k): v for k,v in library_static.items()},
                  base_initial_out_of_bounds=out_of_bounds, resource_sha256=source_hashes,
                  limitation='Raw Base+4 census is not a traced runtime ordinal producer')
    (args.run_dir/'support-loader-replay.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    rows = ['name\tcount\tpoints\taccepted']
    rows.extend(f'{name}\t{len(points)}\t{json.dumps(points,separators=(",",":"))}\t{int(accepted)}' for name,points,accepted in results)
    (args.run_dir/'support-loader-fixtures.tsv').write_text('\n'.join(rows)+'\n', encoding='utf-8')
    sources = [dict(module='Porsche.exe', sha256=response.SHA)]
    for address in (0x43cd50, 0x59f700, 0x4510f0, 0x4750b0, 0x4874a0,
                    0x4876e0, 0x4879d0, 0x488090, 0x473240):
        output = subprocess.check_output(['py', '-3', str(HERE/'query-binary-index.py'),
                                          '--binary', 'Porsche.exe', '--address', hex(address),
                                          '--disassemble', '--limit', '2000'],
                                         cwd=response.ROOT, text=True, encoding='utf-8')
        sources.extend(record for record in map(json.loads, output.splitlines())
                       if record.get('kind') in ('function', 'disassembly'))
    args.source_dir.mkdir(parents=True, exist_ok=True)
    (args.source_dir/'support-loader-source.jsonl').write_text(
        ''.join(json.dumps(record)+'\n' for record in sources), encoding='utf-8')
    groups = []
    for address, size in ((0x5b47e0, 0x10), (0x5b4718, 0x10),
                          (0x482970, 0x310), (0x4781a0, 0x400)):
        command = ['py', '-3', str(HERE/'inspect-pe-range.py'), '--binary', 'Porsche.exe',
                   '--address', hex(address), '--size', hex(size)]
        if address >= 0x5b0000:
            command.append('--words')
        groups.append(subprocess.check_output(command, cwd=response.ROOT, text=True, encoding='utf-8'))
    (args.source_dir/'support-loader-article-groups.txt').write_text('\n'.join(groups), encoding='utf-8')
    print(f'{len(results)} original branch cases; Base ordinal histogram {dict(histogram)}; out of bounds {out_of_bounds}')


if __name__ == '__main__':
    main()
