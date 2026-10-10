"""Differentially compare frame service helpers 004ab150/004ab200 with x86."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
SHA='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
BASE,START150,START200=0x400000,0x4ab150,0x4ab200
SIZE150,SIZE200=0xa8,0x6a
ARENA,RECORDS,FLAGS,SCALE,RENDER=0x6573e8,0x656180,0x656868,0x5d14b0,0x5d1740
STACK,EXIT=0x221f000,0x222f000
BOUNDARY={name:0x222f100+i*4 for i,name in enumerate(
    ('af900','66340','ae3c0','65cd0','ad510','ae8c0','ae4d0','noop'))}
IDS={name:i+1 for i,name in enumerate(
    ('af900','66340','ae3c0','65cd0','ad510','ae8c0','ae4d0','noop'))}


def cases():
    rows=[
      # op, gate, flags, flag after 4ae3c0, multiplier, records0/2, app5, render5, 4ad510 output5, 4ae4d0 output5
      [0,0,0x22,0x33,0,0x50,0xffffffff,0xffffffff,
       [0x101,0x202,0x303,0x404,0x505],[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15]],
      [0,0,0x44,0x55,1,0x50,0x11111111,0,
       [0x1001,0x1002,0x1003,0x1004,0x1005],[21,22,23,24,25],[31,32,33,34,35],[41,42,43,44,45]],
      [0,0x87654321,0x66,0x77,1,0x50,0,1,
       [0x2001,0x2002,0x2003,0x2004,0x2005],[51,52,53,54,55],[61,62,63,64,65],[71,72,73,74,75]],
      [1,0,0x12,0x34,0,0xffffffff,0,0,
       [0x301,0x302,0x303,0x304,0x305],[0x7f,0x7f,0x7f,0x7f,0x7f],[81,82,83,84,85],[91,92,93,94,95]],
      [1,0,0x56,0x78,0,0x40000000,0,0,
       [0x401,0x402,0x403,0x404,0x405],[0xfffffffe,0x11,0x22,0x33,0x44],[101,102,103,104,105],[0xabcdef01,0xabcdef02,0xabcdef03,0xabcdef04,0xabcdef05]],
      [1,0,0x9a,0xbc,0,0x50,0,0,
       [0x501,0x502,0x503,0x504,0x505],[0x7f,0x7f,0x7f,0x7f,0x7f],[111,112,113,114,115],[121,122,123,124,125]],
      [1,0x80000001,0xde,0xad,0,0x12345678,0,0,
       [0x601,0x602,0x603,0x604,0x605],[0x10203040,0x11223344,0x55667788,0x99aabbcc,0xddeeff00],[131,132,133,134,135],[141,142,143,144,145]],
    ]
    result=[]
    for row in rows:
        op,gate,f68,f69,post,scale,rec0,rec2,app,render,save,restore=row
        values=[op,gate,f68,f69,post,scale,rec0,rec2,*app,*render,*save,*restore]
        assert len(values)==28
        result.append({'values':[x&0xffffffff for x in values]})
    return result


def initial_records(case):
    words=[0xffffffff]*146
    for i in range(73): words[i*2+1]=0xa0000000+i
    values=case['values']
    words[0],words[4]=values[6],values[7]
    return words


def original(module,image,case):
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP,UC_X86_REG_ESI
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    uc.mem_map(BASE,0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(BASE+section['rva'],image[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2200000,0x30000)
    def put(addr,value): uc.mem_write(addr,struct.pack('<I',value&0xffffffff))
    def word(addr): return struct.unpack('<I',uc.mem_read(addr,4))[0]
    v=case['values']; op,gate,f68,f69,post,scale,rec0,rec2=v[:8]
    uc.mem_write(RECORDS,struct.pack('<146I',*initial_records(case)))
    uc.mem_write(FLAGS,bytes((f68&0xff,f69&0xff)))
    put(SCALE,scale)
    for i,value in enumerate(v[13:18]): put(RENDER+i*4,value)
    put(ARENA+(0x657c94-0x6573e8),gate)
    for i,value in enumerate(v[8:13]): put(ARENA+(0x657ca0-0x6573e8)+i*4,value)
    put(STACK,EXIT)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.reg_write(UC_X86_REG_ESI,0x13572468)
    names={BOUNDARY[k]:k for k in BOUNDARY}
    direct={0x4af900:'af900',0x566340:'66340',0x4ae3c0:'ae3c0',
            0x565cd0:'65cd0',0x4ad510:'ad510',0x4ae8c0:'ae8c0',
            0x4ae4d0:'ae4d0',0x516950:'noop'}
    trace=[]
    def hook(machine,address,_size,_user):
        if address==EXIT:
            machine.emu_stop(); return
        if address in (START150,START200) or (START150<=address<START150+SIZE150) or (START200<=address<START200+SIZE200):
            return
        key=names.get(address) or direct.get(address)
        if key is None: raise RuntimeError(f'unexpected x86 call {address:08x}; trace={trace}')
        sp=machine.reg_read(UC_X86_REG_ESP)
        argc={'af900':2,'66340':2,'ae3c0':1,'65cd0':2,'ae8c0':1,'ae4d0':2}.get(key,0)
        args=[word(sp+4+4*i) for i in range(argc)]
        trace.append([IDS[key],*(args+[0]*max(0,2-len(args)))])
        if key=='ae3c0':
            machine.mem_write(FLAGS,bytes((v[4]&0xff,)))
        elif key=='ad510':
            for i,value in enumerate(v[18:23]): put(RENDER+i*4,value)
        elif key=='ae4d0':
            for i,value in enumerate(v[23:28]): put(RENDER+i*4,value)
        ret=word(sp)
        machine.reg_write(UC_X86_REG_ESP,sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    start=START150 if op==0 else START200
    try: uc.emu_start(start,EXIT+1,count=10000)
    except Exception as error: raise RuntimeError(f'x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x}; {trace}') from error
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT: raise AssertionError('x86 function did not return')
    records=list(struct.unpack('<146I',uc.mem_read(RECORDS,584)))
    flags=list(uc.mem_read(FLAGS,2))
    render=[word(RENDER+i*4) for i in range(5)]
    arena=[word(ARENA+(0x657c94-0x6573e8))]
    arena += [word(ARENA+(0x657ca0-0x6573e8)+i*4) for i in range(5)]
    return {'return':uc.reg_read(UC_X86_REG_EAX),'trace':trace,'records':records,
      'flags':flags,'scale':word(SCALE),'render':render,'arena':arena,
      'entry_stack_restored':uc.reg_read(UC_X86_REG_ESP)==STACK+4,
      'esi_restored':uc.reg_read(UC_X86_REG_ESI)==0x13572468}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/frame-services-105/bin/Release/frame_services_probe.exe')
    parser.add_argument('--report-dir',type=Path,required=True)
    args=parser.parse_args(); args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA: raise AssertionError('frozen executable hash mismatch')
    inputs=cases()
    stdin=''.join(' '.join(map(str,c['values']))+'\n' for c in inputs)
    run=subprocess.run([str(args.probe)],input=stdin,text=True,capture_output=True,check=True)
    actuals=[json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals)!=len(inputs): raise AssertionError(f'native returned {len(actuals)} rows, expected {len(inputs)}')
    summaries=[]
    for i,(case,actual) in enumerate(zip(inputs,actuals)):
        expected=original(module,image,case)
        if not expected['entry_stack_restored'] or not expected['esi_restored']:
            raise AssertionError(f'x86 ABI mismatch case {i}: {expected}')
        comparable={k:expected[k] for k in ('return','trace','records','flags','scale','render','arena')}
        if actual!=comparable: raise AssertionError(f'case {i}: x86={comparable}; native={actual}')
        summaries.append({'index':i,'function':'004ab150' if case['values'][0]==0 else '004ab200',
          'gate_nonzero':case['values'][1]!=0,'boundary_calls':len(expected['trace'])})
    source_paths=[
      'iterations/v2/001-original-recovery/source/include/porsche/frame_services.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_services.cpp',
      'iterations/v2/001-original-recovery/source/recovered/frame_services_probe.cpp',
      'scripts/research/verify-v2-frame-services.py',
      'iterations/v2/001-original-recovery/runs/105-frame-services/CMakeLists.txt',
      'iterations/v2/001-original-recovery/runs/105-frame-services/README.md']
    function_vas=['004ab150','004ab200']
    hashes={}
    for start,size in ((START150,SIZE150),(START200,SIZE200)):
        rva=start-BASE
        section=next(s for s in module['sections'] if s['rva']<=rva<s['rva']+s['raw_size'])
        offset=section['raw_offset']+rva-section['rva']
        hashes[f'{start:08x}']=hashlib.sha256(image[offset:offset+size]).hexdigest()
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,
      'function_vas':function_vas,'full_function_vas':function_vas,'partial_function_vas':[],
      'cases':len(inputs),'native_cpp_equal_original_x86':True,
      'comparison_boundary':'Complete 004ab150/004ab200 bodies; 73 raw record pairs, two flags, 005d14b0, five renderer DWORDs, five shared ApplicationStateArena DWORDs, return EAX, call args/order, ESI and x86 return stack.',
      'caller_vas':['00415110','004152e0','004b0d70'],
      'global_vas':['00656180','00656868','00656869','00657c94','00657ca0','00657ca4','00657ca8','00657cac','00657cb0','005d14b0','005d1740','005d1744','005d1748','005d174c','005d1750'],
      'original_functions':[{'va':'004ab150','body_bytes':SIZE150,'body_sha256':hashes['004ab150']},{'va':'004ab200','body_bytes':SIZE200,'body_sha256':hashes['004ab200']}],
      'cases_summary':summaries,
      'source_sha256':source_hashes([ROOT/p for p in source_paths],compiled_sources=[
        ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_services.cpp',
        ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp',
        ROOT/'iterations/v2/001-original-recovery/source/recovered/frame_services_probe.cpp'])}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({k:report[k] for k in ('sha256','function_vas','full_function_vas','partial_function_vas','cases','native_cpp_equal_original_x86')}))

if __name__=='__main__': main()
