"""Compare the 00561ba0 leaf against original x86 with typed service hooks."""
import argparse
import hashlib
import json
import struct
import subprocess
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
TARGET, FILE_PREDICATE = 0x561ba0, 0x561b80
ATOMIC, ROUTE, FILE_COMPARE = 0x568d50, 0x568e90, 0x533f00
CALLBACK = 0x561be0
BODY_BYTES, FILE_PREDICATE_BYTES = 55, 20
EXIT, CALLER_SP = 0x2201000, 0x220f000
CASES = [
    {'path':'DATA\\cars\\pic16.fsh','route':0,'group':1,'result':0},
    {'path':'DATA\\ui\\fonts.fsh','route':31,'group':0x104,'result':-13},
    {'path':'BACKUP\\missing.fsh','route':7,'group':0x80000002,'result':0x34567},
]


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset+size]


def original(module, image, function_va, case):
    import sys
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX,
        UC_X86_REG_ECX, UC_X86_REG_EDI, UC_X86_REG_EIP, UC_X86_REG_ESI,
        UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base+section['rva'], image[section['raw_offset']:
                section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2200000, 0x10000)
    path_address = 0x2203000
    uc.mem_write(path_address, case['path'].encode('ascii')+b'\0')
    caller_sp = CALLER_SP
    uc.mem_write(caller_sp-4, struct.pack('<I', EXIT))
    uc.mem_write(caller_sp, struct.pack('<I', path_address))
    uc.mem_write(0x5df770, struct.pack('<I', case['group']))
    # Seed the complete local context; only +0 and +0x0c should be written.
    context_entry = caller_sp-20
    uc.mem_write(context_entry, b'\xa5'*16)
    for reg, value in ((UC_X86_REG_EAX,0xa1a2a3a4),
        (UC_X86_REG_EBX,0xb1b2b3b4),(UC_X86_REG_EBP,0x1718191a),
        (UC_X86_REG_ESI,0xe1e2e3e4),(UC_X86_REG_EDI,0xd1d2d3d4),
        (UC_X86_REG_ECX,0xc1c2c3c4)):
        uc.reg_write(reg, value)
    uc.reg_write(UC_X86_REG_ESP, caller_sp-4)
    events=[]

    def u32(address):
        return struct.unpack('<I',uc.mem_read(address,4))[0]

    def cstr(address):
        data=bytearray()
        for _ in range(260):
            byte=uc.mem_read(address,1)[0]
            if byte==0:
                return data.decode('ascii')
            data.append(byte);address+=1
        raise AssertionError('unterminated guest path')

    def signed32(value):
        return struct.unpack('<i',struct.pack('<I',value & 0xffffffff))[0]

    def ret(eax=None):
        esp=uc.reg_read(UC_X86_REG_ESP)
        destination=u32(esp)
        if eax is not None: uc.reg_write(UC_X86_REG_EAX,eax & 0xffffffff)
        uc.reg_write(UC_X86_REG_ESP,esp+4)
        uc.reg_write(UC_X86_REG_EIP,destination)

    def hook(machine,address,_size,_user):
        if address==EXIT:
            machine.emu_stop();return
        esp=machine.reg_read(UC_X86_REG_ESP)
        if function_va==TARGET and address==ROUTE:
            path=cstr(u32(esp+4))
            events.append({'op':'route','path':path,'value':case['route']})
            ret(case['route'])
        elif function_va==TARGET and address==ATOMIC:
            callback,device,group,context=(u32(esp+4),u32(esp+8),
                u32(esp+12),u32(esp+16))
            context_path=u32(context)
            flag=u32(context+12)
            events.append({'op':'atomic','path':cstr(context_path),
                'callback_va':callback,'device':device,'group':group,
                'context_path_matches':context_path==path_address,
                'context_flag':flag})
            ret(case['result'])
        elif function_va==FILE_PREDICATE and address==FILE_COMPARE:
            path,group=u32(esp+4),u32(esp+8)
            events.append({'op':'file_compare','path':cstr(path),
                           'group':group,'value':case['result']})
            ret(case['result'])

    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(function_va,0,count=500)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:
        raise AssertionError(f'{function_va:08x} did not return')
    eax=uc.reg_read(UC_X86_REG_EAX)
    return {'return':signed32(eax),'caller_argument_bytes':4,'events':events,
        'callee_esp_delta':uc.reg_read(UC_X86_REG_ESP)-caller_sp,
        'preserved':{name:uc.reg_read(reg) for name,reg in
            (('ebx',UC_X86_REG_EBX),('ebp',UC_X86_REG_EBP),
             ('esi',UC_X86_REG_ESI),('edi',UC_X86_REG_EDI))},
        'context_bytes':bytes(uc.mem_read(context_entry,16)).hex()}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,required=True)
    parser.add_argument('--report-dir',type=Path,required=True)
    args=parser.parse_args()
    args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,
        (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines())
        if x['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:
        raise AssertionError('original module SHA mismatch')
    target_body=read_va(image,module,TARGET,BODY_BYTES)
    compare_body=read_va(image,module,FILE_PREDICATE,FILE_PREDICATE_BYTES)
    run=subprocess.run([str(args.probe)],text=True,capture_output=True,check=True)
    actuals=[json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals)!=len(CASES): raise AssertionError('native case count mismatch')

    summaries=[]
    predicate_comparisons=[]
    for index,(case,actual) in enumerate(zip(CASES,actuals)):
        target=original(module,image,TARGET,case)
        expected={k:target[k] for k in
            ('return','caller_argument_bytes','events')}
        normalized={k:actual[k] for k in
            ('return','caller_argument_bytes','events')}
        if normalized!=expected:
            raise AssertionError(f'00561ba0 case {index}: original={expected}, native={actual}')
        if target['callee_esp_delta']!=0:
            raise AssertionError(f'00561ba0 caller-clean stack mismatch: {target}')
        if target['preserved']!={'ebx':0xb1b2b3b4,'ebp':0x1718191a,
                'esi':0xe1e2e3e4,'edi':0xd1d2d3d4}:
            raise AssertionError(f'callee-saved register mismatch: {target}')
        expected_context=struct.pack('<I',0x2203000)+b'\xa5'*8+struct.pack('<I',1)
        if bytes.fromhex(target['context_bytes'])!=expected_context:
            raise AssertionError(f'context write footprint mismatch: {target["context_bytes"]}')

        file_predicate=original(module,image,FILE_PREDICATE,case)
        if len(target['events'])!=2 or target['events'][0]['op']!='route' or \
                target['events'][1]['op']!='atomic':
            raise AssertionError(f'00561ba0 direct-call trace changed: {target}')
        if len(file_predicate['events'])!=1 or \
                file_predicate['events'][0]['op']!='file_compare':
            raise AssertionError(f'00561b80 comparison boundary mismatch: {file_predicate}')
        predicate_comparisons.append({'case':index,
            'resource_leaf_calls':['00568e90','00568d50'],
            'file_predicate_calls':['00533f00'],
            'same_va':False,'same_event_trace':target['events']==file_predicate['events']})
        summaries.append({'case':index,'native_original_equal':True,
            'return':target['return'],'events':len(target['events']),
            'caller_argument_bytes':target['caller_argument_bytes'],
            'callee_saved_equal':True,'context_written_fields':['+0x00 path','+0x0c = 1'],
            'context_opaque_bytes_preserved':True})

    iteration='iterations/v2/001-original-recovery/'
    base=iteration+'source/'
    tus=[base+'recovered/resource_leaf_probe.cpp',
         base+'recovered/Porsche.exe/resource_leaf.cpp']
    pins=[base+'include/porsche/resource_leaf.hpp',
          base+'include/porsche/files.hpp',*tus,
          iteration+'runs/109-resource-leaf/CMakeLists.txt',
          iteration+'runs/109-resource-leaf/README.md',
          'scripts/research/verify-v2-resource-leaf.py']
    hashes=source_hashes([ROOT/p for p in pins],compiled_sources=tus)
    evidence={p:(ROOT/p).read_bytes() for p in (
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'iterations/v2/001-original-recovery/source/catalog/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl')}
    result={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,
        'function_vas':['00561ba0'],'full_function_vas':['00561ba0'],
        'partial_function_vas':[],'cases':len(summaries),
        'native_cpp_equal_original_x86':True,
        'original_function':{'va':'00561ba0','body_bytes':BODY_BYTES,
            'body_sha256':hashlib.sha256(target_body).hexdigest(),
            'abi':'one path pointer; cdecl caller-clean; RET returns dispatcher EAX',
            'callee_vas':['00568e90','00568d50'],
            'callee_abis':{'00568e90':'one path pointer; cdecl; returns device index',
                '00568d50':'callback pointer, device, group, context; cdecl; returns callback EAX'},
            'call_order':['00568e90(path)','00568d50(00561be0, device, [005df770], context)'],
            'context_layout':{'size':16,'path_offset':0,'opaque_offsets':[4,8],
                              'initialized_flag_offset':12,'initialized_flag_value':1}},
        'reference_comparison':{'va':'00561b80','body_bytes':FILE_PREDICATE_BYTES,
            'body_sha256':hashlib.sha256(compare_body).hexdigest(),
            'byte_bodies_equal':target_body==compare_body,
            'same_effects':False,'cases':predicate_comparisons,
            'distinction':'00561ba0 routes the path then enters the FILESYS atomic callback dispatcher; 00561b80 calls 00533f00 with path and [005df770].'},
        'boundaries':{'00568e90':'existing typed file-device route; fixture records input path and configured device return',
            '00568d50':'unrecovered 247-byte FILESYS atomic dispatcher; fixture records all four arguments and returns configured raw EAX without emulating device locks or queue effects',
            '00561be0':'unrecovered 118-byte callback passed by address; fixture verifies callback identity but does not invoke it',
            '005df770':'global consumed as group value; no canonical production owner found in current source tree, declared external and fixture-owned'},
        'cases_summary':summaries,'compiled_translation_units':tus,
        'source_sha256':hashes,'original_evidence':{
            path:{'sha256':hashlib.sha256(data).hexdigest()} for path,data in evidence.items()},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified':False}
    (args.report_dir/'verification.json').write_text(
        json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'cases':len(summaries),'function_vas':result['function_vas'],
        'native_cpp_equal_original_x86':True,
        'distinct_from_00561b80':True}))


if __name__=='__main__':
    main()
