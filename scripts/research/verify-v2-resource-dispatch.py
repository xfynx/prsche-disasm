"""Differential proof for FILESYS atomic dispatcher and resource callback."""
import argparse
import hashlib
import json
import struct
import subprocess
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = 'ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
DISPATCHER, CALLBACK = 0x568d50, 0x561be0
FILE_START, ENTER, LEAVE = 0x568390, 0x5322b0, 0x5322c0
OPEN, SIZE, CLOSE, SIGNAL = 0x533b90, 0x533de0, 0x533da0, 0x55fb30
DIAGNOSTIC = 0x2205000
TABLE, CONTEXT, PATH = 0x2204000, 0x2206000, 0x2203000
EXIT, CALLER_SP = 0x2201000, 0x220f000
DEVICE_BYTES = 0x70
CASES = [
    {'device':3,'group':5,'old_group':9,'initialized':True,'table':True,'open':1,'size':0x1234},
    {'device':4,'group':2,'old_group':7,'initialized':True,'table':True,'open':0,'size':0},
    {'device':1,'group':5,'old_group':2,'initialized':True,'table':True,'open':1,'size':88},
    {'device':7,'group':0xffffffff,'old_group':0,'initialized':True,'table':True,'open':1,'size':-1},
    {'device':0xffffffff,'group':1,'old_group':0,'initialized':True,'table':True,'open':1,'size':0},
    {'device':32,'group':1,'old_group':0,'initialized':True,'table':True,'open':1,'size':0},
    {'device':2,'group':3,'old_group':0,'initialized':False,'table':True,'open':1,'size':0},
    {'device':0xffffffff,'group':1,'old_group':0,'initialized':True,'table':False,'open':1,'size':0},
]
LOCK_BASE, EVENT_BASE, HANDLE = 0x2207000, 0x2207100, 0x2209000
DIAG_FILE = '\\real\\pc\\nfile.c'
CALLBACK_DIAG_FILE = '\\real\\cmn\\hlsfile.c'


def read_va(image,module,va,size):
    rva=va-int(module['image_base'],16)
    section=next(s for s in module['sections']
                 if s['rva']<=rva<s['rva']+s['raw_size'])
    offset=section['raw_offset']+rva-section['rva']
    return image[offset:offset+size]


def original(module,image,case):
    import sys
    sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
    from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,
        UC_X86_REG_EDI,UC_X86_REG_EIP,UC_X86_REG_ESI,UC_X86_REG_ESP)
    uc=Uc(UC_ARCH_X86,UC_MODE_32)
    base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for section in module['sections']:
        if section['raw_size']:
            uc.mem_write(base+section['rva'],image[section['raw_offset']:
                section['raw_offset']+section['raw_size']])
    uc.mem_map(0x2200000,0x10000)
    uc.mem_write(PATH,b'DATA\\cars\\pic16.fsh\0')
    uc.mem_write(CONTEXT,struct.pack('<IIII',PATH,0xaaaaaaaa,0xbbbbbbbb,1))
    uc.mem_write(TABLE,b'\0'*(32*DEVICE_BYTES))
    if case['table']:
        uc.mem_write(0x6a5c7c,struct.pack('<I',TABLE))
        if case['device']<32:
            slot=TABLE+case['device']*DEVICE_BYTES
            uc.mem_write(slot,struct.pack('<I',int(case['initialized'])))
            uc.mem_write(slot+0x5c,struct.pack('<I',EVENT_BASE+case['device']*4))
            uc.mem_write(slot+0x60,struct.pack('<I',LOCK_BASE+case['device']*4))
            uc.mem_write(slot+0x6c,struct.pack('<I',case['old_group']))
    else:
        uc.mem_write(0x6a5c7c,b'\0'*4)
    uc.mem_write(0x5debf0,struct.pack('<I',DIAGNOSTIC))
    uc.mem_write(0x5deb74,struct.pack('<I',0))
    uc.mem_write(0x5deb78,struct.pack('<I',0))
    uc.mem_write(CALLER_SP-4,struct.pack('<I',EXIT))
    for offset,value in ((0, CALLBACK),(4,case['device']),
                         (8,case['group']),(12,CONTEXT)):
        uc.mem_write(CALLER_SP+offset,struct.pack('<I',value))
    sentinel_regs=((UC_X86_REG_EAX,0xa1a2a3a4),(UC_X86_REG_EBX,0xb1b2b3b4),
        (UC_X86_REG_EBP,0x1718191a),(UC_X86_REG_ESI,0xe1e2e3e4),
        (UC_X86_REG_EDI,0xd1d2d3d4))
    for reg,value in sentinel_regs: uc.reg_write(reg,value)
    uc.reg_write(UC_X86_REG_ESP,CALLER_SP-4)
    events=[]

    def u32(address):
        return struct.unpack('<I',uc.mem_read(address,4))[0]

    def cstr(address):
        output=bytearray()
        for _ in range(512):
            byte=uc.mem_read(address,1)[0]
            if byte==0: return output.decode('ascii')
            output.append(byte);address+=1
        raise AssertionError(f'unterminated string at {address:08x}')

    def signed(value):
        return struct.unpack('<i',struct.pack('<I',value & 0xffffffff))[0]

    def ret(eax=None):
        esp=uc.reg_read(UC_X86_REG_ESP)
        dst=u32(esp)
        if eax is not None: uc.reg_write(UC_X86_REG_EAX,eax & 0xffffffff)
        uc.reg_write(UC_X86_REG_ESP,esp+4)
        uc.reg_write(UC_X86_REG_EIP,dst)

    def event(op,**fields):
        fields={'op':op,**fields}
        events.append(fields)

    def hook(machine,address,_size,_user):
        if address==EXIT:
            machine.emu_stop();return
        sp=machine.reg_read(UC_X86_REG_ESP)
        if address==FILE_START:
            index=u32(sp+4)
            event('start_device',index=index)
            slot=TABLE+index*DEVICE_BYTES
            uc.mem_write(slot,struct.pack('<I',1))
            uc.mem_write(slot+0x60,struct.pack('<I',LOCK_BASE+index*4))
            uc.mem_write(slot+0x5c,struct.pack('<I',EVENT_BASE+index*4))
            uc.mem_write(slot+0x6c,struct.pack('<I',0xff))
            ret()
        elif address in (ENTER,LEAVE):
            event('enter' if address==ENTER else 'leave',lock=u32(sp+4));ret()
        elif address==OPEN:
            path,mode,group,out=u32(sp+4),u32(sp+8),u32(sp+12),u32(sp+16)
            opened=case['open']!=0
            uc.mem_write(out,struct.pack('<I',HANDLE if opened else 0))
            event('open',path=cstr(path),mode=mode,group=group,
                  result=int(opened))
            ret(int(opened))
        elif address==SIZE:
            handle,group=u32(sp+4),u32(sp+8)
            event('size',handle=handle,group=group,result=case['size'])
            ret(case['size'])
        elif address==CLOSE:
            handle,group=u32(sp+4),u32(sp+8)
            event('close',handle=handle,group=group,result=0x7788)
            ret(0x7788)
        elif address==SIGNAL:
            event('signal',event=u32(sp+4));ret(0xdeadbeef)
        elif address==DIAGNOSTIC:
            fmt_ptr=u32(sp+4);fmt=cstr(fmt_ptr)
            file_ptr=u32(0x5deb74)
            fields={'file':cstr(file_ptr),'line':u32(0x5deb78),
                    'format':fmt,'args':[]}
            if '%s' in fmt: fields['args'].append(cstr(u32(sp+8)))
            elif fmt.count('%d')==1: fields['args'].append(signed(u32(sp+8)))
            elif fmt.count('%d')==2:
                fields['args'].extend((signed(u32(sp+8)),signed(u32(sp+12))))
            event('diagnostic',**fields);ret()

    uc.hook_add(UC_HOOK_CODE,hook)
    uc.emu_start(DISPATCHER,0,count=3000)
    if uc.reg_read(UC_X86_REG_EIP)!=EXIT:
        raise AssertionError(f'00568d50 did not return for case {case}')
    state=None
    if case['table'] and case['device']<32:
        slot=TABLE+case['device']*DEVICE_BYTES
        state={'initialized':u32(slot),'field6c':u32(slot+0x6c)}
    eax=uc.reg_read(UC_X86_REG_EAX)
    return {'return':signed(eax),'caller_argument_bytes':16,'events':events,
        'device_state':state,'callee_esp_delta':uc.reg_read(UC_X86_REG_ESP)-CALLER_SP,
        'preserved':{'ebx':uc.reg_read(UC_X86_REG_EBX),
            'ebp':uc.reg_read(UC_X86_REG_EBP),'esi':uc.reg_read(UC_X86_REG_ESI),
            'edi':uc.reg_read(UC_X86_REG_EDI)}}


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
    dispatcher_body=read_va(image,module,DISPATCHER,247)
    callback_body=read_va(image,module,CALLBACK,118)
    run=subprocess.run([str(args.probe)],text=True,capture_output=True,check=True)
    actuals=[json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals)!=len(CASES): raise AssertionError('native case count mismatch')
    summaries=[]
    for i,(case,actual) in enumerate(zip(CASES,actuals)):
        target=original(module,image,case)
        expected={key:target[key] for key in
            ('return','caller_argument_bytes','events','device_state')}
        normalized={key:actual[key] for key in
            ('return','caller_argument_bytes','events','device_state')}
        if normalized!=expected:
            raise AssertionError(f'case {i}: original={expected}, native={actual}')
        if target['callee_esp_delta']!=0:
            raise AssertionError(f'dispatch caller cleanup mismatch: {target}')
        expected_registers={'ebx':0xb1b2b3b4,'ebp':0x1718191a,
            'esi':0xe1e2e3e4,'edi':0xd1d2d3d4}
        if target['preserved']!=expected_registers:
            raise AssertionError(f'original callee-saved register mismatch: {target}')
        if actual['preserved']!={k:v for k,v in expected_registers.items()}:
            raise AssertionError(f'native callee-saved register mismatch: {actual}')
        summaries.append({'case':i,'native_original_equal':True,
            'return':target['return'],'events':len(target['events']),
            'caller_argument_bytes':16,'device_state_equal':True,
            'callee_saved_equal':True})

    iteration='iterations/v2/001-original-recovery/'
    base=iteration+'source/'
    tus=[base+'recovered/resource_dispatch_probe.cpp',
         base+'recovered/Porsche.exe/resource_dispatch.cpp']
    pins=[base+'include/porsche/resource_dispatch.hpp',
        base+'include/porsche/resource_leaf.hpp',base+'include/porsche/files.hpp',
        base+'include/porsche/shared_runtime_globals.hpp',*tus,
        iteration+'runs/113-resource-dispatch/CMakeLists.txt',
        iteration+'runs/113-resource-dispatch/README.md',
        'scripts/research/verify-v2-resource-dispatch.py']
    hashes=source_hashes([ROOT/p for p in pins],compiled_sources=tus)
    evidence_paths=(
        'research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm',
        'iterations/v2/001-original-recovery/source/catalog/Porsche.exe-ddd748fdbe6d/functions.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/calls.jsonl',
        'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/strings.jsonl')
    evidence={path:(ROOT/path).read_bytes() for path in evidence_paths}
    result={'schema':1,'module':'Porsche.exe','sha256':SHA,'module_sha256':SHA,
        'function_vas':['00568d50','00561be0'],
        'full_function_vas':['00568d50','00561be0'],'partial_function_vas':[],
        'cases':len(summaries),'native_cpp_equal_original_x86':True,
        'original_functions':[
          {'va':'00568d50','body_bytes':247,
           'body_sha256':hashlib.sha256(dispatcher_body).hexdigest(),
           'abi':'callback, signed device index, priority/group, context; cdecl; returns callback EAX',
           'callers':['00561ba0','00561c60','00561ca0','00561e00','00561f20','005620c0','00562300','00562340','00562460'],
           'callee_vas':['00568390','005322b0','005322c0','0055fb30','diagnostic_handler_005debf0']},
          {'va':'00561be0','body_bytes':118,
           'body_sha256':hashlib.sha256(callback_body).hexdigest(),
           'abi':'priority/group and context; cdecl; returns size or zero',
           'callee_vas':['00533b90','00533de0','00533da0','diagnostic_handler_005debf0']}],
        'semantics':{'device_range':'signed index must be in [0,31]',
            'device_initialization':'uninitialized slot calls 00568390 before reading lock',
            'priority_order':'under device lock, reject signed requested group greater than signed field6c; otherwise set field6c during callback, restore it, signal queued_event, then unlock',
            'callback':'open path with mode 1 and group; on success return size(handle, group-1) after close(handle, group-1); on open failure optionally log FILE_size diagnostic and return 0'},
        'boundaries':{'00568390':'existing recovered device-start service; fixture records call and initializes only state required by this dispatcher proof',
            '005322b0/005322c0':'existing heap-lock helpers; platform lock effects are recorded typed boundaries',
            '0055fb30':'existing event-signal helper; platform signal effect is recorded typed boundary',
            '00533b90/00533de0/00533da0':'existing open/size/close services; fixture records arguments and configured outcomes, without claiming underlying disk or queue effects',
            'diagnostic_handler_005debf0':'existing indirect diagnostic target; these original paths make no null check, and the fixture records format/arguments plus shared source/line fields'},
        'cases_summary':summaries,'compiled_translation_units':tus,
        'source_sha256':hashes,'original_evidence':{
            path:{'sha256':hashlib.sha256(data).hexdigest()} for path,data in evidence.items()},
        'probe_sha256':hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        'game_launch_verified':False}
    (args.report_dir/'verification.json').write_text(
        json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({'cases':len(summaries),'function_vas':result['function_vas'],
        'native_cpp_equal_original_x86':True}))


if __name__=='__main__':
    main()
