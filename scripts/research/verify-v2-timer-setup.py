"""Differentially compare the original x86 timer setup cluster and native C++."""
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
ENTRY = 0x565030
BODY_BYTES = 574
BODY_SHA = '905e1c12173e3725f34dbe8e56fc1cb0dbe18f3c0951fae361aacdfd0f133182'
STACK = 0x2210000
EXIT = 0x222fff0
HOOK_BASE = 0x710000
HOOKS = {
    'tick': HOOK_BASE + 0x100,
    'caps': HOOK_BASE + 0x110,
    'begin': HOOK_BASE + 0x120,
    'kill': HOOK_BASE + 0x130,
    'set': HOOK_BASE + 0x140,
    'end': HOOK_BASE + 0x150,
    'signal': HOOK_BASE + 0x160,
    'sleep': HOOK_BASE + 0x170,
    'thread': HOOK_BASE + 0x180,
    'atexit': HOOK_BASE + 0x190,
    'diagnostic': HOOK_BASE + 0x1a0,
    'aux': HOOK_BASE + 0x1b0,
}
IAT = {
    0x5b2080: 'tick',
    0x5b233c: 'begin',
    0x5b2340: 'caps',
    0x5b2344: 'kill',
    0x5b2348: 'set',
    0x5b234c: 'end',
    0x5b2160: 'sleep',
    0x5b2194: 'signal',
}


def scenario(case_id):
    rows = [
        (128, 0, 1, 0, 9, 0, 0, 0, 0, 0, 0, 1,
         [1000, 1000, 1000, 1000, 1010]),
        (10001, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 1,
         [2000, 2000, 2000, 2000, 2010]),
        (128, 1, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, [3000]),
        (1000, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, [4000]),
        (1000, 0, 1, 1, 8, 0, 0, 0, 0, 0, 0, 0, [5000]),
        (1000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         [6000, 6000, 6000, 6000]),
        (1000, 0, 1, 0, 10, 1, 7, 1, 0x2207000, 2, 0, 0,
         [7000, 7000, 7000, 12000, 17000]),
        (1000, 0, 1, 0, 8, 0, 0, 0, 0, 2, 0, 0,
         [8000, 9003, 9004, 9004, 14004]),
        (1000, 0, 1, 0, 10, 1, 7, 1, 0x2207000, 0, 1, 0,
         [7000, 7000, 7000, 12000, 17000]),
    ]
    (interval, caps, thread, begin, event, active, timer_id, period,
     handle, kill_mode, idle_clears_event, sleep_worker, ticks) = rows[case_id]
    return dict(interval=interval, caps=caps, thread=thread, begin=begin,
        event=event, active=active, timer_id=timer_id, period=period,
        handle=handle, kill_mode=kill_mode, sleep_worker=sleep_worker,
        idle_clears_event=idle_clears_event, ticks=ticks)


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def c_string(machine, address):
    value = bytearray()
    for offset in range(256):
        byte = machine.mem_read(address + offset, 1)[0]
        if byte == 0:
            break
        value.append(byte)
    return value.decode('ascii', errors='replace')


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP,
        UC_X86_REG_EBX, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESP,
        UC_X86_REG_ESI)

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

    def return_to_caller(machine, eax=0, cleanup=0):
        esp = machine.reg_read(UC_X86_REG_ESP)
        ret = word(esp)
        machine.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        machine.reg_write(UC_X86_REG_ESP, esp + 4 + cleanup)
        machine.reg_write(UC_X86_REG_EIP, ret)

    for address, name in IAT.items():
        put(address, HOOKS[name])
    put(0x5debf0, HOOKS['diagnostic'])
    put(0x69e5dc, 0)
    put(0x6a5bf8, 0)
    put(0x6a5c00, 0)
    put(0x6a5c04, 0)
    put(0x6a5c08, case['period'])
    put(0x6a5c0c, case['active'])
    put(0x6a5c10, case['timer_id'])
    put(0x6a5c1c, 0)
    put(0x6a5c20, 0)
    put(0x6a5bfc, case['handle'])
    put(0x6b7c7c, 0x11111111)
    put(0x6b7c44, 0x22222222)
    put(0x6b7c40, 0x33333333)
    put(0x5deb48, 0x44444444)
    put(0x5deb74, 0)
    put(0x5deb78, 0)
    for i in range(7):
        put(0x6b7c60 + 4 * i, 0xa5a50000 + i * 0x101)
    put(STACK, EXIT)
    put(STACK + 4, case['interval'])

    initial = {UC_X86_REG_EBX: 0x11223344,
        UC_X86_REG_EBP: 0x22334455, UC_X86_REG_ESI: 0x33445566,
        UC_X86_REG_EDI: 0x44556677}
    for register, value in initial.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)

    events = []
    pcs = []
    tick_index = 0
    sleep_count = 0

    def hook(machine, address, _size, _user):
        nonlocal tick_index, sleep_count
        pcs.append(address)
        if address == EXIT:
            machine.emu_stop()
            return
        if address == HOOKS['tick']:
            value = case['ticks'][min(tick_index, len(case['ticks']) - 1)]
            tick_index += 1
            events.append(f'tick:{value}')
            return_to_caller(machine, value)
            return
        if address == HOOKS['caps']:
            esp = machine.reg_read(UC_X86_REG_ESP)
            size = word(esp + 8)
            caps_ptr = word(esp + 4)
            events.append(f'caps:{size}')
            if case['caps'] == 0 and size >= 8:
                put(caps_ptr, 1)
                put(caps_ptr + 4, 1)
            return_to_caller(machine, case['caps'], 8)
        elif address == HOOKS['begin']:
            period = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append(f'begin:{period}')
            return_to_caller(machine, case['begin'], 4)
        elif address == HOOKS['kill']:
            event_id = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append(f'kill:{event_id}')
            if case['kill_mode'] == 1:
                put(0x6a5c10, 0)
            return_to_caller(machine, 0, 4)
        elif address == HOOKS['set']:
            esp = machine.reg_read(UC_X86_REG_ESP)
            delay, resolution = word(esp + 4), word(esp + 8)
            callback, user, flags = word(esp + 12), word(esp + 16), word(esp + 20)
            label = 'producer' if callback == 0x564eb0 else 'other'
            events.append(f'set:{delay},{resolution},{user},{flags},{label}')
            return_to_caller(machine, case['event'], 20)
        elif address == HOOKS['end']:
            period = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append(f'end:{period}')
            return_to_caller(machine, 0, 4)
        elif address == HOOKS['signal']:
            handle = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append(f'signal:{handle:#x}')
            return_to_caller(machine, 1, 4)
        elif address == HOOKS['sleep']:
            esp = machine.reg_read(UC_X86_REG_ESP)
            milliseconds = word(esp + 4)
            sleep_count += 1
            events.append(f'sleep:{milliseconds}')
            if case['kill_mode'] == 2 and word(0x6a5c0c) == 0:
                put(0x6a5c10, 0)
            if case['idle_clears_event'] and word(0x6a5c0c) == 0:
                put(0x6a5bfc, 0)
            if case['sleep_worker'] and sleep_count == 1:
                put(0x6b7c7c, word(0x6b7c7c) + 1)
            return_to_caller(machine, 0, 8)
        elif address == HOOKS['thread']:
            esp = machine.reg_read(UC_X86_REG_ESP)
            callback, stack, priority = word(esp + 4), word(esp + 8), word(esp + 12)
            unused, out_ptr = word(esp + 16), word(esp + 20)
            if out_ptr != 0x6b7c60:
                raise AssertionError(f'00565030 output pointer changed: {out_ptr:#x}')
            label = 'worker' if callback == 0x565270 else 'other'
            events.append(f'thread:{label},{stack},{priority},{unused},out-record')
            if case['thread']:
                for offset, value in enumerate((0x2207100, 0, 2, 0,
                        0x3456, 0x11223344, 7)):
                    put(out_ptr + offset * 4, value)
                put(0x6a5bfc, case['handle'] or 0x2207100)
            return_to_caller(machine, case['thread'])
        elif address == HOOKS['atexit']:
            callback = word(machine.reg_read(UC_X86_REG_ESP) + 4)
            events.append('atexit:cleanup' if callback == 0x564fa0 else 'atexit:other')
            return_to_caller(machine, 0)
        elif address == HOOKS['diagnostic']:
            esp = machine.reg_read(UC_X86_REG_ESP)
            message = word(esp + 4)
            argument = word(esp + 8) if message == 0x5bd480 else 0
            source = c_string(machine, word(0x5deb74))
            events.append(f'diag:{word(0x5deb78)}:{argument}:{source}')
            return_to_caller(machine, 0)
        elif address == HOOKS['aux']:
            events.append('aux-call')
            return_to_caller(machine, 0)
        elif address == 0x55f420:
            # Canonical recovered window thread-start wrapper is a fixture boundary here.
            machine.reg_write(UC_X86_REG_EIP, HOOKS['thread'])
        elif address == 0x557380:
            machine.reg_write(UC_X86_REG_EIP, HOOKS['atexit'])
        elif address == 0x53c270:
            machine.reg_write(UC_X86_REG_EIP, HOOKS['aux'])

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(ENTRY, 0, count=100000)
    except Exception as error:
        raise AssertionError(f'x86 oracle failed at EIP={uc.reg_read(UC_X86_REG_EIP):08x}; tail={[hex(x) for x in pcs[-20:]]}: {error}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'00565030 did not return; EIP={uc.reg_read(UC_X86_REG_EIP):08x}')
    preserved = {reg: uc.reg_read(number) for reg, number in
        [('ebx', UC_X86_REG_EBX), ('ebp', UC_X86_REG_EBP),
         ('esi', UC_X86_REG_ESI), ('edi', UC_X86_REG_EDI)]}
    if preserved != {'ebx': 0x11223344, 'ebp': 0x22334455,
                     'esi': 0x33445566, 'edi': 0x44556677}:
        raise AssertionError(f'callee-saved registers changed: {preserved}')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError('00565030 stack cleanup differs from one-argument cdecl')
    state_addresses = [0x6a5bf8, 0x6a5c00, 0x6a5c04, 0x6a5c08,
        0x6a5c10, 0x6a5c1c, 0x6a5c20, 0x6a5c0c, 0x6b7c7c,
        0x6b7c44, 0x6b7c40, 0x5deb48, 0x6a5bfc, 0x5deb78,
        *range(0x6b7c60, 0x6b7c7c, 4)]
    return {'state': [word(address) for address in state_addresses], 'events': events}


def native(probe, case_id):
    result = subprocess.run([str(probe), str(case_id)], text=True,
        capture_output=True, check=True)
    lines = result.stdout.splitlines()
    if len(lines) != 2 or not lines[0].startswith('state=') or not lines[1].startswith('events='):
        raise AssertionError(f'bad native probe output: {result.stdout!r}')
    values = [int(value) for value in lines[0][6:].split(',')]
    events = [] if not lines[1][7:] else lines[1][7:].split(';')
    return {'state': values, 'events': events}


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
    functions_path = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    functions = [json.loads(line) for line in functions_path.read_text().splitlines()]
    rows = {}
    for address in ('00564eb0', '00564fa0', '00565030'):
        rows[address] = next(row for row in functions if row['entry_va'] == address)
    bodies = {}
    for address, row in rows.items():
        entry, end = (int(part, 16) for part in row['ranges'][0])
        body = read_va(image, module, entry, end - entry + 1)
        if len(body) != row['body_bytes']:
            raise AssertionError(f'function size mismatch at {address}')
        bodies[address] = hashlib.sha256(body).hexdigest()
    expected_layout = {
        '00564eb0': (199, '00564eb0', '00564f76'),
        '00564fa0': (131, '00564fa0', '00565022'),
        '00565030': (574, '00565030', '0056526d'),
    }
    for address, (size, begin, end) in expected_layout.items():
        if rows[address]['body_bytes'] != size or rows[address]['ranges'] != [[begin, end]]:
            raise AssertionError(f'function range mismatch at {address}: {rows[address]}')
    if rows['00565030']['body_bytes'] != BODY_BYTES:
        raise AssertionError('00565030 body length differs from expected 574 bytes')
    if bodies['00565030'] != BODY_SHA:
        raise AssertionError('00565030 original body hash mismatch')

    import_rows = [json.loads(line) for line in
        (ROOT / 'research/binary-index/static/imports.jsonl').read_text().splitlines()]
    expected_imports = {'timeBeginPeriod': 0x5b233c,
        'timeGetDevCaps': 0x5b2340, 'timeKillEvent': 0x5b2344,
        'timeSetEvent': 0x5b2348, 'timeEndPeriod': 0x5b234c}
    for symbol, address in expected_imports.items():
        row = next(item for item in import_rows if item.get('path') == 'Porsche.exe'
            and item.get('dll', '').lower() == 'winmm.dll'
            and item.get('symbol') == symbol)
        if BASE + int(row['iat_rva'], 16) != address:
            raise AssertionError(f'WinMM IAT mismatch: {symbol}: {row}')
    expected_kernel_imports = {'GetTickCount': 0x5b2080,
        'SleepEx': 0x5b2160, 'SetEvent': 0x5b2194}
    for symbol, address in expected_kernel_imports.items():
        row = next(item for item in import_rows if item.get('path') == 'Porsche.exe'
            and item.get('dll', '').lower() == 'kernel32.dll'
            and item.get('symbol') == symbol)
        if BASE + int(row['iat_rva'], 16) != address:
            raise AssertionError(f'KERNEL32 IAT mismatch: {symbol}: {row}')

    summaries = []
    for case_id in range(9):
        original_result = original(module, image, scenario(case_id))
        native_result = native(args.probe, case_id)
        if native_result != original_result:
            raise AssertionError(f'case {case_id}: original={original_result}; native={native_result}')
        summaries.append({'case': case_id, 'events': len(original_result['events']),
            'diagnostics': sum(e.startswith('diag:') for e in original_result['events']),
            'equal': True})

    iteration = 'iterations/v2/001-original-recovery/'
    pins = [
        iteration + 'source/include/porsche/timer_setup.hpp',
        iteration + 'source/recovered/Porsche.exe/timer_setup.cpp',
        iteration + 'source/recovered/timer_setup_probe.cpp',
        iteration + 'source/include/porsche/clock_worker.hpp',
        iteration + 'source/include/porsche/file_events.hpp',
        iteration + 'source/include/porsche/file_threads.hpp',
        iteration + 'source/include/porsche/object_update.hpp',
        iteration + 'source/include/porsche/shared_runtime_globals.hpp',
        iteration + 'source/include/porsche/window_create.hpp',
        iteration + 'source/recovered/Porsche.exe/shared_runtime_globals.cpp',
        iteration + 'source/recovered/Porsche.exe/window_threads.cpp',
        iteration + 'source/recovered/Porsche.exe/file_events.cpp',
        iteration + 'runs/118-timer-setup/CMakeLists.txt',
        iteration + 'runs/118-timer-setup/README.md',
        'scripts/research/verify-v2-timer-setup.py',
        'scripts/research/v2_source_dependencies.py',
        'research/binary-index/static/imports.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/strings.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
    ]
    report = {
        'schema': 1,
        'module': 'Porsche.exe',
        'sha256': SHA,
        'module_sha256': SHA,
        'function_vas': ['00564eb0', '00564fa0', '00565030'],
        'full_function_vas': ['00564eb0', '00564fa0', '00565030'],
        'partial_function_vas': [],
        'cases': len(summaries),
        'native_cpp_equal_original_x86': True,
        'original_functions': [
            {'va': address, 'body_bytes': rows[address]['body_bytes'],
             'body_sha256': bodies[address],
             'abi': abi}
            for address, abi in [
                ('00564eb0', 'stdcall, five DWORD callback arguments, RET 0x14; inputs unused'),
                ('00564fa0', 'cdecl, zero stack arguments, RET; return ignored'),
                ('00565030', 'cdecl, one DWORD interval argument, caller cleanup; return ignored')]],
        'imports': expected_imports,
        'kernel_imports': expected_kernel_imports,
        'state_vas': ['006a5bf8', '006a5c00', '006a5c04', '006a5c08',
            '006a5c10', '006a5c1c', '006a5c20', '006a5c0c', '006b7c7c',
            '006b7c44', '006b7c40', '005deb48', '006a5bfc', '005deb74', '005deb78',
            '006b7c60', '006b7c64', '006b7c68', '006b7c6c', '006b7c70',
            '006b7c74', '006b7c78'],
        'boundaries': [
            'WINMM timeGetDevCaps/timeBeginPeriod/timeKillEvent/timeSetEvent/timeEndPeriod imports',
            'KERNEL32 GetTickCount, SleepEx, SetEvent imports',
            '0055f420 canonical recovered window_thread_start_0055f420 implementation; fixture replaces it in oracle/probe',
            '00557380 CRT exit-registration wrapper; fixture records callback registration',
            '0053c270 auxiliary SetEvent helper remains timer_auxiliary_wait_boundary; fixture records call with its global handle set null',
            '005debf0 diagnostic callback and asynchronous timer/worker scheduling',
        ],
        'cases_detail': summaries,
        'source_sha256': source_hashes([ROOT / pin for pin in pins]),
        'compiled_translation_units': [
            str((ROOT / iteration / 'source/recovered/Porsche.exe/timer_setup.cpp').resolve()),
            str((ROOT / iteration / 'source/recovered/timer_setup_probe.cpp').resolve()),
            str((ROOT / iteration / 'source/recovered/Porsche.exe/shared_runtime_globals.cpp').resolve()),
        ],
    }
    (args.report_dir / 'verification.json').write_text(
        json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f"verified {len(summaries)} original x86 timer cases; report={args.report_dir / 'verification.json'}")


if __name__ == '__main__':
    main()
