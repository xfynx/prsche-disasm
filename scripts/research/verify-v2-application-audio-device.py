"""Differential proof for Porsche.exe audio device creation and descriptor helpers."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE = 0x400000
STACK = 0x2210000
EXIT = 0x220fff0
STATE = 0x6b48c0
STATE_SIZE = 0x17c
INIT_FLAG = 0x6a5c30
MARKER = 0x5e2470
OUTPUT = 0x710000
ALTERNATE_MARKER = 0x710100
AUTHOR_BYTES = bytes.fromhex(
    '534e44415554484f523a2044617665204d6572636965722c2046726964617920'
    '30333a3036504d204d61722030332c20323030302c2056342e316700')

# function, initialized, active, channels, format, table mode, callback,
# 0058a4f0 result, 0058fdb0 result
CASES = [
    (0, 0, 0, 0, 0, 0, 0, 0x1234, 0),
    (0, 1, 0, 0, 0, 0, 0, -7, 0),
    (1, 1, 0, 0, 0, 0, 0, 0, 0),
    (2, 0, 1, 0, 16, 1, 0, 0, 0),
    (2, 1, 0, 2, 8, 2, 0x11223344, 0, 0),
    (2, 0, 0, 0, 16, 1, 0, -3, 0),
    (2, 0, 0, 0, 16, 1, 0, 0, -5),
    (2, 1, 0, 0, 16, 1, 0, 0, 0),
    (2, 1, 0, 0xffff, 16, 1, 0, 0, 0),
    (1, 1, 0, 0, 0, 0, 0, 0, 0),
]
FUNCTIONS = {
    '00565680': (74, [['00565680', '005656c9']],
        'cdecl, one 32-bit descriptor output pointer, signed EAX result'),
    '005656d0': (66, [['005656d0', '00565711']],
        'cdecl, one 32-bit descriptor pointer, u32 EAX return is zero'),
    '00565720': (363, [['00565720', '0056588a']],
        'cdecl, three 32-bit caller arguments; first two consumed, signed EAX'),
}
BOUNDARIES = ('0058a4f0', '0058a690', '0058fef0', '0058aa90', '0058aae0',
              '0058e2d0', '0058fdb0', '0058fe80', '0058e2e0', '0058e0e0')


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if int(s['rva']) <= rva and
                   rva + size <= int(s['rva']) + int(s['raw_size']))
    offset = int(section['raw_offset']) + rva - int(section['rva'])
    return image[offset:offset + size]


def section_covering(module, va, size):
    rva = va - int(module['image_base'], 16)
    return next(s for s in module['sections']
                if int(s['rva']) <= rva and
                rva + size <= int(s['rva']) + int(s['vsize']))


def seed_state():
    backing = bytearray((i * 29 + 7) & 0xff for i in range(STATE_SIZE + 0x10))
    state = memoryview(backing)[0x10:]
    function, initialized, active, channels, fmt, mode, callback, _, _ = CASES[current_case]
    state[0xdc] = active
    state[0x18:0x1a] = struct.pack('<H', fmt)
    state[0x1c] = mode
    state[0xe4:0xe6] = struct.pack('<H', channels)
    state[0xec:0xf0] = struct.pack('<I', callback)
    return backing, initialized


current_case = 0


def original(module, image, case_id):
    global current_case
    current_case = case_id
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP,
        UC_X86_REG_EBX, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESP,
        UC_X86_REG_ESI)

    function, initialized, _, _, _, _, _, initialize_result, device_result = CASES[case_id]
    entry = (0x565680 if function == 0 else 0x5656d0 if function == 1 else 0x565720)
    backing, _ = seed_state()
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            start = int(section['raw_offset'])
            uc.mem_write(BASE + int(section['rva']), image[start:start + int(section['raw_size'])])
    uc.mem_map(0x2200000, 0x100000)
    uc.mem_map(0x700000, 0x20000)

    def put(address, data):
        if isinstance(data, int):
            data = struct.pack('<I', data & 0xffffffff)
        uc.mem_write(address, bytes(data))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def ret(machine, eax=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        return_address = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, return_address)

    put(STACK, EXIT)
    args = ([OUTPUT] if function == 0 else [STATE - 0x10] if case_id == 9
            else [OUTPUT] if function == 1
            else [0x22004000, 0x40000, 0x12345678])
    for i, value in enumerate(args):
        put(STACK + 4 + i * 4, value)
    regs = {UC_X86_REG_EBX: 0x11223344, UC_X86_REG_ESI: 0x22334455,
            UC_X86_REG_EDI: 0x33445566, UC_X86_REG_EBP: 0x44556677}
    for register, value in regs.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    put(STATE - 0x10, backing)
    put(INIT_FLAG, initialized)
    marker_pointer = ALTERNATE_MARKER if case_id == 3 else MARKER
    put(0x5e246c, marker_pointer)
    alternate_target = bytes((0xa0 + i) & 0xff for i in range(60))
    put(ALTERNATE_MARKER, alternate_target)
    put(OUTPUT, bytes((i * 17 + 0x31) & 0xff for i in range(0x7c)))

    events = []
    allocations = 0
    def handle(machine, address, _size, _user):
        nonlocal allocations
        if address == EXIT:
            machine.emu_stop()
            return
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x58a4f0:
            events.append('0058a4f0')
            ret(machine, initialize_result)
        elif address == 0x58a690:
            events.append('0058a690')
            ret(machine)
        elif address in (0x58fef0, 0x58aa90):
            a, b = word(esp + 4), word(esp + 8)
            va = f'{address:08x}'
            events.append(f'{va}:{a:08x}:{b:08x}')
            ret(machine)
        elif address == 0x58aae0:
            size = word(esp + 4)
            events.append(f'0058aae0:{size:08x}')
            ret(machine, 0x71001000 if allocations == 0 else 0x71002000)
            allocations += 1
        elif address == 0x58e2d0:
            events.append('0058e2d0')
            ret(machine)
        elif address == 0x58fdb0:
            events.append('0058fdb0')
            ret(machine, device_result)
        elif address == 0x58fe80:
            events.append('0058fe80')
            ret(machine)
        elif address == 0x58e2e0:
            events.append('0058e2e0')
            ret(machine)
        elif address == 0x58e0e0:
            events.append('0058e0e0')
            ret(machine)

    uc.hook_add(UC_HOOK_CODE, handle)
    try:
        uc.emu_start(entry, 0, count=50000)
    except Exception as error:
        raise AssertionError(f'case {case_id}: original fault at EIP={uc.reg_read(UC_X86_REG_EIP):08x}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'case {case_id}: original did not return')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError(f'case {case_id}: cdecl stack mismatch: {uc.reg_read(UC_X86_REG_ESP):08x}')
    for register, expected in regs.items():
        if uc.reg_read(register) != expected:
            raise AssertionError(f'case {case_id}: callee-saved register changed')
    result = uc.reg_read(UC_X86_REG_EAX)
    return {
        'result': f'{result:08x}',
        'initialized': f'{word(INIT_FLAG):08x}',
        'state': bytes(uc.mem_read(STATE, STATE_SIZE)).hex(),
        'output': bytes(uc.mem_read(OUTPUT, 0x7c)).hex(),
        'author': bytes(uc.mem_read(MARKER, 60)).hex(),
        'target': bytes(uc.mem_read(marker_pointer, 60)).hex(),
        'trace': events,
    }


def native(probe, case_id):
    run = subprocess.run([str(probe), str(case_id)], text=True,
                         capture_output=True, check=True)
    lines = run.stdout.splitlines()
    if len(lines) != 6 or not all(line.startswith(prefix) for line, prefix in
            zip(lines, ('result=', 'state=', 'output=', 'author=', 'target=', 'trace='))):
        raise AssertionError(f'case {case_id}: malformed probe output {run.stdout!r}')
    fields = dict(item.split('=', 1) for item in lines[0].split(','))
    return {
        'result': fields['result'], 'initialized': fields['initialized'],
        'state': lines[1][6:], 'output': lines[2][7:],
        'author': lines[3][7:], 'target': lines[4][7:],
        'trace': [] if not lines[5][6:] else lines[5][6:].split(';'),
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    static = [json.loads(line) for line in
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()]
    module = next(row for row in static if row.get('sha256') == SHA)
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('original module SHA mismatch')
    state_section = section_covering(module, STATE, STATE_SIZE)
    init_section = section_covering(module, INIT_FLAG, 4)
    if (STATE - int(module['image_base'], 16) + STATE_SIZE <=
            int(state_section['rva']) + int(state_section['raw_size'])):
        raise AssertionError('audio device state unexpectedly became fully raw-backed')
    if (INIT_FLAG - int(module['image_base'], 16) + 4 <=
            int(init_section['rva']) + int(init_section['raw_size'])):
        raise AssertionError('descriptor-init flag unexpectedly became fully raw-backed')
    pointer_cell = read_va(image, module, 0x5e246c, 4)
    if struct.unpack('<I', pointer_cell)[0] != MARKER:
        raise AssertionError(f'original marker pointer changed: {pointer_cell.hex()}')
    marker_source = read_va(image, module, MARKER, 60)
    defined = [json.loads(line) for line in
        (ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/defined-data.jsonl').read_text().splitlines()]
    author_row = next(row for row in defined if row['va'] == '005e2470')
    pointer_row = next(row for row in defined if row['va'] == '005e246c')
    if author_row['bytes'] != 60 or pointer_row['value'] != '005e2470':
        raise AssertionError('original marker pointer/string extent changed')
    if marker_source != AUTHOR_BYTES:
        raise AssertionError(f'author string source bytes changed: {marker_source.hex()}')

    rows = [json.loads(line) for line in
        (ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines()]
    by_va = {row['entry_va']: row for row in rows}
    functions = []
    for va, (size, ranges, abi) in FUNCTIONS.items():
        row = by_va[va]
        if row['body_bytes'] != size or row['ranges'] != ranges:
            raise AssertionError(f'index boundary changed for {va}: {row}')
        begin, end = ranges[0]
        body = read_va(image, module, int(begin, 16), size)
        functions.append({'va': va, 'body_bytes': size,
            'body_sha256': hashlib.sha256(body).hexdigest(), 'ranges': ranges, 'abi': abi})

    call_rows = [json.loads(line) for line in
        (ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl').read_text().splitlines()]
    edges = {(row.get('from_va'), row.get('to_va')) for row in call_rows}
    expected_edges = {
        ('004a66c5', '00565680'), ('004a67ee', '005656d0'),
        ('004a6801', '00565720'), ('00565762', '00565680'),
        ('00565777', '005656d0'), ('0056568e', '0058a4f0'),
        ('005656f7', '0058a690'), ('00565744', '0058fef0'),
        ('0056574b', '0058aa90'), ('00565793', '0058aae0'),
        ('005657ac', '0058aae0'), ('005657cc', '0058e2d0'),
        ('005657f0', '0058fdb0'), ('005657fb', '0058fe80'),
        ('00565800', '0058e2e0'), ('00565881', '0058e0e0'),
    }
    if missing := expected_edges - edges:
        raise AssertionError(f'call graph edges missing: {sorted(missing)}')

    boundary_records = []
    for va in BOUNDARIES:
        row = by_va[va]
        begin, end = row['ranges'][0]
        size = int(end, 16) - int(begin, 16) + 1
        body = read_va(image, module, int(begin, 16), size)
        boundary_records.append({'va': va, 'ranges': row['ranges'],
            'body_bytes': row['body_bytes'], 'body_sha256': hashlib.sha256(body).hexdigest(),
            'status': 'typed, controlled external backend boundary'})

    details = []
    for case_id in range(len(CASES)):
        expected = original(module, image, case_id)
        actual = native(args.probe, case_id)
        if expected != actual:
            raise AssertionError(f'case {case_id} mismatch\noriginal={expected}\nnative={actual}')
        details.append({'case': case_id, 'trace_events': len(expected['trace']), 'equal': True})

    compiled = [
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/application_audio_device_probe.cpp',
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp',
    ]
    paths = [
        'iterations/v2/001-original-recovery/runs/133-application-audio-device/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/133-application-audio-device/README.md',
        'iterations/v2/001-original-recovery/source/include/porsche/application_audio_device.hpp',
        'iterations/v2/001-original-recovery/source/recovered/application_audio_device_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_audio_device.cpp',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/static/binaries.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/defined-data.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'scripts/research/v2_source_dependencies.py',
        'scripts/research/verify-v2-application-audio-device.py',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA, 'module_sha256': SHA,
        'function_vas': list(FUNCTIONS), 'full_function_vas': list(FUNCTIONS),
        'partial_function_vas': [], 'cases': len(CASES),
        'native_cpp_equal_original_x86': True, 'original_functions': functions,
        'callee_boundaries': boundary_records,
        'caller_edges': ['004a66c5 -> 00565680', '004a67ee -> 005656d0',
                         '004a6801 -> 00565720'],
        'state_vas': ['005e2470', '006a5c30', '006b48c0..006b4a3b'],
        'state_contract': 'BSS state is modeled as an opaque 0x17c-byte zero-initialized span; only directly accessed cells are interpreted.',
        'image_data_evidence': {
            'state_section': state_section['name'],
            'state_raw_size': state_section['raw_size'],
            'state_virtual_size': state_section['vsize'],
            'descriptor_flag_section': init_section['name'],
            'marker_pointer_va': '005e246c', 'marker_pointer_bytes': pointer_cell.hex(),
            'marker_target_va': '005e2470', 'marker_target_bytes': len(marker_source),
            'marker_target_initial_bytes': marker_source.hex(),
            'marker_target_sha256': hashlib.sha256(marker_source).hexdigest(),
        },
        'boundary_contracts': [
            '0058a4f0/0058a690 backend descriptor effects are controlled and do not model physical audio I/O',
            '0058fef0/0058aa90/0058aae0 configure/allocate boundaries record arguments and return controlled allocation tokens',
            '0058e2d0/0058fdb0/0058fe80/0058e2e0/0058e0e0 are typed backend lifecycle boundaries; hidden state effects remain unresolved',
            '00565720 receives three stack words; the body consumes buffer and byte count, and does not read the third device_flags word',
        ],
        'cases_detail': details,
        'source_sha256': source_hashes(paths, compiled_sources=compiled),
        'compiled_translation_units': [p.relative_to(ROOT).as_posix() for p in compiled],
    }
    output = args.report_dir / 'verification.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'verified {len(CASES)} audio-device original-x86 cases; report={output.resolve().relative_to(ROOT)}')


if __name__ == '__main__':
    main()
