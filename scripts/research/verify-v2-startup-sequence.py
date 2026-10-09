"""Differentially verify the ordered 004b67b0 consumer against Porsche.exe x86."""
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
START, END, TAIL = 0x4b67b0, 0x4b68e7, 0x4691c0
EXIT, STACK = 0x2201000, 0x220f000
SERVICE, NETWORK = 0x3100000, 0x3110000
REPORT_VALUE = 0x13579bdf

NOARG = [0x44dfb0,0x56a490,0x516950,0x413cf0,0x427a60,0x4a4700,
         0x4b0d70,0x4affd0,0x468fb0,0x471b70,0x4a8cd0,0x414db0,
         0x4690d0,0x434a90,0x424460,0x415dc0,0x4b0fa0,0x4121b0,
         0x48cdf0]
PHASE_CALLS = [0x4a4a70]
VALUE_CALLS = [0x569a90]
REPORT_CALLS = [0x5a177b]
TEXT_CALLS = [0x44df10]


def u32(value):
    return value & 0xffffffff


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    sec = next(section for section in module['sections']
               if section['rva'] <= rva < section['rva'] + section['raw_size'])
    offset = sec['raw_offset'] + rva - sec['rva']
    return image[offset:offset + size]


def cases():
    return [
        {'network': 'none', 'connected': 0, 'blocked': 0, 'result': REPORT_VALUE},
        {'network': 'empty', 'connected': 0, 'blocked': 0, 'result': 0x00000000},
        {'network': 'blocked', 'connected': 1, 'blocked': 1, 'result': 0x80000001},
        {'network': 'connected', 'connected': 1, 'blocked': 0, 'result': 0xfedcba98},
    ]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP,
                                   UC_X86_REG_ESP)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2200000, 0x10000)
    uc.mem_map(SERVICE, 0x1000)
    uc.mem_map(NETWORK, 0x1000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', u32(value)))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    uc.mem_write(SERVICE, bytes(0x100))
    put(0x0069ed0c, SERVICE)
    put(SERVICE + 4, SERVICE + 0x80)
    if case['network'] == 'none':
        put(0x00628c70, 0)
    else:
        put(0x00628c70, NETWORK)
        put(NETWORK + 8, case['connected'])
        uc.mem_write(NETWORK + 0xbf, bytes([case['blocked']]))
    put(0x00606ac0, 0xa5a5a5a5)
    put(0x00606ac4, 0x5a5a5a5a)
    put(STACK, EXIT)
    uc.reg_write(UC_X86_REG_ESP, STACK)

    calls = []
    stopped_at_tail = False

    def return_from_call(machine, esp, result=None):
        ret = word(esp)
        if result is not None:
            machine.reg_write(UC_X86_REG_EAX, u32(result))
        machine.reg_write(UC_X86_REG_ESP, esp + 4)
        machine.reg_write(UC_X86_REG_EIP, ret)

    def hook(machine, address, _size, _user):
        nonlocal stopped_at_tail
        if address == TAIL:
            calls.append('tail.004691c0')
            stopped_at_tail = True
            machine.emu_stop()
            return
        if address == EXIT:
            machine.emu_stop()
            return
        esp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x536080:
            receiver = machine.reg_read(UC_X86_REG_ECX)
            calls.append(f'00536080:{u32(receiver - SERVICE):08x}')
            return_from_call(machine, esp)
        elif address in NOARG:
            calls.append(f'{address:08x}')
            return_from_call(machine, esp)
        elif address in PHASE_CALLS:
            phase = word(esp + 4)
            calls.append(f'{address:08x}:{phase:08x}')
            return_from_call(machine, esp)
        elif address in VALUE_CALLS:
            calls.append(f'{address:08x}')
            return_from_call(machine, esp, case['result'])
        elif address in REPORT_CALLS:
            fmt, value = word(esp + 4), word(esp + 8)
            calls.append(f'{address:08x}.format:{fmt:08x}')
            calls.append(f'{address:08x}.value:{value:08x}')
            return_from_call(machine, esp)
        elif address in TEXT_CALLS:
            calls.append(f'{address:08x}:{word(esp + 4):08x}')
            return_from_call(machine, esp)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(START, 0, count=10000)
    state = [word(0x00606ac0), word(0x00606ac4)]
    return {'trace': calls, 'state': state,
            'tail_transfer': stopped_at_tail,
            'entry_stack_restored': uc.reg_read(UC_X86_REG_ESP) == STACK}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads,
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines())
        if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA

    inputs = cases()
    results = []
    for case in inputs:
        actual = json.loads(subprocess.run(
            [str(args.probe), case['network'], f"{case['result']:08x}"],
            text=True, capture_output=True, check=True).stdout)
        expected = original(module, image, case)
        normalized = {'trace': actual['trace'], 'state': actual['state'],
                      'tail_transfer': True,
                      'entry_stack_restored': actual['stack_equal']}
        if normalized != expected:
            raise AssertionError(f"{case}: original={expected} native={normalized}")
        results.append(expected)

    source_paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/startup_sequence.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_sequence.cpp',
        'iterations/v2/001-original-recovery/source/recovered/startup_sequence_probe.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/game_setup.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/startup_services.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/splash_progress.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/splash_progress.cpp',
        'iterations/v2/001-original-recovery/runs/097-startup-sequence/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/097-startup-sequence/README.md',
        'scripts/research/verify-v2-startup-sequence.py',
    ]
    body = read_va(image, module, START, END - START)
    result = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA, 'module_sha256': SHA,
        'function_vas': ['004b67b0'], 'full_function_vas': ['004b67b0'],
        'partial_function_vas': [], 'cases': len(inputs),
        'native_cpp_equal_original_x86': True,
        'original_function': {'va': '004b67b0', 'last_va': '004b68e6',
                              'body_end_exclusive': '004b68e7',
                              'body_bytes': len(body),
                              'body_sha256': hashlib.sha256(body).hexdigest()},
        'caller': {'va': '004b6d88', 'condition': 'inside 004b6a50 main loop after the stream is freed and only when frame_active'},
        'bounded_paths': [
            'ordered service calls, observed arguments, direct DWORD clears, network gate, and final tail transfer',
            '00536080 and remaining service callees are typed call boundaries; their internal effects are not claimed',
            '004a4a70 uses the recovered splash_progress_004a4a70(int32 phase) boundary/body from the shared source; the isolated probe records its calls',
            '004691c0 is the original unconditional tail target; the fixture records the handoff and stops at that address',
        ],
        'boundary_vas': [f'{v:08x}' for v in sorted(set(NOARG + PHASE_CALLS + VALUE_CALLS + REPORT_CALLS + TEXT_CALLS + [0x536080, TAIL]))],
        'cases_summary': [{'network': c['network'], 'trace_calls': len(r['trace']),
                           'tail_transfer': r['tail_transfer'], 'entry_stack_restored': r['entry_stack_restored']}
                          for c, r in zip(inputs, results)],
        'source_sha256': source_hashes([ROOT / p for p in source_paths]),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({'cases': len(inputs), 'function_vas': result['function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
