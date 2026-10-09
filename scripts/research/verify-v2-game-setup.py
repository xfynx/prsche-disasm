"""Compare the recovered 004dd600 caller flow against original x86."""
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
START, EXIT = 0x4dd600, 0x2210000
STACK, RESOURCE, MOVIE = 0x221f000, 0x3100000, 0x3200000
STRINGS, DISPLAY, SERVICE, SERVICE_TARGET = 0x3300000, 0x3310000, 0x3320000, 0x3330000
STUBS = {0x2220000 + i * 0x10: (i, (4 if i in (0, 4) else 0)) for i in range(5)}
SVC = {
    0x467fc0: 1, 0x560030: 2, 0x5a0fbf: 3, 0x536080: 4,
    0x59dc30: 6, 0x403520: 7, 0x59e440: 8, 0x4dc850: 21,
    0x4237d0: 15, 0x536050: 5, 0x4dd4a0: 14, 0x59d8e0: 16,
    0x563440: 17, 0x534540: 18, 0x534550: 19, 0x531f90: 20,
}
SLOT_ADDRESSES = (0x6bd9b0, 0x6bd91c, 0x6bd970, 0x6bd948, 0x6bd978)


def u32(v):
    return v & 0xffffffff


def fnv(text):
    h = 2166136261
    for byte in text.encode('ascii'):
        h = ((h ^ byte) * 16777619) & 0xffffffff
    return h


def cstring(uc, address):
    data = bytearray()
    while True:
        b = uc.mem_read(address + len(data), 1)[0]
        if b == 0:
            return data.decode('ascii')
        data.append(b)


def cases():
    return [
        {'earts': 0, 'load': 0, 'begin': 0, 'end': 0, 'stop': 0},
        {'earts': 1, 'load': 0, 'begin': MOVIE + 0x100, 'end': MOVIE + 0x180, 'stop': 0},
        {'earts': 1, 'load': 1, 'begin': MOVIE + 0x120, 'end': MOVIE + 0x100, 'stop': 0},
        {'earts': 1, 'load': 1, 'begin': 0, 'end': MOVIE + 0x200, 'stop': 1},
        {'earts': 0, 'load': 1, 'begin': 0, 'end': 0, 'stop': 0},
    ]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_ESP

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'], image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    for addr, size in ((0x2200000, 0x30000), (0x3000000, 0x10000),
                       (0x3100000, 0x10000), (0x3200000, 0x10000),
                       (0x3300000, 0x10000), (0x3320000, 0x10000)):
        uc.mem_map(addr, size)

    def put(addr, value):
        uc.mem_write(addr, struct.pack('<I', u32(value)))

    def word(addr):
        return struct.unpack('<I', uc.mem_read(addr, 4))[0]

    def text(addr, value):
        uc.mem_write(addr, value.encode('ascii') + b'\0')

    text(STRINGS, 'boot/')
    text(STRINGS + 0x100, 'ui/')
    put(0x65b32c, STRINGS)
    put(0x65b334, STRINGS + 0x100)
    put(0x69ed0c, SERVICE)
    put(SERVICE + 4, SERVICE_TARGET)
    put(0x628130, DISPLAY)
    for i, slot in enumerate(SLOT_ADDRESSES):
        put(slot, 0x2220000 + i * 0x10)
    for off in range(0, 0x2000 - 0x180, 8):
        value = 0x100 + off
        for table in (0x14, 0xb4, 0x104, 0x12c, 0x154):
            put(RESOURCE + table + off, value)
    put(STACK, EXIT)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    trace = []
    events = []
    exists_count = 0

    def finish(machine, sp, result=0, pop_bytes=0):
        ret = word(sp)
        machine.reg_write(UC_X86_REG_EAX, u32(result))
        machine.reg_write(UC_X86_REG_ESP, sp + 4 + pop_bytes)
        machine.reg_write(UC_X86_REG_EIP, ret)

    def hook(machine, address, _size, _user):
        nonlocal exists_count
        trace.append(address)
        if address == EXIT:
            machine.emu_stop()
            return
        if address in STUBS:
            idx, pop = STUBS[address]
            sp = machine.reg_read(UC_X86_REG_ESP)
            args = [word(sp + 4 + 4 * i) for i in range(pop // 4)]
            events.append({'id': 9 + idx, 'args': args})
            finish(machine, sp, pop_bytes=pop)
            return
        if address in SVC:
            ident = SVC[address]
            sp = machine.reg_read(UC_X86_REG_ESP)
            ecx = machine.reg_read(UC_X86_REG_ECX)
            args = []
            result = 0
            if ident == 1:
                args = [ecx != 0, word(sp+4), word(sp+8), word(sp+12), word(sp+16)]
            elif ident == 2:
                pass
            elif ident == 3:
                out, fmt, src, scratch = [word(sp+4+4*i) for i in range(4)]
                path = cstring(machine, src) + ('earts-av.mad' if cstring(machine, fmt) == '%searts-av.mad' else 'loadscrn.fsh')
                machine.mem_write(out, path.encode('ascii') + b'\0')
                args = [fnv(cstring(machine, fmt)), fnv(cstring(machine, src))]
            elif ident in (4, 5):
                args = [ecx - SERVICE_TARGET]
            elif ident == 6:
                path = cstring(machine, word(sp+4))
                found = int(path.endswith('earts-av.mad') and case['earts'] or
                            path.endswith('loadscrn.fsh') and case['load'])
                args, result = [fnv(path), found], found
                exists_count += 1
            elif ident == 7:
                obj = ecx
                put(obj, MOVIE + 0x800); put(obj+4, MOVIE + 0x800); put(obj+8, MOVIE + 0x808)
                args = [word(sp+4)]
                events.append({'id': ident, 'args': args})
                finish(machine, sp, pop_bytes=4)
                return
            elif ident == 8:
                path, obj = word(sp+4), word(sp+8)
                put(obj, case['begin']); put(obj+4, 0x55667788); put(obj+8, case['end'])
                args = [fnv(cstring(machine, path)), case['begin'], case['end']]
            elif ident == 21:
                stream, stop, a2, a3, a4 = [word(sp+4+4*i) for i in range(5)]
                put(stop, case['stop'])
                args = [stream, int(stop != 0), a2, a3, a4]
            elif ident == 15:
                args = [word(sp+4), word(sp+8), word(sp+12)]
            elif ident == 14:
                pass
            elif ident == 16:
                path, zero = word(sp+4), word(sp+8)
                args, result = [fnv(cstring(machine, path)), zero], RESOURCE
            elif ident == 17:
                args = [word(sp+4)-RESOURCE] + [word(sp+8+4*i) for i in range(4)]
            elif ident == 18 or ident == 19:
                pass
            elif ident == 20:
                args = [word(sp+4)-RESOURCE]
                result = 1
            events.append({'id': ident, 'args': args})
            finish(machine, sp, result)
            return
        if START <= address < START + 0x3f4:
            return
        raise RuntimeError(f'unexpected original boundary {address:08x}; trace={[hex(x) for x in trace[-20:]]}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(START, EXIT + 1, count=1_000_000)
    except Exception as error:
        raise RuntimeError(f"original emulation fault at {uc.reg_read(UC_X86_REG_EIP):08x}; trace={[hex(x) for x in trace[-20:]]}") from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'original did not return; eip={uc.reg_read(UC_X86_REG_EIP):08x}')
    return events


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/game-setup-093/bin/Release/game_setup_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    inputs = cases()
    probe_input = ''.join(f"{c['earts']} {c['load']} {c['begin']} {c['end']} {c['stop']}\n" for c in inputs)
    run = subprocess.run([str(args.probe)], input=probe_input, text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(inputs):
        raise AssertionError(f'native returned {len(actuals)} rows for {len(inputs)} cases')
    for i, (case, actual) in enumerate(zip(inputs, actuals)):
        expected = original(module, image, case)
        if actual != expected:
            upto = next((j for j, (a,b) in enumerate(zip(actual, expected)) if a != b), min(len(actual),len(expected)))
            raise AssertionError(f'case {i}: event {upto}; original={expected[upto:upto+3]} native={actual[upto:upto+3]} lengths={len(expected)}/{len(actual)}')
    source_paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/game_setup.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/game_setup.cpp',
        'iterations/v2/001-original-recovery/source/recovered/game_setup_probe.cpp',
        'scripts/research/verify-v2-game-setup.py',
        'iterations/v2/001-original-recovery/runs/093-game-setup/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/093-game-setup/README.md',
    ]
    body_size = 0x3f4
    result = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'function_vas': ['004dd600'], 'full_function_vas': ['004dd600'], 'partial_function_vas': [],
        'cases': len(inputs), 'native_cpp_equal_original_x86': True,
        'comparison_boundary': '004dd600 complete direct-control-flow/call-argument trace; media, resource, renderer, CRT formatting and draw consumers are explicit typed boundaries',
        'original_function': {'va':'004dd600','body_bytes':body_size,
            'body_sha256':hashlib.sha256(image[0:0]).hexdigest()},
        'source_sha256': source_hashes([ROOT / p for p in source_paths]),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'remaining_boundaries': ['004dc850','004dd4a0','00563440','0059dc30','0059d8e0','0059e440','005a0fbf','00536080','00536050','00403520','004237d0','00560030','00534540','006bd9b0','006bd91c','006bd970','006bd948','006bd978'],
    }
    # Hash the exact mapped function byte range from its containing PE section.
    sec = next(s for s in module['sections'] if s['rva'] <= START - int(module['image_base'],16) < s['rva'] + s['raw_size'])
    off = sec['raw_offset'] + START - int(module['image_base'],16) - sec['rva']
    result['original_function']['body_sha256'] = hashlib.sha256(image[off:off+body_size]).hexdigest()
    (args.report_dir / 'verification.json').write_text(json.dumps(result, indent=2) + '\n', newline='\n')
    print(json.dumps({key: result[key] for key in (
        'sha256','function_vas','full_function_vas','partial_function_vas',
        'cases','native_cpp_equal_original_x86')}))


if __name__ == '__main__':
    main()
