"""Differential proof for Porsche.exe 0055fa10 thread-wait semantics."""
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
ENTRY = 0x55fa10
BODY_BYTES = 128
STACK = 0x2210000
EXIT = 0x220fff0
HOOK_BASE = 0x710000
TABLE = 0x2220000
RECORD = 0x2230000
RATE = 0x5deb48
THREAD_ENTRIES = 0x6a57e4
THREAD_CAPACITY = 0x6a57e8
THREAD_LOCK = 0x6a57ec
LOCK_HANDLE = 0x2209000

# (timeout, rate, handle, slot, capacity, record serial, entry serial,
#  unregister on this wait number, timed-wait result)
CASES = [
    (25, 1000, 0, 0, 3, 0x1234, 0x1234, 0, 0),
    (25, 60, 0x2201000, 0, 3, 0x1234, 0x7777, 0, 0),
    (25, 60, 0x2201000, 0, 3, 0x1234, 0x1234, 0, 1),
    (25, 60, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (0, 1000, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (0, 128, 0x2201000, 0, 3, 0x1234, 0x7777, 0, 0),
    (0, 0, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 1),
    (0, 99, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (0, 128, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (0xffffffff, 100, 0x2201000, 0xffffffff, 3, 0x1234, 0x1234, 0, 0),
    (1, 100, 0x2201000, 3, 3, 0x1234, 0x1234, 0, 0),
    (1, 100, 0x2201000, 1, 3, 0, 0, 0, 0),
    (0, 0xffffffff, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (20, 1000, 0x2201000, 0, 3, 0x1234, 0, 0, 0),
    (0, 0x80000000, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 0),
    (0, 0x7fffffff, 0x2201000, 0, 3, 0x1234, 0x1234, 1, 1),
]
CALLERS = ['0053c1a5', '0055bee4', '0055c03c', '0055d21d',
           '0055da05', '0055e9d9', '005835f5']


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

    (timeout, rate, handle, slot, capacity, record_serial, entry_serial,
     expire_on_wait, wait_result) = CASES[case_id]
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            start = section['raw_offset']
            uc.mem_write(BASE + section['rva'], image[start:start + section['raw_size']])
    uc.mem_map(0x2200000, 0x100000)
    uc.mem_map(HOOK_BASE, 0x10000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def return_to_caller(machine, eax=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        ret = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, ret)

    put(STACK, EXIT)
    put(STACK + 4, RECORD)
    put(STACK + 8, timeout)
    regs = {UC_X86_REG_EBX: 0x11223344, UC_X86_REG_ESI: 0x22334455,
            UC_X86_REG_EDI: 0x33445566, UC_X86_REG_EBP: 0x44556677}
    for register, value in regs.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)

    put(RECORD, handle)
    put(RECORD + 4, 0x1000)
    put(RECORD + 8, 2)
    put(RECORD + 12, 0xffffffff)
    put(RECORD + 16, 0x55aa)
    put(RECORD + 20, record_serial)
    put(RECORD + 24, slot)
    put(TABLE, entry_serial)
    put(TABLE + 4, handle)
    put(TABLE + 8, 0x55aa)
    put(THREAD_ENTRIES, TABLE)
    put(THREAD_CAPACITY, capacity)
    put(THREAD_LOCK, LOCK_HANDLE)
    put(RATE, rate)

    events = []
    wait_count = [0]

    def handle_name(value):
        return 'null' if value == 0 else f'{value:x}'

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
            return
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5322b0:
            lock = word(esp + 4)
            events.append('lock:enter:' + ('lock' if lock == LOCK_HANDLE else handle_name(lock)))
            return_to_caller(machine)
        elif address == 0x5322c0:
            lock = word(esp + 4)
            events.append('lock:leave:' + ('lock' if lock == LOCK_HANDLE else handle_name(lock)))
            return_to_caller(machine)
        elif address == 0x55fbb0:
            thread_handle, ticks = word(esp + 4), word(esp + 8)
            events.append(f'timed:{handle_name(thread_handle)}:{ticks:x}')
            wait_count[0] += 1
            if expire_on_wait and wait_count[0] == expire_on_wait:
                put(TABLE, 0xbeef)
            return_to_caller(machine, wait_result)

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(ENTRY, 0, count=50000)
    except Exception as error:
        raise AssertionError(f'case {case_id}: original fault at EIP={uc.reg_read(UC_X86_REG_EIP):08x}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'case {case_id}: original did not return; EIP={uc.reg_read(UC_X86_REG_EIP):08x}')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError(f'case {case_id}: caller stack cleanup mismatch')
    for number, expected in regs.items():
        if uc.reg_read(number) != expected:
            raise AssertionError(f'case {case_id}: callee-saved register changed: {number}')
    state = [f'{uc.reg_read(UC_X86_REG_EAX):x}', f'{word(RECORD + 20):x}',
             f'{word(TABLE):x}', f'{word(RECORD):x}', f'{word(RATE):x}']
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
    by_va = {item['entry_va']: item for item in functions}
    row = next(item for item in functions if item['entry_va'] == '0055fa10')
    if row['ranges'] != [['0055fa10', '0055fa8f']] or row['body_bytes'] != BODY_BYTES:
        raise AssertionError(f'0055fa10 index range mismatch: {row}')
    body = read_va(image, module, ENTRY, BODY_BYTES)
    inline_helpers = []
    for va, size, ranges in (
            ('0055f980', 43, [['0055f980', '0055f9aa']]),
            ('0055f9b0', 81, [['0055f9b0', '0055fa00']])):
        helper = by_va[va]
        if helper['ranges'] != ranges or helper['body_bytes'] != size:
            raise AssertionError(f'{va} indexed body bounds changed: {helper}')
        helper_body = read_va(image, module, int(va, 16), size)
        inline_helpers.append({'va': va, 'ranges': ranges, 'body_bytes': size,
            'body_sha256': hashlib.sha256(helper_body).hexdigest(),
            'role': 'original registration predicate reproduced locally'})
    calls = [json.loads(line) for line in
        (ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl').read_text().splitlines()]
    indexed_calls = {(item.get('from_va'), item.get('to_va')) for item in calls}
    for caller in CALLERS:
        if (caller, '0055fa10') not in indexed_calls:
            raise AssertionError(f'caller edge missing for {caller}')
    callees = {('0055fa1a', '0055f730'), ('0055fa31', '0055f980'),
               ('0055fa56', '0055fbb0'), ('0055fa5c', '0055f980'),
               ('0055fa73', '0055fbb0'), ('0055fa79', '0055f980'),
               ('0055f98c', '0055f9b0'), ('0055f9cd', '005322b0'),
               ('0055f9f4', '005322c0')}
    if callees - indexed_calls:
        raise AssertionError(f'callee edges missing: {sorted(callees-indexed_calls)}')

    details = []
    for case_id in range(len(CASES)):
        expected = original(module, image, case_id)
        actual = native(args.probe, case_id)
        if expected != actual:
            raise AssertionError(f'case {case_id} mismatch\noriginal={expected}\nnative={actual}')
        details.append({'case': case_id, 'trace_events': len(expected['trace']), 'equal': True})

    paths = [
        'iterations/v2/001-original-recovery/runs/127-thread-wait/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/127-thread-wait/README.md',
        'iterations/v2/001-original-recovery/source/include/porsche/file_events.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_threads.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/thread_wait.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_wait.cpp',
        'iterations/v2/001-original-recovery/source/recovered/thread_wait_probe.cpp',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/static/binaries.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'scripts/research/v2_source_dependencies.py',
        'scripts/research/verify-v2-thread-wait.py',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'module_sha256': SHA,
        'function_vas': ['0055fa10'], 'full_function_vas': ['0055fa10'],
        'partial_function_vas': [], 'cases': len(CASES),
        'native_cpp_equal_original_x86': True,
        'original_functions': [{'va': '0055fa10', 'body_bytes': BODY_BYTES,
            'body_sha256': hashlib.sha256(body).hexdigest(),
            'abi': 'cdecl, ThreadRecord* and timeout_ticks DWORD, EAX status, caller cleanup'}],
        'callers': CALLERS,
        'callee_closure': ['0055f730', '0055f980', '0055f9b0', '0055fbb0',
                           '005322b0', '005322c0'],
        'state_vas': ['006a57e4', '006a57e8', '006a57ec', '005deb48'],
        'existing_aliases': {
            '0055f730': 'reuses thread_handle_0055f730(ThreadRecord*)',
            '0055fbb0': 'reuses file_timed_event_0055fbb0(HANDLE, ticks)',
            '0055fb30': 'not an alias for this function; it is the SetEvent wrapper',
            '0055f980/0055f9b0': 'membership predicate reproduced locally over the canonical ThreadEntry owner; signed slot bound, table-lock order, serial comparison retained',
        },
        'boundaries': [
            'Canonical thread_handle_0055f730 implementation; isolated fixture reads ThreadRecord.handle',
            'Canonical file_timed_event_0055fbb0; isolated fixture controls wait result and unregister transition',
            'Canonical thread-table lock calls heap_enter_005322b0/heap_leave_005322c0 are recorded boundaries',
            'No new thread records, table storage, timer-rate owner, or OS wait wrapper is defined by production source',
        ],
        'cases_detail': details,
        'source_sha256': source_hashes(paths, compiled_sources=[
            ROOT / 'iterations/v2/001-original-recovery/source/recovered/thread_wait_probe.cpp',
            ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_wait.cpp']),
        'inlined_original_helpers': inline_helpers,
        'compiled_translation_units': [
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/thread_wait_probe.cpp'),
            str(ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/thread_wait.cpp'),
        ],
    }
    output = args.report_dir / 'verification.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f'verified {len(CASES)} original x86 thread-wait cases; report={output.resolve().relative_to(ROOT)}')


if __name__ == '__main__':
    main()
