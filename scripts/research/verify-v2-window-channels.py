"""Run079: differentially verify original keyboard-channel setup (005739b0)."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/079-window-channels'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, EXIT = 0x3108000, 0x3200000
GET_KEY_STATE, KEYBD_EVENT = 0x3210000, 0x3210010
IAT_GET_KEY_STATE, IAT_KEYBD_EVENT = 0x5B2284, 0x5B2288


def put(u, address, value):
    u.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(u, address):
    return struct.unpack('<I', u.mem_read(address, 4))[0]


def cases():
    return [(channel, desired, state) for channel in
            (0, 1, 2, 3, 0xffffffff)
            for desired in (0, 1, 2, 0xffffffff)
            for state in (0, 1, 2, 0xfffe, 0xffff, 0x100)]


def original(module, image, case):
    channel, desired, key_state = case
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
    put(u, IAT_GET_KEY_STATE, GET_KEY_STATE)
    put(u, IAT_KEYBD_EVENT, KEYBD_EVENT)
    trace = {'queries': [], 'events': []}

    def hook(m, address, _size, _):
        if address not in (GET_KEY_STATE, KEYBD_EVENT):
            return
        sp = m.reg_read(UC_X86_REG_ESP)
        ret = word(m, sp)
        if address == GET_KEY_STATE:
            trace['queries'].append(word(m, sp + 4))
            signed_short = key_state & 0xffff
            if signed_short & 0x8000:
                signed_short -= 0x10000
            m.reg_write(UC_X86_REG_EAX, signed_short & 0xffffffff)
            cleanup = 4
        else:
            trace['events'].append(tuple(word(m, sp + 4 + 4 * i) & mask
                                          for i, mask in enumerate((0xff, 0xff, 0xffffffff, 0xffffffff))))
            cleanup = 16
        m.reg_write(UC_X86_REG_ESP, sp + 4 + cleanup)
        m.reg_write(UC_X86_REG_EIP, ret)

    u.hook_add(UC_HOOK_CODE, hook)
    for i, value in enumerate((EXIT, channel, desired)):
        put(u, STACK + 4 * i, value)
    u.reg_write(UC_X86_REG_ESP, STACK)
    u.emu_start(0x5739b0, EXIT, count=5000)
    return trace


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path,
                        default=ROOT / 'local/builds/v2/001-original-recovery/window-channels-079/bin/Release/window_channels_probe.exe')
    parser.add_argument('--report', type=Path, default=RUN / 'verification.json')
    args = parser.parse_args()
    module = next(json.loads(line) for line in
                  (ROOT / 'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()
                  if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')
    inputs = cases()
    process = subprocess.run([str(args.probe)], input=''.join(
        f'{channel} {desired} {state}\n' for channel, desired, state in inputs),
        text=True, capture_output=True, check=True)
    lines = process.stdout.splitlines()
    if len(lines) != len(inputs):
        raise RuntimeError(f'probe returned {len(lines)} lines for {len(inputs)} cases')
    outputs = []
    for case, line in zip(inputs, lines):
        native = tuple(int(value, 0) for value in line.split())
        nqueries, queried_key, nevents = native[:3]
        if len(native) != 3 + nevents * 4:
            raise RuntimeError(f'malformed native trace for {case}: {native}')
        actual = {'queries': [queried_key] * nqueries,
                  'events': [tuple(native[3 + i * 4:7 + i * 4]) for i in range(nevents)]}
        expected = original(module, image, case)
        if actual != expected:
            raise RuntimeError(f'{case}: original={expected}, native={actual}')
        outputs.append({'input': case, 'output': actual})
    dependencies = [
        'iterations/v2/001-original-recovery/source/include/porsche/window_channels.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_channels.cpp',
        'iterations/v2/001-original-recovery/source/recovered/window_channels_probe.cpp',
        'iterations/v2/001-original-recovery/runs/079-window-channels/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/079-window-channels/README.md',
        'scripts/research/verify-v2-window-channels.py',
    ]
    report = {
        'schema': 1,
        'sha256': SHA,
        'function_vas': ['005739b0'],
        'full_function_vas': ['005739b0'],
        'partial_function_vas': [],
        'cases': len(inputs),
        'native_cpp_equal_original_x86': True,
        'binary_matched': False,
        'game_launch_verified': False,
        'boundaries': 'USER32 GetKeyState (signed SHORT return) and keybd_event (BYTE/BYTE/DWORD/ULONG_PTR); Unicorn hooks execute at IAT-resolved API entry and model stdcall cleanup only.',
        'source_sha256': source_hashes(dependencies, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_channels.cpp',
            'iterations/v2/001-original-recovery/source/recovered/window_channels_probe.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': outputs,
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'full_function_vas': report['full_function_vas'],
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
