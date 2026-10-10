"""Compare 0059dd00 to original x86 with explicit file/device boundaries."""
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
TARGET, REFERENCE = 0x59dd00, 0x59dc30
BODY_BYTES = 198
EXIT, CALLER_SP = 0x2201000, 0x220f000
CALLBACK = 0x2205000
CASES = [
    {'input':'cars\\pic16.fsh','roots':False,'primary':'DATA\\','fallback':'','unrooted':-7,'exists':[]},
    {'input':'cars\\pic16.fsh','roots':False,'primary':'DATA\\','fallback':'','unrooted':0x1234,'exists':[]},
    {'input':'cars\\pic16.fsh','roots':True,'primary':'DATA\\','fallback':'BACKUP\\','unrooted':-9,'exists':[1],'reference_tail':[-5]},
    {'input':'ui\\fonts.fsh','roots':True,'primary':'DATA\\','fallback':'','unrooted':0,'exists':[0]},
    {'input':'ui\\fonts.fsh','roots':True,'primary':'DATA\\','fallback':'BACKUP\\','unrooted':0x345,'exists':[0,1],'reference_tail':[-6]},
    {'input':'missing.fsh','roots':True,'primary':'DATA\\','fallback':'BACKUP\\','unrooted':0,'exists':[0,0]},
    {'input':'zero-after-hit.fsh','roots':True,'primary':'DATA\\','fallback':'','unrooted':0,'exists':[0x80000001],'reference_tail':[0x778]},
]


def read_va(image, module, va, size):
    rva = va - int(module['image_base'], 16)
    section = next(s for s in module['sections']
                   if s['rva'] <= rva < s['rva'] + s['raw_size'])
    offset = section['raw_offset'] + rva - section['rva']
    return image[offset:offset+size]


def write_cstr(uc, address, value, size=None):
    data = value.encode('ascii') + b'\0'
    if size:
        if len(data) > size:
            raise AssertionError(f'fixture string exceeds storage: {value!r}')
        data += b'\0' * (size-len(data))
    uc.mem_write(address, data)


def original(module, image, function_va, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_EBP, UC_X86_REG_EBX,
                                   UC_X86_REG_EIP, UC_X86_REG_ESI, UC_X86_REG_ESP)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    base = int(module['image_base'], 16)
    uc.mem_map(base, 0x300000)
    for sec in module['sections']:
        if sec['raw_size']:
            uc.mem_write(base+sec['rva'], image[sec['raw_offset']:sec['raw_offset']+sec['raw_size']])
    uc.mem_map(0x2200000, 0x10000)
    input_address = 0x2203000
    write_cstr(uc, input_address, case['input'])
    write_cstr(uc, 0x6af168, case['primary'], 260)
    write_cstr(uc, 0x6af26c, case['fallback'], 260)
    uc.mem_write(0x6af370, bytes([1 if case['roots'] else 0]))
    uc.mem_write(0x6afbe4, struct.pack('<I', CALLBACK))
    caller_sp = CALLER_SP
    uc.mem_write(caller_sp-4, struct.pack('<I', EXIT))
    uc.mem_write(caller_sp, struct.pack('<I', input_address))
    for reg,val in ((UC_X86_REG_EAX,0xa1a2a3a4),(UC_X86_REG_EBX,0xb1b2b3b4),
                    (UC_X86_REG_EBP,0x1718191a),(UC_X86_REG_ESI,0xe1e2e3e4)):
        uc.reg_write(reg,val)
    uc.reg_write(UC_X86_REG_ESP,caller_sp-4)
    events=[]
    exists_index=0
    exists_values=list(case['exists'])
    if function_va == REFERENCE:
        if not case['roots']:
            exists_values=[-13]
        elif case['exists'][0] != 0 or (case['fallback'] and len(case['exists'])>1 and case['exists'][1] != 0):
            exists_values += case.get('reference_tail', [])

    def cstr(address):
        out=bytearray()
        for _ in range(260):
            b=uc.mem_read(address,1)[0]
            if b==0: return out.decode('ascii')
            out.append(b);address+=1
        raise AssertionError('unterminated guest string')

    def u32(address):
        return struct.unpack('<I',uc.mem_read(address,4))[0]

    def signed32(value):
        return struct.unpack('<i',struct.pack('<I',value & 0xffffffff))[0]

    def ret(eax=None):
        esp=uc.reg_read(UC_X86_REG_ESP)
        destination=u32(esp)
        if eax is not None: uc.reg_write(UC_X86_REG_EAX,eax&0xffffffff)
        uc.reg_write(UC_X86_REG_ESP,esp+4)
        uc.reg_write(UC_X86_REG_EIP,destination)

    def hook(machine,address,_size,_user):
        nonlocal exists_index
        if address==EXIT:
            machine.emu_stop();return
        sp=machine.reg_read(UC_X86_REG_ESP)
        if address==0x5a0fbf:
            out,fmt,root,suffix=(u32(sp+4),u32(sp+8),u32(sp+12),u32(sp+16))
            fmt_s,root_s,suffix_s=cstr(fmt),cstr(root),cstr(suffix)
            candidate=root_s+suffix_s
            uc.mem_write(out,candidate.encode('ascii')+b'\0')
            events.append({'op':'format','path':candidate,'format':fmt_s,'root':root_s,'value':0})
            ret(0x12121212)
        elif address==0x561b80:
            if exists_index>=len(exists_values):
                raise AssertionError('unexpected 00561b80 call without configured return')
            value=exists_values[exists_index];exists_index+=1
            events.append({'op':'file_probe','path':cstr(u32(sp+4)),'format':'','root':'','value':signed32(value)})
            ret(value)
        elif address==0x561ba0:
            events.append({'op':'unrooted_probe','path':cstr(u32(sp+4)),
                           'format':'','root':'','value':case['unrooted']})
            ret(case['unrooted'])
        elif address==CALLBACK:
            path,reason=cstr(u32(sp+4)),struct.unpack('<i',struct.pack('<I',u32(sp+8)))[0]
            events.append({'op':'missing_callback','path':path,'format':'','root':'','value':reason})
            ret(0x45454545)

    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(function_va,0,count=1000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:
        raise AssertionError(f'{function_va:08x} did not return')
    if function_va == TARGET:
        expected_exists=len(case['exists'])
    elif not case['roots']:
        expected_exists=1
    else:
        candidate_hit=(case['exists'][0] != 0 or
            bool(case['fallback']) and len(case['exists'])>1 and case['exists'][1] != 0)
        expected_exists=len(case['exists'])+(1 if candidate_hit else 0)
    if exists_index!=expected_exists:
        raise AssertionError(f'{function_va:08x}: exists-call count {exists_index}, expected {expected_exists}')
    eax=uc.reg_read(UC_X86_REG_EAX)
    signed_eax=struct.unpack('<i',struct.pack('<I',eax))[0]
    return {'return':signed_eax,
            'caller_argument_bytes':4,
            'callee_esp_delta':uc.reg_read(UC_X86_REG_ESP)-caller_sp,
            'events':events,
            'preserved':{'ebx':uc.reg_read(UC_X86_REG_EBX),
                         'ebp':uc.reg_read(UC_X86_REG_EBP),
                         'esi':uc.reg_read(UC_X86_REG_ESI)}}


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
    reference_body=read_va(image,module,REFERENCE,BODY_BYTES)
    run=subprocess.run([str(args.probe)],text=True,capture_output=True,check=True)
    actuals=[json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals)!=len(CASES): raise AssertionError('native case count mismatch')
    summaries=[]
    alias_summaries=[]
    for i,(case,actual) in enumerate(zip(CASES,actuals)):
        target=original(module,image,TARGET,case)
        normalized={k:actual[k] for k in ('return','caller_argument_bytes','events')}
        expected={k:target[k] for k in ('return','caller_argument_bytes','events')}
        if normalized!=expected:
            raise AssertionError(f'0059dd00 case {i}: original={expected}, native={actual}')
        if target['preserved']!={'ebx':0xb1b2b3b4,'ebp':0x1718191a,'esi':0xe1e2e3e4}:
            raise AssertionError(f'callee-saved register mismatch: {target}')
        reference=original(module,image,REFERENCE,case)
        rooted_equivalent=(target['events']==reference['events'] and
                          target['return']==reference['return'])
        candidate_hit=(case['roots'] and
            (case['exists'][0] != 0 or bool(case['fallback']) and
             len(case['exists'])>1 and case['exists'][1] != 0))
        expected_equivalent=bool(case['roots'] and not candidate_hit)
        if rooted_equivalent != expected_equivalent:
            raise AssertionError(f'0059dc30 comparison mismatch in case {i}: target={target}, reference={reference}')
        summaries.append({'case':i,'roots_enabled':case['roots'],
            'input':case['input'],'native_original_equal':True,
            'return':target['return'],'events':len(target['events']),
            'caller_argument_bytes':target['caller_argument_bytes'],
            'callee_saved_equal':True})
        alias_summaries.append({'case':i,'roots_enabled':case['roots'],
            'candidate_hit':bool(candidate_hit),
            'same_result_and_trace_as_0059dc30':rooted_equivalent,
            'target_unrooted_call':any(e['op']=='unrooted_probe' for e in target['events']),
            'reference_unrooted_call':any(e['op']=='unrooted_probe' for e in reference['events'])})

    iteration='iterations/v2/001-original-recovery/'
    source_base=iteration+'source/'
    tus=[source_base+'recovered/resource_predicate_probe.cpp',
         source_base+'recovered/Porsche.exe/resource_predicate.cpp']
    pins=[source_base+'include/porsche/resource_predicate.hpp',
          source_base+'include/porsche/files.hpp',*tus,
          iteration+'runs/106-resource-predicate/CMakeLists.txt',
          iteration+'runs/106-resource-predicate/README.md',
          'scripts/research/verify-v2-resource-predicate.py']
    hashes=source_hashes([ROOT/p for p in pins],compiled_sources=tus)
    asm=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    funcs=ROOT/'iterations/v2/001-original-recovery/source/catalog/Porsche.exe-ddd748fdbe6d/functions.jsonl'
    calls=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl'
    result={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,
        'function_vas':['0059dd00'],'full_function_vas':['0059dd00'],
        'partial_function_vas':[],'cases':len(summaries),
        'native_cpp_equal_original_x86':True,
        'original_function':{'va':'0059dd00','body_bytes':BODY_BYTES,
            'body_sha256':hashlib.sha256(target_body).hexdigest(),
            'abi':'one pointer argument; cdecl caller-clean; RET leaves the argument for caller cleanup',
            'caller_va':'00427a84','callee_vas':['00561ba0','005a0fbf','00561b80'],
            'disabled_root_leaf':'00561ba0','rooted_path_probe':'00561b80'},
        'reference_comparison':{'va':'0059dc30','body_bytes':BODY_BYTES,
            'body_sha256':hashlib.sha256(reference_body).hexdigest(),
            'byte_bodies_equal':target_body==reference_body,
            'rooted_miss_cases_equal':all(x['same_result_and_trace_as_0059dc30'] for x in alias_summaries if x['roots_enabled'] and not x['candidate_hit']),
            'rooted_hit_cases_equal':False,
            'disabled_root_cases_equal':False,
            'distinction':'0059dd00 calls 00561ba0 when roots are disabled and after a rooted candidate hit; 0059dc30 calls 00561b80 at those return points. Rooted misses share the fallback/diagnostic trace.'},
        'semantics':{'copy_bytes':'input string including terminating NUL into a 260-byte local',
            'rooted_format':'005a0fbf(out, "%s%s", root, original_input)',
            'primary_and_fallback':'Each candidate is gated by 00561b80; a nonzero result calls 00561ba0(candidate) and returns that raw EAX.',
            'fallback_enabled':'file_fallback_006af26c[0] != 0',
            'missing_callback':'if non-null, callback(original_input, -2); then return 0',
            'return':'unrooted service or successful rooted candidate service raw EAX; missing paths return 0'},
        'boundaries':{'00561ba0':'unrecovered device/resource service; exact path and raw result are recorded, no filesystem/device behavior claimed',
            '00561b80':'existing typed canonical file predicate boundary; exact candidate path, gate result and call order are recorded',
            '005a0fbf':'existing typed formatter boundary; fixture implements the observed fixed "%s%s" use only',
            'missing_file_006afbe4':'nullable original callback retained and compared when present'},
        'cases_summary':summaries,'reference_cases':alias_summaries,
        'compiled_translation_units':tus,'source_sha256':hashes,
        'original_evidence':{'disassembly_path':asm.relative_to(ROOT).as_posix(),
            'disassembly_sha256':hashlib.sha256(asm.read_bytes()).hexdigest(),
            'function_catalog_path':funcs.relative_to(ROOT).as_posix(),
            'function_catalog_sha256':hashlib.sha256(funcs.read_bytes()).hexdigest(),
            'call_index_path':calls.relative_to(ROOT).as_posix(),
            'call_index_sha256':hashlib.sha256(calls.read_bytes()).hexdigest()},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified':False}
    (args.report_dir/'verification.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'cases':len(summaries),'function_vas':result['function_vas'],
        'native_cpp_equal_original_x86':True,
        'disabled_root_differs_from_0059dc30':True}))


if __name__=='__main__':
    main()
