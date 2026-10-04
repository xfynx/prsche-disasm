"""Read a bounded original PE range when Ghidra has no function for a target.

Uses the versioned inventory and verifies SHA256. Output is a raw decode, not
an inferred function boundary or semantic proof. Does not modify the original.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', required=True, help='Exact inventory file/path')
    parser.add_argument('--address', required=True, type=lambda x: int(x, 16))
    parser.add_argument('--size', required=True, type=lambda x: int(x, 0))
    parser.add_argument('--words', action='store_true', help='Decode dwords instead of instructions')
    args = parser.parse_args()
    if not 1 <= args.size <= 4096:
        parser.error('size must be between 1 and 4096 bytes')
    root = Path(__file__).resolve().parents[2]
    modules = [json.loads(line) for line in
               (root / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()]
    matches = [m for m in modules if args.binary.lower() in (m['file'].lower(), m['path'].lower())]
    if len(matches) != 1:
        parser.error('expected exactly one inventory module')
    module = matches[0]
    data = (root / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest() != module['sha256']:
        parser.error('original SHA256 differs from inventory')
    rva = args.address - int(module['image_base'], 16)
    sections = [s for s in module['sections']
                if s['rva'] <= rva and rva + args.size <= s['rva'] + s['raw_size']]
    if len(sections) != 1:
        parser.error('requested range must fit one file-backed section')
    section = sections[0]
    offset = section['raw_offset'] + rva - section['rva']
    chunk = data[offset:offset + args.size]
    print(f"{module['path']} SHA256={module['sha256']} VA={args.address:08x} size={args.size}")
    print('Raw range; function extent and meaning require separate verification.')
    if args.words:
        if len(chunk) % 4:
            parser.error('--words requires size divisible by four')
        for index, (value,) in enumerate(struct.iter_unpack('<I', chunk)):
            print(f'{args.address + index * 4:08x} {value:08x} float={struct.unpack("<f", struct.pack("<I", value))[0]:.9g}')
    else:
        from capstone import Cs, CS_ARCH_X86, CS_MODE_32
        if module['machine'] != '014c':
            parser.error('only indexed x86-32 modules supported')
        for instruction in Cs(CS_ARCH_X86, CS_MODE_32).disasm(chunk, args.address):
            print(f'{instruction.address:08x} {instruction.mnemonic} {instruction.op_str}'.rstrip())


if __name__ == '__main__':
    main()
