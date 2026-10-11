"""Verify initial CRT data, native relocations, and consumer bounds (no startup claim)."""
import argparse
import hashlib
import json
import struct
import subprocess
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
RANGES = {'iob': (0x5e54e8, 640), 'buffer': (0x6c0520, 4096),
          'invalid_record': (0x5e5f50, 36), 'preceding_bank': (0x6c01dc, 4),
          'handle_table': (0x6c01e0, 256), 'handle_limit': (0x6c02e0, 4),
          'null_narrow': (0x5c1a34, 7), 'null_wide': (0x5c1a24, 14)}
# Exact instructions establish extents independently of adjacency guesses.
CODE = {
    0x5a3683: 'b8e8545e00', 0x5a3691: '83c020',
    0x5a3697: '3d68575e00', 0x5a369c: '7cea',
    0x5ab4e1: 'bde0016c00', 0x5ab574: '83c504',
    0x5ab578: '81fde0026c00', 0x5ab582: '0f8c5effffff',
    0x5a9566: 'c705e0026c0020000000',
    0x5a958e: '83c624', 0x5a9570: '8d8680040000',
    0x5a0f62: 'c7058c575e008d3e5a00',
    0x5a0f6c: 'a388575e00', 0x5a0f7b: 'c70594575e00333e5a00',
    0x5abee8: '6a02e8336fffff59c3',
}


def mapped(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    for section in module['sections']:
        extent = max(section['raw_size'], section['vsize'])
        if section['rva'] <= rva and rva + size <= section['rva'] + extent:
            relative = rva - section['rva']
            backed = max(0, min(size, section['raw_size'] - relative))
            offset = section['raw_offset'] + relative
            return image[offset:offset + backed] + bytes(size - backed)
    raise AssertionError(f'unmapped original range {va:08x}+{size:x}')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', required=True, type=Path)
    parser.add_argument('--report-dir', required=True, type=Path)
    args = parser.parse_args()
    modules = [json.loads(line) for line in (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()]
    module = next(m for m in modules if m['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA == module['sha256']
    for va, raw in CODE.items():
        assert mapped(image, module, va, len(bytes.fromhex(raw))).hex() == raw, hex(va)
    index = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    refs = [json.loads(line) for line in (index / 'references.jsonl').read_text().splitlines()]
    wanted = {'005a3683': '005e54e8', '005a3697': '005e5768',
              '005a430a': '006c01e0', '005a4319': '005e5f50',
              '005a471b': '005e5788', '005a46d5': '005e57a0',
              '005a0f62': '005e578c', '005a0f7b': '005e5794'}
    evidence = [r for r in refs if wanted.get(r['from_va']) == r['to_va']]
    assert {r['from_va'] for r in evidence} == set(wanted)
    native = [json.loads(line) for line in subprocess.run(
        [str(args.probe.resolve())], text=True, capture_output=True, check=True).stdout.splitlines()]
    assert native[-1] == {'native_pointer_identities': True, 'unresolved_callbacks_executed': False}
    assert len(native) == len(RANGES) + 1
    data = {}
    for row, (name, (va, size)) in zip(native, RANGES.items()):
        original = mapped(image, module, va, size)
        assert row == {'name': name, 'hex': original.hex()}, name
        data[name] = {'va': f'{va:08x}', 'bytes': size, 'initial_hex': original.hex(),
                      'sha256': hashlib.sha256(original).hexdigest()}
    cells = mapped(image, module, 0x5e5788, 32)
    assert struct.unpack('<8I', cells) == (0x5abee8,) * 6 + (0x5c1a34, 0x5c1a24)
    pe = struct.unpack_from('<I', image, 0x3c)[0]
    optional = pe + 24
    assert struct.unpack_from('<H', image, optional)[0] == 0x10b
    relocation_rva, relocation_size = struct.unpack_from('<II', image, optional + 96 + 5 * 8)
    relocations = mapped(image, module, 0x400000 + relocation_rva, relocation_size)
    highlow = set()
    offset = 0
    while offset < len(relocations):
        page, size = struct.unpack_from('<II', relocations, offset)
        assert size >= 8 and size % 2 == 0 and offset + size <= len(relocations)
        for (entry,) in struct.iter_unpack('<H', relocations[offset + 8:offset + size]):
            if entry >> 12 == 3:
                highlow.add(0x400000 + page + (entry & 0xfff))
        offset += size
    pointer_vas = {0x5e54e8, 0x5e54f0, *range(0x5e5788, 0x5e57a8, 4)}
    assert pointer_vas <= highlow
    paths = ['iterations/v2/001-original-recovery/source/include/porsche/formatter_runtime_storage.hpp',
             'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/formatter_runtime_storage.cpp',
             'iterations/v2/001-original-recovery/source/recovered/formatter_runtime_storage_probe.cpp',
             'iterations/v2/001-original-recovery/runs/138-formatter-runtime-storage/CMakeLists.txt',
             'iterations/v2/001-original-recovery/runs/138-formatter-runtime-storage/README.md',
             'scripts/research/verify-v2-formatter-runtime-storage.py']
    report = {'schema': 1, 'module': 'Porsche.exe', 'module_sha256': SHA,
              'data_only_packet': True, 'full_function_vas': [], 'partial_function_vas': [],
              'initial_data_equal_original_mapped_image': True,
              'ranges': data, 'pointer_cells_005e5788_hex': cells.hex(),
              'native_pointer_identities': True, 'consumer_instruction_bytes': {f'{va:08x}': raw for va, raw in CODE.items()},
              'pe_highlow_pointer_relocations': [f'{va:08x}' for va in sorted(pointer_vas)],
              'index_references': evidence, 'source_sha256': source_hashes(paths),
              'limits': ['Initial image only; CRT startup and lowio initialization are not recovered.',
                         '005abee8 fatal effect 005a2e22 unresolved; private probe abort identities are never called.',
                         '005a0f5d replaces float callbacks with 005a41e3/005a3e8d/005a3e33; those bodies remain unresolved.',
                         '006c01dc is only the preceding mapped cell consumed by signed index -1; object semantics unknown.',
                         'No game launch or behavioral/visual acceptance.']}
    args.report_dir.mkdir(parents=True, exist_ok=True)
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8', newline='\n')
    print(json.dumps({'ok': True, 'data_ranges': len(RANGES), 'initial_bytes': sum(s for _, s in RANGES.values()),
                      'native_pointer_identities': True, 'full_functions_added': 0}))


if __name__ == '__main__':
    main()
