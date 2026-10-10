"""Compare original x86 0053c270 with the bounded native recovery."""
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
ENTRY = 0x53c270
BODY_BYTES = 17
STACK = 0x2210000
EXIT = 0x222fff0
HOOK = 0x710100
EVENT = 0x69e5dc
CASES = (0, 0x02201000, 0x12345678)


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def original(module, image, handle):
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
    uc.mem_map(0x710000, 0x10000)

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

    put(EVENT, handle)
    put(STACK, EXIT)
    initial = {UC_X86_REG_EBX: 0x11223344,
        UC_X86_REG_EBP: 0x22334455, UC_X86_REG_ESI: 0x33445566,
        UC_X86_REG_EDI: 0x44556677}
    for register, value in initial.items():
        uc.reg_write(register, value)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    events = []

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
        elif address == 0x55fb30:
            esp = machine.reg_read(UC_X86_REG_ESP)
            event = word(esp + 4)
            events.append(f'signal:{event:#x}')
            # The recovered SetEvent wrapper's return is deliberately an
            # ignored boundary result at this call site.
            return_to_caller(machine, 1)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(ENTRY, 0, count=1000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'0053c270 did not return: EIP={uc.reg_read(UC_X86_REG_EIP):08x}')
    if uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise AssertionError('0053c270 zero-argument cdecl stack behavior differs')
    preserved = {reg: uc.reg_read(number) for reg, number in
        [('ebx', UC_X86_REG_EBX), ('ebp', UC_X86_REG_EBP),
         ('esi', UC_X86_REG_ESI), ('edi', UC_X86_REG_EDI)]}
    if preserved != {'ebx': 0x11223344, 'ebp': 0x22334455,
                     'esi': 0x33445566, 'edi': 0x44556677}:
        raise AssertionError(f'callee-saved registers changed: {preserved}')
    return {'state': word(EVENT), 'events': events}


def native(probe, handle):
    result = subprocess.run([str(probe)], input=f'{handle:x}\n', text=True,
        capture_output=True, check=True)
    fields = result.stdout.split()
    if len(fields) < 2:
        raise AssertionError(f'bad native probe output: {result.stdout!r}')
    state, count = int(fields[0], 16), int(fields[1], 10)
    signals = [int(value, 16) for value in fields[2:]]
    if len(signals) != count:
        raise AssertionError(f'bad native signal count: {result.stdout!r}')
    return {'state': state, 'events': [f'signal:{value:#x}' for value in signals]}


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
    row = next(item for item in functions if item['entry_va'] == '0053c270')
    if row['ranges'] != [['0053c270', '0053c280']] or row['body_bytes'] != BODY_BYTES:
        raise AssertionError(f'0053c270 index range mismatch: {row}')
    body = read_va(image, module, ENTRY, BODY_BYTES)
    body_sha = hashlib.sha256(body).hexdigest()

    references_path = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl'
    references = [json.loads(line) for line in references_path.read_text().splitlines()]
    cell_refs = [item for item in references if item.get('to_va') == '0069e5dc']
    expected_refs = {
        ('0053c0f5', 'WRITE'), ('0053c104', 'READ'),
        ('0053c14f', 'READ'), ('0053c15d', 'WRITE'),
        ('0053c179', 'READ'), ('0053c270', 'READ'),
    }
    if {(item['from_va'], item['type']) for item in cell_refs} != expected_refs:
        raise AssertionError(f'0069e5dc reference set changed: {cell_refs}')
    calls_path = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl'
    calls = [json.loads(line) for line in calls_path.read_text().splitlines()]
    if not any(item.get('from_va') == '0053c27a' and item.get('to_va') == '0055fb30'
            for item in calls):
        raise AssertionError('0053c270 -> canonical signal helper call edge missing')

    data = next(section for section in module['sections'] if section['name'] == '.data')
    image_base = int(module['image_base'], 16)
    raw_end = image_base + data['rva'] + data['raw_size']
    virtual_end = image_base + data['rva'] + data['vsize']
    if not raw_end <= EVENT < virtual_end:
        raise AssertionError(f'0069e5dc is not in the .data zero-fill tail: {data}')
    summaries = []
    for handle in CASES:
        x86 = original(module, image, handle)
        cpp = native(args.probe, handle)
        if cpp != x86:
            raise AssertionError(f'handle {handle:#x}: original={x86}; native={cpp}')
        summaries.append({'input_handle': f'{handle:#010x}', 'events': len(x86['events']),
            'state_unchanged': x86['state'] == handle, 'equal': True})

    iteration = 'iterations/v2/001-original-recovery/'
    pins = [
        iteration + 'source/include/porsche/auxiliary_wait.hpp',
        iteration + 'source/recovered/Porsche.exe/auxiliary_wait.cpp',
        iteration + 'source/recovered/auxiliary_wait_probe.cpp',
        iteration + 'source/include/porsche/files.hpp',
        iteration + 'runs/122-auxiliary-wait/CMakeLists.txt',
        iteration + 'runs/122-auxiliary-wait/README.md',
        'scripts/research/verify-v2-auxiliary-wait.py',
        'scripts/research/v2_source_dependencies.py',
        'research/binary-index/static/binaries.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl',
    ]
    report = {
        'schema': 1,
        'module': 'Porsche.exe',
        'sha256': SHA,
        'module_sha256': SHA,
        'function_vas': ['0053c270'],
        'full_function_vas': ['0053c270'],
        'partial_function_vas': [],
        'cases': len(summaries),
        'native_cpp_equal_original_x86': True,
        'original_functions': [{'va': '0053c270', 'body_bytes': BODY_BYTES,
            'body_sha256': body_sha,
            'abi': 'cdecl, zero arguments, RET; SetEvent return ignored'}],
        'state_vas': ['0069e5dc'],
        'storage': {
            'va': '0069e5dc',
            'type': 'one pointer-sized Win32 event HANDLE cell',
            'initialization': 'PE .data virtual tail, not present in raw bytes; zero-filled on image load',
            'producer': 'anonymous worker body 0053c0f0 writes the result of 0055fb20 at 0053c0f5',
            'clear': 'anonymous worker body 0053c0f0 clears cell at 0053c15d before RET',
            'other_indexed_accesses': ['0053c104 read', '0053c14f read', '0053c179 read'],
        },
        'boundaries': [
            '0055fb30 canonical recovered file_event_signal_0055fb30; fixture records the typed call and supplies its ignored return',
            'The 0053c0f0 worker lifecycle, event creation/wait, callback list and cleanup remain outside this Run122 body',
        ],
        'cases_detail': summaries,
        'source_sha256': source_hashes([ROOT / pin for pin in pins]),
        'compiled_translation_units': [
            str((ROOT / iteration / 'source/recovered/Porsche.exe/auxiliary_wait.cpp').resolve()),
            str((ROOT / iteration / 'source/recovered/auxiliary_wait_probe.cpp').resolve()),
        ],
    }
    (args.report_dir / 'verification.json').write_text(
        json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(f"verified {len(summaries)} original x86 auxiliary-wait cases; report={args.report_dir / 'verification.json'}")


if __name__ == '__main__':
    main()
