"""Reproduce topology loader evidence; do not infer physical meaning from flags."""
import argparse
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path

import capstone


def pe_sections(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    if data[pe:pe + 4] != b'PE\0\0':
        raise ValueError('Expected PE signature')
    count = struct.unpack_from('<H', data, pe + 6)[0]
    optional_size = struct.unpack_from('<H', data, pe + 20)[0]
    if struct.unpack_from('<H', data, pe + 24)[0] != 0x10b:
        raise ValueError('Expected PE32')
    image_base = struct.unpack_from('<I', data, pe + 52)[0]
    sections = []
    for index in range(count):
        start = pe + 24 + optional_size + index * 40
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from('<4I', data, start + 8)
        sections.append(dict(name=data[start:start + 8].rstrip(b'\0').decode('ascii'),
                             rva=rva, virtual_size=virtual_size,
                             raw_size=raw_size, raw_offset=raw_offset))
    return image_base, sections


def raw_offset(sections, rva, size):
    for section in sections:
        offset = rva - section['rva']
        if 0 <= offset and offset + size <= section['raw_size']:
            return section['raw_offset'] + offset
    raise ValueError(f'RVA 0x{rva:x} length {size} has no contiguous file mapping')


def main():
    root = Path(__file__).resolve().parents[2]
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--game-dir', type=Path, default=root / 'local/game')
    parser.add_argument('--output', type=Path, default=root / 'local/research/005-unified-driving')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    exe = args.game_dir / 'nfs5.exe'
    data = exe.read_bytes()
    base, sections = pe_sections(data)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    # Addresses inherited from 004, not automatically established function bounds.
    probes = [(0x48789f, 160), (0x481080, 700), (0x488090, 300),
              (0x487e80, 640), (0x485100, 384), (0x440ee0, 256)]
    reports = []
    for va, size in probes:
        rva = va - base
        offset = raw_offset(sections, rva, size)
        sample = data[offset:offset + size]
        name = f'nfs5-rva-{rva:08x}.asm.txt'
        lines = [f'; SHA256 {hashlib.sha256(data).hexdigest()}',
                 f'; image_base=0x{base:x} RVA=0x{rva:x} raw=0x{offset:x}',
                 '; Linear decode window; boundaries and branch paths require validation.']
        lines.extend(f'{ins.address:08x}  {ins.bytes.hex():<22} {ins.mnemonic} {ins.op_str}'
                     for ins in decoder.disasm(sample, va))
        (args.output / name).write_text('\n'.join(lines) + '\n', encoding='utf-8')
        reports.append(dict(va=hex(va), rva=hex(rva), raw_offset=hex(offset),
                            size=size, artifact=name))
    tracks = []
    for path in sorted((args.game_dir / 'GameData/Track').glob('*.edg')):
        edges = path.read_bytes()
        if len(edges) < 4 or (len(edges) - 4) % 28:
            raise ValueError(f'Invalid EDG length: {path.name}')
        flags = Counter(edges[index] for index in range(4, len(edges), 28))
        jnc = path.with_suffix('.jnc').read_bytes()
        if len(jnc) % 36:
            raise ValueError(f'Invalid JNC length: {path.stem}')
        tracks.append(dict(track=path.stem, edg_sha256=hashlib.sha256(edges).hexdigest(),
                           edge_records=(len(edges) - 4) // 28,
                           flag_counts={hex(k): v for k, v in sorted(flags.items())},
                           jnc_sha256=hashlib.sha256(jnc).hexdigest(), jnc_records=len(jnc) // 36))
    report = dict(module='nfs5.exe', sha256=hashlib.sha256(data).hexdigest(),
                  image_base=hex(base), sections=sections, probes=reports, tracks=tracks,
                  limitations=['Linear disassembly does not establish field consumers.',
                               'EDG flag meanings and JNC lap-checkpoint role remain unproven.'])
    (args.output / 'evidence.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f"module={report['sha256']} probes={len(probes)} tracks={len(tracks)}")


if __name__ == '__main__':
    main()
