"""Run083: compare scheduled window shutdown against original x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/083-window-shutdown'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, STOP = 0x3108000, 0x3200000
CLOSE, DISPLAY = 0x3210010, 0x3210020
HANDLE, MODE = 0x69dd18, 0x5de630
STATE_A, STATE_B, STATE_C = 0x5de64c, 0x5de67c, 0x5de6ac
CONFIG, SOURCE_A, SOURCE_B = 0x5de620, 0x5de65c, 0x5de65d
SLOTS = 0x69dd20


def put(u, address, value):
    u.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(u, address):
    return struct.unpack('<I', u.mem_read(address, 4))[0]


def initial_slots(index):
    rows = [[0x00410000 + i * 4, 100 + i, 200 + i, 300 + i] for i in range(16)]
    if index is not None:
        rows[index] = [0x0053bae0, 0xabc00000 + index, 0xdef00000 + index, 0x13570000 + index]
    return rows


def cases():
    result = []
    for mode in (0, 1, 2, 3, 0x101):
        for has_handle in (False, True):
            result.append({
                'mode': mode, 'handle': 0x11223344 if has_handle else 0,
                'mutate': 0xffffffff, 'fill_scalar': 0, 'fill_vector': 0,
                'context': 0x12345678, 'elapsed': 0x87654321,
                'config': [0xeeee0000 + i for i in range(12)],
                'slots': initial_slots(0 if has_handle else 15),
            })
    # 00534430 reads the mode byte after CloseHandle returns.
    for replacement in (0, 1, 2, 3):
        result.append({
            'mode': 2, 'handle': 0xaabbccdd, 'mutate': replacement,
            'fill_scalar': 1, 'fill_vector': 0, 'context': 0xffffffff,
            'elapsed': 0, 'config': [0x10203040 + i for i in range(12)],
            'slots': initial_slots(7),
        })
    # Exercise each exact 0053c290 fill dispatch: scalar, MMX, and SSE.
    for flags in ((0, 0), (0, 1), (1, 0)):
        result.append({
            'mode': 0, 'handle': 0, 'mutate': 0xffffffff,
            'fill_scalar': flags[0], 'fill_vector': flags[1],
            'context': 17, 'elapsed': 29,
            'config': [0xdeadbeef - i for i in range(12)],
            'slots': initial_slots(4),
        })
    # Removal is first-match only when duplicate registrations exist.
    rows = initial_slots(None)
    rows[2] = [0x0053bae0, 21, 22, 23]
    rows[11] = [0x0053bae0, 31, 32, 33]
    result.append({
        'mode': 2, 'handle': 0, 'mutate': 0xffffffff,
        'fill_scalar': 0, 'fill_vector': 0, 'context': 55, 'elapsed': 66,
        'config': list(range(12)), 'slots': rows,
    })
    return result


def load_original():
    index = ROOT / 'research/binary-index/static/binaries.jsonl'
    module = next(json.loads(line) for line in index.read_text(encoding='utf8').splitlines()
                  if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')
    return module, image


def original(module, image, case):
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0x400000, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            u.mem_write(0x400000 + section['rva'],
                        image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    u.mem_map(0x3100000, 0x10000)
    u.mem_map(STOP, 0x1000)
    u.mem_map(0x3210000, 0x1000)
    put(u, HANDLE, case['handle'])
    put(u, STATE_A, 0x11111111)
    put(u, STATE_B, 0x22222222)
    put(u, STATE_C, 0x33333333)
    for i, value in enumerate(case['config']):
        put(u, CONFIG + 4 * i, value)
    u.mem_write(MODE, bytes((case['mode'] & 0xff,)))
    put(u, 0x5deb1c, case['fill_scalar'])
    put(u, 0x5deb18, case['fill_vector'])
    put(u, 0x6bd92c, CLOSE)
    put(u, 0x6bd9b0, DISPLAY)
    for i, slot in enumerate(case['slots']):
        for j, value in enumerate(slot):
            put(u, SLOTS + i * 16 + j * 4, value)
    trace = {'events': []}

    def hook(m, address, _size, _):
        if address == CLOSE:
            sp = m.reg_read(UC_X86_REG_ESP)
            handle = word(m, sp + 4)
            trace['events'].append([1, handle])
            if case['mutate'] != 0xffffffff:
                m.mem_write(MODE, bytes((case['mutate'] & 0xff,)))
            m.reg_write(UC_X86_REG_EAX, 1)
            m.reg_write(UC_X86_REG_ESP, sp + 8)  # stdcall consumes one argument
            m.reg_write(UC_X86_REG_EIP, word(m, sp))
        elif address == DISPLAY:
            sp = m.reg_read(UC_X86_REG_ESP)
            trace['events'].append([2, word(m, sp + 4)])
            m.reg_write(UC_X86_REG_ESP, sp + 8)  # stdcall consumes mode; 00534430 restores saved ESI
            m.reg_write(UC_X86_REG_EIP, word(m, sp))
        elif address == 0x5a246e:
            sp = m.reg_read(UC_X86_REG_ESP)
            trace['events'].append([3, word(m, sp + 4)])
            m.emu_stop()  # terminal exit boundary; original body is not entered

    u.hook_add(UC_HOOK_CODE, hook)
    put(u, STACK, STOP)
    put(u, STACK + 4, case['context'])
    put(u, STACK + 8, case['elapsed'])
    u.reg_write(UC_X86_REG_ESP, STACK)
    u.emu_start(0x53bae0, STOP, count=100000)
    return collect_original(u, trace)


def collect_original(u, trace):
    return {
        'exit_code': trace['events'][-1][1] if trace['events'] and trace['events'][-1][0] == 3 else 0xffffffff,
        'exit_count': sum(1 for event in trace['events'] if event[0] == 3),
        'events': trace['events'],
        'handle': word(u, HANDLE), 'mode': u.mem_read(MODE, 1)[0],
        'state': [word(u, STATE_A), word(u, STATE_B), word(u, STATE_C)],
        'config': [word(u, CONFIG + i * 4) for i in range(12)],
        'slots': [[word(u, SLOTS + i * 16 + j * 4) for j in range(4)] for i in range(16)],
    }


def native_input(case):
    fields = [case['mode'], case['handle'], case['mutate'], case['fill_scalar'],
              case['fill_vector'], case['context'], case['elapsed']]
    fields.extend(case['config'])
    fields.extend(value for row in case['slots'] for value in row)
    return ' '.join(str(value) for value in fields) + '\n'


def normalize_native(line):
    words = [int(value, 0) for value in line.split()]
    result, exit_code, exit_count, count = words[:4]
    cursor = 4
    events = []
    for _ in range(count):
        events.append(words[cursor:cursor + 2])
        cursor += 2
    handle, mode, *rest = words[cursor:cursor + 5]
    cursor += 5
    config = words[cursor:cursor + 12]
    cursor += 12
    slots = [words[cursor + i * 4:cursor + i * 4 + 4] for i in range(16)]
    return {'result': result, 'exit_code': exit_code, 'exit_count': exit_count,
            'events': events, 'handle': handle, 'mode': mode,
            'state': rest, 'config': config, 'slots': slots}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/window-shutdown-083/bin/Release/window_shutdown_probe.exe')
    parser.add_argument('--report', type=Path, default=RUN / 'verification.json')
    args = parser.parse_args()
    module, image = load_original()
    inputs = cases()
    expected = [original(module, image, case) for case in inputs]
    native = subprocess.run([str(args.probe)], input=''.join(native_input(case) for case in inputs),
                            text=True, capture_output=True, check=True).stdout.splitlines()
    if len(native) != len(inputs):
        raise RuntimeError(f'probe returned {len(native)} rows for {len(inputs)} cases')
    outputs = [normalize_native(line) for line in native]
    for index, (want, got) in enumerate(zip(expected, outputs)):
        comparable = {key: got[key] for key in want}
        if want != comparable:
            raise AssertionError(f'case {index}: expected {want}, got {comparable}')
        if got['exit_count'] != 1 or got['exit_code'] != 0:
            raise AssertionError(f'case {index}: terminal exit boundary not reached exactly once')
        if got['result'] != 0:
            raise AssertionError(f'case {index}: native callback returned unexpected EAX')
    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/window_shutdown.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_shutdown.cpp',
        'iterations/v2/001-original-recovery/source/recovered/window_shutdown_probe.cpp',
        'iterations/v2/001-original-recovery/runs/083-window-shutdown/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/083-window-shutdown/README.md',
        'scripts/research/verify-v2-window-shutdown.py',
    ]
    report = {
        'schema': 1, 'sha256': SHA,
        'function_vas': ['00534430', '00534480', '00534550', '0053bae0', '00557370'],
        'full_function_vas': ['00534430', '00534550', '0053bae0', '00557370'],
        'partial_function_vas': ['00534480'],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'binary_matched': False, 'game_launch_verified': False,
        'boundaries': '006bd92c is an exact stdcall close-handle boundary; 006bd9b0 is an exact stdcall display callback boundary, proven by stack provenance at 00534471-0053447f; 005a246e is the terminal process-exit boundary. 00534480 is only recovered for its observed null-descriptor path via 00534550; non-null descriptor branches remain outside scope. The 0053bae0 callback receives two DWORDs but ignores both. 0053c290 is locally represented only for its proven (dest=005de620, value=0, length=0x30) fill invocation.',
        'source_sha256': source_hashes(dependencies, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_shutdown.cpp',
            'iterations/v2/001-original-recovery/source/recovered/window_shutdown_probe.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': [{'input': case, 'output': got} for case, got in zip(inputs, outputs)],
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'full_function_vas': report['full_function_vas'],
                      'partial_function_vas': report['partial_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
