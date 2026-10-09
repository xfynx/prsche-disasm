from v2_source_dependencies import source_hashes
"""Compare recovered heap commit/object-start wrappers with Porsche.exe x86."""
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

EXIT, STACK, ARENA = 0x2200000, 0x200f000, 0x3600000
HEAPS, HEAP_ARENAS, PAGE_SIZE = 0x6b4f20, 0x6af3b4, 0x6af3f8
DEFAULT_ARENA, QUEUE_INDEX = 0x5deb98, 0x6af374


def cases():
    rows = []
    for bytes_ in (1, 0x1000, 0x1001, 0x2000, 0x1800000):
        for occupied in (0, 1, 7, 12):
            for slot in (0, 0xffffffff, 0xfffffffd):
                for locked, quantum in ((0, 8), (1, 8), (1, 0x100)):
                    for success in (0, 1):
                        rows.append((1, bytes_, 0x1000, success, occupied, slot, locked, quantum))
    for existing_default in (0, 1):
        for bytes_ in (1, 0x1800000):
            rows.append((0, bytes_, 0x1000, 1, existing_default, 0, 0, 0))
    return rows


def original(case, module, data):
    op, bytes_, page, success, occupied, queue_slot, locked, quantum = case
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        uc.mem_write(base + section['rva'], data[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2000000, 0x10000)
    uc.mem_map(EXIT, 0x1000)
    uc.mem_map(ARENA, 0x1000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def cstring(address):
        return bytes(uc.mem_read(address, 32)).split(b'\0', 1)[0].decode('latin1')

    put(PAGE_SIZE, page)
    put(DEFAULT_ARENA, 0x03600900 if op == 0 and occupied else 0)
    for index in range(16):
        put(HEAPS + index * 4, 0)
        put(HEAP_ARENAS + index * 4, 0)
    for index in range(occupied if op == 1 else 0):
        put(HEAPS + (3 + index) * 4, 0x03600400 + (3 + index) * 0x40)
    put(STACK, EXIT)
    if op == 0:
        args = (ARENA + 0x200, bytes_)
        function = 0x5aef80
        output_index = 0
    else:
        args = (bytes_, 0x5e5058, queue_slot, locked, quantum)
        function = 0x59ebc0
        output_index = 3 + occupied
    for i, arg in enumerate(args):
        put(STACK + 4 + i * 4, arg)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    calls = []

    bounds = ((0x5aef80, 0x5aefca), (0x59ebc0, 0x59ec39),
              (0x569a70, 0x569a8b), (0x59ed40, 0x59ed8a))
    trace = []

    def hook(machine, address, _size, _user):
        trace.append(address)
        if address == EXIT:
            machine.emu_stop()
            return
        sp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5697f0:
            index, name, arena, size, pool, alignment = [word(sp + 4 + 4 * i) for i in range(6)]
            locked_arg = word(sp + 44)
            callback = word(sp + 48)
            flags = (1 if locked_arg else 0) | (2 if callback else 0)
            calls.append(['heap_init', cstring(name), index, arena, size, pool, alignment, flags])
            if index < 16:
                put(HEAPS + index * 4, 0x03600400 + index * 0x40)
            machine.reg_write(UC_X86_REG_EAX, 1)
            machine.reg_write(UC_X86_REG_ESP, sp + 4)
            machine.reg_write(UC_X86_REG_EIP, word(sp))
            return
        if address == 0x59ed80:
            arena, size, allocation_type, protection = [word(sp + 4 * i) for i in range(4)]
            calls.append(['alloc', '', size, allocation_type, protection, 0, 0, 0])
            machine.reg_write(UC_X86_REG_EAX, ARENA + 0x200 if success else 0)
            # This hook is on the CALL instruction, before it pushes a return
            # address. VirtualAlloc removes the four arguments on return.
            machine.reg_write(UC_X86_REG_ESP, sp + 16)
            machine.reg_write(UC_X86_REG_EIP, address + 6)
            return
        if address == EXIT:
            return
        if not any(first <= address <= last for first, last in bounds):
            raise RuntimeError(f'unexpected original code at {address:08x}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(function, EXIT + 1, count=2000)
    except Exception as error:
        raise RuntimeError(f'original emulation failed at {uc.reg_read(UC_X86_REG_EIP):08x} for {case}; trace={[f"{x:08x}" for x in trace[-20:]]}') from error
    assert uc.reg_read(UC_X86_REG_EIP) == EXIT
    return {
        'return': uc.reg_read(UC_X86_REG_EAX),
        'page': word(PAGE_SIZE),
        'default': word(DEFAULT_ARENA),
        'heap0': word(HEAPS),
        'heap1': word(HEAPS + 4),
        'heap_at': word(HEAPS + output_index * 4),
        'arena_at': word(HEAP_ARENAS + output_index * 4),
        'queue_slot': word(QUEUE_INDEX + 4),
        'calls': calls,
    }


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/application_heap_init_probe.exe')
    parser.add_argument('--report-dir',type=Path,default=ROOT/'iterations/v2/001-original-recovery/runs/033-application-heap-init')
    args=parser.parse_args();binary=args.probe
    report=args.report_dir
    report.mkdir(parents=True,exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file'] == 'Porsche.exe')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    expected_sha = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    assert hashlib.sha256(data).hexdigest() == expected_sha
    inputs = cases()
    process = subprocess.run([str(binary)], input=''.join(' '.join(map(str, row)) + '\n' for row in inputs),
                             text=True, capture_output=True, check=True)
    native = list(map(json.loads, process.stdout.splitlines()))
    assert len(native) == len(inputs)
    for i, (case, actual) in enumerate(zip(inputs, native)):
        expected = original(case, module, data)
        if case[0] == 0:
            # The primary wrapper is void; EAX is not part of its C++ API.
            actual.pop('return')
            expected.pop('return')
        if actual != expected:
            raise AssertionError(f'case {i} {case}: original={expected} native={actual}')
    paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/application_heap_init.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_heap_init.cpp',
        'iterations/v2/001-original-recovery/source/recovered/application_heap_init_probe.cpp',
    ]
    paths += ['scripts/research/verify-v2-application-heap-init.py']
    paths += ['iterations/v2/001-original-recovery/source/include/porsche/application_heap.hpp','iterations/v2/001-original-recovery/source/include/porsche/heap.hpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_heap.cpp']
    result = {'schema': 1, 'module': 'Porsche.exe', 'sha256': expected_sha, 'module_sha256': expected_sha,
              'function_vas': ['005aef80', '0059ebc0', '00569a70'], 'cases': len(inputs),
              'native_cpp_equal_original_x86': True,
              'scope': 'Primary heap commit and optional object heap start; page allocation is exercised through the Run025 consumer; 005679f0 pool initialization remains a separate dependency.',
              'source_sha256': {p: hashlib.sha256((ROOT / p).read_bytes().replace(b'\r\n', b'\n')).hexdigest() for p in paths},
              'probe_sha256': hashlib.sha256(binary.read_bytes()).hexdigest()}
    result['source_sha256']=source_hashes([*result['source_sha256'],Path(__file__)])
    (report / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({'cases': len(inputs), 'function_vas': result['function_vas'], 'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
