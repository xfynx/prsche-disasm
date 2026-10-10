"""Run 115: compare terminal adapter and CRT cleanup with original x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/115-process-exit'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, STOP = 0x3108000, 0x3200000
ARENA, ARENA_SIZE = 0x3600000, 0x10000
EXIT, CURRENT_PROCESS, TERMINATE_PROCESS = 0x3210000, 0x3210010, 0x3210020
LOCK_ENTER, LOCK_LEAVE = 0x5a4ba4, 0x5a4c05
REG_BASE, REG_NEXT, STATE, STARTED, MODE = 0x6c1534, 0x6c1530, 0x6afce8, 0x6afce4, 0x6afce0
CALLBACKS = [0x3500100, 0x3500200, 0x3500300, 0x3500400]
STATIC_CALLBACKS = {0x5a36d6: 5912278, 0x5ac147: 5947719}


def put(uc, address, value):
    uc.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(uc, address):
    return struct.unpack('<I', uc.mem_read(address, 4))[0]


def cases():
    return [
        {'process_state': 0, 'code': 0, 'callbacks': [], 'null_index': -1},
        {'process_state': 0, 'code': 1, 'callbacks': [1], 'null_index': -1},
        {'process_state': 0, 'code': 0x87654321, 'callbacks': [1, 2, 3, 4], 'null_index': -1},
        {'process_state': 0, 'code': 0xffffffff, 'callbacks': [1, 2, 3], 'null_index': 2},
        {'process_state': 1, 'code': 0x12345678, 'callbacks': [4, 2], 'null_index': -1},
        {'process_state': 1, 'code': 0, 'callbacks': [1, 2, 3], 'null_index': 1},
    ]


def load_original():
    index = ROOT / 'research/binary-index/static/binaries.jsonl'
    module = next(json.loads(line) for line in index.read_text(encoding='utf8').splitlines()
                  if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')
    return module, image


def original(module, image, case):
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(0x400000, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(0x400000 + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(ARENA, ARENA_SIZE)
    uc.mem_map(0x3100000, 0x10000)
    uc.mem_map(STOP, 0x1000)
    uc.mem_map(0x3210000, 0x1000)
    uc.mem_map(0x3500000, 0x1000)
    uc.mem_write(ARENA, b'\xcc' * ARENA_SIZE)
    base = ARENA + 0x4000
    put(uc, REG_BASE, base)
    put(uc, REG_NEXT, base + 4 * len(case['callbacks']))
    for i, callback_id in enumerate(case['callbacks']):
        put(uc, base + i * 4, 0 if callback_id == case['null_index'] else CALLBACKS[callback_id - 1])
    put(uc, STATE, case['process_state'])
    put(uc, STARTED, 0x12345678)
    put(uc, MODE, 0xabcd1200)
    put(uc, 0x5b2094, CURRENT_PROCESS)
    put(uc, 0x5b216c, TERMINATE_PROCESS)
    put(uc, 0x5b21a8, EXIT)
    events, coverage = [], set()

    def ret(machine, sp, stack_bytes=4, eax=None):
        retaddr = word(machine, sp)
        if eax is not None:
            machine.reg_write(UC_X86_REG_EAX, eax)
        machine.reg_write(UC_X86_REG_ESP, sp + stack_bytes)
        machine.reg_write(UC_X86_REG_EIP, retaddr)

    def hook(machine, address, _size, _user):
        sp = machine.reg_read(UC_X86_REG_ESP)
        if address == EXIT:
            events.append(['exit_process', word(machine, sp + 4)])
            machine.emu_stop()
            return
        if address == CURRENT_PROCESS:
            events.append(['get_current_process'])
            ret(machine, sp, 4, 0x12345678)
            return
        if address == TERMINATE_PROCESS:
            events.append(['terminate_process', word(machine, sp + 4), word(machine, sp + 8)])
            ret(machine, sp, 12, 1)
            return
        if address in (LOCK_ENTER, LOCK_LEAVE):
            events.append(['lock' if address == LOCK_ENTER else 'unlock', word(machine, sp + 4)])
            coverage.add(f'{address:08x}')
            ret(machine, sp)
            return
        if address in STATIC_CALLBACKS:
            events.append(['callback', STATIC_CALLBACKS[address]])
            coverage.add(f'{address:08x}')
            ret(machine, sp)
            return
        if address in CALLBACKS:
            events.append(['callback', (CALLBACKS.index(address) + 1)])
            ret(machine, sp)

    uc.hook_add(UC_HOOK_CODE, hook)
    put(uc, STACK, STOP)
    put(uc, STACK + 4, case['code'])
    uc.reg_write(UC_X86_REG_ESP, STACK)
    try:
        uc.emu_start(0x5a246e, STOP, count=200000)
    except Exception as exc:
        raise RuntimeError(f'original x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x}; ESP={uc.reg_read(UC_X86_REG_ESP):08x}; events={events}') from exc
    if not events or events[-1][0] != 'exit_process':
        raise RuntimeError(f'original did not reach terminal ExitProcess boundary: {events}')
    return ({
        'terminal': True, 'base': word(uc, REG_BASE), 'next': word(uc, REG_NEXT),
        'process_state': word(uc, STATE), 'started': word(uc, STARTED),
        'mode': word(uc, MODE), 'events': events,
    }, coverage)


def native_input(case):
    ids = ' '.join(str(value) for value in case['callbacks'])
    return f"{case['process_state']} {case['code']} {len(case['callbacks'])} {case['null_index']} {ids}\n"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/process-exit-115/bin/Release/process_exit_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    module, image = load_original()
    inputs = cases()
    actual_lines = subprocess.run([str(args.probe)], input=''.join(native_input(c) for c in inputs),
                                  text=True, capture_output=True, check=True, timeout=30).stdout.splitlines()
    if len(actual_lines) != len(inputs):
        raise RuntimeError(f'probe returned {len(actual_lines)} rows for {len(inputs)} cases')
    outputs = [json.loads(line) for line in actual_lines]
    fixtures, coverage = [], set()
    for i, (case, got) in enumerate(zip(inputs, outputs)):
        want, hit = original(module, image, case)
        coverage |= hit
        if want != got:
            raise AssertionError(f'case {i} mismatch: original={want}, native={got}')
        if not got['terminal'] or got['events'][-1] != ['exit_process', case['code']]:
            raise AssertionError(f'case {i}: terminal boundary/order mismatch')
        fixtures.append({'input': case, 'output': got})
    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/process_exit.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/process_exit.cpp',
        'iterations/v2/001-original-recovery/source/recovered/process_exit_probe.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/exit_shutdown.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_shutdown.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/exit_registry.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp',
        'iterations/v2/001-original-recovery/runs/115-process-exit/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/115-process-exit/README.md',
        'scripts/research/verify-v2-process-exit.py',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'range': '005a246e..005a247e', 'function_vas': ['005a246e'],
        'full_function_vas': ['005a246e'], 'partial_function_vas': [],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'binary_matched': False, 'game_launch_verified': False,
        'comparison': 'Runs the actual original 005a246e and 005a2490 through the imported terminal boundary; compares registry callbacks in reverse order, lock/terminal order, arguments, and shutdown globals against the native adapter plus accepted CRT shutdown/registry sources.',
        'boundaries': {
            'ExitProcess': 'IAT target is replaced by a controlled terminal hook in Unicorn and a C++ exception signal in the native fixture. It records the exit code and stops without terminating the host probe.',
            'GetCurrentProcess/TerminateProcess': 'Exact Win32 API contracts are recording hooks; the process-state-one cases let TerminateProcess return so the subsequent CRT cleanup order remains observable.',
            'lock_api': '005a4ba4/005a4c05 are typed recording boundaries reached through recovered 005a2535/005a253e wrappers.',
            'CRT callbacks': 'Registered no-argument callback leaves and static callbacks 005a36d6/005ac147 are deterministic recording leaves; their bodies are not claimed recovered here.',
        },
        'source_sha256': source_hashes(dependencies, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/process_exit.cpp',
            'iterations/v2/001-original-recovery/source/recovered/process_exit_probe.cpp',
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_shutdown.cpp',
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/exit_registry.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': fixtures,
    }
    args.report_dir.mkdir(parents=True, exist_ok=True)
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'full_function_vas': report['full_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
