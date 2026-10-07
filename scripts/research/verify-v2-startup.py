"""Compare recovered C++ startup with unchanged Porsche.exe x86 instructions.

Only the unrecovered app-main callee (0x4b6a50) is replaced by a recording
boundary in BOTH executions. This verifies 0x4b6710, not game initialization.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP

SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
STACK, BUFFER, EXIT = 0x2008000, 0x2100000, 0x2200000
RUN = ROOT / 'iterations/v2/001-original-recovery/runs/002-cpp-startup'


def compiled_code(probe):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    build = probe.parents[2]
    mapping = (build/'recovery_probe.map').read_text(encoding='utf8')
    match = re.search(r'^\s+\S+\s+\?win_main_004b6710@\S+\s+([0-9a-fA-F]{8})\s', mapping, re.M)
    if not match:
        raise RuntimeError('compiled startup symbol absent from linker map')
    va = int(match[1], 16)
    data = probe.read_bytes()
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    if struct.unpack_from('<H', data, pe+4)[0] != 0x14c:
        raise RuntimeError('compiled PE is not x86')
    sections = struct.unpack_from('<H', data, pe+6)[0]
    size = struct.unpack_from('<H', data, pe+20)[0]
    base = struct.unpack_from('<I', data, pe+24+28)[0]
    rva = va-base
    offset = None
    for i in range(sections):
        header = pe+24+size+i*40
        _vsize, start, raw_size, raw = struct.unpack_from('<4I', data, header+8)
        if start <= rva < start+raw_size:
            offset = raw+rva-start
    if offset is None:
        raise RuntimeError('compiled startup is not file-backed')
    instructions = []
    body = b''
    for insn in Cs(CS_ARCH_X86, CS_MODE_32).disasm(data[offset:offset+1024], va):
        instructions.append({'relative_offset': insn.address-va,
                             'instruction': insn.mnemonic+' '+insn.op_str})
        body += insn.bytes
        if insn.mnemonic == 'ret':
            if insn.op_str != '0x10':
                raise RuntimeError('compiled startup does not retain stdcall ret 0x10')
            break
    else:
        raise RuntimeError('compiled startup return absent in bounded decode')
    metadata = json.loads((build/'build-metadata.json').read_text(encoding='utf-8-sig'))
    return {'compiled_va': f'{va:08x}', 'compiled_bytes': len(body),
            'compiled_instruction_count': len(instructions),
            'compiled_byte_sha256': hashlib.sha256(body).hexdigest(),
            'stdcall_ret_0x10': True, 'instructions': instructions,
            'toolchain': metadata, 'original_bytes': 149,
            'binary_matched': False,
            'limitation': 'Modern toolchain and relocated probe; exact original codegen/layout not established.'}


def original(module, data, command):
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        uc.mem_write(base + section['rva'], data[section['raw_offset']:
                     section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2000000, 0x10000)
    uc.mem_map(BUFFER, 0x10000)
    uc.mem_map(EXIT, 0x1000)
    payload = (command or b'') + b'\0'
    uc.mem_write(BUFFER, payload)
    uc.mem_write(STACK, struct.pack('<5I', EXIT, 0, 0,
                                   BUFFER if command is not None else 0, 10))
    uc.reg_write(UC_X86_REG_ESP, STACK)
    capture = {}

    def read_string(pointer):
        out = bytearray()
        for i in range(65536):
            byte = uc.mem_read(pointer + i, 1)[0]
            if not byte:
                return out.hex()
            out.append(byte)
        raise RuntimeError('unterminated original argument')

    def boundary(machine, address, _size, _user):
        if address == 0x4b6a50:
            sp = machine.reg_read(UC_X86_REG_ESP)
            ret, argc, argv = struct.unpack('<3I', machine.mem_read(sp, 12))
            if capture or not 1 <= argc <= 32 or argv != 0x65b20c:
                raise RuntimeError('unexpected original app-main call')
            pointers = struct.unpack('<' + 'I' * argc, machine.mem_read(argv, argc * 4))
            capture.update(argc=argc, argv=[read_string(p) for p in pointers])
            machine.reg_write(UC_X86_REG_EAX, 0x12345678)
            machine.reg_write(UC_X86_REG_ESP, sp + 4)  # cdecl callee return
            machine.reg_write(UC_X86_REG_EIP, ret)
        elif not 0x4b6710 <= address <= 0x4b67a4:
            raise RuntimeError(f'execution left verified function: {address:08x}')

    uc.hook_add(UC_HOOK_CODE, boundary)
    uc.emu_start(0x4b6710, EXIT, count=20000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT or uc.reg_read(UC_X86_REG_ESP) != STACK + 20:
        raise RuntimeError('original stdcall return/stack mismatch')
    capture.update(buffer=bytes(uc.mem_read(BUFFER, len(payload))).hex()
                   if command is not None else '', result=uc.reg_read(UC_X86_REG_EAX))
    return capture


def cases():
    values = [None, b'', b' ', b'    ', b'a', b' a ', b'a  b   c',
              b'"two words" tail', b'a\tb\tc', b'a\r\nb', b'a\0b c',
              b' '.join(str(i).encode() for i in range(30)),
              b' '.join(str(i).encode() for i in range(31)),
              b' '.join(str(i).encode() for i in range(32)),
              b' '.join(str(i).encode() for i in range(40))]
    rng = random.Random(0x4b6710)
    alphabet = b'abXYZ0123   \t\r\n"\\' + bytes([128, 255])
    values.extend(bytes(rng.choice(alphabet) for _ in range(rng.randrange(512)))
                  for _ in range(160))
    return values


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--probe', type=Path,
                        default=ROOT / 'local/builds/v2/001-original-recovery/bin/Release/recovery_probe.exe')
    args = parser.parse_args()
    modules = [json.loads(line) for line in (ROOT / 'research/binary-index/static/binaries.jsonl')
               .read_text(encoding='utf8').splitlines()]
    module = next(m for m in modules if m['file'] == 'Porsche.exe')
    data = (ROOT / 'local/game' / module['path']).read_bytes()
    if module['sha256'] != SHA or hashlib.sha256(data).hexdigest() != SHA:
        raise RuntimeError('original SHA mismatch')
    inputs = cases()
    wire = '\n'.join('null' if c is None else c.hex() for c in inputs) + '\n'
    process = subprocess.run([str(args.probe)], input=wire, text=True,
                             capture_output=True, check=True, timeout=30)
    native = [json.loads(line) for line in process.stdout.splitlines()]
    if len(native) != len(inputs):
        raise RuntimeError('native output count mismatch')
    fixtures = []
    for index, (command, actual) in enumerate(zip(inputs, native)):
        expected = original(module, data, command)
        if actual != expected:
            raise RuntimeError(f'case {index}: native={actual}, original={expected}')
        fixtures.append({'input': None if command is None else command.hex(), 'original': expected})
    RUN.mkdir(parents=True, exist_ok=True)
    fixture_path = RUN / 'fixtures.json'
    fixture_path.write_text(json.dumps(fixtures, indent=2) + '\n', encoding='utf8', newline='\n')
    report = {'schema': 1, 'original_module': 'Porsche.exe', 'sha256': SHA,
              'function_va': '004b6710', 'function_bytes': 149,
              'cases': len(fixtures), 'native_cpp_equal_original_x86': True,
              'checks': ['argc', 'argument bytes', 'entire mutated input buffer',
                         'callee return value', 'original stdcall stack cleanup'],
              'boundary': '004b6a50: recorder only; game main not executed or recovered',
              'binary_matched': False, 'game_launch_verified': False,
              'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
              'fixture_sha256': hashlib.sha256(fixture_path.read_bytes()).hexdigest(),
              'source_sha256': {str(p.relative_to(ROOT)).replace('\\', '/'):
                               hashlib.sha256(p.read_bytes().replace(b'\r\n', b'\n')).hexdigest()
                               for p in [ROOT / 'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup.cpp',
                                         ROOT / 'iterations/v2/001-original-recovery/source/recovered/recovery_probe.cpp',
                                         ROOT / 'iterations/v2/001-original-recovery/source/include/porsche/startup.hpp']}}
    report['machine_code'] = compiled_code(args.probe)
    (RUN / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf8', newline='\n')
    print(json.dumps({k: report[k] for k in ['function_va', 'cases', 'native_cpp_equal_original_x86',
                                          'binary_matched', 'game_launch_verified']}))


if __name__ == '__main__':
    main()
