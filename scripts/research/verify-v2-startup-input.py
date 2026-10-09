"""Compare the recovered DirectInput startup chain with Porsche.exe x86."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys

from v2_source_dependencies import source_hashes

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/046-startup-input'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EIP,UC_X86_REG_ESP

ARENA,ARENA_BYTES,STACK,EXIT=0x3600000,0x10000,0x200f000,0x2200000
ADDR={'di':0x6a5b14,'device':0x6a5b18,'initialized':0x6a5b1c,'registered':0x6a5b20,
      'accelerator':0x6bd9dc,'lock':0x69e59c,'capacity':0x69e560,'read':0x69e0d8,
      'write':0x69e568,'callback':0x5df6a4,'hwnd':0x6b7bf8,'diag_file':0x5deb74,'diag_line':0x5deb78}
FUNCTIONS=(0x55fcf0,0x55fe00,0x55fe50,0x53bf90,0x557380,0x557460,0x56e940,0x5a2400)
CASES=[
    # Complete DirectInputA -> keyboard -> Device2 setup, including first input reset.
    (0,0,0,0,0,0,0,0,0,0,12,2,5,0,0x1230000,0),
    # DirectInputCreateA failure.
    (0,0,0,0,0x80004005,0,0,0,0,0,4,1,3,0,0x1230000,0),
    # CreateDevice failure causes release of the DirectInput interface.
    (0,0,0,0,0,0x80004005,0,0,0,0,32,7,9,0,0x1230000,0),
    # QueryInterface failure releases the temporary keyboard, then DirectInput.
    (0,0,0,0,0,0,0x80004005,0,0,0,8,3,6,0,0x1230000,0),
    # SetDataFormat failure tears down the returned Device2 and DirectInput.
    (0,0,0,0,0,0,0,0x80004005,0,0,10,4,7,0,0x1230000,0),
    # Cooperative-level failure follows the same original cleanup branch.
    (0,0,0,0,0,0,0,0,0x80004005,0,16,6,11,0,0,0),
    # Already initialized/existing COM objects skip setup; exit callback clears state.
    (1,1,1,1,0,0,0,0,0,1,32,0,0,1,0x1230000,1),
    # Repeated startup still registers the one-time cleanup callback.
    (1,0,1,0,0,0,0,0,0,1,32,0,0,0,0,0),
]

def original(case,module,data,function_rows):
    init,registered,has_di,has_device,create_status,device_status,query_status,format_status,coop_status,has_lock,capacity,read,write,callback,hwnd,cleanup_after=case
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16);uc.mem_map(base,0x300000)
    for section in module['sections']:
        uc.mem_write(base+section['rva'],data[section['raw_offset']:section['raw_offset']+section['raw_size']])
    uc.mem_map(ARENA,ARENA_BYTES);uc.mem_write(ARENA,b'\xcc'*ARENA_BYTES)
    uc.mem_map(0x2000000,0x10000);uc.mem_map(EXIT,0x2000)
    record={'di':ARENA+0x4000,'temp':ARENA+0x4010,'device':ARENA+0x4020,
            'di_table':ARENA+0x5000,'temp_table':ARENA+0x5100,'device_table':ARENA+0x5200}
    def put(address,*values):uc.mem_write(address,struct.pack('<'+'I'*len(values),*[v&0xffffffff for v in values]))
    def word(address):return struct.unpack('<I',uc.mem_read(address,4))[0]
    def words(address,count):return list(struct.unpack('<'+'I'*count,uc.mem_read(address,count*4)))
    def read_cstr(address):
        out=bytearray()
        while len(out)<256:
            b=uc.mem_read(address+len(out),1)[0]
            if not b:break
            out.append(b)
        return out.decode('ascii','replace')
    for address,target in ((0x5b2138,EXIT+0x100),(0x5b202c,EXIT+0x110)):
        put(address,target)
    put(ADDR['di'],record['di'] if has_di else 0);put(ADDR['device'],record['device'] if has_device else 0)
    put(ADDR['initialized'],init);put(ADDR['registered'],registered)
    put(ADDR['accelerator'],1);put(ADDR['lock'],0x2003000 if has_lock else 0)
    put(ADDR['capacity'],capacity);put(ADDR['read'],read);put(ADDR['write'],write)
    put(ADDR['callback'],0x5abc1234 if callback else 0);put(ADDR['hwnd'],hwnd)
    put(ADDR['diag_file'],0);put(ADDR['diag_line'],0);put(0x5debf0,0)
    # Native and x86 fixtures share fixed object/vtable addresses.
    for table in (record['di_table'],record['temp_table'],record['device_table']):uc.mem_write(table,b'\0'*64)
    put(record['di'],record['di_table']);put(record['temp'],record['temp_table']);put(record['device'],record['device_table'])
    put(record['di_table']+8,EXIT+0x220);put(record['di_table']+12,EXIT+0x200)
    put(record['temp_table'],EXIT+0x210);put(record['temp_table']+8,EXIT+0x220)
    put(record['device_table']+8,EXIT+0x220);put(record['device_table']+32,EXIT+0x230)
    put(record['device_table']+44,EXIT+0x240);put(record['device_table']+52,EXIT+0x250)
    calls=[];coverage=set();functions=[(int(a,16),int(b,16)) for va in FUNCTIONS if f'{va:08x}' in function_rows for a,b in function_rows[f'{va:08x}']['ranges']]
    functions.append((0x55fe40,0x55fe4f))
    endpoints={EXIT+0x100:('get_module',1),0x56e940:('direct_input_create',4),
               EXIT+0x200:('create_device',4),EXIT+0x210:('query_interface',3),
               EXIT+0x220:('release',1),EXIT+0x230:('unacquire',1),
               EXIT+0x240:('set_format',2),EXIT+0x250:('set_cooperative',3),
               0x5321f0:('lock_create',0),
               0x5a2400:('callback_register',1)}
    def hook(machine,address,_size,_user):
        if address==EXIT:machine.emu_stop();return
        if address in FUNCTIONS or address==0x55fe40:coverage.add(f'{address:08x}')
        endpoint=endpoints.get(address)
        if endpoint is None:
            if not any(lo<=address<=hi for lo,hi in functions):raise RuntimeError(f'unexpected x86 address {address:08x}; calls={calls[-5:]}')
            return
        name,n=endpoint;sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,n+1);result=0
        if name=='get_module':calls.append([name,args[0]]);result=0x4001000
        elif name=='direct_input_create':
            module_handle,version,out,outer=args;calls.append([name,module_handle,version,out,outer])
            if create_status==0:put(out,record['di'])
            result=create_status
        elif name=='create_device':
            this,guid,out,outer=args;calls.append([name,this,guid,0x3008000,outer])
            if device_status==0:put(out,record['temp'])
            result=device_status
        elif name=='query_interface':
            this,guid,out=args;calls.append([name,this,guid,out])
            if query_status==0:put(out,record['device'])
            result=query_status
        elif name=='release':calls.append([name,args[0]]);result=1
        elif name=='unacquire':calls.append([name,args[0]]);result=1
        elif name=='set_format':calls.append([name,*args]);result=format_status
        elif name=='set_cooperative':calls.append([name,*args]);result=coop_status
        elif name=='lock_create':calls.append([name,0x2001000]);result=0x2001000
        elif name=='callback_register':calls.append([name,args[0]])
        stdcall=address in {EXIT+0x100,0x56e940,EXIT+0x200,EXIT+0x210,EXIT+0x220,EXIT+0x230,EXIT+0x240,EXIT+0x250}
        machine.reg_write(UC_X86_REG_EAX,result);machine.reg_write(UC_X86_REG_ESP,sp+4*(n+1) if stdcall else sp+4)
        machine.reg_write(UC_X86_REG_EIP,ret)
    uc.hook_add(UC_HOOK_CODE,hook)
    def run(va,args=()):
        put(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
        try:uc.emu_start(va,EXIT+1,count=200000)
        except Exception as error:raise RuntimeError(f'x86 failed at {uc.reg_read(UC_X86_REG_EIP):08x} case={case} calls={calls[-5:]}') from error
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:raise RuntimeError(f'ABI mismatch {va:08x} {case}')
        return uc.reg_read(UC_X86_REG_EAX)
    result=run(0x55fcf0)
    if cleanup_after:run(0x55fe40)
    globals_=[word(ADDR[k]) for k in ('di','device','initialized','registered','accelerator','lock','capacity','read','write','callback','diag_file','diag_line')]
    return {'return':result,'globals':globals_,'arena':bytes(uc.mem_read(ARENA,ARENA_BYTES)).hex(),'calls':calls},coverage

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--limit',type=int,default=0);parser.add_argument('--report-dir',type=Path,default=RUN);parser.add_argument("--probe",type=Path,default=ROOT/"local/builds/v2/001-original-recovery/bin/Release/startup_input_probe.exe");args=parser.parse_args()
    module=next(x for x in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text().splitlines()) if x['file']=='Porsche.exe')
    binary=(ROOT/'local/game'/module['path']).read_bytes();sha='ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39'
    if hashlib.sha256(binary).hexdigest()!=sha:raise RuntimeError('original SHA mismatch')
    function_rows={x['entry_va']:x for x in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines())}
    selected=CASES[:args.limit or None];probe=args.probe
    process=subprocess.run([str(probe)],input=''.join(' '.join(map(str,row))+'\n' for row in selected),text=True,capture_output=True,check=True,timeout=30)
    actual=[json.loads(line) for line in process.stdout.splitlines()]
    if len(actual)!=len(selected):raise RuntimeError('native output count differs')
    coverage=set();fixtures=[]
    for index,(case,got) in enumerate(zip(selected,actual)):
        want,hit=original(case,module,binary,function_rows);coverage|=hit
        if got!=want:
            path=ROOT/'local/reports/v2-startup-input-mismatch.json';path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text(json.dumps({'case':case,'expected':want,'actual':got},indent=2)+'\n',encoding='utf8')
            keys=[k for k in want if got.get(k)!=want[k]]
            raise AssertionError(f'case {index} differs in {keys}: {path}')
        fixtures.append({'input':case,'output_sha256':hashlib.sha256(json.dumps(want,sort_keys=True).encode()).hexdigest()})
    print(json.dumps({'range':'0055fcf0..0055fdf4','cases':len(selected),'functions':sorted(coverage),'native_cpp_equal_original_x86':True}))
    if args.limit:return
    required={'0055fcf0','0055fe00','0055fe40','0055fe50','0053bf90','00557380','00557460'}
    if not required<=coverage:raise RuntimeError(f'original coverage missing {sorted(required-coverage)}')
    paths=['iterations/v2/001-original-recovery/source/include/porsche/startup_input.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/files.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/heap.hpp',
        'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
        'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_input.cpp',
        'iterations/v2/001-original-recovery/source/recovered/startup_input_probe.cpp',
        'iterations/v2/001-original-recovery/runs/046-startup-input/CMakeLists.txt',
        'scripts/research/verify-v2-startup-input.py']
    report={'schema':1,'module':'Porsche.exe','sha256':sha,'range':'0055fcf0..0055fdf4',
        'function_vas':sorted(coverage),'full_function_vas':['0053bf90','00557380','00557460','0055fcf0','0055fe00','0055fe40','0055fe50'],
        'partial_function_vas':['0056e940','005a2400'],'cases':len(selected),'native_cpp_equal_original_x86':True,
        'binary_matched':False,'game_launch_verified':False,
        'comparison':'Full 64 KiB input-interface/vtable arena, DirectInput globals, shared window key-ring and accelerator state, return value, and ordered Win32/COM/callback calls. GUIDs and keyboard DIDATAFORMAT are byte-derived from original data addresses 005bf970/005bf9b0/005bf8c0/0056f9e0/0056e9e0.',
        'boundaries':{'platform':'GetModuleHandleA and DirectInputCreateA are deterministic API fixtures.',
            'COM':'DirectInput/CreateDevice/QueryInterface/Release/Unacquire/SetDataFormat/SetCooperativeLevel are deterministic vtable fixtures; method selection, argument order, state, and failure cleanup are compared. Device hardware behavior is not claimed.',
            'callback_registry':'005a2400 callback insertion is a recording boundary; exit callback code 0055fe40 is invoked directly in one comparison.'},
        'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
        'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),'fixtures':fixtures}
    report_dir=args.report_dir if args.report_dir.is_absolute() else ROOT/args.report_dir;report_dir.mkdir(parents=True,exist_ok=True)
    report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/startup_input.cpp', 'iterations/v2/001-original-recovery/source/recovered/startup_input_probe.cpp'])
    (report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
    print(json.dumps({'report':str(report_dir/'verification.json'),'native_equal_original_x86':True}))
if __name__=='__main__':main()
