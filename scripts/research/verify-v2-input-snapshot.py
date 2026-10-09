"""Compare original 0055feb0 selector paths with the recovered input snapshot provider."""
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
START, EXIT = 0x55feb0, 0x2201000
STACK = 0x220f000
STORAGE, DEVICE, VTABLE = 0x6a57f0, 0x3100000, 0x3101000
POLL_FN, ACQUIRE_FN, GET_STATE_FN, GET_CAPS_FN = 0x3300000, 0x3300010, 0x3300020, 0x3300030
LOST = (0x8007000c, 0x8007001e)
DIAGNOSTIC_FILE = 0x5bccac
STORAGE_SIZE = 0x324


def u32(n):
    return n & 0xffffffff


def cstring(uc, address, limit=256):
    if not address:
        return ''
    out = bytearray()
    for i in range(limit):
        ch = uc.mem_read(address + i, 1)[0]
        if ch == 0:
            break
        out.append(ch)
    return out.decode('latin1')


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    sec = next(section for section in module['sections']
               if section['rva'] <= rva < section['rva'] + section['raw_size'])
    offset = sec['raw_offset'] + rva - sec['rva']
    return image[offset:offset + size]


def cases():
    fail = 0x80004005
    lost1, lost2 = LOST
    return [
        # selector 6: absent DirectInput, success, ordinary failure/clear, and reacquire/retry cases.
        {'mode': 6, 'present': 0, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x11},
        {'mode': 6, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x23},
        {'mode': 6, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': fail, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x35},
        {'mode': 6, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': lost1, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x47},
        {'mode': 6, 'present': 1, 'poll': lost1, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x59},
        {'mode': 6, 'present': 1, 'poll': lost2, 'poll_retry': fail, 'acquire': fail,
         'get': 0, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0x6b},
        {'mode': 6, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': fail,
         'get': lost2, 'get_retry': fail, 'caps': fail, 'caps_boundary': 0, 'seed': 0x7d},
        # selector 2: DirectInput gate, GetCapabilities failure, and explicit success-algorithm boundary.
        {'mode': 2, 'present': 0, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': 0, 'caps_boundary': 0, 'seed': 0x8f},
        {'mode': 2, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': fail, 'caps_boundary': 0, 'seed': 0xa1},
        {'mode': 2, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': 0, 'caps_boundary': 0, 'seed': 0xb3},
        {'mode': 2, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': 0, 'caps_boundary': fail, 'seed': 0xc5},
        # Unknown selectors exercise the original variadic diagnostic boundary.
        {'mode': -1, 'present': 1, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': 0, 'caps_boundary': 0, 'seed': 0xd7},
        {'mode': 3, 'present': 0, 'poll': 0, 'poll_retry': 0, 'acquire': 0,
         'get': 0, 'get_retry': 0, 'caps': 0, 'caps_boundary': 0, 'seed': 0xe9},
    ]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_EBP,
                                   UC_X86_REG_EIP, UC_X86_REG_ESI, UC_X86_REG_EDI,
                                   UC_X86_REG_ESP)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'], image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    for address, size in ((0x2200000, 0x10000), (0x3100000, 0x2000), (0x3300000, 0x1000)):
        uc.mem_map(address, size)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', u32(value)))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    storage = bytes([0xa5]) * STORAGE_SIZE
    uc.mem_write(STORAGE, storage)
    put(0x6a5b14, 0x1234 if case['present'] else 0)
    put(0x6a5b18, DEVICE)
    uc.mem_write(DEVICE, struct.pack('<I', VTABLE))
    for offset, target in ((0x1c, ACQUIRE_FN), (0x24, GET_STATE_FN),
                           (0x3c, GET_CAPS_FN), (0x64, POLL_FN)):
        put(VTABLE + offset, target)
    put(0x5deb74, 0)
    put(0x5deb78, 0x777)
    diag_target = word(0x5debf0)
    put(STACK, EXIT)
    put(STACK + 4, case['mode'])
    uc.reg_write(UC_X86_REG_ESP, STACK)

    calls = []
    caps_frame = None
    poll_count = 0
    get_count = 0

    def emulate_return(machine, sp, result, cleanup):
        ret = word(sp)
        machine.reg_write(UC_X86_REG_EAX, u32(result))
        machine.reg_write(UC_X86_REG_ESP, sp + 4 + cleanup)
        machine.reg_write(UC_X86_REG_EIP, ret)

    def hook(machine, address, _size, _user):
        nonlocal caps_frame, poll_count, get_count
        if address == EXIT:
            machine.emu_stop()
            return
        if address == 0x53c290:
            sp = machine.reg_read(UC_X86_REG_ESP)
            destination, value, size = word(sp + 4), word(sp + 8), word(sp + 12)
            calls.append(f'fill:{destination - STORAGE}:{value}:{size}')
            pattern = struct.pack('<I', value)
            machine.mem_write(destination, (pattern * ((size + 3) // 4))[:size])
            emulate_return(machine, sp, 0, 0)
            return
        if address == POLL_FN:
            sp = machine.reg_read(UC_X86_REG_ESP)
            result = case['poll'] if poll_count == 0 else case['poll_retry']
            poll_count += 1
            calls.append(f'poll:{result}')
            emulate_return(machine, sp, result, 4)
            return
        if address == ACQUIRE_FN:
            sp = machine.reg_read(UC_X86_REG_ESP)
            calls.append('acquire')
            emulate_return(machine, sp, case['acquire'], 4)
            return
        if address == GET_STATE_FN:
            sp = machine.reg_read(UC_X86_REG_ESP)
            size, destination = word(sp + 8), word(sp + 12)
            result = case['get'] if get_count == 0 else case['get_retry']
            get_count += 1
            calls.append(f'getstate:{size}:{destination - STORAGE}:{result}')
            uc.mem_write(destination, bytes((case['seed'] + i * 3) & 0xff for i in range(size)))
            emulate_return(machine, sp, result, 12)
            return
        if address == GET_CAPS_FN:
            sp = machine.reg_read(UC_X86_REG_ESP)
            calls.append(f'getcaps:{case["caps"]}')
            emulate_return(machine, sp, case['caps'], 8)
            return
        if address == 0x56fdb0:
            sp = machine.reg_read(UC_X86_REG_ESP)
            caps_frame = {
                'sp': sp, 'ret': word(sp),
                'regs': {r: machine.reg_read(r) for r in
                         (UC_X86_REG_EBX, UC_X86_REG_EBP, UC_X86_REG_ESI, UC_X86_REG_EDI)},
            }
        if address == 0x56fdf9:
            if not caps_frame:
                raise RuntimeError('caps success boundary reached without entry frame')
            calls.append('caps-success-boundary')
            for reg, value in caps_frame['regs'].items():
                machine.reg_write(reg, value)
            machine.reg_write(UC_X86_REG_EAX, case['caps_boundary'])
            machine.reg_write(UC_X86_REG_ESP, caps_frame['sp'] + 4)
            machine.reg_write(UC_X86_REG_EIP, caps_frame['ret'])
            return
        if address == diag_target:
            sp = machine.reg_read(UC_X86_REG_ESP)
            fmt, selector = word(sp + 4), struct.unpack('<i', struct.pack('<I', word(sp + 8)))[0]
            calls.append(f'diagnostic:{cstring(machine, fmt)}:{selector}')
            emulate_return(machine, sp, 0, 0)
            return
        if (START <= address <= 0x55ff53 or 0x56fce0 <= address <= 0x56fcff or
                0x56fd00 <= address <= 0x56fd2a or 0x56fd30 <= address <= 0x56fd6a or
                0x56fdb0 <= address <= 0x56ff8c):
            return
        raise RuntimeError(f'unexpected original address {address:08x}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(START, EXIT + 1, count=10000)
    except Exception as error:
        raise RuntimeError(f'original emulation failed for {case}, eip={uc.reg_read(UC_X86_REG_EIP):08x}, calls={calls}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'original did not return for {case}; eip={uc.reg_read(UC_X86_REG_EIP):08x}')
    raw_return = uc.reg_read(UC_X86_REG_EAX)
    ret_offset = raw_return - STORAGE if STORAGE <= raw_return < STORAGE + STORAGE_SIZE else (-1 if raw_return == 0 else None)
    if ret_offset is None:
        raise AssertionError(f'unexpected original return pointer {raw_return:08x} for {case}')
    snapshot = bytes(uc.mem_read(STORAGE, STORAGE_SIZE)).hex()
    file_pointer = word(0x5deb74)
    return {
        'return_offset': ret_offset, 'snapshot': snapshot,
        'diag_line': word(0x5deb78), 'diag_file': cstring(uc, file_pointer),
        'calls': calls,
    }


def case_line(c):
    return ' '.join(str(c[key]) for key in (
        'mode', 'present', 'poll', 'poll_retry', 'acquire', 'get', 'get_retry',
        'caps', 'caps_boundary', 'seed'))


def compare_calls(case, original_calls, native_calls):
    # The already-recovered input_caps owner clears its 0x21c output with the
    # equivalent typed byte-fill; only that internal boundary call is omitted
    # from the native callback log. The resulting full bytes are still compared.
    filtered = []
    for call in original_calls:
        if case['mode'] == 2 and call.startswith('fill:0:0:540'):
            continue
        filtered.append(call)
    if filtered != native_calls:
        raise AssertionError(f'ordered calls differ for {case}: original={filtered}, native={native_calls}')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/input_snapshot_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    inputs = cases()
    run = subprocess.run([str(args.probe)], input=''.join(case_line(c) + '\n' for c in inputs),
                         text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(inputs):
        raise AssertionError(f'native returned {len(actuals)} rows for {len(inputs)} cases')
    for i, (case, actual) in enumerate(zip(inputs, actuals)):
        expected = original(module, image, case)
        if actual != expected:
            if (actual.get('return_offset') == expected.get('return_offset') and
                    actual.get('snapshot') == expected.get('snapshot') and
                    actual.get('diag_line') == expected.get('diag_line') and
                    actual.get('diag_file') == expected.get('diag_file')):
                compare_calls(case, expected['calls'], actual['calls'])
            else:
                raise AssertionError(f'case {i} {case}: original={expected} native={actual}')

    source_paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/input_snapshot.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_snapshot.cpp',
        'iterations/v2/001-original-recovery/source/recovered/input_snapshot_probe.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/input_state.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_state.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/input_buffer.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/input_buffer.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/startup_input.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/shared_runtime_globals.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp',
        'iterations/v2/001-original-recovery/runs/096-input-snapshot/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/096-input-snapshot/README.md',
        'scripts/research/verify-v2-input-snapshot.py',
    ]
    result = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA, 'module_sha256': SHA,
        'function_vas': ['0055feb0'], 'full_function_vas': ['0055feb0'], 'partial_function_vas': [],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'original_function': {'va': '0055feb0', 'body_bytes': 164,
                              'body_sha256': hashlib.sha256(read_va(image, module, START, 164)).hexdigest()},
        'bounded_paths': ['selector 2 capabilities wrapper; its 0056fdf9 success parser remains an explicit provider boundary',
                          'selector 6 state acquisition, lost-device retry, error zero-fill, and 006a5a10 prefix return',
                          'invalid selector diagnostic format/source/line through variadic callback boundary'],
        'state_storage': {'base': '006a57f0', 'size': '0x324', 'keyboard_return': '006a5a10',
                          'keyboard_bytes': '006a5a14', 'startup_pointers': ['006a5b14','006a5b18']},
        'source_sha256': source_hashes([ROOT / p for p in source_paths]),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({'cases': len(inputs), 'function_vas': result['function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
