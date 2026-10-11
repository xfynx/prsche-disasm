import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/135-application-context-base'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
MODULE_DIR = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d'
IMAGE, IMAGE_SIZE = 0x400000, 0x300000
ARENA, ARENA_SIZE, STACK, EXIT = 0x23000000, 0x200000, 0x02200000, 0x02210000
MANAGER, LOCK, HEAP_SELECTOR = 0x23010000, 0x23010100, 0x23010300
CONTEXT, HEAD, HEAD_NEXT = 0x23020000, 0x23030000, 0x23031000
CTOR_ALLOC, CONTEXT_MEMBER, MEMBER_STORAGE = 0x23040000, 0x23041000, 0x23042000
EXISTING_HEAD, LIST_NODE = 0x23043000, 0x23044000
MEMBER, MEMBER_ARRAY, MEMBER_BLOCK = 0x23050000, 0x23060000, 0x23070000
RETURN_VALUE = 0xCAFE0071
CASES = range(20)
FULL_CONSTRUCTOR_CASES = (0, 1, 2, 6)
FULL_MEMBER_CASES = (3, 4, 9, 10, 11, 16, 17)
FULL_HELPER_CASES = (12, 13, 14, 15, 19)
CASE_NAMES = [
    'base-allocation-null', 'base-new-head', 'base-existing-head-one-node',
    'member-allocation-null', 'member-one-block', 'composed-context',
    'base-new-head-mutates-lock-and-next', 'base-two-nodes-callback-mutations',
    'base-count-nonzero-list-empty', 'member-array-callback-changes-count',
    'member-finalize-nulls-array', 'member-callbacks-change-bounds-count-array',
    'copy-forward-overlap', 'range-link-overlapping-source-field',
    'blocks-three-changing-selector-pointer', 'blocks-reversed-range',
    'member-null-block-result', 'member-finalize-zeroes-count',
    'base-null-preserves-second-eax-seed', 'blocks-empty-range',
]

sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EDX, UC_X86_REG_ESP, UC_X86_REG_EIP
from unicorn.x86_const import UC_X86_REG_EBX, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI
sys.path.insert(0, str(ROOT / 'scripts/research'))
from v2_source_dependencies import source_hashes


def hex32(value):
    return f'{value & 0xffffffff:08x}'


def hex_bytes(raw):
    return raw.hex()


def seed_arena(machine, case_id):
    pattern = bytes((i * 19 + 0x17) & 0xff for i in range(ARENA_SIZE))
    machine.mem_write(ARENA, pattern)

    def put(address, value):
        machine.mem_write(address, struct.pack('<I', value & 0xffffffff))

    put(MANAGER + 0x28, LOCK)
    put(MANAGER + 0x40, EXISTING_HEAD if case_id in (2, 7, 8) else 0)
    put(EXISTING_HEAD, 0x11111111)
    put(EXISTING_HEAD + 4, HEAD)
    put(HEAD, 0x22222222)
    put(HEAD + 4, 0)
    put(HEAP_SELECTOR, 7)
    for offset, value in enumerate((0x23061000, 0x23062000, 0x23063000,
                                    MEMBER_BLOCK, 0x23065000, 0x23066000,
                                    0x23067000, 0x23068000)):
        put(MEMBER_ARRAY + offset * 4, value)
    put(LIST_NODE + 8, 0)
    put(LIST_NODE + 0x0c, 0x55667788)
    put(LIST_NODE + 0x10, 0x23045000)
    put(LIST_NODE + 0x108, 0)
    put(LIST_NODE + 0x10c, 0x99aabbcc)

    # Original image has [005e4fe8] = 005e3e18; the ctor accesses that
    # address +28 directly (no second pointer load). The fixture replaces
    # the cell with a controlled manager address; storage owner unresolved.
    put(0x005e4fe8, MANAGER)
    put(0x005e4fec, 0x006af374)
    put(0x006af374, 7)

    if case_id in (0, 1, 2):
        put(0x005e8e50, 0)
    elif case_id == 5:
        machine.mem_write(0x005e8e50, b'ctx\0')
    else:
        put(0x005e8e50, 0)


def original_case(case_id, binary, module):
    machine = Uc(UC_ARCH_X86, UC_MODE_32)
    machine.mem_map(IMAGE, IMAGE_SIZE)
    for section in module['sections']:
        if section['raw_size']:
            start = IMAGE + section['rva']
            machine.mem_write(start, binary[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    machine.mem_map(ARENA, ARENA_SIZE)
    machine.mem_map(STACK - 0x10000, 0x20000)
    machine.mem_map(EXIT, 0x1000)
    seed_arena(machine, case_id)

    traces = []
    alloc_results = {
        0: [0], 1: [CTOR_ALLOC], 2: [CTOR_ALLOC],
        3: [0], 4: [MEMBER_STORAGE],
        5: [CTOR_ALLOC, CONTEXT_MEMBER, MEMBER_STORAGE],
        6: [CTOR_ALLOC], 7: [CTOR_ALLOC], 8: [CTOR_ALLOC],
        9: [MEMBER_STORAGE], 10: [MEMBER_STORAGE], 11: [MEMBER_STORAGE],
        12: [], 13: [], 14: [], 15: [], 16: [MEMBER_STORAGE],
        17: [MEMBER_STORAGE], 18: [0], 19: [],
    }[case_id]
    alloc_sizes = {
        0: [0x0c], 1: [0x0c], 2: [0x0c],
        3: [0x28], 4: [0x28],
        5: [0x0c, 0x2c, 0x28],
        6: [0x0c], 7: [0x0c], 8: [0x0c],
        9: [0x28], 10: [0x28], 11: [0x28],
        12: [], 13: [], 14: [], 15: [], 16: [0x28],
        17: [0x28], 18: [0x0c], 19: [],
    }[case_id]
    alloc_index = 0
    block_calls = 0
    abi_checks = []

    def read32(address):
        return struct.unpack('<I', machine.mem_read(address, 4))[0]

    def write32(address, value):
        machine.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def record_call(name, args):
        traces.append(name + ':' + ':'.join(hex32(arg) for arg in args))

    def invoke(address, ecx, args=(), pop=0, limit=500000):
        machine.mem_write(STACK, struct.pack('<' + 'I' * (1 + len(args)), EXIT, *args))
        machine.reg_write(UC_X86_REG_ESP, STACK)
        machine.reg_write(UC_X86_REG_ECX, ecx)
        machine.reg_write(UC_X86_REG_EDX, 0x12345678)
        machine.reg_write(UC_X86_REG_EAX, 0xa5b6c7d8 if case_id == 18 else 0x13579bdf)
        saved = {UC_X86_REG_EBX: 0xb1b2b3b4, UC_X86_REG_EBP: 0xc1c2c3c4,
                 UC_X86_REG_ESI: 0xd1d2d3d4, UC_X86_REG_EDI: 0xe1e2e3e4}
        for reg, value in saved.items(): machine.reg_write(reg, value)
        try:
            machine.emu_start(address, EXIT + 1, count=limit)
        except Exception as exc:
            raise RuntimeError(f'x86 {address:08x} case {case_id} failed at {machine.reg_read(UC_X86_REG_EIP):08x}; trace={traces}') from exc
        assert machine.reg_read(UC_X86_REG_EIP) == EXIT, 'original did not return'
        assert machine.reg_read(UC_X86_REG_ESP) == STACK + 4 + pop, 'original stack imbalance'
        assert all(machine.reg_read(reg) == value for reg, value in saved.items()), 'original nonvolatile register changed'
        abi_checks.append({'va': hex32(address), 'stack_pop': pop, 'callee_saved_preserved': True})
        return machine.reg_read(UC_X86_REG_EAX)

    def hook(machine, address, size, _):
        nonlocal alloc_index, block_calls
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == EXIT:
            machine.emu_stop()
            return
        cdecl = {0x0059ef90, 0x0059f050, 0x0059eeb0, 0x005322b0,
                 0x005322c0, 0x004d7da0, 0x004237d0, 0x004211d0,
                 0x0059ecb0, 0x00529c20, 0x00441200}
        thiscall_pop4 = {0x005262e0, 0x004e4560}
        if address in cdecl or address in thiscall_pop4:
            ret = read32(esp)
            argcount = {0x0059ef90: 1, 0x0059f050: 1, 0x0059eeb0: 2,
                0x005322b0: 1, 0x005322c0: 1, 0x004d7da0: 2,
                0x004237d0: 3, 0x004211d0: 2, 0x0059ecb0: 3,
                0x00529c20: 9, 0x00441200: 2, 0x005262e0: 1,
                0x004e4560: 1}[address]
            args = [read32(esp + 4 + 4 * i) for i in range(argcount)]
            if address == 0x0059ef90:
                requested = args[0]
                result = alloc_results[alloc_index] if alloc_index < len(alloc_results) and alloc_sizes[alloc_index] == requested else 0
                if alloc_index >= len(alloc_results) or alloc_sizes[alloc_index] != requested:
                    raise AssertionError(f'unexpected allocation #{alloc_index} size {requested:#x}')
                alloc_index += 1
                record_call('alloc59ef90', [requested, result])
                machine.reg_write(UC_X86_REG_EAX, result)
            elif address == 0x0059f050:
                record_call('free59f050', [args[0], RETURN_VALUE])
                machine.reg_write(UC_X86_REG_EAX, RETURN_VALUE)
            elif address == 0x0059eeb0:
                record_call('newhead59eeb0', args)
                write32(MANAGER + 0x40, HEAD)
                write32(HEAD + 4, 0)
                if case_id == 6:
                    write32(MANAGER + 0x28, LOCK + 0x10)
                    write32(HEAD + 4, HEAD_NEXT)
                machine.reg_write(UC_X86_REG_EAX, HEAD)
            elif address in (0x005322b0, 0x005322c0):
                record_call('enter322b0' if address == 0x005322b0 else 'leave322c0', args)
            elif address == 0x004d7da0:
                record_call('notify4d7da0', args)
                if case_id == 7: write32(CTOR_ALLOC, HEAD_NEXT)
            elif address == 0x004237d0:
                record_call('clear4237d0', args)
            elif address == 0x004211d0:
                record_call('memberarray4211d0', [args[0], args[1], MEMBER_ARRAY])
                if case_id == 9: write32(MEMBER_STORAGE + 4, 6)
                machine.reg_write(UC_X86_REG_EAX, MEMBER_ARRAY)
            elif address == 0x0059ecb0:
                result = MEMBER_BLOCK + block_calls * 0x200 if case_id == 14 else (0 if case_id == 16 else MEMBER_BLOCK)
                record_call('memberblock59ecb0', args + [result])
                block_calls += 1
                if case_id == 14:
                    # Move the selector cell itself on each iteration too.
                    write32(0x005e4fec, HEAP_SELECTOR + block_calls * 4)
                    write32(HEAP_SELECTOR + block_calls * 4, 7 + block_calls)
                    write32(HEAP_SELECTOR, 7 + block_calls)
                machine.reg_write(UC_X86_REG_EAX, result)
            elif address == 0x00529c20:
                first = hex_bytes(bytes(machine.mem_read(esp + 4, 0x10)))
                second = hex_bytes(bytes(machine.mem_read(esp + 0x14, 0x10)))
                traces.append(f'compareranges29c20:{first}:{second}:{hex32(read32(esp + 0x24))}')
                if case_id == 10: write32(MEMBER_STORAGE, 0)
                if case_id == 11:
                    write32(MEMBER_STORAGE + 0x14, MEMBER_ARRAY + 8)
                    write32(MEMBER_STORAGE + 0x24, MEMBER_ARRAY + 12)
                if case_id == 17: write32(MEMBER_STORAGE + 4, 0)
            elif address == 0x00441200:
                record_call('destroyblock441200', args)
                if case_id == 11:
                    write32(MEMBER_STORAGE + 4, 3)
                    write32(MEMBER_STORAGE, MEMBER_ARRAY + 0x100)
                    write32(MEMBER_STORAGE + 0x24, 0)
                    write32(MEMBER_STORAGE + 0x14, 0)
            elif address == 0x005262e0:
                record_call('unlink262e0', [machine.reg_read(UC_X86_REG_ECX), args[0]])
                if case_id == 7 and args[0] == 0x55667788:
                    write32(LIST_NODE + 8, LIST_NODE + 0x100)
            elif address == 0x004e4560:
                record_call('releasenode4e4560', [machine.reg_read(UC_X86_REG_ECX), args[0]])
                if case_id == 7: write32(LIST_NODE + 8, 0)
            machine.reg_write(UC_X86_REG_ESP, esp + 4 + (4 if address in thiscall_pop4 else 0))
            machine.reg_write(UC_X86_REG_EIP, ret)

    machine.hook_add(UC_HOOK_CODE, hook)
    base_ctor_result = 0
    member_ctor_result = 0
    result = 0
    constructor_trace = []
    if case_id <= 2 or case_id in (6, 7, 8, 18):
        base_ctor_result = invoke(0x00525e20, CONTEXT)
        constructor_trace = list(traces)
        before = bytes(machine.mem_read(CONTEXT, 0x180))
        scratch_before = bytes(machine.mem_read(ARENA + 0x10000, 0x70000))
        if case_id in (2, 7, 8):
            write32(CTOR_ALLOC + 4, 1)
            write32(EXISTING_HEAD, 0x33333333)
            write32(EXISTING_HEAD + 4, 0 if case_id == 8 else LIST_NODE)
        result = invoke(0x00525ec0, CONTEXT)
        after = bytes(machine.mem_read(CONTEXT, 0x180))
    elif case_id <= 4 or case_id in (9, 10, 11, 16, 17):
        member_ctor_result = invoke(0x005294c0, MEMBER)
        before = bytes(machine.mem_read(MEMBER, 0x2c))
        scratch_before = bytes(machine.mem_read(ARENA + 0x10000, 0x70000))
        invoke(0x005295b0, MEMBER)
        after = bytes(machine.mem_read(MEMBER, 0x2c))
    elif case_id == 5:
        base_ctor_result = invoke(0x004d1a90, CONTEXT)
        before = bytes(machine.mem_read(CONTEXT, 0x180))
        scratch_before = bytes(machine.mem_read(ARENA + 0x10000, 0x70000))
        result = invoke(0x004d1ba0, CONTEXT)
        after = bytes(machine.mem_read(CONTEXT, 0x180))
    else:
        before = bytes(machine.mem_read(MEMBER_ARRAY, 0x20))
        scratch_before = bytes(machine.mem_read(ARENA + 0x10000, 0x70000))
        if case_id == 12:
            result = invoke(0x005299d0, MEMBER_ARRAY + 4, (MEMBER_ARRAY,), 4)
        elif case_id == 13:
            invoke(0x00529a20, MEMBER_ARRAY, (MEMBER_ARRAY + 4,), 4)
        else:
            end = MEMBER_ARRAY + 12 if case_id == 14 else (MEMBER_ARRAY - 4 if case_id == 15 else MEMBER_ARRAY)
            invoke(0x00529a40, 0, (MEMBER_ARRAY, end), 8)
        after = bytes(machine.mem_read(MEMBER_ARRAY, 0x20))

    scratch = bytes(machine.mem_read(ARENA + 0x10000, 0x70000))
    return {'before': hex_bytes(before), 'after': hex_bytes(after),
            'scratch_before': hex_bytes(scratch_before), 'scratch': hex_bytes(scratch), 'trace': traces,
            'constructor_trace': constructor_trace,
            'base_ctor_result': hex32(base_ctor_result),
            'member_ctor_result': hex32(member_ctor_result),
            'result': hex32(result), 'abi_checks': abi_checks}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/application-context-base-135/bin/Release/application_context_base_probe.exe')
    parser.add_argument('--report-dir', type=Path, default=RUN)
    args = parser.parse_args()
    binaries = [json.loads(line) for line in (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf-8').splitlines()]
    module = next(item for item in binaries if item['file'] == 'Porsche.exe')
    binary = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(binary).hexdigest() != SHA:
        raise RuntimeError('original executable SHA-256 mismatch')

    def original_bytes(start, size):
        section = next(item for item in module['sections'] if IMAGE + item['rva'] <= start < IMAGE + item['rva'] + item['raw_size'])
        offset = section['raw_offset'] + start - IMAGE - section['rva']
        return binary[offset:offset + size]

    global_pins = []
    for address in (0x005e4fe8, 0x005e4fec):
        raw = original_bytes(address, 4)
        global_pins.append({'va': hex32(address), 'bytes_hex': raw.hex(),
                            'pointer_value': hex32(struct.unpack('<I', raw)[0]),
                            'sha256': hashlib.sha256(raw).hexdigest()})
    assert global_pins[0]['pointer_value'] == '005e3e18'
    assert global_pins[1]['pointer_value'] == '006af374'

    probe_bytes = args.probe.read_bytes()
    pe_offset = struct.unpack_from('<I', probe_bytes, 0x3c)[0]
    assert probe_bytes[pe_offset:pe_offset + 4] == b'PE\0\0'
    assert struct.unpack_from('<H', probe_bytes, pe_offset + 4)[0] == 0x14c
    assert struct.unpack_from('<H', probe_bytes, pe_offset + 24)[0] == 0x10b
    build_dir = args.probe.resolve().parents[2]
    cache = (build_dir / 'CMakeCache.txt').read_text(encoding='utf-8')
    assert re.search(r'^CMAKE_GENERATOR_PLATFORM:INTERNAL=Win32$', cache, re.M)
    compiler_file = next((build_dir / 'CMakeFiles').glob('*/CMakeCXXCompiler.cmake'))
    compiler = compiler_file.read_text(encoding='utf-8')
    def compiler_value(name):
        return re.search(r'set\(' + name + r' "?([^"\)]+)"?\)', compiler)[1]
    assert compiler_value('CMAKE_CXX_COMPILER_ID') == 'MSVC'
    assert compiler_value('CMAKE_CXX_SIZEOF_DATA_PTR') == '4'
    toolchain = {'compiler_id': 'MSVC', 'compiler_version': compiler_value('CMAKE_CXX_COMPILER_VERSION'),
                 'compiler': compiler_value('CMAKE_CXX_COMPILER'), 'pointer_size': 4,
                 'generator_platform': 'Win32', 'native_pe_machine': '014c', 'native_pe_magic': '010b'}

    native = []
    for case_id in CASES:
        line = subprocess.run([str(args.probe), str(case_id)], capture_output=True,
            text=True, check=True, timeout=30).stdout.strip()
        native.append(json.loads(line))

    fixture_hashes = []
    abi_checks = []
    null_eax = []
    full_fixtures = []
    for case_id, actual in zip(CASES, native):
        expected = original_case(case_id, binary, module)
        for key in ('before', 'after', 'scratch_before', 'scratch', 'trace', 'constructor_trace',
                    'base_ctor_result', 'member_ctor_result'):
            if actual[key] != expected[key]:
                if key in ('before', 'after', 'scratch_before', 'scratch'):
                    left, right = bytes.fromhex(actual[key]), bytes.fromhex(expected[key])
                    mismatch = next((i for i, pair in enumerate(zip(left, right)) if pair[0] != pair[1]), min(len(left), len(right)))
                    raise AssertionError(f'case {case_id} {key} mismatch at +{mismatch:#x}')
                raise AssertionError(f'case {case_id} {key} mismatch: {actual[key]} != {expected[key]}')
        # 00525ec0 preserves incoming EAX when its +4 cell is null. Typed
        # C++ currently normalizes that unproved source-level return to zero.
        if case_id in (0, 18):
            assert expected['result'] == ('a5b6c7d8' if case_id == 18 else '13579bdf')
            null_eax.append({'case': case_id, 'original_preserved_eax': expected['result'],
                             'cpp_normalized_eax': actual['result'], 'parity_claimed': False})
        if case_id in (1, 2, 5, 6, 7, 8, 12) and actual['result'] != expected['result']:
            raise AssertionError(f'case {case_id} destructor result mismatch')
        fixture_hashes.append(hashlib.sha256(json.dumps(expected, sort_keys=True).encode()).hexdigest())
        abi_checks.append({'case': case_id, 'calls': expected['abi_checks']})
        if case_id in FULL_CONSTRUCTOR_CASES:
            keys = ('before', 'scratch_before', 'base_ctor_result', 'constructor_trace')
            scoped = {key: expected[key] for key in keys}
            scoped['abi_checks'] = expected['abi_checks'][:1]
            phase = 'base-constructor-only-before-partial-destructor'
        elif case_id in FULL_MEMBER_CASES + FULL_HELPER_CASES:
            keys = ('before', 'after', 'scratch_before', 'scratch', 'trace',
                    'member_ctor_result', 'result')
            scoped = {key: expected[key] for key in keys}
            scoped['abi_checks'] = expected['abi_checks']
            phase = 'member-ctor-dtor' if case_id in FULL_MEMBER_CASES else 'direct-helper'
        else:
            scoped = None
        if scoped is not None:
            assert all(actual[key] == expected[key] for key in keys)
            full_fixtures.append({'case': case_id, 'name': CASE_NAMES[case_id],
                'phase': phase, 'compared_fields': list(keys),
                'sha256': hashlib.sha256(json.dumps(scoped, sort_keys=True).encode()).hexdigest(),
                'original_abi_checks': scoped['abi_checks']})

    full = ['00525e20', '005294c0', '005295b0', '00529a20', '00529a40', '005299d0']
    partial = ['00525ec0']
    functions = [json.loads(line) for line in (ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf-8').splitlines()]
    pins = []
    for va in full + partial + ['005299f0', '004d1a90', '004d1ba0', '00529c20']:
        function = next(item for item in functions if item['entry_va'] == va)
        spans = []
        for first, last in function['ranges']:
            start, end = int(first, 16), int(last, 16) + 1
            raw = original_bytes(start, end - start)
            spans.append({'start_va': first, 'end_va_inclusive': last, 'bytes': len(raw), 'sha256': hashlib.sha256(raw).hexdigest()})
        pins.append({'entry_va': va, 'ranges': spans})
    compiled = [
        'iterations/v2/001-original-recovery/source/recovered/application_context_base_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_context_base.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_context_base_destroy_partial.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_context.cpp',
    ]
    paths = compiled + [
        'iterations/v2/001-original-recovery/source/include/porsche/application_context_base.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/application_context.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/application_alloc.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/application_heap_init.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/runs/135-application-context-base/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/135-application-context-base/README.md',
        'scripts/research/verify-v2-application-context-base.py',
        'research/binary-index/static/binaries.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/references.jsonl',
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
    ]
    hashes = source_hashes(paths, compiled_sources=compiled)
    args.report_dir.mkdir(parents=True, exist_ok=True)
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'function_vas': full + partial,
        'full_function_vas': full, 'partial_function_vas': partial,
        'original_body_pins': pins,
        'original_global_pins': global_pins, 'native_toolchain': toolchain,
        'cases': len(CASES), 'native_cpp_equal_original_x86': False,
        'verified_contract_equal_original_x86': True,
        'comparison': 'Full object spans and 0x70000 poisoned arena bytes before/after, constructor/copy EAX, non-null destructor EAX, 36-byte by-value compare payload and ordered typed-boundary effects; mutation, overlap, empty/reversed range and composed context cases.',
        'partial_reason': '00525ec0 null-allocation path preserves arbitrary incoming EAX; C++ return is normalized to zero and source-level return contract is unproved.',
        'partial_isolation': 'application_context_base_destroy_partial.cpp is compiled only by private Run135; common library must leave 00525ec0 unresolved.',
        'null_allocation_eax': null_eax, 'original_abi_checks': abi_checks,
        'unknown_boundaries': ['005e4fe8 pointer cell (initially 005e3e18; ctor directly accesses +28/+40; storage owner unresolved)', '005e4fec selector pointer cell (initially 006af374)', '0059ef90', '0059f050', '0059eeb0', '005262e0', '004e4560', '004d7da0', '004237d0', '004211d0', '0059ecb0', '00529c20', '00441200'],
        'source_sha256': hashes,
        'probe_sha256': hashlib.sha256(probe_bytes).hexdigest(),
        'fixtures': [{'case': i, 'name': CASE_NAMES[i], 'sha256': value} for i, value in zip(CASES, fixture_hashes)],
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8', newline='\n')
    full_report = dict(report)
    full_report.update({
        'function_vas': full, 'full_function_vas': full, 'partial_function_vas': [],
        'cases': len(full_fixtures), 'native_cpp_equal_original_x86': True,
        'comparison': 'Scoped full-body proof only: four base-constructor phases captured before partial destruction, seven full member ctor/dtor cases, five direct-helper cases. All recorded memory, returns, traces and original ABI checks match.',
        'scope': '525ec0 is excluded. The private probe links its partial file only for separate packet evidence. No partial destructor memory, trace, or EAX outcome enters this full proof.',
        'packet_report': 'verification.json',
        'fixtures': full_fixtures,
        'original_abi_checks': [{'case': item['case'], 'calls': item['original_abi_checks']} for item in full_fixtures],
        'original_body_pins': [item for item in pins if item['entry_va'] in full + ['005299f0', '00529c20']],
    })
    for key in ('partial_reason', 'partial_isolation', 'null_allocation_eax'):
        full_report.pop(key, None)
    (args.report_dir / 'full-verification.json').write_text(json.dumps(full_report, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({'full_functions': full, 'partial_functions': partial, 'cases': len(CASES),
        'verified_contract_equal_original_x86': True,
        'full_proof_cases': len(full_fixtures),
        'report': str(args.report_dir / 'verification.json')}))


if __name__ == '__main__':
    main()
