"""Original-x86/native integration proof for event-stop plus thread-wait."""
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
HOOK_BASE = 0x710000
TABLE = 0x2220000
# Canonical static ThreadRecord used by the original caller, not a fixture-only
# shadow object. Its address is also the argument passed to 0055f780/0055fa10.
RECORD = 0x6bd9c0
EVENT = 0x69e5dc
LIFECYCLE_LOCK = 0x69e5d4
STOP = 0x69e5d8
TABLE_PTR = 0x6a57e4
CAPACITY = 0x6a57e8
TABLE_LOCK = 0x6a57ec
RATE = 0x5deb48
CASES = [
    {'self_thread': 0, 'registered': 1, 'detach_on_wait': 1},
    {'self_thread': 1, 'registered': 1, 'detach_on_wait': 1},
    {'self_thread': 0, 'registered': 0, 'detach_on_wait': 0},
]


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def original(module, image, case_id):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP,
        UC_X86_REG_EBX, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESP,
        UC_X86_REG_ESI)

    case = CASES[case_id]
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            raw = section['raw_offset']
            uc.mem_write(BASE + section['rva'], image[raw:raw + section['raw_size']])
    uc.mem_map(0x2200000, 0x100000)
    uc.mem_map(HOOK_BASE, 0x10000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def ret(machine, eax=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        return_address = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, return_address)

    put(STACK, EXIT)
    regs = {UC_X86_REG_EBX: 0x11223344, UC_X86_REG_ESI: 0x22334455,
            UC_X86_REG_EDI: 0x33445566, UC_X86_REG_EBP: 0x44556677}
    for reg, value in regs.items():
        uc.reg_write(reg, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    put(LIFECYCLE_LOCK, 0x2201000)
    put(STOP, 0)
    put(EVENT, 0x2202000)
    put(RECORD, 0x2204000)
    put(RECORD + 4, 0x1000)
    put(RECORD + 8, 1)
    put(RECORD + 12, 0xffffffff)
    put(RECORD + 16, 0x55aa)
    put(RECORD + 20, 0x1234)
    put(RECORD + 24, 0)
    put(TABLE, 0x1234 if case['registered'] else 0x7777)
    put(TABLE + 4, 0x2204000)
    put(TABLE + 8, 0x55aa)
    put(TABLE_PTR, TABLE)
    put(CAPACITY, 1)
    put(TABLE_LOCK, 0x2203000)
    put(RATE, 1000)

    events = []
    wait_count = [0]

    def lock_name(value):
        if value == 0x2201000: return 'lifecycle-lock'
        if value == 0x2203000: return 'table-lock'
        return f'{value:x}'

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
            return
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5322b0:
            events.append('lock:enter:' + lock_name(word(esp + 4)))
            ret(machine)
        elif address == 0x5322c0:
            events.append('lock:leave:' + lock_name(word(esp + 4)))
            ret(machine)
        elif address == 0x5322d0:
            events.append('lock:destroy:' + lock_name(word(esp + 4)))
            ret(machine)
        elif address == 0x55fb30:
            handle = word(esp + 4)
            events.append('event:signal:' + ('event' if handle == 0x2202000 else f'{handle:x}'))
            ret(machine, 1)
        elif address == 0x55f780:
            identity = word(esp + 4)
            events.append('thread:current:' + ('record' if identity == 0x6bd9c0 else 'other'))
            ret(machine, case['self_thread'])
        elif address == 0x55fbb0:
            handle, ticks = word(esp + 4), word(esp + 8)
            events.append(f'timed:{handle:x}:{ticks:x}')
            wait_count[0] += 1
            if case['detach_on_wait'] and wait_count[0] == case['detach_on_wait']:
                put(TABLE, 0xbeef)
            ret(machine, 0)

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(0x53c170, 0, count=50000)
    except Exception as error:
        raise AssertionError(f'case {case_id}: original fault at {uc.reg_read(UC_X86_REG_EIP):08x}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'case {case_id}: original did not return')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError(f'case {case_id}: stack cleanup mismatch')
    for reg, expected in regs.items():
        if uc.reg_read(reg) != expected:
            raise AssertionError(f'case {case_id}: callee-saved register changed')
    state = [f'{word(LIFECYCLE_LOCK):x}', f'{word(STOP):x}', f'{word(EVENT):x}',
             f'{word(RECORD):x}', f'{word(RECORD+20):x}', f'{word(TABLE):x}', f'{word(RATE):x}']
    return {'state': state, 'trace': events}


def native(probe, case_id):
    result = subprocess.run([str(probe), str(case_id)], text=True,
        capture_output=True, check=True)
    lines = result.stdout.splitlines()
    if len(lines) != 2 or not lines[0].startswith('state=') or not lines[1].startswith('trace='):
        raise AssertionError(f'case {case_id}: malformed native output {result.stdout!r}')
    return {'state': lines[0][6:].split(','),
            'trace': [] if not lines[1][6:] else lines[1][6:].split(';')}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(json.loads(line) for line in
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()
        if json.loads(line).get('file') == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('original Porsche.exe SHA mismatch')
    functions = [json.loads(line) for line in
        (ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines()]
    by_va = {row['entry_va']: row for row in functions}
    indexed = by_va['0053c1d0']
    if indexed['ranges'] != [['0053c170', '0053c1c6'], ['0053c1d0', '0053c261']]:
        raise AssertionError('0053c170 lifecycle helper boundary changed')
    if by_va['0055fa10']['ranges'] != [['0055fa10', '0055fa8f']]:
        raise AssertionError('0055fa10 function boundary changed')
    bodies = {
        '0053c170': (0x53c170, 87),
        '0055fa10': (0x55fa10, 128),
        '0055f980': (0x55f980, 43),
        '0055f9b0': (0x55f9b0, 81),
    }
    body_records = []
    for va, (address, size) in bodies.items():
        body = read_va(image, module, address, size)
        body_records.append({'va': va, 'body_bytes': size,
            'body_sha256': hashlib.sha256(body).hexdigest()})

    details = []
    for case_id in range(len(CASES)):
        expected = original(module, image, case_id)
        actual = native(args.probe, case_id)
        if expected != actual:
            raise AssertionError(f'case {case_id} mismatch\noriginal={expected}\nnative={actual}')
        details.append({'case': case_id, 'trace_events': len(expected['trace']), 'equal': True})

    paths = [
        'iterations/v2/001-original-recovery/runs/130-event-thread-integration/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/130-event-thread-integration/README.md',
        'iterations/v2/001-original-recovery/source/include/porsche/auxiliary_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/event_lifecycle.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_events.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_threads.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap_locks.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/shared_runtime_globals.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/thread_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/window_create.hpp',
        'iterations/v2/001-original-recovery/source/recovered/event_thread_integration_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/event_lifecycle.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_wait.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp',
        'research/binary-index/static/binaries.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'scripts/research/v2_source_dependencies.py',
        'scripts/research/verify-v2-event-thread-integration.py',
    ]
    compiled = [ROOT / 'iterations/v2/001-original-recovery/source/recovered/event_thread_integration_probe.cpp',
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp',
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/event_lifecycle.cpp',
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_wait.cpp',
        ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp']
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA, 'module_sha256': SHA,
        'function_vas': ['0053c170', '0055fa10'],
        'full_function_vas': ['0053c170', '0055fa10'], 'partial_function_vas': [],
        'anonymous_entry_evidence': [{'va': '0053c170', 'bytes': 87,
            'body_sha256': body_records[0]['body_sha256'],
            'parent_index_row': '0053c1d0 separate range'}],
        'original_functions': body_records,
        'cases': len(CASES), 'native_cpp_equal_original_x86': True,
        'state_vas': ['0069e5d4', '0069e5d8', '0069e5dc', '006bd9c0',
                      '006a57e4', '006a57e8', '006a57ec', '005deb48'],
        'boundary_contracts': [
            'Win32 SetEvent, current-thread query and timed wait are controlled fixture boundaries',
            'canonical 0055f730 record-handle accessor is fixture-bound to its recovered field load',
            '0055fbb0 wait return is controlled; the original lifecycle and thread-wait callers ignore it',
            'CRT registration and worker creation are outside the two executed entries',
        ],
        'cases_detail': details,
        'source_sha256': source_hashes(paths, compiled_sources=compiled),
        'compiled_translation_units': [str(path) for path in compiled],
    }
    output = args.report_dir / 'verification.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'verified {len(CASES)} original x86 event/thread integration cases; report={output.resolve().relative_to(ROOT)}')


if __name__ == '__main__':
    main()
