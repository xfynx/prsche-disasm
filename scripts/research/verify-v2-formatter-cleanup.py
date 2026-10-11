"""Differentially verify the original 005a4259 cleanup routine and bridge."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE, MEM, EXIT = 0x400000, 0x2200000, 0x220f000
OUT, DESC, BANK, COUNT, INVALID = MEM+0x4000, MEM+0x2000, MEM+0x7000, MEM+0x3000, 0x5e5f50
EMIT, CLEANUP = 0x5a4ab2, 0x5a4259
CASES = [
    ('early_zero_flags',0,7,0x141,32,0,0,9,2,8,1,False,False,False),
    ('early_42_wrapper',0x42,0xffffffff,ord('Q'),32,0,0,100,1,9,1,False,False,False),
    ('flag1_without10',1,2,ord('!'),32,0,0,12,3,6,1,False,False,False),
    ('flag1_with10_reset',0x11,3,ord('R'),32,0,0,8,3,7,1,False,False,False),
    ('ordinary_direct_success',2,4,0x1a3,32,0,0,7,1,6,1,False,False,False),
    ('ordinary_direct_short',2,5,ord('S'),32,0,0,7,0,6,0,False,False,False),
    ('ordinary_direct_negative',0x80,6,ord('T'),32,0,0,7,0,6,-1,False,False,False),
    ('special_a_character_handle',2,3,ord('A'),32,0x40,0,5,0,6,1,True,False,False),
    ('special_b_noncharacter_handle',2,4,ord('B'),32,0,0,5,0,6,1,False,True,False),
    ('special_out_of_range',2,32,ord('C'),32,0x40,0,5,0,6,1,True,False,False),
    ('flag4_prepare_boundary',4,2,ord('D'),32,0,0,5,0,6,1,False,False,False),
    ('buffer_write_success',8,7,ord('N'),32,0,0,11,3,16,3,False,False,False),
    ('buffer_write_short',8,8,ord('O'),32,0,0,11,3,16,2,False,False,False),
    ('buffer_write_failure',0x108,9,ord('P'),32,0,0,11,2,16,-1,False,False,False),
    ('buffer_empty_aux',8,0xffffffff,ord('E'),32,0,0x20,11,0,16,0,False,False,False),
    ('buffer_empty_no_aux',8,0xffffffff,ord('F'),32,0,0,11,0,16,0,False,False,False),
    ('buffer_empty_nonnegative_id',8,2,ord('G'),32,0x20,0,11,0,16,0,False,False,False),
    ('buffer_empty_signed_bank_negative',8,0xfffffffe,ord('M'),32,0x20,0,11,0,16,0,False,False,False),
    ('buffer_size_zero_wrap',8,10,ord('H'),32,0,0,11,0,0,0,False,False,False),
    ('early40_flag',0x40,11,ord('I'),32,0,0,11,1,16,1,False,False,False),
    ('emitter_cleanup_bridge',0x42,12,ord('J'),32,0,0,0,0,16,1,False,False,True),
    ('prepare_mutates_to_buffer',2,4,ord('L'),32,0,0,5,0,8,1,False,False,False),
    ('prepare_aux_mutates_base',2,4,ord('M'),32,0x20,0,5,0,8,0,False,False,False),
]


def read_va(image, module, va, size):
    rva=va-int(module['image_base'],16)
    section=next(s for s in module['sections'] if s['rva']<=rva and rva+size<=s['rva']+s['raw_size'])
    return image[section['raw_offset']+rva-section['rva']:section['raw_offset']+rva-section['rva']+size]


def signed(bits):
    return struct.unpack('<i',struct.pack('<I',bits&0xffffffff))[0]


def setup_descriptor(uc, case):
    name,flags,file_id,ch,limit,handle_flags,invalid_flags,remaining,cursor,bufsize,write_ret,special_a,special_b,through=case
    special=0x5e5508 if special_a else (0x5e5528 if special_b else DESC)
    output=bytes((0x40+i)&0xff for i in range(64))
    tail=struct.pack('<4I',file_id,0x14151617,bufsize&0xffffffff,0x1c1d1e1f)
    uc.mem_write(OUT,output)
    uc.mem_write(special,struct.pack('<4I',OUT+cursor,remaining,OUT,flags)+tail)
    uc.mem_write(0x6c02e0,struct.pack('<I',limit))  # zero-filled virtual BSS state, seeded for this fixture
    uc.mem_write(0x6c01dc,struct.pack('<I',BANK))
    uc.mem_write(0x6c01e0,struct.pack('<I',BANK))
    uc.mem_write(0x6c01e4,struct.pack('<I',BANK+32*36))
    uc.mem_write(BANK,b'\0'*(64*36))
    if file_id<64:
        uc.mem_write(BANK+((file_id&31)*36)+4,bytes([handle_flags&0xff]))
        if file_id>=32:
            uc.mem_write(BANK+32*36+((file_id&31)*36)+4,bytes([handle_flags&0xff]))
    if file_id==0xfffffffe:
        uc.mem_write(BANK+30*36+4,bytes([handle_flags&0xff]))
    uc.mem_write(INVALID+4,bytes([invalid_flags&0xff]))
    return special,output,tail


def run_original(module,image,case):
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,
        UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_ESI,UC_X86_REG_EDI)
    uc=Uc(UC_ARCH_X86,UC_MODE_32);uc.mem_map(BASE,0x300000)
    for s in module['sections']:
        if s['raw_size']:uc.mem_write(BASE+s['rva'],image[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(MEM,0x10000)
    name,flags,file_id,ch,limit,handle_flags,invalid_flags,remaining,cursor,bufsize,write_ret,special_a,special_b,through=case
    special,initial_output,tail=setup_descriptor(uc,case)
    if through:
        uc.mem_write(COUNT,struct.pack('<i',0))
        stack=MEM+0xe000-16
        uc.mem_write(stack,struct.pack('<4I',EXIT,ch,special,COUNT))
        start=EMIT
    else:
        stack=MEM+0xe000-12
        uc.mem_write(stack,struct.pack('<3I',EXIT,ch,special))
        start=CLEANUP
    regs={'eax':UC_X86_REG_EAX,'ebx':UC_X86_REG_EBX,'esi':UC_X86_REG_ESI,'edi':UC_X86_REG_EDI,
          'ebp':UC_X86_REG_EBP,'esp':UC_X86_REG_ESP}
    seeds={'eax':0xa1a2a3a4,'ebx':0xb1b2b3b4,'esi':0xe1e2e3e4,'edi':0xf1f2f3f4,'ebp':0x1718191a}
    for k,v in seeds.items():uc.reg_write(regs[k],v)
    uc.reg_write(regs['esp'],stack)
    trace={'write_calls':0,'write_file':0,'write_length':0,'write_bytes':'',
           'aux_calls':0,'aux_file':0,'aux_offset':0,'aux_origin':0,
           'prepare_calls':0,'prepare_file':0,'prepare_flags':0,'events':[]}
    def finish(m,ret):
        sp=m.reg_read(UC_X86_REG_ESP);retaddr=struct.unpack('<I',m.mem_read(sp,4))[0]
        m.reg_write(UC_X86_REG_EAX,ret);m.reg_write(UC_X86_REG_ESP,sp+4);m.reg_write(UC_X86_REG_EIP,retaddr)
    def hook(m,addr,_size,_data):
        if addr==EXIT:m.emu_stop();return
        sp=m.reg_read(UC_X86_REG_ESP)
        if addr==0x5a9e49:
            _,file,pointer,length=struct.unpack('<4I',m.mem_read(sp,16))
            trace.update(write_calls=trace['write_calls']+1,write_file=file,write_length=length,
                write_bytes=bytes(m.mem_read(pointer,min(length,64))).hex())
            trace['events'].append(2)
            if name=='prepare_mutates_to_buffer':
                m.mem_write(special+8,struct.pack('<I',OUT+12))
            finish(m,write_ret);return
        if addr==0x5a9ab8:
            _,file,offset,origin=struct.unpack('<4I',m.mem_read(sp,16))
            trace.update(aux_calls=trace['aux_calls']+1,aux_file=file,aux_offset=offset,aux_origin=origin)
            trace['events'].append(3)
            if name=='prepare_aux_mutates_base':
                m.mem_write(special+8,struct.pack('<I',OUT+13))
            finish(m,0);return
        if addr==0x5abef1:
            _,descriptor=struct.unpack('<2I',m.mem_read(sp,8))
            dflags=struct.unpack('<I',m.mem_read(descriptor+12,4))[0]
            dfile=struct.unpack('<I',m.mem_read(descriptor+16,4))[0]
            trace.update(prepare_calls=trace['prepare_calls']+1,prepare_file=dfile,prepare_flags=dflags)
            trace['events'].append(1)
            if name=='prepare_mutates_to_buffer':
                m.mem_write(descriptor+12,struct.pack('<I',8))
                m.mem_write(descriptor+8,struct.pack('<I',OUT+4))
                m.mem_write(descriptor,struct.pack('<I',OUT+5))
                m.mem_write(descriptor+24,struct.pack('<I',5))
            elif name=='prepare_aux_mutates_base':
                m.mem_write(descriptor+12,struct.pack('<I',8))
                m.mem_write(descriptor+8,struct.pack('<I',OUT+5))
                m.mem_write(descriptor,struct.pack('<I',OUT+5))
                m.mem_write(descriptor+24,struct.pack('<I',10))
            finish(m,0);return
    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(start,0,count=100000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:raise AssertionError(f'{name}: oracle failed to return at {uc.reg_read(UC_X86_REG_EIP):08x}')
    dbytes=bytes(uc.mem_read(special,32));cur,rem,base,df=struct.unpack('<4I',dbytes[:16])
    result=signed(uc.reg_read(UC_X86_REG_EAX))
    count=signed(struct.unpack('<I',uc.mem_read(COUNT,4))[0]) if through else 0
    out=bytes(uc.mem_read(OUT,16)).hex()
    return {'case':name,'result':count if through else result,'count':count,
        'cursor_offset':signed(cur-OUT),'base_offset':signed(base-OUT),'remaining':signed(rem),'flags':df,
        'descriptor_tail':dbytes[16:].hex(),'output':out,**trace,
        'caller_stack_ok':uc.reg_read(UC_X86_REG_ESP)==stack+4,
        'callee_saved_ok':[uc.reg_read(regs[k]) for k in ('ebx','esi','edi','ebp')]==[seeds[k] for k in ('ebx','esi','edi','ebp')],
        'eax_is_count_pointer':not through or uc.reg_read(UC_X86_REG_EAX)==COUNT}


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--probe',type=Path,required=True);ap.add_argument('--report-dir',type=Path,required=True);a=ap.parse_args()
    a.report_dir.mkdir(parents=True,exist_ok=True)
    index=ROOT/'research/binary-index/static/binaries.jsonl'
    module=next(json.loads(x) for x in index.read_text().splitlines() if json.loads(x)['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA:raise AssertionError('Porsche.exe SHA mismatch')
    expected=[run_original(module,image,c) for c in CASES]
    actual=[json.loads(x) for x in subprocess.run([str(a.probe)],text=True,capture_output=True,check=True).stdout.splitlines()]
    if len(actual)!=len(expected):raise AssertionError('cleanup case count differs')
    keys=('case','result','count','cursor_offset','base_offset','remaining','flags','descriptor_tail','output','write_calls','write_file','write_length','write_bytes',
          'aux_calls','aux_file','aux_offset','aux_origin','prepare_calls','prepare_file','prepare_flags','events')
    for o,n in zip(expected,actual):
        for key in keys:
            if o[key]!=n[key]:raise AssertionError(f'{o["case"]} {key}: original={o[key]!r}, native={n[key]!r}')
        if not o['caller_stack_ok'] or not o['callee_saved_ok'] or not o['eax_is_count_pointer']:
            raise AssertionError(f'{o["case"]}: x86 ABI/register proof failed')
    ix=ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d'
    funcs={json.loads(x)['entry_va']:json.loads(x) for x in (ix/'functions.jsonl').read_text().splitlines()}
    calls=[json.loads(x) for x in (ix/'calls.jsonl').read_text().splitlines()]
    required={'005a4259':280,'005a9e49':101,'005a9ab8':101,'005abef1':68,'005abf35':41}
    bodies={}
    for va,size in required.items():
        if funcs.get(va,{}).get('body_bytes')!=size:raise AssertionError(f'indexed body size changed at {va}')
        body=read_va(image,module,int(va,16),size)
        bodies[va]={'bytes':size,'sha256':hashlib.sha256(body).hexdigest()}
    cleanup_calls=[c for c in calls if c.get('from_function')=='005a4259']
    direct_callers=[{'from_function':c.get('from_function'),'call_va':c.get('from_va')} for c in calls if c.get('to_va')=='005a4259']
    asm=ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm'
    source='iterations/v2/001-original-recovery/source/'
    files=[source+'include/porsche/formatter_cleanup.hpp',source+'recovered/Porsche.exe/formatter_cleanup.cpp',
      source+'recovered/formatter_cleanup_probe.cpp',source+'include/porsche/formatter_original.hpp',
      source+'recovered/Porsche.exe/formatter_original.cpp',
      'iterations/v2/001-original-recovery/runs/132-formatter-cleanup/CMakeLists.txt',
      'iterations/v2/001-original-recovery/runs/132-formatter-cleanup/README.md',
      'scripts/research/verify-v2-formatter-cleanup.py']
    data=next(s for s in module['sections'] if s['name']=='.data')
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,'function_va':'005a4259','body_bytes':280,
      'cases':len(expected),'case_results':expected,'full_function_vas':['005a4259','005abf35'],
      'callee_body_hashes':bodies,'cleanup_outgoing_call_sites':[{'from':c['from_va'],'to':c['to_va']} for c in cleanup_calls],
      'indexed_direct_callers':direct_callers,
      'descriptor':{'size':32,'offsets':{'cursor':0,'remaining':4,'base':8,'flags':12,'file_id':16,'opaque_14':20,'buffer_size':24,'opaque_1c':28},
        'evidence':'005a4259 loads +0xc and +0x10 on entry; 005abef1 writes +0x8/+0xc/+0x18/+0x4/+0x0; cleanup reads +0x18 only under flags&0x108; +0x14/+0x1c are preserved opaque words'},
      'pe_mapping':{'data_rva':data['rva'],'data_raw_size':data['raw_size'],'data_virtual_size':data['vsize'],
        'handle_table_va':'006c01e0','handle_limit_va':'006c02e0','handle_globals_in_virtual_zero_fill':True,
        'note':'Oracle seeds BSS globals after mapping; it does not read file bytes at VA-ImageBase for zero-filled state'},
      'boundaries':{'005a9e49':'typed file-write boundary; calls/arguments/payload and selected return are checked; actual file backend unresolved',
        '005a9ab8':'typed auxiliary file operation; exact three stack arguments and order checked; external state effects unresolved',
        '005abef1':'typed descriptor initialization/allocation boundary; descriptor pointer and pre-call flags/file id checked; allocator effects unresolved',
        'descriptor_identity':'native pointer aliases must bind original stream objects 005e5508 and 005e5528; this packet does not define those stream owners'},
      'source_sha256':source_hashes([ROOT/p for p in files],compiled_sources=[ROOT/(source+'recovered/formatter_cleanup_probe.cpp'),ROOT/(source+'recovered/Porsche.exe/formatter_cleanup.cpp'),ROOT/(source+'recovered/Porsche.exe/formatter_original.cpp')]),
      'compiled_translation_units':[source+'recovered/formatter_cleanup_probe.cpp',source+'recovered/Porsche.exe/formatter_cleanup.cpp',source+'recovered/Porsche.exe/formatter_original.cpp'],
      'disassembly_sha256':hashlib.sha256(asm.read_bytes()).hexdigest(),'functions_index_sha256':hashlib.sha256((ix/'functions.jsonl').read_bytes()).hexdigest(),
      'calls_index_sha256':hashlib.sha256((ix/'calls.jsonl').read_bytes()).hexdigest(),'probe_sha256':hashlib.sha256(a.probe.read_bytes()).hexdigest(),
      'native_cpp_equal_original_x86':True,'game_launch_verified':False}
    (a.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'cases':len(expected),'cleanup_bytes':280,'native_cpp_equal_original_x86':True,'game_launch_verified':False}))

if __name__=='__main__':main()
