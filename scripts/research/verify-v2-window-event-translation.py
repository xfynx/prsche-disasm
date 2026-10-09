"""Run091: compare the recovered 00560080 input translator with original x86."""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/091-window-event-translation'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, EXIT = 0x3108000, 0x3200000
SNAPSHOT = 0x3300000
WINDOW_FLAG, WINDOW_STATE = 0x5de020, 0x5de024
TABLES = (0x5de128, 0x5de1de, 0x5de183, 0x5de239, 0x5de294)
PROVIDER, TERMINAL_EXIT = 0x55feb0, 0x5a246e


def put(u, address, value):
    u.mem_write(address, (value & 0xffffffff).to_bytes(4, 'little'))


def word(u, address):
    return int.from_bytes(u.mem_read(address, 4), 'little')


def read_va(image, module, va, size):
    rva = va - 0x400000
    section = next(section for section in module['sections']
                   if section['rva'] <= rva < section['rva'] + section['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def cases():
    out = []
    # Each group selects one of the five immutable original tables. Exercise
    # every in-range index except 0x3a, whose earlier branch toggles state.
    for table_index in range(5):
        for payload in range(0x5b):
            if payload == 0x3a:
                continue
            state = bytearray(0xbd)
            window_state = 0
            if table_index == 1:
                window_state = 1
            elif table_index == 2:
                state[0x2e] = 1
            elif table_index == 3:
                state[0x21] = 1
            elif table_index == 4:
                state[0x3c] = 1
            out.append({
                'payload': payload, 'type': (0x10203040 + table_index * 0x100 + payload) & 0xffffffff,
                'window_state': window_state, 'guard': 0,
                'snapshot': bytes(state),
            })

    # Branch precedence, alternate fields, OR tests, and toggle behavior.
    for field in (0x3c, 0xbc, 0x21, 0xa1, 0x2e, 0x3a):
        state = bytearray(0xbd)
        state[field] = 1
        out.append({'payload': 7, 'type': field * 0x101, 'window_state': 1,
                    'guard': 0, 'snapshot': bytes(state)})
    state = bytearray(0xbd)
    state[0x3c] = state[0x21] = state[0x2e] = 1
    out.append({'payload': 1, 'type': 0xffffffff, 'window_state': 0,
                'guard': 1, 'snapshot': bytes(state)})  # group 4 suppresses exit
    state = bytearray(0xbd)
    state[0x21] = 1
    out.append({'payload': 1, 'type': 0, 'window_state': 0,
                'guard': 1, 'snapshot': bytes(state)})  # terminal exit
    out.append({'payload': 1, 'type': 1, 'window_state': 0,
                'guard': 0, 'snapshot': bytes(state)})  # no exit
    out.append({'payload': 2, 'type': 1, 'window_state': 0,
                'guard': 1, 'snapshot': bytes(state)})  # payload guard
    for old in (0, 1, 0x12345678):
        out.append({'payload': 0x3a, 'type': 0xfedcba98, 'window_state': old,
                    'guard': 1, 'snapshot': bytes([0xff]) * 0xbd})
    # The second queue argument is unused; same payload maps the same way.
    zero = bytes(0xbd)
    out.extend([
        {'payload': 0x10, 'type': 0, 'window_state': 0, 'guard': 0, 'snapshot': zero},
        {'payload': 0x10, 'type': 0xffffffff, 'window_state': 0, 'guard': 0, 'snapshot': zero},
    ])
    return out


def original(module, image, case):
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0x400000, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            u.mem_write(0x400000 + section['rva'],
                        image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    u.mem_map(0x3100000, 0x10000)
    u.mem_map(EXIT, 0x1000)
    u.mem_map(SNAPSHOT, 0x1000)
    u.mem_write(EXIT, b'\xc3' * 0x1000)
    u.mem_write(SNAPSHOT, case['snapshot'])
    put(u, WINDOW_FLAG, case['guard'])
    put(u, WINDOW_STATE, case['window_state'])
    trace = {'provider': [], 'exit': []}

    def hook(m, address, _size, _):
        if address == PROVIDER:
            sp = m.reg_read(UC_X86_REG_ESP)
            trace['provider'].append(word(m, sp + 4))
            m.reg_write(UC_X86_REG_EAX, SNAPSHOT)
            m.reg_write(UC_X86_REG_ESP, sp + 4)  # cdecl provider; caller removes selector
            m.reg_write(UC_X86_REG_EIP, word(m, sp))
        elif address == TERMINAL_EXIT:
            sp = m.reg_read(UC_X86_REG_ESP)
            trace['exit'].append(word(m, sp + 4))
            m.emu_stop()

    u.hook_add(UC_HOOK_CODE, hook)
    put(u, STACK, EXIT)
    put(u, STACK + 4, case['payload'])
    put(u, STACK + 8, case['type'])
    u.reg_write(UC_X86_REG_ESP, STACK)
    try:
        u.emu_start(0x560080, EXIT, count=10000)
    except Exception as exc:
        raise RuntimeError(f'original x86 fault at EIP={u.reg_read(UC_X86_REG_EIP):08x}, EAX={u.reg_read(UC_X86_REG_EAX):08x}, ECX={u.reg_read(UC_X86_REG_ECX):08x}; provider={trace["provider"]}; exit={trace["exit"]}') from exc
    exited = bool(trace['exit'])
    return {
        'exited': exited, 'result': u.reg_read(UC_X86_REG_EAX),
        'provider_calls': len(trace['provider']),
        'provider_selector': trace['provider'][0] if trace['provider'] else 0xffffffff,
        'window_state': word(u, WINDOW_STATE), 'guard': word(u, WINDOW_FLAG),
        'exit_calls': len(trace['exit']),
        'exit_code': trace['exit'][0] if trace['exit'] else 0xffffffff,
    }


def native_line(case):
    return ' '.join((str(case['payload']), str(case['type']),
                     str(case['window_state']), str(case['guard']),
                     case['snapshot'].hex())) + '\n'


def parse_native(line):
    values = [int(value, 0) for value in line.split()]
    if len(values) != 8:
        raise RuntimeError(f'malformed native result: {line!r}')
    return {'exited': bool(values[0]), 'result': values[1],
            'provider_calls': values[2], 'provider_selector': values[3],
            'window_state': values[4], 'guard': values[5],
            'exit_calls': values[6], 'exit_code': values[7]}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path,
        default=ROOT / 'local/builds/v2/001-original-recovery/window-event-translation-091/bin/Release/window_event_translation_probe.exe')
    parser.add_argument('--report-dir', type=Path, default=RUN)
    args = parser.parse_args()

    module = next(json.loads(line) for line in
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()
        if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')

    inputs = cases()
    expected = [original(module, image, case) for case in inputs]
    proc = subprocess.run([str(args.probe)],
                          input=''.join(native_line(case) for case in inputs),
                          text=True, capture_output=True, check=True)
    lines = proc.stdout.splitlines()
    if len(lines) != len(inputs):
        raise RuntimeError(f'probe returned {len(lines)} rows for {len(inputs)} cases')
    outputs = [parse_native(line) for line in lines]
    for index, (want, got) in enumerate(zip(expected, outputs)):
        keys = ('exited', 'provider_calls', 'provider_selector',
                'window_state', 'guard', 'exit_calls', 'exit_code')
        if any(want[key] != got[key] for key in keys):
            raise AssertionError(f'case {index}: expected={want}, actual={got}')
        if not want['exited'] and want['result'] != got['result']:
            raise AssertionError(f'case {index} {inputs[index]}: result expected {want["result"]:#x}, got {got["result"]:#x}')
        if got['provider_calls'] != 1 or got['provider_selector'] != 6:
            raise AssertionError(f'case {index}: provider call contract changed: {got}')

    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/window_event_translation.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_event_translation.cpp',
        'iterations/v2/001-original-recovery/source/recovered/window_event_translation_probe.cpp',
        'iterations/v2/001-original-recovery/runs/091-window-event-translation/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/091-window-event-translation/README.md',
        'scripts/research/verify-v2-window-event-translation.py',
    ]
    report = {
        'schema': 1, 'sha256': SHA,
        'function_vas': ['00560080'],
        'full_function_vas': ['00560080'],
        'partial_function_vas': [],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'binary_matched': False, 'game_launch_verified': False,
        'boundaries': '0055feb0 is a typed input-state provider boundary invoked as selector 6; its 164-byte body contains DirectInput/state acquisition and diagnostic behavior outside this translation. The 005a246e call is a terminal exit boundary; the fixture traps at entry and records its code. 005de024 uses its existing production owner; unique scalar 005de020 is owned here. Data tables are literal 0x5b-byte arrays copied from original .data at 005de128/1de/183/239/294.',
        'source_sha256': source_hashes(dependencies, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_event_translation.cpp',
            'iterations/v2/001-original-recovery/source/recovered/window_event_translation_probe.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': [{'payload': case['payload'], 'type': case['type'], 'window_state': case['window_state'],
                      'guard': case['guard'], 'snapshot_fields': {
                          hex(i): value for i, value in enumerate(case['snapshot'])
                          if value and i in (0x21,0xa1,0x2e,0x3a,0x3c,0xbc)},
                      'output': got} for case, got in zip(inputs, outputs)],
    }
    args.report_dir.mkdir(parents=True, exist_ok=True)
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'function_vas': report['function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
