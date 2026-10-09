"""Compare startup service cleanup 0056a490 with the original x86 body."""
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
START, SIZE = 0x56a490, 41
FREE, EXIT = 0x531f90, 0x222f000
STACK, BASE = 0x221f000, 0x400000
GLOBALS = (0x6af114, 0x6af118, 0x6af11c)


def u32(value):
    return value & 0xffffffff


def cases():
    return [
        {'pointer':0, 'word118':0xaaaa1111, 'word11c':0xbbbb2222, 'free_result':0},
        {'pointer':0, 'word118':0, 'word11c':0xffffffff, 'free_result':1},
        {'pointer':0xdeadbeef, 'word118':0x12345678, 'word11c':0x87654321, 'free_result':0},
        {'pointer':0x1000, 'word118':0, 'word11c':0, 'free_result':0xffffffff},
        {'pointer':0x6af114, 'word118':0xffffffff, 'word11c':0xa5a5a5a5, 'free_result':0xfeedface},
    ]


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EIP,
                                   UC_X86_REG_ESP, UC_X86_REG_ESI)

    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(BASE + section['rva'],
                         image[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2200000, 0x30000)

    def put(address, value):
        uc.mem_write(address, struct.pack('<I', u32(value)))

    def word(address):
        return struct.unpack('<I', uc.mem_read(address, 4))[0]

    for address, value in zip(GLOBALS, (case['pointer'], case['word118'], case['word11c'])):
        put(address, value)
    put(STACK, EXIT)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    uc.reg_write(UC_X86_REG_ESI, 0x1234abcd)
    entry_sp = STACK
    trace = []
    freed = []

    def hook(machine, address, _size, _user):
        trace.append(address)
        if address == EXIT:
            machine.emu_stop()
            return
        if address == FREE:
            sp = machine.reg_read(UC_X86_REG_ESP)
            freed.append(word(sp + 4))
            ret = word(sp)
            machine.reg_write(UC_X86_REG_EAX, u32(case['free_result']))
            machine.reg_write(UC_X86_REG_ESP, sp + 4)
            machine.reg_write(UC_X86_REG_EIP, ret)
            return
        if START <= address < START + SIZE:
            return
        raise RuntimeError(f'unexpected x86 boundary {address:08x}; trace={[hex(x) for x in trace[-12:]]}')

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(START, EXIT + 1, count=10000)
    except Exception as error:
        raise RuntimeError(f'x86 emulation fault at {uc.reg_read(UC_X86_REG_EIP):08x}; trace={[hex(x) for x in trace[-12:]]}') from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError(f'original did not return; eip={uc.reg_read(UC_X86_REG_EIP):08x}')
    return {
        'state':[word(address) for address in GLOBALS],
        'free':freed,
        'entry_stack_restored':uc.reg_read(UC_X86_REG_ESP) == entry_sp + 4,
        'esi_restored':uc.reg_read(UC_X86_REG_ESI) == 0x1234abcd,
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--probe', type=Path,
        default=ROOT / 'local/builds/v2/startup-service-099/bin/Release/startup_service_56a490_probe.exe')
    parser.add_argument('--report-dir', type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads,
        (ROOT / 'research/binary-index/static/binaries.jsonl').read_text().splitlines())
        if x['file'] == 'Porsche.exe')
    image = (ROOT / 'local/game' / module['path']).read_bytes()
    assert hashlib.sha256(image).hexdigest() == SHA
    inputs = cases()
    stdin = ''.join(f"{c['pointer']} {c['word118']} {c['word11c']} {c['free_result']}\n" for c in inputs)
    run = subprocess.run([str(args.probe)], input=stdin, text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(inputs):
        raise AssertionError(f'native returned {len(actuals)} rows for {len(inputs)} inputs')
    summaries = []
    for i, (case, actual) in enumerate(zip(inputs, actuals)):
        expected = original(module, image, case)
        if not expected['entry_stack_restored'] or not expected['esi_restored']:
            raise AssertionError(f'x86 ABI state not restored for case {i}: {expected}')
        comparable = {'state':expected['state'], 'free':expected['free']}
        if actual != comparable:
            raise AssertionError(f'case {i} {case}: original={expected}, native={actual}')
        summaries.append({'pointer_nonzero':bool(case['pointer']),
                          'free_calls':len(expected['free']),
                          'word118_after':expected['state'][1],
                          'word11c_after':expected['state'][2]})
    source_paths = [
        'iterations/v2/001-original-recovery/source/include/porsche/startup_service_56a490.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_service_56a490.cpp',
        'iterations/v2/001-original-recovery/source/recovered/startup_service_56a490_probe.cpp',
        'scripts/research/verify-v2-startup-service-56a490.py',
        'iterations/v2/001-original-recovery/runs/099-startup-service/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/099-startup-service/README.md',
    ]
    rva = START - BASE
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    report = {
        'schema':1, 'module':'Porsche.exe', 'sha256':SHA, 'module_sha256':SHA,
        'function_vas':['0056a490'], 'full_function_vas':['0056a490'],
        'partial_function_vas':[], 'cases':len(inputs),
        'native_cpp_equal_original_x86':True,
        'comparison_boundary':'complete 0056a490 body, free_00531f90 call and all three global DWORDs; x86 oracle also checks ESI and return-stack preservation',
        'caller':{'va':'004b67c2','function_va':'004b67b0'},
        'global_vas':['006af114','006af118','006af11c'],
        'original_function':{'va':'0056a490','body_bytes':SIZE,
            'body_sha256':hashlib.sha256(image[offset:offset+SIZE]).hexdigest()},
        'cases_summary':summaries,
        'source_sha256':source_hashes([ROOT / p for p in source_paths]),
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
    }
    (args.report_dir / 'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({key:report[key] for key in (
        'sha256','function_vas','full_function_vas','partial_function_vas',
        'cases','native_cpp_equal_original_x86')}))


if __name__ == '__main__':
    main()
