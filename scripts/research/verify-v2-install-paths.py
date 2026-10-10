"""Run116: compare install.txt path producer, cleanup, and size leaf to x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/116-install-paths'
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
INSTALL_SHA = '30e603756352a84c00d6d6b85a37e8dd19a375b544b318be88a1081a56bf1aae'
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

STACK, STOP = 0x3108000, 0x3200000
ARENA, ARENA_SIZE, BLOB_OFFSET = 0x3600000, 0x10000, 0x1000
OPEN, FREE = 0x59d8e0, 0x531f90
TABLE, BLOB_CELL = 0x65b2a0, 0x65b29c
TABLE_CELLS = 60
FUNCTIONS = {'004b6ff0', '004b7070', '00556640'}


def put(uc, address, value):
    uc.mem_write(address, struct.pack('<I', value & 0xffffffff))


def word(uc, address):
    return struct.unpack('<I', uc.mem_read(address, 4))[0]


def install_blob():
    path = ROOT / 'local/game/install.txt'
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != INSTALL_SHA:
        raise RuntimeError('read-only local/game/install.txt SHA mismatch')
    return data


def load_cases(real):
    return [
        {'name': 'real_install_txt', 'bytes': real},
        {'name': 'LF_only', 'bytes': real.replace(b'\r\n', b'\n')},
        {'name': 'mixed_and_blank_separators', 'bytes': b'001alpha\r\n\r\n002beta\n\n003gamma\r004delta\r\n\r\n'},
        {'name': 'CR_only', 'bytes': b'abcOne\rabcTwo\r\r'},
        {'name': 'empty_length_two', 'bytes': b'\r\n'},
    ]


def pe_image():
    index = ROOT / 'research/binary-index/static/binaries.jsonl'
    module = next(json.loads(line) for line in index.read_text(encoding='utf8').splitlines()
                  if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise RuntimeError('local/game Porsche.exe does not match indexed original SHA')
    return module, image


def execute_original(module, image, operation, data=None):
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
    events, coverage = [], set()
    blob = ARENA + BLOB_OFFSET
    if operation in ('LOAD', 'SIZE'):
        assert data is not None
        uc.mem_write(blob - 12, struct.pack('<I', len(data)))
        uc.mem_write(blob, data)
    if operation == 'LOAD':
        put(uc, BLOB_CELL, 0x11111111)
        for i in range(TABLE_CELLS):
            put(uc, TABLE + i * 4, 0x77000000 + i)
    elif operation == 'CLEAN':
        put(uc, BLOB_CELL, blob if data else 0)

    def ret(machine, sp, cleanup, eax=None):
        return_address = word(machine, sp)
        if eax is not None:
            machine.reg_write(UC_X86_REG_EAX, eax)
        machine.reg_write(UC_X86_REG_ESP, sp + cleanup)
        machine.reg_write(UC_X86_REG_EIP, return_address)

    def hook(machine, address, _size, _user):
        sp = machine.reg_read(UC_X86_REG_ESP)
        va = f'{address:08x}'
        if va in FUNCTIONS:
            coverage.add(va)
        if address == OPEN:
            path_pointer, zero = word(machine, sp + 4), word(machine, sp + 8)
            raw = bytearray()
            while machine.mem_read(path_pointer + len(raw), 1) != b'\x00':
                raw.extend(machine.mem_read(path_pointer + len(raw), 1))
            events.append(['open', raw.decode('ascii'), zero])
            ret(machine, sp, 4, blob)
        elif address == FREE:
            pointer = word(machine, sp + 4)
            events.append(['free', pointer])
            ret(machine, sp, 4, 1)

    uc.hook_add(UC_HOOK_CODE, hook)
    put(uc, STACK, STOP)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    entry = {'LOAD': 0x4b6ff0, 'CLEAN': 0x4b7070, 'SIZE': 0x556640}[operation]
    if operation == 'SIZE':
        put(uc, STACK + 4, blob)
    try:
        uc.emu_start(entry, STOP, count=100000)
    except Exception as exc:
        raise RuntimeError(f'{operation} original fault at EIP={uc.reg_read(UC_X86_REG_EIP):08x}, ESP={uc.reg_read(UC_X86_REG_ESP):08x}, events={events}') from exc
    if uc.reg_read(UC_X86_REG_EIP) != STOP or uc.reg_read(UC_X86_REG_ESP) != STACK + 4:
        raise RuntimeError(f'{operation} original ABI mismatch: EIP={uc.reg_read(UC_X86_REG_EIP):08x}, ESP={uc.reg_read(UC_X86_REG_ESP):08x}')
    eax = uc.reg_read(UC_X86_REG_EAX)
    if operation == 'LOAD':
        offsets = []
        for i in range(TABLE_CELLS):
            value = word(uc, TABLE + i * 4)
            offsets.append(None if value == 0 else value - blob)
        return {'op': operation, 'result': eax, 'blob_offset': BLOB_OFFSET,
                'open_path': events[0][1], 'open_zero': events[0][2],
                'table_offsets': offsets, 'bytes': bytes(uc.mem_read(blob, len(data))).hex()}, coverage
    if operation == 'CLEAN':
        pointer = word(uc, BLOB_CELL)
        return {'op': operation, 'result': eax, 'blob_offset': BLOB_OFFSET if pointer else -1,
                'free_count': len(events), 'free_pointer_offset': (events[0][1] - ARENA) if events else -1}, coverage
    return {'op': operation, 'result': eax}, coverage


def native_line(operation, data=None):
    if operation == 'LOAD' or operation == 'SIZE':
        return f'{operation} {len(data)} {data.hex()}\n'
    return f'CLEAN {1 if data else 0}\n'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT / 'local/builds/v2/001-original-recovery/install-paths-116/bin/Release/install_paths_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    module, image = pe_image()
    real = install_blob()
    inputs = [('LOAD', row['bytes']) for row in load_cases(real)]
    inputs += [('SIZE', real), ('SIZE', b'\r\n'), ('CLEAN', None), ('CLEAN', b'free')]
    requests = ''.join(native_line(op, data) for op, data in inputs)
    rows = subprocess.run([str(args.probe)], input=requests, text=True,
                          capture_output=True, check=True, timeout=30).stdout.splitlines()
    if len(rows) != len(inputs):
        raise RuntimeError(f'probe returned {len(rows)} rows for {len(inputs)} cases')
    actual = [json.loads(row) for row in rows]
    fixtures, coverage = [], set()
    for index, ((op, data), got) in enumerate(zip(inputs, actual)):
        want, hit = execute_original(module, image, op, data)
        coverage |= hit
        if want != got:
            raise AssertionError(f'case {index} {op} mismatch: original={want}, native={got}')
        fixtures.append({'input': {'operation': op, 'bytes_sha256': hashlib.sha256(data).hexdigest() if data is not None else None}, 'output': got})
    expected = {'004b6ff0', '004b7070', '00556640'}
    if coverage != expected:
        raise RuntimeError(f'original function coverage mismatch: {sorted(coverage)}')
    real_output = actual[0]
    real_entries = sum(value is not None for value in real_output['table_offsets'])
    if real_entries != 49:
        raise RuntimeError(f'expected 49 real install path entries; got {real_entries}')
    deps = [
        'iterations/v2/001-original-recovery/source/include/porsche/install_paths.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths.cpp',
        'iterations/v2/001-original-recovery/source/recovered/install_paths_probe.cpp',
        'iterations/v2/001-original-recovery/source/include/porsche/game_setup.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
        'iterations/v2/001-original-recovery/runs/116-install-paths/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/116-install-paths/README.md',
        'scripts/research/verify-v2-install-paths.py',
        'local/game/install.txt',
    ]
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'sha256': SHA,
        'function_vas': sorted(coverage), 'full_function_vas': sorted(expected),
        'partial_function_vas': [], 'cases': len(inputs),
        'native_cpp_equal_original_x86': True, 'binary_matched': False,
        'game_launch_verified': False,
        'original_fixture': {'path': 'local/game/install.txt', 'sha256': INSTALL_SHA,
                             'bytes': len(real), 'physical_lines_including_final_blank': len(real.splitlines()),
                             'recovered_entries': real_entries},
        'comparison': 'Compares the exact 60 pointer cells, mutation of each parsed blob, return EAX, literal open arguments, metadata size helper, cleanup return/global preservation, and conditional free boundary against original x86.',
        'boundaries': {
            '0059d8e0': 'Typed resource-open recording boundary returns the exact supplied blob and records path plus zero mode; the game archive implementation is outside this run.',
            '00531f90': 'Typed free recording boundary returns the observed success value 1; heap internals are outside this run.',
            'long_or_malformed_input': 'No synthetic clamp or recovery behavior is added. Fixtures use the real bounded install.txt and bounded LF/CRLF/blank-line variants; >60 table writes and unterminated scans are not claimed.',
            'producer_EAX': 'The recovered body preserves its final AL value. Some end cases read a byte beyond the declared blob; the fixture uses matching zero-filled surrounding pages, and caller 004a5410 ignores EAX. No allocator-padding-independent return claim is made.',
            'shared_globals': 'Run116 owns its isolated table/blob declarations. Existing 0065b32c/334/360 and display-name aliases remain unchanged pending root integration.',
        },
        'source_sha256': source_hashes(deps, compiled_sources=[
            'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths.cpp',
            'iterations/v2/001-original-recovery/source/recovered/install_paths_probe.cpp']),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'fixtures': fixtures,
    }
    args.report_dir.mkdir(parents=True, exist_ok=True)
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8')
    print(json.dumps({'cases': len(inputs), 'function_vas': sorted(coverage),
                      'real_install_entries': real_entries,
                      'native_cpp_equal_original_x86': True}))


if __name__ == '__main__':
    main()
