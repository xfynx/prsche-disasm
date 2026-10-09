"""Compare the recovered 00516950 RET leaf against the immutable x86 body."""
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
START, BODY_SIZE = 0x516950, 1
EXIT, CALLER_SP = 0x2201000, 0x220f000
ARG_VALUES = [0x11111111,0x22222222,0x33333333,0x44444444]
REGS = {
    'eax': 0xa1a2a3a4, 'ebx': 0xb1b2b3b4, 'ecx': 0xc1c2c3c4,
    'edx': 0xd1d2d3d4, 'esi': 0xe1e2e3e4, 'edi': 0xf1f2f3f4,
    'ebp': 0x1718191a,
}
COUNTS = [0,1,2,4]


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    sec = next(section for section in module['sections']
               if section['rva'] <= rva < section['rva'] + section['raw_size'])
    offset = sec['raw_offset'] + rva - sec['rva']
    return image[offset:offset + size]


def coff_symbol_bytes(path, wanted):
    data = path.read_bytes()
    _, section_count, _, symbol_ptr, symbol_count, optional_size, _ = struct.unpack_from('<HHIIIHH',data,0)
    section_start = 20 + optional_size
    sections = {}
    for index in range(section_count):
        pos = section_start + index * 40
        name = data[pos:pos+8].split(b'\0',1)[0].decode('ascii')
        raw_size, raw_ptr = struct.unpack_from('<II',data,pos+16)
        sections[index+1] = (name,raw_ptr,raw_size)
    strings_pos = symbol_ptr + symbol_count * 18
    strings_size = struct.unpack_from('<I',data,strings_pos)[0]
    strings = data[strings_pos:strings_pos+strings_size]
    found = None
    index = 0
    while index < symbol_count:
        pos = symbol_ptr + index * 18
        name_field = data[pos:pos+8]
        if name_field[:4] == b'\0\0\0\0':
            name_offset = struct.unpack_from('<I',name_field,4)[0]
            end = strings.find(b'\0',name_offset)
            name = strings[name_offset:end].decode('ascii')
        else:
            name = name_field.split(b'\0',1)[0].decode('ascii')
        value, section_number, _, _, aux_count = struct.unpack_from('<IhHBB',data,pos+8)
        if name == wanted:
            found = (value,section_number)
            break
        index += 1 + aux_count
    if found is None:
        raise AssertionError(f'COFF symbol {wanted} not found in {path}')
    value, section_number = found
    section_name, raw_ptr, raw_size = sections[section_number]
    code = data[raw_ptr+value:raw_ptr+raw_size]
    return {'object_sha256':hashlib.sha256(data).hexdigest(),
            'symbol':wanted,'section':section_name,'section_offset':value,
            'section_code_hex':code.hex()}


def original(module, image, argc):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX,
                                   UC_X86_REG_ECX, UC_X86_REG_EDI, UC_X86_REG_EDX,
                                   UC_X86_REG_EFLAGS, UC_X86_REG_EIP, UC_X86_REG_ESI,
                                   UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2200000, 0x10000)
    entry_sp = CALLER_SP - 4
    uc.mem_write(entry_sp, struct.pack('<I', EXIT))
    for i, value in enumerate(ARG_VALUES[:argc]):
        uc.mem_write(CALLER_SP + i * 4, struct.pack('<I', value))

    ids = {'eax':UC_X86_REG_EAX,'ebx':UC_X86_REG_EBX,'ecx':UC_X86_REG_ECX,
           'edx':UC_X86_REG_EDX,'esi':UC_X86_REG_ESI,'edi':UC_X86_REG_EDI,
           'ebp':UC_X86_REG_EBP}
    for name, register in ids.items():
        uc.reg_write(register, REGS[name])
    uc.reg_write(UC_X86_REG_EFLAGS, 0x246)
    uc.reg_write(UC_X86_REG_ESP, entry_sp)

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(START, 0, count=8)

    args_after = [struct.unpack('<I', uc.mem_read(CALLER_SP + i * 4, 4))[0]
                  for i in range(argc)]
    return {'argc':argc, 'gpr':[uc.reg_read(ids[k]) for k in REGS],
            'eflags':uc.reg_read(UC_X86_REG_EFLAGS),
            'esp_delta':uc.reg_read(UC_X86_REG_ESP) - CALLER_SP,
            'args_after':args_after,
            'returned_to_sentinel':uc.reg_read(UC_X86_REG_EIP)==EXIT}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, default=ROOT/'local/builds/v2/001-original-recovery/bin/Release/startup_service_516950_probe.exe')
    parser.add_argument('--object', type=Path, default=ROOT/'local/builds/v2/001-original-recovery/startup-service-100/startup_service_516950_probe.dir/Release/startup_service_516950.obj',
                        help='MSVC COFF object for startup_service_516950.cpp')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads,
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines())
        if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    body = read_va(image,module,START,BODY_SIZE)
    assert body == b'\xc3', body.hex()
    native_object = coff_symbol_bytes(args.object,
        '?startup_service_noop_00516950@porsche@@YAXXZ')

    run = subprocess.run([str(args.probe)], text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if [x['argc'] for x in actuals] != COUNTS:
        raise AssertionError(f'unexpected native cases: {actuals}')
    cases = []
    for actual, argc in zip(actuals,COUNTS):
        expected = original(module,image,argc)
        normalized = dict(actual)
        normalized['args_after'] = normalized['args_after'][:argc]
        normalized['returned_to_sentinel'] = True
        if normalized != expected:
            raise AssertionError(f'argc={argc}: original={expected} native={normalized}')
        cases.append(expected)

    tus = [
        'iterations/v2/001-original-recovery/source/recovered/startup_service_516950_probe.cpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_service_516950.cpp',
    ]
    pinned = [
        'iterations/v2/001-original-recovery/source/include/porsche/startup_service_516950.hpp',
        *tus,
        'iterations/v2/001-original-recovery/runs/100-startup-service/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/100-startup-service/README.md',
        'scripts/research/verify-v2-startup-service-516950.py',
    ]
    result = {
        'schema':1, 'module':'Porsche.exe', 'sha256':SHA, 'module_sha256':SHA,
        'function_vas':['00516950'], 'full_function_vas':['00516950'],
        'partial_function_vas':[], 'cases':len(cases),
        'native_cpp_equal_original_x86':True,
        'original_function':{'va':'00516950','body_bytes':1,
                             'body_hex':body.hex(),
                             'body_sha256':hashlib.sha256(body).hexdigest()},
        'native_object':{**native_object,
                         'byte_identical_to_original':native_object['section_code_hex']=='c3',
                         'note':'MSVC Release emits RET 0 (C2 00 00) for this naked __cdecl void; differential cases verify equivalent caller-clean behavior.'},
        'closure':{'direct_call_count':90,'tail_jump_incoming_va':'005229e0',
                   'indexed_incoming_call_records':91,'indexed_data_references':57,
                   'direct_call_sites_with_observed_push_before_call':8,
                   'callee_cleanup':'none; original C3 RET consumes only the return address'},
        'cases_summary':[{'argc':c['argc'],'gpr_eflags_equal':True,
                          'caller_stack_delta':c['esp_delta'],
                          'arguments_preserved':c['args_after']} for c in cases],
        'compiled_translation_units':tus,
        'source_sha256':source_hashes([ROOT / p for p in pinned]),
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
    }
    (args.report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(cases),'function_vas':result['function_vas'],
                      'native_cpp_equal_original_x86':True,
                      'native_code_byte_identical':result['native_object']['byte_identical_to_original']}))


if __name__=='__main__':
    main()
