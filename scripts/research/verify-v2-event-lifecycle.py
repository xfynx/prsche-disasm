"""Differential proof for the original auxiliary-event lifecycle cluster."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes
from v2_manual_index import records as manual_records

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE = 0x400000
STACK = 0x2210000
EXIT = 0x72fff0
HOOK_BASE = 0x710000
TABLE = 0x69e5b4
LOCK = 0x69e5d4
STOP = 0x69e5d8
EVENT = 0x69e5dc
RECORD = 0x6bd9c0
DIAG_FILE = 0x5deb74
DIAG_LINE = 0x5deb78
DIAG_HANDLER = 0x5debf0
CALLBACKS = {'A': 0x720100, 'B': 0x720200, 'C': 0x720300, '-': 0}
OP_ENTRY = {0: 0x53bfe0, 1: 0x53c060, 2: 0x53c0f0,
            3: 0x53c1d0, 4: 0x53c170}
BODY_RANGES = {
    '0053bfe0': (0x53bfe0, 121),
    '0053c060': (0x53c060, 134),
    'anonymous_0053c0f0': (0x53c0f0, 120),
    'anonymous_0053c170': (0x53c170, 87),
    '0053c1d0': (0x53c1d0, 146),
}

# Fields mirror the isolated native probe's fixed, representative input set.
CASES = [
    (0, 'A', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0, ''),
    (0, 'A', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0, 'AB'),
    (0, 'C', 0x2209000, 0, 0, 0, 0x2209000, 1, 0, 0, 0, 'ABABABAB'),
    (0, 'A', 0, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, ''),
    (0, 'A', 0, 0, 0, 0x3300000, 0x2209000, 0, 0, 0, 0, ''),
    (2, '-', 0x2209000, 1, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, ''),
    (2, '-', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 1, 0, 'AB'),
    (2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, ''),
    (3, 'B', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, 'ABC'),
    (3, 'A', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, 'A'),
    (4, '-', 0x2209000, 0, 0x3301000, 0x3300000, 0x2209000, 1, 1, 0, 0, ''),
    (4, '-', 0, 0, 0x3301000, 0x3300000, 0x2209000, 1, 0, 0, 0, ''),
    (3, 'C', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, 'AB'),
    (3, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, 'A-B'),
    (0, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, ''),
    (2, '-', 0x2209000, 1, 0, 0, 0x2209000, 1, 0, 0, 0, ''),
    (2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 2, 'AB'),
    (1, '-', 0, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 0, ''),
    (2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, 'A-B'),
    (2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, '-B'),
    (2, '-', 0x2209000, 0, 0, 0x3300000, 0x2209000, 1, 0, 0, 1, 'ABABABAB'),
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

    (operation, add_remove, initial_lock, stopping, event_before,
     event_created, lock_created, start_result, current_thread,
     stop_from_a, stop_after_wait, callback_text) = CASES[case_id]
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            start = section['raw_offset']
            uc.mem_write(BASE + section['rva'], image[start:start + section['raw_size']])
    uc.mem_map(0x2200000, 0x100000)
    uc.mem_map(HOOK_BASE, 0x10000)
    uc.mem_map(0x720000, 0x10000)
    uc.mem_map(0x730000, 0x10000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def cstring(address):
        value = bytearray()
        while (byte := uc.mem_read(address + len(value), 1)[0]) != 0:
            value.append(byte)
        return value.decode('ascii', errors='replace')

    def return_to_caller(machine, eax=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        ret = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, ret)

    put(STACK, EXIT)
    initial_regs = {UC_X86_REG_EBX: 0x11223344,
        UC_X86_REG_EBP: 0x22334455, UC_X86_REG_ESI: 0x33445566,
        UC_X86_REG_EDI: 0x44556677}
    for register, value in initial_regs.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    put(LOCK, initial_lock)
    put(STOP, stopping)
    put(EVENT, event_before)
    for index in range(8):
        value = callback_text[index] if index < len(callback_text) else '-'
        put(TABLE + index * 4, CALLBACKS[value])
    record_initial = [0xa5000000 + i * 0x101 for i in range(7)]
    for i, value in enumerate(record_initial):
        put(RECORD + i * 4, value)
    uc.mem_write(0x730000, b'fixture-before\0')
    put(DIAG_FILE, 0x730000)
    put(DIAG_LINE, 0x77)
    put(DIAG_HANDLER, HOOK_BASE + 0x100)
    if operation in (0, 3):
        put(STACK + 4, CALLBACKS[add_remove])

    events = []
    wait_count = [0]
    handles = {0: 'null', initial_lock: 'lock', lock_created: 'lock',
               event_before: 'event', event_created: 'event', RECORD: 'record'}

    def handle(value):
        if value == 0:
            return 'null'
        return handles.get(value, f'{value:x}')

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
            return
        if address in (0x720100, 0x720200, 0x720300):
            name = {0x720100: 'A', 0x720200: 'B', 0x720300: 'C'}[address]
            events.append('callback:' + name)
            if name == 'A' and stop_from_a:
                put(STOP, 1)
            return_to_caller(machine)
            return
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5321f0:
            events.append('lock:create')
            return_to_caller(machine, lock_created)
        elif address == 0x5322b0:
            events.append('lock:enter:' + handle(word(esp + 4)))
            return_to_caller(machine)
        elif address == 0x5322c0:
            events.append('lock:leave:' + handle(word(esp + 4)))
            return_to_caller(machine)
        elif address == 0x5322d0:
            events.append('lock:destroy:' + handle(word(esp + 4)))
            return_to_caller(machine)
        elif address == 0x557380:
            callback = word(esp + 4)
            events.append('atexit:' + ('stop' if callback == 0x53c170 else 'other'))
            return_to_caller(machine)
        elif address == 0x55f420:
            entry, stack_size, priority, flags, out_ptr = [word(esp + 4 + 4*i) for i in range(5)]
            events.append(f'thread:start:{"worker" if entry == 0x53c0f0 else "other"},'
                          f'{stack_size},{priority},{flags},'
                          f'{"record" if out_ptr == RECORD else "other"}')
            if start_result and out_ptr == RECORD:
                for i, value in enumerate((0x2401000, 0, 1, 0, 0x3344, 0x44556677, 3)):
                    put(out_ptr + 4*i, value)
            return_to_caller(machine, start_result)
        elif address == 0x55fb20:
            events.append('event:create')
            return_to_caller(machine, event_created)
        elif address == 0x55fb90:
            wait_count[0] += 1
            event_ptr = word(esp + 4)
            events.append('event:wait:' + handle(event_ptr))
            if stop_after_wait and wait_count[0] == stop_after_wait:
                put(STOP, 1)
            return_to_caller(machine, event_ptr)
        elif address == 0x55fb30:
            events.append('event:signal:' + handle(word(esp + 4)))
            return_to_caller(machine, 1)
        elif address == 0x55fc10:
            events.append('event:close:' + handle(word(esp + 4)))
            return_to_caller(machine, 1)
        elif address == 0x55f780:
            identity = word(esp + 4)
            events.append('thread:current:' + ('record' if identity == RECORD else 'other'))
            return_to_caller(machine, current_thread)
        elif address == 0x55fa10:
            thread_record, timeout = word(esp + 4), word(esp + 8)
            events.append(f'thread:join:{handle(thread_record)},{timeout}')
            return_to_caller(machine, 0)
        elif address == HOOK_BASE + 0x100:
            message = cstring(word(esp + 4))
            file_name = cstring(word(DIAG_FILE))
            line = word(DIAG_LINE)
            events.append('diagnostic:' +
                ('lowtimer' if file_name == r'\real\pc\lowtimer.c' else 'other') +
                f',{line},{"thread-failed" if message == "wininittimer - FAILED TO CREATE SECONDARY TIMER`S THREAD.\n" else "other"}')
            return_to_caller(machine)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(OP_ENTRY[operation], 0, count=50000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'case {case_id}: original did not return; EIP={uc.reg_read(UC_X86_REG_EIP):08x}')
    expected_esp = STACK + 4
    if uc.reg_read(UC_X86_REG_ESP) != expected_esp:
        raise AssertionError(f'case {case_id}: stack {uc.reg_read(UC_X86_REG_ESP):08x}, expected {expected_esp:08x}')
    regs = {name: uc.reg_read(number) for name, number in
        [('ebx', UC_X86_REG_EBX), ('ebp', UC_X86_REG_EBP),
         ('esi', UC_X86_REG_ESI), ('edi', UC_X86_REG_EDI)]}
    if regs != {'ebx': 0x11223344, 'ebp': 0x22334455,
                'esi': 0x33445566, 'edi': 0x44556677}:
        raise AssertionError(f'case {case_id}: callee-saved register mismatch {regs}')
    table = [word(TABLE + i*4) for i in range(8)]
    callback_tokens = {value: key for key, value in CALLBACKS.items()}
    diag_file = cstring(word(DIAG_FILE))
    state = [f'{word(LOCK):x}', f'{word(STOP):x}', f'{word(EVENT):x}']
    state += [callback_tokens.get(value, '?') for value in table]
    state += [f'{word(RECORD + i*4):x}' for i in range(7)]
    state += ['before' if diag_file == 'fixture-before' else
              'lowtimer' if diag_file == r'\real\pc\lowtimer.c' else 'other',
              f'{word(DIAG_LINE):x}']
    return {'state': state, 'trace': events}


def native(probe, case_id):
    result = subprocess.run([str(probe), str(case_id)], text=True,
        capture_output=True, check=True)
    lines = result.stdout.splitlines()
    if len(lines) != 2 or not lines[0].startswith('state=') or not lines[1].startswith('trace='):
        raise AssertionError(f'case {case_id}: malformed probe output: {result.stdout!r}')
    state = lines[0][6:].split(',')
    trace = [] if not lines[1][6:] else lines[1][6:].split(';')
    return {'state': state, 'trace': trace}


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

    index_path = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    functions = [json.loads(line) for line in index_path.read_text().splitlines()]
    by_va = {row['entry_va']: row for row in functions}
    for va, expected in [('0053bfe0', [['0053bfe0', '0053c058']]),
                         ('0053c060', [['0053c060', '0053c0e5']]),
                         ('0053c1d0', [['0053c170', '0053c1c6'], ['0053c1d0', '0053c261']])]:
        if by_va[va]['ranges'] != expected:
            raise AssertionError(f'{va} indexed ranges changed: {by_va[va]}')

    body_records = []
    for name, (va, size) in BODY_RANGES.items():
        body = read_va(image, module, va, size)
        if len(body) != size:
            raise AssertionError(f'{name}: original bytes truncated')
        body_records.append({'name': name, 'va': f'{va:08x}', 'body_bytes': size,
                             'body_sha256': hashlib.sha256(body).hexdigest()})
    if read_va(image, module, 0x53c08f, 5) != bytes.fromhex('68f0c05300'):
        raise AssertionError('0053c060 no longer passes anonymous worker entry 0053c0f0')
    if read_va(image, module, 0x53c060, 5) != bytes.fromhex('6870c15300'):
        raise AssertionError('0053c060 no longer registers anonymous stop entry 0053c170')
    if read_va(image, module, 0x53c25c, 5) != bytes.fromhex('e90fffffff'):
        raise AssertionError('0053c1d0 tail transfer to stop entry changed')
    if BODY_RANGES['0053c1d0'] != (0x53c1d0, 146):
        raise AssertionError('unexpected callback removal boundary')

    calls_path = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl'
    calls = [json.loads(line) for line in calls_path.read_text().splitlines()]
    required_edges = {('0053bfee', '0053c060'), ('0053c065', '00557380'),
        ('0053c06a', '005321f0'), ('0053c094', '0055f420'),
        ('0053c0f0', '0055fb20'), ('0053c10a', '0055fb90'),
        ('0053c189', '0055fb30'), ('0053c193', '0055f780'),
        ('0053c1a5', '0055fa10'), ('0056026c', '0053bfe0'),
        ('00587c24', '0053bfe0'), ('005602d2', '0053c1d0'),
        ('005604e3', '0053c1d0'), ('00587e7a', '0053c1d0')}
    indexed_edges = {(row['from_va'], row['to_va']) for row in calls}
    missing_edges = sorted(required_edges - indexed_edges)
    if missing_edges:
        raise AssertionError(f'call-index closure missing edges: {missing_edges}')
    references_path = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl'
    references = [json.loads(line) for line in references_path.read_text().splitlines()]
    required_refs = {('0053c08f', '0053c0f0', 'DATA'),
                     ('0053c25c', '0053c170', 'UNCONDITIONAL_JUMP'),
                     ('0053c18e', '006bd9c0', 'DATA')}
    indexed_refs = {(row['from_va'], row['to_va'], row['type']) for row in references}
    if required_refs - indexed_refs:
        raise AssertionError(f'reference-index closure missing {sorted(required_refs-indexed_refs)}')
    row = by_va['0053c1d0']
    indexed_body = b''.join(read_va(image, module, int(start, 16),
        int(end, 16) - int(start, 16) + 1) for start, end in row['ranges'])
    if len(indexed_body) != 233:
        raise AssertionError(f'0053c1d0 full indexed body size changed: {len(indexed_body)}')

    details = []
    manual = {row['entry_va']: row for row in manual_records(SHA)}
    for va in ('0053c0f0', '0053c170'):
        assert va in manual, f'missing separately callable entry {va}'
    for case_id in range(len(CASES)):
        expected = original(module, image, case_id)
        actual = native(args.probe, case_id)
        if expected != actual:
            raise AssertionError(f'case {case_id} mismatch\noriginal={expected}\nnative={actual}')
        details.append({'case': case_id, 'trace_events': len(expected['trace']), 'equal': True})

    paths = [
        'iterations/v2/001-original-recovery/runs/123-event-lifecycle/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/123-event-lifecycle/README.md',
        'iterations/v2/001-original-recovery/source/include/porsche/auxiliary_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/event_lifecycle.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/event_lifecycle.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp',
        'iterations/v2/001-original-recovery/source/recovered/event_lifecycle_probe.cpp',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
        'research/binary-index/static/binaries.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'scripts/research/v2_source_dependencies.py',
        'scripts/research/verify-v2-event-lifecycle.py',
        'scripts/research/index-v2-event-lifecycle.py',
        'scripts/research/v2_manual_index.py',
        'research/binary-index/manual-functions.jsonl',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'module_sha256': SHA,
        'function_vas': ['0053bfe0', '0053c060', '0053c0f0', '0053c170', '0053c1d0'],
        'full_function_vas': ['0053bfe0', '0053c060', '0053c0f0', '0053c170', '0053c1d0'],
        'partial_function_vas': [],
        'anonymous_entry_evidence': [
            {'va': '0053c0f0', 'bytes': 120, 'body_sha256': body_records[2]['body_sha256'],
             'role': 'worker callback literal passed by 0053c060; supplementary indexed entry'},
            {'va': '0053c170', 'bytes': 87, 'body_sha256': body_records[3]['body_sha256'],
             'role': 'registered shutdown callback; supplementary entry shares automatic0053c1d0 tail'},
        ],
        'original_functions': body_records,
        'indexed_function_rows': [{
            'va': '0053bfe0', 'ranges': by_va['0053bfe0']['ranges'],
            'body_bytes': by_va['0053bfe0']['body_bytes'],
            'body_sha256': hashlib.sha256(read_va(image, module, 0x53bfe0, 121)).hexdigest()}, {
            'va': '0053c060', 'ranges': by_va['0053c060']['ranges'],
            'body_bytes': by_va['0053c060']['body_bytes'],
            'body_sha256': hashlib.sha256(read_va(image, module, 0x53c060, 134)).hexdigest()}, {
            'va': '0053c1d0', 'ranges': row['ranges'], 'body_bytes': row['body_bytes'],
            'body_sha256': hashlib.sha256(indexed_body).hexdigest()}],
        'cases': len(CASES), 'native_cpp_equal_original_x86': True,
        'state_vas': ['0069e5b4', '0069e5d4', '0069e5d8', '0069e5dc', '006bd9c0'],
        'boundaries': [
            '0055fa10 uses canonical Run127 declaration; this component probe controls its result; connected execution is verified separately',
            '0055f420 canonical recovered thread start; fixture controls output record and success result',
            '0055fb20/0055fb90/0055fb30/0055fc10/0055f780 event and thread APIs are controlled fixture boundaries',
            '005322b0/005322c0/005321f0/005322d0 heap-lock APIs are recorded boundaries',
            '00557380 CRT exit registration and 005debf0 diagnostic callback are recorded boundaries',
            '0069e5dc event HANDLE owner is reused from Run122; no duplicate definition',
        ],
        'cases_detail': details,
        'source_sha256': source_hashes(paths, compiled_sources=[
            ROOT/'iterations/v2/001-original-recovery/source/recovered/event_lifecycle_probe.cpp',
            ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp',
            ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/event_lifecycle.cpp',
            ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp']),
        'compiled_translation_units': [
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/event_lifecycle_probe.cpp'),
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/auxiliary_wait.cpp'),
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/event_lifecycle.cpp'),
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp'),
        ],
    }
    output = args.report_dir / 'verification.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'verified {len(CASES)} original x86 lifecycle cases; report={output.resolve().relative_to(ROOT)}')


if __name__ == '__main__':
    main()
