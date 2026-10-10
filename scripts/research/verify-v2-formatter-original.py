"""Differentially verify the recovered original formatter helper packet."""
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
BASE, EXIT, CALLER_SP = 0x400000, 0x2201000, 0x220f000
MEM = 0x2200000
OUT, DESC, COUNT, RAW, RAW_DATA, SPAN = 0x2203000, 0x2205000, 0x2205100, 0x2206000, 0x2206100, 0x2207000
HELPERS = {
    0x5a4ab2: ('005a4ab2', 53), 0x5a4ae7: ('005a4ae7', 49),
    0x5a4b18: ('005a4b18', 56), 0x5a4b50: ('005a4b50', 13),
    0x5a4b5d: ('005a4b5d', 16), 0x5a4b6d: ('005a4b6d', 14),
}
TAILS = {
    'emit_ff': bytes(range(0xa0, 0xb0)),
    'emit_overflow': bytes(range(0x80, 0x90)),
    'emit_count_wrap': bytes(range(0x30, 0x40)),
    'repeat_3': bytes(range(0x40, 0x50)),
    'repeat_negative': bytes(range(0x10, 0x20)),
    'repeat_abort_minus1': bytes(range(0x50, 0x60)),
    'span_binary': bytes(range(0x70, 0x80)),
    'span_length_2': bytes(range(0x20, 0x30)),
}


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def signed(value):
    return struct.unpack('<i', struct.pack('<I', value & 0xffffffff))[0]


def invoke(module, image, va, args, setup):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX,
        UC_X86_REG_ECX, UC_X86_REG_EDI, UC_X86_REG_EDX, UC_X86_REG_EIP,
        UC_X86_REG_ESI, UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(BASE + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(MEM, 0x10000)
    setup(uc)
    sp = CALLER_SP - 4
    uc.mem_write(sp, struct.pack('<' + 'I' * (len(args) + 1), EXIT,
                                 *(x & 0xffffffff for x in args)))
    regs = {'eax': UC_X86_REG_EAX, 'ebx': UC_X86_REG_EBX, 'ecx': UC_X86_REG_ECX,
            'edx': UC_X86_REG_EDX, 'esi': UC_X86_REG_ESI, 'edi': UC_X86_REG_EDI,
            'ebp': UC_X86_REG_EBP, 'esp': UC_X86_REG_ESP}
    seeds = {'eax': 0xa1a2a3a4, 'ebx': 0xb1b2b3b4, 'ecx': 0xc1c2c3c4,
             'edx': 0xd1d2d3d4, 'esi': 0xe1e2e3e4, 'edi': 0xf1f2f3f4,
             'ebp': 0x1718191a}
    for name, reg in regs.items():
        if name in seeds:
            uc.reg_write(reg, seeds[name])
    uc.reg_write(UC_X86_REG_ESP, sp)
    cleanup_calls = []
    def on_code(m, address, _size, _user):
        if address == EXIT:
            m.emu_stop()
        elif address == 0x5a4259:
            # Typed call-boundary fixture for cleanup; its effects are unknown.
            current_sp = m.reg_read(UC_X86_REG_ESP)
            return_va, character, descriptor = struct.unpack('<3I', m.mem_read(current_sp, 12))
            cleanup_calls.append({'character': character, 'descriptor': descriptor})
            m.reg_write(UC_X86_REG_EAX, 0xffffffff)
            m.reg_write(UC_X86_REG_ESP, current_sp + 4)
            m.reg_write(UC_X86_REG_EIP, return_va)
    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.emu_start(va, 0, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'original helper {va:08x} did not return')
    return uc, regs, seeds, cleanup_calls


def descriptor_setup(name, remaining, count):
    def setup(uc):
        uc.mem_write(OUT, b'\xcc' * 64)
        tail = TAILS[name]
        uc.mem_write(DESC, struct.pack('<4I', OUT, remaining, OUT, 0x42) + tail)
        uc.mem_write(COUNT, struct.pack('<I', count & 0xffffffff))
    return setup


def descriptor_result(uc, name):
    cursor, remaining, base, flags = struct.unpack('<4I', uc.mem_read(DESC, 16))
    used = cursor - OUT
    tail = bytes(uc.mem_read(DESC + 16, 16))
    count = struct.unpack('<i', uc.mem_read(COUNT, 4))[0]
    return {'case': name, 'cursor': used, 'remaining': signed(remaining),
            'base': base - OUT, 'flags': flags, 'tail': tail.hex(),
            'bytes': bytes(uc.mem_read(OUT, used)).hex(), 'count': count}


def run_original(module, image):
    results, abi = [], []
    cases = [
        ('emit_ff', 0x5a4ab2, [-1, DESC, COUNT], 10, 5),
        ('emit_overflow', 0x5a4ab2, [-1, DESC, COUNT], 0, 3),
        ('emit_count_wrap', 0x5a4ab2, [ord('W'), DESC, COUNT], 4, 0x7fffffff),
        ('repeat_3', 0x5a4ae7, [ord('A'), 3, DESC, COUNT], 8, 2),
        ('repeat_negative', 0x5a4ae7, [ord('Z'), -2, DESC, COUNT], 8, 7),
        ('repeat_abort_minus1', 0x5a4ae7, [ord('Q'), 4, DESC, COUNT], 8, -2),
        ('span_binary', 0x5a4b18, [SPAN, 4, DESC, COUNT], 8, 1),
        ('span_length_2', 0x5a4b18, [SPAN, 2, DESC, COUNT], 8, 0),
    ]
    span_inputs = {'span_binary': bytes([0x41, 0, 0xff, 0x7f]),
                   'span_length_2': b'xyz'}
    for name, va, args, remaining, count in cases:
        def setup(uc, n=name, rem=remaining, cnt=count):
            descriptor_setup(n, rem, cnt)(uc)
            if n in span_inputs:
                uc.mem_write(SPAN, span_inputs[n])
        uc, regs, seeds, cleanup = invoke(module, image, va, args, setup)
        result = descriptor_result(uc, name)
        if name in ('emit_ff', 'emit_overflow'):
            result['return_is_counter'] = uc.reg_read(regs['eax']) == COUNT
        if name == 'emit_overflow':
            result['cleanup_calls'] = len(cleanup)
            result['cleanup_character'] = cleanup[0]['character'] if cleanup else 0
            result['cleanup_descriptor_is_argument'] = bool(cleanup and cleanup[0]['descriptor'] == DESC)
        if uc.reg_read(regs['esp']) != CALLER_SP:
            raise AssertionError(f'{name}: caller stack not balanced')
        preserved = [uc.reg_read(regs[n]) for n in ('ebx', 'esi', 'edi', 'ebp')]
        if preserved != [seeds[n] for n in ('ebx', 'esi', 'edi', 'ebp')]:
            raise AssertionError(f'{name}: callee-saved register mismatch {preserved!r}')
        result['esp_delta'] = uc.reg_read(regs['esp']) - CALLER_SP
        result['preserved'] = preserved
        results.append(result)

    raw_cases = [
        ('next_u32', 0x5a4b50, 1, [0x12345678, 0x89abcdef, 0x01234567]),
        ('next_u64', 0x5a4b5d, 2, [0x12345678, 0x89abcdef, 0x01234567]),
        ('next_u16', 0x5a4b6d, 1, [0x89abcdef, 0x01234567]),
    ]
    for name, va, words, values in raw_cases:
        def setup(uc):
            uc.mem_write(RAW, struct.pack('<I', RAW_DATA))
            uc.mem_write(RAW_DATA, struct.pack('<' + 'I' * len(values), *values))
        uc, regs, seeds, cleanup = invoke(module, image, va, [RAW], setup)
        eax = uc.reg_read(regs['eax'])
        value = ((uc.reg_read(regs['edx']) << 32) | eax) if name == 'next_u64' else (eax & 0xffff if name == 'next_u16' else eax)
        cursor = struct.unpack('<I', uc.mem_read(RAW, 4))[0]
        results.append({'case': name, 'value': value, 'cursor_words': (cursor - RAW_DATA) // 4})
        if uc.reg_read(regs['esp']) != CALLER_SP:
            raise AssertionError(f'{name}: caller stack not balanced')
        preserved = [uc.reg_read(regs[n]) for n in ('ebx', 'esi', 'edi', 'ebp')]
        if preserved != [seeds[n] for n in ('ebx', 'esi', 'edi', 'ebp')]:
            raise AssertionError(f'{name}: callee-saved register mismatch {preserved!r}')
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--probe', type=Path, required=True)
    ap.add_argument('--report-dir', type=Path, required=True)
    args = ap.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    binaries = ROOT / 'research/binary-index/static/binaries.jsonl'
    module = next(json.loads(line) for line in binaries.read_text(encoding='utf-8').splitlines()
                  if json.loads(line)['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('Porsche.exe SHA mismatch')
    index_dir = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    funcs = [json.loads(x) for x in (index_dir / 'functions.jsonl').read_text(encoding='utf-8').splitlines()]
    calls = [json.loads(x) for x in (index_dir / 'calls.jsonl').read_text(encoding='utf-8').splitlines()]
    by_va = {f['entry_va']: f for f in funcs}
    if any(name not in by_va or by_va[name]['body_bytes'] != size
           for _, (name, size) in HELPERS.items()):
        raise AssertionError('helper index entries/lengths changed')
    originals = run_original(module, image)
    native_lines = subprocess.run([str(args.probe)], text=True, capture_output=True,
                                  check=True).stdout.splitlines()
    native = [json.loads(line) for line in native_lines]
    expected_cleanup = {'case': 'cleanup_boundary', 'cleanup_calls': 1,
                        'character': 0xffffffff, 'descriptor_nonnull': True}
    if native[-1] != expected_cleanup:
        raise AssertionError(f'cleanup boundary recorder differs: {native[-1]}')
    if len(native) != len(originals) + 1:
        raise AssertionError('native/original helper case count differs')
    for index, (oracle, actual) in enumerate(zip(originals, native[:-1])):
        for key, value in oracle.items():
            if key in ('esp_delta', 'preserved'):
                if value != 0 and key == 'esp_delta':
                    raise AssertionError(f'{oracle["case"]}: caller stack imbalance')
                if key == 'preserved' and value != [0xb1b2b3b4, 0xe1e2e3e4, 0xf1f2f3f4, 0x1718191a]:
                    raise AssertionError(f'{oracle["case"]}: callee-saved mismatch')
                continue
            if actual.get(key) != value:
                raise AssertionError(f'case {index} {oracle["case"]} {key}: original={value!r}, native={actual.get(key)!r}')

    asm = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    body_hashes = {}
    for va, (va_text, size) in HELPERS.items():
        body = read_va(image, module, va, size)
        if len(body) != size:
            raise AssertionError(f'{va_text}: helper not raw-backed')
        body_hashes[va_text] = hashlib.sha256(body).hexdigest()
    outgoing = [c for c in calls if c.get('from_function') == '005a4371']
    if len(outgoing) != 28:
        raise AssertionError(f'005a4371 indexed outgoing edge count changed: {len(outgoing)}')
    helper_call_sites = {}
    for _, (name, _) in HELPERS.items():
        helper_call_sites[name] = {
            'incoming': [{'from': c['from_va'], 'from_function': c['from_function'], 'type': c['type']}
                         for c in calls if c.get('to_va') == name],
            'outgoing': [{'to': c['to_va'], 'to_function': c['to_function'], 'type': c['type']}
                         for c in calls if c.get('from_function') == name]}
    if len(helper_call_sites['005a4ab2']['incoming']) != 4 or \
            helper_call_sites['005a4ab2']['outgoing'] != [
                {'to': '005a4259', 'to_function': '005a4259', 'type': 'UNCONDITIONAL_CALL'}]:
        raise AssertionError('005a4ab2 caller/cleanup edge evidence changed')
    source = 'iterations/v2/001-original-recovery/source/'
    tus = [source + 'recovered/formatter_original_probe.cpp',
           source + 'recovered/Porsche.exe/formatter_original.cpp']
    pinned = [source + 'include/porsche/formatter_original.hpp', *tus,
              'iterations/v2/001-original-recovery/runs/119-formatter-original/CMakeLists.txt',
              'iterations/v2/001-original-recovery/runs/119-formatter-original/README.md',
              'scripts/research/verify-v2-formatter-original.py']
    report = {
        'schema': 1, 'module': 'Porsche.exe', 'module_sha256': SHA,
        'function_vas': [name for name, _ in HELPERS.values()],
        'full_function_vas': [name for name, _ in HELPERS.values()],
        'parser_va': '005a4371', 'parser_recovered': False,
        'native_cpp_equal_original_x86': True, 'cases': len(originals),
        'case_results': originals,
        'original_helpers': {'body_bytes': {va: size for va, (_, size) in HELPERS.items()},
                             'body_sha256': body_hashes},
        'binary_index_evidence': {
            'index': 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d',
            'functions_sha256': hashlib.sha256((index_dir / 'functions.jsonl').read_bytes()).hexdigest(),
            'calls_sha256': hashlib.sha256((index_dir / 'calls.jsonl').read_bytes()).hexdigest(),
            'disassembly_sha256': hashlib.sha256(asm.read_bytes()).hexdigest(),
            'helper_call_sites': helper_call_sites,
            'parser_outgoing_call_sites': [{'from': c['from_va'], 'to': c['to_va'], 'type': c['type']} for c in outgoing]},
        'abi': {
            'descriptor': '32 bytes; cursor/remaining/base/flags at +0/+4/+8/+0xc; +0x10..+0x1f opaque',
            'emit': 'cdecl(int32 character, descriptor*, int32* emitted_count); EAX returns emitted_count pointer',
            'repeat': 'cdecl(int32 character, int32 count, descriptor*, int32* emitted_count)',
            'span': 'cdecl(bytes*, int32 length, descriptor*, int32* emitted_count)',
            'va_fetch': 'cdecl(raw DWORD cursor*); 32/16 consume one DWORD, 64 consumes low then high DWORD; 64 advances pointer by eight bytes before both loads',
            'return_registers': {'005a4b6d': 'AX is the only meaningful returned portion; MOV AX preserves upper EAX from the advanced cursor',
                                 '005a4ae7/005a4b18': 'void-like callers ignore EAX; no EAX value is claimed',
                                 '005a4ab2': 'EAX is the physical emitted_count pointer on both success and cleanup branches; x86 oracle compares this address in native calls'}},
        'boundaries': {
            '005a4259': 'typed external boundary. The negative-capacity case proves the original call site, stack arguments and -1 result path using a recording oracle stub; cleanup body/layout effects remain unrecovered.',
            '005a4371': 'unrecovered 1,825-byte table-driven parser; classification table 005c19a8 and transition table 005c19c8; no alternate parser included',
            'floating': 'runtime callback cells initialized at 005a0f5d; callback pipeline remains open',
            'wide_multibyte': 'path through 005abf5e remains open'},
        'compiled_translation_units': tus,
        'source_sha256': source_hashes([ROOT / p for p in pinned]),
        'probe_sha256': hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified': False}
    (args.report_dir / 'verification.json').write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'cases': len(originals), 'helpers': len(HELPERS),
                      'native_cpp_equal_original_x86': True, 'parser_recovered': False}))


if __name__ == '__main__':
    main()
