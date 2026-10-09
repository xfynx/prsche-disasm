"""Run082: compare callback scheduling and removal to original x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/082-window-scheduler'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, EXIT = 0x3108000, 0x3200000
DIAGNOSTIC = 0x3210030
SLOTS, DEPTH, TICK = 0x69DD20, 0x69DE20, 0x6B7C40
ERROR_FILE, ERROR_LINE, ERROR_CALL = 0x5DEB74, 0x5DEB78, 0x5DEBF0
ERROR_MESSAGE = 0x5BB6EC


def put(u, address, value):
    u.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(u, address):
    return struct.unpack('<I', u.mem_read(address, 4))[0]


def make_case(operation, depth, tick, callback, period=0, delay=0, slots=None):
    return {'operation': operation, 'depth': depth, 'tick': tick,
            'callback': callback, 'period': period, 'delay': delay,
            'slots': slots or [[0, 0, 0, 0] for _ in range(16)]}


def cases():
    result = [
        make_case(0, 0, 100, 0x400123, 5, 10),
        make_case(0, 0, 0xfffffffa, 0x400456, 0xffffffff, 10),
        make_case(0, 2, 77, 0x400789, 3, 4),
        make_case(0, 0xffffffff, 99, 0x400abc, 1, 2),
    ]
    slots = [[0, 0, 0, 0] for _ in range(16)]
    slots[1], slots[7], slots[12] = [0x400111, 11, 22, 1], [0x400222, 33, 44, 0], [0x400111, 55, 66, 1]
    result.append(make_case(0, 3, 0xfffffff8, 0x400111, 7, 16, slots))
    slots = [[0, 0, 0, 0] for _ in range(16)]
    slots[0], slots[2], slots[4], slots[8] = [0x400100, 1, 11, 1], [0x400200, 2, 22, 1], [0x400300, 3, 33, 1], [0x400400, 4, 44, 1]
    result.append(make_case(0, 2, 5, 0x400555, 9, 20, slots))
    slots = [[0x400000 + i * 4, i + 1, i + 2, i % 2] for i in range(16)]
    result.append(make_case(0, 0, 10, 0x400999, 6, 8, slots))
    slots[13] = [0, 0xaa, 0xbb, 0xcc]
    result.append(make_case(0, 1, 10, 0x400999, 6, 8, slots))
    for index in (0, 7, 15):
        slots = [[0x500000 + i * 4, 100 + i, 200 + i, i + 1] for i in range(16)]
        slots[index] = [0x400777, 55, 66, 77]
        result.append(make_case(1, 9, 123, 0x400777, slots=slots))
    slots = [[0x500000 + i * 4, i + 1, i + 2, i + 3] for i in range(16)]
    result.append(make_case(1, 0, 123, 0x400777, slots=slots))
    slots = [[0, 10 + i, 20 + i, 30 + i] for i in range(16)]
    slots[6] = [0x500600, 61, 62, 63]
    result.append(make_case(1, 0, 123, 0, slots=slots))
    # Empty-depth allocation selects the first free slot; later exact matches
    # replace that tentative selection, so the last duplicate wins.
    slots = [[0x510000 + i * 4, i, i, i] for i in range(16)]
    slots[3] = [0, 31, 32, 33]
    slots[14] = [0x400ddd, 44, 45, 46]
    result.append(make_case(0, 0, 17, 0x400ddd, 4, 5, slots))
    for depth in range(18):
        result.append(make_case(0, depth, (0xfffffff0 + depth) & 0xffffffff,
                                0x410000 + depth * 4, depth + 1, 0x20 + depth))
    for index in range(16):
        slots = [[0x420000 + i * 4, 100 + i, 200 + i, i + 1] for i in range(16)]
        slots[index] = [0, 300 + index, 400 + index, 500 + index]
        result.append(make_case(0, index % 3, 0xabcdef00 + index,
                                0x430000 + index * 4, index, 0xffffffff - index, slots))
    for index in range(16):
        slots = [[0x440000 + i * 4, 1 + i, 17 + i, 33 + i] for i in range(16)]
        slots[index] = [0x450000 + index * 4, 1000 + index, 2000 + index, 3000 + index]
        result.append(make_case(1, index, 0x12345678,
                                0x450000 + index * 4, slots=slots))
    return result


def original(module, image, case):
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0x400000, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            u.mem_write(0x400000 + section['rva'],
                        image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    u.mem_map(0x3100000, 0x10000)
    u.mem_map(EXIT, 0x1000)
    u.mem_map(0x3210000, 0x1000)
    u.mem_write(EXIT, b'\xc3' * 0x1000)
    put(u, DEPTH, case['depth'])
    put(u, TICK, case['tick'])
    put(u, ERROR_FILE, 0x11111111)
    put(u, ERROR_LINE, 0x22222222)
    put(u, ERROR_CALL, DIAGNOSTIC)
    for index, slot in enumerate(case['slots']):
        for field, value in enumerate(slot):
            put(u, SLOTS + index * 16 + field * 4, value)
    trace = {'diagnostics': []}

    def hook(m, address, _size, _):
        if address != DIAGNOSTIC:
            return
        sp = m.reg_read(UC_X86_REG_ESP)
        trace['diagnostics'].append(word(m, sp + 4))
        m.reg_write(UC_X86_REG_EAX, 0)
        m.reg_write(UC_X86_REG_ESP, sp + 4)  # cdecl external call; caller removes arg
        m.reg_write(UC_X86_REG_EIP, word(m, sp))

    u.hook_add(UC_HOOK_CODE, hook)
    args = [EXIT, case['callback'], case['period'], case['delay']]
    if case['operation'] == 1:
        args = [EXIT, case['callback']]
    for index, value in enumerate(args):
        put(u, STACK + index * 4, value)
    u.reg_write(UC_X86_REG_ESP, STACK)
    entry = 0x5365e0 if case['operation'] == 0 else 0x5366a0
    u.emu_start(entry, EXIT, count=50000)
    slots = [[word(u, SLOTS + i * 16 + j * 4) for j in range(4)] for i in range(16)]
    return {'result': u.reg_read(UC_X86_REG_EAX), 'depth': word(u, DEPTH),
            'tick': word(u, TICK), 'error_file': word(u, ERROR_FILE),
            'error_line': word(u, ERROR_LINE), 'diagnostics': trace['diagnostics'],
            'slots': slots}


def native_input(case):
    fields = [case['operation'], case['depth'], case['tick'], case['callback'],
              case['period'], case['delay']]
    fields.extend(value for slot in case['slots'] for value in slot)
    return ' '.join(str(value) for value in fields) + '\n'


def parse_native(line):
    words = [int(value, 0) for value in line.split()]
    if len(words) != 7 + 16 * 4:
        raise RuntimeError(f'malformed native trace ({len(words)} words)')
    slots = [words[7 + i * 4:11 + i * 4] for i in range(16)]
    return {'result': words[0], 'depth': words[1], 'tick': words[2],
            'error_file': words[3], 'error_line': words[4],
            'diagnostics': [words[6]] * words[5], 'slots': slots}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path,
        default=ROOT / 'local/builds/v2/001-original-recovery/window-scheduler-082/bin/Release/window_scheduler_probe.exe')
    parser.add_argument('--report', type=Path, default=RUN / 'verification.json')
    args = parser.parse_args()
    module = next(json.loads(line) for line in
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()
        if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')
    inputs = cases()
    run = subprocess.run([str(args.probe)], input=''.join(map(native_input, inputs)),
        text=True, capture_output=True, check=True)
    lines = run.stdout.splitlines()
    if len(lines) != len(inputs):
        raise RuntimeError(f'probe returned {len(lines)} lines for {len(inputs)} cases')
    outputs = []
    for case, line in zip(inputs, lines):
        expected = original(module, image, case)
        actual = parse_native(line)
        if actual != expected:
            raise RuntimeError(f'{case}: original={expected}, native={actual}')
        outputs.append({'input': case, 'output': actual})
    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/window_scheduler.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_scheduler.cpp',
        'iterations/v2/001-original-recovery/source/recovered/window_scheduler_probe.cpp',
        'iterations/v2/001-original-recovery/runs/082-window-scheduler/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/082-window-scheduler/README.md',
        'scripts/research/verify-v2-window-scheduler.py',
    ]
    report = {
        'schema': 1, 'sha256': SHA,
        'function_vas': ['005365e0', '005366a0'],
        'full_function_vas': ['005365e0', '005366a0'],
        'partial_function_vas': [], 'cases': len(inputs),
        'native_cpp_equal_original_x86': True,
        'binary_matched': False, 'game_launch_verified': False,
        'boundaries': 'The address stored at 005debf0 is intercepted only on the full-table registration-error path; the fixture records the original message pointer and models the observed cdecl return. Shared timed slots at 0069dd20 are fixture storage with the existing TimedCallbackSlot layout.',
        'source_sha256': source_hashes(dependencies, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_scheduler.cpp',
            'iterations/v2/001-original-recovery/source/recovered/window_scheduler_probe.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': outputs,
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'full_function_vas': report['full_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
