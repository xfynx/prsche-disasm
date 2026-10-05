"""Replay unmodified original Base and primitive readers; not a scene loader.

Finite, bounded synthetic payloads and sampled real track primitives are supplied.
No allocation/renderer calls, patches or emulated original callees are used.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import random
import struct
import subprocess

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('support', HERE / 'replay-support-polygons.py')
support = importlib.util.module_from_spec(spec)
spec.loader.exec_module(support)
response = support.response
spec = importlib.util.spec_from_file_location('crp', HERE / 'inspect_crp.py')
crp = importlib.util.module_from_spec(spec)
spec.loader.exec_module(crp)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX,
                               UC_X86_REG_EDI, UC_X86_REG_ESI, UC_X86_REG_ESP,
                               UC_X86_REG_EIP, UC_X86_REG_EFLAGS)

PR = 0x2300000
OUT = response.CAR + 0x300
TAGS = [0x76742020, 0x6e6d2020, 0x75762020, 0x64662020,
        0x42617365, 0x70722020, 0x65662020]
VERTICES, STEPS, SHIFTS = [0, 3, 2, 3, 4], [0, 1, 2, 3, 4], [0, 0, 1, -1, 2]


def u16(data, offset):
    return struct.unpack_from('<H', data, offset)[0]


def u32(data, offset):
    return struct.unpack_from('<I', data, offset)[0]


def reference_descriptor(payload, tag, occurrence):
    for i in range(u32(payload, 0x28)):
        offset = 0x30 + i * 16
        kind = u16(payload, offset + 10)
        actual = TAGS[kind] if kind < 256 else (kind << 16) | 0x2020
        if actual == tag:
            if occurrence == 0:
                return offset
            occurrence -= 1
    return None


def reference_indices(payload, polygon, base, row):
    kind = u16(payload, 0)
    step = (STEPS[kind] * polygon) & 0xffffffff
    if row == 65535:
        return [(base + step + i) & 0xffffffff for i in range(VERTICES[kind])]
    ni, nd = u32(payload, 0x28), u32(payload, 0x2c)
    offset = 48 + 16*ni + 8*nd + u32(payload, 52 + 8*(row+2*ni)) + step
    return [(base + value) & 0xffffffff for value in payload[offset:offset+VERTICES[kind]]]


def primitive_case(uc, name, payload, total, polygon, base, row, tag, occurrence):
    if len(payload) > 0x100000:
        raise RuntimeError('primitive exceeds replay buffer')
    uc.mem_write(PR, payload)
    count = support.execute(uc, 0x5a0b70, [], PR)
    polygons = support.execute(uc, 0x5a0b80, [total], PR)
    descriptor = support.execute(uc, 0x5a0c50, [tag, occurrence], PR)
    support.words(uc, OUT, [0xdeadbeef]*4)
    returned = support.execute(uc, 0x5a0bc0, [polygon, OUT, base, row], PR)
    assert returned & 255 == 1
    indices = list(struct.unpack('<'+'I'*count, uc.mem_read(OUT, count*4))) if count else []
    assert bytes(uc.mem_read(OUT+4*count, 4)) == struct.pack('<I', 0xdeadbeef) if count < 4 else True
    kind = u16(payload, 0)
    remainder = (total-VERTICES[kind]) & 0xffffffff
    expected_count = ((remainder//3 if SHIFTS[kind] < 0 else remainder >> SHIFTS[kind])+1) & 0xffffffff
    descriptor_offset = descriptor-PR if descriptor else None
    assert count == VERTICES[kind], name
    assert polygons == expected_count, name
    assert descriptor_offset == reference_descriptor(payload, tag, occurrence), name
    assert indices == reference_indices(payload, polygon, base, row), name
    channels = []
    # Execute precisely the two descriptor and index helper calls selected by
    # the support consumer, including its two different offset shifts.
    for channel_tag, shift in ((TAGS[0], 4), (TAGS[3], 2)):
        pointer = support.execute(uc, 0x5a0c50, [channel_tag, 0], PR)
        if not pointer:
            raise RuntimeError(f'{name}: missing support channel')
        channel_offset = pointer-PR
        channel_base = u32(payload, channel_offset+4) >> shift
        channel_row = u16(payload, channel_offset+14)
        support.execute(uc, 0x5a0bc0, [polygon, OUT, channel_base, channel_row], PR)
        actual = list(struct.unpack('<'+'I'*count, uc.mem_read(OUT, 4*count))) if count else []
        assert actual == reference_indices(payload, polygon, channel_base, channel_row), name
        channels.append(actual)
    return [name, payload.hex(), total, polygon, base, row, tag, occurrence,
            count, polygons, '-' if descriptor_offset is None else descriptor_offset,
            ','.join(map(str, indices)) or '-',
            ','.join(map(str, channels[0])) or '-', ','.join(map(str, channels[1])) or '-']


def synthetic(kind, rng):
    descriptors = [(0, 16*7+3, 0), (3, 4*11+1, 1), (0, 16*19, 65535)]
    descriptors += [(i, 0, 65535) for i in (1, 2, 4, 5, 6, 0x6162)]
    payload = bytearray(48 + 16*len(descriptors) + 16 + 256)
    struct.pack_into('<I', payload, 0, 0xa5a50000 | kind)
    struct.pack_into('<II', payload, 40, len(descriptors), 2)
    for i, (tag, offset, row) in enumerate(descriptors):
        struct.pack_into('<I', payload, 52+i*16, offset)
        struct.pack_into('<H', payload, 58+i*16, tag)
        struct.pack_into('<H', payload, 62+i*16, row)
    row_start = 48 + 16*len(descriptors)
    struct.pack_into('<4I', payload, row_start, 0x11111111, 13, 0x22222222, 73)
    start = row_start+16
    payload[start:] = bytes(rng.randrange(256) for _ in range(256))
    return bytes(payload)


def base_case(uc, name, payload):
    uc.mem_write(PR, payload)
    uc.reg_write(UC_X86_REG_ESI, PR)
    uc.reg_write(UC_X86_REG_ESP, response.STACK)
    # Stop BEFORE the branch at 475164; the original flags and selected mask
    # address have both been computed and stored by the preceding instructions.
    def slice_until(start, end):
        def stop(machine, address, _size, _user):
            if address == end:
                machine.emu_stop()
        hook = uc.hook_add(UC_HOOK_CODE, stop)
        try:
            uc.emu_start(start, response.EXIT, count=100)
        finally:
            uc.hook_del(hook)
        assert uc.reg_read(UC_X86_REG_EIP) == end
    slice_until(0x475152, 0x475164)
    ordinal = u32(payload, 4)
    pointer = uc.reg_read(UC_X86_REG_EDI)
    assert pointer == PR + 100 + 12*ordinal
    skipped = not bool(uc.reg_read(UC_X86_REG_EFLAGS) & 0x40)
    assert skipped == bool(payload[0] & 0x40)
    stored, = struct.unpack('<I', uc.mem_read(response.STACK+0x18, 4))
    assert stored == pointer
    offset = pointer-PR
    # Isolated static-path consumers: preparation deliberately excludes the
    # earlier special-collider lookup and branch. No lookup result is stubbed.
    slice_until(0x47516a, 0x475174)
    resource = uc.reg_read(UC_X86_REG_EDX)
    slice_until(0x47533a, 0x47533d)
    enabled = not bool(uc.reg_read(UC_X86_REG_EFLAGS) & 0x40)
    slice_until(0x475343, 0x47534f)
    first, last = uc.reg_read(UC_X86_REG_ECX), uc.reg_read(UC_X86_REG_EAX)
    assert enabled == bool(payload[offset])
    assert (first, last, resource) == struct.unpack_from('<3H', payload, offset+4)
    return [name, payload.hex(), int(skipped), ordinal, offset, int(enabled), first, last, resource]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--run-dir', type=Path, required=True)
    parser.add_argument('--source-output', type=Path, required=True)
    args = parser.parse_args()
    module, = [m for m in map(json.loads, (response.ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()) if m['file'] == 'Porsche.exe']
    data = (response.ROOT / 'local/game' / module['path']).read_bytes()
    if response.hashlib.sha256(data).hexdigest() != response.SHA or module['sha256'] != response.SHA:
        raise RuntimeError('original SHA256 mismatch')
    uc = response.machine(module, data, ((0x5a0b70, 0x5a0ca9+1), (0x475152, 0x475175),
                                       (0x47533a, 0x475350)))
    uc.mem_map(PR, 0x100000)
    rng = random.Random(0x4750b0)
    rows = []
    for kind in range(5):
        payload = synthetic(kind, rng)
        for i in range(40):
            total = ([0, 1, 2, 3, 4, 5, 12, 255, 0xfffffffe, 0xffffffff][i % 10]
                     if i < 20 else rng.randrange(10000))
            row = [0, 1, 65535][i % 3]
            polygon = rng.randrange(20) if row != 65535 else [0, 1, 0x7fffffff, 0xffffffff][i % 4]
            # Channel helper calls always use indexed rows, so keep their
            # polygon bounded even when probing wraparound on the supplied row.
            if row == 65535 and polygon > 20:
                # Separate huge-polygon fixtures have sequential support channels.
                payload = bytearray(payload)
                struct.pack_into('<H', payload, 62, 65535)
                struct.pack_into('<H', payload, 78, 65535)
                payload = bytes(payload)
            else:
                payload = synthetic(kind, rng)
            tag = (TAGS + [0x61622020, 0x7a7a2020])[i % 9]
            rows.append(primitive_case(uc, f'synthetic_{kind}_{i}', payload, total, polygon,
                                       [0, 7, 0xfffffffe, 0xffffffff][i % 4], row, tag, i % 3))
    bases = []
    for flags in (0, 0x10, 0x40, 0x50, 0x80):
        for ordinal in (0, 1, 3):
            for enabled in (0, 1, 0x80):
                payload = bytearray(148)
                struct.pack_into('<4I', payload, 0, flags, ordinal, 0, 4)
                for j in range(4):
                    struct.pack_into('<I4H', payload, 100+12*j, (0x11223300 | enabled) if j == ordinal else 0,
                                     j*4096, j*4096+255, 65535-j, 0xbeef)
                bases.append(base_case(uc, f'base_{flags}_{ordinal}_{enabled}', bytes(payload)))
    census = []
    source_hashes = {}
    for path in sorted((response.ROOT / 'local/game/GameData/Track').glob('*.crp')):
        source = path.read_bytes()
        decoded = crp.dec(source)
        assert decoded[:4] == b'karT'
        source_hashes[path.name] = response.hashlib.sha256(source).hexdigest()
        articles = crp.u32(decoded, 4) >> 5
        start = crp.u32(decoded, 12)*16
        histogram = {}
        sample_kinds = set()
        base_count = 0
        for article in (crp.entry(decoded, start+16*i) for i in range(articles)):
            for entry in article.get('entries', []):
                payload = decoded[entry['target']:entry['target']+entry['length']]
                if entry['tag'] == 'Base':
                    base_count += 1
                    if base_count == 1:
                        bases.append(base_case(uc, f'{path.stem}_base', payload))
                if entry['tag'] != 'pr':
                    continue
                kind = u16(payload, 0)
                histogram[kind] = histogram.get(kind, 0)+1
                if kind in sample_kinds:
                    continue
                sample_kinds.add(kind)
                descriptor = reference_descriptor(payload, TAGS[0], 0)
                base = u32(payload, descriptor+4) >> 4
                row = u16(payload, descriptor+14)
                remainder = entry['count']-VERTICES[kind]
                polygons = (remainder//3 if SHIFTS[kind]<0 else remainder >> SHIFTS[kind])+1
                for polygon in sorted(set([0, polygons//2, polygons-1])):
                    rows.append(primitive_case(uc, f'{path.stem}_pr{entry["index"]}_{kind}_{polygon}', payload,
                                               entry['count'], polygon, base, row, TAGS[0], 0))
        census.append([f'GameData/Track/{path.name}', base_count, sum(histogram.values()),
                       ','.join(f'{k}:{v}' for k, v in sorted(histogram.items()))])
    if len(census) != 15:
        raise RuntimeError(f'expected 15 tracks, found {len(census)}')
    args.run_dir.mkdir(parents=True, exist_ok=True)
    def tsv(name, header, records):
        (args.run_dir/name).write_text(header+'\n'+''.join('\t'.join(map(str,row))+'\n' for row in records), encoding='utf-8')
    tsv('primitive-fixtures.tsv', 'name\tpayload\ttotal\tpolygon\tbase\trow\ttag\toccurrence\tvertices\tpolygons\tdescriptor\tindices\tvt_indices\tdf_indices', rows)
    tsv('base-fixtures.tsv', 'name\tpayload\tskipped\tordinal\toffset\tenabled\tfirst\tlast\tresource', bases)
    tsv('primitive-census.tsv', 'path\tbases\tprimitives\ttype_histogram', census)
    report = {'module': 'Porsche.exe', 'sha256': response.SHA,
              'primitive_payload_cases': len(rows), 'primitive_helper_outputs': len(rows)*8,
              'base_slice_cases': len(bases), 'track_census': census,
              'resource_sha256': source_hashes,
              'excluded': ['Base ordinal producer', 'special collider lookup', 'alternate primitives',
                           'degeneracy', 'polygon construction', 'spatial insertion', 'runtime binding']}
    (args.run_dir/'assembly-replay.json').write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    sources = [{'module': 'Porsche.exe', 'sha256': response.SHA}]
    for address in (0x4750b0, 0x5a0b70, 0x5a0b80, 0x5a0bc0, 0x5a0c50):
        output = subprocess.check_output(['py', '-3', str(HERE/'query-binary-index.py'), '--binary', 'Porsche.exe',
                                          '--address', hex(address), '--disassemble', '--limit', '2000'],
                                         cwd=response.ROOT, text=True, encoding='utf-8')
        sources.extend(json.loads(line) for line in output.splitlines()
                       if json.loads(line).get('kind') in ('function', 'disassembly'))
    args.source_output.parent.mkdir(parents=True, exist_ok=True)
    args.source_output.write_text(''.join(json.dumps(record)+'\n' for record in sources), encoding='utf-8')
    constants = []
    for address, size, extra in ((0x5e5084, 28, ['--words']), (0x5e5138, 60, ['--words']), (0x477d40, 0x6b, [])):
        constants.append(subprocess.check_output(['py', '-3', str(HERE/'inspect-pe-range.py'), '--binary', 'Porsche.exe',
                                                  '--address', hex(address), '--size', hex(size), *extra],
                                                 cwd=response.ROOT, text=True, encoding='utf-8'))
    args.source_output.with_name('support-assembly-constants.txt').write_text('\n'.join(constants), encoding='utf-8')
    print(f'{len(rows)} primitive payloads / {len(rows)*8} helper outputs; {len(bases)} Base slices; 15-track census passed')


if __name__ == '__main__':
    main()
