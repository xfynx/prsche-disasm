"""Differentially verify startup pool allocation against Porsche.exe x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP

EXIT, STACK = 0x2200000, 0x200f000
ARENAS = (0x03600000, 0x03610000, 0x03620000)
LOCK_BASE = 0x03700000
DEVICE_PTR, PHYSICAL_COUNT, PHYSICAL_PTR = 0x6a5c7c, 0x6af080, 0x6af084
PAGE_SIZE, SLOT_LOCK = 0x6a6418, 0x6af07c
OP_LIST, AUX_LIST = 0x6a5c58, 0x6a5c38


def cases():
    return [(disk, ops, 4096, pre)
            for disk, ops in ((0, 0), (1, 1), (4, 13), (64, 64), (96, 100))
            for pre in (0,)] + [(64, 64, 4096, 1)]


def original(case, module, data):
    disk_slots, operation_slots, page, preinitialized = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        uc.mem_write(base + section['rva'], data[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2000000, 0x10000)
    uc.mem_map(EXIT, 0x1000)
    for arena in ARENAS:
        uc.mem_map(arena, 0x2000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    uc.mem_write(0x6a5c38, bytes(0x1c))
    uc.mem_write(0x6a5c58, bytes(0x1c))
    uc.mem_write(0x6aeffc, bytes(0x80))
    put(DEVICE_PTR, ARENAS[0] if preinitialized else 0)
    put(PHYSICAL_COUNT, 0);put(PHYSICAL_PTR, 0);put(PAGE_SIZE, page);put(SLOT_LOCK, 0)
    put(0x6a5c54, 0);put(0x6a5c78, 0);put(0x6a5c74, 0)
    put(STACK, EXIT)
    for i, arg in enumerate((disk_slots, 0, operation_slots)):
        put(STACK + 4 + 4 * i, arg)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    calls, allocations, locks = [], 0, 0
    allowed = ((0x5679f0, 0x567ae6), (0x591820, 0x5918b4),
               (0x580630, 0x58066f), (0x5806e0, 0x580721),
               (0x56e5f0, 0x56e639), (0x557380, 0x55738b))

    def hook(machine, address, _size, _user):
        nonlocal allocations, locks
        if address == EXIT:
            machine.emu_stop();return
        sp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5321f0:
            result = LOCK_BASE + locks * 0x100
            calls.append(['lock_create', result]);locks += 1
            machine.reg_write(UC_X86_REG_EAX, result)
            machine.reg_write(UC_X86_REG_ESP, sp + 4);machine.reg_write(UC_X86_REG_EIP, word(sp));return
        if address in (0x5322b0, 0x5322c0):
            calls.append(['enter' if address == 0x5322b0 else 'leave', word(sp + 4)])
            machine.reg_write(UC_X86_REG_ESP, sp + 4);machine.reg_write(UC_X86_REG_EIP, word(sp));return
        if address == 0x53c290:
            dest, value, count = word(sp + 4), word(sp + 8), word(sp + 12)
            calls.append(['fill', dest, value, count])
            if dest:machine.mem_write(dest, bytes([value & 0xff]) * count)
            machine.reg_write(UC_X86_REG_EAX, dest)
            machine.reg_write(UC_X86_REG_ESP, sp + 4);machine.reg_write(UC_X86_REG_EIP, word(sp));return
        if address == 0x56e62f:
            dest, size, kind, protection = [word(sp + 4 * i) for i in range(4)]
            result = ARENAS[allocations] if allocations < len(ARENAS) else 0
            calls.append(['alloc', size, kind, protection, result]);allocations += 1
            machine.reg_write(UC_X86_REG_EAX, result)
            machine.reg_write(UC_X86_REG_ESP, sp + 16);machine.reg_write(UC_X86_REG_EIP, address + 6);return
        if address == 0x5a2400:
            callback = word(sp + 4)
            calls.append(['callback_register', callback])
            machine.reg_write(UC_X86_REG_EAX, 0)
            machine.reg_write(UC_X86_REG_ESP, sp + 4);machine.reg_write(UC_X86_REG_EIP, word(sp));return
        if not any(first <= address <= last for first, last in allowed):
            raise RuntimeError(f'unexpected original code at {address:08x}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(0x5679f0, EXIT + 1, count=100000)
    except Exception as error:
        raise RuntimeError(f'original emulation failed at {uc.reg_read(UC_X86_REG_EIP):08x} for {case}') from error
    assert uc.reg_read(UC_X86_REG_EIP) == EXIT

    def list_state(address):
        vals = [word(address + n) for n in range(0, 28, 4)]
        if vals[4] == 0x580670:pass
        return vals

    return {'return': uc.reg_read(UC_X86_REG_EAX), 'page': word(PAGE_SIZE),
            'devices': word(DEVICE_PTR), 'physical': word(PHYSICAL_PTR),
            'physical_count': word(PHYSICAL_COUNT), 'operation_arena': word(0x6a5c54),
            'disk_lock': word(SLOT_LOCK), 'pool_lock': word(0x6a5c78),
            'shutdown_state': word(0x6a5c74), 'disk_mutexes': bytes(uc.mem_read(0x6aeffc, 0x80)).hex(),
            'free_operations': list_state(OP_LIST), 'free_auxiliary': list_state(AUX_LIST),
            'arenas': [bytes(uc.mem_read(a, 0x2000)).hex() for a in ARENAS], 'calls': calls}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/application-pool/bin/Release/application_pool_probe.exe")
    parser.add_argument("--report-dir",type=Path,default=ROOT/"iterations/v2/001-original-recovery/runs/037-application-pool")
    args=parser.parse_args()
    binary = args.probe
    report = args.report_dir
    report.mkdir(parents=True,exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file'] == 'Porsche.exe')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    expected_sha = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    assert hashlib.sha256(data).hexdigest() == expected_sha
    inputs = cases()
    process = subprocess.run([str(binary)], input=''.join(' '.join(map(str, row)) + '\n' for row in inputs), text=True, capture_output=True, check=True)
    native = list(map(json.loads, process.stdout.splitlines()))
    assert len(native) == len(inputs)
    for index, (case, actual) in enumerate(zip(inputs, native)):
        expected = original(case, module, data)
        if actual != expected:
            details=[]
            for key in expected:
                if actual.get(key)==expected[key]:continue
                if key=='calls':
                    at=next((j for j,(a,b) in enumerate(zip(actual[key],expected[key])) if a!=b),min(len(actual[key]),len(expected[key])))
                    details.append(f'calls[{at}] original={expected[key][at:at+2]} native={actual[key][at:at+2]} lengths={len(expected[key])}/{len(actual[key])}')
                elif key=='arenas':
                    ai=next(j for j,(a,b) in enumerate(zip(actual[key],expected[key])) if a!=b)
                    off=next((j for j,(a,b) in enumerate(zip(actual[key][ai],expected[key][ai])) if a!=b),-1)
                    details.append(f'arenas[{ai}] first_diff={off} original={expected[key][ai][max(0,off-16):off+32]} native={actual[key][ai][max(0,off-16):off+32]}')
                else:details.append(f'{key}: original={expected[key]} native={actual.get(key)}')
            raise AssertionError(f'case {index} {case}: '+'; '.join(details))
    paths = [
        'scripts/research/verify-v2-application-pool.py',
        'iterations/v2/001-original-recovery/source/include/porsche/application_pool.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/disk_open.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_device.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_worker.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_threads.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_events.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/file_wait.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/files.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap_locks.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_pool.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_pages.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/file_device.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/io_worker_lists.cpp',
        'iterations/v2/001-original-recovery/source/recovered/application_pool_probe.cpp',
        'iterations/v2/001-original-recovery/runs/037-application-pool/CMakeLists.txt',
    ]
    result = {'schema': 1, 'module': 'Porsche.exe', 'sha256': expected_sha, 'module_sha256': expected_sha,
              'function_vas': ['005679f0', '00591820', '00557380', '00580630', '005806e0', '0056e5f0'],
              'full_function_vas': ['00557380'],
              'partial_function_vas': ['005679f0', '00591820'],
              'cases': len(inputs), 'native_cpp_equal_original_x86': True,
              'scope': 'Initial application pool startup and first disk-slot initialization; lock, fill, Win32 allocation and callback-registry insertion are explicit boundaries. Reinitialization cleanup and shutdown callback are outside startup scope.',
              'source_sha256': {p: hashlib.sha256((ROOT / p).read_bytes().replace(b'\r\n', b'\n')).hexdigest() for p in paths},
              'probe_sha256': hashlib.sha256(binary.read_bytes()).hexdigest()}
    (report / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({'cases': len(inputs), 'function_vas': result['function_vas'], 'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
