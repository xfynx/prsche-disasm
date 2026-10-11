"""Compare recovered formatter CRT leaves against the original x86 bodies."""
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
BASE, MEM, EXIT = 0x400000, 0x2200000, 0x220f000
TEXT = MEM + 0x1000
PAIRS = [
    ('zero_dividend',0,1), ('identity',0xffffffffffffffff,1),
    ('small_divisor',0xfedcba9876543210,10),
    ('high_quotient_word',0xfedcba9876543210,0x10000),
    ('near_32_boundary',0x00000001ffffffff,0xffffffff),
    ('divisor_high_min',0xffffffffffffffff,0x100000000),
    ('divisor_high_low_one',0xfedcba9876543210,0x100000001),
    ('divisor_high_mid',0xffffffffffffffff,0x7fffffff12345678),
    ('divisor_high_top',0xffffffffffffffff,0x8000000000000000),
    ('dividend_below_divisor',0x00000001ffffffff,0x100000000),
    ('exact_high_divisor',0x8000000000000000,0x4000000000000000),
    ('high_word_one',0x0000000100000000,0x00000000ffffffff),
    ('zero_remainder',0x8000000000000000,0x100000000),
    ('quotient_round_down',0xffffffffffffffff,0x80000000ffffffff),
    ('normalize_overestimate_correct',0x0000000200000001,0x0000000100000001),
    ('normalize_overestimate_remainder',0x0000000400000003,0x0000000100000001),
]
LENGTHS = (0,1,2,3,4,5,7,8,15,16,31,32,63,255)


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva and rva + size <= s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset + size]


def execute(module, image, va, args, return_words, name, text_bytes=None):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_EDX,
                                  UC_X86_REG_EIP, UC_X86_REG_ESI, UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(BASE + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(MEM, 0x10000)
    if text_bytes is not None:
        uc.mem_write(TEXT, text_bytes)
    sp = MEM + 0xe000
    stack_words = [EXIT, *args]
    uc.mem_write(sp, struct.pack('<' + 'I' * len(stack_words), *stack_words))
    uc.reg_write(UC_X86_REG_ESP, sp)
    uc.reg_write(UC_X86_REG_EBX, 0xb1b2b3b4)
    uc.reg_write(UC_X86_REG_ESI, 0xe1e2e3e4)
    uc.reg_write(UC_X86_REG_EDX, 0xd1d2d3d4)
    uc.reg_write(UC_X86_REG_EAX, 0xa1a2a3a4)
    hits = []
    def hook(m, address, _size, _data):
        if address in (0x5a680e, 0x5a687a):
            hits.append(address)
        if address == EXIT:
            m.emu_stop()
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(va, 0, count=10000)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'{name}: original did not return (EIP={uc.reg_read(UC_X86_REG_EIP):08x})')
    cleanup = 4 * len(args) if return_words == 2 else 0
    if uc.reg_read(UC_X86_REG_ESP) != sp + 4 + cleanup:
        raise AssertionError(f'{name}: original stack cleanup mismatch')
    if uc.reg_read(UC_X86_REG_EBX) != 0xb1b2b3b4:
        raise AssertionError(f'{name}: original did not preserve EBX')
    if va == 0x5a67b0 and uc.reg_read(UC_X86_REG_ESI) != 0xe1e2e3e4:
        raise AssertionError(f'{name}: original did not preserve ESI')
    value = uc.reg_read(UC_X86_REG_EAX)
    if return_words == 2:
        value |= uc.reg_read(UC_X86_REG_EDX) << 32
    return value, hits


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    modules = [json.loads(line) for line in (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines()]
    module = next(item for item in modules if item['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('original Porsche.exe SHA changed')
    native = [json.loads(line) for line in subprocess.run(
        [str(args.probe)], check=True, text=True, capture_output=True).stdout.splitlines()]
    originals = []
    for name, dividend, divisor in PAIRS:
        quotient, div_hits = execute(module, image, 0x5a67b0,
                           [dividend & 0xffffffff, dividend >> 32,
                            divisor & 0xffffffff, divisor >> 32], 2, name + ':divide')
        remainder, rem_hits = execute(module, image, 0x5a6820,
                            [dividend & 0xffffffff, dividend >> 32,
                             divisor & 0xffffffff, divisor >> 32], 2, name + ':remainder')
        if name.startswith('normalize_overestimate') and (0x5a680e not in div_hits or 0x5a687a not in rem_hits):
            raise AssertionError(f'{name}: original correction branches were not reached')
        originals.append({'kind':'integer','name':name,'dividend':f'{dividend:016x}',
                          'divisor':f'{divisor:016x}','quotient':f'{quotient:016x}',
                          'remainder':f'{remainder:016x}'})
    for alignment in range(4):
        for length in LENGTHS:
            body = bytes((i * 73 + alignment * 19) % 255 + 1 for i in range(length)) + b'\0'
            mem = bytearray(alignment + len(body))
            mem[alignment:] = body
            result, _ = execute(module, image, 0x5a6730,
                             [TEXT + alignment], 1, f'strlen:a{alignment}_n{length}', bytes(mem))
            originals.append({'kind':'strlen','name':f'a{alignment}_n{length}',
                              'align':alignment,'length':length,'result':result})
    if len(native) != len(originals):
        raise AssertionError(f'case count differs: native={len(native)} original={len(originals)}')
    for expected, actual in zip(originals, native):
        if expected != actual:
            raise AssertionError(f'{expected["name"]}: native={actual!r}, original={expected!r}')

    index_dir = ROOT / 'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    functions = [json.loads(line) for line in (index_dir / 'functions.jsonl').read_text().splitlines()]
    by_va = {entry['entry_va']:entry for entry in functions}
    sizes = {'005a67b0':104,'005a6820':117,'005a6730':123}
    if any(va not in by_va or by_va[va]['body_bytes'] != size for va,size in sizes.items()):
        raise AssertionError('function boundaries changed')
    calls = [json.loads(line) for line in (index_dir / 'calls.jsonl').read_text().splitlines()]
    targets = {f'{va:08x}': [c for c in calls if c.get('to_va') == f'{va:08x}']
               for va in (0x5a67b0,0x5a6820,0x5a6730)}
    if not all(any(c.get('from_function') == '005a4371' for c in rows) for rows in targets.values()):
        raise AssertionError('formatter parser call edges changed')
    bodies = {va:{'body_bytes':size,'body_sha256':hashlib.sha256(
        read_va(image,module,int(va,16),size)).hexdigest()} for va,size in sizes.items()}
    source = 'iterations/v2/001-original-recovery/source/'
    paths = [source+'include/porsche/formatter_runtime.hpp',
             source+'recovered/Porsche.exe/formatter_runtime.cpp',
             source+'recovered/formatter_runtime_probe.cpp',
             'iterations/v2/001-original-recovery/runs/137-formatter-runtime/CMakeLists.txt',
             'iterations/v2/001-original-recovery/runs/137-formatter-runtime/README.md',
             'scripts/research/verify-v2-formatter-runtime.py']
    asm = ROOT / 'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    report = {
        'schema':1,'module':'Porsche.exe','module_sha256':SHA,'sha256':SHA,
        'function_vas':['005a6730','005a67b0','005a6820'],
        'full_function_vas':['005a6730','005a67b0','005a6820'],'partial_function_vas':[],
        'functions':bodies,'cases':len(originals),'case_results':originals,
        'native_cpp_equal_original_x86':True,
        'abi':{'unsigned_divide':'uint64 stdcall(uint64 dividend,uint64 divisor), args are four x86 dwords, RET 0x10; EDX:EAX quotient',
               'unsigned_remainder':'uint64 stdcall(uint64 dividend,uint64 divisor), args are four x86 dwords, RET 0x10; EDX:EAX remainder',
               'strlen':'uint32 cdecl(const char*), RET; caller removes the one pointer argument'},
        'evidence':{'parser_caller_va':'005a4371','direct_call_sites':{
            va:[{'from_va':c['from_va'],'from_function':c['from_function']} for c in rows]
            for va,rows in targets.items()},
            'division_algorithm':'For divisor high dword 0, sequential DIV produces quotient-high then quotient-low (or remainder). Otherwise original repeatedly SHR/RCR-normalizes both 64-bit operands until divisor high becomes 0, DIV estimates a 32-bit quotient, and MUL/add/compare decrements an overestimate by one. Native implementation preserves these limbs and branches.',
            'correction_branch_cases':['normalize_overestimate_correct','normalize_overestimate_remainder'],
            'strlen_algorithm':'Original byte-aligns the pointer, uses the 0x7efefeff word scan and 0x81010100 predicate, then tests the candidate dword bytes in order.',
            'disassembly_sha256':hashlib.sha256(asm.read_bytes()).hexdigest(),
            'functions_index_sha256':hashlib.sha256((index_dir/'functions.jsonl').read_bytes()).hexdigest(),
            'calls_index_sha256':hashlib.sha256((index_dir/'calls.jsonl').read_bytes()).hexdigest()},
        'scope':{'divisor_zero':'Excluded: original x86 DIV raises divide-error; no normal return behavior is asserted.',
                 'invalid_string_pointer':'Excluded; strlen requires a readable NUL-terminated byte string.',
                 'crt_exports':'These are internal indexed code bodies called directly by the formatter parser; this packet defines isolated typed recovered bodies and does not claim an external CRT export binding.'},
        'source_sha256':source_hashes([ROOT/p for p in paths],compiled_sources=[
            ROOT/(source+'recovered/formatter_runtime_probe.cpp'),
            ROOT/(source+'recovered/Porsche.exe/formatter_runtime.cpp')]),
        'compiled_translation_units':[source+'recovered/formatter_runtime_probe.cpp',
                                      source+'recovered/Porsche.exe/formatter_runtime.cpp'],
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified':False}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'cases':len(originals),'native_cpp_equal_original_x86':True,
                      'function_vas':report['full_function_vas']}))


if __name__ == '__main__':
    main()
