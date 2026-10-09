"""Differentially compare the bounded 00427a60 caller with original x86."""
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
START, BODY_SIZE = 0x427a60, 0x51
EXIT, CALLER_SP = 0x2201000, 0x220f000
CASES = [
    {'root':'DATA\\', 'exists':0, 'resource':0},
    {'root':'./', 'exists':1, 'resource':0x12345678},
    {'root':'C:\\NFS5\\DATA\\', 'exists':-1, 'resource':0x87654321},
]
BOUNDARIES = {0x5a0fbf, 0x59dd00, 0x59d8e0, 0x48cb50, 0x531f90}


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    sec = next(s for s in module['sections']
               if s['rva'] <= rva < s['rva'] + s['raw_size'])
    return image[sec['raw_offset'] + rva - sec['rva']:
                 sec['raw_offset'] + rva - sec['rva'] + size]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX,
                                   UC_X86_REG_ECX, UC_X86_REG_EDI, UC_X86_REG_EDX,
                                   UC_X86_REG_EIP, UC_X86_REG_ESI, UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base + section['rva'],
                         image[section['raw_offset']:section['raw_offset'] + section['raw_size']])
    uc.mem_map(0x2200000, 0x10000)
    root_addr = 0x2203000
    uc.mem_write(root_addr, case['root'].encode('ascii') + b'\0')
    uc.mem_write(0x65b360, struct.pack('<I', root_addr))
    caller_sp = CALLER_SP
    entry_sp = caller_sp - 4
    uc.mem_write(entry_sp, struct.pack('<I', EXIT))
    regs = {'eax':UC_X86_REG_EAX, 'ebx':UC_X86_REG_EBX,
            'ecx':UC_X86_REG_ECX, 'edx':UC_X86_REG_EDX,
            'esi':UC_X86_REG_ESI, 'edi':UC_X86_REG_EDI,
            'ebp':UC_X86_REG_EBP}
    seeds = {'eax':0xa1a2a3a4, 'ebx':0xb1b2b3b4, 'ecx':0xc1c2c3c4,
             'edx':0xd1d2d3d4, 'esi':0xe1e2e3e4, 'edi':0xf1f2f3f4,
             'ebp':0x1718191a}
    for name, reg in regs.items():
        uc.reg_write(reg, seeds[name])
    uc.reg_write(UC_X86_REG_ESP, entry_sp)
    events = []

    def cstr(address):
        out = bytearray()
        while True:
            b = uc.mem_read(address, 1)[0]
            if b == 0:
                return out.decode('ascii')
            out.append(b)
            address += 1

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    def ret(eax=None):
        esp = uc.reg_read(UC_X86_REG_ESP)
        address = word(esp)
        if eax is not None:
            uc.reg_write(UC_X86_REG_EAX, eax & 0xffffffff)
        uc.reg_write(UC_X86_REG_ESP, esp + 4)
        uc.reg_write(UC_X86_REG_EIP, address)

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
            return
        if address not in BOUNDARIES:
            return
        sp = machine.reg_read(UC_X86_REG_ESP)
        if address == 0x5a0fbf:
            out, fmt, root, suffix = (word(sp+4), word(sp+8), word(sp+12), word(sp+16))
            fmt_s, root_s, suffix_s = cstr(fmt), cstr(root), cstr(suffix)
            path = root_s + suffix_s + '.fsh'
            machine.mem_write(out, path.encode('ascii') + b'\0')
            events.append({'name':'format','path':fmt_s+'|'+root_s+'|'+suffix_s+'|'+path,'a':0,'b':0,'c':0})
            ret(0x12121212)
        elif address == 0x59dd00:
            path = cstr(word(sp+4))
            events.append({'name':'exists','path':path,'a':0,'b':0,'c':0})
            ret(case['exists'])
        elif address == 0x59d8e0:
            path, zero = cstr(word(sp+4)), word(sp+8)
            events.append({'name':'load','path':path,'a':zero,'b':0,'c':0})
            ret(case['resource'])
        elif address == 0x48cb50:
            zero, resource, exists = word(sp+4), word(sp+8), word(sp+12)
            events.append({'name':'consume','path':'','a':zero,'b':resource,'c':exists})
            ret(0x34343434)
        else:
            resource = word(sp+4)
            events.append({'name':'free','path':'','a':resource,'b':0,'c':0})
            ret(0x56565656)

    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(START, 0, count=200)
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError('original did not return to sentinel')
    return {'events':events,
            'esp_delta':uc.reg_read(UC_X86_REG_ESP)-caller_sp,
            'preserved':{k:uc.reg_read(regs[k]) for k in ('ebx','esi','edi','ebp')}}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path, required=True)
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads,
        (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines())
        if x['file'] == 'Porsche.exe')
    image = (ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError('original image SHA mismatch')
    body = read_va(image,module,START,BODY_SIZE)
    if len(body) != BODY_SIZE:
        raise AssertionError('function bytes outside raw-backed section')
    run = subprocess.run([str(args.probe)], text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(CASES):
        raise AssertionError(f'expected {len(CASES)} native cases, got {len(actuals)}')
    cases = []
    for i,(case,actual) in enumerate(zip(CASES,actuals)):
        expected = original(module,image,case)
        normalized = {k:actual[k] for k in ('events','esp_delta')}
        if normalized != {k:expected[k] for k in ('events','esp_delta')}:
            raise AssertionError(f'case {i}: original={expected}, native={actual}')
        if expected['preserved'] != {'ebx':0xb1b2b3b4,'esi':0xe1e2e3e4,
                                     'edi':0xf1f2f3f4,'ebp':0x1718191a}:
            raise AssertionError(f'callee-saved register mismatch: {expected}')
        cases.append({'case':i, 'root':case['root'], 'exists':case['exists'],
                      'resource':case['resource'], 'events':len(expected['events']),
                      'ordered_calls_equal':True, 'caller_stack_delta':expected['esp_delta'],
                      'callee_saved_equal':True})
    source_base='iterations/v2/001-original-recovery/source/'
    tus=[source_base+'recovered/engine_service_427a60_probe.cpp',
         source_base+'recovered/Porsche.exe/engine_service_427a60.cpp']
    pinned=[source_base+'include/porsche/engine_service_427a60.hpp',*tus,
            'iterations/v2/001-original-recovery/runs/103-engine-service/CMakeLists.txt',
            'iterations/v2/001-original-recovery/runs/103-engine-service/README.md',
            'scripts/research/verify-v2-engine-service-427a60.py']
    result={
      'schema':1, 'module':'Porsche.exe', 'sha256':SHA, 'module_sha256':SHA,
      'function_vas':['00427a60'], 'full_function_vas':['00427a60'],
      'partial_function_vas':[], 'cases':len(cases),
      'native_cpp_equal_original_x86':True,
      'original_function':{'va':'00427a60','body_bytes':BODY_SIZE,
          'body_sha256':hashlib.sha256(body).hexdigest(),
          'boundary_call_sites':['00427a7a','00427a84','00427a92','00427a9d','00427aa3']},
      'semantics':{'format':'"%s%s.fsh" with [0065b360] and "pic16"',
          'sequence':['005a0fbf','0059dd00','0059d8e0','0048cb50','00531f90'],
          'arguments':{'0059dd00':['path'],'0059d8e0':['path',0],
                       '0048cb50':[0,'resource','signed result from 0059dd00'],
                       '00531f90':['resource']},
          'cleanup':'cdecl/caller-clean; ADD ESP,0x2c releases 44 bytes of accumulated arguments',
          'state':'0065b360 is a BSS pointer cell; source storage owner remains external'},
      'boundaries':{'0059dd00':'unrecovered file-existence routine, typed fixture boundary; EAX is consumed as signed value',
          '0059d8e0':'resource-open boundary; pointer result is passed through and freed, internals not claimed',
          '0048cb50':'unrecovered resource consumer, explicit effect boundary; return ignored',
          '005a0fbf':'existing file_format_005a0fbf declaration; fixture emulates only this fixed format',
          '00531f90':'existing free_00531f90 declaration; fixture records pointer and return is ignored'},
      'cases_summary':cases, 'compiled_translation_units':tus,
      'source_sha256':source_hashes([ROOT/p for p in pinned]),
      'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
      'game_launch_verified':False}
    (args.report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(cases),'function_vas':result['function_vas'],
                      'native_cpp_equal_original_x86':True}))


if __name__=='__main__':
    main()
