"""Differentially compare the recovered 004b0d70 frame-pump body with x86."""
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
START, SIZE = 0x4b0d70, 0x13e
BASE, STACK, EXIT = 0x400000, 0x221f000, 0x222f000
ARENA = 0x6573b8
TICK = 0x655a08
SERVICE_CELL = 0x69ed0c
BOUNDARY = {
    'shutdown':0x222f100, 'ab150':0x222f104, 'notify':0x222f108,
    'flush':0x222f10c, 'setstate':0x222f110, 'window':0x222f114,
    'clear':0x222f118, 'update':0x222f11c, 'sync':0x222f120,
    'slot20':0x222f124, 'slot1c':0x222f128, 'service_start':0x222f12c,
    'service_end':0x222f130, 'ab200':0x222f134, 'arg_service':0x222f138,
}
IDS = {'shutdown':1,'ab150':2,'notify':3,'flush':4,'setstate':5,'window':6,
       'clear':7,'update':8,'sync':9,'slot20':10,'slot1c':11,
       'service_start':12,'service_end':13,'ab200':14,'arg_service':15}


def u32(v): return v & 0xffffffff


def cases():
    seeds = [
        (0,0,0,0,0,0,0,0,0,0,0,0x11112222,0x1234abcd),
        (0x10203040,0x11223344,0x55667788,0x99aabbcc,0xddeeff00,0x12345678,0x87654321,0,0,1,0,0xffffffff,0xabcdef01),
        (0x10203040,0x11223344,0x55667788,0x99aabbcc,0xddeeff00,0x12345678,0x87654321,0,1,0,1,0x11223344,0xfaceb00c),
        (0x10203040,0x11223344,0x55667788,0x99aabbcc,0xddeeff00,0x12345678,0x87654321,0,1,1,1,0x11223344,0x01020304),
        (0,0,0,0,0,0,0,1,1,0,0,0xabcdef12,0x76543210),
        (0,0,0,0,0,0,0,1,1,0,1,0xabcdef12,0x76543210),
        (0,0,0,0,0,0,0,0,0,1,1,0xabcdef12,0x76543210),
        (0,0,0,0,0,0,0,1,0,1,1,0xabcdef12,0x76543210),
    ]
    return [dict(zip(('b8','bc','c0','c4','d0','d4','d8','e0','e1','e2','e4','tick','movie'), x)) for x in seeds]


def initial_arena(case):
    data = bytearray((0x40+i) & 0xff for i in range(0x30))
    for name, offset in (('b8',0),('bc',4),('c0',8),('c4',12),('d0',24),('d4',28),('d8',32)):
        data[offset:offset+4] = struct.pack('<I',u32(case[name]))
    for name, offset in (('e0',40),('e1',41),('e2',42),('e4',44)):
        data[offset] = case[name] & 0xff
    return data


def original(module, image, case):
    sys.path.insert(0, str(ROOT / 'local/tools/python-unicorn'))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_EIP,
      UC_X86_REG_ESP, UC_X86_REG_ESI)
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(BASE + section['rva'], image[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2200000, 0x30000)
    def put(addr,val): uc.mem_write(addr,struct.pack('<I',u32(val)))
    def word(addr): return struct.unpack('<I',uc.mem_read(addr,4))[0]
    uc.mem_write(ARENA,bytes(initial_arena(case)))
    put(TICK,case['tick'])
    put(SERVICE_CELL,0x2203000)
    put(0x2203000,0x2201000); put(0x2203004,0x12345678)
    put(0x2201000,0x2202000)
    put(0x220201c,BOUNDARY['slot1c']); put(0x2202020,BOUNDARY['slot20'])
    for addr,key in ((0x6bd970,'flush'),(0x6bd97c,'setstate'),(0x6bd9b0,'window'),
                     (0x6bd91c,'clear'),(0x6bd948,'update'),(0x6bd978,'sync')):
        put(addr,BOUNDARY[key])
    put(STACK,EXIT)
    uc.reg_write(UC_X86_REG_ESP,STACK)
    uc.reg_write(UC_X86_REG_ESI,0x13572468)
    trace=[]
    by_va={BOUNDARY[k]:k for k in BOUNDARY}
    direct={0x534550:'shutdown',0x4ab150:'ab150',0x5693e0:'notify',
            0x568f30:'arg_service',0x5360a0:'service_start',
            0x5363a0:'service_end',0x4ab200:'ab200'}
    def hook(machine,address,_size,_user):
        if address==EXIT:
            machine.emu_stop(); return
        if START <= address < START+SIZE:
            return
        key=by_va.get(address)
        if key is None:
            key=direct.get(address)
        if key is None:
            raise RuntimeError(f'unexpected original boundary {address:08x}; trace={trace}')
        sp=machine.reg_read(UC_X86_REG_ESP)
        argc={'setstate':2,'window':1,'sync':1,'slot1c':1,
              'service_start':1,'arg_service':6}.get(key,0)
        args=[word(sp+4+4*i) for i in range(argc)]
        if key=='slot20':
            args=[0x2201000,case['movie']]
        if key=='slot1c':
            args=[0x2201000,word(sp+4)]
        if key=='service_start':
            args=[machine.reg_read(UC_X86_REG_ECX),*args]
        if key=='service_end':
            args=[machine.reg_read(UC_X86_REG_ECX)]
        trace.append([IDS[key],*(args+[0]*max(0,6-len(args)))])
        if key=='slot20': machine.reg_write(UC_X86_REG_EAX,u32(case['movie']))
        ret=word(sp)
        cleanup=argc*4 if key in ('setstate','window','sync','slot1c','service_start') else 0
        machine.reg_write(UC_X86_REG_ESP,sp+4+cleanup)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    try: uc.emu_start(START,EXIT+1,count=10000)
    except Exception as error: raise RuntimeError(f'x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x}; {trace}') from error
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT: raise AssertionError('original did not return')
    arena=bytes(uc.mem_read(ARENA,0x30))
    flat=[word(ARENA+offset) for offset in (0,4,8,12,24,28,32)]
    flat += [arena[40],arena[41],arena[42],arena[44],word(TICK),case['movie']]
    return {'trace':trace,'state':flat,'arena':list(arena),
      'entry_stack_restored':uc.reg_read(UC_X86_REG_ESP)==STACK+4,
      'esi_restored':uc.reg_read(UC_X86_REG_ESI)==0x13572468}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--probe',type=Path,default=ROOT/'local/builds/v2/frame-pump-101/bin/Release/frame_pump_probe.exe')
    parser.add_argument('--report-dir',type=Path,required=True)
    args=parser.parse_args(); args.report_dir.mkdir(parents=True,exist_ok=True)
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    image=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(image).hexdigest()!=SHA: raise AssertionError('frozen Porsche.exe hash mismatch')
    inputs=cases()
    stdin=''.join(' '.join(str(c[k]) for k in ('b8','bc','c0','c4','d0','d4','d8','e0','e1','e2','e4','tick','movie'))+'\n' for c in inputs)
    run=subprocess.run([str(args.probe)],input=stdin,text=True,capture_output=True,check=True)
    actuals=[json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals)!=len(inputs): raise AssertionError(f'native returned {len(actuals)} rows for {len(inputs)} cases')
    for i,(case,actual) in enumerate(zip(inputs,actuals)):
        expected=original(module,image,case)
        if not expected['entry_stack_restored'] or not expected['esi_restored']:
            raise AssertionError(f'x86 ABI mismatch in case {i}: {expected}')
        comparable={k:expected[k] for k in ('trace','state','arena')}
        if actual!=comparable: raise AssertionError(f'case {i} {case}: x86={comparable}; native={actual}')
    source_paths=[
      'iterations/v2/001-original-recovery/source/include/porsche/frame_pump.hpp',
      'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_pump.cpp',
      'iterations/v2/001-original-recovery/source/recovered/frame_pump_probe.cpp',
      'scripts/research/verify-v2-frame-pump.py',
      'iterations/v2/001-original-recovery/runs/101-frame-pump/CMakeLists.txt',
      'iterations/v2/001-original-recovery/runs/101-frame-pump/README.md']
    functions=['004b0d70']
    rva=START-BASE
    section=next(s for s in module['sections'] if s['rva']<=rva<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    report={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,
      'function_vas':functions,'full_function_vas':functions,'partial_function_vas':[],
      'cases':len(inputs),'native_cpp_equal_original_x86':True,
      'comparison_boundary':'complete 004b0d70 body, all owned state bytes, tick word, indirect display/movie calls, six argument values at 00568f30, and saved ESI/return stack in x86 oracle',
      'caller_vas':['004a4a70','004b0fa0','004b67b0','004dda00'],
      'global_vas':['006573b8','006573bc','006573c0','006573c4','006573d0','006573d4','006573d8','006573e0','006573e1','006573e2','006573e4','00655a08'],
      'original_function':{'va':'004b0d70','body_bytes':SIZE,'body_sha256':hashlib.sha256(image[offset:offset+SIZE]).hexdigest()},
      'cases_summary':[{'index':i,'trace_events':len(original(module,image,c)['trace']),'e0':c['e0']&0xff,'e1':c['e1']&0xff,'e2':c['e2']&0xff,'e4':c['e4']&0xff} for i,c in enumerate(inputs)],
      'source_sha256':source_hashes([ROOT/p for p in source_paths],compiled_sources=[ROOT/'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/frame_pump.cpp',ROOT/'iterations/v2/001-original-recovery/source/recovered/frame_pump_probe.cpp'])}
    (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',newline='\n')
    print(json.dumps({k:report[k] for k in ('sha256','function_vas','full_function_vas','partial_function_vas','cases','native_cpp_equal_original_x86')}))

if __name__=='__main__': main()
