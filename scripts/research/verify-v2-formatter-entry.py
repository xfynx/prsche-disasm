"""Compare recovered 005a0fbf wrapper against its original x86 body."""
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
START, SIZE = 0x5a0fbf, 0x52
CORE, CLEANUP = 0x5a4371, 0x5a4259
EXIT, CALLER_SP = 0x2201000, 0x220f000
CASES = [
    {'remaining':0x00000000,'cursor':0,'result':0x00000000},
    {'remaining':0x00000001,'cursor':7,'result':0x7fffffff},
    {'remaining':0x00000002,'cursor':31,'result':0x80000000},
    {'remaining':0x7fffffff,'cursor':3,'result':0xdeadbeef},
    {'remaining':0x80000000,'cursor':19,'result':0x13579bdf},
    {'remaining':0x80000001,'cursor':11,'result':0xffffffff},
    {'remaining':0xffffffff,'cursor':23,'result':0x2468ace0},
]
RAW = [0x11223344,0x8192a3b4,0xc3d4e5f6]
BOUNDARIES = {CORE,CLEANUP}


def read_va(image, module, va, size):
    rva = va-int(module['image_base'],16)
    sec = next(s for s in module['sections']
               if s['rva'] <= rva < s['rva']+s['raw_size'])
    return image[sec['raw_offset']+rva-sec['rva']:
                 sec['raw_offset']+rva-sec['rva']+size]


def original(module,image,case):
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,
        UC_X86_REG_ECX,UC_X86_REG_EDI,UC_X86_REG_EDX,UC_X86_REG_EIP,
        UC_X86_REG_ESI,UC_X86_REG_ESP)
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:
        if s['raw_size']:
            uc.mem_write(base+s['rva'],image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x2200000,0x10000)
    out,fmt=0x2203000,0x2204000
    uc.mem_write(out,b'X'*64); uc.mem_write(fmt,b'fmt:%08x/%08x/%08x\0')
    entry_sp=CALLER_SP-4
    uc.mem_write(entry_sp,struct.pack('<I',EXIT))
    uc.mem_write(entry_sp+4,struct.pack('<I',out)+struct.pack('<I',fmt)+struct.pack('<3I',*RAW))
    regs={'eax':UC_X86_REG_EAX,'ebx':UC_X86_REG_EBX,'ecx':UC_X86_REG_ECX,
          'edx':UC_X86_REG_EDX,'esi':UC_X86_REG_ESI,'edi':UC_X86_REG_EDI,
          'ebp':UC_X86_REG_EBP}
    seeds={'eax':0xa1a2a3a4,'ebx':0xb1b2b3b4,'ecx':0xc1c2c3c4,
           'edx':0xd1d2d3d4,'esi':0xe1e2e3e4,'edi':0xf1f2f3f4,'ebp':0x1718191a}
    for k,r in regs.items(): uc.reg_write(r,seeds[k])
    uc.reg_write(UC_X86_REG_ESP,entry_sp)
    events=[]
    def word(a): return struct.unpack('<I',uc.mem_read(a,4))[0]
    def ret(eax=None):
        sp=uc.reg_read(UC_X86_REG_ESP); target=word(sp)
        if eax is not None: uc.reg_write(UC_X86_REG_EAX,eax&0xffffffff)
        uc.reg_write(UC_X86_REG_ESP,sp+4); uc.reg_write(UC_X86_REG_EIP,target)
    def hook(m,address,_size,_user):
        if address==EXIT: m.emu_stop(); return
        if address not in BOUNDARIES: return
        sp=m.reg_read(UC_X86_REG_ESP)
        if address==CORE:
            desc,fmtp,argp=word(sp+4),word(sp+8),word(sp+12)
            initial=[word(desc+i) for i in (0,4,8,12)]
            assert initial[0]==out and initial[1]==0x7fffffff and initial[2]==out and initial[3]==0x42
            assert word(argp)==RAW[0] and word(argp+4)==RAW[1] and word(argp+8)==RAW[2]
            m.mem_write(desc,struct.pack('<I',out+case['cursor']))
            m.mem_write(desc+4,struct.pack('<I',case['remaining']))
            events.append({'core':{'format_ok':1,'raw':RAW,
                'initial_remaining':initial[1],'initial_cursor_offset':0,
                'initial_base_offset':0,'initial_flags':initial[3]}})
            ret(case['result'])
        else:
            zero,desc=word(sp+4),word(sp+8)
            state=[word(desc+i) for i in (0,4,8,12)]
            events.append({'cleanup':{'zero':zero,'remaining':state[1],
                'cursor_offset':state[0]-out,'base_offset':state[2]-out,'flags':state[3]}})
            ret(0x55667788)
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(START,0,count=200)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT: raise AssertionError('original failed to return')
    after=uc.mem_read(out,64)
    zeros=[i for i,b in enumerate(after) if b==0]
    state={'core_calls':sum('core' in e for e in events),
        'initial_remaining':0x7fffffff,'initial_cursor_offset':0,'initial_base_offset':0,
        'initial_flags':0x42,'format_ok':1,'raw':RAW,'cleanup_calls':sum('cleanup' in e for e in events),
        'cleanup_zero':0xffffffff,'cleanup_remaining':0,'cleanup_cursor_offset':0,
        'cleanup_base_offset':0,'cleanup_flags':0,'result':case['result']&0xffffffff,
        'clear_offsets':zeros,'esp_delta':uc.reg_read(UC_X86_REG_ESP)-CALLER_SP,
        'preserved':[seeds[k] for k in ('ebx','esi','edi','ebp')]}
    core=next(e['core'] for e in events if 'core' in e)
    state.update(core)
    rem=(case['remaining']-1)&0xffffffff
    if rem&0x80000000:
        c=next(e['cleanup'] for e in events if 'cleanup' in e)
        state.update({'cleanup_calls':1,'cleanup_zero':c['zero'],
            'cleanup_remaining':c['remaining'],'cleanup_cursor_offset':c['cursor_offset'],
            'cleanup_base_offset':c['base_offset'],'cleanup_flags':c['flags']})
    else:
        state['clear_offsets']=[case['cursor']]
    return state


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--probe',type=Path,required=True)
    ap.add_argument('--report-dir',type=Path,required=True)
    a=ap.parse_args(); a.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(json.loads(x) for x in (ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()
                if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA: raise AssertionError('original SHA mismatch')
    body=read_va(image,module,START,SIZE)
    if len(body)!=SIZE: raise AssertionError('entry body not raw-backed')
    index_dir=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    functions=[json.loads(x) for x in (index_dir/'functions.jsonl').read_text().splitlines()]
    calls=[json.loads(x) for x in (index_dir/'calls.jsonl').read_text().splitlines()]
    indexed={f['entry_va']:f for f in functions if f['entry_va'] in
             {'005a0fbf','005a4371','005a4259'}}
    incoming=sum(c['to_va']=='005a0fbf' for c in calls)
    outgoing=[c for c in calls if c.get('from_function')=='005a0fbf' or
              c['from_va'] in {'005a0fe8','005a1005'}]
    if set(indexed)!={'005a0fbf','005a4371','005a4259'} or incoming!=584:
        raise AssertionError('binary index coverage/call evidence changed')
    native=[json.loads(x) for x in subprocess.run([str(a.probe)],text=True,capture_output=True,check=True).stdout.splitlines()]
    if len(native)!=len(CASES): raise AssertionError('native case count mismatch')
    cases=[]
    for i,(c,n) in enumerate(zip(CASES,native)):
        o=original(module,image,c)
        actual={'core_calls':n['core_calls'],'initial_remaining':n['initial_remaining'],
            'initial_cursor_offset':n['initial_cursor_offset'],'initial_base_offset':n['initial_base_offset'],
            'initial_flags':n['initial_flags'],'format_ok':n['format_ok'],'raw':n['raw'],
            'cleanup_calls':n['cleanup_calls'],'cleanup_zero':n['cleanup_zero'],
            'cleanup_remaining':n['cleanup_remaining'],'cleanup_cursor_offset':n['cleanup_cursor_offset'],
            'cleanup_base_offset':n['cleanup_base_offset'],'cleanup_flags':n['cleanup_flags'],
            'result':n['result'],'clear_offsets':n['clear_offsets'],
            'esp_delta':n['after_sp']-n['before_sp'],'preserved':n['saved']}
        for k,v in o.items():
            if actual.get(k)!=v: raise AssertionError(f'case {i} {k}: original={v!r} native={actual.get(k)!r}')
        expected_branch='cleanup' if ((c['remaining']-1)&0xffffffff)>=0x80000000 else 'clear-current-cursor'
        cases.append({'case':i,'core_remaining':c['remaining'],'core_cursor_offset':c['cursor'],
            'return_bits':c['result'],'branch':expected_branch,'return_state_and_order_equal':True,
            'native_stack_delta':actual['esp_delta'],'raw_va_words_equal':True})
    base='iterations/v2/001-original-recovery/source/'
    tus=[base+'recovered/formatter_entry_probe.cpp',base+'recovered/Porsche.exe/formatter_entry.cpp']
    pinned=[base+'include/porsche/formatter_entry.hpp',*tus,
        'iterations/v2/001-original-recovery/runs/108-formatter-entry/CMakeLists.txt',
        'iterations/v2/001-original-recovery/runs/108-formatter-entry/README.md',
        'scripts/research/verify-v2-formatter-entry.py']
    report={'schema':1,'module':'Porsche.exe','module_sha256':SHA,'sha256':SHA,'function_vas':['005a0fbf'],
        'full_function_vas':['005a0fbf'],'partial_function_vas':[], 'cases':len(cases),
        'native_cpp_equal_original_x86':True,
        'original_function':{'va':'005a0fbf','body_bytes':SIZE,'body_sha256':hashlib.sha256(body).hexdigest(),
            'callees':['005a4371','005a4259']},
        'binary_index_evidence':{'index':'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d',
            'incoming_direct_calls':incoming,
            'functions':{va:{'body_bytes':indexed[va]['body_bytes'],'range':indexed[va]['ranges'][0]}
                for va in ('005a0fbf','005a4371','005a4259')},
            'outgoing_direct_calls':[{'from':c['from_va'],'to':c['to_va']} for c in outgoing],
            'index_sha256':{name:hashlib.sha256((index_dir/name).read_bytes()).hexdigest()
                for name in ('functions.jsonl','calls.jsonl')}},
        'abi':{'entry':'int32 __cdecl(char* output,const char* format,...)',
            'raw_adapter':'int32 __cdecl(char*,const char*,const uint32_t* raw_stack_args)',
            'stack_arguments':['return','output','format','raw variadic DWORDs'],
            'descriptor_offsets':{'cursor':0,'signed_remaining':4,'base':8,'flags':12},
            'cleanup':'caller cleans 12 bytes passed to 005a4371; wrapper returns with caller stack unchanged'},
        'semantics':{'initial_descriptor':['output','0x7fffffff','output','0x42'],
            'flow':['005a4371(descriptor,format,EBP+0x10 raw varargs)','DEC descriptor.remaining','JS cleanup or clear *descriptor.cursor','return core EAX'],
            'clear_target':'current descriptor cursor after core mutation, not necessarily output[0]',
            'cleanup_args':['0','descriptor']},
        'boundaries':{'005a4371':'unrecovered formatting core; test fixture records raw words and mutates descriptor under explicit case script',
            '005a4259':'unrecovered cleanup/error helper; fixture records incoming descriptor and zero; effects are not claimed'},
        'cases_summary':cases,'compiled_translation_units':tus,
        'source_sha256':source_hashes([ROOT/p for p in pinned]),
        'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),'game_launch_verified':False}
    (a.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({'cases':len(cases),'function_vas':report['function_vas'],
        'native_cpp_equal_original_x86':True}))

if __name__=='__main__': main()
