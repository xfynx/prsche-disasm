"""Differentially compare the original 00565270 worker with the recovered C++."""
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
ENTRY = 0x565270
BODY_SIZE = 0xcf
TICK_IAT = 0x5b2080
ACTIVE = 0x6a5c0c
EVENT = 0x6a5bfc
CURRENT_TICK = 0x6b7c40
CARRY = 0x6b7c44
ITERATIONS = 0x6b7c7c
CALLBACKS = 0x6b7c20
STACK = 0x2210000
EXIT = 0x222fff0
TICK_HOOK = 0x222f100
CREATE_HOOK = 0x222f200
WAIT_HOOK = 0x222f210
CLOSE_HOOK = 0x222f220
CALLBACK_BASE = 0x222f300
CALLBACK_STEP = 0x10

CASES = [
    # First wait observes a stopped worker; setup still creates and closes event.
    {'tick': 77, 'current': 0x1234, 'iterations': 9, 'carry': 0x45,
     'active': 1, 'timer': 16, 'handle': 0x2207000, 'waits': [0],
     'ticks': [77], 'callbacks': [1, 2, 0, 0, 0, 0, 0, 0], 'mutations': []},
    # One complete iteration, null callbacks are skipped.
    {'tick': 1000, 'current': 0xffffffff, 'iterations': 0xffffffff,
     'carry': 0x12345678, 'active': 0, 'timer': 100, 'handle': 0x2207010,
     'waits': [1, 0], 'ticks': [1000, 1020],
     'callbacks': [0, 3, 0, 7, 0, 0, 0, 0], 'mutations': []},
    # Tick-count rollover, signed carry, two iterations, and same-pass callback edits.
    {'tick': 0xfffffff0, 'current': 0xabcdef01, 'iterations': 0x10203040,
     'carry': 0, 'active': 1, 'timer': 40, 'handle': 0x2207020,
     'waits': [1, 1, 0], 'ticks': [0xfffffff0, 0x10, 0x4c],
     'callbacks': [1, 2, 3, 0, 0, 0, 0, 0],
     'mutations': [[1, 1, 1, 5], [5, 1, 2, 0]]},
    # Signed JLE suppresses carry while the wrapped 32-bit accumulator is negative.
    {'tick': 0, 'current': 0x10, 'iterations': 0x20, 'carry': 7,
     'active': 1, 'timer': 1, 'handle': 0x2207030,
     'waits': [1, 1, 0], 'ticks': [0, 0x80000000, 0x80000001],
     'callbacks': [8, 0, 0, 0, 0, 0, 0, 0], 'mutations': []},
    # Null event handle still follows the original wait/close sequence.
    {'tick': 5, 'current': 6, 'iterations': 7, 'carry': 8, 'active': 0,
     'timer': 9, 'handle': 0, 'waits': [1, 0], 'ticks': [5, 15],
     'callbacks': [4, 0, 0, 0, 0, 0, 0, 0], 'mutations': []},
    # Later callback slots are read live, after the earlier callback mutates them.
    {'tick': 0xfffffffc, 'current': 0, 'iterations': 0, 'carry': 0,
     'active': 0, 'timer': 0xffffffff, 'handle': 0x2207040,
     'waits': [1, 0], 'ticks': [0xfffffffc, 2],
     'callbacks': [6, 7, 8, 0, 0, 0, 0, 0],
     'mutations': [[6, 1, 2, 2], [7, 1, 1, 0]]},
]


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def csv(values):
    return ','.join(str(v) for v in values) if values else '-'


def native_input(case):
    mutation_field = ';'.join(','.join(map(str, m)) for m in case['mutations']) or '-'
    values = [case['tick'], case['current'], case['iterations'], case['carry'],
              case['active'], case['timer'], case['handle'], csv(case['waits']),
              csv(case['ticks']), csv(case['callbacks']), mutation_field]
    return '|'.join(map(str, values))


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP,
        UC_X86_REG_EBX, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESI,
        UC_X86_REG_ESP)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            start = section['raw_offset']
            uc.mem_write(base + section['rva'], image[start:start + section['raw_size']])
    uc.mem_map(0x2200000, 0x100000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    callback_addrs = {i: CALLBACK_BASE + (i - 1) * CALLBACK_STEP
                      for i in range(1, 9)}
    callback_ids_by_addr = {address: i for i, address in callback_addrs.items()}
    put(ACTIVE, case['active'])
    put(CURRENT_TICK, case['current'])
    put(CARRY, case['carry'])
    put(ITERATIONS, case['iterations'])
    put(EVENT, 0xdeadbeef)
    for index, callback_id in enumerate(case['callbacks']):
        put(CALLBACKS + index * 4, callback_addrs.get(callback_id, 0))
    put(TICK_IAT, TICK_HOOK)
    put(STACK, EXIT)

    initial_regs = {
        UC_X86_REG_EBX: 0x11223344,
        UC_X86_REG_EBP: 0x22334455,
        UC_X86_REG_ESI: 0x33445566,
        UC_X86_REG_EDI: 0x44556677,
    }
    for register, value in initial_regs.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)

    events = []
    tick_index = 0
    wait_index = 0
    callback_calls = [0] * 9
    mutation_rows = [tuple(row) for row in case['mutations']]

    def return_cdecl(machine, eax, args=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        ret = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, ret)

    def hook(machine, address, _size, _user):
        nonlocal tick_index, wait_index
        if address == EXIT:
            machine.emu_stop()
            return
        if address == TICK_HOOK:
            value = case['ticks'][tick_index] if tick_index < len(case['ticks']) else 0
            tick_index += 1
            events.append(f'tick:{value}')
            return_cdecl(machine, value)
            return
        if address == CREATE_HOOK or address == 0x55fb20:
            events.append(f'create:{case["handle"]}')
            return_cdecl(machine, case['handle'])
            return
        if address == WAIT_HOOK or address == 0x55fb90:
            event = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            active = case['waits'][wait_index] if wait_index < len(case['waits']) else 0
            wait_index += 1
            put(ACTIVE, active)
            events.append(f'wait:{event}:{active}')
            return_cdecl(machine, event if active else 0)
            return
        if address == CLOSE_HOOK or address == 0x55fc10:
            event = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append(f'close:{event}')
            return_cdecl(machine, 1)
            return
        callback_id = callback_ids_by_addr.get(address)
        if callback_id is not None:
            callback_calls[callback_id] += 1
            occurrence = callback_calls[callback_id]
            events.append(f'callback:{callback_id}')
            for trigger, trigger_occurrence, slot, replacement in mutation_rows:
                if trigger == callback_id and trigger_occurrence == occurrence:
                    put(CALLBACKS + slot * 4, callback_addrs.get(replacement, 0))
                    events.append(f'mutation:{callback_id}:{occurrence}:{slot}:{replacement}')
            return_cdecl(machine, 0)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(ENTRY, 0, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError('00565270 did not return to its sentinel')

    final_callbacks = []
    for index in range(8):
        address = word(CALLBACKS + index * 4)
        final_callbacks.append(callback_ids_by_addr.get(address, 0))
    result = {
        'return': uc.reg_read(UC_X86_REG_EAX),
        'active': word(ACTIVE),
        'current_tick': word(CURRENT_TICK),
        'carry': word(CARRY),
        'iterations': word(ITERATIONS),
        'timer_rate': word(0x5deb48),
        'event': word(EVENT),
        'callbacks': final_callbacks,
        'events': events,
    }
    preserved = {register: uc.reg_read(reg) for register, reg in
                 [('ebx', UC_X86_REG_EBX), ('ebp', UC_X86_REG_EBP),
                  ('esi', UC_X86_REG_ESI), ('edi', UC_X86_REG_EDI)]}
    expected_preserved = {'ebx': 0x11223344, 'ebp': 0x22334455,
                          'esi': 0x33445566, 'edi': 0x44556677}
    if preserved != expected_preserved:
        raise AssertionError(f'callee-saved registers changed: {preserved}')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError('00565270 changed caller stack beyond its return address')
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)

    module = next(json.loads(line) for line in
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()
        if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('original Porsche.exe SHA mismatch')
    original_body = read_va(image, module, ENTRY, BODY_SIZE)
    if hashlib.sha256(original_body).hexdigest() != \
            '630ed67ef3c5fe03acfa69366bb9bd1df5b93799666bdf5c49bdca9fe1121b5d':
        raise AssertionError('00565270 body does not match Run110 indexed body')
    manual_path = ROOT / 'research/binary-index/manual-functions.jsonl'
    manual_row = next(json.loads(line) for line in manual_path.read_text().splitlines()
        if json.loads(line).get('module') == 'Porsche.exe'
        and json.loads(line).get('entry_va') == '00565270')
    if (manual_row.get('body_bytes') != BODY_SIZE or
            manual_row.get('body_sha256') != hashlib.sha256(original_body).hexdigest()):
        raise AssertionError(f'00565270 manual index row does not match image: {manual_row}')
    imports_path = ROOT / 'research/binary-index/static/imports.jsonl'
    tick_import = next(json.loads(line) for line in imports_path.read_text().splitlines()
        if json.loads(line).get('path') == 'Porsche.exe'
        and json.loads(line).get('dll', '').lower() == 'kernel32.dll'
        and json.loads(line).get('symbol') == 'GetTickCount')
    if int(tick_import['iat_rva'], 16) + BASE != TICK_IAT:
        raise AssertionError(f'unexpected GetTickCount IAT row: {tick_import}')
    calls_path = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl'
    indexed_calls = [json.loads(line) for line in calls_path.read_text().splitlines()]
    if not any(row.get('from_va') == '0056513a' and row.get('to_va') == '0055f420'
               for row in indexed_calls):
        raise AssertionError('Run110 thread-bootstrap caller edge is missing')
    stdin = ''.join(native_input(case) + '\n' for case in CASES)
    process = subprocess.run([str(args.probe)], input=stdin, text=True,
                             capture_output=True, check=True)
    native = [json.loads(line) for line in process.stdout.splitlines()]
    if len(native) != len(CASES):
        raise AssertionError(f'native returned {len(native)} cases, expected {len(CASES)}')

    summaries = []
    for index, (case, actual) in enumerate(zip(CASES, native)):
        expected = original(module, image, case)
        if actual != expected:
            raise AssertionError(f'case {index}: original={expected}; native={actual}')
        summaries.append({'case': index, 'iterations': case['waits'].count(1),
            'waits': len(case['waits']), 'callbacks': sum(1 for e in expected['events']
                if e.startswith('callback:')), 'event_handle': case['handle'],
            'native_original_equal': True})

    iteration = 'iterations/v2/001-original-recovery/'
    tu_probe = iteration + 'source/recovered/clock_worker_probe.cpp'
    tu_impl = iteration + 'source/recovered/Porsche.exe/clock_worker.cpp'
    pins = [iteration + 'source/include/porsche/clock_worker.hpp',
        iteration + 'source/include/porsche/window_runtime.hpp',
        iteration + 'source/include/porsche/file_events.hpp',
        iteration + 'source/include/porsche/file_device.hpp',
        iteration + 'source/include/porsche/file_worker.hpp',
        iteration + 'source/include/porsche/object_update.hpp',
        tu_probe, tu_impl,
        iteration + 'runs/112-clock-worker/CMakeLists.txt',
        iteration + 'runs/112-clock-worker/README.md',
        'scripts/research/verify-v2-clock-worker.py',
        'scripts/research/v2_source_dependencies.py',
        'iterations/v2/001-original-recovery/runs/110-clock-worker-index/README.md',
        'iterations/v2/001-original-recovery/runs/110-clock-worker-index/clock-worker-index.json',
        'scripts/research/index-v2-clock-worker.py',
        'research/binary-index/manual-functions.jsonl',
        'research/binary-index/static/imports.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl']
    compiled = [ROOT / tu_probe, ROOT / tu_impl]
    report = {
        'schema': 1,
        'module': 'Porsche.exe',
        'sha256': SHA,
        'module_sha256': SHA,
        'function_vas': ['00565270'],
        'full_function_vas': ['00565270'],
        'partial_function_vas': [],
        'cases': len(summaries),
        'native_cpp_equal_original_x86': True,
        'original_function': {
            'va': '00565270', 'body_bytes': BODY_SIZE,
            'body_sha256': hashlib.sha256(original_body).hexdigest(),
            'abi': 'cdecl, zero stack arguments, caller-clean; return EAX is zero',
            'caller': '00565030 pushes 00565270 at 00565135 for thread bootstrap 0055f420 at 0056513a'},
        'global_vas': ['006b7c20..006b7c3f', '006b7c40', '006b7c44',
            '006b7c7c', '006a5bfc', '006a5c0c', '005deb48'],
        'semantics': {
            'tick': 'initial GetTickCount followed by one sample per enabled iteration; delta wraps unsigned 32-bit',
            'rate_accumulator': 'delta*1193 plus local accumulator wraps at 32 bits; signed JLE against 0xffff gates SAR16 carry into 006b7c44 and low-word mask',
            'iteration_state': '006b7c7c and canonical 006b7c40 each increment once per enabled loop',
            'callbacks': 'eight nullable cdecl zero-argument slots at 006b7c20..3f; each slot is reloaded immediately before call',
            'exit': 'create and wait once before checking active flag; loop waits after callbacks; close event, clear handle and canonical 005deb48, return zero'},
        'boundaries': {
            '005b2080': 'GetTickCount import through canonical __stdcall platform_get_tick_count declaration; fixture controls sampled ticks',
            '0055fb20': 'existing event-create helper; fixture records returned handle',
            '0055fb90': 'existing event-wait helper; fixture controls asynchronous active-flag changes while blocked',
            '0055fc10': 'existing event-close helper; fixture records handle and return',
            'callbacks': 'fixture callbacks record invocation and may mutate later slots; no callback algorithm is claimed'},
        'cases_summary': summaries,
        'compiled_translation_units': [tu_probe, tu_impl],
        'source_sha256': source_hashes([ROOT / path for path in pins],
                                       compiled_sources=compiled),
        'original_evidence': {
            'disassembly_path': 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
            'disassembly_sha256': hashlib.sha256((ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm').read_bytes()).hexdigest(),
            'manual_index_path': manual_path.relative_to(ROOT).as_posix(),
            'manual_index_sha256': hashlib.sha256(manual_path.read_bytes()).hexdigest(),
            'call_index_path': calls_path.relative_to(ROOT).as_posix(),
            'call_index_sha256': hashlib.sha256(calls_path.read_bytes()).hexdigest(),
            'import': {'iat_va': '005b2080', 'dll': tick_import['dll'],
                       'symbol': tick_import['symbol'], 'iat_rva': tick_import['iat_rva'],
                       'stdcall': True}},
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified': False,
    }
    (args.report_dir / 'verification.json').write_text(
        json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({'sha256': SHA, 'function_vas': report['function_vas'],
        'full_function_vas': report['full_function_vas'],
        'partial_function_vas': report['partial_function_vas'],
        'cases': len(summaries), 'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
