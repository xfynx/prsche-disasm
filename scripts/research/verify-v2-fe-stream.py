from v2_source_dependencies import source_hashes
"""Differential FE producer -> stream -> dispatcher against unchanged original x86.

Heap, file, callback endpoints are recording fixtures, not recovered game callees.
Original CRT compare is executed in its default C-locale state.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
RUN=ROOT/'iterations/v2/001-original-recovery/runs/003-fe-stream'
sys.path.insert(0,str(ROOT/'local/tools/python-unicorn'))
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_ESP,UC_X86_REG_EIP
FUNCTIONS=[0x4b51e0,0x4b5250,0x4b5430,0x4b5470,0x4b5ee0,0x4b60d0,0x4b6660,0x4b4b80,0x4b4cd0]
STACK,BUFFER,EXIT,ARENA,SCRATCH=0x2008000,0x2100000,0x2200000,0x2300000,0x2400000
BANK=(0x160*9+16)*4
CUSTOM=[(0x10e,0,'STR'),(0x142,1,'VEC'),(0x21e,None,'CAR'),(0x13a,0,'TEXT'),
        (0x147,1,'LIST'),(0x220,2,'FIELD'),(0x21f,2,'TYPE'),(0x14e,None,'ACTION'),
        (7,'enabled','FE'),(1,None,'IMPORT'),(0,None,None)]


def cases():
    root=(ROOT/'local/game/fe.txt').read_bytes()
    values=[b'',b'0',b'-1',b'2147483648',b'4294967296',b'0xff',b'123x2',b'1,2,3',
            b'255,128,64',b'1,2,3,4',b'1 2',b'-0xA',b'AI',b'unknown',b'SingleRace',b'SC_F10',b'5-',b'--5',b'0xff 10',b'1,2,3,4,5',bytes([255]),b'fe'+bytes([128])]
    enums=json.loads((RUN/'tables.json').read_text(encoding='utf8'))
    values += [row['name'].encode() for row in enums['tables']['values']['rows'] if row['name']]
    result=[{'mode':'V','value':v} for v in values]
    result += [{'mode':'T','value':v,'delimiter':d,'cap':cap} for v,d,cap in
               [(b'a b\tc\r\nd',10,63),(b'foo,bar',44,63),(b'',10,63),(b'abc',10,0),
                (b'abc',10,-1),(b'aaaa b',10,3),(b'\nrest',10,8)]]
    def build(mode,body,args=(),addon=None,nested=None):
        return {'mode':mode,'root':body,'args':list(args),'addon':addon,'nested':nested}
    result += [build('B',root),build('B',root,[b'AppName',b'NUMCARS=8',b'numopponentracecars=7',b'FE=0']),
               build('B',None),build('B',b''),build('B',b'FE=1\nLOCKSIM=-1\nUNKNOWN=xyz\n'),
               build('B',b'@addon\n',addon=b'NUMCARS=3\n@nested\n',nested=b'DAMAGE=1\n'),
               build('B',b'IMPORT=addon\n',addon=b'NUM_LAPS=0xff\n'),
               build('B',b'#NUMCARS=3\nNUMCARS=4\n'),build('B',b'NUMCARS=9'),
               build('B',b'NUMCARS=1\n',args=[b'NUMCARS=5',b'@addon'],addon=b'NUMCARS=7\n')]
    result += [build('X',body) for body in [
        b'STR=abcdef\nVEC=1,2,3\n', b'CAR[0].TEXT=abcdef\nCAR[1].LIST=1,2,3\nCAR[8].FIELD=-2\n',
        b'CAR[0to8].FIELD=0xFFFFFFFF\nCAR[-1to1].TYPE=356A\n',
        b'ACTION=Analog,-1\nACTION=Button,42\nACTION=Pov,255\n',
        b'CAR[8to10].TEXT=01234567890123456789\n', b'CAR[2].LIST=1,,3,4,\n',
        b'CAR[1to0].FIELD=5\nUNKNOWN=foo\n', b'STR=\nVEC=\n',
        b'CAR[0].TYPE=unknown\nCAR[1].TYPE=BOX\n',
        b'VEC='+b'1'*150+b',2,3\n',
        b'STR='+b'z'*80+b'\nCAR[0to8].TEXT='+b'x'*80+b'\n',
        b'CAR[0].LIST='+b'9'*100+b',3\n',
        b'CAR[0to1to2].FIELD=7\n',
        b'CAR[0].UNKNOWN=7\nACTION=unknown,1\n']]

    rng=random.Random(0x4b5470)
    keys=[b'NUMCARS',b'DAMAGE',b'NUM_LAPS',b'MIRROR',b'REVERSE',b'RACE_TYPE',b'FE',b'NOT_A_KEY']
    literals=[b'0',b'-1',b'0x80000000',b'1,2,3',b'SingleRace',b'auto',b'unknown',b'255']
    result += [build('B',b''.join(rng.choice(keys)+b' = '+rng.choice(literals)+b'\r\n'
                               for _ in range(rng.randrange(1,20)))) for _ in range(40)]
    return result


def wire(case):
    if case['mode']=='V': return 'V|'+case['value'].hex()
    if case['mode']=='T':return '|'.join(['T',case['value'].hex(),str(case['delimiter']),str(case['cap'])])
    fields=[case['mode']]+['missing' if case[k] is None else case[k].hex() for k in ['root','addon','nested']]
    fields += [v.hex() for v in case['args']]
    return '|'.join(fields)


def original(case,module,data,functions,definitions):
    uc=Uc(UC_ARCH_X86,UC_MODE_32);base=int(module['image_base'],16)
    uc.mem_map(base,0x300000)
    for s in module['sections']:uc.mem_write(base+s['rva'],data[s['raw_offset']:s['raw_offset']+s['raw_size']])
    uc.mem_map(0x2000000,0x10000);uc.mem_map(BUFFER,0x100000);uc.mem_map(EXIT,4096);uc.mem_map(ARENA,0x200000)
    uc.mem_write(SCRATCH,b'\xcc'*(BANK*3))
    ranges=[(int(a,16),int(b,16)) for va in FUNCTIONS+[0x5ae3c0] for a,b in functions[f'{va:08x}']['ranges']]
    calls=[];allocs=[];heap=ARENA;handles={};used=0;coverage=set()
    files={name:case[key] for name,key in [('fe.txt','root'),('addon.txt','addon'),('nested.txt','nested')]
           if case.get(key) is not None}
    def words(p,n):return list(struct.unpack('<'+'I'*n,uc.mem_read(p,n*4)))
    def write(p,*values):uc.mem_write(p,struct.pack('<'+'I'*len(values),*values))
    def string(p):
        out=bytearray()
        for i in range(65536):
            b=uc.mem_read(p+i,1)[0]
            if not b:return bytes(out)
            out.append(b)
        raise RuntimeError('Unterminated fixture string')
    if case['mode']=='X':
        for i,(op,bank,name) in enumerate(CUSTOM):
            name_ptr=0x24f0000+i*32 if name else 0
            if name:uc.mem_write(name_ptr,name.encode()+b'\0')
            target=0 if bank is None else 0x65b298 if bank=='enabled' else SCRATCH+bank*BANK
            write(0x5d1e40+i*12,op,target,name_ptr)
    endpoints={0x531ca0:3,0x59e040:4,0x533de0:2,0x533bf0:5,0x533da0:2,0x531f90:1,0x569640:2,
               0x411b40:1,0x4119e0:1,0x411a80:1}
    def hook(machine,address,_size,_user):
        nonlocal heap,used
        if address in FUNCTIONS:coverage.add(f'{address:08x}')
        if address in endpoints:
            sp=machine.reg_read(UC_X86_REG_ESP);ret,*args=words(sp,endpoints[address]+1);value=0
            if address==0x531ca0:
                name,size,flags=args;name=string(name);calls.append(['allocate',name.hex(),size,flags]);value=heap+16
                uc.mem_write(heap,b'\0'*(size+128));
                if flags==16:uc.mem_write(value,b'\xcc'*size)
                allocs.append((name,value,size));heap+=(size+128+15)&~15
            elif address==0x59e040:
                name,mode,group,pointer=args;name=string(name);calls.append(['open',name.hex(),mode,group])
                handle=ARENA+0x1f0000+len(handles)*16 if name.decode('latin1') in files else 0
                if handle:handles[handle]=files[name.decode('latin1')]
                write(pointer,handle)
            elif address==0x533de0:calls.append(['size',args[1]]);value=len(handles[args[0]])
            elif address==0x533bf0:
                handle,offset,dest,size,group=args;calls.append(['read',offset,size,group]);uc.mem_write(dest,handles[handle][offset:offset+size])
            elif address==0x533da0:calls.append(['close',args[1]])
            elif address==0x531f90:calls.append(['free',next(n.hex() for n,p,_s in allocs if p==args[0])])
            elif address==0x569640:calls.append(['resize',args[1]]);used=args[1];value=args[0]
            else:
                arg=struct.unpack('<i',struct.pack('<I',args[0]))[0]
                calls.append(['callback',{0x411b40:1,0x4119e0:2,0x411a80:5}[address],arg])
            machine.reg_write(UC_X86_REG_EAX,value);machine.reg_write(UC_X86_REG_ESP,sp+4);machine.reg_write(UC_X86_REG_EIP,ret)
        elif not any(a<=address<=b for a,b in ranges):raise RuntimeError(f'Left recovered closure: {address:08x}')
    uc.hook_add(UC_HOOK_CODE,hook)
    def execute(va,args):
        write(STACK,EXIT,*args);uc.reg_write(UC_X86_REG_ESP,STACK)
        uc.emu_start(va,EXIT,count=3000000)
        if uc.reg_read(UC_X86_REG_EIP)!=EXIT or uc.reg_read(UC_X86_REG_ESP)!=STACK+4:
            raise RuntimeError(f'Original budget/ABI failure at {va:08x}')
        return uc.reg_read(UC_X86_REG_EAX)
    if case['mode'] in ['V','T']:
        uc.mem_write(BUFFER,case['value']+b'\0'*128)
        if case['mode']=='V':return {'value':execute(0x4b5250,[BUFFER])},coverage
        write(BUFFER+0x10000,BUFFER)
        value=execute(0x4b51e0,[BUFFER+0x10000,case['delimiter'],case['cap']&0xffffffff,BUFFER+0x11000])
        p=words(BUFFER+0x10000,1)[0]
        return {'offset':p-BUFFER,'token':string(BUFFER+0x11000).hex(),'count':value&65535,'high_pointer':value>>16==p>>16},coverage
    pointers=[]
    for i,arg in enumerate(case['args']):
        p=BUFFER+0x1000+i*0x1000;uc.mem_write(p,arg+b'\0'*128);pointers.append(p)
    write(BUFFER,*pointers)
    stream=execute(0x4b6660,[len(pointers),BUFFER]);enabled=words(0x65b298,1)[0]
    pointer=stream;lengths=[]
    while words(pointer,1)[0]:
        execute(0x4b4b80,[pointer]);length=execute(0x4b4cd0,[pointer])
        if not 0<length<8192 or len(lengths)>4096:raise RuntimeError('Invalid original record length')
        lengths.append(length);pointer+=length*4
    return {'stream':bytes(uc.mem_read(stream,used)).hex(),'enabled':enabled,'final_enabled':words(0x65b298,1)[0],
            'lengths':lengths,'globals':[words(d['target'],1)[0] if d['target'] else 0 for d in definitions],
            'scratch':bytes(uc.mem_read(SCRATCH,BANK*3)).hex() if case['mode']=='X' else '',
            'actions':bytes(uc.mem_read(0x5e9130,0x21e*4)).hex(),'calls':calls,
            'file_buffers':[[n.hex(),bytes(uc.mem_read(p,size)).hex()] for n,p,size in allocs if n!=b'FE Data Stream']},coverage


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--limit',type=int)
    parser.add_argument('--report-dir',type=Path,default=RUN,help='Preserve historical checks by selecting a new run directory')
    args=parser.parse_args()
    module=next(r for r in map(json.loads,(ROOT/'research/binary-index/static/binaries.jsonl').read_text(encoding='utf8').splitlines()) if r['file']=='Porsche.exe')
    data=(ROOT/'local/game'/module['path']).read_bytes()
    if hashlib.sha256(data).hexdigest()!=module['sha256']:raise RuntimeError('Original SHA mismatch')
    functions={r['entry_va']:r for r in map(json.loads,(ROOT/'research/binary-index/ghidra/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text(encoding='utf8').splitlines())}
    tables=json.loads((RUN/'tables.json').read_text(encoding='utf8'))
    definitions=tables['tables']['definitions']['rows']
    inputs=cases();inputs=inputs[:args.limit] if args.limit else inputs
    probe=ROOT/'local/builds/v2/001-original-recovery/bin/Release/fe_stream_probe.exe'
    native=subprocess.run([str(probe)],input='\n'.join(map(wire,inputs))+'\n',text=True,capture_output=True,check=True,timeout=60)
    outputs=[json.loads(line) for line in native.stdout.splitlines()]
    if len(inputs)!=len(outputs):raise RuntimeError('Native case count differs')
    coverage=set();fixtures=[]
    for i,(case,actual) in enumerate(zip(inputs,outputs)):
        expected,hit=original(case,module,data,functions,definitions);coverage|=hit
        if actual!=expected:
            target=ROOT/'local/reports/v2-fe-mismatch.json'
            target.write_text(json.dumps({'case':wire(case),'expected':expected,'actual':actual},indent=2)+'\n',encoding='utf8')
            raise RuntimeError(f"Case {i} differs in {[k for k in expected if expected[k]!=actual.get(k)]}; {target}")
        fixtures.append({'input':wire(case),'output_sha256':hashlib.sha256(json.dumps(expected,sort_keys=True).encode()).hexdigest(),
                         'mode':case['mode'],'stream_words':len(expected.get('stream',''))//8,'records':len(expected.get('lengths',[]))})
    print(json.dumps({'cases':len(inputs),'functions':sorted(coverage),'native_equal_original':True}))
    if not args.limit:
        paths=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_stream.cpp',
               'iterations/v2/001-original-recovery/source/recovered/Porsche.exe/fe_tables.inc',
               'iterations/v2/001-original-recovery/source/include/porsche/fe_stream.hpp',
               'iterations/v2/001-original-recovery/source/recovered/fe_stream_probe.cpp']
        report={'schema':1,'sha256':module['sha256'],'function_vas':sorted(coverage),'cases':len(inputs),
                'native_cpp_equal_original_x86':True,'binary_matched':False,'game_launch_verified':False,
                'boundaries':{'file':'0059e040/00533de0/00533bf0/00533da0 recording byte-file fixture',
                              'heap':'00531ca0/00531f90/00569640 recording aligned zeroed/patterned allocations; original heap not recovered',
                              'callbacks':'00411b40/004119e0/00411a80 record only',
                              'CRT':'original 005ae3c0 in C locale; native equality comparator; locale change not recovered'},
                'synthetic_tables':'X fixtures replace tables/data in memory to exercise generic formats, not applied to game',
                'source_sha256':{p:hashlib.sha256((ROOT/p).read_bytes().replace(b'\r\n',b'\n')).hexdigest() for p in paths},
                'probe_sha256':hashlib.sha256(probe.read_bytes()).hexdigest(),
                'fixtures':fixtures}
        args.report_dir.mkdir(parents=True,exist_ok=True)
        report['source_sha256']=source_hashes(report['source_sha256'].keys(),compiled_sources=['iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp','iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_globals.cpp'])
        (args.report_dir/'verification.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf8',newline='\n')
        indexed=[{'sha256':module['sha256'],**functions[va]} for va in sorted(coverage)]
        (args.report_dir/'source-functions.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in indexed),encoding='utf8',newline='\n')


if __name__=='__main__':main()
